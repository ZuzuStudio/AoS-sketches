#include "warehousedialog.h"

WarehouseDialog::WarehouseDialog(QString name, Data *cache, QWidget *parent) :
    QDialog(parent),
    lay(new QGridLayout)
{
    setWindowTitle(name);
    labor = new CityInformElement(cache, AOSData::Labor);
    hardDrive = new CityInformElement(cache, AOSData::HardDrive);
    motherboard = new CityInformElement(cache, AOSData::Motherboard);
    processor = new CityInformElement(cache, AOSData::Processor);
    ram = new CityInformElement(cache, AOSData::RAM);

    lay->addWidget(labor, 0,0,2,1);
    lay->addWidget(hardDrive,0,1);
    lay->addWidget(motherboard,1,1);
    lay->addWidget(processor,0,2);
    lay->addWidget(ram,1,2);

    setLayout(lay);
}
