/* Root existing production consumers; numerical operations remain canonical. */
#define ARM64_SIM_ENABLE_STACK 1
#include "Arm64Addressing.h"
#undef ARM64_SIM_STACK_BYTES
#define ARM64_SIM_STACK_BYTES (addressing->capacity)
#undef ARM64_SIM_STACK_BIAS
#define ARM64_SIM_STACK_BIAS (addressing->bias)
#undef ARM64_SIM_L_UNSPECIFIED
#define ARM64_SIM_L_UNSPECIFIED() NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_UNSPECIFIED)
#define __a64_stack (*addressing)
#define __a64_stack_tag (addressing->stack_tags)
#define __a64_stack_payload (addressing->payload)
#define __a64_sp (addressing->coordinates->stack_offset)
#define __a64_numeric_sp (addressing->coordinates->sp_base)
#define __a64_numeric_return (addressing->coordinates->return_base)
#define __a64_numeric_sp_valid (addressing->coordinates->sp_valid)
#define __a64_numeric_return_valid (addressing->coordinates->return_valid)
#define __a64_sim_helper_ctx (addressing->helper_context)
#define __a64_sim_helper_abi_base (addressing->helper_abi_base)
#define __a64_sim_is_xdp (addressing->is_xdp)
#define __a64_sim_abi_kind (addressing->abi_kind)
#define CELL(REG, NAME) [KPROG_ARM64_GPR_CELL(REG)] = &addressing->registers[KPROG_ARM64_GPR_CELL(REG)],
#define TAG(REG, NAME) [KPROG_ARM64_GPR_CELL(REG)] = &addressing->tags[KPROG_ARM64_GPR_CELL(REG)],
#define REGISTERS() \
	union arm64_sim_gpr *const __a64_cells[31] = { ARM64_SIM_L_FOR_EACH_GPR(CELL) }; \
	__u8 *const __a64_tag_cells[31] = { ARM64_SIM_L_FOR_EACH_GPR(TAG) }

__u64 kprog_arm64_modified_reg(struct kprog_arm64_addressing *addressing,
                              __u64 reg, __u8 mod, __u8 shift, __u8 width)
{
	REGISTERS();
	__u64 result;
	ARM64_SIM_L_MOD_VALUE_INTO(result, reg, mod, shift, width);
	return result;
}
__s64 kprog_arm64_memory_offset(struct kprog_arm64_addressing *addressing,
                               __u32 aux, __u64 index, __u64 imm)
{
	REGISTERS();
	__s64 result;
	ARM64_SIM_L_MEM_BASE_OFF_INTO(result, aux, index, imm);
	return result;
}
void *kprog_arm64_helper_argument(struct kprog_arm64_addressing *addressing, __u64 reg)
{
	REGISTERS();
	void * result;
	ARM64_SIM_L_HELPER_ARG_PTR_INTO(result, reg);
	return result;
}
void *kprog_arm64_helper_context(struct kprog_arm64_addressing *addressing, __u64 reg)
{
	REGISTERS();
	void * result;
	ARM64_SIM_L_HELPER_CTX_PTR_INTO(result, reg);
	return result;
}
void kprog_arm64_memory_pre(struct kprog_arm64_addressing *addressing,
                           __u64 base, __u32 aux, __u64 imm)
{
	REGISTERS();
	ARM64_SIM_L_MEM_PRE(base, aux, imm);
}
void kprog_arm64_memory_post(struct kprog_arm64_addressing *addressing,
                            __u64 base, __u32 aux, __u64 imm)
{
	REGISTERS();
	ARM64_SIM_L_MEM_POST(base, aux, imm);
}
__u8 kprog_arm64_memory_tag(struct kprog_arm64_addressing *addressing,
                           __u64 base, __u64 index, __u32 aux, __u64 imm,
                           __s64 extra, __u8 width)
{
	REGISTERS();
	__u8 result;
	ARM64_SIM_L_MEM_READ_TAG_INTO(result, base, index, aux, imm, extra, width);
	return result;
}
__u64 kprog_arm64_memory_payload(struct kprog_arm64_addressing *addressing,
                                __u64 base, __u64 index, __u32 aux, __u64 imm,
                                __s64 extra, __u64 value, __u8 tag)
{
	REGISTERS();
	__u64 result;
	ARM64_SIM_L_MEM_PAYLOAD_INTO(result, base, index, aux, imm, extra, value, tag);
	return result;
}

