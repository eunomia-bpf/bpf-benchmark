#ifndef X86_SIM_INLINE_H
#define X86_SIM_INLINE_H

/* Include after the program's readonly-load hooks. Instruction constants enter
 * this one C body as arguments; preprocessing never clones it per instruction.
 * Bind existing cells by reference: no state copy, new input or input reorder.
 * Internal temporaries have no debugger identity: keep -g and program BTF,
 * without cloning thousands of interpreter variable descriptions per step. */
#include "x86_sim_local_bpf.h"
#ifdef KPROG_X86_PROGRAM_EXPORT
#include "../formal/c/X86ProgramCallees.h"
#endif

struct x86_sim_inline_value { __u8 *tag; void **pointer; };
struct x86_sim_inline_bindings {
    struct x86_sim_gpr_cell *cells;
    union x86_sim_stack_mem *stack;
    struct x86_sim_inline_value values[KPROG_X86_STACK_WORDS(X86_SIM_STACK_BYTES)];
    __u64 *native_stack_base;
    __u8 *cf;
    __u8 *zf;
    __u8 *sf;
    __u8 *of;
    __u8 *pf;
    __u8 *af;
    __u64 *xmm0_lo;
    __u64 *xmm0_hi;
    __u64 *sim_ret_addr;
    void * sim_helper_ctx;
    void * sim_helper_abi_base;
    struct __sk_buff * sim_skb_ctx;
    __u8 sim_is_xdp;
    __u8 sim_abi_kind;
};

#define X86_SIM_INLINE_VALUE(I) \
    [(I)] = { &X86_SIM_L_SV_TAG(I), &X86_SIM_L_SV_PTR(I) },
#ifdef X86_SIM_STACK_VALUE_WORDS
#define X86_SIM_INLINE_VALUES_INIT \
    .values = { X86_SIM_STACK_VALUE_WORDS(X86_SIM_INLINE_VALUE) },
#define X86_SIM_INLINE_VALUES_BIND() do { } while (0)
#else
#define X86_SIM_INLINE_VALUES_INIT
#define X86_SIM_INLINE_VALUES_BIND() \
    do { for (__u32 i=0; i<KPROG_X86_STACK_WORDS(X86_SIM_STACK_BYTES); ++i) { \
        __x86_inline_bindings.values[i].tag=&X86_SIM_L_SV_TAG(i); \
        __x86_inline_bindings.values[i].pointer=&X86_SIM_L_SV_PTR(i); \
    } } while (0)
#endif

#define X86_SIM_BIND_INLINE() \
    struct x86_sim_inline_bindings __x86_inline_bindings = { \
        .cells=__x86_gpr_cells, .stack=&__x86_stack_mem, \
        X86_SIM_INLINE_VALUES_INIT \
        .native_stack_base=&__x86_native_stack_base, \
        .cf=&__x86_cf, \
        .zf=&__x86_zf, \
        .sf=&__x86_sf, \
        .of=&__x86_of, \
        .pf=&__x86_pf, \
        .af=&__x86_af, \
        .xmm0_lo=&__x86_xmm0_lo, \
        .xmm0_hi=&__x86_xmm0_hi, \
        .sim_ret_addr=&__x86_sim_ret_addr, \
        .sim_helper_ctx=__x86_sim_helper_ctx, \
        .sim_helper_abi_base=__x86_sim_helper_abi_base, \
        .sim_skb_ctx=__x86_sim_skb_ctx, \
        .sim_is_xdp=__x86_sim_is_xdp, \
        .sim_abi_kind=__x86_sim_abi_kind, \
    }; \
    X86_SIM_INLINE_VALUES_BIND()

