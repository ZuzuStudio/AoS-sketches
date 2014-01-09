#ifndef CITYDATA_H
#define CITYDATA_H

#include <QPixmap>
#include <QString>
#include <QFile>
#include <QDebug>


namespace AOSData{

enum Resources{Labor, FirstWorker, SecondWorker,
               ThirdWorker, HardDrive, Motherboard,
               Processor,RAM,END};
const QString ResoursesNames[] ={"Labor", "FirstWorker", "SecondWorker",
                             "ThirdWorker", "HardDrive", "Motherboard",
                             "Processor","RAM"};

}

struct ResourceInfo{
    QPixmap *image;
    QString text;
    int number;
};

class Data
{
public:
    Data();
    ~Data();

    ResourceInfo getData(AOSData::Resources res);
    QString getDataText(AOSData::Resources res);
    QPixmap getDataImage(AOSData::Resources res);
    int getDataNumber(AOSData::Resources res);

private:
    ResourceInfo *resourse;

};


#endif // CITYDATA_H
