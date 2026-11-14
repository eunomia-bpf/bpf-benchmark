#define _GNU_SOURCE
#include <assert.h>
#include <asm/prctl.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <ucontext.h>
#include <unistd.h>

static struct { int unused, disabled; } task;
static uintptr_t user_max = UINTPTR_MAX;
static uint32_t capabilities[10]; /* SMAP deliberately off in user-mode test. */
static unsigned char *code;
static unsigned sites[2], lengths[2];
static unsigned faults, denied, callbacks;
static const void *expected_src;
static unsigned expected_size;
static int user;

static int policy(const void *src, unsigned size)
{
    assert(task.disabled == 7); /* Policy failure must precede pagefault_disable. */
    if (!user) { assert(src == expected_src); assert(size == expected_size); }
    ++callbacks;
    return !denied;
}

static void fault(int sig, siginfo_t *info, void *context)
{
    (void)sig; (void)info;
    ucontext_t *uc = context;
    uintptr_t ip = uc->uc_mcontext.gregs[REG_RIP];
    for (unsigned i = 0; i < 2; ++i) {
        if (ip != (uintptr_t)code + sites[i]) continue;
        assert(task.disabled == 8);
        ++faults;
        /* Exactly the existing kernel EX_TYPE_BPF action selected by metadata. */
        uc->uc_mcontext.gregs[REG_R11] = 0;
        uc->uc_mcontext.gregs[REG_RIP] += lengths[i];
        return;
    }
    _exit(99); /* Unregistered faults must not masquerade as helper recovery. */
}

static void check(void *dst, const void *src, unsigned n, long expected)
{
    unsigned char *d = dst;
    memset(d-1, 0xa5, n+2);
    expected_src = src; expected_size = n;
    long result = ((long (*)(void *,unsigned,const void *))code)(dst,n,src);
    assert(result == expected);
    assert(task.disabled == 7);
    assert(d[-1] == 0xa5 && d[n] == 0xa5);
    if (!expected) assert(!memcmp(dst,src,n));
    else for (unsigned i=0; i<n; ++i) assert(d[i] == 0);
}

int main(int argc, char **argv)
{
    assert(argc == 4);
    user = atoi(argv[3]);
    FILE *f = fopen(argv[1],"rb"); assert(f);
    assert(!fseek(f,0,SEEK_END)); long size = ftell(f); assert(size > 0);
    rewind(f);
    code = mmap(NULL,size,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_32BIT,-1,0);
    assert(code != MAP_FAILED && fread(code,1,size,f) == (size_t)size); assert(!fclose(f));
    /* Host fixture literals only; no historical guest address is executed. */
    for (long i=0; i+8<=size; ++i) {
        uint64_t value; memcpy(&value,code+i,8);
        uintptr_t target = value == 0x1111222233334444ULL ? (uintptr_t)&user_max :
            value == 0x5555666677778888ULL ? (uintptr_t)&capabilities : 0;
        if (target) memcpy(code+i,&target,8);
    }
    f = fopen(argv[2],"r"); assert(f);
    for (unsigned i=0; i<2; ++i) {
        unsigned destination;
        assert(fscanf(f,"%u %u %u",sites+i,lengths+i,&destination) == 3);
        assert(destination == 11 && lengths[i] == 3);
    }
    unsigned call;
    assert(fscanf(f,"%u",&call) == 1 && code[call] == 0xe8);
    int64_t disp = (intptr_t)policy - (intptr_t)(code+call+5);
    assert(disp == (int32_t)disp); int32_t rel = disp;
    memcpy(code+call+1,&rel,4); assert(!fclose(f));
    assert(!mprotect(code,size,PROT_READ|PROT_EXEC));
    struct sigaction sa = {.sa_sigaction=fault,.sa_flags=SA_SIGINFO};
    assert(!sigemptyset(&sa.sa_mask)); assert(!sigaction(SIGSEGV,&sa,NULL));
    uintptr_t old_gs, current = (uintptr_t)&task;
    assert(!syscall(SYS_arch_prctl,ARCH_GET_GS,&old_gs));
    assert(!syscall(SYS_arch_prctl,ARCH_SET_GS,&current));
    task.disabled = 7;
    unsigned char *src = mmap(NULL,8192,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    assert(src != MAP_FAILED); for (unsigned i=0;i<4096;++i) src[i]=(i*17)^0x5a;
    assert(!mprotect(src+4096,4096,PROT_NONE));
    unsigned char dest[1026]; unsigned vectors = 0;
    for (unsigned n=0;n<=1024;++n) { check(dest+1,src+4096-n,n,0); ++vectors; }
    for (unsigned n=1;n<=65;++n) {
        check(dest+1,src+4096,n,-14); ++vectors;
        if (n>9) { check(dest+1,src+4087,n,-14); ++vectors; }
    }
    denied=1; check(dest+1,src,33,user ? -14 : -34); ++vectors; denied=0;
    if (user) {
        unsigned before = callbacks;
        user_max=(uintptr_t)src+16;
        check(dest+1,src,17,-14); ++vectors;
        check(dest+1,(void *)(UINTPTR_MAX-3),8,-14); ++vectors;
        assert(callbacks == before); /* Invalid range never invokes NMI check. */
    }
    assert(!syscall(SYS_arch_prctl,ARCH_SET_GS,old_gs));
    printf("probe-read host user=%d: %u vectors, %u exact-site faults, nesting/zero/error/bounds PASS\n",user,vectors,faults);
    return 0;
}
