#include <stdio.h>
#include <math.h>

int main()
{
  unsigned long long int x= pow(2,1000);
  long int toplam = 0;

  for(int i=1;i<=ceil(log10(x));i++)
  {
    toplam += (x%10);
    x /= 10 ;
  }

  printf("%ld", toplam);

}