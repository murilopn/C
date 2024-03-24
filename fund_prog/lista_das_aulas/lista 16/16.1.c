#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFLEN 1024

char* empacotaString (char* string){

    char *v;
    int tam=0,i=0;

    tam=strlen(string);
        v = (char *) malloc ((tam +1)* sizeof(char));
        for (i=0; i<tam; i++){
            v[i]=string[i];
        }
        v[i]='\0';

    return v;

}
int main (){
    char *p;
    int s=0;

char buffer [BUFLEN];
fgets (buffer, BUFLEN, stdin);
p = empacotaString (buffer);
s=strlen(p);
printf("%s",p);
printf("%d",s-1);
free(p);

    return 0;
}
/*Eu coloco o tamanho do malloc como tam+1, pois o strlen retorna o índice do /0, ou seja,
na string "oi\0", ele retorna 2. Na hora do malloc, ele vai declarar o tamanho da string como 2, mas o tamanho
é 3, por causa do /0, por isso tem q colocar +1.

Eu coloco v[i]='\0', pois eu tenho 
*/