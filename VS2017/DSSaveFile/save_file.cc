#include "save_file.h"

#include <assert.h>

#include <QtCore/QDebug>
#include <QtCore/QDir>
#include <QtWidgets/QDialog>
#include <QtWidgets/QMessageBox>

#include "save_file_dialog.h"

#define QDIR_2_CSTR(dir) (dir).absolutePath().toStdString().c_str()

void DSSaveFile::bindSignalSlot() {
  connect<void (QComboBox::*)(int)>(ui_.game_combo_box, &QComboBox::activated,
                                    this, &DSSaveFile::OnChooseGame);
  connect(ui_.loadButton, &QPushButton::clicked, this, &DSSaveFile::LoadFile);
  connect(ui_.saveButton, &QPushButton::clicked, this, &DSSaveFile::SaveFile);
  connect(ui_.renameButton, &QPushButton::clicked, this,
          &DSSaveFile::RenameFile);
  connect(ui_.deleteButton, &QPushButton::clicked, this,
          &DSSaveFile::RemoveFile);
}

void DSSaveFile::OnChooseGame(int index) {
  // Not changed
  if (current_game_id_ == index) {
    qDebug("Same game id");
    return;
  }

  QDir save_file_path(app_data_path_);

  // Target game file should exist
  if (!save_file_path.cd(kIndex2Game[index])) {
    QMessageBox::critical(this, kIndex2Game[index], "Game data not found");
    ResetGameId();
    return;
  }

  // There should be a directory as user id
  save_file_path.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
  user_id_.clear();
  for (auto&& entry : save_file_path.entryList()) {
    user_id_ = entry;
    break;
  }
  if (user_id_.isEmpty()) {
    QMessageBox::critical(this, kIndex2Game[index], "User id not found");
    ResetGameId();
    return;
  }
  save_file_path.cd(user_id_);
  if (!save_file_path.exists(kIndex2File[index])) {
    QMessageBox::critical(this, kIndex2Game[index], "Save data not found");
    ResetGameId();
    return;
  }
  if (!save_file_path.exists("backup")) {
    save_file_path.mkdir("backup");
  }
  save_file_path.cd("backup");
  current_game_id_ = index;
  qDebug("Game path changed to: %s", QDIR_2_CSTR(save_file_path));

  ui_.listWidget->clear();
  ui_.listWidget->setCurrentRow(-1);
  save_file_path.setFilter(QDir::Files);
  for (auto&& entry : save_file_path.entryList()) {
    ui_.listWidget->addItem(entry);
  }
  ui_.listWidget->setCurrentRow(ui_.listWidget->count() == 0 ? -1 : 0);
}

void DSSaveFile::LoadFile() {
  // Nothing selected
  if (ui_.listWidget->currentRow() == -1) {
    qDebug("Empty load");
    return;
  }

  QDir save_file_path(app_data_path_);
  save_file_path.cd(kIndex2Game[current_game_id_]);
  save_file_path.cd(user_id_);
  save_file_path.cd("backup");
  QFile save_file(
      save_file_path.filePath(ui_.listWidget->currentItem()->text()));
  if (save_file.exists()) {
    save_file_path.cd("..");
    QFile old_save_file(save_file_path.filePath(kIndex2File[current_game_id_]));
    old_save_file.remove();
    save_file.copy(old_save_file.fileName());
  }
}

void DSSaveFile::SaveFile() {
  // Open a dialog to do this
  SaveFileDialog dialog(this);
  connect(&dialog, &SaveFileDialog::PassNewName, this,
          &DSSaveFile::OnNewFileName);
  dialog.exec();
}

void DSSaveFile::RenameFile() {
  QMessageBox::warning(this, "Not implemented", "Can't rename file now!");
}

void DSSaveFile::RemoveFile() {
  auto current_item = ui_.listWidget->currentItem();
  if (current_item == nullptr) {
    return;
  }

  auto current_name = current_item->text();
  auto selection = QMessageBox::question(
      this, "Before delete",
      "Are you sure to delete this file: " + current_name);
  if (selection == QMessageBox::Yes) {
    QDir save_file_path(app_data_path_);
    save_file_path.cd(kIndex2Game[current_game_id_]);
    save_file_path.cd(user_id_);
    save_file_path.cd("backup");
    save_file_path.remove(current_name);
    auto idx = 0;
    for (int idx = 0; idx < ui_.listWidget->count(); ++idx) {
      if (ui_.listWidget->item(idx)->text() == current_name) {
        delete ui_.listWidget->takeItem(idx);
        break;
      }
    }
  }
}

void DSSaveFile::OnNewFileName(QString s) {
  s = kIndex2Prefix[current_game_id_] + s;
  // Check redunction
  QDir save_file_path(app_data_path_);
  save_file_path.cd(kIndex2Game[current_game_id_]);
  save_file_path.cd(user_id_);
  save_file_path.cd("backup");
  QFile save_file(save_file_path.filePath(s));
  if (save_file.exists()) {
    QMessageBox::warning(this, "Save file already exists", "File not saved!");
    return;
  }
  save_file_path.cd("..");
  QFile old_save_file(save_file_path.filePath(kIndex2File[current_game_id_]));
  old_save_file.copy(save_file.fileName());
  ui_.listWidget->addItem(s);
  ui_.listWidget->sortItems();
}
