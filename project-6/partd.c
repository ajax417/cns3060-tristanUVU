#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 4
int count = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
void *incrementCounter( void *m)
{
	int i;
	for (i = 0; i < 10; ++i)
	{
		sleep(1);
		pthread_mutex_lock( &mutex1 );
		count++;
		pthread_mutex_unlock( &mutex1 );
	}
	return NULL;
}
int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for(t = 0; t < NUM_THREADS; t++)
	{
	rc = pthread_create(&threads[t], NULL, incrementCounter, (void *)t);
	}
	for(t = 0; t < NUM_THREADS; t++)
	{
		(void) pthread_join(threads[t], NULL);
	}
	printf("count %d\n",count);
    return 0;
}
