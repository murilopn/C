#include <stdio.h>
#include <math.h>

int main (){
    float volume=0,raio=0;
    scanf("%f",&raio);

    volume=(4/3.0)*pow(raio,3)*M_PI;

    printf("%f",volume);




    return 0;
}