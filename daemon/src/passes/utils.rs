// SPDX-License-Identifier: MIT
//! Shared utilities for BPF rewrite passes.
//!
//! Contains branch fixup, kfunc call emission, and instruction iteration
//! helpers that are used by multiple passes.

use crate::insn::*;

// ── Branch fixup ───────────────────────────────────────────────────

/// Fix up branch and pseudo-call offsets after rewriting using an address map.
///
/// For each instruction in the *original* stream that is a branch/jump,
/// compute where it ended up in the new stream and adjust its offset
/// so it still points to the correct target.
pub fn fixup_all_branches(
    new_insns: &mut [BpfInsn],
    old_insns: &[BpfInsn],
    addr_map: &[usize],
) {
    let old_n = old_insns.len();
    let mut old_pc = 0;
    while old_pc < old_n {
        let insn = &old_insns[old_pc];
        if insn.is_call() && insn.src_reg() == 1 {
            // BPF pseudo-call: fix up imm (pc-relative offset to target subprog).
            let old_target = (old_pc as i64 + 1 + insn.imm as i64) as usize;
            if old_target < old_n {
                let new_pc = addr_map[old_pc];
                let new_target = addr_map[old_target];
                if new_pc < new_insns.len() && new_insns[new_pc].is_call() {
                    let new_imm = new_target as i64 - (new_pc as i64 + 1);
                    new_insns[new_pc].imm = new_imm as i32;
                }
            }
        } else if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
            let new_pc = addr_map[old_pc];
            let old_target = (old_pc as i64 + 1 + insn.off as i64) as usize;
            if old_target <= old_n {
                let new_target = addr_map[old_target];
                if new_pc < new_insns.len() && new_insns[new_pc].is_jmp_class() {
                    let new_off = new_target as i64 - (new_pc as i64 + 1);
                    new_insns[new_pc].off = new_off as i16;
                }
            }
        }
        old_pc = if insn.is_ldimm64() {
            old_pc + 2
        } else {
            old_pc + 1
        };
    }
}

// ── Kfunc call emission ────────────────────────────────────────────

/// A kfunc argument value -- either an immediate or a register.
#[derive(Clone, Copy, Debug, PartialEq)]
pub enum KfuncArg {
    Reg(u8),
    Imm(i32),
}

/// Emit a kfunc call sequence: set up arguments r1..rN, emit CALL, and
/// optionally move r0 to a destination register.
///
/// The generated sequence is:
///   MOV r1, args[0]
///   MOV r2, args[1]
///   ...
///   MOV rN, args[N-1]
///   CALL kfunc (btf_id)
///   MOV dst_reg, r0    (if dst_reg != 0)
///
/// Uses swap-safe parameter marshalling: if source registers overlap with
/// target registers {r1..rN}, the emission order is chosen to avoid aliasing.
/// Unresolvable conflicts are broken via r0 as a scratch register.
pub fn emit_kfunc_call(dst_reg: u8, args: &[KfuncArg], kfunc_btf_id: i32) -> Vec<BpfInsn> {
    let mut out = Vec::with_capacity(args.len() + 2);
    emit_safe_kfunc_params(&mut out, args);
    out.push(BpfInsn::call_kfunc(kfunc_btf_id));
    if dst_reg != 0 {
        out.push(BpfInsn::mov64_reg(dst_reg, 0));
    }
    out
}

/// Emit a MOV instruction for a KfuncArg value into a target register.
fn emit_mov_arg(dst: u8, val: KfuncArg) -> BpfInsn {
    match val {
        KfuncArg::Reg(src) => BpfInsn::mov64_reg(dst, src),
        KfuncArg::Imm(imm) => BpfInsn::mov64_imm(dst, imm),
    }
}