#pragma push_macro("__x86_rax")
#undef __x86_rax
#define __x86_rax (__x86_bind->cells[0].value)
#pragma push_macro("__x86_rcx")
#undef __x86_rcx
#define __x86_rcx (__x86_bind->cells[1].value)
#pragma push_macro("__x86_rdx")
#undef __x86_rdx
#define __x86_rdx (__x86_bind->cells[2].value)
#pragma push_macro("__x86_rbx")
#undef __x86_rbx
#define __x86_rbx (__x86_bind->cells[3].value)
#pragma push_macro("__x86_rsp")
#undef __x86_rsp
#define __x86_rsp (__x86_bind->cells[4].value)
#pragma push_macro("__x86_rbp")
#undef __x86_rbp
#define __x86_rbp (__x86_bind->cells[5].value)
#pragma push_macro("__x86_rsi")
#undef __x86_rsi
#define __x86_rsi (__x86_bind->cells[6].value)
#pragma push_macro("__x86_rdi")
#undef __x86_rdi
#define __x86_rdi (__x86_bind->cells[7].value)
#pragma push_macro("__x86_r8")
#undef __x86_r8
#define __x86_r8 (__x86_bind->cells[8].value)
#pragma push_macro("__x86_r9")
#undef __x86_r9
#define __x86_r9 (__x86_bind->cells[9].value)
#pragma push_macro("__x86_r10")
#undef __x86_r10
#define __x86_r10 (__x86_bind->cells[10].value)
#pragma push_macro("__x86_r11")
#undef __x86_r11
#define __x86_r11 (__x86_bind->cells[11].value)
#pragma push_macro("__x86_r12")
#undef __x86_r12
#define __x86_r12 (__x86_bind->cells[12].value)
#pragma push_macro("__x86_r13")
#undef __x86_r13
#define __x86_r13 (__x86_bind->cells[13].value)
#pragma push_macro("__x86_r14")
#undef __x86_r14
#define __x86_r14 (__x86_bind->cells[14].value)
#pragma push_macro("__x86_r15")
#undef __x86_r15
#define __x86_r15 (__x86_bind->cells[15].value)
#pragma push_macro("__x86_rax_tag")
#undef __x86_rax_tag
#define __x86_rax_tag (__x86_bind->cells[0].tag)
#pragma push_macro("__x86_rcx_tag")
#undef __x86_rcx_tag
#define __x86_rcx_tag (__x86_bind->cells[1].tag)
#pragma push_macro("__x86_rdx_tag")
#undef __x86_rdx_tag
#define __x86_rdx_tag (__x86_bind->cells[2].tag)
#pragma push_macro("__x86_rbx_tag")
#undef __x86_rbx_tag
#define __x86_rbx_tag (__x86_bind->cells[3].tag)
#pragma push_macro("__x86_rsp_tag")
#undef __x86_rsp_tag
#define __x86_rsp_tag (__x86_bind->cells[4].tag)
#pragma push_macro("__x86_rbp_tag")
#undef __x86_rbp_tag
#define __x86_rbp_tag (__x86_bind->cells[5].tag)
#pragma push_macro("__x86_rsi_tag")
#undef __x86_rsi_tag
#define __x86_rsi_tag (__x86_bind->cells[6].tag)
#pragma push_macro("__x86_rdi_tag")
#undef __x86_rdi_tag
#define __x86_rdi_tag (__x86_bind->cells[7].tag)
#pragma push_macro("__x86_r8_tag")
#undef __x86_r8_tag
#define __x86_r8_tag (__x86_bind->cells[8].tag)
#pragma push_macro("__x86_r9_tag")
#undef __x86_r9_tag
#define __x86_r9_tag (__x86_bind->cells[9].tag)
#pragma push_macro("__x86_r10_tag")
#undef __x86_r10_tag
#define __x86_r10_tag (__x86_bind->cells[10].tag)
#pragma push_macro("__x86_r11_tag")
#undef __x86_r11_tag
#define __x86_r11_tag (__x86_bind->cells[11].tag)
#pragma push_macro("__x86_r12_tag")
#undef __x86_r12_tag
#define __x86_r12_tag (__x86_bind->cells[12].tag)
#pragma push_macro("__x86_r13_tag")
#undef __x86_r13_tag
#define __x86_r13_tag (__x86_bind->cells[13].tag)
#pragma push_macro("__x86_r14_tag")
#undef __x86_r14_tag
#define __x86_r14_tag (__x86_bind->cells[14].tag)
#pragma push_macro("__x86_r15_tag")
#undef __x86_r15_tag
#define __x86_r15_tag (__x86_bind->cells[15].tag)
#pragma push_macro("__x86_gpr_cells")
#undef __x86_gpr_cells
#define __x86_gpr_cells (__x86_bind->cells)
#pragma push_macro("__x86_native_stack_base")
#undef __x86_native_stack_base
#define __x86_native_stack_base (*__x86_bind->native_stack_base)
#pragma push_macro("__x86_cf")
#undef __x86_cf
#define __x86_cf (*__x86_bind->cf)
#pragma push_macro("__x86_zf")
#undef __x86_zf
#define __x86_zf (*__x86_bind->zf)
#pragma push_macro("__x86_sf")
#undef __x86_sf
#define __x86_sf (*__x86_bind->sf)
#pragma push_macro("__x86_of")
#undef __x86_of
#define __x86_of (*__x86_bind->of)
#pragma push_macro("__x86_pf")
#undef __x86_pf
#define __x86_pf (*__x86_bind->pf)
#pragma push_macro("__x86_af")
#undef __x86_af
#define __x86_af (*__x86_bind->af)
#pragma push_macro("__x86_xmm0_lo")
#undef __x86_xmm0_lo
#define __x86_xmm0_lo (*__x86_bind->xmm0_lo)
#pragma push_macro("__x86_xmm0_hi")
#undef __x86_xmm0_hi
#define __x86_xmm0_hi (*__x86_bind->xmm0_hi)
#pragma push_macro("__x86_sim_ret_addr")
#undef __x86_sim_ret_addr
#define __x86_sim_ret_addr (*__x86_bind->sim_ret_addr)
#pragma push_macro("__x86_sim_helper_ctx")
#undef __x86_sim_helper_ctx
#define __x86_sim_helper_ctx (__x86_bind->sim_helper_ctx)
#pragma push_macro("__x86_sim_helper_abi_base")
#undef __x86_sim_helper_abi_base
#define __x86_sim_helper_abi_base (__x86_bind->sim_helper_abi_base)
#pragma push_macro("__x86_sim_skb_ctx")
#undef __x86_sim_skb_ctx
#define __x86_sim_skb_ctx (__x86_bind->sim_skb_ctx)
#pragma push_macro("__x86_sim_is_xdp")
#undef __x86_sim_is_xdp
#define __x86_sim_is_xdp (__x86_bind->sim_is_xdp)
#pragma push_macro("__x86_sim_abi_kind")
#undef __x86_sim_abi_kind
#define __x86_sim_abi_kind (__x86_bind->sim_abi_kind)
#pragma push_macro("__x86_stack_mem")
#undef __x86_stack_mem
#define __x86_stack_mem (*__x86_bind->stack)
#pragma push_macro("X86_SIM_L_SV_TAG")
#undef X86_SIM_L_SV_TAG
#define X86_SIM_L_SV_TAG(I) (*__x86_bind->values[(I)].tag)
#pragma push_macro("X86_SIM_L_SV_PTR")
#undef X86_SIM_L_SV_PTR
#define X86_SIM_L_SV_PTR(I) (*__x86_bind->values[(I)].pointer)

