#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAREDE '#'
#define PACMAN '>'
#define COMIDA '*'
#define ESPACO ' '
#define PORTAL '@'

#define FANTASMA_ESQUERDA 'B'
#define FANTASMA_DIREITA 'C'
#define FANTASMA_CIMA 'P'
#define FANTASMA_BAIXO 'I'

#define ESQUERDA 'a'
#define DIREITA 'd'
#define CIMA 'w'
#define BAIXO 's'

typedef struct {
    int linha;
    int coluna;
    int inverteu;
    int linA;
    int colA;
    int existe;
    int emcimacomida;

} tFantasma;

typedef struct {
        //todas as informações serão extraidas do mapa.
    int linha;
    int coluna;   
    
}tPacman;

typedef struct{
    int l;
    int c; 
    int limjogadas;
    char mapa[40][100];
    int ehparede; //util para quando o fantasma come o pacman na parede
}tMapa;

typedef struct{
    int numbatidas;
    int numsemponto;
    int nummovimentos;
    int nummovibaixo;
    int nummovicima;
    int nummovidireita;
    int nummoviesquerda;

}tEstatistica;

typedef struct{
    int trilha[40][100];
}tTrilha;

typedef struct {
    int parede;
    int comida;
    int fantasma;

}tResumo;

/*typedef struct {
    numcolisoes;
    numalimento;
    numacoes;
}tRanking;*/

typedef struct{
    int matrizportal[40][100];
    int linhaP1;
    int colunaP1;
    int linhaP2;
    int colunaP2;
    int antigoportal;
}tPortal;

typedef struct {
    tPortal portal;
    int imprimenaparede;
    tMapa mapa;
    tPacman pacman;
    tFantasma fantasma; 
    int matrizcomida[40][100];
    tFantasma B;
    tFantasma C;
    tFantasma I;
    tFantasma P;
    int qntdcomida; //caso o pacman coma tudo, vai dar vitoria
    int totalcomida;
    tEstatistica dados;
    tTrilha trilha;
    tResumo resumo;
    char fancola;
    int fim;
    //tRanking matrizranking[4][3];//cada linha é um movimento e cada coluna um valor
    int retorno;
     //tRanking a;
    //tRanking s;
    //tRanking w;
    //tRanking d;
}tPartida;

/*void Ranking(tPartida jogo,char * argv[]){
    int i,j,s=0,aux=0,vetfinal[4];
    
    FILE * ranking;
    char x [1000];
    sprintf(x,"%s/saida/ranking.txt",argv[1]);
    ranking=fopen(x,"w");

    for (i=0;i<4;i++){   //fazer na marretada, sem tempo
        for(j=i+1;j<4;j++){
            if(jogo.matrizcomida[i][i]>jogo.matrizcomida[i][j]){
                aux=jogo.matrizcomida[i][i];
                jogo.matrizcomida[i][i]=jogo.matrizcomida[i][j];
                vetfinal[i]=jogo.matrizcomida[i][i];
                jogo.matrizcomida[i][j]=aux;
            }
            else if(jogo.matrizcomida[i][i]==jogo.matrizcomida[i][j]){
                jogo.matrizcomida[1][i]
            }
        }

    }
       fclose(ranking);
 }*/

void ImprimeTrilha(tPartida jogo, char * argv[]){
    FILE * trilha;
    int i,j;
    char u[1000];

    sprintf(u,"%s/saida/trilha.txt",argv[1]);
    trilha=fopen(u,"w");

    for (i=0;i<jogo.mapa.l;i++){
        for (j=0;j<jogo.mapa.c;j++){
            if (jogo.trilha.trilha[i][j]==-1){
                fprintf(trilha,"# ");
            }
            else {
                fprintf(trilha,"%d ",jogo.trilha.trilha[i][j]);
            }
        }
        fprintf(trilha,"\n");
    }
}

tPartida Trilha (tPartida jogo){ //NAO PRECISA DE ARQUIVO
    jogo.trilha.trilha[jogo.pacman.linha][jogo.pacman.coluna]=jogo.dados.nummovimentos;
    return jogo;
}

void Resumo(tPartida jogo, char mov, char  * argv[],FILE * resumo){//USAR APPEND AQUI

    if(jogo.resumo.comida){
        fprintf(resumo,"Movimento %d (%c) pegou comida\n",jogo.dados.nummovimentos,mov);
    }
    else if (jogo.resumo.parede){
        fprintf(resumo,"Movimento %d (%c) colidiu na parede\n",jogo.dados.nummovimentos,mov);
    }
    else if (jogo.resumo.fantasma){
        fprintf(resumo,"Movimento %d (%c) fim de jogo por encostar em um fantasma\n",jogo.dados.nummovimentos,mov);
    }
  
}

