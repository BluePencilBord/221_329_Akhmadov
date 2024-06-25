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
    QLabel *label;

    void setupUi(QWidget *ListWidgetItem)
    {
        if (ListWidgetItem->objectName().isEmpty())
            ListWidgetItem->setObjectName("ListWidgetItem");
        ListWidgetItem->resize(458, 58);
        gridLayout = new QGridLayout(ListWidgetItem);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(ListWidgetItem);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(ListWidgetItem);

        QMetaObject::connectSlotsByName(ListWidgetItem);
    } // setupUi

    void retranslateUi(QWidget *ListWidgetItem)
    {
        ListWidgetItem->setWindowTitle(QCoreApplication::translate("ListWidgetItem", "Form", nullptr));
        label->setText(QCoreApplication::translate("ListWidgetItem", "test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListWidgetItem: public Ui_ListWidgetItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWIDGETITEM_H
