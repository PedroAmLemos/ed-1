#ifndef __SVG__
#define __SVG__
#include <stdio.h>
#include "wrapper.h"


FILE* createTag(char* svgPathName);
//recebe o caminho do arquivo svg, cria o arquivo abre a tag e retorna um ponteiro para o arquivo;

void printRects(FILE* svgArq, List lis, List extraFig);
//recebe a lista de retangulo, a lista de figuras que devem ser printadas por cima, e o arquivo svg

void closeTag(FILE* svgArq);
//recebe o arquivo svg e fecha a tag 

#endif