#if defined(__COMPCERT__)
#ifdef X86_SIM_L_NATIVE_DATA_LOAD_INTO
/* Producer readonly selection shares its declaration body with native C. */
static __always_inline __u64
x86_sim_inline_native_data_load(const void *base, __u64 offset, __u8 width)
{
    __u64 value;
    X86_SIM_L_NATIVE_DATA_LOAD_INTO(value, base, offset, width);
    return value;
}
#pragma push_macro("X86_SIM_L_NATIVE_DATA_LOAD")
#undef X86_SIM_L_NATIVE_DATA_LOAD
#define X86_SIM_L_NATIVE_DATA_LOAD(BASE, OFF, WIDTH) \
    x86_sim_inline_native_data_load((BASE), (OFF), (WIDTH))
#endif
/* The native expression facades and these standard-C functions use the same
 * primitive bodies. Pass the binding itself, so unused cells stay unread.
 * Arguments at the execution sites are decoded fields, not state snapshots. */
static __always_inline __u64
x86_sim_inline_read_reg(const struct x86_sim_inline_bindings *__x86_bind,
    __u64 reg, __u64 width, __u64 shift)
{
    __u64 value;
    X86_SIM_L_READ_REG_WIDTH_SHIFT_INTO(value, reg, width, shift);
    return value;
}

static __always_inline __u8
x86_sim_inline_reg_tag(const struct x86_sim_inline_bindings *__x86_bind,
    __u64 reg)
{
    __u8 tag;
    X86_SIM_L_REG_TAG_INTO(tag, reg);
    return tag;
}

#pragma push_macro("X86_SIM_L_READ_REG_WIDTH_SHIFT")
#undef X86_SIM_L_READ_REG_WIDTH_SHIFT
#define X86_SIM_L_READ_REG_WIDTH_SHIFT(REG, WIDTH, SHIFT) \
    x86_sim_inline_read_reg(__x86_bind, (REG), (WIDTH), (SHIFT))
