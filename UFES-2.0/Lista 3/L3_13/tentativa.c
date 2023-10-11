#include <stdio.h>

int CalculaValorPalavra(int num){

     if (num>=97 && num<=122){
        num=num-96;
    }
    else {
        num=num-38;
    }
    return num;
}
   
int EhPrimo(int n){
    int cont=2;
    while (cont<n){

        if(!(n%cont)){
            return 1;
            break;
        }
        cont++;
    }
        if(n==cont){
            printf("E primo\n");
        }
   
 }

 int ProximoPrimo(int n){
    int cont=2;
    while (cont<n){

        if(!(n%cont)){
            cont=2;
            n++;
        }
        cont++;
    }
        if(n==cont){
            printf("Nao e primo %d\n",n);
        }
   
 }

int main (){
    char palavra=0,naoprimo=0;
    int num=0,valortotalpalavra=0;
     while(scanf("%c",&palavra)==1){
    
    if (palavra=='\n'){
        break;
    }
        
    num = (int)palavra;

    num = CalculaValorPalavra(num);
        valortotalpalavra+=num;
        
        
        naoprimo=EhPrimo(valortotalpalavra);

        if(naoprimo){
            ProximoPrimo(valortotalpalavra);
        }
         valortotalpalavra=0;
     }

    return 0;
}