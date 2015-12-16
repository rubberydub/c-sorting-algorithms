/*
 * COMP20007 Design of Algorithms
 * Semester 1 2015
 * Assignment 1 
 * Quicksort.
 *
 * Luther Carroll
 * 391929
 * luthercarroll@runbox.com	
 * 24 - 3 - 2015
 */

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include<assert.h>
#include"frame.h"

/*
 * Merge.
 */
void merge(void **A, long start, long middle, long end) {
	
	/* Various indicies.
	 * i and j for traversing the ranges for merging.
	 * n for traversing the temp array.
	 * k for the correct iterations for the next two loops.
	 */
	long i = start, j = middle, n = 0, k; 

	// Temp array.
	long *temp = (long *) malloc(((int) (end + 1 - start)) * sizeof(long));

	// Iterate over the range.
	for (k = start; k <= end; k++) {
		
		// If i is in range and either j is out of range or A[i] < A[j].
		if (i < middle && (j == end + 1 || (long) A[i] <= (long) A[j])) {

			temp[n] = (long) A[i];
			i++;
			n++;
		}
		// Else it must be A[j].
		else {

			temp[n] = (long) A[j];
			j++;
			n++;
		}
	}

	// Copy the temp array into A.
	//TODO seperate function.
	for (k = 0; k <= end - start; k++) {

		A[start + k] = (void *) temp[k];
	}

	free(temp);
}

/*
 * Mergesort.
 *
 * There are a lot of needless variables in this funtion
 * but they are for clarity.
 */
void myMergesort(void **A, int n, int(cmp)(void *, void*)) {
	
	// If A is only one element, return.
	if (n == 1)
		return;

	long start = 0, middle = (n - 1)/2, end = n - 1;
	//long range_start, range_end, range_mid, merge_start, merge_middle, merge_end;
	Stack *stack = stack_new();

	// Frame pointers for algorithm.
	Frame *frame, *frame2;
	
	// Push first ranges onto stack.
	stack_push(stack, frame_new(start, middle, MERGE_FALSE));
	stack_push(stack, frame_new(middle + 1, end, MERGE_FALSE));

	while (!stack_isEmpty(stack)) {

		// Next range.
		frame = ((Frame *) stack_pop(stack));
		long range_start = frame->start;
		long range_end = frame->end;
		long range_mid = range_start + (range_end - range_start)/2;

		// Range not ready to merge.
		if (!frame->merge) {
			
			/* Range is length 1, so flag for merging and
			 * push back onto stack.
			 */
			if (range_end - range_start == 0) {

				stack_push(stack, frame_new(range_start, range_end, MERGE_TRUE));

			}
			// Divide range in half and push new ranges onto stack.
			else {

				stack_push(stack, frame_new(range_start, range_mid, MERGE_FALSE));
				stack_push(stack, frame_new(range_mid + 1, range_end, MERGE_FALSE));

			}

		} 
		// Range ready to merge. Also check that range is not last range.
		else if(frame->merge && !stack_isEmpty(stack)) {

			frame2 = ((Frame *) stack_pop(stack));

			long second_range_start = frame2->start;
			long second_range_end = frame2->end;

			// If next range also ready, then merge and push new range.
			if (frame2->merge) {

				// Use ternaries to find range of merged items.
				long merge_start = range_start < second_range_start? range_start : second_range_start;
				long merge_middle = range_start > second_range_start? range_start : second_range_start;
				long merge_end = range_end > second_range_end ? range_end : second_range_end;

				merge(A, merge_start, merge_middle, merge_end);
				
				stack_push(stack, frame_new(merge_start, merge_end, MERGE_TRUE));
				
			}
			// If not, just push frames back onto stack in reverse order and continue.
			else { 

				stack_push(stack, frame_new(range_start, range_end, MERGE_TRUE));
				stack_push(stack, frame_new(second_range_start, second_range_end, MERGE_FALSE));
			}

			// Free used frames.
			free(frame2);
		}
		
		// Free used frames.
		free(frame);

	}
	
    	return;
}
