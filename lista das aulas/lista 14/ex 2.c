#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
int main (){
    srand(time(NULL));
    char flu [N];
    int pos=0,aux=0,i=0,tam=0;       
    
    for (i=0; i<N; i++){
        scanf("%c",&flu[i]);
    }    
    printf("%s\n",flu);                         

    scanf("%d",&pos );

    for (i=0; i<N; i++){

        if (i==pos-1){
            aux=flu[0]; 
            flu[0]=flu[i]; 
            i=1;
             for (int j=1; j<N; j++){
                
                if (j==pos-1){
                    flu[j]=aux;
                }
                else{
                    flu[j]=flu[i];
                }
                    i++;
             }
          i=pos;
        }    
    }
     for (int j=1; j<N; j++){
                
                printf("%c",flu[j]);

         }











    return 0;
}