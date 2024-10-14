#include "abbLista.h"


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

//========= Q2 - min =====
int min (Arvore *a){
   while (a->esq!=NULL){
      a=a->esq;
   }
   return a->info;
}


//========= Q2 - max =====
int max (Arvore *a){
   while (a->dir!=NULL){
      a=a->dir;
   }
   return a->info;
}

//========= Q3 - imprime_decrescente =====
void imprime_decrescente (Arvore *a){
   if (a!=NULL){
      imprime_decrescente(a->dir); //sempre printando o elemento mais a direita.
      printf("%d ",a->info);
      imprime_decrescente(a->esq);
   }
   

}

//========= Q4 - maior ramo =====
int maior_ramo (Arvore *a){
   if(a!=NULL){
      if(a->esq==NULL && a->dir==NULL){ //volto na pilha de recursão, porque é folha
         return a->info; //retorno o valor do nó, porque a partir daqui é para voltar.
      }
      //partindo do pressuposto que para chegar aqui não pode ser folha, agora basta analisar qual lado é maior.
      if (maior_ramo(a->esq) > maior_ramo(a->dir)){
         return a->info + maior_ramo(a->esq); // retorno aquele número mais o seu lado esq, uma vez que ele é maior.
      }
      else{
         return a->info + maior_ramo(a->dir);
      }

   }
  
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

   //inserir
   a = inserir (a, 50);
   a = inserir (a, 30); 
   a = inserir (a, 90); 
   a = inserir (a, 20); 
   a = inserir (a, 40); 
   a = inserir (a, 95); 
   a = inserir (a, 10);
   a = inserir (a, 35);
   a = inserir (a, 45);
   pre_order (a);	
   printf("\n");
   
   int num;
   /*scanf("%d",&num);
   if (buscar(a,num)){
      printf("O elemento %d está na arvore\n",num);
   }
   else{
      printf("O elemento %d NÃO está na arvore\n",num);
   }

   printf("O valor mínimo é: %d\n",min(a));
   printf("O valor máximo é: %d\n",max(a));
  imprime_decrescente(a);
   */
   // ====== Q5 ====
   printf("%d\n",maior_ramo(a));
   return 0;
}


