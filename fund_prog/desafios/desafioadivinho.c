#include <stdio.h>

int main () {
    char resp='s';
    int num=10,tam=0,maior=0,menor=0;

    while (tam!=2) {

    printf("Ele é maior(3),igual(2) ou menor(1) que %d? ",num);
    scanf("%d",&tam);    
        
        if (tam==2){
            break; 
        }
        else if(tam==1){//menor
            
            if(maior){
                num+=20;
                maior=0;
            }
            menor=1;
            num/=2;

        }
        else{ //maior
            maior=1;
          if(menor && num-20>0){
                num-=20;
                menor=0;
            }
            
            num*=2;
        }       
    }
    return 0;
}