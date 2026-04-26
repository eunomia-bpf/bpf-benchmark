// SPDX-License-Identifier: MIT
// Shared utilities for BPF rewrite passes.
//
// Contains branch fixup, kinsn call emission, and instruction iteration
// helpers that are used by multiple passes.

use std::collections::HashSet;

use crate::analysis::{CFGAnalysis, CFGResult, LivenessAnalysis};
use crate::insn::*;
use crate::pass::{Analysis, BpfProgram};

const BPF_FUNC_TAIL_CALL: i32 = 12;
const BPF_TAIL_CALL: u8 = 0xf0;

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
        let new_pc = addr_map[old_pc];
        let next_old_pc = old_pc + insn_width(insn);
        let survived_unchanged = new_pc < new_insns.len()
            && next_old_pc < addr_map.len()
            && addr_map[next_old_pc] > new_pc
            && new_insns.get(new_pc).copied() == Some(*insn);

        if insn.is_ldimm64_pseudo_func() {
            let old_target = (old_pc as i64 + 1 + insn.imm as i64) as usize;
            if old_target < old_n
                && survived_unchanged
                && new_pc < new_insns.len()
                && new_insns[new_pc].is_ldimm64_pseudo_func()
            {
                let new_target = addr_map[old_target];
                let new_imm = new_target as i64 - (new_pc as i64 + 1);
                new_insns[new_pc].imm = new_imm as i32;
            }
        } else if insn.is_call() && insn.src_reg() == 1 {
            // BPF pseudo-call: fix up imm (pc-relative offset to target subprog).
            let old_target = (old_pc as i64 + 1 + insn.imm as i64) as usize;
            if old_target < old_n {
                let new_target = addr_map[old_target];
                if survived_unchanged && new_insns[new_pc].is_call() {
                    let new_imm = new_target as i64 - (new_pc as i64 + 1);
                    new_insns[new_pc].imm = new_imm as i32;
                }
            }
        } else if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
            let old_target = (old_pc as i64 + 1 + insn.off as i64) as usize;
            if old_target <= old_n {
                let new_target = addr_map[old_target];
                if survived_unchanged
                    && new_insns[new_pc].is_jmp_class()
                    && !new_insns[new_pc].is_call()
                    && !new_insns[new_pc].is_exit()
                {
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

/// Return the exclusive prefix end before which instruction-count changes must
/// be avoided to preserve tail-call poke descriptor indices during REJIT.
pub fn tail_call_protected_prefix_end(insns: &[BpfInsn]) -> Option<usize> {
    last_tail_call_pc(insns).map(|pc| pc + insn_width(&insns[pc]))
}

fn last_tail_call_pc(insns: &[BpfInsn]) -> Option<usize> {
    let mut last = None;
    let mut pc = 0usize;
    while pc < insns.len() {
        if is_tail_call_insn(&insns[pc]) {
            last = Some(pc);
        }
        pc += insn_width(&insns[pc]);
    }
    last
}

fn is_tail_call_insn(insn: &BpfInsn) -> bool {
    insn.code == (BPF_JMP | BPF_TAIL_CALL)
        || (insn.is_call() && insn.src_reg() == 0 && insn.imm == BPF_FUNC_TAIL_CALL)
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
///
/// Subprog entries are only considered reachable if there exists a reachable
/// pseudo-call that targets them. This prevents orphaned subprogs (whose only
/// call site was in a dead block) from surviving and triggering verifier
/// "unreachable insn" errors.
pub fn eliminate_unreachable_blocks_with_cfg(
    insns: &[BpfInsn],
    cfg: &CFGResult,
) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    if insns.is_empty() || cfg.blocks.is_empty() {
        return None;
    }

    let mut reachable = vec![false; cfg.blocks.len()];
    let mut worklist = Vec::new();

    // Seed with main entry (the first subprog, which always starts at 0).
    if !cfg.subprogs.is_empty() {
        let main_entry_block = cfg.insn_to_block[cfg.subprogs[0].start];
        reachable[main_entry_block] = true;
        worklist.push(main_entry_block);
    }

    // Collect all subprog entry PCs for quick lookup.
    let subprog_entry_pcs: HashSet<usize> = cfg
        .subprogs
        .iter()
        .filter(|s| s.start < insns.len())
        .map(|s| s.start)
        .collect();

    // Iterative reachability: propagate through CFG edges, and when a
    // reachable block contains a pseudo-call, seed the target subprog entry.
    loop {
        // Drain the worklist, propagating through CFG successors.
        while let Some(block_idx) = worklist.pop() {
            for &succ in &cfg.blocks[block_idx].succs {
                if !reachable[succ] {
                    reachable[succ] = true;
                    worklist.push(succ);
                }
            }
        }

        // Find pseudo-calls in reachable blocks that target not-yet-reachable
        // subprog entries.
        let mut found_new = false;
        for (block_idx, block) in cfg.blocks.iter().enumerate() {
            if !reachable[block_idx] {
                continue;
            }
            let mut pc = block.start;
            while pc < block.end {
                let insn = &insns[pc];
                if insn.is_ldimm64_pseudo_func() {
                    let target = (pc as i64 + 1 + insn.imm as i64) as usize;
                    if target < insns.len() && subprog_entry_pcs.contains(&target) {
                        let target_block = cfg.insn_to_block[target];
                        if !reachable[target_block] {
                            reachable[target_block] = true;
                            worklist.push(target_block);
                            found_new = true;
                        }
                    }
                } else if insn.is_call() && insn.src_reg() == 1 {
                    // BPF pseudo-call: target = pc + 1 + imm
                    let target = (pc as i64 + 1 + insn.imm as i64) as usize;
                    if target < insns.len() && subprog_entry_pcs.contains(&target) {
                        let target_block = cfg.insn_to_block[target];
                        if !reachable[target_block] {
                            reachable[target_block] = true;
                            worklist.push(target_block);
                            found_new = true;
                        }
                    }
                }
                pc = if insn.is_ldimm64() { pc + 2 } else { pc + 1 };
            }
        }

        if !found_new {
            break;
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

/// Remove side-effect-free register definitions whose result is dead.
///
/// This runs to a fixed point because deleting one dead definition can expose
/// earlier definitions that were only live through the removed instruction.
pub fn eliminate_dead_register_defs(insns: &[BpfInsn]) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    if insns.is_empty() {
        return None;
    }

    let mut final_insns = insns.to_vec();
    let mut final_addr_map: Option<Vec<usize>> = None;

    while let Some((cleaned_insns, cleanup_map)) = eliminate_dead_register_defs_once(&final_insns) {
        final_addr_map = Some(match final_addr_map.take() {
            Some(existing) => compose_addr_maps(&existing, &cleanup_map),
            None => cleanup_map,
        });
        final_insns = cleaned_insns;
    }

    final_addr_map.map(|addr_map| (final_insns, addr_map))
}

/// Tail-call-aware dead-def elimination.
///
/// Dead defs before `protected_prefix_end` are neutralized in place instead of
/// deleted so later tail-call helper PCs keep the same indices during REJIT.
pub fn eliminate_dead_register_defs_tail_safe(
    insns: &[BpfInsn],
    protected_prefix_end: usize,
) -> Option<(Vec<BpfInsn>, Vec<usize>, usize, usize)> {
    if insns.is_empty() {
        return None;
    }

    let mut final_insns = insns.to_vec();
    let mut final_addr_map: Option<Vec<usize>> = None;
    let mut total_neutralized = 0usize;
    let mut total_deleted = 0usize;

    while let Some((next_insns, cleanup_map, neutralized, deleted)) =
        eliminate_dead_register_defs_once_tail_safe(&final_insns, protected_prefix_end)
    {
        total_neutralized += neutralized;
        total_deleted += deleted;
        final_addr_map = Some(match final_addr_map.take() {
            Some(existing) => compose_addr_maps(&existing, &cleanup_map),
            None => cleanup_map,
        });
        final_insns = next_insns;
    }

    final_addr_map.map(|addr_map| (final_insns, addr_map, total_neutralized, total_deleted))
}

fn eliminate_dead_register_defs_once(insns: &[BpfInsn]) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    let liveness = LivenessAnalysis.run(&BpfProgram::new(insns.to_vec()));
    let mut deleted = vec![false; insns.len()];
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = &insns[pc];
        let width = insn_width(insn);

        if is_removable_dead_def(insn, liveness.live_out.get(pc)) {
            for slot in &mut deleted[pc..pc + width] {
                *slot = true;
            }
        }

        pc += width;
    }

    eliminate_marked_insns(insns, &deleted)
}

fn eliminate_dead_register_defs_once_tail_safe(
    insns: &[BpfInsn],
    protected_prefix_end: usize,
) -> Option<(Vec<BpfInsn>, Vec<usize>, usize, usize)> {
    let liveness = LivenessAnalysis.run(&BpfProgram::new(insns.to_vec()));
    let mut deleted = vec![false; insns.len()];
    let mut replacements = Vec::new();
    let mut neutralized = 0usize;
    let mut deleted_count = 0usize;
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = &insns[pc];
        let width = insn_width(insn);

        if is_removable_dead_def(insn, liveness.live_out.get(pc)) {
            if pc < protected_prefix_end {
                replacements.push((pc, neutralize_dead_def_span(insn)));
                neutralized += width;
            } else {
                for slot in &mut deleted[pc..pc + width] {
                    *slot = true;
                }
                deleted_count += width;
            }
        }

        pc += width;
    }

    if replacements.is_empty() && deleted_count == 0 {
        return None;
    }

    let (mut new_insns, addr_map) = if deleted_count > 0 {
        eliminate_marked_insns(insns, &deleted)
            .expect("tail-safe dead-def elimination marked instructions for deletion")
    } else {
        (insns.to_vec(), identity_addr_map(insns.len()))
    };

    for (old_pc, replacement) in replacements {
        let new_pc = addr_map[old_pc];
        for (idx, new_insn) in replacement.into_iter().enumerate() {
            new_insns[new_pc + idx] = new_insn;
        }
    }

    Some((new_insns, addr_map, neutralized, deleted_count))
}

fn is_removable_dead_def(insn: &BpfInsn, live_out: Option<&HashSet<u8>>) -> bool {
    let Some(live_out) = live_out else {
        return false;
    };
    let is_self_move = matches!(insn.class(), BPF_ALU | BPF_ALU64)
        && bpf_op(insn.code) == BPF_MOV
        && bpf_src(insn.code) == BPF_X
        && insn.dst_reg() == insn.src_reg();
    if is_self_move {
        return false;
    }

    match insn.class() {
        BPF_ALU | BPF_ALU64 | BPF_LDX => !live_out.contains(&insn.dst_reg()),
        BPF_LD if insn.is_ldimm64() && !insn.is_ldimm64_pseudo_func() => {
            !live_out.contains(&insn.dst_reg())
        }
        _ => false,
    }
}

fn neutralize_dead_def_span(insn: &BpfInsn) -> Vec<BpfInsn> {
    vec![BpfInsn::mov64_reg(insn.dst_reg(), insn.dst_reg()); insn_width(insn)]
}

fn identity_addr_map(len: usize) -> Vec<usize> {
    (0..=len).collect()
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
            if insn.is_ldimm64_pseudo_func() {
                let old_target = (old_pc as i64 + 1 + insn.imm as i64) as usize;
                if old_target < old_n {
                    let new_pc = addr_map[old_pc];
                    let new_target = addr_map[old_target];
                    if new_pc < new_insns.len() && new_insns[new_pc].is_ldimm64_pseudo_func() {
                        let new_imm = new_target as i64 - (new_pc as i64 + 1);
                        new_insns[new_pc].imm = new_imm as i32;
                    }
                }
            } else if insn.is_call() && insn.src_reg() == 1 {
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
                    if new_pc < new_insns.len()
                        && new_insns[new_pc].is_jmp_class()
                        && !new_insns[new_pc].is_call()
                        && !new_insns[new_pc].is_exit()
                    {
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

    fn call_helper(imm: i32) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_CALL,
            regs: BpfInsn::make_regs(0, 0),
            off: 0,
            imm,
        }
    }

    fn pseudo_func_ref(dst: u8, imm: i32) -> [BpfInsn; 2] {
        [
            BpfInsn {
                code: BPF_LD | BPF_DW | BPF_IMM,
                regs: BpfInsn::make_regs(dst, BPF_PSEUDO_FUNC),
                off: 0,
                imm,
            },
            BpfInsn {
                code: 0,
                regs: 0,
                off: 0,
                imm: 0,
            },
        ]
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
    fn test_fixup_all_branches_does_not_write_branch_off_into_helper_call() {
        // Old pc 0 is a branch that gets deleted by a rewrite. addr_map[0] then
        // points at the next surviving insn, which happens to be a helper call.
        // Branch fixup must not treat that helper call like a jump and scribble
        // a non-zero off field into its reserved bits.
        let old_insns = vec![BpfInsn::ja(1), BpfInsn::nop(), call_helper(5), exit_insn()];
        let mut new_insns = vec![call_helper(5), exit_insn()];
        let addr_map = vec![0, 0, 0, 1, 2];

        fixup_all_branches(&mut new_insns, &old_insns, &addr_map);

        assert!(new_insns[0].is_call());
        assert_eq!(new_insns[0].src_reg(), 0);
        assert_eq!(new_insns[0].dst_reg(), 0);
        assert_eq!(new_insns[0].off, 0);
        assert_eq!(new_insns[0].imm, 5);
    }

    #[test]
    fn test_fixup_all_branches_does_not_write_deleted_branch_target_into_surviving_branch() {
        let old_insns = vec![
            BpfInsn::ja(1),
            BpfInsn::nop(),
            BpfInsn::ja(1),
            BpfInsn::nop(),
            exit_insn(),
        ];
        let mut new_insns = vec![BpfInsn::ja(1), BpfInsn::nop(), exit_insn()];
        let addr_map = vec![0, 0, 0, 1, 2, 3];

        fixup_all_branches(&mut new_insns, &old_insns, &addr_map);

        assert!(new_insns[0].is_ja());
        assert_eq!(new_insns[0].off, 1);
    }

    #[test]
    fn test_fixup_all_branches_rewrites_pseudo_func_target_after_growth() {
        let callback = pseudo_func_ref(2, 3);
        let old_insns = vec![
            callback[0],
            callback[1],
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
            BpfInsn::mov64_reg(0, 1),
            exit_insn(),
        ];
        let mut new_insns = vec![
            callback[0],
            callback[1],
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
            BpfInsn::nop(),
            BpfInsn::mov64_reg(0, 1),
            exit_insn(),
        ];
        let addr_map = vec![0, 1, 2, 3, 5, 6, 7];

        fixup_all_branches(&mut new_insns, &old_insns, &addr_map);

        assert!(new_insns[0].is_ldimm64_pseudo_func());
        assert_eq!(new_insns[0].imm, 4);
        assert_eq!(0usize + 1 + new_insns[0].imm as usize, 5);
    }

    #[test]
    fn test_eliminate_nops_preserves_helper_call_reserved_fields() {
        let insns = vec![BpfInsn::ja(0), call_helper(5), exit_insn()];
        let (new_insns, _addr_map) = eliminate_nops(&insns).expect("nop should be removed");

        assert_eq!(new_insns.len(), 2);
        assert!(new_insns[0].is_call());
        assert_eq!(new_insns[0].src_reg(), 0);
        assert_eq!(new_insns[0].dst_reg(), 0);
        assert_eq!(new_insns[0].off, 0);
        assert_eq!(new_insns[0].imm, 5);
    }

    #[test]
    fn test_tail_call_protected_prefix_end_tracks_last_tail_call() {
        let insns = vec![
            BpfInsn::mov64_imm(1, 1),
            call_helper(12),
            BpfInsn::mov64_imm(2, 2),
            call_helper(12),
            exit_insn(),
        ];

        assert_eq!(tail_call_protected_prefix_end(&insns), Some(4));
    }

    #[test]
    fn test_eliminate_dead_register_defs_tail_safe_neutralizes_prefix_defs() {
        let insns = vec![
            BpfInsn::mov64_imm(8, 1),
            BpfInsn::mov64_imm(8, 2),
            call_helper(12),
            exit_insn(),
        ];

        let (new_insns, addr_map, neutralized, deleted) =
            eliminate_dead_register_defs_tail_safe(&insns, 3)
                .expect("tail-safe DCE should rewrite dead defs");

        assert_eq!(neutralized, 2);
        assert_eq!(deleted, 0);
        assert_eq!(addr_map, vec![0, 1, 2, 3, 4]);
        assert_eq!(
            new_insns,
            vec![
                BpfInsn::mov64_reg(8, 8),
                BpfInsn::mov64_reg(8, 8),
                call_helper(12),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn test_eliminate_dead_register_defs_cascades_across_overwrites() {
        let insns = vec![
            BpfInsn::mov64_imm(1, 1),
            BpfInsn::mov64_imm(1, 2),
            BpfInsn::mov64_imm(0, 7),
            exit_insn(),
        ];

        let (new_insns, _addr_map) =
            eliminate_dead_register_defs(&insns).expect("dead defs should be removed");

        assert_eq!(new_insns, vec![BpfInsn::mov64_imm(0, 7), exit_insn(),]);
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
