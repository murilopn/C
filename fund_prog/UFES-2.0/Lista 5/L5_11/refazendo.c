#include <stdio.h>

void Imprime (int vetA[], int vetB[], int tamA, int tamB){
    int i=0,j=0;

    while (i+j <tamA+tamB){

        if(i==tamA && j<tamB){
            printf("B");
            j++;
        }
        else if(j==tamB && i<tamA){
            printf("A");
            i++;
        }
        else if(vetA[i]>vetB[j]){
            printf("B");
            j++;
        }
        else {
            printf("A");
            i++;
        }
    }
    printf("\n");
}

void OrdenaVetor (int vet [], int tam){
    int i=0,j=0,aux=0;

for (i=0; i<tam; i++){
    for (j=i+1; j<tam; j++){
        if(vet[i]>vet[j]){
            aux=vet[i];
            vet[i]=vet[j];
            vet[j]=aux;
        }
    }
  }
}


int main (){
    int tam1,tam2,i,j;

scanf("%d",&tam1);

    int vetA[tam1];

for ( i=0; i<tam1; i++){
    scanf("%d",&vetA[i]);
}

scanf("%d",&tam2);

    int vetB[tam2];

for( j=0; j<tam2; j++){
    scanf("%d",&vetB[j]);
}

OrdenaVetor(vetA, i);
OrdenaVetor(vetB, j);
Imprime (vetA,vetB,i,j);

    return 0;
}