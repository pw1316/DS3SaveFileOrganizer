#ifndef __DS_SAVE_FILE_H__
#define __DS_SAVE_FILE_H__

#include <QtCore/QString>
#include <QtWidgets/QMainWindow>

#include "ui_save_file.h"

#include "app_data_wrapper.h"

class DSSaveFile : public QMainWindow {
  Q_OBJECT

  static constexpr char* kIndex2Game[] = {"DarkSoulsIII", "Sekiro"};
  static constexpr char* kIndex2File[] = {"DS30000.sl2", "S0000.sl2"};
  static constexpr char* kIndex2Prefix[] = {"DS3-", "Sekiro-"};

 public:
  DSSaveFile(QWidget* parent = Q_NULLPTR) {
    ui_.setupUi(this);
    bindSignalSlot();
    app_data_path_ = GetAppDataPath();
    OnGameChanged(ui_.game_combo_box->currentIndex());
  }

 private:
  void bindSignalSlot();

  Ui::DSSaveFileClass ui_;
  QString app_data_path_;
  QString user_id_;

 public slots:
  void OnGameChanged(int index);
  void OnProfileChanged(int index);
  void LoadFile();
  void SaveFile();
  void OnNewFileName(QString s);
  void RenameFile();
  void RemoveFile();
};
#endif
