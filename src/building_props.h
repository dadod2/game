#ifndef BUILDING_PROPS_H
#define BUILDING_PROPS_H

#include <QString>
#include <QTextStream>
#include <QFile>
#include <QDebug>

class building_props
{
private:
    QString name;
    int IN;
    char WLVL;//wasserlvl
    char NLVL;//nahrungslvl
    char GLVL;//gesundheitslvl
    char VLVL;//verschmutzungslvl
    char OLVL;//ordnungslvl
    char KLVL;//kulturlvl
    char ULVL;//unterhaltungslvl
    char WlLVL;//Wohlstandslvl
    char BLVL;//Bildungslvl
    int bk;//baukosten
    int uk;//unterhaltskosten
    building_props *next;

public:
    building_props(QString name_="unbenannt",
             int WLVL_=0,
             int NLVL_=0,
             int GLVL_=0,
             int VLVL_=0,
             int OLVL_=0,
             int KLVL_=0,
             int ULVL_=0,
             int WlLVL_=0,
             int BLVL_=0,
             QString bk_=0,
             QString uk_=0
             );
    building_props(QFile *fin);

    int give_IN();
    char give_WLVL();
    char give_NLVL();
    char give_GLVL();
    char give_VLVL();
    char give_OLVL();
    char give_KLVL();
    char give_ULVL();
    char give_WlLVL();
    char give_BLVL();
    int give_bk();
    int give_uk();

    building_props *give_next();

    void set_next(building_props *hp=NULL);
    void set_IN(int);

    int my_atoi(char *);
    void save(QTextStream *hp=NULL);
    void print_name();
    void add_building(building_props*);
    building_props *get_byIN(int i=0);
    QString give_name();
};

inline int building_props::give_IN(){
    return IN;
}

inline char building_props::give_WLVL(){
    return WLVL;
}

inline char building_props::give_NLVL(){
    return NLVL;
}

inline char building_props::give_VLVL(){
    return VLVL;
}

inline char building_props::give_GLVL(){
    return GLVL;
}

inline char building_props::give_OLVL(){
    return OLVL;
}

inline char building_props::give_KLVL(){
    return KLVL;
}

inline char building_props::give_ULVL(){
    return ULVL;
}

inline char building_props::give_WlLVL(){
    return WlLVL;
}

inline char building_props::give_BLVL(){
    return BLVL;
}

inline int building_props::give_bk(){
    return bk;
}

inline int building_props::give_uk(){
    return uk;
}

inline building_props *building_props::give_next(){
    return next;
}

inline void building_props::set_next(building_props *next_){
    next=next_;
}

inline void building_props::set_IN(int i){
    IN=i;
}

inline void building_props::print_name(){
    qDebug() << name;
}

inline QString building_props::give_name(){
    return name;
}

#endif // BUILDING_PROPS_H
