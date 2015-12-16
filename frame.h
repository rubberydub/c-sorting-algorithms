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
 *
 * Adapted from workshop 1.
 */

#define MERGE_TRUE 1
#define MERGE_FALSE 0

typedef struct {
	long start;	// Starting index of range.
	long end;	// Ending index of range.
	int merge;	// Merge flag. 0 do now merge. 1 merge	
} Frame;

Frame *frame_new(long start, long end, int merge);

void frame_print(void *);
