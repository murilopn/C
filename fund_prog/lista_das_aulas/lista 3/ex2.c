#include <stdio.h>
int main(){
    int num,novo_c,novo_d,novo_u;
    scanf("%d",&num);

    
    novo_c=num%100;//vou pegar o último
    novo_c%=10;
    novo_d=num%100;
    novo_d/=10;
    novo_u=num/100;

    printf("%d%d%d",novo_c,novo_d,novo_u);
    







    return 0;
}