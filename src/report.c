#include "report.h"
#include "leitura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beginCol(int size, int counter, char* outPath){
    char *txtPath=NULL;
    txtPath=malloc((strlen(outPath)+1)*sizeof(char));
    char *txtName="temp.txt";
    char *pathName=NULL;
    strcpy(txtPath,outPath);
    pathName=concatPathFile(txtPath,txtName);
    FILE *temp=fopen(pathName,"w");
    fprintf(temp,"%d %d\n",size,counter);
    fclose(temp);
    free(txtPath);
    free(pathName);
}
void continueCol(int size, int counter, char *outPath){
    char *txtPath=NULL;
    txtPath=malloc((strlen(outPath)+1)*sizeof(char));
    char *txtName="temp.txt";
    char *pathName=NULL;
    strcpy(txtPath,outPath);
    pathName=concatPathFile(txtPath,txtName);
    FILE *temp=fopen(pathName,"a");
    fprintf(temp,"%d %d\n",size,counter);
    fclose(temp);
    free(txtPath);
    free(pathName);
}
void finCol(int size, int counter, char *outPath, char *nameArq, char* arqTitle){
    int aux=size;
    int auxaux=counter;
    char *txtPath=NULL;
    txtPath=malloc((strlen(outPath)+1)*sizeof(char));
    char txtName[]="temp.txt";
    char *pathName=NULL;
    strcpy(txtPath,outPath);
    pathName=concatPathFile(txtPath,txtName);
    FILE *temp=fopen(pathName,"r");
    int counterSvg,sizeSvg;
    char *svgColPathNameAux=concatPathFile(outPath,nameArq);
    char *svgColPathName=malloc((strlen(svgColPathNameAux)+5)*sizeof(char));
    sprintf(svgColPathName,"%s.svg",svgColPathNameAux);
    FILE* svgCol=fopen(svgColPathName,"w");
    fprintf(svgCol,"<svg>\n");
    fprintf(svgCol,"\t<text x=\"100\" y=\"50\">%s</text>\n",arqTitle);
    fprintf(svgCol,"\t<circle cx=\"%d\" cy=\"%d\" r=\"1\" stroke=\"black\" fill=\"aqua\"/>\n",counter,size);
    fprintf(svgCol,"\t<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" stroke=\"pink\" fill=\"none\" stroke-dasharray=\"5.5\"/>\n",counter,size);
    while(!feof(temp)){
        fscanf(temp,"%d %d\n",&sizeSvg, &counterSvg);
        fprintf(svgCol,"\t<circle cx=\"%d\" cy=\"%d\" stroke=\"black\" r=\"1\" fill=\"aqua\"/>\n",counterSvg,sizeSvg);
        fprintf(svgCol,"\t<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" stroke=\"pink\" fill=\"none\" stroke-dasharray=\"5.5\"/>\n",counterSvg,sizeSvg);
        if(sizeSvg>aux){
            aux=sizeSvg;
        }
        if(counterSvg>auxaux){
            auxaux=counterSvg;
        }
    }
    fprintf(svgCol,"\t<line x1=\"0\" y1=\"0\" x2=\"%d\" y2=\"0\" style=\"stroke:black\"/>\n",auxaux);
    fprintf(svgCol,"\t<line x1=\"0\" y1=\"0\" x2=\"0\" y2=\"%d\" style=\"stroke:black\"/>\n",aux);      
    fprintf(svgCol,"</svg>");
    fclose(svgCol);
    fclose(temp);
    remove(pathName);
    free(svgColPathName);
    free(svgColPathNameAux);
    free(txtPath);
    free(pathName);

}

