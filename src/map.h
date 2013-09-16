#ifndef MAP_H
#define MAP_H
#include <QFile>
#include "chunk.h"

int my_atoi(char *p);
void deletemap(chunk*** map);
chunk*** mapload(chunk*** map,QFile *fp);
int disp(chunk ***map);
char get_chunk_type(chunk ***map, int x, int y);
char my_rand(char **map,int *a,int *b,int *c,int *d,float e,float f,float g,float h,int x,int y,int size);
int mapgen(int size_index,QFile *fp,float e,float f,float g,float h);

#endif // MAP_H
