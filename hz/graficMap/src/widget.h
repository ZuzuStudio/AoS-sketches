#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSvgRenderer>
#include <QImage>
#include <QPainter>

class Widget : public QWidget
{
        Q_OBJECT
    public:
        explicit Widget(QWidget *parent = 0);

    signals:

    public slots:

    protected:
        void paintEvent(QPaintEvent *event);

    private:
        QSvgRenderer *renderer;
        QImage image;

};

#endif // WIDGET_H
