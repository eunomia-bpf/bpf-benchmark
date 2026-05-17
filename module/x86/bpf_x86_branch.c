// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: conditional and unconditional branches.
 *
 * The payload carries a verifier-side BPF PC delta and the original x86
 * rel8/rel32 displacement.  instantiate_insn() branches using shadow flags
 * written by cmp/test kinsns; emit_x86() writes exactly one x86 branch insn.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_ja(void) {}
__bpf_kfunc void bpf_x86_jae(void) {}
__bpf_kfunc void bpf_x86_jb(void) {}
__bpf_kfunc void bpf_x86_jbe(void) {}
__bpf_kfunc void bpf_x86_je(void) {}
__bpf_kfunc void bpf_x86_jne(void) {}
__bpf_kfunc void bpf_x86_jg(void) {}
__bpf_kfunc void bpf_x86_jge(void) {}
__bpf_kfunc void bpf_x86_jl(void) {}
__bpf_kfunc void bpf_x86_jle(void) {}
__bpf_kfunc void bpf_x86_js(void) {}
__bpf_kfunc void bpf_x86_jns(void) {}
__bpf_kfunc void bpf_x86_jmp(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_branch_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_ja)
BTF_ID_FLAGS(func, bpf_x86_jae)
BTF_ID_FLAGS(func, bpf_x86_jb)
BTF_ID_FLAGS(func, bpf_x86_jbe)
BTF_ID_FLAGS(func, bpf_x86_je)
BTF_ID_FLAGS(func, bpf_x86_jg)
BTF_ID_FLAGS(func, bpf_x86_jge)
BTF_ID_FLAGS(func, bpf_x86_jl)
BTF_ID_FLAGS(func, bpf_x86_jle)
BTF_ID_FLAGS(func, bpf_x86_jmp)
BTF_ID_FLAGS(func, bpf_x86_jne)
BTF_ID_FLAGS(func, bpf_x86_jns)
BTF_ID_FLAGS(func, bpf_x86_js)
BTF_KFUNCS_END(bpf_x86_branch_kfunc_ids)

enum x86_branch_cond {
	X86_BRANCH_JA,
	X86_BRANCH_JAE,
	X86_BRANCH_JB,
	X86_BRANCH_JBE,
	X86_BRANCH_JE,
	X86_BRANCH_JNE,
	X86_BRANCH_JG,
	X86_BRANCH_JGE,
	X86_BRANCH_JL,
	X86_BRANCH_JLE,
	X86_BRANCH_JS,
	X86_BRANCH_JNS,
};

static __always_inline s16 branch_delta(u64 payload)
{
	return kinsn_payload_s16(payload, 4);
}

static __always_inline s32 branch_x86_disp(u64 payload)
{
	payload = kinsn_payload_decode(payload);
	return (s32)((u32)(payload >> 20));
}

static __always_inline bool branch_x86_near(u64 payload)
{
	payload = kinsn_payload_decode(payload);
	return payload & 0xf;
}

static __always_inline void load_flag(struct bpf_insn *insn_buf, int *cnt,
				      u8 dst, s16 off)
{
	insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_W, dst, BPF_REG_10, off);
}

static __always_inline int branch_on_bool(u64 payload, struct bpf_insn *insn_buf,
					  int *cnt)
{
	int branch_idx, ja_idx, fallthrough_idx;
	s16 delta;

	branch_idx = *cnt;
	insn_buf[(*cnt)++] = BPF_JMP_IMM(BPF_JEQ, KINSN_X86_SCRATCH0,
					 0, 0);
	kinsn_x86_restore_scratch(insn_buf, cnt,
				  KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
				  KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1) |
				  KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH2));
	ja_idx = *cnt;
	insn_buf[(*cnt)++] = BPF_JMP_A(0);
	fallthrough_idx = *cnt;
	insn_buf[branch_idx].off = fallthrough_idx - branch_idx - 1;
	kinsn_x86_restore_scratch(insn_buf, cnt,
				  KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
				  KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1) |
				  KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH2));
	delta = branch_delta(payload);
	insn_buf[ja_idx] = BPF_JMP_A(delta - ja_idx - 1);
	return 0;
}

static int instantiate_jcc(u64 payload, struct bpf_insn *insn_buf,
			   enum x86_branch_cond cond)
{
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH2);
	int cnt = 0;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	switch (cond) {
	case X86_BRANCH_JE:
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			  KINSN_X86_SHADOW_ZF_OFF);
		break;
	case X86_BRANCH_JNE:
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			  KINSN_X86_SHADOW_ZF_OFF);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_XOR, KINSN_X86_SCRATCH0,
						1);
		break;
	case X86_BRANCH_JB:
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			  KINSN_X86_SHADOW_CF_OFF);
		break;
	case X86_BRANCH_JAE:
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			  KINSN_X86_SHADOW_CF_OFF);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_XOR, KINSN_X86_SCRATCH0,
						1);
		break;
	case X86_BRANCH_JBE:
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			  KINSN_X86_SHADOW_CF_OFF);
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH1,
			  KINSN_X86_SHADOW_ZF_OFF);
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, KINSN_X86_SCRATCH0,
						KINSN_X86_SCRATCH1);
		break;
	case X86_BRANCH_JA:
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			  KINSN_X86_SHADOW_CF_OFF);
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH1,
			  KINSN_X86_SHADOW_ZF_OFF);
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, KINSN_X86_SCRATCH0,
						KINSN_X86_SCRATCH1);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_XOR, KINSN_X86_SCRATCH0,
						1);
		break;
	case X86_BRANCH_JGE:
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			  KINSN_X86_SHADOW_GE_OFF);
		break;
	case X86_BRANCH_JL:
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			  KINSN_X86_SHADOW_GE_OFF);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_XOR, KINSN_X86_SCRATCH0,
						1);
		break;
	case X86_BRANCH_JLE:
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			  KINSN_X86_SHADOW_GE_OFF);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_XOR, KINSN_X86_SCRATCH0,
						1);
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH1,
			  KINSN_X86_SHADOW_ZF_OFF);
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, KINSN_X86_SCRATCH0,
						KINSN_X86_SCRATCH1);
		break;
	case X86_BRANCH_JG:
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			  KINSN_X86_SHADOW_GE_OFF);
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH1,
			  KINSN_X86_SHADOW_ZF_OFF);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_XOR, KINSN_X86_SCRATCH1,
						1);
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KINSN_X86_SCRATCH0,
						KINSN_X86_SCRATCH1);
		break;
	case X86_BRANCH_JS:
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			  KINSN_X86_SHADOW_SF_OFF);
		break;
	case X86_BRANCH_JNS:
		load_flag(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			  KINSN_X86_SHADOW_SF_OFF);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_XOR, KINSN_X86_SCRATCH0,
						1);
		break;
	}
	branch_on_bool(payload, insn_buf, &cnt);
	return cnt;
}

