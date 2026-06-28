#include <stdio.h>

int main()
{
    char str[20];
    printf("Enree: ");
    scanf("%s", str);
    int i = 0;
    while (str[i])
        i++;
    char s2[20];
    int idx = 0;
    while(i >= 0)
    {
        s2[idx] = str[i - 1];
        idx++;
        i--;
    }
    printf("Sortie: %s", s2);
}