#include <stdio.h>
int main(){
  int n, i, num;
  int num1, num2, num3, num4, num5, num6, num7, num8, num9;

  scanf("%d", &n);

  for(i=1;i<=n;i++){

    scanf("%d", &num);
    
    switch(i){
      case 1:
        num1 = num;
        break;
      case 2:
        num2 = num;
        break;
      case 3:
        num3 = num;
        break;
      case 4:
        num4 = num;
        break;
      case 5:
        num5 = num;
        break;
      case 6:
        num6 = num;
        break;
      case 7:
        num7 = num;
        break;
      case 8:
        num8 = num;
        break;
      case 9:
        num9 = num;
        break;
    }
  }

  char caracter;

  while(1){
    scanf("%c", &caracter);
    if(caracter == '"'){
      while(scanf("%c", &caracter) && caracter != '"'){
        if(caracter == '%'){
          scanf("%c", &caracter);

          if((caracter-n)>'0'){
            printf("ERRO");
          }else{
            switch(caracter){
              case '1':
                printf("%d", num1);
                break;
              case '2':
                printf("%d", num2);
                break;
              case '3':
                printf("%d", num3);
                break;
              case '4':
                printf("%d", num4);
                break;
              case '5':
                printf("%d", num5);
                break;
              case '6':
                printf("%d", num6);
                break;
              case '7':
                printf("%d", num7);
                break;
              case '8':
                printf("%d", num8);
                break;
              case '9':
                printf("%d", num9);
                break;
              default:
                printf("ERRO");
            }
          }
        }else{
          printf("%c", caracter);
        }
      }
      break;
    }
  }

  return 0;
}