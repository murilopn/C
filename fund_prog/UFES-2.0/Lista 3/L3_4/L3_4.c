#include <stdio.h> 

   int Primo (int n, int m){
    int cont=2,i=0,multiplos=1,contM=2;
    for (i=n+1; i<m ;i++){
        cont=2;

        while (i>cont){
        if (i%cont==0){
            break;        
        }
        cont++;
        }
        if (i==cont){  //os primos saem daqui
        printf("%d\n",i);
        contM=2;
        multiplos=1;
            if(i*2>=m){
            printf("*\n");
            multiplos=32000; //anulando as possibilidades de imprimir multiplos maiores que m
            }
                while (contM<m){
                if (multiplos<m-i){
                    multiplos=i*contM;
                    printf("%d ",multiplos);
                        contM++;
                }    
                if (multiplos>=m-i && contM!=2){
                        printf("\n");
                }
                if (multiplos>=m-i){
                    break;}
    }}}}
int main (){
    int n=0,m=0,i=0;
    scanf("%d %d",&n,&m);   //subprograma para as entradas (somente)
    i=Primo (n,m); 
    return 0;     
}