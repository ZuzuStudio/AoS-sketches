#ifndef CITYLEFTPANNEL_H
#define CITYLEFTPANNEL_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>

#include "cityinformelement.h"
#include "data.h"

class CityLeftPannel : public QWidget
{
    Q_OBJECT
public:
    explicit CityLeftPannel(Data *cache = 0, QWidget *parent = 0);

private:
    CityInformElement *labor;                  // free hands in game(picture+number)
    CityInformElement *workerFirst;            // min hands(picture+number)
    CityInformElement *workerSecond;           // mid hands(picture+number)
    CityInformElement *workerThird;            // max hands(picture+number)
    QVBoxLayout *lay;

};

#endif // CITYLEFTPANNEL_H
