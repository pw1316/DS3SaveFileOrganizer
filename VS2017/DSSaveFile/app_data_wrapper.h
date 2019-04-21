#ifndef __APP_DATA_WRAPPER_H__
#define __APP_DATA_WRAPPER_H__

#include <QtCore/QString>

#ifdef _WIN32
#include <ShlObj.h>
inline QString GetAppDataPath() {
  char buffer[256];
  SHGetSpecialFolderPathA(nullptr, buffer, CSIDL_APPDATA, false);
  return buffer;
}
#else
#error Not Implemented!
#endif
#endif
