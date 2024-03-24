#include <stdio.h> 

typedef struct { // fechado em d1 e aberto em d2
   int dia;
   int mes;
   int ano;
   int dia2;
   int mes2;
   int ano2;

} tData;


int main (){
   tData data;
   int a=0,b=0,numinvertido=0,num=0,validar=1;
   scanf("%d %d %d",&data.dia,&data.mes,&data.ano);
   scanf("%d %d %d",&data.dia2,&data.mes2,&data.ano2);  

    if (data.mes>12){ //casos em que o mes fornecido n existe
        data.mes=12;
    }
    else if (data.mes<1){ //casos em que o mes fornecido n existe
        data.mes=1;
    }

    if (data.mes2>12){
        data.mes2=12;
    }
    else if (data.mes2<1){ 
        data.mes2=1;
    }
     if (data.dia<1){ 
        data.dia=1;
    }
    if (data.dia2<1){
        data.dia2=1;
    }

    if (((data.mes ==4) || (data.mes==6) || (data.mes==9 )|| (data.mes==11)) && (data.dia>30)){ //casos em que o dia fornecido n existe
        data.dia=30;
    }
    else if (((data.mes ==1) || (data.mes==3) || (data.mes==5 )|| (data.mes==7) || (data.mes==8) || (data.mes==10) || (data.mes==12)) && (data.dia>31)){
        data.dia=31;
    }
    else if ((data.mes==2) && (data.dia>28)){ //fevereiro!!
                b=data.ano;
                //temos que colocar a condiçao do ano terminado em 00 primeiro, pois há anos como 2100, 2200 e etc
                    b=data.ano;
                       while (data.ano!=0){
                        a=data.ano%10;
                        data.ano/=10;
                           num+=a;
                    }
                                data.ano=b;

                if ((num%4==0) || (data.ano%4==0)){ //eh bissexto
                    if(data.dia>29){
                            data.dia=29;
                        }}
                else{
                        data.dia=28;
                    }}
                    a=0;
                    b=0;

     if (((data.mes2 ==4) || (data.mes2==6) || (data.mes2==9 )|| (data.mes2==11)) && (data.dia2>30)){ //casos em que o dia fornecido n existe
        data.dia2=30;
    }
    else if (((data.mes2 ==1) || (data.mes2==3) || (data.mes2==5 )|| (data.mes2==7) || (data.mes2==8) || (data.mes2==10) || (data.mes2==12)) && (data.dia2>31)){
        data.dia2=31;
    }
    else if ((data.mes2==2) && (data.dia2>28)){ //fevereiro!!
                b=data.ano2;
                //temos que colocar a condiçao do ano terminado em 00 primeiro, pois há anos como 2100, 2200 e etc
                    b=data.ano2;
                       while (data.ano2!=0){
                        a=data.ano2%10;
                        data.ano2/=10;
                           num+=a;
                    }
                                data.ano2=b;

                if ((num%4==0) || (data.ano2%4==0)){ //eh bissexto
                    if(data.dia2>29){
                            data.dia2=29;
                        }}
                else{
                        data.dia2=28;
                    }}

       printf("'%.02d/%.02d/%.02d'\n",data.dia,data.mes,data.ano); 

       
       

    while (((data.mes!=data.mes2) || (data.dia!=data.dia2) || (data.ano!=data.ano2))){
          data.dia++;
        if (((data.mes ==1) || (data.mes==3) || (data.mes==5 )|| (data.mes==7) || (data.mes==8) || (data.mes==10) || (data.mes==12)) && (data.dia>31)){

            if(data.mes==12){ //virada de ano
                data.mes=1;
                data.ano++;
                data.dia=1;
           } else {
        data.dia=1;
        data.mes++;
    }}
        else if (((data.mes ==4) || (data.mes==6) || (data.mes==9 )|| (data.mes==11)) && (data.dia>30)){
            
            data.mes++;
            data.dia=1;
        }

        else if ((data.mes==2) && (data.dia>28)){
                      b=data.ano;
                       while (data.ano!=0){
                        a=data.ano%10;
                        data.ano/=10;
                           num+=a;
                    }
                                data.ano=b;

                if ((num%4==0) || (data.ano%4==0)){ //eh bissexto
                    if(data.dia>29){
                            data.dia=1;
                            data.mes++;
                        }
                    else{
                        data.dia=29;
                    }
                }
                     else {
                    data.dia=1;
                    data.mes++;
                }
                num=0;
    }
        if((data.dia==data.dia2) && (data.mes==data.mes2) && (data.ano==data.ano2)){
            continue;
        }
        else {
        printf("'%.02d/%.02d/%d'\n",data.dia,data.mes,data.ano);
        }
      
    }


     return 0;
}



