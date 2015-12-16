/*
 * COMP20007 Design of Algorithms
 * Semester 1 2015
 * Assignment 1 
 * Partition function.
 *
 * Luther Carroll
 * 391929
 * luthercarroll@runbox.com	
 * 24 - 3 - 2015
 */


#include <stdio.h>
#include <stdlib.h>

typedef long Type;

/*
 * Swap by value. 
 */
void swap(Type *x, Type *y) {
	Type temp = *x;
	*x = *y;
	*y = temp;
}

/*
 * Partiton function
 */
int partition(void **A, int n, void *pivot, int (cmp)(void *, void *)) {

	// Casts to appropriate Type.
	Type *B = (Type *) A;

	/* Pointer to a pivot for swaps and a seperate 
	 * variable for comparisons.
	 */
	Type *pivot_pointer = (Type *) pivot;
	Type pivot_value = *((Type *) pivot);

	// Swap pivot and right.
	swap(pivot_pointer, B + n);	

	// Store index and increment for main loop.
	int sI = 0, i;

	// Main loop.
	for(i = 0; i < n; i++) {

		/* If B[i] < pivot, swap with sI.
		 * cmp requires: cmp(void *, void *);
		 * cmp requires: x > y direction of comparison.
		 */
		if (cmp((void *) pivot_value, (void *) B[i]) > 0) {
			swap(B + sI, B + i);
			sI++;
		}
	}
	// Place pivot in correct spot ie A[sI]
	swap(B + n, B + sI);

	return sI;
}
