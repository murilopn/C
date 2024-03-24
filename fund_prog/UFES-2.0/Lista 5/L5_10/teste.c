#include <stdio.h>

void TrocaValor (int vet[], int i, int j){
    int aux;
    aux = vet[j];
    vet [j] = vet[i];
    vet [i]= aux;
}


int EhMenorQueAntes (int a, int b){
    return a<b;
}

int AcharMenorNum (int vet[],int a, int b){
    int i=0, indice=0, menor=0;

    menor=vet[a];
    indice=a;

    for (i=a+1;i<=b;i++){

        if (EhMenorQueAntes (vet[i],menor)){
            menor = vet[i];
            indice=i;
        }
    }
    return indice;

}

void OrdenaCrescente (int numeros [], int tam){
   int i=0, menorindice=0;

   for (i=0; i<tam-1;i++){

        menorindice= AcharMenorNum (numeros,i+1,tam-1);
        if (EhMenorQueAntes (numeros[menorindice],numeros[i])) {
                TrocaValor (numeros,menorindice,i);
        }

   }
}

void Imprime (int vet[], int tam  ){
    int i=0;
    printf("{");
    for (i=0;i<tam;i++){

        if (i+1==tam){
            printf("%d}",vet[i]);
        }
        else {
        printf("%d, ",vet[i]);
    }}

}



int main (){
    int i=0,qntd=0;

    scanf("%d",&qntd);

    if (qntd==0){
        printf("{}");
    }

    else {
    int numeros[qntd];

    for (i=0;i<qntd;i++){
        scanf("%d",&numeros[i]);
    }

    OrdenaCrescente (numeros,i);
    Imprime (numeros, i);

    }
    return 0;
}