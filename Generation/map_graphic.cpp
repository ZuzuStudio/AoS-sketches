#include "map_graphic.h"

map_graphic::map_graphic(QWidget *parent)
    : QWidget(parent)
{
    map = new map_logic(200,900);
    map->generation();
}

map_graphic::~map_graphic()
{

}