__u64 kprog_arm64_xdp_read(struct kprog_arm64_addressing *addressing,
                          __u64 base, __s64 off, __u8 width)
{
	REGISTERS();
	__u64 result;
	ARM64_SIM_L_XDP_READ_INTO(result, base, off, width);
	return result;
}
__u64 kprog_arm64_skb_read(struct kprog_arm64_addressing *addressing,
                          __u64 base, __s64 off, __u8 width)
{
	REGISTERS();
	__u64 result;
	ARM64_SIM_L_SKB_READ_INTO(result, base, off, width);
	return result;
}
void kprog_arm64_skb_write(struct kprog_arm64_addressing *addressing,
                           __u64 base, __s64 off, __u8 width, __u64 value)
{
	REGISTERS();
	ARM64_SIM_L_SKB_WRITE(base, off, width, value);
}
__u64 kprog_arm64_cb_read(void *context, __s64 off, __u8 width)
{
	__u64 result;
	ARM64_SIM_L_SKB_CB_READ_BYTES_INTO(result, context, off, width);
	return result;
}
void kprog_arm64_cb_write(void *context, __s64 off, __u8 width, __u64 value)
{
	ARM64_SIM_L_SKB_CB_WRITE_BYTES(context, off, width, value);
}

__u64 kprog_arm64_memory_read(struct kprog_arm64_addressing *addressing,
                             __u64 base, __u64 index, __u32 aux, __u64 imm,
                             __s64 extra, __u8 width)
{
	REGISTERS();
	__u64 result;
	ARM64_SIM_L_MEM_READ_INTO(result, base, index, aux, imm, extra, width);
	return result;
}
void kprog_arm64_memory_write(struct kprog_arm64_addressing *addressing,
                              __u64 base, __u64 index, __u32 aux, __u64 imm,
                              __s64 extra, __u8 width, __u64 value, __u8 tag)
{
	REGISTERS();
	ARM64_SIM_L_MEM_WRITE(base, index, aux, imm, extra, width, value, tag);
}

int kprog_arm64_read_fault(struct kprog_arm64_addressing *addressing,
                          __u64 base, __u64 index, __u32 aux, __u64 imm)
{
	REGISTERS();
	int result;
	ARM64_SIM_L_READ_FAULT_INTO(result, base, index, aux, imm);
	return result;
}
void kprog_arm64_load(struct kprog_arm64_addressing *addressing,
                      __u64 dst, __u64 base, __u64 index, __u32 aux, __u64 imm, __u8 flags)
{
	REGISTERS();
	ARM64_SIM_L_LOAD_STEP(ARM64_OP_LOAD, dst, base, index, aux, imm, ARM64_SIM_L_EFFECTIVE_WIDTH(flags));
}
void kprog_arm64_signed_load(struct kprog_arm64_addressing *addressing, __u32 op,
                             __u64 dst, __u64 base, __u64 index, __u32 aux, __u64 imm, __u8 flags)
{
	REGISTERS();
	ARM64_SIM_L_LDRSX_STEP(op, dst, base, index, aux, imm, ARM64_SIM_L_EFFECTIVE_WIDTH(flags));
}
void kprog_arm64_store(struct kprog_arm64_addressing *addressing,
                       __u64 base, __u64 src, __u64 index, __u32 aux, __u64 imm, __u8 flags)
{
	REGISTERS();
	ARM64_SIM_L_STORE_STEP(base, src, index, aux, imm, ARM64_SIM_L_EFFECTIVE_WIDTH(flags));
}

