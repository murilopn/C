#include <stdio.h>
int main (){
    int preco_gas, preco_alc, km_gas, km_alc;

scanf("%d %d %d %d",&preco_alc,&preco_gas,&km_alc,&km_gas);
    
if (preco_alc==preco_gas){
    printf("Abasteça com gasolina");
}

else if(preco_alc/km_alc<preco_gas/km_gas){
    printf("Abasteça com álcool");
}
else{
    printf("Abasteça com gasolina");
}
    return 0;
}