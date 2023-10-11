#include <stdio.h>
int main () {
int num=0,ordem=0,final=0,novo=0,velho=0;
char letras=0,n=0;
scanf("%d %d",&num,&ordem);

scanf("%*c");


while(scanf("%c",&n)==1){

if (num!=2 && num!=1){
printf("Operacao invalida.");
break;}

if (n=='.'){
    printf(".");
break;}

if (n>=97 && n<=122){
    
    final=ordem%26;
    novo=n+final;
    velho=n-final;
        
    if (num==1){//codificar
    if (n+final>122){
        novo= n+final-122+96;}

        printf ("%c",novo);}

    if(num==2){//decodificar
    if (n-final<97){
        velho=n-final-97+123;}

        printf ("%c",velho);}
}

else{
    printf("%c",n);
}}

    return 0;
}

