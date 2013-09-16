#ifndef CHUNK_H
#define CHUNK_H

#include "settlement.h"
#include <QWidget>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QGridLayout>

class chunk
{

private:
    char type;
    int x;
    int y;
    settlement *settlementp;

public:
    explicit chunk(QWidget *parent = 0);
    chunk(char);
    chunk(QFile*,int x_=0,int y_=0);

    char give_type();
    int give_xcord();
    int give_ycord();
    settlement *give_settlement();

    void set_type(char);
    void set_settlement(settlement*);
    void set_coords(int,int);

    void save(QTextStream*);
};

inline char chunk::give_type(){
    return type;
}

inline int chunk::give_xcord(){
    return x;
}

inline int chunk::give_ycord(){
    return y;
}

inline settlement *chunk::give_settlement(){
    return settlementp;
}

inline void chunk::set_type(char c){
    type=c;
}

inline void chunk::set_coords(int x_, int y_){
    x=x_;
    y=y_;
}

inline void chunk::set_settlement(settlement *settlement_){
    settlementp=settlement_;
}

#endif // CHUNK_H
