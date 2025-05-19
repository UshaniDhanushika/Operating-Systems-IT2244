//write a C program to generate and print the fibonacci series up to a specified number of terms.
The program should take the number of terms as input from the user and then display the corresponding
Fibonacci sequence

#include<stdio.h>
int main(){


int n;
printf("Enter the number:");
scanf("%d",&n);

int a=0;
int b=1;

printf("%d , %d ",a,b);

for(int i=3; i<=n; i++)
{
	int fib = a + b;
	printf(" , %d ",fib);
	a=b;
	b=fib;
	
}
printf("\n");
return 0;

}

