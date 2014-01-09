#include "cityrightpannel.h"

CityRightPannel::CityRightPannel(Data * cache, QWidget *parent) :
    QWidget(parent),
    hardDrive(new CityInformElement(cache, AOSData::HardDrive)),
    motherboard(new CityInformElement(cache, AOSData::Motherboard)),
    processor(new CityInformElement(cache, AOSData::Processor)),
    ram(new CityInformElement(cache, AOSData::RAM)),
    lay(new QVBoxLayout)
{
    lay->addWidget(hardDrive);
    lay->addWidget(motherboard);
    lay->addWidget(processor);
    lay->addWidget(ram);

    lay->setAlignment(Qt::AlignTop);


    setLayout(lay);
}



