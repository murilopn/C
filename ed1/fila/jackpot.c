#include "queue.h"
#include <time.h>


void jackpot (int n, int r) {
  int i=0,j=0;
 /*ideia: criar um vetor com 3 posições, cada posição é um carretel que contém 10 elementos:
 usarei ponteiro de forma a apontar para a struct da Queue da queue.h, daí vai jogar no create da queue.c, ou seja, 2 ponteiros*/

 Queue**carretel; //declarando com dois, pois é poonteiro pra vetor dando malloc
 int elem,elem_sort,cont=0;
 carretel= (Queue**)malloc(sizeof(Queue*)*n);/*n pq são n carretéis*/
 
 //preenchendo cada carretel
 for (i=0;i<n ;i++){
  
  carretel[i]=create(r+1);//criando os n carretéis
  
  
  elem = rand() % 10;//sortenado primeiro elemento de forma aleatória (mecanismo de diferenciação entre as filas)

   
  for (j=0; j<r; j++){
    enqueue(carretel[i],elem);//preenchendo o vetor de 10 posições correspondente a cada carretel
    elem++;
    if(elem>9){
      elem=0;
    }
  }
 }


for (i=0;i<r;i++){ //eu escolho o número de jogos a serem feitos. Eu escolhi o valor de r, por vontade, mas poderia ser 1, se eu quisesse.
  
  for (j=0; j<n; j++){
    elem = dequeue(carretel[j]); 
    enqueue(carretel[j],elem); //enfileirando novamente, como o exerício pede
    printf("%d ",elem);
    
  }
  printf("\n");
  
}
//agora é ver se o elemento do front é igual aos 2o e 3o
elem_sort=front(carretel[0]);//retorna um valor int para o primeiro elemento q deve ser compatível ao carretel [0][1][2]
//estou fazendo fora do for, pra já estabelecer esse número.


for (i=0; i<n;i++){
  if (elem_sort==front(carretel[i])){ //vai retornar um int, q deve ser igual ao elem_sort lá de cima(fora do for)
    cont++;
  }
  //printf("%d ",&carretel[i]);
}

if (cont==n){
  printf("parabéns, você venceu!!\n");
}
else{
 printf("Não foi dessa vez, tente na próxima\n"); 
}

}


int main () {
  srand(time(NULL));	
  int n = 3;  /*número de carretéis*/ 
  int r = 10; /*sequência de números em cada carretel*/
  jackpot (n, r);

  return 0;
}



