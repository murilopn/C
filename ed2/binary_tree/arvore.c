#include "arvore.h"
#define max(a, b) ((a) > (b) ? (a) : (b)) //usando ternário, mas poderia fazer uma funçãozinha e afins.

Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}


//========= Exercício 2 - pré-ordem ====
void pre_ordem(Arvore *a){ //RED
    if (!verifica_arv_vazia(a)){
       printf("%c ",a->info);
       pre_ordem(a->esq);
       pre_ordem(a->dir);
    }

}

//========= Exercício 2 - in-ordem ====
void in_ordem(Arvore *a){ //ERD
    
    if (!verifica_arv_vazia(a)){
        in_ordem(a->esq);
        printf("%c ",a->info);
        in_ordem(a->dir);
    }
} 

//========= Exercício 2 - pós-ordem ====
void pos_ordem(Arvore *a){ //EDR

    if (!verifica_arv_vazia(a)){
        pos_ordem(a->esq);
        pos_ordem(a->dir);
        printf("%c ",a->info);
    }
} 


//========= Exercício 3 - pertence ====

int pertence_arv (Arvore *a, char c){
    if (!verifica_arv_vazia(a)){
        if (a->info==c){
            return 1;
        }
    else{
        int left,right;
        left = pertence_arv(a->esq, c);
        right = pertence_arv(a->dir,c);    
        return left || right;
    }
  }
  else{
        return 0;
  }

}

//========= Exercício 4 - conta nós ==== a ideia aqui é varrer a árvore toda e contar na volta da recursão da pilha
int conta_nos (Arvore *a){
   
    if (!verifica_arv_vazia(a)){
        return (1+conta_nos(a->esq)+conta_nos(a->dir));
    }
    else{
        return 0;
    }

  
}

//========= Exercício 5 - calcula altura ==== 
int calcula_altura_arvore (Arvore *a){

      if(verifica_arv_vazia(a)){
        return -1; //quando a árvore é NULL, sua altura é -1.
      }
      else{
        return (max(calcula_altura_arvore(a->esq), calcula_altura_arvore(a->dir))+1);
        //percorro o lado esq. todo e dps o direito todo. Comparo qual é maior e somo +1.
      }
      /*O conceito de altura é da árvore, ou seja, eu tenho que ir para o lado esquerdo e para o lado direito e ver em qual
      lado a minha altura é maior, é isso que a função max faz. Eu somo +1, pq ela já começando indo para o endereço apontado,
      ou seja, ela ignora a primeira "cordina", a primeira altura*/
}



//========= Exercício 6 - conta folhas ====
int conta_nos_folha (Arvore *a){
    if (!verifica_arv_vazia(a)){
        
        if(a->esq==NULL && a->dir==NULL){
            return 1;
        }
        return (conta_nos_folha(a->esq)+conta_nos_folha(a->dir));
        }
    
    return 0;
    
    }


int main (int argc, char *argv[]) {

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );	
/*
//exercício 2
    pre_ordem(a);
    printf("\n");
    in_ordem(a);
    printf("\n");
    pos_ordem(a);    
    printf("\n");  

//exercício 3

    char c = 'a';
    printf("Digite o número que você acha que está na árvore: ");
    scanf("%c",&c );
    if(pertence_arv(a,c)){
     printf("A letra %c pertence a árvore\n", c);
    }
    else {
     printf("A letra %c não petence a árvore\n",c);
    }

//exercício 4
    printf("O número de nós é: %d\n", conta_nos(a));
    arv_libera (a); 
*/

//exercício 5
    int h=calcula_altura_arvore(a);
    printf("A altura da árvore é: %d\n",h);

//exercício 6
    int folhas=conta_nos_folha(a);
    printf("O número de nós folha é: %d\n",folhas);
    return 0;
}

 