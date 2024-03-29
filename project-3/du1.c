#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>


FILE *file;

int printFile(char* filePath)
{
	int fileSize = 0;
	struct stat fileStat;
	if (stat(filePath, &fileStat) == 0 && S_ISDIR(fileStat.st_mode))
	{
			printf("I am a directory");
			DIR		*d;
			struct dirent *dir;
			d = opendir(filePath);
			if (d)
			{
				while ((dir = readdir(d)) != NULL)
				{
					if(strcmp(dir->d_name,".") != 0 && strcmp(dir->d_name,"..") != 0)
						fileSize += printFile(dir->d_name);
				}
				closedir(d);
			}
	}
	else if(stat(filePath, &fileStat) != 0)
	{
		printf("I am having trouble opening\n");
		printf("%s\n",filePath);
		return -1;
	}
	fileSize += fileStat.st_size;
	printf("%dB",fileSize);
	printf("\t%s\t\t\n",filePath);
	return fileSize;
}
int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		printFile(argv[1]);
	}
	else
	{
		printFile("./");
	}
	getchar();
    return 0;
}
