#ifndef LISTWIDGETITEM_H
#define LISTWIDGETITEM_H

#include <QWidget>

namespace Ui {
class ListWidgetItem;
}

class ListWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit ListWidgetItem(QString sum, QString walletId, QString date, QString prevHash, QWidget *parent = nullptr);
    ~ListWidgetItem();

private:
    Ui::ListWidgetItem *ui;
};

#endif // LISTWIDGETITEM_H
