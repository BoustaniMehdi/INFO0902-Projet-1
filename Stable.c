#include "Stable.h"
#include "Sort.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool isSortStable(size_t algo, const int *array, size_t length)
{
    // A compléter
    return true;
}

void stableSort(size_t algo, void *array, size_t length,
                int (*compare)(const void *, size_t i, size_t j),
                void (*swap)(void *array, size_t i, size_t j))
{
    // A modifier/compléter
    sort(algo, array, length, compare, swap);
}
