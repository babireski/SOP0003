#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMTHREADS 5

typedef pthread_t thread;

void *hello(void *arg)
{
    long tid = (long) arg;
    printf("hello(): greetings from thread #%li! \n", tid);
    pthread_exit(NULL);
}

int main()
{
    thread threads[NUMTHREADS];
    int rc; /* Return? */

    for(long t = 0; t < NUMTHREADS; t++)
    {
        printf("main():  creating thread %li", t);
        printf("\n");
        rc = pthread_create(&threads[t], NULL, hello, (void*) t);

        if(rc)
        {
            printf("ERRO - rc = %d", rc);
            printf("\n");
            exit(-1);
        }
    }

    pthread_exit(NULL);
}