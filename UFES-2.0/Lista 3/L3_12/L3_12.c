#include <stdio.h>
int somadosdigitos(int n){
    int a=1,soma=0,b=0,cont=0;
    while (n!=0){
        a=n%10;
        n=n/10;
        soma=soma*10+a;
    }
    n=soma;
    soma=0;
    while (n!=0){
        a=n%10;
        n=n/10;
        soma+=a;
    
    }
    return soma;
}

void parImpar(int n){

    if (!(n%2)){
        printf(" Par ");
        if (n==0){
            printf("Nao e primo");
        }
    }
    else {
        printf(" Impar ");
        if (n==1){
            printf("Nao e primo");
        }
    }

}
void valorPrimo (int n){
    int cont=2;

    while (cont<n){
        if (!(n%cont)){
            printf("Nao e primo\n");
           break;
        }
            cont++;
        }
    if (cont==n){
        printf("Primo\n");
    }

}




int main (){
    int num=0,analise=11,teste=0,final=0;
    scanf ("%d",&num);
    
    analise=somadosdigitos(num); 
    printf("%d",analise);

    parImpar(analise);

     valorPrimo (analise);
     
        while (analise>=10){
         analise=somadosdigitos(analise); 
            printf("%d",analise);

           parImpar(analise);

            valorPrimo (analise);
            
    }
    
    return 0;
}