#pragma push_macro("X86_SIM_L_REG_TAG")
#undef X86_SIM_L_REG_TAG
#define X86_SIM_L_REG_TAG(REG) x86_sim_inline_reg_tag(__x86_bind, (REG))

static __always_inline __u8
x86_sim_inline_mem_read_src(const struct x86_sim_inline_bindings *__x86_bind,
    __u64 base, __u64 width)
{
    __u8 source;
    X86_SIM_L_MEM_READ_SRC_INTO(source, base, width);
    return source;
}
#pragma push_macro("X86_SIM_L_MEM_READ_SRC")
#undef X86_SIM_L_MEM_READ_SRC
#define X86_SIM_L_MEM_READ_SRC(BASE, WIDTH) \
    x86_sim_inline_mem_read_src(__x86_bind, (BASE), (WIDTH))

static __always_inline __u64
x86_sim_inline_stack_read(const struct x86_sim_inline_bindings *__x86_bind,
    __s64 offset, __u64 width)
{
    __u64 value;
    X86_SIM_L_STACK_READ_INTO(value, offset, width);
    return value;
}
#pragma push_macro("X86_SIM_L_STACK_READ")
#undef X86_SIM_L_STACK_READ
#define X86_SIM_L_STACK_READ(OFF, WIDTH) \
    x86_sim_inline_stack_read(__x86_bind, (OFF), (WIDTH))

static __always_inline struct x86_sim_stack_value
x86_sim_inline_stack_values_read(const struct x86_sim_inline_bindings *__x86_bind,
    __u64 index, __u64 width)
{
    struct x86_sim_stack_value value;
    X86_SIM_L_STACK_VALUES_READ_INTO(value, index, width);
    return value;
}
#pragma push_macro("X86_SIM_L_STACK_VALUES_READ")
#undef X86_SIM_L_STACK_VALUES_READ
#define X86_SIM_L_STACK_VALUES_READ(INDEX, WIDTH) \
    x86_sim_inline_stack_values_read(__x86_bind, (INDEX), (WIDTH))

static __always_inline __s64
x86_sim_inline_mem_offset(const struct x86_sim_inline_bindings *__x86_bind,
    __u64 aux, __s64 displacement)
{
    __s64 offset;
    X86_SIM_L_MEM_OFFSET_INTO(offset, aux, displacement);
    return offset;
}
#pragma push_macro("X86_SIM_L_MEM_OFFSET")
#undef X86_SIM_L_MEM_OFFSET
#define X86_SIM_L_MEM_OFFSET(AUX, DISP) x86_sim_inline_mem_offset(__x86_bind, (AUX), (DISP))

/* Only decoded scalar fields are captured here. The state-derived address
 * and index remain inside the common recovery body's short circuit. */
static __always_inline int
x86_sim_inline_read_recovery(const struct x86_sim_inline_bindings *__x86_bind,
    __u64 base, __u64 dst)
{
    int recovered;
    X86_SIM_L_READ_RECOVERY_INTO(recovered, base, dst);
    return recovered;
}
static __always_inline int
x86_sim_inline_read_recovery_mem(const struct x86_sim_inline_bindings *__x86_bind,
    __u64 base, __u64 dst, __u64 aux, __s64 displacement)
{
    int recovered;
    X86_SIM_L_READ_RECOVERY_MEM_INTO(recovered, base, dst, aux, displacement);
    return recovered;
}
#pragma push_macro("X86_SIM_L_READ_RECOVERY")
#undef X86_SIM_L_READ_RECOVERY
#define X86_SIM_L_READ_RECOVERY(BASE, DST) x86_sim_inline_read_recovery(__x86_bind, (BASE), (DST))
#pragma push_macro("X86_SIM_L_READ_RECOVERY_MEM")
#undef X86_SIM_L_READ_RECOVERY_MEM
#define X86_SIM_L_READ_RECOVERY_MEM(BASE, DST, AUX, DISP) \
    x86_sim_inline_read_recovery_mem(__x86_bind, (BASE), (DST), (AUX), (DISP))

static __always_inline __u8 x86_sim_inline_movbe_width(__u64 flags)
{
    __u8 width;
    KPROG_X86_MOVBE_WIDTH_INTO(width,flags);
    return width;
}
#pragma push_macro("KPROG_X86_MOVBE_WIDTH")
#undef KPROG_X86_MOVBE_WIDTH
#define KPROG_X86_MOVBE_WIDTH(FLAGS) x86_sim_inline_movbe_width(FLAGS)

