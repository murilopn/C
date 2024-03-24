#include <stdio.h>
int main () {

int   qntd=0,resultado=0,validacaom=0,validacaof=0,manterid=0,proximaid=1,contnotas=1,
      maiorM=0,idmaiorresultadoM=0,identidadeM=0,identidadeF=0,maiorF=0,idmaiorresultadoF=0,       
      contmenosum=0,numdelegacao=0,menorF=0,menorM=0,idmenorresultadoF=0,idmenorresultadoM=0,
      contscanf=0;
 
          
    scanf("%d",&qntd); //qntd de delegações

while (contmenosum!=qntd){

    scanf("%d ",&resultado); //entrada tudo em uma linha

     if(contscanf!=qntd){

        if (resultado==45){
         contscanf++;}
         
     continue;}

        if ((resultado==77) || (validacaom)){ //masculino (77 é o valor ascii)
           //tirei o genero, acho q n importa
            validacaom=1;

           if (manterid){ //identidade do atleta (n pode voltar)
            identidadeM=proximaid;
            manterid=0;
            proximaid++;
            }
            
            if (contnotas<=3){ // pra entrar as 3 notas de cada atleta
               contnotas++;
                if(resultado>maiorM){
                    maiorM=resultado;
                    idmaiorresultadoM=identidadeM;          

                 }
                if(resultado<menorM){
                    menorM=resultado;
                    idmenorresultadoM=identidadeM;
                    }}}


        if ((resultado==70) || (validacaof)){ //feminino (70 é o valor ascii)
            //tirei o genero, acho q n importa
            validacaof=1;

           if (manterid){ //identidade do atleta (n pode voltar)
            identidadeF=proximaid;
            manterid=0;
            proximaid++;
            }
            
            if (contnotas<=3){ // pra entrar as 3 notas de cada atleta
               contnotas++;
                if(resultado>maiorF){
                    maiorF=resultado;
                    idmaiorresultadoF=identidadeF;          

                 }
                if(resultado<menorF){
                    menorF=resultado;
                    idmenorresultadoF=identidadeF;
                    }}}


    if(resultado=='\n'){
    manterid=1;         //vai recomeçar as contagens pra um novo atleta
    contnotas=1;
    }

    if(resultado==45){ //valor do menos na ascii
    contmenosum;      //vai igualar -1 com num de delegações pra quebrar                   
    }
    }

while (numdelegacao!=qntd){
numdelegacao++;

printf("MELHORES ATLETAS DA DELEGACAO %d",numdelegacao);
printf("MASCULINO: %d FEMININO: %d",idmaiorresultadoM,idmaiorresultadoF);
printf("PIORES ATLETAS DA DELEGACAO 1");
printf("MASCULINO: %d FEMININO: %d",idmenorresultadoM,idmenorresultadoM );

}




    return 0;
}