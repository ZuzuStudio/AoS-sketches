#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    renderer(0)
{
    image = new QImage(size(), QImage::Format_ARGB32_Premultiplied);
    renderer = new QSvgRenderer(QString("../src/files/bubbles.svg"), this);//QString("../../hillFlat_res.svg")
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
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j <2; ++j)
            renderer->render(&imagePainter,QRectF(200*i,200*j,200,200));
    imagePainter.end();
    //-------------//
    QPainter p(this);
    p.drawImage(0, 0, *image);
    Q_UNUSED(event);
}
