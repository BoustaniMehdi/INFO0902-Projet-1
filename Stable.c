#include "Stable.h"
#include "Sort.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


// --------------------------------------- GLOBAL VARIABLES ---------------------------------------------------- //


static int (*compare_stablesort)(const void *array, size_t i, size_t j);
static void (*swap_stablesort)(void *array, size_t i, size_t j);
static int *global_array;

// --------------------------------------- GLOBAL VARIABLES ---------------------------------------------------- //


// -------------------------------------------- stableSort  ------------------------------------------------- //


static int compare_new(const void *array, size_t i, size_t j){
    int compare = compare_stablesort(array, i, j);
    return compare;

}

static void swap_new(void *array, size_t i, size_t j) {
    swap_stablesort(global_array, i, j);
}


void stableSort(size_t algo, void *array, size_t length,
                int (*compare)(const void *, size_t i, size_t j),
                void (*swap)(void *array, size_t i, size_t j))
{

   compare_stablesort = compare;
   swap_stablesort = swap;
   global_array = array;

   sort(algo, array, length, compare_new, swap_new);


}


// -------------------------------------------- stableSort  ------------------------------------------------- //




// ----------------------------------------- isSortStable --------------------------------------------------- //

static Element **create_element_array(const int *array, size_t length);
static void swap_element(void *array, size_t i, size_t j);
static int compare_int(const void *array, size_t i, size_t j);


static Element **create_element_array(const int *array, size_t length){

    Element** newArray = malloc(length * sizeof(Element*));
    for (size_t i = 0; i < length; i++){
        newArray[i] = malloc(sizeof(Element));
        if (!newArray[i]){
            for (size_t j = 0; j < i; j++){
                free(newArray[j]);
            }
            printf("Error allocating memory\n");
            return NULL;
        }
        newArray[i]->key = i;
        newArray[i]->value = (void *)&array[i];
    }
    return newArray;    
}


static void swap_element(void *array, size_t i, size_t j)
{
    Element **elements = (Element **)array;
    Element *temp = elements[i];
    elements[i] = elements[j];
    elements[j] = temp;
}


static int compare_int(const void *array, size_t i, size_t j)
{
    const Element **elements = (const Element **)array;
    const Element *e1 = elements[i];
    const Element *e2 = elements[j];
    return ( *((int *)e1->value) - *((int *)e2->value));
}


static void destroy_array(Element **elements, size_t length){
    for (size_t i = 0; i < length; i++){
        free(elements[i]);
    }
    free (elements);
}


bool isSortStable(size_t algo, const int *array, size_t length)
{
    // A compléter
    Element **newArray = create_element_array(array, length);
    if (!newArray){
        return EXIT_FAILURE;
    }
    sort(algo, newArray, length, compare_int, swap_element);

   
    for (size_t i = 0; i < length-1; i++){
        if (!compare_int(newArray, i, i+1) && newArray[i]->key > newArray[i+1]->key){
            destroy_array(newArray, length);
            return false;
        }
    }
    destroy_array(newArray, length);
    return true;
}

// ----------------------------------------- isSortStable --------------------------------------------------- //

