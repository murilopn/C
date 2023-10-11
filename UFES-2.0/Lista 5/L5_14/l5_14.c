#include <stdio.h>
typedef struct{

    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
}tCandidato;

void ImprimeCandidato(tCandidato candidato){

    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",candidato.codigo, candidato.nome, 
candidato.sobrenome, candidato.nota, candidato.idade);
}

int ComparaString(char str1[],char str2[]){
    int i=0,j=0;
    while (str1[i]!='\0' || str2[j]!='\0'){
        if (str1[i]!=str2[j]){   //quer dizer que as palavras sao diferentes
            return 0;
        }
        i++;
        j++;
    }
    return 1;// palavras iguais.
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

int main (){
    int qtdCand, i = 0,j=0,novo=1;
    
 scanf("%d", &qtdCand); 
  tCandidato candidatos[qtdCand]; 
  
 for(i = 0; i < qtdCand; i++){ 
  candidatos[i] = LeCandidato(); 
 } 
 for (i=0;i<qtdCand;i++){
    for (j=i+1;j<qtdCand;j++){

        if(ComparaString(candidatos[i].sobrenome,candidatos[j].sobrenome )){/*estou passando o candidato logo com o sobrenome,logo
                                                  não preciso colocar posição de caractere de sobrenome aqui, a função faz isso nos i e j*/
            if (candidatos[j].nota!=-1){
                if (novo){ 
                    ImprimeCandidato(candidatos[i]);    //criei esse novo para não imprimir o mesmo nome mais de uma vez
                    ImprimeCandidato(candidatos[j]);
                    candidatos[j].nota=-1;              //criei pra quando tiver 3 ou mais nomes iguais, não imprimir o 2 e o 3 dnv quando for a vez deles.
                    novo=0;
                }
                else {
                    ImprimeCandidato(candidatos[j]);
                    candidatos[j].nota=-1;
                }   
          
        }
        }
    }
    novo=1;
 }
 
}
