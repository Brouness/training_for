#include <stdio.h>


int est_trier(int *tab, int n)
{
    int i = 0;
    while (i < n -1)
    {
        if (tab[i] >= tab[i + 1])
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    int a[] = {1,2,3,4,5,8};
    if (est_trier(a, 8))
        printf("le tableau est trier.");
    else
        printf("le tableau n'est pas trier.");
    return 0;
}