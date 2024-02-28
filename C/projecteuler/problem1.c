#include <stdio.h>

int main (){

  int toplam=0;

  for(int i=1 ; i<1000; i++){
    if((i%3==0 || i%5==0)){
      toplam += i;
    }
  }

  printf("1000 e kadar 3'e veya 5'e tam bolunen sayilarin toplami:%d \n", toplam);
  return 0;

}