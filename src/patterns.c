#include "analyzer.h"
#include <stdlib.h>
#include <time.h>

void generate_sequential(int *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = (int)i;
    }
}

void generate_random(int *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = (int)i;
    }

    srand((unsigned int)time(NULL));
    for (size_t i = size - 1; i > 0; i--) {
        size_t j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
