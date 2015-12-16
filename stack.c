/*
 * COMP20007 Design of Algorithms
 * Semester 1 2015
 * Assignment 1 
 * Stack implementation.
 *
 * Luther Carroll
 * 391929
 * luthercarroll@runbox.com	
 * 24 - 3 - 2015
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"stack.h"

#define INITIAL_STACK_SIZE 1024 

/*
 * Return a new stack.
 */
Stack *stack_new() { 

	// Allocate an array for the contents.
	void **B;
	B = (void **) malloc(INITIAL_STACK_SIZE * sizeof(void *));
	assert(B);

	// Allocate a Stack and add in initial details.
	Stack *a_new_stack = (Stack *) malloc(sizeof(Stack));
	assert(a_new_stack);

	a_new_stack->A = B;
	a_new_stack->size = INITIAL_STACK_SIZE; // is initial size.
	a_new_stack->top = 0; // is empty.

	return a_new_stack;
}

/*
 * Push an item onto a stack.
 */
void stack_push(Stack *s, void *item) {  

	// Check the size of the stack.
	if (s->top == s->size) {
        	s->size *= 2;  // double the size of the stack.
        	s->A = (void **) realloc(s->A, sizeof(void *) * s->size);
        	assert(s->A);

	}
	// Push item onto the stack and increment top.
		s->A[s->top] = item;
		s->top++;
}

/*
 * Pop top element of stack.
 */
void  *stack_pop(Stack *s) { 

	s->top--;

	return s->A[s->top];
}

/*
 * Returns 1 if empty, 0 otherwise.
 */
int stack_isEmpty(Stack *s) {  
	
	return (s->top == 0);
}

/*
 * Print a stack.
 */
void stack_print(Stack *s, void(printFn)(void *)) {  

	printf("           Stack Print:          \n");
	printf("         Size of stack: %d       \n", s->top);
	printf("---------------------------------\n");
	printf("| SLOT:         | CONTENTS:     |\n");
	printf("---------------------------------\n");

	// Iterate through the stack to print its contents. 
	for (int i = 0; i < s->top; i++) {
		printf("| %14d", i);
		printf("| ");
		printFn(s->A[i]);
		printf("|\n");
	}

	printf("---------------------------------\n");
}
