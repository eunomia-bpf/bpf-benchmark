// SPDX-License-Identifier: MIT
//! Pattern matching engine — scans BPF instruction sequences for rewrite sites.
//!
//! POC version: implements WIDE_MEM (byte-ladder → wide load) only.

use crate::insn::*;

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

/// A single rewrite site found by the scanner.
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
/// **Variant A — low-byte-first (canonical LE):**
///   insn[0]:   LDX_MEM(B, dst, base, off)        — load byte 0
///   insn[1]:   LDX_MEM(B, tmp, base, off+1)      — load byte 1
///   insn[2]:   LSH64_IMM(tmp, 8)
///   insn[3]:   OR64_REG(dst, tmp)
///   insn[4]:   LDX_MEM(B, tmp, base, off+2)      — load byte 2
///   insn[5]:   LSH64_IMM(tmp, 16)
///   insn[6]:   OR64_REG(dst, tmp)
///   ... Total: 1 + 3*(W-1) insns.
///
/// **Variant B — high-byte-first (clang reorder):**
///   insn[0]:   LDX_MEM(B, dst, base, off+1)      — load byte 1 first
///   insn[1]:   LSH64_IMM(dst, 8)                  — shift dst
///   insn[2]:   LDX_MEM(B, tmp, base, off)         — load byte 0
///   insn[3]:   OR64_REG(dst, tmp)                  — accumulate
///   For each subsequent byte i (2..width-1):
///     insn[3*i-2]: LDX_MEM(B, tmp, base, off+i)
///     insn[3*i-1]: LSH64_IMM(tmp, 8*i)
///     insn[3*i]:   OR64_REG(dst, tmp)
///   Total: 3*W - 2 insns (for W>=2).
pub fn scan_wide_mem(insns: &[BpfInsn]) -> Vec<RewriteSite> {
    let mut sites = Vec::new();
    let n = insns.len();
    if n < 4 {
        return sites;
    }

    let mut pc = 0;
    while pc < n {
        // Try to match starting at `pc`, trying largest widths first.
        if let Some(site) = try_match_wide_mem_at(insns, pc) {
            let site_len = site.old_len;
            sites.push(site);
            pc += site_len; // skip past matched pattern
        } else {
            pc += 1;
        }
    }

    sites
}

