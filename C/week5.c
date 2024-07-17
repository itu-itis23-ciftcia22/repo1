#include <stdio.h>

int main()
{
  char letter = 'F' ;

  printf("Letter is %c\n", letter);

  char digit = '5' ; // char 1 bit oldugu icin daha az yer kapliyor.

  int digit_int = digit - '0' ; // char i int yaptik

  printf("int version of letter is %d\n", digit_int);

  int digit_char = digit + '0' ; 

  printf("char version of letter is %c \n", digit_char);

  return 0;
}