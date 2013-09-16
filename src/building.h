#ifndef BUILDING_H
#define BUILDING_H
#include <QString>
#include <QTextStream>
#include "building_props.h"

class building
{
private:
    int IN;
    building *next;

public:
    building();
    building(building_props*);
    void save(QTextStream*);
    int give_IN();
    building *give_next();
    void set_next(building*);
    void set_IN(int);
};

inline int building::give_IN(){
    return IN;
}

inline building *building::give_next(){
    return next;
}

inline void building::set_next(building *next_){
    next=next_;
}

inline void building::set_IN(int i){
    IN=i;
}

#endif // BUILDING_H
