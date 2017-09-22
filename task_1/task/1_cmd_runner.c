#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	pid_t pid;
   	int status;
	int n = 0, i = 0;
	char s[20]="privet";
	while(1)
	{  	
		switch(pid = fork()) 
		{
	   		case 0: 
				gets(s);
				if (strcmp(s, "out") == 0) exit(-2);				
				int l = strlen(s);
				for (i = 0; i < l; i++)
					{
					if (s[i] == ' ')
					{
						n++;
						s[i] = 0;
					}
				}
				char **argv = (char *)malloc((n + 2)*sizeof(char*));
				argv[n + 1] = NULL;
				for (i = 0, n = 0; i < l; i++)
				{	
					if(i == 0 || s[i-1] == 0)
					{
						argv[n] = s + i;
						n++;		
					}			
				}
				execv(argv[0], argv);	
	   		case -1:
				printf ("ERROR!1!!1!!!1");
				exit(-1);

			default:
			
				wait(&status);
				
					if(WEXITSTATUS(status) == 254)
					{
						exit(-1);
					}
					printf("\nexit status is %d \n", WEXITSTATUS(status));
		}
	}
	return 0;
}
