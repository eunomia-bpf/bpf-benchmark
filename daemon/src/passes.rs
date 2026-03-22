// SPDX-License-Identifier: MIT
//! Concrete pass implementations — WideMemPass, RotatePass, SpectreMitigationPass.
//!
//! These are stub implementations with enough structure to compile and test
//! the pass framework integration. Full implementation is TODO.

use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

// ── WideMemPass ─────────────────────────────────────────────────────

/// WIDE_MEM optimization pass: merges byte-load + shift + OR sequences
/// into a single wide load instruction.
///
/// This is the most important BpfReJIT optimization, accounting for ~50.7%
/// of the kernel JIT surplus. No kinsn support needed — pure BPF replacement.
pub struct WideMemPass;

impl BpfPass for WideMemPass {
    fn name(&self) -> &str {
        "wide_mem"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        // Use the analysis framework to get branch targets.
        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);

        // Scan for wide_mem sites using existing matcher.
        let raw_sites = crate::matcher::scan_wide_mem(&program.insns);

        // Filter: skip sites with interior branch targets.
        let mut safe_sites = Vec::new();
        let mut skipped = Vec::new();

        for site in &raw_sites {
            let has_interior_target = (site.start_pc + 1..site.start_pc + site.old_len)
                .any(|pc| pc < bt.is_target.len() && bt.is_target[pc]);

            if has_interior_target {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "interior branch target".into(),
                });
            } else {
                safe_sites.push(site.clone());
            }
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics: vec![],
            });
        }

        // Apply rewrite using the existing rewriter.
        let orig_len = program.insns.len();
        let result = crate::rewriter::rewrite(&program.insns, &safe_sites)?;
        let applied = result.sites_applied;

        program.insns = result.new_insns;
        program.log_transform(TransformEntry {
            pass_name: self.name().into(),
            sites_applied: applied,
            insns_before: orig_len,
            insns_after: program.insns.len(),
            details: safe_sites
                .iter()
                .map(|s| {
                    format!(
                        "pc={} len={} width={}",
                        s.start_pc,
                        s.old_len,
                        s.get_binding("width").unwrap_or(0)
                    )
                })
                .collect(),
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
        })
    }
}

// ── RotatePass ──────────────────────────────────────────────────────

/// ROTATE optimization pass: replaces shift+OR rotate patterns with
/// bpf_rotate64() kfunc calls. JIT inlines the kfunc as a RORX instruction.
pub struct RotatePass;

impl BpfPass for RotatePass {
    fn name(&self) -> &str {
        "rotate"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Optimization
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
        // Prerequisite: check if bpf_rotate64 kfunc is available.
        if ctx.kfunc_registry.rotate64_btf_id < 0 {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![SkipReason {
                    pc: 0,
                    reason: "bpf_rotate64 kfunc not available".into(),
                }],
                diagnostics: vec![],
            });
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);
        let liveness_analysis = LivenessAnalysis;
        let liveness = analyses.get(&liveness_analysis, program);

        let sites = scan_rotate_sites(&program.insns);
        let mut safe_sites = Vec::new();
        let mut skipped = Vec::new();
        let btf_id = ctx.kfunc_registry.rotate64_btf_id;

        for site in sites {
            // Safety check 1: interior branch target.
            let has_interior = (site.start_pc + 1..site.start_pc + site.old_len)
                .any(|pc| pc < bt.is_target.len() && bt.is_target[pc]);
            if has_interior {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "interior branch target".into(),
                });
                continue;
            }

            // Safety check 2: caller-saved register conflict.
            // A kfunc call clobbers r1-r5. If any of those are live after
            // the site (excluding the value register), we cannot safely transform.
            let site_end = site.start_pc + site.old_len;
            if site_end > 0 && site_end - 1 < liveness.live_out.len() {
                let live_after = &liveness.live_out[site_end - 1];
                let caller_saved_conflict = (1u8..=5)
                    .any(|r| r != site.val_reg && live_after.contains(&r));
                if caller_saved_conflict {
                    skipped.push(SkipReason {
                        pc: site.start_pc,
                        reason: "caller-saved register conflict".into(),
                    });
                    continue;
                }
            }

            safe_sites.push(site);
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics: vec![],
            });
        }

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

            if site_idx < safe_sites.len() && pc == safe_sites[site_idx].start_pc {
                let site = &safe_sites[site_idx];
                // Emit: r1 = val_reg, r2 = shift, call kfunc, dst = r0.
                if site.val_reg != 1 {
                    new_insns.push(BpfInsn::mov64_reg(1, site.val_reg));
                }
                new_insns.push(BpfInsn::mov64_imm(2, site.shift_amount as i32));
                new_insns.push(BpfInsn::call_kfunc(btf_id));
                if site.dst_reg != 0 {
                    new_insns.push(BpfInsn::mov64_reg(site.dst_reg, 0));
                }

                // Map old PCs in the site range.
                for j in 1..site.old_len {
                    addr_map[pc + j] = new_pc;
                }

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
        fixup_branches_inline(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        program.log_transform(TransformEntry {
            pass_name: self.name().into(),
            sites_applied: applied,
            insns_before: orig_len,
            insns_after: program.insns.len(),
            details: vec![],
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
        })
    }
}

struct RotateSite {
    start_pc: usize,
    old_len: usize,
    dst_reg: u8,
    val_reg: u8,
    shift_amount: u32,
}

