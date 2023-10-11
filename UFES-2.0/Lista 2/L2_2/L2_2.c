#include <stdio.h>
int main () {
    int limite1=0, limite2=0, multiplos=0;
    scanf ("%d %d",&limite1, &limite2);

    for (multiplos=limite1+1; multiplos<limite2; multiplos++)
        if (!(multiplos%3)) {
            printf ("%d ",multiplos);
    }   else {
            if (!(multiplos%4)){
                printf("%d ",multiplos);
    }   else { 
            if (!(multiplos%7)) {
                printf("%d ", multiplos);
            }}} 
return 0;
}