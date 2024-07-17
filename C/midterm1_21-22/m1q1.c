#include <stdio.h>

int main()
{
  int a,b,c;

  printf("Give three integers separated with space:");
  scanf("%d %d %d", &a, &b, &c);

  if(a < b && b < c)
  {
    printf("strictly increasing\n");
  } else if( a > b && b > c)
  {
    printf("strictly decreasing\n");
  } 
  else printf("none of the two\n");

  return 0;
}
