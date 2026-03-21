// SPDX-License-Identifier: MIT
//! Bytecode rewriter — applies matched sites and fixes up branch offsets.
//!
//! Core algorithm:
//! 1. Walk original instructions; at each site, emit replacement insns, else copy.
//! 2. Build addr_map[old_pc] → new_pc.
//! 3. Fix up all JMP/CALL relative offsets using the addr_map.

use anyhow::{bail, Result};

use crate::emit;
use crate::insn::*;
use crate::matcher::RewriteSite;

/// Result of a rewrite pass.
#[derive(Clone, Debug)]
pub struct RewriteResult {
    /// The new instruction sequence after rewriting.
    pub new_insns: Vec<BpfInsn>,
    /// Whether any transforms were actually applied.
    pub has_transforms: bool,
    /// How many sites were applied.
    pub sites_applied: usize,
}

/// Rewrite a BPF instruction sequence by applying the given rewrite sites.
///
/// Sites must be sorted by `start_pc` and non-overlapping. The function
/// emits replacement instructions for each site, copies all other instructions
/// verbatim, and then fixes up all branch/jump offsets.
pub fn rewrite(insns: &[BpfInsn], sites: &[RewriteSite]) -> Result<RewriteResult> {
    if sites.is_empty() {
        return Ok(RewriteResult {
            new_insns: insns.to_vec(),
            has_transforms: false,
            sites_applied: 0,
        });
    }

    // Validate sites are sorted and non-overlapping.
    for w in sites.windows(2) {
        if w[1].start_pc < w[0].start_pc + w[0].old_len {
            bail!(
                "overlapping sites: site at {} (len {}) and site at {}",
                w[0].start_pc,
                w[0].old_len,
                w[1].start_pc
            );
        }
    }

    let n = insns.len();

    // ── Phase 1: Build new instruction stream + address map ─────────
    // addr_map[old_pc] = new_pc for every original instruction index.
    // For instructions inside a replaced site, we map them to the start of
    // the replacement block.
    let mut new_insns: Vec<BpfInsn> = Vec::with_capacity(n);
    let mut addr_map: Vec<usize> = vec![0; n + 1]; // +1 for the "end" sentinel
    let mut sites_applied = 0usize;

    let mut old_pc = 0usize;
    let mut site_idx = 0usize;

    while old_pc < n {
        let new_pc = new_insns.len();

        if site_idx < sites.len() && old_pc == sites[site_idx].start_pc {
            let site = &sites[site_idx];
            let replacement = emit::emit_site(site)?;

            // Map all old PCs in the site range to the start of the replacement.
            for j in 0..site.old_len {
                addr_map[old_pc + j] = new_pc;
            }

            new_insns.extend_from_slice(&replacement);
            old_pc += site.old_len;
            site_idx += 1;
            sites_applied += 1;
        } else {
            addr_map[old_pc] = new_pc;
            new_insns.push(insns[old_pc]);

            // Handle LDIMM64 (two-slot instruction): copy the second slot too.
            if insns[old_pc].is_ldimm64() && old_pc + 1 < n {
                old_pc += 1;
                addr_map[old_pc] = new_insns.len();
                new_insns.push(insns[old_pc]);
            }

            old_pc += 1;
        }
    }

    // Sentinel: map the "end" position.
    addr_map[n] = new_insns.len();

    // ── Phase 2: Fix up branch offsets ──────────────────────────────
    fixup_branches(&mut new_insns, insns, &addr_map)?;

    Ok(RewriteResult {
        new_insns,
        has_transforms: sites_applied > 0,
        sites_applied,
    })
}

