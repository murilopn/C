#include "list.h"


List* merge (List *A, List *B) {
  
  if(A==NULL){ //Eu não preciso dar return B->next, pq já acabou a lista, ou seja, na hora da recursão, vai voltar por B.
    return B;
  }
  else if(B==NULL){
    return A;
  }
  else{
    if(A->data <= B->data){
      A->next = merge(A->next,B);/*estou mudando quem o próximo nó está conectado (interpretar o A->next como o local onde eu vou jogar a corda e o parâ
      metro A->next como o nó a ser comparado)*/
      return A;
    }
    else{
      B->next= merge(A,B->next);
      return B;
    }
  }
  


}

int main () {
  int k;
  
  List *A = NULL;
  for (k = 0; k <= 14; k += 2) {
    A = insert_back (A, k);
  }
  printf("Lista = ");
  print (A);
  printf("\n");

  List *B = NULL;
  for (k = 1; k <= 9; k += 2) {
    B = insert_back (B, k);
  }
  printf("Lista = ");
  print (B);
  printf("\n");
  List *C = merge (A, B);
  printf("Lista = ");
  print (C);
  printf("\n");

  destroy (C);
  return 0;
}

   
 /*    


 


 if(A==NULL){
   
  }
  else if (B==NULL){
    
  }
  else{
    printf("%d e %d\n",A->data, B->data);

    if(A->data > B->data){
      return (merge(A->next,B));
    }
    else{
      return (merge(A,B->next));
    }
  }
*/
