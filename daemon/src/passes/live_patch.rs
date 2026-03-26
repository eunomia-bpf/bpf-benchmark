// SPDX-License-Identifier: MIT
//! Live-patching security pass.

use std::collections::{BTreeMap, HashSet};

use crate::analysis::{BranchTargetAnalysis, BranchTargetResult, LivenessAnalysis, LivenessResult};
use crate::insn::*;
use crate::pass::*;

use super::utils::fixup_all_branches;

const BPF_ADD: u8 = 0x00;

const BPF_PROG_TYPE_SCHED_CLS: u32 = 3;
const BPF_PROG_TYPE_SCHED_ACT: u32 = 4;
const BPF_PROG_TYPE_XDP: u32 = 6;

const BPF_FUNC_MAP_LOOKUP_ELEM: i32 = 1;
const BPF_FUNC_SKB_STORE_BYTES: i32 = 9;
const BPF_FUNC_TAIL_CALL: i32 = 12;
const BPF_FUNC_PROBE_READ: i32 = 4;
const BPF_FUNC_PROBE_WRITE_USER: i32 = 36;
const BPF_FUNC_PROBE_READ_STR: i32 = 45;
const BPF_FUNC_XDP_ADJUST_HEAD: i32 = 44;
const BPF_FUNC_PROBE_READ_USER: i32 = 112;
const BPF_FUNC_PROBE_READ_KERNEL: i32 = 113;
const BPF_FUNC_PROBE_READ_USER_STR: i32 = 114;
const BPF_FUNC_PROBE_READ_KERNEL_STR: i32 = 115;
const BPF_FUNC_COPY_FROM_USER: i32 = 148;

const XDP_DATA_OFF: i16 = 0;
const XDP_DATA_END_OFF: i16 = 4;
const SKB_DATA_OFF: i16 = 76;
const SKB_DATA_END_OFF: i16 = 80;

const POINTER_REFRESH_WINDOW: usize = 16;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct PacketCtxLayout {
    data_off: i16,
    data_end_off: i16,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct MaybeNullPtr {
    helper_id: i32,
    guarded: bool,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct NullGuardSite {
    deref_pc: usize,
    ptr_reg: u8,
    helper_id: i32,
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct HelperSanitizeSite {
    call_pc: usize,
    helper_id: i32,
    arg_regs: Vec<u8>,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct PointerRefreshSite {
    call_pc: usize,
    stale_use_pc: usize,
    helper_id: i32,
    ctx_reg: u8,
    data_reg: u8,
    data_end_reg: u8,
    scratch_reg: u8,
    access_end: i32,
    layout: PacketCtxLayout,
    needs_ctx_save: bool,
}

#[derive(Default)]
struct ScanResult {
    null_guards: Vec<NullGuardSite>,
    helper_sanitizers: Vec<HelperSanitizeSite>,
    pointer_refreshes: Vec<PointerRefreshSite>,
    tail_call_pcs: Vec<usize>,
    skips: Vec<SkipReason>,
}

#[derive(Clone, Copy)]
struct InjectedInsn {
    insn: BpfInsn,
    needs_safe_exit: bool,
}

impl InjectedInsn {
    fn plain(insn: BpfInsn) -> Self {
        Self {
            insn,
            needs_safe_exit: false,
        }
    }

    fn safe_exit_jump(insn: BpfInsn) -> Self {
        Self {
            insn,
            needs_safe_exit: true,
        }
    }
}

/// Phase-1 live patching pass for verifier-CVE hardening.
pub struct LivePatchPass;

impl BpfPass for LivePatchPass {
    fn name(&self) -> &str {
        "live_patch"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Security
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["cfg", "branch_targets", "liveness"]
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

        let bt = analyses.get(&BranchTargetAnalysis, program);
        let liveness = analyses.get(&LivenessAnalysis, program);

        let mut scan = ScanResult::default();
        scan_null_guard_sites(&program.insns, &bt, &mut scan);
        scan_helper_sanitization_sites(&program.insns, &bt, &mut scan);
        scan_tail_call_sites(&program.insns, &mut scan);
        if let Some(layout) = packet_ctx_layout(ctx.prog_type) {
            scan_pointer_refresh_sites(&program.insns, &bt, &liveness, layout, &mut scan);
        }

        let sites_applied = scan.null_guards.len()
            + scan.helper_sanitizers.len()
            + scan.pointer_refreshes.len()
            + scan.tail_call_pcs.len();
        if sites_applied == 0 {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: scan.skips,
                diagnostics: vec![],
                ..Default::default()
            });
        }

        let diagnostics = build_diagnostics(&scan);
        let old_insns = program.insns.clone();
        let (mut new_insns, addr_map) = rewrite_sites(&old_insns, &scan);
        fixup_all_branches(&mut new_insns, &old_insns, &addr_map);

        program.insns = new_insns;
        program.remap_annotations(&addr_map);
        program.log_transform(TransformEntry { sites_applied });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: true,
            sites_applied,
            sites_skipped: scan.skips,
            diagnostics,
            ..Default::default()
        })
    }
}

