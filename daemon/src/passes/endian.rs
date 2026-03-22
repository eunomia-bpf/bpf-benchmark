// SPDX-License-Identifier: MIT
//! ENDIAN_FUSION optimization pass.

use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::utils::{emit_kfunc_call, fixup_all_branches, KfuncArg};

/// BPF ALU endian operation code.
const BPF_END: u8 = 0xd0;
/// BPF_TO_BE source modifier (big-endian byte swap on LE host).
const BPF_TO_BE: u8 = 0x08;

/// ENDIAN_FUSION optimization pass: replaces LDX_MEM + ENDIAN_TO_BE patterns
/// with bpf_endian_loadXX() kfunc calls (lowered to MOVBE on x86 or
/// LDR+REV on ARM64 by the JIT).
///
/// Pattern:
///   LDX_MEM(BPF_W, dst, src, off)     ; 32-bit load
///   END_TO_BE(dst, 32)                 ; byte-swap to big-endian
///
/// Also matches BPF_H (16-bit) and BPF_DW (64-bit) variants.
///
/// Replacement:
///   r1 = src + off                     ; compute effective address
///   call bpf_endian_loadXX             ; fused load + byte-swap
///   dst = r0                           ; if dst != r0
pub struct EndianFusionPass;

/// An endian fusion site: a LDX_MEM immediately followed by ENDIAN_TO_BE
/// on the same destination register, with matching sizes.
struct EndianFusionSite {
    start_pc: usize,
    old_len: usize,
    dst_reg: u8,
    src_reg: u8,
    offset: i16,
    /// BPF size code: BPF_H (16), BPF_W (32), or BPF_DW (64).
    size: u8,
}

/// Scan for LDX_MEM + ENDIAN_TO_BE patterns with matching sizes.
fn scan_endian_fusion_sites(insns: &[BpfInsn]) -> Vec<EndianFusionSite> {
    let mut sites = Vec::new();
    let n = insns.len();
    let mut pc = 0;

    while pc + 1 < n {
        let i0 = &insns[pc];
        let i1 = &insns[pc + 1];

        // i0 must be LDX_MEM of some size.
        if !i0.is_ldx_mem() {
            pc += 1;
            continue;
        }

        // i1 must be ALU|END|TO_BE with matching size.
        let is_endian_to_be = i1.code == (BPF_ALU | BPF_END | BPF_TO_BE);
        if !is_endian_to_be {
            pc += 1;
            continue;
        }

        // dst registers must match.
        if i0.dst_reg() != i1.dst_reg() {
            pc += 1;
            continue;
        }

        // Match load size with endian size.
        let load_size = bpf_size(i0.code);
        let endian_size = i1.imm;

        let sizes_match = match (load_size, endian_size) {
            (BPF_H, 16) => true,
            (BPF_W, 32) => true,
            (BPF_DW, 64) => true,
            _ => false,
        };

        if sizes_match {
            sites.push(EndianFusionSite {
                start_pc: pc,
                old_len: 2,
                dst_reg: i0.dst_reg(),
                src_reg: i0.src_reg(),
                offset: i0.off,
                size: load_size,
            });
            pc += 2;
        } else {
            pc += 1;
        }
    }

    sites
}

/// Select the appropriate BTF ID for a given load size.
fn btf_id_for_size(ctx: &PassContext, size: u8) -> i32 {
    match size {
        BPF_H => ctx.kfunc_registry.endian_load16_btf_id,
        BPF_W => ctx.kfunc_registry.endian_load32_btf_id,
        BPF_DW => ctx.kfunc_registry.endian_load64_btf_id,
        _ => -1,
    }
}

/// Check if any of the three endian_load kfuncs are available.
fn any_endian_kfunc_available(ctx: &PassContext) -> bool {
    ctx.kfunc_registry.endian_load16_btf_id >= 0
        || ctx.kfunc_registry.endian_load32_btf_id >= 0
        || ctx.kfunc_registry.endian_load64_btf_id >= 0
}

