#include <stdio.h>


double puissance(double x, int y)
{
    if (y == 0)
        return 1;
    return x * puissance(x, y - 1);
}

int main()
{
    printf("%f", puissance(10, 2));
}