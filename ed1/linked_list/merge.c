#include "list.h"

List* merge (List *A, List *B){
  List *t,*C;
  C=NULL;
  t=NULL;
   
  while(A!=NULL && B!=NULL){

    if(C==NULL){
    if (A->data > B->data){
      C=B;
      t=B;
      B=B->next;
    }
    else{
      C=A;
      t=A;
      A=A->next;
    }
   }
  else{
   if (A->data > B->data){
    t->next=B;
    B=B->next;
    t=t->next;

   }
   else{
    t->next=A;
    A=A->next;
    t=t->next;
   }
  }

  }

  if(A==NULL){
    t->next=B;
  }
  else{
    t->next=A;
  }
  
  return C;
  	
}

/**/
int main () {
  int k;
  List *A = NULL, *B = NULL;

  for (k = 10; k >= 0; k -= 2) 
    A = insert (A, k);
  for (k = 19; k >= 0; k -= 2) 
    B = insert (B, k);
  print (A);
  print (B);
  List *C = merge (A, B);
  print (C);
  destroy (C);
  return 0;
}
