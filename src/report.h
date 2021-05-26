#ifndef __REPORT__
#define __REPORT__
#include <stdio.h>

void beginCol(int size, int counter,char *outPath);
//recebe o tamanho da lista, o numero de visitas e o caminho de saida. inicia a coleta de dados do programa

void continueCol(int size, int counter,char *outPath);
//recebe o tamanho da lista, o numero de visitas e o caminho de saida. continua a coleta de dados do programa

void finCol(int size, int counter, char *outPath, char *nameArq, char* arqTitle);
//recebe o tamanho da lista, o numero de visitas, o caminho de saida, o nome do relatorio e o titulo. finaliza a coleta de dados do programa


#endif