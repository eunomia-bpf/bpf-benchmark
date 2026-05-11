// SPDX-License-Identifier: MIT
//! skb_load_bytes specialization pass.

use std::collections::BTreeSet;
use std::ops::Range;

use crate::analysis::{
    advance_reg_state as advance_simple_reg_state, control_flow_target_sites, packet_ctx_layout,
    site_pc, BBProgram, BlockId, InsnSite, PacketCtxLayout, PacketCtxLayoutScope, SimpleRegValue,
};
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
        mov32_value(value)
    }

    fn alu64_imm(value: Self, op: u8, imm: i32) -> Self {
        match apply_alu64_imm(value, op, imm) {
            Some(value) => value,
            None => Self::Unknown,
        }
    }

    fn alu32_add_sub(value: Self, imm: i32, is_add: bool) -> Self {
        alu32_add_sub(value, imm, is_add)
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct RewriteSite {
    call_pc: usize,
    offset: i32,
    len: i32,
}

#[derive(Clone, Debug)]
struct AppliedRewriteSite {
    block: BlockId,
    range: Range<usize>,
    site: RewriteSite,
}

#[derive(Default)]
struct ScanResult {
    sites: Vec<AppliedRewriteSite>,
    skips: Vec<SkipReason>,
}

/// Specialize eligible `bpf_skb_load_bytes()` helper sites into direct packet access.
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
    let branch_targets = control_flow_target_sites(prog)?;
    let scan = scan_sites(prog, &branch_targets)?;
    if scan.sites.is_empty() {
        return Ok(PassResult {
            sites_skipped: scan.skips,
            ..PassResult::unchanged()
        });
    }
    apply_skb_load_bytes_sites(prog, &scan.sites, layout)?;
    Ok(PassResult {
        sites_applied: scan.sites.len(),
        sites_skipped: scan.skips,
        ..PassResult::unchanged()
    })
}

fn apply_skb_load_bytes_sites(
    prog: &mut BBProgram,
    sites: &[AppliedRewriteSite],
    layout: PacketCtxLayout,
) -> anyhow::Result<()> {
    for site in sites.iter().rev() {
        prog.replace_range(
            site.block,
            site.range.clone(),
            emit_replacement(site.site, layout),
        )?;
    }
    Ok(())
}

fn scan_sites(prog: &BBProgram, branch_targets: &BTreeSet<InsnSite>) -> anyhow::Result<ScanResult> {
    let mut scan = ScanResult::default();
    let mut regs = initial_reg_state();

    for block in prog.block_ids().collect::<Vec<_>>() {
        if prog.should_reset_linear_state_at_block(block)? {
            regs = initial_reg_state();
        }
        let sites = prog.sites_in_block(block)?;
        for (index, site) in sites.iter().copied().enumerate() {
            let pc = site_pc(prog, site)?;
            if index == 0 && pc > 0 && branch_targets.contains(&site) {
                regs = initial_reg_state();
            }

            let insn = prog
                .insn_at(site)
                .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
            if insn.is_call() && insn.imm == BPF_FUNC_SKB_LOAD_BYTES {
                if insn.src_reg() != 0 {
                    scan.skips.push(SkipReason {
                        pc,
                        reason: "helper is not regular call #26".into(),
                    });
                } else {
                    match classify_site(pc, branch_targets.contains(&site), &regs) {
                        Ok(rewrite_site) => scan.sites.push(AppliedRewriteSite {
                            block,
                            range: site.idx..site.idx + 1,
                            site: rewrite_site,
                        }),
                        Err(reason) => scan.skips.push(SkipReason { pc, reason }),
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
            advance_simple_reg_state(insn, ldimm64_hi, &mut regs)?;
        }
    }

    Ok(scan)
}

fn classify_site(
    call_pc: usize,
    is_branch_target: bool,
    regs: &[RegValue; 11],
) -> Result<RewriteSite, String> {
    if is_branch_target {
        return Err("call pc is a branch target".into());
    }
    if regs[1] != RegValue::Ctx {
        return Err("arg1 is not ctx".into());
    }

    let Some(offset) = extract_nonnegative_i32(regs[2]) else {
        return Err("offset is not constant".into());
    };

    let Some(dest_off) = extract_fp_stack_off(regs[3]) else {
        return Err("dest is not fp-relative stack".into());
    };
    if dest_off >= 0 {
        return Err("dest is not fp-relative stack".into());
    }

    let Some(len) = extract_nonnegative_i32(regs[4]) else {
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

    Ok(RewriteSite {
        call_pc,
        offset,
        len,
    })
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
    insns.push(BpfInsn::mov64_imm(0, 0));
    insns.push(BpfInsn::ja(3));
    insns.push(BpfInsn::mov64_imm(2, site.offset));
    insns.push(BpfInsn::mov64_imm(4, site.len));
    insns.push(BpfInsn::new(
        BPF_JMP | BPF_CALL,
        BpfInsn::make_regs(0, 0),
        0,
        BPF_FUNC_SKB_LOAD_BYTES,
    ));

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

fn apply_alu64_imm(value: RegValue, op: u8, imm: i32) -> Option<RegValue> {
    match value {
        RegValue::Const(current) => {
            let next = match op {
                BPF_ADD => current.checked_add(imm as i64)?,
                BPF_SUB => current.checked_sub(imm as i64)?,
                _ => return None,
            };
            Some(RegValue::Const(next))
        }
        RegValue::FpPlusConst(current) => {
            let next = match op {
                BPF_ADD => (current as i64).checked_add(imm as i64)?,
                BPF_SUB => (current as i64).checked_sub(imm as i64)?,
                _ => return None,
            };
            let next = match i32::try_from(next) {
                Ok(next) => next,
                Err(_) => return None,
            };
            Some(RegValue::FpPlusConst(next))
        }
        _ => None,
    }
}

fn mov32_value(value: RegValue) -> RegValue {
    match value {
        RegValue::Const(current) => RegValue::Const(current as u32 as i64),
        _ => RegValue::Unknown,
    }
}

fn alu32_add_sub(value: RegValue, imm: i32, is_add: bool) -> RegValue {
    match value {
        RegValue::Const(current) => {
            let current = current as u32;
            let imm = imm as u32;
            let next = if is_add {
                current.wrapping_add(imm)
            } else {
                current.wrapping_sub(imm)
            };
            RegValue::Const(next as i64)
        }
        _ => RegValue::Unknown,
    }
}

fn extract_nonnegative_i32(value: RegValue) -> Option<i32> {
    match value {
        RegValue::Const(current) if (0..=i32::MAX as i64).contains(&current) => {
            Some(current as i32)
        }
        _ => None,
    }
}

fn extract_fp_stack_off(value: RegValue) -> Option<i32> {
    match value {
        RegValue::FpPlusConst(off) => Some(off),
        _ => None,
    }
}
