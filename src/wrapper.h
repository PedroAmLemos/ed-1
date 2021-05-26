#ifndef __WRAPPER__
#define __WRAPPER__
typedef void* List;
typedef void* Node;
typedef void* Info;

List create(int a, int size);
//recebe o tipo de lista e o tamanho, e determina qual tipo de lista usar, retorna um void pointer pra lista

void insert(Info info, List lis);
//recebe a info que deve ser passada e a lista, determina qual tipo de lista usar e insere a info na lista

void removeNode(List lis, Node parameter);
//recebe a lista e o node que deve ser removido, e determina qual tipo de lista usar, remove o node passado

int removeList(List lis, int flag);
//recebe a lista, uma flag que indica se deve ser realizado free nas infos, e deleta a lista, retornando o contador de visitas

Node getFirst(List lis);
//recebe a lista e retorna o primeiro no 

Node getLast(List lis);
//recebe a lista e retorna o ultimo no 

Node getNext(List lis, Node parameter);
//recebe a lista e um node, e retorna o primeiro no 

Info getInfo(List lis, Node parameter);
//recebe a lista e um node, e retorna a info desse node

int getSize(List lis);
//recebe a lista e retorna o tamanho atual dela

int getCounter(List lis);
//recebe a lista e retorna o contador atual 

void addCounter(List lis, int plus);
//recebe a lista e um inteiro que sera somado no contador de visitas

int getType(List lis);
//recebe a lista e retorna o tipo dela

int getSofar(List lis);
//recebe a lista e retorna o numero de nos utilizados

Node getPrev(List lis, Node node);
//recebe a lista e um no, retorna o no anterior

int getIniSize(List lis);
//recebe a lista e retorna o tamanho inicial dela 


#endif