fn packet_ctx_layout(prog_type: u32) -> Option<PacketCtxLayout> {
    match prog_type {
        BPF_PROG_TYPE_XDP => Some(PacketCtxLayout {
            data_off: XDP_DATA_OFF,
            data_end_off: XDP_DATA_END_OFF,
        }),
        BPF_PROG_TYPE_SCHED_CLS | BPF_PROG_TYPE_SCHED_ACT => Some(PacketCtxLayout {
            data_off: SKB_DATA_OFF,
            data_end_off: SKB_DATA_END_OFF,
        }),
        _ => None,
    }
}

fn helper_returns_ptr_or_null(helper_id: i32) -> bool {
    matches!(helper_id, BPF_FUNC_MAP_LOOKUP_ELEM)
}

fn helper_sanitize_regs(helper_id: i32) -> Option<&'static [u8]> {
    match helper_id {
        BPF_FUNC_PROBE_READ
        | BPF_FUNC_PROBE_WRITE_USER
        | BPF_FUNC_PROBE_READ_STR
        | BPF_FUNC_PROBE_READ_USER
        | BPF_FUNC_PROBE_READ_KERNEL
        | BPF_FUNC_PROBE_READ_USER_STR
        | BPF_FUNC_PROBE_READ_KERNEL_STR
        | BPF_FUNC_COPY_FROM_USER => Some(&[2]),
        _ => None,
    }
}

fn helper_may_invalidate_packet_pointers(helper_id: i32) -> bool {
    matches!(
        helper_id,
        BPF_FUNC_SKB_STORE_BYTES | BPF_FUNC_XDP_ADJUST_HEAD
    )
}

fn build_diagnostics(scan: &ScanResult) -> Vec<String> {
    let mut diagnostics = Vec::new();

    for site in &scan.null_guards {
        diagnostics.push(format!(
            "pc {}: inserted null guard for r{} after helper #{}",
            site.deref_pc, site.ptr_reg, site.helper_id
        ));
    }
    for site in &scan.helper_sanitizers {
        diagnostics.push(format!(
            "pc {}: sanitized helper #{} args {:?}",
            site.call_pc, site.helper_id, site.arg_regs
        ));
    }
    for site in &scan.pointer_refreshes {
        diagnostics.push(format!(
            "pc {}: refreshed packet pointers after helper #{} using r{}",
            site.call_pc, site.helper_id, site.ctx_reg
        ));
    }
    for &pc in &scan.tail_call_pcs {
        diagnostics.push(format!("pc {pc}: isolated tail-call edge"));
    }

    diagnostics
}

fn scan_null_guard_sites(insns: &[BpfInsn], bt: &BranchTargetResult, scan: &mut ScanResult) {
    let mut maybe_null: [Option<MaybeNullPtr>; 11] = [None; 11];
    let mut pc = 0usize;

    while pc < insns.len() {
        if pc > 0 && bt.is_target.get(pc).copied().unwrap_or(false) {
            maybe_null = [None; 11];
        }

        let insn = insns[pc];
        if let Some(ptr_reg) = mem_base_reg(&insn).filter(|&reg| reg != 10) {
            if let Some(mut ptr) = maybe_null[ptr_reg as usize] {
                if ptr.guarded {
                    scan.skips.push(SkipReason {
                        pc,
                        reason: "already_guarded".into(),
                    });
                } else if bt.is_target.get(pc).copied().unwrap_or(false) {
                    scan.skips.push(SkipReason {
                        pc,
                        reason: "null-guard deref is branch target".into(),
                    });
                } else {
                    scan.null_guards.push(NullGuardSite {
                        deref_pc: pc,
                        ptr_reg,
                        helper_id: ptr.helper_id,
                    });
                    ptr.guarded = true;
                    maybe_null[ptr_reg as usize] = Some(ptr);
                }
            }
        }

        advance_null_guard_state(insns, pc, &mut maybe_null);
        pc += insn_width(&insn);
    }
}

