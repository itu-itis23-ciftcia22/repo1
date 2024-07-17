#include <stdio.h>

void print_array(int arr[], int size) {

    for(int i = 0; i < size; i++) {
        printf("%d\n",arr[i]);
    }
}


int main()
{
  int min=0;
  int temp=0;

  int size;

  printf("Enter size of array: ");
  scanf("%d", &size);


  int arr[size];

  printf("Enter a values: ");
  
  for(int i = 0; i<size; i++)
  {
    scanf("%d",&arr[i]);
  }

  int i,j;

  for(i = 0; i<size-1; i++){

    min = i;

    for(j = i+1; j<size; j++){
      if(arr[j]<arr[min]){
        min = j;
      }
    }
    
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }

  print_array(arr,size);

}