#include <stdio.h>
#define N 5
int main (){
    char matriz1 [N][N];
    char matriz2 [N][N];
    int s=0,h=4,i=0,j=0,g=0,z=0,a=0;
    
    for (i=0; i<N; i++){
        for (j=s; j<N; j++){
            matriz1[i][j]='A'+j;
        }
        s++;
    }
    i=0;
    j=0;
    for (g=0; g<N; g++){
    
        for (z=h; z>=0; z--){
            matriz2[g][z]=matriz1[i][j];
            j++;
        }
        j=0;
        h--;
        i++;

    }
    s=0;
      for (int w=0; w<N; w++){
        for (int l=s; l<N; l++){
            printf("%c",matriz2[w][l]);
        }
        printf("\n");
        s++;
    }



    return 0;
}