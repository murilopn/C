#include <stdio.h> 

int IdentificacaoPalindromo (int num){
int p=0,digito=0,dividendo=1,primeiro=0,ultimo=0;

if (num<10){
return 1;
}
else {
    while (dividendo>0)
    dividendo=dividendo*10;
primeiro= num/dividendo;
ultimo= num%dividendo;
    while (dividendo!=10)
    dividendo++;






}
}
int main (){
    int num=0,i=0;
   while (scanf("%d",&num))
   i=IdentificacaoPalindromo(num);
    if (i){
        printf("S");
    }
    else{
        printf("N");
    }
    return 0;     
}