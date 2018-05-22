/********************************************************************************
** Form generated from reading UI file 'DSSaveFile.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSSAVEFILE_H
#define UI_DSSAVEFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DSSaveFileClass
{
public:
    QWidget *centralWidget;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *renameButton;
    QPushButton *deleteButton;
    QListWidget *listWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DSSaveFileClass)
    {
        if (DSSaveFileClass->objectName().isEmpty())
            DSSaveFileClass->setObjectName(QStringLiteral("DSSaveFileClass"));
        DSSaveFileClass->resize(400, 320);
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(12);
        DSSaveFileClass->setFont(font);
        centralWidget = new QWidget(DSSaveFileClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(150, 10, 180, 24));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 10, 90, 24));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(20, 40, 90, 24));
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(110, 40, 90, 24));
        renameButton = new QPushButton(centralWidget);
        renameButton->setObjectName(QStringLiteral("renameButton"));
        renameButton->setGeometry(QRect(200, 40, 90, 24));
        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(290, 40, 90, 24));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 70, 360, 220));
        listWidget->setFont(font);
        DSSaveFileClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DSSaveFileClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DSSaveFileClass->setStatusBar(statusBar);

        retranslateUi(DSSaveFileClass);

        QMetaObject::connectSlotsByName(DSSaveFileClass);
    } // setupUi

    void retranslateUi(QMainWindow *DSSaveFileClass)
    {
        DSSaveFileClass->setWindowTitle(QApplication::translate("DSSaveFileClass", "DSSaveFile", nullptr));
        label->setText(QApplication::translate("DSSaveFileClass", "Profile:", nullptr));
        loadButton->setText(QApplication::translate("DSSaveFileClass", "load", nullptr));
        saveButton->setText(QApplication::translate("DSSaveFileClass", "save", nullptr));
        renameButton->setText(QApplication::translate("DSSaveFileClass", "rename", nullptr));
        deleteButton->setText(QApplication::translate("DSSaveFileClass", "delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DSSaveFileClass: public Ui_DSSaveFileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSSAVEFILE_H
