#include "tableclass.h"
#include <QDebug>

tableclass::tableclass()
{
    first=0;
    second=0;
    next=0;
}

void tableclass::clear(){
    tableclass *hp1;
    tableclass *hp2;
    if(next){
        hp1=next;
        while(hp1){
            hp2=hp1;
            hp1=hp1->get_next();
            delete hp2;
        }
        next=0;
    }
}

int tableclass::get_secbyfirst(int i){
    tableclass *hp;
    hp=this;
    while(hp){
        if((hp->first)==i)return (hp->get_second());
        else hp=hp->get_next();
    }
    qDebug("Error, no matching first_var");qDebug() << i;
    return 0;
}

void tableclass::add(tableclass *hp,int sec_){
    tableclass *hp1;
    tableclass *hp2=this;
    while(hp2){
        hp1=hp2;
        hp2=hp2->get_next();
    }
    hp1->set_next(hp);
    hp->set_first((hp1->get_first())+1);
    hp->set_second(sec_);
}
