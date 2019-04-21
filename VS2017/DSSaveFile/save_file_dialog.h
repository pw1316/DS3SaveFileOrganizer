#ifndef __DS_SAVE_FILE_DIALOG_H__
#define __DS_SAVE_FILE_DIALOG_H__
#include <QtCore/QString>
#include <QtWidgets/QDialog>

#include "ui_save_file_dialog.h"

class SaveFileDialog : public QDialog {
  Q_OBJECT

 public:
  SaveFileDialog(QWidget* parent = Q_NULLPTR) {
    ui_.setupUi(this);
    QRegExp regex("[a-zA-Z0-9]+");
    ui_.editArea->setValidator(new QRegExpValidator(regex));
    ui_.editArea->setFocus();
    connect(ui_.okButton, &QPushButton::clicked,
            [&] { emit PassNewName(ui_.editArea->text()); });
  }

 private:
  Ui::SaveFileDialogClass ui_;

 signals:
  void PassNewName(QString s);
};
#endif
