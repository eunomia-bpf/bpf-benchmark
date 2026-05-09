// SPDX-License-Identifier: MIT
//! COND_SELECT optimization pass.

use std::collections::HashSet;

use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::utils::{
    emit_packed_kinsn_call_with_off, fixup_all_branches, kinsn_replacement_subprog_skip_reason,
    map_replacement_range, remap_kinsn_btf_metadata, resolve_kinsn_call_off_for_pass,
};

/// COND_SELECT pass: replaces branch+mov diamond patterns with
/// bpf_select64() kfunc calls (lowered to branchless select by the JIT).
///
/// Pattern A (4-insn diamond):
///   Jcc r_cond, X, +2 ; MOV r_dst, val_false ; JA +1 ; MOV r_dst, val_true
///
/// Emit (when kfunc available):
///   MOV r1, <true_val>       // arg1 = a (returned when cond != 0)
///   MOV r2, <false_val>      // arg2 = b (returned when cond == 0)
///   MOV r3, <cond_reg>       // arg3 = condition value
///   CALL bpf_select64        // r0 = bpf_select64(a, b, cond)
///   MOV dst, r0              // dst = result
///
/// The kfunc signature is: `u64 bpf_select64(u64 a, u64 b, u64 cond)`
/// Semantics: returns `a` if `cond != 0`, otherwise returns `b`.
///
pub struct CondSelectPass;

/// A detected cond-select site.
pub(super) struct CondSelectSite {
    pub(super) start_pc: usize,
    pub(super) old_len: usize,
    pub(super) cond_reg: u8,
    pub(super) dst_reg: u8,
    pub(super) true_val: CondSelectValue,
    pub(super) false_val: CondSelectValue,
    /// The JCC opcode (BPF_JNE, BPF_JEQ, etc.).
    pub(super) jcc_op: u8,
    /// The JCC immediate (for BPF_K source).
    pub(super) jcc_imm: i32,
    /// The JCC source kind (BPF_K or BPF_X).
    pub(super) jcc_src: u8,
    /// The full JCC instruction code (BPF_JMP/BPF_JMP32 + op + source).
    pub(super) jcc_code: u8,
    /// The JCC source register for BPF_X conditions.
    pub(super) jcc_src_reg: u8,
}

/// A cond_select site that has passed safety checks, ready for transformation.
struct SafeCondSelectSite {
    site: CondSelectSite,
    lowering: CondSelectLowering,
}

