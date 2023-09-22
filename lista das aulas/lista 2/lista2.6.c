#include <stdio.h>
int main (){
    int seg=0,dias=0,horas=0,minutos=0,segundos=0;

    scanf("%d",&seg);

    dias=seg/86400;
    horas=(seg-86400*dias)/3600;
    minutos=(seg-86400*dias-3600*horas)/60;
    segundos=seg-86400*dias-3600*horas-minutos*60;


    printf("%d segundos correspondem a %d dia, %d horas, %d minutos e %d segundos",
            seg,dias,horas,minutos,segundos);

    return 0;
}