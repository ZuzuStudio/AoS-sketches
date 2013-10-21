#include "widget.h"
#include <QDebug>
#include <qmath.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    renderer(0),
    image(0),
    scale(3.0)
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
    imagePainter.fillRect(0, 0, size().width(), size().height(), Qt::white);

    for(int i = 0; i < 30; ++i)
        for(int j = 0; j < 30; ++j)
            renderer->render(&imagePainter, QRectF((j & 1) * 0.75 * scale + scale * 1.5 * i, sqrt(3.0)*scale * j / 4.0, scale, scale));

    imagePainter.end();
    //-------------//
    QPainter p(this);
    p.drawImage(0, 0, *image);
    Q_UNUSED(event);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_A:
            scale *= 1.05;
            repaint();
            break;

        case Qt::Key_D:
            scale /= 1.05;
            repaint();
            break;

        default:
            QWidget::keyPressEvent(event);
            break;
    }
}
