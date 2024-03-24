#include <stdio.h> 

typedef struct { // fechado em d1 e aberto em d2
   
    int x;
    int y;
    int x2;
    int y2;
    int quantidade;
    int coordenada1;
    int coordenada2;
    int a;
    int b;

}tPonto ;

int EixoX (tPonto ponto){

    if (ponto.x>0){
        //quadrante 1 ou 4
        return 1;
    }
    else if (ponto.x<0){
        //quadrante 2 ou 3
        return 2;
    }
    else {
        return 0;  //qudrante 0
    }

        //qudrante 0
}
int EixoY (tPonto ponto){
    if (ponto.y>0){
        return 1;//quadrante 1 ou 2
    }
    else if (ponto.y<0){
        return 2;//quadrante 3 ou 4
    }
    else {
        return 0;//quadrante 0
    }
}
int QuadranteInicial (tPonto ponto){


    ponto.x=EixoX(ponto);

    ponto.y=EixoY(ponto);

    if(ponto.x==1 && ponto.y==1){
        return 1;
    }
    else if (ponto.x==1 && ponto.y==2){
        return 4;
    }
    else if (ponto.x==2 && ponto.y==1){
        return 2;
    }
    else if (ponto.x==2 && ponto.y==2){
        return 3;
    }
    else if ((ponto.x==0) || (ponto.y==0)){
        return 0;
    }
}

int QuadranteOposto(tPonto ponto){
    ponto.x=ponto.x*-1;
    ponto.y=ponto.y*-1;

    ponto.x=EixoX(ponto);
    ponto.y=EixoY(ponto);
    if(ponto.x==1 && ponto.y==1){
        return 1;
    }
    else if (ponto.x==1 && ponto.y==2){
        return 4;
    }
    else if (ponto.x==2 && ponto.y==1){
        return 2;
    }
    else if (ponto.x==2 && ponto.y==2){
        return 3;
    }
    else if ((ponto.x==0) || (ponto.y==0)){
        return 0;
    }

}
void Imprime (tPonto ponto){

    printf("(%d,%d) %d (%d,%d) %d\n",ponto.a,ponto.b,ponto.coordenada1,
    ponto.a*-1,ponto.b*-1,ponto.coordenada2);



}

int main () {
    tPonto ponto;
    int cont=0;
    scanf("%d",&ponto.quantidade);
    while (ponto.quantidade>cont){
    scanf("%d %d",&ponto.x,&ponto.y);
    ponto.a=ponto.x;
    ponto.b=ponto.y;
    
    ponto.coordenada1 = QuadranteInicial(ponto); //fornece o quadrante de x e y;
    ponto.coordenada2 =QuadranteOposto(ponto); //fornece o quadrante do oposto de x e y;
    Imprime(ponto);

cont ++;
    }
     return 0;
}



