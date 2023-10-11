#include <stdio.h>
typedef struct { // fechado em d1 e aberto em d2
   int dia;
   int mes;
   int ano;
   int dia2;
   int mes2;
   int ano2;
   int returnmes31;
} tData;

int EhBisexto1 (tData data){

    if((!(data.ano%400)) || (!(data.ano%4))){
        return 1;
    }
    else {
        return 0;
}}
int EhBisexto2 (tData data){

    if((!(data.ano2%400)) || (!(data.ano2%4))){
        return 1;
    }
    else {
        return 0;
    }}
int AumentaOsAnos (tData data){
    data.dia=1;
    data.mes=1;
    data.ano++;
}

int AumentaOsMeses (tData data){
    int validabisexto1=0;
    if (((data.mes ==1) || (data.mes==3) || (data.mes==5 )|| (data.mes==7) || (data.mes==8) || (data.mes==10) || (data.mes==12)) && (data.dia>31)){
            if(data.mes<12){
                data.mes++;
            }
            else if (data.mes==12){
                AumentaOsAnos (data);
            }
            return 1;
}
    else if (((data.mes ==4) || (data.mes==6) || (data.mes==9 )|| (data.mes==11)) && (data.dia>30)){
        data.mes++;
        return 0;
}
    else { //fevereiro
          validabisexto1=EhBisexto1(data);
        if (validabisexto1){//bisexto
                if (data.dia>29)
                data.mes++;
            }
        else{
            data.mes++;
        }
    }
}

int AumentaOsDias (tData data){
    while (((data.dia!=data.dia2) || (data.mes!=data.mes2) || (data.ano!=data.ano2))) {
            if (data.dia>28){
                AumentaOsMeses(data);
            }
        printf("'%02d %02d %d'\n",data.dia,data.mes,data.ano);

        data.dia++;
    }
}

int ValidacaoDasEntradas(tData data){
    int validabisexto1=0,validabisexto2=0;
     if (data.mes<0){
        data.mes=1;
    }
    else if (data.mes>12){
        data.mes=12;
    }
    if (data.mes2<0){
        data.mes2=1;
    }
    else if (data.mes2>12){
        data.mes2=12;
    }

    if (data.dia<0){
        data.dia=1;
    }
    else if (data.dia>28){

        if (data.mes==2){
            validabisexto1=EhBisexto1(data);
            if(validabisexto1){
                data.dia=29;
            }
            else{
                data.dia=28;
            }
        }
        else if(data.dia>30){
             data.returnmes31=AumentaOsMeses(data);
            if(data.returnmes31){
                data.dia=31;
            }
            else {
                data.dia=30;
            }
        }
    }
    if (data.dia2<0){
        data.dia2=1;
    }
    if (data.dia2>28){
        if(data.mes2==2){
            validabisexto2=EhBisexto2(data);
            if(validabisexto2){
                data.dia2=29;
            }
            else{
                data.dia2=28;
            }
        }
    }
    else if(data.dia2>30){
        if (((data.mes2 ==1) || (data.mes2==3) || (data.mes2==5 )|| (data.mes2==7) || (data.mes2==8) || (data.mes2==10) || (data.mes2==12)) && (data.dia2>31)){
            data.dia2=31;
        }
        else {
            data.dia2=30;
        }
    }
    AumentaOsDias(data);
}

int LeEntradas (){
    tData data;
    scanf("%d %d %d",&data.dia,&data.mes,&data.ano);
    scanf("%d %d %d",&data.dia2,&data.mes2,&data.ano2);

    ValidacaoDasEntradas(data);
}   
int main () {
    LeEntradas ();
    
    return 0;
}