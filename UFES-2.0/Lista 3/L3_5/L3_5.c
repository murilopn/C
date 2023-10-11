#include <stdio.h> 

int CalculodaPropriedade (int n,int m){
int a=0,b=0,c=0,d=0,e=0,f=0,validacao=0;

while (m>n){

a=n/1000;        //aplicar o cálculo da propriedade
b=n%1000/100;
c=(n%1000/10)%10;
d= ((n%100) %100) %10;
e=a*10+b;
f=c*10+d;
validacao=(e+f)*(e+f);

if (validacao== n){
return 1;
}
else{
return 0;
}}}

int main (int m, int n) {
int i=0;    

scanf ("%d %d",&n,&m);
while (m>n){
    n++;
    i=CalculodaPropriedade (n,m);
    if (i && n!=m)
        printf ("%d\n",n);
}
    return 0;     //receber os números e imprimir,caso vdd
}
