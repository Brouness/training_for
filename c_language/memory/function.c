#include <stdio.h>
#include <stdlib.h>
void    tableua_de_multiplication(int number)
{
    int i = 0;
    printf("La multiplication de %d\n", number);
    while (i <= 10)
    {
        printf("%d x %d = %d\n", i, number, i*number);
        i++;
    }
}

int main(int c, char **v)
{
    int n = atoi(v[1]);
    tableua_de_multiplication(n);
}