fn scan_rotate_sites(insns: &[BpfInsn]) -> Vec<RotateSite> {
    let mut sites = Vec::new();
    let n = insns.len();
    let mut pc = 0;

    while pc + 2 < n {
        let i0 = &insns[pc];
        let i1 = &insns[pc + 1];
        let i2 = &insns[pc + 2];

        if let Some(site) = try_match_rotate(i0, i1, i2, pc) {
            let len = site.old_len;
            sites.push(site);
            pc += len;
        } else {
            pc += 1;
        }
    }

    sites
}

fn try_match_rotate(
    i0: &BpfInsn,
    i1: &BpfInsn,
    i2: &BpfInsn,
    pc: usize,
) -> Option<RotateSite> {
    // Pattern A: RSH64_IMM(dst, 64-S) ; LSH64_IMM(tmp, S) ; OR64_REG(dst, tmp)
    let is_rsh = i0.code == (BPF_ALU64 | BPF_RSH | BPF_K);
    let is_lsh = i1.code == (BPF_ALU64 | BPF_LSH | BPF_K);
    let is_or = i2.code == (BPF_ALU64 | BPF_OR | BPF_X);

    if is_rsh && is_lsh && is_or {
        let rsh_amount = i0.imm as u32;
        let lsh_amount = i1.imm as u32;

        if rsh_amount + lsh_amount == 64 {
            let dst = i0.dst_reg();
            let tmp = i1.dst_reg();

            if i2.dst_reg() == dst && i2.src_reg() == tmp {
                return Some(RotateSite {
                    start_pc: pc,
                    old_len: 3,
                    dst_reg: dst,
                    val_reg: dst,
                    shift_amount: lsh_amount,
                });
            }
        }
    }

    // Pattern B: LSH64_IMM(dst, S) ; RSH64_IMM(tmp, 64-S) ; OR64_REG(dst, tmp)
    let is_lsh_first = i0.code == (BPF_ALU64 | BPF_LSH | BPF_K);
    let is_rsh_second = i1.code == (BPF_ALU64 | BPF_RSH | BPF_K);

    if is_lsh_first && is_rsh_second && is_or {
        let lsh_amount = i0.imm as u32;
        let rsh_amount = i1.imm as u32;

        if lsh_amount + rsh_amount == 64 {
            let dst = i0.dst_reg();
            let tmp = i1.dst_reg();

            if i2.dst_reg() == dst && i2.src_reg() == tmp {
                return Some(RotateSite {
                    start_pc: pc,
                    old_len: 3,
                    dst_reg: dst,
                    val_reg: dst,
                    shift_amount: lsh_amount,
                });
            }
        }
    }

    None
}

fn fixup_branches_inline(new_insns: &mut [BpfInsn], old_insns: &[BpfInsn], addr_map: &[usize]) {
    let old_n = old_insns.len();
    let mut old_pc = 0;
    while old_pc < old_n {
        let insn = &old_insns[old_pc];
        if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
            let new_pc = addr_map[old_pc];
            let old_target = (old_pc as i64 + 1 + insn.off as i64) as usize;
            if old_target <= old_n {
                let new_target = addr_map[old_target];
                if new_pc < new_insns.len() && new_insns[new_pc].is_jmp_class() {
                    let new_off = new_target as i64 - (new_pc as i64 + 1);
                    new_insns[new_pc].off = new_off as i16;
                }
            }
        }
        old_pc = if insn.is_ldimm64() {
            old_pc + 2
        } else {
            old_pc + 1
        };
    }
}

// ── CondSelectPass ─────────────────────────────────────────────────

/// COND_SELECT optimization: replace branch+mov diamond with bpf_select64()
/// kfunc call. PGO-guided: highly predictable branches are skipped since
/// CMOV is slower than a well-predicted branch.
///
/// Pattern A (4-insn diamond):
///   Jcc r_cond, X, +2 ; MOV r_dst, val_false ; JA +1 ; MOV r_dst, val_true
///
/// Pattern B (3-insn):
///   Jcc r_cond, X, +1 ; MOV r_dst, val_false ; MOV r_dst, val_true
pub struct CondSelectPass {
    /// Predictability threshold: skip if branch is more predictable than this
    /// (e.g., 0.8 means skip if >80% one direction).
    pub predictability_threshold: f64,
}

struct CondSelectSite {
    start_pc: usize,
    old_len: usize,
    cond_reg: u8,
    dst_reg: u8,
    true_val: CondSelectValue,
    false_val: CondSelectValue,
}

#[derive(Clone, Copy)]
enum CondSelectValue {
    Reg(u8),
    Imm(i32),
}

