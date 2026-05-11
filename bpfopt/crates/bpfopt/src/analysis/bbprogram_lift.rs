// SPDX-License-Identifier: MIT
//! Lift linear BPF bytecode into BBProgram.

use std::collections::{BTreeMap, BTreeSet};
use std::sync::Arc;

use crate::analysis::{
    BBProgram, Block, BlockId, BtfMetadataMap, FrameId, InsnSite, Terminator, VerifierOracle,
};
use crate::insn::*;
use crate::pass::KinsnRegistry;

pub fn lift(insns: &[BpfInsn], oracle: Option<VerifierOracle>) -> anyhow::Result<BBProgram> {
    lift_with_kinsn_registry(insns, oracle, Arc::new(KinsnRegistry::default()))
}

pub fn lift_with_kinsn_registry(
    insns: &[BpfInsn],
    oracle: Option<VerifierOracle>,
    kinsn_reg: Arc<KinsnRegistry>,
) -> anyhow::Result<BBProgram> {
    if insns.is_empty() {
        return BBProgram::new(
            Vec::new(),
            BlockId(0),
            oracle,
            BTreeMap::new(),
            kinsn_reg,
            BTreeMap::new(),
            BTreeMap::new(),
        );
    }

    let boundaries = instruction_boundaries(insns)?;
    let mut block_starts = collect_block_starts(insns, &boundaries)?;
    block_starts.insert(0);
    let block_starts = block_starts.into_iter().collect::<Vec<_>>();
    let pc_to_block = pc_to_block_map(insns.len(), &block_starts);
    let subprog_starts = collect_subprog_starts(insns, &boundaries)?;
    let frame_by_pc = frame_by_pc_map(insns.len(), &subprog_starts);

    let mut blocks = Vec::with_capacity(block_starts.len());
    let mut btf = BtfMetadataMap::new();
    let mut ldimm64_second_slots = BTreeMap::new();
    let mut pc_relative_ldimm64_targets = BTreeMap::new();

    for (block_idx, &start_pc) in block_starts.iter().enumerate() {
        let end_pc = block_starts
            .get(block_idx + 1)
            .copied()
            .unwrap_or(insns.len());
        let id = BlockId(block_idx);
        let frame = FrameId(frame_by_pc.get(start_pc).copied().unwrap_or(0));
        let mut block = Block {
            id,
            insns: Vec::new(),
            terminator: Terminator::End,
            frame,
        };

        let mut pc = start_pc;
        while pc < end_pc {
            let insn = insns[pc];
            if is_block_terminator(&insn) {
                block.terminator = lift_terminator(insns, pc, end_pc, &pc_to_block)?;
                let site = InsnSite {
                    block: id,
                    idx: block.insns.len(),
                };
                btf.insert(site, pc);
                pc += 1;
                if pc != end_pc {
                    anyhow::bail!("terminator at pc {pc} did not end block {:?}", id);
                }
                break;
            }

            let site = InsnSite {
                block: id,
                idx: block.insns.len(),
            };
            btf.insert(site, pc);
            block.insns.push(insn);
            if insn.is_ldimm64() {
                let second_pc = pc + 1;
                let second = *insns
                    .get(second_pc)
                    .ok_or_else(|| anyhow::anyhow!("LD_IMM64 at pc {pc} is missing second slot"))?;
                ldimm64_second_slots.insert(site, second);
                if insn.is_ldimm64_pseudo_func() {
                    let target = target_block_for_pc_relative_imm(
                        pc,
                        i64::from(insn.imm),
                        &pc_to_block,
                        insns.len(),
                    )?;
                    pc_relative_ldimm64_targets.insert(site, target);
                }
                pc += 2;
            } else {
                pc += 1;
            }
        }

        if matches!(block.terminator, Terminator::End) && end_pc < insns.len() {
            block.terminator = Terminator::Fallthrough {
                next: pc_to_block[end_pc],
            };
        }
        blocks.push(block);
    }

    BBProgram::new(
        blocks,
        BlockId(0),
        oracle,
        btf,
        kinsn_reg,
        ldimm64_second_slots,
        pc_relative_ldimm64_targets,
    )
}

