/*
 *
 *   srtheap.c file
 *
 */

// added this
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include "srt.h"

#define RIGHT(x)  (((x) << 1) + 2)
#define LEFT(x)   (((x) << 1) + 1)
#define PARENT(x) (((x) - 1) >> 1)

bool tick = true;

void oneLevelCheck(void *base, int i, int nelem, int (*compar)(const void *, const void *), int bound, bool inRemoveOffEnd);
void removeOffEnd(void *base, int i, int nelem, int (*compar)(const void *, const void *));
void oneLevelCheckFloat(void *base, int i, int nelem, int (*compar)(const void *, const void *), int bound, bool inRemoveOffEnd);
void removeOffEndFloat(void *base, int i, int nelem, int (*compar)(const void *, const void *));

void srtheap(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *)) {

    if (size == 8) {

        int start = (nelem / 2) - 1;
        // int heapHeight = (log((int)nelem + 1) / log(2)) - 1;
        // printf("Heap height: %i\n", heapHeight);

        printf("\nOriginal array is: \n");
        for(int i=0;i<nelem;i++)
        {
            printf("%f\n",*((double*)base + i));
        }

        // building max heap
        for (int i = start; i >= 0; i--) {

            oneLevelCheck(base, i, (int)nelem, compar, (int)nelem, false);

        }

        // creating new array based off max heap
        for (int i = 0; i < nelem; i++) {

            removeOffEnd(base, i, (int)nelem, compar);

        }

        printf("\nSorted array is: \n");
    	for(int i=0;i<nelem;i++)
    	{
    		printf("%f\n",*((double*)base + i));
    	}


    } else {

        int start = (nelem / 2) - 1;
        // int heapHeight = (log((int)nelem + 1) / log(2)) - 1;
        // printf("Heap height: %i\n", heapHeight);

        // printf("\nOriginal array is: \n");
        // for(int i=0;i<nelem;i++)
        // {
        //     printf("%f\n",*((float*)base + i));
        // }

        // building max heap
        for (int i = start; i >= 0; i--) {

            oneLevelCheckFloat(base, i, (int)nelem, compar, (int)nelem, false);

        }

        // creating new array based off max heap
        for (int i = 0; i < nelem; i++) {

            removeOffEndFloat(base, i, (int)nelem, compar);

        }

        // printf("\nSorted array is: \n");
        // for(int i=0;i<nelem;i++)
        // {
        //     printf("%f\n",*((float*)base + i));
        // }


    }

	return;

}

// getting a zero from this function
void oneLevelCheck(void *base, int i, int nelem, int (*compar)(const void *, const void *), int bound, bool inRemoveOffEnd) {

    double temp;
    double *parentp = (double*)base + i;
    double *rp = (double *)base + RIGHT(i);
    double *lp = (double *)base + LEFT(i);

    // if not called from function removeOffEnd enter here
    if (!inRemoveOffEnd) {
        if (compar(rp, lp) > 0) {
            printf("right is greater than left.\n");
            if (compar(rp, parentp) > 0) {
                printf("right is greater than parent.\n");
                temp = *parentp;
                *parentp = *rp;
                *rp = temp;
                if (RIGHT(RIGHT(i)) < bound) {
                    oneLevelCheck(base, RIGHT(i), nelem, compar, bound, inRemoveOffEnd);
                }
            }
        } else {
            if (compar(lp, parentp) > 0) {
                printf("left %f is greater than parent %f.\n", *lp, *parentp);

                temp = *parentp;
                *parentp = *lp;
                *lp = temp;
                if (RIGHT(RIGHT(i)) < bound) {
                    oneLevelCheck(base, LEFT(i), nelem, compar, bound, inRemoveOffEnd);
                }
            }
        }
    // end of original
    // if called from function removeOffEnd enter below
    } else {
        // if only leftmost bottom node is available (only check bottom left node)
        if ((tick) && (RIGHT(i) == bound)) {
            if (compar(lp, parentp) > 0) {
                temp = *parentp;
                *parentp = *lp;
                *lp = temp;
                if (RIGHT(RIGHT(i)) < bound) {
                    oneLevelCheck(base, LEFT(i), nelem, compar, bound, inRemoveOffEnd);
                }
            }
        // both bottomost nodes are available (check both nodes)
        } else {
            // same code as above just copy/paste
            if (compar(rp, lp) > 0) {
                if (compar(rp, parentp) > 0) {
                    temp = *parentp;
                    *parentp = *rp;
                    *rp = temp;
                    if (RIGHT(RIGHT(i)) < bound) {
                        oneLevelCheck(base, RIGHT(i), nelem, compar, bound, inRemoveOffEnd);
                    }
                }
            } else {
                if (compar(lp, parentp) > 0) {
                    temp = *parentp;
                    *parentp = *lp;
                    *lp = temp;
                    if (RIGHT(RIGHT(i)) < bound) {
                        oneLevelCheck(base, LEFT(i), nelem, compar, bound, inRemoveOffEnd);
                    }
                }
            }
        }

        tick = !tick;
    } // end of main else

}

