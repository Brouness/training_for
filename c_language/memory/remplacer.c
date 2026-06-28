#include <stdio.h>

void rempalacer(char *str, char a, char b)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == a)
            str[i] = b;
        i++;
    }
    printf("%s", str);
    return;
}

int main()
{
    char s1[20];
    char a, b;
    printf("Entrer: "),
    scanf("%s %c %c", s1, &a, &b);
    printf("Sortie: ");
    rempalacer(s1, a, b);
}