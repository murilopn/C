#include "list.h"

int meio (List *l) { //ele deu a dica de criar dois ponteiros, um anda 2x mais rápido do q o outro
  //List *t= (List*) malloc (sizeof(List));
  List *t=l;
  List *s=l;
  //List *s= (List *) malloc (sizeof(List));
  

  while (s->next!=NULL){ //s vai andar 2x mais q t
   
    s=s->next;
    if(s->next!=NULL){
      s=s->next;
    }
   /*
    else{ se eu colocar esse else, ele vai printar o segundo elemento do meio das listas pares.
      break;
    }
   */
    t=t->next;
  }
      return t->data;
  //quando sair daqui quer dizer que chegou no meio

}

int main () {
  int i;	
 
  List *l0 = create();
  for (i = 0; i < 3; i++)
    l0 = insert (l0, i);	
  print (l0); 
  printf("Elemento no meio da lista: %d\n", meio(l0));
  destroy (l0);

  List *l1 = create();
  for (i = 0; i < 10; i++)
    l1 = insert (l1, i);	
  print (l1); 
  printf("Elemento no meio da lista: %d\n", meio(l1));
  destroy (l1);

  List *l2 = create();
  for (i = 0; i < 19; i++)
    l2 = insert (l2, i);	 
  print (l2); 
  printf("Elemento no meio da lista: %d\n", meio(l2));
  destroy (l2);

  return 0;
}
 