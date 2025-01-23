#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;       // Index of the top element
    int size;      // Maximum size of the stack
    int *array;    // Pointer to stack elements
} stack;

// Function to create a new stack
stack *new_stack(int size) {
    stack *stk = (stack *)malloc(sizeof(stack));
    stk->array = (int *)malloc(size * sizeof(int));
    stk->size = size;
    stk->top = -1; // Indicates stack is empty
    return stk;
}

// Function to push an element onto the stack
void push(stack *stk, int val) {
    if (stk->top == stk->size - 1) {
        printf("Stack overflow! Cannot push %d\n", val);
        return;
    }
    stk->array[++stk->top] = val; // Increment top and add value
}

// Function to pop an element from the stack
int pop(stack *stk) {
    if (stk->top == -1) {
        printf("Stack underflow! Returning 0\n");
        return 0; // Default value for an empty stack
    }
    return stk->array[stk->top--]; // Return top value and decrement top
}

// Test the static stack
int main() {
    stack *stk = new_stack(4);
    push(stk, 32);
    push(stk, 33);
    push(stk, 34);
    push(stk, 35);
    push(stk, 36); // This should trigger stack overflow

    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk)); // This should trigger stack underflow

    return 0;
}