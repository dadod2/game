#include "menu.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

menu::menu(QWidget **content,QSignalMapper *signalmapper)
{
    QVBoxLayout *vblay=new QVBoxLayout;
    QPushButton *buttone_one=new QPushButton("one");
    QPushButton *buttone_two=new QPushButton("Laden");
    QPushButton *buttone_three=new QPushButton("Neues Spiel");
    QPushButton *buttone_four=new QPushButton("Karte löschen");
    QPushButton *buttone_five=new QPushButton("Gebäude erstellen");

    vblay->addWidget(buttone_one);
    vblay->addWidget(buttone_two);
    vblay->addWidget(buttone_three);
    vblay->addWidget(buttone_four);
    vblay->addWidget(buttone_five);
    vblay->addStretch();
    this->setLayout(vblay);

    QObject::connect(buttone_one,SIGNAL(clicked()),signalmapper,SLOT(map()));
    QObject::connect(buttone_two,SIGNAL(clicked()),signalmapper,SLOT(map()));
    QObject::connect(buttone_three,SIGNAL(clicked()),signalmapper,SLOT(map()));
    QObject::connect(buttone_four,SIGNAL(clicked()),signalmapper,SLOT(map()));
    QObject::connect(buttone_five,SIGNAL(clicked()),signalmapper,SLOT(map()));

    signalmapper->setMapping(buttone_one,*(content+0));
    signalmapper->setMapping(buttone_two,*(content+1));
    signalmapper->setMapping(buttone_three,*(content+2));
    signalmapper->setMapping(buttone_four,*(content+3));
    signalmapper->setMapping(buttone_five,*(content+4));
}
