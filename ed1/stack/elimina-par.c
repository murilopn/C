#include "stack.h"

int main () {
  int tam = 6;
  Stack *s1 = create (tam);
  Stack *s2 = create (tam);
  srand(time(NULL));
  int i,e;
  for (i = 0; i < tam; i++) {
    push (s1, rand()%10);
    e=get_peek(s1);
    
    if(e%2==1){
      push(s2,e);
    }
  }
  print (s1);
  print (s2);
  destroy (s1);
  destroy (s2);
}
