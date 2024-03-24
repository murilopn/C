#include <stdio.h>
int main () {

char frasefora=0,contparfora=0,contpardentro=0,frasedentro=0,a=1,b=0,parenteses=1,parentesesfora=1;


while (1){
scanf ("%c",&frasefora);

if (b==0){
printf("RESP:");
b=1;
}

if (frasefora==')'){
contparfora++;
}

if ((frasefora=='(') || (a==frasedentro)){
   a=frasedentro;
   contpardentro++;
    if((frasefora=='(') && (parenteses)){
        parenteses=0;
        continue;
    }    

if ((contparfora==contpardentro) && (frasefora==')')){
break;
}

printf("%c",frasefora);
}
}
    return 0;
}