/// Emit the kfunc call sequence for an endian load.
///
/// If offset is 0, we pass the src register directly:
///   MOV r1, src_reg
///   CALL bpf_endian_loadXX
///   MOV dst, r0  (if dst != r0)
///
/// If offset is non-zero, we compute the effective address:
///   MOV r1, src_reg
///   ADD64 r1, offset
///   CALL bpf_endian_loadXX
///   MOV dst, r0  (if dst != r0)
fn emit_endian_fusion_call(
    dst_reg: u8,
    src_reg: u8,
    offset: i16,
    btf_id: i32,
) -> Vec<BpfInsn> {
    if offset == 0 {
        // Simple case: no offset addition needed.
        emit_kfunc_call(dst_reg, &[KfuncArg::Reg(src_reg)], btf_id)
    } else {
        // Need to add offset to base address.
        let mut out = Vec::with_capacity(5);
        // MOV r1, src_reg (unless src_reg is already r1)
        if src_reg != 1 {
            out.push(BpfInsn::mov64_reg(1, src_reg));
        }
        // ADD64 r1, offset
        out.push(BpfInsn::alu64_imm(BPF_ADD, 1, offset as i32));
        // CALL kfunc
        out.push(BpfInsn::call_kfunc(btf_id));
        // MOV dst, r0 (if needed)
        if dst_reg != 0 {
            out.push(BpfInsn::mov64_reg(dst_reg, 0));
        }
        out
    }
}

/// BPF ALU ADD operation code.
const BPF_ADD: u8 = 0x00;

