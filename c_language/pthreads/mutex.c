// MUTEX SHARED COUNTER RACE!!!!!
// data type pthread_mutex_t


#include <pthread.h>
#include <stdio.h>
pthread_mutex_t   lock;
typedef struct s_shared
{
    long    counter;
    int     inrements_per_thread;
    
} t_shared;


void    *start_routine(void *arg)
{
    t_shared    *ptr = (t_shared *)arg;
    int i = 0;
    while(i < ptr->inrements_per_thread)
    {
        pthread_mutex_lock(&lock);
        ptr->counter = ptr->counter + 1;
        pthread_mutex_unlock(&lock);
        i++;
    }
    return NULL;
}

int main()
{
    pthread_t   threads[4];
    t_shared shared;
    shared.counter = 0;
    pthread_mutex_init(&lock, NULL);
    shared.inrements_per_thread = 1000000;
    pthread_create(&threads[0], NULL, start_routine, &shared);
    pthread_create(&threads[1], NULL, start_routine, &shared);
    pthread_create(&threads[2], NULL, start_routine, &shared);
    pthread_create(&threads[3], NULL, start_routine, &shared);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);
    printf("THIS IS THE COUNTER AFTER ALL 4 THREADS FINISH: [%ld]\n", shared.counter);
    pthread_mutex_destroy(&lock);
}