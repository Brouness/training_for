#include <stdio.h>
#include <pthread.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;


void *trythis(void* ptr)
{
    pthread_mutex_lock(&lock);
    counter += 1;
    unsigned long i = 0;
    printf("Job %d started\n", counter);
    while (i < 0xFfffff)
        i++;
    printf("Job %d finished\n", counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}


int main()
{
    pthread_mutex_init(&lock, NULL);
    int i = 0;
    while (i < 2)
    {
        pthread_create(&tid[i], NULL, trythis, NULL);
    }
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}
