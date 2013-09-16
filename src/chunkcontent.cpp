#include "chunkcontent.h"
#include "chunklabel.h"
#include <QSignalMapper>
#include <QDebug>

chunkcontent::chunkcontent(QWidget *parent,management *manager_) :
    QWidget(parent)
{

    /*deklaration von hauptfenstern und änderbaren bausteinen*/

    chunk_p=NULL;
    manager=manager_;
    buildcombotable=new tableclass;
    window1=new QWidget;
    window2=new QWidget;
    buildwindow=new QWidget;
    dekretewindow=new QWidget;
    buildcombo=new QComboBox;
    dekretecombo=new QComboBox;
        dekretecombo->addItem("a");
        dekretecombo->addItem("b");
        dekretecombo->addItem("c");

        /*Siedlungsbeschreibende variable Label*/
        settlname_lbl=new QLabel;
        settltype_lbl=new QLabel;
        type_lbl=new QLabel;
        type_lbl2=new QLabel;
        ewz_lbl=new QLabel;
        orderlvl_lbl=new QLabel;
        foodlvl_lbl=new QLabel;
        waterlvl_lbl=new QLabel;
        dirtlvl_lbl=new QLabel;
        healthlvl_lbl=new QLabel;
        culturlvl_lbl=new QLabel;
        entertainlvl_lbl=new QLabel;
        wealthlvl_lbl=new QLabel;
        educationlvl_lbl=new QLabel;

        /*gebäude beschreibende variable Label und widgets*/

        building_name=new QLabel;
        building_water_lvl=new QLabel;
        building_food_lvl=new QLabel;
        building_health_lvl=new QLabel;
        building_dirt_lvl=new QLabel;
        building_order_lvl=new QLabel;
        building_culture_lvl=new QLabel;
        building_entertainment_lvl=new QLabel;
        building_wealth_lvl=new QLabel;
        building_education_lvl=new QLabel;
        building_bk_lvl=new QLabel;
        building_uk_lvl=new QLabel;


        b_name_widget=new QWidget;
        b_water_widget=new QWidget;
        b_food_widget=new QWidget;
        b_health_widget=new QWidget;
        b_dirt_widget=new QWidget;
        b_order_widget=new QWidget;
        b_culture_widget=new QWidget;
        b_entertainment_widget=new QWidget;
        b_wealth_widget=new QWidget;
        b_education_widget=new QWidget;
        b_bk_widget=new QWidget;
        b_uk_widget=new QWidget;


    /*denklaration der restlichen bausteine und layouts*/

    QSignalMapper *signalmapper=new QSignalMapper;//Signalmapper für change_chunk Button
    QSignalMapper *signalmapper2=new QSignalMapper;//Signalmapper für Navigationsbutton
    //QSignalMapper *signalmapper3=new QSignalMapper;//Signalmapper für refresh buildingdsc

    QVBoxLayout *vblay=new QVBoxLayout;
    QVBoxLayout *vblay2=new QVBoxLayout;
    QVBoxLayout *buildwin_vblay=new QVBoxLayout;
    QVBoxLayout *dekretewin_vblay=new QVBoxLayout;
    QGridLayout *gridlay=new QGridLayout;
    //QGridLayout *building_dsc_grid=new QGridLayout;
    QVBoxLayout *buildings_dsc_layout=new QVBoxLayout;
    QHBoxLayout *building_name_layout=new QHBoxLayout;QHBoxLayout *building_water_layout=new QHBoxLayout;QHBoxLayout *building_food_layout=new QHBoxLayout;QHBoxLayout *building_health_layout=new QHBoxLayout;QHBoxLayout *building_dirt_layout=new QHBoxLayout;QHBoxLayout *building_order_layout=new QHBoxLayout;QHBoxLayout *building_culture_layout=new QHBoxLayout;QHBoxLayout *building_entertainment_layout=new QHBoxLayout;QHBoxLayout *building_wealth_layout=new QHBoxLayout;QHBoxLayout *building_education_layout=new QHBoxLayout;QHBoxLayout *building_bk_layout=new QHBoxLayout;QHBoxLayout *building_uk_layout=new QHBoxLayout;
    QWidget *buildingdsc=new QWidget;

    QPushButton *backbutton1=new QPushButton("Zurück");
    QPushButton *backbutton2=new QPushButton("Zurück");
    QPushButton *buildwin_button=new QPushButton("Gebäude");
    QPushButton *dekretewin_button=new QPushButton("Dekrete");
    QPushButton *button1=new QPushButton("bauen!");
    QPushButton *button2=new QPushButton("erlassen!");
    QPushButton *button3=new QPushButton("neue Siedlung gründen!");

    QLabel *type_lbl_=new QLabel("Geländetyp");
    QLabel *type_lbl2_=new QLabel("Geländetyp");

        /*Siedlungsbeschreibende Label*/
        QLabel *settltype_lbl_=new QLabel("Besiedlungsstatus");QLabel *ewz_lbl_=new QLabel("Einwohnerzahl");QLabel *orderlvl_lbl_=new QLabel("Ordnungslevel");QLabel *foodlvl_lbl_=new QLabel("Nahrungslevel");QLabel *waterlvl_lbl_=new QLabel("Wasserlevel");QLabel *dirtlvl_lbl_=new QLabel("Verschmutzung");QLabel *healthlvl_lbl_=new QLabel("Gesundheitslevel");QLabel *culturlvl_lbl_=new QLabel("Kulturlevel");QLabel *entertainlvl_lbl_ =new QLabel("Unterhaltungslevel");QLabel *wealthlvl_lbl_=new QLabel("Wohlstandslevel");QLabel *educationlvl_lbl_=new QLabel("Bildungslevel");
        /*Gebäudebeschreibende Label und widgets*/
        QWidget *building_name_widget=new QWidget;QWidget *building_water_widget=new QWidget;QWidget *building_food_widget=new QWidget;QWidget *building_health_widget=new QWidget;QWidget *building_dirt_widget=new QWidget;QWidget *building_order_widget=new QWidget;QWidget *building_culture_widget=new QWidget;QWidget *building_entertainment_widget=new QWidget;QWidget *building_wealth_widget=new QWidget;QWidget *building_education_widget=new QWidget;QWidget *building_bk_widget=new QWidget;QWidget *building_uk_widget=new QWidget;
        QLabel *building_water_lvl_=new QLabel("Einfluss auf Wasserlevel");QLabel *building_food_lvl_=new QLabel("Einfluss auf Nahrungslevel");QLabel *building_health_lvl_=new QLabel("Einfluss auf Gesundheitslevel");QLabel *building_dirt_lvl_=new QLabel("Einfluss auf Verschmutzungslevel");QLabel *building_order_lvl_=new QLabel("Einfluss auf Ordnungslevel");QLabel *building_culture_lvl_=new QLabel("Einfluss auf Kulturlevel");QLabel *building_entertainment_lvl_=new QLabel("Einfluss auf Unterhaltungslevel");QLabel *building_wealth_lvl_=new QLabel("Einfluss auf Wohlstandslevel");QLabel *building_education_lvl_=new QLabel("Einfluss auf Bildungslevel");QLabel *building_bk_lvl_=new QLabel("Baukosten");QLabel *building_uk_lvl_=new QLabel("Unterhaltungskosten");


    QLabel *build_lbl=new QLabel("Bauen");
    QLabel *dekrete_lbl=new QLabel("Dekrete");
    QLabel *founding_lbl=new QLabel("Siedlung gründen");

    /*mappin der action button's*/

    QObject::connect(button1,SIGNAL(clicked()),signalmapper,SLOT(map()));
            signalmapper->setMapping(button1,1);
    QObject::connect(button2,SIGNAL(clicked()),signalmapper,SLOT(map()));
            signalmapper->setMapping(button2,2);
    QObject::connect(button3,SIGNAL(clicked()),this,SLOT(found_settlement()));

    QObject::connect(signalmapper,SIGNAL(mapped(int)),this,SLOT(change_chunk(int)));

    /*mapping der window-change buttons's*/

    QObject::connect(buildwin_button,SIGNAL(clicked()),signalmapper2,SLOT(map()));
            signalmapper2->setMapping(buildwin_button,1);
    QObject::connect(backbutton1,SIGNAL(clicked()),signalmapper2,SLOT(map()));
            signalmapper2->setMapping(backbutton1,2);

    QObject::connect(dekretewin_button,SIGNAL(clicked()),signalmapper2,SLOT(map()));
            signalmapper2->setMapping(dekretewin_button,3);
    QObject::connect(backbutton2,SIGNAL(clicked()),signalmapper2,SLOT(map()));
            signalmapper2->setMapping(backbutton2,2);

    QObject::connect(signalmapper2,SIGNAL(mapped(int)),this,SLOT(button_clicked(int)));

    /*Mapping der builddsc refresh funktion*/

    QObject::connect(buildcombo,SIGNAL(currentIndexChanged(int)),this,SLOT(change_building_dsc(int)));
    //QObject::connect(buildcombo,SIGNAL(currentIndexChanged(int)),signalmapper3,SLOT(map(int)));
    //        signalmapper3->setMapping(buildcombo,1);
    //QObject::connect(this,SIGNAL(refresh_buildingdsc()),signalmapper3,SLOT(map(int)));
    //       signalmapper3->setMapping(this,2);
    //QObject::connect(signalmapper3,SIGNAL(mapped(int)),this,SLOT(change_building_dsc(int)));

    /*setzen der layouts*/

    window1->setLayout(vblay2);
        window1->setVisible(true);
    window2->setLayout(gridlay);
        window2->setVisible(false);
    buildwindow->setLayout(buildwin_vblay);
        buildwindow->setVisible(false);
    dekretewindow->setLayout(dekretewin_vblay);
        dekretewindow->setVisible(false);
    buildingdsc->setLayout(buildings_dsc_layout);

    b_name_widget->setLayout(building_name_layout);
        building_name_widget->setVisible(false);
    b_water_widget->setLayout(building_water_layout);
        building_water_widget->setVisible(false);
    b_food_widget->setLayout(building_food_layout);
        building_food_widget->setVisible(false);
    b_health_widget->setLayout(building_health_layout);
        building_health_widget->setVisible(false);
    b_dirt_widget->setLayout(building_dirt_layout);
        building_dirt_widget->setVisible(false);
    b_order_widget->setLayout(building_order_layout);
        building_order_widget->setVisible(false);
    b_culture_widget->setLayout(building_culture_layout);
        building_culture_widget->setVisible(false);
    b_entertainment_widget->setLayout(building_entertainment_layout);
        building_entertainment_widget->setVisible(false);
    b_wealth_widget->setLayout(building_wealth_layout);
        building_wealth_widget->setVisible(false);
    b_education_widget->setLayout(building_education_layout);
        building_education_widget->setVisible(false);
    b_bk_widget->setLayout(building_bk_layout);
        building_bk_widget->setVisible(false);
    b_uk_widget->setLayout(building_uk_layout);
        building_uk_widget->setVisible(false);

    gridlay->addWidget(settlname_lbl,0,0);
    gridlay->addWidget(settltype_lbl_,1,0);
    gridlay->addWidget(settltype_lbl,1,1);
    gridlay->addWidget(type_lbl_,2,0);
    gridlay->addWidget(type_lbl,2,1);
    gridlay->addWidget(ewz_lbl_,3,0);
    gridlay->addWidget(ewz_lbl,3,1);
    gridlay->addWidget(orderlvl_lbl_,4,0);
    gridlay->addWidget(orderlvl_lbl,4,1);
    gridlay->addWidget(foodlvl_lbl_,5,0);
    gridlay->addWidget(foodlvl_lbl,5,1);
    gridlay->addWidget(waterlvl_lbl_,6,0);
    gridlay->addWidget(waterlvl_lbl,6,1);
    gridlay->addWidget(dirtlvl_lbl_,7,0);
    gridlay->addWidget(dirtlvl_lbl,7,1);
    gridlay->addWidget(healthlvl_lbl_,8,0);
    gridlay->addWidget(healthlvl_lbl,8,1);
    gridlay->addWidget(culturlvl_lbl_,9,0);
    gridlay->addWidget(culturlvl_lbl,9,1);
    gridlay->addWidget(entertainlvl_lbl_,10,0);
    gridlay->addWidget(entertainlvl_lbl,10,1);
    gridlay->addWidget(wealthlvl_lbl_,11,0);
    gridlay->addWidget(wealthlvl_lbl,11,1);
    gridlay->addWidget(educationlvl_lbl_,12,0);
    gridlay->addWidget(educationlvl_lbl,12,1);
    gridlay->addWidget(buildwin_button,15,0,1,2);
    gridlay->addWidget(dekretewin_button,16,0,1,2);
/*
    building_dsc_grid->addWidget(building_name,0,0);
    building_dsc_grid->addWidget(building_water_lvl_,1,0);
    building_dsc_grid->addWidget(building_water_lvl,1,1);
    building_dsc_grid->addWidget(building_food_lvl_,2,0);
    building_dsc_grid->addWidget(building_food_lvl,2,1);
    building_dsc_grid->addWidget(building_health_lvl_,3,0);
    building_dsc_grid->addWidget(building_health_lvl,3,1);
    building_dsc_grid->addWidget(building_dirt_lvl_,4,0);
    building_dsc_grid->addWidget(building_dirt_lvl,4,1);
    building_dsc_grid->addWidget(building_order_lvl_,5,0);
    building_dsc_grid->addWidget(building_order_lvl,5,1);
    building_dsc_grid->addWidget(building_culture_lvl_,6,0);
    building_dsc_grid->addWidget(building_culture_lvl,6,1);
    building_dsc_grid->addWidget(building_entertainment_lvl_,7,0);
    building_dsc_grid->addWidget(building_entertainment_lvl,7,1);
    building_dsc_grid->addWidget(building_wealth_lvl_,8,0);
    building_dsc_grid->addWidget(building_wealth_lvl,8,1);
    building_dsc_grid->addWidget(building_education_lvl_,9,0);
    building_dsc_grid->addWidget(building_education_lvl,9,1);
    building_dsc_grid->addWidget(building_bk_lvl_,10,0);
    building_dsc_grid->addWidget(building_bk_lvl,10,1);
    building_dsc_grid->addWidget(building_uk_lvl_,11,0);
    building_dsc_grid->addWidget(building_uk_lvl,11,1);
*/
    buildings_dsc_layout->addWidget(b_name_widget);
    buildings_dsc_layout->addWidget(b_water_widget);
    buildings_dsc_layout->addWidget(b_food_widget);
    buildings_dsc_layout->addWidget(b_health_widget);
    buildings_dsc_layout->addWidget(b_dirt_widget);
    buildings_dsc_layout->addWidget(b_order_widget);
    buildings_dsc_layout->addWidget(b_culture_widget);
    buildings_dsc_layout->addWidget(b_entertainment_widget);
    buildings_dsc_layout->addWidget(b_wealth_widget);
    buildings_dsc_layout->addWidget(b_education_widget);
    buildings_dsc_layout->addWidget(b_bk_widget);
    buildings_dsc_layout->addWidget(b_uk_widget);


    building_name_layout->addWidget(building_name);
    building_water_layout->addWidget(building_water_lvl_);
    building_water_layout->addWidget(building_water_lvl);
    building_food_layout->addWidget(building_food_lvl_);
    building_food_layout->addWidget(building_food_lvl);
    building_health_layout->addWidget(building_health_lvl_);
    building_health_layout->addWidget(building_health_lvl);
    building_dirt_layout->addWidget(building_dirt_lvl_);
    building_dirt_layout->addWidget(building_dirt_lvl);
    building_order_layout->addWidget(building_order_lvl_);
    building_order_layout->addWidget(building_order_lvl);
    building_culture_layout->addWidget(building_culture_lvl_);
    building_culture_layout->addWidget(building_culture_lvl);
    building_entertainment_layout->addWidget(building_entertainment_lvl_);
    building_entertainment_layout->addWidget(building_entertainment_lvl);
    building_wealth_layout->addWidget(building_wealth_lvl_);
    building_wealth_layout->addWidget(building_wealth_lvl);
    building_education_layout->addWidget(building_education_lvl_);
    building_education_layout->addWidget(building_education_lvl);
    building_bk_layout->addWidget(building_bk_lvl_);
    building_bk_layout->addWidget(building_bk_lvl);
    building_uk_layout->addWidget(building_uk_lvl_);
    building_uk_layout->addWidget(building_uk_lvl);


    vblay2->addWidget(type_lbl2_);
    vblay2->addWidget(type_lbl2);
    vblay2->addWidget(founding_lbl);
    vblay2->addWidget(button3);

    buildwin_vblay->addWidget(build_lbl);
    buildwin_vblay->addWidget(buildcombo);
    buildwin_vblay->addWidget(button1);
    buildwin_vblay->addWidget(buildingdsc);
    buildwin_vblay->addStretch();
    buildwin_vblay->addWidget(backbutton1);

    dekretewin_vblay->addWidget(dekrete_lbl);
    dekretewin_vblay->addWidget(dekretecombo);
    dekretewin_vblay->addWidget(button2);
    dekretewin_vblay->addStretch();
    dekretewin_vblay->addWidget(backbutton2);

    vblay->addWidget(window1);
    vblay->addWidget(window2);
    vblay->addWidget(buildwindow);
    vblay->addWidget(dekretewindow);
    this->setLayout(vblay);
}

