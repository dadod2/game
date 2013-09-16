#include "mapdiag.h"
#include "ui_mapdiag.h"
#include "map.h"
#include "movebutton.h"
#include "chunkcontent.h"
#include <QToolBar>
//#include <QPushButton>
#include <QSignalMapper>
#include <QDesktopWidget>
/*
void mapdiag::set_map(chunk ***mapp){
    map=mapp;
}*/

void mapdiag::set_coords(int x_,int y_){
    x=x_;
    y=y_;
}

void mapdiag::set_mapcont(mapcontainer *mapcontainer){
    mapcont=mapcontainer;
}

void mapdiag::save(){
    int i,j;
    QString mapsave=manager->give_savedir();
        mapsave.append("map.txt");
    QString settlsave=manager->give_savedir();
        settlsave.append("settlements.txt");
    QFile fpmapsave(mapsave);
    QFile fpsettlsave(settlsave);
    chunk ***map=manager->give_map();

    if(!fpmapsave.open(QFile::WriteOnly | QFile::Text)){
        qDebug("cant open map-savefile");
        qDebug() << mapsave;
    }
    else{
        qDebug("open map-savefile succesfull");

        /*Saving map into file*/

        QTextStream mapsaveout(&fpmapsave);
        mapsaveout << mapsize << endl;
        for(i=0;i<mapsize;i++){
            for(j=0;j<mapsize;j++){
                map[i][j]->save(&mapsaveout);
            }
        }
        mapsaveout.flush();

    }
    fpmapsave.close();

    settlement *hp=manager->give_settlements();
    while(hp){
        hp=hp->give_next();
    }

    if(!fpsettlsave.open(QFile::WriteOnly | QFile::Text)){
        qDebug("cant open settl-savefile");
        qDebug() << settlsave;
    }
    else{
        qDebug("open settl-savefile succesfull");

        /*Saving settlements into file*/

        QTextStream settlsaveout(&fpsettlsave);
        hp=manager->give_settlements();
        while(hp){
            hp->save(&settlsaveout,buildcount);
            hp=hp->give_next();
        }
        settlsaveout.flush();

    }
    fpsettlsave.close();
}

mapdiag::mapdiag(QWidget *parent,management *manager_) :
    QDialog(parent),
    ui(new Ui::mapdiag)
{
    manager=manager_;
    ui->setupUi(this);
    x=0;
    y=0;
    mapgrid=new QGridLayout;
    mapsize=manager->give_mapsize();
    buildcount=manager->give_buildcount();
    QDesktopWidget dw;
    QWidget *menuframe=new QWidget;
    QWidget *mainframe=new QWidget;
    QWidget *leftcontent=new QWidget;
    QWidget *maincontent=new QWidget;
    chunkcontent *chunkcont=new chunkcontent(this,manager);
    mapcont=new mapcontainer(this,manager,mapgrid,chunkcont,0,0);
    QWidget *buttoncont=new QWidget;
    movebutton *button_up=new movebutton(this,1);
    movebutton *button_left=new movebutton(this,2);
    movebutton *button_down=new movebutton(this,3);
    movebutton *button_right=new movebutton(this,4);
    QPushButton *save=new QPushButton("Save");

    QLabel *label2=new QLabel("test2");
    QVBoxLayout *vblay=new QVBoxLayout;
    QVBoxLayout *leftcontvblay=new QVBoxLayout;
    QVBoxLayout *maincontvblay=new QVBoxLayout;
    QHBoxLayout *menuhblay=new QHBoxLayout;
    QHBoxLayout *hblay=new QHBoxLayout;
    QGridLayout *gridlay=new QGridLayout;

    vblay->addWidget(menuframe);
    vblay->addWidget(mainframe);
    hblay->addWidget(leftcontent);
    hblay->addWidget(maincontent);
    hblay->addWidget(chunkcont);
        hblay->setMargin(0);
        hblay->setAlignment(0);
    menuhblay->addWidget(save);
    menuhblay->addStretch();
    leftcontvblay->addWidget(label2);
    leftcontvblay->addStretch();
    leftcontvblay->addWidget(buttoncont);
    maincontvblay->addWidget(mapcont);
        maincontvblay->setMargin(0);
        maincontvblay->setAlignment(0);

    gridlay->addWidget(button_up,0,1);
    gridlay->addWidget(button_left,1,0);
    gridlay->addWidget(button_down,2,1);
    gridlay->addWidget(button_right,1,2);

    menuframe->setLayout(menuhblay);
    mainframe->setLayout(hblay);
    leftcontent->setLayout(leftcontvblay);
    maincontent->setLayout(maincontvblay);
    buttoncont->setLayout(gridlay);
    maincontent->setFixedSize(0.7*dw.height(),0.7*dw.height());
    buttoncont->setFixedSize(0.2*dw.height(),0.2*dw.height());
    chunkcont->setFixedSize(0.5*dw.height(),0.7*dw.height());
    this->setLayout(vblay);

    buttoncont->setFocus();

    QObject::connect(button_up,SIGNAL(clicked(int)),mapcont,SLOT(moved(int)));
    QObject::connect(button_left,SIGNAL(clicked(int)),mapcont,SLOT(moved(int)));
    QObject::connect(button_down,SIGNAL(clicked(int)),mapcont,SLOT(moved(int)));
    QObject::connect(button_right,SIGNAL(clicked(int)),mapcont,SLOT(moved(int)));
    QObject::connect(this,SIGNAL(clicked(int)),mapcont,SLOT(moved(int)));
    QObject::connect(save,SIGNAL(clicked()),this,SLOT(save()));
}

mapdiag::~mapdiag()
{
    delete ui;
}

void mapdiag::keyPressEvent(QKeyEvent *kev){
    if(kev->key()==Qt::Key_W) emit clicked(1);
    else if(kev->key()==Qt::Key_A) emit clicked(2);
    else if(kev->key()==Qt::Key_S) emit clicked(3);
    else if(kev->key()==Qt::Key_D) emit clicked(4);
}
