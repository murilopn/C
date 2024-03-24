#include <stdio.h>
int main (){

int cont=0,contMult=0, n=0,m=0,den=0,multiplo=0,i=2;

scanf("%d %d",&n,&m);
n++;
while (m>n){
den=1;
cont=0;
contMult=0;
while (den<=n){

if (!(n%den)){
cont++;}
den++;

}

if (cont==2){
printf ("%d\n",n);

multiplo=n*2;
i=2;
while(multiplo<m){
multiplo=n*i;
i++;
if (multiplo<m){
printf("%d ",multiplo);
contMult++;}}

if (contMult!=0){
printf("\n");}
else{
printf ("*\n");}}

n++;
}
return 0;
}
