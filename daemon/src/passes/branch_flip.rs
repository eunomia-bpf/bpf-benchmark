// SPDX-License-Identifier: MIT
//! BRANCH_FLIP PGO-guided pass.

use crate::analysis::BranchTargetAnalysis;
use crate::insn::*;
use crate::pass::*;

use super::fixup_branches_inline;

/// BRANCH_FLIP: PGO-guided reorder of if/else bodies.
///
/// Generalised pattern:
///   pc:           Jcc +N          // conditional jump over then-body to JA
///   pc+1..pc+N:   [then body: N insns]
///   pc+N+1:       JA +M           // unconditional jump over else-body
///   pc+N+2..pc+N+M+1: [else body: M insns]
///
/// After flip (inverted condition, bodies swapped):
///   pc:           J!cc +M         // inverted, jump over else-body (now first)
///   pc+1..pc+M:   [else body: M insns]
///   pc+M+1:       JA +N           // jump over then-body (now second)
///   pc+M+2..pc+M+N+1: [then body: N insns]
///
/// If PGO shows the taken path (else body) is hot, flip the condition and
/// swap bodies so the hot path becomes the fall-through (favoured by
/// the CPU static branch predictor).
///
/// Safety: skips sites where external branches target interior instructions,
/// or where JSET is used (no simple inverse). Also adjusts internal branch
/// offsets within relocated bodies via an address map.
pub struct BranchFlipPass {
    /// Minimum taken rate to trigger a flip.
    pub min_bias: f64,
}

/// A detected branch-flip site.
struct BranchFlipSite {
    /// PC of the Jcc instruction.
    pc: usize,
    /// Number of instructions in the then-body.
    then_len: usize,
    /// Number of instructions in the else-body.
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

            // PGO check.
            let should_flip = if let Some(ref bp) = program.annotations[site.pc].branch_profile {
                let total = bp.taken_count + bp.not_taken_count;
                if total > 0 {
                    bp.taken_count as f64 / total as f64 >= self.min_bias
                } else {
                    false
                }
            } else {
                false
            };

            if !should_flip {
                skipped.push(SkipReason {
                    pc: site.pc,
                    reason: "branch not biased enough or no PGO data".into(),
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

                // Emit inverted Jcc
                let old_jcc = program.insns[site.pc];
                let new_op = invert_jcc_op(bpf_op(old_jcc.code)).unwrap();
                let mut new_jcc = old_jcc;
                new_jcc.code = (old_jcc.code & 0x0f) | new_op;
                new_jcc.off = site.else_len as i16;
                new_insns.push(new_jcc);

                // Emit else body
                for i in else_start..else_end {
                    addr_map[i] = new_insns.len();
                    new_insns.push(program.insns[i]);
                }

                // Emit JA
                addr_map[ja_pc] = new_insns.len();
                new_insns.push(BpfInsn::ja(site.then_len as i16));

                // Emit then body
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

        // Phase 4: fix up internal branches.
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

/// Scan for branch-flip candidate sites.
fn scan_branch_flip_sites(insns: &[BpfInsn]) -> Vec<BranchFlipSite> {
    let mut sites = Vec::new();
    let n = insns.len();
    let mut pc = 0;

    while pc < n {
        let jcc = &insns[pc];
        if jcc.is_cond_jmp() && jcc.off > 0 {
            let then_len = jcc.off as usize;
            let ja_pc = pc + 1 + then_len;
            if ja_pc < n && insns[ja_pc].is_ja() && insns[ja_pc].off > 0 {
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

    #[test]
    fn test_branch_flip_no_pgo() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 1),
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
    }

    #[test]
    fn test_branch_flip_with_biased_pgo() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 1),
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
        assert_eq!(bpf_op(prog.insns[0].code), BPF_JEQ);
        assert_eq!(prog.insns[1].imm, 20);
        assert_eq!(prog.insns[3].imm, 10);
    }

    #[test]
    fn test_branch_flip_asymmetric_bodies() {
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::mov64_imm(1, 2),
            BpfInsn::ja(3),
            BpfInsn::mov64_imm(0, 10),
            BpfInsn::mov64_imm(1, 20),
            BpfInsn::mov64_imm(2, 30),
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
        assert_eq!(bpf_op(prog.insns[0].code), BPF_JNE);
        assert_eq!(prog.insns[0].off, 3);
        assert_eq!(prog.insns[1].imm, 10);
        assert_eq!(prog.insns[2].imm, 20);
        assert_eq!(prog.insns[3].imm, 30);
        assert!(prog.insns[4].is_ja());
        assert_eq!(prog.insns[4].off, 2);
        assert_eq!(prog.insns[5].imm, 1);
        assert_eq!(prog.insns[6].imm, 2);
        assert_eq!(prog.insns.len(), 8);
    }

    #[test]
    fn test_branch_flip_skips_jset() {
        let mut prog = make_program(vec![
            BpfInsn {
                code: BPF_JMP | BPF_JSET | BPF_K,
                regs: BpfInsn::make_regs(1, 0),
                off: 1,
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
            jne_imm(1, 0, 1),
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
    fn test_branch_flip_scan_finds_sites() {
        let insns = vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::mov64_imm(1, 2),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 10),
            exit_insn(),
        ];
        let sites = scan_branch_flip_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].pc, 0);
        assert_eq!(sites[0].then_len, 2);
        assert_eq!(sites[0].else_len, 1);
        assert_eq!(sites[0].total_len(), 5);
    }

    #[test]
    fn test_branch_flip_preserves_program_size() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 1),
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
}
