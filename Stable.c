#include "Stable.h"
#include "Sort.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>




// static void global_swap(void *array, size_t i, size_t j);
// static int global_compare(const void *array, size_t i, size_t j);

// static int *indices;


static Element **create_element_array(const int *array, size_t length);

static void swap_element(void *array, size_t i, size_t j);


// static int compare_int_stable(const void *array, size_t i, size_t j);

// -------------------------------- COMPARE FUNCTIONS ---------------------------------------------- //

static int compare_int(const void *array, size_t i, size_t j);
// static int compare_char(const void *array, size_t i, size_t j);

// -------------------------------- COMPARE FUNCTIONS ---------------------------------------------- //




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

// -------------------------------- COMPARE FUNCTIONS ---------------------------------------------- //

static int compare_int(const void *array, size_t i, size_t j)
{
    const Element **elements = (const Element **)array;
    const Element *e1 = elements[i];
    const Element *e2 = elements[j];
    return ( *((int *)e1->value) - *((int *)e2->value));
}


// -------------------------------- COMPARE FUNCTIONS ---------------------------------------------- //

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

    // printf("newArray ordered : \n");
    // for (size_t i = 0; i < length ; i++){
    //     printf("%d ", *((int *)newArray[i]->value));
    //  }
    //  printf("\n\n");

    for (size_t i = 0; i < length-1; i++){
        if (!compare_int(newArray, i, i+1) && newArray[i]->key > newArray[i+1]->key){
            destroy_array(newArray, length);
            return false;
        }
    }
    destroy_array(newArray, length);
    return true;
}


// static int compare_int_stable(const void *array, size_t i, size_t j)
// {
//     const Element **elements = (const Element **)array;
//     const Element *e1 = elements[i];
//     const Element *e2 = elements[j];
//     if (  *((int *)e1->value) - *((int *)e2->value) == 0){
//         return (e1->key - e2->key);
//     }
//     return ( *((int *)e1->value) - *((int *)e2->value));
// }



void stableSort(size_t algo, void *array, size_t length,
                int (*compare)(const void *, size_t i, size_t j),
                void (*swap)(void *array, size_t i, size_t j))
{

    // A modifier/compléter
    // indices = malloc(length * sizeof(int));
    // for (size_t i = 0; i < length; i++){
    //     indices[i] = i;
    // }
    void **arr = (void**)&array;
    

    Element **newArray = create_element_array(array, length);
    if (!newArray){
        return;
    }
    sort(algo, newArray, length, compare, swap);


    destroy_array(newArray, length);

}



