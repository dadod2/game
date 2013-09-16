#include <QDebug>
#include <QTextStream>
#include <cstdlib>
#include "chunk.h"
#include "map.h"

using  	namespace std;

void deletemap(chunk*** map){
    int i=0,j=0;
    while(*(map+i)){
        while(*(*(map+i)+j)){
            delete *(*(map+i)+j);
            j++;
        }
    delete *(map+i);
    i++;
    }
delete map;
map=NULL;
}


chunk*** mapload(chunk*** map,QFile *fin){
    int size;
    char size_char[10];
    fin->readLine(&size_char[0],10);
    size=my_atoi(&size_char[0]);
    int i=0,j=0;

    map=new chunk** [(size+1)*sizeof(chunk**)];
    for(i=0;i<size;i++){
        *(map+i)=new chunk* [(size+1)*sizeof(chunk*)];
        for(j=0;j<size;j++){
            *(*(map+i)+j)=new chunk(fin,i,j);
        }
        *(*(map+i)+size)=NULL;
    }
    *(map+size)=NULL;
fin->close();
return map;
}

/***************************************/
/* MAP GENERATOR                       */
/***************************************/

char my_rand(char **map,int *a,int *b,int *c,int *d,float e,float f,float g,float h,int x,int y,int size){
    int q,r,i,j,k,l,m=0,n=0,o=0,p=0;
    char ch;
    //a anzahl von geländetyp 1
    //b anzahl von geländetyp 2
    //c anzahl von geländetyp 3
    //d anzahl von geländetyp 4

    //e angestrebte % von geländetyp 1
    //f angestrebte % von geländetyp 2
    //g angestrebte % von geländetyp 3
    //h angestrebte % von geländetyp 4

    //i % für geländetyp 1
    //j % für geländetyp 2
    //k % für geländetyp 3
    //l % für geländetyp 4

    //m anzahl anschließender chunks vom type 1
    //n anzahl anschließender chunks vom type 2
    //o anzahl anschließender chunks vom type 3
    //p anzahl anschließender chunks vom type 4

    //q hilfsvariable
    //r hilfsvariable
    //ch hilfsvariable

    for(q=-1;q<2;q++){
        for(r=-1;r<2;r++){
            if(r==0 && q==0){
                continue;
            }
            else if((x+q)>=0 && (y+r)>=0 && (x+q)<size && (y+r)<size && map[x+q][y+r]!='e'){
                ch=map[x+q][y+r];
                if(ch=='a'){
                    m++;
                }
                if(ch=='b'){
                    n++;
                }
                if(ch=='c'){
                    o++;
                }
                if(ch=='d'){
                    p++;
                }
            }
        }
    }
    /*
    i=(int)(e*size*size)-(int)(*a)+(int)400*m-(int)00*n-(int)200*o+(int)00*p;
    if(i<0)i=5;
    j=(int)(f*size*size)-(int)(*b)-(int)00*m+(int)300*n+(int)150*o+(int)00*p;
    if(j<0)j=5;
    k=(int)(g*size*size)-(int)(*c)-(int)200*m+(int)200*n+(int)200*o+(int)00*p;
    if(k<0)k=5;
    l=(int)(h*size*size)-(int)(*d)+(int)50*m+(int)20*n-(int)100*o+(int)20*p;
    if(l<0)l=5;
    */
    i=(int)(e*size*size)-(int)(*a)+(int)5*size*m-(int)00*size*n-(int)1.25*size*o+(int)00*size*p;
    if(i<0)i=5;
    j=(int)(f*size*size)-(int)(*b)-(int)00*size*m+(int)2.5*size*n+(int)2.5*size*o+(int)00*size*p;
    if(j<0)j=5;
    k=(int)(g*size*size)-(int)(*c)-(int)2.5*size*m+(int)2.5*size*n+(int)2.5*size*o+(int)00*size*p;
    if(k<0)k=5;
    l=(int)(h*size*size)-(int)(*d)+(int)2.5*size*m+(int)2.5*size*n-(int)2.5*size*o+(int)2.5*size*p;
    if(l<0)l=5;
    q=i+j+k+l;
    r=rand()%q;

    if(0<=r && r<i){
        ch='a';
        (*a)++;
    }
    else if(i<=r && r<(i+j)){
        ch='b';
        (*b)++;
    }
    else if((i+j)<=r && r<(i+j+k)){
        ch='c';
        (*c)++;
    }
    else if((i+j+k)<=r && r<(i+j+k+l)){
        ch='d';
        (*d)++;
    }

return ch;
}


