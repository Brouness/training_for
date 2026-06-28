#include <stdio.h>

int main()
{
    int somme = 0;
    int idx = 0;
    int tab[] = {1,2,3,4,5,6,7,8,9,10};
    while (idx < sizeof(tab) / 4)
    {
        somme = somme + tab[idx];
        idx++;
    }
    printf("%d", somme);
    return 1;
}