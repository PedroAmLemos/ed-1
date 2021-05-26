#include "leitura.h"
#include "wrapper.h"
#include "svg.h"
#include "geo.h"
#include "report.h"
#include "qry.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *concatPathFile(char *path, char *fileName){
    char *retorno=NULL;
    int tamanho_path=strlen(path), tamanho_nome=strlen(fileName);
    if(path[tamanho_path-1]=='/'){
        retorno = malloc(sizeof(char)*(tamanho_path+tamanho_nome)+1);                        ;
        strcpy(retorno, path);
        strcat(retorno, fileName);
        return retorno;
    }else{
        retorno=malloc(sizeof(char)*(tamanho_nome+tamanho_path)+2);
        strcpy(retorno, path);
        retorno[tamanho_path]='/';
        retorno[tamanho_path+1]='\0';
        strcat(retorno, fileName);
        return retorno;
    }
}
char *getFileName(char path[]){
    char *aux = strrchr(path,'/');
    if(aux == NULL){
        return strtok(path,".");
    }
	return strtok(&aux[1],".");
}
void read(char *path, char *geo_name, char *qry_name, char *out_path, int ini_col, int cont_col, char *fina_col, int lisType, int fin_col,  char* col_title){
    char *geoPath=NULL;
    char *svgPathName=NULL;
    char *qryTxt=NULL;
    char *qrySvg=NULL; 
    char *svgName=NULL;
    char *qryPath=NULL;
    char *qryOutPath=NULL;
    int counter=0; 
    //--------------------------pegando o path do geo e do qry
    if(qry_name==NULL){
        if(path!=NULL){
            geoPath=concatPathFile(path, geo_name);
        }else{
            geoPath=geo_name;
        }
    }else{
        if(path!=NULL){
            geoPath=concatPathFile(path, geo_name);
            qryPath=concatPathFile(path, qry_name);
        }else{
            geoPath=geo_name;
            qryPath=qry_name;
        }
    }
    //--------------------------preechendo a lista
    FILE *fGeo=fopen(geoPath, "r");
    List lis=geoTreat(fGeo, lisType);
    //--------------------------pegando o outpath
    svgName=getFileName(geo_name);
    strcat(svgName, ".svg");
    svgPathName=concatPathFile(out_path,svgName);
    //--------------------------preenchendo o svg com os retangulos do .geo e fechando o svg
    FILE *fSvgGeo=createTag(svgPathName);
    printRects(fSvgGeo, lis, NULL);
    closeTag(fSvgGeo);
    int size=getIniSize(lis);
    //--------------------------tratando do qry
    if(qryPath!=NULL){
        FILE *fQry=fopen(qryPath, "r");
        //--------------------------pegando os paths para criar o svg e o txt
        qryOutPath=concatPathFile(out_path, getFileName(geo_name));
		strcat(qryOutPath,"-");
		strcat(qryOutPath, getFileName(qry_name));
        qrySvg=malloc(sizeof(char)*(strlen(qryOutPath)+5));
        qryTxt=malloc(sizeof(char)*(strlen(qryOutPath)+5));
        strcpy(qrySvg, qryOutPath);
        strcpy(qryTxt, qryOutPath);
        strcat(qrySvg, ".svg");
        strcat(qryTxt, ".txt");
        //-------------------------- comandos do qry e preenchimento do txt e criacao do svg do qry
        FILE* fQrySvg=createTag(qrySvg);
        FILE* fQryTxt=fopen(qryTxt,"w");
        List extraFig=create(getType(lis),getSize(lis));
        qryTreat(fQry,lis,fQryTxt,fQrySvg,extraFig);

        //-------------------------- preenchendo o qry svg
        printRects(fQrySvg,lis,extraFig);
        closeTag(fQrySvg);
        
        //-------------------------- dando close e free em tudo
        removeList(extraFig,1);
        fclose(fQrySvg);
        fclose(fQryTxt);
        fclose(fQry);
        free(qryOutPath);
        free(qrySvg);
        free(qryTxt);
        free(qryPath);
    }
    
    //--------------------------dando free nas coisas
    counter=removeList(lis, 1);
    if(ini_col==1){
        beginCol(size,counter,out_path);
    }
    else if(cont_col==1){
        continueCol(size,counter,out_path);
    }
    else if(fin_col==1){
        finCol(size,counter,out_path,fina_col,col_title);
    }
    fclose(fSvgGeo);
    fclose(fGeo);
    free(svgPathName);
    if(path!=NULL)
        free(geoPath);
}
