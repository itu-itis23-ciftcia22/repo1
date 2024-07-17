#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void make_an_array(int arr[],int size)
{
  for(int i=0; i<size ;i++)
  {
    arr[i] = (rand() % 10) + 1;
  }
}

void print_array(int arr[], int size) {

    for(int i = 0; i < size; i++) {
        printf("%d\n",arr[i]);
    }
}

int finding_frequency(int arr[],int size,int point){

  int frequency = 0;

  for(int i = 0; i<size; i++) {
    if(arr[i] == point){
      frequency++;
    }
  }
  return frequency;
}

int main() {

  srand(time(0));
  int points[40] = {0};

  make_an_array(points,40);

  printf("Rating\tFrequency\n");
  for(int i = 1; i<=10; i++){
    printf("%6d\t%9d\n",i,finding_frequency(points,40,i));
  }
  double sum = 0;
  for(int i = 1; i<=10; i++){
    sum += i*finding_frequency(points,40,i);
  }

  printf("avg of rating: %.2lf", sum/40);
  

  return 0;
}