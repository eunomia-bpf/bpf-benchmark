// SPDX-License-Identifier: MIT
//! Shared rewrite-plan commit machinery for bytecode replacement passes.

use std::collections::{BTreeMap, BTreeSet};

use crate::insn::*;
use crate::pass::{BpfProgram, PassResult};

use super::utils::{fixup_all_branches, insn_width, map_replacement_range, remap_btf_metadata};

#[derive(Clone, Debug, Default)]
pub struct RewritePlan {
    replacements: BTreeMap<usize, ReplacementSlot>,
    deletions: BTreeSet<(usize, usize)>,
    insertions: BTreeMap<usize, Vec<BpfInsn>>,
    internal_branch_patches: Vec<BranchPatch>,
}

type ReplacementSlot = (usize, Vec<BpfInsn>);
type BranchPatch = (usize, usize, usize);

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum BtfRemapPolicy {
    Remap,
    NoRemap,
}

impl RewritePlan {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn replace_range(&mut self, start_pc: usize, old_len: usize, new_insns: Vec<BpfInsn>) {
        assert!(
            self.replacements
                .insert(start_pc, (old_len, new_insns))
                .is_none(),
            "duplicate rewrite replacement at old pc {start_pc}"
        );
    }

    pub fn insert_before(&mut self, pc: usize, new_insns: Vec<BpfInsn>) {
        self.insertions.entry(pc).or_default().extend(new_insns);
    }

    pub fn delete_range(&mut self, start_pc: usize, len: usize) {
        let end = start_pc
            .checked_add(len)
            .expect("rewrite deletion range overflow");
        assert!(
            self.deletions.insert((start_pc, end)),
            "duplicate rewrite deletion range {start_pc}..{end}"
        );
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
        btf_policy: BtfRemapPolicy,
    ) -> anyhow::Result<PassResult> {
        let old_insns = program.insns.clone();
        let old_len = old_insns.len();
        self.validate(&old_insns)?;

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

        fixup_all_branches(&mut new_insns, &old_insns, &addr_map);
        patch_internal_branches(
            &mut new_insns,
            &addr_map,
            &replacement_starts,
            &self.internal_branch_patches,
        )?;

        program.insns = new_insns;
        if btf_policy == BtfRemapPolicy::Remap {
            remap_btf_metadata(program, &addr_map)?;
        }
        program.remap_annotations(&addr_map);

        Ok(PassResult {
            sites_applied,
            insns_before: old_len,
            insns_after: program.insns.len(),
            ..Default::default()
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
            branch.imm = i32::try_from(delta)
                .map_err(|_| anyhow::anyhow!("internal pseudo-branch offset exceeds i32"))?;
        } else if branch.is_jmp_class() && !branch.is_call() && !branch.is_exit() {
            branch.off = i16::try_from(delta)
                .map_err(|_| anyhow::anyhow!("internal branch offset exceeds i16"))?;
        } else {
            anyhow::bail!("internal branch patch at new pc {new_pc} is not a branch");
        }
    }
    Ok(())
}
