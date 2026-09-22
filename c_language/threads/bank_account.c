#include <stdio.h>
#include <pthread.h>



double CIH_WALLET = 0;
pthread_mutex_t mut;


void    *TPE_MACHINE(void *ptr)
{
    double sold = *(double *) ptr;
    // pthread_mutex_lock(&mut);
    for (long i = 0; i < 10000000; i++)
        CIH_WALLET+=sold;
    // pthread_mutex_unlock(&mut);
    return (NULL);
}

int main(void)
{
    pthread_mutex_init(&mut, NULL);
    pthread_t hamid_depos;
    pthread_t youness_depos;
    printf("THIS IS TPE MACHINE\n");
    printf("This is the current sold: => %lf\n", CIH_WALLET);
    double hamid_floss = 0.000000003;
    double youness_floss = 0.000000001;
    pthread_create(&hamid_depos, NULL, TPE_MACHINE, &hamid_floss);
    pthread_create(&youness_depos, NULL, TPE_MACHINE, &youness_floss);
    pthread_join(hamid_depos, NULL);
    pthread_join(youness_depos, NULL);
    printf("this is the wallet after depos: => %lf\n", CIH_WALLET);

}