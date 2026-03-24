// SPDX-License-Identifier: MIT
//! WIDE_MEM optimization pass.
//!
//! Self-contained: pattern matching (was matcher.rs), emission (was emit.rs),
//! and the BpfPass implementation are all here.

use anyhow::bail;

use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::fixup_branches_inline;

// ═══════════════════════════════════════════════════════════════════
// Pattern matching (absorbed from matcher.rs)
// ═══════════════════════════════════════════════════════════════════

/// Identifies which transform family a matched site belongs to.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Family {
    WideMem,
}

impl std::fmt::Display for Family {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Family::WideMem => write!(f, "wide_mem"),
        }
    }
}

/// A named binding captured from a matched pattern.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Binding {
    pub name: &'static str,
    pub value: i64,
}

/// A single rewrite site found by the daemon.
#[derive(Clone, Debug)]

pub struct RewriteSite {
    /// Index of the first instruction in the matched pattern.
    pub start_pc: usize,
    /// Number of original instructions consumed by this pattern.
    pub old_len: usize,
    /// Which transform family.
    pub family: Family,
    /// Captured bindings (register numbers, offsets, widths, etc.).
    pub bindings: Vec<Binding>,
}

impl RewriteSite {
    /// Get a binding value by name, or None.
    pub fn get_binding(&self, name: &str) -> Option<i64> {
        self.bindings
            .iter()
            .find(|b| b.name == name)
            .map(|b| b.value)
    }
}

/// Scan for WIDE_MEM (byte-ladder) patterns.
///
/// Supports two orderings that clang may produce:
///
/// **Variant A -- low-byte-first (canonical LE):**
///   Total: 1 + 3*(W-1) insns.
///
/// **Variant B -- high-byte-first (clang reorder):**
///   Total: 3*W - 2 insns (for W>=2).
pub fn scan_wide_mem(insns: &[BpfInsn]) -> Vec<RewriteSite> {
    let mut sites = Vec::new();
    let n = insns.len();
    if n < 4 {
        return sites;
    }

    let mut pc = 0;
    while pc < n {
        if let Some(site) = try_match_wide_mem_at(insns, pc) {
            let site_len = site.old_len;
            sites.push(site);
            pc += site_len;
        } else {
            pc += 1;
        }
    }

    sites
}

fn try_match_wide_mem_at(insns: &[BpfInsn], pc: usize) -> Option<RewriteSite> {
    let n = insns.len();

    let first = &insns[pc];
    if !first.is_ldx_mem() || bpf_size(first.code) != BPF_B {
        return None;
    }

    let dst = first.dst_reg();
    let base = first.src_reg();
    let first_off = first.off as i64;

    for width in (2u32..=8).rev() {
        // Variant A: low-byte-first
        let len_a = 1 + 3 * (width as usize - 1);
        if pc + len_a <= n
            && match_wide_mem_low_first(insns, pc, dst, base, first_off, width)
        {
            return Some(RewriteSite {
                start_pc: pc,
                old_len: len_a,
                family: Family::WideMem,
                bindings: vec![
                    Binding {
                        name: "dst_reg",
                        value: dst as i64,
                    },
                    Binding {
                        name: "base_reg",
                        value: base as i64,
                    },
                    Binding {
                        name: "base_off",
                        value: first_off,
                    },
                    Binding {
                        name: "width",
                        value: width as i64,
                    },
                ],
            });
        }

        // Variant B: high-byte-first
        let len_b = 3 * width as usize - 2;
        if pc + len_b <= n {
            if let Some(base_off) =
                match_wide_mem_high_first(insns, pc, dst, base, first_off, width)
            {
                return Some(RewriteSite {
                    start_pc: pc,
                    old_len: len_b,
                    family: Family::WideMem,
                    bindings: vec![
                        Binding {
                            name: "dst_reg",
                            value: dst as i64,
                        },
                        Binding {
                            name: "base_reg",
                            value: base as i64,
                        },
                        Binding {
                            name: "base_off",
                            value: base_off,
                        },
                        Binding {
                            name: "width",
                            value: width as i64,
                        },
                    ],
                });
            }
        }
    }

    None
}

