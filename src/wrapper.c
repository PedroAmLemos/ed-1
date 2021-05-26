#include "wrapper.h"
#include "d_list.h"
#include "s_list.h"
#include "rect.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int n;
    void* lis;
    int size;
}structList ;

List create(int a, int size){
    structList* list=malloc(sizeof(structList));
    list->size=size;
    if(a==1){
        list->n=1;
        list->lis=createListD();
    }else{
        list->n=0;
        list->lis=createListS(size);
    }
    return list;
}

void insert(Info info, List lis){
    structList* list=(structList*) lis;
    if(list->n==1){
        insertListD(info, list->lis);
    }else{
        insertListS(info, list->lis);
    }
}

void removeNode(List lis, Node parameter){
    structList* list=(structList*) lis;
    if(list->n==1){
        removeNodeD(list->lis, parameter);
    }else{
        removeNodeS(list->lis, parameter);
    }

}

int removeList(List lis, int flag){
    structList* list=(structList*) lis;
    int counter=0;
    if(list->n==1){
        counter=removeListD(list->lis, flag);
    }else{
        counter=removeListS(list->lis, flag);
    }
    free(list);
    return counter;
}

Node getFirst(List lis){
    structList* list=(structList*) lis;
    if(list->n==1){
        Node first=getFirstD(list->lis);
        return first;
    }else{
        Node first=getFirstS(list->lis);
        return first;
    }
}

Node getLast(List lis){
    structList* list=(structList*) lis;
    if(list->n==1){
        Node last=getLastD(list->lis);
        return last;
    }else{
        Node last=getLastS(list->lis);
        return last;
    }
}

Node getNext(List lis, Node parameter){
    structList* list=(structList*) lis;
    if(list->n==1){
        Node next=getNextD(parameter);
        return next;
    }else{
        Node next=getNextS(parameter);
        return next;
    }
}

Info getInfo(List lis, Node parameter){
    structList* list=(structList*) lis;
    if(list->n==1){
        Info info=getInfoD(parameter);
        return info;
    }else{
        Info info=getInfoS(parameter);
        return info;
    }
}

int getSize(List lis){
    structList* list=(structList*) lis;
    if(list->n==1){
        int size=getSizeD(list->lis);
        return size;
    }else{
        int size=getSizeS(list->lis);
        return size;
    }
}

int getIniSize(List lis){
    structList* list=(structList*) lis;
    return list->size;
}

int getCounter(List lis){
    structList* list=(structList*) lis;
    if(list->n==1){
        int counter=getCounterD(list->lis);
        return counter;
    }else{
        int counter=getCounterS(list->lis);
        return counter;
    }
    
}

void addCounter(List lis, int plus){
    structList* list=(structList*) lis;
    if(list->n==1){
        addCounterD(list->lis, plus);
    }else{
        addCounterS(list->lis, plus);
    }
}

int getType(List lis){
    structList* list=(structList*) lis;
    return list->n;
}

int getSofar(List lis){
    structList* list=(structList*) lis;
    if(list->n==1){
        return getSizeD(list->lis);
    }else{
        return getSizeS(list->lis);
    }
}

Node getPrev(List lis, Node node){
    structList* list=(structList*) lis;
    if(list->n==1){
        return getPrevD(node);
    }else{
        return getPrevS(lis,node);
    }
}