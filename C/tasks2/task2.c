#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int main()
{

  char* date = (char*) malloc( 10 * sizeof(char));

  puts("Enter a date");
  fgets(date,11,stdin);

  char* gun = strtok(date, "/");
  char* ay = strtok(NULL, "/");
  char* yil = strtok(NULL, "/");

  printf("%s\n",gun);
  printf("%s\n",ay);
  printf("%s\n",yil);

  int ay_int = atoi(ay);
  

  switch(ay_int)
  {
    case 1: printf("January"); break;
    case 2: printf("February"); break;
    case 3: printf("March"); break;
    case 4: printf("April"); break;
    case 5: printf("May"); break;
    case 6: printf("June"); break;
    case 7: printf("July"); break;
    case 8: printf("August"); break;
    case 9: printf("September"); break;
    case 10: printf("October"); break;
    case 11: printf("November"); break;
    case 12: printf("December"); break;
  }
  printf(" %s, ",gun);
  printf("%s\n",yil);

  free(date);

  return 0;
}