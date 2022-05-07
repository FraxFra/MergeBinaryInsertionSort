/* Library */
extern void array_merge_sort(void** arr, int p, int r, int(*compare)(void*, void*));
extern void array_merge(void** arr, int p, int q, int r, int(*compare)(void*, void*));
extern void array_insertion_sort(void** arr, int size, int(*compare)(void*, void*));
extern void array_binary_insertion_sort(void** arr, int low, int high, int(*compare)(void*, void*));
extern int binary_search(void** arr, int low, int high, void* key, int(*compare)(void*, void*));
extern void array_merge_binary_insertion_sort(void** arr, int low, int high, int k, int(*compare)(void*, void*));