/// Swap-safe parameter marshalling for kfunc calls.
///
/// Sets r1=args[0], r2=args[1], ..., rN=args[N-1] without aliasing issues.
/// If a source register overlaps with a not-yet-written target, we reorder
/// or break cycles through r0 as scratch.
///
/// An assignment `dst <- val` is safe to emit only when writing `dst` would
/// NOT clobber a source register that another pending assignment still needs.
/// In graph terms: emit assignments in topological order of the "must read
/// before write" dependency graph. True cycles are broken via r0 scratch.
fn emit_safe_kfunc_params(out: &mut Vec<BpfInsn>, args: &[KfuncArg]) {
    struct Assignment {
        dst: u8,
        val: KfuncArg,
    }

    let mut assignments: Vec<Assignment> = args
        .iter()
        .enumerate()
        .map(|(i, &val)| Assignment {
            dst: (i + 1) as u8,
            val,
        })
        .collect();

    // Skip assignments where dst already holds the right value.
    // e.g., if args[0] = Reg(1), no need to emit mov r1, r1.
    assignments.retain(|a| !matches!(a.val, KfuncArg::Reg(r) if r == a.dst));

    let max_dst = args.len() as u8;
    let mut emitted = vec![false; (max_dst + 1) as usize];

    // Pass 1: topological emit — emit assignments that don't clobber
    // any source needed by another pending assignment.
    // An assignment i is safe to emit when:
    //   its destination is NOT a register source of any other pending assignment.
    for _round in 0..assignments.len() {
        for i in 0..assignments.len() {
            let dst = assignments[i].dst;
            if emitted[dst as usize] {
                continue;
            }

            // Check: would writing `dst` clobber a source that another
            // pending assignment still needs?
            let dst_is_pending_source = assignments.iter().enumerate().any(|(j, other)| {
                j != i
                    && !emitted[other.dst as usize]
                    && matches!(other.val, KfuncArg::Reg(r) if r == dst)
            });

            if !dst_is_pending_source {
                out.push(emit_mov_arg(dst, assignments[i].val));
                emitted[dst as usize] = true;
            }
        }
    }

    // Pass 2: break remaining cycles via r0 as scratch.
    // Any assignments still pending form true cycles (e.g., r1<-r2, r2<-r1).
    // For each cycle, follow the chain backwards: save one source to r0,
    // then emit the cycle in reverse order so each assignment reads its
    // source before that source gets overwritten.
    for i in 0..assignments.len() {
        let dst = assignments[i].dst;
        if emitted[dst as usize] {
            continue;
        }
        match assignments[i].val {
            KfuncArg::Reg(src) => {
                // Save source to r0 before the cycle unwinds.
                out.push(BpfInsn::mov64_reg(0, src));

                // Follow the cycle: starting from `src`, find the chain
                // of assignments back to `dst`, and emit them in reverse
                // (so each reads its source before that source is written).
                let mut chain = Vec::new();
                let mut cur = src;
                loop {
                    // Find the assignment whose dst == cur
                    let found = assignments.iter().position(|a| {
                        !emitted[a.dst as usize] && a.dst == cur
                    });
                    match found {
                        Some(idx) => {
                            chain.push(idx);
                            match assignments[idx].val {
                                KfuncArg::Reg(next) => {
                                    if next == src {
                                        // We've completed the cycle back to the saved source.
                                        break;
                                    }
                                    cur = next;
                                }
                                KfuncArg::Imm(_) => break,
                            }
                        }
                        None => break,
                    }
                }

                // Emit chain in order (each reads `cur` before it's overwritten
                // by the next assignment, since we follow the dependency direction).
                for &idx in &chain {
                    out.push(emit_mov_arg(assignments[idx].dst, assignments[idx].val));
                    emitted[assignments[idx].dst as usize] = true;
                }

                // Complete the original assignment from saved r0.
                out.push(BpfInsn::mov64_reg(dst, 0));
                emitted[dst as usize] = true;
            }
            KfuncArg::Imm(imm) => {
                out.push(BpfInsn::mov64_imm(dst, imm));
                emitted[dst as usize] = true;
            }
        }
    }
}

// ── Instruction iterator ───────────────────────────────────────────

/// Iterator over BPF instructions that automatically skips LDIMM64 second slots.
///
/// Yields `(pc, &BpfInsn)` for each logical instruction, advancing by 2
/// for LDIMM64 and by 1 for everything else.
#[allow(dead_code)]
pub fn insn_iter_skip_ldimm64(insns: &[BpfInsn]) -> InsnIterSkipLdimm64<'_> {
    InsnIterSkipLdimm64 { insns, pc: 0 }
}

#[allow(dead_code)]
pub struct InsnIterSkipLdimm64<'a> {
    insns: &'a [BpfInsn],
    pc: usize,
}

impl<'a> Iterator for InsnIterSkipLdimm64<'a> {
    type Item = (usize, &'a BpfInsn);

    fn next(&mut self) -> Option<Self::Item> {
        if self.pc >= self.insns.len() {
            return None;
        }
        let pc = self.pc;
        let insn = &self.insns[pc];
        self.pc = if insn.is_ldimm64() {
            pc + 2
        } else {
            pc + 1
        };
        Some((pc, insn))
    }
}

// ── Tests ──────────────────────────────────────────────────────────

#[cfg(test)]
mod tests {
    use super::*;

    fn exit_insn() -> BpfInsn {
        BpfInsn { code: BPF_JMP | BPF_EXIT, regs: 0, off: 0, imm: 0 }
    }

