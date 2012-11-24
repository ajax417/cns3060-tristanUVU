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
	pthread_t thread1, thread2, thread3, thread4;
	int rc;
	long t;
	rc = pthread_create(&thread1, NULL, incrementCounter, (void *)t);
	rc = pthread_create(&thread2, NULL, incrementCounter, (void *)t);
	rc = pthread_create(&thread3, NULL, incrementCounter, (void *)t);
	rc = pthread_create(&thread4, NULL, incrementCounter, (void *)t);
	printf("count %d\n",count);
    return 0;
}
