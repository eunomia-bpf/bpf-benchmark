// SPDX-License-Identifier: MIT
//! ROTATE optimization pass.

use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::utils::{
    emit_packed_kinsn_call_with_off, fixup_all_branches, kinsn_replacement_subprog_skip_reason,
    map_replacement_range, remap_kinsn_btf_metadata, resolve_kinsn_call_off_for_target,
};

/// ROTATE optimization pass: replaces shift+OR rotate patterns with
/// bpf_rotate64()/bpf_rotate32() kfunc calls. JIT inlines each kfunc as a
/// native rotate.
pub struct RotatePass;

impl BpfPass for RotatePass {
    fn name(&self) -> &str {
        "rotate"
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
        // Prerequisite: check if at least one rotate kfunc is available.
        if ctx.kinsn_registry.rotate64_btf_id < 0 && ctx.kinsn_registry.rotate32_btf_id < 0 {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "rotate kfuncs not available".into(),
                },
            ));
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);
        let liveness_analysis = LivenessAnalysis;
        let liveness = analyses.get(&liveness_analysis, program);

        let sites = scan_rotate_sites(&program.insns);
        let mut safe_sites: Vec<SafeRotateSite> = Vec::new();
        let mut skipped = Vec::new();

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

            if let Some(reason) = kinsn_replacement_subprog_skip_reason(
                &program.insns,
                site.start_pc,
                site.old_len,
                2,
            )? {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason,
                });
                continue;
            }

            if ctx
                .kinsn_registry
                .btf_id_for_target_name(site.width.target_name())
                < 0
            {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: format!("{} kfunc not available", site.width.target_name()),
                });
                continue;
            }

            // Safety check 2: tmp_reg live-out check.
            // The original code destroys tmp_reg via the shift. After rewrite,
            // tmp_reg is not written at all. If tmp_reg is live after the site,
            // the rewrite would change semantics.
            let site_end = site.start_pc + site.old_len;
            if site_end > 0 && site_end - 1 < liveness.live_out.len() {
                let live_after = &liveness.live_out[site_end - 1];
                if live_after.contains(&site.tmp_reg) {
                    skipped.push(SkipReason {
                        pc: site.start_pc,
                        reason: format!("tmp_reg r{} is live after site", site.tmp_reg),
                    });
                    continue;
                }

                safe_sites.push(SafeRotateSite { site });
                continue;
            }

            safe_sites.push(SafeRotateSite { site });
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                sites_skipped: skipped,
                ..PassResult::unchanged(self.name())
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

            if site_idx < safe_sites.len() && pc == safe_sites[site_idx].site.start_pc {
                let safe_site = &safe_sites[site_idx];
                let site = &safe_site.site;
                let btf_id = ctx
                    .kinsn_registry
                    .btf_id_for_target_name(site.width.target_name());
                let kfunc_off = resolve_kinsn_call_off_for_target(ctx, site.width.target_name())?;
                // Emit: bpf_rotate{32,64}(val_reg, shift_amount) -> dst_reg
                let payload = (site.dst_reg as u64)
                    | ((site.val_reg as u64) << 4)
                    | ((site.shift_amount as u64) << 8)
                    | ((site.tmp_reg as u64) << 16);
                let replacement = emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off);
                new_insns.extend_from_slice(&replacement);
                map_replacement_range(&mut addr_map, pc, site.old_len, new_pc, replacement.len());

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

pub(super) struct RotateSite {
    pub(super) start_pc: usize,
    pub(super) old_len: usize,
    pub(super) dst_reg: u8,
    pub(super) val_reg: u8,
    pub(super) tmp_reg: u8,
    pub(super) shift_amount: u32,
    pub(super) width: RotateWidth,
}

/// A rotate site that has passed safety checks, ready for transformation.
struct SafeRotateSite {
    site: RotateSite,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(super) enum RotateWidth {
    W32,
    W64,
}

impl RotateWidth {
    fn bits(self) -> u32 {
        match self {
            Self::W32 => 32,
            Self::W64 => 64,
        }
    }

    fn alu_class(self) -> u8 {
        match self {
            Self::W32 => BPF_ALU,
            Self::W64 => BPF_ALU64,
        }
    }

    fn target_name(self) -> &'static str {
        match self {
            Self::W32 => "bpf_rotate32",
            Self::W64 => "bpf_rotate64",
        }
    }
}

pub(super) fn scan_rotate_sites(insns: &[BpfInsn]) -> Vec<RotateSite> {
    let mut sites = Vec::new();
    let n = insns.len();
    let mut pc = 0;

    while pc + 2 < n {
        let i0 = &insns[pc];
        let i1 = &insns[pc + 1];
        let i2 = &insns[pc + 2];

        if let Some(site) = try_match_rotate(insns, i0, i1, i2, pc) {
            let end = site.start_pc + site.old_len;
            sites.push(site);
            pc = end;
        } else {
            pc += 1;
        }
    }

    sites
}

