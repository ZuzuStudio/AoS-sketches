#ifndef CITYMAP_H
#define CITYMAP_H

#include <QWidget>
#include <QPushButton>
#include <QLayout>

#include "citydialog.h"
#include "warehousedialog.h"
#include "data.h"


class CityMap : public QWidget
{
    Q_OBJECT
public:
    explicit CityMap(Data *cache, QWidget *parent = 0);
    ~CityMap();


private:
    QPushButton* factor1;
    QPushButton* factor2;
    QPushButton* factor3;
    QPushButton* factor4;
    QPushButton* factor5;
    QPushButton* factor6;
    QPushButton* factor7;
    QPushButton* factor8;
    QPushButton* factor9;
    QPushButton* factor10;
    QPushButton* factor11;
    QPushButton* factor12;
    QPushButton* factor13;

    WarehouseDialog* factor_dialog1;
    CityDialog* factor_dialog2;
    CityDialog* factor_dialog3;
    CityDialog* factor_dialog4;
    CityDialog* factor_dialog5;
    CityDialog* factor_dialog6;
    CityDialog* factor_dialog7;
    CityDialog* factor_dialog8;
    CityDialog* factor_dialog9;
    CityDialog* factor_dialog10;
    CityDialog* factor_dialog11;
    CityDialog* factor_dialog12;
    CityDialog* factor_dialog13;

    QGridLayout* lay;


signals:

public slots:

};

#endif // CITYMAP_H
