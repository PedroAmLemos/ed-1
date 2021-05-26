#include "rect.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct rectangle{
    char id[40], fill[40], shape[40];
    float x,y,w,h;
}rec;

Rect createRect(char id[40],char fill[40],char shape[40], float x, float y, float w, float h){
    rec* rectan=(rec*)malloc(sizeof(rec));
    strcpy(rectan->id, id);
    strcpy(rectan->fill, fill);
    strcpy(rectan->shape, shape);
    rectan->x=x;
    rectan->y=y;
    rectan->w=w;
    rectan->h=h;
    return rectan;
}

void changeFill(Rect recta, char nfill[40]){
    rec* rectan=(rec*) recta;
    strcpy(rectan->fill,nfill);
}

void changeShape(Rect recta, char nshape[40]){
    rec* rectan=(rec*) recta;
    strcpy(rectan->shape,nshape);
}

void changeX(Rect recta, float nx){
    rec* rectan=(rec*) recta;
    rectan->x=nx;   
}

void changeY(Rect recta, float ny){
    rec* rectan=(rec*) recta;
    rectan->y=ny;   
}

void changeW(Rect recta, float nw){
    rec* rectan=(rec*) recta;
    rectan->w=nw;   
}

void changeH(Rect recta, float nh){
    rec* rectan=(rec*) recta;
    rectan->h=nh;
}

char* getId(Rect recta){
    rec* rectan=(rec*) recta;
    return rectan->id;
}

char* getFill(Rect recta){
    rec* rectan=(rec*) recta;
    return rectan->fill;
}

char* getShape(Rect recta){
    rec* rectan=(rec*) recta;
    return rectan->shape;
}

float getX(Rect recta){
    rec* rectan=(rec*) recta;
    return rectan->x;
}

float getY(Rect recta){
    rec* rectan=(rec*) recta;
    return rectan->y;
}

float getW(Rect recta){
    rec* rectan=(rec*) recta;
    return rectan->w;
}

float getH(Rect recta){
    rec* rectan=(rec*) recta;
    return rectan->h;
}

void printSvg(FILE* svgArq, Rect recta){
    rec* rectan=(rec*) recta;
    fprintf(svgArq,"\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\"/>\n",rectan->x,rectan->y,rectan->w,rectan->h,rectan->fill,rectan->shape);
}
