//Receive

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
	
//structure for message queue
	
struct mesg_buffer{
	long mesg_type;
	char mesg_text[100];
}message;

int main()
{
	key_t key;
	int msgid;
	
	//ftok to generate unique key
	
	key = ftok("2021ict80",80);
	
	//mesgget creates a message queue
	//and returns identifier
	
	msgid = msgget(key,0666 | IPC_CREAT);
	
	//msgrcv to recieve message 
	msgrcv(msgid, &message, sizeof(message),1,0);
	
	//Display the message 
	printf("Data recieved is: %s\n",message.mesg_text);
	
	//to Destroy the message queue 
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}



//How to run receive data without any error ( Can receive data what you send, without received any others data )
//vi send.c
//touch 2021ict80
//chmod 644 2021ict80 //Give permissionas -> Read and Write
//gcc send.c -o send

//vi receive.c
//gcc receive.c -o receive

//./send
//./receive