// SPDX-License-Identifier: MIT
use std::collections::BTreeSet;

use crate::analysis::{InsnSite, LiftedRegFact, ProgramCFG};
use crate::insn::*;
use crate::pass::*;

const BPF_FUNC_SKB_LOAD_BYTES: i32 = libbpf_sys::BPF_FUNC_skb_load_bytes as i32;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct RewriteSite {
    offset: i32,
    len: i32,
}

#[derive(Default)]
struct ScanResult {
    sites: Vec<(InsnSite, RewriteSite)>,
    skips: Vec<SiteSkipReason>,
}

pub struct SkbLoadBytesSpecPass;

impl BpfPass for SkbLoadBytesSpecPass {
    fn run(&self, prog: &mut ProgramCFG, ctx: &PassContext) -> anyhow::Result<PassResult> {
        let Some(layout) = packet_ctx_layout(ctx.prog_type, PacketCtxLayoutScope::SkbHelper) else {
            return Ok(PassResult::default());
        };
        let branch_targets = prog.branch_target_entry_sites()?;
        let mut scan = scan_sites(prog, &branch_targets)?;
        if scan.sites.is_empty() {
            return Ok(PassResult::with_sites(0, scan.skips));
        }
        let applied =
            apply_candidates_reverse(prog, &scan.sites, &mut scan.skips, |_, _, rewrite| {
                Ok((1, emit_replacement(*rewrite, layout)))
            })?;
        Ok(PassResult::with_sites(applied, scan.skips))
    }
}

fn scan_sites(
    prog: &ProgramCFG,
    branch_targets: &BTreeSet<InsnSite>,
) -> anyhow::Result<ScanResult> {
    let mut scan = ScanResult::default();
    for block in prog.block_ids().collect::<Vec<_>>() {
        for site in prog.sites_in_block(block)? {
            let insn = prog.insn(site)?;
            if !insn.is_call() || insn.imm != BPF_FUNC_SKB_LOAD_BYTES {
                continue;
            }
            if insn.src_reg() != 0 {
                scan.skips.push(SiteSkipReason {
                    site,
                    reason: "helper is not regular call #26".into(),
                });
                continue;
            }
            match classify_site(prog, site, branch_targets.contains(&site))? {
                Ok(rewrite_site) => scan.sites.push((site, rewrite_site)),
                Err(reason) => scan.skips.push(SiteSkipReason::new(site, reason)),
            }
        }
    }
    Ok(scan)
}

fn classify_site(
    prog: &ProgramCFG,
    site: InsnSite,
    is_branch_target: bool,
) -> anyhow::Result<Result<RewriteSite, String>> {
    if is_branch_target {
        return Ok(Err("call site is a branch target".into()));
    }
    if prog.reg_fact_at(site, 1)? != LiftedRegFact::Ctx {
        return Ok(Err("arg1 is not ctx".into()));
    }
    let Some(offset) = nonnegative_i32(prog.reg_fact_at(site, 2)?) else {
        return Ok(Err("offset is not constant".into()));
    };
    let Some(dest_off) = prog.reg_fact_at(site, 3)?.as_fp_off() else {
        return Ok(Err("dest is not fp-relative stack".into()));
    };
    if dest_off >= 0 {
        return Ok(Err("dest is not fp-relative stack".into()));
    }
    let Some(len) = nonnegative_i32(prog.reg_fact_at(site, 4)?) else {
        return Ok(Err("len is not constant".into()));
    };
    if len == 0 {
        return Ok(Err("len == 0".into()));
    }
    if len > 8 {
        return Ok(Err("len > 8".into()));
    }
    if offset.checked_add(len).is_none() {
        return Ok(Err("offset + len exceeds i32".into()));
    }
    Ok(Ok(RewriteSite { offset, len }))
}

fn nonnegative_i32(fact: LiftedRegFact) -> Option<i32> {
    let value = fact.as_const()?;
    (0..=i64::from(i32::MAX))
        .contains(&value)
        .then_some(value as i32)
}

fn emit_replacement(site: RewriteSite, layout: PacketCtxLayout) -> Vec<BpfInsn> {
    let copy_insns = emit_copy_insns(site.len);
    let slow_off = (3 + copy_insns.len()) as i16;

    let mut insns = vec![
        BpfInsn::ldx_mem(BPF_W, 5, 1, layout.data_off),
        BpfInsn::ldx_mem(BPF_W, 0, 1, layout.data_end_off),
        BpfInsn::mov64_reg(2, 5),
        BpfInsn::alu64_imm(BPF_ADD, 2, site.offset + site.len),
        BpfInsn::jump_reg(BPF_JGT, 2, 0, slow_off),
        BpfInsn::alu64_imm(BPF_ADD, 5, site.offset),
    ];

    insns.extend(copy_insns);
    insns.extend([
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::ja(3),
        BpfInsn::mov64_imm(2, site.offset),
        BpfInsn::mov64_imm(4, site.len),
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, 0),
            0,
            BPF_FUNC_SKB_LOAD_BYTES,
        ),
    ]);

    insns
}

fn emit_copy_insns(len: i32) -> Vec<BpfInsn> {
    // Keep the fast path bytewise. Widening packet accesses here can turn a
    // helper-legal unaligned copy into a verifier-rejected direct packet load.
    let mut insns = Vec::with_capacity(len as usize * 2);
    for i in 0..len {
        let off = i as i16;
        insns.push(BpfInsn::ldx_mem(BPF_B, 4, 5, off));
        insns.push(BpfInsn::stx_mem(BPF_B, 3, 4, off));
    }
    insns
}
