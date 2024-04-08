#include "list.h"


int sum (List *l) {

  if (l!=NULL){
    return (l->data + sum(l->next));
  }
  else{
    return 0; /*quando for igual a null, vai ser o final, daí eu volto somando (Recursividade, efeito dominó reverso), ele retorna e fica dentro do return da sum,
    n fica voltando no int sum lá em cima*/
  }
  
}

int main () {
  List *l = NULL;
  int k;
  for (k = 5; k <= 9; k++) {
    l = insert_back (l, k);
  }
  for (k = 4; k >= 0; k--) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("Sum = %d\n", sum(l));
  destroy (l);
  return 0;
}
