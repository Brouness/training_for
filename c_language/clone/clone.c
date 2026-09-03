#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/wait.h>
#include <unistd.h>

// Allocate a 1 MB stack for the child task
#define STACK_SIZE (1024 * 1024)

// Shared variable between parent and child
int shared_variable = 42;

// This function runs inside the child task
int child_function(void *arg) {
    printf("[Child]  Started. Current shared_variable = %d\n", shared_variable);
    
    // Modify the shared variable
    shared_variable = 99;
    
    printf("[Child]  Changed shared_variable to = %d\n", shared_variable);
    return 0;
}

int main() {
    // Allocate memory for the child's stack
    char *stack = malloc(STACK_SIZE);
    if (!stack) {
        perror("malloc failed");
        exit(1);
    }

    // Stacks grow downward on x86, so point to the top of the allocated memory
    char *stack_top = stack + STACK_SIZE;

    printf("[Parent] Before clone, shared_variable = %d\n", shared_variable);

    // Call clone. CLONE_VM shares memory. SIGCHLD tells kernel to signal parent on exit.
    pid_t pid = clone(child_function, stack_top, CLONE_VM | SIGCHLD, NULL);

    if (pid == -1) {
        perror("clone failed");
        free(stack);
        exit(1);
    }

    // Wait for the child task to finish
    waitpid(pid, NULL, 0);

    // Because of CLONE_VM, the parent sees the change made by the child
    printf("[Parent] After child finished, shared_variable = %d\n", shared_variable);

    // Clean up stack memory
    free(stack);
    return 0;
}
