#include "cityinformelement.h"
#include <QApplication>
#include <QDesktopWidget>

CityInformElement::CityInformElement(Data *cache, AOSData::Resources name, QWidget *parent) :
    QWidget(parent),
    lay(new QVBoxLayout),
    picture(new QLabel),
    text(new QLabel)
{
    if(&(cache->getDataImage(name))) qDebug() << "Image Ok"<<AOSData::ResoursesNames[name];
    else qDebug() << "Image WHY?!?!?!!";
    qDebug() << '\n';

    picture->setPixmap(cache->getDataImage(name));


    text->setAlignment(Qt::AlignCenter);
    lay->addWidget(picture);
    lay->addWidget(text);
    lay->setAlignment(Qt::AlignCenter);

    lay->setContentsMargins(0,0,0,0);

    setLayout(lay);

    changeValue(cache->getDataNumber(name));
}

void CityInformElement::changeValue(int num)
{
    if(num == 0){
        setVisible(false);
    }
    else{
        if(num <= -1)
        {
            text->setText("+");
        }
        else
            text->setText(QString::number(num));
        setVisible(true);
    }
}
