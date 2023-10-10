#include <stdio.h>
void ImprimeVetor (int cont){
  printf("(%d %d) ",cont,cont+1);
}

int ComparaVetor (int vet[],int qntd){
  int i,j,pos=0,comparacao=-1;;
  int dif[qntd-1];

  for (i=0;i<qntd;i++){

  if (i+1<qntd){
      dif[i]=vet[i+1]-vet[i];

          if (dif[i]<0){
            dif[i]*=-1;
        }

          if (dif[i]>comparacao){
           pos=i;
           comparacao=dif[i];
        }        
  }
  }
  printf(" ");
  ImprimeVetor (pos);

  for (i=0;i<qntd-1;i++){ //para imprimir os de mesma diferença
    if (dif[i]==comparacao && i!=pos){
        ImprimeVetor (i);
    }
  }

}

int main (){
  int qntd=0,i;
  scanf("%d",&qntd);
  int vet [qntd];
  if(qntd<=1){
    printf("IMPOSSIVEL");
  }
  else {
  for (i=0;i<qntd;i++){
    scanf("%d",&vet[i]);
  }
  ComparaVetor(vet,qntd);
  }
    return 0;
}