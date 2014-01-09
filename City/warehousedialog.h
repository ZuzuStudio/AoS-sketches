#ifndef WAREHOUSEDIALOG_H
#define WAREHOUSEDIALOG_H

#include <QDialog>
#include <QLayout>

#include "cityinformelement.h"
#include "data.h"

class WarehouseDialog : public QDialog
{
    Q_OBJECT
public:
    explicit WarehouseDialog(QString name, Data *cache = 0, QWidget *parent = 0);
    
private:
    CityInformElement *labor;                  // free hands in game(picture+number)
    CityInformElement *hardDrive;              // wheat(in a normal mod)
    CityInformElement *motherboard;            // apple(in a normal mod)
    CityInformElement *processor;              // fish(in a normal mod)
    CityInformElement *ram;                    // meat((in a normal mod)
    QGridLayout *lay;
    
signals:

public slots:

};

#endif // WAREHOUSEDIALOG_H
