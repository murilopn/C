#include <stdio.h>

char Codifica(char letra, int n, int tipo){
    int num=0;
    n=n%26;
if (tipo==1){//é maiuscula, acrescento 2x      
num=letra+n*2;

if (num>'Z'){
        num= num -'Z';
        num='A'+ num;
           num=num-1;
    }

    return num;
}

else {   //é minuscula
num=letra+n;
    if(num>'z'){
       num= num - 'z';
        num='a'+num;
        num=num-1;
    }
    return num;
}

}

char Decodifica(char letra, int n, int tipo){
    int num=0;
    n=n%26;
if (tipo==1){//é maiuscula, acrescento 2x
       
num=letra-n*2;

    if (num<'A'){
        num= 'A' - num;
        num='Z'- num;
        num=num+1;
    }
    return num;
}
else {   //é minuscula
num=letra-n;
    if(num<'a'){
        num= 'a' - num;
        num='z'- num;
        num=num+1;
    }
    return num;
}
}
int  EhLetra  (char  c){
    if (((c>='a') && (c<='z')) || ((c>='A') && (c<='Z'))){
        return 1;
    }
    else {
        printf("%c",c);
        return 0;
    }

}
int EhLetraMaiuscula (char c){
    if ((c>='A') && (c<='Z')){
        return 1;
    }
    else {
        return 0;

}
}
int main (){
    int modo=0,chave=0,analise=0;
    char frase=0;;
    scanf("%d %d",&modo,&chave);
    while (1){
        scanf("%c",&frase);
        if (frase=='.'){
            printf(".");
            break;
        }
        analise = EhLetra(frase);
        if (analise){
            analise=EhLetraMaiuscula(frase);
                if (modo==1){
                    frase=Codifica(frase,chave,analise);
                }
                else if(modo==2){
                    frase=Decodifica(frase,chave,analise);
            }
                else{
                    printf("Operacao invalida.");
                    break;
                }
              printf("%c",frase);
        }
    }

    return 0;
}