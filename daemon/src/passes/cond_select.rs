// SPDX-License-Identifier: MIT
//! COND_SELECT optimization pass.

use crate::analysis::BranchTargetAnalysis;
use crate::insn::*;
use crate::pass::*;

use super::utils::{emit_packed_kinsn_call_with_off, ensure_btf_fd_slot, fixup_all_branches};

/// COND_SELECT pass: replaces branch+mov diamond patterns with
/// bpf_select64() kfunc calls (lowered to CMOV by the JIT).
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
/// Currently only handles cases where the JCC condition maps cleanly to
/// the kfunc's `cond != 0` test:
///   - JNE reg, 0: cond = reg (direct)
///   - JEQ reg, 0: cond = reg (swap true/false values)
///
/// Other JCC conditions are skipped (no simple mapping to a single register).
pub struct CondSelectPass;

/// A detected cond-select site.
pub struct CondSelectSite {
    pub start_pc: usize,
    pub old_len: usize,
    pub cond_reg: u8,
    pub dst_reg: u8,
    pub true_val: CondSelectValue,
    pub false_val: CondSelectValue,
    /// The JCC opcode (BPF_JNE, BPF_JEQ, etc.).
    pub jcc_op: u8,
    /// The JCC immediate (for BPF_K source).
    pub jcc_imm: i32,
    /// The JCC source kind (BPF_K or BPF_X).
    pub jcc_src: u8,
}

/// A cond_select site that has passed safety checks, ready for transformation.
struct SafeCondSelectSite {
    site: CondSelectSite,
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub enum CondSelectValue {
    Reg(u8),
    Imm(i32),
}

impl CondSelectPass {
    /// Analyze the program and return all detected cond-select sites.
    ///
    /// This is the pure detection phase. Each returned `CondSelectSite`
    /// describes a JCC+MOV pattern that could be lowered to a CMOV/kfunc.
    pub fn analyze(&self, insns: &[BpfInsn]) -> Vec<CondSelectSite> {
        scan_cond_select_sites(insns)
    }
}

/// Check whether a site's JCC condition can be mapped to the kfunc's `cond != 0`.
///
/// Returns `true` if we can use `cond_reg` directly (JNE reg, 0) or with
/// a true/false swap (JEQ reg, 0).
fn is_simple_zero_test(site: &CondSelectSite) -> bool {
    if site.jcc_src != BPF_K || site.jcc_imm != 0 {
        return false;
    }
    matches!(site.jcc_op, BPF_JNE | BPF_JEQ)
}

/// For JEQ reg, 0: the JCC jumps (to true_val) when reg == 0.
/// But bpf_select64 returns `a` when cond != 0.
/// So for JEQ: we need to swap a/b so that a=false_val, b=true_val.
/// Returns (a_val, b_val) in the order for the kfunc call.
fn kfunc_args_for_site(site: &CondSelectSite) -> (CondSelectValue, CondSelectValue) {
    match site.jcc_op {
        BPF_JNE => {
            // JNE jumps when cond != 0 -> true_val selected
            // bpf_select64(a, b, cond) returns a when cond != 0
            // So a = true_val, b = false_val
            (site.true_val, site.false_val)
        }
        BPF_JEQ => {
            // JEQ jumps when cond == 0 -> true_val selected
            // bpf_select64(a, b, cond) returns b when cond == 0
            // So a = false_val, b = true_val
            (site.false_val, site.true_val)
        }
        _ => unreachable!("is_simple_zero_test should have filtered this"),
    }
}

fn packed_supported_for_site(ctx: &PassContext, site: &CondSelectSite) -> bool {
    if !ctx.kinsn_registry.packed_supported_for_pass("cond_select") {
        return false;
    }

    let (a_val, b_val) = kfunc_args_for_site(site);
    matches!(a_val, CondSelectValue::Reg(_)) && matches!(b_val, CondSelectValue::Reg(_))
}

impl BpfPass for CondSelectPass {
    fn name(&self) -> &str {
        "cond_select"
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
        // Check if platform has CMOV support.
        if !ctx.platform.has_cmov {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "platform lacks CMOV support".into(),
                },
            ));
        }

        // Check if bpf_select64 kfunc is available.
        if ctx.kinsn_registry.select64_btf_id < 0 {
            // Fall back to detection-only mode.
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

        if !ctx.kinsn_registry.packed_supported_for_pass(self.name()) {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "bpf_select64 packed ABI not available".into(),
                },
            ));
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);

        let sites = self.analyze(&program.insns);
        let btf_id = ctx.kinsn_registry.select64_btf_id;
        let mut safe_sites: Vec<SafeCondSelectSite> = Vec::new();
        let mut skipped = Vec::new();

        for site in sites {
            // Safety check 1: only handle simple zero-test conditions.
            if !is_simple_zero_test(&site) {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: format!(
                        "JCC condition not a simple zero test (op={:#x} imm={} src={:#x})",
                        site.jcc_op, site.jcc_imm, site.jcc_src
                    ),
                });
                continue;
            }

            // Safety check 2: interior branch target (excluding the JCC's own target).
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

            if !packed_supported_for_site(ctx, &site) {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "packed ABI requires register true/false operands".into(),
                });
                continue;
            }

            safe_sites.push(SafeCondSelectSite { site });
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                sites_skipped: skipped,
                ..PassResult::unchanged(self.name())
            });
        }

        let kfunc_off = ctx
            .kinsn_registry
            .btf_fd_for_pass(self.name())
            .map(|fd| ensure_btf_fd_slot(program, fd))
            .unwrap_or(0);

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
                let (a_val, b_val) = kfunc_args_for_site(site);

                let a_reg = match a_val {
                    CondSelectValue::Reg(r) => r,
                    CondSelectValue::Imm(_) => unreachable!("packed path requires register inputs"),
                };
                let b_reg = match b_val {
                    CondSelectValue::Reg(r) => r,
                    CondSelectValue::Imm(_) => unreachable!("packed path requires register inputs"),
                };
                let payload = (site.dst_reg as u64)
                    | ((a_reg as u64) << 4)
                    | ((b_reg as u64) << 8)
                    | ((site.cond_reg as u64) << 12);
                let replacement = emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off);
                new_insns.extend_from_slice(&replacement);

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
        fixup_all_branches(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        program.remap_annotations(&addr_map);
        program.log_transform(TransformEntry {
            sites_applied: applied,
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
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
                        jcc_op: bpf_op(jcc.code),
                        jcc_imm: jcc.imm,
                        jcc_src: bpf_src(jcc.code),
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

        if jcc.is_cond_jmp() && jcc.off == 1 && is_mov64(mov_true) && is_mov64(mov_false) {
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

#[cfg(test)]
#[path = "cond_select_tests.rs"]
mod tests;
