#include "map.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Map w(60,120);
    w.show();

    return a.exec();
}
