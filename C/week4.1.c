#include <stdio.h>
#include <stdlib.h>

int main ()
{

  const double acilis = 24.75; // tl
  const double unit_basi = 1.76; // tl
  const double unit_uzaklik = 0.1 ; // km
  const double min_ucret = 90; // tl

  double uzaklik = 0;

  printf("Uzakligi gririniz: ");
	scanf("%lf", &uzaklik);

	double price = acilis + (int)(uzaklik / unit_uzaklik) * unit_basi;

  double fare = 0;

  if(price<min_ucret)
  {
     fare = min_ucret;
  }
  else
  {
     fare = price;
  }

	printf("Taxi fare for distance %.2lf km is %.2lf TL\n", uzaklik, fare);

	return EXIT_SUCCESS; // EXIT_FAILURE

}