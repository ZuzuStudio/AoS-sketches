#ifndef MAP_GRAPHIC_H
#define MAP_GRAPHIC_H

#include <QWidget>

class map_graphic : public QWidget
{
    Q_OBJECT

public:
    map_graphic(QWidget *parent = 0);
    ~map_graphic();
};

#endif // MAP_GRAPHIC_H