impl BpfPass for CondSelectPass {
    fn name(&self) -> &str {
        "cond_select"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Optimization
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
        if ctx.kfunc_registry.select64_btf_id < 0 {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![SkipReason {
                    pc: 0,
                    reason: "bpf_select64 kfunc not available".into(),
                }],
                diagnostics: vec![],
            });
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);
        let liveness_analysis = LivenessAnalysis;
        let liveness = analyses.get(&liveness_analysis, program);

        let sites = scan_cond_select_sites(&program.insns);
        let mut safe_sites = Vec::new();
        let mut skipped = Vec::new();

        for site in sites {
            // Interior branch target check:
            // Skip sites where an EXTERNAL branch targets interior instructions.
            // The pattern's own JCC (at start_pc) naturally targets within the site,
            // so we exclude that self-referencing target from the check.
            let own_jcc_target = {
                let jcc = &program.insns[site.start_pc];
                (site.start_pc as i64 + 1 + jcc.off as i64) as usize
            };
            let has_exterior_interior = (site.start_pc + 1..site.start_pc + site.old_len)
                .any(|pc| {
                    pc < bt.is_target.len()
                        && bt.is_target[pc]
                        && pc != own_jcc_target
                });
            if has_exterior_interior {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "interior branch target from external source".into(),
                });
                continue;
            }

            // PGO: skip highly predictable branches (annotation-level)
            if site.start_pc < program.annotations.len() {
                if let Some(ref bp) = program.annotations[site.start_pc].branch_profile {
                    let total = bp.taken_count + bp.not_taken_count;
                    if total > 0 {
                        let max_rate = (bp.taken_count as f64 / total as f64)
                            .max(bp.not_taken_count as f64 / total as f64);
                        if max_rate > (1.0 - self.predictability_threshold) {
                            skipped.push(SkipReason {
                                pc: site.start_pc,
                                reason: format!(
                                    "branch highly predictable ({:.1}%)",
                                    max_rate * 100.0
                                ),
                            });
                            continue;
                        }
                    }
                }
            }

            // Caller-saved register conflict
            let site_end = site.start_pc + site.old_len;
            if site_end > 0 && site_end - 1 < liveness.live_out.len() {
                let live_after = &liveness.live_out[site_end - 1];
                let conflict = (1u8..=5).any(|r| live_after.contains(&r));
                if conflict {
                    skipped.push(SkipReason {
                        pc: site.start_pc,
                        reason: "caller-saved register conflict".into(),
                    });
                    continue;
                }
            }

            safe_sites.push(site);
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics: vec![],
            });
        }

        let btf_id = ctx.kfunc_registry.select64_btf_id;
        let orig_len = program.insns.len();
        let mut new_insns = Vec::with_capacity(orig_len);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut pc = 0;
        let mut site_idx = 0;
        let mut applied = 0;

        while pc < orig_len {
            let new_pc = new_insns.len();
            addr_map[pc] = new_pc;

            if site_idx < safe_sites.len() && pc == safe_sites[site_idx].start_pc {
                let site = &safe_sites[site_idx];
                let mut replacement = Vec::new();

                // r1 = cond
                if site.cond_reg != 1 {
                    replacement.push(BpfInsn::mov64_reg(1, site.cond_reg));
                }
                // r2 = true_val
                match site.true_val {
                    CondSelectValue::Reg(r) => {
                        if r != 2 {
                            replacement.push(BpfInsn::mov64_reg(2, r));
                        }
                    }
                    CondSelectValue::Imm(v) => {
                        replacement.push(BpfInsn::mov64_imm(2, v));
                    }
                }
                // r3 = false_val
                match site.false_val {
                    CondSelectValue::Reg(r) => {
                        if r != 3 {
                            replacement.push(BpfInsn::mov64_reg(3, r));
                        }
                    }
                    CondSelectValue::Imm(v) => {
                        replacement.push(BpfInsn::mov64_imm(3, v));
                    }
                }
                // call bpf_select64
                replacement.push(BpfInsn::call_kfunc(btf_id));
                // dst = r0
                if site.dst_reg != 0 {
                    replacement.push(BpfInsn::mov64_reg(site.dst_reg, 0));
                }

                for j in 1..site.old_len {
                    addr_map[pc + j] = new_pc;
                }

                new_insns.extend(replacement);
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

        fixup_branches_inline(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        program.log_transform(TransformEntry {
            pass_name: self.name().into(),
            sites_applied: applied,
            insns_before: orig_len,
            insns_after: program.insns.len(),
            details: vec![],
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
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

            if is_mov64(mov_false) && ja.is_ja() && ja.off == 1 && is_mov64(mov_true) {
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
                    });
                }
            }
        }
    }

    // Pattern B: 3-insn
    //   Jcc +1 ; MOV dst, false_val ; MOV dst, true_val
    if pc + 2 < n {
        let jcc = &insns[pc];
        if jcc.is_cond_jmp() && jcc.off == 1 {
            let mov_false = &insns[pc + 1];
            let mov_true = &insns[pc + 2];

            if is_mov64(mov_false) && is_mov64(mov_true) {
                let dst_f = mov_false.dst_reg();
                let dst_t = mov_true.dst_reg();
                if dst_f == dst_t {
                    return Some(CondSelectSite {
                        start_pc: pc,
                        old_len: 3,
                        cond_reg: jcc.dst_reg(),
                        dst_reg: dst_f,
                        true_val: extract_mov_value(mov_true),
                        false_val: extract_mov_value(mov_false),
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

fn extract_mov_value(insn: &BpfInsn) -> CondSelectValue {
    if bpf_src(insn.code) == BPF_X {
        CondSelectValue::Reg(insn.src_reg())
    } else {
        CondSelectValue::Imm(insn.imm)
    }
}

// ── BranchFlipPass ─────────────────────────────────────────────────

/// BRANCH_FLIP: PGO-guided reorder of if/else bodies.
///
/// Handles the 4-insn diamond: Jcc +2 ; body1 ; JA +1 ; body2.
/// If PGO shows the taken path (body2) is hot, flip the condition and
/// swap bodies so the hot path becomes the fall-through (favoured by
/// the CPU static branch predictor).
pub struct BranchFlipPass {
    /// Minimum taken rate to trigger a flip.
    pub min_bias: f64,
}

impl BpfPass for BranchFlipPass {
    fn name(&self) -> &str {
        "branch_flip"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let n = program.insns.len();
        let mut applied = 0;
        let mut skipped = Vec::new();
        let orig_len = n;

        let mut pc = 0;
        while pc + 3 < n {
            let jcc = &program.insns[pc];
            if jcc.is_cond_jmp() && jcc.off == 2 {
                let ja = &program.insns[pc + 2];
                if ja.is_ja() && ja.off == 1 {
                    // Check PGO annotation
                    let should_flip =
                        if let Some(ref bp) = program.annotations[pc].branch_profile {
                            let total = bp.taken_count + bp.not_taken_count;
                            if total > 0 {
                                bp.taken_count as f64 / total as f64 >= self.min_bias
                            } else {
                                false
                            }
                        } else {
                            false
                        };

                    if should_flip {
                        let then_insn = program.insns[pc + 1];
                        let else_insn = program.insns[pc + 3];

                        if let Some(new_op) = invert_jcc_op(bpf_op(jcc.code)) {
                            program.insns[pc].code =
                                (program.insns[pc].code & 0x0f) | new_op;
                            program.insns[pc + 1] = else_insn;
                            program.insns[pc + 3] = then_insn;
                            applied += 1;
                        } else {
                            skipped.push(SkipReason {
                                pc,
                                reason: "cannot invert condition opcode".into(),
                            });
                        }
                    } else {
                        skipped.push(SkipReason {
                            pc,
                            reason: "branch not biased enough or no PGO data".into(),
                        });
                    }
                }
            }
            pc += 1;
        }

        if applied > 0 {
            program.log_transform(TransformEntry {
                pass_name: self.name().into(),
                sites_applied: applied,
                insns_before: orig_len,
                insns_after: program.insns.len(),
                details: vec![],
            });
        }

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
        })
    }
}

/// Invert a conditional jump opcode.
fn invert_jcc_op(op: u8) -> Option<u8> {
    match op {
        BPF_JEQ => Some(BPF_JNE),
        BPF_JNE => Some(BPF_JEQ),
        BPF_JGT => Some(BPF_JLE),
        BPF_JLE => Some(BPF_JGT),
        BPF_JGE => Some(BPF_JLT),
        BPF_JLT => Some(BPF_JGE),
        BPF_JSGT => Some(BPF_JSLE),
        BPF_JSLE => Some(BPF_JSGT),
        BPF_JSGE => Some(BPF_JSLT),
        BPF_JSLT => Some(BPF_JSGE),
        BPF_JSET => None, // JSET has no simple inverse
        _ => None,
    }
}

// ── SpectreMitigationPass ───────────────────────────────────────────

/// Spectre mitigation pass: inserts NOP (`JA +0`) barriers after conditional
/// branches as speculation barrier placeholders. Avoids double-insertion if
/// a NOP already follows. Performs branch fixup after insertion.
pub struct SpectreMitigationPass;

impl BpfPass for SpectreMitigationPass {
    fn name(&self) -> &str {
        "spectre_mitigation"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Security
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let orig_len = program.insns.len();
        let mut new_insns: Vec<BpfInsn> = Vec::with_capacity(orig_len + orig_len / 4);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut insertions = 0usize;

        let mut pc = 0;
        while pc < orig_len {
            let new_pc = new_insns.len();
            addr_map[pc] = new_pc;

            let insn = program.insns[pc];
            new_insns.push(insn);

            // After a conditional jump, insert a NOP if one isn't already there
            if insn.is_cond_jmp() {
                let next_pc = pc + 1;
                let already_has_nop = next_pc < orig_len
                    && program.insns[next_pc].is_ja()
                    && program.insns[next_pc].off == 0;

                if !already_has_nop {
                    new_insns.push(BpfInsn::nop());
                    insertions += 1;
                }
            }

            // Handle LDIMM64 second slot
            if insn.is_ldimm64() && pc + 1 < orig_len {
                pc += 1;
                addr_map[pc] = new_insns.len();
                new_insns.push(program.insns[pc]);
            }

            pc += 1;
        }
        addr_map[orig_len] = new_insns.len();

        if insertions > 0 {
            // Fix up branches using the address map
            fixup_branches_inline(&mut new_insns, &program.insns, &addr_map);

            program.insns = new_insns;
            program.log_transform(TransformEntry {
                pass_name: self.name().into(),
                sites_applied: insertions,
                insns_before: orig_len,
                insns_after: program.insns.len(),
                details: vec![format!("inserted {} NOP barriers", insertions)],
            });
        }

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: insertions > 0,
            sites_applied: insertions,
            sites_skipped: vec![],
            diagnostics: if insertions > 0 {
                vec![format!(
                    "{} speculation barriers inserted (NOP placeholder)",
                    insertions
                )]
            } else {
                vec![]
            },
        })
    }
}

// ── Pipeline constructors ───────────────────────────────────────────

use crate::analysis::CFGAnalysis;
use crate::analysis::PGOAnalysis;

/// Build the default optimization pipeline.
pub fn build_default_pipeline() -> PassManager {
    let mut pm = PassManager::new();

    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(LivenessAnalysis);
    pm.register_analysis(PGOAnalysis { profiling_data: None });

    pm.add_pass(WideMemPass);
    pm.add_pass(RotatePass);
    pm.add_pass(CondSelectPass {
        predictability_threshold: 0.8,
    });
    pm.add_pass(BranchFlipPass { min_bias: 0.7 });

    pm
}

/// Build security pipeline.
#[allow(dead_code)]
pub fn build_security_pipeline() -> PassManager {
    let mut pm = PassManager::new();
    pm.register_analysis(BranchTargetAnalysis);
    pm.add_pass(SpectreMitigationPass);
    pm
}

/// Build the full pipeline (security + optimization).
#[allow(dead_code)]
pub fn build_full_pipeline() -> PassManager {
    let mut pm = PassManager::new();

    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(LivenessAnalysis);
    pm.register_analysis(PGOAnalysis { profiling_data: None });

    pm.add_pass(SpectreMitigationPass);
    pm.add_pass(WideMemPass);
    pm.add_pass(RotatePass);
    pm.add_pass(CondSelectPass {
        predictability_threshold: 0.8,
    });
    pm.add_pass(BranchFlipPass { min_bias: 0.7 });

    pm
}

// ── Tests ───────────────────────────────────────────────────────────

#[cfg(test)]
mod tests {
    use super::*;
    use crate::insn::*;
    use crate::pass::{Analysis, AnalysisCache, PassContext};

    // ── Test helpers ────────────────────────────────────────────────

    fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
        BpfProgram::new(insns, ProgMeta::default())
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
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

    /// Build a canonical 4-byte low-byte-first byte-ladder (Variant A).
    fn make_wide_mem_4byte_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::ldx_mem(BPF_B, 2, 1, 0), // r2 = *(u8*)(r1+0)
            BpfInsn::ldx_mem(BPF_B, 3, 1, 1), // r3 = *(u8*)(r1+1)
            BpfInsn::alu64_imm(BPF_LSH, 3, 8), // r3 <<= 8
            BpfInsn::alu64_reg(BPF_OR, 2, 3),  // r2 |= r3
            BpfInsn::ldx_mem(BPF_B, 3, 1, 2), // r3 = *(u8*)(r1+2)
            BpfInsn::alu64_imm(BPF_LSH, 3, 16), // r3 <<= 16
            BpfInsn::alu64_reg(BPF_OR, 2, 3),  // r2 |= r3
            BpfInsn::ldx_mem(BPF_B, 3, 1, 3), // r3 = *(u8*)(r1+3)
            BpfInsn::alu64_imm(BPF_LSH, 3, 24), // r3 <<= 24
            BpfInsn::alu64_reg(BPF_OR, 2, 3),  // r2 |= r3
            exit_insn(),
        ]
    }

    /// Build a rotate pattern: RSH(dst, 64-S); LSH(tmp, S); OR(dst, tmp)
    fn make_rotate_program(dst: u8, tmp: u8, shift: u32) -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_imm(dst as u8, 0x12345678), // setup value
            BpfInsn::mov64_reg(tmp, dst),               // copy to tmp
            BpfInsn::alu64_imm(BPF_RSH, dst, (64 - shift) as i32), // dst >>= (64 - S)
            BpfInsn::alu64_imm(BPF_LSH, tmp, shift as i32), // tmp <<= S
            BpfInsn::alu64_reg(BPF_OR, dst, tmp),       // dst |= tmp
            exit_insn(),
        ]
    }

    fn ctx_with_rotate_kfunc(btf_id: i32) -> PassContext {
        let mut ctx = PassContext::test_default();
        ctx.kfunc_registry.rotate64_btf_id = btf_id;
        ctx
    }

    // ── WideMemPass tests ───────────────────────────────────────────

    #[test]
    fn test_wide_mem_pass_finds_sites() {
        let mut prog = make_program(make_wide_mem_4byte_program());
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        // 10 insns replaced by 1 wide load, plus 1 exit = 2 insns.
        assert_eq!(prog.insns.len(), 2);
        // First insn should be a wide load (LDX_MEM W).
        assert!(prog.insns[0].is_ldx_mem());
        assert_eq!(bpf_size(prog.insns[0].code), BPF_W);
    }

    #[test]
    fn test_wide_mem_pass_no_sites() {
        // Program with no byte-ladder patterns.
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(0, 42),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert_eq!(prog.insns.len(), 2);
    }

    #[test]
    fn test_wide_mem_pass_transforms_correctly() {
        // A 2-byte ladder: should become LDX_MEM(H, ...).
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_B, 0, 6, 10), // byte 0
            BpfInsn::ldx_mem(BPF_B, 1, 6, 11), // byte 1
            BpfInsn::alu64_imm(BPF_LSH, 1, 8), // shift
            BpfInsn::alu64_reg(BPF_OR, 0, 1),  // or
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert_eq!(prog.insns.len(), 2); // 1 wide load + exit
        // Should be LDX_MEM(H, r0, r6, 10).
        assert_eq!(bpf_size(prog.insns[0].code), BPF_H);
        assert_eq!(prog.insns[0].dst_reg(), 0);
        assert_eq!(prog.insns[0].src_reg(), 6);
        assert_eq!(prog.insns[0].off, 10);
    }

    #[test]
    fn test_wide_mem_pass_preserves_branch_offsets() {
        // Program with a forward jump over a byte ladder:
        //   0: ja +10        -> target is 11 (= exit)
        //   1-10: 4-byte byte ladder (10 insns)
        //   11: exit
        //
        // After rewrite:
        //   0: ja +1         -> target is 2 (= exit)
        //   1: ldx_mem(W, ...)
        //   2: exit

        let mut insns = vec![BpfInsn::ja(10)]; // 0: ja +10 -> 11
        // Append a 4-byte low-first byte ladder.
        insns.push(BpfInsn::ldx_mem(BPF_B, 0, 6, 0)); // 1
        insns.push(BpfInsn::ldx_mem(BPF_B, 2, 6, 1)); // 2
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 2, 8)); // 3
        insns.push(BpfInsn::alu64_reg(BPF_OR, 0, 2)); // 4
        insns.push(BpfInsn::ldx_mem(BPF_B, 3, 6, 2)); // 5
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 3, 16)); // 6
        insns.push(BpfInsn::alu64_reg(BPF_OR, 0, 3)); // 7
        insns.push(BpfInsn::ldx_mem(BPF_B, 4, 6, 3)); // 8
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 4, 24)); // 9
        insns.push(BpfInsn::alu64_reg(BPF_OR, 0, 4)); // 10
        insns.push(exit_insn()); // 11

        let mut prog = make_program(insns);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(prog.insns.len(), 3); // ja + ldx_mem + exit

        // The ja should now point to exit at new_pc=2.
        let ja = &prog.insns[0];
        assert!(ja.is_ja());
        assert_eq!(ja.off, 1, "ja should jump over ldx_mem to exit");
    }

    #[test]
    fn test_wide_mem_pass_skips_site_with_interior_branch_target() {
        // A byte ladder where an interior instruction is a branch target.
        // The pass should skip this site.
        //
        // 0: jeq r5, 0, +2   -> targets pc 3 (inside the byte ladder)
        // 1: byte-ladder start: ldx_mem(B, r0, r6, 0)
        // 2: ldx_mem(B, r1, r6, 1)
        // 3: lsh64 r1, 8          <- branch target from pc 0!
        // 4: or64 r0, r1
        // 5: exit

        let mut prog = make_program(vec![
            jeq_imm(5, 0, 2),                  // 0: jeq r5, 0, +2 -> pc 3
            BpfInsn::ldx_mem(BPF_B, 0, 6, 0), // 1
            BpfInsn::ldx_mem(BPF_B, 1, 6, 1), // 2
            BpfInsn::alu64_imm(BPF_LSH, 1, 8), // 3 <- branch target!
            BpfInsn::alu64_reg(BPF_OR, 0, 1),  // 4
            exit_insn(),                       // 5
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        // The byte ladder at pc=1 has an interior branch target at pc=3.
        // It should be skipped.
        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(!result.sites_skipped.is_empty());
        assert!(result.sites_skipped[0].reason.contains("interior branch target"));
    }

    #[test]
    fn test_wide_mem_pass_multiple_sites() {
        // Two consecutive 2-byte ladders.
        let mut prog = make_program(vec![
            // Site 1: dst=0, base=6, off=0
            BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
            BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
            BpfInsn::alu64_imm(BPF_LSH, 1, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 1),
            // Site 2: dst=3, base=7, off=4
            BpfInsn::ldx_mem(BPF_B, 3, 7, 4),
            BpfInsn::ldx_mem(BPF_B, 4, 7, 5),
            BpfInsn::alu64_imm(BPF_LSH, 4, 8),
            BpfInsn::alu64_reg(BPF_OR, 3, 4),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 2);
        // 4 + 4 insns replaced by 1 + 1, plus exit = 3.
        assert_eq!(prog.insns.len(), 3);
    }

    #[test]
    fn test_wide_mem_pass_integration_with_pass_manager() {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.add_pass(WideMemPass);

        let mut prog = make_program(make_wide_mem_4byte_program());
        let ctx = PassContext::test_default();

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(prog.insns.len(), 2);
    }

    // ── RotatePass tests ────────────────────────────────────────────

    #[test]
    fn test_rotate_pass_pattern_match() {
        // Verify that scan_rotate_sites finds the pattern.
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 56), // r2 >>= 56 (64-8)
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),  // r3 <<= 8
            BpfInsn::alu64_reg(BPF_OR, 2, 3),   // r2 |= r3
        ];
        let sites = scan_rotate_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].start_pc, 0);
        assert_eq!(sites[0].old_len, 3);
        assert_eq!(sites[0].shift_amount, 8);
        assert_eq!(sites[0].dst_reg, 2);
    }

    #[test]
    fn test_rotate_pass_pattern_b_match() {
        // Pattern B: LSH first, RSH second.
        let insns = vec![
            BpfInsn::alu64_imm(BPF_LSH, 2, 16), // r2 <<= 16
            BpfInsn::alu64_imm(BPF_RSH, 3, 48), // r3 >>= 48 (64-16)
            BpfInsn::alu64_reg(BPF_OR, 2, 3),   // r2 |= r3
        ];
        let sites = scan_rotate_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].shift_amount, 16);
    }

    #[test]
    fn test_rotate_pass_no_match_wrong_sum() {
        // RSH + LSH amounts don't sum to 64.
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 20),
            BpfInsn::alu64_imm(BPF_LSH, 3, 20), // 20+20 != 64
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_rotate_sites(&insns);
        assert!(sites.is_empty());
    }

    #[test]
    fn test_rotate_pass_emit_kfunc_call() {
        // Full pass test: rotate pattern should be replaced with kfunc call.
        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 56), // r2 >>= 56
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),  // r3 <<= 8
            BpfInsn::alu64_reg(BPF_OR, 2, 3),   // r2 |= r3
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_rotate_kfunc(9999);

        let pass = RotatePass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);

        // The replacement should contain a kfunc call.
        let has_kfunc_call = prog.insns.iter().any(|i| i.is_call() && i.src_reg() == 2);
        assert!(has_kfunc_call, "expected a kfunc call in the output");

        // The kfunc call should have the BTF ID we specified.
        let call_insn = prog.insns.iter().find(|i| i.is_call() && i.src_reg() == 2).unwrap();
        assert_eq!(call_insn.imm, 9999);
    }

    #[test]
    fn test_rotate_pass_skip_when_kfunc_unavailable() {
        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        // kfunc not available (btf_id = -1, the default).
        let ctx = PassContext::test_default();

        let pass = RotatePass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(!result.sites_skipped.is_empty());
        assert!(result.sites_skipped[0]
            .reason
            .contains("kfunc not available"));
        // Program should be unchanged.
        assert_eq!(prog.insns.len(), 4);
    }

    #[test]
    fn test_rotate_pass_caller_saved_conflict() {
        // Construct a program where r3 is live after the rotate site,
        // causing a caller-saved register conflict.
        //
        //   0: mov r3, 99          (r3 will be live across the site)
        //   1: rsh r2, 56          \
        //   2: lsh r4, 8            | rotate site (dst=r2, val=r2)
        //   3: or r2, r4           /
        //   4: mov r0, r3          (uses r3 — r3 is live-out of the site)
        //   5: exit
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(3, 99),           // 0
            BpfInsn::alu64_imm(BPF_RSH, 2, 56), // 1: rsh r2, 56
            BpfInsn::alu64_imm(BPF_LSH, 4, 8),  // 2: lsh r4, 8
            BpfInsn::alu64_reg(BPF_OR, 2, 4),   // 3: or r2, r4
            BpfInsn::mov64_reg(0, 3),            // 4: mov r0, r3 (uses r3)
            exit_insn(),                         // 5
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_rotate_kfunc(9999);

        let pass = RotatePass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        // r3 is live-out of the rotate site, and r3 is caller-saved (r1-r5).
        // The kfunc call would clobber r3, so this site must be skipped.
        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        let has_conflict = result
            .sites_skipped
            .iter()
            .any(|s| s.reason.contains("caller-saved"));
        assert!(
            has_conflict,
            "expected caller-saved conflict skip reason, got: {:?}",
            result.sites_skipped
        );
    }

    #[test]
    fn test_rotate_pass_integration_with_pass_manager() {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(LivenessAnalysis);
        pm.add_pass(RotatePass);

        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            exit_insn(),
        ]);
        let ctx = ctx_with_rotate_kfunc(1234);

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
    }

    // ── SpectreMitigationPass tests ─────────────────────────────────

    #[test]
    fn test_spectre_pass_inserts_fence_after_branch() {
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1), // 0: conditional branch
            BpfInsn::mov64_imm(0, 1), // 1
            BpfInsn::mov64_imm(0, 2), // 2
            exit_insn(),       // 3
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = SpectreMitigationPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        // Should have original 4 insns + 1 fence = 5.
        assert_eq!(prog.insns.len(), 5);
        // The fence (NOP) should be right after the conditional branch.
        assert!(prog.insns[0].is_cond_jmp());
        assert!(prog.insns[1].is_ja() && prog.insns[1].off == 0); // NOP fence
    }

    #[test]
    fn test_spectre_pass_no_change_when_no_vulnerable_sites() {
        // Program with no conditional branches — just a linear sequence.
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(0, 42),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = SpectreMitigationPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert_eq!(prog.insns.len(), 2);
    }

    #[test]
    fn test_spectre_pass_multiple_branches() {
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),         // 0: cond branch
            BpfInsn::mov64_imm(0, 1),  // 1
            jeq_imm(2, 0, 1),         // 2: another cond branch
            BpfInsn::mov64_imm(0, 2),  // 3
            exit_insn(),              // 4
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = SpectreMitigationPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 2);
        // 5 original + 2 fences = 7.
        assert_eq!(prog.insns.len(), 7);
    }

    #[test]
    fn test_spectre_pass_does_not_insert_after_unconditional_jump() {
        // JA (unconditional) should NOT get a fence.
        let mut prog = make_program(vec![
            BpfInsn::ja(1),            // 0: unconditional jump
            BpfInsn::mov64_imm(0, 42), // 1
            exit_insn(),              // 2
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = SpectreMitigationPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert_eq!(prog.insns.len(), 3);
    }

    #[test]
    fn test_spectre_pass_integration_with_pass_manager() {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.add_pass(SpectreMitigationPass);

        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let ctx = PassContext::test_default();

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
    }

    // ── Multi-pass pipeline tests ───────────────────────────────────

    #[test]
    fn test_pipeline_wide_mem_then_spectre() {
        // Pipeline: WideMemPass -> SpectreMitigationPass.
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.add_pass(WideMemPass);
        pm.add_pass(SpectreMitigationPass);

        // Program with a byte ladder followed by a conditional branch.
        let mut insns = vec![
            BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
            BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
            BpfInsn::alu64_imm(BPF_LSH, 1, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 1),
            jeq_imm(0, 42, 1),        // conditional branch
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ];

        let mut prog = make_program(insns);
        let ctx = PassContext::test_default();

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        // WideMemPass should find and apply 1 site; SpectreMitigationPass should find 1 cond branch.
        assert!(result.total_sites_applied >= 2);
    }

    // ── Additional analysis tests (for completeness) ────────────────

    #[test]
    fn test_cfg_analysis_with_subprogs() {
        use crate::analysis::CFGAnalysis;

        // Program with a BPF-to-BPF pseudo call:
        //   0: pseudo_call +2   -> calls subprog at pc 3
        //   1: mov r0, 0
        //   2: exit
        //   3: mov r0, 1       (subprog entry)
        //   4: exit
        let prog = make_program(vec![
            BpfInsn {
                code: BPF_JMP | BPF_CALL,
                regs: BpfInsn::make_regs(0, 1), // src_reg=1 for pseudo call
                off: 0,
                imm: 2, // target = 0+1+2 = pc 3
            },
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
            BpfInsn::mov64_imm(0, 1), // subprog entry
            exit_insn(),
        ]);

        let cfg = CFGAnalysis;
        let result = cfg.run(&prog);

        // PC 3 should be a branch target (subprog entry).
        assert!(result.branch_targets[3]);
        // Should have at least 2 subprogs.
        assert!(result.subprogs.len() >= 2);
    }

    #[test]
    fn test_liveness_across_branch() {
        use crate::analysis::LivenessAnalysis;

        let prog = make_program(vec![
            BpfInsn::mov64_imm(1, 10), // 0: defs r1
            jeq_imm(1, 0, 1),         // 1: uses r1, jump to 3
            BpfInsn::mov64_imm(0, 1),  // 2: defs r0
            BpfInsn::mov64_imm(0, 2),  // 3: defs r0
            exit_insn(),              // 4: uses r0
        ]);

        let liveness = LivenessAnalysis;
        let result = liveness.run(&prog);

        // r1 should be live between def (pc=0) and use (pc=1).
        assert!(result.live_out[0].contains(&1));
        assert!(result.live_in[1].contains(&1));

        // r0 should be live-in at exit.
        assert!(result.live_in[4].contains(&0));
    }

    #[test]
    fn test_branch_targets_backward_jump() {
        use crate::analysis::BranchTargetAnalysis;

        let prog = make_program(vec![
            BpfInsn::mov64_imm(0, 0), // 0
            BpfInsn::ja(-2),          // 1: ja -2 -> 1+1+(-2) = 0
        ]);

        let bt = BranchTargetAnalysis;
        let result = bt.run(&prog);

        assert!(result.is_target[0]);
        assert!(!result.is_target[1]);
    }

    // ── CondSelectPass tests ────────────────────────────────────────

    fn jne_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JNE | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    fn ctx_with_select_kfunc(btf_id: i32) -> PassContext {
        let mut ctx = PassContext::test_default();
        ctx.kfunc_registry.select64_btf_id = btf_id;
        ctx
    }

    #[test]
    fn test_cond_select_no_kfunc() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(!result.changed);
        assert!(result.sites_skipped[0].reason.contains("not available"));
    }

    #[test]
    fn test_cond_select_4insn_diamond() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(77);

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
    }

    #[test]
    fn test_cond_select_3insn_pattern() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(77);

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
    }

    #[test]
    fn test_cond_select_skips_predictable_branch() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        prog.annotations[0].branch_profile = Some(BranchProfile {
            taken_count: 950,
            not_taken_count: 50,
        });

        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(77);

        let pass = CondSelectPass { predictability_threshold: 0.1 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(!result.changed);
        assert!(result.sites_skipped.iter().any(|s| s.reason.contains("predictable")));
    }

    #[test]
    fn test_cond_select_no_match_different_dst() {
        let sites = scan_cond_select_sites(&[
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(2, 1), // different dst
        ]);
        assert!(sites.is_empty());
    }

    // ── BranchFlipPass tests ────────────────────────────────────────

    #[test]
    fn test_branch_flip_no_pgo() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 10),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 20),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = BranchFlipPass { min_bias: 0.7 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(!result.changed);
    }

    #[test]
    fn test_branch_flip_with_biased_pgo() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 10),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 20),
            exit_insn(),
        ]);
        prog.annotations[0].branch_profile = Some(BranchProfile {
            taken_count: 80,
            not_taken_count: 20,
        });

        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = BranchFlipPass { min_bias: 0.7 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        // Condition should be inverted (JNE -> JEQ)
        assert_eq!(bpf_op(prog.insns[0].code), BPF_JEQ);
        // Bodies should be swapped
        assert_eq!(prog.insns[1].imm, 20);
        assert_eq!(prog.insns[3].imm, 10);
    }

    #[test]
    fn test_invert_jcc_roundtrip() {
        let pairs = [
            (BPF_JEQ, BPF_JNE), (BPF_JGT, BPF_JLE), (BPF_JGE, BPF_JLT),
            (BPF_JSGT, BPF_JSLE), (BPF_JSGE, BPF_JSLT),
        ];
        for (a, b) in pairs {
            assert_eq!(invert_jcc_op(a), Some(b));
            assert_eq!(invert_jcc_op(b), Some(a));
        }
        assert_eq!(invert_jcc_op(BPF_JSET), None);
    }

    // ── SpectreMitigationPass tests ─────────────────────────────────

    #[test]
    fn test_spectre_inserts_nop() {
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 42),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert_eq!(prog.insns.len(), 4);
        // NOP should be at position 1
        assert!(prog.insns[1].is_ja() && prog.insns[1].off == 0);
    }

    #[test]
    fn test_spectre_no_double_insert() {
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),
            BpfInsn::nop(), // existing NOP
            BpfInsn::mov64_imm(0, 42),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(!result.changed);
        assert_eq!(prog.insns.len(), 4);
    }

    #[test]
    fn test_spectre_no_jcc() {
        let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 0), exit_insn()]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(!result.changed);
    }

    // ── Pipeline integration tests ──────────────────────────────────

    #[test]
    fn test_default_pipeline_wide_mem() {
        let mut prog = make_program(make_wide_mem_4byte_program());
        let ctx = PassContext::test_default();

        let pm = build_default_pipeline();
        let result = pm.run(&mut prog, &ctx).unwrap();
        assert!(result.program_changed);
        assert!(result.total_sites_applied >= 1);
    }

    #[test]
    fn test_full_pipeline_builds() {
        let pm = build_full_pipeline();
        assert!(pm.pass_count() >= 5);
    }
}
