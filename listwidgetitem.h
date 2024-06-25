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
    explicit ListWidgetItem(QWidget *parent = nullptr);
    ~ListWidgetItem();

private:
    Ui::ListWidgetItem *ui;

    QString sum;
    QString walletId;
    QString date;
    QString prevHash;
};

#endif // LISTWIDGETITEM_H
