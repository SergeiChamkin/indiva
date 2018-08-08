#include "setwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SetWindow w;
    w.show();

    return a.exec();
}
