#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;                         // Index of the top element
    int size;                        // Maximum size of the stack
    int *array;                      // Pointer to stack elements
} stack;

// Function to create a new stack
stack *new_stack(int size) {
    stack *stk = (stack *)malloc(sizeof(stack));
    stk->array = (int *)malloc(size * sizeof(int));

    stk->size = size;                       /*Added: A size as a independent variable from the structure so we do not need to rely on the original size, 
                                            making manipulation of size easier with push and pop.*/

    stk->top = -1;                             // Added: A starting point for the poiner to know where the current top is or if empty as -1 = 0 elements, 0 = 1 element, 1 = 2 elements.. etc.

    return stk;
}

// Function to push an element onto the stack
void push(stack *stk, int val) {
    if (stk->top == stk->size - 1) {                        //Check if the stack is full by checking top value is equal to the size of the array - 1 hence full.
        printf("Stack overflow! Cannot push %d\n", val);    //Prints out error message about overflow to inform user about error.
        return;
    }
    stk->array[++stk->top] = val;                           // Increment top to move pointer and assign the value to the stack.
}

// Function to pop an element from the stack
int pop(stack *stk) {
    if (stk->top == -1) {                           //Check if stack is empty, by checking if top == -1 indicating empty stack.
        printf("Stack underflow! Returning 0\n");   //Send out error message to inform user.
        return 0;                                   // Default value for an empty stack.
    }
    return stk->array[stk->top--];                  // Return top value and decrement top
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

/* When trying to push on more values, that is overfilling the stack. It would write in the adjecent memory and not give a notice as C does not perform rutine checks like Java.
In my case it worked without crashes, or irregular behaviour of the program, however a tested a few times and it still worked. But with more complex programs or just by chance it
could overwrite important memory that can cause the program to crash, corrupt the files progressively for future uses, or cause weird behaviour overall. I instead implemented error
messages like overflow and underflow to inform the users of the program about this. So pushing an overstacked stack with more numbers would cause overwritting onto adjecent memories
while poping an empty stack would pop adjecent memory outside the stack in the same manner. Hence I put in the error messages as this could prove detrimental*/