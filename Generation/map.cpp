#include "map.h"

Map::Map(QWidget *parent) :
    QWidget(parent)
{
    lmap = new map_logic(60,120);
    lmap->generation();
    gmap = new map_graphic(lmap);
}
