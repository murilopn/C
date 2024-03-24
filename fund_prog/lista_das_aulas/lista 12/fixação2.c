#include <stdio.h>
int main (){
    int a=20,*p;
    p=&a;
    printf("VALOR DA VARIÁVEL: %d\n",a);
    printf("ENDEREÇO DA VARIÁVEL: %p\n",&a);
    printf("ENDEREÇO APONTADO PELO PONTEIRO: %p\n",p);
    printf("VALOR APONTADO PELO PONTEIRO: %d\n",*p);
    printf("ENDEREÇO DO PONTEIRO: %p",&p);

    return 0;
}
/*CONCLUSÃO:

    - Para printar o endereço da variável por ela mesma, basta colocar um "&" no print
    - O endereço da variável apontado pelo ponteiro é o próprio conteúdo dele, por isso não se deve colocar * no print   



*/