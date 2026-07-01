#include <stdio.h>

void copier(char *dest, char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    return;
}

int main(void)
{
    char tab[20] = "youness";
    char dest[20];
    copier(dest, tab);
    printf("%s", dest);
    return 0;
}