#include <stdio.h>
int main () {

    int maior=1, i=1, soma=0;
    float media=1,qntd=1;

    while (i!=0) {
        scanf ("%d",&i);
    if (i==0)
        break;
    if (i>maior){
    maior = i;
}
    
    soma = soma + i;
    media = soma /qntd;
     printf ("%d %.6f\n", maior, media);

    qntd++;
   
}
    return 0;
}