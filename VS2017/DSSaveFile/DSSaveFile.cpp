#include "DSSaveFile.h"
#include <assert.h>
#include <ShlObj.h>

#include <QtCore/QDebug>
#include <QtCore/QDir>
#include <QtWidgets/QDialog>
#include <QtWidgets/QMessageBox>

#include "SaveFileDialog.h"

DSSaveFile::DSSaveFile(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    bindSignalSlot();
    char buffer[256];
    SHGetSpecialFolderPathA(nullptr, buffer, CSIDL_APPDATA, false);
    savedataPath = buffer;
    savedataPath += "\\DarkSoulsIII";
    inintializeWithPath();
}

void DSSaveFile::bindSignalSlot()
{
    connect(ui.loadButton, &QPushButton::clicked, this, &DSSaveFile::loadFile);
    connect(ui.saveButton, &QPushButton::clicked, this, &DSSaveFile::saveFile);
    connect(ui.renameButton, &QPushButton::clicked, this, &DSSaveFile::renameFile);
    connect(ui.deleteButton, &QPushButton::clicked, this, &DSSaveFile::deleteFile);
    connect<void (QComboBox::*)(int)>(ui.comboBox, &QComboBox::currentIndexChanged, this, &DSSaveFile::onProfileChanged);//Signal is overloaded
}

void DSSaveFile::inintializeWithPath()
{
    QDir dir(savedataPath);
    if (!dir.exists())
    {
        QMessageBox::critical(this, "Save data not found", "Can not find DarkSoulsIII's save file!");
        exit(1);
    }
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    /* Treat the first as where the save file is */
    for (const auto &entry : dir.entryList())
    {
        userId = entry;
        dir.cd(dir.filePath(entry));
        break;
    }
    /* Profiles */
    for (const auto &entry : dir.entryList())
    {
        ui.comboBox->addItem(entry);
    }
    ui.comboBox->addItem("Add new profile");
    /* Save Data */
    ui.comboBox->setCurrentIndex(0);
    savedProfileIndex = 0;
    /* No Profile, should create one first */
    if (ui.comboBox->itemText(0) == "Add new profile")
    {
        /// TODO Create profile and set as current
    }
    QDir profileDir(dir.filePath(ui.comboBox->itemText(0)));
    profileDir.setFilter(QDir::Files);
    for (const auto &entry : profileDir.entryList())
    {
        ui.listWidget->addItem(entry);
    }
    if (ui.listWidget->count() > 0)
    {
        ui.listWidget->setCurrentRow(0);
    }
}

void DSSaveFile::loadFile()
{
    /* No save file in current profile */
    if (ui.listWidget->count() == 0)
    {
        return;
    }
    auto curProfile = ui.comboBox->currentText();
    auto curFileName = ui.listWidget->currentItem()->text();
    QDir dir(savedataPath);
    dir.cd(userId);
    dir.cd(curProfile);
    QFile file(dir.filePath(curFileName));
    if (file.exists())
    {
        dir.cd("..");
        QFile f(dir.filePath(saveFileName));
        f.remove();
        file.copy(dir.filePath(saveFileName));
    }
}

void DSSaveFile::saveFile()
{
    SaveFileDialog dialog(this);
    connect(&dialog, &SaveFileDialog::passNewName, this, &DSSaveFile::onNewFileName);
    dialog.exec();
}

void DSSaveFile::renameFile()
{
    qDebug() << "rename";
}

void DSSaveFile::deleteFile()
{
    auto cur = ui.listWidget->currentItem();
    if (cur == nullptr)
    {
        return;
    }
    auto curName = cur->text();
    auto selection = QMessageBox::question(this, "Before delete", "Are you sure to delete this file: " + curName);
    if (selection == QMessageBox::Yes)
    {
        QDir dir(savedataPath);
        dir.cd(userId);
        assert(ui.comboBox->count() > 0);
        dir.cd(ui.comboBox->currentText());
        dir.remove(curName);
        auto idx = 0;
        for (; idx < ui.listWidget->count(); ++idx)
        {
            if (ui.listWidget->item(idx)->text() == curName)
            {
                break;
            }
        }
        if (idx < ui.listWidget->count())
        {
            ui.listWidget->takeItem(idx);
        }
    }
}

void DSSaveFile::onProfileChanged(int index)
{
    if (index == ui.comboBox->count() - 1)
    {
        ui.comboBox->setCurrentIndex(savedProfileIndex);
        /// TODO Create new Profile
    }
    else
    {
        savedProfileIndex = index;
        ui.listWidget->clear();
        QDir dir(savedataPath);
        dir.cd(userId);
        dir.cd(ui.comboBox->itemText(index));
        dir.setFilter(QDir::Files);
        for (const auto &entry : dir.entryList())
        {
            ui.listWidget->addItem(entry);
        }
        if (ui.listWidget->count() > 0)
        {
            ui.listWidget->setCurrentRow(0);
        }
    }
}

void DSSaveFile::onNewFileName(QString s)
{
    s = "DS3-" + s;
    /* Check redunction */
    QDir dir(savedataPath);
    dir.cd(userId);
    assert(ui.comboBox->count() > 0);
    dir.cd(ui.comboBox->currentText());
    QFile file(dir.filePath(s));
    if (file.exists())
    {
        QMessageBox::warning(this, "Save file already exists", "Can not create file with the same name as existing files!");
        return;
    }
    dir.cd("..");
    QFile originalFile(dir.filePath(saveFileName));
    originalFile.copy(file.fileName());
    ui.listWidget->addItem(s);
    ui.listWidget->sortItems();
}