void Estatistica (tPartida jogo, char * argv[]){
    FILE * estatistica;
    char f[1000];
        sprintf(f,"%s/saida/estatisticas.txt",argv[1]);
        estatistica= fopen(f,"w");

    fprintf(estatistica,"Numero de movimentos: %d\n",jogo.dados.nummovimentos);
    fprintf(estatistica,"Numero de movimentos sem pontuar: %d\n",jogo.dados.numsemponto);
    fprintf(estatistica,"Numero de colisoes com parede: %d\n",jogo.dados.numbatidas);
    fprintf(estatistica,"Numero de movimentos para baixo: %d\n",jogo.dados.nummovibaixo);
    fprintf(estatistica,"Numero de movimentos para cima: %d\n",jogo.dados.nummovicima);
    fprintf(estatistica,"Numero de movimentos para esquerda: %d\n",jogo.dados.nummoviesquerda);
    fprintf(estatistica,"Numero de movimentos para direita: %d\n",jogo.dados.nummovidireita);

    fclose (estatistica);
}

void ImprimeVitoria (tPartida jogo,FILE * imprimejogo){
    fprintf(imprimejogo,"Voce venceu!\nPontuacao final: %d\n",jogo.qntdcomida);
}

  void ImprimeJogoAtual(tPartida partida, char mov, FILE * imprimejogo){
    int i,j;
   
    fprintf(imprimejogo,"Estado do jogo apos o movimento '%c': \n",mov);
    for (i=0;i<partida.mapa.l;i++){
        for (j=0;j<partida.mapa.c;j++){

            fprintf(imprimejogo,"%c",partida.mapa.mapa[i][j]);
        }
        fprintf (imprimejogo,"\n");
    }
    fprintf(imprimejogo,"Pontuacao: %d\n",partida.qntdcomida);
    fprintf(imprimejogo,"\n");
 }


void GameOver (tPartida partida,char mov,FILE * imprimejogo){//deve possuir um print próprio
  int i,j;
 
  fprintf(imprimejogo,"Estado do jogo apos o movimento '%c':\n",mov);
  for (i=0;i<partida.mapa.l;i++){
    for(j=0;j<partida.mapa.c;j++){
        if(partida.mapa.mapa[i][j]==PACMAN){
            partida.mapa.mapa[i][j]=ESPACO;//tudo que o pacman passar por cima vira espaço
        }
        fprintf(imprimejogo,"%c",partida.mapa.mapa[i][j]);
    }
    fprintf(imprimejogo,"\n");
  }
    fprintf(imprimejogo,"Pontuacao: %d\n",partida.qntdcomida);
    fprintf(imprimejogo,"\nGame over!\nPontuacao final: %d\n",partida.qntdcomida);
}

tPartida Teletransporta(tPartida jogo){
    int i,j,baixopracima=0;
    if(jogo.pacman.linha>jogo.portal.linhaP1){
        baixopracima=1;
  }
  else if(jogo.pacman.linha==jogo.portal.linhaP1){
    if(jogo.pacman.coluna>jogo.portal.colunaP1){
          baixopracima=1;
    }
  }
    
  if(baixopracima==0){
         jogo.mapa.mapa[jogo.portal.linhaP1][jogo.portal.colunaP1]=PORTAL;
         jogo.mapa.mapa[jogo.portal.linhaP2][jogo.portal.colunaP2]=PACMAN;
                
            jogo.pacman.linha=jogo.portal.linhaP2;
            jogo.pacman.coluna=jogo.portal.colunaP2;
        }
  
  else{
        jogo.mapa.mapa[jogo.pacman.linha][jogo.pacman.coluna]=ESPACO;
        jogo.mapa.mapa[jogo.portal.linhaP2][jogo.portal.colunaP2]=PORTAL;
        jogo.mapa.mapa[jogo.portal.linhaP1][jogo.portal.colunaP1]=PACMAN;
        jogo.pacman.linha=jogo.portal.linhaP1;
        jogo.pacman.coluna=jogo.portal.colunaP1;
  }    
 
    return jogo;
}