fn advance_null_guard_state(
    insns: &[BpfInsn],
    pc: usize,
    maybe_null: &mut [Option<MaybeNullPtr>; 11],
) {
    let insn = insns[pc];

    if insn.is_call() && insn.src_reg() == 0 {
        maybe_null[0] = helper_returns_ptr_or_null(insn.imm).then_some(MaybeNullPtr {
            helper_id: insn.imm,
            guarded: false,
        });
        for reg in 1..=5 {
            maybe_null[reg] = None;
        }
        return;
    }

    if is_explicit_null_guard(&insn) {
        let reg = insn.dst_reg() as usize;
        if let Some(mut ptr) = maybe_null[reg] {
            ptr.guarded = true;
            maybe_null[reg] = Some(ptr);
        }
    }

    match insn.class() {
        BPF_ALU64 | BPF_ALU => {
            let dst = insn.dst_reg() as usize;
            if bpf_op(insn.code) == BPF_MOV && bpf_src(insn.code) == BPF_X {
                maybe_null[dst] = maybe_null[insn.src_reg() as usize];
            } else {
                maybe_null[dst] = None;
            }
        }
        BPF_LDX | BPF_LD => {
            maybe_null[insn.dst_reg() as usize] = None;
        }
        _ => {}
    }
}

fn is_explicit_null_guard(insn: &BpfInsn) -> bool {
    insn.code == (BPF_JMP | BPF_JEQ | BPF_K) && insn.imm == 0
}

fn scan_helper_sanitization_sites(
    insns: &[BpfInsn],
    bt: &BranchTargetResult,
    scan: &mut ScanResult,
) {
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = insns[pc];
        if insn.is_call() && insn.src_reg() == 0 {
            if let Some(arg_regs) = helper_sanitize_regs(insn.imm) {
                if bt.is_target.get(pc).copied().unwrap_or(false) {
                    scan.skips.push(SkipReason {
                        pc,
                        reason: "helper call is branch target".into(),
                    });
                } else {
                    let window_start = linear_window_start(bt, pc);
                    let missing_regs = arg_regs
                        .iter()
                        .copied()
                        .filter(|&reg| !arg_recently_zeroed(reg, window_start, pc, insns))
                        .collect::<Vec<_>>();

                    if missing_regs.is_empty() {
                        scan.skips.push(SkipReason {
                            pc,
                            reason: "helper args already sanitized".into(),
                        });
                    } else {
                        scan.helper_sanitizers.push(HelperSanitizeSite {
                            call_pc: pc,
                            helper_id: insn.imm,
                            arg_regs: missing_regs,
                        });
                    }
                }
            }
        }

        pc += insn_width(&insn);
    }
}

fn arg_recently_zeroed(arg_reg: u8, block_start: usize, call_pc: usize, insns: &[BpfInsn]) -> bool {
    let mut cursor = call_pc;
    while let Some(pc) = prev_insn_pc(insns, cursor) {
        if pc < block_start {
            break;
        }
        let insn = insns[pc];
        if insn == BpfInsn::mov64_imm(arg_reg, 0) {
            return true;
        }
        if writes_reg(&insn, arg_reg) {
            return false;
        }
        cursor = pc;
    }
    false
}

fn scan_tail_call_sites(insns: &[BpfInsn], scan: &mut ScanResult) {
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = insns[pc];
        if insn.is_call() && insn.src_reg() == 0 && insn.imm == BPF_FUNC_TAIL_CALL {
            scan.tail_call_pcs.push(pc);
        }
        pc += insn_width(&insn);
    }
}

fn scan_pointer_refresh_sites(
    insns: &[BpfInsn],
    bt: &BranchTargetResult,
    liveness: &LivenessResult,
    layout: PacketCtxLayout,
    scan: &mut ScanResult,
) {
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = insns[pc];
        if insn.is_call() && insn.src_reg() == 0 && helper_may_invalidate_packet_pointers(insn.imm)
        {
            match classify_pointer_refresh_site(insns, bt, liveness, pc, layout) {
                Ok(Some(site)) => scan.pointer_refreshes.push(site),
                Ok(None) => {}
                Err(reason) => scan.skips.push(SkipReason { pc, reason }),
            }
        }

        pc += insn_width(&insn);
    }
}