    #[test]
    fn test_fixup_all_branches_forward_jump() {
        // Old: [0] JA +1  [1] nop  [2] exit
        // New (insert at 1): [0] JA +1  [1] new_insn  [2] nop  [3] exit
        // addr_map: 0->0, 1->2, 2->3, sentinel 3->4
        let old_insns = vec![
            BpfInsn::ja(1),
            BpfInsn::nop(),
            exit_insn(),
        ];
        let mut new_insns = vec![
            BpfInsn::ja(1), // will be fixed
            BpfInsn::nop(), // inserted
            BpfInsn::nop(),
            exit_insn(),
        ];
        let addr_map = vec![0, 2, 3, 4];
        fixup_all_branches(&mut new_insns, &old_insns, &addr_map);
        // JA at new_pc=0 should target new_pc=3 (old target was pc=2 -> addr_map[2]=3)
        assert_eq!(new_insns[0].off, 2); // 3 - (0+1) = 2
    }

    #[test]
    fn test_emit_kfunc_call_basic() {
        let insns = emit_kfunc_call(2, &[KfuncArg::Reg(5), KfuncArg::Imm(42)], 9999);
        // Expected: mov r1, r5; mov r2, 42; call 9999; mov r2, r0
        assert_eq!(insns.len(), 4);
        // r1 = r5
        assert_eq!(insns[0].code, BPF_ALU64 | BPF_MOV | BPF_X);
        assert_eq!(insns[0].dst_reg(), 1);
        assert_eq!(insns[0].src_reg(), 5);
        // r2 = 42
        assert_eq!(insns[1].code, BPF_ALU64 | BPF_MOV | BPF_K);
        assert_eq!(insns[1].dst_reg(), 2);
        assert_eq!(insns[1].imm, 42);
        // call
        assert!(insns[2].is_call());
        assert_eq!(insns[2].imm, 9999);
        // mov r2, r0
        assert_eq!(insns[3].dst_reg(), 2);
        assert_eq!(insns[3].src_reg(), 0);
    }

    #[test]
    fn test_emit_kfunc_call_dst_is_r0() {
        let insns = emit_kfunc_call(0, &[KfuncArg::Imm(1)], 1234);
        // No trailing MOV since dst_reg == 0
        assert_eq!(insns.len(), 2); // mov r1, 1; call
        assert!(insns[1].is_call());
    }

    #[test]
    fn test_emit_kfunc_call_swap_safe() {
        // args: r1=Reg(2), r2=Reg(1) -- cycle: we need r2's old value for r1,
        // and r1's old value for r2.
        let insns = emit_kfunc_call(0, &[KfuncArg::Reg(2), KfuncArg::Reg(1)], 5555);
        // Should use r0 as scratch to break the cycle.
        // One valid sequence: mov r0,r2; mov r2,r1; mov r1,r0; call
        // Another: mov r0,r1; mov r1,r2; mov r2,r0; call
        // Either way, there should be a call instruction at the end.
        assert!(insns.last().unwrap().is_call());
        assert!(insns.len() >= 4); // at least 3 MOVs + call
    }

    #[test]
    fn test_emit_kfunc_call_no_redundant_mov() {
        // args: r1=Reg(1) -- should skip the identity mov
        let insns = emit_kfunc_call(0, &[KfuncArg::Reg(1), KfuncArg::Imm(7)], 1111);
        // Expected: mov r2, 7; call 1111  (skip mov r1, r1)
        assert_eq!(insns.len(), 2);
        assert_eq!(insns[0].dst_reg(), 2);
        assert!(insns[1].is_call());
    }

    #[test]
    fn test_insn_iter_skip_ldimm64() {
        let ldimm64_lo = BpfInsn {
            code: BPF_LD | BPF_DW | BPF_IMM,
            regs: BpfInsn::make_regs(0, 0),
            off: 0,
            imm: 42,
        };
        let ldimm64_hi = BpfInsn { code: 0, regs: 0, off: 0, imm: 0 };
        let insns = vec![
            BpfInsn::mov64_imm(0, 1),  // pc=0
            ldimm64_lo,                  // pc=1 (2-slot)
            ldimm64_hi,                  // pc=2 (second slot, skipped)
            exit_insn(),                 // pc=3
        ];
        let pcs: Vec<usize> = insn_iter_skip_ldimm64(&insns).map(|(pc, _)| pc).collect();
        assert_eq!(pcs, vec![0, 1, 3]);
    }

    #[test]
    fn test_insn_iter_empty() {
        let insns: Vec<BpfInsn> = vec![];
        let pcs: Vec<usize> = insn_iter_skip_ldimm64(&insns).map(|(pc, _)| pc).collect();
        assert!(pcs.is_empty());
    }
}
