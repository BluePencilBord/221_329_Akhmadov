#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "listwidgetitem.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTimer>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QFileDialog>
#include <openssl/evp.h>
#include <QBuffer>

bool MainWindow::decryptJson(unsigned char *key, QString filename)
{
    QFile jsonFile(filename);

    if(!jsonFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл: " + jsonFile.errorString());
        return false;
    }

    QByteArray encryptedBytes = QByteArray::fromHex(jsonFile.readAll());
    QByteArray decryptedBytes;

    int return_code = MainWindow::decryptQByteArray(encryptedBytes, decryptedBytes, key);

    QJsonDocument jsonDoc = QJsonDocument::fromJson(decryptedBytes);
    QJsonObject jsonObj = jsonDoc.object();
    qDebug() << jsonDoc;
    transactionsArray = jsonObj["transactions"].toArray();

    jsonFile.close();

    return !return_code;
}


void MainWindow::loadTransactions(QByteArray bytearrayHashKey)
{
    ui->listWidget->clear();

    unsigned char HashKey[32] = {0};
    memcpy(HashKey, bytearrayHashKey.data(), 32);

    if(decryptJson(HashKey, fileName))
    {
        bool is_red = false;

        qDebug() << transactionsArray.size();
        for (int i = 0; i != transactionsArray.size(); ++i)
        {
            QJsonObject jsonItem = transactionsArray[i].toObject();

            if(!is_red && (i != 0))
            {
                QJsonObject prevjsonItem = transactionsArray[i-1].toObject();
                QString stringtohash = prevjsonItem["sum"].toString() + prevjsonItem["walletId"].toString() + prevjsonItem["date"].toString() + prevjsonItem["prevHash"].toString();
                QByteArray hash = QCryptographicHash::hash(stringtohash.toUtf8(), QCryptographicHash::Sha256);

                if(hash.toHex() != jsonItem["prevHash"].toString())
                {
                    is_red = true;
                }
            }

            QListWidgetItem *newItem = new QListWidgetItem();
            ListWidgetItem *newWidget = new ListWidgetItem(jsonItem["sum"].toString(), jsonItem["walletId"].toString(), jsonItem["date"].toString(), jsonItem["prevHash"].toString());

            if (is_red) newItem->setBackground(Qt::red);

            ui->listWidget->addItem(newItem);
            ui->listWidget->setItemWidget(newItem, newWidget);

            newItem->setSizeHint(newWidget->sizeHint());
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "Ошибка", "Неверный пинкод");
        ui->stackedWidget->setCurrentIndex(0);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOk_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    QByteArray bytearrayHashKey = QCryptographicHash::hash(ui->lineEditPassword->text().toUtf8(), QCryptographicHash::Sha256);
    ui->lineEditPassword->setText("");
    loadTransactions(bytearrayHashKey);
}


void MainWindow::on_pushButtonSelectFile_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, "Выберите файл с транзакциями", "", "JSON Files (*.json);;All Files (*)");
    if (!fileName.isEmpty()) {
        ui->stackedWidget->setCurrentIndex(0);
    }
}

int MainWindow::decryptQByteArray(const QByteArray& encryptedBytes, QByteArray& decryptedBytes, unsigned char *key)
{
    QByteArray iv_hex("00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f");
    QByteArray iv_ba = QByteArray::fromHex(iv_hex);

    unsigned char iv[16] = {0};
    memcpy(iv, iv_ba.data(), 16);

    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    if (!EVP_DecryptInit_ex2(ctx, EVP_aes_256_cbc(), key, iv, NULL)) {
        qDebug() << "Error";
        /* Error */
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }
    qDebug() << "NoError";

#define BUF_LEN 256
    unsigned char encrypted_buf[BUF_LEN] = {0}, decrypted_buf[BUF_LEN] = {0};
    int encr_len, decr_len;

    QDataStream encrypted_stream(encryptedBytes);

    decryptedBytes.clear();
    QBuffer decryptedBuffer(&decryptedBytes);
    decryptedBuffer.open(QIODevice::ReadWrite);


    encr_len = encrypted_stream.readRawData(reinterpret_cast<char*>(encrypted_buf), BUF_LEN);
    while(encr_len > 0){

        if (!EVP_DecryptUpdate(ctx, decrypted_buf, &decr_len, encrypted_buf, encr_len)) {
            /* Error */
            qDebug() << "Error";
            EVP_CIPHER_CTX_free(ctx);
            return 0;
        }

        decryptedBuffer.write(reinterpret_cast<char*>(decrypted_buf), decr_len);
        encr_len = encrypted_stream.readRawData(reinterpret_cast<char*>(encrypted_buf), BUF_LEN);
    }

    int tmplen;
    if (!EVP_DecryptFinal_ex(ctx, decrypted_buf, &tmplen)) {
        /* Error */
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    // qDebug() << "***EVP_DecryptFinal_ex " << reinterpret_cast<char*>(decrypted_buf);
    decryptedBuffer.write(reinterpret_cast<char*>(decrypted_buf), tmplen);
    EVP_CIPHER_CTX_free(ctx);

    decryptedBuffer.close();
    return 0;
}


void MainWindow::on_lineEditAddSum_textChanged(const QString &arg1)
{
    bool is_numeric;
    ui->lineEditAddSum->text().toInt(&is_numeric);
    if(is_numeric && (ui->lineEditAddSum->text().length() == 7))
    {
        ui->pushButtonSave->setEnabled(true);
    }
    else
    {
        ui->pushButtonSave->setEnabled(false);
    }
}


void MainWindow::on_lineEditAddSum_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEditAddSum_editingFinished()
{
    int length = ui->lineEditAddSum->text().length();
    for(int i = 0; i < (7 - length); ++i)
    {
        ui->lineEditAddSum->setText("0" + ui->lineEditAddSum->text());
    }
}


void MainWindow::on_lineEditAddSum_selectionChanged()
{

}


void MainWindow::on_lineEditAddId_textChanged(const QString &arg1)
{
    bool is_numeric;
    ui->lineEditAddId->text().toInt(&is_numeric);
    if(is_numeric && (ui->lineEditAddId->text().length() == 6))
    {
        ui->pushButtonSave->setEnabled(true);
    }
    else
    {
        ui->pushButtonSave->setEnabled(false);
    }
}


void MainWindow::on_lineEditAddDate_textChanged(const QString &arg1)
{

}

