#include <stdio.h>
int main()
{
    printf ("%f\n", 3.539);
    printf ("%.0f\n", 3.539);
    printf ("%.1f\n", 3.539);
    printf ("%.2f\n", 3.539);
    printf ("%.3f\n", 3.539);
    printf ("%.4f\n", 3.539);
    printf ("%.5f\n", 3.539);
    return 0;
}
/* o Printf formata a saída para ter a quantidade desejada de números, por ex:
se ele coloca .5f, vai aparecer 5 dígitos, independentemente.
*/