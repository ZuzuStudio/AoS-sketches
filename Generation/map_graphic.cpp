#include "map_graphic.h"

map_graphic::map_graphic(map_logic *lmap):
    width(lmap->getWidth()),
    height(lmap->getHeight())
{
    /*QGraphicsSvgItem *lands = new QGraphicsSvgItem(":/files/Land.svg");
    //seas = new QGraphicsSvgItem(":/files/Sea.svg");*/

    int x = 0, y = 0;
    map = new QGraphicsSvgItem**[height];
    for(int i = 0; i < height; ++i)
    {
        map[i] = new QGraphicsSvgItem*[width];
        for(int k = 0; k < width; ++k)
        {
            if(lmap->getElement(i,k).type)
                map[i][k] = new QGraphicsSvgItem(":/files/Sea.svg");
            else
                map[i][k] = new QGraphicsSvgItem(":/files/Land.svg");
            map[i][k]->setPos(x,y);
            x +=186;
            if((k%2))y += 119;
            else y -=119;
    }
    y +=238;
    x = 0;
    }
}

QGraphicsSvgItem* map_graphic::getElement(int x, int y)
{
    return map[y][x];
}

map_graphic::~map_graphic()
{

}