fn classify_pointer_refresh_site(
    insns: &[BpfInsn],
    bt: &BranchTargetResult,
    liveness: &LivenessResult,
    call_pc: usize,
    layout: PacketCtxLayout,
) -> Result<Option<PointerRefreshSite>, String> {
    if bt.is_target.get(call_pc).copied().unwrap_or(false) {
        return Err("packet helper call is branch target".into());
    }

    let window_start = linear_window_start(bt, call_pc);
    let existing_ctx_reg = find_ctx_save_reg(insns, window_start, call_pc);
    let (data_reg, data_end_reg) =
        find_packet_root_regs(insns, window_start, call_pc, layout, existing_ctx_reg)
            .ok_or_else(|| "missing packet data/data_end roots before helper".to_string())?;

    let window_end = (call_pc + 1 + POINTER_REFRESH_WINDOW).min(insns.len());
    let mut stale_use_pc = None;

    let mut cursor = call_pc + 1;
    while cursor < window_end {
        if cursor > call_pc + 1 && bt.is_target.get(cursor).copied().unwrap_or(false) {
            break;
        }

        let insn = insns[cursor];
        if writes_reg(&insn, data_reg) || writes_reg(&insn, data_end_reg) {
            break;
        }

        if let Some(ctx_reg) = existing_ctx_reg {
            if writes_reg(&insn, ctx_reg) {
                break;
            }
            if packet_pointers_already_refreshed(
                insns,
                cursor,
                window_end,
                ctx_reg,
                data_reg,
                data_end_reg,
                layout,
            ) {
                return Err("packet pointers already refreshed".into());
            }
        }

        if mem_base_reg(&insn) == Some(data_reg) {
            stale_use_pc = Some(cursor);
            break;
        }
        cursor += insn_width(&insn);
    }

    let Some(stale_use_pc) = stale_use_pc else {
        return Ok(None);
    };

    let access_end = access_end_for_packet_use(&insns[stale_use_pc])
        .ok_or_else(|| "stale packet use has unsupported width".to_string())?;
    let stale_live_out = liveness
        .live_out
        .get(stale_use_pc)
        .ok_or_else(|| "missing liveness at stale packet use".to_string())?;

    let mut reserved = vec![data_reg, data_end_reg];
    let (ctx_reg, needs_ctx_save) = if let Some(ctx_reg) = existing_ctx_reg {
        reserved.push(ctx_reg);
        (ctx_reg, false)
    } else {
        let live_out = liveness
            .live_out
            .get(call_pc)
            .ok_or_else(|| "missing liveness at packet helper call".to_string())?;
        let ctx_reg = pick_dead_callee_saved(live_out, &reserved, &[9, 8, 7, 6])
            .ok_or_else(|| "no dead callee-saved register for ctx save".to_string())?;
        reserved.push(ctx_reg);
        (ctx_reg, true)
    };

    let scratch_reg = pick_dead_callee_saved(stale_live_out, &reserved, &[8, 9, 7, 6])
        .ok_or_else(|| "no dead callee-saved register for packet guard".to_string())?;

    Ok(Some(PointerRefreshSite {
        call_pc,
        stale_use_pc,
        helper_id: insns[call_pc].imm,
        ctx_reg,
        data_reg,
        data_end_reg,
        scratch_reg,
        access_end,
        layout,
        needs_ctx_save,
    }))
}

fn find_ctx_save_reg(insns: &[BpfInsn], block_start: usize, call_pc: usize) -> Option<u8> {
    let mut cursor = call_pc;
    let mut clobbered = [false; 11];

    while let Some(pc) = prev_insn_pc(insns, cursor) {
        if pc < block_start {
            break;
        }

        let insn = insns[pc];
        if insn == BpfInsn::mov64_reg(6, 1)
            || insn == BpfInsn::mov64_reg(7, 1)
            || insn == BpfInsn::mov64_reg(8, 1)
            || insn == BpfInsn::mov64_reg(9, 1)
        {
            let reg = insn.dst_reg() as usize;
            if !clobbered[reg] {
                return Some(insn.dst_reg());
            }
        }

        for reg in 6..=9 {
            if writes_reg(&insn, reg) {
                clobbered[reg as usize] = true;
            }
        }
        cursor = pc;
    }
    None
}

fn find_packet_root_regs(
    insns: &[BpfInsn],
    block_start: usize,
    call_pc: usize,
    layout: PacketCtxLayout,
    ctx_reg: Option<u8>,
) -> Option<(u8, u8)> {
    let mut data_reg = None;
    let mut data_end_reg = None;
    let mut cursor = call_pc;
    let mut clobbered = [false; 11];

    while let Some(pc) = prev_insn_pc(insns, cursor) {
        if pc < block_start {
            break;
        }

        let insn = insns[pc];
        if data_reg.is_none() && is_packet_ctx_load(&insn, layout.data_off, ctx_reg) {
            let reg = insn.dst_reg() as usize;
            if !clobbered[reg] {
                data_reg = Some(insn.dst_reg());
            }
        }
        if data_end_reg.is_none() && is_packet_ctx_load(&insn, layout.data_end_off, ctx_reg) {
            let reg = insn.dst_reg() as usize;
            if !clobbered[reg] {
                data_end_reg = Some(insn.dst_reg());
            }
        }
        if data_reg.is_some() && data_end_reg.is_some() {
            break;
        }

        for reg in 0..=10 {
            if writes_reg(&insn, reg) {
                clobbered[reg as usize] = true;
            }
        }
        cursor = pc;
    }

    Some((data_reg?, data_end_reg?))
}

fn is_packet_ctx_load(insn: &BpfInsn, off: i16, ctx_reg: Option<u8>) -> bool {
    if insn.code != (BPF_LDX | BPF_W | BPF_MEM) || insn.off != off {
        return false;
    }

    insn.src_reg() == 1 || Some(insn.src_reg()) == ctx_reg
}

