#include <stdio.h>


int est_palindrom(char *str, int debut, int fin)
{
    if (debut < fin)
    {
        if (str[debut] == str[fin])
            return est_palindrom(str, debut+1, fin-1);
        else
            return 0;
    }
    return 1;
}

int main()
{
    char *str = "apba";
    if (est_palindrom(str, 0, 3))
        printf("yess");
    else
        printf("no");
    return 0;
}
