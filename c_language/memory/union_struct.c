#include <stdio.h>

typedef union struc
{
    int hamid;
    int youness;
} me;

int main()
{
    me one;
    one.hamid = 26;
    printf("this is union variable hamid value %d\n", one.hamid);
    one.youness = 22;
    printf("this is union variable youness value %d\n", one.youness);
    printf("ths is hamid value after initialising youness value %d\n", one.hamid);
    printf("this is the size of this union that have two data type of int %lu\n", sizeof(me));
}
