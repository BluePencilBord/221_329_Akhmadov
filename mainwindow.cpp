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

void MainWindow::loadTransactions(QString filename)
{
    QFile jsonFile(filename);

    if(!jsonFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл: " + jsonFile.errorString());
    }
    else
    {
        ui->listWidget->clear();
        QByteArray fileData = jsonFile.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
        QJsonArray transactionsArray = jsonDoc["transactions"].toArray();
        bool is_red = false;

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
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadTransactions("C:\\Users\\bruh\\Documents\\221_329_Akhmadov\\json\\transactions.json");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOk_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButtonSelectFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл с транзакциями", "", "JSON Files (*.json);;All Files (*)");
    if (!fileName.isEmpty()) {
        loadTransactions(fileName);
    }
}

