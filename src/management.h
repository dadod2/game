#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "chunk.h"
#include "settlement.h"
#include "building_props.h"

class management
{
private:
    int mapsize;
    int buildcount;
    int winsize;
    int stepsize;
    chunk ***map;
    QString savedir;
    settlement *settlements;
    building_props *buildings;

public:
    management(chunk ***map_=NULL,settlement *settlements_=NULL,building_props *buildings_=NULL);
    void set_map(chunk***);
    void set_settlements(settlement*);
    void set_building_props(building_props*);
    void set_mapsize(int);
    void set_buildcount(int);
    void set_winsize(int);
    void set_stepsize(int);
    void set_savedir(QString);

    chunk*** give_map();
    QString give_savedir();
    settlement* give_settlements();
    building_props* give_building_props();
    int give_mapsize();
    int give_buildcount();
    int give_winsize();
    int give_stepsize();

    void add_settlement(settlement*);
    void add_building_props(building_props*);
    void test_settlements();

public slots:
    void fount_settlement(chunk***);
};

inline void management::set_map(chunk ***chp){
    map=chp;
}

inline void management::set_settlements(settlement *shp){
    settlements=shp;
}

inline void management::set_building_props(building_props *bphp){
    buildings=bphp;
}

inline void management::set_mapsize(int i){
    mapsize=i;
}

inline void management::set_buildcount(int i){
    buildcount=i;
}

inline void management::set_winsize(int i){
    winsize=i;
}

inline void management::set_stepsize(int i){
    stepsize=i;
}

inline void management::set_savedir(QString s){
    savedir=s;
}

inline chunk*** management::give_map(){
    return map;
}

inline QString management::give_savedir(){
    return savedir;
}

inline settlement* management::give_settlements(){
    return settlements;
}

inline building_props* management::give_building_props(){
    return buildings;
}

inline int management::give_mapsize(){
    return mapsize;
}

inline int management::give_buildcount(){
    return buildcount;
}

inline int management::give_winsize(){
    return winsize;
}

inline int management::give_stepsize(){
    return stepsize;
}

inline void management::add_settlement(settlement *shp){
    if(settlements){
        settlements->add_settlement(shp);
    }
    else{
        settlements=shp;
    }
}

inline void management::add_building_props(building_props *bphp){
    if(buildings){
        buildings->add_building(bphp);
    }
    else{
        buildings=bphp;
    }
}

inline void management::test_settlements(){
    settlement *shp;
    shp=settlements;
    while(shp){
        qDebug() << shp;
        shp=shp->give_next();
    }
}

#endif // MANAGEMENT_H

