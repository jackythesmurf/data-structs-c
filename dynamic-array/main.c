#include "headers/array.h"
#include "stdio.h"
#include "stdlib.h"
int main()
{
    struct Array* array = init_array();

    /*
    Insert elements into array
    */
    insertion(array, 0, 9);
    insertion(array, 1, 8);
    insertion(array, 2, 7);
    insertion(array, 0, 6);
    printf("Inserting elements in array . . . \n");
    display(array);

    /*
    Remove elements from array
    */
    deletion(array, 3);
    printf("Inserting element at 3rd index . . . \n");
    display(array);

    int index_of_element = get_index(array, 9);
    printf("Return index of element in array \n");
    printf("%d\n", index_of_element);

    

    free(array->elements);    
    free(array);
    return 0;
}
