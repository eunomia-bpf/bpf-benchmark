// SPDX-License-Identifier: MIT
//! Lower BBProgram back to linear BPF bytecode.

use crate::analysis::bbprogram_btf::{
    old_pc_to_current_pc, read_u32_field, remap_btf_record_pc, validate_btf_records, BtfRecordKind,
    BtfRecordRemap,
};
use crate::analysis::{BBProgram, BlockId, InsnSite, Terminator};
use crate::insn::BpfInsn;
use crate::pass::BtfInfoRecords;

pub fn lower(prog: &BBProgram) -> anyhow::Result<Vec<BpfInsn>> {
    if prog.blocks.is_empty() {
        return Ok(Vec::new());
    }

    let block_order = (0..prog.blocks.len()).map(BlockId).collect::<Vec<_>>();
    let block_start_pc = assign_block_pcs(prog, &block_order)?;
    let mut out = Vec::new();

    for block_id in block_order {
        let block = prog.block(block_id)?;
        for (idx, &insn) in block.insns.iter().enumerate() {
            let site = InsnSite {
                block: block_id,
                idx,
            };
            let mut emitted = insn;
            if let Some(&target) = prog.pc_relative_ldimm64_targets.get(&site) {
                let target_pc = block_start_pc[target.0];
                let delta = pc_delta(out.len(), target_pc)?;
                emitted.set_pc_relative_imm_delta(delta)?;
            }
            out.push(emitted);
            if insn.is_ldimm64() {
                let second = prog.ldimm64_second_slots.get(&site).ok_or_else(|| {
                    anyhow::anyhow!("LD_IMM64 at {:?} is missing its second slot", site)
                })?;
                out.push(*second);
            }
        }

        emit_terminator(
            prog,
            &block.terminator,
            &block_start_pc,
            out.len(),
            &mut out,
        )?;
    }

    Ok(out)
}

pub(crate) fn remap_btf_records_for_lowering(
    prog: &BBProgram,
    records: Option<&BtfInfoRecords>,
    kind: BtfRecordKind,
) -> anyhow::Result<Option<BtfInfoRecords>> {
    let Some(records) = records else {
        return Ok(None);
    };
    if records.bytes.is_empty() {
        return Ok(Some(records.clone()));
    }
    validate_btf_records(records)?;

    let rec_size = records.rec_size as usize;
    let old_to_new = old_pc_to_current_pc(prog)?;
    let mut out = Vec::with_capacity(records.bytes.len());
    let mut previous = None;
    for record in records.bytes.chunks(rec_size) {
        let old_pc = read_u32_field(record, 0, "insn_off")?;
        let new_pc = match remap_btf_record_pc(&old_to_new, old_pc as usize) {
            BtfRecordRemap::Keep { new_pc } => new_pc,
            BtfRecordRemap::DeletedOriginalInstruction => {
                // Deleting an instruction explicitly deletes its attached BTF
                // record; surviving records still must preserve strict order.
                continue;
            }
        };
        if previous.is_some_and(|prev| new_pc <= prev) {
            if kind == BtfRecordKind::Line && previous == Some(new_pc) {
                continue;
            }
            anyhow::bail!("BTF remap produced non-increasing insn_off");
        }
        let new_pc: u32 = new_pc
            .try_into()
            .map_err(|_| anyhow::anyhow!("BTF remapped insn_off does not fit u32"))?;
        out.extend_from_slice(record);
        let start = out.len() - rec_size;
        out[start..start + 4].copy_from_slice(&new_pc.to_le_bytes());
        previous = Some(new_pc as usize);
    }

    Ok(Some(BtfInfoRecords {
        rec_size: records.rec_size,
        bytes: out,
    }))
}

fn assign_block_pcs(prog: &BBProgram, order: &[BlockId]) -> anyhow::Result<Vec<usize>> {
    let mut block_start_pc = vec![0usize; prog.blocks.len()];
    let mut pc = 0usize;
    for &block_id in order {
        block_start_pc[block_id.0] = pc;
        let block = prog.block(block_id)?;
        for idx in 0..block.insns.len() {
            pc += prog.insn_slot_width(InsnSite {
                block: block_id,
                idx,
            })?;
        }
        if block.terminator.raw_insn().is_some() {
            pc += 1;
        }
    }
    Ok(block_start_pc)
}

