#include <stdio.h>

void yerDegis(int arr[],int a){
  int temp;

  temp = arr[a];
  arr[a] = arr[a+1];
  arr[a+1] = temp;
}

void yazdir(int arr[]) {
    
    for (int i = 0; i < 10; i++) {
        printf(" %d", arr[i]);
    }
   printf("\n");
}

void artan(int arr[]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        // Her geçitte küçük elemanı sona doğru "bubbles" (büyükten küçüğe sıralama için)
        for (j = 0; j < 9-i; j++) {
            if (arr[j] > arr[j+1]) {
                yerDegis(arr,j);
            }
        }
    }
}
void azalan(int arr[]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        // Her geçitte küçük elemanı sona doğru "bubbles" (büyükten küçüğe sıralama için)
        for (j = 0; j < 9-i; j++) {
            if (arr[j] < arr[j+1]) {
                yerDegis(arr,j);
            }
        }
    }
}

int main(){

    int arr[10];
    printf("Enter 10 numbers:");

    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

   
    printf("Original Array:");
    yazdir(arr);

   
    artan(arr);
    printf("Sorted Array(Ascending):");
    yazdir(arr);

    azalan(arr);
    printf("Sorted Array(Descending):");
    yazdir(arr);

    

}


