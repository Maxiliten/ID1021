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



// Push an element onto the stack and double size if stack is full
void push(stack *stk, int val) {

    //Check if stack is full and create new bigger stack with the old elements
    if (stk->top == stk->size - 1) { 
        int new_size = stk->size * 2; 
        int *new_array = (int *)malloc(new_size * sizeof(int));
        printf("Incresing Stack Size\n");
        for (int i = 0; i <= stk->top; i++) { 
            new_array[i] = stk->array[i];
        }

    // Free old memory
    free(stk->array);
    //Change pointer and size to the new array
        stk->array = new_array; 
        stk->size = new_size; 
    }
    //Increment and push value on top of stack
    stk->array[++stk->top] = val;
}



// Pop an element from the stack, shrinking if necessary
int pop(stack *stk) {

    //Check if stack is empty
    if (stk->top == -1) {
        printf("Stack Empty\n");
        return 0;
    }
    //take value of top
    int val = stk->array[stk->top--];
    
    //Check if stack is half empty and bigger than 4 ints and create smaller array and copy old elements.
    if (stk->top < stk->size / 2 && stk->size > 4) {
        int new_size = stk->size / 2;
        int *new_array = (int *)malloc(new_size * sizeof(int));
        for (int i = 0; i <= stk->top; i++) {
            new_array[i] = stk->array[i];
        }

        // Free old memory
        free(stk->array);
        //Change pointer and size to new smaller stack
        stk->array = new_array;
        stk->size = new_size;
        printf("Reducing Stack Size\n", new_size);
    }

    //return value of top
    return val;
}


int main() {
    stack *stk = new_stack(4);
    push(stk, 10);
    push(stk, 20);
    push(stk, 30);
    push(stk, 40);
    push(stk, 50);      //Test for dynamic list (increase)

    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk));
    printf("Pop: %d\n", pop(stk));          //Test for dynamic list (reduce)

    return 0;
}
