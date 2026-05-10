// SPDX-License-Identifier: MIT
//! Shared rewrite-plan commit machinery for bytecode replacement passes.

use std::collections::{BTreeMap, BTreeSet};

use crate::insn::*;
use crate::pass::{
    remap_btf_metadata, remap_kinsn_btf_metadata, BpfProgram, KinsnRegistry, PassResult,
};

/// Fix up branch and pseudo-call offsets after rewriting using an address map.
///
/// For each instruction in the original stream that is a branch/jump, compute
/// where it ended up in the new stream and adjust its offset so it still points
/// to the correct target.
pub fn fixup_all_branches(
    new_insns: &mut [BpfInsn],
    old_insns: &[BpfInsn],
    addr_map: &[usize],
) -> anyhow::Result<()> {
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
            if let Some(old_target) = relative_branch_target_pc(old_pc, i64::from(insn.imm)) {
                if old_target < old_n
                    && survived_unchanged
                    && new_pc < new_insns.len()
                    && new_insns[new_pc].is_ldimm64_pseudo_func()
                {
                    let new_target = addr_map[old_target];
                    let new_imm = new_target as i64 - (new_pc as i64 + 1);
                    new_insns[new_pc].set_pc_relative_imm_delta(new_imm)?;
                }
            }
        } else if insn.is_call() && insn.src_reg() == 1 {
            if let Some(old_target) = relative_branch_target_pc(old_pc, i64::from(insn.imm)) {
                if old_target < old_n {
                    let new_target = addr_map[old_target];
                    if survived_unchanged && new_insns[new_pc].is_call() {
                        let new_imm = new_target as i64 - (new_pc as i64 + 1);
                        new_insns[new_pc].set_pc_relative_imm_delta(new_imm)?;
                    }
                }
            }
        } else if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
            if let Some(old_target) = insn.branch_target_pc(old_pc) {
                if old_target <= old_n {
                    let new_target = addr_map[old_target];
                    if survived_unchanged
                        && new_insns[new_pc].is_jmp_class()
                        && !new_insns[new_pc].is_call()
                        && !new_insns[new_pc].is_exit()
                    {
                        let new_off = new_target as i64 - (new_pc as i64 + 1);
                        new_insns[new_pc].set_branch_target_delta(new_off)?;
                    }
                }
            }
        }
        old_pc = if insn.is_ldimm64() {
            old_pc + 2
        } else {
            old_pc + 1
        };
    }
    Ok(())
}

/// Compose two address maps: `old -> mid` and `mid -> new`.
pub fn compose_addr_maps(first: &[usize], second: &[usize]) -> Vec<usize> {
    first.iter().map(|&pc| second[pc]).collect()
}

pub fn map_replacement_range(
    addr_map: &mut [usize],
    old_start: usize,
    old_len: usize,
    new_start: usize,
    new_len: usize,
) {
    debug_assert!(new_len > 0);
    for old_offset in 0..old_len {
        let new_offset = old_offset.min(new_len.saturating_sub(1));
        addr_map[old_start + old_offset] = new_start + new_offset;
    }
}

#[derive(Clone, Debug, Default)]
pub struct RewritePlan {
    replacements: BTreeMap<usize, ReplacementSlot>,
    deletions: BTreeSet<(usize, usize)>,
    insertions: BTreeMap<usize, Vec<BpfInsn>>,
    internal_branch_patches: Vec<BranchPatch>,
}

type ReplacementSlot = (usize, Vec<BpfInsn>);
type BranchPatch = (usize, usize, usize);

#[derive(Clone, Copy, Debug)]
pub enum BtfRemapPolicy<'a> {
    Remap,
    RemapKinsn(&'a KinsnRegistry),
    NoRemap,
}

#[derive(Clone, Debug)]
pub struct RewriteOutput {
    pub insns: Vec<BpfInsn>,
    pub addr_map: Vec<usize>,
    pub sites_applied: usize,
}

