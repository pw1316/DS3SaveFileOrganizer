/********************************************************************************
** Form generated from reading UI file 'SaveFileDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEFILEDIALOG_H
#define UI_SAVEFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaveFileDialogClass
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLineEdit *editArea;

    void setupUi(QDialog *SaveFileDialogClass)
    {
        if (SaveFileDialogClass->objectName().isEmpty())
            SaveFileDialogClass->setObjectName(QStringLiteral("SaveFileDialogClass"));
        SaveFileDialogClass->resize(320, 100);
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(12);
        SaveFileDialogClass->setFont(font);
        layoutWidget = new QWidget(SaveFileDialogClass);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 50, 281, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        editArea = new QLineEdit(SaveFileDialogClass);
        editArea->setObjectName(QStringLiteral("editArea"));
        editArea->setGeometry(QRect(20, 20, 280, 20));
        editArea->setMaxLength(12);

        retranslateUi(SaveFileDialogClass);
        QObject::connect(okButton, SIGNAL(clicked()), SaveFileDialogClass, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), SaveFileDialogClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(SaveFileDialogClass);
    } // setupUi

    void retranslateUi(QDialog *SaveFileDialogClass)
    {
        SaveFileDialogClass->setWindowTitle(QApplication::translate("SaveFileDialogClass", "SaveFile", nullptr));
        okButton->setText(QApplication::translate("SaveFileDialogClass", "OK", nullptr));
        cancelButton->setText(QApplication::translate("SaveFileDialogClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveFileDialogClass: public Ui_SaveFileDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEFILEDIALOG_H
