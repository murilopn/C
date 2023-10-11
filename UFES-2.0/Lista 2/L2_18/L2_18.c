#include <stdio.h>
int main () {

int l=0,c=0,flagsair=0, contl=0,contc=0,maior=-32766,num=0,posicaoc=0,posicaol=0;

scanf ("%d %d",&l,&c);

if (l>100){
    l=-1;
}
else if (l<1){
    l=-1;
}

if (c>100){
    c=-1;
}
else if (c<1){
    c=-1;
}

while (contl<l){
contc=0;
contl++;

    while(contc<c){
        scanf("%d",&num);
        
        if (-32767>num || num>32767){
        flagsair=1;
        break;}        

        contc++;
        if (num>maior){
            maior=num;
            posicaoc=contc;
            posicaol=contl;}
    }
    if (flagsair){
    break;}

}
    if ((l==-1) || (c==-1)){
    return 0;
}
    if (flagsair==0){
    printf("%d (%d, %d)",maior,posicaol,posicaoc);
    }
    return 0;
}