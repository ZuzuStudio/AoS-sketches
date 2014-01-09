#include "citymap.h"

CityMap::CityMap(Data *cache, QWidget *parent) :
    QWidget(parent),
    factor1(new QPushButton(tr("factor1"))),
    factor2(new QPushButton(tr("factor2"))),
    factor3(new QPushButton(tr("factor3"))),
    factor4(new QPushButton(tr("factor4"))),
    factor5(new QPushButton(tr("factor5"))),
    factor6(new QPushButton(tr("factor6"))),
    factor7(new QPushButton(tr("factor7"))),
    factor8(new QPushButton(tr("factor8"))),
    factor9(new QPushButton(tr("factor9"))),
    factor10(new QPushButton(tr("factor10"))),
    factor11(new QPushButton(tr("factor11"))),
    factor12(new QPushButton(tr("factor12"))),
    factor13(new QPushButton(tr("factor13"))),
    factor_dialog1(new WarehouseDialog(tr("factor 1"), cache,this)),
    factor_dialog2(new CityDialog(tr("factor 2"),this)),
    factor_dialog3(new CityDialog(tr("factor 3"),this)),
    factor_dialog4(new CityDialog(tr("factor 4"),this)),
    factor_dialog5(new CityDialog(tr("factor 5"),this)),
    factor_dialog6(new CityDialog(tr("factor 6"),this)),
    factor_dialog7(new CityDialog(tr("factor 7"),this)),
    factor_dialog8(new CityDialog(tr("factor 8"),this)),
    factor_dialog9(new CityDialog(tr("factor 9"),this)),
    factor_dialog10(new CityDialog(tr("factor 10"),this)),
    factor_dialog11(new CityDialog(tr("factor 11"),this)),
    factor_dialog12(new CityDialog(tr("factor 12"),this)),
    factor_dialog13(new CityDialog(tr("factor 13"),this)),
    lay(new QGridLayout)
{


    factor1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    factor2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    factor3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    factor4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    factor5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    factor6->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    factor7->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    factor8->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    factor9->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    factor10->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    factor11->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    factor12->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    factor13->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    connect(factor1, SIGNAL(clicked()), factor_dialog1, SLOT(show()));
    connect(factor2, SIGNAL(clicked()), factor_dialog2, SLOT(show()));
    connect(factor3, SIGNAL(clicked()), factor_dialog3, SLOT(show()));
    connect(factor4, SIGNAL(clicked()), factor_dialog4, SLOT(show()));
    connect(factor5, SIGNAL(clicked()), factor_dialog5, SLOT(show()));
    connect(factor6, SIGNAL(clicked()), factor_dialog6, SLOT(show()));
    connect(factor7, SIGNAL(clicked()), factor_dialog7, SLOT(show()));
    connect(factor8, SIGNAL(clicked()), factor_dialog8, SLOT(show()));
    connect(factor9, SIGNAL(clicked()), factor_dialog9, SLOT(show()));
    connect(factor10, SIGNAL(clicked()), factor_dialog10, SLOT(show()));
    connect(factor11, SIGNAL(clicked()), factor_dialog11, SLOT(show()));
    connect(factor12, SIGNAL(clicked()), factor_dialog12, SLOT(show()));
    connect(factor13, SIGNAL(clicked()), factor_dialog13, SLOT(show()));


    lay->addWidget(factor1, 0, 0,1,2);
    lay->addWidget(factor2, 0, 2,1,4);
    lay->addWidget(factor3, 1, 0,1,4);
    lay->addWidget(factor4, 1, 4,1,2);
    lay->addWidget(factor5, 2, 0,1,3);
    lay->addWidget(factor6, 2, 3,1,3);
    lay->addWidget(factor7, 3, 0,1,2);
    lay->addWidget(factor8, 3, 2,1,4);
    lay->addWidget(factor9, 4, 0,1,2);
    lay->addWidget(factor10, 4, 2,1,2);
    lay->addWidget(factor11, 4, 4,1,2);
    lay->addWidget(factor12, 5, 0,1,3);
    lay->addWidget(factor13, 5, 3,1,3);


    setLayout(lay);
}

CityMap::~CityMap()
{
}







