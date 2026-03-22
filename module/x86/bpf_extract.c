// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: BITFIELD_EXTRACT — bit-field extraction via BEXTR (BMI1)
 *
 * Registers a kfunc bpf_extract64(u64 val, u32 start, u32 len) with
 * KF_INLINE_EMIT. Extracts bits [start, start+len) from val.
 * When inlined by the x86 JIT, emits a BEXTR sequence using BMI1.
 *
 * BPF register -> x86 register mapping (from bpf_jit_comp.c):
 *   BPF_REG_0 = RAX (return value)
 *   BPF_REG_1 = RDI (arg1 = val)
 *   BPF_REG_2 = RSI (arg2 = start)
 *   BPF_REG_3 = RDX (arg3 = len)
 *
 * BEXTR control operand format: bits[7:0] = start, bits[15:8] = length
 *
 * Emitted x86-64 sequence (12 bytes):
 *   89 D0              mov eax, edx           ; eax = len (32-bit, clears upper)
 *   C1 E0 08           shl eax, 8             ; eax = len << 8
 *   09 F0              or  eax, esi           ; eax = (len << 8) | start
 *   C4 E2 F8 F7 C7    bextr rax, rdi, rax    ; rax = extract(rdi, ctrl=rax)
 *
 * The BEXTR instruction is VEX-encoded (BMI1, CPUID.EBX[3]):
 *   VEX.NDS.LZ.0F38.W1 F7 /r
 *   C4 = 3-byte VEX prefix
 *   E2 = R~=1, X~=1, B~=1, mmmmm=00010 (0F38 map)
 *   F8 = W=1 (64-bit), vvvv=1111 (~RAX), L=0, pp=00
 *   F7 = opcode
 *   C7 = ModRM: mod=11, reg=RAX(000), rm=RDI(111)
 */

#include <linux/bpf.h>
#include <linux/btf.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/string.h>

/* ---- kfunc fallback implementation ---- */

__bpf_kfunc_start_defs();

__bpf_kfunc u64 bpf_extract64(u64 val, u32 start, u32 len)
{
	if (start >= 64 || len == 0 || len > 64)
		return 0;
	if (start + len > 64)
		len = 64 - start;
	return (val >> start) & (len >= 64 ? ~0ULL : (1ULL << len) - 1);
}

__bpf_kfunc_end_defs();

/* ---- BTF kfunc registration with KF_INLINE_EMIT ---- */

BTF_KFUNCS_START(bpf_extract_kfunc_ids)
BTF_ID_FLAGS(func, bpf_extract64, KF_INLINE_EMIT);
BTF_KFUNCS_END(bpf_extract_kfunc_ids)

static const struct btf_kfunc_id_set bpf_extract_kfunc_set = {
	.owner = THIS_MODULE,
	.set = &bpf_extract_kfunc_ids,
};

/* ---- x86 JIT emit callback ---- */

static int emit_extract_x86(u8 *image, u32 *off, bool emit,
			     const struct bpf_insn *insn,
			     struct bpf_prog *prog)
{
	/*
	 * Build BEXTR control value in EAX: (len << 8) | start
	 * Then execute BEXTR to extract the bit field.
	 *
	 * mov eax, edx           89 D0        (2 bytes)
	 * shl eax, 8             C1 E0 08     (3 bytes)
	 * or  eax, esi           09 F0        (2 bytes)
	 * bextr rax, rdi, rax    C4 E2 F8 F7 C7  (5 bytes)
	 *
	 * Total: 12 bytes
	 */
	static const u8 insns[] = {
		/* mov eax, edx — move len into eax (32-bit clears upper) */
		0x89, 0xD0,
		/* shl eax, 8 — shift len to bits[15:8] */
		0xC1, 0xE0, 0x08,
		/* or eax, esi — merge start into bits[7:0] */
		0x09, 0xF0,
		/* VEX-encoded BEXTR rax, rdi, rax (BMI1, 64-bit) */
		0xC4, 0xE2, 0xF8, 0xF7, 0xC7,
	};

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	(void)insn;
	(void)prog;

	if (emit)
		memcpy(image + *off, insns, sizeof(insns));

	*off += sizeof(insns);
	return sizeof(insns);
}

static struct bpf_kfunc_inline_ops extract_ops = {
	.emit_x86 = emit_extract_x86,
	.max_emit_bytes = 16,
};

/* ---- module init/exit ---- */

static int __init bpf_extract_init(void)
{
	int ret;

	ret = bpf_register_kfunc_inline_ops("bpf_extract64", &extract_ops);
	if (ret)
		return ret;

	ret = register_btf_kfunc_id_set(BPF_PROG_TYPE_UNSPEC,
					 &bpf_extract_kfunc_set);
	if (ret)
		bpf_unregister_kfunc_inline_ops("bpf_extract64");

	return ret;
}

static void __exit bpf_extract_exit(void)
{
	bpf_unregister_kfunc_inline_ops("bpf_extract64");
}

module_init(bpf_extract_init);
module_exit(bpf_extract_exit);

MODULE_DESCRIPTION("BpfReJIT kinsn: BITFIELD_EXTRACT (BEXTR/BMI1) inline kfunc");
MODULE_LICENSE("GPL");
