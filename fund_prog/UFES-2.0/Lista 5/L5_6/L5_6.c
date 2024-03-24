#include <stdio.h>

void Imprime (int tamA, int cont){

  if(tamA==cont){
    printf("TODOS");
  }
  else if (cont==0){
    printf("NENHUM");
  }
  else {
    printf("PARCIAL");
  }

}

int ComparaOsVetores(int vetorA[],int vetorB[],int tamA,int tamB,int qntdA){
  int i=0,cont=0,numiguais=0,varreutotal=0;

  while(1){

  while (cont<tamB){//varrer todos os valores de B para um único valor de A
  if (vetorA[i]==vetorB[cont]){
    numiguais++;
    break;
      //recomeçar, pq agora é um novoA
  }
  cont++;
}
cont=0;
i++;
varreutotal++;

  if (varreutotal==qntdA){
    break;
  }
}

  Imprime (tamA,numiguais);
}

int main (){
  int qntdA=0, i=0;
  int qntdB=0,j=0;

  scanf("%d",&qntdA);

  int vetorA[qntdA];
  for (i=0;i<qntdA;i++){

    scanf("%d",&vetorA[i]);

  }

  scanf("%d",&qntdB);

  int vetorB[qntdB];
  for (j=0;j<qntdB;j++){

    scanf("%d",&vetorB[j]);
  }

    ComparaOsVetores(vetorA,vetorB,i,j,qntdA);

    return 0;
}