
#include <stdio.h>

int main(){
  
    int Num = 1;
    while (1) {
        int divisible = 1;
        for (int i = 1; i <= 20; i++) {
            if (Num % i != 0) {
                divisible = 0;
                break;
            }
        }
        if (divisible) {
            printf("%d\n", Num);
            break;
        }
        Num++;
    }
    return 0;
}