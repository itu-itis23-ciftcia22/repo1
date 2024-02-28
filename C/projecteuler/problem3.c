#include <stdio.h>
#include <stdbool.h>

/*The prime factors of 13195 are 5, 7, 13 and 29. What is the largest prime factor of the number 600851475143 ?*/

int isPrimeFactor (int n)
{
    int i, k=1;
    for (i=2; i<=n && k <= 2; i++)
    {
        if (n % i == 0)
            k++;
    }
    return k == 2;
}

int main()
{
    int i=1, Largest_Prime_Factor = 1, Value_of_LPF = Largest_Prime_Factor <= i;
    unsigned long long NUMBER = 600851475143ULL;

    for (i=2; i<=NUMBER; i++)
    {
        if ((NUMBER % i == 0) && (isPrimeFactor(i)) == true)
        {
            Largest_Prime_Factor = (Value_of_LPF) ? i : Largest_Prime_Factor ;
            NUMBER/=i;//Once we find a prime factor, we reduce the value of NUMBER
        }
    }
    printf ("%d", Largest_Prime_Factor);
}
