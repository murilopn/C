#include <stdio.h>
int main () {
	int  num=0,i=2;
	scanf ("%d",&num);
if (num<0)
num= num *-1; 

if (num==3){
printf("Primo");
}
if (num==2){
printf("Primo");
}
if(num==1){
printf("Nao primo");
}
if(num==0){
printf("Nao primo");
}
if (num==4){
	printf("Nao primo");}
	
if (num>3 && num!=4){
while (i<100000){
i++;
if (num<i){
	printf("Primo");
break;}
if (!(num%i)) {
	if (num==i){
	continue;

}	else{
	printf("Nao primo");
	break;
	}
}
continue;	
}
}


return 0;
}