void chunkcontent::change_cont(chunk* chp){
    chunk_p=chp;

    switch(chunk_p->give_type()){
    case 'a':
        type_lbl->setText("Wasser");
        type_lbl2->setText("Wasser");
        break;
    case 'b':
        type_lbl->setText("Flachland");
        type_lbl2->setText("Flachland");
        break;
    case 'c':
        type_lbl->setText("Gebirge");
        type_lbl2->setText("Gebirge");
        break;
    case 'd':
        type_lbl->setText("Wald");
        type_lbl2->setText("Wald");
        break;
    default:
        break;
    }
    if(!(chunk_p->give_settlement())){
        window1->setVisible(true);
        window2->setVisible(false);
        buildwindow->setVisible(false);
        dekretewindow->setVisible(false);
    }
    else{
        window1->setVisible(false);
        window2->setVisible(true);
        buildwindow->setVisible(false);
        dekretewindow->setVisible(false);

        building_props *building_list_=manager->give_building_props();
        building *buildings=NULL;
        if(chunk_p->give_settlement()){
            buildings=(chunk_p->give_settlement())->give_buildings();
        }
        tableclass *hp;
        if(buildcombotable->get_next()){
            buildcombotable->clear();
        }
        buildcombo->clear();
        //buildcombo->addItem("");
        buildcombo->addItem("");

        while(building_list_){
            if(!buildings || (building_list_->give_IN())!=(buildings->give_IN())){
                hp=new tableclass();
                buildcombotable->add(hp,building_list_->give_IN());
                buildcombo->addItem(building_list_->give_name());
            }
            building_list_=building_list_->give_next();
        }
        //emit refresh_buildingdsc();
    }
}

