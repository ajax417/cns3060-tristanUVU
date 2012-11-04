#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
#include <signal.h>
const struct termios orig_term_attr;
void terminate (int param)
{
	printf("%s","terminating and restoring terminal");
	exit(0);
}

void printFile(int numLines, FILE *fp)
{
	int i = 0;
	char mystring [100];
	for(i; i< numLines; i++)
	{
		if( fgets (mystring, 100 , fp) != NULL)
			puts(mystring);
	}
}
int main(int argc, int *argv[])
{
	void (*prev_fn);
	prev_fn = signal(SIGINT,terminate);
	struct termios new_term_attr;
	
	tcgetattr(fileno(stdin), &orig_term_attr);
	memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termio));
	new_term_attr.c_lflag &= ~(ECHO|ICANON);
	new_term_attr.c_cc[VTIME] = 0;
	new_term_attr.c_cc[VMIN] = 0;
	tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);
	FILE *fp;
	char userInput;
	if(argc > 1)
	{
		int numLines = 0;
		printf("%s","here");
		fp = fopen(argv[1],"r");
		if(fp == NULL)
		{
			printf("%s","error reading file");
			fclose(fp);
			tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);
			return 1;
		}
		char fileInput = 'x';
		while(fileInput != NULL)
		{
			fileInput = fgetc(fp);
			if(fileInput = "\n")
			numLines++;
		}
		fclose(fp);
		fp = fopen(argv[1],"r");
		printf("%d",numLines);
		while(userInput != 'q')
		{
			if(userInput == ' ')
			{
				printFile(23,fp);
			}
			if(userInput == '\n')
			{
				printFile(1,fp);
			}
			userInput = getc(stdin);
		}
		fclose(fp);
		printf("%s","sucess");
		tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);
	}
	char fileInput[100];
	while(fileInput[0] != 'q')
	{
		tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);
		printf("%s","\033[7m");
		gets(fileInput);
		printf("%s\0",fileInput);
		printf("%s\n","bytes");
		printf("%s","\033[m");
	}
	tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);
	return 0;
}