/// The rotate lowering is only sound when the provenance copy is the
/// instruction immediately preceding the shift pair. If arbitrary instructions
/// are allowed between the MOV and the rotate idiom, rewriting the whole
/// window into sidecar+call would silently drop those side effects.
fn find_provenance_mov(
    insns: &[BpfInsn],
    shift_pc: usize,
    tmp: u8,
    dst: u8,
    width: RotateWidth,
) -> Option<usize> {
    if shift_pc == 0 {
        return None;
    }

    let mov_pc = shift_pc - 1;
    let insn = &insns[mov_pc];
    if insn.dst_reg() != tmp || insn.src_reg() != dst {
        return None;
    }

    is_reg_mov_for_width(insn, width).then_some(mov_pc)
}

fn is_reg_mov_for_width(insn: &BpfInsn, width: RotateWidth) -> bool {
    let mov64 = insn.code == (BPF_ALU64 | BPF_MOV | BPF_X);
    let mov32 = insn.code == (BPF_ALU | BPF_MOV | BPF_X);
    mov64 || (width == RotateWidth::W32 && mov32)
}

fn try_match_rotate(
    insns: &[BpfInsn],
    i0: &BpfInsn,
    i1: &BpfInsn,
    i2: &BpfInsn,
    pc: usize,
) -> Option<RotateSite> {
    try_match_split_copy_rotate(insns, pc)
        .or_else(|| try_match_rotate_width(insns, i0, i1, i2, pc, RotateWidth::W64))
        .or_else(|| try_match_rotate_width(insns, i0, i1, i2, pc, RotateWidth::W32))
}

/// Clang often lowers 32-bit hash rotates with two explicit copies:
///
///   MOV tmp, val; RSH tmp, W-k; MOV dst, val; LSH dst, k; OR dst, tmp
///
/// This is the shape seen in Cilium's Jenkins hash paths. The older matcher
/// only saw adjacent `shift; shift; OR` triples and missed this form.
fn try_match_split_copy_rotate(insns: &[BpfInsn], pc: usize) -> Option<RotateSite> {
    try_match_split_copy_rotate_width(insns, pc, RotateWidth::W64)
        .or_else(|| try_match_split_copy_rotate_width(insns, pc, RotateWidth::W32))
}

fn try_match_split_copy_rotate_width(
    insns: &[BpfInsn],
    pc: usize,
    width: RotateWidth,
) -> Option<RotateSite> {
    if pc + 4 >= insns.len() {
        return None;
    }

    let mov0 = &insns[pc];
    let shift0 = &insns[pc + 1];
    let mov1 = &insns[pc + 2];
    let shift1 = &insns[pc + 3];
    let or_insn = &insns[pc + 4];

    if !is_reg_mov_for_width(mov0, width) || !is_reg_mov_for_width(mov1, width) {
        return None;
    }

    let val_reg = mov0.src_reg();
    if mov1.src_reg() != val_reg {
        return None;
    }

    let reg0 = mov0.dst_reg();
    let reg1 = mov1.dst_reg();
    if reg0 == reg1 || shift0.dst_reg() != reg0 || shift1.dst_reg() != reg1 {
        return None;
    }

    let alu_class = width.alu_class();
    let shift0_is_lsh = shift0.code == (alu_class | BPF_LSH | BPF_K);
    let shift0_is_rsh = shift0.code == (alu_class | BPF_RSH | BPF_K);
    let shift1_is_lsh = shift1.code == (alu_class | BPF_LSH | BPF_K);
    let shift1_is_rsh = shift1.code == (alu_class | BPF_RSH | BPF_K);

    let (lsh_amount, rsh_amount) = if shift0_is_lsh && shift1_is_rsh {
        (shift0.imm as u32, shift1.imm as u32)
    } else if shift0_is_rsh && shift1_is_lsh {
        (shift1.imm as u32, shift0.imm as u32)
    } else {
        return None;
    };

    if lsh_amount + rsh_amount != width.bits() {
        return None;
    }

    if or_insn.code != (alu_class | BPF_OR | BPF_X) {
        return None;
    }

    let or_dst = or_insn.dst_reg();
    let or_src = or_insn.src_reg();
    let or_uses_both = (or_dst == reg0 && or_src == reg1) || (or_dst == reg1 && or_src == reg0);
    if !or_uses_both {
        return None;
    }

    rotate_site(pc, 5, or_dst, val_reg, or_src, lsh_amount, width)
}

