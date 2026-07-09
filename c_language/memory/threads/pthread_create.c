#include <pthread.h>
#include <stdio.h>

void *say_hello(void *arg)
{
    int id = *(int *)arg;
    printf("Hello from thread %d\n", id);
    printf("youness\n");
    printf("youness\n");
    printf("youness\n");
    printf("youness\n");
    printf("youness\n");
    printf("youness\n");
    printf("youness\n");
    printf("youness\n");
    printf("youness\n");
    printf("youness\n");
    printf("youness\n");
    printf("youness\n");

    return NULL;
}

int main(void)
{
    pthread_t thread;
    int id = 1;

    pthread_create(&thread, NULL, say_hello, &id);
    // main() keeps running immediately here, WITHOUT waiting for the thread
    printf("Hello from main\n");

    pthread_join(thread, NULL);  // now main waits for the thread to finish
    printf("hello ne \n");
    return 0;
}