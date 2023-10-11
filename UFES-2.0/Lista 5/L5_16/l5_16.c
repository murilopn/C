#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct{ 
 int codigo; 
 char sobrenome[21]; 
 char nome[21]; 
 int nota; 
 int idade; 
} tCandidato; 
 
  void ImprimeCandidato(tCandidato candidato[],int i){  
    
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",candidato[i].codigo, candidato[i].nome,     
  candidato[i].sobrenome, candidato[i].nota, candidato[i].idade); 
}

void OrdenaCrescente(tCandidato candidatos[], int qtdCand){
    int i,j;
    tCandidato aux;

 for(i = 0; i < qtdCand; i++){ 

    for(j=i+1 ; j<qtdCand; j++){
        if (candidatos[i].nota<candidatos[j].nota){ // maior nota
           
                aux = candidatos[i];
                candidatos[i]=candidatos[j];
                candidatos[j] = aux;
        }
        else if (candidatos[i].nota==candidatos[j].nota){

             if(candidatos[i].idade>candidatos[j].idade){//menor idade
                        aux = candidatos[i];
                        candidatos[i]=candidatos[j];
                         candidatos[j] = aux;
             }
             else if (candidatos[i].idade==candidatos[j].idade){
                    if(candidatos[i].codigo>candidatos[j].codigo){
                            aux = candidatos[i];
                            candidatos[i]=candidatos[j];
                            candidatos[j] = aux;
                    }
             }
        }
    }
  ImprimeCandidato(candidatos,i);

 }

}
 
tCandidato LeCandidato(){ 
 tCandidato candidato; 
 scanf("%*[^{]"); 
 scanf("%*[{ ]"); 
 scanf("%d", &candidato.codigo); 
 scanf("%*[, ]"); 
 scanf("%[^,],", candidato.sobrenome); 
 scanf("%*[ ]"); 
 scanf("%[^,],", candidato.nome); 
 scanf("%d", &candidato.nota); 
scanf("%*[, ]"); 
scanf("%d", &candidato.idade);  
scanf("%*[^\n]\n");
  return candidato; 
  }  

int main(){ 
 int qtdCand, i = 0, j; 
  
 scanf("%d", &qtdCand); 
  tCandidato candidatos[qtdCand]; 
  
 for(i = 0; i < qtdCand; i++){ 
  candidatos[i] = LeCandidato(); 
 } 
  OrdenaCrescente(candidatos,qtdCand);

    return 0;     
} 