/********************************************************************************
** Form generated from reading UI file 'listwidgetitem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTWIDGETITEM_H
#define UI_LISTWIDGETITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListWidgetItem
{
public:
    QGridLayout *gridLayout;
    QLabel *labelSum;
    QLabel *labelWalletId;
    QLabel *labelDate;

    void setupUi(QWidget *ListWidgetItem)
    {
        if (ListWidgetItem->objectName().isEmpty())
            ListWidgetItem->setObjectName("ListWidgetItem");
        ListWidgetItem->resize(458, 58);
        gridLayout = new QGridLayout(ListWidgetItem);
        gridLayout->setObjectName("gridLayout");
        labelSum = new QLabel(ListWidgetItem);
        labelSum->setObjectName("labelSum");

        gridLayout->addWidget(labelSum, 0, 0, 1, 1);

        labelWalletId = new QLabel(ListWidgetItem);
        labelWalletId->setObjectName("labelWalletId");

        gridLayout->addWidget(labelWalletId, 0, 1, 1, 1);

        labelDate = new QLabel(ListWidgetItem);
        labelDate->setObjectName("labelDate");

        gridLayout->addWidget(labelDate, 0, 2, 1, 1);


        retranslateUi(ListWidgetItem);

        QMetaObject::connectSlotsByName(ListWidgetItem);
    } // setupUi

    void retranslateUi(QWidget *ListWidgetItem)
    {
        ListWidgetItem->setWindowTitle(QCoreApplication::translate("ListWidgetItem", "Form", nullptr));
        labelSum->setText(QCoreApplication::translate("ListWidgetItem", "test", nullptr));
        labelWalletId->setText(QCoreApplication::translate("ListWidgetItem", "TextLabel", nullptr));
        labelDate->setText(QCoreApplication::translate("ListWidgetItem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListWidgetItem: public Ui_ListWidgetItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWIDGETITEM_H
