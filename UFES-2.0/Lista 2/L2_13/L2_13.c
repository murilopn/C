#include <stdio.h>
#include <ctype.h>
int main () {
int a=0;
char nome=0;
while (scanf("%c",&nome)==1){

a=(int) nome;

printf("%c",toupper(nome));

if (a==46||a==33||a==63){
break;}

}
    return 0;
}