pub fn commit_rewrite_output(
    program: &mut BpfProgram,
    output: RewriteOutput,
    btf_policy: BtfRemapPolicy<'_>,
) -> anyhow::Result<PassResult> {
    let old_len = program.insns.len();
    let RewriteOutput {
        insns,
        addr_map,
        sites_applied,
    } = output;

    program.insns = insns;
    match btf_policy {
        BtfRemapPolicy::Remap => remap_btf_metadata(program, &addr_map)?,
        BtfRemapPolicy::RemapKinsn(registry) => {
            remap_kinsn_btf_metadata(program, registry)?;
        }
        BtfRemapPolicy::NoRemap => {}
    }
    program.remap_annotations(&addr_map);

    Ok(PassResult {
        sites_applied,
        insns_before: old_len,
        insns_after: program.insns.len(),
        ..Default::default()
    })
}

impl RewritePlan {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn replace_range(
        &mut self,
        start_pc: usize,
        old_len: usize,
        new_insns: Vec<BpfInsn>,
    ) -> anyhow::Result<()> {
        if self.replacements.contains_key(&start_pc) {
            anyhow::bail!("duplicate rewrite replacement at old pc {start_pc}");
        }
        self.replacements.insert(start_pc, (old_len, new_insns));
        Ok(())
    }

    pub fn insert_before(&mut self, pc: usize, new_insns: Vec<BpfInsn>) {
        self.insertions.entry(pc).or_default().extend(new_insns);
    }

    pub fn delete_range(&mut self, start_pc: usize, len: usize) -> anyhow::Result<()> {
        let end = start_pc
            .checked_add(len)
            .ok_or_else(|| anyhow::anyhow!("rewrite deletion range {start_pc} overflows"))?;
        if !self.deletions.insert((start_pc, end)) {
            anyhow::bail!("duplicate rewrite deletion range {start_pc}..{end}");
        }
        Ok(())
    }

    pub fn add_internal_branch(
        &mut self,
        replacement_old_pc: usize,
        replacement_idx: usize,
        target_old_pc: usize,
    ) {
        self.internal_branch_patches
            .push((replacement_old_pc, replacement_idx, target_old_pc));
    }

    pub fn commit(
        self,
        program: &mut BpfProgram,
        btf_policy: BtfRemapPolicy<'_>,
    ) -> anyhow::Result<PassResult> {
        let old_insns = program.insns.clone();
        let output = self.build(&old_insns)?;
        commit_rewrite_output(program, output, btf_policy)
    }

    pub fn build(self, old_insns: &[BpfInsn]) -> anyhow::Result<RewriteOutput> {
        let old_len = old_insns.len();
        self.validate(old_insns)?;

        let sites_applied = self.replacements.len();
        let deletions = self.deletion_starts();
        let mut replacement_starts = BTreeMap::new();
        let mut new_insns = Vec::with_capacity(old_len);
        let mut addr_map = vec![0usize; old_len + 1];
        let mut pc = 0usize;

        while pc < old_len {
            addr_map[pc] = new_insns.len();
            if let Some(insns) = self.insertions.get(&pc) {
                new_insns.extend_from_slice(insns);
            }

            if let Some(slot) = self.replacements.get(&pc) {
                let new_pc = new_insns.len();
                replacement_starts.insert(pc, new_pc);
                map_replacement_range(&mut addr_map, pc, slot.0, new_pc, slot.1.len());
                new_insns.extend_from_slice(&slot.1);
                pc += slot.0;
                continue;
            }
            if let Some(&end) = deletions.get(&pc) {
                for old_pc in pc..end {
                    addr_map[old_pc] = new_insns.len();
                }
                pc = end;
                continue;
            }

            let insn = old_insns[pc];
            new_insns.push(insn);
            if insn.is_ldimm64() && pc + 1 < old_len {
                pc += 1;
                addr_map[pc] = new_insns.len();
                new_insns.push(old_insns[pc]);
            }
            pc += 1;
        }

        addr_map[old_len] = new_insns.len();
        if let Some(insns) = self.insertions.get(&old_len) {
            new_insns.extend_from_slice(insns);
        }

        fixup_all_branches(&mut new_insns, &old_insns, &addr_map)?;
        patch_internal_branches(
            &mut new_insns,
            &addr_map,
            &replacement_starts,
            &self.internal_branch_patches,
        )?;

        Ok(RewriteOutput {
            insns: new_insns,
            addr_map,
            sites_applied,
        })
    }

    fn deletion_starts(&self) -> BTreeMap<usize, usize> {
        self.deletions
            .iter()
            .map(|&(start, end)| (start, end))
            .collect()
    }

