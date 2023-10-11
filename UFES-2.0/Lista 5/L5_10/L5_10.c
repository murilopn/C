#include <stdio.h>
void Imprime (int ordem[],int tam){
  
}

void OrdenaCrescente (int numeros [], int tam){
    int i=0,pos=0,a=0,j=0;
    int menor [tam];
    a=tam;
    for (i=0;i<tam;i++){
            while (j<tam){
             
            if (numeros[i]<=numeros[j]){
                menor[i]=numeros[i];
                pos=i;
                 j++;
        }}
          j=i+1;
    }
    Imprime (menor,i);
}

int main (){
    int i=0,qntd=0;

    scanf("%d",&qntd);

    int numeros[qntd];

    for (i=0;i<qntd;i++){
        scanf("%d",&numeros[i]);
    }

    OrdenaCrescente (numeros,i);


    return 0;
}