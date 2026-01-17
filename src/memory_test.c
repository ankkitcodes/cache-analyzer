#include "analyzer.h"
#include <stdio.h>
#include <stdlib.h>

#define ITERATIONS 1000000

static void write_result(const char *pattern, size_t size, uint64_t cycles) {
    FILE *f = fopen("results/results.csv", "a");
    if (!f) return;

    fprintf(f, "%s,%zu,%llu\n", pattern, size, (unsigned long long)cycles);
    fclose(f);
}

void run_sequential_test(size_t size) {
    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr) return;

    generate_sequential(arr, size);

    volatile int sum = 0;
    uint64_t start = read_timer();

    for (size_t i = 0; i < ITERATIONS; i++) {
        sum += arr[i % size];
    }

    uint64_t end = read_timer();
    write_result("sequential", size, end - start);

    free(arr);
}

void run_random_test(size_t size) {
    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr) return;

    generate_random(arr, size);

    volatile int sum = 0;
    uint64_t start = read_timer();

    for (size_t i = 0; i < ITERATIONS; i++) {
        sum += arr[rand() % size];
    }

    uint64_t end = read_timer();
    write_result("random", size, end - start);

    free(arr);
}
