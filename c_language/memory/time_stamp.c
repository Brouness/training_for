#include <sys/time.h>
#include <stdio.h>
struct timeval time;

int main()
{
    
    gettimeofday(&time, NULL);
    printf("this is time in second : %ld\nand this is the time in microsecond %ld\n", time.tv_sec, time.tv_usec);
}