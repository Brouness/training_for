#include <stdio.h>

int nchiffres(long n)
{
    int length = 0;
    if (n < 0)
        n = -n;
    else if (n == 0)
        return 1;
    while (n != 0)
    {
        n = n / 10;
        length++;
    }
    return length;
}


int main()
{
    long z;
    printf("Introduire un nombre entier: ");
    scanf("%ld", &z);
    printf("Le nombre %ld contient %d chiffres.", z, nchiffres(z));
}
