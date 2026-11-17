#define _GNU_SOURCE
#include <assert.h>
#include <asm/prctl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <unistd.h>

/* Dynamic layouts catch unsafe adjacent-field fusion and displacement truncation.
 * The highest credential field ends at, or just before, an inaccessible page. */
static struct { void *current; } percpu;
static uint32_t next(uint32_t *state)
{
    *state = *state * 1664525u + 1013904223u;
    return *state;
}
int main(int argc, char **argv)
{
    assert(argc == 5);
    unsigned task_offset = strtoul(argv[2], NULL, 10);
    unsigned uid_offset = strtoul(argv[3], NULL, 10);
    unsigned gid_offset = strtoul(argv[4], NULL, 10);
    size_t extent = (uid_offset > gid_offset ? uid_offset : gid_offset) + 4u;
    assert(extent + 7 <= 4096); /* Test inputs, not a production layout limit. */
    FILE *f = fopen(argv[1], "rb"); assert(f);
    assert(!fseek(f, 0, SEEK_END)); long size = ftell(f); assert(size > 0); rewind(f);
    unsigned char *code = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_32BIT, -1, 0);
    assert(code != MAP_FAILED && fread(code, 1, size, f) == (size_t)size); assert(!fclose(f));
    assert(!mprotect(code, size, PROT_READ|PROT_EXEC));
    uint64_t (*uid_gid)(void) = (uint64_t (*)(void))code;
    unsigned char *task = calloc((size_t)task_offset + sizeof(void *), 1); assert(task);
    unsigned char *pages = mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    assert(pages != MAP_FAILED && !mprotect(pages + 4096, 4096, PROT_NONE));
    uintptr_t old_gs;
    assert(!syscall(SYS_arch_prctl, ARCH_GET_GS, &old_gs));
    assert(!syscall(SYS_arch_prctl, ARCH_SET_GS, &percpu));
    unsigned vectors = 0;
    uint32_t state = 0x9145abcd;
    static const uint32_t ids[][2] = {{0,0},{1000,2000},{0xfffffffeu,1},{0xffffffffu,0xffffffffu},{7,0xfffffffeu}};
    static const unsigned slacks[] = {0,1,3,7};
    for (unsigned a = 0; a < sizeof(slacks)/sizeof(slacks[0]); ++a) {
        unsigned char *cred = pages + 4096 - extent - slacks[a];
        memcpy(task + task_offset, &cred, sizeof(cred)); percpu.current = task;
        for (unsigned i = 0; i < 133; ++i) {
            uint32_t uid = i < 5 ? ids[i][0] : next(&state);
            uint32_t gid = i < 5 ? ids[i][1] : next(&state);
            assert(!mprotect(pages, 4096, PROT_READ|PROT_WRITE));
            memset(pages, 0xa5, 4096);
            memcpy(cred + uid_offset, &uid, sizeof(uid));
            memcpy(cred + gid_offset, &gid, sizeof(gid));
            assert(!mprotect(pages, 4096, PROT_READ));
            assert(uid_gid() == ((uint64_t)gid << 32 | uid)); ++vectors;
        }
    }
    percpu.current = NULL; assert(uid_gid() == (uint64_t)-22); ++vectors;
    assert(!syscall(SYS_arch_prctl, ARCH_SET_GS, old_gs));
    assert(!munmap(pages, 8192) && !munmap(code, size)); free(task);
    printf("uid_gid leaf: read-only/guard/unaligned/live IDs/NULL current, %u vectors PASS\n", vectors);
    return 0;
}
