#include <stdio.h>

void Imprime(int dentro, int fora){

  printf("%d %d",dentro,fora);

}

int AnalisarOsNumerosDoIntervalo(int numeros[],int tam,int inicio ,int fim){
  int contfora=0,contdentro=0,i=0;

while (tam>i){
if (numeros[i]>fim){
contfora++;
}
else if (numeros[i]<inicio){
  contfora++;
}
else if (inicio<numeros[i]<fim){
    contdentro++;
}
i++;
}
    Imprime(contdentro,contfora);    
}    

int main (){
 
  int a=0,b=0,n=0,i=0,
      contfora=0,contdentro=0;

  scanf("%d",&n);

  int numeros[n];

  for (i=0;i<n;i++){

    scanf("%d",&numeros[i]);
  }

  scanf("%d %d",&a,&b);

  AnalisarOsNumerosDoIntervalo(numeros,i,a,b);
  
    return 0;
}