// SPDX-License-Identifier: MIT
//! BRANCH_FLIP PGO-guided pass.

use crate::analysis::BranchTargetAnalysis;
use crate::insn::*;
use crate::pass::*;

use super::fixup_branches_inline;

/// BRANCH_FLIP: PGO-guided reorder of if/else bodies.
///
/// True if/else diamond in BPF bytecode:
///   pc:             Jcc +N          // conditional jump; if taken, go to else_start
///   pc+1..pc+N:     [then body: N-1 insns]
///   pc+N:           JA +M           // unconditional jump over else-body
///   pc+N+1..pc+N+M: [else body: M insns]
///
/// Where:
///   - `N = jcc.off` (the Jcc offset)
///   - then_len = N - 1 (instructions between Jcc and JA, exclusive)
///   - else_start = pc + N + 1
///   - else_len = M = ja.off
///
/// After flip (inverted condition, bodies swapped):
///   pc:             J!cc +M         // inverted, jump over else-body (now first)
///   pc+1..pc+M:     [else body: M insns]
///   pc+M+1:         JA +(N-1)       // jump over then-body (now second)
///   pc+M+2..pc+M+N: [then body: N-1 insns]
///
/// **PGO-only mode**: branch_flip only fires when PGO profiler data (via
/// `BranchProfile` annotation) shows the taken path is hot. Without profiler
/// data, the pass skips all sites (no heuristic fallback).
///
/// Safety: skips sites where external branches target interior instructions,
/// or where JSET is used (no simple inverse). Also adjusts internal branch
/// offsets within relocated bodies via an address map.
pub struct BranchFlipPass {
    /// Minimum taken rate to trigger a PGO-guided flip.
    pub min_bias: f64,
}

/// A detected branch-flip site.
struct BranchFlipSite {
    /// PC of the Jcc instruction.
    pc: usize,
    /// Number of instructions in the then-body (N-1, between Jcc and JA).
    then_len: usize,
    /// Number of instructions in the else-body (M = ja.off).
    else_len: usize,
}

