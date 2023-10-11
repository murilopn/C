#include <stdio.h> 

typedef struct {
    int codigo;
    float preco;
    int qntd;

} tProdutos;

int main (){
    tProdutos itens;
    int numprod=0,cont=0,validar=0,flagsair=0;
    int codigoma=0,qntdma=0,qntdme=0,codigome=0;
    float maior=-32000,menor=320000;
    scanf("%d",&numprod);

    while(1){
     while (1){
        cont ++;
    scanf("%d;%f;%d",&itens.codigo,&itens.preco,&itens.qntd);

        if (itens.preco>maior){
            maior=itens.preco;
            codigoma=itens.codigo;
            qntdma=itens.qntd;
        }

        if (itens.preco<menor){
            menor=itens.preco;
            codigome=itens.codigo;
            qntdme=itens.qntd;
        }
         if (itens.qntd==0){
        printf("FALTA:COD %d, PRE %.2f, QTD %d\n",itens.codigo,itens.preco,itens.qntd);
         if (numprod==1){
            printf("MAIOR:COD %d, PRE %.2f, QTD %d\n",codigoma,maior,qntdma);
            printf("MENOR:COD %d, PRE %.2f, QTD %d",codigome,menor,qntdme);
         flagsair=1;
         break;
         }}
    
        if (cont>=numprod){
            printf("MAIOR:COD %d, PRE %.2f, QTD %d\n",codigoma,maior,qntdma);
            printf("MENOR:COD %d, PRE %.2f, QTD %d",codigome,menor,qntdme);
            flagsair=1;
            break;


}}
 if (flagsair){
    break;
}}
     
    return 0;
}