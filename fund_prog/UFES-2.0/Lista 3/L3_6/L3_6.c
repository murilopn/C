#include <stdio.h> 
int EhPalindromo(int num){
int a=0,b=0,inverso=0;
a=num;
b=num;
if ((num<10) && (num>10)){
    return 1;
}else{
while (num!=0){
  a=num%10;
  inverso=inverso*10+a;
  num=num/10;
}
if (inverso==b){
  return 1;
}
else{
  return 0;
}
}}
int main (){
  int num=0,valido=0;
  while(scanf("%d",&num)==1){
   valido=EhPalindromo(num);  
   if (valido){
   printf("S\n");
}
  else{
  printf("N\n");
  }} 
    return 0;     
}