    fn validate(&self, old_insns: &[BpfInsn]) -> anyhow::Result<()> {
        let old_len = old_insns.len();
        let boundaries = instruction_boundaries(old_insns);
        let mut claimed = vec![false; old_len];

        for (&pc, slot) in &self.replacements {
            check_range("replacement", pc, slot.0, old_len, &boundaries)?;
            if slot.1.is_empty() {
                anyhow::bail!("replacement at old pc {pc} has no new instructions");
            }
            claim(pc, pc + slot.0, &mut claimed)?;
        }
        for &(start, end) in &self.deletions {
            check_range("deletion", start, end - start, old_len, &boundaries)?;
            claim(start, end, &mut claimed)?;
        }
        for (&pc, insns) in &self.insertions {
            if pc > old_len || !boundaries[pc] {
                anyhow::bail!("insertion pc {pc} is not an instruction boundary");
            }
            if insns.is_empty() {
                anyhow::bail!("insertion at old pc {pc} has no new instructions");
            }
            if pc < old_len && claimed[pc] {
                anyhow::bail!("insertion at old pc {pc} conflicts with replacement/deletion");
            }
        }
        for &(replacement_old_pc, replacement_idx, target_old_pc) in &self.internal_branch_patches {
            let Some(slot) = self.replacements.get(&replacement_old_pc) else {
                anyhow::bail!(
                    "internal branch patch references missing replacement at old pc {}",
                    replacement_old_pc
                );
            };
            if replacement_idx >= slot.1.len() {
                anyhow::bail!("internal branch patch index exceeds replacement length");
            }
            if target_old_pc > old_len || !boundaries[target_old_pc] {
                anyhow::bail!("internal branch patch target is not an instruction boundary");
            }
        }
        Ok(())
    }
}

fn instruction_boundaries(insns: &[BpfInsn]) -> Vec<bool> {
    let mut boundaries = vec![false; insns.len() + 1];
    let mut pc = 0usize;
    while pc < insns.len() {
        boundaries[pc] = true;
        pc += insn_width(&insns[pc]);
    }
    boundaries[insns.len()] = true;
    boundaries
}

fn check_range(
    label: &str,
    start: usize,
    len: usize,
    old_len: usize,
    boundaries: &[bool],
) -> anyhow::Result<()> {
    if len == 0 {
        anyhow::bail!("{label} at old pc {start} has zero length");
    }
    let end = start
        .checked_add(len)
        .ok_or_else(|| anyhow::anyhow!("{label} at old pc {start} overflows"))?;
    if end > old_len || !boundaries[start] || !boundaries[end] {
        anyhow::bail!("{label} range {start}..{end} is outside or not instruction-aligned");
    }
    Ok(())
}

fn claim(start: usize, end: usize, claimed: &mut [bool]) -> anyhow::Result<()> {
    for pc in start..end {
        if claimed[pc] {
            anyhow::bail!("rewrite ranges overlap at old pc {pc}");
        }
        claimed[pc] = true;
    }
    Ok(())
}