static __always_inline __u8 x86_sim_inline_movbe_arm(__u64 stack)
{
    __u8 arm;
    KPROG_X86_MOVBE_ARM_INTO(arm,stack);
    return arm;
}
#pragma push_macro("KPROG_X86_MOVBE_ARM")
#undef KPROG_X86_MOVBE_ARM
#define KPROG_X86_MOVBE_ARM(STACK) x86_sim_inline_movbe_arm(STACK)

static __always_inline __u64
x86_sim_inline_read_mem_value(const struct x86_sim_inline_bindings *__x86_bind,
    __u64 base, __u64 aux, __u64 imm, __u64 width, __u64 store_disp)
{
    __u64 value;
    X86_SIM_L_READ_MEM_VALUE_INTO(value,base,aux,imm,width,store_disp);
    return value;
}
#pragma push_macro("X86_SIM_L_READ_MEM_VALUE")
#undef X86_SIM_L_READ_MEM_VALUE
#define X86_SIM_L_READ_MEM_VALUE(BASE, AUX, IMM, WIDTH, STORE) \
    x86_sim_inline_read_mem_value(__x86_bind,(BASE),(AUX),(IMM),(WIDTH),(STORE))

/* These execution-site arguments are decoded fields. Source register reads
 * remain inside the shared store declaration's immediate/register branch. */
static __always_inline __u32 x86_sim_inline_store_src_shift(__u64 immediate,__u64 aux)
{
    __u32 shift;
    KPROG_X86_STORE_SRC_SHIFT_INTO(shift,immediate,aux);
    return shift;
}
#pragma push_macro("KPROG_X86_STORE_SRC_SHIFT")
#undef KPROG_X86_STORE_SRC_SHIFT
#define KPROG_X86_STORE_SRC_SHIFT(IMMEDIATE, AUX) x86_sim_inline_store_src_shift(IMMEDIATE,AUX)
static __always_inline __u8 x86_sim_inline_store_arm(__u64 stack)
{
    __u8 arm;
    KPROG_X86_STORE_ARM_INTO(arm,stack);
    return arm;
}
#pragma push_macro("KPROG_X86_STORE_ARM")
#undef KPROG_X86_STORE_ARM
#define KPROG_X86_STORE_ARM(STACK) x86_sim_inline_store_arm(STACK)
static __always_inline __u8 x86_sim_inline_xmm0_arm(__u64 stack)
{
    __u8 arm;
    KPROG_X86_XMM0_ARM_INTO(arm,stack);
    return arm;
}
#pragma push_macro("KPROG_X86_XMM0_ARM")
#undef KPROG_X86_XMM0_ARM
#define KPROG_X86_XMM0_ARM(STACK) x86_sim_inline_xmm0_arm(STACK)
static __always_inline __u8 x86_sim_inline_cmov_writeback(__u64 wide)
{
    __u8 result; KPROG_X86_CMOV_WRITEBACK_INTO(result,wide); return result;
}
static __always_inline __u8 x86_sim_inline_setcc_lane(__u64 shift)
{
    __u8 result; KPROG_X86_SETCC_LANE_INTO(result,shift); return result;
}
static __always_inline __u8 x86_sim_inline_setcc_mem_base(__u64 dst)
{
    __u8 result; KPROG_X86_SETCC_MEM_BASE_INTO(result,dst); return result;
}
static __always_inline __u8 x86_sim_inline_setcc_mem_arm(__u64 stack)
{
    __u8 result; KPROG_X86_SETCC_MEM_ARM_INTO(result,stack); return result;
}
#pragma push_macro("KPROG_X86_CMOV_WRITEBACK")
#undef KPROG_X86_CMOV_WRITEBACK
#define KPROG_X86_CMOV_WRITEBACK(WIDE) x86_sim_inline_cmov_writeback(WIDE)
#pragma push_macro("KPROG_X86_SETCC_LANE")
#undef KPROG_X86_SETCC_LANE
#define KPROG_X86_SETCC_LANE(SHIFT) x86_sim_inline_setcc_lane(SHIFT)
#pragma push_macro("KPROG_X86_SETCC_MEM_BASE")
#undef KPROG_X86_SETCC_MEM_BASE
#define KPROG_X86_SETCC_MEM_BASE(DST) x86_sim_inline_setcc_mem_base(DST)
#pragma push_macro("KPROG_X86_SETCC_MEM_ARM")
#undef KPROG_X86_SETCC_MEM_ARM
#define KPROG_X86_SETCC_MEM_ARM(STACK) x86_sim_inline_setcc_mem_arm(STACK)
#endif