fn emit_terminator(
    prog: &BBProgram,
    term: &Terminator,
    block_start_pc: &[usize],
    current_pc: usize,
    out: &mut Vec<BpfInsn>,
) -> anyhow::Result<()> {
    match *term {
        Terminator::Fallthrough { next } => {
            let target_pc = block_start_pc[next.0];
            if target_pc != current_pc {
                anyhow::bail!(
                    "fallthrough to {:?} is not physically adjacent: current pc {}, target pc {}",
                    next,
                    current_pc,
                    target_pc
                );
            }
        }
        Terminator::Jump { mut insn, target } => {
            let target_pc = block_start_pc[target.0];
            let delta = pc_delta(current_pc, target_pc)?;
            insn.set_branch_target_delta(delta)?;
            out.push(insn);
        }
        Terminator::CondBranch {
            mut cond,
            taken,
            fallthrough,
        } => {
            let fallthrough_pc = block_start_pc[fallthrough.0];
            if fallthrough_pc != current_pc + 1 {
                anyhow::bail!(
                    "conditional fallthrough to {:?} is not adjacent: branch pc {}, fallthrough pc {}",
                    fallthrough,
                    current_pc,
                    fallthrough_pc
                );
            }
            let target_pc = block_start_pc[taken.0];
            let delta = pc_delta(current_pc, target_pc)?;
            cond.set_branch_target_delta(delta)?;
            out.push(cond);
        }
        Terminator::Call {
            mut call,
            callee,
            return_to,
        } => {
            let return_pc = block_start_pc[return_to.0];
            if return_pc != current_pc + 1 {
                anyhow::bail!(
                    "pseudo_call return to {:?} is not adjacent: call pc {}, return pc {}",
                    return_to,
                    current_pc,
                    return_pc
                );
            }
            let callee_pc = block_start_pc[callee.0];
            let delta = pc_delta(current_pc, callee_pc)?;
            call.set_pc_relative_imm_delta(delta)?;
            out.push(call);
        }
        Terminator::Exit { insn } => out.push(insn),
        Terminator::End => {
            if current_pc != total_slot_len(prog)? {
                anyhow::bail!("non-final End terminator at pc {current_pc}");
            }
        }
    }
    Ok(())
}

fn total_slot_len(prog: &BBProgram) -> anyhow::Result<usize> {
    let mut len = 0usize;
    for block in prog.blocks() {
        for idx in 0..block.insns.len() {
            len += prog.insn_slot_width(InsnSite {
                block: block.id,
                idx,
            })?;
        }
        if block.terminator.raw_insn().is_some() {
            len += 1;
        }
    }
    Ok(len)
}

fn pc_delta(from_pc: usize, target_pc: usize) -> anyhow::Result<i64> {
    let delta = target_pc as i128 - from_pc as i128 - 1;
    i64::try_from(delta).map_err(|_| {
        anyhow::anyhow!("pc-relative delta from pc {from_pc} to {target_pc} does not fit i64")
    })
}

#[cfg(test)]
mod tests {
    use crate::insn::*;

    #[test]
    fn fixup_all_branches_rewrites_ja32_imm_after_growth() {
        let mut insn = BpfInsn::new(BPF_JMP32 | BPF_JA, 0, 0, 1);

        insn.set_branch_target_delta(42).unwrap();

        assert_eq!(insn.off, 0);
        assert_eq!(insn.imm, 42);
    }

    #[test]
    fn fixup_all_branches_rejects_i16_overflow() {
        let mut insn = BpfInsn::ja(0);

        let err = insn
            .set_branch_target_delta(i64::from(i16::MAX) + 1)
            .unwrap_err();

        assert!(err.to_string().contains("exceeds i16"));
    }

    #[test]
    fn fixup_all_branches_rejects_ja32_i32_overflow() {
        let mut insn = BpfInsn::new(BPF_JMP32 | BPF_JA, 0, 0, 0);

        let err = insn
            .set_branch_target_delta(i64::from(i32::MAX) + 1)
            .unwrap_err();

        assert!(err.to_string().contains("exceeds i32"));
    }
}
