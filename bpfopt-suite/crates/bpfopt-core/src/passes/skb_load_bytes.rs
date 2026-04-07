// SPDX-License-Identifier: MIT
//! skb_load_bytes specialization pass.

use std::collections::BTreeMap;

use crate::analysis::{BranchTargetAnalysis, BranchTargetResult};
use crate::insn::*;
use crate::pass::*;

use super::utils::fixup_all_branches;

const BPF_ADD: u8 = 0x00;
const BPF_SUB: u8 = 0x10;

const BPF_FUNC_SKB_LOAD_BYTES: i32 = 26;

const BPF_PROG_TYPE_SCHED_CLS: u32 = 3;
const BPF_PROG_TYPE_SCHED_ACT: u32 = 4;

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
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![],
                diagnostics: vec![],
                ..Default::default()
            });
        }

        let Some(layout) = packet_ctx_layout(ctx.prog_type) else {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![],
                diagnostics: vec![],
                ..Default::default()
            });
        };

        let bt = analyses.get(&BranchTargetAnalysis, program);
        let scan = scan_sites(&program.insns, &bt);
        if scan.sites.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: scan.skips,
                diagnostics: vec![],
                ..Default::default()
            });
        }

        let old_insns = program.insns.clone();
        let (mut new_insns, addr_map) = rewrite_sites(&old_insns, &scan.sites, layout);
        fixup_all_branches(&mut new_insns, &old_insns, &addr_map);

        program.insns = new_insns;
        program.remap_annotations(&addr_map);
        program.log_transform(TransformEntry {
            sites_applied: scan.sites.len(),
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: true,
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
    insns.push(BpfInsn {
        code: BPF_JMP | BPF_CALL,
        regs: BpfInsn::make_regs(0, 0),
        off: 0,
        imm: BPF_FUNC_SKB_LOAD_BYTES,
    });

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
        for reg in 0..=5 {
            regs[reg] = RegValue::Unknown;
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
            Some(RegValue::FpPlusConst(i32::try_from(next).ok()?))
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
    BpfInsn {
        code: BPF_JMP | BPF_JGT | BPF_X,
        regs: BpfInsn::make_regs(dst, src),
        off,
        imm: 0,
    }
}

fn insn_width(insn: &BpfInsn) -> usize {
    if insn.is_ldimm64() {
        2
    } else {
        1
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    use crate::analysis::BranchTargetAnalysis;
    use crate::pass::{BpfProgram, PassContext, PassManager};

    const BPF_ADD: u8 = 0x00;

    const BPF_FUNC_SKB_LOAD_BYTES: i32 = 26;
    const BPF_FUNC_DUMMY_HELPER: i32 = 1;

    const BPF_PROG_TYPE_SOCKET_FILTER: u32 = 1;
    const BPF_PROG_TYPE_SCHED_CLS: u32 = 3;
    const BPF_PROG_TYPE_SCHED_ACT: u32 = 4;

    const SKB_DATA_OFF: i16 = 76;
    const SKB_DATA_END_OFF: i16 = 80;

    fn exit_insn() -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        }
    }

    fn helper_call(helper_id: i32) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_CALL,
            regs: BpfInsn::make_regs(0, 0),
            off: 0,
            imm: helper_id,
        }
    }

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JEQ | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    fn jne_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JNE | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    fn jgt_reg(dst: u8, src: u8, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JGT | BPF_X,
            regs: BpfInsn::make_regs(dst, src),
            off,
            imm: 0,
        }
    }

    fn make_skb_load_bytes_setup(offset: i32, stack_off: i32, len: i32) -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_imm(2, offset),
            BpfInsn::mov64_reg(3, 10),
            BpfInsn::alu64_imm(BPF_ADD, 3, stack_off),
            BpfInsn::mov64_imm(4, len),
        ]
    }

    fn make_skb_load_bytes_program(offset: i32, stack_off: i32, len: i32) -> Vec<BpfInsn> {
        let mut insns = make_skb_load_bytes_setup(offset, stack_off, len);
        insns.push(helper_call(BPF_FUNC_SKB_LOAD_BYTES));
        insns.push(jne_imm(0, 0, 2));
        insns.push(BpfInsn::mov64_imm(0, 1));
        insns.push(exit_insn());
        insns.push(BpfInsn::mov64_imm(0, 0));
        insns.push(exit_insn());
        insns
    }

    fn make_non_skb_helper_program() -> Vec<BpfInsn> {
        let mut insns = make_skb_load_bytes_setup(14, -8, 1);
        insns.push(helper_call(BPF_FUNC_DUMMY_HELPER));
        insns.push(jne_imm(0, 0, 2));
        insns.push(BpfInsn::mov64_imm(0, 1));
        insns.push(exit_insn());
        insns.push(BpfInsn::mov64_imm(0, 0));
        insns.push(exit_insn());
        insns
    }

    fn make_no_helper_calls_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::mov64_reg(2, 10),
            BpfInsn::alu64_imm(BPF_ADD, 2, -8),
            exit_insn(),
        ]
    }

    fn make_variable_offset_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_reg(2, 6),
            BpfInsn::mov64_reg(3, 10),
            BpfInsn::alu64_imm(BPF_ADD, 3, -8),
            BpfInsn::mov64_imm(4, 1),
            helper_call(BPF_FUNC_SKB_LOAD_BYTES),
            jne_imm(0, 0, 2),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    }

    fn make_variable_len_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_imm(2, 14),
            BpfInsn::mov64_reg(3, 10),
            BpfInsn::alu64_imm(BPF_ADD, 3, -8),
            BpfInsn::mov64_reg(4, 7),
            helper_call(BPF_FUNC_SKB_LOAD_BYTES),
            jne_imm(0, 0, 2),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    }

    fn make_two_call_program() -> Vec<BpfInsn> {
        let mut insns = vec![BpfInsn::mov64_reg(6, 1)];
        insns.extend(make_skb_load_bytes_setup(14, -8, 1));
        insns.push(helper_call(BPF_FUNC_SKB_LOAD_BYTES));
        insns.push(jne_imm(0, 0, 9));
        insns.push(BpfInsn::mov64_reg(1, 6));
        insns.extend(make_skb_load_bytes_setup(18, -16, 1));
        insns.push(helper_call(BPF_FUNC_SKB_LOAD_BYTES));
        insns.push(jne_imm(0, 0, 2));
        insns.push(BpfInsn::mov64_imm(0, 1));
        insns.push(exit_insn());
        insns.push(BpfInsn::mov64_imm(0, 0));
        insns.push(exit_insn());
        insns
    }

    fn make_prior_helper_without_ctx_reload_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_reg(6, 1),
            helper_call(BPF_FUNC_DUMMY_HELPER),
            BpfInsn::mov64_imm(2, 14),
            BpfInsn::mov64_reg(3, 10),
            BpfInsn::alu64_imm(BPF_ADD, 3, -8),
            BpfInsn::mov64_imm(4, 1),
            helper_call(BPF_FUNC_SKB_LOAD_BYTES),
            jne_imm(0, 0, 2),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    }

    fn make_prior_helper_with_ctx_reload_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_reg(6, 1),
            helper_call(BPF_FUNC_DUMMY_HELPER),
            BpfInsn::mov64_reg(1, 6),
            BpfInsn::mov64_imm(2, 14),
            BpfInsn::mov64_reg(3, 10),
            BpfInsn::alu64_imm(BPF_ADD, 3, -8),
            BpfInsn::mov64_imm(4, 1),
            helper_call(BPF_FUNC_SKB_LOAD_BYTES),
            jne_imm(0, 0, 2),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    }

    fn make_branch_around_program() -> Vec<BpfInsn> {
        let mut insns = vec![jeq_imm(0, 0, 6)];
        insns.extend(make_skb_load_bytes_program(14, -8, 1));
        insns
    }

    fn expected_call_replacement(offset: i32, len: i32) -> Vec<BpfInsn> {
        let mut insns = vec![
            BpfInsn::ldx_mem(BPF_W, 5, 1, SKB_DATA_OFF),
            BpfInsn::ldx_mem(BPF_W, 0, 1, SKB_DATA_END_OFF),
            BpfInsn::mov64_reg(2, 5),
            BpfInsn::alu64_imm(BPF_ADD, 2, offset + len),
            jgt_reg(2, 0, (3 + 2 * len) as i16),
            BpfInsn::alu64_imm(BPF_ADD, 5, offset),
        ];

        for i in 0..len {
            insns.push(BpfInsn::ldx_mem(BPF_B, 4, 5, i as i16));
            insns.push(BpfInsn::stx_mem(BPF_B, 3, 4, i as i16));
        }

        insns.push(BpfInsn::mov64_imm(0, 0));
        insns.push(BpfInsn::ja(3));
        insns.push(BpfInsn::mov64_imm(2, offset));
        insns.push(BpfInsn::mov64_imm(4, len));
        insns.push(helper_call(BPF_FUNC_SKB_LOAD_BYTES));
        insns
    }

    fn expected_rewritten_program(offset: i32, stack_off: i32, len: i32) -> Vec<BpfInsn> {
        let mut insns = make_skb_load_bytes_setup(offset, stack_off, len);
        insns.extend(expected_call_replacement(offset, len));
        insns.push(jne_imm(0, 0, 2));
        insns.push(BpfInsn::mov64_imm(0, 1));
        insns.push(exit_insn());
        insns.push(BpfInsn::mov64_imm(0, 0));
        insns.push(exit_insn());
        insns
    }

    fn run_skb_load_bytes_pass(
        program: &mut BpfProgram,
        prog_type: u32,
    ) -> crate::pass::PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.add_pass(SkbLoadBytesSpecPass);

        let mut ctx = PassContext::test_default();
        ctx.prog_type = prog_type;
        pm.run(program, &ctx).unwrap()
    }

    fn count_ctx_access(insns: &[BpfInsn], off: i16) -> usize {
        insns
            .iter()
            .filter(|insn| {
                insn.is_ldx_mem()
                    && bpf_size(insn.code) == BPF_W
                    && insn.src_reg() == 1
                    && insn.off == off
            })
            .count()
    }

    #[test]
    fn test_empty_program() {
        let mut program = BpfProgram::new(vec![]);

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(!result.program_changed);
        assert!(program.insns.is_empty());
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_no_helper_calls() {
        let original = make_no_helper_calls_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_non_skb_helper_unchanged() {
        let original = make_non_skb_helper_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_single_skb_load_bytes_replaced() {
        let mut program = BpfProgram::new(make_skb_load_bytes_program(14, -8, 1));

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, expected_rewritten_program(14, -8, 1));
    }

    #[test]
    fn test_constant_offset_and_len_required() {
        let variable_offset = make_variable_offset_program();
        let mut offset_program = BpfProgram::new(variable_offset.clone());
        let offset_result = run_skb_load_bytes_pass(&mut offset_program, BPF_PROG_TYPE_SCHED_CLS);
        assert!(!offset_result.program_changed);
        assert_eq!(offset_program.insns, variable_offset);

        let variable_len = make_variable_len_program();
        let mut len_program = BpfProgram::new(variable_len.clone());
        let len_result = run_skb_load_bytes_pass(&mut len_program, BPF_PROG_TYPE_SCHED_CLS);
        assert!(!len_result.program_changed);
        assert_eq!(len_program.insns, variable_len);
    }

    #[test]
    fn test_ctx_arg_must_be_reloaded_after_prior_helper_call() {
        let original = make_prior_helper_without_ctx_reload_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason == "arg1 is not ctx"));
    }

    #[test]
    fn test_ctx_reload_from_callee_saved_reg_is_accepted() {
        let mut expected = make_prior_helper_with_ctx_reload_program();
        let call_pc = 7usize;
        expected.splice(call_pc..=call_pc, expected_call_replacement(14, 1));

        let mut program = BpfProgram::new(make_prior_helper_with_ctx_reload_program());

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, expected);
    }

    #[test]
    fn test_only_small_constant_lengths_are_specialized() {
        let original = make_skb_load_bytes_program(14, -16, 9);
        let mut program = BpfProgram::new(original.clone());

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason == "len > 8"));
    }

    #[test]
    fn test_only_tc_programs() {
        let expected = expected_rewritten_program(14, -8, 1);

        let mut cls_program = BpfProgram::new(make_skb_load_bytes_program(14, -8, 1));
        let cls_result = run_skb_load_bytes_pass(&mut cls_program, BPF_PROG_TYPE_SCHED_CLS);
        assert!(cls_result.program_changed);
        assert_eq!(cls_result.pass_results[0].sites_applied, 1);
        assert_eq!(cls_program.insns, expected);

        let mut act_program = BpfProgram::new(make_skb_load_bytes_program(14, -8, 1));
        let act_result = run_skb_load_bytes_pass(&mut act_program, BPF_PROG_TYPE_SCHED_ACT);
        assert!(act_result.program_changed);
        assert_eq!(act_result.pass_results[0].sites_applied, 1);
        assert_eq!(act_program.insns, expected_rewritten_program(14, -8, 1));

        let original = make_skb_load_bytes_program(14, -8, 1);
        let mut socket_filter_program = BpfProgram::new(original.clone());
        let socket_filter_result =
            run_skb_load_bytes_pass(&mut socket_filter_program, BPF_PROG_TYPE_SOCKET_FILTER);
        assert!(!socket_filter_result.program_changed);
        assert_eq!(socket_filter_program.insns, original);
    }

    #[test]
    fn test_supported_wide_lengths_stay_bytewise() {
        for len in [2, 4, 8] {
            let mut program = BpfProgram::new(make_skb_load_bytes_program(14, -16, len));

            let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

            assert!(result.program_changed, "len={len}");
            assert_eq!(result.pass_results[0].sites_applied, 1, "len={len}");
            assert_eq!(program.insns, expected_rewritten_program(14, -16, len));
        }
    }

    #[test]
    fn test_error_check_preserved() {
        let mut program = BpfProgram::new(make_skb_load_bytes_program(14, -8, 1));

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(result.program_changed);
        assert_eq!(program.insns[8], jgt_reg(2, 0, 5));
        assert_eq!(program.insns[17], jne_imm(0, 0, 2));
    }

    #[test]
    fn test_multiple_calls_in_sequence() {
        let original = make_two_call_program();
        let original_len = original.len();
        let mut program = BpfProgram::new(original);

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_ACT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 2);
        assert_eq!(count_ctx_access(&program.insns, SKB_DATA_OFF), 2);
        assert_eq!(count_ctx_access(&program.insns, SKB_DATA_END_OFF), 2);
        assert_eq!(program.insns.len(), original_len + 24);
    }

    #[test]
    fn test_output_fewer_or_equal_instructions() {
        let original = make_skb_load_bytes_program(14, -8, 1);
        let original_len = original.len();
        let mut program = BpfProgram::new(original);

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert!(program.insns.len() > original_len);
        assert!(program.insns.len() <= original_len + 12);
    }

    #[test]
    fn test_branch_fixup_correct() {
        let mut program = BpfProgram::new(make_branch_around_program());

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(result.program_changed);
        assert_eq!(program.insns[0], jeq_imm(0, 0, 18));
    }
}
