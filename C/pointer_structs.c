#include <stdio.h>

typedef struct {
    int x;
    int y;
}Point ;

int main()
{
    Point p1 = {10, 20};
    Point *p2 = &p1;

    // İki yöntem de aynı sonucu verir
    printf("p2->x = %d\n", p2->x);     
    printf("(*p2).x = %d\n", (*p2).x);

    return 0;
}