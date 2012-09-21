#include <stdio.h>
#include <string.h>


#define LINELEN 512

FILE *file;

int main(int argc, char *argv[])
{
    int count = 0;
    char str1[LINELEN];
    char *str2 = "Hello";
    int lineNum = 1;
    if(argc > 2)
    {
		if(strncmp("-n",argv[1],LINELEN) == 0)
        		count = 2;
		else
			count = 1;
        while(count < argc)
        {
		file = fopen(argv[count],"rt");
		if(file == NULL)
		{
			printf("%s","He is dead Jim it was a bad file \n");
			return(1);
		}
		while(fgets(str1, LINELEN, file) != NULL)
		{
			if(strncmp("-n",argv[1],LINELEN) == 0)
			{
				printf("\t %d ",lineNum);
				lineNum++;
			}
			if(str1[strlen(str1) -1] == '\n')
			{
			str1[strlen(str1) -1] = '\0';
			}
			printf("%s",str1);
		   	printf("\n");
    		}
		fclose(file);
		count++;
        }
    }
    else
    {
	if(argc == 2)
	if(strncmp("-n",argv[1],LINELEN) != 0)
	{
		file = fopen(argv[1],"rt");
		if(file == NULL)
		{
			printf("He is dead Jim it was a bad file or bad command \n");
			return(1);
		}
		while(fgets(str1, LINELEN, file) != NULL)
		{
		   	printf("%s",str1);
			printf("\n");
		}
		fclose(file);
		return(0);
	}
        while(fgets(str1, LINELEN, stdin) != NULL)
        {
		if(argc == 2)
		if(strncmp("-n",argv[1],LINELEN) != 0)
		{
			printf("bad command \n");
			return(1);
		}
		else
		{
			printf("\t %d ",lineNum);
			lineNum++;
		}
		if(str1[strlen(str1) -1] == '\n')
		{
		str1[strlen(str1) -1] = '\0';
		}
		printf("%s",str1);
		printf("\n");
        }
    }
    return 0;
}
