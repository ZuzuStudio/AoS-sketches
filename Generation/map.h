#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <SvgView>
#include "map_logic.h"
#include "map_graphic.h"

class Map : public QWidget
{
    Q_OBJECT
public:
    explicit Map(QWidget *parent = 0);

private:
    map_logic *lmap;
    map_graphic *gmap;

    SvgView *m_view;

signals:

public slots:

};

#endif // MAP_H
