#include <stdio.h>
int main () {

int qntd=0,i=1,a=1,maior=1, menor=10000000, impar=0 , par =0;
float media=1,soma=0;

	scanf("%d", &qntd);

while (i<=qntd) {
	scanf("%d",&i);
	
	soma = soma + i;

	if (i>maior) {
	maior = i ;
	}
	if (i<menor) {
	menor = i;
	}

	media = soma/qntd; 	

	if (!(i%2)) {
		par = par + 1;

}	else {
		impar = impar + 1;
	}

	a++;
	i=a;
}

printf ("%d %d %d %d %.6f", maior, menor, par, impar, media);


return 0;	
}