#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSvgRenderer>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>

class Widget : public QWidget
{
        Q_OBJECT
    public:
        explicit Widget(QWidget *parent = 0);

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

#endif // WIDGET_H
