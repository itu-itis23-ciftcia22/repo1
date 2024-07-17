#include <stdio.h>


void print_array(int nums[], int size) {

    for(int i = 0; i < size; i++) {
        printf("arr[%d] = %d", i, nums[i]);

        if (i < (size - 1)) {
            printf(" | ");
        } else {
            printf("\n");
        }
    }

}

void print_2D_array(int nums[][3], int num_rows, int num_cols) { 
    for(int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("nums[%d][%d]: %d", i, j, nums[i][j]);
            if (j < num_cols - 1) {
                printf(" | ");
            } else {
                printf("\n");
            }
        }
    }
}


int remove_element_value(int nums[], int size, int value_to_remove) {

    for (int i = 0; i < 0; i++) {
        if (nums[i] == value_to_remove) {
            nums[i] = nums[size-1];
            size--; 
        }
    }

    return size; 
}

int remove_element_at_index(int nums[], int size, int removal_index) {

    if (removal_index < size && removal_index >=0) {
        nums[removal_index] = nums[size-1];
        size--;
    }   
    
    return size; 
}

int find_minimum_value(int nums[], int size) {
    int lowest = nums[0];

    for (int i = 1; i < size; i++) { 
        if (nums[i] < lowest) {
            lowest = nums[i];
        }
    }
    return lowest;
}

int find_minimum_value_index(int nums[], int size) {
    int lowest = 0;

    for (int i = 1; i < size; i++) { 
        if (nums[i] < nums[lowest]) {
            lowest = i;
        }
    }
    return lowest;
}

float compute_avg(int nums[], int size) {
    float avg = 0;

    int total = 0;

    for (int i = 0; i < size; i++) {
        total += nums[i];
    }

    avg = total / (float)size;

    return avg; 
}



void swap_array_elements(int nums[], int element_ix1, int element_ix2) {
    int temp = nums[element_ix1];
    nums[element_ix1] = nums[element_ix2];
    nums[element_ix2] = temp;
}


// MAIN 3: 
#define NUM_COUNTRIES 2
#define NUM_MEDAL_TYPES 3

int main() {
    
    int medals[NUM_COUNTRIES][NUM_MEDAL_TYPES] = { {5, 2, 6}, {2, 0, 3}};

    print_2D_array(medals, NUM_COUNTRIES, NUM_MEDAL_TYPES);
    
    return 0;
}




// MAIN 2: 
// int main() {
//     int capacity = 10; // extra : ilk 4 unun yerini degistirmek icin 
//     int coin_count = 10;
//     int coins[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//     print_array(coins, coin_count);

//     coin_count = 4; // extra
//     int ix1 = 0, ix2 = coin_count / 2;
//     while (ix1 < coin_count / 2) {
//         swap_array_elements(coins, ix1, ix2);
//         ix1++;
//         ix2++;
//     }

//     // print_array(coins, coin_count);
//     print_array(coins, capacity); // extra

//     return 0;
// }


// MAIN 1: 
// int main() {

//     const int MAXIMUM_SIZE = 100;
//     int grade;
//     int grades[MAXIMUM_SIZE];
//     int index = 0;

//     // get quiz grades for a student
//     do {
//         printf("Enter a grade between 0 and 100 (-1 to exit): ");
//         scanf("%d", &grade);

//         if (grade == -1) {
//             break;
//         } else if (grade <= 100 && grade >= 0) {
//             grades[index] = grade;
//             index++;

//             print_array(grades, index);
//         } else {
//             printf("Invalid grade!\n");
//         }
//     } while (index < MAXIMUM_SIZE);

//     print_array(grades, index);

//     // find the lowest grade
//     // int minimum = find_minimum_value(grades, index);
//     int minimum = find_minimum_value_index(grades, index);

//     // eliminate the lowest quiz grade
//     // index = remove_element_value(grades, index, minimum); 
//     index = remove_element_at_index(grades, index, minimum); 

//     print_array(grades, index);

//     // compute the avg quiz grade

//     float avg_grade = compute_avg(grades, index);
//     printf("Average grade: %.1lf\n", avg_grade);

//     return 0;
// }