#include <stdio.h>
int main (){
    int num, a=0,novo=0,inicial;
        
        scanf("%d",&num);
    inicial=num;
    a=num;
    while (a>0)   {
        num=a;
        num=num%10;
        novo*=10;
        novo+=num;
        a/=10;
    }
    if (inicial==novo){
        printf("%d\n",inicial);
        printf("%d",novo);
    }
    
    return 0;
}