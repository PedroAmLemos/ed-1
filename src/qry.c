#include "qry.h"
#include "wrapper.h"
#include "rect.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int intInter(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2){
    return x1>=x2&&y1>=y2&&x1+w1<=x2+w2&&y1+h1<=y2+h2;
}
float larger(float a, float b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
float smaller(float a, float b){
    if(a<b){
        return a;
    }else{
        return b;
    }
} 
int inter(Rect r1, Rect r2){
    float x,y,w,h;
    x=smaller(getX(r1),getX(r2));
    w=larger(getX(r1)+getW(r1),getX(r2)+getW(r2))-x;
    y=smaller(getY(r1),getY(r2));
    h=larger(getY(r1)+getH(r1),getY(r2)+getH(r2))-y;    
    if(w<=getW(r1)+getW(r2)&&h<=getH(r1)+getH(r2)){
        return 1;
    }else{
        return 0;
    }

}
void tp(List lis, FILE* txt){
    char* colors[10]={"aqua", "deepskyblue", "deeppink", "lightcoral", "indigo", "olive", "crimson", "blueviolet","mediumblue","orange"};
    Node node;
    Node next;
    Rect nodeR;
    Rect nextR;
    int inte, color=0,counter=0;
    for(node=getFirst(lis);node!=NULL;node=getNext(lis,node)){
        nodeR=getInfo(lis,node);
        counter++;
        for(next=getNext(lis,node);next!=NULL;next=getNext(lis,next)){
            nextR=getInfo(lis,next);
            inte=inter(nodeR,nextR);
            if(inte==1){
                if(color==9){
                    color=0;
                }
                changeFill(nodeR,colors[color]);
                changeFill(nextR,colors[color]);
                fprintf(txt,"%s %s\n",getId(nodeR),getId(nextR));
                color++;
                counter++;
            }
        }
    }
    addCounter(lis,counter);
}
void tpr(List lis, float x, float y, float w, float h, FILE* txt){
    Rect area=createRect("null","null","null",x,y,w,h);
    List aux=create(getType(lis),getSize(lis));
    int a;
    Rect interR;
    float x2,y2,w2,h2;
    for(Node node=getFirst(lis);node!=NULL;node=getNext(lis,node)){
        interR=getInfo(lis,node);
        x2=getX(interR);
        y2=getY(interR);
        w2=getW(interR);
        h2=getW(interR);
        a=intInter(x2,y2,w2,h2,x,y,w,h);
        if(a==1){
            insert(getInfo(lis,node),aux);
        }
    }
    tp(aux,txt);
    int counter=getCounter(lis);
    addCounter(lis,counter);
    removeList(aux,0);
    free(area);
}
void dpi(List lis, float x, float y, FILE* txt){
    int counter=0,a;
    float x2,y2,w2,h2;
    Rect extR;
    Node node=getFirst(lis);  
    Node aux;  
    while(node!=NULL){
        counter++;
        extR=getInfo(lis,node);
        x2=getX(extR);
        y2=getY(extR);
        w2=getW(extR);
        h2=getW(extR);
        a=intInter(x,y,0,0,x2,y2,w2,h2);
        aux=getNext(lis,node);
        if(a==1){   
            fprintf(txt,"%s\n",getId(extR));
            if(getType(lis)==0&&aux!=NULL){
                aux=node;
            }
            removeNode(lis,node);
        }
        node=aux;
    }
    addCounter(lis,counter);
}
void dr(List lis, char* id, FILE* txt){
    Rect area,extR;
    Node node;
    float x2,y2,w2,h2;
    int a,counter=0;
    for(node=getFirst(lis);node!=NULL;node=getNext(lis,node)){
        area=getInfo(lis,node);        
        if(((strcmp(getId(area),id))==0)){  
            break;
        }
    }
    if(node==NULL){
        printf("Nao foi encontrado um retangulo com o id informado na funcao dr");
        return;
    }
    node=getFirst(lis);  
    Node aux;  
    while(node!=NULL){
        counter++;
        extR=getInfo(lis,node);
        x2=getX(extR);
        y2=getY(extR);
        w2=getW(extR);
        h2=getW(extR);
        a=intInter(x2,y2,w2,h2,getX(area),getY(area),getW(area),getH(area));
        aux=getNext(lis,node);
        if(a==1&&(strcmp(getId(area),getId(getInfo(lis,node))))!=0){   
            fprintf(txt,"%s\n",getId(extR));
            if(getType(lis)==0&&aux!=NULL){
                aux=node;
            }
            removeNode(lis,node);
        }
        node=aux;
    }
    addCounter(lis,counter);

}
void bbi(List lis, float x, float y, FILE* txt, FILE* svg, List extraFig){
    float mx=100000,xw=0,my=100000,yh=0;    
    char aux[40];
    int counter=0;
    for(Node node=getFirst(lis);node!=NULL;node=getNext(lis,node)){
        if(intInter(x,y,0,0,getX(getInfo(lis,node)),getY(getInfo(lis,node)),getW(getInfo(lis,node)),getH(getInfo(lis,node)))==1){
            if(getX(getInfo(lis,node))<mx){
                mx=getX(getInfo(lis,node));
            }
            if(getY(getInfo(lis,node))<my){
                my=getY(getInfo(lis,node));
            }
            if((getX(getInfo(lis,node))+getW(getInfo(lis,node)))>xw){
                xw=getX(getInfo(lis,node))+getW(getInfo(lis,node));
            }
            if((getY(getInfo(lis,node))+getH(getInfo(lis,node)))>yh){
                yh=getY(getInfo(lis,node))+getH(getInfo(lis,node));
            }
            fprintf(txt,"%s %s %s\n",getId(getInfo(lis,node)),getFill(getInfo(lis,node)),getShape(getInfo(lis,node)));
            strcpy(aux,getShape(getInfo(lis,node)));
            strcpy(getShape(getInfo(lis,node)),getFill(getInfo(lis,node)));
            strcpy(getFill(getInfo(lis,node)),aux);
        }
        counter++;
    }
    addCounter(lis,counter);
    int *fig1, *fig2;
    fig1=malloc(sizeof(int));
    fig2=malloc(sizeof(int));
    *fig1=getSofar(extraFig);
    insert(fig1,extraFig);
    *fig2=getSofar(extraFig);
    insert(fig2,extraFig);
    fprintf(svg,"\t<circle cx=\"%f\" cy=\"%f\" r=\"1\" stroke=\"aqua\" stroke-width=\"0.2\" fill=\"pink\" fill-widht=\"1\" id=\"%d\"/>\n",x,y,*fig1);
    fprintf(svg,"\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"white\" stroke=\"red\" fill-opacity=\'0\' stroke-dasharray=\"5.5\" d=\"M5 20 l215 0\" id=\"%d\"/>\n",mx,my,xw-mx,yh-my,*fig2);
}
void bbid(List lis, char* id, FILE* txt, FILE* svg, List figExtra){
    Rect area;
    Node node;
    float mx=10000,my=10000,xw=0,yh=0;
    int counter=0;
    char aux[40];
    for(node=getFirst(lis);node!=NULL;node=getNext(lis,node)){
        area=getInfo(lis,node);        
        if(((strcmp(getId(area),id))==0)){  
            break;
        }
    }
    if(node==NULL){
        printf("\nNao foi encontrado um retangulo com o id informado na funcao bbid\n");
        return;
    }
    for(Node node=getFirst(lis);node!=NULL;node=getNext(lis,node)){
        if(intInter(getX(getInfo(lis,node)),getY(getInfo(lis,node)),getW(getInfo(lis,node)),getH(getInfo(lis,node)),getX(area),getY(area),getW(area),getH(area))==1&&(strcmp(getId(getInfo(lis,node)),getId(area)))!=0){  
            if(getX(getInfo(lis,node))<mx){
                mx=getX(getInfo(lis,node));
            }
            if(getY(getInfo(lis,node))<my){
                my=getY(getInfo(lis,node));
            }
            if((getX(getInfo(lis,node))+getW(getInfo(lis,node)))>xw){
                xw=getX(getInfo(lis,node))+getW(getInfo(lis,node));
            }
            if((getY(getInfo(lis,node))+getH(getInfo(lis,node)))>yh){
                yh=getY(getInfo(lis,node))+getH(getInfo(lis,node));
            }
            fprintf(txt,"%s %s %s\n",getId(getInfo(lis,node)),getFill(getInfo(lis,node)),getShape(getInfo(lis,node)));
            strcpy(aux,getShape(getInfo(lis,node)));
            strcpy(getShape(getInfo(lis,node)),getFill(getInfo(lis,node)));
            strcpy(getFill(getInfo(lis,node)),aux);
        }
        counter++;
    }
    addCounter(lis,counter);
    int *fig1;
    fig1=malloc(sizeof(int));
    *fig1=getSofar(figExtra);
    insert(fig1,figExtra);
    fprintf(svg,"\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"white\" stroke=\"red\" fill-opacity=\'0\' stroke-dasharray=\"5,5\" d=\"M5 20 l215 0\"  id=\"%d\" />\n",mx,my,xw-mx,yh-my,*fig1);
}
void iid(List lis, char* id, int k, FILE* txt){
    Node node, aux;
    int cont=0, counter=0;
    for(node=getFirst(lis);node!=NULL&&strcmp(getId(getInfo(lis,node)),id)!=0;node=getNext(lis,node)){  
        counter++;
    }   
    if(node==NULL){
        printf("\nNao foi encontrado um retangulo com o id informado na funcao iid\n");
        return;
    }
    if(k>=0){
        for(aux=node,cont=0;aux!=NULL&&cont!=k+1;aux=getNext(lis,aux),cont++){
            counter++;
            fprintf(txt,"%s %f %f %f %f %s %s\n",getId(getInfo(lis,aux)),getX(getInfo(lis,aux)),getY(getInfo(lis,aux)),getW(getInfo(lis,aux)),getH(getInfo(lis,aux)),getShape(getInfo(lis,aux)),getFill(getInfo(lis,aux)));    
        }
    }else{
        k=k*(-1);
        for(aux=node,cont=0;aux!=NULL&&cont!=k+1;aux=getPrev(lis,aux),cont++){
            counter++;
            fprintf(txt,"%s %f %f %f %f %s %s\n",getId(getInfo(lis,aux)),getX(getInfo(lis,aux)),getY(getInfo(lis,aux)),getW(getInfo(lis,aux)),getH(getInfo(lis,aux)),getShape(getInfo(lis,aux)),getFill(getInfo(lis,aux)));    
        }

    }
    addCounter(lis,counter);
}
void diid(List lis, char* id, int k, FILE* txt){
    Node node, aux, auxaux;
    int cont=0, counter=0;
    for(node=getFirst(lis);node!=NULL&&strcmp(getId(getInfo(lis,node)),id)!=0;node=getNext(lis,node)){  
        counter++;
    }   
    if(node==NULL){
        printf("\nNao foi encontrado um retangulo com o id informado na funcao diid\n");
        return;
    }
    aux=node;
    if(k>=0){
        while(aux!=NULL&&cont!=k+1){
            counter++;
            fprintf(txt,"%s %f %f %f %f %s %s\n",getId(getInfo(lis,aux)),getX(getInfo(lis,aux)),getY(getInfo(lis,aux)),getW(getInfo(lis,aux)),getH(getInfo(lis,aux)),getShape(getInfo(lis,aux)),getFill(getInfo(lis,aux)));    
            auxaux=getNext(lis,aux);
            if(cont!=0){
                if(getType(lis)==0&&aux!=NULL){
                    auxaux=aux;
                }
                removeNode(lis,aux);
            }    
            cont++;
            aux=auxaux;
        }
    }else{
        k=k*(-1);
        while(aux!=NULL&&cont!=k+1){
            counter++;
            fprintf(txt,"%s %f %f %f %f %s %s\n",getId(getInfo(lis,aux)),getX(getInfo(lis,aux)),getY(getInfo(lis,aux)),getW(getInfo(lis,aux)),getH(getInfo(lis,aux)),getShape(getInfo(lis,aux)),getFill(getInfo(lis,aux)));    
            auxaux=getPrev(lis,aux);
            if(cont!=0){
                if(getType(lis)==0&&aux!=NULL){
                    auxaux=aux;
                }
                removeNode(lis,aux);
            }  
            cont++;  
            aux=auxaux;
        }

    }
    addCounter(lis,counter);
}
void qryTreat(FILE* fQry, List lis, FILE* fQryTxt, FILE* fQrySvg, List extraFig){
    float x,y,w,h;    
    int k;
    char id[40];
    char aux[40];
    while(fscanf(fQry, "%s", aux)!=EOF){
        if((strcmp(aux,"tp"))==0){
            fprintf(fQryTxt,"\ntp\n");
            tp(lis, fQryTxt);
        }
        else if((strcmp(aux,"tpr"))==0){
            fscanf(fQry,"%f %f %f %f", &x, &y, &w, &h);
            fprintf(fQryTxt,"\ntpr\n");
            tpr(lis,x,y,w,h,fQryTxt);
        }
        else if((strcmp(aux,"dpi"))==0){
            fscanf(fQry,"%f %f", &x, &y);
            fprintf(fQryTxt,"\ndpi\n");
            dpi(lis,x,y,fQryTxt);
        }
        else if((strcmp(aux,"dr"))==0){
            fscanf(fQry,"%s",id);
            fprintf(fQryTxt,"\ndr\n");
            dr(lis, id, fQryTxt);
        }
        else if((strcmp(aux,"bbi"))==0){
            fscanf(fQry,"%f %f", &x,&y);
            fprintf(fQryTxt,"\nbbi\n");
            bbi(lis,x,y,fQryTxt,fQrySvg,extraFig);
        }
        else if((strcmp(aux,"bbid"))==0){
            fscanf(fQry,"%s",id);
            fprintf(fQryTxt,"\nbbid\n");
            bbid(lis, id,fQryTxt,fQrySvg,extraFig);
        }
        else if((strcmp(aux,"iid"))==0){
            fscanf(fQry,"%s %d",id,&k);
            fprintf(fQryTxt,"\niid\n");
            iid(lis,id,k,fQryTxt);
        }
        else if((strcmp(aux,"diid"))==0){
            fscanf(fQry,"%s %d",id,&k);
            fprintf(fQryTxt,"\ndiid\n");
            diid(lis,id,k, fQryTxt);
        }

    }

}