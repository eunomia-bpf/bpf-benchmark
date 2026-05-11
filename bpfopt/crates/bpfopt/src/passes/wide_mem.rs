// SPDX-License-Identifier: MIT
use crate::analysis::{control_flow_target_sites, BBProgram, BlockId, InsnSite, Terminator};
use crate::insn::*;
use crate::pass::*;
use anyhow::{bail, Context};
use std::collections::BTreeSet;
use std::ops::Range;
#[derive(Clone, Debug, PartialEq, Eq)]
pub(super) struct Binding {
    pub(super) name: &'static str,
    pub(super) value: i64,
}
#[derive(Clone, Debug)]
pub(super) struct RewriteSite {
    pub(super) start_idx: usize,
    pub(super) old_len: usize,
    pub(super) bindings: Vec<Binding>,
}
impl RewriteSite {
    pub(super) fn get_binding(&self, name: &str) -> Option<i64> {
        self.bindings
            .iter()
            .find(|b| b.name == name)
            .map(|b| b.value)
    }
    fn required_binding(&self, name: &str) -> anyhow::Result<i64> {
        self.get_binding(name)
            .ok_or_else(|| anyhow::anyhow!("wide_mem site missing required {name} binding"))
    }
}
pub(super) fn scan_wide_mem(insns: &[BpfInsn]) -> Vec<RewriteSite> {
    let mut sites = Vec::new();
    let n = insns.len();
    if n < 4 {
        return sites;
    }
    let mut idx = 0;
    while idx < n {
        if let Some(site) = try_match_wide_mem_at(insns, idx) {
            let site_len = site.old_len;
            sites.push(site);
            idx += site_len;
        } else {
            idx += 1;
        }
    }
    sites
}
fn try_match_wide_mem_at(insns: &[BpfInsn], idx: usize) -> Option<RewriteSite> {
    let n = insns.len();
    let first = &insns[idx];
    if !first.is_ldx_mem() || bpf_size(first.code) != BPF_B {
        return None;
    }
    let dst = first.dst_reg();
    let base = first.src_reg();
    let first_off = first.off as i64;
    for width in (2u32..=8).rev() {
        let len_a = 1 + 3 * (width as usize - 1);
        if idx + len_a <= n && match_wide_mem_low_first(insns, idx, dst, base, first_off, width) {
            return Some(RewriteSite {
                start_idx: idx,
                old_len: len_a,
                bindings: vec![
                    Binding {
                        name: "dst_reg",
                        value: dst as i64,
                    },
                    Binding {
                        name: "base_reg",
                        value: base as i64,
                    },
                    Binding {
                        name: "base_off",
                        value: first_off,
                    },
                    Binding {
                        name: "width",
                        value: width as i64,
                    },
                ],
            });
        }
        let len_b = 3 * width as usize - 2;
        if idx + len_b <= n {
            if let Some(base_off) =
                match_wide_mem_high_first(insns, idx, dst, base, first_off, width)
            {
                return Some(RewriteSite {
                    start_idx: idx,
                    old_len: len_b,
                    bindings: vec![
                        Binding {
                            name: "dst_reg",
                            value: dst as i64,
                        },
                        Binding {
                            name: "base_reg",
                            value: base as i64,
                        },
                        Binding {
                            name: "base_off",
                            value: base_off,
                        },
                        Binding {
                            name: "width",
                            value: width as i64,
                        },
                    ],
                });
            }
        }
    }
    None
}
fn match_wide_mem_low_first(
    insns: &[BpfInsn],
    start_idx: usize,
    dst: u8,
    base: u8,
    base_off: i64,
    width: u32,
) -> bool {
    for i in 1..width {
        let idx = start_idx + 3 * (i as usize - 1) + 1;
        let load = &insns[idx];
        let shift = &insns[idx + 1];
        let or = &insns[idx + 2];
        if !load.is_ldx_mem() || bpf_size(load.code) != BPF_B {
            return false;
        }
        if load.src_reg() != base {
            return false;
        }
        if load.off as i64 != base_off + i as i64 {
            return false;
        }
        let tmp = load.dst_reg();
        if tmp == dst {
            return false;
        }
        if shift.code != (BPF_ALU64 | BPF_LSH | BPF_K) {
            return false;
        }
        if shift.dst_reg() != tmp {
            return false;
        }
        if shift.imm != (8 * i) as i32 {
            return false;
        }
        if or.code != (BPF_ALU64 | BPF_OR | BPF_X) {
            return false;
        }
        if or.dst_reg() != dst || or.src_reg() != tmp {
            return false;
        }
    }
    true
}
fn match_wide_mem_high_first(
    insns: &[BpfInsn],
    start_idx: usize,
    dst: u8,
    base: u8,
    first_off: i64,
    width: u32,
) -> Option<i64> {
    let shift0 = &insns[start_idx + 1];
    if shift0.code != (BPF_ALU64 | BPF_LSH | BPF_K) {
        return None;
    }
    if shift0.dst_reg() != dst {
        return None;
    }
    if shift0.imm != 8 {
        return None;
    }
    let load0 = &insns[start_idx + 2];
    if !load0.is_ldx_mem() || bpf_size(load0.code) != BPF_B {
        return None;
    }
    if load0.src_reg() != base {
        return None;
    }
    let base_off = load0.off as i64;
    if first_off != base_off + 1 {
        return None;
    }
    let tmp0 = load0.dst_reg();
    if tmp0 == dst {
        return None;
    }
    let or0 = &insns[start_idx + 3];
    if or0.code != (BPF_ALU64 | BPF_OR | BPF_X) {
        return None;
    }
    if or0.dst_reg() != dst || or0.src_reg() != tmp0 {
        return None;
    }
    for i in 2..width {
        let idx = start_idx + 3 * i as usize - 2;
        let load = &insns[idx];
        let shift = &insns[idx + 1];
        let or = &insns[idx + 2];
        if !load.is_ldx_mem() || bpf_size(load.code) != BPF_B {
            return None;
        }
        if load.src_reg() != base {
            return None;
        }
        if load.off as i64 != base_off + i as i64 {
            return None;
        }
        let tmp = load.dst_reg();
        if tmp == dst {
            return None;
        }
        if shift.code != (BPF_ALU64 | BPF_LSH | BPF_K) {
            return None;
        }
        if shift.dst_reg() != tmp {
            return None;
        }
        if shift.imm != (8 * i) as i32 {
            return None;
        }
        if or.code != (BPF_ALU64 | BPF_OR | BPF_X) {
            return None;
        }
        if or.dst_reg() != dst || or.src_reg() != tmp {
            return None;
        }
    }
    Some(base_off)
}
pub(super) fn emit_wide_mem(site: &RewriteSite) -> anyhow::Result<Vec<BpfInsn>> {
    let dst = u8::try_from(site.required_binding("dst_reg")?)
        .context("wide_mem dst_reg binding does not fit u8")?;
    let base = u8::try_from(site.required_binding("base_reg")?)
        .context("wide_mem base_reg binding does not fit u8")?;
    let off = i16::try_from(site.required_binding("base_off")?)
        .context("wide_mem base_off binding does not fit i16")?;
    let width = site.required_binding("width")?;
    let size = match width {
        2 => BPF_H,
        4 => BPF_W,
        8 => BPF_DW,
        _ => bail!("WIDE_MEM: unsupported width {} (supports 2, 4, 8)", width),
    };
    Ok(vec![BpfInsn::ldx_mem(size, dst, base, off)])
}
fn wide_load_alignment_skip_reason(site: &RewriteSite) -> anyhow::Result<Option<String>> {
    let width = site.required_binding("width")?;
    let base_off = site.required_binding("base_off")?;
    if matches!(width, 2 | 4 | 8) && base_off.rem_euclid(width) != 0 {
        return Ok(Some(format!(
            "wide load offset {base_off} is not naturally aligned for width {width}"
        )));
    }
    Ok(None)
}
fn is_btf_struct_ptr_type(reg_type: &str) -> bool {
    let safe = matches!(
        reg_type,
        "scalar"
            | "fp"
            | "map_value"
            | "map_key"
            | "pkt"
            | "pkt_meta"
            | "ctx"
            | "mem"
            | "buf"
            | "ringbuf_mem"
            | "iter"
    ) || reg_type.starts_with("scalar")
        || reg_type.starts_with("fp");
    !safe
}
fn skip_site(site: InsnSite, reason: impl Into<String>) -> SiteSkipReason {
    SiteSkipReason {
        site,
        reason: reason.into(),
    }
}
const BPF_PROG_TYPE_SCHED_CLS: u32 = libbpf_sys::BPF_PROG_TYPE_SCHED_CLS;
const BPF_PROG_TYPE_SCHED_ACT: u32 = libbpf_sys::BPF_PROG_TYPE_SCHED_ACT;
const BPF_PROG_TYPE_XDP: u32 = libbpf_sys::BPF_PROG_TYPE_XDP;
const BPF_PROG_TYPE_LWT_IN: u32 = libbpf_sys::BPF_PROG_TYPE_LWT_IN;
const BPF_PROG_TYPE_LWT_OUT: u32 = libbpf_sys::BPF_PROG_TYPE_LWT_OUT;
const BPF_PROG_TYPE_LWT_XMIT: u32 = libbpf_sys::BPF_PROG_TYPE_LWT_XMIT;
const BPF_PROG_TYPE_SK_SKB: u32 = libbpf_sys::BPF_PROG_TYPE_SK_SKB;
fn is_packet_unsafe_prog_type(prog_type: u32) -> bool {
    matches!(
        prog_type,
        BPF_PROG_TYPE_SCHED_CLS
            | BPF_PROG_TYPE_SCHED_ACT
            | BPF_PROG_TYPE_XDP
            | BPF_PROG_TYPE_LWT_IN
            | BPF_PROG_TYPE_LWT_OUT
            | BPF_PROG_TYPE_LWT_XMIT
            | BPF_PROG_TYPE_SK_SKB
    )
}
fn is_likely_packet_ptr(reg: i32, before_slot: usize, insns: &[BpfInsn]) -> bool {
    const LOOKBACK: usize = 32;
    let start = before_slot.saturating_sub(LOOKBACK);
    for i in (start..before_slot).rev() {
        let insn = &insns[i];
        if insn.dst_reg() as i32 == reg {
            if insn.is_ldx_mem() {
                return insn.src_reg() == 1;
            }
            return false;
        }
    }
    true
}
pub struct WideMemPass;
#[derive(Clone, Debug)]
struct SafeWideMemSite {
    block: BlockId,
    range: Range<usize>,
    site: RewriteSite,
}
impl BpfPass for WideMemPass {
    fn name(&self) -> &str {
        "wide_mem"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx)
    }
}
pub fn run_on_bbprogram(prog: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
    let block_ids = prog.block_ids().collect::<Vec<_>>();
    if block_ids
        .iter()
        .copied()
        .try_fold(true, |all_empty, block| {
            Ok::<_, anyhow::Error>(all_empty && prog.block_is_body_empty(block)?)
        })?
    {
        return Ok(PassResult::unchanged());
    }
    let branch_targets = control_flow_target_sites(prog)?;
    let mut safe_sites = Vec::new();
    let mut skipped = Vec::new();
    let mut reported_starts = BTreeSet::new();
    for block in block_ids {
        let block_sites = prog.sites_in_block(block)?;
        let block_insns = block_sites
            .iter()
            .map(|&site| {
                prog.insn_at(site)
                    .copied()
                    .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))
            })
            .collect::<anyhow::Result<Vec<_>>>()?;
        for site in scan_wide_mem(&block_insns) {
            let start_idx = site.start_idx;
            let start_site = block_sites
                .get(start_idx)
                .copied()
                .ok_or_else(|| anyhow::anyhow!("wide_mem start index {start_idx} missing"))?;
            reported_starts.insert(start_site);
            let end_idx = start_idx + site.old_len;
            if end_idx > block_sites.len() {
                anyhow::bail!(
                    "wide_mem site at {:?} spans beyond block {:?} body",
                    start_site,
                    block
                );
            }
            let range = start_site.idx..start_site.idx + site.old_len;
            let has_interior_target = block_sites[start_idx + 1..end_idx]
                .iter()
                .any(|candidate| branch_targets.contains(candidate));
            if has_interior_target {
                skipped.push(skip_site(start_site, "interior branch target"));
                continue;
            }
            let dst_reg = u8::try_from(site.required_binding("dst_reg")?)
                .context("wide_mem dst_reg binding does not fit u8")?;
            let mut scratch_regs = std::collections::HashSet::new();
            for insn in &block_insns[start_idx..end_idx] {
                let class = insn.class();
                if class == BPF_ALU64 || class == BPF_ALU || class == BPF_LDX {
                    let dreg = insn.dst_reg();
                    if dreg != dst_reg {
                        scratch_regs.insert(dreg);
                    }
                }
            }
            let last_site = block_sites[end_idx - 1];
            let live_after = prog.live_out_site_checked(last_site)?;
            let has_live_scratch = scratch_regs.iter().any(|r| live_after.contains(r));
            if has_live_scratch {
                skipped.push(skip_site(start_site, "scratch register live after site"));
                continue;
            }
            let width = site.required_binding("width")?;
            if width != 2 && width != 4 && width != 8 {
                skipped.push(skip_site(
                    start_site,
                    format!("unsupported width {} (supports 2, 4, 8)", width),
                ));
                continue;
            }
            if let Some(reason) = wide_load_alignment_skip_reason(&site)? {
                skipped.push(skip_site(start_site, reason));
                continue;
            }
            if is_packet_unsafe_prog_type(ctx.prog_type) {
                let base_reg = site.required_binding("base_reg")?;
                let base_reg_i32 = i32::try_from(base_reg)
                    .context("wide_mem base_reg binding does not fit i32")?;
                if base_reg != 10 && is_likely_packet_ptr(base_reg_i32, start_idx, &block_insns) {
                    skipped.push(skip_site(
                        start_site,
                        format!(
                            "likely packet pointer r{} in XDP/TC prog (prog_type={})",
                            base_reg, ctx.prog_type
                        ),
                    ));
                    continue;
                }
            }
            let base_reg = u8::try_from(site.required_binding("base_reg")?)
                .context("wide_mem base_reg binding does not fit u8")?;
            if prog
                .oracle_at(start_site)
                .and_then(|state| state.regs.get(&base_reg))
                .is_some_and(|state| is_btf_struct_ptr_type(&state.reg_type))
            {
                skipped.push(skip_site(
                    start_site,
                    format!(
                    "base register r{} is a BTF struct pointer; wide load may cross field boundary",
                    base_reg
                ),
                ));
                continue;
            }
            safe_sites.push(SafeWideMemSite { block, range, site });
        }
    }
    add_cross_block_wide_mem_skips(prog, &branch_targets, &mut reported_starts, &mut skipped)?;
    if safe_sites.is_empty() {
        return Ok(PassResult {
            site_skipped: skipped,
            ..PassResult::unchanged()
        });
    }
    for site in safe_sites.iter().rev() {
        prog.replace_range(site.block, site.range.clone(), emit_wide_mem(&site.site)?)?;
    }
    Ok(PassResult {
        sites_applied: safe_sites.len(),
        site_skipped: skipped,
        ..Default::default()
    })
}
fn add_cross_block_wide_mem_skips(
    prog: &BBProgram,
    branch_targets: &BTreeSet<InsnSite>,
    reported_starts: &mut BTreeSet<InsnSite>,
    skipped: &mut Vec<SiteSkipReason>,
) -> anyhow::Result<()> {
    for block in prog.block_ids().collect::<Vec<_>>() {
        let block_len = prog.block_body_len(block)?;
        for idx in 0..block_len {
            let site = InsnSite { block, idx };
            if reported_starts.contains(&site) {
                continue;
            }
            let first_block_remaining = block_len - idx;
            let window = collect_wide_mem_window(prog, block, idx, branch_targets)?;
            if !window.crossed_branch_target {
                continue;
            }
            let Some(candidate) = try_match_wide_mem_at(&window.insns, 0) else {
                continue;
            };
            if candidate.old_len <= first_block_remaining {
                continue;
            }
            reported_starts.insert(site);
            skipped.push(skip_site(site, "interior branch target"));
        }
    }
    Ok(())
}
struct WideMemWindow {
    insns: Vec<BpfInsn>,
    crossed_branch_target: bool,
}
fn collect_wide_mem_window(
    prog: &BBProgram,
    start_block: BlockId,
    start_idx: usize,
    branch_targets: &BTreeSet<InsnSite>,
) -> anyhow::Result<WideMemWindow> {
    const MAX_WIDE_MEM_LEN: usize = 22;
    let mut insns = Vec::with_capacity(MAX_WIDE_MEM_LEN);
    let mut crossed_branch_target = false;
    let mut block = start_block;
    let mut idx = start_idx;
    while insns.len() < MAX_WIDE_MEM_LEN {
        let block_len = prog.block_body_len(block)?;
        while idx < block_len && insns.len() < MAX_WIDE_MEM_LEN {
            let site = InsnSite { block, idx };
            insns.push(
                *prog
                    .insn_at(site)
                    .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?,
            );
            idx += 1;
        }
        if insns.len() >= MAX_WIDE_MEM_LEN {
            break;
        }
        match prog.terminator(block)? {
            Terminator::Fallthrough { next } if next.0 == block.0 + 1 => {
                if let Some(site) = prog.first_site_in_block(next)? {
                    crossed_branch_target |= branch_targets.contains(&site);
                }
                block = next;
                idx = 0;
            }
            _ => break,
        }
    }
    Ok(WideMemWindow {
        insns,
        crossed_branch_target,
    })
}
