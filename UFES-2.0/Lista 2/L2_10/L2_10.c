#include <stdio.h>
int main (){

int n=0,m=0,i=1,multiplicacao=1;

scanf ("%d %d",&n,&m);

while (n<=m){

for(i=1;i<=10;i++){
multiplicacao=n*i;

printf ("%d x %d = %d\n",n,i,multiplicacao);
continue;
}
n++;
}
	return 0;
}