#ifndef __LISTS__
#define __LISTS__
#include "wrapper.h"

List createListS(int size);
//recebe o tamanho maximo da lista, cria a lista -> retorna list

void insertListS(Info info, List lis);
//recebe a informacao e a lista e adiciona info no primeiro node disponivel

void removeNodeS(List lis, Node parameter);
//recebe a lista e um node para ser removido

int removeListS(List lis, int flag);
//recebe a lista e da free no vetor de struct

Node getFirstS(List lis);
//recebe a lista e retorna o lis[0]

Info getInfoS(Node parameter);
//recebe um node e retorna a info desse node

Node getLastS(List lis);
//recebe a lista e retorna o lis[sofar-1]

Node getNextS(Node parameter);
//recebe um node e retorna o node.next

int getSizeS(List lis);
//recebe a lista e retorna o tamanho

int getCounterS(List lis);
//recebe a lista e retorna o contado

void addCounterS(List lis, int plus);
//recebe a lista e um inteiro e soma o inteiro com o contador da lista

Node getPrevS(List lis, Node node);
//recebe a lista e um node e retorna o node anterior

#endif