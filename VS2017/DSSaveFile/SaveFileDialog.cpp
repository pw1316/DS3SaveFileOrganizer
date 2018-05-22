#include "SaveFileDialog.h"

SaveFileDialog::SaveFileDialog(QWidget *parent): QDialog(parent)
{
    ui.setupUi(this);
    QRegExp rx("[a-zA-Z0-9]+");
    ui.editArea->setValidator(new QRegExpValidator(rx));
    ui.editArea->setFocus();
    connect(ui.okButton, &QPushButton::clicked, [=] {emit passNewName(ui.editArea->text()); });
}
