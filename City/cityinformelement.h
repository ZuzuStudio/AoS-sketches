#ifndef CITYINFORMELEMENT_H
#define CITYINFORMELEMENT_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QString>
#include <QGraphicsSvgItem>

#include "data.h"


class CityInformElement : public QWidget
{
    Q_OBJECT
public:
    explicit CityInformElement(Data *cache, AOSData::Resources name , QWidget *parent = 0);

private:
    QLabel *picture;
    QLabel *text;
    QVBoxLayout *lay;

signals:

public slots:
    void changeValue(int num);

};

#endif // CITYINFORMELEMENT_H
