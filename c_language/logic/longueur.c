#include <stdio.h>


int longueur(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int main()
{
    char str[200];
    printf("Entrer une chaine de caractere: ");
    scanf("%s", str);
    printf("Entrer: '%s'", str);
    printf("\nSortie: %d", longueur(str));
}