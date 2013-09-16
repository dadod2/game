#include "chunk.h"
#include <QObject>

chunk::chunk(char c)
{
    type=c;
    x=0;
    y=0;
    settlementp=NULL;
}

chunk::chunk(QFile* fin,int x_,int y_)
{
    char c[10];
    fin->readLine(c,5);
    type=c[0];
    x=x_;
    y=y_;
    settlementp=NULL;
}

//andere Funktionen

void chunk::save(QTextStream* fout){
    *fout << type << endl;
}



