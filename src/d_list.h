#ifndef __LISTD__ 
#define __LISTD__
#include "wrapper.h"

List createListD();
//inicia a lista -> retorna list

void insertListD(Info info, List lis);
//insere um novo node no final

void insertAfterD(Info info, List lis, Node parameter);
//insere um novo node depois de um parametros informado

void insertBeforeD(Info info, List lis, Node parameter);
//insere um novo node antes de um parametros informado

void removeNodeD(List lis, Node parameter);
//remove o node informado

int removeListD(List lis, int flag);
//remove a lista, e recebe um endereco de inteiro para armazenar o contador

int getSizeD(List lis);
//recebe a lista e retorna o tamanho

Node getFirstD(List lis);
//recebe a lista e retorna o primeiro no

Node getLastD(List lis);
//recebe a lista e retorna o ultimo no

Node getNextD(Node parameter);
//recebe um no e retorna o posterior

Node getPrevD(Node parameter);
//recebe um no e retorna o anterior

Info getInfoD(Node parameter);
//recebe um no e retorna a info do no

int getCounterD(List lis);
//recebe a lista e retorna o contador

void addCounterD(List lis, int plus);
//recebe a lista e um inteiro e soma esse inteiro ao contador da lista

#endif