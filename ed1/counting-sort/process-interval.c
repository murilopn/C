#include "utils.h"

/* vou ter que ordenar e condição de parada = A [j] < numero passado, daí eu retorno o contador*/
int* process_interval (int *A, int n, int range) {
  int i, j;

  int *C = (int *)malloc((range+1) * sizeof(int)); 
  
    for (i=0; i<=range; i++){
      C[i]=0;
    }
    for (j=0; j< n; j++){
      C[A[j]] = C[A[j]]+1;
    }
    for (i=1; i<= range; i++){
      C[i] = C[i] + C[i-1];
    }   //ele sai da
    return C; //retornando ponteiro pro meu vetor q irei passar como parâmetro para a query
  
}

int query (int *C, int n, int i, int j) {
  /*a e b são os números referentes aos intervalos do meu vetor q já está ordenado.*/
  
  if (i){ //para casos em que i!=0
    return (C[j] - C[i-1]); //retorna o intervalo
  }
  else{
    return (C[j]); //só retorna os iguais/menores que J
  }
  /*Não pode ter laço de repetição!*/


  return n;
}

/* */
int main () {
  int a, b, n = 15;
  int range = 10;
  int A[] = {9,2,0,8,7,9,3,2,0,7,5,0,2,6,0};
  print (A, n, "Input");
  int *C = process_interval (A, n, range);
  a = 0, b = 3;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 4, b = 8;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 0, b = 0;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 6, b = 6;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 2, b = 4;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 9, b = 9;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  return 0;
}

