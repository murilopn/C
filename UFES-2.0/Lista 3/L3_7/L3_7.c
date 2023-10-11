#include <stdio.h>

int area (int x1, int y1, int x2, int y2){
    int base=0,altura=0,area=0;

    base=x2-x1;
    altura=y2-y1;
    area=base*altura;
    
    if (base*altura<0){
        area=area*(-1);
    }
    return area;
}

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2) {
int area1=0,area2=0,area3=0,area4=0;
if ((r1_x1<=r2_x1) && (r1_x2>=r2_x1)){  //quer dizer q a base do segundo está dentro da base do primeiro
      if ((r1_y2==r2_y1) || (r1_y2==r2_y2)){
        r2_x1=r1_x2;                             //se os pontos de y são iguais (nao vai ficar nada sobrando)
      }
      else {

      }                                         
}
if ((r1_<=r2_y1) && (r1_y2>=r2_y1)){
        r2_y1=r1_y2;
}
    area1=area(r1_x1,r1_y1,r1_x2,r1_y2);
    area2=area(r2_x1,r2_y1,r2_x2,r2_y2);
 
    printf("RESP:%d",area1+area2);

}
int main () {
    int XIE1=0,YIE1=0,XSD1=0,YSD1=0;
    int xie2=0,yie2=0,xsd2=0,ysd2=0;

scanf("%d %d %d %d",&XIE1,&YIE1,&XSD1,&YSD1);
scanf("%d %d %d %d",&xie2,&yie2,&xsd2,&ysd2);

area_total (XIE1,YIE1,XSD1,YSD1,xie2,yie2,xsd2,ysd2);

    return 0;
}
