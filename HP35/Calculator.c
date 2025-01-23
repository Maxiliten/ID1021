#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the stack structure
typedef struct stack {
    int top;       // Tracks the index of the top element
    int size;      // Maximum capacity of the stack
    int *array;    // Pointer to the dynamically allocated array
} stack;

// Function to create a new stack
stack *new_stack(int size) {
    stack *stk = (stack *)malloc(sizeof(stack));       // Allocate memory for the stack structure
    stk->array = (int *)malloc(size * sizeof(int));    // Allocate memory for the array
    stk->size = size;                                  // Set the initial size
    stk->top = -1;                                     // Initialize the stack as empty
    return stk;
}

// Function to free the stack
void free_stack(stack *stk) {
    free(stk->array);                                  // Free the array memory
    free(stk);                                         // Free the stack structure memory
}

// Push an element onto the dynamic stack
void push(stack *stk, int val) {
    if (stk->top == stk->size - 1) {                   // Check if the stack is full
        int new_size = stk->size * 2;                  // Double the size of the stack
        int *new_array = (int *)malloc(new_size * sizeof(int)); // Allocate a new array
        for (int i = 0; i <= stk->top; i++) {          // Copy old elements to the new array
            new_array[i] = stk->array[i];
        }
        free(stk->array);                              // Free the old array memory
        stk->array = new_array;                        // Update the pointer to the new array
        stk->size = new_size;                          // Update the stack size
        printf("Stack resized to %d\n", new_size);     // Inform the user about the resize
    }
    stk->array[++stk->top] = val;                      // Increment top and add the value
}

// Pop an element from the dynamic stack
int pop(stack *stk) {
    if (stk->top == -1) {                              // Check if the stack is empty
        printf("Stack underflow! Returning 0\n");
        return 0;                                      // Return 0 as a default value
    }
    int val = stk->array[stk->top--];                  // Retrieve the value and decrement top
    if (stk->top < stk->size / 4 && stk->size > 4) {   // Shrink the stack if underutilized
        int new_size = stk->size / 2;                  // Halve the size of the stack
        int *new_array = (int *)malloc(new_size * sizeof(int)); // Allocate a smaller array
        for (int i = 0; i <= stk->top; i++) {          // Copy elements to the smaller array
            new_array[i] = stk->array[i];
        }
        free(stk->array);                              // Free the old array memory
        stk->array = new_array;                        // Update the pointer to the new array
        stk->size = new_size;                          // Update the stack size
        printf("Stack resized to %d\n", new_size);     // Inform the user about the resize
    }
    return val;                                        // Return the popped value
}

// Main function for the calculator
int main() {
    stack *stk = new_stack(4);                         // Initialize the dynamic stack with size 4
    printf("HP-35 Pocket Calculator (Reverse Polish Notation)\n");
    printf("Enter numbers and operators (+, -, *, /). Press ENTER to exit.\n");

    char buffer[10];                                   // Buffer for user input
    int run = 1;                                       // Loop control variable

    while (run) {
        printf(" > ");
        fgets(buffer, 10, stdin);                      // Read input from the user

        if (strcmp(buffer, "\n") == 0) {               // Quit if input is just ENTER
            run = 0;
        } else if (strcmp(buffer, "+\n") == 0) {       // Perform addition
            int a = pop(stk);
            int b = pop(stk);
            push(stk, a + b);
        } else if (strcmp(buffer, "-\n") == 0) {       // Perform subtraction
            int a = pop(stk);
            int b = pop(stk);
            push(stk, b - a);                          // Note: Order matters for subtraction
        } else if (strcmp(buffer, "*\n") == 0) {       // Perform multiplication
            int a = pop(stk);
            int b = pop(stk);
            push(stk, a * b);
        } else if (strcmp(buffer, "/\n") == 0) {       // Perform division
            int a = pop(stk);
            int b = pop(stk);
            if (a != 0) {
                push(stk, b / a);                      // Note: Order matters for division
            } else {
                printf("Division by zero error\n");
                push(stk, b);                          // Restore the second operand
            }
        } else {                                       // Assume the input is a number
            int val = atoi(buffer);                   // Convert input to an integer
            push(stk, val);                           // Push the number onto the stack
        }
    }

    printf("The result is: %d\n", pop(stk));           // Output the final result
    printf("Goodbye! I love reverse Polish notation, don't you?\n");
    free_stack(stk);                                   // Free the stack memory
    return 0;
}