fn packet_pointers_already_refreshed(
    insns: &[BpfInsn],
    cursor: usize,
    window_end: usize,
    ctx_reg: u8,
    data_reg: u8,
    data_end_reg: u8,
    layout: PacketCtxLayout,
) -> bool {
    if cursor + 1 >= window_end {
        return false;
    }

    insns[cursor] == BpfInsn::ldx_mem(BPF_W, data_reg, ctx_reg, layout.data_off)
        && insns[cursor + 1] == BpfInsn::ldx_mem(BPF_W, data_end_reg, ctx_reg, layout.data_end_off)
}

fn access_end_for_packet_use(insn: &BpfInsn) -> Option<i32> {
    let width = match bpf_size(insn.code) {
        BPF_B => 1,
        BPF_H => 2,
        BPF_W => 4,
        BPF_DW => 8,
        _ => return None,
    };

    Some(insn.off as i32 + width)
}

fn pick_dead_callee_saved(live: &HashSet<u8>, reserved: &[u8], order: &[u8]) -> Option<u8> {
    order
        .iter()
        .copied()
        .find(|reg| !reserved.contains(reg) && !live.contains(reg))
}

fn linear_window_start(bt: &BranchTargetResult, pc: usize) -> usize {
    let mut cursor = pc;
    while cursor > 0 {
        if bt.is_target.get(cursor).copied().unwrap_or(false) {
            return cursor;
        }
        cursor -= 1;
    }
    0
}

fn rewrite_sites(old_insns: &[BpfInsn], scan: &ScanResult) -> (Vec<BpfInsn>, Vec<usize>) {
    let mut pre_insertions: BTreeMap<usize, Vec<InjectedInsn>> = BTreeMap::new();
    let mut post_insertions: BTreeMap<usize, Vec<InjectedInsn>> = BTreeMap::new();
    let mut replacements: BTreeMap<usize, Vec<BpfInsn>> = BTreeMap::new();
    let mut needs_safe_exit = false;

    for site in &scan.null_guards {
        pre_insertions
            .entry(site.deref_pc)
            .or_default()
            .push(InjectedInsn::safe_exit_jump(jeq_imm(site.ptr_reg, 0, 0)));
        needs_safe_exit = true;
    }

    for site in &scan.helper_sanitizers {
        let entry = pre_insertions.entry(site.call_pc).or_default();
        for &reg in &site.arg_regs {
            entry.push(InjectedInsn::plain(BpfInsn::mov64_imm(reg, 0)));
        }
    }

    for site in &scan.pointer_refreshes {
        if site.needs_ctx_save {
            pre_insertions
                .entry(site.call_pc)
                .or_default()
                .push(InjectedInsn::plain(BpfInsn::mov64_reg(site.ctx_reg, 1)));
        }

        post_insertions.entry(site.call_pc).or_default().extend([
            InjectedInsn::plain(BpfInsn::ldx_mem(
                BPF_W,
                site.data_reg,
                site.ctx_reg,
                site.layout.data_off,
            )),
            InjectedInsn::plain(BpfInsn::ldx_mem(
                BPF_W,
                site.data_end_reg,
                site.ctx_reg,
                site.layout.data_end_off,
            )),
            InjectedInsn::plain(BpfInsn::mov64_reg(site.scratch_reg, site.data_reg)),
            InjectedInsn::plain(BpfInsn::alu64_imm(
                BPF_ADD,
                site.scratch_reg,
                site.access_end,
            )),
            InjectedInsn::safe_exit_jump(jgt_reg(site.scratch_reg, site.data_end_reg, 0)),
        ]);
        needs_safe_exit = true;
    }

    for &pc in &scan.tail_call_pcs {
        replacements.insert(pc, vec![BpfInsn::mov64_imm(0, 0)]);
    }

    let mut new_insns = Vec::with_capacity(old_insns.len() + 16);
    let mut addr_map = vec![0usize; old_insns.len() + 1];
    let mut safe_exit_jump_pcs = Vec::new();
    let mut pc = 0usize;

    while pc < old_insns.len() {
        if let Some(insertions) = pre_insertions.get(&pc) {
            emit_insertions(insertions, &mut new_insns, &mut safe_exit_jump_pcs);
        }

        let old_pc = pc;
        addr_map[old_pc] = new_insns.len();

        if let Some(replacement) = replacements.get(&old_pc) {
            new_insns.extend_from_slice(replacement);
            let width = insn_width(&old_insns[old_pc]);
            for extra_pc in 1..width {
                addr_map[old_pc + extra_pc] = new_insns.len();
            }
            pc += width;
        } else {
            let insn = old_insns[pc];
            new_insns.push(insn);
            if insn.is_ldimm64() && pc + 1 < old_insns.len() {
                pc += 1;
                addr_map[pc] = new_insns.len();
                new_insns.push(old_insns[pc]);
            }
            pc += 1;
        }

        if let Some(insertions) = post_insertions.get(&old_pc) {
            emit_insertions(insertions, &mut new_insns, &mut safe_exit_jump_pcs);
        }
    }
    addr_map[old_insns.len()] = new_insns.len();

    if needs_safe_exit {
        let safe_exit_pc = new_insns.len();
        new_insns.push(BpfInsn::mov64_imm(0, 0));
        new_insns.push(exit_insn());

        for jump_pc in safe_exit_jump_pcs {
            let off = safe_exit_pc as i64 - (jump_pc as i64 + 1);
            new_insns[jump_pc].off = off as i16;
        }
    }

    (new_insns, addr_map)
}

