#include "map_logic.h"

map_logic::map_logic():
    map(0), width(0), height(0)
{
}

map_logic::map_logic(int n_height, int n_width):
    height(n_height), width(n_width)
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
    deleteMap();
}

////////////////////////////////////////////

void map_logic::resize(int n_height, int n_width)
{
    if(height == n_height)
    {
        if(width == n_width){}
        else
        {
            width = n_width;
            for(int i = 0; i < height; ++i)
            {
                delete [] map[i];
                map[i] = new LogicItem[width];
                for(int n = 0; n < width; ++n)
                    map[i][n].type = Sea;
            }
        }
        deleteMap();
        width = n_width;
        height = n_height;
        map = new LogicItem*[height];
        for(int i = 0; i < height; ++i)
        {
            map[i] = new LogicItem[width];
            for(int n = 0; n < width; ++n)
                map[i][n].type = Sea;
        }
    }
}

LogicItem map_logic::getElement(int row, int column)
{
    return map[row][column];
}

void map_logic::changeType(Territori n_type, int row, int column)
{
    map[row][column].type = n_type;
}

void map_logic::deleteMap()
{
    for(int i = 0; i < width; ++i)
        delete [] map[i];
    delete [] map;
}

void map_logic::generation()
{
    srand(time(NULL));
    int x,y;
    for(int k = 0; k <35; ++k){
        x = rand()%160;
        y= rand()%860;
    for(int i = 0; i < 40; ++i){
        for(int n = 0; n < 40; ++n)
        map[i+x][n+y].type = Land;
    }
    }
    makeFractal((width+height)/4);
    makeFile();
}

void map_logic::makeFractal(int step) {
  for (int y=0; y<width; y+=step) {
    for (int x=0; x<height; x+=step) {

      int cx=x+ ((rand()%2) ? 0 : step);
      int cy=y+ ((rand()%2) ? 0 : step);

      cx=(cx/(step*2))*step*2;
      cy=(cy/(step*2))*step*2;

      cx=cx%height;
      cy=cy%width;

      changeType(getElement(cx,cy).type, x, y);
    }
  }

    if (step>1) makeFractal(step/2);
  }

void map_logic::makeFile(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    for(int i = 0; i < height; ++i){
        for(int n = 0; n < width; ++n)
            out << map[i][n].type;
        out << '\n';
    }
}
