#include "listwidgetitem.h"
#include "ui_listwidgetitem.h"

ListWidgetItem::ListWidgetItem(QString sum, QString walletId, QString date, QString prevHash, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListWidgetItem)
{
    ui->setupUi(this);

    ui->labelSum->setText(sum);
    ui->labelWalletId->setText(walletId);
    ui->labelDate->setText(date);
}

ListWidgetItem::~ListWidgetItem()
{
    delete ui;
}
