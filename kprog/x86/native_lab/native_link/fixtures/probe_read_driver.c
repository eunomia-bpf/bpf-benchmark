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

static struct { int unused, disabled; uintptr_t mm; } task; /* fixture pagefault_disabled=4, task_mm=8 */
static struct { uintptr_t current, loaded_mm; } percpu; /* GS: current_task=0, cpu_tlbstate.loaded_mm=8 */
static uintptr_t user_max = UINTPTR_MAX;
/* boot_cpu_data: x86_capability words from 0 (SMAP stays off: STAC faults in user mode), x86_virt_bits at 40. */
static uint32_t cpu[11];
static unsigned char *code;
static unsigned sites[4], lengths[4], site_count;
static unsigned faults;

static void virt_bits(unsigned bits) { ((unsigned char *)cpu)[40] = bits; }

static void fault(int sig, siginfo_t *info, void *context)
{
    (void)sig; (void)info;
    ucontext_t *uc = context;
    uintptr_t ip = uc->uc_mcontext.gregs[REG_RIP];
    for (unsigned i = 0; i < site_count; ++i) {
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
    long result = ((long (*)(void *,unsigned,const void *))code)(dst,n,src);
    assert(result == expected);
    assert(task.disabled == 7); /* Denial precedes pagefault_disable; every entered path leaves it. */
    assert(d[-1] == 0xa5 && d[n] == 0xa5);
    if (!expected) assert(!memcmp(dst,src,n));
    else for (unsigned i=0; i<n; ++i) assert(d[i] == 0);
}

static void check_string(void *dst, const void *src, unsigned n, long expected)
{
    unsigned char *d = dst;
    memset(d-1,0xa5,n+2);
    long result=((long (*)(void *,unsigned,const void *))code)(dst,n,src);
    assert(result==expected && task.disabled==7);
    assert(d[-1]==0xa5 && d[n]==0xa5);
    if (expected>0) {
        assert(!memcmp(d,src,expected-1) && d[expected-1]==0);
        for (unsigned i=expected;i<n;++i) assert(d[i]==0xa5);
    } else if (expected<0) for (unsigned i=0;i<n;++i) assert(d[i]==0);
}

int main(int argc, char **argv)
{
    assert(argc == 4);
    int mode = atoi(argv[3]);
    int user = mode == 1;
    FILE *f = fopen(argv[1],"rb"); assert(f);
    assert(!fseek(f,0,SEEK_END)); long size = ftell(f); assert(size > 0);
    rewind(f);
    code = mmap(NULL,size,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_32BIT,-1,0);
    assert(code != MAP_FAILED && fread(code,1,size,f) == (size_t)size); assert(!fclose(f));
    /* Host fixture literals only; no historical guest address is executed. */
    for (long i=0; i+8<=size; ++i) {
        uint64_t value; memcpy(&value,code+i,8);
        uintptr_t target = value == 0x1111222233334444ULL ? (uintptr_t)&user_max :
            value == 0x5555666677778888ULL ? (uintptr_t)cpu : 0;
        if (target) memcpy(code+i,&target,8);
    }
    if (mode >= 3) {
        struct { uintptr_t current; unsigned cpu, pad; uintptr_t offset; } gs =
            {0x123456789abcdef0ULL, 123, 0, 0};
        gs.offset = (uintptr_t)&gs;
        uintptr_t old_gs;
        assert(!mprotect(code,size,PROT_READ|PROT_EXEC));
        assert(!syscall(SYS_arch_prctl,ARCH_GET_GS,&old_gs));
        assert(!syscall(SYS_arch_prctl,ARCH_SET_GS,&gs));
        uint64_t value = ((uint64_t (*)(void))code)();
        assert(!syscall(SYS_arch_prctl,ARCH_SET_GS,old_gs));
        assert(value == (mode == 3 ? gs.current : gs.cpu));
        puts("percpu emitted load: full-width task and zero-extended CPU PASS");
        return 0;
    }
    f = fopen(argv[2],"r"); assert(f);
    assert(fscanf(f,"%u",&site_count) == 1 && site_count > 0 && site_count <= 4);
    for (unsigned i=0; i<site_count; ++i) {
        unsigned destination;
        assert(fscanf(f,"%u %u %u",sites+i,lengths+i,&destination) == 3);
        assert(destination == 11 && (lengths[i] == 2 || lengths[i] == 3));
    }
    assert(!fclose(f)); /* Both reads are leaves: their policy reads are inline, with no call to patch. */
    assert(!mprotect(code,size,PROT_READ|PROT_EXEC));
    struct sigaction sa = {.sa_sigaction=fault,.sa_flags=SA_SIGINFO};
    assert(!sigemptyset(&sa.sa_mask)); assert(!sigaction(SIGSEGV,&sa,NULL));
    uintptr_t old_gs;
    percpu.current = (uintptr_t)&task;
    task.mm = percpu.loaded_mm = 0x1000;
    assert(!syscall(SYS_arch_prctl,ARCH_GET_GS,&old_gs));
    assert(!syscall(SYS_arch_prctl,ARCH_SET_GS,&percpu));
    task.disabled = 7;
    unsigned char *src = mmap(NULL,8192,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    assert(src != MAP_FAILED); for (unsigned i=0;i<4096;++i) src[i]=(i*17)^0x5a;
    assert(!mprotect(src+4096,4096,PROT_NONE));
    assert((uintptr_t)src >> 40); /* A 40-bit width makes this host address non-canonical. */
    if (!user) { user_max = 0; virt_bits(48); } /* Kernel reads: threshold USER_PTR_MAX + PAGE_SIZE = 4096. */
    unsigned char dest[1026]; unsigned vectors = 0;
    if (mode == 2) {
        check_string(dest+1,src+4096,0,0); ++vectors; /* zero count returns 0 ahead of the policy */
        memset(src,'x',4096);
        for (unsigned n=1;n<=65;++n) {
            check_string(dest+1,src+4096-n,n,n); ++vectors;
            check_string(dest+1,src+4096,n,-14); ++vectors;
            if (n>9) {check_string(dest+1,src+4087,n,-14); ++vectors;}
        }
        src[4095]=0;check_string(dest+1,src+4088,65,8); ++vectors;
        src[0]=0;check_string(dest+1,src,65,1); ++vectors;
        user_max=(uintptr_t)src-4095; check_string(dest+1,src,33,-34); ++vectors; user_max=0; /* last denied address */
        virt_bits(40); check_string(dest+1,src,33,-34); ++vectors; virt_bits(48);
        check_string(dest+1,(void *)0xffffffffff600123ULL,8,-34); ++vectors;
        check_string(dest+1,(void *)0xffffffffff600123ULL,0,0); ++vectors;
        puts("kernel string: NUL/truncation/zero-count/policy/partial-fault/full-zero PASS");
    } else {
    for (unsigned n=0;n<=1024;++n) { check(dest+1,src+4096-n,n,0); ++vectors; }
    for (unsigned n=1;n<=65;++n) {
        check(dest+1,src+4096,n,-14); ++vectors;
        if (n>9) { check(dest+1,src+4087,n,-14); ++vectors; }
    }
    if (user) {
        percpu.loaded_mm = task.mm + 0x1000; /* nmi_uaccess_okay false */
        check(dest+1,src,33,-14); ++vectors; percpu.loaded_mm = task.mm;
        user_max=(uintptr_t)src+16;
        check(dest+1,src,17,-14); ++vectors;
        check(dest+1,(void *)(UINTPTR_MAX-3),8,-14); ++vectors;
    } else {
        user_max=(uintptr_t)src-4095; check(dest+1,src,33,-34); ++vectors; /* last address below TASK_SIZE_MAX + PAGE_SIZE */
        user_max=(uintptr_t)src-4096; check(dest+1,src,16,0); ++vectors; user_max=0; /* first allowed address */
        virt_bits(40); check(dest+1,src,33,-34); ++vectors; /* non-canonical at the boot width */
        virt_bits(0); check(dest+1,src+4096-16,16,0); ++vectors; virt_bits(48); /* width zero allows */
        check(dest+1,(void *)0xffffffffff600123ULL,8,-34); ++vectors; /* vsyscall page */
        check(dest+1,(void *)0xffffffffff5ffff8ULL,8,-14); ++vectors; /* page below it: policy allows, load faults */
    }
    }
    assert(!syscall(SYS_arch_prctl,ARCH_SET_GS,old_gs));
    printf("probe-read host user=%d: %u vectors, %u exact-site faults, nesting/zero/error/bounds PASS\n",user,vectors,faults);
    return 0;
}
