#include "d_list.h"
#include "wrapper.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    Info info;
    struct node* prev;
    struct node* next;
}structNode;

typedef struct list{
    structNode* first;
    structNode* last;
    int size;
    int counter;
}structList;

List createListD(){
    structList* list=(structList*) malloc(sizeof(structList));
    list->first=NULL;
    list->last=NULL;
    list->size=0;
    list->counter=0;
    return list;
}

void insertListD(Info info, List lis){
    structList* list=(structList*) lis;
    structNode* node=(structNode*) malloc(sizeof(structNode));
    node->info=info;
    if(list->first==NULL){
        node->prev=NULL;
        list->first=node;
    }else{
        node->prev=list->last;
        list->last->next=node;
    }
    node->next=NULL;
    list->last=node;
    list->size++;
    list->counter++;
}

void insertAfterD(Info info, List lis, Node parameter){
    structList* list=(structList*) lis;
    structNode* node=(structNode*) parameter;
    structNode* new=(structNode*) malloc(sizeof(structNode));
    if(node->next==NULL){
        new->next=NULL;        
        new->prev=node;
        node->next=new;
        list->last=new;
    }else{
        structNode* aux=node->next;
        new->prev=node;
        new->next=aux;
        node->next=new;
        aux->prev=new;
    }
    new->info=info;
    list->size++;
    list->counter++;
}

void insertBeforeD(Info info, List lis, Node parameter){
    structList* list=(structList*) lis;
    structNode* node=(structNode*) parameter;
    structNode* new=(structNode*) malloc(sizeof(structNode));
    new->info=info;
    if(node->prev==NULL){
        new->prev=NULL;
        new->next=node;
        node->prev=new;
        list->first=new;
    }else{
        structNode* aux=node->prev;
        new->next=node;
        new->prev=aux;
        node->prev=new;
        aux->next=new;
    }
    list->size++;
    list->counter++;
}

void removeNodeD(List lis, Node parameter){
    structList* list=(structList*) lis;
    structNode* remove=(structNode*) parameter;
    if(remove->prev==NULL){
        list->first=remove->next;
    }else{
        remove->prev->next=remove->next;
    }
    if(remove->next==NULL){
        list->last=remove->prev;
    }else{
        remove->next->prev=remove->prev;
    }
    free(remove->info);
    free(remove);
    list->size--;
    list->counter++;
}

int removeListD(List lis, int flag){
    structList* list=(structList*) lis;
    structNode* node=list->first;
    structNode* aux;
    while (node!=NULL){
        aux=node;
        node=node->next;
        if(flag==1)
            free(aux->info);
        free(aux);
        list->counter++;
    }
    int counter=list->counter;
    free(list);
    return counter;
}

int getSizeD(List lis){
    structList* list=(structList*) lis;
    return list->size;
}

Node getFirstD(List lis){
    structList* list=(structList*) lis;
    return list->first;
}

Node getLastD(List lis){
    structList* list=(structList*) lis;
    return list->last;
}

Node getNextD(Node parameter){
    structNode* node=(structNode*) parameter;
    return node->next;
}

Node getPrevD(Node parameter){
    structNode* node=(structNode*) parameter;
    return node->prev;
}

Info getInfoD(Node parameter){
    structNode* node=(structNode*) parameter;
    return node->info;
}

int getCounterD(List lis){
    structList* list=(structList*) lis;
    return list->counter;    
}

void addCounterD(List lis, int plus){
    structList* list=(structList*) lis;
    list->counter+=plus;
}