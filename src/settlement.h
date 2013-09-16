#ifndef SETTLEMENT_H
#define SETTLEMENT_H
#include "building.h"
#include <QFile>

class settlement
{
private:
    int x;
    int y;
    char settl_type;
    int ewz;
    settlement *next;
    building *builds;

public:
    settlement();
    settlement(int x,int y);
    settlement(char);
    settlement(QFile*);

    void add_building(building*);
    void set_coords(int,int);
    void set_settl_type(char);
    void set_ewz(int);
    void set_next(settlement*);

    building *give_buildings();
    char give_settl_type();
    int give_ewz();
    int give_xcord();
    int give_ycord();
    settlement *give_next();

    void add_settlement(settlement *);
    void save(QTextStream *fout=NULL,int buildcount=0);
};

inline void settlement::set_coords(int x_, int y_){
    x=x_;
    y=y_;
}

inline void settlement::set_settl_type(char c){
    settl_type=c;
}

inline void settlement::set_ewz(int newewz){
    if(newewz!=0)ewz=newewz;
    else ewz=ewz;
}

inline void settlement::set_next(settlement *next_){
    next=next_;
}

inline building *settlement::give_buildings(){
    return builds;
}

inline char settlement::give_settl_type(){
    return settl_type;
}

inline int settlement::give_ewz(){
    return ewz;
}

inline int settlement::give_xcord(){
    return x;
}

inline int settlement::give_ycord(){
    return y;
}

inline settlement *settlement::give_next(){
    return next;
}

#endif // SETTLEMENT_H
