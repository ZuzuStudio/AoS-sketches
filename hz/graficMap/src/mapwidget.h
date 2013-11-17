#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QSvgRenderer>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>

class MapWidget : public QWidget
{
        Q_OBJECT
    public:
        explicit MapWidget(QWidget *parent = 0);
        ~MapWidget();

    signals:

    public slots:

    protected:
        void paintEvent(QPaintEvent *event);
        void keyPressEvent(QKeyEvent *event);

    private:
        QSvgRenderer *renderer;
        QImage *image;
        double scale;

};

#endif // MAPWIDGET_H
