//C Program to execute Linux system commands using Linux API system calls exec() family

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int status;
    pid_t pid;

    printf("Running ps with execlp\n");
    pid = fork();
    
    if (pid == 0)
    {
        // This is the child process
        execlp("ps", "ps", "ax", NULL);
        // If execlp fails, print an error message
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    else if (pid > 0)
    {
        // This is the parent process
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child exited with status of %d\n", WEXITSTATUS(status));
        } else {
            puts("Child did not exit successfully");
        }
    }

    else {
        // fork() failed
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    printf("Done.\n");

    printf("Running ps with execl. Now with path specified\n");
    pid = fork();
    
    if (pid == 0)
    {
        // This is the child process
        execl("/bin/ps", "ps", "ax", NULL);
        // If execl fails, print an error message
        perror("execl");
        exit(EXIT_FAILURE);
    }
   else if (pid > 0)
    {
        // This is the parent process
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child exited with status of %d\n", WEXITSTATUS(status));
        } else {
            puts("Child did not exit successfully");
        }
    }

  else {
        // fork() failed
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    printf("Done.\n");

    return 0;
}
