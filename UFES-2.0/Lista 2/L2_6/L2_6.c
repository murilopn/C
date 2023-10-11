#include <stdio.h>
#include<math.h>
int main () {
int s=1;
double total=0,divisao=1,den=1,num=1,expo=0;

scanf ("%d",&s);

if (s==1) {
while (den<=50){

divisao=num/den;
total = total + divisao;
den ++;
num = num+2;
}
printf("%.6f",total);
}	
if (s==2){
 den=50;
	while (den>=1){
expo = expo + 1;
num = pow (2,expo);
divisao = num/den;
total = total + divisao;
den--;

}
printf("%.6f",total);
}
num=1;
if (s==3){
while (num<=10){

divisao = num/den;
total = divisao + total;

num++;
den = pow (num,2);
}

printf ("%.6f",total);
}
	return 0;
}




