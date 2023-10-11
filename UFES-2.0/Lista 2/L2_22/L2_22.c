#include <stdio.h>
int main () {
int num=0, unidade=0, dezena=0, centena=0,milhar=0,dezenamilhar=0, soma=32000;

scanf("%d",&num);

if (num<10)
printf("RESP:%d",num);

if ((num>=10) && (num<100)){

    while (soma>=10){
    dezena=num/10;
    unidade=num%10;
    soma=dezena+unidade;
    num=soma;
}
printf("RESP:%d",soma);
}

if ((num>=100) && (num<1000)){

    while (soma>=10){
    centena=num/100;
    dezena=num%100/10;
    unidade= num%100 %10;
    soma=centena+dezena+unidade;
    num=soma;
}
printf("RESP:%d",soma);
}
if ((num>=1000) && (num<10000)){

    while (soma>=10){
    milhar=num/1000;
    centena=num/100 %10;
    dezena=num/10 %100 %10;
    unidade= num%1000 %100 %10;
    soma = milhar + centena + dezena + unidade;
    num=soma;
}
printf("RESP:%d",soma);
}
if ((num>=10000) && (num<100000)){

    while (soma>=10){
    dezenamilhar=num/10000;
    milhar=num/1000 %10;   
    centena=num/100 %10;
    dezena=num/10 %10;
    unidade=num%10000 %1000 %100 %10; 
    soma=dezenamilhar+milhar+centena+dezena+unidade;
    num=soma;
}
printf("RESP:%d",soma);
}



    return 0;
}