#include "utils.h"

int partition (int A[], int left, int right) {
  int pivo,i,j;
  pivo=A[right];
  i=left-1; //sim, ele começa fora mesmo.
  for (j=left; j<right; j++){
    if (A[j] <= pivo){
      i++;
      swap(A,i,j);
    }
  }
  swap(A, i+1, right);
  return i+1;

}

void quick_find (int *A, int left, int right, int k) {
  int pivo=0;
  pivo=partition(A, left, right); //me retorna a posição do pivô

  /*na hora de mexer na recursão pensar assim: se k<pivo, o final tá ok, eu tenho que acrescentar no
  começo. Se for maior, o começo tá ok, eu tenho q tirar do final*/

  if (pivo>k){ 
    quick_find(A,left,pivo-1,k);
  }
  else if(pivo<k){
    quick_find(A,pivo+1,right,k);
  }
  //se não for igual a nada vai sair. A ideia é fazer o pivo ser k e retornar ele 
}

/* */
int main () {
  int n = 8;
  int A[] = {7, 1, 3, 10, 17, 2, 21, 9};
  print (A, n, "Input");
  quick_find (A, 0, n-1, 4);
  print (A, n, "Partial sorted");
  return 0;
}
