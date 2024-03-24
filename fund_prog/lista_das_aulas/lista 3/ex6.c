#include <stdio.h>
int main (){
    float x,y;
    scanf("%f %f",&x,&y);

    if (x==0 && y==0){
        printf("Origem");
    }
    
    else if (x==0){
        printf("Eixo y");
    }

    else{
        if (x>0){ //quer dizer que pode ser Q1 e Q4

            if(y>0){
                printf("Quadrante 1");
            }
            else if(y<0){
                printf("Quadrante 4");
            }
            else{
                printf("Eixo x");
            }
        }

        else if(x<0){ //quer dizer que pode ser Q2 e Q3

            if(y>0){
                printf("Quadrante 2");
            }
            else if(y<0){
                printf("Quadrante 3");
            }
            else{
                printf("Eixo x");
            }

            }
    }

    return 0;
}