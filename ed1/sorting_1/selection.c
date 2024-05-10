#include "utils.h"

/* */
void selection_sort (int *A, int n) {
  int menor,j,i;
  for (i=0;i<n;i++){
    menor=i;
  
    for (j=i+1;j<n; j++){ //n-1, pois não posso comparar com o elemento de fora, meu último índice é n-1
      if (A[menor]>=A[j]){
          menor=j;
      }
    }
    swap(A,i,menor);
  }	
}

/* */
int main (int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }
   
  int i;
  int n = atoi(argv[1]);
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
  }  

  start = clock();
  //print (A, n, "Input");
  selection_sort (A, n);
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

