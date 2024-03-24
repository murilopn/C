#include <stdio.h>

int transformaPrimo (int n){
    int cont =2;
    if (n==-1){
        return -2;
}
    else if (n<0){
    n = n*(-1);
    while (cont<n){

        if (!(n%cont)){
            n++;
            cont=2;
            continue;
        }
        cont++;
    }
        if (cont==n){
            n=n*(-1);
            return n;
        }}
    else {
        while (cont<n){

        if (!(n%cont)){
            n++;
            cont=2;
            continue;
        }
        cont++;
    }
        if (cont==n){;
            return n;
    }

}}

int verificaPrimo(int n){//analise o numero parâmetro
    int cont=2;
   
    while (cont<n){
        if (!(n%cont)){
            break;
        }
        cont++;
    }
    if (cont==n){
        return 1;
    }
    else {
        return 0;
    }
}

int main () {
    int l=0,c=0,matriz=0,analise=0,contl=0,contc=0,num=0,validacao=1;
   scanf ("%d %d",&l,&c);
   while (l>contl){
    contl++;
    contc=0;
        while (contc<c){
            scanf("%d",&num);
            if (num>32000 || num<-32000){
                break;
            }
           if(validacao){
            printf("	");
            validacao=0;
           } 
        analise= verificaPrimo(num);
        if (analise){
            matriz=num;
        }//quando é primo
        else {
            matriz= transformaPrimo (num); //matriz recebe o próximo primo
            if (matriz>32000 || matriz<-32000){
                matriz=num;
            }
        }
        printf("%d ",matriz);
        contc++;
        }
          printf("\n");
          validacao=1;
        }
    return 0;
}
