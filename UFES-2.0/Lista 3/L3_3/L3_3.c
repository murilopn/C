#include <stdio.h> 

int Primo (int n, int m){
    int cont=2,i=0;
    for (i=n+1; i<m ;i++){
        cont=2;

        while (i>cont){
        if (i%cont==0){
            break;        
        }
        cont++;
        }
        if (i==cont){
        printf("%d ",i);

    }}}
int main (){
    int n=0,m=0,i=0;
    scanf("%d %d",&n,&m);
    i=Primo (n,m);
    return 0;     
}