fn try_match_rotate_width(
    insns: &[BpfInsn],
    i0: &BpfInsn,
    i1: &BpfInsn,
    i2: &BpfInsn,
    pc: usize,
    width: RotateWidth,
) -> Option<RotateSite> {
    let alu_class = width.alu_class();
    let is_or = i2.code == (alu_class | BPF_OR | BPF_X);
    if !is_or {
        return None;
    }

    // Pattern A: RSH_IMM(rA, S_rsh) ; LSH_IMM(rB, S_lsh) ; OR_REG(or_dst, or_src)
    // where S_rsh + S_lsh equals the operation width.
    //
    // The two registers rA, rB hold copies of the same original value.
    // One was copied from the other via `MOV tmp, orig` before the shifts.
    // Either register could be the original or the copy — we try both.
    let is_rsh = i0.code == (alu_class | BPF_RSH | BPF_K);
    let is_lsh = i1.code == (alu_class | BPF_LSH | BPF_K);

    if is_rsh && is_lsh {
        let rsh_amount = i0.imm as u32;
        let lsh_amount = i1.imm as u32;

        if rsh_amount + lsh_amount == width.bits() {
            let rsh_reg = i0.dst_reg();
            let lsh_reg = i1.dst_reg();
            if rsh_reg != lsh_reg {
                let or_dst = i2.dst_reg();
                let or_src = i2.src_reg();

                // The OR must combine exactly these two registers.
                let or_uses_both = (or_dst == rsh_reg && or_src == lsh_reg)
                    || (or_dst == lsh_reg && or_src == rsh_reg);
                if or_uses_both {
                    let result_reg = or_dst;
                    // Try both provenance directions:
                    // Case 1: rsh_reg is the copy (tmp), lsh_reg is the original (dst)
                    //   => MOV rsh_reg, lsh_reg
                    if let Some(mov_pc) = find_provenance_mov(insns, pc, rsh_reg, lsh_reg, width) {
                        return rotate_site(
                            mov_pc,
                            (pc + 3) - mov_pc,
                            result_reg,
                            lsh_reg,
                            rsh_reg,
                            lsh_amount,
                            width,
                        );
                    }
                    // Case 2: lsh_reg is the copy (tmp), rsh_reg is the original (dst)
                    //   => MOV lsh_reg, rsh_reg
                    if let Some(mov_pc) = find_provenance_mov(insns, pc, lsh_reg, rsh_reg, width) {
                        return rotate_site(
                            mov_pc,
                            (pc + 3) - mov_pc,
                            result_reg,
                            rsh_reg,
                            lsh_reg,
                            lsh_amount,
                            width,
                        );
                    }
                }
            }
        }
    }

    // Pattern B: LSH_IMM(rA, S_lsh) ; RSH_IMM(rB, S_rsh) ; OR_REG(or_dst, or_src)
    let is_lsh_first = i0.code == (alu_class | BPF_LSH | BPF_K);
    let is_rsh_second = i1.code == (alu_class | BPF_RSH | BPF_K);

    if is_lsh_first && is_rsh_second {
        let lsh_amount = i0.imm as u32;
        let rsh_amount = i1.imm as u32;

        if lsh_amount + rsh_amount == width.bits() {
            let lsh_reg = i0.dst_reg();
            let rsh_reg = i1.dst_reg();
            if lsh_reg != rsh_reg {
                let or_dst = i2.dst_reg();
                let or_src = i2.src_reg();

                let or_uses_both = (or_dst == lsh_reg && or_src == rsh_reg)
                    || (or_dst == rsh_reg && or_src == lsh_reg);
                if or_uses_both {
                    let result_reg = or_dst;
                    // Try both provenance directions:
                    if let Some(mov_pc) = find_provenance_mov(insns, pc, rsh_reg, lsh_reg, width) {
                        return rotate_site(
                            mov_pc,
                            (pc + 3) - mov_pc,
                            result_reg,
                            lsh_reg,
                            rsh_reg,
                            lsh_amount,
                            width,
                        );
                    }
                    if let Some(mov_pc) = find_provenance_mov(insns, pc, lsh_reg, rsh_reg, width) {
                        return rotate_site(
                            mov_pc,
                            (pc + 3) - mov_pc,
                            result_reg,
                            rsh_reg,
                            lsh_reg,
                            lsh_amount,
                            width,
                        );
                    }
                }
            }
        }
    }

    None
}

fn rotate_site(
    start_pc: usize,
    old_len: usize,
    dst_reg: u8,
    val_reg: u8,
    tmp_reg: u8,
    shift_amount: u32,
    width: RotateWidth,
) -> Option<RotateSite> {
    // The packed rotate kinsn uses tmp_reg as verifier proof scratch. It cannot
    // encode sites where the scratch is also the result or source register.
    (dst_reg != tmp_reg && val_reg != tmp_reg).then_some(RotateSite {
        start_pc,
        old_len,
        dst_reg,
        val_reg,
        tmp_reg,
        shift_amount,
        width,
    })
}
