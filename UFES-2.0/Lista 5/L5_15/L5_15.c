#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

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
 
 int OrdenaCrescente(tCandidato candidatos[],int qtdCand){
    int i,j,receben=0,recebes=0;
    tCandidato aux;

        for (i=0;i<qtdCand;i++){

            for (j=0;j<qtdCand;j++){

                receben=strcmp(candidatos[i].nome,candidatos[j].nome);

                if (receben<0){// j>i

                        aux=candidatos[i];
                        candidatos[i]=candidatos[j];
                        candidatos[j]=aux;
                  }

                else if (receben==0){ //iguais
                    recebes=strcmp(candidatos[i].sobrenome,candidatos[j].sobrenome);

                        if (recebes<0){// j>i
                            aux=candidatos[i];
                            candidatos[i]=candidatos[j];
                            candidatos[j]=aux;

                        }        
                  }

             }
         }

    for(i = 0; i < qtdCand; i++){ 
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
 int qtdCand,i, j; 
  
 scanf("%d", &qtdCand); 
  tCandidato candidatos[qtdCand]; 
  
 for(i = 0; i < qtdCand; i++){ 
  candidatos[i] = LeCandidato(); 
 } 
 
 OrdenaCrescente(candidatos, qtdCand); 
  
    return 0;     
} 