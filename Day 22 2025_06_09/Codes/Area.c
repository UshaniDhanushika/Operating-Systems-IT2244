#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <sys/wait.h>
#include <ctype.h>

// Child calculates area based on choice char
float calculateAreaByChoice(char choice, float a, float b) {
    switch (toupper(choice)) {
        case 'C': // Circle
            return M_PI * a * a;
        case 'R': // Rectangle
            return a * b;
        case 'T': // Triangle
            return 0.5 * a * b;
        case 'S': // Square
            return a * a;
        default:
            return -1; // Invalid choice
    }
}

int main() {
    int ptc[2]; // Parent to Child pipe
    int ctp[2]; // Child to Parent pipe

    if (pipe(ptc) == -1 || pipe(ctp) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {
        // ===== PARENT PROCESS =====

        close(ptc[0]); // Close read end of ptc
        close(ctp[1]); // Close write end of ctp

        char choice;
        float val1 = 0, val2 = 0;

        printf("Area calculation program\n");
        printf("Circle => C\nTriangle => T\nSquare => S\nRectangle => R\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        choice = toupper(choice); // convert to uppercase for uniformity

        switch (choice) {
            case 'C':
                printf("Enter radius: ");
                scanf("%f", &val1);
                val2 = 0;
                break;
            case 'T':
                printf("Enter base: ");
                scanf("%f" , &val1);
				printf("Enter height: ");
				scanf("%f" , &val2);
                break;
				
            case 'S':
                printf("Enter side: ");
                scanf("%f", &val1);
                val2 = 0;
                break;
            case 'R':
				printf("Enter length ");
                scanf("%f" , &val1);
				printf("Enter width: ");
				scanf("%f" , &val2);
                break;
				
            default:
                printf("Invalid choice entered.\n");
                close(ptc[1]);
                close(ctp[0]);
                wait(NULL);
                return 1;
        }

        // Send choice and values to child
        write(ptc[1], &choice, sizeof(char));
        write(ptc[1], &val1, sizeof(float));
        write(ptc[1], &val2, sizeof(float));

        // Read area from child
        float area;
        read(ctp[0], &area, sizeof(float));
        if (area < 0)
            printf("\n[Parent] Invalid choice received from child\n");
        else
            printf("\n[Parent] Area received from child: %.2f\n", area);

        close(ptc[1]);
        close(ctp[0]);

        wait(NULL);

    } else {
        // ===== CHILD PROCESS =====

        close(ptc[1]); // Close write end of ptc
        close(ctp[0]); // Close read end of ctp

        char choice;
        float a, b;

        read(ptc[0], &choice, sizeof(char));
        read(ptc[0], &a, sizeof(float));
        read(ptc[0], &b, sizeof(float));

        float result = calculateAreaByChoice(choice, a, b);

        write(ctp[1], &result, sizeof(float));

        close(ptc[0]);
        close(ctp[1]);
    }

    return 0;
}