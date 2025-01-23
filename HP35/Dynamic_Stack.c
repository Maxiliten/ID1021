#include <stdio.h>
#include <stdlib.h>

// Define the stack structure   (Same as in Static Stack)
typedef struct stack {
    int top;       // Index of the top element
    int size;      // Maximum size of the stack
    int *array;    // Pointer to the stack elements
} stack;

/*Creating new stacks*/
stack *new_stack(int size) {
    stack *stk = (stack *)malloc(sizeof(stack));      // Allocate memory for the stack structure
    stk->array = (int *)malloc(size * sizeof(int));   // Allocate memory for the array
    stk->size = size;                                 // Set the initial size (capacity) of the stack
    stk->top = -1;                                    // Initialize the stack as empty
    return stk;                                       // Return the pointer to the stack
}



// Push an element onto the stack, resizing if necessary
void push(stack *stk, int val) {

    /*Checks if stack is full, if full create a new array with double the old size, copies the elements of old stack to new, frees the old memory, 
    change pointer to new array, updates the stack's size, sends out a message about the new size of new stack, increments top and then adds a new value on that memory spot*/

    if (stk->top == stk->size - 1) {                                     // Check if the stack is full
        int new_size = stk->size * 2;                                    // Double the size of the stack
        int *new_array = (int *)malloc(new_size * sizeof(int));          // Allocate a new array with the larger size
        for (int i = 0; i <= stk->top; i++) {                            // Copy elements from the old array to the new one
            new_array[i] = stk->array[i];
        }
        free(stk->array);                                                // Free the memory of the old array
        stk->array = new_array;                                          // Point to the new array
        stk->size = new_size;                                            // Update the stack's size
        printf("Stack resized to %d\n", new_size);                       // Inform the user about the resize
    }

    stk->array[++stk->top] = val;                                        // Utilizes the old position of top pointer and increments it by 1 then inserts the value.
}



// Pop an element from the stack, shrinking if necessary
int pop(stack *stk) {
    if (stk->top == -1) {                                               // Check if the stack is empty
        printf("Stack underflow! Returning 0\n");
        return 0;                                                       // Return 0 as a default value
    }
    int val = stk->array[stk->top--];                                   // Retrieve and remove the top value
    if (stk->top < stk->size / 4 && stk->size > 4) {                    // Check if the pointer is currently less than size/4 and size is bigger than 4 slots to decide if to shrink
        int new_size = stk->size / 2;                                   // Halve the size of the stack
        int *new_array = (int *)malloc(new_size * sizeof(int));         // Allocate a smaller array
        for (int i = 0; i <= stk->top; i++) {                           // Copy elements from the old array to the new one
            new_array[i] = stk->array[i];
        }
        free(stk->array);                                            // Free the memory of the old array
        stk->array = new_array;                                      // Point to the new array
        stk->size = new_size;                                        // Update the stack's size
        printf("Stack resized to %d\n", new_size);                   // Inform the user about the resize
    }
    return val;                                                      // Return the value popped from the stack
}



// Free the stack memory
void free_stack(stack *stk) {
    free(stk->array);   // Free the array memory
    free(stk);          // Free the stack structure memory
}



int main() {
    stack *stk = new_stack(4);
    push(stk, 10);
    push(stk, 20);
    push(stk, 30);
    push(stk, 40);
    push(stk, 50); // Resize happens here

    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk)); // Resize may happen here

    free_stack(stk);
    return 0;
}
