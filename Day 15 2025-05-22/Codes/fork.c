//=================================================================
#include<stdio.h>
#include <unistd.h>

int main()
{
	fork();
	printf("Hello World!\n");
	
	return 0;
	
}

Output: 
Hello World!
Hello World!

//=================================================================

#include<stdio.h>
#include <unistd.h>

int main()
{
	fork();
	fork();
	printf("Hello World!\n");
	
	return 0;
	
}

Output:5
Hello World!
Hello World!
Hello World!
Hello World!  // If u increase fork Hello world will increase


//=================================================================


#include<stdio.h>
#include <unistd.h>

int main()
{
	int pid = getpid();
    int f = fork();
	
    if(f==0)
	{
		printf("I am the child process, My ID is: %d\n",f);
	}		
	
	else{
		printf("I am the parent Process, My ID is: %d\n",pid);
	}
	
	return 0;
	
}

output:
I am the parent Process, my Id is:14318
I am the child process, My Id is:0


//=================================================================
//Print numbers from 1 to 10
//1 to 5 should be print by child process and 
//From 6 to 10 should be parent process
//Calculate summation of those numbers

#include<stdio.h>
#include<unistd.h>
int main()
{
	int f = fork();
    int n;
	int sum =0;
	
		
		if(f==0)
		{
			n=1;
		}
	
		else{
			n=6;
		}
	
		for(int i=n; i<n+5;i++)
		{
		   printf("%d\n",i);
		   sum += i;
		}
	
		printf("Summation is:%d\n",sum);
		printf("\n");
			
		return 0;
	
}