void kprog_arm64_pair_step(struct kprog_arm64_addressing *addressing, __u32 op,
                           __u64 dst, __u64 src, __u64 src2, __u64 base, __u64 index,
                           __u32 aux, __u64 imm, __u8 flags)
{
	REGISTERS();
	__u8 width = ARM64_SIM_L_EFFECTIVE_WIDTH(flags);
	ARM64_SIM_L_PAIR_MEM_STEP(op, dst, src, src2, base, index, aux, imm, width);
}
void kprog_arm64_exclusive_store(struct kprog_arm64_addressing *addressing,
                                  __u64 dst, __u64 src, __u64 base, __u32 aux,
                                  __u64 site, __u8 flags)
{
	REGISTERS();
	__u8 width = ARM64_SIM_L_EFFECTIVE_WIDTH(flags);
	ARM64_SIM_L_STLXR_STEP(ARM64_OP_STLXR, dst, src, base, aux, site, width);
}
void kprog_arm64_atomic_add(struct kprog_arm64_addressing *addressing,
                             __u64 dst, __u64 src, __u64 base, __u32 aux, __u8 flags)
{
	REGISTERS();
	__u8 width = ARM64_SIM_L_EFFECTIVE_WIDTH(flags);
	ARM64_SIM_L_ATOMIC_RMW(__atomic_fetch_add, 0, dst, src, base, width, aux);
}
void kprog_arm64_atomic_set(struct kprog_arm64_addressing *addressing,
                             __u64 dst, __u64 src, __u64 base, __u32 aux, __u8 flags)
{
	REGISTERS();
	__u8 width = ARM64_SIM_L_EFFECTIVE_WIDTH(flags);
	ARM64_SIM_L_ATOMIC_RMW(__atomic_fetch_or, 0, dst, src, base, width, aux);
}
void kprog_arm64_atomic_clear(struct kprog_arm64_addressing *addressing,
                             __u64 dst, __u64 src, __u64 base, __u32 aux, __u8 flags)
{
	REGISTERS();
	__u8 width = ARM64_SIM_L_EFFECTIVE_WIDTH(flags);
	ARM64_SIM_L_ATOMIC_RMW(__atomic_fetch_and, 1, dst, src, base, width, aux);
}
void kprog_arm64_memory_tags(struct kprog_arm64_addressing *addressing,
                              __s64 dst, __u8 dtag, __s64 src, __u8 stag,
                              __u64 length, __u8 copy)
{
	ARM64_SIM_L_MEMORY_TAG_TRANSFER(dst, dtag, src, stag, length, copy);
}
#undef __a64_v0
#undef __a64_v0_hi
#define __a64_v0 (*v0_lo)
#define __a64_v0_hi (*v0_hi)
void kprog_arm64_vector_step(struct kprog_arm64_addressing *addressing,
                             __u64 *v0_lo, __u64 *v0_hi, __u32 op, __u64 base,
                             __u64 index, __u32 aux, __u64 imm)
{
	REGISTERS();
	ARM64_SIM_L_DQ_MEM_STEP(op, base, index, aux, imm);
}

#undef __a64_v0
#undef __a64_v0_hi
#define __a64_vectors vectors
#define __a64_v0 (__a64_vectors[0].lo)
#define __a64_v0_hi (__a64_vectors[0].hi)
#define __a64_n (*n)
#define __a64_z (*z)
#define __a64_c (*c)
#define __a64_v (*v)
#if defined(__COMPCERT__)
/* Decoded register numbers are passed by value; all state observations stay
 * inside the same primitive and at the original dispatch expression site. */
