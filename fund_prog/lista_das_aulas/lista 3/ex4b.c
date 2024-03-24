#include <stdio.h>
int main (){
    int hora1,hora2,min1,min2;
    scanf("%d:%02d %d:%02d",&hora1,&min1,&hora2,&min2);

    if(hora1==hora2){
        if (min1==min2){
            printf("O jogo durou 24 horas");
        }
        else if (min1>min2){
            printf("O jogo durou %d minutos",min1-min2);
        }
        else{
            printf ("O jogo durou %d minutos",min2-min1);
        }
    }
    
    else if (hora1>hora2){
        hora2+=24;
        if (min1==min2){
            printf("O jogo durou %d horas",hora1-hora2);
        }
        else if (min1>min2){
            printf("O jogo durou %d horas e %d minutos",hora1-hora2,min1-min2);
        }
        else{
            printf ("O jogo durou %d horas e %d minutos",hora1-hora2,min2-min1);
        }
    }
    
    else{
         if (min1==min2){
            printf("O jogo durou %d horas",hora2-hora1);
        }
        else if (min1>min2){
            printf("O jogo durou %d horas e %d minutos",hora2-hora1,min1-min2);
        }
        else{
            printf ("O jogo durou %d horas e %d minutos",hora2-hora1,min2-min1);
        }
    }

    return 0;
}

