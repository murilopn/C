#include <stdio.h>
void  Imprime(int vetA[],int vetB[],int tamA,int tamB){
    int i=0,j=0;
    
    while(i+j<tamA+tamB){

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
        else{
            printf("A");
            i++;
        }

    }


}

void OrdenaVetor(int vet[],int tam){
    int aux;
    for(int i=0; i<tam; i++){
        for (int j=i+1; j<tam; j++){

            if(vet[i]>vet[j]){
                aux=vet[i];
                vet[i]=vet[j];
                vet[j]=aux;
            }

        }
    }
}

int main (){
    int qntdA, qntdB,i,j;

    scanf("%d",&qntdA);
    
    int vetA[qntdA];
    
    for(i=0;i<qntdA;i++){
        scanf("%d",&vetA[i]);
    }

    scanf("%d",&qntdB);

    int vetB[qntdB];
    
    for(j=0; j<qntdB; j++){
        scanf("%d",&vetB[j]);
    }

    OrdenaVetor(vetA,i);
    OrdenaVetor(vetB,j);
    Imprime(vetA,vetB,i,j);



    return 0;
}