static void *execute_pointer(struct kprog_arm64_addressing *addressing, __u64 reg)
{
	REGISTERS();
	void *result; ARM64_SIM_L_READ_REG_PTR_INTO(result, reg); return result;
}
static __u32 execute_tag(struct kprog_arm64_addressing *addressing, __u64 reg)
{
	REGISTERS();
	__u32 result; ARM64_SIM_L_REG_TAG_INTO(result, reg); return result;
}
static int execute_condition(__u64 cond, const __u8 *n, const __u8 *z,
                              const __u8 *c, const __u8 *v)
{
	int result;
	KPROG_ARM64_EVAL_COND_INTO(result, cond, *n, *z, *c, *v, ARM64_SIM_L_UNSUPPORTED_OPCODE());
	return result;
}
#undef ARM64_SIM_L_READ_REG_PTR
#define ARM64_SIM_L_READ_REG_PTR(REG) execute_pointer(addressing, (REG))
#undef ARM64_SIM_L_REG_TAG
#define ARM64_SIM_L_REG_TAG(REG) execute_tag(addressing, (REG))
#undef ARM64_SIM_L_READ_REG
#define ARM64_SIM_L_READ_REG(REG) kprog_arm64_read_reg(addressing->coordinates, addressing->registers, addressing->tags, (REG))
#undef ARM64_SIM_L_MOD_VALUE
#define ARM64_SIM_L_MOD_VALUE(REG, MOD, SHIFT, WIDTH) kprog_arm64_modified_reg(addressing, (REG), (MOD), (SHIFT), (WIDTH))
#undef ARM64_SIM_L_WRITE_REG_WIDTH
#define ARM64_SIM_L_WRITE_REG_WIDTH(REG, VALUE, WIDTH) kprog_arm64_write_reg(addressing->coordinates, addressing->registers, addressing->tags, addressing->b, addressing->stack_tags, addressing->capacity, addressing->bias, (REG), (VALUE), (WIDTH))
#undef ARM64_SIM_L_WRITE_REG_PTR_TAG
#define ARM64_SIM_L_WRITE_REG_PTR_TAG(REG, VALUE, TAG) kprog_arm64_write_ptr(addressing->coordinates, addressing->registers, addressing->tags, addressing->b, addressing->stack_tags, addressing->capacity, addressing->bias, (REG), (VALUE), (TAG))
#undef ARM64_SIM_L_MOV_PTR_TAG_PATH
#define ARM64_SIM_L_MOV_PTR_TAG_PATH(OP, WIDTH) kprog_arm64_mov_path((OP), (WIDTH))
#undef KPROG_ARM64_CSEL_PTR_TAG_PATH
#define KPROG_ARM64_CSEL_PTR_TAG_PATH(OP, WIDTH, UNSUPPORTED) kprog_arm64_csel_path((OP), (WIDTH))
#undef KPROG_ARM64_ALU_OPERAND_SELECT
#define KPROG_ARM64_ALU_OPERAND_SELECT(OP) kprog_arm64_alu_source(OP)
#undef KPROG_ARM64_EVAL_COND
#define KPROG_ARM64_EVAL_COND(COND, N, Z, C, V, UNSUPPORTED) execute_condition((COND), &(N), &(Z), &(C), &(V))
#undef KPROG_ALU64_RESULT
#define KPROG_ALU64_RESULT(OP, LHS, RHS, UNSUPPORTED) kprog_arm64_alu_result((OP), (LHS), (RHS))
#undef ARM64_SIM_L_REDUCTION_VALUE
#define ARM64_SIM_L_REDUCTION_VALUE(OP, VALUE) kprog_arm64_reduction((OP), (VALUE))
#undef KPROG_ARM64_FMOV_DEST_VECTOR
#define KPROG_ARM64_FMOV_DEST_VECTOR(DIR, UNSUPPORTED) kprog_arm64_fmov_dest(DIR)
#endif
void kprog_arm64_execute(struct kprog_arm64_addressing *addressing,
                         struct kprog_arm64_vector *vectors,
                         __u8 *n, __u8 *z, __u8 *c, __u8 *v, __u32 op,
                         __u64 dst, __u64 src, __u64 src2, __u64 src3,
                         __u8 flags, __u32 aux, __u64 imm)
{
	REGISTERS();
	ARM64_SIM_L_EXEC(op, dst, src, src2, src3, flags, aux, imm);
}