fn patch_internal_branches(
    new_insns: &mut [BpfInsn],
    addr_map: &[usize],
    replacement_starts: &BTreeMap<usize, usize>,
    patches: &[BranchPatch],
) -> anyhow::Result<()> {
    for &(replacement_old_pc, replacement_idx, target_old_pc) in patches {
        let new_pc = replacement_starts
            .get(&replacement_old_pc)
            .and_then(|pc| pc.checked_add(replacement_idx))
            .ok_or_else(|| anyhow::anyhow!("internal branch patch references missing site"))?;
        let target_pc = *addr_map
            .get(target_old_pc)
            .ok_or_else(|| anyhow::anyhow!("internal branch patch target is outside addr_map"))?;
        let delta = target_pc as i64 - (new_pc as i64 + 1);
        let Some(branch) = new_insns.get_mut(new_pc) else {
            anyhow::bail!("internal branch patch pc {new_pc} is outside rewritten program");
        };

        if branch.is_ldimm64_pseudo_func() || branch.is_call() && branch.src_reg() == 1 {
            branch.set_pc_relative_imm_delta(delta)?;
        } else if branch.is_jmp_class() && !branch.is_call() && !branch.is_exit() {
            branch.set_branch_target_delta(delta)?;
        } else {
            anyhow::bail!("internal branch patch at new pc {new_pc} is not a branch");
        }
    }
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    fn pseudo_func_ref(dst: u8, imm: i32) -> [BpfInsn; 2] {
        [
            BpfInsn::new(
                BPF_LD | BPF_DW | BPF_IMM,
                BpfInsn::make_regs(dst, BPF_PSEUDO_FUNC),
                0,
                imm,
            ),
            BpfInsn::new(0, 0, 0, 0),
        ]
    }

    #[test]
    fn test_fixup_all_branches_forward_jump() {
        let old_insns = vec![BpfInsn::ja(1), BpfInsn::nop(), BpfInsn::exit()];
        let mut new_insns = vec![
            BpfInsn::ja(1),
            BpfInsn::nop(),
            BpfInsn::nop(),
            BpfInsn::exit(),
        ];
        let addr_map = vec![0, 2, 3, 4];

        fixup_all_branches(&mut new_insns, &old_insns, &addr_map).unwrap();

        assert_eq!(new_insns[0].off, 2);
    }

    #[test]
    fn test_fixup_all_branches_does_not_write_branch_off_into_helper_call() {
        let old_insns = vec![
            BpfInsn::ja(1),
            BpfInsn::nop(),
            BpfInsn::helper_call(5),
            BpfInsn::exit(),
        ];
        let mut new_insns = vec![BpfInsn::helper_call(5), BpfInsn::exit()];
        let addr_map = vec![0, 0, 0, 1, 2];

        fixup_all_branches(&mut new_insns, &old_insns, &addr_map).unwrap();

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
            BpfInsn::exit(),
        ];
        let mut new_insns = vec![BpfInsn::ja(1), BpfInsn::nop(), BpfInsn::exit()];
        let addr_map = vec![0, 0, 0, 1, 2, 3];

        fixup_all_branches(&mut new_insns, &old_insns, &addr_map).unwrap();

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
            BpfInsn::exit(),
            BpfInsn::mov64_reg(0, 1),
            BpfInsn::exit(),
        ];
        let mut new_insns = vec![
            callback[0],
            callback[1],
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::exit(),
            BpfInsn::nop(),
            BpfInsn::mov64_reg(0, 1),
            BpfInsn::exit(),
        ];
        let addr_map = vec![0, 1, 2, 3, 5, 6, 7];

        fixup_all_branches(&mut new_insns, &old_insns, &addr_map).unwrap();

        assert!(new_insns[0].is_ldimm64_pseudo_func());
        assert_eq!(new_insns[0].imm, 4);
        assert_eq!(1 + new_insns[0].imm as usize, 5);
    }

    #[test]
    fn fixup_all_branches_rewrites_ja32_imm_after_growth() {
        let old_insns = vec![
            BpfInsn::new(BPF_JMP32 | BPF_JA, 0, 0, 1),
            BpfInsn::nop(),
            BpfInsn::exit(),
        ];
        let mut new_insns = vec![
            old_insns[0],
            BpfInsn::nop(),
            BpfInsn::nop(),
            BpfInsn::exit(),
        ];
        let addr_map = vec![0, 2, 3, 4];

        fixup_all_branches(&mut new_insns, &old_insns, &addr_map).unwrap();

        assert_eq!(new_insns[0].imm, 2);
        assert_eq!(new_insns[0].off, 0);
    }

    #[test]
    fn fixup_all_branches_rejects_i16_overflow() {
        let old_insns = vec![BpfInsn::ja(1), BpfInsn::nop(), BpfInsn::exit()];
        let mut new_insns = vec![old_insns[0], BpfInsn::exit()];
        let addr_map = vec![0, 1, 40_000, 40_001];

        let err = fixup_all_branches(&mut new_insns, &old_insns, &addr_map).unwrap_err();

        assert!(err.to_string().contains("exceeds i16"));
    }

    #[test]
    fn fixup_all_branches_rejects_ja32_i32_overflow() {
        let old_insns = vec![
            BpfInsn::new(BPF_JMP32 | BPF_JA, 0, 0, 1),
            BpfInsn::nop(),
            BpfInsn::exit(),
        ];
        let mut new_insns = vec![old_insns[0], BpfInsn::exit()];
        let addr_map = vec![0, 1, i32::MAX as usize + 10, i32::MAX as usize + 11];

        let err = fixup_all_branches(&mut new_insns, &old_insns, &addr_map).unwrap_err();

        assert!(err.to_string().contains("exceeds i32"));
    }
}
