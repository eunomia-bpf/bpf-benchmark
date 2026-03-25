// SPDX-License-Identifier: MIT
//! Shared utilities for BPF rewrite passes.
//!
//! Contains branch fixup, kinsn call emission, and instruction iteration
//! helpers that are used by multiple passes.

use std::collections::HashSet;

use crate::analysis::{CFGAnalysis, CFGResult};
use crate::insn::*;
use crate::pass::{Analysis, BpfProgram};

// ── Branch fixup ───────────────────────────────────────────────────

/// Fix up branch and pseudo-call offsets after rewriting using an address map.
///
/// For each instruction in the *original* stream that is a branch/jump,
/// compute where it ended up in the new stream and adjust its offset
/// so it still points to the correct target.
pub fn fixup_all_branches(new_insns: &mut [BpfInsn], old_insns: &[BpfInsn], addr_map: &[usize]) {
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

/// Compose two address maps: `old -> mid` and `mid -> new`.
pub fn compose_addr_maps(first: &[usize], second: &[usize]) -> Vec<usize> {
    first.iter().map(|&pc| second[pc]).collect()
}

/// Remove all CFG-unreachable basic blocks from the instruction stream.
pub fn eliminate_unreachable_blocks(insns: &[BpfInsn]) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    if insns.is_empty() {
        return None;
    }

    let cfg = CFGAnalysis.run(&BpfProgram::new(insns.to_vec()));
    eliminate_unreachable_blocks_with_cfg(insns, &cfg)
}

/// Remove all CFG-unreachable basic blocks from the instruction stream using
/// a caller-provided CFG.
pub fn eliminate_unreachable_blocks_with_cfg(
    insns: &[BpfInsn],
    cfg: &CFGResult,
) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    if insns.is_empty() || cfg.blocks.is_empty() {
        return None;
    }

    let mut reachable = vec![false; cfg.blocks.len()];
    let mut worklist = Vec::new();
    let mut entry_blocks = HashSet::new();

    for subprog in &cfg.subprogs {
        if subprog.start < insns.len() {
            entry_blocks.insert(cfg.insn_to_block[subprog.start]);
        }
    }

    for block_idx in entry_blocks {
        reachable[block_idx] = true;
        worklist.push(block_idx);
    }

    while let Some(block_idx) = worklist.pop() {
        for &succ in &cfg.blocks[block_idx].succs {
            if !reachable[succ] {
                reachable[succ] = true;
                worklist.push(succ);
            }
        }
    }

    let mut deleted = vec![false; insns.len()];
    for (block_idx, block) in cfg.blocks.iter().enumerate() {
        if reachable[block_idx] {
            continue;
        }
        for slot in &mut deleted[block.start..block.end] {
            *slot = true;
        }
    }

    eliminate_marked_insns(insns, &deleted)
}

/// Remove all `ja +0` no-op instructions from the instruction stream.
pub fn eliminate_nops(insns: &[BpfInsn]) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    let mut deleted = vec![false; insns.len()];
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = &insns[pc];
        let width = insn_width(insn);
        if insn.is_ja() && insn.off == 0 {
            for slot in &mut deleted[pc..pc + width] {
                *slot = true;
            }
        }
        pc += width;
    }

    eliminate_marked_insns(insns, &deleted)
}

fn eliminate_marked_insns(
    insns: &[BpfInsn],
    deleted: &[bool],
) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    if insns.is_empty() || !deleted.iter().any(|&flag| flag) {
        return None;
    }

    let orig_len = insns.len();
    let mut new_insns = Vec::with_capacity(orig_len);
    let mut addr_map = vec![0usize; orig_len + 1];
    let mut pc = 0usize;

    while pc < orig_len {
        let insn = &insns[pc];
        let width = insn_width(insn);
        let new_pc = new_insns.len();

        if deleted[pc] {
            for j in 0..width {
                addr_map[pc + j] = new_pc;
            }
            pc += width;
            continue;
        }

        addr_map[pc] = new_pc;
        new_insns.push(*insn);
        if width == 2 && pc + 1 < orig_len {
            addr_map[pc + 1] = new_insns.len();
            new_insns.push(insns[pc + 1]);
        }
        pc += width;
    }
    addr_map[orig_len] = new_insns.len();

    fixup_surviving_branches(&mut new_insns, insns, &addr_map, deleted);
    Some((new_insns, addr_map))
}