int AnalisaGameOver(char mov, tPartida jogo, int c, int l){   //LEMBRANDO QUE O FANTASMA JÁ CHEGA AQUI MOVIDO.
    int cont=0,colB,linB,colP,linP,colI,linI,colC,linC;     //SE TIVER BUGANDO, FAZER SEPARADO POR FANTASMA(PQ AÍ EU DESCARTO OS QUE NAO EXISTE)

    colB=jogo.B.colA , linB=jogo.B.linA;
    colP=jogo.P.colA , linP=jogo.P.linA;
    colI=jogo.I.colA , linI=jogo.I.linA;
    colC=jogo.C.colA , linC=jogo.C.linA;
     //OS PRIMEIROS IF É PARA CASOS DE COLISÃO (POSIÇÕES FINAIS IGUAIS)
     //O SEGUNDO IF É PARA CASOS EM QUE A POSIÇÃO FINAL DO FANTASMA É IGUAL A INICIAL DO PACMAN E VICE-VERSA (conferir se o fantasma tá na posição antiga dele mesmo)
    //A POSIÇÃO ANTIGA ATUALIZA, OU SEJA, ELA VAI SER IGUAL UM ESPAÇO, POR EX.
   if(jogo.mapa.mapa[l][c]==FANTASMA_BAIXO || jogo.mapa.mapa[l][c]==FANTASMA_CIMA || 
      jogo.mapa.mapa[l][c]==FANTASMA_DIREITA || jogo.mapa.mapa[l][c]==FANTASMA_ESQUERDA){ 
            cont=1;  //FIZ ESSE IF AQUI EM CIMA,POIS EU TERIA QUE BOTAR ELE EM CADA MOV(DAÍ PRA ECONOMIZAR ESPAÇO,BOTEI SÓ UM. 
      }   

  if(mov==BAIXO){
        if(jogo.mapa.mapa[l+1][c]==FANTASMA_BAIXO || jogo.mapa.mapa[l+1][c]==FANTASMA_CIMA || 
        jogo.mapa.mapa[l+1][c]==FANTASMA_DIREITA || jogo.mapa.mapa[l+1][c]==FANTASMA_ESQUERDA ){
                return 1;
        }
        else if (cont && (((l+1==linB) && (c==colB)) || ((l+1==linC) && (c==colC)) || ((l+1==linP) && (c==colP)) || ((l+1==linI) && (c==colI)))){
                return 1;
        }
       
    } 
 
  else if (mov==CIMA){
        if(jogo.mapa.mapa[l-1][c]==FANTASMA_BAIXO || jogo.mapa.mapa[l-1][c]==FANTASMA_CIMA || 
        jogo.mapa.mapa[l-1][c]==FANTASMA_DIREITA || jogo.mapa.mapa[l-1][c]==FANTASMA_ESQUERDA ){
                  return 1;
        }
        else if (cont && (((l-1==linB) && (c==colB)) || ((l-1==linP) && (c==colP)) || ((l-1==linC) && (c==colC)) || ((l-1==linI) && (c==colI)))){
                  return 1;
        }

  }
  
  else if (mov==ESQUERDA){
        if(jogo.mapa.mapa[l][c-1]==FANTASMA_BAIXO || jogo.mapa.mapa[l][c-1]==FANTASMA_CIMA || 
        jogo.mapa.mapa[l][c-1]==FANTASMA_DIREITA || jogo.mapa.mapa[l][c-1]==FANTASMA_ESQUERDA ){
                return 1;
        }
       else if(cont && (((l==linB) && (c-1==colB)) ||((l==linP) && (c-1==colP))|| ((l==linI) && (c-1==colI)) || ((l==linC) && (c-1==colC)))){
            return 1;
        }

  }
  
  else if (mov==DIREITA){
        if(jogo.mapa.mapa[l][c+1]==FANTASMA_BAIXO || jogo.mapa.mapa[l][c+1]==FANTASMA_CIMA || 
        jogo.mapa.mapa[l][c+1]==FANTASMA_DIREITA || jogo.mapa.mapa[l][c+1]==FANTASMA_ESQUERDA){
                return 1;
        }
        else if(cont && (((l==linB) && (c+1==colB)) ||((l==linP) && (c+1==colP))|| ((l==linI) && (c+1==colI)) || ((l==linC) && (c+1==colC)))){
            return 1;
        }
    }
    
    if(cont && jogo.mapa.ehparede){//casos em que o pacman é comido pelo fantasma na parede
        return 1;
    }
  return 0;
}

tPartida FantasmaNaCola(tPartida jogo,int c, int l){
   jogo.fancola='Z';
    
        if(jogo.mapa.mapa[l][c]==FANTASMA_BAIXO){
            jogo.fancola=FANTASMA_BAIXO;
        }
        else if(jogo.mapa.mapa[l][c]==FANTASMA_CIMA)  {
            jogo.fancola=FANTASMA_CIMA;
        }
        else if(jogo.mapa.mapa[l][c]==FANTASMA_DIREITA) {
            jogo.fancola=FANTASMA_DIREITA;
         } 
         else if(jogo.mapa.mapa[l][c]==FANTASMA_ESQUERDA ){
            jogo.fancola=FANTASMA_ESQUERDA;
         }

    return jogo;
}

