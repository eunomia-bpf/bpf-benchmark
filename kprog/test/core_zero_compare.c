// Changing this field from u16 to the kernel's u64 must preserve the actual
// BPF comparison-register width, including high32-only nonzero inputs.
struct task_struct___zero_compare {
    unsigned long flags;
    unsigned short start_boottime;
} __attribute__((preserve_access_index));
#ifndef COMPARE_NE
#define COMPARE_NE 0
#endif
#ifndef COMPARE_NONZERO
#define COMPARE_NONZERO 0
#endif
__attribute__((section("test"))) int wide_compare(void *ctx)
{
    struct task_struct___zero_compare *task=ctx;
    return COMPARE_NE ? task->start_boottime != COMPARE_NONZERO :
                        task->start_boottime == COMPARE_NONZERO;
}
