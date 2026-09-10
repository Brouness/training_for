#include <stdio.h>
#include <sys/time.h>

long    get_time_fn(void)
{
    struct  timeval time;
    long    curent_time;

    if (gettimeofday(&time, NULL))
        return (-1);
    curent_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return (curent_time);
}
int main()
{
    long x = get_time_fn();
    printf("This is the time of day in sec %lu\n", x);

}