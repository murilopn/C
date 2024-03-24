
#include <stdio.h> 
#include <stdlib.h> 
 
void ConcatenaString(char str1[], char str2[], char strOut[]) {
    int i=0;
    while (1){
    if (str1[i]==' '){
        '\0';
        break;
    }
    else{
        strOut=str1; //uma string pode receber outra por inteiro assim mesmo
    }
    i++;
    }

printf("%s%s\n",strOut,str2);

} 




int main(){ 
 char nome[1000]; 
 char sobrenome[1000]; 
 char nomeCompleto[2000]; 
   
 while ( scanf("%s", sobrenome) == 1 && scanf("%s", nome) == 1){ 
  ConcatenaString(nome, sobrenome, nomeCompleto); 
 
}
  
    return 0;     
}