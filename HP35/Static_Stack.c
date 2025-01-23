#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;                         // Index for top of stack
    int size;                        // Size of stack
    int *array;                      // Pointer for stack elements
} stack;

// Function to create a new stack
stack *new_stack(int size) {

    //Allocate memory for array/stack
    stack *stk = (stack *)malloc(sizeof(stack));
    stk->array = (int *)malloc(size * sizeof(int));

    //Create a local size variable and initiate top index to -1
    stk->size = size;
    stk->top = -1;
    return stk;
}

// Function to push an element onto the stack
void push(stack *stk, int val) {

    //Check if stack is full and give warning
    if (stk->top == stk->size - 1) {
        printf("Stack overflow! Cannot push %d\n", val);
        return;
    }

    //Increment top index and assign value to top of stack
    stk->array[++stk->top] = val;
}

// Function to pop an element from the stack
int pop(stack *stk) {

    //Check if stack is empty and give warning
    if (stk->top == -1) {
        printf("Stack underflow! Returning 0\n");
        return 0;
    }

    //return value and decrement top index
    return stk->array[stk->top--];
}

// Test the static stack
int main() {
    stack *stk = new_stack(4);
    push(stk, 32);
    push(stk, 33);
    push(stk, 34);
    push(stk, 35);
    push(stk, 36);                      // Test to trigger overflow

    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk));      //Test to trigger underflow

    return 0;
}