#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:

     QWidget *window;
     QVBoxLayout *layoutbase;
     QHBoxLayout *layout[5];
     QSlider *slider[5];
     QSpinBox *spinBox[5];
     QLabel *labels[5];
     QPushButton *quit;
};

#endif // WIDGET_H
