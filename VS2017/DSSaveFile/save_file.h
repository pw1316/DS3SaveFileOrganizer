#ifndef __DS_SAVE_FILE_H__
#define __DS_SAVE_FILE_H__

#include <QtCore/QString>
#include <QtWidgets/QMainWindow>

#include "ui_save_file.h"

#include "app_data_wrapper.h"

class DSSaveFile : public QMainWindow {
  Q_OBJECT

  static constexpr char* kIndex2Game[] = {"???", "DarkSoulsIII", "Sekiro"};
  static constexpr char* kIndex2File[] = {"???", "DS30000.sl2", "S0000.sl2"};
  static constexpr char* kIndex2Prefix[] = {"???", "DS3-", "Sekiro-"};

 public:
  DSSaveFile(QWidget* parent = Q_NULLPTR) {
    ui_.setupUi(this);
    bindSignalSlot();
    app_data_path_ = GetAppDataPath();
    ResetGameId();
  }

 private:
  void bindSignalSlot();
  void ResetGameId() {
    current_game_id_ = -1;
    ui_.game_combo_box->setCurrentIndex(-1);
    ui_.listWidget->clear();
    ui_.listWidget->setCurrentRow(-1);
  }

  Ui::DSSaveFileClass ui_;
  QString app_data_path_;
  QString user_id_;

  int current_game_id_ = -1;

 public slots:
  void OnChooseGame(int index);
  void LoadFile();
  void SaveFile();
  void RenameFile();
  void RemoveFile();
  void OnNewFileName(QString s);
};
#endif
