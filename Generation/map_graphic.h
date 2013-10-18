#ifndef MAP_GRAPHIC_H
#define MAP_GRAPHIC_H

#include <QWidget>
#include "map_logic.h"
#include <QGraphicsSvgItem>

class map_graphic : public QWidget
{
    Q_OBJECT

public:
    map_graphic(QWidget *parent = 0);
    map_graphic(map_logic *lmap);
    QGraphicsSvgItem* getElement(int x, int y);
    ~map_graphic();
private:
    QGraphicsSvgItem ***map;
    QGraphicsSvgItem *land;
    QGraphicsSvgItem *sea;
    map_logic *lmap;
    int width, height;
};

#endif // MAP_GRAPHIC_H
