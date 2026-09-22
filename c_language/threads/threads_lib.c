#include <pthread.h>
#include <stdio.h>


void *print_message_function(void *ptr)
{
    char *message = (char *)ptr;
    printf("%s\n", message);
    return NULL;
}

int main()
{
    pthread_t youness_1, youness_2;
    char *message_1 = "youness is the goat";
    char *message_2 = "youness is humble";
    int mini_me_1, mini_me_2;
    mini_me_1 = pthread_create(&youness_1, NULL, print_message_function, (void *)message_1);
    mini_me_1 = pthread_create(&youness_2, NULL, print_message_function, (void *)message_2);
    pthread_join(youness_1, NULL);
    pthread_join(youness_2, NULL);
    printf("youness 1 returns: %d\n", mini_me_1);
    printf("youness 2 returns: %d\n", mini_me_2);
    return (0);
}