#include <stdio.h>
#include <math.h>

#define SIZE 3


void initialization_array(int arr[],int size)
{
  for(int i = 0; i<size ; i++){
    arr[i]=0;
  }
}

void make_a_disks(int arr[], int size)
{
  for(int i = 0; i<size ; i++){
    arr[i]=(i+1);
  }
}
void print_3_array(int arr1[],int arr2[],int arr3[], int size) {

    for(int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n",arr1[i],arr2[i],arr3[i]);
    }
}

int main() {

  // peg1 => peg3 ; peg2 yardimci
  int peg1[SIZE];
  int peg2[SIZE];
  int peg3[SIZE];

  make_a_disks(peg1,SIZE);
  initialization_array(peg2,SIZE);
  initialization_array(peg3,SIZE);

  print_3_array(peg1,peg2,peg3,SIZE);

  int size = SIZE;
  int peg1_k = -1;
  int peg2_k = size;
  int peg3_k = size;

  for(int i = 1; i < (pow(2,SIZE));i++)
  {
    if(SIZE % 2 == 1){
      if(i % 3 == 1){
        peg1_k++;
        peg3_k--;
        peg3[peg3_k] = peg1[peg1_k];
        peg1[peg1_k] = 0;
        
      }
      else if (i % 3 == 2){
        peg1_k++;
        peg2_k--;
        peg2[peg2_k] = peg1[peg1_k];
        peg1[peg1_k] = 0;
        

      }
      else if (i % 3 == 0){
        peg2_k--;
        peg2[peg2_k] = peg3[peg3_k];
        peg3[peg3_k] = 0;
        
      }
    }
    else {
      if(i % 3 == 1){
        peg2[peg2_k] = peg1[peg1_k];
        peg1[peg1_k] = 0;
        peg1_k++;
        
      }
      else if (i % 3 == 2){
        peg3[peg3_k] = peg1[peg1_k];
        peg1[peg1_k] = 0;
        peg1_k++;
        peg3_k--;
      
      }
      else if (i % 3 == 0){
        peg3[peg3_k] = peg2[peg2_k];
        peg2[peg2_k] = 0;
        peg2_k++;
       
      }
    }
  }
  print_3_array(peg1,peg2,peg3,SIZE);
  return 0;
}