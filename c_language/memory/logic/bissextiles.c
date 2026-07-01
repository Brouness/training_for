#include <stdio.h>

int main()
{
    int annee = 0;
    printf("entrez une annee pour savoir si est elle bissextiles ou non: ");
    scanf("%d", &annee);
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0))
    {
        printf("%d est une annee bissextille", annee);
        return 0;
    }
    else
    {
        printf("%d n'est pas une annee bissextille", annee);
    }

}