#include <QtWidgets/QApplication>

#include "save_file.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  DSSaveFile w;
  w.show();
  return a.exec();
}
