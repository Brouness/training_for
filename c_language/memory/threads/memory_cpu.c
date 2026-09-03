struct cpu
{
    int     *ponter;
    char    character;
    int     ubtl;
    int     dsj;
}  __attribute__((packed));
#include <stdio.h>
int main()
{
    struct cpu i5;
    printf("This is the memory of cpu Type: %lu", sizeof(struct cpu));
}
