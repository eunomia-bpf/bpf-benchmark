/* Same production C bodies, bound to actual entry-local references. */
#define ARM64_SIM_ENABLE_STACK 1
#include "Arm64Program.h"
#undef ARM64_SIM_STACK_BYTES
#undef ARM64_SIM_STACK_BIAS
#define ARM64_SIM_STACK_BYTES (entry->capacity)
#define ARM64_SIM_STACK_BIAS (entry->bias)
#define __a64_cells (entry->cells)
#define __a64_tag_cells (entry->tag_cells)
#define __a64_stack (*entry)
#define __a64_stack_tag (entry->stack_tags)
#define __a64_stack_payload (entry->payload)
#undef ARM64_SIM_L_STACK_PAYLOAD_LOAD
#undef ARM64_SIM_L_STACK_PAYLOAD_STORE
#define ARM64_SIM_L_STACK_PAYLOAD_LOAD(INDEX) entry->payload_load(entry->payload, (INDEX))
#define ARM64_SIM_L_STACK_PAYLOAD_STORE(INDEX, VALUE) \
    entry->payload_store(entry->payload, (INDEX), (VALUE))
#define __a64_sp (*entry->sp)
#define __a64_numeric_sp (*entry->sp_base)
#define __a64_numeric_return (*entry->return_base)
#define __a64_numeric_sp_valid (*entry->sp_valid)
#define __a64_numeric_return_valid (*entry->return_valid)
#define __a64_sim_helper_ctx (*entry->helper_context)
#define __a64_sim_helper_abi_base (*entry->helper_abi_base)
#define __a64_sim_is_xdp (*entry->is_xdp)
#define __a64_sim_abi_kind (*entry->abi_kind)
#define __a64_sim_skb_ctx (*entry->skb_context)
#define __a64_sim_abi (*(struct arm64_sim_xdp_abi *)entry->abi)
#define __a64_n (*entry->n)
#define __a64_z (*entry->z)
#define __a64_c (*entry->c)
#define __a64_v (*entry->v)
#undef ARM64_SIM_L_VECTOR_LO
#undef ARM64_SIM_L_VECTOR_HI
#define ARM64_SIM_L_VECTOR_LO(INDEX) (*entry->vector_lo[(INDEX)])
#define ARM64_SIM_L_VECTOR_HI(INDEX) (*entry->vector_hi[(INDEX)])
#define __a64_x1 (*entry->cells[1])
#define __a64_x1_tag (*entry->tag_cells[1])
#define __a64_x2 (*entry->cells[2])
#define __a64_x2_tag (*entry->tag_cells[2])
#define __a64_x3 (*entry->cells[3])
#define __a64_x3_tag (*entry->tag_cells[3])
#define __a64_x4 (*entry->cells[4])
#define __a64_x4_tag (*entry->tag_cells[4])
#define __a64_x5 (*entry->cells[5])
#define __a64_x5_tag (*entry->tag_cells[5])
#define __a64_x6 (*entry->cells[6])
#define __a64_x6_tag (*entry->tag_cells[6])
#define __a64_x7 (*entry->cells[7])
#define __a64_x7_tag (*entry->tag_cells[7])
#define __a64_x8 (*entry->cells[8])
#define __a64_x8_tag (*entry->tag_cells[8])
#define __a64_x9 (*entry->cells[9])
#define __a64_x9_tag (*entry->tag_cells[9])
#define __a64_x10 (*entry->cells[10])
#define __a64_x10_tag (*entry->tag_cells[10])
#define __a64_x11 (*entry->cells[11])
#define __a64_x11_tag (*entry->tag_cells[11])
#define __a64_x12 (*entry->cells[12])
#define __a64_x12_tag (*entry->tag_cells[12])
#define __a64_x13 (*entry->cells[13])
#define __a64_x13_tag (*entry->tag_cells[13])
#define __a64_x14 (*entry->cells[14])
#define __a64_x14_tag (*entry->tag_cells[14])
#define __a64_x15 (*entry->cells[15])
#define __a64_x15_tag (*entry->tag_cells[15])
#define __a64_x16 (*entry->cells[16])
#define __a64_x16_tag (*entry->tag_cells[16])
#define __a64_x17 (*entry->cells[17])
#define __a64_x17_tag (*entry->tag_cells[17])
#define __a64_x18 (*entry->cells[18])
#define __a64_x18_tag (*entry->tag_cells[18])
__u64 kprog_arm64_program_raw(struct kprog_arm64_entry *entry, __u64 reg)
{ __u64 result; ARM64_SIM_L_READ_REG_RAW_INTO(result, reg); return result; }
void * kprog_arm64_program_pointer(struct kprog_arm64_entry *entry, __u64 reg)
{ void * result; ARM64_SIM_L_READ_REG_PTR_INTO(result, reg); return result; }
__u32 kprog_arm64_program_tag(struct kprog_arm64_entry *entry, __u64 reg)
{ __u32 result; ARM64_SIM_L_REG_TAG_INTO(result, reg); return result; }
__u64 kprog_arm64_program_read(struct kprog_arm64_entry *entry, __u64 reg)
{ __u64 result; ARM64_SIM_L_READ_REG_INTO(result, reg); return result; }
void * kprog_arm64_program_argument(struct kprog_arm64_entry *entry, __u64 reg)
{ void * result; ARM64_SIM_L_HELPER_ARG_PTR_INTO(result, reg); return result; }
void * kprog_arm64_program_context(struct kprog_arm64_entry *entry, __u64 reg)
{ void * result; ARM64_SIM_L_HELPER_CTX_PTR_INTO(result, reg); return result; }
void kprog_arm64_program_write(struct kprog_arm64_entry *entry, __u64 reg, __u64 value, __u8 width)
{ ARM64_SIM_L_WRITE_REG_WIDTH(reg, value, width); }
void kprog_arm64_program_write_pointer(struct kprog_arm64_entry *entry, __u64 reg, void *value, __u8 tag)
{ ARM64_SIM_L_WRITE_REG_PTR_TAG(reg, value, tag); }
__u64 kprog_arm64_program_modified(struct kprog_arm64_entry *entry, __u64 reg, __u8 mod, __u8 shift, __u8 width)
{ __u64 result; ARM64_SIM_L_MOD_VALUE_INTO(result, reg, mod, shift, width); return result; }
__u64 kprog_arm64_program_memory_read(struct kprog_arm64_entry *entry, __u64 base, __u64 index, __u32 aux, __u64 imm, __s64 extra, __u8 width)
{ __u64 result; ARM64_SIM_L_MEM_READ_INTO(result, base, index, aux, imm, extra, width); return result; }
int kprog_arm64_program_condition(__u64 cond, const __u8 *n, const __u8 *z, const __u8 *c, const __u8 *v)
{ int result; KPROG_ARM64_EVAL_COND_INTO(result, cond, *n, *z, *c, *v, ARM64_SIM_L_UNSUPPORTED_OPCODE()); return result; }
void kprog_arm64_program_clobbers(struct kprog_arm64_entry *entry)
{ ARM64_SIM_L_HELPER_CLOBBERS(); }

#define KPROG_ARM64_PROGRAM_STATE entry
#include "Arm64ProgramExpressions.h"
void kprog_arm64_program_execute(struct kprog_arm64_entry *entry, __u32 op, __u64 dst, __u64 src, __u64 src2, __u64 src3, __u8 flags, __u32 aux, __u64 imm)
{ ARM64_SIM_L_EXEC(op, dst, src, src2, src3, flags, aux, imm); }
void kprog_arm64_program_memset(struct kprog_arm64_entry *entry)
{ ARM64_SIM_LIBC_MEMSET(); }
void kprog_arm64_program_memcpy(struct kprog_arm64_entry *entry)
{ ARM64_SIM_LIBC_MEMCPY(); }
#define KPROG_ARM64_HELPER(ID, NAME, RESULT, ARGS) \
void kprog_arm64_program_helper_##NAME(struct kprog_arm64_entry *entry, RESULT (*NAME) ARGS) \
{ ARM64_SIM_BPF_CALL_##NAME(); }
#include "Arm64HelperCalls.h"
#undef KPROG_ARM64_HELPER
