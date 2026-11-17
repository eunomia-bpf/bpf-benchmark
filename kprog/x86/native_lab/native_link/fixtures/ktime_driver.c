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
#include <x86intrin.h>

/* Host model of the kernel objects the ktime leaf reads, at the fixture layout in x86_ktime.rs. */
struct __attribute__((packed)) pvti { uint32_t version, pad0; uint64_t tsc_timestamp, system_time;
                                      uint32_t mul; int8_t shift; uint8_t flags; uint8_t pad[2]; };
struct tkr { void *clock; uint64_t mask, cycle_last; uint32_t mult, shift; uint64_t xtime_nsec; int64_t base;
             uint64_t base_real; };
static struct { uint32_t seq, pad; struct tkr base[2]; } tk;            /* seq 0, base 8, tk_read_base 56 bytes */
static struct { uint64_t pad, max_cycles; } kvm_clock, other_clock;     /* max_cycles at 8 */
static struct pvti pv;
static struct { int32_t preempt_count, pad; struct pvti *hv; } percpu;  /* GS: __preempt_count 0, hv_clock_per_cpu 8 */
static uint8_t valid_flags;
unsigned resched_calls;
#define SENTINEL 0x5eedf00dULL
#define NO_RESCHED ((int32_t)0x80000000)  /* PREEMPT_NEED_RESCHED is folded in inverted */

static uint64_t kernel_ktime(void) { return SENTINEL; } /* the kernel's own ktime_get_mono_fast_ns */
/* Stands in for the PREEMPT_DYNAMIC static call: it keeps every register, as preempt_schedule_notrace_thunk does. */
__attribute__((naked)) static void resched(void) { __asm__ volatile("lock incl resched_calls(%rip)\n\tret"); }

static uint64_t (*ktime)(void);

static uint64_t to_ns(const struct tkr *t, uint64_t cycles)
{
    uint64_t delta = (cycles - t->cycle_last) & t->mask;
    return (uint64_t)t->base + ((delta * t->mult + t->xtime_nsec) >> t->shift);
}

static uint64_t scale(uint64_t delta, uint32_t mul, int shift)
{
    delta = shift < 0 ? delta >> -shift : delta << shift;
    return (uint64_t)(((unsigned __int128)delta * mul) >> 32);
}

static uint64_t read_balanced(int32_t preempt)
{
    percpu.preempt_count = preempt;
    uint64_t value = ktime();
    assert(percpu.preempt_count == preempt);
    return value;
}