fn match_wide_mem_low_first(
    insns: &[BpfInsn],
    pc: usize,
    dst: u8,
    base: u8,
    base_off: i64,
    width: u32,
) -> bool {
    for i in 1..width {
        let idx = pc + 3 * (i as usize - 1) + 1;

        let load = &insns[idx];
        let shift = &insns[idx + 1];
        let or = &insns[idx + 2];

        if !load.is_ldx_mem() || bpf_size(load.code) != BPF_B {
            return false;
        }
        if load.src_reg() != base {
            return false;
        }
        if load.off as i64 != base_off + i as i64 {
            return false;
        }
        let tmp = load.dst_reg();
        if tmp == dst {
            return false;
        }

        if shift.code != (BPF_ALU64 | BPF_LSH | BPF_K) {
            return false;
        }
        if shift.dst_reg() != tmp {
            return false;
        }
        if shift.imm != (8 * i) as i32 {
            return false;
        }

        if or.code != (BPF_ALU64 | BPF_OR | BPF_X) {
            return false;
        }
        if or.dst_reg() != dst || or.src_reg() != tmp {
            return false;
        }
    }

    true
}

fn match_wide_mem_high_first(
    insns: &[BpfInsn],
    pc: usize,
    dst: u8,
    base: u8,
    first_off: i64,
    width: u32,
) -> Option<i64> {
    let shift0 = &insns[pc + 1];
    if shift0.code != (BPF_ALU64 | BPF_LSH | BPF_K) {
        return None;
    }
    if shift0.dst_reg() != dst {
        return None;
    }
    if shift0.imm != 8 {
        return None;
    }

    let load0 = &insns[pc + 2];
    if !load0.is_ldx_mem() || bpf_size(load0.code) != BPF_B {
        return None;
    }
    if load0.src_reg() != base {
        return None;
    }
    let base_off = load0.off as i64;
    if first_off != base_off + 1 {
        return None;
    }
    let tmp0 = load0.dst_reg();
    if tmp0 == dst {
        return None;
    }

    let or0 = &insns[pc + 3];
    if or0.code != (BPF_ALU64 | BPF_OR | BPF_X) {
        return None;
    }
    if or0.dst_reg() != dst || or0.src_reg() != tmp0 {
        return None;
    }

    for i in 2..width {
        let idx = pc + 3 * i as usize - 2;

        let load = &insns[idx];
        let shift = &insns[idx + 1];
        let or = &insns[idx + 2];

        if !load.is_ldx_mem() || bpf_size(load.code) != BPF_B {
            return None;
        }
        if load.src_reg() != base {
            return None;
        }
        if load.off as i64 != base_off + i as i64 {
            return None;
        }
        let tmp = load.dst_reg();
        if tmp == dst {
            return None;
        }

        if shift.code != (BPF_ALU64 | BPF_LSH | BPF_K) {
            return None;
        }
        if shift.dst_reg() != tmp {
            return None;
        }
        if shift.imm != (8 * i) as i32 {
            return None;
        }

        if or.code != (BPF_ALU64 | BPF_OR | BPF_X) {
            return None;
        }
        if or.dst_reg() != dst || or.src_reg() != tmp {
            return None;
        }
    }

    Some(base_off)
}

// ═══════════════════════════════════════════════════════════════════
// Emission (absorbed from emit.rs)
// ═══════════════════════════════════════════════════════════════════

/// Emit replacement instructions for a single WIDE_MEM rewrite site.
fn emit_wide_mem(site: &RewriteSite) -> anyhow::Result<Vec<BpfInsn>> {
    let dst = site
        .get_binding("dst_reg")
        .ok_or_else(|| anyhow::anyhow!("missing dst_reg binding"))? as u8;
    let base = site
        .get_binding("base_reg")
        .ok_or_else(|| anyhow::anyhow!("missing base_reg binding"))? as u8;
    let off = site
        .get_binding("base_off")
        .ok_or_else(|| anyhow::anyhow!("missing base_off binding"))? as i16;
    let width = site
        .get_binding("width")
        .ok_or_else(|| anyhow::anyhow!("missing width binding"))?;

    let size = match width {
        2 => BPF_H,
        4 => BPF_W,
        8 => BPF_DW,
        _ => bail!("WIDE_MEM: unsupported width {} (supports 2, 4, 8)", width),
    };

    Ok(vec![BpfInsn::ldx_mem(size, dst, base, off)])
}

// ═══════════════════════════════════════════════════════════════════
// BpfPass implementation
// ═══════════════════════════════════════════════════════════════════

/// WIDE_MEM optimization pass: merges byte-load + shift + OR sequences
/// into a single wide load instruction.
///
/// This is the most important BpfReJIT optimization, accounting for ~50.7%
/// of the kernel JIT surplus. No kinsn support needed -- pure BPF replacement.
pub struct WideMemPass;

