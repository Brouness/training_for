#include <stdio.h>

int comparer(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
        i++;
    }
    return 0;
}

int main()
{
    char s1[20] = "youness";
    char s2[20] = "youssra";
    printf("la compareson des deux est: %d ", comparer(s2, s1));
}