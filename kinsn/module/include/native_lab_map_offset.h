/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_MAP_OFFSET_H
#define NATIVE_LAB_MAP_OFFSET_H

#include <linux/bpf.h>

/* A register addend is admitted only with an actual constant definition
 * dominating this straight-line prefix. Incoming CFG edges that bypass the
 * definition reject; no verifier-known scalar is guessed from register names.
 */
static inline int native_lab_map_constant_before(const struct bpf_insn *insns,
    __u32 count, __u32 position, __u32 reg, __u64 *value)
{
    __u32 i, definition = 0;
    int known = 0;
    for (i = 0; i < position; i++) {
        const struct bpf_insn *insn = &insns[i];
        __u32 cls = BPF_CLASS(insn->code);
        if (insn->code == (BPF_LD | BPF_DW | BPF_IMM)) {
            if (insn->dst_reg == reg) known = 0;
            i++;
        } else if (cls == BPF_JMP || cls == BPF_JMP32) {
            if (BPF_OP(insn->code) != BPF_CALL || reg <= BPF_REG_5) known = 0;
        } else if ((cls == BPF_ALU64 || cls == BPF_ALU || cls == BPF_LDX) && insn->dst_reg == reg) {
            known = (insn->code == (BPF_ALU64 | BPF_MOV | BPF_K) ||
                     insn->code == (BPF_ALU | BPF_MOV | BPF_K)) && !insn->src_reg && !insn->off;
            if (known) {
                *value = cls == BPF_ALU64 ? (__u64)(__s64)insn->imm : (__u32)insn->imm;
                definition = i;
            }
        }
    }
    if (!known) return 0;
    for (i = 0; i < count; i++) {
        const struct bpf_insn *insn = &insns[i];
        __u32 cls = BPF_CLASS(insn->code), op = BPF_OP(insn->code);
        __s64 target;
        if (insn->code == (BPF_LD | BPF_DW | BPF_IMM)) { i++; continue; }
        if (cls != BPF_JMP && cls != BPF_JMP32) continue;
        if (op == BPF_EXIT) continue;
        if (op == BPF_CALL) {
            if (!insn->src_reg) continue;
            target = (__s64)i + 1 + insn->imm;
        } else {
            target = (__s64)i + 1 +
                (insn->code == (BPF_JMP32 | BPF_JA) ? insn->imm : insn->off);
        }
        if (target > definition && target <= position) return 0;
    }
    return 1;
}

/* Match an exact value pointer, including constant pointer arithmetic that
 * clang leaves after the source-map base LDDW. This never substitutes a
 * same-map range check for identity of the actual derived value address.
 */
static inline int native_lab_map_offset_matches(const struct bpf_insn *insns,
    __u32 count, __u32 index, __u32 base, __u32 target)
{
    __u64 offset = base;
    __u32 next;
    if (index >= count || count - index < 2)
        return 0;
    if (offset == target)
        return 1;
    for (next = index + 2; next < count; next++) {
        const struct bpf_insn *step = &insns[next];
        __u64 immediate = (__u64)(__s64)step->imm;
        __u32 op = BPF_OP(step->code);
        if (step->dst_reg != insns[index].dst_reg || step->off ||
            BPF_CLASS(step->code) != BPF_ALU64 || (op != BPF_ADD && op != BPF_SUB))
            return 0;
        if (BPF_SRC(step->code) == BPF_X) {
            if (step->src_reg > BPF_REG_10 ||
                !native_lab_map_constant_before(insns, count, next, step->src_reg, &immediate))
                return 0;
        } else if (step->src_reg) {
            return 0;
        }
        offset = op == BPF_ADD ? offset + immediate : offset - immediate;
        if (offset > (__u32)-1)
            return 0;
        if (offset == target)
            return 1;
    }
    return 0;
}
#endif
