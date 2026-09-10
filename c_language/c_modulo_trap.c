#include <stdio.h>

int main()
{
    int i = 0;
    char *str = "youness";
    while(i < 10)
    {
        printf("charachter next: %c\n", str[(i - 1 + 7 )% 7]);
        i++;
    }
    return 0;
}
