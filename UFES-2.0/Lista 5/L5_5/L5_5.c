#include <stdio.h>

void Imprime (int posicao){

  printf("RESP:%d",posicao);

}



int AnalisaOsNumeros (int num[],int tam,int numprocurado){
  int i=0,cont=0;

  for (i=0;i<tam;i++){

    if (num[i]==numprocurado){
      Imprime(i);
      cont++;
      break;
    }
  }
  if (cont==0){
    printf("RESP:%d",tam);
  }


}


int main (){
  int numprocurado=0,qntd=0,i=0;

  scanf("%d %d",&numprocurado,&qntd);
 
  int num[qntd];

    for(i=0;i<qntd;i++){

      scanf("%d",&num[i]);

    }

  AnalisaOsNumeros(num,i,numprocurado);


    return 0;
}