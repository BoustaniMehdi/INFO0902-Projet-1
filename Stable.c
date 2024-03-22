#include "Stable.h"
#include "Sort.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int key;
    void *value;
}Element;

// --------------------------------------- GLOBAL VARIABLES ---------------------------------------------------- //


static int (*compare_stablesort)(const void *array, size_t i, size_t j);
static void (*swap_stablesort)(void *array, size_t i, size_t j);
static void *global_array;
static Element **element_array;

// --------------------------------------- GLOBAL VARIABLES ---------------------------------------------------- //


// ----------------------------------------- isSortStable --------------------------------------------------- //

static Element **create_element_array(const int *array, size_t length);
static void swap_element(void *array, size_t i, size_t j);
static int compare_int(const void *array, size_t i, size_t j);


static Element **create_element_array(const int *array, size_t length){

    element_array= malloc(length * sizeof(Element*));
    for (size_t i = 0; i < length; i++){
        element_array[i] = malloc(sizeof(Element));
        if (!element_array[i]){
            for (size_t j = 0; j < i; j++){
                free(element_array[j]);
            }
            return NULL;
        }
        element_array[i]->key = i;
        element_array[i]->value = (void *)&array[i];
    }
    return element_array;    
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


// ------------------------------------------- //


static int compare_new(const void *array, size_t i, size_t j){
    int compare = compare_stablesort(array, i, j);
    if (compare == 0){
        return element_array[i]->key - element_array[j]->key;
    }
    return compare;

}

static void swap_new(void *array, size_t i, size_t j) {
    swap_stablesort(array, i, j);
 
    Element *temp = element_array[i];
    element_array[i] = element_array[j];
    element_array[j] = temp;
    
}

void stableSort(size_t algo, void *array, size_t length,
                int (*compare)(const void *, size_t i, size_t j),
                void (*swap)(void *array, size_t i, size_t j))
{

   compare_stablesort = compare;
   swap_stablesort = swap;
   global_array = array;
   element_array = create_element_array(array, length);
   if (!element_array){
    return;
   }

   sort(algo, array, length, compare_new, swap_new);
   destroy_array(element_array, length);


}

// ----------------------------------------- isSortStable --------------------------------------------------- //
