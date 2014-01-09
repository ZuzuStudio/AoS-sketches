#include "city.h"

City::City(Data *cache, QWidget *parent)
    : QWidget(parent),
      backButton(new QPushButton("back")),
      helpButton(new QPushButton("help")),
      map(new CityMap(cache)),
      lay(new QGridLayout),
      rightPannel(new CityRightPannel(cache)),
      leftPannel(new CityLeftPannel(cache))
{

    lay->addWidget(backButton,0,0);
    lay->addWidget(leftPannel,1,0);
    lay->addWidget(map,0,1,2,1);
    lay->addWidget(helpButton,0,2);
    lay->addWidget(rightPannel,1,2);

    lay->setColumnStretch(0,1);
    lay->setColumnStretch(1,12);
    lay->setColumnStretch(2,1);

    connect(backButton,SIGNAL(clicked()),this, SLOT(back()));
    connect(helpButton,SIGNAL(clicked()),this, SLOT(help()));

    setLayout(lay);

    connect(this,SIGNAL(backClicked()), this, SLOT(close()));
    connect(this,SIGNAL(helpClicked()), this, SLOT(showFullScreen()));
}

City::~City()
{

}

void City::back()
{
    emit backClicked();
}

void City::help()
{
    emit helpClicked();
}