impl BpfPass for EndianFusionPass {
    fn name(&self) -> &str {
        "endian_fusion"
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
        // Check if any endian_load kfunc is available.
        if !any_endian_kfunc_available(ctx) {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![SkipReason {
                    pc: 0,
                    reason: "bpf_endian_loadXX kfuncs not available".into(),
                }],
                diagnostics: vec![],
            });
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);
        let liveness_analysis = LivenessAnalysis;
        let liveness = analyses.get(&liveness_analysis, program);

        let sites = scan_endian_fusion_sites(&program.insns);
        let mut safe_sites = Vec::new();
        let mut skipped = Vec::new();

        for site in sites {
            // Check if the specific size kfunc is available.
            let btf_id = btf_id_for_size(ctx, site.size);
            if btf_id < 0 {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: format!(
                        "bpf_endian_load{} kfunc not available",
                        match site.size {
                            BPF_H => 16,
                            BPF_W => 32,
                            BPF_DW => 64,
                            _ => 0,
                        }
                    ),
                });
                continue;
            }

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
            // A kfunc call clobbers r1-r5. If any caller-saved register
            // (other than dst_reg) is live after the site, skip.
            let site_end = site.start_pc + site.old_len;
            if site_end > 0 && site_end - 1 < liveness.live_out.len() {
                let live_after = &liveness.live_out[site_end - 1];
                let caller_saved_conflict = (1u8..=5)
                    .any(|r| r != site.dst_reg && live_after.contains(&r));
                if caller_saved_conflict {
                    skipped.push(SkipReason {
                        pc: site.start_pc,
                        reason: "caller-saved register conflict".into(),
                    });
                    continue;
                }
            }

            // Safety check 3: src_reg must not be the same as dst_reg
            // when offset != 0, because we modify r1 before the call.
            // Actually, src_reg is only read (to compute addr), and we
            // copy it to r1 first, so this is safe. But if src_reg is
            // in r1-r5 and is live after, it's already caught by check 2.

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
                let btf_id = btf_id_for_size(ctx, site.size);

                let replacement = emit_endian_fusion_call(
                    site.dst_reg,
                    site.src_reg,
                    site.offset,
                    btf_id,
                );
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
            pass_name: self.name().into(),
            sites_applied: applied,
            insns_before: orig_len,
            insns_after: program.insns.len(),
            details: vec![],
        });

        // Record module FDs needed for the kfunc calls we emitted.
        if applied > 0 {
            if let Some(fd) = ctx.kfunc_registry.module_fd_for_pass(self.name()) {
                if !program.required_module_fds.contains(&fd) {
                    program.required_module_fds.push(fd);
                }
            }
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

#[cfg(test)]
mod tests {
    use super::*;
    use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
    use crate::pass::{AnalysisCache, PassContext, PassManager};

    fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
        BpfProgram::new(insns, ProgMeta::default())
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn { code: BPF_JMP | BPF_EXIT, regs: 0, off: 0, imm: 0 }
    }

    fn endian_to_be(dst: u8, size: i32) -> BpfInsn {
        BpfInsn {
            code: BPF_ALU | BPF_END | BPF_TO_BE,
            regs: BpfInsn::make_regs(dst, 0),
            off: 0,
            imm: size,
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

    fn ctx_with_endian_kfuncs(btf_id16: i32, btf_id32: i32, btf_id64: i32) -> PassContext {
        let mut ctx = PassContext::test_default();
        ctx.kfunc_registry.endian_load16_btf_id = btf_id16;
        ctx.kfunc_registry.endian_load32_btf_id = btf_id32;
        ctx.kfunc_registry.endian_load64_btf_id = btf_id64;
        ctx
    }

    fn ctx_with_endian32_kfunc(btf_id: i32) -> PassContext {
        ctx_with_endian_kfuncs(-1, btf_id, -1)
    }

    // ── Pattern scanning tests ─────────────────────────────────────

    #[test]
    fn test_scan_endian_fusion_basic_32bit() {
        let insns = vec![
            BpfInsn::ldx_mem(BPF_W, 2, 1, 4),  // LDX_MEM(W) r2, [r1+4]
            endian_to_be(2, 32),                  // ENDIAN_TO_BE r2, 32
            exit_insn(),
        ];
        let sites = scan_endian_fusion_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].start_pc, 0);
        assert_eq!(sites[0].old_len, 2);
        assert_eq!(sites[0].dst_reg, 2);
        assert_eq!(sites[0].src_reg, 1);
        assert_eq!(sites[0].offset, 4);
        assert_eq!(sites[0].size, BPF_W);
    }

    #[test]
    fn test_scan_endian_fusion_16bit() {
        let insns = vec![
            BpfInsn::ldx_mem(BPF_H, 3, 6, 10),
            endian_to_be(3, 16),
            exit_insn(),
        ];
        let sites = scan_endian_fusion_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].size, BPF_H);
        assert_eq!(sites[0].dst_reg, 3);
        assert_eq!(sites[0].offset, 10);
    }

    #[test]
    fn test_scan_endian_fusion_64bit() {
        let insns = vec![
            BpfInsn::ldx_mem(BPF_DW, 0, 7, 0),
            endian_to_be(0, 64),
            exit_insn(),
        ];
        let sites = scan_endian_fusion_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].size, BPF_DW);
        assert_eq!(sites[0].dst_reg, 0);
        assert_eq!(sites[0].offset, 0);
    }

    #[test]
    fn test_scan_endian_fusion_no_match_different_regs() {
        let insns = vec![
            BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
            endian_to_be(3, 32),  // different dst
            exit_insn(),
        ];
        let sites = scan_endian_fusion_sites(&insns);
        assert!(sites.is_empty());
    }

    #[test]
    fn test_scan_endian_fusion_no_match_size_mismatch() {
        let insns = vec![
            BpfInsn::ldx_mem(BPF_H, 2, 1, 0),  // 16-bit load
            endian_to_be(2, 32),                   // 32-bit swap -- mismatch
            exit_insn(),
        ];
        let sites = scan_endian_fusion_sites(&insns);
        assert!(sites.is_empty());
    }

    #[test]
    fn test_scan_endian_fusion_no_match_byte_load() {
        // BPF_B (byte) load doesn't need endian swap.
        let insns = vec![
            BpfInsn::ldx_mem(BPF_B, 2, 1, 0),
            endian_to_be(2, 16),
            exit_insn(),
        ];
        let sites = scan_endian_fusion_sites(&insns);
        assert!(sites.is_empty());
    }

    #[test]
    fn test_scan_endian_fusion_multiple_sites() {
        let insns = vec![
            BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
            endian_to_be(2, 32),
            BpfInsn::ldx_mem(BPF_H, 3, 1, 4),
            endian_to_be(3, 16),
            exit_insn(),
        ];
        let sites = scan_endian_fusion_sites(&insns);
        assert_eq!(sites.len(), 2);
        assert_eq!(sites[0].start_pc, 0);
        assert_eq!(sites[0].size, BPF_W);
        assert_eq!(sites[1].start_pc, 2);
        assert_eq!(sites[1].size, BPF_H);
    }

    #[test]
    fn test_scan_endian_fusion_zero_offset() {
        let insns = vec![
            BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
            endian_to_be(2, 32),
            exit_insn(),
        ];
        let sites = scan_endian_fusion_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].offset, 0);
    }

    // ── Pass execution tests ───────────────────────────────────────

    #[test]
    fn test_endian_fusion_pass_skip_when_kfunc_unavailable() {
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
            endian_to_be(2, 32),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default(); // all btf_ids = -1

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(result.sites_skipped[0].reason.contains("kfuncs not available"));
    }

    #[test]
    fn test_endian_fusion_pass_emit_kfunc_call_32bit() {
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_W, 2, 6, 8),
            endian_to_be(2, 32),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);

        // Verify a kfunc call exists with the correct btf_id.
        let has_kfunc_call = prog.insns.iter().any(|i| i.is_call() && i.src_reg() == 2);
        assert!(has_kfunc_call, "expected a kfunc call in the output");
        let call_insn = prog.insns.iter().find(|i| i.is_call() && i.src_reg() == 2).unwrap();
        assert_eq!(call_insn.imm, 8888);

        // Verify the last instruction is still EXIT.
        assert!(prog.insns.last().unwrap().is_exit());
    }

    #[test]
    fn test_endian_fusion_pass_zero_offset() {
        // When offset is 0, the emitted sequence should not include ADD.
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            endian_to_be(2, 32),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);

        // With zero offset, emit_kfunc_call is used directly (no ADD).
        // Check no ADD instruction was emitted.
        let has_add = prog.insns.iter().any(|i| {
            i.code == (BPF_ALU64 | BPF_ADD | BPF_K)
        });
        assert!(!has_add, "should not emit ADD when offset is 0");
    }

    #[test]
    fn test_endian_fusion_pass_nonzero_offset() {
        // When offset is non-zero, the emitted sequence should include ADD.
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_W, 2, 6, 12),
            endian_to_be(2, 32),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);

        // Check ADD r1, 12 was emitted.
        let has_add = prog.insns.iter().any(|i| {
            i.code == (BPF_ALU64 | BPF_ADD | BPF_K) && i.dst_reg() == 1 && i.imm == 12
        });
        assert!(has_add, "should emit ADD r1, 12 for non-zero offset");
    }

    #[test]
    fn test_endian_fusion_pass_caller_saved_conflict() {
        // r3 is live after the site (used in a later mov), so the pass
        // should skip since kfunc call clobbers r1-r5.
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(3, 99),              // r3 = 99
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            endian_to_be(2, 32),
            BpfInsn::mov64_reg(0, 3),                // uses r3 after site
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(result.sites_skipped.iter().any(|s| s.reason.contains("caller-saved")));
    }

    #[test]
    fn test_endian_fusion_pass_interior_branch_target() {
        // A branch targets the ENDIAN_TO_BE instruction inside the site.
        let mut prog = make_program(vec![
            jeq_imm(5, 0, 1),                        // if r5 == 0, jump to pc=2
            BpfInsn::ldx_mem(BPF_W, 2, 1, 0),        // pc=1
            endian_to_be(2, 32),                       // pc=2 -- branch target
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert!(result.sites_skipped.iter().any(|s| s.reason.contains("interior branch")));
    }

    #[test]
    fn test_endian_fusion_pass_branch_fixup() {
        // Branch over a 2-insn site. After rewrite the site becomes
        // longer (kfunc call sequence), so branch offsets must be adjusted.
        let mut prog = make_program(vec![
            jeq_imm(5, 0, 2),                        // if r5==0, skip 2 insns to exit
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),        // pc=1: site start
            endian_to_be(2, 32),                       // pc=2: site end
            exit_insn(),                               // pc=3: branch target
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        // The branch at pc=0 should still reach the EXIT instruction.
        let last_pc = prog.insns.len() - 1;
        assert!(prog.insns[last_pc].is_exit());
        let branch_target = (0i64 + 1 + prog.insns[0].off as i64) as usize;
        assert_eq!(branch_target, last_pc);
    }

    #[test]
    fn test_endian_fusion_pass_records_module_fd() {
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            endian_to_be(2, 32),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let mut ctx = ctx_with_endian32_kfunc(8888);
        ctx.kfunc_registry.module_fd = Some(42);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert!(prog.required_module_fds.contains(&42));
    }

    #[test]
    fn test_endian_fusion_pass_specific_size_unavailable() {
        // Only 32-bit kfunc available, but pattern is 16-bit.
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_H, 2, 1, 0),
            endian_to_be(2, 16),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888); // only 32-bit available

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(result.sites_skipped.iter().any(|s| s.reason.contains("load16")));
    }

    #[test]
    fn test_endian_fusion_pass_dst_is_r0() {
        // When dst_reg is r0, no trailing MOV should be emitted.
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_W, 0, 6, 0),
            endian_to_be(0, 32),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        // No redundant MOV r0, r0.
        let mov_r0_r0_count = prog.insns.iter().filter(|i| {
            i.code == (BPF_ALU64 | BPF_MOV | BPF_X) && i.dst_reg() == 0 && i.src_reg() == 0
        }).count();
        assert_eq!(mov_r0_r0_count, 0, "should not emit redundant MOV r0, r0");
    }

    #[test]
    fn test_endian_fusion_pass_no_sites() {
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(0, 42),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
    }

    #[test]
    fn test_endian_fusion_pass_two_consecutive_sites() {
        // Use callee-saved register (r6) as source so r1-r5 are not
        // live between sites (avoids caller-saved conflict).
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_W, 7, 6, 0),
            endian_to_be(7, 32),
            BpfInsn::ldx_mem(BPF_W, 8, 6, 4),
            endian_to_be(8, 32),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 2);
        // Verify two kfunc calls exist.
        let call_count = prog.insns.iter()
            .filter(|i| i.is_call() && i.src_reg() == 2 && i.imm == 8888)
            .count();
        assert_eq!(call_count, 2);
        assert!(prog.insns.last().unwrap().is_exit());
    }

    #[test]
    fn test_endian_fusion_pass_all_three_sizes() {
        // Use callee-saved register (r6) as source to avoid caller-saved
        // register conflicts between consecutive sites.
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_H, 7, 6, 0),
            endian_to_be(7, 16),
            BpfInsn::ldx_mem(BPF_W, 8, 6, 2),
            endian_to_be(8, 32),
            BpfInsn::ldx_mem(BPF_DW, 9, 6, 6),
            endian_to_be(9, 64),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian_kfuncs(1111, 2222, 3333);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 3);

        // Check we got the right BTF IDs for each size.
        let calls: Vec<i32> = prog.insns.iter()
            .filter(|i| i.is_call() && i.src_reg() == 2)
            .map(|i| i.imm)
            .collect();
        assert!(calls.contains(&1111), "should contain 16-bit kfunc btf_id");
        assert!(calls.contains(&2222), "should contain 32-bit kfunc btf_id");
        assert!(calls.contains(&3333), "should contain 64-bit kfunc btf_id");
    }

    #[test]
    fn test_endian_fusion_pass_integration_with_pass_manager() {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(LivenessAnalysis);
        pm.add_pass(EndianFusionPass);

        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
            endian_to_be(2, 32),
            exit_insn(),
        ]);
        let ctx = ctx_with_endian32_kfunc(1234);

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
    }
}
