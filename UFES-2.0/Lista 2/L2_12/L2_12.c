#include <stdio.h>
int main (){
    char nome=0;
    int a=0;
while (scanf("%c",&nome)==1){
  if(a==0){
  printf("RESP:");}

a = (int) nome;

    if (a==32){
    printf("_");
    continue;}

printf("%c",nome);
    
if (a==46|| a==33 ||a==63){
    break;}
}
    return 0;
}