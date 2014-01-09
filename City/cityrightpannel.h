#ifndef CITYRIGHTPANNEL_H
#define CITYRIGHTPANNEL_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>

#include "cityinformelement.h"
#include "data.h"

class CityRightPannel : public QWidget
{
    Q_OBJECT
public:
    explicit CityRightPannel(Data *cache = 0, QWidget *parent = 0);

protected:
    CityInformElement *hardDrive;              // wheat(in a normal mod)
    CityInformElement *motherboard;            // apple(in a normal mod)
    CityInformElement *processor;              // fish(in a normal mod)
    CityInformElement *ram;                    // meat((in a normal mod)
    QVBoxLayout *lay;



};

#endif // CITYRIGHTPANNEL_H
