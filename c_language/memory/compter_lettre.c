#include <stdio.h>

void comterLettre(char *str)
{
    int i = 0;
    int voyelle = 0;
    int conssone = 0;
    while (str[i])
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y')
            voyelle++;
        else
            conssone++;
        i++;
    }
    printf("Voyelles = %d, consonnes = %d", voyelle, conssone);
    return;
}

int main()
{
    printf("Entrer une chaine de caractere: ");
    char str[20];
    scanf("%s", str);
    printf("Entree: '%s", str);
    printf("\nSortie: ");
    comterLettre(str);
}