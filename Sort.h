
#ifndef SORT_H_
#define SORT_H_

#include <stdlib.h>

extern const int studentcode;

void sort(size_t algo, void *array, size_t length,
		  int (*compare)(const void *, size_t i, size_t j),
		  void (*swap)(void *array, size_t i, size_t j));

int isSorted(void *array, size_t length, int (*compare)(const void *, size_t i, size_t j));

#endif // SORT_H_
