#include <stdio.h>
#include <stdlib.h>

void get_subarray(int *array, int startIndex, int subarraySize, int *subarray) {
    for (int i = 0; i < subarraySize; i++) {
        subarray[i] = array[startIndex + i];
    }
}

void print_array(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]");
}

void print_all_subarrays(int*** subarray, int size){
    for(int i = 0; i < size ; i++){
        for(int j = 0; j < size - i ; j++){
            print_array(subarray[i][j],i+1);
            if(j != size - i -1) printf(",");
        }
        printf("\n");
    }
}

int sum_array(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size = 0;
    printf("Enter a size of array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid size. Size must be positive.\n");
        return 1;
    }

    int*** sub_arrays = (int***) malloc(sizeof(int**) * size);

    if (sub_arrays == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        sub_arrays[i] = (int**) malloc(sizeof(int*) * (size - i));

        if (sub_arrays[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        for (int j = 0; j < size - i; j++) {
            sub_arrays[i][j] = (int*) malloc(sizeof(int) * (i + 1));

            if (sub_arrays[i][j] == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }

            // Başlangıç değerlerini sıfırla
            for (int k = 0; k < i + 1; k++) {
                sub_arrays[i][j][k] = 0;
            }
        }
    }

    printf("Memory allocation successful.\n");

    int *arr = (int*) malloc(sizeof(int) * size);
    printf("Enter a array:");
    for(int i = 0; i<size ; i++){
        scanf("%d",(arr+i));
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i ; j++){
            get_subarray(arr,j,(i+1),sub_arrays[i][j]);
        }
    }

    print_all_subarrays(sub_arrays, size);

    int max = sum_array(sub_arrays[0][0],1);
    int index_x,index_y;
    for(int i = 0; i<size; i++){
      for(int j = 0; j<size-i;j++){
        if(sum_array(sub_arrays[i][j],i+1)>max){
          max = sum_array(sub_arrays[i][j],i+1);
          index_x = i;
          index_y = j;
        }
      }
    }
    print_array(sub_arrays[index_x][index_y],index_x+1);
    printf(" sum of this array is %d\n",max);

    // Belleği serbest bırak
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            free(sub_arrays[i][j]);
        }
        free(sub_arrays[i]);
    }
    free(sub_arrays);
    return 0;
}
