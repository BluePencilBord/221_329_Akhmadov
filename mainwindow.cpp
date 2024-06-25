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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile jsonFile("C:\\Users\\Bruh\\Documents\\221_329_Akhmadov\\json\\transactions.json");

    if(!jsonFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл: " + jsonFile.errorString());
    }
    else
    {
        QByteArray fileData = jsonFile.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
        QJsonArray transactionsArray = jsonDoc.array();

        for (int i = 0; i != transactionsArray.size(); ++i)
        {
            QJsonObject jsonItem = transactionsArray[i].toObject();

            QString stringtohash = jsonItem["sum"].toString() + jsonItem["walletId"].toString() + jsonItem["date"].toString() + jsonItem["prevHash"].toString();
            QByteArray hash = QCryptographicHash::hash(stringtohash.toUtf8(), QCryptographicHash::Sha256);

            QListWidgetItem *newItem = new QListWidgetItem();
            ListWidgetItem *newWidget = new ListWidgetItem;

            ui->listWidget->addItem(newItem);
            ui->listWidget->setItemWidget(newItem, newWidget);

            newItem->setSizeHint(newWidget->sizeHint());
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOk_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

