/* Clight extraction keeps section attributes without libbpf's pragmas. */
#include "Platform.h"
#include <bpf_helpers.h>
#undef SEC
#define SEC(NAME) __attribute__((section(NAME), used))
