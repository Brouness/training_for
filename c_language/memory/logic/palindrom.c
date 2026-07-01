#include <stdio.h>

int palindrom(char *str)
{
    char *v = str;
    int i = 0;
    while(v[i])
        i++;
    if (i == 1)
        return 1;
    int idx = 0;
    int len = i;
    while(idx < i)
    {
        if (v[i - 1] == str[idx])
        {
            i--;
            idx++;
        }
        else
            return 0;
    }
    return 1;
}

int main()
{
    char str[200];
    printf("Entre une chaine de caractere : ");
    scanf("%s", str);
    if (palindrom(str))
        printf("la chaine %s ext un palindrom.", str);
    else
        printf("la chaine %s n'ext pas une palindrom.", str);
}