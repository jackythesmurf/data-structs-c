#include "headers/array.h"
#include "stdio.h"
#include "stdlib.h"
/*
Array operations
- insertion
- deletion
- display
- get element at index
*/

struct Array* init_array(){
    struct Array* array = malloc(sizeof(struct Array));
    array->elements = calloc(1, sizeof(int));
    array->length = 0;
    return array;
}

int handle_array_errors(struct Array *array, int index) {
  if (index < 0) {
    printf("Error: index is less than 0\n");
    return 1;
  }
  if (index > array->length) {
    printf("Error: index is out of bounds\n");
    return 1;
  }
  if (array == NULL) {
    printf("Error: invalid array");
    return 1;
  }
  return 0;
}

// insert at location in array, keeps the same elements
void insertion(struct Array* array, int index, int element) {
    if (handle_array_errors(array, index) == 1) {
        return;
    }
    array->length++;
    array->elements = realloc(array->elements, sizeof(int) * (array->length + 1));

    for (int i = array->length - 1; i > index; i--) {
      array->elements[i] = array->elements[i - 1];
    }

    array->elements[index] = element;
}

void deletion(struct Array* array, int index) {
  if (handle_array_errors(array, index + 1) == 1) {
    return;
  }

    for (int i = 0; i < array->length -1; i++)
    {
        if (i == index) {
            for (int j = i; j < array->length-1; j++) {
              array->elements[j] = array->elements[j + 1];
            }
        }
    }
    
  array->elements = realloc(array->elements, sizeof(int) * (array->length - 1));
  array->length--;

}

int get_index(struct Array* array, int element) {
  for (int i = 0; i < array->length - 1; i++) {
    if (array->elements[i] == element) {
        return i;
    }
  }
  return -1;
}

void display(struct Array* array) {
  printf("[ ");
  if (array->length == 0) {
    printf("]\n");
    return;
  }
  for (int i = 0; i < array->length - 1; i++) {
    printf("%d, ", array->elements[i]);
    }
    printf("%d ]\n", array->elements[array->length - 1]);
}