int VerificaPosicaoFutura(char mov, tPartida posicao, int c, int l){ 
    int gameover1=0,gameover2=0;
    posicao=FantasmaNaCola(posicao,c,l); //tem que me retornar o fantasma que está na cola para printar o fantasma certo
    gameover1=AnalisaGameOver(mov,posicao,c,l);
    if(gameover1==1){//quer dizer que bateu na parede e o fantasma comeu
        posicao.imprimenaparede=1;
        return 3;
    }
        if(mov==ESQUERDA){ 

           if (posicao.mapa.mapa[l][c-1]==ESPACO){
                if(posicao.fancola=='Z'){  //se retornar 1, ele está na cola, estando na cola eu devo analisar se deu gameover(caso nao,imprimo espaço)
                    return 0; 
                }
            }
            else if(posicao.mapa.mapa[l][c-1]==PAREDE){
                posicao.mapa.ehparede=1;
                gameover1=AnalisaGameOver(mov,posicao,c,l);
                posicao.mapa.ehparede=0;

                if(gameover1==0){
                     return 1;

                }
                 
            }   
            else if(posicao.mapa.mapa[l][c-1]==COMIDA){
                    return 2;
            }
            else if(posicao.mapa.mapa[l][c-1]==PORTAL){
                    return 4;
            }
        }

        else if(mov==CIMA){
         
            if(posicao.mapa.mapa[l-1][c]==ESPACO){
                  if(posicao.fancola=='Z'){
                    return 0;
                 }
            }
            else if(posicao.mapa.mapa[l-1][c]==PAREDE){
                posicao.mapa.ehparede=1;
                gameover1=AnalisaGameOver(mov,posicao,c,l);
                posicao.mapa.ehparede=0; 
                if(gameover1==0){
                     return 1;

                }
            }   
            else if(posicao.mapa.mapa[l-1][c]==COMIDA){
                    return 2;
            }
             else if(posicao.mapa.mapa[l-1][c]==PORTAL){
                    return 4;
            }    
        }

        else if (mov==BAIXO){
            
            if(posicao.mapa.mapa[l+1][c]==ESPACO){
                 if(posicao.fancola=='Z'){
                  return 0;
                }
            }
            else if(posicao.mapa.mapa[l+1][c]==PAREDE){
                posicao.mapa.ehparede=1;
                gameover1=AnalisaGameOver(mov,posicao,c,l);
                posicao.mapa.ehparede=0; 
                
                if(gameover1==0){
                     return 1;

                }
            }   
            else if(posicao.mapa.mapa[l+1][c]==COMIDA){
                    return 2;
            }
            else if(posicao.mapa.mapa[l+1][c]==PORTAL){
                    return 4;
            }
        }

        else if(mov==DIREITA){
        
           if(posicao.mapa.mapa[l][c+1]==ESPACO){
                  if(posicao.fancola=='Z'){
                     return 0;
                    }
            }
            else if(posicao.mapa.mapa[l][c+1]==PAREDE){
                posicao.mapa.ehparede=1;
                gameover1=AnalisaGameOver(mov,posicao,c,l);
                 posicao.mapa.ehparede=0;
                if(gameover1==0){
                     return 1;

                }
            }   
            else if(posicao.mapa.mapa[l][c+1]==COMIDA){
                    return 2;
            }
            else if(posicao.mapa.mapa[l][c+1]==PORTAL){
                    return 4;
            }
        }   
        
        gameover2=AnalisaGameOver(mov,posicao,c,l);
       
        if(gameover1 || gameover2){
            return 3;
        }
        else {
            return 0;
        }
      
    }

