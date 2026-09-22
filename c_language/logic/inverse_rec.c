#include <stdio.h>

int inverse(int n)
{
    // int last_n = n % 10;
    // int rest = n / 10;
    if (n != 0)
        return printf("%d\n", n % 10);
    return 1;
}

int main()
{
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);
    printf("Bfore: %d\n", n);
    printf("After: \n%d", inverse(n));
}