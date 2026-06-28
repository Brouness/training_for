#include <stdio.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
int is_prime(int i)
{
    int prime = 0;
    int idx = 1;
    while(idx <= i)
    {
        if(i % idx == 0)
           prime++;
        idx++;
    }
    if (prime > 2)
        return 0;
    else if (prime == 2)
        return 1;
    return 0;
}

void prime(void)
{
    int i = 0;
    while (i < 100)
    {
        if (!is_prime(i) && i != 0 && i != 1)
        {
            printf(GREEN "%d est un nombre compose" RESET "\n", i);
        }
        else
            printf(RED "%d est un nombre premier" RESET "\n", i);
        i++;
    }
}
int main(){
    prime();
}