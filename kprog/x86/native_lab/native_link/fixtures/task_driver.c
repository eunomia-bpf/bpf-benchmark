#define _GNU_SOURCE
#include <assert.h>
#include <asm/prctl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <unistd.h>

/* Host model at the fixture layout in x86_task.rs: GS current_task 0, task->cred 16, cred->uid 8, cred->gid 12. */
static struct { uint32_t pad[2], uid, gid; } cred;
static struct { char pad[16]; void *cred; } task;
static struct { void *current; } percpu;

int main(int argc, char **argv)
{
    assert(argc == 2);
    FILE *f = fopen(argv[1], "rb"); assert(f);
    assert(!fseek(f, 0, SEEK_END)); long size = ftell(f); assert(size > 0); rewind(f);
    unsigned char *code = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_32BIT, -1, 0);
    assert(code != MAP_FAILED && fread(code, 1, size, f) == (size_t)size); assert(!fclose(f));
    assert(!mprotect(code, size, PROT_READ|PROT_EXEC));
    uint64_t (*uid_gid)(void) = (uint64_t (*)(void))code;
    uintptr_t old_gs;
    assert(!syscall(SYS_arch_prctl, ARCH_GET_GS, &old_gs));
    assert(!syscall(SYS_arch_prctl, ARCH_SET_GS, &percpu));
    unsigned vectors = 0;
    task.cred = &cred; percpu.current = &task;
    static const uint32_t ids[][2] = {{0, 0}, {1000, 2000}, {0xfffffffeu, 1}, {0xffffffffu, 0xffffffffu}, {7, 0xfffffffeu}};
    for (unsigned i = 0; i < sizeof(ids) / sizeof(ids[0]); ++i) {
        cred.uid = ids[i][0]; cred.gid = ids[i][1];
        assert(uid_gid() == ((uint64_t)cred.gid << 32 | cred.uid)); ++vectors;
    }
    percpu.current = NULL; assert(uid_gid() == (uint64_t)-22); ++vectors; /* -EINVAL */
    assert(!syscall(SYS_arch_prctl, ARCH_SET_GS, old_gs));
    printf("uid_gid leaf: current->cred ids and NULL current, %u vectors PASS\n", vectors);
    return 0;
}