void chunkcontent::change_chunk(int i){
    if(i==1){
        if(buildcombo->currentIndex()!=0){
            building *hp=new building((manager->give_building_props())->get_byIN(buildcombotable->get_secbyfirst((buildcombo->currentIndex())+1)));
            if(chunk_p->give_settlement()){
                (chunk_p->give_settlement())->add_building(hp);
            }
            else {
                qDebug("error! No settlement!");
            }
        }
    }
    else if(i==2){

    }
    change_cont(chunk_p);
}

void chunkcontent::change_building_dsc(int index){
        //qDebug("test0");fflush(stdout);
        b_name_widget->setVisible(false);
        //qDebug("test1");fflush(stdout);
        b_water_widget->setVisible(false);
        b_food_widget->setVisible(false);
        b_health_widget->setVisible(false);
        b_dirt_widget->setVisible(false);
        b_order_widget->setVisible(false);
        b_culture_widget->setVisible(false);
        b_entertainment_widget->setVisible(false);
        b_wealth_widget->setVisible(false);
        b_education_widget->setVisible(false);
        b_bk_widget->setVisible(false);
        b_uk_widget->setVisible(false);

        if(index != -1){
                qDebug("test1");
                qDebug("building_dsc changed!");
            //qDebug("test0");fflush(stdout);
            building_props *building=((manager->give_building_props())->get_byIN(buildcombotable->get_secbyfirst((buildcombo->currentIndex())+1)));
            //qDebug("test1");fflush(stdout);
            b_name_widget->setVisible(true);
            building_name->setText(building->give_name());
            //qDebug("test2");fflush(stdout);
            switch(building->give_WLVL()){
            case('f'):
                break;
            case('b'):
                building_water_lvl->setText("-30%");
                b_water_widget->setVisible(true);
                break;
            case('c'):
                building_water_lvl->setText("-20%");
                b_water_widget->setVisible(true);
                break;
            case('d'):
                building_water_lvl->setText("-10%");
                b_water_widget->setVisible(true);
                break;
            case('e'):
                building_water_lvl->setText("-5%");
                b_water_widget->setVisible(true);
                break;
            case('g'):
                building_water_lvl->setText("+5%");
                b_water_widget->setVisible(true);
                break;
            case('h'):
                building_water_lvl->setText("+10%");
                b_water_widget->setVisible(true);
                break;
            case('i'):
                building_water_lvl->setText("+20%");
                b_water_widget->setVisible(true);
                break;
            case('j'):
                building_water_lvl->setText("+30%");
                b_water_widget->setVisible(true);
                break;
            }
            switch(building->give_NLVL()){
            case('f'):
                break;
            case('b'):
                building_food_lvl->setText("-30%");
                b_food_widget->setVisible(true);
                break;
            case('c'):
                building_food_lvl->setText("-20%");
                b_food_widget->setVisible(true);
                break;
            case('d'):
                building_food_lvl->setText("-10%");
                b_food_widget->setVisible(true);
                break;
            case('e'):
                building_food_lvl->setText("-5%");
                b_food_widget->setVisible(true);
                break;
            case('g'):
                building_food_lvl->setText("+5%");
                b_food_widget->setVisible(true);
                break;
            case('h'):
                building_food_lvl->setText("+10%");
                b_food_widget->setVisible(true);
                break;
            case('i'):
                building_food_lvl->setText("+20%");
                b_food_widget->setVisible(true);
                break;
            case('j'):
                building_food_lvl->setText("+30%");
                b_food_widget->setVisible(true);
                break;
            }
            switch(building->give_GLVL()){
            case('f'):
                break;
            case('b'):
                building_health_lvl->setText("-30%");
                b_health_widget->setVisible(true);
                break;
            case('c'):
                building_health_lvl->setText("-20%");
                b_health_widget->setVisible(true);
                break;
            case('d'):
                building_health_lvl->setText("-10%");
                b_health_widget->setVisible(true);
                break;
            case('e'):
                building_health_lvl->setText("-5%");
                b_health_widget->setVisible(true);
                break;
            case('g'):
                building_health_lvl->setText("+5%");
                b_health_widget->setVisible(true);
                break;
            case('h'):
                building_health_lvl->setText("+10%");
                b_health_widget->setVisible(true);
                break;
            case('i'):
                building_health_lvl->setText("+20%");
                b_health_widget->setVisible(true);
                break;
            case('j'):
                building_health_lvl->setText("+30%");
                b_health_widget->setVisible(true);
                break;
            }
            switch(building->give_VLVL()){
            case('f'):
                break;
            case('b'):
                building_dirt_lvl->setText("-30%");
                b_dirt_widget->setVisible(true);
                break;
            case('c'):
                building_dirt_lvl->setText("-20%");
                b_dirt_widget->setVisible(true);
                break;
            case('d'):
                building_dirt_lvl->setText("-10%");
                b_dirt_widget->setVisible(true);
                break;
            case('e'):
                building_dirt_lvl->setText("-5%");
                b_dirt_widget->setVisible(true);
                break;
            case('g'):
                building_dirt_lvl->setText("+5%");
                b_dirt_widget->setVisible(true);
                break;
            case('h'):
                building_dirt_lvl->setText("+10%");
                b_dirt_widget->setVisible(true);
                break;
            case('i'):
                building_dirt_lvl->setText("+20%");
                b_dirt_widget->setVisible(true);
                break;
            case('j'):
                building_dirt_lvl->setText("+30%");
                b_dirt_widget->setVisible(true);
                break;
            }
            switch(building->give_OLVL()){
            case('f'):
                break;
            case('b'):
                building_order_lvl->setText("-30%");
                b_order_widget->setVisible(true);
                break;
            case('c'):
                building_order_lvl->setText("-20%");
                b_order_widget->setVisible(true);
                break;
            case('d'):
                building_order_lvl->setText("-10%");
                b_order_widget->setVisible(true);
                break;
            case('e'):
                building_order_lvl->setText("-5%");
                b_order_widget->setVisible(true);
                break;
            case('g'):
                building_order_lvl->setText("+5%");
                b_order_widget->setVisible(true);
                break;
            case('h'):
                building_order_lvl->setText("+10%");
                b_order_widget->setVisible(true);
                break;
            case('i'):
                building_order_lvl->setText("+20%");
                b_order_widget->setVisible(true);
                break;
            case('j'):
                building_order_lvl->setText("+30%");
                b_order_widget->setVisible(true);
                break;
            }
            switch(building->give_KLVL()){
            case('f'):
                break;
            case('b'):
                building_culture_lvl->setText("-30%");
                b_culture_widget->setVisible(true);
                break;
            case('c'):
                building_culture_lvl->setText("-20%");
                b_culture_widget->setVisible(true);
                break;
            case('d'):
                building_culture_lvl->setText("-10%");
                b_culture_widget->setVisible(true);
                break;
            case('e'):
                building_culture_lvl->setText("-5%");
                b_culture_widget->setVisible(true);
                break;
            case('g'):
                building_culture_lvl->setText("+5%");
                b_culture_widget->setVisible(true);
                break;
            case('h'):
                building_culture_lvl->setText("+10%");
                b_culture_widget->setVisible(true);
                break;
            case('i'):
                building_culture_lvl->setText("+20%");
                b_culture_widget->setVisible(true);
                break;
            case('j'):
                building_culture_lvl->setText("+30%");
                b_culture_widget->setVisible(true);
                break;
            }
            switch(building->give_ULVL()){
            case('f'):
                break;
            case('b'):
                building_entertainment_lvl->setText("-30%");
                b_entertainment_widget->setVisible(true);
                break;
            case('c'):
                building_entertainment_lvl->setText("-20%");
                b_entertainment_widget->setVisible(true);
                break;
            case('d'):
                building_entertainment_lvl->setText("-10%");
                b_entertainment_widget->setVisible(true);
                break;
            case('e'):
                building_entertainment_lvl->setText("-5%");
                b_entertainment_widget->setVisible(true);
                break;
            case('g'):
                building_entertainment_lvl->setText("+5%");
                b_entertainment_widget->setVisible(true);
                break;
            case('h'):
                building_entertainment_lvl->setText("+10%");
                b_entertainment_widget->setVisible(true);
                break;
            case('i'):
                building_entertainment_lvl->setText("+20%");
                b_entertainment_widget->setVisible(true);
                break;
            case('j'):
                building_entertainment_lvl->setText("+30%");
                b_entertainment_widget->setVisible(true);
                break;
            }
            switch(building->give_WlLVL()){
            case('f'):
                break;
            case('b'):
                building_wealth_lvl->setText("-30%");
                b_wealth_widget->setVisible(true);
                break;
            case('c'):
                building_wealth_lvl->setText("-20%");
                b_wealth_widget->setVisible(true);
                break;
            case('d'):
                building_wealth_lvl->setText("-10%");
                b_wealth_widget->setVisible(true);
                break;
            case('e'):
                building_wealth_lvl->setText("-5%");
                b_wealth_widget->setVisible(true);
                break;
            case('g'):
                building_wealth_lvl->setText("+5%");
                b_wealth_widget->setVisible(true);
                break;
            case('h'):
                building_wealth_lvl->setText("+10%");
                b_wealth_widget->setVisible(true);
                break;
            case('i'):
                building_wealth_lvl->setText("+20%");
                b_wealth_widget->setVisible(true);
                break;
            case('j'):
                building_wealth_lvl->setText("+30%");
                b_wealth_widget->setVisible(true);
                break;
            }
            switch(building->give_BLVL()){
            case('f'):
                break;
            case('b'):
                building_education_lvl->setText("-30%");
                b_education_widget->setVisible(true);
                break;
            case('c'):
                building_education_lvl->setText("-20%");
                b_education_widget->setVisible(true);
                break;
            case('d'):
                building_education_lvl->setText("-10%");
                b_education_widget->setVisible(true);
                break;
            case('e'):
                building_education_lvl->setText("-5%");
                b_education_widget->setVisible(true);
                break;
            case('g'):
                building_education_lvl->setText("+5%");
                b_education_widget->setVisible(true);
                break;
            case('h'):
                building_education_lvl->setText("+10%");
                b_education_widget->setVisible(true);
                break;
            case('i'):
                building_education_lvl->setText("+20%");
                b_education_widget->setVisible(true);
                break;
            case('j'):
                building_education_lvl->setText("+30%");
                b_education_widget->setVisible(true);
                break;
            }
        }
}

void chunkcontent::found_settlement(){
    settlement *shp=new settlement(chunk_p->give_xcord(),chunk_p->give_ycord());
    manager->add_settlement(shp);
    chunk_p->set_settlement(shp);
    //manager->test_settlements();
    change_cont(chunk_p);
}

void chunkcontent::button_clicked(int i){
    switch(i){
    case 1:
        window1->setVisible(false);
        window2->setVisible(false);
        buildwindow->setVisible(true);
        dekretewindow->setVisible(false);
        break;
    case 2:
        window1->setVisible(false);
        window2->setVisible(true);
        buildwindow->setVisible(false);
        dekretewindow->setVisible(false);
        break;
    case 3:
        window1->setVisible(false);
        window2->setVisible(false);
        buildwindow->setVisible(false);
        dekretewindow->setVisible(true);
        break;
    default:
        break;
    }
}

//void chunkcontent::refresh_buildingdsc(){

//}
