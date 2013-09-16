#include "chunk.h"

int my_atoi(char *p){
    int i;
    while(*p==45 || *p==32 || *p=='\n')p++;
    for(i=0;isdigit(*p);p++){
        i=i*10+*p-48;
    }
return i;
}

settlement::settlement()
{
    x=-1;
    y=-1;
    settl_type='a';
    builds=NULL;
    next=NULL;
    ewz=100;
}

settlement::settlement(int x_,int y_)
{
    x=x_;
    y=y_;
    settl_type='a';
    builds=NULL;
    next=NULL;
    ewz=100;

}

settlement::settlement(char c)
{
    x=-1;
    y=-1;
    settl_type=c;
    builds=NULL;
    next=NULL;
    ewz=0;
}

settlement::settlement(QFile *fin)
{
    building *hp;
    int i=1;
    char c[30];
    fin->readLine(c,10);
    x=my_atoi(&c[0]);
    fin->readLine(c,10);
    y=my_atoi(&c[0]);
    fin->readLine(c,30);
    settl_type=c[0];
    builds=NULL;
    while(c[i]!='\n' && c[i]!=EOF){
        if(c[i]=='b'){
            hp=new building(0);
            hp->set_IN(i);
            add_building(hp);
        }
        i++;
    }
    fin->readLine(c,10);
    ewz=my_atoi(&c[0]);
    next=NULL;
}

void settlement::add_building(building *newbuild){
    building *hp=builds;
    building *hp2=NULL;
    while(hp && hp->give_IN()!=newbuild->give_IN()){
        hp2=hp;
        hp=hp->give_next();
    }
    if(hp && hp->give_IN()==newbuild->give_IN()){

    }
    else if(hp2){
        hp2->set_next(newbuild);
    }
    else{
        builds=newbuild;
    }
}
void settlement::add_settlement(settlement *newsettlement){
    settlement *hp1=this;
    settlement *hp2=this;
    while(hp2){
        hp1=hp2;
        hp2=hp2->give_next();
    }
    hp1->set_next(newsettlement);
}

void settlement::save(QTextStream *fout,int buildcount){
    int i=1;
    building *hp=builds;
    *fout << x << endl;
    *fout << y << endl;
    *fout << settl_type;
    while(i<=buildcount){
        if(hp){
            if((hp->give_IN())==i){
                *fout << "b";
                hp=hp->give_next();
            }
            else
                *fout << "a";
        }
        else{
            *fout << "a";
        }
        i++;
    }
    *fout << endl;
    *fout << ewz << endl;
}
