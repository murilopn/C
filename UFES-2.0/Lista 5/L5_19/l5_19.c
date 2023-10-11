#include <stdio.h>

void Imprime(int inicio,int final){
    printf("%d %d",inicio,final);
}

int ImagensDepoisDoTempo(int h,int w,int matriz[h][w],int horas){
 int i,j,cont=0;

    for (i=1;i<h;i++){ //obs: sempre tem água na borda!

        for (j=1;j<w;j++){ //obs: sempre tem água na borda!
           
        if (matriz[i][j]==0){

            if (matriz[i-1][j]==0){ //p ver em cima

                if(matriz[i+i][j]==0){ //p ver em baixo

                    if (matriz[i][j-1]==0){ //p ver no lado esquerdo

                        if (matriz [i][j+1]==0){//p ver no lado direito
                            cont++;
                        }
                    }
                }
            }
        }

      }
    }
        return cont;
 }


 int ImagensNaHoraDaFoto(int h,int w,int matriz[h][w]){
    int i,j,cont=0;

    for (i=0;i<h;i++){

        for (j=0;j<w;j++){
            if (matriz[i][j]==0){
                cont++;
            }
        }
    }

    return cont;
 }


int main (){
    int horas=0,w=0,h=0,i,j,inicio,final;

    scanf("%d",&horas);
    
    scanf("%d %d",&w,&h);
    
    int matriz[h][w];

    for (i=0;i<h;i++){

        for (j=0;j<w;j++){
            scanf("%d",&matriz[i][j]);   
            printf("%d",matriz[i][j]);
        }
       
        printf("\n");
      
     
    }

    inicio=ImagensNaHoraDaFoto(h,w,matriz);
    final=ImagensDepoisDoTempo(h,w,matriz,horas);
    Imprime(inicio,final);



    return 0;
}