tPartida MovimentaPacMan(tPartida jogo,char mov, char  * argv[],FILE * imprimejogo,FILE * resumo){
    int entra=1,somecomida=0,resultado=0,teleporte=0,podeentrar=0,l=jogo.pacman.linha,c=jogo.pacman.coluna,deugameover=0;
    jogo.retorno=resultado=VerificaPosicaoFutura(mov,jogo,c,l);    //jogo retorno será necessário para gerar o ranking

    jogo.dados.numsemponto++;

            if(resultado==0){ //espaço
                podeentrar=1;
            }
            else if(resultado==1){ //parede
                jogo.dados.numbatidas++;
                ImprimeJogoAtual(jogo, mov,imprimejogo);//imprime sem trocar a posição
                jogo.resumo.parede=1;
                Resumo(jogo,mov,argv,resumo);
                jogo.resumo.parede=0;

                return jogo;
            }
            else if(resultado==2){ //comida
                jogo.qntdcomida++;
                somecomida=1;
                jogo.dados.numsemponto--;
                jogo.resumo.comida=1;
                Resumo(jogo,mov,argv,resumo);
                jogo.resumo.comida=0;
                podeentrar=1;
            }
            else if (resultado==3){ //gameover
                    deugameover=1;
            }
            else if(resultado==4){
                teleporte=1;
            }
          
           jogo=FantasmaNaCola(jogo,c,l);//botei aqui, pois dentro de posição futura tava entrando em comida e não printando fantasmanacola,por ex

            if(jogo.fancola!='Z'){
                    jogo.mapa.mapa[l][c]=jogo.fancola;
                    entra=0;    //PARA NÃO TROCAR POR ESPAÇO
                }
            
        if(jogo.portal.antigoportal){
                jogo.mapa.mapa[l][c]=PORTAL;
                jogo.portal.antigoportal=0;
                 entra=0; 
            }    

         if(podeentrar){    
                if(entra){
                    jogo.mapa.mapa[l][c]=ESPACO;
                }

            if(mov==ESQUERDA){ //atualizar as posições.       
                    if(somecomida){
                        jogo.matrizcomida[l][c-1]=0;
                        somecomida=0;    
                    } 
                    jogo.mapa.mapa[l][c-1]=PACMAN; //vai receber a futura posição do pacman pra jogar ela no mapa depois
                    jogo.pacman.coluna=jogo.pacman.coluna-1;

            }

            else if (mov==CIMA){  //atualizar as posições.
                    
                    if(somecomida){
                        jogo.matrizcomida[l-1][c]=0;
                        somecomida=0;    
                    } 
                    jogo.mapa.mapa[l-1][c]=PACMAN; 
                    jogo.pacman.linha=jogo.pacman.linha-1;  
            }

            else if (mov==BAIXO){ //atualizar as posições.
                    if(somecomida){
                        jogo.matrizcomida[l+1][c]=0;
                        somecomida=0;    
                    } 
                    jogo.mapa.mapa[l+1][c]=PACMAN;
                    jogo.pacman.linha=jogo.pacman.linha+1;

            }

            else if (mov==DIREITA){  //atualizar as posições.
                    if(somecomida){
                        jogo.matrizcomida[l][c+1]=0;
                        somecomida=0;    
                    } 
                    jogo.mapa.mapa[l][c+1]=PACMAN;
                    jogo.pacman.coluna=jogo.pacman.coluna+1;
            }
             ImprimeJogoAtual(jogo, mov,imprimejogo);
         }
            if(deugameover){
               jogo.resumo.fantasma=1;
               Resumo(jogo,mov,argv,resumo);
               GameOver(jogo,mov,imprimejogo);
               jogo.resumo.fantasma=0;

               if(jogo.imprimenaparede){    
                    jogo.dados.numbatidas++;
                    jogo.resumo.parede=1;
                    Resumo(jogo,mov,argv,resumo);
               }
               jogo.fim=1; 
            }
            else if(teleporte){
                
                 jogo=Teletransporta(jogo);//retorna com o pacman em cima do portal
                 ImprimeJogoAtual(jogo, mov,imprimejogo);//vai printar o pacman no portal
                 teleporte=0; //provavelmente dá pra apagar
                 jogo.portal.antigoportal=1;//para imprimir o portal quando passar por ele

            }
    
    return jogo;
 }

tPartida EhParede(tPartida jogo,char fantasma){ //define o sentido do movimento do fantasma (inverso ou não)
   int lB=jogo.B.linha,cB=jogo.B.coluna,lP=jogo.P.linha,cP=jogo.P.coluna,lI=jogo.I.linha,cI=jogo.I.coluna,
    lC=jogo.C.linha,cC=jogo.C.coluna;
   
       if(fantasma==FANTASMA_ESQUERDA){

        if(jogo.B.inverteu==0){//sentido original

            if(jogo.mapa.mapa[lB][cB-1]==PAREDE){
                    jogo.B.inverteu=1;
            }
        }

        else if(jogo.B.inverteu){//sentido trocado

            if(jogo.mapa.mapa[lB][cB+1]==PAREDE){
                    jogo.B.inverteu=0;
            }
        }

     }

      else if(fantasma==FANTASMA_CIMA){

         if(jogo.P.inverteu==0){//sentido original

             if(jogo.mapa.mapa[lP-1][cP]==PAREDE){
                    jogo.P.inverteu=1;
            }
         }
        else {  // sentido trocado

           if(jogo.mapa.mapa[lP+1][cP]==PAREDE){
                    jogo.P.inverteu=0;
            }
         }
     }
            
      else  if(fantasma==FANTASMA_BAIXO){

        if(jogo.I.inverteu==0){//sentido original

            if(jogo.mapa.mapa[lI+1][cI]==PAREDE){                 
                jogo.I.inverteu=1;
              
            }
        }    
        else {//sentido invertido
             if(jogo.mapa.mapa[lI-1][cI]==PAREDE){     
                jogo.I.inverteu=0;
             }           
          }
      }
        
      else if(fantasma==FANTASMA_DIREITA){

          if(jogo.C.inverteu==0){//sentido original

                if(jogo.mapa.mapa[lC][cC+1]==PAREDE){
                    jogo.C.inverteu=1;
                }   
          }

          else{ //movimento invertido
             if(jogo.mapa.mapa[lC][cC-1]==PAREDE){
                    jogo.C.inverteu=0;
                }   
         }
    }

    return jogo;
}