int mapgen(int size_index/*,int buildcount*/,QFile *fp,float e,float f,float g,float h){
    int size=0;

    switch(size_index){
    case 0: size=50;
            break;
    case 1: size=100;
            break;
    case 2: size=200;
            break;
    case 3: size=500;
            break;
    default:qDebug("%i Error size_index doas not match any member!",size_index);
            break;
    }

    int bon=10,k,i,j;					//Kartengröße, überstand und hilfsvariablen
    int a=0,b=0,c=0,d=0;

    //anzahl von Geländetypen auf der karte
    char **map=new char*[size+bon];
    for(i=0;i<(size+bon);i++){
        map[i]=new char[size+bon];
    }
    chunk ***map2=new chunk** [size+1];
    *(map2+size)=NULL;
    for(i=0;i<size;i++){
        *(map2+i)=new chunk* [size+1];
        *(*(map2+i)+size)=NULL;
    }

    for(i=0;i<(size+bon);i++){
        for(j=0;j<(size+bon);j++){
            map[i][j]='e';
        }
    }

    //Map erstellen

    srand(time(0));
    if((size+bon)%2!=1){
        k=0;
        for(i=0;i<(size+bon)/2;i++){
            for(j=k;j<(size+bon-k);j++){
                map[i][j]=my_rand(map,&a,&b,&c,&d,e,f,g,h,i,j,size+bon);
                map[(size+bon-1)-i][j]=my_rand(map,&a,&b,&c,&d,e,f,g,h,(size+bon-1)-i,j,size+bon);
            }
            for(j=(i+1);j<(size+bon-(i+1));j++){
                map[j][k]=my_rand(map,&a,&b,&c,&d,e,f,g,h,j,k,size+bon);
                map[j][(size+bon-1)-k]=my_rand(map,&a,&b,&c,&d,e,f,g,h,j,(size+bon-1)-k,size+bon);
            }
        k++;
        }
    }

    //Rand weg schneiden und map mit rand löschen

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            *(*(map2+i)+j)=new chunk(map[i+bon][j+bon]);

        }
    }

    for(i=0;i<(size+bon);i++){
        delete map[i];
    }
    delete map;

    //Map etwas begradigen

    for(i=1;i<(size-1);i++){
        for(j=1;j<(size-1);j++){
            if(((*(*(map2+i)+j))->give_type())=='a'){
                k=0;
                if(((*(*(map2+i-1)+j))->give_type())!='a')k++;
                if(((*(*(map2+i)+j+1))->give_type())!='a')k++;
                if(((*(*(map2+i+1)+j))->give_type())!='a')k++;
                if(((*(*(map2+i)+j-1))->give_type())!='a')k++;
                if(k==4){
                    ((*(*(map2+i)+j))->set_type('b'));
                }
            }
            else if(((*(*(map2+i)+j))->give_type())=='b'){
                k=0;
                if(((*(*(map2+i-1)+j))->give_type())!='b')k++;
                if(((*(*(map2+i)+j+1))->give_type())!='b')k++;
                if(((*(*(map2+i+1)+j))->give_type())!='b')k++;
                if(((*(*(map2+i)+j-1))->give_type())!='b')k++;
                if(k==4){
                    ((*(*(map2+i)+j))->set_type('a'));
                }
            }
        }
    }

    //Abspeichern in Datei
    QTextStream fout(fp);
    fout << size << endl;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            map2[i][j]->save(&fout/*,buildcount*/);
        }
    }
    fout.flush();
return 0;
}


