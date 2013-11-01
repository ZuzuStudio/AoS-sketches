#include "map_graphic.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    map_graphic w;
    w.show();

    return a.exec();
}