tPartida EhComida(tPartida jogo, char fan){
    int lB=jogo.B.linha,cB=jogo.B.coluna,lP=jogo.P.linha,cP=jogo.P.coluna,lI=jogo.I.linha,cI=jogo.I.coluna,
    lC=jogo.C.linha,cC=jogo.C.coluna;

        
        if (fan==FANTASMA_BAIXO){
            if(jogo.matrizcomida[lI][cI]==1){//ele está em cima da comida
                jogo.I.emcimacomida=1;
            }
            else {
                jogo.I.emcimacomida=0;
            }
        }
    
        else if(fan==FANTASMA_CIMA){
        if(jogo.matrizcomida[lP][cP]==1){
                jogo.P.emcimacomida=1;
        }
        else {
                jogo.P.emcimacomida=0;
        }
        }
    
        else if (fan==FANTASMA_DIREITA){
            if(jogo.matrizcomida[lC][cC]==1){
                jogo.C.emcimacomida=1;
            }
            else {
                jogo.C.emcimacomida=0;
            }
        }

        else if (fan==FANTASMA_ESQUERDA){
        if(jogo.matrizcomida[lB][cB]==1){
            jogo.B.emcimacomida=1;
        }
        else {
            jogo.B.emcimacomida=0;
        }
    }

    return jogo;
}

tPartida MovimentaFantasma(tPartida jogo){//FALTA ATUALIZAR AS POSIÇÕES E MEXER C A COMIDA
    char fan;
    int lB=jogo.B.linha,cB=jogo.B.coluna,lP=jogo.P.linha,cP=jogo.P.coluna,lI=jogo.I.linha,cI=jogo.I.coluna,
    lC=jogo.C.linha,cC=jogo.C.coluna;

        if (jogo.B.existe){
            
            fan='B';  //ele está comendo a comida(vai pra EhComida na posição futura já).

            jogo=EhComida(jogo,fan);//tem que analisar a posição atual, pois vai printar fantasma, independente

            jogo.B.linA=lB;
            jogo.B.colA=cB;

            if(jogo.B.emcimacomida){
                jogo.mapa.mapa[lB][cB]=COMIDA;
            }
            else {
                jogo.mapa.mapa[lB][cB]=ESPACO;
            }

            jogo=EhParede(jogo,fan);

            if(jogo.B.inverteu==0){//sentido original
                jogo.mapa.mapa[lB][cB-1]=FANTASMA_ESQUERDA;
                jogo.B.coluna=jogo.B.coluna-1;

            }
            else { //mov invertido
                jogo.mapa.mapa[lB][cB+1]=FANTASMA_ESQUERDA;
                 jogo.B.coluna=jogo.B.coluna+1;
            }
        }

        if (jogo.C.existe){
            fan='C';

            jogo=EhComida(jogo,fan);  
            jogo.C.linA=lC;
            jogo.C.colA=cC;

            if(jogo.C.emcimacomida){
                jogo.mapa.mapa[lC][cC]=COMIDA;
            }
            else {
                jogo.mapa.mapa[lC][cC]=ESPACO;
            }

            jogo=EhParede(jogo,fan);

            if(jogo.C.inverteu==0){//mov original
                jogo.mapa.mapa[lC][cC+1]=FANTASMA_DIREITA;
                jogo.C.coluna=jogo.C.coluna+1;
            } 
            else { //mov invertido
                 jogo.mapa.mapa[lC][cC-1]=FANTASMA_DIREITA;
                    jogo.C.coluna=jogo.C.coluna-1;
            }
        }

        if (jogo.I.existe){
            fan='I';
            
            jogo=EhComida(jogo,fan);
            jogo.I.linA=lI;
            jogo.I.colA=cI;

            if(jogo.I.emcimacomida){
                jogo.mapa.mapa[lI][cI]=COMIDA;
            }
            else{
                jogo.mapa.mapa[lI][cI]=ESPACO;

            }
            jogo=EhParede(jogo,fan);

            if(jogo.I.inverteu==0){//mov original
               jogo.mapa.mapa[lI+1][cI]=FANTASMA_BAIXO; 
               jogo.I.linha=jogo.I.linha+1;
            }
            else {
                 jogo.mapa.mapa[lI-1][cI]=FANTASMA_BAIXO;
                 jogo.I.linha=jogo.I.linha-1;
            }   

        }
    
        if (jogo.P.existe){
            
             fan='P';

             jogo=EhComida(jogo,fan);
             jogo.P.linA=lP;
             jogo.P.colA=cP;

              if(jogo.P.emcimacomida){
                jogo.mapa.mapa[lP][cP]=COMIDA;
            }
            else{
                jogo.mapa.mapa[lP][cP]=ESPACO;
            }

             jogo=EhParede(jogo,fan);
             if(jogo.P.inverteu==0){//mov original
                jogo.mapa.mapa[lP-1][cP]=FANTASMA_CIMA;
                jogo.P.linha=jogo.P.linha-1;

             }
             else {//mov inverso
                jogo.mapa.mapa[lP+1][cP]=FANTASMA_CIMA;
                jogo.P.linha=jogo.P.linha+1;
             }
            
        }
           
        return jogo;
     }

