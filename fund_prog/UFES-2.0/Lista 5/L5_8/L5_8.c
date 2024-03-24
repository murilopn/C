#include <stdio.h>

void ImprimeDadosDoVetor(int numero [], int tam){
  int i=0;
    printf("{");
    for (i=0;i<tam;i++){

        if (i==tam-1){
            printf("%d}",numero[i]);
        }

      else{
      printf("%d, ",numero[i]);
    }}
}
void TrocaParEImpar (int numeros[], int tam){
  int i=0;
  int numtrocados[tam];
    for (i=0;i<tam;i++){

      if (!(i%2)){
        if (i+1==tam){
            numtrocados[i]=numeros[i];
            continue;
        }
        else{
        numtrocados[i]=numeros[i+1];

      }}
      else {
        numtrocados[i]=numeros[i-1];
      }
    }

  ImprimeDadosDoVetor(numtrocados,i);
}

int main (){
  int qntd=0,i=0;

  scanf("%d",&qntd);

  if (qntd==0){
    printf("{}");
  }
else {
  int numeros[qntd];

  for (i=0;i<qntd;i++){

    scanf("%d",&numeros[i]);

  }
  TrocaParEImpar (numeros,i);
}
    return 0;
}