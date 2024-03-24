#include <stdio.h>
int main (){
    int x1,x2,x3,x4,x5,media=0;

    scanf("%d %d %d %d %d",&x1,&x2,&x3,&x4,&x5);

    media=(x1+x2)/2.0;
    printf("%.1f\n",media);
    media=(x1+x2+x3)/3.0;
    printf("%.1f\n",media);
    media=(x1+x2+x3+x4)/4.0;
    printf("%.1f\n",media);
    media=(x1+x2+x3+x4+x5)/5.0;
    printf("%.1f\n",media);

    return 0;
}