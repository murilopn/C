#include <stdio.h>
#define N 80
int main (){
    char flu [N];       
    char gaba [N];
    int tam=0,cont=0;

    scanf("%d",&tam);

   
        scanf("%s",gaba);
        scanf("%s",flu);    


    for (int i=0; i<tam; i++){
        if (flu[i]==gaba[i]){
            cont++;
        }
    }

    printf("%d",cont);










    return 0;
}