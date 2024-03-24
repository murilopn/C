#include <stdio.h>

void ComparaAB(int seq1[],int seq2[],int qntd1,int qntd2){
    int i=0,j=0,aux=0;
    while (i+j<qntd1+qntd2){

         if(j==qntd2 && i<qntd1){
            printf("A");
            i++;
         }
         else if (i==qntd1 && j<qntd2){
            printf("B");
            j++;
         }       
         else if(seq1[i]>seq2[j]){
                printf("B");
                j++;
            }
            else{
               printf("A");
                i++;
            }
    
}
}

void Ordena(int seq[],int qntd){
    int i,j,aux=0;

    for (i=0;i<qntd;i++){
        for (j=i+1;j<qntd;j++){
            
            if(seq[i]>seq[j]){
                aux=seq[i];
                seq[i]=seq[j];
                seq[j]=aux;
            }
      }
    }
}

int main (){
    int qntd1,qntd2,i;

    scanf("%d",&qntd1);
    
        int seq1[qntd1];

        for (i=0;i<qntd1;i++){
            scanf("%d",&seq1[i]);
        } 

    scanf("%d",&qntd2);
     
        int seq2[qntd2];

        for (i=0;i<qntd2;i++){
        scanf("%d",&seq2[i]);
    }

    Ordena(seq1,qntd1);
    Ordena(seq2,qntd2);
    ComparaAB(seq1,seq2,qntd1,qntd2);//os vetores já chegam aqui ordenados.
    return 0;
}