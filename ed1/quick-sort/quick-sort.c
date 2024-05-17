#include "utils.h"

/* */
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

/* */
void quick_sort (int *A, int left, int right) {
  int p;
  if (left < right){
    p= partition(A,left,right);
    quick_sort(A, left, p-1);
    quick_sort(A, p+1, right);
  }
}

/* */
int main (int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  int i;
  int n = 100000; /*Altere para 100, 1000, 10 mil, 1 milhao elementos!*/
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    //A[i] = rand() % (n+1); /*valores aleatórios*/
    //A[i] = i; /*ordem crescente*/
    //A[i] = n-i; /*ordem descrente*/
    A[i] = 0; /*iguais*/
  }  

  start = clock();
  //print (A, n, "Input");
  quick_sort (A, 0, n-1);
  //print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

