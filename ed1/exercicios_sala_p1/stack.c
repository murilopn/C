#include "stack.h"

Stack* create () {
  return NULL;
}

void destroy (Stack *s) {
  Stack *t=s;
  while (t!=NULL){
    t=s->next;
    free(s);
    s=t;
  }
}

Stack* push (Stack *s, int elem) {
  
  Stack *node= (Stack *) malloc (sizeof(Stack));
  node->data=elem;//tenho que encaixar esse node na cabeça
  node->next=s;
  return node;

}

Stack* pop (Stack *s) {
  if (empty(s)==0){
  Stack*t=s->next; //como estou na pilha, eu vou tirar o último que entrou (a cabeça)
  free(s);
  s=t;
  }
    return s;
}

int get_peek (Stack *s) {
  if (s!=NULL){
    return s->data;
  }
}

int empty (Stack *s) {
  return (s==NULL);
}

void print (Stack *s) {
  Stack *t=s;
  printf("Stack (peek) ");
  for (t=s;t!=NULL;t=t->next){
    printf("%d ",t->data);
  }
  printf("(base)\n");
}