fn instruction_boundaries(insns: &[BpfInsn]) -> anyhow::Result<Vec<bool>> {
    let mut boundaries = vec![false; insns.len() + 1];
    let mut pc = 0usize;
    while pc < insns.len() {
        boundaries[pc] = true;
        let width = insn_width(&insns[pc]);
        if pc + width > insns.len() {
            anyhow::bail!(
                "instruction at pc {pc} exceeds program length {}",
                insns.len()
            );
        }
        pc += width;
    }
    boundaries[insns.len()] = true;
    if pc != insns.len() {
        anyhow::bail!(
            "instruction walk ended at pc {pc}, expected {}",
            insns.len()
        );
    }
    Ok(boundaries)
}

fn collect_block_starts(insns: &[BpfInsn], boundaries: &[bool]) -> anyhow::Result<BTreeSet<usize>> {
    let mut starts = BTreeSet::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = insns[pc];
        let width = insn_width(&insn);
        let next_pc = pc + width;

        if insn.is_ldimm64_pseudo_func() {
            starts.insert(target_pc_for_pc_relative_imm(
                pc,
                i64::from(insn.imm),
                insns.len(),
            )?);
        } else if is_block_terminator(&insn) {
            if !insn.is_exit() {
                if let Some(target) = branch_or_call_target_pc(&insn, pc)? {
                    starts.insert(target);
                }
            }
            if next_pc < insns.len() {
                starts.insert(next_pc);
            }
        } else if insn.is_cond_jmp() || insn.is_ja() {
            if let Some(target) = branch_or_call_target_pc(&insn, pc)? {
                starts.insert(target);
            }
            if next_pc < insns.len() {
                starts.insert(next_pc);
            }
        }

        pc = next_pc;
    }

    for &start in &starts {
        if start > insns.len() {
            anyhow::bail!(
                "block start pc {start} is outside program length {}",
                insns.len()
            );
        }
        if !boundaries[start] {
            anyhow::bail!("block start pc {start} is not an instruction boundary");
        }
    }
    Ok(starts)
}

fn collect_subprog_starts(insns: &[BpfInsn], boundaries: &[bool]) -> anyhow::Result<Vec<usize>> {
    let mut starts = BTreeSet::from([0usize]);
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = insns[pc];
        if insn.is_ldimm64_pseudo_func() || is_pseudo_call(&insn) {
            starts.insert(target_pc_for_pc_relative_imm(
                pc,
                i64::from(insn.imm),
                insns.len(),
            )?);
        }
        pc += insn_width(&insn);
    }

    let starts = starts.into_iter().collect::<Vec<_>>();
    for &start in &starts {
        if start >= insns.len() {
            anyhow::bail!(
                "subprogram start pc {start} is outside program length {}",
                insns.len()
            );
        }
        if !boundaries[start] {
            anyhow::bail!("subprogram start pc {start} is not an instruction boundary");
        }
    }
    Ok(starts)
}

fn pc_to_block_map(program_len: usize, block_starts: &[usize]) -> Vec<BlockId> {
    let mut pc_to_block = vec![BlockId(0); program_len + 1];
    for (idx, &start) in block_starts.iter().enumerate() {
        let end = block_starts.get(idx + 1).copied().unwrap_or(program_len);
        for slot in pc_to_block.iter_mut().take(end).skip(start) {
            *slot = BlockId(idx);
        }
    }
    pc_to_block[program_len] = block_starts
        .iter()
        .position(|&start| start == program_len)
        .map(BlockId)
        .unwrap_or(BlockId(block_starts.len()));
    pc_to_block
}

fn frame_by_pc_map(program_len: usize, subprog_starts: &[usize]) -> Vec<usize> {
    let mut frame_by_pc = vec![0usize; program_len];
    for (frame, &start) in subprog_starts.iter().enumerate() {
        let end = subprog_starts
            .get(frame + 1)
            .copied()
            .unwrap_or(program_len);
        for slot in &mut frame_by_pc[start..end] {
            *slot = frame;
        }
    }
    frame_by_pc
}

