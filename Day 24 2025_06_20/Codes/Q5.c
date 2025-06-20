/*
Q5)
Implement a thread function that takes an integer argument, squares it,
and returns the result to the main thread using pthread_exit and pthread_join.


*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* square(void* arg) {
    int num = *(int*)arg;
    int* result = malloc(sizeof(int)); //Allocate memory on the heap to store an integer.result points to this allocated memory.
    *result = num * num;  //Store the result in the allocated memory.
	//function used by a thread to terminate itself and optionally return a value (retval) to any thread that joins it.
    pthread_exit(result); //Exit the thread and return the pointer result to the caller.
}

int main() {
    pthread_t t;
    int num = 5;

    pthread_create(&t, NULL, square, &num);

    int* res; //Declare a pointer res to receive the result
    pthread_join(t, (void**)&res);//pthread_join stores the thread's return value (a void*) in res.

    printf("Square of %d is %d\n", num, *res);
    free(res); //Free the memory allocated by the thread to avoid memory leaks.
    return 0;
}
