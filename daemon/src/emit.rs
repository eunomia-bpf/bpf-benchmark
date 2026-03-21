// SPDX-License-Identifier: MIT
//! Per-transform emit logic — generates replacement instruction sequences.
//!
//! Each transform family has an `emit_*` function that takes a `RewriteSite`
//! and produces replacement BPF instructions.

use anyhow::{bail, Result};

use crate::insn::*;
use crate::matcher::{Family, RewriteSite};

/// Emit replacement instructions for a single rewrite site.
///
/// Returns the replacement instruction sequence (may be shorter than the
/// original, which is the whole point).
pub fn emit_site(site: &RewriteSite) -> Result<Vec<BpfInsn>> {
    match site.family {
        Family::WideMem => emit_wide_mem(site),
    }
}

/// WIDE_MEM: replace a byte-ladder with a single wide load.
///
/// Input: 10 insns (for width=4) doing byte loads + shifts + ORs.
/// Output: 1 insn `LDX_MEM(size, dst, base, off)` where size matches width.
fn emit_wide_mem(site: &RewriteSite) -> Result<Vec<BpfInsn>> {
    let dst = site.get_binding("dst_reg")
        .ok_or_else(|| anyhow::anyhow!("missing dst_reg binding"))? as u8;
    let base = site.get_binding("base_reg")
        .ok_or_else(|| anyhow::anyhow!("missing base_reg binding"))? as u8;
    let off = site.get_binding("base_off")
        .ok_or_else(|| anyhow::anyhow!("missing base_off binding"))? as i16;
    let width = site.get_binding("width")
        .ok_or_else(|| anyhow::anyhow!("missing width binding"))?;

    let size = match width {
        2 => BPF_H,
        4 => BPF_W,
        8 => BPF_DW,
        // For widths 3, 5, 6, 7: the POC doesn't handle non-power-of-2 widths.
        // In a real implementation we would emit a smaller wide load + remaining bytes,
        // but for the POC we bail.
        _ => bail!("WIDE_MEM: unsupported width {} (POC supports 2, 4, 8)", width),
    };

    Ok(vec![BpfInsn::ldx_mem(size, dst, base, off)])
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::matcher::Binding;

    #[test]
    fn test_emit_wide_mem_4() {
        let site = RewriteSite {
            start_pc: 5,
            old_len: 10,
            family: Family::WideMem,
            bindings: vec![
                Binding { name: "dst_reg", value: 0 },
                Binding { name: "base_reg", value: 6 },
                Binding { name: "base_off", value: 10 },
                Binding { name: "width", value: 4 },
            ],
        };
        let result = emit_site(&site).unwrap();
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
                Binding { name: "dst_reg", value: 1 },
                Binding { name: "base_reg", value: 7 },
                Binding { name: "base_off", value: 0 },
                Binding { name: "width", value: 2 },
            ],
        };
        let result = emit_site(&site).unwrap();
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
                Binding { name: "dst_reg", value: 3 },
                Binding { name: "base_reg", value: 10 },
                Binding { name: "base_off", value: -8 },
                Binding { name: "width", value: 8 },
            ],
        };
        let result = emit_site(&site).unwrap();
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
                Binding { name: "dst_reg", value: 0 },
                Binding { name: "base_reg", value: 6 },
                Binding { name: "base_off", value: 0 },
                Binding { name: "width", value: 3 },
            ],
        };
        assert!(emit_site(&site).is_err());
    }
}
