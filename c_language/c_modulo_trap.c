#include <stdio.h>

int main()
{
    int i = 0;
    char *str = "123456789";
    while(i < 10)
    {
        printf("charachter next: %c\n", str[(i - 1 + 7 )% 9]);
        i++;
    }
    return 0;
}
