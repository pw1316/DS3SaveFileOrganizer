# DS3SaveFileOrganizer
A save file manager for the game Dark Souls III

## Prerequisites

Visual Studio 2017(_MSC_VER 1916)

Qt 5.10.1(msvc2017_64)

## Usage

First of all, you should make sure your From Software games have savefile layouts as:

```
%APPDATA%\<game name>\<user hash>\<file name>.sl2
%APPDATA%\<game name>\GraphicsConfig.xml
```

### Save File

A save file means one copy of the `<file name>.sl2` file. You could rename the file with no more than 12 characters(character is in `[A-Za-z0-9]`). The name of save file in the same profile should be different.

### Features

- Change game. Currently surpported:
  - Dark Souls III
  - Sekiro: Shadow Dies Twice
- **Load** the save file from the selected backup file
- **Save** the current save data to a backup file with name specified
- * [ ] TODO: **Rename** the selected backup file
- **Delete** the backup file

## Future Work

* [ ] Sort save file by modified date(files are currently sorted by name)
