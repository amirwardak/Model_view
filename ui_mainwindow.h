/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSaveAs;
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *load_from_txt;
    QPushButton *btnShow;
    QPushButton *btnLoadAdress;
    QPushButton *btnShowAdress;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName("actionSaveAs");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(60, 20, 691, 431));
        load_from_txt = new QPushButton(centralwidget);
        load_from_txt->setObjectName("load_from_txt");
        load_from_txt->setGeometry(QRect(60, 460, 161, 29));
        btnShow = new QPushButton(centralwidget);
        btnShow->setObjectName("btnShow");
        btnShow->setGeometry(QRect(230, 460, 161, 29));
        btnLoadAdress = new QPushButton(centralwidget);
        btnLoadAdress->setObjectName("btnLoadAdress");
        btnLoadAdress->setGeometry(QRect(400, 460, 161, 29));
        btnShowAdress = new QPushButton(centralwidget);
        btnShowAdress->setObjectName("btnShowAdress");
        btnShowAdress->setGeometry(QRect(580, 460, 161, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName("menu_File");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(actionSaveAs);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "Save &As", nullptr));
        load_from_txt->setText(QCoreApplication::translate("MainWindow", " Load with telephon", nullptr));
        btnShow->setText(QCoreApplication::translate("MainWindow", "Show with telephon", nullptr));
        btnLoadAdress->setText(QCoreApplication::translate("MainWindow", "Load with adress", nullptr));
        btnShowAdress->setText(QCoreApplication::translate("MainWindow", "Show with adress", nullptr));
        menu_File->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
