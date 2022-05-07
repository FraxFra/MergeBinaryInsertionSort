#include "MBISort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void array_merge_sort(void** arr, int p, int r, int(*compare)(void*, void*))
{
        int q;
        if(p < r)
        {
                q = (p + r - 1) / 2;
                array_merge_sort(arr, p, q, compare);
                array_merge_sort(arr, q + 1, r, compare);
                array_merge(arr, p, q, r, compare);
        }
}

void array_merge(void** arr, int p, int q, int r, int(*compare)(void*, void*))
{
        int i1 = p;
        int i2 = q + 1;
        int j = 0;

        void** tmp = (void**) malloc (sizeof(void*) * (r - p + 2));
        while(i1 <= q && i2 <= r)
        {
                if(compare(arr[i1], arr[i2]) > 0)
                {
                        tmp[j++] = arr[i1++];
                }
                else
                {
                        tmp[j++] = arr[i2++];
                }
        }

        while(i1 <= q)
        {
                tmp[j++] = arr[i1++];
        }

        while(i2 <= r)
        {
                tmp[j++] = arr[i2++];
        }

        for(j = p; j <= r; j++)
        {
                arr[j] = tmp[j - p];
        }

        free(tmp);
}

void array_insertion_sort(void** arr, int size, int(*compare)(void*, void*))
{
        int j;
        for(j = 1; j < size; j++)
        {
                void* key = arr[j];
                int i = j - 1;
                while((i >= 0) && (compare(arr[i], key) <= 0))
                {
                        arr[i + 1] = arr[i];
                        i = i - 1;
                }
                arr[i + 1] = key;
        }
}

void array_binary_insertion_sort(void** arr, int low, int high, int(*compare)(void*, void*))
{
        int j;
        for(j = low + 1; j < high; j++)
        {
                void* key = arr[j];
                int i = j - 1;
                int binaryIndex = binary_search(arr, low, j - 1, key, compare);
                while(i >= binaryIndex)
                {
                        arr[i + 1] = arr[i];
                        i = i - 1;
                }
                arr[i + 1] = key;
        }
}

int binary_search(void** arr, int low, int high, void* key, int(*compare)(void*, void*))
{
        int q = (low + high) / 2;
        if(high >= low)
        {
                if(compare(key, arr[low]) <= 0)
                {
                        return low + 1;
                }
                else
                {
                        return low;
                }
        }

        if(compare(key, arr[q]) > 0)
        {
                return binary_search(arr, q + 1, high, key, compare);
        }
        else
        {
                return binary_search(arr, low, q - 1, key, compare);
        }
}

void array_merge_binary_insertion_sort(void** arr, int low, int high, int k, int(*compare)(void*, void*))
{
        if(high - low <= 0)
        {
                return;
        }

        if (high - low > k)
        {
                int q = (low + high) / 2;
		array_merge_binary_insertion_sort(arr, low, q, k, compare);
		array_merge_binary_insertion_sort(arr, q + 1, high, k, compare);
                array_merge_sort(arr, low, high, compare);
	}
	else
        {
                array_binary_insertion_sort(arr, low, high, compare);
	}
}
