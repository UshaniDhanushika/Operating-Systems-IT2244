//*********************************
//if else SYNTAX:

if(condition)
{
	//body of if statement;
}

else{
	//body of else statement;
}

Example: 

Q1)
Enter your age and verify your aligible or not for election voting 
using if-else condition


#include<stdio.h>
int main(){

int age;
printf("Enter your age:");
scanf("%d",&age);

printf("Your age is:%d\n",age);

    if(age <0)
	{
		printf("Invalid Age\n");
	}
		
	else if(age>18)
	{
		printf("You are eligible to voting\n");
	}

	else{
		printf("Sorry,You are not eligible to voting\n");
	}
	
	return 0;
}





//*********************************
//Ternary Operator SYNTAX:

if test_condition ? expression1 : expression2


#include<stdio.h>
int main(){

int age;
printf("Enter your age:");
scanf("%d",&age);

printf("Your age is:%d\n",age);

   (age>=18) ? printf("You can vote\n") : printf("You can not vote\n");;
   // you can add the condition without bracket  -> age>=18
    return 0; 
	
}
