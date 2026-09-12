#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


typedef struct s_shared
{
    int     ready;
    pthread_mutex_t lock;
    pthread_cond_t  cond;
}   t_shared;

void    *waiter_routine(void *args)
{
    t_shared    *ptr = (t_shared *) args;
    printf("Waiter is going to sleep\n");
    pthread_mutex_lock(&ptr->lock);
    while(ptr->ready == 0)
    {
        pthread_cond_wait(&ptr->cond, &ptr->lock);
    }
    pthread_mutex_unlock(&ptr->lock);
    printf("Waiter: woke up, ready is now 1\n");
    return NULL;
} 

void    *notifier_routine(void  *args)
{
    t_shared *ptr = (t_shared *)args;
    printf("Notifier: sleeping for 3 seconds before signaling\n");
    sleep(3);
    pthread_mutex_lock(&ptr->lock);
    ptr->ready = 1;
    pthread_cond_broadcast(&ptr->cond);
    pthread_mutex_unlock(&ptr->lock);
    printf("Notifier: signaled\n");
    return NULL;
}

int main(void)
{
    t_shared    shared;
    shared.ready = 0;
    pthread_mutex_init(&shared.lock, NULL);
    pthread_cond_init(&shared.cond, NULL);
    pthread_t   waiter;
    pthread_t   Waiter_two;
    pthread_t   waiter_three;
    pthread_t   notifier;
    pthread_create(&waiter, NULL, waiter_routine, &shared);
    pthread_create(&waiter_three, NULL, waiter_routine, &shared);
    pthread_create(&Waiter_two, NULL, waiter_routine, &shared);
    pthread_create(&notifier, NULL, notifier_routine, &shared);
    pthread_join(waiter, NULL);
    pthread_join(waiter_three, NULL);
    pthread_join(Waiter_two, NULL);
    pthread_join(notifier, NULL);
    pthread_mutex_destroy(&shared.lock);
    pthread_cond_destroy(&shared.cond);
    return 0;
}