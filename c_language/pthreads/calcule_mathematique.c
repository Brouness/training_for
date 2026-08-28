#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// On définit le nombre de threads égal à vos 12 CPU logiques
#define NUM_THREADS 12
// Taille du tableau : 120 millions d'éléments (facilement divisible par 12)
#define ARRAY_SIZE 120000000 

// Structure pour donner à chaque thread sa zone de travail
typedef struct {
    int thread_id;
    double* data;
    long start_index;
    long end_index;
} ThreadData;

// La fonction lourde en calcul mathématique que chaque thread va exécuter
void* gros_calcul_mathematique(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    
    printf("[Thread %d] Démarre sur les index %ld à %ld\n", 
           data->thread_id, data->start_index, data->end_index);

    // Chaque thread fait ses calculs intensifs sur sa propre portion de mémoire
    for (long i = data->start_index; i < data->end_index; i++) {
        // Une opération mathématique qui demande beaucoup de puissance CPU
        data->data[i] = sin(i) * cos(i) + sqrt(i) + 99999999;
    }

    printf("[Thread %d] Calcul terminé !\n", data->thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    
    // Allocation d'un gros bloc de mémoire RAM
    printf("Allocation de la mémoire pour %d éléments...\n", ARRAY_SIZE);
    double* gros_tableau = malloc(ARRAY_SIZE * sizeof(double));
    if (gros_tableau == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire !\n");
        return 1;
    }

    // Découpage du travail : chaque thread reçoit exactement 10 millions d'éléments
    long elements_par_thread = ARRAY_SIZE / NUM_THREADS;

    printf("Lancement de %d threads en parallèle...\n", NUM_THREADS);
    
    // Création et lancement des 12 threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].data = gros_tableau;
        thread_data[i].start_index = i * elements_par_thread;
        thread_data[i].end_index = (i + 1) * elements_par_thread;

        // Création du thread
        pthread_create(&threads[i], NULL, gros_calcul_mathematique, (void*)&thread_data[i]);
    }

    // Le thread principal (main) attend que les 12 threads aient fini
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("✅ Succès ! Les 12 threads ont traité %d éléments en parallèle.\n", ARRAY_SIZE);

    // Libération de la mémoire
    free(gros_tableau);
    return 0;
}
