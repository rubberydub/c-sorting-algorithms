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

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "frame.h"

/*
 * Create a new frame with values <type payload>
 * and return a pointer to that frame.
 */
Frame *frame_new(long start, long end, int merge) {
    Frame *f = (Frame *) malloc(sizeof(Frame));
    assert(f);

    f->start = start;
    f->end = end;
    f->merge = merge;

    return f;
}

/*
 * Print the frame pointed to by p
 */
void frame_print(void *p) {
    assert(p);

    Frame *f = (Frame *)p;
    printf("Start: %ld, End: %ld, Merge Flag: %d\n", f->start, f->end, f->merge);
}
