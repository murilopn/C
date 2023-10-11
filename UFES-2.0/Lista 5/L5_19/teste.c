#include <stdio.h>

int main (){
    int horas=0,w=0,h=0,i,j,inicio,final;

    scanf("%d",&horas);
    scanf("\n");
    scanf("%d %d",&w,&h);
    scanf("\n");
    int matriz[h][w];

    for (i=0;i<h;i++){

        for (j=0;j<w;j++){
            scanf("%d",&matriz[i][j]);    
                  
        }
     
    }

     for (i=0;i<h;i++){

        for (j=0;j<w;j++){
            printf("%d",matriz[i][j]);          
        }
        printf("\n");
    }

    return 0;
}