/// Fix up all JMP/CALL relative offsets after rewriting.
///
/// For each instruction in the *original* stream that is a branch/jump,
/// we compute where it ended up in the new stream and adjust its offset
/// so it still points to the correct target.
fn fixup_branches(
    new_insns: &mut [BpfInsn],
    old_insns: &[BpfInsn],
    addr_map: &[usize],
) -> Result<()> {
    let old_n = old_insns.len();

    // We need to iterate over old instructions and find their new positions.
    // Then fix the branch offset of the new instruction.
    let mut old_pc = 0usize;
    while old_pc < old_n {
        let insn = &old_insns[old_pc];

        // Only process jump-class instructions with relative offsets.
        if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
            let new_pc = addr_map[old_pc];

            // The old target pc.
            let old_target = (old_pc as i64 + 1 + insn.off as i64) as usize;
            if old_target > old_n {
                bail!(
                    "branch at old_pc={} targets {} which is out of range (len={})",
                    old_pc,
                    old_target,
                    old_n
                );
            }

            let new_target = addr_map[old_target];

            // The instruction at new_pc should be the same branch (or a NOP if
            // inside a replaced site — but replaced-site insns are skipped, so
            // we should only get here for non-replaced insns).
            if new_pc < new_insns.len() && new_insns[new_pc].is_jmp_class() {
                let new_off = new_target as i64 - (new_pc as i64 + 1);
                new_insns[new_pc].off = new_off as i16;
            }
        }

        // Skip LDIMM64's second slot.
        if insn.is_ldimm64() {
            old_pc += 2;
        } else {
            old_pc += 1;
        }
    }

    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::matcher::{Binding, Family};

    /// Helper: build a wide_mem_4 pattern (10 insns) at the start.
    fn wide_mem_4_insns(dst: u8, base: u8, off: i16) -> Vec<BpfInsn> {
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

    fn make_wide_mem_site(start_pc: usize) -> RewriteSite {
        RewriteSite {
            start_pc,
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
        }
    }

    #[test]
    fn test_rewrite_wide_mem() {
        // Program: wide_mem_4 + exit
        let mut insns = wide_mem_4_insns(0, 6, 10);
        insns.push(BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        });

        let sites = vec![make_wide_mem_site(0)];
        let result = rewrite(&insns, &sites).unwrap();

        assert!(result.has_transforms);
        assert_eq!(result.sites_applied, 1);
        // 10 insns replaced by 1, plus 1 exit = 2 total.
        assert_eq!(result.new_insns.len(), 2);
        // First insn should be LDX_MEM(W, 0, 6, 10).
        assert_eq!(result.new_insns[0].code, BPF_LDX | BPF_W | BPF_MEM);
        assert_eq!(result.new_insns[0].dst_reg(), 0);
        assert_eq!(result.new_insns[0].src_reg(), 6);
        assert_eq!(result.new_insns[0].off, 10);
        // Second insn should be exit.
        assert!(result.new_insns[1].is_exit());
    }

    #[test]
    fn test_rewrite_no_sites() {
        let insns = vec![
            BpfInsn::mov64_imm(0, 42),
            BpfInsn {
                code: BPF_JMP | BPF_EXIT,
                regs: 0,
                off: 0,
                imm: 0,
            },
        ];
        let result = rewrite(&insns, &[]).unwrap();
        assert!(!result.has_transforms);
        assert_eq!(result.sites_applied, 0);
        assert_eq!(result.new_insns.len(), 2);
    }

    #[test]
    fn test_branch_fixup() {
        // Program layout (old):
        //   0: mov64_imm r0, 0
        //   1-10: wide_mem_4 (10 insns)
        //   11: mov64_imm r0, 1
        //   12: ja +1            → target is 14 (old_pc 12 + 1 + off 1 = 14)
        //   13: mov64_imm r0, 2
        //   14: exit
        //
        // After rewrite (wide_mem_4 → 1 insn):
        //   0: mov64_imm r0, 0
        //   1: ldx_mem(W, ...)    (replaces 1..10)
        //   2: mov64_imm r0, 1
        //   3: ja +1              → should still target exit (new pc 5)
        //   4: mov64_imm r0, 2
        //   5: exit
        //
        // So the ja at new_pc=3 should have off = 5 - (3+1) = 1 (unchanged in this case).

        let mut insns = Vec::new();
        insns.push(BpfInsn::mov64_imm(0, 0)); // 0
        insns.extend(wide_mem_4_insns(0, 6, 10)); // 1..10
        insns.push(BpfInsn::mov64_imm(0, 1)); // 11
        insns.push(BpfInsn::ja(1)); // 12: ja +1 → 14
        insns.push(BpfInsn::mov64_imm(0, 2)); // 13
        insns.push(BpfInsn {
            // 14: exit
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        });

        let sites = vec![RewriteSite {
            start_pc: 1,
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
        }];

        let result = rewrite(&insns, &sites).unwrap();
        assert_eq!(result.new_insns.len(), 6); // 1 + 1 + 1 + 1 + 1 + 1

        // Verify the ja instruction is at new_pc=3 and offset is still 1.
        let ja_insn = &result.new_insns[3];
        assert!(ja_insn.is_ja());
        assert_eq!(
            ja_insn.off, 1,
            "ja offset should be 1 (skip one insn to exit)"
        );
    }

    #[test]
    fn test_branch_fixup_forward_across_site() {
        // Program layout (old):
        //   0: ja +10              → target is 11
        //   1-10: wide_mem_4 (10 insns)
        //   11: exit
        //
        // After rewrite:
        //   0: ja +?               → should target exit at new_pc=2
        //   1: ldx_mem(W, ...)
        //   2: exit
        //
        // ja at new_pc=0: off = 2 - (0+1) = 1

        let mut insns = Vec::new();
        insns.push(BpfInsn::ja(10)); // 0: ja +10 → pc 11
        insns.extend(wide_mem_4_insns(0, 6, 0)); // 1..10
        insns.push(BpfInsn {
            // 11: exit
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        });

        let sites = vec![RewriteSite {
            start_pc: 1,
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
                    value: 0,
                },
                Binding {
                    name: "width",
                    value: 4,
                },
            ],
        }];

        let result = rewrite(&insns, &sites).unwrap();
        assert_eq!(result.new_insns.len(), 3);

        // ja at new_pc=0 should now have off=1 (was 10).
        let ja = &result.new_insns[0];
        assert!(ja.is_ja());
        assert_eq!(ja.off, 1, "ja should jump over ldx_mem to exit");
    }

    #[test]
    fn test_branch_fixup_backward_across_site() {
        // Program layout (old):
        //   0: mov64_imm r0, 0
        //   1-10: wide_mem_4 (10 insns)
        //   11: ja -12            → target is 11 + 1 + (-12) = 0
        //   12: exit
        //
        // After rewrite:
        //   0: mov64_imm r0, 0
        //   1: ldx_mem(W, ...)
        //   2: ja -3              → target should be new_pc 0 (2 + 1 + (-3) = 0)
        //   3: exit

        let mut insns = Vec::new();
        insns.push(BpfInsn::mov64_imm(0, 0)); // 0
        insns.extend(wide_mem_4_insns(0, 6, 0)); // 1..10
        insns.push(BpfInsn::ja(-12)); // 11: ja -12 → pc 0
        insns.push(BpfInsn {
            // 12: exit
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        });

        let sites = vec![RewriteSite {
            start_pc: 1,
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
                    value: 0,
                },
                Binding {
                    name: "width",
                    value: 4,
                },
            ],
        }];

        let result = rewrite(&insns, &sites).unwrap();
        assert_eq!(result.new_insns.len(), 4);

        // ja at new_pc=2 should have off=-3 (target new_pc 0).
        let ja = &result.new_insns[2];
        assert!(ja.is_ja());
        assert_eq!(ja.off, -3, "ja should jump back to pc 0");
    }

    #[test]
    fn test_overlapping_sites_rejected() {
        let sites = vec![
            RewriteSite {
                start_pc: 0,
                old_len: 10,
                family: Family::WideMem,
                bindings: vec![],
            },
            RewriteSite {
                start_pc: 5, // overlaps with first site
                old_len: 10,
                family: Family::WideMem,
                bindings: vec![],
            },
        ];
        let insns = vec![BpfInsn::nop(); 20];
        assert!(rewrite(&insns, &sites).is_err());
    }

    #[test]
    fn test_conditional_branch_fixup() {
        // Program layout (old):
        //   0: jeq r1, 0, +10    → target is 11
        //   1-10: wide_mem_4
        //   11: exit
        //
        // After rewrite:
        //   0: jeq r1, 0, +1     → target is 2 (exit)
        //   1: ldx_mem(W)
        //   2: exit

        let mut insns = Vec::new();
        insns.push(BpfInsn {
            code: BPF_JMP | BPF_JEQ | BPF_K,
            regs: BpfInsn::make_regs(1, 0),
            off: 10,
            imm: 0,
        });
        insns.extend(wide_mem_4_insns(0, 6, 0));
        insns.push(BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        });

        let sites = vec![RewriteSite {
            start_pc: 1,
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
                    value: 0,
                },
                Binding {
                    name: "width",
                    value: 4,
                },
            ],
        }];

        let result = rewrite(&insns, &sites).unwrap();
        assert_eq!(result.new_insns.len(), 3);

        let jeq = &result.new_insns[0];
        assert!(jeq.is_cond_jmp());
        assert_eq!(jeq.off, 1, "jeq should jump to exit at new_pc=2");
    }
}
