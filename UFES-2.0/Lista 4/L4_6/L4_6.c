#include <stdio.h>
#include <math.h>

typedef struct { // fechado em d1 e aberto em d2
    int qntd;
   int y;
   int x;
   float dist;
   float disty;
   float distx;
}tPonto ;

typedef struct{
    int pi1;
    int pi2;
    int pf1;
    int pf2;
}tReta;

tPonto InicializaPonto (){
    tPonto ponto;
    
   
    scanf("%d %d",&ponto.x,&ponto.y);

    return ponto;
}
tReta InicializaReta(){
    tReta reta;

    scanf("%d %d %d %d",&reta.pi1,&reta.pi2,&reta.pf1,&reta.pf2);
    
    return reta;
}

float DistanciaPontoRetaInicial (tPonto ponto,tReta reta){

    ponto.distx = ponto.x-reta.pi1;
    ponto.disty = ponto.y-reta.pi2;
    ponto.dist = pow(ponto.distx,2) + pow(ponto.disty,2);
    ponto.dist=sqrt(ponto.dist);

return ponto.dist;
}

float DistanciaPontoRetaFinal (tPonto ponto, tReta reta){

    ponto.distx = ponto.x-reta.pf1;
    ponto.disty = ponto.y-reta.pf2;
    ponto.dist = pow(ponto.distx,2) + pow(ponto.disty,2);
    ponto.dist=sqrt(ponto.dist);

return ponto.dist;

}

int main (){
    tPonto analiseP;
   tReta analiseR;
   float distancia1=0,distancia2=0;
   int cont=0,dist=0;
    scanf("%d",&analiseP.qntd);
    dist=analiseP.qntd;

   while(cont<dist){

   analiseP=InicializaPonto();
   
   analiseR=InicializaReta();
    distancia1=DistanciaPontoRetaInicial(analiseP,analiseR);
    distancia2=DistanciaPontoRetaFinal(analiseP,analiseR);

if (distancia1>distancia2){
    printf("FIM\n");
}
else if (distancia2>distancia1){
    printf("INICIO\n");
}
else {
    printf("EQUIDISTANTE\n");
}
cont++;
}
   

    return 0;
}
