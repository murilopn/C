#include <stdio.h>
int main ()
{
    float x1 = 5.0, x2 = 2.0;
    int x3;
    printf ("%f\n", x1 % x2); //RESTO DA DIVISÃO DE INTEIROS COM NÚMEROS FLOAT
    printf ("%f\n", &x1); //POSSUI & EM PRINTF
    x1 = x2 //NÃO POSSUI PONTO VÍRGULA
    printf ("%d\n", x3); //VAI PRINTAR LIXO(é esse o erro?)
    X2 = 10;//É FLOAT E TÁ ATRIBUINDO INT
    x1 + 10.0; // NÃO ESTÁ JOGANDO A SOMA PARA LUGAR ALGUM
    x3 = 039; // O 9 NÃO ESTÁ PRESENTE NA BASE OCTAL (SE FOSSE 037 DARIA CERTO)
    return 0;

}