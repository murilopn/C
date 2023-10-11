#include <stdio.h>
#include <math.h>
int main () {

float a=0,b=0,c=0,d=0,e=0,f=0,x=0,y=0,achouP=0,achouV=0,sucessor=0,antecessor=0;


scanf ("%f %f %f %f %f %f",&a,&b,&c,&d,&e,&f);

for(x=e;x>=e && x<=f;x++){

    
    antecessor= a*pow(x-1,3) + b*pow(x-1,2) + c*(x-1) + d;
    sucessor= a*pow(x+1,3) + b*pow(x+1,2) + c*(x+1) + d;
    y = a*pow(x,3) + b*pow(x,2) + c*x+ d;


    if (y>sucessor && y>antecessor){
        printf("Pico em x=%.0f\n",x);
        achouP++;
    }

    else if (y<sucessor && y<antecessor){
        achouV++;
         printf("Vale em x=%.0f\n",x);
    }
        
}

    if(achouP == 0){
        printf("Nao ha pico\n");
    }
    if (achouV == 0){
        printf("Nao ha vale");
    }

    return 0;
}