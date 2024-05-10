/*************/
/*  Queue.h  */
/*************/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR -INT_MAX
#define TRUE 1
#define FALSE 0

/*Structure*/
typedef struct node { 
  int data;
  struct node *next;
} Queue;

/*Interface:*/
Queue* create ();
void destroy (Queue *q);
Queue* enqueue (Queue *q, int elem);
Queue* dequeue (Queue *q);
int get_front (Queue *q);
int empty (Queue *q);
void print (Queue *q);

/*************/
/*  Queue.c  */
/*************/

Queue* create () {
  /*Terminar*/
}

void destroy (Queue *q) {
  /*Terminar*/
}

int empty (Queue *q) {
  /*Terminar*/
}

Queue* enqueue (Queue *q, int elem) {
  /*Terminar*/
}

Queue* dequeue (Queue *q) {
  /*Terminar*/
}

int get_front (Queue *q) {
  /*Terminar*/
}

void print (Queue *q) {
  /*Terminar*/
}

/**************/
/* Programa.c */
/**************/
int main () {
  srand(time(NULL));	
  int i;
  int r = 10; /*sequência de números em cada carretel*/
  Queue *q1, *q2, *q3;
  q1 = q2 = q3 = create();
  for (i = 0; i < r; i++) {
    q1 = enqueue (q1, i);
    q2 = enqueue (q2, i);
    q3 = enqueue (q3, i);
  }
  int ntries = 0;
  int fq1, fq2, fq3;
  do {
    int j;
    int r1 = rand() % 100;
    for (j = 0; j < r1; j++) { 
      q1 = enqueue (q1, get_front(q1));
      q1 = dequeue (q1);
    }  
    int r2 = rand() % 100;
    for (j = 0; j < r2; j++)  {
      q2 = enqueue (q2, get_front(q2));
      q2 = dequeue (q2);
    }  
    int r3 = rand() % 100;
    for (j = 0; j < r3; j++) {
      q3 = enqueue (q3, get_front(q3));
      q3 = dequeue (q3);
    }  
    fq1 = get_front (q1);  
    fq2 = get_front (q2);  
    fq3 = get_front (q3);  
    printf ("Sorteio: %d,%d,%d\n", fq1, fq2, fq3);
    ntries++;
  } while ((fq1 != fq2) || (fq2 != fq3));
  printf ("Ganhou :)\n");
  printf("Número de tentativas: %d\n", ntries);
  destroy (q1);
  destroy (q2);
  destroy (q3);
  return 0;
}
