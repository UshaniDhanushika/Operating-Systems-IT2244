//===========================================================
#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("\nHello World!");
	int f = fork();
	int p = getpid();
	printf("\npid is:%d",p);
	printf("\npid is:%d\n",f);
	
	return 0;
}



//===========================================================

#include<stdio.h>
#include<unistd.h>
int main()
{
	fork();
	fork();
	printf("\nHello World");
	
	return 0;
}

//===========================================================
//print  without copyies
//ex1:
#include<stdio.h>
#include<unistd.h>
int main()
{
	
	int p = getpid();
	int f = fork();
	
	if(f==0)
	{
		printf("\n Hey I'm Child Processor,My pid is:%d\n",f);
	}
	
	else{
		
		printf("\n Hey I'm Parent Processor,My pid is:%d",p);
	}
	
	return 0;
}

//ex2:

#include<stdio.h>
#include<unistd.h>
int main()
{
	 int f = fork();
	 
	 if(f==0)
	 {
		printf("I am Child\n");
		printf("My Parent Id is:%d\n",getppid());
	 }
	 
    else{
		
		int c = fork();
		
		if(c==0)
		{
			printf("I am Sibling\n");
		    printf("My Parent Id is:%d\n",getppid());
		}
		
		else{
	      printf("I am Parent\n");
		  printf("My Id is:%d\n",getpid());
		  
		}  
	}
	return 0;
	
}
