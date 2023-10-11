#include <stdio.h> 
#include<math.h>
typedef struct { // fechado em d1 e aberto em d2
   
   int qntd;
   int y;
   int x;
   int x2;
   int y2;
   float dist;
   float disty;
   float distx;
   int cont;
   float analise;
}tPonto ;

float CalculaDistanciaEntrePontos(tPonto ponto){
  
  ponto.y=(float)ponto.y;
  ponto.x=(float)ponto.x;
    
    if (ponto.cont==0){
      printf("-\n");
        return -1;
    }
    else{
    ponto.distx = ponto.x-ponto.x2;
    ponto.disty = ponto.y-ponto.y2;
    ponto.dist = pow(ponto.distx,2) + pow(ponto.disty,2);
    ponto.dist=sqrt(ponto.dist);
      return ponto.dist;
    }  
  

}


int main () {
  tPonto ponto = {0,0,0,0,0,0,0,0};
    scanf("%d",&ponto.qntd);
    while (ponto.cont<ponto.qntd){
    scanf("%d %d",&ponto.x2,&ponto.y2);
   ponto.analise = CalculaDistanciaEntrePontos(ponto);
    ponto.x=ponto.x2;
    ponto.y=ponto.y2;
    if (ponto.analise==-1){
      ponto.cont++;
      continue;
    }
    else {
      printf("%.2f\n",ponto.analise);
    }


  ponto.cont++;
  }
     return 0;
}



