#include <stdio.h>
#define N 4

int main (){
    int i=0,j=0,matriz[N][N],cont=1;

    
    for (int s=0; s<N; s++){
        for (int z=0; z<N; z++){
            matriz[s][z]=0;
        }
    }

            matriz[i][j]=cont;
            cont++;

        for (int j=1; j<N; j++){
            matriz[i][j]=cont;
            cont++;
            if (j==N-1){
                i++;

                while (i<N){
                    matriz[i][j]=cont;
                    cont++;
                    i++;
                }
                i--;
                j--;
                while (j>0){
                    matriz[i][j]=cont;
                    cont++;
                    j--;
                }
                
            }

            if (j==0){
                while (i!=1){
                    matriz[i][j]=cont;
                    cont++;
                    i--;
                }

                while (j<N-1){
                    matriz[i][j]=cont;
                    cont++;
                    j++;
                } 
                j--;
                while(i<N-2){
                    i++;

                    matriz[i][j]=cont;
                    cont++;
                }
                //j--;
                printf("valor de i:%d\n",i);
                printf("valor de j:%d\n",j);
                while (j!=1){

                    j--;
                    matriz[i][j]=cont;
                    cont++;
                }
                
                break;   

            }

    }

      for (int a=0; a<N; a++){
        for (int b=0; b<N; b++){
            printf("%d ",matriz[a][b]);
        }
        printf("\n");
    }





    return 0;
}