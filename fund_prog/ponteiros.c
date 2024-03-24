#include <stdio.h>
//TESTANDO AS DIFERENTES SAÍDAS COM PONTEIRO
int main (){
    int a=0, *pt;

    pt=&a;
    scanf("%d", &a);
    printf("O valor de a: %d\n",a);

    printf("ENDEREÇO DA VARIÁVEL: %p\n",&a);
    printf("ENDEREÇO APONTADO PELO PONTEIRO (mesmo do que o endereço da varíalve): %p\n",pt);
    
    printf("O conteúdo apontado por pt recebe o próprio valor do a: %d\n",*pt);

    printf("ENDEREÇO DO PONTEIRO: %p",&pt);

    *pt=25;
    printf("O conteúdo apontado por pt, ou seja, o a recebe um outro valor (obs: to printando o a): %d\n",a);







    return 0;
}