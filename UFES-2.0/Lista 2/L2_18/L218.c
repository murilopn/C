#include <stdio.h>
int main (){
int l=0,c=0,maior=0,contL=0,contC=0,num=0,posicaoL=0,posicaoC=0,a=0;

scanf("%d %d",&l,&c);

if (((l>=1) && (l<=100)) && ((c>=1) && (c<=100))){
contL=0;
}

while (contL<l){
contL++;

scanf("%d",&num);
a=num;
if (num>maior){
maior=num;
posicaoL=contL;}

    while (contC<c){
    contC++;
        if (a>maior){
            maior=a;
            posicaoC=contC;}
    break;}
    
}
if (contL){
printf ("%d (%d, %d)", maior,posicaoL,posicaoC);
}
    return 0;
}


