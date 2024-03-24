#include <stdio.h> 
#include <math.h>
int MenorNota(int pontuacoes[], int tam) {
  int menor=-32000,i=0;

  for (i=0;i<tam;i++){
    if (menor<pontuacoes[i]){
      menor=pontuacoes[i];
    }
  }
return menor;

}

int MaiorNota(int pontuacoes[], int tam) {
  int maior=32000,i=0;

  for (i=0;i<tam;i++){
    if (maior>pontuacoes[i]){
      maior=pontuacoes[i];
    }
  }
return maior;

}

float NotaMedia(int pontuacoes[], int tam){
  int soma=0,i;
  float media=0;
  for (i=0;i<tam;i++){
    soma+=pontuacoes[i];
  }
  media=soma/(float)tam;

return media;

}

float DesvioPadrao (int pontuacoes[], int tam, float media){
  int i=0;
  float dp=0,soma=0,a=0;
  for (i=0;i<tam;i++){
    a=(pontuacoes[i]-media);
    soma+=pow(a,2);
  }
 
  dp=sqrt(soma/tam);
return dp;
}

int NumeroDeReprovados (int pontuacao[], int tam){
  int cont=0,i;
  for (i=0;i<tam;i++){
    if (pontuacao[i]<70){
      cont++;
    }

  }
  return cont;
}

int NumeroDeAcimaDaMedia ( int pontuacao [],int tam, int media) {
  int cont=0,i=0;
  for (i=0;i<tam;i++){
    if (pontuacao[i]>media){
      cont++;
    }
  }
  return cont;
}

int main (){

  int i=0,participantes=0,maior=0,menor=0,numreprovados=0,acimamedia=0;
  float desviopadrao=0,media=0;

  scanf("%d",&participantes);

  int pontuacao[participantes];

  for(i=0;i<participantes;i++){

    scanf("%d",&pontuacao[i]);

  }
    menor = MenorNota(pontuacao,i);
    maior=MaiorNota(pontuacao,i);
    media=NotaMedia (pontuacao,i);
    desviopadrao=DesvioPadrao(pontuacao,i,media);
    acimamedia=NumeroDeAcimaDaMedia(pontuacao,i,media);
    numreprovados=NumeroDeReprovados(pontuacao,i);

    printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d",maior,menor,media,desviopadrao,acimamedia,numreprovados);
  
     return 0;
}



