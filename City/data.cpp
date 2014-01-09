#include "data.h"
#include <QFile>

Data::Data()
{
    QFile file("ResoursesDataBase.txt");
    try{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw((QString)"We coudn't open file.");
    }

    catch(QString e)
    {
            qDebug()<< e;
            return;
    }

    QString line;// = file.readLine();
    QString work;

    bool fl;

    //int numberOfResourses = line.toInt();
    resourse = new ResourceInfo[AOSData::END];

    for(int k = 0; !file.atEnd(); ++k){

        line = file.readLine();

        work = line.section(' ', 0, 0);
        int i = AOSData::Labor;
        for(fl = true; i<AOSData::END && fl; ++i)
        {
            if(AOSData::ResoursesNames[i] == work)
                fl = false;
        }
        if(!fl)
        {
            resourse[i-1].image = new QPixmap(line.section(' ', 1, 1));
            resourse[i-1].image->setDevicePixelRatio(4);
            resourse[i-1].number = line.section(' ', 2, 2).toInt();
            resourse[i-1].text = line.section(' ',3);
            qDebug()<<i<< line.section(' ', 0, 0)<<'\t'<< line.section(' ', 1, 1)<<'\t'<< line.section(' ', 2, 2).toInt()<<'\t'<< resourse[i-1].text<<'\t';
            if(resourse[i-1].image) qDebug() << "Ok";
            else qDebug() << "WHY?!?!?!!";
            qDebug() << '\n';
        }
    }
    int i = AOSData::Labor;
        for(; i<AOSData::END; ++i)
        {
           qDebug() <<i << resourse[i].text << '\t' << resourse[i].number;
        }
}

Data::~Data()
{
    delete [] resourse;
}

ResourceInfo Data::getData(AOSData::Resources res)
{
    return resourse[res];
}

QString Data::getDataText(AOSData::Resources res)
{
    return resourse[res].text;
}

QPixmap Data::getDataImage(AOSData::Resources res)
{
    return *(resourse[res].image);
}

int Data::getDataNumber(AOSData::Resources res)
{
    return resourse[res].number;
}
