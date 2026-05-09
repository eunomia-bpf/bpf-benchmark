// SPDX-License-Identifier: MIT
//! skb_load_bytes specialization pass.

use std::collections::BTreeMap;

use crate::analysis::{BranchTargetAnalysis, BranchTargetResult};
use crate::insn::*;
use crate::pass::*;

use super::utils::{fixup_all_branches, insn_width};

const BPF_FUNC_SKB_LOAD_BYTES: i32 = kernel_sys::BPF_FUNC_skb_load_bytes as i32;

const BPF_PROG_TYPE_SCHED_CLS: u32 = kernel_sys::BPF_PROG_TYPE_SCHED_CLS;
const BPF_PROG_TYPE_SCHED_ACT: u32 = kernel_sys::BPF_PROG_TYPE_SCHED_ACT;

const SKB_DATA_OFF: i16 = 76;
const SKB_DATA_END_OFF: i16 = 80;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct PacketCtxLayout {
    data_off: i16,
    data_end_off: i16,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum RegValue {
    Unknown,
    Ctx,
    Const(i64),
    FpPlusConst(i32),
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct RewriteSite {
    call_pc: usize,
    offset: i32,
    len: i32,
}

#[derive(Default)]
struct ScanResult {
    sites: Vec<RewriteSite>,
    skips: Vec<SkipReason>,
}

/// Specialize eligible `bpf_skb_load_bytes()` helper sites into direct packet access.
pub struct SkbLoadBytesSpecPass;

impl BpfPass for SkbLoadBytesSpecPass {
    fn name(&self) -> &str {
        "skb_load_bytes_spec"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        if program.insns.is_empty() {
            return Ok(PassResult::unchanged(self.name()));
        }

        let Some(layout) = packet_ctx_layout(ctx.prog_type) else {
            return Ok(PassResult::unchanged(self.name()));
        };

        let bt = analyses.get(&BranchTargetAnalysis, program);
        let scan = scan_sites(&program.insns, &bt);
        if scan.sites.is_empty() {
            return Ok(PassResult {
                sites_skipped: scan.skips,
                ..PassResult::unchanged(self.name())
            });
        }

        let old_insns = program.insns.clone();
        let (mut new_insns, addr_map) = rewrite_sites(&old_insns, &scan.sites, layout);
        fixup_all_branches(&mut new_insns, &old_insns, &addr_map);

        program.insns = new_insns;
        program.remap_annotations(&addr_map);

        Ok(PassResult {
            pass_name: self.name().into(),
            sites_applied: scan.sites.len(),
            sites_skipped: scan.skips,
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

fn packet_ctx_layout(prog_type: u32) -> Option<PacketCtxLayout> {
    match prog_type {
        BPF_PROG_TYPE_SCHED_CLS | BPF_PROG_TYPE_SCHED_ACT => Some(PacketCtxLayout {
            data_off: SKB_DATA_OFF,
            data_end_off: SKB_DATA_END_OFF,
        }),
        _ => None,
    }
}

fn scan_sites(insns: &[BpfInsn], bt: &BranchTargetResult) -> ScanResult {
    let mut scan = ScanResult::default();
    let mut regs = initial_reg_state();
    let mut pc = 0usize;

    while pc < insns.len() {
        if pc > 0 && bt.is_target.get(pc).copied().unwrap_or(false) {
            regs = initial_reg_state();
        }

        let insn = &insns[pc];
        if insn.is_call() && insn.imm == BPF_FUNC_SKB_LOAD_BYTES {
            if insn.src_reg() != 0 {
                scan.skips.push(SkipReason {
                    pc,
                    reason: "helper is not regular call #26".into(),
                });
            } else {
                match classify_site(pc, bt, &regs) {
                    Ok(site) => scan.sites.push(site),
                    Err(reason) => scan.skips.push(SkipReason { pc, reason }),
                }
            }
        }

        advance_reg_state(insns, pc, &mut regs);
        pc += insn_width(insn);
    }

    scan
}

fn classify_site(
    call_pc: usize,
    bt: &BranchTargetResult,
    regs: &[RegValue; 11],
) -> Result<RewriteSite, String> {
    if bt.is_target.get(call_pc).copied().unwrap_or(false) {
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

fn rewrite_sites(
    old_insns: &[BpfInsn],
    sites: &[RewriteSite],
    layout: PacketCtxLayout,
) -> (Vec<BpfInsn>, Vec<usize>) {
    let mut replacements: BTreeMap<usize, Vec<BpfInsn>> = BTreeMap::new();
    for site in sites {
        replacements.insert(site.call_pc, emit_replacement(*site, layout));
    }

    let orig_len = old_insns.len();
    let mut new_insns = Vec::with_capacity(orig_len);
    let mut addr_map = vec![0usize; orig_len + 1];
    let mut pc = 0usize;

    while pc < orig_len {
        addr_map[pc] = new_insns.len();

        if let Some(replacement) = replacements.get(&pc) {
            new_insns.extend_from_slice(replacement);
            pc += 1;
            continue;
        }

        let insn = old_insns[pc];
        new_insns.push(insn);
        if insn.is_ldimm64() && pc + 1 < orig_len {
            pc += 1;
            addr_map[pc] = new_insns.len();
            new_insns.push(old_insns[pc]);
        }
        pc += 1;
    }
    addr_map[orig_len] = new_insns.len();

    (new_insns, addr_map)
}

fn emit_replacement(site: RewriteSite, layout: PacketCtxLayout) -> Vec<BpfInsn> {
    let copy_insns = emit_copy_insns(site.len);
    let slow_off = (3 + copy_insns.len()) as i16;

    let mut insns = vec![
        BpfInsn::ldx_mem(BPF_W, 5, 1, layout.data_off),
        BpfInsn::ldx_mem(BPF_W, 0, 1, layout.data_end_off),
        BpfInsn::mov64_reg(2, 5),
        BpfInsn::alu64_imm(BPF_ADD, 2, site.offset + site.len),
        jgt_reg(2, 0, slow_off),
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

fn advance_reg_state(insns: &[BpfInsn], pc: usize, regs: &mut [RegValue; 11]) {
    let insn = &insns[pc];

    if insn.is_call() {
        for reg in regs.iter_mut().take(6) {
            *reg = RegValue::Unknown;
        }
        return;
    }

    if insn.is_ldimm64() {
        let next = insns.get(pc + 1).copied();
        regs[insn.dst_reg() as usize] = next
            .map(|hi| combine_ldimm64(insn, &hi))
            .map(RegValue::Const)
            .unwrap_or(RegValue::Unknown);
        return;
    }

    match insn.class() {
        BPF_ALU64 => advance_alu64_state(insn, regs),
        BPF_ALU => advance_alu32_state(insn, regs),
        BPF_LDX | BPF_LD => regs[insn.dst_reg() as usize] = RegValue::Unknown,
        _ => {}
    }
}

fn advance_alu64_state(insn: &BpfInsn, regs: &mut [RegValue; 11]) {
    let dst = insn.dst_reg() as usize;
    match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_X) => regs[dst] = regs[insn.src_reg() as usize],
        (BPF_MOV, BPF_K) => regs[dst] = RegValue::Const(insn.imm as i64),
        (BPF_ADD | BPF_SUB, BPF_K) => {
            regs[dst] = apply_alu64_imm(regs[dst], bpf_op(insn.code), insn.imm)
                .unwrap_or(RegValue::Unknown);
        }
        _ => regs[dst] = RegValue::Unknown,
    }
}

fn advance_alu32_state(insn: &BpfInsn, regs: &mut [RegValue; 11]) {
    let dst = insn.dst_reg() as usize;
    match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_X) => regs[dst] = mov32_value(regs[insn.src_reg() as usize]),
        (BPF_MOV, BPF_K) => regs[dst] = RegValue::Const(insn.imm as u32 as i64),
        (BPF_ADD, BPF_K) => regs[dst] = alu32_add_sub(regs[dst], insn.imm, true),
        (BPF_SUB, BPF_K) => regs[dst] = alu32_add_sub(regs[dst], insn.imm, false),
        _ => regs[dst] = RegValue::Unknown,
    }
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

fn combine_ldimm64(lo: &BpfInsn, hi: &BpfInsn) -> i64 {
    let low = lo.imm as u32 as u64;
    let high = hi.imm as u32 as u64;
    i64::from_le_bytes((low | (high << 32)).to_le_bytes())
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

fn jgt_reg(dst: u8, src: u8, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP | BPF_JGT | BPF_X,
        BpfInsn::make_regs(dst, src),
        off,
        0,
    )
}
