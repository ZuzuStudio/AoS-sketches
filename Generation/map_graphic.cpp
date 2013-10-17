#include "map_graphic.h"

map_graphic::map_graphic(map_logic *lmap):
    width(lmap->getWidth()),
    height(lmap->getHeight())
{
    land = new QGraphicsSvgItem(":/files/Land.svg");
    sea = new QGraphicsSvgItem(":/files/Sea.svg");

    map = new QGraphicsSvgItem**[height];
    for(int i = 0; i < height; ++i)
    {
        map[i] = new QGraphicsSvgItem*[width];
        for(int k = 0; k < width; ++k)
            if(lmap->getElement(i,k).type)
                map[i][k] = new QGraphicsSvgItem(sea);
            else
                map[i][k] = new QGraphicsSvgItem(land);
    }
}

map_graphic::~map_graphic()
{

}