fn lift_terminator(
    insns: &[BpfInsn],
    pc: usize,
    block_end: usize,
    pc_to_block: &[BlockId],
) -> anyhow::Result<Terminator> {
    let insn = insns[pc];
    if insn.is_exit() {
        return Ok(Terminator::Exit { insn });
    }
    if is_pseudo_call(&insn) {
        let callee =
            target_block_for_pc_relative_imm(pc, i64::from(insn.imm), pc_to_block, insns.len())?;
        let return_pc = pc + 1;
        if return_pc >= insns.len() {
            anyhow::bail!("pseudo_call at pc {pc} has no return instruction");
        }
        return Ok(Terminator::Call {
            call: insn,
            callee,
            return_to: pc_to_block[return_pc],
        });
    }
    if insn.is_ja() {
        let target_pc = branch_or_call_target_pc(&insn, pc)?
            .ok_or_else(|| anyhow::anyhow!("JA at pc {pc} has no target"))?;
        return Ok(Terminator::Jump {
            insn,
            target: pc_to_block[target_pc],
        });
    }
    if insn.is_cond_jmp() {
        let target_pc = branch_or_call_target_pc(&insn, pc)?
            .ok_or_else(|| anyhow::anyhow!("conditional branch at pc {pc} has no target"))?;
        let fallthrough_pc = pc + 1;
        if fallthrough_pc >= insns.len() {
            anyhow::bail!("conditional branch at pc {pc} has no fallthrough instruction");
        }
        return Ok(Terminator::CondBranch {
            cond: insn,
            taken: pc_to_block[target_pc],
            fallthrough: pc_to_block[fallthrough_pc],
        });
    }

    if block_end < insns.len() {
        Ok(Terminator::Fallthrough {
            next: pc_to_block[block_end],
        })
    } else {
        Ok(Terminator::End)
    }
}

fn is_block_terminator(insn: &BpfInsn) -> bool {
    insn.is_exit() || insn.is_ja() || insn.is_cond_jmp() || is_pseudo_call(insn)
}

fn is_pseudo_call(insn: &BpfInsn) -> bool {
    insn.is_call() && insn.src_reg() == BPF_PSEUDO_CALL
}

fn branch_or_call_target_pc(insn: &BpfInsn, pc: usize) -> anyhow::Result<Option<usize>> {
    if is_pseudo_call(insn) {
        return Ok(Some(target_pc_for_pc_relative_imm(
            pc,
            i64::from(insn.imm),
            usize::MAX,
        )?));
    }
    Ok(insn.branch_target_pc(pc))
}

fn target_pc_for_pc_relative_imm(
    pc: usize,
    delta: i64,
    program_len: usize,
) -> anyhow::Result<usize> {
    let Some(target) = relative_branch_target_pc(pc, delta) else {
        anyhow::bail!("pc-relative target from pc {pc} with delta {delta} underflows");
    };
    if target >= program_len {
        anyhow::bail!("pc-relative target {target} is outside program length {program_len}");
    }
    Ok(target)
}