// function just swaps first and last position and then fixes max heap
void removeOffEnd(void *base, int i, int nelem, int (*compar)(const void *, const void *)) {

    double temp;
    double *top = (double*)base;
    double *last = (double*)base + (nelem - i);

    temp = *top;
    *top = *last;
    *last = temp;

    // only checks to nelem - i
    oneLevelCheck(base, 0, nelem, compar, nelem-i, true);

}

// getting a zero from this function
void oneLevelCheckFloat(void *base, int i, int nelem, int (*compar)(const void *, const void *), int bound, bool inRemoveOffEnd) {

    float temp;
    float *parentp = (float*)base + i;
    float *rp = (float *)base + RIGHT(i);
    float *lp = (float *)base + LEFT(i);

    // if not called from function removeOffEnd enter here
    if (!inRemoveOffEnd) {
        if (compar(rp, lp) > 0) {
            if (compar(rp, parentp) > 0) {
                temp = *parentp;
                *parentp = *rp;
                *rp = temp;
                if (RIGHT(RIGHT(i)) < bound) {
                    oneLevelCheckFloat(base, RIGHT(i), nelem, compar, bound, inRemoveOffEnd);
                }
            }
        } else {
            if (compar(lp, parentp) > 0) {
                temp = *parentp;
                *parentp = *lp;
                *lp = temp;
                if (RIGHT(RIGHT(i)) < bound) {
                    oneLevelCheckFloat(base, LEFT(i), nelem, compar, bound, inRemoveOffEnd);
                }
            }
        }
    // end of original
    // if called from function removeOffEnd enter below
    } else {
        // if only leftmost bottom node is available (only check bottom left node)
        if ((tick) && (RIGHT(i) == bound)) {
            if (compar(lp, parentp) > 0) {
                temp = *parentp;
                *parentp = *lp;
                *lp = temp;
                if (RIGHT(RIGHT(i)) < bound) {
                    oneLevelCheckFloat(base, LEFT(i), nelem, compar, bound, inRemoveOffEnd);
                }
            }
        // both bottomost nodes are available (check both nodes)
        } else {
            // same code as above just copy/paste
            if (compar(rp, lp) > 0) {
                if (compar(rp, parentp) > 0) {
                    temp = *parentp;
                    *parentp = *rp;
                    *rp = temp;
                    if (RIGHT(RIGHT(i)) < bound) {
                        oneLevelCheckFloat(base, RIGHT(i), nelem, compar, bound, inRemoveOffEnd);
                    }
                }
            } else {
                if (compar(lp, parentp) > 0) {
                    temp = *parentp;
                    *parentp = *lp;
                    *lp = temp;
                    if (RIGHT(RIGHT(i)) < bound) {
                        oneLevelCheckFloat(base, LEFT(i), nelem, compar, bound, inRemoveOffEnd);
                    }
                }
            }
        }

        tick = !tick;
    } // end of main else

}

void removeOffEndFloat(void *base, int i, int nelem, int (*compar)(const void *, const void *)) {

    float temp;
    float *top = (float*)base;
    float *last = (float*)base + (nelem - i);

    temp = *top;
    *top = *last;
    *last = temp;

    // only checks to nelem - i
    oneLevelCheckFloat(base, 0, nelem, compar, nelem-i, true);

}
