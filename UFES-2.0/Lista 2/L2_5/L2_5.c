#include <stdio.h>
#include<math.h>
int main () {
int n=0,k=1;
float pi=0, soma=0, a=0;

	scanf("%d",&n);
	
while (k<=n) {

a=6/pow (k,2); 

soma = soma + a;

k ++;
}

pi = sqrt(soma);

printf("%.6f", pi);

return 0;
}
