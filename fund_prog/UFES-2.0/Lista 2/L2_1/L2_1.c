#include <stdio.h>
int main () {

	int n=0, m=1,a=0;

	scanf ("%d %d", &n, &m);
a=n;
if (n<m) {
if (!(n%2)){
	n=n+2;
	printf("RESP:");
	while (n<m) {
	printf("%d ",n); 
	n = n +2;
	}
} else{
	n=n+1;
	printf("RESP:");
	while (n<m) {
	printf("%d ",n);
	n= n +2;
} }
}
if (a>=m) {
	printf("RESP:");
}
return 0;
}