fn emit_insertions(
    insertions: &[InjectedInsn],
    new_insns: &mut Vec<BpfInsn>,
    safe_exit_jump_pcs: &mut Vec<usize>,
) {
    for insertion in insertions {
        let new_pc = new_insns.len();
        new_insns.push(insertion.insn);
        if insertion.needs_safe_exit {
            safe_exit_jump_pcs.push(new_pc);
        }
    }
}

fn writes_reg(insn: &BpfInsn, reg: u8) -> bool {
    match insn.class() {
        BPF_ALU64 | BPF_ALU | BPF_LDX | BPF_LD => insn.dst_reg() == reg,
        BPF_JMP | BPF_JMP32 if insn.is_call() => reg <= 5,
        _ => false,
    }
}

fn prev_insn_pc(insns: &[BpfInsn], pc: usize) -> Option<usize> {
    if pc == 0 {
        return None;
    }

    if pc >= 2 && insns[pc - 2].is_ldimm64() {
        Some(pc - 2)
    } else {
        Some(pc - 1)
    }
}

fn mem_base_reg(insn: &BpfInsn) -> Option<u8> {
    match insn.class() {
        BPF_LDX if bpf_mode(insn.code) == BPF_MEM => Some(insn.src_reg()),
        BPF_ST | BPF_STX if bpf_mode(insn.code) == BPF_MEM => Some(insn.dst_reg()),
        _ => None,
    }
}

