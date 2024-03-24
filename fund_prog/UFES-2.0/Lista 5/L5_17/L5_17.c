#include <stdio.h>

int main(){

    char matriz[500][501];
    int letra = 0,i=0;

         while (scanf("%500[A-Za-z]", matriz[i])==1){

            scanf("%*[^A-Za-z]");
            i++;
    }

    
    for (;i>=0;i--){
        printf("%s ", matriz[i]);
    }

    return 0;
}