/* Bind the original named caller-saved fields to the same live GPR cells. */
#define __a64_x1 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X1)])
#define __a64_x1_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X1)])
#define __a64_x2 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X2)])
#define __a64_x2_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X2)])
#define __a64_x3 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X3)])
#define __a64_x3_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X3)])
#define __a64_x4 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X4)])
#define __a64_x4_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X4)])
#define __a64_x5 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X5)])
#define __a64_x5_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X5)])
#define __a64_x6 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X6)])
#define __a64_x6_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X6)])
#define __a64_x7 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X7)])
#define __a64_x7_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X7)])
#define __a64_x8 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X8)])
#define __a64_x8_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X8)])
#define __a64_x9 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X9)])
#define __a64_x9_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X9)])
#define __a64_x10 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X10)])
#define __a64_x10_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X10)])
#define __a64_x11 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X11)])
#define __a64_x11_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X11)])
#define __a64_x12 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X12)])
#define __a64_x12_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X12)])
#define __a64_x13 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X13)])
#define __a64_x13_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X13)])
#define __a64_x14 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X14)])
#define __a64_x14_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X14)])
#define __a64_x15 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X15)])
#define __a64_x15_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X15)])
#define __a64_x16 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X16)])
#define __a64_x16_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X16)])
#define __a64_x17 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X17)])
#define __a64_x17_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X17)])
#define __a64_x18 (*__a64_cells[KPROG_ARM64_GPR_CELL(ARM64_X18)])
#define __a64_x18_tag (*__a64_tag_cells[KPROG_ARM64_GPR_CELL(ARM64_X18)])

#if defined(__COMPCERT__)
/* Keep reads at their original value-expression site, after destination
 * resolution in memcpy; passing a pre-read value to the writer reorders it. */
#undef ARM64_SIM_L_MEM_READ
#define ARM64_SIM_L_MEM_READ(BASE, INDEX, AUX, IMM, EXTRA, WIDTH) kprog_arm64_memory_read(addressing, (BASE), (INDEX), (AUX), (IMM), (EXTRA), (WIDTH))
#undef KPROG_ARM64_FLAG_RHS
#define KPROG_ARM64_FLAG_RHS(OP, IMM, REG) kprog_arm64_flag_rhs((OP), (IMM), (REG))
#undef KPROG_ARM64_BRANCH_TEST
#define KPROG_ARM64_BRANCH_TEST(KIND, VALUE, BIT) kprog_arm64_branch_test((KIND), (VALUE), (BIT))
static __u64 execute_raw(struct kprog_arm64_addressing *addressing, __u64 reg)
{
	REGISTERS();
	__u64 result; ARM64_SIM_L_READ_REG_RAW_INTO(result, reg); return result;
}
#undef ARM64_SIM_L_READ_REG_RAW
#define ARM64_SIM_L_READ_REG_RAW(REG) execute_raw(addressing, (REG))
#endif

