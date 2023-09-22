#include <stdio.h>
int main (){
    int hora1,hora2;
    scanf("%d %d",&hora1, &hora2);

    if(hora1==hora2){
        printf("O jogo durou 24 horas");
    }
    
    else if (hora1>hora2){
        hora2+=24;
        printf("O jogo durou %d horas",(hora1-hora2)*-1);
    }
    else{
        printf("O jogo durou %d horas",hora2-hora1);
    }

    return 0;
}