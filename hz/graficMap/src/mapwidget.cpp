#include "mapwidget.h"
#include <QDebug>
#include <qmath.h>

MapWidget::MapWidget(QWidget *parent) :
    QWidget(parent),
    renderer(0),
    image(0),
    scale(30.0)
{
    image = new QImage(size(), QImage::Format_ARGB32_Premultiplied);
    renderer = new QSvgRenderer(QString("../../hillFlatLod2_res.svg"), this);//QString("../../hillFlat_res.svg")//QString("../src/files/bubbles.svg")
    //---------------//
    connect(renderer, SIGNAL(repaintNeeded()), this, SLOT(repaint()));
}

MapWidget::~MapWidget()
{
    delete image;
}

void MapWidget::paintEvent(QPaintEvent *event)
{
    if(image->size() != this->size())
    {
        delete image;
        image = new QImage(size(), QImage::Format_ARGB32_Premultiplied);
    }

    QPainter imagePainter(image);
    imagePainter.fillRect(0, 0, size().width(), size().height(), Qt::white);

    for(int j = 0; j < 21; ++j)
        for(int i = 0; i < 18; ++i)
            renderer->render(&imagePainter, QRectF(sqrt(3.0)*scale * i / 2.0 + (j & 1) * sqrt(3.0) * scale / 4.0 - 1, scale * 0.75 * j - 1, scale + 2, scale + 2));

    imagePainter.end();
    //-------------//
    QPainter p(this);
    p.drawImage(0, 0, *image);
    Q_UNUSED(event);
}

void MapWidget::keyPressEvent(QKeyEvent *event)
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
