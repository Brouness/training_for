#include <stdio.h>
#include <unistd.h>


int main()
{
    fork();
    printf("hello this is fork clone of the process, %d.\n", getpid());
    fork();
    printf("second clone of this process. and his id is %d\n", getpid());
}