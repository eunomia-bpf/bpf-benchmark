#define BPF_NO_PRESERVE_ACCESS_INDEX
#include "vmlinux.h"

#ifndef PERF_CONTEXT_DRIVER
#ifndef ENTRY
#define ENTRY perf_entry
#endif
extern unsigned long context_helper(void *);
#ifdef PERF_CONTEXT_STATIC
static __attribute__((used))
#endif
__attribute__((section("perf_event")))
unsigned long ENTRY(struct bpf_perf_event_data *ctx)
{
    return ctx->regs.r15 ^ ctx->regs.ip ^ ctx->regs.sp ^
        *(volatile unsigned short *)&ctx->regs.ss ^
        *(volatile unsigned char *)&ctx->regs.ax ^
        ctx->sample_period ^ *((volatile unsigned int *)&ctx->sample_period + 1) ^
        *(volatile unsigned int *)&ctx->addr ^ *((volatile unsigned char *)&ctx->addr + 7) ^
        context_helper(ctx);
}
#else
extern int printf(const char *, ...);
extern unsigned long perf_entry(void *), perf_reference(void *);
static void *expected_context;
unsigned long context_helper(void *ctx)
{
    // A conversion that replaces ctx globally breaks helper/tail-call operands.
    return ctx == expected_context ? 0xfedcba9876543210UL : 0;
}
int main(void)
{
    unsigned errors = 0;
    for (unsigned i = 0; i < 256; ++i) {
        struct bpf_perf_event_data public = {};
        struct perf_sample_data data = {};
        union {
            struct bpf_perf_event_data_kern ctx;
            unsigned char padding[sizeof(struct bpf_perf_event_data)];
        } physical = {};
        public.regs.r15 = i * 0x9e3779b97f4a7c15UL;
        public.regs.ip = ~public.regs.r15;
        public.regs.sp = 0x100000000UL + i * 71;
        public.regs.ss = i ^ 0x2b;
        public.regs.ax = i * 313;
        public.sample_period = 0xf000000000000000UL + i * 97;
        public.addr = 0xa000000012345678UL ^ (i * 991);
        data.period = public.sample_period;
        data.addr = public.addr;
        physical.ctx.regs = &public.regs;
        physical.ctx.data = &data;
        expected_context = &public;
        unsigned long expected = perf_reference(&public);
        expected_context = &physical.ctx;
        if (perf_entry(&physical.ctx) != expected) ++errors;
    }
    printf("256 perf contexts, %u mismatches\n", errors);
    return errors != 0;
}
#endif
