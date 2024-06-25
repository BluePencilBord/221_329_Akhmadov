/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QLineEdit *lineEditPassword;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelPassword;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButtonOk;
    QSpacerItem *horizontalSpacer;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButtonSelectFile;
    QListWidget *listWidget;
    QPushButton *pushButtonAdd;
    QWidget *page_3;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLineEdit *lineEditAddId;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *lineEditAddDate;
    QPushButton *pushButtonSave;
    QLabel *label_2;
    QLineEdit *lineEditAddSum;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setSizeIncrement(QSize(1, 1));
        page = new QWidget();
        page->setObjectName("page");
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName("gridLayout");
        lineEditPassword = new QLineEdit(page);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEditPassword, 1, 2, 1, 2);

        verticalSpacer = new QSpacerItem(20, 173, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(267, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        labelPassword = new QLabel(page);
        labelPassword->setObjectName("labelPassword");

        gridLayout->addWidget(labelPassword, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 223, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 3, 1, 1);

        pushButtonOk = new QPushButton(page);
        pushButtonOk->setObjectName("pushButtonOk");

        gridLayout->addWidget(pushButtonOk, 2, 2, 1, 2);

        horizontalSpacer = new QSpacerItem(257, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setObjectName("gridLayout_3");
        pushButtonSelectFile = new QPushButton(page_2);
        pushButtonSelectFile->setObjectName("pushButtonSelectFile");

        gridLayout_3->addWidget(pushButtonSelectFile, 1, 0, 1, 1);

        listWidget = new QListWidget(page_2);
        listWidget->setObjectName("listWidget");

        gridLayout_3->addWidget(listWidget, 0, 0, 1, 1);

        pushButtonAdd = new QPushButton(page_2);
        pushButtonAdd->setObjectName("pushButtonAdd");

        gridLayout_3->addWidget(pushButtonAdd, 2, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        gridLayout_4 = new QGridLayout(page_3);
        gridLayout_4->setObjectName("gridLayout_4");
        label = new QLabel(page_3);
        label->setObjectName("label");

        gridLayout_4->addWidget(label, 1, 0, 1, 1);

        lineEditAddId = new QLineEdit(page_3);
        lineEditAddId->setObjectName("lineEditAddId");

        gridLayout_4->addWidget(lineEditAddId, 2, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 5, 1, 1, 1);

        lineEditAddDate = new QLineEdit(page_3);
        lineEditAddDate->setObjectName("lineEditAddDate");

        gridLayout_4->addWidget(lineEditAddDate, 3, 1, 1, 1);

        pushButtonSave = new QPushButton(page_3);
        pushButtonSave->setObjectName("pushButtonSave");
        pushButtonSave->setEnabled(false);

        gridLayout_4->addWidget(pushButtonSave, 4, 1, 1, 1);

        label_2 = new QLabel(page_3);
        label_2->setObjectName("label_2");

        gridLayout_4->addWidget(label_2, 2, 0, 1, 1);

        lineEditAddSum = new QLineEdit(page_3);
        lineEditAddSum->setObjectName("lineEditAddSum");

        gridLayout_4->addWidget(lineEditAddSum, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 0, 1, 1, 1);

        label_3 = new QLabel(page_3);
        label_3->setObjectName("label_3");

        gridLayout_4->addWidget(label_3, 3, 0, 1, 1);

        stackedWidget->addWidget(page_3);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelPassword->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButtonOk->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        pushButtonSelectFile->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\321\201\321\203\320\274\320\274\320\260 \321\202\321\200\320\260\320\275\320\267\320\260\320\272\321\206\320\270\320\270", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\275\320\276\320\274\320\265\321\200 \320\272\320\276\321\210\320\265\320\273\321\214\320\272\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\264\320\260\321\202\320\260 \321\202\321\200\320\260\320\275\320\267\320\260\320\272\321\206\320\270\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
