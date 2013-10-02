#ifndef MAP_GRAPHIC_H
#define MAP_GRAPHIC_H

#include <QWidget>
#include "map_logic.h"

class map_graphic : public QWidget
{
    Q_OBJECT

public:
    map_graphic(QWidget *parent = 0);
    ~map_graphic();
private:
    map_logic *map;
};

#endif // MAP_GRAPHIC_H