static __always_inline __attribute__((nodebug)) void
x86_sim_inline_clear_values(const struct x86_sim_inline_bindings *__x86_bind)
{ X86_SIM_L_STACK_VALUES_CLEAR(); }
#pragma push_macro("X86_SIM_L_STACK_VALUES_CLEAR")
#undef X86_SIM_L_STACK_VALUES_CLEAR
#define X86_SIM_L_STACK_VALUES_CLEAR() x86_sim_inline_clear_values(__x86_bind)

static __always_inline __attribute__((nodebug)) void
x86_sim_inline_call_frame_values(const struct x86_sim_inline_bindings *__x86_bind)
{ X86_SIM_L_STACK_VALUES_CALL_FRAME(); }
#pragma push_macro("X86_SIM_L_STACK_VALUES_CALL_FRAME")
#undef X86_SIM_L_STACK_VALUES_CALL_FRAME
#define X86_SIM_L_STACK_VALUES_CALL_FRAME() x86_sim_inline_call_frame_values(__x86_bind)

static __always_inline __attribute__((nodebug)) void
x86_sim_inline_helper_register_clobbers(const struct x86_sim_inline_bindings *__x86_bind)
{ X86_SIM_L_HELPER_REGISTER_CLOBBERS(); }
#pragma push_macro("X86_SIM_L_HELPER_REGISTER_CLOBBERS")
#undef X86_SIM_L_HELPER_REGISTER_CLOBBERS
#define X86_SIM_L_HELPER_REGISTER_CLOBBERS() x86_sim_inline_helper_register_clobbers(__x86_bind)

/* Families are compiled separately before constant-opcode wrappers inline.
 * The C statements and dispatch conditions remain shared with the raw I. */
#define X86_SIM_INLINE_FAMILY(NAME) \
    static __always_inline __attribute__((nodebug)) void \
    x86_sim_inline_arm_##NAME(const struct x86_sim_inline_bindings *__x86_bind, \
        __u8 op, __u8 dst, __u8 src, __u8 flags, __u32 aux, __u64 imm, __u8 width) \
    { X86_SIM_L_ARM_##NAME(op, dst, src, flags, aux, imm, width); }
X86_SIM_L_FAMILIES(X86_SIM_INLINE_FAMILY)
#undef X86_SIM_INLINE_FAMILY

#define X86_SIM_INLINE_CALL_ARM(BIND, NAME, OP, DST, SRC, FLAGS, AUX, IMM, WIDTH) \
    x86_sim_inline_arm_##NAME(BIND, OP, DST, SRC, FLAGS, AUX, IMM, WIDTH)

/* This template contains calls only, never a second copy of a handler body. */
#define X86_SIM_DECLARE_INSTRUCTION(NAME, OPCODE) \
    static __always_inline __attribute__((nodebug)) void \
    NAME(const struct x86_sim_inline_bindings *__x86_bind, \
         __u8 dst, __u8 src, __u8 flags, __u32 aux, __u64 imm) \
    { X86_SIM_L_EXEC_DISPATCH(X86_SIM_INLINE_CALL_ARM, __x86_bind, \
                             OPCODE, dst, src, flags, aux, imm); }

static __always_inline __attribute__((nodebug)) void
x86_sim_inline_execute(const struct x86_sim_inline_bindings *__x86_bind,
    __u8 op, __u8 dst, __u8 src, __u8 flags, __u32 aux, __u64 imm)
{
    X86_SIM_L_EXEC_DISPATCH(X86_SIM_INLINE_CALL_ARM, __x86_bind, op, dst, src, flags, aux, imm);
}

static __always_inline __attribute__((nodebug)) void
x86_sim_inline_mul(const struct x86_sim_inline_bindings *__x86_bind, __u8 src)
{ X86_SIM_L_EXEC_MUL_U64(src); }

static __always_inline __attribute__((nodebug)) void
x86_sim_inline_stos(const struct x86_sim_inline_bindings *__x86_bind, __u8 width)
{ X86_SIM_L_EXEC_REP_STOS(width); }

static __always_inline __attribute__((nodebug)) void
x86_sim_inline_code(const struct x86_sim_inline_bindings *__x86_bind, __u8 dst, __u64 address)
{ X86_SIM_X86_CODE_ADDRESS(dst, address); }

static __always_inline __attribute__((nodebug)) int
x86_sim_inline_condition(const struct x86_sim_inline_bindings *__x86_bind, __u8 cc)
{ return X86_SIM_L_EVAL_CC(cc); }

static __always_inline __attribute__((nodebug)) void
x86_sim_inline_call(const struct x86_sim_inline_bindings *__x86_bind, __u64 address)
{
    __x86_rsp.ptr = KPROG_PTR_ADD64_BITS(__x86_rsp.ptr, -8);
    X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, address);
}

