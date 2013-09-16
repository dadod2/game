#include "building_props.h"
#include <QDebug>

int building_props::my_atoi(char *p){
    int i;
    while(*p==45 || *p==32 || *p=='\n')p++;
    for(i=0;isdigit(*p);p++){
        i=i*10+*p-48;
    }
return i;
}

void building_props::save(QTextStream *fp){
    *fp << name << endl;
    *fp << (char)WLVL << (char)NLVL << (char)GLVL << (char)VLVL << (char)OLVL << (char)KLVL << (char)ULVL << (char)WlLVL << (char)BLVL << endl;
    *fp << (int)bk << endl;
    *fp << (int)uk << endl;
}

building_props::building_props(QString name_,
                   int WLVL_,
                   int NLVL_,
                   int GLVL_,
                   int VLVL_,
                   int OLVL_,
                   int KLVL_,
                   int ULVL_,
                   int WlLVL_,
                   int BLVL_,
                   QString bk_,
                   QString uk_
                   )
{
    switch(WLVL_){
    case 0: WLVL='b'; break;case 1: WLVL='c'; break;case 2: WLVL='d'; break;case 3: WLVL='e'; break;case 4: WLVL='f'; break;case 5: WLVL='g'; break;case 6: WLVL='h'; break;case 7: WLVL='i'; break;case 8: WLVL='j'; break;default:break;
    }
    switch(NLVL_){
    case 0: NLVL='b'; break;case 1: NLVL='c'; break;case 2: NLVL='d'; break;case 3: NLVL='e'; break;case 4: NLVL='f'; break;case 5: NLVL='g'; break;case 6: NLVL='h'; break;case 7: NLVL='i'; break;case 8: NLVL='j'; break;default:break;
    }
    switch(GLVL_){
    case 0: GLVL='b'; break;case 1: GLVL='c'; break;case 2: GLVL='d'; break;case 3: GLVL='e'; break;case 4: GLVL='f'; break;case 5: GLVL='g'; break;case 6: GLVL='h'; break;case 7: GLVL='i'; break;case 8: GLVL='j'; break;default:break;
    }
    switch(VLVL_){
    case 0: VLVL='b'; break;case 1: VLVL='c'; break;case 2: VLVL='d'; break;case 3: VLVL='e'; break;case 4: VLVL='f'; break;case 5: VLVL='g'; break;case 6: VLVL='h'; break;case 7: VLVL='i'; break;case 8: VLVL='j'; break;default:break;
    }
    switch(OLVL_){
    case 0: OLVL='b'; break;case 1: OLVL='c'; break;case 2: OLVL='d'; break;case 3: OLVL='e'; break;case 4: OLVL='f'; break;case 5: OLVL='g'; break;case 6: OLVL='h'; break;case 7: OLVL='i'; break;case 8: OLVL='j'; break;default:break;
    }
    switch(KLVL_){
    case 0: KLVL='b'; break;case 1: KLVL='c'; break;case 2: KLVL='d'; break;case 3: KLVL='e'; break;case 4: KLVL='f'; break;case 5: KLVL='g'; break;case 6: KLVL='h'; break;case 7: KLVL='i'; break;case 8: KLVL='j'; break;default:break;
    }
    switch(ULVL_){
    case 0: ULVL='b'; break;case 1: ULVL='c'; break;case 2: ULVL='d'; break;case 3: ULVL='e'; break;case 4: ULVL='f'; break;case 5: ULVL='g'; break;case 6: ULVL='h'; break;case 7: ULVL='i'; break;case 8: ULVL='j'; break;default:break;
    }
    switch(WlLVL_){
    case 0: WlLVL='b'; break;case 1: WlLVL='c'; break;case 2: WlLVL='d'; break;case 3: WlLVL='e'; break;case 4: WlLVL='f'; break;case 5: WlLVL='g'; break;case 6: WlLVL='h'; break;case 7: WlLVL='i'; break;case 8: WlLVL='j'; break;default:break;
    }
    switch(BLVL_){
    case 0: BLVL='b'; break;case 1: BLVL='c'; break;case 2: BLVL='d'; break;case 3: BLVL='e'; break;case 4: BLVL='f'; break;case 5: BLVL='g'; break;case 6: BLVL='h'; break;case 7: BLVL='i'; break;case 8: BLVL='j'; break;default:break;
    }

    name=name_;
    IN=0;
    //WLVL=WLVL_;
    //NLVL=NLVL_;
    //GLVL=GLVL_;
    //VLVL=VLVL_;
    //OLVL=OLVL_;
    next=NULL;
    bk=bk_.toInt(0,10);
    uk=uk_.toInt(0,10);
    //uk=QString::number(uk_);
}


building_props* building_props::get_byIN(int i){
    //building_props *hp1;
    building_props *hp2=this;
    while(hp2 && hp2->give_IN()!=i){
        //hp1=hp2;
        hp2=hp2->give_next();
    }
    if(hp2)return hp2;
    else {
        qDebug("no matching building!");
        return NULL;
    }

}

building_props::building_props(QFile *fin){
    char namepuffer[20];
    char pmpuffer[15];
    char bkpuffer[8];
    char ukpuffer[8];
    fin->readLine(&namepuffer[0],20);
    name=namepuffer;
    fin->readLine(&pmpuffer[0],15);
    WLVL=pmpuffer[0];
    NLVL=pmpuffer[1];
    GLVL=pmpuffer[2];
    VLVL=pmpuffer[3];
    OLVL=pmpuffer[4];
    fin->readLine(&bkpuffer[0],8);
    bk=my_atoi(&bkpuffer[0]);
    fin->readLine(&ukpuffer[0],8);
    uk=my_atoi(&ukpuffer[0]);
}

void building_props::add_building(building_props *bphp1){
    building_props *bphp2=this;
    building_props *bphp3=this;
    while(bphp2){
        bphp3=bphp2;
        bphp2=bphp2->give_next();
    }
    bphp3->set_next(bphp1);
}
