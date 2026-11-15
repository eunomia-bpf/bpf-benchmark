/* Cross-TU calls below name the actual exported X86Pointer C definitions.
 * They compose the same primitives; no state-derived argument is snapshotted. */
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "X86Memory.h"
#undef __x86_stack_mem
#define __x86_stack_mem (*arena)
#undef X86_SIM_STACK_BYTES
#define X86_SIM_STACK_BYTES capacity
#undef X86_SIM_L_SV_TAG
#undef X86_SIM_L_SV_PTR
#define X86_SIM_L_SV_TAG(I) (*facts[(I)].tag)
#define X86_SIM_L_SV_PTR(I) (*facts[(I)].pointer)

static __u8 tag_of(struct x86_sim_register_state *state,__u64 reg)
{
    struct x86_sim_register_state *__x86_state=state;
    __u8 tag;
    X86_SIM_L_REG_TAG_INTO(tag,reg);
    return tag;
}
#undef X86_SIM_L_REG_TAG
#define X86_SIM_L_REG_TAG(REG) tag_of(state,REG)
#undef X86_SIM_L_READ_REG_WIDTH_SHIFT
#define X86_SIM_L_READ_REG_WIDTH_SHIFT(REG, WIDTH, SHIFT) \
    kprog_x86_read_reg(state,arena,capacity,(REG),(WIDTH),(SHIFT))
#undef X86_SIM_L_MEM_OFFSET
#define X86_SIM_L_MEM_OFFSET(AUX, DISP) kprog_x86_mem_offset(state,arena,capacity,(AUX),(DISP))
#undef X86_SIM_L_STACK_READ
#define X86_SIM_L_STACK_READ(OFF, WIDTH) kprog_x86_stack_read(state,arena,capacity,(OFF),(WIDTH))
static __u8 source_of(struct x86_sim_register_state *state,__u64 base,__u64 width)
{
    __u8 source;
    X86_SIM_L_MEM_READ_SRC_INTO(source,base,width);
    return source;
}
#undef X86_SIM_L_MEM_READ_SRC
#define X86_SIM_L_MEM_READ_SRC(BASE, WIDTH) source_of(state,(BASE),(WIDTH))

__u8 kprog_x86_movbe_width(__u64 flags)
{
    __u8 width;
    KPROG_X86_MOVBE_WIDTH_INTO(width,flags);
    return width;
}
__u8 kprog_x86_movbe_arm(__u64 stack)
{
    __u8 arm;
    KPROG_X86_MOVBE_ARM_INTO(arm,stack);
    return arm;
}
__u64 kprog_x86_read_mem_value(struct x86_sim_register_state *state,
                              struct kprog_x86_arena *arena,__u32 capacity,
                              __u64 base,__u64 aux,__u64 imm,__u64 width,__u64 store_disp)
{
    struct x86_sim_register_state *__x86_state=state;
    __u64 value;
    X86_SIM_L_READ_MEM_VALUE_INTO(value,base,aux,imm,width,store_disp);
    return value;
}
#undef X86_SIM_L_READ_MEM_VALUE
#define X86_SIM_L_READ_MEM_VALUE(BASE,AUX,IMM,WIDTH,STORE) \
    kprog_x86_read_mem_value(state,arena,capacity,(BASE),(AUX),(IMM),(WIDTH),(STORE))
#undef X86_SIM_L_READ_RECOVERY_MEM
#define X86_SIM_L_READ_RECOVERY_MEM(BASE,DST,AUX,DISP) \
    kprog_x86_read_recovery_mem(state,arena,facts,capacity,(BASE),(DST),(AUX),(DISP))
#if defined(__COMPCERT__)
#undef KPROG_X86_MOVBE_WIDTH
#define KPROG_X86_MOVBE_WIDTH(FLAGS) kprog_x86_movbe_width(FLAGS)
#endif
void kprog_x86_movbe_load(struct x86_sim_register_state *state,
                         struct kprog_x86_arena *arena,struct kprog_x86_stack_fact *facts,
                         __u32 capacity,__u64 dst,__u64 src,__u64 flags,__u64 aux,__u64 imm)
{
    struct x86_sim_register_state *__x86_state=state;
    X86_SIM_L_EXEC_MOVBE_LOAD(dst,src,flags,aux,imm);
}

/* Use the exact shared physical-store helper, including width byte capture. */
void kprog_x86_store_memory(void *address,__u64 width,__u64 value)
{
    KPROG_X86_MEM_STORE(address,width,value);
}