static __always_inline __attribute__((nodebug)) void
x86_sim_inline_subret(const struct x86_sim_inline_bindings *__x86_bind)
{
    __x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
    __x86_rsp.ptr = KPROG_PTR_ADD64_BITS(__x86_rsp.ptr, +8);
    X86_SIM_L_STACK_RELEASE((__s64)(long)__x86_rsp.ptr - 8);
}

static __always_inline __attribute__((nodebug)) __u32
x86_sim_inline_return(const struct x86_sim_inline_bindings *__x86_bind)
{ X86_SIM_X86_RET(); }

static __always_inline __attribute__((nodebug)) int
x86_sim_inline_recover(const struct x86_sim_inline_bindings *__x86_bind,
    __u8 base, __u8 dst, __u32 aux, __s64 displacement)
{ return X86_SIM_L_READ_RECOVERY_MEM(base, dst, aux, displacement); }

#pragma pop_macro("X86_SIM_L_HELPER_REGISTER_CLOBBERS")
#pragma pop_macro("X86_SIM_L_STACK_VALUES_CALL_FRAME")
#pragma pop_macro("X86_SIM_L_STACK_VALUES_CLEAR")
#if defined(__COMPCERT__)
#ifdef X86_SIM_L_NATIVE_DATA_LOAD_INTO
#pragma pop_macro("X86_SIM_L_NATIVE_DATA_LOAD")
#endif
#pragma pop_macro("KPROG_X86_SETCC_MEM_ARM")
#pragma pop_macro("KPROG_X86_SETCC_MEM_BASE")
#pragma pop_macro("KPROG_X86_SETCC_LANE")
#pragma pop_macro("KPROG_X86_CMOV_WRITEBACK")
#pragma pop_macro("KPROG_X86_XMM0_ARM")
#pragma pop_macro("KPROG_X86_STORE_ARM")
#pragma pop_macro("KPROG_X86_STORE_SRC_SHIFT")
#pragma pop_macro("X86_SIM_L_READ_RECOVERY_MEM")
#pragma pop_macro("X86_SIM_L_READ_MEM_VALUE")
#pragma pop_macro("KPROG_X86_MOVBE_ARM")
#pragma pop_macro("KPROG_X86_MOVBE_WIDTH")
#pragma pop_macro("X86_SIM_L_READ_RECOVERY")
#pragma pop_macro("X86_SIM_L_MEM_OFFSET")
#pragma pop_macro("X86_SIM_L_STACK_VALUES_READ")
#pragma pop_macro("X86_SIM_L_STACK_READ")
#pragma pop_macro("X86_SIM_L_MEM_READ_SRC")
#pragma pop_macro("X86_SIM_L_REG_TAG")
#pragma pop_macro("X86_SIM_L_READ_REG_WIDTH_SHIFT")
#endif
#pragma pop_macro("X86_SIM_L_SV_PTR")
#pragma pop_macro("X86_SIM_L_SV_TAG")
#pragma pop_macro("__x86_stack_mem")
#pragma pop_macro("__x86_sim_abi_kind")
#pragma pop_macro("__x86_sim_is_xdp")
#pragma pop_macro("__x86_sim_skb_ctx")
#pragma pop_macro("__x86_sim_helper_abi_base")
#pragma pop_macro("__x86_sim_helper_ctx")
#pragma pop_macro("__x86_sim_ret_addr")
#pragma pop_macro("__x86_xmm0_hi")
#pragma pop_macro("__x86_xmm0_lo")
#pragma pop_macro("__x86_af")
#pragma pop_macro("__x86_pf")
#pragma pop_macro("__x86_of")
#pragma pop_macro("__x86_sf")
#pragma pop_macro("__x86_zf")
#pragma pop_macro("__x86_cf")
#pragma pop_macro("__x86_native_stack_base")
#pragma pop_macro("__x86_gpr_cells")
#pragma pop_macro("__x86_r15_tag")
#pragma pop_macro("__x86_r14_tag")
#pragma pop_macro("__x86_r13_tag")
#pragma pop_macro("__x86_r12_tag")
#pragma pop_macro("__x86_r11_tag")
#pragma pop_macro("__x86_r10_tag")
#pragma pop_macro("__x86_r9_tag")
#pragma pop_macro("__x86_r8_tag")
#pragma pop_macro("__x86_rdi_tag")
#pragma pop_macro("__x86_rsi_tag")
#pragma pop_macro("__x86_rbp_tag")
#pragma pop_macro("__x86_rsp_tag")
#pragma pop_macro("__x86_rbx_tag")
#pragma pop_macro("__x86_rdx_tag")
#pragma pop_macro("__x86_rcx_tag")
#pragma pop_macro("__x86_rax_tag")
#pragma pop_macro("__x86_r15")
#pragma pop_macro("__x86_r14")
#pragma pop_macro("__x86_r13")
#pragma pop_macro("__x86_r12")
#pragma pop_macro("__x86_r11")
#pragma pop_macro("__x86_r10")
#pragma pop_macro("__x86_r9")
#pragma pop_macro("__x86_r8")
#pragma pop_macro("__x86_rdi")
#pragma pop_macro("__x86_rsi")
#pragma pop_macro("__x86_rbp")
#pragma pop_macro("__x86_rsp")
#pragma pop_macro("__x86_rbx")
#pragma pop_macro("__x86_rdx")
#pragma pop_macro("__x86_rcx")
#pragma pop_macro("__x86_rax")

