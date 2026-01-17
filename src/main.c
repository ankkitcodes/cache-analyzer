#include "analyzer.h"
#include <stdio.h>

int main(void) {
    printf("Cache Analyzer Started\n");

    size_t test_sizes[] = {
        1024,
        8 * 1024,
        64 * 1024,
        512 * 1024,
        1024 * 1024
    };

    for (int i = 0; i < sizeof(test_sizes) / sizeof(test_sizes[0]); i++) {
        run_sequential_test(test_sizes[i]);
        run_random_test(test_sizes[i]);
    }

    printf("Results written to results/results.csv\n");
    return 0;
}
