#include "geo.h"
#include "rect.h"
#include "wrapper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
List geoTreat(FILE *fGeo, int lisType){ 
    char id[40]="default", fill[40]="blue", shape[40]="blue", aux[5];
    int size;
    float x,y,w,h;
    fscanf(fGeo,"%s", aux);  
    if((strcmp(aux,"nx"))==0){
        fscanf(fGeo,"%d", &size);
    }
    List list=create(lisType, size);
    while(fscanf(fGeo, "%s", aux)!=EOF){
        if((strcmp(aux, "cc"))==0){
            fscanf(fGeo,"%s", shape);
        }
        if((strcmp(aux,"cp"))==0){
            fscanf(fGeo,"%s", fill);
        }
        if((strcmp(aux,"r"))==0){
            fscanf(fGeo,"%s %f %f %f %f",id,&x,&y,&w,&h);
            Rect rectan=createRect(id,fill,shape,x,y,w,h);
            insert(rectan, list);
        }
    }
    return list;
}   
