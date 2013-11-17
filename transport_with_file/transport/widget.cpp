#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent),
      window(new QWidget),
      layoutbase(new QVBoxLayout()),
      quit(new QPushButton(tr("Exit")))

{
    int size, element=0;
    int *array=new int[10];
    readFile(array,size);

    for(int i=0; i<size; ++i)
        qDebug()<<array[i];
    qDebug()<<size;


    setWindowTitle ("Transport");
    setGeometry(100,100,400,300);

    for(int i=0;i<5;i++)
    {
        int value=array[element];

        layout[i] = new QHBoxLayout();
        slider[i]=new QSlider(Qt::Horizontal);
        spinBox[i]=new QSpinBox();
        labels[i] = new QLabel(tr("Transport # %1 ").arg(i + 1));

        layout[i]->addWidget(labels[i]);
        layout[i]->addWidget(slider[i]);
        layout[i]->addWidget(spinBox[i]);
        layoutbase->addLayout(layout[i]);

        setLayout(layoutbase);
        spinBox[i]->setRange(0,130);
        slider[i]->setRange(0,130);
        connect(spinBox[i], SIGNAL(valueChanged(int)),slider[i], SLOT(setValue(int)));
        connect(slider[i], SIGNAL(valueChanged(int)), spinBox[i], SLOT(setValue(int)));
        spinBox[i]->setValue(value);

        ++element;
    }

    //  quit->resize(300, 40);
    // connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

}
Widget::~Widget()
{

}

void Widget::readFile(int *array,int &size)
{
    QFile file("data");

    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"Error";
        return;
    }

    int  element=0;
    QString line;
    line = file.readLine();
    size=line.toInt();

    while (!file.atEnd()){
        line = file.readLine();
        array[element]=line.toInt();
        ++element;
    }
}