int main(int argc, char **argv)
{
    assert(argc == 3);
    FILE *f = fopen(argv[1], "rb"); assert(f);
    assert(!fseek(f, 0, SEEK_END)); long size = ftell(f); assert(size > 0); rewind(f);
    unsigned char *code = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_32BIT, -1, 0);
    assert(code != MAP_FAILED && fread(code, 1, size, f) == (size_t)size); assert(!fclose(f));
    for (long i = 0; i + 8 <= size; ++i) {
        uint64_t value; memcpy(&value, code + i, 8);
        uintptr_t target = value == 0x1234567800000001ULL ? (uintptr_t)&tk :
            value == 0x1234567800000002ULL ? (uintptr_t)&kvm_clock :
            value == 0x1234567800000003ULL ? (uintptr_t)&valid_flags : 0;
        if (target) memcpy(code + i, &target, 8);
    }
    f = fopen(argv[2], "r"); assert(f);
    unsigned count; assert(fscanf(f, "%u", &count) == 1 && count == 3);
    for (unsigned i = 0; i < count; ++i) {
        unsigned offset, kind;
        assert(fscanf(f, "%u %u", &offset, &kind) == 2 && code[offset] == 0xe8);
        int64_t disp = (intptr_t)(kind ? (void *)kernel_ktime : (void *)resched) - (intptr_t)(code + offset + 5);
        assert(disp == (int32_t)disp); int32_t rel = disp; memcpy(code + offset + 1, &rel, 4);
    }
    assert(!fclose(f));
    assert(!mprotect(code, size, PROT_READ|PROT_EXEC));
    ktime = (uint64_t (*)(void))code;
    uintptr_t old_gs;
    assert(!syscall(SYS_arch_prctl, ARCH_GET_GS, &old_gs));
    assert(!syscall(SYS_arch_prctl, ARCH_SET_GS, &percpu));
    percpu.hv = &pv;
    unsigned vectors = 0;

    /* Both latch copies, with mul 0 so the kvm-clock read is exactly system_time. */
    tk.base[0] = (struct tkr){&kvm_clock, ~0ULL, 100, 3, 1, 7, 1000, 0};
    tk.base[1] = (struct tkr){&kvm_clock, ~0ULL, 50, 5, 0, 0, 2000, 0};
    kvm_clock.max_cycles = ~0ULL; valid_flags = 1;
    pv = (struct pvti){.version = 2, .system_time = 1100, .mul = 0, .shift = 0, .flags = 1};
    tk.seq = 0; assert(read_balanced(NO_RESCHED) == to_ns(&tk.base[0], 1100)); ++vectors;
    tk.seq = 1; assert(read_balanced(NO_RESCHED) == to_ns(&tk.base[1], 1100)); ++vectors;
    tk.seq = 2; tk.base[0].mask = 0xff; assert(read_balanced(NO_RESCHED) == to_ns(&tk.base[0], 1100)); ++vectors;
    tk.base[0].mask = ~0ULL;
    assert(resched_calls == 0);

    /* TSC scaling, every shift sign: the value lies between the scaled TSC before and after the call. */
    tk.seq = 0; tk.base[0] = (struct tkr){&kvm_clock, ~0ULL, 0, 1, 0, 0, 0, 0};
    for (int shift = -2; shift <= 2; ++shift) {
        pv = (struct pvti){.version = 4, .tsc_timestamp = __rdtsc(), .system_time = 5,
                           .mul = 0x80000000u, .shift = (int8_t)shift, .flags = 1};
        uint64_t t0 = __rdtsc(); uint64_t value = read_balanced(NO_RESCHED); uint64_t t1 = __rdtsc();
        assert(5 + scale(t0 - pv.tsc_timestamp, pv.mul, shift) <= value);
        assert(value <= 5 + scale(t1 - pv.tsc_timestamp, pv.mul, shift)); ++vectors;
    }

    /* preempt_enable_notrace reaching zero with a reschedule pending makes the static call once per read. */
    pv = (struct pvti){.version = 2, .system_time = 1100, .mul = 0, .shift = 0, .flags = 1};
    tk.base[0] = (struct tkr){&kvm_clock, ~0ULL, 100, 3, 1, 7, 1000, 0};
    assert(read_balanced(0) == to_ns(&tk.base[0], 1100)); assert(resched_calls == 1); ++vectors;

    /* The kernel's other branches return its own ktime_get_mono_fast_ns. */
    pv.flags = 0; assert(read_balanced(NO_RESCHED) == SENTINEL); ++vectors;           /* vCPU TSC unstable */
    assert(read_balanced(0) == SENTINEL && resched_calls == 2); ++vectors;           /* bracket closes first */
    pv.flags = 1; valid_flags = 0; assert(read_balanced(NO_RESCHED) == SENTINEL); ++vectors; /* valid_flags clear */
    valid_flags = 1; kvm_clock.max_cycles = 999; assert(read_balanced(NO_RESCHED) == SENTINEL); ++vectors;
    kvm_clock.max_cycles = 1000; assert(read_balanced(NO_RESCHED) == to_ns(&tk.base[0], 1100)); ++vectors;
    tk.base[0].clock = &other_clock; assert(read_balanced(0) == SENTINEL && resched_calls == 2); ++vectors;

    assert(!syscall(SYS_arch_prctl, ARCH_SET_GS, old_gs));
    printf("ktime leaf: latch copies, pvclock scaling, preemption bracket and kernel calls, %u vectors PASS\n", vectors);
    return 0;
}
