#include <stdio.h>

int main() {

  double g=1;
  long int x;
  int y;

  printf("Hangi tam sayinin karekokunu hesaplamak istersiniz: ");
  scanf("%ld", &x);

  do {
     printf("1 ile 10 arasindan bir sayi seciniz, ne kadar buyuk bir sayi yazarsaniz sonucunuz o kadar dogru olur: ");
     scanf("%d", &y);
  }
  while( y>11 || y<1);

  for(int i=0; i<y ;i++){

    g = (g + x/g) / 2 ; // if An+1 = ( An + x/An ) / 2,  lim n=>infinity An = sqrt(x)

  }

  printf("%ld sayisinin karekoku %.4lf olmalidir.", x, g);
  return 0;
}