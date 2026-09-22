#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_station
{
    int             free_pumps;
    pthread_mutex_t station_lock;
    pthread_mutex_t log_lock;
    pthread_cond_t  cond;
    long            start_time;
}   t_station;

typedef struct s_car
{
    int id;
    t_station *ptr;
}   t_car;

void    log_message(t_station *st, int id, char *str)
{
    pthread_mutex_lock(&st->log_lock);
    printf("car id: %d %s\n", id, str);
    pthread_mutex_unlock(&st->log_lock);
    return ;
}

void    *car_routine(void *args)
{
    t_car *ptr = (t_car *) args;
    log_message(ptr->ptr, ptr->id, "arrived, waiting for a pump");
    pthread_mutex_lock(&ptr->ptr->station_lock);
    while(ptr->ptr->free_pumps == 0)
        pthread_cond_wait(&ptr->ptr->cond, &ptr->ptr->station_lock);
    ptr->ptr->free_pumps--;
    pthread_mutex_unlock(&ptr->ptr->station_lock);
    log_message(ptr->ptr, ptr->id, "is refueling");
    usleep(1000000);
    pthread_mutex_lock(&ptr->ptr->station_lock);
    ptr->ptr->free_pumps++;
    pthread_cond_signal(&ptr->ptr->cond);
    pthread_mutex_unlock(&ptr->ptr->station_lock);
    log_message(ptr->ptr, ptr->id, "done, pump released");
    return NULL;
}

int main(int ac, char **av)
{
    if (ac != 3)
        return fprintf(stderr, "Error INVALID NUMBER OF ARGS...\nHINT: NUMBER OF ARGS MUST BE[./program number_of_pumps number_of_cars] \n");
    else
    {
        pthread_t   *cars = malloc(sizeof(pthread_t) * atoi(av[2]));
        t_station   station_args;
        t_car       *car_args = malloc(sizeof(t_car) * atoi(av[2]));
        int i = 0;
        while(i < atoi(av[2]))
        {
            car_args[i].id = i;
            car_args[i].ptr = &station_args;
            i++;
        }
        station_args.free_pumps = atoi(av[1]);
        pthread_mutex_init(&station_args.log_lock, NULL);
        pthread_mutex_init(&station_args.station_lock, NULL);
        pthread_cond_init(&station_args.cond, NULL);
        station_args.start_time = 0;
        i = 0;
        while(i < atoi(av[2]))
        {
            pthread_create(&cars[i], NULL, car_routine, &car_args[i]);
            i++;
        }
        i = 0;
        while(i < atoi(av[2]))
        {
            pthread_join(cars[1], NULL);
            i++;
        }
        pthread_mutex_destroy(&station_args.station_lock);
        pthread_mutex_destroy(&station_args.log_lock);
        pthread_cond_destroy(&station_args.cond);
        free(cars);
        free(car_args);
    }
    return 0;
}
