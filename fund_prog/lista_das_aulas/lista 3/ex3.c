#include <stdio.h>
int main (){
    int num1,num2,num3;
    scanf("%d %d %d",&num1,&num2,&num3);

    if (num1>num2 && num1>num3){
        printf("%d",num1);
    }

    else if (num2>num1 && num2>num3){
        printf("%d",num2);
    }

    else if (num3>num1 && num3>num2){
        printf("%d",num3);
    }
    
    return 0;
}
/*
outra forma:
if (num1>num2){
    if (num1>num3){
        printf num1
    }
    else{
        printf num3
    }
}
else{
    if(num n2>n3){
        printf num2
    }
    else{
        printf num3
    }
}
outra forma:
    maior=num1
    if (num2>maior){
        maior=n2
    }
    if (num3>maior){
        maior=num3
    }
    printf maior
*/