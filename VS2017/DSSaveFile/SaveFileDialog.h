#pragma once
#include <QtWidgets/QDialog>
#include "ui_SaveFileDialog.h"
#include <QtCore/QString>

class SaveFileDialog : public QDialog
{
    Q_OBJECT

public:
    SaveFileDialog(QWidget *parent = Q_NULLPTR);

private:
    Ui::SaveFileDialogClass ui;

signals:
    void passNewName(QString s);
};
