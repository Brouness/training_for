#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>

struct timeval tv;
struct timespec ts;

typedef struct s_shared
{
    int             ready;
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
}   t_shared;

typedef struct s_thread_args
{
    t_shared    *ptr;
    int         id;
}   t_thread_args;

void    *start_waiting(void *args)
{
    t_thread_args *ptr = ( t_thread_args *) args;
    printf("The waiter thread %d start waiting\n", ptr->id);
    pthread_mutex_lock(&ptr->ptr->mutex);
    gettimeofday(&tv, NULL);
    ts.tv_sec = tv.tv_sec + 3;
    ts.tv_nsec = tv.tv_usec * 1000;
    while (ptr->ptr->ready != 1)
    {
        printf("The waiter is sleeping...\n");
        int rc = pthread_cond_timedwait(&ptr->ptr->cond, &ptr->ptr->mutex, &ts);
        if (rc == ETIMEDOUT)
        {
            printf("time out the waiter will wake up\n");
            break;
        }
    }
    printf("The waiter just woke up\n");
    pthread_mutex_unlock(&ptr->ptr->mutex);
    return NULL;
}

void    *start_notifie(void *args)
{
    t_thread_args   *ptr = (t_thread_args *) args;
    printf("The notifier is going to sleep some seconds then notifie waiters\n");
    printf(". . .\n");
    sleep(3);
    pthread_mutex_lock(&ptr->ptr->mutex);
    pthread_cond_signal(&ptr->ptr->cond);
    printf("The notifier woke the waiter up\n");
    ptr->ptr->ready = 1;
    pthread_mutex_unlock(&ptr->ptr->mutex);
    return NULL;
}

int main()
{
    t_shared        shared;
    t_thread_args   args;
    pthread_t       notifier;
    pthread_t       first_waiter;
    pthread_t       second_waiter;
    pthread_t       theard_waiter;

    args.id = 1;
    args.ptr = &shared;
    shared.ready = 0;
    pthread_cond_init(&shared.cond, NULL);
    pthread_mutex_init(&shared.mutex, NULL);
    pthread_create(&first_waiter, NULL, start_waiting, &args);
    pthread_create(&notifier, NULL, start_notifie, &args);
    pthread_join(first_waiter, NULL);
    pthread_join(notifier, NULL);
    return 0;
}