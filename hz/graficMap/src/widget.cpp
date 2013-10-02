#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    renderer(0)
{
    renderer = new QSvgRenderer(QString("../src/files/bubbles.svg"), this);//QString("../../hillFlat_res.svg")
    //---------------//
    connect(renderer, SIGNAL(repaintNeeded()), this, SLOT(repaint()));
}

void Widget::paintEvent(QPaintEvent *event)
{
    if(image.size() != this->size())
    {
        image = QImage(size(), QImage::Format_ARGB32_Premultiplied);
    }

    QPainter imagePainter(&image);
    renderer->render(&imagePainter);
    imagePainter.end();
    //-------------//
    QPainter p(this);
    p.drawImage(0, 0, image);
    Q_UNUSED(event);
}
