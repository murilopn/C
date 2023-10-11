#include <stdio.h>
#include <math.h>

int main(){
  float a, b, c, d;
  int e, f;

  scanf("%f %f %f %f %d %d", &a, &b, &c, &d, &e, &f);

  int x, cont1=0, cont2=0;
  float y, antY, sucY;

  for(x=e;x>=e && x<=f;x++){
    y = a*pow(x,3) + b*pow(x,2) + c*x + d;
    antY = a*pow(x-1,3) + b*pow(x-1,2) + c*(x-1) + d;
    sucY = a*pow(x+1,3) + b*pow(x+1,2) + c*(x+1) + d;
    if(y>antY && y>sucY){
        cont1++;
        printf("Pico em x=%d\n", x);
    }
    else if(y<antY && y<sucY){
        cont2++;
        printf("Vale em x=%d\n", x);
    }
  }

  if(cont1 == 0){
    printf("Nao ha pico\n");
  }
  if(cont2 == 0){
    printf("Nao ha vale");
  }

  return 0;
}