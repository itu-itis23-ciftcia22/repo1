#include <stdio.h>

int main()
{
  int a,b,c;

  printf("Give three integers separated with space:");
  scanf("%d %d %d", &a, &b, &c);

  int d;

  do{
  printf("Which task would you like to perform?\n");
  printf("1 to check if the list is strictly increasing or decreasing\n");
  printf("2 to check if the list is increasing or decreasing\n");   
  printf("3 to compute the maximum number in the list\n");
  printf("4 to reverse the list\n");
  printf("5 to enter a new list of integers\n");
  printf("-1 to terminate the program\n");
       
  scanf("%d",&d);
      if(d<-1 || d==0 || d>5){
          printf("not a defined option, try again\n");
      }
  switch(d){
    case 1: 
    
        if(a < b && b < c)
        {
          printf("strictly increasing\n");
        } else if( a > b && b > c)
        {
          printf("strictly decreasing\n");
        } 
        else printf("none of the two\n");
        break;

    case 2:

        if(a==b && b==c)
        {
          printf("none of the two\n");
        }
        else if(a <= b && b <= c)
        {
          printf("increasing\n");
        }
        else if( a >= b && b >= c)
        {
          printf("decreasing\n");
        } 
        else printf("none of the two\n");
        break;

    case 3:
      if(a>=b && a>=c) printf("the maximum number is %d\n",a);
      else if(b>=a && b>=c) printf("the maximum number is %d\n",b);
      else if(c>=b && c>=a) printf("the maximum number is %d\n",c);
      break;

    case 4:
      printf("%d %d %d\n",c ,b ,a) ;
      break;

    case 5:
      printf("Give three integers separated with space:");
      scanf("%d %d %d", &a, &b, &c);
    break;   

  }
  } while(d != (-1));

  return 0;
}
