#include "utils.h"

/* */
int missing_number (int *A, int n, int m) {
  int l=0, r=n-1;
  int mean= (l+r)/2;
  int cont=0;

  if (A[l]!=0){ //Quando não começa no zero
    return 0;
  }
  
  if(A[l] + (r-l) == A[r]){ // para casos em que a sequência é completa, ex: 0,1,2,3
    return m-1;
  }

  while (l+1!=mean && r-1!=mean){ //a ideia é que mean fique no meio entre l e r, ou seja, A[mean]+1 não existe.

    mean=(l+r)/2;

    if (A[l] + (r-l) != A[mean]){ //condição para reduzir o tamanho da minha lista (fui fazendo no papel até descobrir)
      l=mean;
    }

    else {
      r=mean;
    }
  }

  return (A[mean]+1);
  
} 

/* */
int main () {
  int i;
  //int n = 4, m = 4;
  //int A[] = {0,1,2,3};
  //int n = 4, m = 12;
  //int A[] = {4,5,10,11};
  //int n = 7, m = 16;
  //int A[] = {0,1,2,6,9,11,15};
  //int n = 8, m = 16;
  //int A[] = {1,2,3,4,6,9,11,15};
  //int n = 7, m = 7;
  //int A[] = {0,1,2,3,4,5,6};
  int n = 9, m = 11;
  int A[] = {0,1,2,3,4,5,6,7,10};
  print (A, n, "Input");
  printf("Missing number: %d\n", missing_number (A, n, m));
  return 0;
}
