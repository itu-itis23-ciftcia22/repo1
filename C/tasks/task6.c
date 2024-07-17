#include <stdio.h>
#include <math.h>


int main ()
{
  int sayi = 0;

  printf("Enter a number: ");
  scanf("%d", &sayi);
  
  int temp = sayi;

  int basamak_sayisi = ceil(log10(sayi));

  printf("basamak sayisi =%d\n", basamak_sayisi);

  int basamak = 0;
  int toplam = 0;

  while(sayi<10){
  for(int i = 0; i <= basamak_sayisi-1 ; i++)
  {
    basamak = (sayi/(int)pow(10,i)) % 10;

    if(i % 6 == 1){
      toplam += basamak;
    }
    else if(i % 6 == 2){
      toplam += 3*basamak;
    }
    else if(i % 6 == 3){
      toplam += 2*basamak;
    }
    else if(i % 6 == 4){
      toplam -= 3*basamak;
    }
    else if(i % 6 == 5){
      toplam -= 2*basamak;
    }
    else if(i % 6 == 0){
      toplam -= 3*basamak;
    }
  }

  while(toplam<0){
    toplam += 7;
  }

  sayi = toplam;
  basamak_sayisi = ceil(log10(sayi));
  }

  int kalan = sayi % 7;

  if(kalan == 0){
  printf("The number %d is divisible by 7. Because the remainder is %d",temp,kalan);
  }
  else {
  printf("The number %d is not divisible by 7. Because the remainder is %d",temp,kalan);
  }

  return 0;
  
}