tPartida Movimentos(tPartida jogo, char * argv[], FILE * imprimejogo,FILE *resumo){
    int i=0;
    char mov;

    for (i=0;i<jogo.mapa.limjogadas;i++){
       
        jogo=MovimentaFantasma(jogo);//LEMBRAR QUE SEMPRE MOVIMENTA FANTASMA PRIMEIRO

        scanf("%c%*c",&mov);

        jogo.dados.nummovimentos++;
        if(mov==ESQUERDA){//COLUNA ZERO
           // jogo.matrizranking[0][0]=jogo.a.numacoes++;
            jogo.dados.nummoviesquerda++;
            jogo=MovimentaPacMan(jogo,mov,argv,imprimejogo,resumo);

            if(jogo.retorno==1){
                //jogo.matrizranking[1][0]=jogo.a.numcolisoes++;           
            }
            else if(jogo.retorno==2){
               // jogo.matrizranking[2][0]=jogo.a.numalimento++;
            }

        }
        else if (mov==DIREITA){//COLUNA 1
           // jogo.matrizranking[0][1]=jogo.d.numacoes++;
            jogo.dados.nummovidireita++;
            jogo=MovimentaPacMan(jogo,mov,argv,imprimejogo,resumo);

            if(jogo.retorno==1){
              //jogo.matrizranking[1][1]=jogo.d.numcolisoes++;
            }
            else if(jogo.retorno==2){
              // jogo.matrizranking[2][1]=jogo.d.numalimento++;
            }

        }
        else if (mov==CIMA){ //COLUNA 2
           // jogo.matrizranking[0][2]=jogo.w.numacoes++;
            jogo.dados.nummovicima++;
            jogo=MovimentaPacMan(jogo,mov,argv,imprimejogo,resumo);

             if(jogo.retorno==1){
                // jogo.matrizranking[1][2]=jogo.w.numcolisoes++;
            }
            else if(jogo.retorno==2){
                //jogo.matrizranking[2][2]=jogo.w.numalimento;
            }

        }
        else if (mov==BAIXO){ //COLUNA 3
             //jogo.matrizranking[0][3]=jogo.s.numacoes++;
            jogo.dados.nummovibaixo++;
            jogo=MovimentaPacMan(jogo,mov,argv,imprimejogo,resumo);

             if(jogo.retorno==1){
                //jogo.matrizranking[1][3]=jogo.w.numcolisoes++;
            }
            else if(jogo.retorno==2){
                // jogo.matrizranking[2][3]=jogo.w.numalimento;
            }
        }
 
        if(jogo.qntdcomida==jogo.totalcomida){
            jogo = Trilha(jogo);
            ImprimeVitoria(jogo,imprimejogo);
            break;
        }
        if(jogo.fim){//quando dá gameover
            break;
        }
        if(jogo.mapa.limjogadas==jogo.dados.nummovimentos){
             jogo = Trilha(jogo);
            printf("Game over!\nPontuacao final: %d\n",jogo.qntdcomida);
            break;
        }
        jogo = Trilha(jogo);
    }
    return jogo;
}

tFantasma IdentificaFantasma(tPartida partida,char fantasma){
    tFantasma f;
   int i,j,temfan=0,linha=partida.mapa.l,coluna=partida.mapa.c;//INICIALIZAR NO ACHA FANTASMA NA INICIALIZACAO
 

    for (i=0;i<linha;i++){
        for (j=0;j<coluna;j++){
            if(partida.mapa.mapa[i][j]==fantasma){
                f.linha=i;
                f.coluna=j;
                f.existe=1;
                temfan++;
                }
            }
        }
    
    if(temfan==0){
        f.existe=0;
    }
        return f;
}
FILE * InicializaResumo(char * argv[]){
    FILE * resumo;
    char k[1000];
    sprintf(k,"%s/saida/resumo.txt",argv[1]);
    resumo=fopen(k,"w");
    return resumo;
}

FILE * InicializaJogoAtual(char * argv[]){
    FILE * imprimejogo;
    char j[1000];
    sprintf(j,"%s/saida/saida.txt",argv[1]);
    imprimejogo=fopen(j,"w");
    return imprimejogo;
}

tPartida CriaMapaComida(tPartida jogo){
    int i,j,linha=jogo.mapa.l,coluna=jogo.mapa.c;
    
    for (i=0;i<linha;i++){
        for (j=0;j<coluna;j++){

            if(jogo.mapa.mapa[i][j]==COMIDA){
                jogo.matrizcomida[i][j]=1;
                jogo.totalcomida++;
            }
            else {
                jogo.matrizcomida[i][j]=0;
            }
        }
    }
        return jogo;
}

