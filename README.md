# DS3SaveFileOrganizer
A save file manager for the game Dark Souls III

## Prerequisites

Visual Studio 2017(v141 toolchain)

Qt 5.10.1(msvc2017_64)

## Usage

First of all, you should make sure your DS3 savefile is at the right place:

```
%APPDATA%\DarkSoulsIII\-----<numberstring>\-----DS30000.sl2
                         |
                         ---GraphicsConfig.xml
```

### Profile

A profile means a set of save files saved by you. Infact, one Profile is one directory at the same path as `DS30000.sl2`, which means the name of each profile is unique

* [ ] TODO: You should pre-create the profile directory before starting the program, a feature of creating new profile will be added.

### Save File

A save file means one copy of the `DS30000.sl2` file. You could rename the file with no more than 12 characters(character is in `[A-Za-z0-9]`). The name of save file in the same profile should be different, but could be the same in different profiles.

### Features

Load the save file `f` from profile `p`

Save the current save data at profile `p` with name `f`

* [ ] TODO: Rename the save file `f` to `f1` in the profile `p`

Delete the save file `f` in the profile `p`

* [ ] TODO: Add new profile `p`

## Future Work

* [ ] Sort save file by modified date
* [ ] 2-step check before load
