#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Define the triangle
int triangle[15][15] = {
    {75},
    {95, 64},
    {17, 47, 82},
    {18, 35, 87, 10},
    {20, 04, 82, 47, 65},
    {19, 01, 23, 75, 03, 34},
    {88, 02, 77, 73, 07, 63, 67},
    {99, 65, 04, 28, 06, 16, 70, 92},
    {41, 41, 26, 56, 83, 40, 80, 70, 33},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
    {63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
    {04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23}
};

int triangle_size = 15;

int maxPathSum() {
    // Dinamik programlama için geçici bir dizi oluşturuyoruz
    int temp[15][15];

    // Üçgenin en alt satırından başlayarak temp dizisini dolduruyoruz
    for (int i = 0; i < triangle_size; i++) {
        temp[triangle_size - 1][i] = triangle[triangle_size - 1][i];
    }

    // Geriye doğru ilerleyerek maksimum yol toplamını buluyoruz
    for (int i = triangle_size - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            temp[i][j] = triangle[i][j] + MAX(temp[i + 1][j], temp[i + 1][j + 1]);
        }
    }

    // En üstteki eleman temp[0][0]'da olacak
    return temp[0][0];
}

int main() {
    int result = maxPathSum();
    printf("Maximum path sum in the triangle is: %d\n", result);
    return 0;
}
