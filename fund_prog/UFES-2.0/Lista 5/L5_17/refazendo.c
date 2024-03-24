#include <stdio.h>
#include <string.h>

int main (){
char palavra[500];
char texto [500][500];
int i=0;
while(scanf("%[A-Za-z]",palavra)==1){

    scanf("%*[^A-Za-z]");

    strcpy(texto[i],palavra);
i++;
}

for (int j=0; j<i; i--){
    printf("%s ",texto[i]);
}

    return 0;
}