/* Host execution of the exact CompCert-only adapter body. The test supplies
 * this builtin with libc memcpy and records its single full-window call. */
#ifndef KPROG_COMPCERT_MEMORY_HOST_H
#define KPROG_COMPCERT_MEMORY_HOST_H
#include <stddef.h>
void __builtin_memcpy_aligned(void *, const void *, size_t, size_t);
#endif
