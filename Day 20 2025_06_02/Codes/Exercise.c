#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main() {
    size_t size = 4096;
    int *shared_mem = mmap(NULL, size, PROT_READ | PROT_WRITE,
                           MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    int n, r;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter r: ");
    scanf("%d", &r);

    if (r > n || n < 0 || r < 0) {
        printf("Invalid input. Require 0 <= r <= n.\n");
        munmap(shared_mem, size);
        exit(1);
    }

    shared_mem[0] = n;
    shared_mem[1] = r;

    pid_t pid = fork();

    if (pid == 0) {
        // Child process

        // Factorial function inside child process
        unsigned long long factorial(int x) {
            unsigned long long fact = 1;
            for (int i = 2; i <= x; i++)
                fact *= i;
            return fact;
        }

        int n = shared_mem[0];
        int r = shared_mem[1];

        unsigned long long fact_n = factorial(n);
        unsigned long long fact_r = factorial(r);
        unsigned long long fact_n_r = factorial(n - r);

        unsigned long long *facts = (unsigned long long *)(shared_mem + 2);
        facts[0] = fact_n;
        facts[1] = fact_r;
        facts[2] = fact_n_r;

        printf("Child: factorial(%d) = %llu, factorial(%d) = %llu, factorial(%d) = %llu\n",
               n, fact_n, r, fact_r, n - r, fact_n_r);

        exit(0);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);

        unsigned long long *facts = (unsigned long long *)(shared_mem + 2);
        unsigned long long fact_n = facts[0];
        unsigned long long fact_r = facts[1];
        unsigned long long fact_n_r = facts[2];

        unsigned long long nCr = fact_n / (fact_r * fact_n_r);
        unsigned long long nPr = fact_n / fact_n_r;

        printf("Parent: nCr = %llu\n", nCr);
        printf("Parent: nPr = %llu\n", nPr);

        munmap(shared_mem, size);
    } else {
        perror("fork failed");
        munmap(shared_mem, size);
        exit(1);
    }

    return 0;
}