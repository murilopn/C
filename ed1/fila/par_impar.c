#include "queue.h"
#include <time.h>

int main () {
  int i, n = 10,elem=0;	
  /*Use somente as operações definidas em queue.h*/
  /*Não use para resolver esse exercício o operador -> aqui!*/
  /*Terminar*/
  
  Queue *par = create(n);
  Queue *impar = create(n);
  srand(time(NULL));
  i=0;
  while (i<n){
    elem= rand()%10;

    if(elem%2==0){
      enqueue(par,elem);
    }
    else{
      enqueue(impar,elem);
    }
    i++;
  }
  
  print(par);
  printf("\n");
  print(impar);
  destroy(par);
  destroy(impar);

  return 0;
}

