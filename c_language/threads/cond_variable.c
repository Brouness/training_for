#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_cond_variable
{
    int only_one;
    pthread_cond_t  cond_variable;
    pthread_mutex_t mutex;
} t_cond_variable;

void    *fn_meme(void *ptr)
{
    t_cond_variable *meme = (t_cond_variable *) ptr;

    while (meme->only_one == 0)
    {
        pthread_cond_wait(&meme->cond_variable, &meme->mutex);
    }
    printf("hi slimi you just signal me\n");
    meme->only_one = 0;
    pthread_cond_signal(&meme->cond_variable);
    while (meme->only_one == 0)
    {
        pthread_cond_wait(&meme->cond_variable, &meme->mutex);
    }
    printf("Good thanks and you ?\n");
    meme->only_one = 0;
    pthread_cond_signal(&meme->cond_variable);
    while (meme->only_one == 0)
    {
        pthread_cond_wait(&meme->cond_variable, &meme->mutex);
    }
    printf("okey good by meme :)\n");
    return NULL;
}

void    *fn_slimi(void *ptr)
{
    t_cond_variable *slimi;

    slimi = (t_cond_variable *) ptr;
    printf("Hey meme wake up...\n");
    slimi->only_one = 1;
    pthread_cond_signal(&slimi->cond_variable);
    while(slimi->only_one == 1)
    {
        pthread_cond_wait(&slimi->cond_variable, &slimi->mutex);
    }
    printf("how are you slimi do you feel good\n");
    slimi->only_one = 1;
    pthread_cond_signal(&slimi->cond_variable);
    while (slimi->only_one == 1)
    {
        pthread_cond_wait(&slimi->cond_variable, &slimi->mutex);
    }
    printf("I am fine too i will sleep you again\n");
    slimi->only_one = 1;
    pthread_cond_signal(&slimi->cond_variable);
    return NULL;
}

int main()
{
    pthread_t       my_thread;
    pthread_t       your_thread;
    t_cond_variable conversation;
    conversation.only_one = 0;
    pthread_cond_init(&conversation.cond_variable, NULL);
    pthread_mutex_init(&conversation.mutex, NULL);
    pthread_create(&my_thread, NULL, fn_meme, &conversation);
    pthread_create(&your_thread, NULL, fn_slimi, &conversation);
    pthread_join(my_thread, NULL);
    pthread_join(your_thread, NULL);
    return 0;
}