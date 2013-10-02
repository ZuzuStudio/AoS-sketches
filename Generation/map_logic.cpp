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
    int x, y;
    for(int i = 0; i < 3; ++i){
        x = (width+height)/8;
        y = (width+height)/8;
        map[x*i][y*i].type = Land;
    }
    makeFractal((width+height)/8);
    makeFile();
}

void map_logic::makeFractal(int step) {
  for (int y=0; y<width; y+=step) {
    for (int x=0; x<height; x+=step) {
      // Внутренний цикл вычисляет (cx,cy)
      // это точка от которой копируется цвет карты

      // добавить случайное смещение
      int cx=x+ ((rand()%2) ? 0 : step);
      int cy=y+ ((rand()%2) ? 0 : step);

      // округлить до ближайшего произведения от step*2
      // где step*2 предыдущий уровень даталирования
      cx=(cx/(step*2))*step*2;
      cy=(cy/(step*2))*step*2;

      // вращать мир как тор
      // для гарантии что getCell() и setCell() в пределах границ
      cx=cx%height;
      cy=cy%width;

      // копировать из (cx,cy) в (x,y)
      changeType(getElement(cx,cy).type, x, y);
    }
  }

    // рекурсивное вычисление слудующего уровня детализации
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
