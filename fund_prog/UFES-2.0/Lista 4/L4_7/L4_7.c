#include <stdio.h>
typedef struct{
    int pi1;
    int pi2;
    int pf1;
    int pf2;
    int qntd;
    int positivoY;
    int negativoY;
    int positivoX;
    int negativoX;
}tReta;

tReta InicializaReta(){
    tReta reta;

    scanf("%d %d %d %d",&reta.pi1,&reta.pi2,&reta.pf1,&reta.pf2);
    
    return reta;
}
int ValoresPositivosDeY(tReta analise){
    if((analise.pi2>0) && (analise.pf2>0)){
        return 1;
    }
    else {
        return 0;
    }
}

int ValoresNegativosDeY(tReta analise){
    if((analise.pi2<0) && (analise.pf2<0)){
        return 1;
    }
    else {
        return 0;
    }
}
int ValoresPositivosDeX(tReta analise){
    if((analise.pi1>0) && (analise.pf1>0)){
        return 1;
    }
    else {
        return 0;
    }
}

int ValoresNegativosDeX(tReta analise){
    if((analise.pi1<0) && (analise.pf1<0)){
        return 1;
    }
    else {
        return 0;
    }
}
int main (){
   int dist=0,cont=0;
   tReta analiseR;
  
    scanf("%d",&analiseR.qntd);
    dist=analiseR.qntd;
   
   while(cont<dist){
    analiseR=InicializaReta();

       analiseR.positivoY= ValoresPositivosDeY(analiseR);
       analiseR.negativoY= ValoresNegativosDeY(analiseR);
       analiseR.positivoX=ValoresPositivosDeX(analiseR);
       analiseR.negativoX=ValoresNegativosDeX(analiseR);

    if ((analiseR.positivoY) && (analiseR.positivoX)){
            printf("MESMO\n");
    }  
    else if ((analiseR.positivoY) && (analiseR.negativoX)){
            printf("MESMO\n");
    }
    else if ((analiseR.negativoY) && (analiseR.positivoX)){
            printf("MESMO\n");
    }
    else if ((analiseR.negativoY) && (analiseR.negativoX)){
            printf("MESMO\n");
    }
    else{
        printf("DIFERENTE\n");
    }
   cont++;
   }
    return 0;
}
