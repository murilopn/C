#include "stack.h"

int parser (char *c) {
  Stack *s = create(strlen(c));
  int i = 0,cont=0,e=0;
  while (c[i] != '\0') {
    printf("%c",c[i]);
  
  if(c[i]=='(' || c[i]=='['){
   
    push(s,c[i]);
  }

  else if(c[i]==']'){
    e=get_peek(s);
      if(e=='['){
        pop(s);
    }
    else{
      return 0;
    }
  }
  else if(c[i]==')'){
    e=get_peek(s);
      if(e=='('){
        pop(s);
         
      }
      else{
        return 0;
      }
    }
  
    i++;    
  }
  if (empty(s)){ // vai tirar tudo da stack, ou seja, basta conferir o empty
    return 1;
  }
  else{
    return 0;
  }
}


int main () {
  //char *c = "( ( ) [ ( ) ] )";
  //char *c = "( [ ) ]";
  //char *c = "( ) [ ]";
  char *c = "( [ ]";
  //char *c = ") (";
  if (parser(c)) 
    printf("true  (bem formada)\n");
  else  
    printf("false (mal formada)\n");
  return 0;
}
