#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
  srand(time(0));

  int deneme7 = 0;
  int anlik_toplam=0;
  int d1=0;
  int d2=0;

  for(int i = 0; i<36000; i++)
  {
    d1 = rand() % 6 + 1;
    d2 = rand() % 6 + 1;
    anlik_toplam = d1+d2;
    if(anlik_toplam == 7){
      deneme7++;
    }
  }

  double oran = deneme7 / (double) 36000;

  printf("%.3lf\n",oran);
  printf("%.3lf", 1/6.0);
}
