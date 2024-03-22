#include "stack.h"

void reversed_polish_notation (char *c) {
  Stack *s = create(strlen(c));
  int i = 0;

  while (c[i] != '\0') {
   if (c[i]=='+' || c[i]=='*' || c[i]=='/' || c[i]=='-' ){
      push(s,c[i]); //preenchendo a stack só com os sinais
    }  
   
  if (c[i]<=57 && c[i]>=48){//se c for dígito
    printf("%c",c[i]); //vai imprimindo os números.
  }
  else if (c[i]==')'){
    printf("%c",get_peek(s));
    pop(s);
  }
  i++;
}
  destroy(s);
}

int main () {
  char *c = "( 9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )";
  reversed_polish_notation (c);
  return 0;
}
