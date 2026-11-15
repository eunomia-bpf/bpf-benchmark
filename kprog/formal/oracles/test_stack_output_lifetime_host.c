/* Current output-call lifetime: exact pointers, live bytes/facts, released
 * bytes from explicit inputs. No retired below-SP fault guard is modeled. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef TEST_ARM64
#define ARM64_SIM_ENABLE_STACK 1
#include "kprog/arm64/arm64_sim_local_bpf.h"
#undef ARM64_SIM_L_UNSPECIFIED
#define ARM64_SIM_L_UNSPECIFIED() NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_UNSPECIFIED)
#define ENTRY() ARM64_SIM_ENTRY_RAW((void *)0)
#define CAPACITY ARM64_SIM_STACK_BYTES
#define BIAS ARM64_SIM_STACK_BIAS
#define ARENA __a64_stack.b
#define PREPARE(OFF, LEN) do { __a64_sp=-32; __a64_x0.ptr=(void *)(long)(OFF); __a64_x0_tag=ARM64_SIM_TAG_STACK; __a64_x1.x=7; __a64_x1_tag=ARM64_SIM_TAG_SCALAR; __a64_x2.x=(LEN); __a64_x2_tag=ARM64_SIM_TAG_SCALAR; } while(0)
#define PTR() ARM64_SIM_L_HELPER_ARG_PTR(ARM64_X0)
#define FILL() ARM64_SIM_LIBC_MEMSET()
#define COPY() do { __a64_x1.ptr=(void *)-16L; __a64_x1_tag=ARM64_SIM_TAG_STACK; ARM64_SIM_LIBC_MEMCPY(); } while(0)
#define HELPER(LEN) do { __a64_x1.x=(LEN); ARM64_SIM_BPF_CALL_bpf_get_current_comm(); } while(0)
#define RESULT_BITS() __a64_x0.x
#define RESULT_TAG() __a64_x0_tag
#define LIBC_RESULT(OFF) ((__u64)(__s64)(OFF))
#define STACK_TAG ARM64_SIM_TAG_STACK
#define SCALAR_TAG ARM64_SIM_TAG_SCALAR
#define FACT_TAG ARM64_SIM_TAG_MAP_VALUE
#define SET_FACT(I, T) ARM64_SIM_L_TAG_SET((I), (T))
#define GET_FACT(I) ARM64_SIM_L_TAG_GET(I)
#define READ_BYTE(OFF) ARM64_SIM_L_STACK_READ((OFF), ARM64_WIDTH_8)
#else
#define X86_SIM_ENABLE_STACK 1
#include "kprog/x86/x86_sim_local_bpf.h"
#undef X86_SIM_L_UNSPECIFIED
#define X86_SIM_L_UNSPECIFIED() NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_UNSPECIFIED)
#define ENTRY() X86_SIM_ENTRY_RAW((void *)0)
#define CAPACITY X86_SIM_STACK_BYTES
#define BIAS X86_SIM_STACK_BYTES
#define ARENA __x86_stack_mem.b
#define PREPARE(OFF, LEN) do { __x86_rsp.ptr=(void *)-32L; __x86_rdi.ptr=X86_SIM_L_STACK_PTR(OFF); __x86_rdi_tag=X86_SIM_TAG_STACK; __x86_rsi.ptr=(void *)7; __x86_rsi_tag=X86_SIM_TAG_SCALAR; __x86_rdx.ptr=(void *)(long)(LEN); __x86_rdx_tag=X86_SIM_TAG_SCALAR; } while(0)
#define PTR() X86_SIM_L_HELPER_ARG_PTR(X86_RDI)
#define FILL() X86_SIM_L_EXEC_CALL_MEMSET_REG(0)
#define COPY() do { __x86_rsi.ptr=X86_SIM_L_STACK_PTR(-16); __x86_rsi_tag=X86_SIM_TAG_STACK; X86_SIM_L_EXEC_CALL_MEMCPY_REG(0); } while(0)
#define HELPER(LEN) do { __x86_rsi.ptr=(void *)(long)(LEN); X86_SIM_BPF_CALL_bpf_get_current_comm(); } while(0)
#define RESULT_BITS() ((__u64)(long)__x86_rax.ptr)
#define RESULT_TAG() __x86_rax_tag
#define LIBC_RESULT(OFF) ((__u64)(long)(&ARENA[BIAS+(OFF)]))
#define STACK_TAG X86_SIM_TAG_STACK
#define SCALAR_TAG X86_SIM_TAG_SCALAR
#define FACT_TAG X86_SIM_TAG_MAP_VALUE
#define SET_FACT(I, T) (__x86_stack_value_tags[(I)]=(T))
#define GET_FACT(I) __x86_stack_value_tags[I]
#define READ_BYTE(OFF) X86_SIM_L_STACK_READ((OFF), X86_WIDTH_8)
#endif

static unsigned long choice;
static unsigned draws, calls;
static void *expected_output;
static unsigned expected_size;
static int bad_helper_arguments;
static int helper_error;

unsigned long native_lab_entry_input(unsigned int kind)
{
    if (kind == NATIVE_LAB_INPUT_SP) return 0;
    if (kind == NATIVE_LAB_INPUT_UNSPECIFIED) { ++draws; return choice; }
    fprintf(stderr, "unexpected input kind %u\n", kind);
    abort();
}

/* An explicit helper outcome writes real bytes through the actual translated
 * argument. The real simulator wrapper handles result/clobbers/fact erasure. */
