#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFLEN 1024

char* concatenaStrings (char* s1, char* s2){
    char *v;
    int i=0,tam1,tam2,j=0;

    tam1=strlen(s1);
    tam2=strlen(s2);
    v=(char*) malloc((tam1+tam2+1)*sizeof(char));

    for (i=0;i<tam1;i++){
        v[i]=s1[i];
    }
    i-=1;
    for (j=0;j<tam2;j++){
        v[i]=s2[j];
        i++;
    }

    i++;
    v[i]='\0';
    return v;

}

int main (){
    char *p;
    int s=0;
    char string1 [BUFLEN];
    char string2 [BUFLEN];

fgets (string1, BUFLEN, stdin);
fgets (string2, BUFLEN, stdin);

p = concatenaStrings (string1,string2);
printf("%s",p);




    return 0;
}
