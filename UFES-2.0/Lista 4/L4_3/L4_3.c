#include <stdio.h> 

typedef struct { // fechado em d1 e aberto em d2
   int dia;
   int mes;
   int ano;
    int analise;
} tData;



int Ehbissexto (tData data){


    if (!(data.ano%400)){
        return 1;
    }

    else if (!(data.ano%4)){
        return 1;
    }

    else {
        return 0;
    }
}



int ValidacaoDosMeses (tData data){

if(data.mes>12){
       return 12;
    }
    else if (data.mes<1){
       return 1;
    }
    else {
        return data.mes;
    }
}

int ValidacaoDosDias(tData data) {
    if (((data.mes ==1) || (data.mes==3) || (data.mes==5 )|| (data.mes==7) || (data.mes==8) || (data.mes==10) || (data.mes==12)) && (data.dia>31)){
    return 31;
 }
else if (((data.mes ==4) || (data.mes==6) || (data.mes==9 )|| (data.mes==11)) && (data.dia>30)){
    return 30;
}
    else {
        return data.dia;
    }
}

void Imprime(tData data){


    if(data.analise){
        if ((data.mes==2) && (data.dia>29)){
            data.mes=29;
        }
        printf("'%02d/%02d/%d':Bisexto\n",data.dia,data.mes,data.ano);
    }
    else {
        if ((data.mes==2) && (data.dia>28)){
            data.dia=28;
        }
        printf("'%02d/%02d/%d':Normal\n",data.dia,data.mes,data.ano);
    }


}

int main () {
    tData data;
    int cont=0,qntd=0;
    scanf("%d",&qntd);
    while (cont<qntd){
    scanf("%02d %02d %d",&data.dia,&data.mes,&data.ano);


   data.analise=Ehbissexto (data);

  data.mes= ValidacaoDosMeses(data);
   data.dia =ValidacaoDosDias(data);

   Imprime (data);
   cont++;
    }
     return 0;
}



