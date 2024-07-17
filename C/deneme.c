/*
#include <stdio.h>
#include <limits.h> // INT_MIN kullanımı için

void maxSubArraySum(int arr[], int size) {
    int max_ending_here = 0;
    int max_so_far = INT_MIN;
    int start = 0, end = 0, s = 0;

    for (int i = 0; i < size; i++) {
        max_ending_here += arr[i];

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }

    printf("Maximum subarray sum is: %d\n", max_so_far);
    printf("Subarray: [ ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    maxSubArraySum(arr, size);
    
    return 0;
}*/

#include <stdio.h>
#include <stdarg.h>

// Değişken uzunlukta argüman listesi kabul eden bir fonksiyon
int sum(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int total = 0;
    
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    
    va_end(args);
    
    return total;
}

int main() {
    int result1 = sum(3, 1, 2, 3); // 1 + 2 + 3
    int result2 = sum(5, 1, 2, 3, 4, 5); // 1 + 2 + 3 + 4 + 5
    
    printf("Sum of 1, 2, 3: %d\n", result1);
    printf("Sum of 1, 2, 3, 4, 5: %d\n", result2);
    
    return 0;
}

