#include <stdio.h>

// Fonksiyon: Bir sayının bölenlerinin toplamını hesapla
int sum_of_divisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

// Fonksiyon: Dost sayıları bul ve toplamlarını hesapla
long find_amicable_numbers(int limit) {
    long sum = 0;
    int div_sum;

    for (int a = 1; a < limit; a++) {
        div_sum = sum_of_divisors(a);
        if (div_sum > a && sum_of_divisors(div_sum) == a) {
            sum += a + div_sum;
        }
    }

    return sum;
}

int main() {
    int limit = 10000;
    long result = find_amicable_numbers(limit);

    printf("Problem 21 için dost sayıların toplamı: %ld\n", result);

    return 0;
}
