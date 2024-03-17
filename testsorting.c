
#include "Sort.h"
#include "Stable.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>


// For all your tests, replace the code below by the sum of the IDs of the students in 
// your grou (in the format 20221234). If you don't use the correct code, the correction
// of your project will be impossible.

// const int studentcode = 123456;
const int studentcode = 20211757 + 20221594; //S211757 + S221594

// unsigned int nbComp = 0; // Global variable to count number of comparaisons


int *indices;


// --------------------------------- SORT STABLE ----------------------------------------------------- // 


static void swap_element(void *array, size_t i, size_t j);
static void swap_element(void *array, size_t i, size_t j)
{
    Element **elements = (Element **)array;
    Element *temp = elements[i];
    elements[i] = elements[j];
    elements[j] = temp;
}

static int compare_int_stable(const void *array, size_t i, size_t j);
static int compare_int_stable(const void *array, size_t i, size_t j){
    const Element **elements = (const Element **)array;
    const Element *e1 = elements[i];
    const Element *e2 = elements[j];

    if (*((int *)e1->value) == *((int *)e2->value))
        return e1->key - e2->key;
    
    else 
        return ( *((int *)e1->value) - *((int *)e2->value));

}


static void swap_int(void *array, size_t i, size_t j);
static int compare_int(const void *array, size_t i, size_t j);

static void swap_int(void *array, size_t i, size_t j)
{
	int temp = ((int *)array)[i];
	((int *)array)[i] = ((int *)array)[j]; 
	((int *)array)[j] = temp;

	int tmp = indices[i];
	indices[i] = indices[j];
	indices[j] = tmp;
}

static int compare_int(const void *array, size_t i, size_t j)
{
	// nbComp ++; INCREMENTATION of nbComp
	if (((int *)array)[i] - ((int *)array)[j] == 0){
		return indices[i] - indices[j];
	}
	return (((int *)array)[i] - ((int *)array)[j]);
}

int main(int argc, char *argv[])
{

	if (argc < 3 || argc > 4)
	{
		fprintf(stderr, "Usage: %s n algo [stable]\n   - n: the size of the random array\n "
						"  - algo: the algorithm (0,1,..., or 6})\n   - stable: (optional)"
						" run the stabilized version of the algorithm\n",
				argv[0]);
		exit(0);
	}

	srand(42);

	size_t n = atoi(argv[1]);
	size_t algo = atoi(argv[2]);
	bool stable = false;
	if (argc > 3 && strcmp(argv[3], "stable") == 0)
		stable = true;

	int *array = malloc(n * sizeof(int));
	indices = malloc(n * sizeof(int));

	for (size_t i = 0; i < n; i++){
		// array[i] = i + 1; // croissant
		// array[i] = n - i; // decroissant
		array[i] = rand() % (n * 10) - (n * 10) / 2;
		

		// INDICES
		indices[i] = i;
	}

	printf("Sorting a random array of size %zu with algorithm %zu", n, algo);
	if (stable)
		printf(" (stabilized)\n");
	else
		printf("\n");

	if (n <= 20)
	{
		printf("Original array:\n");
		for (size_t i = 0; i < n; i++)
			printf(" (%d : %d)", indices[i], array[i]);

		printf("\n\n");
	}

	clock_t start = clock();

	if (stable)
		stableSort(algo, array, n, compare_int, swap_int);
	else
		sort(algo, array, n, compare_int, swap_int);

	clock_t end = clock();

	if (n <= 20)
	{
		printf("Ordered array:\n");
		for (size_t i = 0; i < n; i++)
		{
			printf(" (%d : %d)", indices[i], array[i]);
		}
		printf("\n");
	}
	printf("CPU time: %f\n", (double)(end - start) / (double)CLOCKS_PER_SEC);
	// printf("Number of comparaison : %d\n", nbComp); // print number of comparaisons on screen
	free(array);
}