#include <pthread.h>
#include <stdio.h>
#include "barreira.h"

void * nada(void *algo){
    barreira_t *bar = (barreira_t*) algo;
    fprintf(stderr , "paro na barreira\n");
    barreira_wait(bar);
    fprintf(stderr,"passou a barreira\n");
    fprintf(stderr , "paro na barreira 2\n");
    barreira_wait(bar);
    fprintf(stderr,"passou a barreira 2\n");
    pthread_exit(NULL);
};


int main (int argc , char* argv[]){
    pthread_t threads[10];
    barreira_t bar;
    barreira_init(&bar , 10);
    for(int i = 0 ; i < 10 ; i++){
        pthread_create(threads+i , NULL , nada , &bar);
    };
    for (int i = 0; i < 10; ++i) {
        pthread_join(threads[i] , NULL);
    }

    return 0;
}
