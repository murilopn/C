#include <stdio.h>
int main () {

int n=0,i=0,num=0,flagsair=0;
char frase=0;

scanf ("%d ",&n);

while (n>i){
    flagsair=0;

    scanf("%d ", &num);

    scanf("%*[^d]");

    while(frase!='"'){
    
    scanf("%c",&frase);
    
     switch(frase){

        case '%':
         frase=num;
            flagsair=1;
        break;
    }
        printf("%c",frase);
        
        if (flagsair)
            break;
  }

  case '2':
        printf("%d",num);
        break;
    case '3':
        printf("%d",num);
        break;
    case '4':
        printf("%d",num);
        break;

i++;
}
    return 0;
}