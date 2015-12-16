/*
** Partition A[0..n-1] so that 
**  all elements less than ** *pivot are in A[0..k-1] and 
**  all elements not less than *pivot ** are in A[k..n-1]. 
** cmp should be used for comparisons.
**
** @return k
**
** Andrew Turpin
** Thu 26 Feb 2015 08:42:06 AEDT
*/

typedef long Type;

/*
 * Swap by value. 
 */
void swap(Type *x, Type *y);

/*
 * Partiton function
 */
int partition(void **A, int n, void *pivot, int (cmp)(void *, void *));