fn fixup_surviving_branches(
    new_insns: &mut [BpfInsn],
    old_insns: &[BpfInsn],
    addr_map: &[usize],
    deleted: &[bool],
) {
    let old_n = old_insns.len();
    let mut old_pc = 0usize;

    while old_pc < old_n {
        let insn = &old_insns[old_pc];
        if !deleted[old_pc] {
            if insn.is_call() && insn.src_reg() == 1 {
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
                let old_target = (old_pc as i64 + 1 + insn.off as i64) as usize;
                if old_target <= old_n {
                    let new_pc = addr_map[old_pc];
                    let new_target = addr_map[old_target];
                    if new_pc < new_insns.len() && new_insns[new_pc].is_jmp_class() {
                        let new_off = new_target as i64 - (new_pc as i64 + 1);
                        new_insns[new_pc].off = new_off as i16;
                    }
                }
            }
        }

        old_pc += insn_width(insn);
    }
}

fn insn_width(insn: &BpfInsn) -> usize {
    if insn.is_ldimm64() {
        2
    } else {
        1
    }
}

// ── Kinsn call emission ────────────────────────────────────────────

/// Emit a packed-ABI kinsn call using a sidecar pseudo-insn immediately
/// before the kinsn CALL. The result register is part of `payload`, so no
/// extra `mov dst, r0` is emitted here.
pub fn emit_packed_kinsn_call_with_off(
    payload: u64,
    kinsn_btf_id: i32,
    kinsn_off: i16,
) -> Vec<BpfInsn> {
    vec![
        BpfInsn::kinsn_sidecar(payload),
        BpfInsn::call_kinsn_with_off(kinsn_btf_id, kinsn_off),
    ]
}

/// Ensure `btf_fd` is present in the program's REJIT `fd_array` list and
/// return the 1-based slot number to encode in `CALL.off`.
pub fn ensure_btf_fd_slot(program: &mut BpfProgram, btf_fd: i32) -> i16 {
    if let Some(idx) = program.required_btf_fds.iter().position(|&fd| fd == btf_fd) {
        return idx as i16 + 1;
    }

    program.required_btf_fds.push(btf_fd);
    program.required_btf_fds.len() as i16
}
// ── Tests ──────────────────────────────────────────────────────────

#[cfg(test)]
mod tests {
    use super::*;

    /// Iterator over BPF instructions that skips LDIMM64 second slots.
    fn insn_iter_skip_ldimm64(insns: &[BpfInsn]) -> InsnIterSkipLdimm64<'_> {
        InsnIterSkipLdimm64 { insns, pc: 0 }
    }

    struct InsnIterSkipLdimm64<'a> {
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
            self.pc = if insn.is_ldimm64() { pc + 2 } else { pc + 1 };
            Some((pc, insn))
        }
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        }
    }

    #[test]
    fn test_fixup_all_branches_forward_jump() {
        // Old: [0] JA +1  [1] nop  [2] exit
        // New (insert at 1): [0] JA +1  [1] new_insn  [2] nop  [3] exit
        // addr_map: 0->0, 1->2, 2->3, sentinel 3->4
        let old_insns = vec![BpfInsn::ja(1), BpfInsn::nop(), exit_insn()];
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
    fn test_emit_packed_kinsn_call_with_module_off() {
        let payload = 0x12345;
        let insns = emit_packed_kinsn_call_with_off(payload, 1234, 2);

        assert_eq!(insns.len(), 2);
        assert!(insns[0].is_kinsn_sidecar());
        assert_eq!(insns[0].dst_reg(), 0x5);
        assert_eq!(insns[0].off, 0x1234);
        assert_eq!(insns[0].imm, 0);
        assert!(insns[1].is_call());
        assert_eq!(insns[1].imm, 1234);
        assert_eq!(insns[1].off, 2);
    }

    #[test]
    fn test_emit_packed_kinsn_call_wide_payload() {
        let payload = 0xabcde12345;
        let insns = emit_packed_kinsn_call_with_off(payload, 5555, 0);

        assert_eq!(insns.len(), 2);
        assert!(insns[0].is_kinsn_sidecar());
        assert_eq!(insns[0].dst_reg(), 0x5);
        assert_eq!(insns[0].off, 0x1234);
        assert_eq!(insns[0].imm, 0xabcde);
        assert!(insns[1].is_call());
        assert_eq!(insns[1].imm, 5555);
    }

    #[test]
    fn test_insn_iter_skip_ldimm64() {
        let ldimm64_lo = BpfInsn {
            code: BPF_LD | BPF_DW | BPF_IMM,
            regs: BpfInsn::make_regs(0, 0),
            off: 0,
            imm: 42,
        };
        let ldimm64_hi = BpfInsn {
            code: 0,
            regs: 0,
            off: 0,
            imm: 0,
        };
        let insns = vec![
            BpfInsn::mov64_imm(0, 1), // pc=0
            ldimm64_lo,               // pc=1 (2-slot)
            ldimm64_hi,               // pc=2 (second slot, skipped)
            exit_insn(),              // pc=3
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
