#include "widget.h"
#include <QDebug>
#include <qmath.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    renderer(0)
{
    image = new QImage(size(), QImage::Format_ARGB32_Premultiplied);
    renderer = new QSvgRenderer(QString("../../hillFlat_res.svg"), this);//QString("../../hillFlat_res.svg")//QString("../src/files/bubbles.svg")
    //---------------//
    connect(renderer, SIGNAL(repaintNeeded()), this, SLOT(repaint()));
}

void Widget::paintEvent(QPaintEvent *event)
{
    if(image->size() != this->size())
    {
        delete image;
        image = new QImage(size(), QImage::Format_ARGB32_Premultiplied);
    }

    QPainter imagePainter(image);
    imagePainter.fillRect(0,0,size().width(),size().height(),Qt::white);
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j <3; ++j)
            renderer->render(&imagePainter,QRectF(300*i,sqrt(3.0)*150*j,300,300));
    imagePainter.end();
    //-------------//
    QPainter p(this);
    p.drawImage(0, 0, *image);
    Q_UNUSED(event);
}
