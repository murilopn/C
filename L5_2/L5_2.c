#include <stdio.h>
int EhDecrescente (int numeros[],int tam){
int i=0,cont=0,a=0;
i=tam-1;
a=tam-1;

  for (tam=0;i>tam;i--){
    if ((numeros[i]<numeros[i-1]) || (numeros[i]==numeros[i-1])){
      cont++;
    }
  }
  if(cont==a){
  return 1;
}
  else{
    return 0;
  }
}

int EhCrescente (int numeros[],int tam){
int i=0,cont=0;
  for (i=0;i<tam;i++){
     
    if (i==tam-1){
        break;
    }
    else if ((numeros[i]<numeros[i+1]) || (numeros[i]==numeros[i+1])){
      cont++;
    }
  }
  if(cont==i){
  return 1;
}
else{
  return 0;
}
}

int main (){
  int quant=0,i=0,decrescente=0,crescente=0;
  

scanf("%d",&quant);

int numeros[quant];

for (i=0;i<quant;i++){
  scanf("%d",&numeros[i]);
  }

 decrescente=EhDecrescente (numeros,i);
 crescente=EhCrescente(numeros,i);

if (((decrescente) && (crescente)) || (quant==1)){
  printf("CRESCENTE&DECRESCENTE");
}
else if ((crescente) && (decrescente==0)){
  printf("CRESCENTE");
}
else if ((decrescente) && (crescente==0)){
  printf("DECRESCENTE");
}
else {
  printf("DESORDENADO");
}
    return 0;
}