void kprog_arm64_helper_clobbers(struct kprog_arm64_addressing *addressing,
                                 struct kprog_arm64_vector *vectors,
                                 __u8 *n, __u8 *z, __u8 *c, __u8 *v)
{
	REGISTERS();
	ARM64_SIM_L_HELPER_CLOBBERS();
}
void kprog_arm64_libc_memset(struct kprog_arm64_addressing *addressing,
                             struct kprog_arm64_vector *vectors,
                             __u8 *n, __u8 *z, __u8 *c, __u8 *v)
{
	REGISTERS();
	ARM64_SIM_LIBC_MEMSET();
}
void kprog_arm64_libc_memcpy(struct kprog_arm64_addressing *addressing,
                             struct kprog_arm64_vector *vectors,
                             __u8 *n, __u8 *z, __u8 *c, __u8 *v)
{
	REGISTERS();
	ARM64_SIM_LIBC_MEMCPY();
}
int kprog_arm64_jcc(struct kprog_arm64_addressing *addressing,
                    __u8 *n, __u8 *z, __u8 *c, __u8 *v,
                    __u64 cond, __u64 current, __u64 target)
{
	REGISTERS();
	ARM64_SIM_A64_JCC(cond, current, target, taken);
	return 0;
taken: return 1;
}
int kprog_arm64_cbz_x(struct kprog_arm64_addressing *addressing, __u64 reg,
                      __u64 kind, __u64 current, __u64 target)
{
	REGISTERS();
	ARM64_SIM_A64_CBZ_IMPL(reg, kind, current, target, taken, 0);
	return 0;
taken: return 1;
}
int kprog_arm64_cbz_w(struct kprog_arm64_addressing *addressing, __u64 reg,
                      __u64 kind, __u64 current, __u64 target)
{
	REGISTERS();
	ARM64_SIM_A64_CBZ_VALUE_IMPL((__u32)ARM64_SIM_L_READ_REG(reg), kind, current, target, taken, 0);
	return 0;
taken: return 1;
}
int kprog_arm64_tbz(struct kprog_arm64_addressing *addressing, __u64 reg,
                    __u64 bit, __u64 kind, __u64 current, __u64 target)
{
	REGISTERS();
	ARM64_SIM_A64_TBZ_IMPL(reg, bit, kind, current, target, taken, 0);
	return 0;
taken: return 1;
}
int kprog_arm64_cmp_gt(struct kprog_arm64_addressing *addressing,
                       __u8 *n, __u8 *z, __u8 *c, __u8 *v, __u32 op,
                       __u64 lhs, __u64 rhs, __u8 width, __u32 aux, __u64 imm)
{
	REGISTERS();
	ARM64_SIM_A64_CMP_GT(op, lhs, rhs, width, aux, imm, taken);
	return 0;
taken: return 1;
}
__u64 kprog_arm64_link(struct kprog_arm64_addressing *addressing, __u64 address)
{
	REGISTERS();
	__u64 __a64_lr;
	ARM64_SIM_A64_LINK(address);
	return __a64_lr;
}
__u32 kprog_arm64_exit(struct kprog_arm64_addressing *addressing)
{
	REGISTERS();
	ARM64_SIM_RET();
}
__u32 kprog_arm64_return_to(struct kprog_arm64_addressing *addressing, __u64 reg)
{
	REGISTERS();
	__u64 __a64_lr;
	/* This root has no internal continuation cases. Actual program cases
	 * require their own label/PC binding; no unknown target is accepted. */
	ARM64_SIM_A64_RET_TO(reg, );
}

/* Existing helper bodies resolve a typed callee instead of a BPF-only numeric
 * function address. No helper behavior is implemented by this binding. */
#undef ARM64_SIM_L_HELPER_CLOBBERS
#define ARM64_SIM_L_HELPER_CLOBBERS() kprog_arm64_helper_clobbers(addressing, vectors, n, z, c, v)
#if defined(__COMPCERT__)
#undef ARM64_SIM_L_HELPER_ARG_PTR
#define ARM64_SIM_L_HELPER_ARG_PTR(REG) kprog_arm64_helper_argument(addressing, (REG))
#undef ARM64_SIM_L_HELPER_CTX_PTR
#define ARM64_SIM_L_HELPER_CTX_PTR(REG) kprog_arm64_helper_context(addressing, (REG))
#define HELPER_REGISTERS()
#else
#define HELPER_REGISTERS() REGISTERS()
#endif
#define KPROG_ARM64_HELPER(ID, NAME, RESULT, ARGS) \
void kprog_arm64_helper_##NAME(struct kprog_arm64_addressing *addressing, \
                               struct kprog_arm64_vector *vectors, \
                               __u8 *n, __u8 *z, __u8 *c, __u8 *v, RESULT (*NAME) ARGS) \
{ HELPER_REGISTERS(); ARM64_SIM_BPF_CALL_##NAME(); }
#include "Arm64HelperCalls.h"
#undef KPROG_ARM64_HELPER
