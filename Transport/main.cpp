#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    
    QFile file1("data");
    //if(!file1.open(QIODevice::WriteOnly))
    //     qDebug()<<"ERRRR";
    //file1.close();

    return a.exec();
}
