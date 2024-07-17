#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice()
{
  srand(time(NULL));

  int dice = 0;
  dice = rand() ;
  return dice;
}

int get_number_from_user(int lowerbound, int upperbound)
{
  int num = 0;

  if(lowerbound>upperbound){
    printf("Lower bound cannot be greater than upper bound");
    return 0;
  }
  do{
        printf("Enter a value between %d and %d: ", lowerbound, upperbound);
        scanf("%d", &num);
    } while(num < 0 || num > upperbound);

    return num;
}
int get_number_from_computer(int lowerbound, int upperbound)
{
  int num = 0;
  do{
        printf("Enter a value between %d and %d: \n", lowerbound, upperbound);
        num = roll_dice();
        printf("computer gives us %d\n", num);
    } while(num < 0 || num > upperbound);

    return num;
}

void print_dash_line(int space_length, int len)
{

  if(space_length<0 || len<0){
    printf("lengths cannot be negative");
  }
  
  for(int i = 0; i< len; i++)
  {
    printf("-");
    for(int j = 0; j< space_length; j++)
    {
        printf(" ");
    }
  }
  printf("\n");
}

int main()
{
    srand(time(NULL));

    int hour = 0, minute = 0, month = 0;;

    print_dash_line(2,15);
    hour = get_number_from_user(0,23);
    print_dash_line(1,30);
    minute = get_number_from_user(0,59);
    print_dash_line(3,10);
    month = get_number_from_user(1,12);
    print_dash_line(6,5);

    printf("the time that you are entered is %d:%d \n", hour, minute);
    printf("month is %d\n", month);

    return 0;
}