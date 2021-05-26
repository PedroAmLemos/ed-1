#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"
int main(int argc, char *argv[]){
    int i=1;
    char *entryPath=NULL; //bed -e path
    int finCol=0; //indica a finalizacao da coleta
    char *Geo=NULL; //bed -f arq.geo
    char *outPath=NULL; //bsd -o path
    char *Qry=NULL; //bed -q arqcons.qry 
    int inCol=0; //iniciar da coleta -ib    
    int ConCol=0; //continuar coleta -cb 
    char *FinCol=NULL; //finalizar coleta -fb arq
    char *ColTi=NULL; //coleta o titulo do relatorio 
    int LisDu=1; //lista duplamente encadeada -ldd (lista duplamente encadeada, nao altera em nada, pois o default eh dupla) -lse altera para lista simplesmente encadeada
    while(i<argc){ //recebimento dos parametros da main
        if(strcmp("-e", argv[i])==0){
            i++;
            if(argv[i] == NULL){
                printf("Erro - Sem parametros em -e");
                exit(1);
            }
            entryPath=malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(entryPath, argv[i]);
        }
        else if(strcmp("-f", argv[i])==0){
            i++;
            if(argv[i] == NULL){
                printf("Erro - Sem parametros em -f");
                exit(1);
            }
            Geo=malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(Geo, argv[i]);
        }
        else if(strcmp("-o", argv[i])==0){
            i++;
            if(argv[i] == NULL){
                printf("Erro - Sem parametros em -o");
                exit(1);
            }
            outPath=malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(outPath, argv[i]);
        }
        else if(strcmp("-q", argv[i])==0){
            i++;
            if(argv[i] == NULL){
                printf("Erro - Sem parametros em -q");
                exit(1);
            }
            Qry=malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(Qry, argv[i]);
        }
        else if(strcmp("-ib", argv[i])==0){
            inCol=1;
        }
        else if(strcmp("-cb", argv[i])==0){
            ConCol=1;
        }
        else if(strcmp("-fb", argv[i])==0){
            i++;
            finCol=1;
            if(argv[i]==NULL){
                printf("Erro - Sem parametros em -fb");
                exit(1);
            }
            FinCol=malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(FinCol, argv[i]);
            if(argv[i+1]==NULL){
                printf("Erro - Sem parametros em -fb");
                exit(1);
            }
            ColTi=malloc((strlen(argv[i+1])+1)*sizeof(char));
            strcpy(ColTi, argv[i+1]);
        }
        else if(strcmp("-ldd", argv[i])==0){
        }
        else if(strcmp("-lse", argv[i])==0){
            LisDu=0;
        }             
        i++;              
    }
    read(entryPath, Geo, Qry, outPath, inCol, ConCol, FinCol, LisDu, finCol, ColTi);
    if(entryPath!=NULL)
        free(entryPath);
    if(Qry!=NULL&&entryPath!=NULL)
        free(Qry);
    if(FinCol!=NULL)
        free(FinCol);
    if(ColTi!=NULL)
        free(ColTi);
    free(Geo);
    free(outPath);
    return 0;
}
