#include<stdio.h>
#include<stdlib.h>  //for exit()
#include<unistd.h>  // for sleep()

int main()
{
	printf("Program started.\n");
	
	printf("Sleeping for 3 seconds.....\n");
	sleep(3); //pause for 3 seconds
	
	printf("Exiting the program\n");
	exit(0);
}


//===================================================================

#include<stdio.h>
#include<stdlib.h>  //for exit()
#include<unistd.h>  // for sleep()
#include<sys/wait.h>  // for wait()

int main()
{
	pid_t pid;  //pid_t is the special data type using get pid
	
	printf("Parent process started.PID:%d\n",getpid());
	
	pid = fork(); //Create a new child process
	
	
	if(pid<0)
	{
		perror("fork faild");
		exit(1);
	}
	
	if(pid==0)
	{
		//child process
		printf("Child Process.PID:%d, sleeping for 2 seconds...\n",getpid());
		sleep(2);
		printf("Child Process exiting.\n");
		exit(0); //child exits with status 0
	}
	
	else{
		//parent process
		int status;
		printf("Parent Waiting for child to process...\n");
		wait(&status); //wait for child to finish
		
		if(WIFEXITED(status))
		{
			printf("Chiled exited with status:%d\n",WEXITSTATUS(status));
		}
		
		else{
			printf("Child did not exit normally.\n");
		}
		
		printf("Parent Process ending.\n");
	}
	
	return 0;
}

//==========================================================================
/*
Exercise 01:

First Child : Slept for 1 second
Second Child : Slept for 3 seconds
Parent : Both children have finish

*/

#include<stdio.h>
#include<stdlib.h>  //for exit()
#include<unistd.h>  // for sleep()
#include<sys/wait.h>  // for wait()

int main()
{
	pid_t pid;  //pid_t is the special data type using get pid
	
	printf("Parent process started.PID:%d\n",getpid());
	
	pid = fork(); //Create a new child process
	
	
	if(pid<0)
	{
		perror("fork faild");
		exit(1);
	}
	
	if(pid==0)
	{
		//child process
		printf("First Child Process.PID:%d, sleeping for 1 seconds...\n",getpid());
		sleep(1);
		printf("Child Process exiting.\n");
		exit(0); //child exits with status 0
	}
	
	wait(NULL);
	
	pid_t new ;
	new = fork();
	
	if(new<0)
	{
		perror("fork faild");
		exit(1);
	}
	
	if(new==0)
	{
		//child process
		printf("Second Child Process.PID:%d, sleeping for 3 seconds...\n",getpid());
		sleep(3);
		printf("Child Process exiting.\n");
		exit(0); //child exits with status 0
	}
	
	else{
		//parent process
		int status;
		printf("Parent Waiting for child to process...\n");
		wait(&status); //wait for child to finish
		
		if(WIFEXITED(status))
		{
			printf("Chiled exited with status:%d\n",WEXITSTATUS(status));
		}
		
		else{
			printf("Child did not exit normally.\n");
		}
		
		printf("Parent Process ending.\n");
	}
	
	return 0;

}

//===================================================================

/*Exercise 02:

First child: sleeps for 2 seconds, exits with status 2
second child: sleeps for 1 seconds, exits with status 1
Parent: wait twice, and prints which child (by PID or exit code)
finished first and second

*/
#include<stdio.h>
#include<stdlib.h>  //for exit()
#include<unistd.h>  // for sleep()
#include<sys/wait.h>  // for wait()

int main()
{
	pid_t pid;  //pid_t is the special data type using get pid
	
	printf("Parent process started.PID:%d\n",getpid());
	
	pid = fork(); //Create a new child process
	
	
	if(pid<0)
	{
		perror("fork faild");
		exit(1);
	}
	
	if(pid==0)
	{
		//child process
		printf("First Child Process.PID:%d, sleeping for 1 seconds...\n",getpid());
		sleep(1);
		printf("Child Process exiting.\n");
		exit(0); //child exits with status 0
	}
	else{
		//parent process
		int status;
		printf("Parent Waiting for first child to process...\n");
		wait(&status); //wait for child to finish
		
		if(WIFEXITED(status))
		{
			printf("First Child exited with status:%d\n",WEXITSTATUS(status));
		}
		
		else{
			printf("Child did not exit normally.\n");
		}
		
		printf("Parent Process ending.\n");
	}
	
	wait(NULL);
	
	pid_t new ;
	new = fork();
	
	if(new<0)
	{
		perror("fork faild");
		exit(1);
	}
	
	if(new==0)
	{
		//child process
		printf("Second Child Process.PID:%d, sleeping for 3 seconds...\n",getpid());
		sleep(3);
		printf("Child Process exiting.\n");
		exit(0); //child exits with status 0
	}
	
	else{
		//parent process
		int status;
		printf("Parent Waiting for child to process...\n");
		wait(&status); //wait for child to finish
		
		if(WIFEXITED(status))
		{
			printf("Chiled exited with status:%d\n",WEXITSTATUS(status));
		}
		
		else{
			printf("Child did not exit normally.\n");
		}
		
		printf("Parent Process ending.\n");
	}
	
	return 0;

}

//===================================================================

/*Exercise 03:

The parent creates a child process
The child creates a grandchild process
The grandchild sleeps 2 seconds and exits with status 2
The child wait for the grandchild,prints its exit status,then exit with status 55
*/
