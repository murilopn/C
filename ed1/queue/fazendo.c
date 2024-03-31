#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct {
    int size;
    int back;
    int front;
    int *array;// mesma coisa que int array[];


}Queue;

Queue *create(int n){ //tava dando ruim, pq não havia colocado o * aqui (isso faz com que eu retorne q e não *q e tb tire o * do par e impar na main)
    
    Queue *q = (Queue *)malloc (sizeof(Queue)); 
    q->front=0;
    q->back=0;
    q->size=n;
    q->array = (int *) malloc (sizeof(n*sizeof(int)));

    return q;
}
void enqueue(Queue *q, int n){
    q->array[q->back] = n;
    q->back = (q->back + 1) % q->size;

}

int main (){
    int n=10,i=0;
    Queue *impar,*par;
    srand(time(NULL));
     par = create(n);
     impar = create(n);

    while(i<n){
        int num=rand()%100;
        if (num%2==0){
            enqueue(par,num);
        }
        else{
            enqueue(impar,num);
        }
        i++;
    }
    printf("PARES: ");
    for (int s=0; s<par->back; s++){
        printf("%d ",par->array[s]);
    } 
    printf("\n");
    printf("ÍMPARES: ");
    for (int s=0; s<impar->back; s++){
        printf("%d ",impar->array[s]);
    }

    return 0;
}
