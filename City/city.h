#ifndef CITY_H
#define CITY_H

#include <QWidget>
#include <QLayout>

#include "citymap.h"
#include "cityleftpannel.h"
#include "cityrightpannel.h"
#include "data.h"

class City : public QWidget
{
    Q_OBJECT

public:
    City(Data *cache = 0,QWidget *parent = 0);
    ~City();

private:
    CityMap *map;

    QPushButton *backButton;
    QPushButton *helpButton;

    CityLeftPannel *leftPannel;
    CityRightPannel *rightPannel;
    QGridLayout *lay;

signals:
    void backClicked();
    void helpClicked();

private slots:
    void back();
    void help();

};

#endif // CITY_H
