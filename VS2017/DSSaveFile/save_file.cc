#include "save_file.h"

#include <assert.h>

#include <QtCore/QDebug>
#include <QtCore/QDir>
#include <QtWidgets/QDialog>
#include <QtWidgets/QMessageBox>

#include "save_file_dialog.h"

void DSSaveFile::bindSignalSlot() {
  connect<void (QComboBox::*)(int)>(ui_.game_combo_box,
                                    &QComboBox::currentIndexChanged, this,
                                    &DSSaveFile::OnGameChanged);
  connect<void (QComboBox::*)(int)>(ui_.profile_combo_box,
                                    &QComboBox::currentIndexChanged, this,
                                    &DSSaveFile::OnProfileChanged);
  connect(ui_.loadButton, &QPushButton::clicked, this, &DSSaveFile::LoadFile);
  connect(ui_.saveButton, &QPushButton::clicked, this, &DSSaveFile::SaveFile);
  connect(ui_.renameButton, &QPushButton::clicked, this,
          &DSSaveFile::RenameFile);
  connect(ui_.deleteButton, &QPushButton::clicked, this,
          &DSSaveFile::RemoveFile);
}

void DSSaveFile::OnGameChanged(int index) {
  QDir save_file_path(app_data_path_);
  if (!save_file_path.cd(kIndex2Game[index])) {
    QMessageBox::critical(this, "Save data not found", kIndex2Game[index]);
    exit(1);
  }
  auto s = save_file_path.absolutePath();
  save_file_path.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
  user_id_.clear();
  for (auto&& entry : save_file_path.entryList()) {
    user_id_ = entry;
    break;
  }
  if (user_id_.isEmpty()) {
    QMessageBox::critical(this, "User id not found", kIndex2Game[index]);
    exit(1);
  }
  save_file_path.cd(user_id_);

  // Read profiles
  ui_.profile_combo_box->clear();
  for (auto&& entry : save_file_path.entryList()) {
    ui_.profile_combo_box->addItem(entry);
  }
  if (ui_.profile_combo_box->count() == 0) {
    // TODO Create profile and set as current
    QMessageBox::critical(this, "Profile not found",
                          "Please create one first!");
    exit(1);
  }
  OnProfileChanged(ui_.profile_combo_box->currentIndex());
}

void DSSaveFile::OnProfileChanged(int index) {
  int game_id = ui_.game_combo_box->currentIndex();
  QDir save_file_path(app_data_path_);
  save_file_path.cd(kIndex2Game[game_id]);
  save_file_path.cd(user_id_);
  save_file_path.cd(ui_.profile_combo_box->itemText(index));
  save_file_path.setFilter(QDir::Files);
  ui_.listWidget->clear();
  for (auto&& entry : save_file_path.entryList()) {
    ui_.listWidget->addItem(entry);
  }
  if (ui_.listWidget->count() > 0) {
    ui_.listWidget->setCurrentRow(0);
  }
}

void DSSaveFile::LoadFile() {
  if (ui_.listWidget->count() == 0) {
    return;
  }

  int game_id = ui_.game_combo_box->currentIndex();
  QDir save_file_path(app_data_path_);
  save_file_path.cd(kIndex2Game[game_id]);
  save_file_path.cd(user_id_);
  save_file_path.cd(ui_.profile_combo_box->currentText());
  QFile save_file(
      save_file_path.filePath(ui_.listWidget->currentItem()->text()));
  if (save_file.exists()) {
    save_file_path.cd("..");
    QFile old_save_file(save_file_path.filePath(kIndex2File[game_id]));
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

void DSSaveFile::OnNewFileName(QString s) {
  int game_id = ui_.game_combo_box->currentIndex();
  s = kIndex2Prefix[game_id] + s;
  // Check redunction
  QDir save_file_path(app_data_path_);
  save_file_path.cd(kIndex2Game[game_id]);
  save_file_path.cd(user_id_);
  save_file_path.cd(ui_.profile_combo_box->currentText());
  QFile save_file(save_file_path.filePath(s));
  if (save_file.exists()) {
    QMessageBox::warning(this, "Save file already exists", "File not saved!");
    return;
  }
  save_file_path.cd("..");
  QFile old_save_file(save_file_path.filePath(kIndex2File[game_id]));
  old_save_file.copy(save_file.fileName());
  ui_.listWidget->addItem(s);
  ui_.listWidget->sortItems();
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
    int game_id = ui_.game_combo_box->currentIndex();
    QDir save_file_path(app_data_path_);
    save_file_path.cd(kIndex2Game[game_id]);
    save_file_path.cd(user_id_);
    save_file_path.cd(ui_.profile_combo_box->currentText());
    save_file_path.remove(current_name);
    auto idx = 0;
    for (int idx = 0; idx < ui_.listWidget->count(); ++idx) {
      if (ui_.listWidget->item(idx)->text() == current_name) {
        ui_.listWidget->takeItem(idx);
        break;
      }
    }
  }
}
