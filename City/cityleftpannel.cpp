#include "cityleftpannel.h"

CityLeftPannel::CityLeftPannel(Data *cache, QWidget *parent) :
    QWidget(parent),
    lay(new QVBoxLayout),
    labor(new CityInformElement(cache, AOSData::Labor)),
    workerFirst(new CityInformElement(cache, AOSData::FirstWorker)),
    workerSecond(new CityInformElement(cache, AOSData::SecondWorker)),
    workerThird(new CityInformElement(cache, AOSData::ThirdWorker))
{
    lay->addWidget(labor);
    lay->addWidget(workerFirst);
    lay->addWidget(workerSecond);
    lay->addWidget(workerThird);

    lay->setAlignment(Qt::AlignTop);


    setLayout(lay);
}


