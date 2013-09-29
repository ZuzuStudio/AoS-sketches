#include "map_logic.h"

map_logic::map_logic():
    map(0), width(0), height(0)
{
}

map_logic::map_logic(int n_height, int n_weight):
    height(n_height), weight(n_weight)
{
    map = new LogicItem*[height];
    for(int i = 0; i < height; ++i)
    {
        map[i] = new LogicItem[width];
        for(int n = 0; n < width; ++n)
            map[i][n].type = Sea;
    }
}

map_logic::~map_logic()
{
    for(int i = 0; i < width; ++i)
        delete [] map[i];
    delete [] map;
}

////////////////////////////////////////////

