#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

void parentOne(int signum)
{
	printf("****Parent SIGUSR1 handler-Received a 'task started' signal from child****\n");
}
void parentTwo(int signum)
{
	printf("****Parent SIGUSR2 handler-Received a 'task completed' signal from child****\n");
}
void childOne(int signum)
{
	printf("**** Child SIGUSR1 handler-Received a 'task start' signal from the parent process****\n");
}
void childTwo(int signum)
{
	printf("**** Child SIGUSR2 handler-Received a 'task complete verification' signal from parent****\n");
}

int main(int argc, char *argv[])
{
	printf("Tristan Wagstaff\nCS3060\n601\n");
	signal(SIGUSR1,parentOne);
	signal(SIGUSR2,parentTwo);
	pid_t child = fork();
	sigset_t wait1, wait2;
	sigemptyset(&wait1);
	sigaddset(&wait1, SIGUSR2);
	sigemptyset(&wait2);
	sigaddset(&wait2, SIGUSR1);
	if(child == 0)
	{
		signal(SIGUSR1,childOne);
		signal(SIGUSR2,childTwo);
		printf("Child is running and waiting for a task\n");
		sigsuspend(&wait1);
		sleep(3);
		kill(getppid (),SIGUSR1);
		printf("Child has done its work\n");
		sigsuspend(&wait2);
		printf("telling parent child is done\n");
		kill(getppid (),SIGUSR2);
		return 0;
	}
	else if(child < 0)
	{
		printf("Error couldn't start child aborting\n");
		exit(1);
	}
	else
	{
		printf("child started\n");
		sleep(3);
		printf("notifying parent I am starting\n");
		kill(child,SIGUSR1);
		sigsuspend(&wait1);
		sleep(3);
		kill(child,SIGUSR2);
		printf("parent has sent sigusr2\n");
		sigsuspend(&wait2);
		printf("parent got sig2 terminating\n");
		return 0;
	}
}
