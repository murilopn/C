#include <stdio.h>

int CalculaValorPalavra(char palavra){
    int soma=0,a=0;


     if ((palavra>='a') && (palavra<='z')){
        palavra=palavra-96;
         soma+=palavra;
    }
    else if ((palavra>='A') && (palavra<='Z')){
        palavra=palavra-38;
         soma+=palavra;
    }
    
    return soma;
}

int EhPrimo(int n){
    int cont=2;
    while (cont<n){

        if(!(n%cont)){
            return 0; // mudei esse caso para retornar 0, antes tava 1
            break;
        }
        cont++;
    }
        if(n==cont){
            printf("E primo\n");
            return 1;
        }
        else if (n==1){
            return 0;
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
        else if (n==1){
            printf("Nao e primo 2\n");
        }
 }
 

int main (){
    char palavra=0;
    int valorpalavra=0,primo=0,soma=0;;
  while(scanf("%c",&palavra)!=-1){


    if ((palavra!= ' ') && (palavra!='\n')){
        valorpalavra=CalculaValorPalavra(palavra);
        soma+=valorpalavra;
        continue;
    }

    if (palavra == '\n') { // essa linha significa q ele vai fazer a verificação sempre que o caracter eh '\n', ou seja, ao final de cada palavra
        primo=EhPrimo (soma);

        if(primo==0){ // se a palavra n for primo, busca o proximo. antes a função EhPrimo retornava 1 sempre 
            ProximoPrimo(soma);
        }
        soma=0;
    }
    
  }
    return 0;
}
       
      