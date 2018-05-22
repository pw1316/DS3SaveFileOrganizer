#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_DSSaveFile.h"
#include <QtCore/QString>

class DSSaveFile : public QMainWindow
{
    Q_OBJECT

public:
    DSSaveFile(QWidget *parent = Q_NULLPTR);

private:
    void bindSignalSlot();
    void inintializeWithPath();

    const QString saveFileName = "DS30000.sl2";

    Ui::DSSaveFileClass ui;
    QString savedataPath;
    QString userId;
    int savedProfileIndex = 0;

public slots:
    void loadFile();
    void saveFile();
    void renameFile();
    void deleteFile();
    void onProfileChanged(int index);
    void onNewFileName(QString s);
};
