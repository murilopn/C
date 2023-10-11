#include <stdio.h>

int  InverteOsNumeros(int numeros [],int tam){
  int i=0;
  printf ("{");
 for (i=tam-1;i>=0;i--){

   if (i-1==-1){
    printf("%d",numeros[i]);
   }   
   else{
   printf("%d, ",numeros[i]);
   }
      
  }
  printf("}");
}

int main (){
    int qntd=0,i=0;

    scanf("%d",&qntd);
    if (qntd==0){
      printf ("{}");
    }

      else {
    int numeros [qntd];

    for (i=0;i<qntd;i++){
      scanf("%d",&numeros[i]);

    }

  InverteOsNumeros(numeros,i);
    
    
      }
    return 0;
}