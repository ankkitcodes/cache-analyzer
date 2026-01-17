#ifndef ANALYZER_H
#define ANALYZER_H

#include <stddef.h>
#include <stdint.h>

/* Timer */
uint64_t read_timer(void);

/* Memory tests */
void run_sequential_test(size_t size);
void run_random_test(size_t size);

/* Patterns */
void generate_sequential(int *arr, size_t size);
void generate_random(int *arr, size_t size);

#endif
