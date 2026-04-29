// SPDX-License-Identifier: MIT
//! WIDE_MEM optimization pass.
//!
//! Self-contained: pattern matching (was matcher.rs), emission (was emit.rs),
//! and the BpfPass implementation are all here.

use anyhow::bail;

use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::utils::fixup_all_branches;

// ═══════════════════════════════════════════════════════════════════
// Pattern matching (absorbed from matcher.rs)
// ═══════════════════════════════════════════════════════════════════

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
        if pc + len_a <= n && match_wide_mem_low_first(insns, pc, dst, base, first_off, width) {
            return Some(RewriteSite {
                start_pc: pc,
                old_len: len_a,
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

// ── Packet-pointer safety constants ─────────────────────────────────

/// BPF_PROG_TYPE_SCHED_CLS (TC classifier).
const BPF_PROG_TYPE_SCHED_CLS: u32 = kernel_sys::BPF_PROG_TYPE_SCHED_CLS as u32;
/// BPF_PROG_TYPE_SCHED_ACT (TC action).
const BPF_PROG_TYPE_SCHED_ACT: u32 = kernel_sys::BPF_PROG_TYPE_SCHED_ACT as u32;
/// BPF_PROG_TYPE_XDP.
const BPF_PROG_TYPE_XDP: u32 = kernel_sys::BPF_PROG_TYPE_XDP as u32;
/// BPF_PROG_TYPE_LWT_IN.
const BPF_PROG_TYPE_LWT_IN: u32 = kernel_sys::BPF_PROG_TYPE_LWT_IN as u32;
/// BPF_PROG_TYPE_LWT_OUT.
const BPF_PROG_TYPE_LWT_OUT: u32 = kernel_sys::BPF_PROG_TYPE_LWT_OUT as u32;
/// BPF_PROG_TYPE_LWT_XMIT.
const BPF_PROG_TYPE_LWT_XMIT: u32 = kernel_sys::BPF_PROG_TYPE_LWT_XMIT as u32;
/// BPF_PROG_TYPE_SK_SKB.
const BPF_PROG_TYPE_SK_SKB: u32 = kernel_sys::BPF_PROG_TYPE_SK_SKB as u32;

/// Returns `true` if the given BPF program type may expose packet pointers
/// whose wide-load safety cannot be statically guaranteed.
///
/// These program types receive a context containing `data`/`data_end` packet
/// pointers. The BPF verifier applies special range and alignment tracking to
/// packet pointer dereferences that may reject wider loads even when
/// individual byte loads were valid.
fn is_packet_unsafe_prog_type(prog_type: u32) -> bool {
    matches!(
        prog_type,
        BPF_PROG_TYPE_SCHED_CLS
            | BPF_PROG_TYPE_SCHED_ACT
            | BPF_PROG_TYPE_XDP
            | BPF_PROG_TYPE_LWT_IN
            | BPF_PROG_TYPE_LWT_OUT
            | BPF_PROG_TYPE_LWT_XMIT
            | BPF_PROG_TYPE_SK_SKB
    )
}

/// Backward-scan heuristic: returns `true` if `reg` was likely loaded from
/// R1 (ctx) via `LDX_MEM`, making it a probable packet pointer
/// (ctx->data / ctx->data_end).  Scans up to `LOOKBACK` instructions before
/// `before_pc`.
fn is_likely_packet_ptr(reg: i32, before_pc: usize, insns: &[BpfInsn]) -> bool {
    const LOOKBACK: usize = 32;
    let start = before_pc.saturating_sub(LOOKBACK);
    for i in (start..before_pc).rev() {
        let insn = &insns[i];
        if insn.dst_reg() as i32 == reg {
            if insn.is_ldx_mem() {
                // reg = *(type *)(src + off).  Packet ptr if src is R1 (ctx).
                return insn.src_reg() == 1;
            }
            // Any other write to reg: not a ctx-derived pointer.
            return false;
        }
    }
    // Couldn't determine provenance; be conservative and skip.
    true
}

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
        ctx: &PassContext,
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

            // Skip sites that may use packet pointers in XDP/TC programs.
            //
            // The BPF verifier tracks packet pointer ranges specially. Byte-by-byte
            // loads (BPF_B) are always accepted because each only requires 1 byte of
            // range. Wide loads (BPF_H/W/DW) require the verifier to prove a larger
            // contiguous range is within [data, data_end), and may also require
            // natural alignment. The verifier may reject the wider access even when
            // individual byte accesses were valid.
            //
            // In XDP/TC programs, packet pointers (loaded from ctx->data /
            // ctx->data_end) use verifier range tracking that may reject wide
            // loads even when individual byte loads succeeded.  Skip sites
            // whose base register likely holds a packet pointer.
            //
            // Heuristic: a register is a likely packet pointer if it was loaded
            // from R1 (ctx) via LDX_MEM, e.g. `r6 = *(u64 *)(r1 + 0)`.  R10
            // (stack) and registers derived from map lookups or other sources
            // are safe for wide loads.
            if is_packet_unsafe_prog_type(ctx.prog_type) {
                let base_reg = site.get_binding("base_reg").unwrap_or(-1);
                if base_reg != 10
                    && is_likely_packet_ptr(base_reg as i32, site.start_pc, &program.insns)
                {
                    skipped.push(SkipReason {
                        pc: site.start_pc,
                        reason: format!(
                            "likely packet pointer r{} in XDP/TC prog (prog_type={})",
                            base_reg, ctx.prog_type
                        ),
                    });
                    continue;
                }
            }

            safe_sites.push(site.clone());
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                sites_skipped: skipped,
                ..PassResult::unchanged(self.name())
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
        fixup_all_branches(&mut new_insns, orig_insns, &addr_map);

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

// ═══════════════════════════════════════════════════════════════════
// Tests
// ═══════════════════════════════════════════════════════════════════

#[cfg(test)]
#[path = "wide_mem_tests.rs"]
mod tests;
