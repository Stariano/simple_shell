#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX 10

int main()
{
    pid_t pid;
    static int loop = 1;
    char command[10];
    int check;
    int m;

    char *arg[] = {"", NULL};
    while(loop)
    {
        printf("#cisfun$ ");
        m = scanf("%s", command);
	if (m == EOF)
		break;

        pid = fork();
	if (pid == 0)
	{
            check = execve(command, arg, NULL);
	    if (check == -1)
		    perror("Error");

	    exit(0);
	}
	else
	{
	    wait(NULL);
    	}
    }

    return (0);
}