struct CondSelectLowering {
    prefix: Vec<BpfInsn>,
    a_reg: u8,
    b_reg: u8,
    cond_reg: u8,
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub(super) enum CondSelectValue {
    Reg(u8),
    Reg32(u8),
    Imm(i32),
    Imm32(i32),
}

impl CondSelectPass {
    /// Analyze the program and return all detected cond-select sites.
    ///
    /// This is the pure detection phase. Each returned `CondSelectSite`
    /// describes a JCC+MOV pattern that could be lowered to a select kfunc.
    pub(super) fn analyze(&self, insns: &[BpfInsn]) -> Vec<CondSelectSite> {
        scan_cond_select_sites(insns)
    }
}

impl BpfPass for CondSelectPass {
    fn name(&self) -> &str {
        "cond_select"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets", "liveness"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        // Check if the target can lower bpf_select64 to branchless select
        // (CMOV on x86, CSEL on ARM64).
        if !ctx.has_branchless_select() {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "platform lacks branchless select support".into(),
                },
            ));
        }

        // Check if bpf_select64 kfunc is available.
        if ctx.kinsn_registry.select64_btf_id < 0 {
            // Report detected sites without emitting when the target kfunc is absent.
            let sites = self.analyze(&program.insns);
            let diagnostics: Vec<String> = sites
                .iter()
                .map(|s| {
                    format!(
                        "cond_select site: pc={} len={} cond=r{} dst=r{} (kfunc unavailable)",
                        s.start_pc, s.old_len, s.cond_reg, s.dst_reg
                    )
                })
                .collect();
            if sites.is_empty() {
                return Ok(PassResult {
                    diagnostics,
                    ..PassResult::unchanged(self.name())
                });
            }
            return Ok(PassResult::skipped_with_diagnostics(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "bpf_select64 kfunc not available".into(),
                },
                diagnostics,
            ));
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);
        let liveness_analysis = LivenessAnalysis;
        let liveness = analyses.get(&liveness_analysis, program);

        let sites = self.analyze(&program.insns);
        let btf_id = ctx.kinsn_registry.select64_btf_id;
        let mut safe_sites: Vec<SafeCondSelectSite> = Vec::new();
        let mut skipped = Vec::new();

        for site in sites {
            let Some(live_after) = liveness.live_out.get(site.start_pc + site.old_len - 1) else {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "missing liveness for cond_select site".into(),
                });
                continue;
            };

            let lowering = match build_lowering(&site, live_after) {
                Ok(lowering) => lowering,
                Err(reason) => {
                    skipped.push(SkipReason {
                        pc: site.start_pc,
                        reason,
                    });
                    continue;
                }
            };

            // Safety check 1: interior branch target (excluding the JCC's own target).
            // For Pattern C (3-insn), the JCC is at start_pc+1, not start_pc.
            let jcc_pc = if site.old_len == 3 {
                site.start_pc + 1
            } else {
                site.start_pc
            };
            let jcc = &program.insns[jcc_pc];
            let own_target = (jcc_pc as i64 + 1 + jcc.off as i64) as usize;
            let has_interior = (site.start_pc + 1..site.start_pc + site.old_len)
                .any(|pc| pc < bt.is_target.len() && bt.is_target[pc] && pc != own_target);
            if has_interior {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "interior branch target".into(),
                });
                continue;
            }

            if let Some(reason) = kinsn_replacement_subprog_skip_reason(
                &program.insns,
                site.start_pc,
                site.old_len,
                lowering.prefix.len() + 2,
            )? {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason,
                });
                continue;
            }

            safe_sites.push(SafeCondSelectSite { site, lowering });
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                sites_skipped: skipped,
                ..PassResult::unchanged(self.name())
            });
        }

        let kfunc_off = resolve_kinsn_call_off_for_pass(ctx, self.name())?;

        // Build replacement instruction stream.
        let orig_len = program.insns.len();
        let mut new_insns = Vec::with_capacity(orig_len);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut pc = 0;
        let mut site_idx = 0;
        let mut applied = 0;

        while pc < orig_len {
            let new_pc = new_insns.len();
            addr_map[pc] = new_pc;

            if site_idx < safe_sites.len() && pc == safe_sites[site_idx].site.start_pc {
                let safe_site = &safe_sites[site_idx];
                let site = &safe_site.site;
                new_insns.extend_from_slice(&safe_site.lowering.prefix);
                let payload = (site.dst_reg as u64)
                    | ((safe_site.lowering.a_reg as u64) << 4)
                    | ((safe_site.lowering.b_reg as u64) << 8)
                    | ((safe_site.lowering.cond_reg as u64) << 12);
                let replacement = emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off);
                new_insns.extend_from_slice(&replacement);
                let replacement_len = safe_site.lowering.prefix.len() + replacement.len();
                map_replacement_range(&mut addr_map, pc, site.old_len, new_pc, replacement_len);

                pc += site.old_len;
                site_idx += 1;
                applied += 1;
            } else {
                new_insns.push(program.insns[pc]);
                if program.insns[pc].is_ldimm64() && pc + 1 < orig_len {
                    pc += 1;
                    addr_map[pc] = new_insns.len();
                    new_insns.push(program.insns[pc]);
                }
                pc += 1;
            }
        }
        addr_map[orig_len] = new_insns.len();

        // Branch fixup.
        fixup_all_branches(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        remap_kinsn_btf_metadata(program, &ctx.kinsn_registry)?;
        program.remap_annotations(&addr_map);

        Ok(PassResult {
            pass_name: self.name().into(),
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

fn scan_cond_select_sites(insns: &[BpfInsn]) -> Vec<CondSelectSite> {
    let mut sites = Vec::new();
    let n = insns.len();
    let mut pc = 0;
    while pc < n {
        if let Some(site) = try_match_cond_select(insns, pc) {
            let len = site.old_len;
            sites.push(site);
            pc += len;
        } else {
            pc += 1;
        }
    }
    sites
}

fn try_match_cond_select(insns: &[BpfInsn], pc: usize) -> Option<CondSelectSite> {
    let n = insns.len();

    // Pattern A: 4-insn diamond
    //   Jcc +2 ; MOV dst, false_val ; JA +1 ; MOV dst, true_val
    if pc + 3 < n {
        let jcc = &insns[pc];
        if jcc.is_cond_jmp() && jcc.off == 2 {
            let mov_false = &insns[pc + 1];
            let ja = &insns[pc + 2];
            let mov_true = &insns[pc + 3];

            if is_select_mov(mov_false) && ja.is_ja() && ja.off == 1 && is_select_mov(mov_true) {
                let dst_f = mov_false.dst_reg();
                let dst_t = mov_true.dst_reg();
                if dst_f == dst_t {
                    return Some(CondSelectSite {
                        start_pc: pc,
                        old_len: 4,
                        cond_reg: jcc.dst_reg(),
                        dst_reg: dst_f,
                        true_val: extract_mov_value(mov_true),
                        false_val: extract_mov_value(mov_false),
                        jcc_op: bpf_op(jcc.code),
                        jcc_imm: jcc.imm,
                        jcc_src: bpf_src(jcc.code),
                        jcc_code: jcc.code,
                        jcc_src_reg: jcc.src_reg(),
                    });
                }
            }
        }
    }

    // Pattern C: 3-insn short conditional MOV (clang's common pattern)
    //   MOV dst, true_val ; Jcc +1 ; MOV dst, false_val
    //
    // Semantics:
    //   - dst is set to true_val unconditionally
    //   - If Jcc taken (condition true): skip false MOV, dst = true_val
    //   - If Jcc not taken (condition false): execute false MOV, dst = false_val
    //
    // The site starts at the MOV before the Jcc (pc-1 relative to the Jcc).
    // We check pc as potential Jcc position.
    if pc >= 1 && pc + 1 < n {
        let mov_true = &insns[pc - 1];
        let jcc = &insns[pc];
        let mov_false = &insns[pc + 1];

        if jcc.is_cond_jmp() && jcc.off == 1 && is_select_mov(mov_true) && is_select_mov(mov_false)
        {
            let dst_t = mov_true.dst_reg();
            let dst_f = mov_false.dst_reg();
            if dst_t == dst_f {
                // Ensure the MOV true_val doesn't also write a register
                // used by the JCC condition (would change semantics).
                // For BPF_X: jcc uses dst_reg and src_reg.
                // For BPF_K: jcc uses dst_reg.
                let jcc_cond_reg = jcc.dst_reg();
                let jcc_src_used = if bpf_src(jcc.code) == BPF_X {
                    Some(jcc.src_reg())
                } else {
                    None
                };
                let mov_true_dst = mov_true.dst_reg();
                let cond_clobbered =
                    mov_true_dst == jcc_cond_reg || jcc_src_used.is_some_and(|s| mov_true_dst == s);

                if !cond_clobbered {
                    return Some(CondSelectSite {
                        start_pc: pc - 1,
                        old_len: 3,
                        cond_reg: jcc_cond_reg,
                        dst_reg: dst_t,
                        true_val: extract_mov_value(mov_true),
                        false_val: extract_mov_value(mov_false),
                        jcc_op: bpf_op(jcc.code),
                        jcc_imm: jcc.imm,
                        jcc_src: bpf_src(jcc.code),
                        jcc_code: jcc.code,
                        jcc_src_reg: jcc.src_reg(),
                    });
                }
            }
        }
    }

    None
}

fn is_mov64(insn: &BpfInsn) -> bool {
    bpf_class(insn.code) == BPF_ALU64 && bpf_op(insn.code) == BPF_MOV
}

fn is_select_mov(insn: &BpfInsn) -> bool {
    is_mov64(insn) || (bpf_class(insn.code) == BPF_ALU && bpf_op(insn.code) == BPF_MOV)
}

fn extract_mov_value(insn: &BpfInsn) -> CondSelectValue {
    if bpf_class(insn.code) == BPF_ALU {
        if bpf_src(insn.code) == BPF_X {
            CondSelectValue::Reg32(insn.src_reg())
        } else {
            CondSelectValue::Imm32(insn.imm)
        }
    } else if bpf_src(insn.code) == BPF_X {
        CondSelectValue::Reg(insn.src_reg())
    } else {
        CondSelectValue::Imm(insn.imm)
    }
}

fn build_lowering(
    site: &CondSelectSite,
    live_after: &HashSet<u8>,
) -> Result<CondSelectLowering, String> {
    let (mut prefix, cond_reg, inverted) = condition_prefix(site, live_after)?;
    let (a_val, b_val) = if inverted {
        (site.false_val, site.true_val)
    } else {
        (site.true_val, site.false_val)
    };

    let mut protected = vec![cond_reg];
    for value in [a_val, b_val] {
        match value {
            CondSelectValue::Reg(reg) | CondSelectValue::Reg32(reg) => protected.push(reg),
            CondSelectValue::Imm(_) | CondSelectValue::Imm32(_) => {}
        }
    }

    let mut allocated = Vec::new();
    let mut imm_regs = Vec::new();
    let a_reg = materialize_value(
        site,
        a_val,
        live_after,
        &protected,
        &mut allocated,
        &mut imm_regs,
        &mut prefix,
    )?;
    let b_reg = materialize_value(
        site,
        b_val,
        live_after,
        &protected,
        &mut allocated,
        &mut imm_regs,
        &mut prefix,
    )?;
    Ok(CondSelectLowering {
        prefix,
        a_reg,
        b_reg,
        cond_reg,
    })
}

fn condition_prefix(
    site: &CondSelectSite,
    live_after: &HashSet<u8>,
) -> Result<(Vec<BpfInsn>, u8, bool), String> {
    if site.jcc_src == BPF_K
        && site.jcc_imm == 0
        && bpf_class(site.jcc_code) == BPF_JMP
        && matches!(site.jcc_op, BPF_JNE | BPF_JEQ)
    {
        return Ok((Vec::new(), site.cond_reg, site.jcc_op == BPF_JEQ));
    }

    if site.jcc_src == BPF_K
        && site.jcc_imm == 0
        && bpf_class(site.jcc_code) == BPF_JMP32
        && matches!(site.jcc_op, BPF_JNE | BPF_JEQ)
    {
        let forbidden = value_source_regs(site);
        let pred = choose_temp_reg(site, live_after, &forbidden, &[]).ok_or_else(|| {
            "no dead register available for cond_select compare predicate".to_string()
        })?;
        return Ok((
            vec![mov32_reg(pred, site.cond_reg)],
            pred,
            site.jcc_op == BPF_JEQ,
        ));
    }

    if site.jcc_src == BPF_K
        && bpf_class(site.jcc_code) == BPF_JMP
        && matches!(site.jcc_op, BPF_JNE | BPF_JEQ)
    {
        let forbidden = value_source_regs(site);
        let pred = choose_temp_reg(site, live_after, &forbidden, &[]).ok_or_else(|| {
            "no dead register available for cond_select compare predicate".to_string()
        })?;
        return Ok((
            vec![
                BpfInsn::mov64_reg(pred, site.cond_reg),
                BpfInsn::alu64_imm(BPF_XOR, pred, site.jcc_imm),
            ],
            pred,
            site.jcc_op == BPF_JEQ,
        ));
    }

    let mut forbidden = value_source_regs(site);
    forbidden.push(site.cond_reg);
    if site.jcc_src == BPF_X {
        forbidden.push(site.jcc_src_reg);
    }
    let pred = choose_temp_reg(site, live_after, &forbidden, &[]).ok_or_else(|| {
        "no dead register available for cond_select compare predicate".to_string()
    })?;
    if let Some(inverse_op) = inverse_jcc_op(site.jcc_op) {
        return Ok((
            vec![
                BpfInsn::mov64_imm(pred, 0),
                BpfInsn::new(
                    (site.jcc_code & !0xf0) | inverse_op,
                    BpfInsn::make_regs(site.cond_reg, site.jcc_src_reg),
                    1,
                    site.jcc_imm,
                ),
                BpfInsn::mov64_imm(pred, 1),
            ],
            pred,
            false,
        ));
    }

    let prefix = if site.old_len == 3 {
        vec![
            BpfInsn::new(
                site.jcc_code,
                BpfInsn::make_regs(site.cond_reg, site.jcc_src_reg),
                2,
                site.jcc_imm,
            ),
            BpfInsn::mov64_imm(pred, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(pred, 1),
        ]
    } else {
        vec![
            BpfInsn::mov64_imm(pred, 1),
            BpfInsn::new(
                site.jcc_code,
                BpfInsn::make_regs(site.cond_reg, site.jcc_src_reg),
                1,
                site.jcc_imm,
            ),
            BpfInsn::mov64_imm(pred, 0),
        ]
    };
    Ok((prefix, pred, false))
}

fn inverse_jcc_op(op: u8) -> Option<u8> {
    match op {
        BPF_JEQ => Some(BPF_JNE),
        BPF_JNE => Some(BPF_JEQ),
        BPF_JGT => Some(BPF_JLE),
        BPF_JGE => Some(BPF_JLT),
        BPF_JLT => Some(BPF_JGE),
        BPF_JLE => Some(BPF_JGT),
        BPF_JSGT => Some(BPF_JSLE),
        BPF_JSGE => Some(BPF_JSLT),
        BPF_JSLT => Some(BPF_JSGE),
        BPF_JSLE => Some(BPF_JSGT),
        _ => None,
    }
}

fn materialize_value(
    site: &CondSelectSite,
    value: CondSelectValue,
    live_after: &HashSet<u8>,
    protected: &[u8],
    allocated: &mut Vec<u8>,
    imm_regs: &mut Vec<(CondSelectValue, u8)>,
    prefix: &mut Vec<BpfInsn>,
) -> Result<u8, String> {
    if let CondSelectValue::Reg(reg) = value {
        return Ok(reg);
    }
    if let Some((_, reg)) = imm_regs.iter().find(|(seen, _)| *seen == value) {
        return Ok(*reg);
    }
    let reg = choose_temp_reg(site, live_after, protected, allocated)
        .ok_or_else(|| "no dead register available to materialize immediate operand".to_string())?;
    match value {
        CondSelectValue::Imm(imm) => prefix.push(BpfInsn::mov64_imm(reg, imm)),
        CondSelectValue::Reg32(src) => prefix.push(mov32_reg(reg, src)),
        CondSelectValue::Imm32(imm) => prefix.push(BpfInsn::mov32_imm(reg, imm)),
        CondSelectValue::Reg(_) => unreachable!(),
    }
    allocated.push(reg);
    imm_regs.push((value, reg));
    Ok(reg)
}

fn mov32_reg(dst: u8, src: u8) -> BpfInsn {
    BpfInsn::new(
        BPF_ALU | BPF_MOV | BPF_X,
        BpfInsn::make_regs(dst, src),
        0,
        0,
    )
}

fn choose_temp_reg(
    site: &CondSelectSite,
    live_after: &HashSet<u8>,
    forbidden: &[u8],
    allocated: &[u8],
) -> Option<u8> {
    std::iter::once(site.dst_reg)
        .chain(BPF_REG_0..=BPF_REG_9)
        .find(|&reg| {
            !forbidden.contains(&reg)
                && !allocated.contains(&reg)
                && (reg == site.dst_reg || !live_after.contains(&reg))
        })
}

fn value_source_regs(site: &CondSelectSite) -> Vec<u8> {
    [site.true_val, site.false_val]
        .into_iter()
        .filter_map(|value| match value {
            CondSelectValue::Reg(reg) | CondSelectValue::Reg32(reg) => Some(reg),
            CondSelectValue::Imm(_) | CondSelectValue::Imm32(_) => None,
        })
        .collect()
}
