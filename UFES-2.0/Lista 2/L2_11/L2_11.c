#include <stdio.h>
int main (){

int ab=0,cd=0,ef=0,abcd=0,num1=0,num2=0,final=0;

scanf ("%d %d",&num1,&num2);

abcd=num1;

if ((1000<num1 && num1<9999) && (1000<num2 && num2<9999) && (num1<num2)){

while (num1<num2){

ab=num1/100;
cd=num1%100;
ef = ab+cd;
final=ef*ef;

if (abcd==final){
printf ("%d\n",abcd);
}
num1++;
abcd = abcd+1;

}}
return 0;
}