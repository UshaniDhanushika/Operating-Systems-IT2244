
#include <stdio.h>
#include <pthread.h>

//function to be executed by the thread
void* print_message(void* arg)
{
   char* message = (char*)arg;
   printf("%s\n",message);
   return NULL;

}

int main(){
   pthread_t thread1,thread2;
   
   //create first thread1
   pthread_create(&thread1,NULL,print_message,"Hello from thread 1!");
   
   //create second thread2
   pthread_create(&thread2,NULL,print_message,"Hello from thread 2!");
   
   //wait for both threads to finish
   pthread_join(thread1,NULL);
   pthread_join(thread2,NULL);
   
   printf("Both threads completed.\n");
   
   return 0;
}



Answer:-

[sashini@Sashini ~]$ vi multi_thread.c
[sashini@Sashini ~]$ gcc multi_thread.c -o multi_thread
[sashini@Sashini ~]$ ./multi_thread
Hello from thread 1!
Hello from thread 2!
Both threads completed.
