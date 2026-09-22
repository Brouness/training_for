#include <stdio.h>

int somme(int  n)
{
    if (n == 0)
        return 0;
    return n + somme(n - 1);
}

int main()
{
    printf("%d", somme(2));
}