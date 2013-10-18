#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QLayout>
#include "map_logic.h"
#include "map_graphic.h"

#include <QGraphicsView>

class Map : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Map(int height, int width);

private:
    map_logic *lmap;
    map_graphic *gmap;
    int width, height;

protected:
    void wheelEvent(QWheelEvent *event);

signals:

public slots:
    void draw();

};

#endif // MAP_H
