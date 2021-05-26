#include "s_list.h"
#include "wrapper.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    Info info;
    struct node* next;
}structNode;

typedef struct list{
    int size;
    int counter;
    int sofar;
    structNode* lis;
}structList;

List createListS(int size){
    structList* list=(structList*) malloc(sizeof(structList));
    list->lis=(structNode*) malloc(sizeof(structNode)*size);
    for(int i=0;i<size;i++){
        list->lis[i].info=NULL;
        list->lis[i].next=NULL;
    }
    list->size=size;
    list->counter=0;
    list->sofar=0;
    return list;
}

void insertListS(Info info, List lis){ 
    structList* list=(structList*) lis;
    if(list!=NULL){
        if(list->sofar!=0){
            list->lis[list->sofar-1].next=&(list->lis[list->sofar]);
        }
        list->lis[list->sofar].info=info;
        list->counter++;
        list->sofar++;
    }
}

void removeNodeS(List lis, Node parameter){
    structList* list=(structList*) lis;
    structNode* node=(structNode*) parameter;
    free(node->info);
    node->info=NULL;
    structNode* aux;
    if(node->next==NULL){
        if(node!=&(list->lis[0])){
            list->lis[list->sofar-2].next=NULL;
        }
        list->counter++;
        list->sofar--;
        return;
    }    
    for(aux=node; aux!=&(list->lis[list->sofar-2]); aux=getNextS(aux)){
        aux->info=aux->next->info;    
        list->counter++;
    }
    aux->info=aux->next->info;    
    aux->next->info=NULL;
    aux->next=NULL;
    list->sofar--;
}

int removeListS(List lis, int flag){
    structList* list=(structList*) lis;
    if(flag==1){
        for(int i=0;i<list->sofar;i++){
            list->counter++;
            free(list->lis[i].info);
        }
    }
    int counter=list->counter;
    free(list->lis);
    free(list);
    return counter;
}

Node getFirstS(List lis){
    structList* list=(structList*) lis;
    if(list->sofar==0){
        return NULL;
    }
    return &list->lis[0];
}

Node getLastS(List lis){
    structList* list=(structList*) lis;
    int a=(list->sofar)-1;
    return &list->lis[a];
}

Info getInfoS(Node parameter){
    structNode* node=(structNode*) parameter;
    return node->info;
}

Node getNextS(Node parameter){
    structNode* node=(structNode*) parameter;
    return node->next;
}

int getSizeS(List lis){
    structList* list=(structList*) lis;
    return list->sofar;
}

int getCounterS(List lis){
    structList* list=(structList*) lis;
    return list->counter;    
}

void addCounterS(List lis, int plus){
    structList* list=(structList*) lis;
    list->counter+=plus;
}

Node getPrevS(List lis, Node node){
    Node aux=getFirst(lis);
    if(node==getFirst(lis)){
        return NULL;
    }else{
        while(aux!=node){
            aux=getNext(lis,aux);
        }
    }
    return aux;
}