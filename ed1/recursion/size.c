#include "list.h"


int size (List *l) {

  if (l!=NULL){
    return (size(l->next) + 1);
  }
  return 0;
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
  printf("Size = %d\n", size(l));
  destroy (l);
  return 0;
}


