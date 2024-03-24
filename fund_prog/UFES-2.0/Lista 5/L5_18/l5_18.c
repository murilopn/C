#include <stdio.h>

  void  Imprime (int c, int lin,int l,int col,int matrizf[l][col]){
    int i=0,j=0,mat=0;

    if (c!=lin){
        printf("IMPOSSIVEL\n");
    }
    else {
    for (i=0;i<l;i++){
        mat= matrizf[i][j];

        for (j=0;j<col;j++){

            if (j==col-1){
                printf("%d",matrizf[i][j]);
            }
            else{
            printf ("%d ",matrizf[i][j]);
        }   }
        printf("\n");
    }

  }  
  }

 void MultiplicaMatriz(int l,int c,int col,int lin,int matriz1[l][c],int matriz2[lin][col],int matrizf[l][col]){
    int a=0,soma=0,i=0,j=0,s=0,z=0;
    while (a<l*col){

        while (s<lin){
            soma+= (matriz1[i][j]*matriz2[s][z]);   
                s++;
                j++;
        }
        matrizf[i][z]=soma;

    z++;
    j=0;
    s=0;  
    soma=0;
    a++;
    if (z==col){
        i++;
        z=0;
    }
}
 }    

int LeMatriz2 (int lin, int col, int matriz2 [lin][col]){
    int i,j;

    for (i=0;i<lin;i++){
       
        for (j=0;j<col;j++){
            scanf("%d",&matriz2[i][j]);
        }
    }
}
int LeMatriz1 (int l,int c, int matriz1 [l][c]){
    int i,j;
   
     for (i=0;i<l;i++){
        
        for (j=0;j<c;j++){
            scanf("%d",&matriz1[i][j]);
        }
      } 
    }


int main (){
    int numpares=0,tam=0,l=0,c=0,lin=0,col=0;

    scanf("%d",&numpares);

    while (numpares>tam){

     scanf("%d %d",&c,&l); //matriz 1


    int matriz1[l][c]; 

    LeMatriz1 (l,c,matriz1);
 

    scanf("%d %d",&col,&lin); //matriz 2

    int matriz2[lin][col];

    LeMatriz2 (lin,col,matriz2);

    int matrizf[l][col]; 

     MultiplicaMatriz(l,c,col,lin,matriz1,matriz2,matrizf);

     Imprime (c,lin,l,col,matrizf);
     printf("\n");

        tam++;
    }
    return 0;
}

