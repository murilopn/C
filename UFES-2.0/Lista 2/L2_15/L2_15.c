#include <stdio.h>
int main () {

int num=0,contNeg=0,somaNeg=0,contPos=0,somaPos=0;

while (scanf("%d",&num)==1){

if (-100>num>100){
break;}

if (num<0){
contNeg++;
somaNeg=somaNeg+num;
}

if (num>0){
contPos++; 
somaPos=somaPos+num;   
}
}

printf("%d %d %d %d",contNeg,contPos,somaNeg,somaPos);
    return 0;
}