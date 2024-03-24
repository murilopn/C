#include <stdio.h>

void Imprime (int armazena [],int tam){
  int i=0,cont=0;
  for (i=0;tam>i;i++){
    if (armazena [i]==armazena[i+1]){
      cont++;
}
  }
  if(cont==i || cont+1==i){
    printf("RESP:%d",armazena[0]);
  }
  else {
    printf("NAO");
  }

}

 int AnalisaProgressaoAritmetica(int numeros[],int tam){
  int comeco=0,final=0,i=0;
  int armazena[tam-1];

for (i=0;i<tam-1;i++){
  comeco=numeros[i];
  final=numeros[i+1];
  
      armazena[i]=final-comeco;
}

  Imprime (armazena,i);

 }

int main (){
  int qntd=0,i=0;

  scanf("%d",&qntd);
  if (qntd==1){
    printf("NAO");
  }
  else {
  int numeros[qntd];
    for (i=0;qntd>i;i++){

      scanf("%d",&numeros[i]);

    }
  AnalisaProgressaoAritmetica(numeros,i);
 
  }
    return 0;
}