fn target_block_for_pc_relative_imm(
    pc: usize,
    delta: i64,
    pc_to_block: &[BlockId],
    program_len: usize,
) -> anyhow::Result<BlockId> {
    let target = target_pc_for_pc_relative_imm(pc, delta, program_len)?;
    pc_to_block
        .get(target)
        .copied()
        .ok_or_else(|| anyhow::anyhow!("target pc {target} has no block"))
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::analysis::bbprogram_lower::lower;

    fn roundtrip(insns: &[BpfInsn]) {
        let prog = lift(insns, None).expect("lift should succeed");
        let lowered = lower(&prog).expect("lower should succeed");
        assert_eq!(lowered, insns);
    }

    fn block_for_original_pc(prog: &BBProgram, pc: usize) -> BlockId {
        prog.btf
            .iter()
            .find_map(|(site, &old_pc)| (old_pc == pc).then_some(site.block))
            .expect("original pc should map to a block")
    }

    #[test]
    fn lift_treats_ldimm64_as_one_logical_instruction_with_second_slot_metadata() {
        let imm = BpfInsn::ld_imm64(1, 0, 0x1122_3344_5566_7788);
        let insns = vec![imm[0], imm[1], BpfInsn::mov64_reg(0, 1), BpfInsn::exit()];

        let prog = lift(&insns, None).expect("lift should keep LD_IMM64 metadata");

        assert_eq!(prog.blocks[0].insns.len(), 2);
        assert!(prog.ldimm64_second_slots.contains_key(&InsnSite {
            block: BlockId(0),
            idx: 0
        }));
        roundtrip(&insns);
    }

    #[test]
    fn lift_assigns_pseudo_call_target_to_a_subprogram_frame() {
        let insns = vec![
            BpfInsn::pseudo_call_to(0, 3),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::exit(),
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::exit(),
        ];

        let prog = lift(&insns, None).expect("lift should resolve pseudo_call");
        let entry = &prog.blocks[0];
        let Terminator::Call {
            callee, return_to, ..
        } = entry.terminator
        else {
            panic!("entry block should end in a pseudo_call terminator");
        };

        assert_eq!(prog.blocks[callee.0].frame, FrameId(1));
        assert_eq!(prog.blocks[return_to.0].frame, FrameId(0));
        roundtrip(&insns);
    }

    #[test]
    fn lift_preserves_ja32_imm_targets_separately_from_ja_off_targets() {
        let ja32 = vec![
            BpfInsn::new(BPF_JMP32 | BPF_JA, 0, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(1, 1),
            BpfInsn::exit(),
        ];
        let ja = vec![
            BpfInsn::ja(2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(1, 1),
            BpfInsn::exit(),
        ];

        for insns in [&ja32, &ja] {
            let prog = lift(insns, None).expect("lift should resolve unconditional jump");
            let target = block_for_original_pc(&prog, 3);
            let Terminator::Jump { target: actual, .. } = prog.blocks[0].terminator else {
                panic!("entry block should end in a jump");
            };
            assert_eq!(actual, target);
            roundtrip(insns);
        }
    }

    #[test]
    fn lift_resolves_conditional_branch_taken_and_fallthrough_blocks() {
        let insns = vec![
            BpfInsn::jeq_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::exit(),
        ];

        let prog = lift(&insns, None).expect("lift should resolve conditional branch");
        let taken_block = block_for_original_pc(&prog, 2);
        let fallthrough_block = block_for_original_pc(&prog, 1);
        let Terminator::CondBranch {
            taken, fallthrough, ..
        } = prog.blocks[0].terminator
        else {
            panic!("entry block should end in a conditional branch");
        };

        assert_eq!(taken, taken_block);
        assert_eq!(fallthrough, fallthrough_block);
        roundtrip(&insns);
    }

    #[test]
    fn lift_records_exit_as_a_raw_terminator() {
        let insns = vec![BpfInsn::mov64_imm(0, 0), BpfInsn::exit()];

        let prog = lift(&insns, None).expect("lift should keep exit terminator");

        let Terminator::Exit { insn } = prog.blocks[0].terminator else {
            panic!("block should end in exit");
        };
        assert_eq!(insn, BpfInsn::exit());
        roundtrip(&insns);
    }

    #[test]
    fn lift_creates_subprogram_entry_blocks_for_pseudo_func_ldimm64_targets() {
        let callback = BpfInsn::ld_imm64(2, BPF_PSEUDO_FUNC, 3);
        let insns = vec![
            callback[0],
            callback[1],
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::exit(),
            BpfInsn::mov64_reg(0, 1),
            BpfInsn::exit(),
        ];

        let prog = lift(&insns, None).expect("lift should mark pseudo_func subprogram entry");
        let subprog_block = block_for_original_pc(&prog, 4);

        assert_eq!(prog.blocks[subprog_block.0].frame, FrameId(1));
        roundtrip(&insns);
    }
}
