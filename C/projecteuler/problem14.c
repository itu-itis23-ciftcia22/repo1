#include <stdio.h>


int main (){

  long baslangic, cevap;
  long long sayi;
  int terim_sayisi;
  int max_terim=0;
  

  for(baslangic=2; baslangic<1000000; baslangic++)
  {
    terim_sayisi=1;
    sayi=baslangic;

    while(sayi>1)
    {
      while(sayi%2==0)
      {
        sayi /=2 ;
        terim_sayisi++;
      }
      if(sayi>1)
      {
        sayi = (sayi*3) + 1;
        terim_sayisi++;
      }
    }
    if(terim_sayisi>max_terim){
      max_terim = terim_sayisi;
      cevap = baslangic;
    }
  }

  printf("%d %ld",max_terim, cevap);


}