/// Try to match a WIDE_MEM byte-ladder starting at `pc`.
/// Returns the largest matching width (tries 8 down to 2).
/// Tries both low-byte-first (variant A) and high-byte-first (variant B).
fn try_match_wide_mem_at(insns: &[BpfInsn], pc: usize) -> Option<RewriteSite> {
    let n = insns.len();

    // The first instruction must be LDX_MEM(B, dst, base, off).
    let first = &insns[pc];
    if !first.is_ldx_mem() || bpf_size(first.code) != BPF_B {
        return None;
    }

    let dst = first.dst_reg();
    let base = first.src_reg();
    let first_off = first.off as i64;

    // Try widths from 8 down to 2, trying both variants at each width.
    for width in (2u32..=8).rev() {
        // ── Variant A: low-byte-first ──
        // Pattern length: 1 + 3*(W-1)
        let len_a = 1 + 3 * (width as usize - 1);
        if pc + len_a <= n {
            if match_wide_mem_low_first(insns, pc, dst, base, first_off, width) {
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
        }

        // ── Variant B: high-byte-first ──
        // Pattern length: 3*W - 2 (for W >= 2)
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

/// Check whether the instructions at `pc` match a WIDE_MEM byte-ladder
/// of the given `width` (little-endian, low-byte-first — Variant A).
fn match_wide_mem_low_first(
    insns: &[BpfInsn],
    pc: usize,
    dst: u8,
    base: u8,
    base_off: i64,
    width: u32,
) -> bool {
    // insn[0] already verified: LDX_MEM(B, dst, base, base_off)
    // For each subsequent byte i in 1..width:
    //   insn[3*(i-1)+1]: LDX_MEM(B, tmp_i, base, base_off + i)
    //   insn[3*(i-1)+2]: LSH64_IMM(tmp_i, 8*i)
    //   insn[3*(i-1)+3]: OR64_REG(dst, tmp_i)
    for i in 1..width {
        let idx = pc + 3 * (i as usize - 1) + 1;

        let load = &insns[idx];
        let shift = &insns[idx + 1];
        let or = &insns[idx + 2];

        // load: LDX_MEM(B, tmp, base, base_off + i)
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
        // tmp must differ from dst (otherwise it would overwrite the accumulator)
        if tmp == dst {
            return false;
        }

        // shift: LSH64_IMM(tmp, 8*i)
        if shift.code != (BPF_ALU64 | BPF_LSH | BPF_K) {
            return false;
        }
        if shift.dst_reg() != tmp {
            return false;
        }
        if shift.imm != (8 * i) as i32 {
            return false;
        }

        // or: OR64_REG(dst, tmp)
        if or.code != (BPF_ALU64 | BPF_OR | BPF_X) {
            return false;
        }
        if or.dst_reg() != dst || or.src_reg() != tmp {
            return false;
        }
    }

    true
}

/// Check whether the instructions at `pc` match a WIDE_MEM byte-ladder
/// of the given `width` using the high-byte-first ordering (Variant B).
///
/// Pattern (clang reorder, as seen in load_byte_recompose.bpf.o):
///   insn[0]:   LDX_MEM(B, dst, base, off_high)     — load byte at off+1
///   insn[1]:   LSH64_IMM(dst, 8)                    — shift by 8
///   insn[2]:   LDX_MEM(B, tmp, base, off_low)       — load byte at off (= off_high - 1)
///   insn[3]:   OR64_REG(dst, tmp)
///   For i in 2..width:
///     insn[3*i-2]: LDX_MEM(B, tmp, base, off_low + i)
///     insn[3*i-1]: LSH64_IMM(tmp, 8*i)
///     insn[3*i]:   OR64_REG(dst, tmp)
///
/// Returns Some(base_off) = the lowest offset, or None on mismatch.
fn match_wide_mem_high_first(
    insns: &[BpfInsn],
    pc: usize,
    dst: u8,
    base: u8,
    first_off: i64,
    width: u32,
) -> Option<i64> {
    // insn[0] already verified: LDX_MEM(B, dst, base, first_off)
    // insn[1] must be: LSH64_IMM(dst, 8)
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

    // insn[2] must be: LDX_MEM(B, tmp, base, first_off - 1) — the byte 0
    let load0 = &insns[pc + 2];
    if !load0.is_ldx_mem() || bpf_size(load0.code) != BPF_B {
        return None;
    }
    if load0.src_reg() != base {
        return None;
    }
    let base_off = load0.off as i64; // this is the actual lowest offset
    if first_off != base_off + 1 {
        return None;
    }
    let tmp0 = load0.dst_reg();
    if tmp0 == dst {
        return None;
    }

    // insn[3] must be: OR64_REG(dst, tmp0)
    let or0 = &insns[pc + 3];
    if or0.code != (BPF_ALU64 | BPF_OR | BPF_X) {
        return None;
    }
    if or0.dst_reg() != dst || or0.src_reg() != tmp0 {
        return None;
    }

    // For each subsequent byte i (2..width):
    //   insn[3*i-2]: LDX_MEM(B, tmp, base, base_off + i)
    //   insn[3*i-1]: LSH64_IMM(tmp, 8*i)
    //   insn[3*i]:   OR64_REG(dst, tmp)
    for i in 2..width {
        let idx = pc + 3 * i as usize - 2;

        let load = &insns[idx];
        let shift = &insns[idx + 1];
        let or = &insns[idx + 2];

        // load: LDX_MEM(B, tmp, base, base_off + i)
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

        // shift: LSH64_IMM(tmp, 8*i)
        if shift.code != (BPF_ALU64 | BPF_LSH | BPF_K) {
            return None;
        }
        if shift.dst_reg() != tmp {
            return None;
        }
        if shift.imm != (8 * i) as i32 {
            return None;
        }

        // or: OR64_REG(dst, tmp)
        if or.code != (BPF_ALU64 | BPF_OR | BPF_X) {
            return None;
        }
        if or.dst_reg() != dst || or.src_reg() != tmp {
            return None;
        }
    }

    Some(base_off)
}

/// Scan all supported patterns on the given instruction sequence.
/// (POC: only WIDE_MEM.)
pub fn scan_all(insns: &[BpfInsn]) -> Vec<RewriteSite> {
    scan_wide_mem(insns)
}

#[cfg(test)]
mod tests {
    use super::*;

    /// Build a canonical 4-byte little-endian byte-ladder.
    fn build_wide_mem_4(dst: u8, base: u8, off: i16) -> Vec<BpfInsn> {
        vec![
            // byte 0
            BpfInsn::ldx_mem(BPF_B, dst, base, off),
            // byte 1
            BpfInsn::ldx_mem(BPF_B, 2, base, off + 1),
            BpfInsn::alu64_imm(BPF_LSH, 2, 8),
            BpfInsn::alu64_reg(BPF_OR, dst, 2),
            // byte 2
            BpfInsn::ldx_mem(BPF_B, 3, base, off + 2),
            BpfInsn::alu64_imm(BPF_LSH, 3, 16),
            BpfInsn::alu64_reg(BPF_OR, dst, 3),
            // byte 3
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
            // byte 0
            BpfInsn::ldx_mem(BPF_B, 1, 6, 0),
            // byte 1
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
        // Not a byte ladder: second load has wrong offset.
        let insns = vec![
            BpfInsn::ldx_mem(BPF_B, 0, 6, 10),
            BpfInsn::ldx_mem(BPF_B, 2, 6, 20), // wrong offset
            BpfInsn::alu64_imm(BPF_LSH, 2, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 2),
        ];
        let sites = scan_wide_mem(&insns);
        assert!(sites.is_empty());
    }

    #[test]
    fn test_scan_wide_mem_embedded_in_program() {
        // prefix + wide_mem_4 + suffix
        let mut insns = vec![
            BpfInsn::mov64_imm(0, 0), // prefix
        ];
        insns.extend(build_wide_mem_4(0, 6, 10));
        insns.push(BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        }); // suffix

        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].start_pc, 1);
        assert_eq!(sites[0].old_len, 10);
    }

    #[test]
    fn test_scan_wide_mem_multiple_sites() {
        // Two consecutive 2-byte wide_mem patterns.
        let mut insns = Vec::new();
        // site 1: dst=0, base=6, off=0
        insns.push(BpfInsn::ldx_mem(BPF_B, 0, 6, 0));
        insns.push(BpfInsn::ldx_mem(BPF_B, 1, 6, 1));
        insns.push(BpfInsn::alu64_imm(BPF_LSH, 1, 8));
        insns.push(BpfInsn::alu64_reg(BPF_OR, 0, 1));
        // site 2: dst=3, base=7, off=4
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
        // Build a 4-byte pattern; scanner should match width=4, not two width=2.
        let insns = build_wide_mem_4(0, 6, 0);
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].get_binding("width"), Some(4));
    }

    // ── High-byte-first (Variant B) tests ──────────────────────────

    /// Build a 2-byte high-byte-first pattern:
    ///   LDX_MEM(B, dst, base, off+1)   — byte 1 first
    ///   LSH64(dst, 8)
    ///   LDX_MEM(B, tmp, base, off)     — byte 0
    ///   OR64(dst, tmp)
    fn build_wide_mem_high_first_2(dst: u8, tmp: u8, base: u8, off: i16) -> Vec<BpfInsn> {
        vec![
            BpfInsn::ldx_mem(BPF_B, dst, base, off + 1),
            BpfInsn::alu64_imm(BPF_LSH, dst, 8),
            BpfInsn::ldx_mem(BPF_B, tmp, base, off),
            BpfInsn::alu64_reg(BPF_OR, dst, tmp),
        ]
    }

    /// Build a 4-byte high-byte-first pattern (as produced by clang for micro_read_u32_le):
    ///   LDX_MEM(B, dst, base, off+1)   — byte 1 first
    ///   LSH64(dst, 8)
    ///   LDX_MEM(B, tmp, base, off)     — byte 0
    ///   OR64(dst, tmp)
    ///   LDX_MEM(B, tmp, base, off+2)   — byte 2
    ///   LSH64(tmp, 16)
    ///   OR64(dst, tmp)
    ///   LDX_MEM(B, tmp, base, off+3)   — byte 3
    ///   LSH64(tmp, 24)
    ///   OR64(dst, tmp)
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
        assert_eq!(s.old_len, 4); // 3*2 - 2 = 4
        assert_eq!(s.family, Family::WideMem);
        assert_eq!(s.get_binding("dst_reg"), Some(1));
        assert_eq!(s.get_binding("base_reg"), Some(6));
        assert_eq!(s.get_binding("base_off"), Some(10)); // lowest offset
        assert_eq!(s.get_binding("width"), Some(2));
    }

    #[test]
    fn test_scan_high_first_4byte() {
        let insns = build_wide_mem_high_first_4(2, 3, 1, 8);
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        let s = &sites[0];
        assert_eq!(s.start_pc, 0);
        assert_eq!(s.old_len, 10); // 3*4 - 2 = 10
        assert_eq!(s.family, Family::WideMem);
        assert_eq!(s.get_binding("dst_reg"), Some(2));
        assert_eq!(s.get_binding("base_reg"), Some(1));
        assert_eq!(s.get_binding("base_off"), Some(8)); // lowest offset
        assert_eq!(s.get_binding("width"), Some(4));
    }

    #[test]
    fn test_scan_high_first_matches_clang_output() {
        // Exact instructions from load_byte_recompose.bpf.o insns 10-19:
        //   10: r2 = *(u8 *)(r1 + 9)
        //   11: r2 <<= 8
        //   12: r3 = *(u8 *)(r1 + 8)
        //   13: r2 |= r3
        //   14: r3 = *(u8 *)(r1 + 10)
        //   15: r3 <<= 16
        //   16: r2 |= r3
        //   17: r3 = *(u8 *)(r1 + 11)
        //   18: r3 <<= 24
        //   19: r2 |= r3
        let insns = vec![
            BpfInsn::ldx_mem(BPF_B, 2, 1, 9),   // r2 = *(u8*)(r1+9)
            BpfInsn::alu64_imm(BPF_LSH, 2, 8),  // r2 <<= 8
            BpfInsn::ldx_mem(BPF_B, 3, 1, 8),   // r3 = *(u8*)(r1+8)
            BpfInsn::alu64_reg(BPF_OR, 2, 3),   // r2 |= r3
            BpfInsn::ldx_mem(BPF_B, 3, 1, 10),  // r3 = *(u8*)(r1+10)
            BpfInsn::alu64_imm(BPF_LSH, 3, 16), // r3 <<= 16
            BpfInsn::alu64_reg(BPF_OR, 2, 3),   // r2 |= r3
            BpfInsn::ldx_mem(BPF_B, 3, 1, 11),  // r3 = *(u8*)(r1+11)
            BpfInsn::alu64_imm(BPF_LSH, 3, 24), // r3 <<= 24
            BpfInsn::alu64_reg(BPF_OR, 2, 3),   // r2 |= r3
        ];
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        let s = &sites[0];
        assert_eq!(s.start_pc, 0);
        assert_eq!(s.old_len, 10);
        assert_eq!(s.get_binding("dst_reg"), Some(2));
        assert_eq!(s.get_binding("base_reg"), Some(1));
        assert_eq!(s.get_binding("base_off"), Some(8)); // lowest offset for replacement LDX_MEM
        assert_eq!(s.get_binding("width"), Some(4));
    }

    #[test]
    fn test_scan_high_first_embedded() {
        // prefix + high-first-4 + suffix
        let mut insns = vec![
            BpfInsn::mov64_imm(0, 0), // prefix
        ];
        insns.extend(build_wide_mem_high_first_4(2, 3, 1, 8));
        insns.push(BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        }); // suffix
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].start_pc, 1);
        assert_eq!(sites[0].old_len, 10);
        assert_eq!(sites[0].get_binding("base_off"), Some(8));
    }

    #[test]
    fn test_scan_high_first_no_false_positive() {
        // Shift amount doesn't match byte position — should not match.
        let insns = vec![
            BpfInsn::ldx_mem(BPF_B, 2, 1, 9),
            BpfInsn::alu64_imm(BPF_LSH, 2, 8),
            BpfInsn::ldx_mem(BPF_B, 3, 1, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            BpfInsn::ldx_mem(BPF_B, 3, 1, 10),
            BpfInsn::alu64_imm(BPF_LSH, 3, 24), // wrong: should be 16
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_wide_mem(&insns);
        // Should NOT match as 4-byte or 3-byte high-first.
        // Might match the first 4 insns as a 2-byte high-first.
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].old_len, 4); // only the 2-byte match
        assert_eq!(sites[0].get_binding("width"), Some(2));
    }

    #[test]
    fn test_scan_high_first_prefers_largest() {
        // A 4-byte high-first should be preferred over 2-byte.
        let insns = build_wide_mem_high_first_4(2, 3, 1, 0);
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].get_binding("width"), Some(4));
    }
}
