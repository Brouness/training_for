#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


typedef struct s_dongle{
    int is_available;
    int  e;
    int b;
} t_dongle;

void *say_hello(void *args)
{
    t_dongle *arg = (t_dongle *)args;
    if (arg->is_available)
    {    printf("Dongle is available\n");
        arg->is_available = 0;}
    else
        printf("Dongle is not available\n");
    return NULL;
}


int main()
{
    t_dongle dongle;
    // printf("size of dongle is: %d\n", sizeof(dongle));
    dongle.is_available = 1;
    pthread_t t;
    pthread_t yy;
    pthread_create(&t, NULL, &say_hello, &dongle);
    pthread_create(&yy, NULL, &say_hello, &dongle);
    pthread_join(t, NULL);
    pthread_join(yy, NULL);
    return 1;
}