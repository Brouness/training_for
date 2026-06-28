#include <stdio.h>

int factorielle(int n)
{
    if (n == 0)
        return 1;
    return n * factorielle(n - 1);
}

int main()
{
    printf("%d", factorielle(5));
}