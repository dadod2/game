#ifndef CHUNKCONTENT_H
#define CHUNKCONTENT_H

#include "chunk.h"
#include "tableclass.h"
#include <QComboBox>
#include <QPushButton>
#include "building_props.h"
#include "building.h"
#include "management.h"

class chunkcontent : public QWidget
{
    Q_OBJECT
private:
    chunk *chunk_p;
    QLabel *type_lbl;
    QLabel *type_lbl2;

    /*Variable, siedlungsbeschreibende Label*/
    QLabel *settltype_lbl;
    QLabel *settlname_lbl;
    QLabel *ewz_lbl;
    QLabel *orderlvl_lbl;
    QLabel *foodlvl_lbl;
    QLabel *waterlvl_lbl;
    QLabel *dirtlvl_lbl;
    QLabel *healthlvl_lbl;
    QLabel *culturlvl_lbl;
    QLabel *entertainlvl_lbl;
    QLabel *wealthlvl_lbl;
    QLabel *educationlvl_lbl;

    /*Variable, gebäude beschreibende Label*/
    QLabel *building_name;
    QLabel *building_water_lvl;
    QLabel *building_food_lvl;
    QLabel *building_health_lvl;
    QLabel *building_dirt_lvl;
    QLabel *building_order_lvl;
    QLabel *building_culture_lvl;
    QLabel *building_entertainment_lvl;
    QLabel *building_wealth_lvl;
    QLabel *building_education_lvl;
    QLabel *building_bk_lvl;
    QLabel *building_uk_lvl;

    QWidget *test;

    QWidget *b_name_widget;
    QWidget *b_water_widget;
    QWidget *b_food_widget;
    QWidget *b_health_widget;
    QWidget *b_dirt_widget;
    QWidget *b_order_widget;
    QWidget *b_culture_widget;
    QWidget *b_entertainment_widget;
    QWidget *b_wealth_widget;
    QWidget *b_education_widget;
    QWidget *b_bk_widget;
    QWidget *b_uk_widget;


    QComboBox *buildcombo;
    QComboBox *dekretecombo;
    tableclass *buildcombotable;
    QWidget *window1;
    QWidget *window2;
    QWidget *buildwindow;
    QWidget *dekretewindow;
    //QWidget *buildingdsc;
    management *manager;
    inline void set_settlstate(char);

public:
    explicit chunkcontent(QWidget *parent_ = NULL,management *manager_=NULL);
    
signals:
    void refresh_buildingdsc();
    
public slots:
    void change_cont(chunk *chp);
    void change_chunk(int);
    void change_building_dsc(int);
    void found_settlement();
    void button_clicked(int i);
};

#endif // CHUNKCONTENT_H
