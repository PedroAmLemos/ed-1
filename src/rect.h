#include <stdio.h>
#ifndef __RECT__
#define __RECT__
typedef void* Rect;

Rect createRect(char id[40],char fill[40],char shape[40], float x, float y, float w, float h);
//recebe os dados iniciais, cria e preenche o retangulo

void changeFill(Rect recta, char nfill[40]);
//recebe o retangulo e o fill para substituir

void changeShape(Rect recta, char nshape[40]);
//recebe o retangulo e o shape para substituir

void changeX(Rect recta, float nx);
//recebe o retangulo e o x para substituir

void changeY(Rect recta, float ny);
//recebe o retangulo e o y para substituir

void changeW(Rect recta, float nw);
//recebe o retangulo e o w para substituir

void changeH(Rect recta, float nH);
//recebe o retangulo e o H para substituir

char* getId(Rect recta);
//recebe o retangulo e retorna o id

char* getFill(Rect recta);
//recebe o retangulo e retorna o fill

char* getShape(Rect recta);
//recebe o retangulo e retorna o shape

float getX(Rect recta);
//recebe o retangulo e retorna o x

float getY(Rect recta);
//recebe o retangulo e retorna o y

float getW(Rect recta);
//recebe o retangulo e retorna o w

float getH(Rect recta);
//recebe o retangulo e retorna o h

void printSvg(FILE* svgArq, Rect recta);
//recebe o arquivo svg e um retangulo e desenha o retangulo









#endif