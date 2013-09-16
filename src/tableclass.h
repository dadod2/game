#ifndef TABLECLASS_H
#define TABLECLASS_H
//#define NULL=null

class tableclass
{
private:
    int first;
    int second;
    tableclass *next;

public:
    tableclass();
    void set_first(int);    //index in buildcombo
    void set_second(int);   //index in building liste
    void set_next(tableclass *hp=0);
    int get_first();
    int get_second();
    tableclass *get_next();
    void clear();
    int get_secbyfirst(int);
    void add(tableclass *hp=0,int sec_=0);
};

#endif // TABLECLASS_H

inline void tableclass::set_first(int i){
    first=i;
}

inline void tableclass::set_second(int i){
    second=i;
}

inline void tableclass::set_next(tableclass* hp){
    next=hp;
}

inline int tableclass::get_first(){
    return first;
}

inline int tableclass::get_second(){
    return second;
}

inline tableclass *tableclass::get_next(){
    return next;
}
