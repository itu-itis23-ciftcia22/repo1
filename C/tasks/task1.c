#include <stdio.h>


int main()
{
  int barcode;
  printf("Enter a barcode for verfication: ");
  scanf("%d", &barcode);

  int d7,d6,d5,d4,d3,d2,d1;

  d7 = barcode % 10;
  d6 = (barcode/10) % 10;
  d5 = (barcode/100) % 10;
  d4 = (barcode/1000) % 10;
  d3 = (barcode/10000) % 10;
  d2 = (barcode/100000) % 10;
  d1 = (barcode/1000000) % 10;

  printf("%d",d1);
  printf("%d",d2);
  printf("%d",d3);
  printf("%d",d4);
  printf("%d",d5);
  printf("%d",d6);
  printf("%d \n",d7);

  //new value of d5,d3,d1
  d5 *= 2;
  d3 *= 2;
  d1 *= 2;
  if(d5>9) d5 -= 9;
  if(d3>9) d3 -= 9;
  if(d1>9) d1 -= 9;

  int verification_d7 = (d6 + d5+ d4 + d3 + d2 + d1) % 10;


  printf("%d \n",verification_d7);


  if(d7 == verification_d7) printf("Valid");
  else printf("No valid");
  

  return 0;

}