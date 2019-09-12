#ifndef __BARREIRA_H__
#define __BARREIRA_H__ value

#include <pthread.h>

typedef struct barreira barreira_t;


struct barreira {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int total;
    int parados;
};

void barreira_init(barreira_t *bar , int qtdThread);
void barreira_wait(barreira_t *bar);


#endif /* ifndef __BARREIRA_H__ */