impl BpfPass for WideMemPass {
    fn name(&self) -> &str {
        "wide_mem"
    }


    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets", "liveness"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);

        let liveness_analysis = LivenessAnalysis;
        let liveness = analyses.get(&liveness_analysis, program);

        // Scan for wide_mem sites.
        let raw_sites = scan_wide_mem(&program.insns);

        // Filter: skip sites with interior branch targets or live scratch regs.
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
                continue;
            }

            let dst_reg = site.get_binding("dst_reg").unwrap_or(-1) as u8;
            let mut scratch_regs = std::collections::HashSet::new();
            let site_end = site.start_pc + site.old_len;
            for pc in site.start_pc..site_end {
                if pc < program.insns.len() {
                    let insn = &program.insns[pc];
                    let class = insn.class();
                    if class == BPF_ALU64 || class == BPF_ALU || class == BPF_LDX {
                        let dreg = insn.dst_reg();
                        if dreg != dst_reg {
                            scratch_regs.insert(dreg);
                        }
                    }
                }
            }

            let last_insn_pc = if site_end > 0 { site_end - 1 } else { 0 };
            let has_live_scratch = if last_insn_pc < liveness.live_out.len() {
                scratch_regs
                    .iter()
                    .any(|r| liveness.live_out[last_insn_pc].contains(r))
            } else {
                false
            };

            if has_live_scratch {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "scratch register live after site".into(),
                });
                continue;
            }

            // Skip unsupported widths (only 2, 4, 8 can be emitted as a single wide load).
            let width = site.get_binding("width").unwrap_or(0);
            if width != 2 && width != 4 && width != 8 {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: format!("unsupported width {} (supports 2, 4, 8)", width),
                });
                continue;
            }

            safe_sites.push(site.clone());
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics: vec![],
                ..Default::default()
            });
        }

        // Apply rewrite: build new instruction stream with address map.
        let orig_insns = &program.insns;
        let orig_len = orig_insns.len();
        let mut new_insns: Vec<BpfInsn> = Vec::with_capacity(orig_len);
        let mut addr_map: Vec<usize> = vec![0; orig_len + 1];
        let mut applied = 0usize;

        let mut old_pc = 0usize;
        let mut site_idx = 0usize;

        while old_pc < orig_len {
            let new_pc = new_insns.len();

            if site_idx < safe_sites.len() && old_pc == safe_sites[site_idx].start_pc {
                let site = &safe_sites[site_idx];
                let replacement = emit_wide_mem(site)?;

                for j in 0..site.old_len {
                    addr_map[old_pc + j] = new_pc;
                }

                new_insns.extend_from_slice(&replacement);

                old_pc += site.old_len;
                site_idx += 1;
                applied += 1;
            } else {
                addr_map[old_pc] = new_pc;
                new_insns.push(orig_insns[old_pc]);

                if orig_insns[old_pc].is_ldimm64() && old_pc + 1 < orig_len {
                    old_pc += 1;
                    addr_map[old_pc] = new_insns.len();
                    new_insns.push(orig_insns[old_pc]);
                }

                old_pc += 1;
            }
        }

        addr_map[orig_len] = new_insns.len();

        // Fix up branch offsets.
        fixup_branches_inline(&mut new_insns, orig_insns, &addr_map);

        program.insns = new_insns;
        program.remap_annotations(&addr_map);
        program.log_transform(TransformEntry { sites_applied: applied });

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

// ═══════════════════════════════════════════════════════════════════
// Tests
// ═══════════════════════════════════════════════════════════════════

#[cfg(test)]
mod tests {
    use super::*;
    use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
    use crate::pass::{AnalysisCache, PassContext, PassManager};

    fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
        BpfProgram::new(insns)
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
            BpfInsn::ldx_mem(BPF_B, 2, 1, 0),
            BpfInsn::ldx_mem(BPF_B, 3, 1, 1),
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            BpfInsn::ldx_mem(BPF_B, 3, 1, 2),
            BpfInsn::alu64_imm(BPF_LSH, 3, 16),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            BpfInsn::ldx_mem(BPF_B, 3, 1, 3),
            BpfInsn::alu64_imm(BPF_LSH, 3, 24),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            exit_insn(),
        ]
    }

    // ── Pattern matching tests (from matcher.rs) ──────────────────

    fn build_wide_mem_4(dst: u8, base: u8, off: i16) -> Vec<BpfInsn> {
        vec![
            BpfInsn::ldx_mem(BPF_B, dst, base, off),
            BpfInsn::ldx_mem(BPF_B, 2, base, off + 1),
            BpfInsn::alu64_imm(BPF_LSH, 2, 8),
            BpfInsn::alu64_reg(BPF_OR, dst, 2),
            BpfInsn::ldx_mem(BPF_B, 3, base, off + 2),
            BpfInsn::alu64_imm(BPF_LSH, 3, 16),
            BpfInsn::alu64_reg(BPF_OR, dst, 3),
            BpfInsn::ldx_mem(BPF_B, 4, base, off + 3),
            BpfInsn::alu64_imm(BPF_LSH, 4, 24),
            BpfInsn::alu64_reg(BPF_OR, dst, 4),
        ]
    }

    #[test]
    fn test_scan_wide_mem_4byte() {
        let insns = build_wide_mem_4(0, 6, 10);
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        let s = &sites[0];
        assert_eq!(s.start_pc, 0);
        assert_eq!(s.old_len, 10);
        assert_eq!(s.family, Family::WideMem);
        assert_eq!(s.get_binding("dst_reg"), Some(0));
        assert_eq!(s.get_binding("base_reg"), Some(6));
        assert_eq!(s.get_binding("base_off"), Some(10));
        assert_eq!(s.get_binding("width"), Some(4));
    }

    #[test]
    fn test_scan_wide_mem_2byte() {
        let insns = vec![
            BpfInsn::ldx_mem(BPF_B, 1, 6, 0),
            BpfInsn::ldx_mem(BPF_B, 2, 6, 1),
            BpfInsn::alu64_imm(BPF_LSH, 2, 8),
            BpfInsn::alu64_reg(BPF_OR, 1, 2),
        ];
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].old_len, 4);
        assert_eq!(sites[0].get_binding("width"), Some(2));
    }

    #[test]
    fn test_scan_wide_mem_no_match() {
        let insns = vec![
            BpfInsn::ldx_mem(BPF_B, 0, 6, 10),
            BpfInsn::ldx_mem(BPF_B, 2, 6, 20),
            BpfInsn::alu64_imm(BPF_LSH, 2, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 2),
        ];
        let sites = scan_wide_mem(&insns);
        assert!(sites.is_empty());
    }

    #[test]
    fn test_scan_wide_mem_embedded_in_program() {
        let mut insns = vec![BpfInsn::mov64_imm(0, 0)];
        insns.extend(build_wide_mem_4(0, 6, 10));
        insns.push(BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        });
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].start_pc, 1);
        assert_eq!(sites[0].old_len, 10);
    }

    #[test]
    fn test_scan_wide_mem_multiple_sites() {
        let mut insns = Vec::new();
        insns.push(BpfInsn::ldx_mem(BPF_B, 0, 6, 0));
        insns.push(BpfInsn::ldx_mem(BPF_B, 1, 6, 1));
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 1, 8));
        insns.push(BpfInsn::alu64_reg(BPF_OR, 0, 1));
        insns.push(BpfInsn::ldx_mem(BPF_B, 3, 7, 4));
        insns.push(BpfInsn::ldx_mem(BPF_B, 4, 7, 5));
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 4, 8));
        insns.push(BpfInsn::alu64_reg(BPF_OR, 3, 4));
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 2);
        assert_eq!(sites[0].start_pc, 0);
        assert_eq!(sites[0].get_binding("dst_reg"), Some(0));
        assert_eq!(sites[1].start_pc, 4);
        assert_eq!(sites[1].get_binding("dst_reg"), Some(3));
    }

    #[test]
    fn test_scan_wide_mem_prefers_largest_width() {
        let insns = build_wide_mem_4(0, 6, 0);
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].get_binding("width"), Some(4));
    }

    // ── High-byte-first (Variant B) tests ──────────────────────────

    fn build_wide_mem_high_first_2(dst: u8, tmp: u8, base: u8, off: i16) -> Vec<BpfInsn> {
        vec![
            BpfInsn::ldx_mem(BPF_B, dst, base, off + 1),
            BpfInsn::alu64_imm(BPF_LSH, dst, 8),
            BpfInsn::ldx_mem(BPF_B, tmp, base, off),
            BpfInsn::alu64_reg(BPF_OR, dst, tmp),
        ]
    }

    fn build_wide_mem_high_first_4(dst: u8, tmp: u8, base: u8, off: i16) -> Vec<BpfInsn> {
        vec![
            BpfInsn::ldx_mem(BPF_B, dst, base, off + 1),
            BpfInsn::alu64_imm(BPF_LSH, dst, 8),
            BpfInsn::ldx_mem(BPF_B, tmp, base, off),
            BpfInsn::alu64_reg(BPF_OR, dst, tmp),
            BpfInsn::ldx_mem(BPF_B, tmp, base, off + 2),
            BpfInsn::alu64_imm(BPF_LSH, tmp, 16),
            BpfInsn::alu64_reg(BPF_OR, dst, tmp),
            BpfInsn::ldx_mem(BPF_B, tmp, base, off + 3),
            BpfInsn::alu64_imm(BPF_LSH, tmp, 24),
            BpfInsn::alu64_reg(BPF_OR, dst, tmp),
        ]
    }

    #[test]
    fn test_scan_high_first_2byte() {
        let insns = build_wide_mem_high_first_2(1, 2, 6, 10);
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        let s = &sites[0];
        assert_eq!(s.start_pc, 0);
        assert_eq!(s.old_len, 4);
        assert_eq!(s.family, Family::WideMem);
        assert_eq!(s.get_binding("dst_reg"), Some(1));
        assert_eq!(s.get_binding("base_reg"), Some(6));
        assert_eq!(s.get_binding("base_off"), Some(10));
        assert_eq!(s.get_binding("width"), Some(2));
    }

    #[test]
    fn test_scan_high_first_4byte() {
        let insns = build_wide_mem_high_first_4(2, 3, 1, 8);
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        let s = &sites[0];
        assert_eq!(s.start_pc, 0);
        assert_eq!(s.old_len, 10);
        assert_eq!(s.family, Family::WideMem);
        assert_eq!(s.get_binding("dst_reg"), Some(2));
        assert_eq!(s.get_binding("base_reg"), Some(1));
        assert_eq!(s.get_binding("base_off"), Some(8));
        assert_eq!(s.get_binding("width"), Some(4));
    }

    #[test]
    fn test_scan_high_first_matches_clang_output() {
        let insns = vec![
            BpfInsn::ldx_mem(BPF_B, 2, 1, 9),
            BpfInsn::alu64_imm(BPF_LSH, 2, 8),
            BpfInsn::ldx_mem(BPF_B, 3, 1, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            BpfInsn::ldx_mem(BPF_B, 3, 1, 10),
            BpfInsn::alu64_imm(BPF_LSH, 3, 16),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            BpfInsn::ldx_mem(BPF_B, 3, 1, 11),
            BpfInsn::alu64_imm(BPF_LSH, 3, 24),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        let s = &sites[0];
        assert_eq!(s.start_pc, 0);
        assert_eq!(s.old_len, 10);
        assert_eq!(s.get_binding("dst_reg"), Some(2));
        assert_eq!(s.get_binding("base_reg"), Some(1));
        assert_eq!(s.get_binding("base_off"), Some(8));
        assert_eq!(s.get_binding("width"), Some(4));
    }

    #[test]
    fn test_scan_high_first_embedded() {
        let mut insns = vec![BpfInsn::mov64_imm(0, 0)];
        insns.extend(build_wide_mem_high_first_4(2, 3, 1, 8));
        insns.push(BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        });
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].start_pc, 1);
        assert_eq!(sites[0].old_len, 10);
        assert_eq!(sites[0].get_binding("base_off"), Some(8));
    }

    #[test]
    fn test_scan_high_first_no_false_positive() {
        let insns = vec![
            BpfInsn::ldx_mem(BPF_B, 2, 1, 9),
            BpfInsn::alu64_imm(BPF_LSH, 2, 8),
            BpfInsn::ldx_mem(BPF_B, 3, 1, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            BpfInsn::ldx_mem(BPF_B, 3, 1, 10),
            BpfInsn::alu64_imm(BPF_LSH, 3, 24),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].old_len, 4);
        assert_eq!(sites[0].get_binding("width"), Some(2));
    }

    #[test]
    fn test_scan_high_first_prefers_largest() {
        let insns = build_wide_mem_high_first_4(2, 3, 1, 0);
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].get_binding("width"), Some(4));
    }

    // ── Emission tests (from emit.rs) ──────────────────────────────

    #[test]
    fn test_emit_wide_mem_4() {
        let site = RewriteSite {
            start_pc: 5,
            old_len: 10,
            family: Family::WideMem,
            bindings: vec![
                Binding {
                    name: "dst_reg",
                    value: 0,
                },
                Binding {
                    name: "base_reg",
                    value: 6,
                },
                Binding {
                    name: "base_off",
                    value: 10,
                },
                Binding {
                    name: "width",
                    value: 4,
                },
            ],
        };
        let result = emit_wide_mem(&site).unwrap();
        assert_eq!(result.len(), 1);
        assert_eq!(result[0].code, BPF_LDX | BPF_W | BPF_MEM);
        assert_eq!(result[0].dst_reg(), 0);
        assert_eq!(result[0].src_reg(), 6);
        assert_eq!(result[0].off, 10);
    }

    #[test]
    fn test_emit_wide_mem_2() {
        let site = RewriteSite {
            start_pc: 0,
            old_len: 4,
            family: Family::WideMem,
            bindings: vec![
                Binding {
                    name: "dst_reg",
                    value: 1,
                },
                Binding {
                    name: "base_reg",
                    value: 7,
                },
                Binding {
                    name: "base_off",
                    value: 0,
                },
                Binding {
                    name: "width",
                    value: 2,
                },
            ],
        };
        let result = emit_wide_mem(&site).unwrap();
        assert_eq!(result.len(), 1);
        assert_eq!(result[0].code, BPF_LDX | BPF_H | BPF_MEM);
        assert_eq!(result[0].dst_reg(), 1);
        assert_eq!(result[0].src_reg(), 7);
        assert_eq!(result[0].off, 0);
    }

    #[test]
    fn test_emit_wide_mem_8() {
        let site = RewriteSite {
            start_pc: 0,
            old_len: 22,
            family: Family::WideMem,
            bindings: vec![
                Binding {
                    name: "dst_reg",
                    value: 3,
                },
                Binding {
                    name: "base_reg",
                    value: 10,
                },
                Binding {
                    name: "base_off",
                    value: -8,
                },
                Binding {
                    name: "width",
                    value: 8,
                },
            ],
        };
        let result = emit_wide_mem(&site).unwrap();
        assert_eq!(result.len(), 1);
        assert_eq!(result[0].code, BPF_LDX | BPF_DW | BPF_MEM);
        assert_eq!(result[0].dst_reg(), 3);
        assert_eq!(result[0].src_reg(), 10);
        assert_eq!(result[0].off, -8);
    }

    #[test]
    fn test_emit_wide_mem_unsupported_width() {
        let site = RewriteSite {
            start_pc: 0,
            old_len: 7,
            family: Family::WideMem,
            bindings: vec![
                Binding {
                    name: "dst_reg",
                    value: 0,
                },
                Binding {
                    name: "base_reg",
                    value: 6,
                },
                Binding {
                    name: "base_off",
                    value: 0,
                },
                Binding {
                    name: "width",
                    value: 3,
                },
            ],
        };
        assert!(emit_wide_mem(&site).is_err());
    }

    // ── Pass tests ─────────────────────────────────────────────────

    #[test]
    fn test_wide_mem_pass_finds_sites() {
        let mut prog = make_program(make_wide_mem_4byte_program());
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert_eq!(prog.insns.len(), 2);
        assert!(prog.insns[0].is_ldx_mem());
        assert_eq!(bpf_size(prog.insns[0].code), BPF_W);
    }

    #[test]
    fn test_wide_mem_pass_no_sites() {
        let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
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
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_B, 0, 6, 10),
            BpfInsn::ldx_mem(BPF_B, 1, 6, 11),
            BpfInsn::alu64_imm(BPF_LSH, 1, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert_eq!(prog.insns.len(), 2);
        assert_eq!(bpf_size(prog.insns[0].code), BPF_H);
        assert_eq!(prog.insns[0].dst_reg(), 0);
        assert_eq!(prog.insns[0].src_reg(), 6);
        assert_eq!(prog.insns[0].off, 10);
    }

    #[test]
    fn test_wide_mem_pass_preserves_branch_offsets() {
        let mut insns = vec![BpfInsn::ja(10)];
        insns.push(BpfInsn::ldx_mem(BPF_B, 0, 6, 0));
        insns.push(BpfInsn::ldx_mem(BPF_B, 2, 6, 1));
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 2, 8));
        insns.push(BpfInsn::alu64_reg(BPF_OR, 0, 2));
        insns.push(BpfInsn::ldx_mem(BPF_B, 3, 6, 2));
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 3, 16));
        insns.push(BpfInsn::alu64_reg(BPF_OR, 0, 3));
        insns.push(BpfInsn::ldx_mem(BPF_B, 4, 6, 3));
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 4, 24));
        insns.push(BpfInsn::alu64_reg(BPF_OR, 0, 4));
        insns.push(exit_insn());

        let mut prog = make_program(insns);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(prog.insns.len(), 3);

        let ja = &prog.insns[0];
        assert!(ja.is_ja());
        assert_eq!(ja.off, 1, "ja should jump to exit at pc 2");
    }

    #[test]
    fn test_wide_mem_pass_skips_site_with_interior_branch_target() {
        let mut prog = make_program(vec![
            jeq_imm(5, 0, 2),
            BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
            BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
            BpfInsn::alu64_imm(BPF_LSH, 1, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(!result.sites_skipped.is_empty());
        assert!(result.sites_skipped[0]
            .reason
            .contains("interior branch target"));
    }

    #[test]
    fn test_wide_mem_pass_multiple_sites() {
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
            BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
            BpfInsn::alu64_imm(BPF_LSH, 1, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 1),
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
        assert_eq!(prog.insns.len(), 3);
    }

    #[test]
    fn test_wide_mem_pass_skips_site_with_live_scratch_reg() {
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
            BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
            BpfInsn::alu64_imm(BPF_LSH, 1, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 1),
            BpfInsn::mov64_reg(2, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(!result.sites_skipped.is_empty());
        assert!(result.sites_skipped[0]
            .reason
            .contains("scratch register live"),);
        assert_eq!(prog.insns.len(), 6);
    }

    #[test]
    fn test_wide_mem_pass_applies_when_scratch_dead() {
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
            BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
            BpfInsn::alu64_imm(BPF_LSH, 1, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert_eq!(prog.insns.len(), 2);
    }

    #[test]
    fn test_wide_mem_pass_integration_with_pass_manager() {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(LivenessAnalysis);
        pm.add_pass(WideMemPass);

        let mut prog = make_program(make_wide_mem_4byte_program());
        let ctx = PassContext::test_default();

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(prog.insns.len(), 2);
    }

    // ── Branch fixup tests (from rewriter.rs) ──────────────────────

    fn wide_mem_4_insns(dst: u8, base: u8, off: i16) -> Vec<BpfInsn> {
        build_wide_mem_4(dst, base, off)
    }

    #[test]
    fn test_branch_fixup_forward_across_site() {
        let mut insns = Vec::new();
        insns.push(BpfInsn::ja(10));
        insns.extend(wide_mem_4_insns(0, 6, 0));
        insns.push(exit_insn());

        let mut prog = make_program(insns);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(prog.insns.len(), 3);
        let ja = &prog.insns[0];
        assert!(ja.is_ja());
        assert_eq!(ja.off, 1, "ja should jump to exit at pc 2");
    }

    #[test]
    fn test_branch_fixup_backward_across_site() {
        let mut insns = Vec::new();
        insns.push(BpfInsn::mov64_imm(0, 0));
        insns.extend(wide_mem_4_insns(0, 6, 0));
        insns.push(BpfInsn::ja(-12));
        insns.push(exit_insn());

        let mut prog = make_program(insns);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(prog.insns.len(), 4);
        let ja = &prog.insns[2];
        assert!(ja.is_ja());
        assert_eq!(ja.off, -3, "ja should jump back to pc 0");
    }

    #[test]
    fn test_conditional_branch_fixup() {
        let mut insns = Vec::new();
        insns.push(BpfInsn {
            code: BPF_JMP | BPF_JEQ | BPF_K,
            regs: BpfInsn::make_regs(1, 0),
            off: 10,
            imm: 0,
        });
        insns.extend(wide_mem_4_insns(0, 6, 0));
        insns.push(exit_insn());

        let mut prog = make_program(insns);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(prog.insns.len(), 3);
        let jeq = &prog.insns[0];
        assert!(jeq.is_cond_jmp());
        assert_eq!(jeq.off, 1, "jeq should jump to exit at pc=2");
    }

    #[test]
    fn test_wide_mem_pass_skips_unsupported_width_3() {
        // Build a 3-byte low-first byte-ladder: LDX(B, dst, base, 0) + 2 more bytes.
        // Width 3 is detected by the daemon but cannot be emitted as a single load.
        let insns = vec![
            BpfInsn::ldx_mem(BPF_B, 0, 6, 0), // byte 0
            BpfInsn::ldx_mem(BPF_B, 1, 6, 1), // byte 1
            BpfInsn::alu64_imm(BPF_LSH, 1, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 1),
            BpfInsn::ldx_mem(BPF_B, 1, 6, 2), // byte 2
            BpfInsn::alu64_imm(BPF_LSH, 1, 16),
            BpfInsn::alu64_reg(BPF_OR, 0, 1),
            exit_insn(),
        ];

        // Verify the daemon finds a width=3 site.
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].get_binding("width"), Some(3));

        // The pass should skip this site (unsupported width) without error.
        let mut prog = make_program(insns);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(!result.changed, "width=3 should be skipped, not applied");
        assert_eq!(result.sites_applied, 0);
        assert!(result
            .sites_skipped
            .iter()
            .any(|s| s.reason.contains("unsupported width")));
    }

    #[test]
    fn test_wide_mem_pass_applies_width4_skips_width3_mixed() {
        // Program with both a width=4 site (supported) and a width=3 site (unsupported).
        // The pass should apply the width=4 site and skip the width=3 site.
        let mut insns = Vec::new();
        // Width=4 low-first: dst=0, base=6, off=0
        insns.push(BpfInsn::ldx_mem(BPF_B, 0, 6, 0));
        insns.push(BpfInsn::ldx_mem(BPF_B, 1, 6, 1));
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 1, 8));
        insns.push(BpfInsn::alu64_reg(BPF_OR, 0, 1));
        insns.push(BpfInsn::ldx_mem(BPF_B, 1, 6, 2));
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 1, 16));
        insns.push(BpfInsn::alu64_reg(BPF_OR, 0, 1));
        insns.push(BpfInsn::ldx_mem(BPF_B, 1, 6, 3));
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 1, 24));
        insns.push(BpfInsn::alu64_reg(BPF_OR, 0, 1));
        // Width=3 low-first: dst=2, base=7, off=0
        insns.push(BpfInsn::ldx_mem(BPF_B, 2, 7, 0));
        insns.push(BpfInsn::ldx_mem(BPF_B, 3, 7, 1));
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 3, 8));
        insns.push(BpfInsn::alu64_reg(BPF_OR, 2, 3));
        insns.push(BpfInsn::ldx_mem(BPF_B, 3, 7, 2));
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 3, 16));
        insns.push(BpfInsn::alu64_reg(BPF_OR, 2, 3));
        insns.push(exit_insn());

        let mut prog = make_program(insns);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = WideMemPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed, "width=4 site should be applied");
        assert_eq!(result.sites_applied, 1);
        // The width=3 site should be in sites_skipped.
        assert!(result
            .sites_skipped
            .iter()
            .any(|s| s.reason.contains("unsupported width 3")));
    }

    // ── MEDIUM #5: Real bytecode pattern test for wide_mem ──────────

    /// MEDIUM #5: Test wide_mem pattern scanning against real compiled BPF bytecode
    /// from load_byte_recompose.bpf.o. Verifies that scan_wide_mem finds patterns
    /// in real clang output, not just hand-constructed sequences.
    #[test]
    fn test_scan_wide_mem_real_bytecode() {
        let path = crate::insn::micro_program_path("load_byte_recompose.bpf.o");
        let insns = match crate::insn::load_bpf_insns_from_elf(&path) {
            Some(i) if !i.is_empty() => i,
            _ => {
                eprintln!("SKIP: load_byte_recompose.bpf.o not found (run `make micro` first)");
                return;
            }
        };

        let sites = scan_wide_mem(&insns);
        assert!(
            !sites.is_empty(),
            "load_byte_recompose.bpf.o should contain wide_mem patterns, found 0 sites in {} insns",
            insns.len()
        );

        // Verify each site has sensible properties
        for site in &sites {
            assert!(
                site.start_pc < insns.len(),
                "wide_mem site start_pc {} out of range (insns.len()={})",
                site.start_pc,
                insns.len()
            );
            assert!(
                site.old_len >= 2,
                "wide_mem site old_len should be >= 2, got {}",
                site.old_len
            );
            // Width should be available in bindings
            if let Some(width) = site.get_binding("width") {
                assert!(
                    width >= 2 && width <= 8,
                    "wide_mem site width should be 2-8, got {}",
                    width
                );
            }
        }

        eprintln!(
            "  load_byte_recompose.bpf.o: found {} wide_mem sites in {} insns",
            sites.len(),
            insns.len()
        );
    }
}