#undef X86_SIM_RUN_OP
#define X86_SIM_RUN_OP(OP, DST, SRC, FLAGS, AUX, IMM) \
    __x86_instruction_##OP(&__x86_inline_bindings, (DST), (SRC), (FLAGS), (AUX), (__u64)(IMM))
#undef X86_SIM_RUN_OP_SUB
#define X86_SIM_RUN_OP_SUB(OP, DST, SRC, FLAGS, AUX, IMM) \
    __x86_instruction_##OP(&__x86_inline_bindings, (DST), (SRC), (FLAGS), (AUX), (__u64)(IMM))
#undef X86_SIM_L_EVAL_CC
#define X86_SIM_L_EVAL_CC(CC) x86_sim_inline_condition(&__x86_inline_bindings, (CC))
#undef X86_SIM_X86_CODE_ADDRESS
#define X86_SIM_X86_CODE_ADDRESS(DST, ADDRESS) \
    x86_sim_inline_code(&__x86_inline_bindings, (DST), (ADDRESS))
#undef X86_SIM_X86_RET
#define X86_SIM_X86_RET() return x86_sim_inline_return(&__x86_inline_bindings)
#undef X86_SIM_X86_CALL
#define X86_SIM_X86_CALL(LABEL, ADDRESS) \
    do { x86_sim_inline_call(&__x86_inline_bindings, (ADDRESS)); goto LABEL; } while (0)
#undef X86_SIM_X86_SUB_RET
#define X86_SIM_X86_SUB_RET(LABEL) \
    do { x86_sim_inline_subret(&__x86_inline_bindings); goto LABEL; } while (0)
#undef X86_SIM_L_READ_RECOVERY_MEM
#define X86_SIM_L_READ_RECOVERY_MEM(BASE, DST, AUX, DISP) \
    x86_sim_inline_recover(&__x86_inline_bindings, (BASE), (DST), (AUX), (DISP))

#if defined(__COMPCERT__) && defined(KPROG_X86_PROGRAM_EXPORT)
/* Generated indirect target switches read the live entry binding too. */
#undef X86_SIM_L_READ_REG_WIDTH_SHIFT
#define X86_SIM_L_READ_REG_WIDTH_SHIFT(REG, WIDTH, SHIFT) \
    x86_sim_inline_read_reg(&__x86_inline_bindings, (REG), (WIDTH), (SHIFT))
#undef X86_SIM_L_REG_TAG
#define X86_SIM_L_REG_TAG(REG) \
    x86_sim_inline_reg_tag(&__x86_inline_bindings, (REG))
#endif

#endif
