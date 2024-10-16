#include "abbLista.h"
#define SIZE 7

Arvore* cria_arvore_vazia (void) {
   return NULL;
}

void arvore_libera (Arvore* a) {
   if (a != NULL) {
      arvore_libera (a->esq);
      arvore_libera (a->dir);
      free(a);
   }
}

//========= Q1 - inserir
Arvore* inserir (Arvore *a, int v) {
 
   if (a!=NULL){
      if (a->info > v){
         a->esq= inserir(a->esq,v);
      }
      else{
         a->dir = inserir(a->dir,v);
      }
   }
   else{
      //Ao chegar aqui, o meu a é nulo, por isso eu devo alocar memória na própria arvore a
      a = (Arvore*) malloc (sizeof(Arvore));
      a->info=v;
      a->esq=NULL;
      a->dir=NULL;
   }
   return a;
}

//========= Q1 - remover
Arvore* remover (Arvore *a, int v) {
//lembrar que na hora da recursão, eu vou retornando nó após nó para o meu ponteiro.
   if (a!=NULL){
      if (a->info==v){ 
         //quando estou no nó folha:
         if (a->dir==NULL && a->esq==NULL){
            free(a);
            a=NULL; //vou retornar nulo para o ponteiro que chamou.
         }
         //quando esq é null e dir não - vou conectar o dir no elemento que estava antes dele
         if (a->esq == NULL){
            Arvore* tmp=a;
            a=a->dir;//faço o meu a virar o elemento ao qual o meu a aponta.
            free(tmp); //libero antigo "a" (que é o tmp).
         }
         //quando dir é null e esq não
         if (a->dir == NULL){
            Arvore* tmp=a;
            a=a->esq;
            free(tmp);
         }
         //quando nem dir e nem esq são nulos
         else{

         }
      }
      else{
         if (a->info > v){
            a->esq = remover(a->esq,v);
         }
         else{
            a->dir = remover (a->dir,v);
         }
      }
   }
   return a;
}


//========= Q1 - busca
int buscar (Arvore *a, int v) {
  if (a!=NULL){
   if (a->info < v){
      buscar(a->dir,v);
   }
   else if (a->info > v){
      buscar(a->esq,v);
   }
   else{
      return 1;
   }
  }
  return 0; 
    
}

int ancestral (Arvore *a, int e1, int e2){
   if(a!=NULL){
      if (e1 < a->info && a->info < e2){
         return a->info;
      }
      else{
         if(ancestral(a->esq,e1,e2)!=0){
            return ancestral(a->esq,e1,e2);
         }
         if(ancestral(a->dir,e1,e2)!=0){
            return ancestral(a->dir,e1,e2);
         }
      }
   }
} 
Arvore* constroi_balanceado (int v[], int esq, int dir){
   if (esq > dir){ //lembrar que isso ocorre, pois mid-1 ou mid+1 toda vez.
      return NULL;
   }
   int mid = (esq+dir)/2;
   Arvore *a = cria_arvore_vazia();

   //devo começar inserindo o elemento do meio
   a = inserir(a,v[mid]);

   //faço os ponteiros apontarem para os novos elementos do meio. Primeiro fazendo a subárvore da esq e depois da dir.
   a->esq = constroi_balanceado(v,esq,mid-1);
   a-> dir = constroi_balanceado(v,mid+1,dir);

    return a;


}

void pre_order (Arvore* a) {
   if (a != NULL) {
      printf("%d ", a->info);
      pre_order (a->esq);
      pre_order (a->dir);
   } 
}

int main () {

   int i;

   Arvore *a = cria_arvore_vazia ();
   Arvore *b = cria_arvore_vazia();

   //inserir
   a = inserir (a, 20);
   a = inserir (a, 8); 
   a = inserir (a, 22); 
   a = inserir (a, 4); 
   a = inserir (a, 12); 
   a = inserir (a, 10); 
   a = inserir (a, 14);
   pre_order (a);	
   printf("\n");

   //Questão 6
   int e1=0,e2=0;
   scanf("%d",&e1);
   scanf("%d",&e2);
   printf("%d\n",ancestral (a,e1,e2));
 
   /*//questão 7
   int vet [SIZE];
   for (int i=0; i<SIZE; i++){
      scanf("%d",&vet[i]);
   }
   b = constroi_balanceado(vet, 0, SIZE-1);
   pre_order(b);	
   printf("\n");
   */
   return 0;
}


