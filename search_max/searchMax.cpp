#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/param.h>

#define ARRAY_LENGTH 100
#define NUM_THREADS 4

int array[ARRAY_LENGTH];

void *find_max(void *arg){
    int thread_id = *((int *)arg);
    int start = thread_id * (ARRAY_LENGTH / NUM_THREADS);
    int end = start + ( ARRAY_LENGTH / NUM_THREADS);
    //int max = array[start];
    /*test*/

    int item, j;

    for (int i = (start + 1); i <= (end-1); i++)
    {
        item = array[i];
        j = i-1;
        while ((j >= start) && (array[j] > item))
        {
            array[j+1] = array[j];
            j--; 
        }
        array[j+1] = item;
   
    } 
    //printf("Maximum finded by thread %d: %d\n",thread_id, max);
    printf("Zoradené pole od %d do %d:\n", start, end);
    for (int i = start; i < end; i++)
    {
        printf("%d,", array[i]);
    }
        printf("\n");
        printf("\n");

    
    return NULL;
}

int timeval_diff_to_ms( timeval *t_before, timeval *t_after )
{
    timeval l_res;
    timersub( t_after, t_before, &l_res );
    return 1000 * l_res.tv_sec + l_res.tv_usec / 1000;
}

int main() {

    srand( ( int ) time( NULL ) );

    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        array[i] = rand() % 100;
        printf("%d,", array[i]);
    }
    printf("\n");

    
    pthread_t thread_id[NUM_THREADS];
    int thread_arg[NUM_THREADS];

    timeval l_time_before, l_time_after;
    gettimeofday( &l_time_before, NULL );
    

    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_arg[i] = i;
       pthread_create(&thread_id[i], NULL, find_max, &thread_arg[i]);
    }
    
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(thread_id[i], NULL);
    }
    gettimeofday( &l_time_after, NULL );
    printf( "The search time: %d [ms]\n", timeval_diff_to_ms( &l_time_before, &l_time_after ) );

    
    return 0;
}