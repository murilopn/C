#include "queue.h"

Queue* create() {
  return  NULL; //lista encadeada sem cabeça retorna null
}

void destroy (Queue *q) {
  //tenho q ir destruindo vagão por vagão
  while (q!=NULL){
    Queue*t=q->next;
    free (q);
    q=t;
  }
}

int empty (Queue *q) {
  return (q==NULL);
}

Queue* enqueue (Queue *q, int elem) {
  Queue*node=(Queue *)malloc(sizeof (Queue));//tenho que criar um novo vagão
  node->data=elem;
  node->next=NULL; //pq ele tá entrando no final da lista.
 
  if (q==NULL){
    return node;
  }
  else{
  Queue *t=q;
  while (t->next!=NULL){ //tenho que inserir na calda, logo preciso correr até a
    t=t->next;
  }
    t->next=node;
  }

  return q;
}

Queue* dequeue (Queue *q) {
  //vou direto na calda (é uma fila)
  
  if(q==NULL){
    return q;
  }
  else{
  Queue *t=q;
    t=q->next;
    free(q);
    q=t;

  }
  
  return q;
}

int get_front (Queue *q) {
  if(q!=NULL){
    return q->data;
  }
}

void print (Queue *q) {
  Queue *t=q;
  printf("Queue (front): ");
  while (t!=NULL){
    printf("%d", t->data);
    t=t->next;
  }
  printf("(back)\n");
}

