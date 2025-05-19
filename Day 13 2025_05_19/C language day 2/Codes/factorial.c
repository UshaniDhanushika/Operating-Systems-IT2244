Q3)
Write a C program to calculate the factorial of a given non - negative integer

#include<stdio.h>
int main(){

int n;
printf("Enter the number:");
scanf("%d",&n);

int fac = 1;

for(int i=1; i<=n; i++)
{
	fac = fac * i;
	
}

printf("Factorial of %d:%d\n",n,fac);
return 0;

}