fn insn_width(insn: &BpfInsn) -> usize {
    if insn.is_ldimm64() {
        2
    } else {
        1
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

fn jgt_reg(dst: u8, src: u8, off: i16) -> BpfInsn {
    BpfInsn {
        code: BPF_JMP | BPF_JGT | BPF_X,
        regs: BpfInsn::make_regs(dst, src),
        off,
        imm: 0,
    }
}

fn exit_insn() -> BpfInsn {
    BpfInsn {
        code: BPF_JMP | BPF_EXIT,
        regs: 0,
        off: 0,
        imm: 0,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    use crate::analysis::{BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis};
    use crate::pass::{BpfProgram, PassContext, PassManager, PipelineResult};

    const BPF_ADD: u8 = 0x00;

    const BPF_PROG_TYPE_TRACEPOINT: u32 = 5;
    const BPF_PROG_TYPE_XDP: u32 = 6;
    const BPF_PROG_TYPE_RAW_TRACEPOINT: u32 = 17;

    const BPF_FUNC_MAP_LOOKUP_ELEM: i32 = 1;
    const BPF_FUNC_TAIL_CALL: i32 = 12;
    const BPF_FUNC_XDP_ADJUST_HEAD: i32 = 44;
    const BPF_FUNC_PROBE_READ_KERNEL: i32 = 113;

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

    fn jgt_reg(dst: u8, src: u8, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JGT | BPF_X,
            regs: BpfInsn::make_regs(dst, src),
            off,
            imm: 0,
        }
    }

    fn run_live_patch_pass(program: &mut BpfProgram, prog_type: u32) -> PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(CFGAnalysis);
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(LivenessAnalysis);
        pm.add_pass(LivePatchPass);

        let mut ctx = PassContext::test_default();
        ctx.prog_type = prog_type;
        pm.run(program, &ctx).unwrap()
    }

    fn make_safe_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_imm(1, 42),
            BpfInsn::mov64_reg(0, 1),
            exit_insn(),
        ]
    }

    fn make_null_guard_vulnerable_program() -> Vec<BpfInsn> {
        vec![
            helper_call(BPF_FUNC_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(6, 0),
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
    }

    fn expected_null_guard_program() -> Vec<BpfInsn> {
        vec![
            helper_call(BPF_FUNC_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(6, 0),
            jeq_imm(6, 0, 3),
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    }

    fn make_null_guard_store_vulnerable_program() -> Vec<BpfInsn> {
        vec![
            helper_call(BPF_FUNC_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(6, 0),
            BpfInsn::stx_mem(BPF_W, 6, 2, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
    }

    fn expected_null_guard_store_program() -> Vec<BpfInsn> {
        vec![
            helper_call(BPF_FUNC_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(6, 0),
            jeq_imm(6, 0, 3),
            BpfInsn::stx_mem(BPF_W, 6, 2, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    }

    fn make_helper_arg_vulnerable_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_reg(2, 7),
            BpfInsn::mov64_imm(3, 16),
            helper_call(BPF_FUNC_PROBE_READ_KERNEL),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
    }

    fn expected_helper_arg_sanitized_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_reg(2, 7),
            BpfInsn::mov64_imm(3, 16),
            BpfInsn::mov64_imm(2, 0),
            helper_call(BPF_FUNC_PROBE_READ_KERNEL),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
    }

    fn make_pointer_refresh_vulnerable_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_reg(9, 1),
            BpfInsn::ldx_mem(BPF_W, 6, 1, 0),
            BpfInsn::ldx_mem(BPF_W, 7, 1, 4),
            helper_call(BPF_FUNC_XDP_ADJUST_HEAD),
            BpfInsn::ldx_mem(BPF_B, 2, 6, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
    }

    fn expected_pointer_refresh_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_reg(9, 1),
            BpfInsn::ldx_mem(BPF_W, 6, 1, 0),
            BpfInsn::ldx_mem(BPF_W, 7, 1, 4),
            helper_call(BPF_FUNC_XDP_ADJUST_HEAD),
            BpfInsn::ldx_mem(BPF_W, 6, 9, 0),
            BpfInsn::ldx_mem(BPF_W, 7, 9, 4),
            BpfInsn::mov64_reg(8, 6),
            BpfInsn::alu64_imm(BPF_ADD, 8, 1),
            jgt_reg(8, 7, 3),
            BpfInsn::ldx_mem(BPF_B, 2, 6, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    }

    fn make_pointer_refresh_ctx_save_clobbered_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_reg(9, 1),
            BpfInsn::mov64_imm(9, 0),
            BpfInsn::ldx_mem(BPF_W, 6, 1, 0),
            BpfInsn::ldx_mem(BPF_W, 7, 1, 4),
            helper_call(BPF_FUNC_XDP_ADJUST_HEAD),
            BpfInsn::ldx_mem(BPF_B, 2, 6, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
    }

    fn expected_pointer_refresh_ctx_save_clobbered_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_reg(9, 1),
            BpfInsn::mov64_imm(9, 0),
            BpfInsn::ldx_mem(BPF_W, 6, 1, 0),
            BpfInsn::ldx_mem(BPF_W, 7, 1, 4),
            BpfInsn::mov64_reg(9, 1),
            helper_call(BPF_FUNC_XDP_ADJUST_HEAD),
            BpfInsn::ldx_mem(BPF_W, 6, 9, 0),
            BpfInsn::ldx_mem(BPF_W, 7, 9, 4),
            BpfInsn::mov64_reg(8, 6),
            BpfInsn::alu64_imm(BPF_ADD, 8, 1),
            jgt_reg(8, 7, 3),
            BpfInsn::ldx_mem(BPF_B, 2, 6, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    }

    fn make_pointer_refresh_root_clobbered_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_reg(9, 1),
            BpfInsn::ldx_mem(BPF_W, 6, 9, 0),
            BpfInsn::ldx_mem(BPF_W, 7, 9, 4),
            BpfInsn::mov64_imm(6, 0),
            helper_call(BPF_FUNC_XDP_ADJUST_HEAD),
            BpfInsn::ldx_mem(BPF_B, 2, 6, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
    }

    fn make_tail_call_vulnerable_program() -> Vec<BpfInsn> {
        vec![
            helper_call(BPF_FUNC_TAIL_CALL),
            BpfInsn::mov64_imm(0, 7),
            exit_insn(),
        ]
    }

    fn expected_tail_call_isolated_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 7),
            exit_insn(),
        ]
    }

    fn make_multiple_vulnerabilities_program() -> Vec<BpfInsn> {
        vec![
            helper_call(BPF_FUNC_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(6, 0),
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            BpfInsn::mov64_reg(2, 7),
            helper_call(BPF_FUNC_PROBE_READ_KERNEL),
            helper_call(BPF_FUNC_TAIL_CALL),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
    }

    fn expected_multiple_vulnerabilities_program() -> Vec<BpfInsn> {
        vec![
            helper_call(BPF_FUNC_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(6, 0),
            jeq_imm(6, 0, 7),
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            BpfInsn::mov64_reg(2, 7),
            BpfInsn::mov64_imm(2, 0),
            helper_call(BPF_FUNC_PROBE_READ_KERNEL),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    }

    fn make_already_guarded_program() -> Vec<BpfInsn> {
        vec![
            helper_call(BPF_FUNC_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(6, 0),
            jeq_imm(6, 0, 3),
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    }

    fn make_branch_fixup_program() -> Vec<BpfInsn> {
        vec![
            jeq_imm(1, 0, 5),
            helper_call(BPF_FUNC_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(6, 0),
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 2),
            exit_insn(),
        ]
    }

    fn expected_branch_fixup_program() -> Vec<BpfInsn> {
        vec![
            jeq_imm(1, 0, 6),
            helper_call(BPF_FUNC_MAP_LOOKUP_ELEM),
            BpfInsn::mov64_reg(6, 0),
            jeq_imm(6, 0, 5),
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 2),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    }

    fn make_semantics_preserving_program() -> Vec<BpfInsn> {
        vec![
            jeq_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 42),
            exit_insn(),
            BpfInsn::mov64_reg(2, 7),
            helper_call(BPF_FUNC_PROBE_READ_KERNEL),
            BpfInsn::mov64_imm(0, 7),
            exit_insn(),
        ]
    }

    fn expected_semantics_preserving_program() -> Vec<BpfInsn> {
        vec![
            jeq_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 42),
            exit_insn(),
            BpfInsn::mov64_reg(2, 7),
            BpfInsn::mov64_imm(2, 0),
            helper_call(BPF_FUNC_PROBE_READ_KERNEL),
            BpfInsn::mov64_imm(0, 7),
            exit_insn(),
        ]
    }

    #[test]
    fn test_empty_program() {
        let mut program = BpfProgram::new(vec![]);

        let result = run_live_patch_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(!result.program_changed);
        assert!(program.insns.is_empty());
        assert_eq!(result.pass_results.len(), 1);
        assert_eq!(result.pass_results[0].pass_name, "live_patch");
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_no_vulnerable_patterns() {
        let original = make_safe_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_live_patch_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_null_guard_insertion() {
        let mut program = BpfProgram::new(make_null_guard_vulnerable_program());

        let result = run_live_patch_pass(&mut program, BPF_PROG_TYPE_RAW_TRACEPOINT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, expected_null_guard_program());
    }

    #[test]
    fn test_null_guard_insertion_for_store_deref() {
        let mut program = BpfProgram::new(make_null_guard_store_vulnerable_program());

        let result = run_live_patch_pass(&mut program, BPF_PROG_TYPE_RAW_TRACEPOINT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, expected_null_guard_store_program());
    }

    #[test]
    fn test_helper_arg_sanitization() {
        let mut program = BpfProgram::new(make_helper_arg_vulnerable_program());

        let result = run_live_patch_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, expected_helper_arg_sanitized_program());
    }

    #[test]
    fn test_pointer_refresh_after_helper() {
        let mut program = BpfProgram::new(make_pointer_refresh_vulnerable_program());

        let result = run_live_patch_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, expected_pointer_refresh_program());
    }

    #[test]
    fn test_pointer_refresh_reinserts_ctx_save_when_saved_ctx_was_clobbered() {
        let mut program = BpfProgram::new(make_pointer_refresh_ctx_save_clobbered_program());

        let result = run_live_patch_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(
            program.insns,
            expected_pointer_refresh_ctx_save_clobbered_program()
        );
    }

    #[test]
    fn test_pointer_refresh_skips_when_packet_root_was_clobbered_before_helper() {
        let original = make_pointer_refresh_root_clobbered_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_live_patch_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_tail_call_isolation() {
        let mut program = BpfProgram::new(make_tail_call_vulnerable_program());

        let result = run_live_patch_pass(&mut program, BPF_PROG_TYPE_XDP);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, expected_tail_call_isolated_program());
    }

    #[test]
    fn test_multiple_patches_composed() {
        let mut program = BpfProgram::new(make_multiple_vulnerabilities_program());

        let result = run_live_patch_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 3);
        assert_eq!(program.insns, expected_multiple_vulnerabilities_program());
    }

    #[test]
    fn test_safe_program_not_modified() {
        let original = make_already_guarded_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_live_patch_pass(&mut program, BPF_PROG_TYPE_RAW_TRACEPOINT);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_branch_fixup_after_insertion() {
        let mut program = BpfProgram::new(make_branch_fixup_program());

        let result = run_live_patch_pass(&mut program, BPF_PROG_TYPE_RAW_TRACEPOINT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, expected_branch_fixup_program());
    }

    #[test]
    fn test_patch_preserves_program_semantics() {
        let mut program = BpfProgram::new(make_semantics_preserving_program());

        let result = run_live_patch_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, expected_semantics_preserving_program());
    }
}
