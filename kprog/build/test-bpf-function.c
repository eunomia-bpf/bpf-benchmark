#include <stdint.h>
#include <stdlib.h>
extern unsigned long supplied64(unsigned long, unsigned long);
extern unsigned long supplied32(unsigned long);
extern int supplied_i32(void *);
extern unsigned short supplied16(void *);
extern void *supplied_ptr(void *);
extern void supplied_void(void *);
static unsigned long (*volatile call64)(unsigned long, unsigned long) = supplied64;
static unsigned long (*volatile call32)(unsigned long) = supplied32;
static int (*volatile call_i32)(void *) = supplied_i32;
static unsigned short (*volatile call16)(void *) = supplied16;
static void *(*volatile call_ptr)(void *) = supplied_ptr;
static void (*volatile call_void)(void *) = supplied_void;
int main(int argc, char **argv)
{
    if (argc != 3) return 2;
    uint64_t expected64 = strtoull(argv[1], 0, 0);
    uint64_t expected32 = strtoull(argv[2], 0, 0);
    for (unsigned long i = 0; i < 48; ++i) {
        if (call64(i, ~i) != expected64 || call32(i) != expected32 ||
            call_i32(&i) != (int)expected32 || call16(&i) != (uint16_t)expected32 ||
            (uintptr_t)call_ptr(&i) != expected64) return 1;
        call_void(&i);
    }
    return 0;
}
