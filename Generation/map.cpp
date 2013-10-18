#include "map.h"
#include <QWheelEvent>
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QtCore>

Map::Map(int height, int width) :
    height(height),
    width(width)
{
    lmap = new map_logic(height,width);
    lmap->generation();
    gmap = new map_graphic(lmap);


    setScene(new QGraphicsScene(this));
    setTransformationAnchor(AnchorUnderMouse);
    setDragMode(ScrollHandDrag);
    setViewportUpdateMode(FullViewportUpdate);


    /*QPixmap tilePixmap(64, 64);
    tilePixmap.fill(Qt::white);
    QPainter tilePainter(&tilePixmap);
    QColor color(220, 220, 220);
    tilePainter.fillRect(0, 0, 32, 32, color);
    tilePainter.fillRect(32, 32, 32, 32, color);
    tilePainter.end();

    setBackgroundBrush(tilePixmap);*/
    draw();
}

void Map::draw()
{
    QGraphicsScene *s = scene();

    s->clear();
    resetTransform();

    for(int i = 0; i < width; ++i)
        for(int k = 0; k < height; ++k)
            s->addItem(gmap->getElement(i,k));
}

void Map::wheelEvent(QWheelEvent *event)
{
    qreal p = event->delta() / 240.0;
    qreal factor = qPow(1.2, p);
    scale(factor, factor);
    event->accept();
}
