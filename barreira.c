#include "barreira.h"


void barreira_init(barreira_t *bar , int qtdThread){
    pthread_mutex_init(&bar->mutex , NULL);
    pthread_cond_init(&bar->cond , NULL);
    bar->total = qtdThread;
    bar->parados = 0;
}



void barreira_wait(barreira_t *bar){
    pthread_mutex_lock(&bar->mutex);
    bar->parados++;
    if(bar->parados != bar->total){
        pthread_cond_wait(&bar->cond , &bar->mutex);
        pthread_mutex_unlock(&bar->mutex);
    }else{
        bar->parados = 0;
        pthread_mutex_unlock(&bar->mutex);
        pthread_cond_broadcast(&bar->cond);
    }
};


