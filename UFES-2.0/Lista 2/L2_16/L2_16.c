#include <stdio.h>
int main () {

int menor=32000,num1=0,a=0;
int num2=0,p=0,aparece1=0,p1=32000;
char c=0;

while (scanf("%d",&num1)==1){
if (num1<menor){
menor=num1;}
}
scanf("%*c");
//limpar o buffer antes de entrar aqui.

while (scanf("%d",&num2)==1){
p++;

if(num2==menor){
aparece1=p;

if(p1>aparece1)
p1=aparece1;
}
}
if (aparece1==0){
printf("%d %d %d",menor,p,p);}
else{
printf("%d %d %d",menor,p1-1,aparece1-1);
}
    return 0;
}
