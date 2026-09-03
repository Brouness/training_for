#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

void    *say_hello(void *arg)
{
    int id = *(int *) arg;
    printf("Hello from thread %d\n", id);
    printf("This binary was compiled on %s at %s\n", __DATE__, __TIME__);
    return NULL;
}

int main()
{
    pthread_t t[3];
    int id[3] = {1,2,3};
    int i = 0;
    while (i < 3)
    {
        pthread_create(&t[i], NULL, say_hello, &id[i]);
        i++;
    }
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);
   
    printf("The size of pthread is: %d", sizeof(t)); return 0;
}
