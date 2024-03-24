# include < stdio .h >
int main ()
 {
 int idade , matricula , cod ;
 float peso ;

 scanf ( "% d " , cod ) ;//SEM &
 scanf ( "% d % f " , & peso , & idade ) ;//IDADE f E PESO d
 scanf ( "% d " , & Matricula ) ; //M EM matricula
 printf ( "% d " , & cod ) ;//COM &

 return 0;
 }