void ImprimeInicializacao(char  * argv[],tPartida partida){
    FILE * inicializacao;
    int i,j;
    char caminho[1000];
        sprintf(caminho,"%s/saida/inicializacao.txt",argv[1]);
        inicializacao= fopen(caminho,"w");

    for (i=0;i<partida.mapa.l;i++){
        for (j=0;j<partida.mapa.c;j++){
            fprintf(inicializacao, "%c",partida.mapa.mapa[i][j]);
        }
        fprintf(inicializacao, "\n");
 
    }
    
    fprintf(inicializacao, "Pac-Man comecara o jogo na linha %d e coluna %d\n",partida.pacman.linha+1,partida.pacman.coluna+1);
   fclose(inicializacao);
} 
tPartida GeraPortal(tPartida jogo){
    int i,j,cont=0;
    for (i=0;i<jogo.mapa.l;i++){
        for (j=0;j<jogo.mapa.c;j++){
            
            if(jogo.mapa.mapa[i][j]==PORTAL){
                if(cont==0){
                    jogo.portal.linhaP1=i;
                    jogo.portal.colunaP1=j;
                    cont++;
                }
                else{
                    jogo.portal.colunaP2=j;
                    jogo.portal.linhaP2=i;
                }
        }
      }
    }
    return jogo;
}

tPacman BuscaPacman(tPartida partida){
    tPacman pm;
    int i,j;

    for (i=0;i<partida.mapa.l;i++){
        for (j=0;j<partida.mapa.c;j++){

            if(partida.mapa.mapa[i][j]==PACMAN){
                pm.linha=i;
                pm.coluna=j;
            }
        }
    }
    return pm;
}

tPartida GeraTrilha(tPartida jogo){
    int i,j;
    for (i=0;i<jogo.mapa.l;i++){
        for (j=0;j<jogo.mapa.c;j++){
            
            if(i==jogo.pacman.linha && j==jogo.pacman.coluna){
                jogo.trilha.trilha[i][j]=0;
            }
            else {
            jogo.trilha.trilha[i][j]=-1;// -1equivale a parede
        }
      }
    }
    return jogo;
}

tMapa LeMapa(char * argv[]){
    FILE * entrada;
    tMapa m;
    int i,j;
    char caminho[1000];
        sprintf(caminho,"%s/mapa.txt",argv[1]);
        entrada= fopen(caminho,"r");
    
    fscanf(entrada, "%d %d %d",&m.l, &m.c, &m.limjogadas);//extraindo as dimensões do mapa pra jogar na matriz.
    fscanf(entrada, "%*c");

    for (i=0;i<m.l;i++){
        for (j=0;j<m.c;j++){
            fscanf(entrada,"%c",&m.mapa[i][j]); //passando tudo pro mapa que eu criei.
        }
        fscanf(entrada,"%*c");
    }
    fclose(entrada);

    return m;
}

tPartida Inicializacao(tPartida jogo,char * argv[]){

        jogo.totalcomida=0;
        jogo.mapa=LeMapa(argv);
        jogo.pacman=BuscaPacman(jogo);
        jogo = GeraTrilha(jogo);
        ImprimeInicializacao(argv,jogo);
        jogo=CriaMapaComida(jogo);//também retorna a quantidade de comida.
        jogo.B=IdentificaFantasma(jogo, FANTASMA_ESQUERDA); //carrega todos os atributos do fantasma
        jogo.C=IdentificaFantasma(jogo, FANTASMA_DIREITA);
        jogo.P=IdentificaFantasma(jogo, FANTASMA_CIMA);
        jogo.I=IdentificaFantasma(jogo, FANTASMA_BAIXO);


        jogo.imprimenaparede=0;
        jogo.qntdcomida=0;
        jogo.fantasma.inverteu=0;
        jogo.dados.numbatidas=0;
        jogo.dados.numsemponto=0;
        jogo.dados.nummovimentos=0;
        jogo.dados.nummovibaixo=0;
        jogo.dados.nummovicima=0;
        jogo.dados.nummovidireita=0;
        jogo.dados.nummoviesquerda=0;
        jogo.trilha.trilha[jogo.pacman.linha][jogo.pacman.coluna]=0;
        jogo.resumo.parede=0;
        jogo.resumo.comida=0;
        jogo.resumo.fantasma=0;      
        jogo.B.linA=0; //é necessário zerar todas as posições antigas, pois estavam dando seg faul ao comparar o gameover
        jogo.C.linA=0;
        jogo.C.colA=0;
        jogo.P.linA=0;
        jogo.P.colA=0;
        jogo.I.linA=0;
        jogo.I.colA=0;
        jogo.B.colA=0;
        jogo.B.linA=0;
        jogo.fim=0;
        jogo.mapa.ehparede=0;
        jogo.B.inverteu=0;
        jogo.C.inverteu=0;
        jogo.I.inverteu=0;
        jogo.P.inverteu=0;
    return jogo;
}
int main (int argc, char  * argv[]){
    tPartida partida;
    if(argc<=1){
        printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
    }
    else{
    partida=Inicializacao(partida,argv);
    FILE * imprimejogo=InicializaJogoAtual(argv);
    FILE * resumo=InicializaResumo(argv);
    partida=Movimentos(partida,argv,imprimejogo,resumo);
    fclose(imprimejogo);
    fclose(resumo);
    Estatistica(partida,argv);
    ImprimeTrilha(partida,argv);
    //Ranking(partida,argv);
    }

return 0;
}