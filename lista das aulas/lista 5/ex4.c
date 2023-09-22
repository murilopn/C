#include <stdio.h>
int main (){
    int entrada=0;

    scanf("%d",&entrada);

    if (entrada & 0x01){ //se o final for 1, vai ser ímpar
        printf("Impar");
    }
    else{
        printf("par");
    }
// Eu coloco o 0x01, pq ele vai ser 0000 0001







    return 0;
}