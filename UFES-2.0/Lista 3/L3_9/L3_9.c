#include <stdio.h>

int  verificapH(float  pH){
    int neutro=0,acido=1,basico=2,cont=0;
    if (pH==7){
        cont++;
        return neutro;
    }
    else if (pH<7){
        cont++;
        return acido;
    }
    else if (pH>7){
        cont++;
        return basico;
    }

}
 int verificaGotaChuvaAcida(float pH){
    if (pH<5.7){
        return 1;
    }
    else {
        return 0;
    }

 }

void imprimeResultadosAnalise(float neutro, float muitoacida){
    float final=0;
    final=neutro+muitoacida;
    neutro/=final;
    muitoacida/=final;
    if (muitoacida>0.75){
        printf("Chuva Acida %.2f %.2f",muitoacida,neutro);
    }
    else if (neutro>0.75){
        printf("Chuva normal %.2f %.2f",muitoacida,neutro);
    }
    else {
        printf("Chuva com indicios de chuva acida %.2f %.2f",muitoacida,neutro);
    }


}

int main (){
    int A=0,D=0,T=0,analise=0,muitoacida=0,neutro=0,acido=0,basico=0,maiorA=-32000,maiorB=32000,maiorN=-32000;
    float P=0;
    scanf("%d %d %d",&A,&D,&T);

    while (scanf("%f",&P)==1){

    analise=verificapH(P);
    if (analise==0){
        if(P>maiorN){
            maiorN=P;
        }
        neutro++;

    }
    else if (analise==2){
        if(P<maiorB){
            maiorB=P;
        }
        basico++;
    }
    else{
        if(P>maiorA){
            maiorA=P;
        }
        acido++;
        if(verificaGotaChuvaAcida(P)){
            muitoacida++;
}}
    }
printf("%d %d %d %d %d %d\n",acido,basico,neutro,maiorA,maiorB,maiorN);

    neutro=basico+acido+neutro;
    imprimeResultadosAnalise(neutro,muitoacida);


//densidade de gotas de chuva (quantas gotas de chuva caem em 1 metro quadrado a cada 1 segundo)
    return 0;
}
