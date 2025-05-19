//*********************************
//Switch Case SYNTAX:
   switch(variable){
   
	case 1:
		//body of case 1
		break;
	
	case 2:
		//body of case 2
		break;
	
	default:
		//body of default
	}
	
	
Example 1:

Enter the value between 1 to 7 and create a program for following output

Enter the number 1 to 7:
Today is Sunday


#include<stdio.h>
int main()
{
	int day;
	printf("Enter the number between 1 to 7:");
	scanf("%d",&day);
	
    switch(day)
	{
		case 1:
			printf("Today is Monday\n");
			break;
			
		case 2:
			printf("Today is Tuesday\n");
			break;
		
		case 3:
			printf("Today is Wedneaday\n");
			break;
		
		case 4:
			printf("Today is Thursday\n");
			break;
			
		case 5:
			printf("Today is Friday\n");
			break;
		
		case 6:
			printf("Today is Saturday\n");
			break;
		
		case 7:
			printf("Today is Sunday\n");
			break;
		
		default:
			printf("Invalid Number! Please enter number between 1 to 7\n");
			break;
	}
	return 0;
}



Example 2:
Write a code for small astrology based on your life path number for that get date 
of birth from user then calculate life path number (used switch case)

ex: 
	Date : 23

	calculation for life path number:
		a = date % 10		3
		b = date / 10		2
		c = a + b			5
		
	if life path number:
		1 : Lucky
		2 : Carefully do your work
		3 : Storger
		4 : Happy
		5 : Can get help
		6 : Doubt
		7 : Sad
		8 : Like
		9 : Courage

#include<stdio.h>
int main()
{
	int date;
	
	printf("Enter your birth date: ");
	scanf("%d",&date);
	
	printf("Date:%d\n",date);
	
	int a = date % 10;
	int b = date / 10;
	int c = a + b;
	
	
	if(c>9)
	{
		 c = (c % 10) + c / 10;
	}
	
	switch(c)
	{
		case 1:
		
			printf("Lucky\n");
			break;
			
		case 2:
		
			printf("Carefully do your work\n");
			break;
			
		case 3:
		
			printf("Storger\n");
			break;
			
		case 4:
		
			printf("Happy\n");
			break;
			
		case 5:
		
			printf("Can get help\n");
			break;
			
		
		case 6:
		
			printf("Doubt\n");
			break;
			
		case 7:
		
			printf("Sad\n");
			break;
			
		case 8:
		
			printf("Like\n");
			break;
			
        case 9:
		
			printf("Courage\n");
			break;
			
		default:
           printf("Invalid Date\n");
	
	}
	
	return 0;
	
}