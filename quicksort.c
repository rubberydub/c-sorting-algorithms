/*
 * COMP20007 Design of Algorithms
 * Semester 1 2015
 * Assignment 1 
 * Quicksort.
 *
 * Luther Carroll
 * 391929
 * luthercarroll@runbox.com	
 * 24 - 5- 2015
 */

#include<stdio.h>
#include"stack.h"
#include"partition.h"

/*
 * Quicksort.
 */
void myQuicksort(void **A, int n, int(cmp)(void *, void*)) {
	
	long left = 0, right = n - 1, pivot;
	Stack *stack = stack_new();

	// Push the initial range on to the stack.
	stack_push(stack, (void *) left);
	stack_push(stack, (void *) right);

	// Main loop.
	while (!stack_isEmpty(stack)) {

		// Pop next pivot range off the stack.
		right = (long) stack_pop(stack);
		left = (long) stack_pop(stack);

		// Partition the range.
		pivot = left + partition(A + left, right - left, A + left, cmp); 

		/* If the range between the left end and the pivot remains
		 * to be pivoted, push that range onto the stack.
		 */
		if (pivot - 1 > left) {
			stack_push(stack, (void *) left);
			stack_push(stack, (void *) (pivot - 1));
		}

		/* If the range between the pivot and the right end remains
		 * to be pivoted, push that range onto the stack.
		 */
		if (pivot + 1 < right) {
			stack_push(stack, (void *) (pivot + 1));
			stack_push(stack, (void *) right);
		}
	}
	return;
}
