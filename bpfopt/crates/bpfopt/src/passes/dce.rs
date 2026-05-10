// SPDX-License-Identifier: MIT
// Dead register definition elimination after constant propagation.

use std::collections::HashSet;

use crate::analysis::{CFGAnalysis, CFGResult, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::rewrite::{compose_addr_maps, fixup_all_branches};

/// Dead code elimination pass.
///
/// Scope:
/// - remove side-effect-free register definitions whose results are dead
pub struct DcePass;

impl BpfPass for DcePass {
    fn name(&self) -> &str {
        "dce"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec![]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let Some((final_insns, final_addr_map)) = eliminate_dead_register_defs(&program.insns)
        else {
            return Ok(PassResult::unchanged(self.name()));
        };

        let sites_applied = program.insns.len() - final_insns.len();
        let mut diagnostics = Vec::new();
        if sites_applied > 0 {
            diagnostics.push(format!("removed {} dead-def insns", sites_applied));
        }

        program.insns = final_insns;
        remap_btf_metadata(program, &final_addr_map)?;
        program.remap_annotations(&final_addr_map);
        Ok(PassResult {
            pass_name: self.name().into(),
            sites_applied,
            sites_skipped: vec![],
            diagnostics,
            ..Default::default()
        })
    }
}

pub fn eliminate_unreachable_blocks(insns: &[BpfInsn]) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    if insns.is_empty() {
        return None;
    }

    let cfg = CFGAnalysis.run(&BpfProgram::new(insns.to_vec()));
    eliminate_unreachable_blocks_with_cfg(insns, &cfg)
}

fn eliminate_unreachable_blocks_with_cfg(
    insns: &[BpfInsn],
    cfg: &CFGResult,
) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    if insns.is_empty() || cfg.blocks.is_empty() {
        return None;
    }

    let mut reachable = vec![false; cfg.blocks.len()];
    let mut worklist = Vec::new();

    if !cfg.subprogs.is_empty() {
        let main_entry_block = cfg.insn_to_block[cfg.subprogs[0].start];
        reachable[main_entry_block] = true;
        worklist.push(main_entry_block);
    }

    let subprog_entry_pcs: HashSet<usize> = cfg
        .subprogs
        .iter()
        .filter(|s| s.start < insns.len())
        .map(|s| s.start)
        .collect();

    loop {
        while let Some(block_idx) = worklist.pop() {
            for &succ in &cfg.blocks[block_idx].succs {
                if !reachable[succ] {
                    reachable[succ] = true;
                    worklist.push(succ);
                }
            }
        }

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
                pc += insn_width(insn);
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

fn eliminate_marked_insns(
    insns: &[BpfInsn],
    deleted: &[bool],
) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    if insns.is_empty() || !deleted.iter().any(|&flag| flag) {
        return None;
    }
    debug_assert_eq!(insns.len(), deleted.len());

    let orig_len = insns.len();
    let deleted = normalize_ldimm64_deletions(insns, deleted);
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

    fixup_all_branches(&mut new_insns, insns, &addr_map);
    Some((new_insns, addr_map))
}

fn normalize_ldimm64_deletions(insns: &[BpfInsn], deleted: &[bool]) -> Vec<bool> {
    let mut normalized = deleted.to_vec();
    let mut pc = 0usize;

    while pc < insns.len() {
        let width = insn_width(&insns[pc]);
        let end = (pc + width).min(insns.len());
        if width == 2 && deleted[pc..end].iter().any(|&flag| flag) {
            for slot in &mut normalized[pc..end] {
                *slot = true;
            }
        }
        pc = end;
    }

    normalized
}

#[cfg(test)]
mod tests {
    use super::*;

    fn pseudo_map_value(dst: u8, imm: i32) -> [BpfInsn; 2] {
        [
            BpfInsn::new(
                BPF_LD | BPF_DW | BPF_IMM,
                BpfInsn::make_regs(dst, BPF_PSEUDO_MAP_VALUE),
                0,
                imm,
            ),
            BpfInsn::new(0, 0, 0, 0x1234),
        ]
    }

    #[test]
    fn test_eliminate_nops_preserves_helper_call_reserved_fields() {
        let insns = vec![BpfInsn::ja(0), BpfInsn::helper_call(5), BpfInsn::exit()];
        let (new_insns, _addr_map) = eliminate_nops(&insns).expect("nop should be removed");

        assert_eq!(new_insns.len(), 2);
        assert!(new_insns[0].is_call());
        assert_eq!(new_insns[0].src_reg(), 0);
        assert_eq!(new_insns[0].dst_reg(), 0);
        assert_eq!(new_insns[0].off, 0);
        assert_eq!(new_insns[0].imm, 5);
    }

    #[test]
    fn test_eliminate_marked_insns_deletes_ldimm64_when_second_slot_is_marked() {
        let map_value = pseudo_map_value(1, 9);
        let insns = vec![BpfInsn::ja(2), map_value[0], map_value[1], BpfInsn::exit()];
        let deleted = vec![false, false, true, false];

        let (new_insns, addr_map) =
            eliminate_marked_insns(&insns, &deleted).expect("LD_IMM64 pair should be deleted");

        assert_eq!(new_insns, vec![BpfInsn::ja(0), BpfInsn::exit()]);
        assert_eq!(addr_map[1], 1);
        assert_eq!(addr_map[2], 1);
        assert!(
            !new_insns
                .iter()
                .any(|insn| insn.is_ldimm64() || insn.src_reg() == BPF_PSEUDO_MAP_VALUE),
            "DCE must not leave either half of a PSEUDO_MAP_VALUE LD_IMM64"
        );
    }

    #[test]
    fn test_eliminate_dead_register_defs_cascades_across_overwrites() {
        let insns = vec![
            BpfInsn::mov64_imm(1, 1),
            BpfInsn::mov64_imm(1, 2),
            BpfInsn::mov64_imm(0, 7),
            BpfInsn::exit(),
        ];

        let (new_insns, _addr_map) =
            eliminate_dead_register_defs(&insns).expect("dead defs should be removed");

        assert_eq!(new_insns, vec![BpfInsn::mov64_imm(0, 7), BpfInsn::exit(),]);
    }
}
