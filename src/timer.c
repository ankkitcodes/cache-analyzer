#include "analyzer.h"

#ifdef _MSC_VER
#include <intrin.h>
#pragma intrinsic(__rdtsc)
uint64_t read_timer(void) {
    return __rdtsc();
}
#else
#include <x86intrin.h>
uint64_t read_timer(void) {
    return __rdtsc();
}
#endif
