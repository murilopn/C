#include <stdio.h>

int EhPar(int x){

    if (!(x%2)){
        return 1;
    }
    else{
         return 0;
    }
}
void PrintaPares (int N){
    printf("%d ",N);

}
void PrintasImpares(int N){
    printf("%d ",N);

}
int main (){
    int num=0,analise=0,qntd=0,cont=0;

    scanf("%d %d",&num,&qntd);
    analise=EhPar(num);

    while (qntd>cont){

   if (analise){
    num=num+2;
    PrintaPares(num);
   }
   else {
    PrintasImpares(num);
    num=num+2;
   }
    cont++;
    }

    return 0;
}