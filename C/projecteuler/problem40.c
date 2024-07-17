#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getChampernowneDigit(int n) {
    int length = 0;
    int number = 1;
    char buffer[10];

    // Loop to find the number where the nth digit is located
    while (length < n) {
        sprintf(buffer, "%d", number);
        length += strlen(buffer);
        number++;
    }

    // Create the Champernowne constant up to the required length
    char *champernowne = (char *)malloc(length + 1);
    champernowne[0] = '\0';

    for (int i = 1; i < number; i++) {
        sprintf(buffer, "%d", i);
        strcat(champernowne, buffer);
    }

    // Extract the nth digit
    int digit = champernowne[n - 1] - '0';

    // Clean up
    free(champernowne);

    return digit;
}

int main() {
    int positions[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
    int product = 1;

    // Calculate the product of the digits at the specified positions
    for (int i = 0; i < 7; i++) {
        int digit = getChampernowneDigit(positions[i]);
        product *= digit;
        printf("Digit at position %d: %d\n", positions[i], digit);
    }

    printf("Product of the digits: %d\n", product);
    return 0;
}
