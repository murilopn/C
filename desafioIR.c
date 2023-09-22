#include <stdio.h>
int main (){
    float salario,novosalario=0;
    printf("Informe o valor do salário: ");
    scanf("%f",&salario);

    if (salario>1200.25){
        novosalario=(2300.5-1200.25)*0.075;

        if (salario>2300.5){
            novosalario+=(3500.75-2300.5)*0.15;

            if(salario>3500.75){
                novosalario+=(4000-3500.75)*0.225;
                
                if(salario>4000){
                    novosalario+=(salario-4000)*0.275;

                }
                else{
                    novosalario-=(4000-3500.75)*0.225;
                    novosalario+=(salario-3500.75)*0.225;
                }
            }
            else{
                novosalario-=(3500.75-2300.5)*0.15;
                novosalario+=(salario-2300.5)*0.15;
            }
        }
        else{
            novosalario=(salario-1200.25)*0.075;
        }
    }
/*Eu faço as contas como se fosse maior que o próximo if, caso não seja eu só desfaço a conta
e faço a conta para o valor entre as faixas estabelecidas*/
printf("%.2f",novosalario);

    return 0;
}