static int instantiate_jmp(u64 payload, struct bpf_insn *insn_buf)
{
	insn_buf[0] = BPF_JMP_A(branch_delta(payload) - 1);
	return 1;
}

static int emit_jcc_x86(u8 *image, u32 *off, bool emit, u64 payload, u8 cc)
{
	u8 buf[6];
	u32 len = 0;
	s32 disp = branch_x86_disp(payload);

	if (branch_x86_near(payload)) {
		kinsn_emit_u8(buf, &len, 0x0f);
		kinsn_emit_u8(buf, &len, 0x80 | cc);
		kinsn_emit_s32(buf, &len, disp);
	} else {
		if (disp < -128 || disp > 127)
			return -EINVAL;
		kinsn_emit_u8(buf, &len, 0x70 | cc);
		kinsn_emit_u8(buf, &len, (u8)disp);
	}
	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_jmp_x86(u8 *image, u32 *off, bool emit, u64 payload,
			const struct bpf_prog *prog)
{
	u8 buf[5];
	u32 len = 0;
	s32 disp = branch_x86_disp(payload);

	(void)prog;
	if (branch_x86_near(payload)) {
		kinsn_emit_u8(buf, &len, 0xe9);
		kinsn_emit_s32(buf, &len, disp);
	} else {
		if (disp < -128 || disp > 127)
			return -EINVAL;
		kinsn_emit_u8(buf, &len, 0xeb);
		kinsn_emit_u8(buf, &len, (u8)disp);
	}
	return kinsn_emit_finish(image, off, emit, buf, len);
}

#define DEFINE_JCC(NAME, COND, CC)						\
static int instantiate_##NAME(u64 payload, struct bpf_insn *insn_buf)		\
{										\
	return instantiate_jcc(payload, insn_buf, COND);			\
}										\
static int emit_##NAME##_x86(u8 *image, u32 *off, bool emit, u64 payload,	\
			     const struct bpf_prog *prog)			\
{										\
	(void)prog;								\
	return emit_jcc_x86(image, off, emit, payload, CC);			\
}

DEFINE_JCC(ja, X86_BRANCH_JA, 0x7)
DEFINE_JCC(jae, X86_BRANCH_JAE, 0x3)
DEFINE_JCC(jb, X86_BRANCH_JB, 0x2)
DEFINE_JCC(jbe, X86_BRANCH_JBE, 0x6)
DEFINE_JCC(je, X86_BRANCH_JE, 0x4)
DEFINE_JCC(jne, X86_BRANCH_JNE, 0x5)
DEFINE_JCC(jg, X86_BRANCH_JG, 0xf)
DEFINE_JCC(jge, X86_BRANCH_JGE, 0xd)
DEFINE_JCC(jl, X86_BRANCH_JL, 0xc)
DEFINE_JCC(jle, X86_BRANCH_JLE, 0xe)
DEFINE_JCC(js, X86_BRANCH_JS, 0x8)
DEFINE_JCC(jns, X86_BRANCH_JNS, 0x9)

#define BRANCH_DESC(NAME)						\
const struct bpf_kinsn bpf_x86_##NAME##_desc = {			\
	.owner = THIS_MODULE,						\
	.instantiate_insn = instantiate_##NAME,				\
	.emit_x86 = emit_##NAME##_x86,					\
	.max_insn_cnt = 24,						\
	.max_emit_bytes = 6,						\
}

BRANCH_DESC(ja);
BRANCH_DESC(jae);
BRANCH_DESC(jb);
BRANCH_DESC(jbe);
BRANCH_DESC(je);
BRANCH_DESC(jne);
BRANCH_DESC(jg);
BRANCH_DESC(jge);
BRANCH_DESC(jl);
BRANCH_DESC(jle);
BRANCH_DESC(js);
BRANCH_DESC(jns);
BRANCH_DESC(jmp);

static const struct bpf_kinsn * const bpf_x86_branch_kinsn_descs[] = {
	&bpf_x86_ja_desc,
	&bpf_x86_jae_desc,
	&bpf_x86_jb_desc,
	&bpf_x86_jbe_desc,
	&bpf_x86_je_desc,
	&bpf_x86_jg_desc,
	&bpf_x86_jge_desc,
	&bpf_x86_jl_desc,
	&bpf_x86_jle_desc,
	&bpf_x86_jmp_desc,
	&bpf_x86_jne_desc,
	&bpf_x86_jns_desc,
	&bpf_x86_js_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_branch,
		       "BpfReJIT x86 branch kinsns",
		       bpf_x86_branch_kfunc_ids,
		       bpf_x86_branch_kinsn_descs);
