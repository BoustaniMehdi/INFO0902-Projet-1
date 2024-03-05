#ifndef STABLE_H_
#define STABLE_H_

#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Return true if the sorting algorithm identified by the first argument
 *        is stable for the given array of integers.
 *
 * @param algo      the first argument of the sort function.
 * @param array     the array of int.
 * @param length    the length of the array.
 * @return bool     true if the sort is stable, false otherwise.
 */

bool isSortStable(size_t algo, const int *array, size_t length);

/**
 * @brief Sort the array using the sort function from Sort.h with the given algorithm.
 *        The sorting is guaranteed to be stable whatever the choosen algorithm and to
 *        preserve the time complexity of the original sort function.
 *
 * @param algo      the first argument of the sort function.
 * @param array     the array to be sorted.
 * @param length    the length of the array.
 * @param compare   a function to compare elements from the array.
 * @param swap      a function to swap elements from the array.
 */

void stableSort(size_t algo, void *array, size_t length,
                int (*compare)(const void *, size_t i, size_t j),
                void (*swap)(void *array, size_t i, size_t j));

#endif // STABLE_H_
