#include "city.h"
#include "data.h"
#include <QApplication>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Data *cache = new Data;
    City w(cache);
    w.show();

    return a.exec();
}
