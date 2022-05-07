#include "MBISort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int compare_int(void* e1, void* e2)
{
        if(e1 < e2)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

int compare_float(void* e1, void* e2)
{
        if(atof(e1) < atof(e2))
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

int compare_string(void* e1, void* e2)
{
        char *chare1 = (char*)e1;
        char *chare2 = (char*)e2;
        if(strcmp(chare1, chare2) < 0)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

int** load_array_int(int** arr)
{
        arr[0] = (int*) malloc(sizeof(int));
        arr[0] = (int*)9;
        arr[1] = (int*) malloc(sizeof(int));
        arr[1] = (int*)8;
        arr[2] = (int*) malloc(sizeof(int));
        arr[2] = (int*)7;
        arr[3] = (int*) malloc(sizeof(int));
        arr[3] = (int*)6;
        arr[4] = (int*) malloc(sizeof(int));
        arr[4] = (int*)5;
        arr[5] = (int*) malloc(sizeof(int));
        arr[5] = (int*)4;
        arr[6] = (int*) malloc(sizeof(int));
        arr[6] = (int*)3;
        arr[7] = (int*) malloc(sizeof(int));
        arr[7] = (int*)2;
        arr[8] = (int*) malloc(sizeof(int));
        arr[8] = (int*)1;
        arr[9] = (int*) malloc(sizeof(int));
        arr[9] = (int*)0;
        return arr;
}

int** create_array_int(int capacity)
{
        int **arr = (int**) malloc(sizeof(int*) * 10);
        return load_array_int(arr);
}

void array_free_memory(int** arr)
{
        if (arr == NULL)
        {
                fprintf(stderr, "ordered_array_free_memory: ordered array is NULL!");
                exit(EXIT_FAILURE);
        }
        free(arr);
}

void toString_int(void** arr, int size)
{
        int i = 0;
        while(i < size)
        {
                printf("index %d: %d\n", i, arr[i]);
                i++;
        }
        printf("\n");
}

int main(int argc, char const *argv[])
{
        printf("--- Merge Sort! ---\n");
        int** array = create_array_int(10);
        printf("Array created!\n");
        toString_int((void**)array, 10);
        array_merge_sort((void**)array, 0, 9, &compare_int);
        toString_int((void**)array, 10);
        array_free_memory(array);

        printf("--- Insertion Sort! ---\n");
        array = create_array_int(10);
        printf("Array created!\n");
        array_insertion_sort((void**)array, 10, &compare_int);
        toString_int((void**)array, 10);
        array_free_memory(array);

        printf("--- Binary Inserion Sort! ---\n");
        array = create_array_int(10);
        printf("Array created!\n");
        array_binary_insertion_sort((void**)array, 0, 10, &compare_int);
        toString_int((void**)array, 10);
        array_free_memory(array);

        printf("--- Merge Binary Inserion Sort! ---\n");
        array = create_array_int(10);
        printf("Array created!\n");
        array_merge_binary_insertion_sort((void**)array, 0, 9, 3, &compare_int);
        toString_int((void**)array, 10);
        array_free_memory(array);
}