static long output_comm(void *output, __u32 size)
{
    ++calls;
    if (output != expected_output || size != expected_size) {
        bad_helper_arguments = 1;
        return -13;
    }
    /* Match the one kernel's comm success and err_clear outcomes. Zero size
     * is a wrapper boundary here; the stock verifier requires size > 0. */
    if (helper_error) {
        memset(output, 0, size);
        return -22;
    }
    const unsigned char comm[] = "helper-outcome";
    for (unsigned i = 0; i < size; ++i)
        ((unsigned char *)output)[i] = i+1 < size ? comm[i] : 0;
    return 0;
}
#define bpf_get_current_comm output_comm

static int run(unsigned operation, long offset, unsigned length, unsigned long input, int error)
{
    choice = input;
    ENTRY();
    PREPARE(offset, length);
    unsigned char expected[CAPACITY], original[CAPACITY];
    for (unsigned i = 0; i < CAPACITY; ++i) {
        expected[i] = original[i] = (unsigned char)(i*37U+11U);
        ARENA[i] = expected[i];
    }
    for (unsigned i = 0; i < CAPACITY/8; ++i)
        SET_FACT(i, (long)(i*8U)-(long)BIAS >= -32 ? FACT_TAG : SCALAR_TAG);
    expected_output = (void *)&ARENA[BIAS+offset];
    expected_size = length;
    calls = draws = 0;
    bad_helper_arguments = 0;
    helper_error = error;
    if (!operation) {
        if (PTR() != expected_output || draws) return 1;
    } else {
        for (unsigned i = 0; i < length; ++i) {
            unsigned at = (unsigned)((long)BIAS+offset+i);
            expected[at] = operation == 1 ? 7U : operation == 2 ?
                original[BIAS-16+i] : !error && i+1 < length ? (unsigned char)"helper-outcome"[i] : 0;
        }
        /* A call releases callee-owned bytes below the unchanged caller SP.
         * A repeated-byte input gives independent byte/word packing the same
         * observable outcome on both ISAs, without choosing zero globally. */
        for (unsigned i = 0; i < CAPACITY; ++i)
            if ((long)i-(long)BIAS < -32) expected[i] = (unsigned char)input;
        if (operation == 1) FILL();
        else if (operation == 2) COPY();
        else HELPER(length);
        if (operation == 3) {
            if (calls != 1 || bad_helper_arguments || RESULT_BITS() != (error ? (__u64)-22LL : 0) ||
                RESULT_TAG() != SCALAR_TAG) return 2;
        } else if (calls || RESULT_BITS() != LIBC_RESULT(offset) || RESULT_TAG() != STACK_TAG) return 3;
    }
    if (memcmp(expected, (const void *)ARENA, CAPACITY)) return 4;
    for (unsigned i = 0; i < CAPACITY/8; ++i) {
        long first = (long)(i*8U)-(long)BIAS;
        unsigned want = first >= -32 ? FACT_TAG : SCALAR_TAG;
        int overlap = length && first < offset+(long)length && offset < first+8;
        if (operation && overlap) {
            want = SCALAR_TAG;
#ifdef TEST_ARM64
            if (operation == 2 && length == 8 && offset == first && first >= -32) want = FACT_TAG;
#endif
        }
#ifndef TEST_ARM64
        /* Native libc's generic clobber path conservatively drops all facts;
         * typed write helpers preserve nonoverlapping caller facts. */
        if (operation == 1 || operation == 2) want = SCALAR_TAG;
#endif
        if (GET_FACT(i) != want) {
            fprintf(stderr, "fact offset=%ld actual=%u expected=%u\n", first, GET_FACT(i), want);
            return 5;
        }
    }
    unsigned prior_draws = draws;
    unsigned observed = READ_BYTE(offset);
    unsigned want_byte = offset < -32 ? (unsigned char)input : expected[BIAS+offset];
    if (observed != want_byte || draws-prior_draws != (offset < -32 ? 1U : 0U)) return 6;
    return 0;
}

int main(void)
{
    const long offsets[] = {-40,-35,-32,-24,-8};
    const unsigned lengths[] = {0,1,7,8};
    const unsigned long inputs[] = {0,0xa7a7a7a7a7a7a7a7UL};
    unsigned cases = 0;
    for (unsigned op = 0; op < 4; ++op)
        for (unsigned off = 0; off < sizeof(offsets)/sizeof(offsets[0]); ++off)
            for (unsigned len = 0; len < sizeof(lengths)/sizeof(lengths[0]); ++len)
                for (unsigned input = 0; input < sizeof(inputs)/sizeof(inputs[0]); ++input)
                  for (int error = 0; error < (op == 3 ? 2 : 1); ++error) {
                    int result = run(op, offsets[off], lengths[len], inputs[input], error);
                    if (result) {
                        fprintf(stderr, "output lifetime failure op=%u off=%ld len=%u input=%u error=%d check=%d\n",
                                op, offsets[off], lengths[len], input, error, result);
                        return 1;
                    }
                    ++cases;
                }
    printf("stack output lifetime: %u pointer/memset/memcpy/helper cases pass\n", cases);
}
