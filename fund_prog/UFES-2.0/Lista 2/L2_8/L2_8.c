#include <stdio.h>
int main () {

int n=1,m=1,i=3;

scanf ("%d %d",&n,&m);

if(n<1){
n*-1;}

n=n+1;

printf("RESP:");
while (n<m){

if(n==2){
printf("2 ");
n++;
continue;
}
//quando é 3 e 3
if (n==3){
printf("3 ");
n++;
}
//eliminar par logo
if (n%2==0){
n++;
continue;
}

//quando o numero é divisível pelo i, por ex: 6/3
if (n%i==0){
n++;
continue;
}

//quando o número é igual ao divisor
if (n==i){
n++;
continue;
}

//quando não é par
if (n%i!=0){
	i=1;
while (n>i){
    i++;
	if (n%i==0){
	break;
	}
	if (i==n-1){
	printf("%d ",n);
	break;}
	continue;
	
}}

n++;
}
 return 0;
}