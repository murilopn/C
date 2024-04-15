#include "list.h"

List* create_circular (List *head) {// não posso ter mais null
  List *t=head;

  if(head==NULL){
    t->next=NULL;
    t->prev=NULL;
    return t;
  }
  else{
    while (t->next!=NULL){
      t=t->next;
  }
    t->next=head;
    head->prev=t;
    return head;
  }
}

int main () {
  int i;	
  int n = 4;	
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  print (l);
  l = create_circular(l);
  print (l);
  destroy (l);
  return 0;
} 
