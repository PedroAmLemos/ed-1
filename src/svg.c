#include "svg.h"
#include "wrapper.h"
#include "rect.h"
#include <stdio.h>
#include <stdlib.h>
FILE* createTag(char* svgPathName){
    FILE* arqSvg;
    arqSvg=fopen(svgPathName,"w");
    fprintf(arqSvg,"<svg>\n");
    return arqSvg;
}

void printRects(FILE* svgArq, List lis, List extraFig){
    Rect rectan;
    Node node;
    for(node=getFirst(lis); node!=NULL; node=getNext(lis,node)){
        rectan=getInfo(lis, node);
        printSvg(svgArq, rectan);
    }
    if(extraFig!=NULL){
        for(Node node=getFirst(extraFig); node != NULL; node = getNext(extraFig,node)){
                fprintf(svgArq,"\t<use xlink:href=\"#%d\"/>",*(int*)getInfo(extraFig,node));
        }    
    }
}

void closeTag(FILE* svgArq){
    fprintf(svgArq,"</svg>");
}
