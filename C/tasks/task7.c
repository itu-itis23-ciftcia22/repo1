#include <stdio.h>


void bubble(int arr[],int size) {
    int i, j;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void print_array(int arr[], int size) {

    printf("[");

    for(int i = 0; i < size; i++) {
        printf("%d",arr[i]);
        if(i>=0&&i<size-1){
          printf(",");
        }
    }
    printf("]\n");
}

int main()
{
  
  int size = 0;

  printf("Give a array size: ");
  scanf("%d", &size);
  int arr[size];
  printf("Give a array: ");

  for(int i = 0; i<size; i++)
  {
    scanf("%d", &arr[i]);
  }

  bubble(arr,size);
  print_array(arr,size);

  int target = 0;
  printf("Target Value: ");
  scanf("%d", &target);


  int left_index = 0;
  int right_index = size - 1;
  int middle = (left_index+right_index)/2;

  while(arr[middle] != target){

    if(target == arr[size-1]){
      middle = size - 1;
      break;
    }
    else if(target == arr[0]){
      middle = 0;
      break;
    }

    else if(arr[middle] > target){
      right_index = middle;
    } 
    else if(arr[middle] < target){
      left_index = middle;
    }

    middle = (left_index+right_index)/2;
  }

    printf("%d\n",middle);
      
      int binary=0;
      int iteration=1;
      int remainder;
      while(middle>0){

        remainder = middle % 2;
        binary += remainder*iteration;
        
        middle = middle/2;
        iteration *= 10;
      
      }
      printf("%d sayisi %d(binary). index de bulunmaktadir",target, binary);
      

    return 0;
}