struct Array {
    int length;
    int* elements;
};

extern void insertion(struct Array *array, int index, int element);

extern struct Array *init_array();

extern void display(struct Array *array);

extern void deletion(struct Array *array, int index);

extern int get_index(struct Array *array, int element);