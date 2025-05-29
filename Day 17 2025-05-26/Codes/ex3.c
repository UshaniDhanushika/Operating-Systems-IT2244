/*Exercise 03:

The parent creates a child process
The child creates a grandchild process
The grandchild sleeps 2 seconds and exits with status 2
The child wait for the grandchild,prints its exit status,then exit with status 55
*/


#include<stdio.h>
#include<stdlib.h>     // for exit()
#include<unistd.h>     // for fork(), sleep()
#include<sys/wait.h>   // for wait()

int main()
{
    pid_t child_pid, grandchild_pid;
    int status;

    printf("Parent process started. PID: %d\n", getpid());

    child_pid = fork();  // Create child process

    if (child_pid < 0)
    {
        perror("fork failed");
        exit(1);
    }

    if (child_pid == 0)
    {
        // Child process
        printf("Child process started. PID: %d, Parent PID: %d\n", getpid(), getppid());

        grandchild_pid = fork();  // Create grandchild process

        if (grandchild_pid < 0)
        {
            perror("fork failed");
            exit(1);
        }

        if (grandchild_pid == 0)
        {
            // Grandchild process
            printf("Grandchild process started. PID: %d, sleeping for 2 seconds...\n", getpid());
            sleep(2);
            printf("Grandchild process exiting with status 2.\n");
            exit(2);
        }
        else
        {
            // Child waits for grandchild
            wait(&status);

            if (WIFEXITED(status))
            {
                printf("Child: Grandchild exited with status: %d\n", WEXITSTATUS(status));
            }
            else
            {
                printf("Child: Grandchild did not exit normally.\n");
            }

            printf("Child process exiting with status 55.\n");
            exit(55);
        }
    }
    else
    {
        // Parent process waits for child
        wait(&status);

        if (WIFEXITED(status))
        {
            printf("Parent: Child exited with status: %d\n", WEXITSTATUS(status));
        }
        else
        {
            printf("Parent: Child did not exit normally.\n");
        }

        printf("Parent process ending.\n");
    }

    return 0;
}