impl BranchFlipSite {
    /// Total number of instructions in the site (Jcc + then + JA + else).
    fn total_len(&self) -> usize {
        1 + self.then_len + 1 + self.else_len
    }
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
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);

        let n = program.insns.len();
        let orig_len = n;

        // Phase 1: scan for all candidate sites.
        let sites = scan_branch_flip_sites(&program.insns);

        // Phase 2: filter sites and collect safe ones to apply.
        let mut safe_sites: Vec<BranchFlipSite> = Vec::new();
        let mut skipped = Vec::new();

        for site in &sites {
            let jcc = &program.insns[site.pc];
            let own_target = (site.pc as i64 + 1 + jcc.off as i64) as usize;
            let site_end = site.pc + site.total_len();

            let has_exterior_interior = (site.pc + 1..site_end).any(|pc_inner| {
                pc_inner < bt.is_target.len()
                    && bt.is_target[pc_inner]
                    && pc_inner != own_target
            });

            if has_exterior_interior {
                skipped.push(SkipReason {
                    pc: site.pc,
                    reason: "interior branch target from external source".into(),
                });
                continue;
            }

            // Safety check: JSET cannot be inverted.
            if invert_jcc_op(bpf_op(jcc.code)).is_none() {
                skipped.push(SkipReason {
                    pc: site.pc,
                    reason: "cannot invert condition opcode".into(),
                });
                continue;
            }

            // Decision: PGO-only mode. No heuristic fallback.
            let should_flip = if let Some(ref bp) = program.annotations[site.pc].branch_profile {
                let total = bp.taken_count + bp.not_taken_count;
                if total > 0 && bp.taken_count as f64 / total as f64 >= self.min_bias {
                    true
                } else {
                    false
                }
            } else {
                false
            };

            if !should_flip {
                let reason = if program.annotations[site.pc].branch_profile.is_some() {
                    "branch not biased enough".to_string()
                } else {
                    "no PGO data available (PGO-only mode)".to_string()
                };
                skipped.push(SkipReason {
                    pc: site.pc,
                    reason,
                });
                continue;
            }

            safe_sites.push(BranchFlipSite {
                pc: site.pc,
                then_len: site.then_len,
                else_len: site.else_len,
            });
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

        // Phase 3: apply rewrites.
        safe_sites.sort_by_key(|s| s.pc);

        let mut new_insns: Vec<BpfInsn> = Vec::with_capacity(n);
        let mut addr_map = vec![0usize; n + 1];
        let mut pc = 0;
        let mut site_idx = 0;
        let mut applied = 0;

        while pc < n {
            let new_pc = new_insns.len();
            addr_map[pc] = new_pc;

            if site_idx < safe_sites.len() && pc == safe_sites[site_idx].pc {
                let site = &safe_sites[site_idx];
                let then_start = site.pc + 1;
                let then_end = site.pc + 1 + site.then_len;
                let ja_pc = then_end;
                let else_start = ja_pc + 1;
                let else_end = else_start + site.else_len;

                // Emit inverted Jcc.
                // New layout: [Jcc'] [else M insns] [JA] [then N-1 insns]
                // Jcc' not-taken: fall through to else body (M insns) then JA
                // Jcc' taken: skip else+JA to reach then body
                // offset = else_len + 1 (skip M else insns + 1 JA insn)
                let old_jcc = program.insns[site.pc];
                let new_op = invert_jcc_op(bpf_op(old_jcc.code)).unwrap();
                let mut new_jcc = old_jcc;
                new_jcc.code = (old_jcc.code & 0x0f) | new_op;
                new_jcc.off = (site.else_len + 1) as i16;
                new_insns.push(new_jcc);

                // Emit else body (was after JA, now first)
                for i in else_start..else_end {
                    addr_map[i] = new_insns.len();
                    new_insns.push(program.insns[i]);
                }

                // Emit JA that skips over then body
                addr_map[ja_pc] = new_insns.len();
                new_insns.push(BpfInsn::ja(site.then_len as i16));

                // Emit then body (was first, now second)
                for i in then_start..then_end {
                    addr_map[i] = new_insns.len();
                    new_insns.push(program.insns[i]);
                }

                pc = else_end;
                site_idx += 1;
                applied += 1;
            } else {
                new_insns.push(program.insns[pc]);
                if program.insns[pc].is_ldimm64() && pc + 1 < n {
                    pc += 1;
                    addr_map[pc] = new_insns.len();
                    new_insns.push(program.insns[pc]);
                }
                pc += 1;
            }
        }
        addr_map[n] = new_insns.len();

        // Phase 4: fix up internal branches (for instructions NOT part of rewritten sites).
        fixup_branches_inline(&mut new_insns, &program.insns, &addr_map);

        // Restore the manually-set JCC and JA offsets that fixup may have overwritten.
        for site in &safe_sites {
            let new_jcc_pc = addr_map[site.pc];
            new_insns[new_jcc_pc].off = (site.else_len + 1) as i16;
            let old_ja_pc = site.pc + 1 + site.then_len;
            let new_ja_pc = addr_map[old_ja_pc];
            new_insns[new_ja_pc].off = site.then_len as i16;
        }

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

/// Scan for branch-flip candidate sites with correct if/else diamond shape.
///
/// True diamond:
///   pc:     Jcc +N          // N = jcc.off
///   pc+1..pc+N-1: then body (N-1 insns)
///   pc+N:   JA +M
///   pc+N+1..pc+N+M: else body (M insns)
fn scan_branch_flip_sites(insns: &[BpfInsn]) -> Vec<BranchFlipSite> {
    let mut sites = Vec::new();
    let n = insns.len();
    let mut pc = 0;

    while pc < n {
        let jcc = &insns[pc];
        if jcc.is_cond_jmp() && jcc.off > 1 {
            let off = jcc.off as usize;
            // The Jcc target is pc + 1 + off = pc + N + 1 (else_start).
            // JA is at pc + off (the last instruction of the then block + JA).
            let ja_pc = pc + off;
            if ja_pc < n && insns[ja_pc].is_ja() && insns[ja_pc].off > 0 {
                let then_len = off - 1; // N-1 instructions between Jcc and JA
                let else_len = insns[ja_pc].off as usize;
                let site_end = ja_pc + 1 + else_len;
                if site_end <= n {
                    let valid = !has_straddling_ldimm64(insns, pc + 1, pc + 1 + then_len)
                        && !has_straddling_ldimm64(insns, ja_pc + 1, ja_pc + 1 + else_len);
                    if valid {
                        sites.push(BranchFlipSite {
                            pc,
                            then_len,
                            else_len,
                        });
                        pc = site_end;
                        continue;
                    }
                }
            }
        }
        pc += 1;
    }
    sites
}

fn has_straddling_ldimm64(insns: &[BpfInsn], range_start: usize, range_end: usize) -> bool {
    if range_end == 0 || range_start >= range_end {
        return false;
    }
    let last = range_end - 1;
    if last < insns.len() && insns[last].is_ldimm64() {
        return true;
    }
    false
}

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
        BPF_JSET => None,
        _ => None,
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::pass::{AnalysisCache, BranchProfile, PassContext};

    fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
        BpfProgram::new(insns, ProgMeta::default())
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn { code: BPF_JMP | BPF_EXIT, regs: 0, off: 0, imm: 0 }
    }

    fn jne_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JNE | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
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

    // ── True diamond: Jcc +N ; [then N-1] ; JA +M ; [else M] ──
    // Example: JNE +2 ; mov(then) ; JA +1 ; mov(else)
    // then_len=1, else_len=1

    #[test]
    fn test_scan_finds_diamond() {
        // JNE r1, 0, +2 ; mov r0, 10 ; JA +1 ; mov r0, 20 ; exit
        let insns = vec![
            jne_imm(1, 0, 2),           // pc=0: Jcc +2 -> target pc=3 (else_start)
            BpfInsn::mov64_imm(0, 10),  // pc=1: then body
            BpfInsn::ja(1),             // pc=2: JA +1 -> skip else
            BpfInsn::mov64_imm(0, 20),  // pc=3: else body
            exit_insn(),                 // pc=4
        ];
        let sites = scan_branch_flip_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].pc, 0);
        assert_eq!(sites[0].then_len, 1);
        assert_eq!(sites[0].else_len, 1);
        assert_eq!(sites[0].total_len(), 4);
    }

    #[test]
    fn test_scan_asymmetric_diamond() {
        // JEQ r1, 0, +3 ; mov1 ; mov2 ; JA +1 ; mov3 ; exit
        let insns = vec![
            jeq_imm(1, 0, 3),           // Jcc +3 -> target pc=4 (else_start)
            BpfInsn::mov64_imm(0, 1),   // then[0]
            BpfInsn::mov64_imm(1, 2),   // then[1]
            BpfInsn::ja(1),             // JA +1
            BpfInsn::mov64_imm(0, 10),  // else[0]
            exit_insn(),
        ];
        let sites = scan_branch_flip_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].then_len, 2);
        assert_eq!(sites[0].else_len, 1);
    }

    #[test]
    fn test_branch_flip_no_pgo_skips() {
        // Without PGO data, the pass should not flip.
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
        assert_eq!(result.sites_applied, 0);
        assert!(result.sites_skipped.iter().any(|s| s.reason.contains("no PGO data")));
    }

    #[test]
    fn test_branch_flip_with_biased_pgo() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 2),           // Jcc +2 -> else at pc=3
            BpfInsn::mov64_imm(0, 10),  // then
            BpfInsn::ja(1),             // skip else
            BpfInsn::mov64_imm(0, 20),  // else
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
        // After flip layout: [JEQ +2] [else: mov 20] [JA +1] [then: mov 10] [exit]
        assert_eq!(bpf_op(prog.insns[0].code), BPF_JEQ); // inverted JNE -> JEQ
        assert_eq!(prog.insns[0].off, 2); // skip else(1) + JA(1) = 2
        assert_eq!(prog.insns[1].imm, 20); // else body first
        assert!(prog.insns[2].is_ja());
        assert_eq!(prog.insns[2].off, 1); // jump over then body (1 insn)
        assert_eq!(prog.insns[3].imm, 10); // then body second
        assert_eq!(prog.insns.len(), 5); // same size
    }

    #[test]
    fn test_branch_flip_asymmetric_with_pgo() {
        // then=2 insns, else=3 insns
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 3),                // Jcc +3 -> else at pc=4
            BpfInsn::mov64_imm(0, 1),        // then[0]
            BpfInsn::mov64_imm(1, 2),        // then[1]
            BpfInsn::ja(3),                  // JA +3 -> skip else
            BpfInsn::mov64_imm(0, 10),       // else[0]
            BpfInsn::mov64_imm(1, 20),       // else[1]
            BpfInsn::mov64_imm(2, 30),       // else[2]
            exit_insn(),
        ]);
        prog.annotations[0].branch_profile = Some(BranchProfile {
            taken_count: 90,
            not_taken_count: 10,
        });

        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = BranchFlipPass { min_bias: 0.7 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert_eq!(bpf_op(prog.insns[0].code), BPF_JNE); // inverted JEQ -> JNE
        assert_eq!(prog.insns[0].off, 4); // skip else(3) + JA(1) = 4
        // Else body first
        assert_eq!(prog.insns[1].imm, 10);
        assert_eq!(prog.insns[2].imm, 20);
        assert_eq!(prog.insns[3].imm, 30);
        // JA to skip then body
        assert!(prog.insns[4].is_ja());
        assert_eq!(prog.insns[4].off, 2); // jump over then body (2 insns)
        // Then body second
        assert_eq!(prog.insns[5].imm, 1);
        assert_eq!(prog.insns[6].imm, 2);
        assert_eq!(prog.insns.len(), 8); // same size
    }

    #[test]
    fn test_branch_flip_skips_jset() {
        let mut prog = make_program(vec![
            BpfInsn {
                code: BPF_JMP | BPF_JSET | BPF_K,
                regs: BpfInsn::make_regs(1, 0),
                off: 2,
                imm: 0xff,
            },
            BpfInsn::mov64_imm(0, 10),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 20),
            exit_insn(),
        ]);
        prog.annotations[0].branch_profile = Some(BranchProfile {
            taken_count: 90,
            not_taken_count: 10,
        });

        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = BranchFlipPass { min_bias: 0.7 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(!result.changed);
        assert!(result.sites_skipped.iter().any(|s| s.reason.contains("cannot invert")));
    }

    #[test]
    fn test_branch_flip_insufficient_bias() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 10),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 20),
            exit_insn(),
        ]);
        prog.annotations[0].branch_profile = Some(BranchProfile {
            taken_count: 60,
            not_taken_count: 40,
        });

        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = BranchFlipPass { min_bias: 0.7 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(result.sites_skipped.iter().any(|s| s.reason.contains("not biased enough")));
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

    #[test]
    fn test_branch_flip_preserves_program_size() {
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
        let orig_len = prog.insns.len();

        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = BranchFlipPass { min_bias: 0.7 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert_eq!(prog.insns.len(), orig_len);
    }

    #[test]
    fn test_branch_flip_no_heuristic_fallback() {
        // Even with very asymmetric bodies, no PGO = no flip.
        let mut prog = make_program(vec![
            jne_imm(1, 0, 6),                // Jcc +6 -> else at pc=7
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::mov64_imm(1, 2),
            BpfInsn::mov64_imm(2, 3),
            BpfInsn::mov64_imm(3, 4),
            BpfInsn::mov64_imm(4, 5),
            BpfInsn::ja(1),                  // JA +1
            BpfInsn::mov64_imm(0, 99),       // else
            exit_insn(),
        ]);
        // No PGO data at all
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = BranchFlipPass { min_bias: 0.7 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(!result.changed, "should NOT flip without PGO data");
        assert!(result.sites_skipped.iter().any(|s| s.reason.contains("no PGO data")));
    }
}
