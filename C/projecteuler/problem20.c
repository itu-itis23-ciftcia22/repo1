#include <stdio.h>

#define MAX_DIGITS 200 // Maximum number of digits in the factorial of 100

// Function to calculate factorial of a number and store the result in an array
void calculateFactorial(int n, int result[]) {
    int i, j, carry, temp;
    result[0] = 1; // Initialize the result as 1 (factorial of 1)

    for (i = 2; i <= n; i++) {
        carry = 0;
        for (j = 0; j < MAX_DIGITS; j++) {
            temp = result[j] * i + carry;
            result[j] = temp % 10;
            carry = temp / 10;
        }
    }
}

// Function to calculate the sum of digits in an array
int sumOfDigits(int result[]) {
    int sum = 0;
    for (int i = 0; i < MAX_DIGITS; i++) {
        sum += result[i];
    }
    return sum;
}

int main() {
    int n = 100;
    int factorial[MAX_DIGITS] = {0};

    calculateFactorial(n, factorial);
    int sum = sumOfDigits(factorial);

    printf("Sum of the digits in %d! is: %d\n", n, sum);

    return 0;
}
