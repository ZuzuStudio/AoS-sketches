#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      window(new QWidget),
      layoutbase(new QVBoxLayout()),
      quit(new QPushButton(tr("Exit")))

{

    setWindowTitle ("Transport");
    setGeometry(100,100,400,300);
    int value=5;
    for(int i=0;i<5;i++)
    {

       layout[i] = new QHBoxLayout();
       slider[i]=new QSlider(Qt::Horizontal);
       spinBox[i]=new QSpinBox();
       labels[i] = new QLabel(tr("Transport # %1 ").arg(i + 1));
       layout[i]->addWidget(labels[i]);
       layout[i]->addWidget(spinBox[i]);
       layout[i]->addWidget(slider[i]);
       layoutbase->addLayout(layout[i]);
       setLayout(layoutbase);
       spinBox[i]->setRange(0,130);
       slider[i]->setRange(0,130);
       connect(spinBox[i], SIGNAL(valueChanged(int)),slider[i], SLOT(setValue(int)));
       connect(slider[i], SIGNAL(valueChanged(int)), spinBox[i], SLOT(setValue(int)));
       spinBox[i]->setValue(value);
       value+=20;


    }

  //  quit->resize(300, 40);
   // connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

}
Widget::~Widget()
{
    
}
