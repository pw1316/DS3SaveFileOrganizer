#include "DSSaveFile.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DSSaveFile w;
    w.show();
    return a.exec();
}
