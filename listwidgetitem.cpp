#include "listwidgetitem.h"
#include "ui_listwidgetitem.h"

ListWidgetItem::ListWidgetItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListWidgetItem)
{
    ui->setupUi(this);
}

ListWidgetItem::~ListWidgetItem()
{
    delete ui;
}
