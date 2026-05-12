// SPDX-License-Identifier: MIT
use std::collections::BTreeSet;

use crate::analysis::{BBProgram, InsnSite};
use crate::insn::*;
use crate::pass::*;

const BPF_FUNC_SKB_LOAD_BYTES: i32 = libbpf_sys::BPF_FUNC_skb_load_bytes as i32;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum RegValue {
    Unknown,
    Ctx,
    Const(i64),
    FpPlusConst(i32),
}

impl RegValue {
    fn nonnegative_i32(self) -> Option<i32> {
        match self {
            Self::Const(current) if (0..=i32::MAX as i64).contains(&current) => {
                Some(current as i32)
            }
            _ => None,
        }
    }

    fn fp_stack_off(self) -> Option<i32> {
        match self {
            Self::FpPlusConst(off) => Some(off),
            _ => None,
        }
    }
}

impl SimpleRegValue for RegValue {
    fn unknown() -> Self {
        Self::Unknown
    }

    fn const64(value: i64) -> Self {
        Self::Const(value)
    }

    fn const32(value: u32) -> Self {
        Self::Const(value as i64)
    }

    fn mov32(value: Self) -> Self {
        match value {
            Self::Const(current) => Self::Const(current as u32 as i64),
            _ => Self::Unknown,
        }
    }

    fn alu64_imm(value: Self, op: u8, imm: i32) -> Self {
        match value {
            Self::Const(current) => add_sub_i64(current, op, imm)
                .map(Self::Const)
                .unwrap_or(Self::Unknown),
            Self::FpPlusConst(current) => add_sub_i64(i64::from(current), op, imm)
                .and_then(|next| i32::try_from(next).ok())
                .map(Self::FpPlusConst)
                .unwrap_or(Self::Unknown),
            _ => Self::Unknown,
        }
    }

    fn alu32_add_sub(value: Self, imm: i32, is_add: bool) -> Self {
        match value {
            Self::Const(current) => {
                let current = current as u32;
                let imm = imm as u32;
                let next = if is_add {
                    current.wrapping_add(imm)
                } else {
                    current.wrapping_sub(imm)
                };
                Self::Const(next as i64)
            }
            _ => Self::Unknown,
        }
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct RewriteSite {
    offset: i32,
    len: i32,
}

type AppliedRewriteSite = (InsnSite, RewriteSite);

#[derive(Default)]
struct ScanResult {
    sites: Vec<AppliedRewriteSite>,
    skips: Vec<SiteSkipReason>,
}

pub struct SkbLoadBytesSpecPass;

impl BpfPass for SkbLoadBytesSpecPass {
    fn name(&self) -> &str {
        "skb_load_bytes_spec"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx.prog_type)
    }
}

pub fn run_on_bbprogram(prog: &mut BBProgram, prog_type: u32) -> anyhow::Result<PassResult> {
    let Some(layout) = packet_ctx_layout(prog_type, PacketCtxLayoutScope::SkbHelper) else {
        return Ok(PassResult::unchanged());
    };
    let branch_targets = prog.branch_target_entry_sites()?;
    let mut scan = scan_sites(prog, &branch_targets)?;
    if scan.sites.is_empty() {
        return Ok(PassResult::with_sites(0, scan.skips));
    }
    let applied = apply_candidates_reverse(prog, &scan.sites, &mut scan.skips, |_, _, rewrite| {
        Ok((1, emit_replacement(*rewrite, layout)))
    })?;
    Ok(PassResult::with_sites(applied, scan.skips))
}

fn scan_sites(prog: &BBProgram, branch_targets: &BTreeSet<InsnSite>) -> anyhow::Result<ScanResult> {
    let mut scan = ScanResult::default();

    for block in prog.block_ids().collect::<Vec<_>>() {
        let mut regs = initial_reg_state();
        let sites = prog.sites_in_block(block)?;
        for site in sites {
            let insn = prog
                .insn_at(site)
                .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
            if insn.is_call() && insn.imm == BPF_FUNC_SKB_LOAD_BYTES {
                if insn.src_reg() != 0 {
                    scan.skips.push(SiteSkipReason {
                        site,
                        reason: "helper is not regular call #26".into(),
                    });
                } else {
                    match classify_site(branch_targets.contains(&site), &regs) {
                        Ok(rewrite_site) => scan.sites.push((site, rewrite_site)),
                        Err(reason) => scan.skips.push(SiteSkipReason::new(site, reason)),
                    }
                }
            }

            let ldimm64_hi = if insn.is_ldimm64() {
                Some(prog.ldimm64_second_slot(site).ok_or_else(|| {
                    anyhow::anyhow!("LD_IMM64 at {:?} is missing high half", site)
                })?)
            } else {
                None
            };
            advance_reg_state(insn, ldimm64_hi, &mut regs)?;
        }
    }

    Ok(scan)
}

fn classify_site(is_branch_target: bool, regs: &[RegValue; 11]) -> Result<RewriteSite, String> {
    if is_branch_target {
        return Err("call site is a branch target".into());
    }
    if regs[1] != RegValue::Ctx {
        return Err("arg1 is not ctx".into());
    }

    let Some(offset) = regs[2].nonnegative_i32() else {
        return Err("offset is not constant".into());
    };

    let Some(dest_off) = regs[3].fp_stack_off() else {
        return Err("dest is not fp-relative stack".into());
    };
    if dest_off >= 0 {
        return Err("dest is not fp-relative stack".into());
    }

    let Some(len) = regs[4].nonnegative_i32() else {
        return Err("len is not constant".into());
    };
    if len == 0 {
        return Err("len == 0".into());
    }
    if len > 8 {
        return Err("len > 8".into());
    }
    if offset.checked_add(len).is_none() {
        return Err("offset + len exceeds i32".into());
    }

    Ok(RewriteSite { offset, len })
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

fn initial_reg_state() -> [RegValue; 11] {
    let mut regs = [RegValue::Unknown; 11];
    regs[1] = RegValue::Ctx;
    regs[10] = RegValue::FpPlusConst(0);
    regs
}

fn add_sub_i64(current: i64, op: u8, imm: i32) -> Option<i64> {
    match op {
        BPF_ADD => current.checked_add(i64::from(imm)),
        BPF_SUB => current.checked_sub(i64::from(imm)),
        _ => None,
    }
}
