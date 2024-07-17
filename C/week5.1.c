#include <stdio.h>
#include <stdbool.h>

int main() 
{

  int age = 0;
  int sum = 0;
  int count = 0;

  printf("Enter the number of people: ");
  scanf("%d", &count);

  int num_people_so_far = 0;

  while (num_people_so_far < count)
  {
    num_people_so_far++;

    printf("Enter the age of %d: ",num_people_so_far);
    scanf("%d", &age);

    sum += age;
  }
  
  printf("Average of %d age values is %.3lf\n", count, sum / (double)count);


}