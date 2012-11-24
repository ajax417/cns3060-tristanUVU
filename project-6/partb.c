#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 4
int count = 0;

void *incrementCounter( void *m)
{
	int i;
	for (i = 0; i < 10; ++i)
	{
		int tempValue = count;
		sleep(1);
		tempValue = tempValue + 1;
		count = tempValue;
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
