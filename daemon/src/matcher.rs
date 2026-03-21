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
        self.bindings.iter().find(|b| b.name == name).map(|b| b.value)
    }
}

/// Scan for WIDE_MEM (little-endian byte-ladder) patterns.
///
/// Pattern for width W (2..=8):
///   insn[0]:   LDX_MEM(B, dst, base, off)
///   for i in 1..W:
///     insn[2i-1]: LDX_MEM(B, tmp_i, base, off+i)
///     insn[2i]:   LSH64_IMM(tmp_i, 8*i)
///     insn[2i+1]: OR64_REG(dst, tmp_i)
///
/// Total pattern length = 1 + 3*(W-1) instructions.
///
/// Actually, the canonical little-endian byte-recompose pattern is:
///   insn[0]:   LDX_MEM(B, dst, base, off)        — load byte 0
///   insn[1]:   LDX_MEM(B, tmp, base, off+1)      — load byte 1
///   insn[2]:   LSH64_IMM(tmp, 8)
///   insn[3]:   OR64_REG(dst, tmp)
///   insn[4]:   LDX_MEM(B, tmp, base, off+2)      — load byte 2
///   insn[5]:   LSH64_IMM(tmp, 16)
///   insn[6]:   OR64_REG(dst, tmp)
///   ... and so on for each additional byte.
///
/// For W=4: 10 insns. For W=2: 4 insns. For W=8: 22 insns.
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
fn try_match_wide_mem_at(insns: &[BpfInsn], pc: usize) -> Option<RewriteSite> {
    let n = insns.len();

    // The first instruction must be LDX_MEM(B, dst, base, off).
    let first = &insns[pc];
    if !first.is_ldx_mem() || bpf_size(first.code) != BPF_B {
        return None;
    }

    let dst = first.dst_reg();
    let base = first.src_reg();
    let base_off = first.off as i64;

    // Try widths from 8 down to 2.
    for width in (2u32..=8).rev() {
        let pattern_len = 1 + 3 * (width as usize - 1);
        if pc + pattern_len > n {
            continue;
        }

        if match_wide_mem_width(insns, pc, dst, base, base_off, width) {
            return Some(RewriteSite {
                start_pc: pc,
                old_len: pattern_len,
                family: Family::WideMem,
                bindings: vec![
                    Binding { name: "dst_reg", value: dst as i64 },
                    Binding { name: "base_reg", value: base as i64 },
                    Binding { name: "base_off", value: base_off },
                    Binding { name: "width", value: width as i64 },
                ],
            });
        }
    }

    None
}

/// Check whether the instructions at `pc` match a WIDE_MEM byte-ladder
/// of the given `width` (little-endian, low-byte-first).
fn match_wide_mem_width(
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
        if tmp == dst && i > 0 {
            // Some compilers may reuse dst, but the canonical pattern uses a temp.
            // For the POC, we allow tmp == dst only if width == 2 and there is no
            // subsequent OR that reads the old dst. For simplicity, disallow.
            // Actually, if the compiler does `ldx dst, [base+i]; lsh dst, 8*i; or dst, dst`
            // that's semantically wrong (or dst,dst is a nop for OR). So tmp != dst is required.
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
        insns.push(BpfInsn { code: BPF_JMP | BPF_EXIT, regs: 0, off: 0, imm: 0 }); // suffix

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
}
