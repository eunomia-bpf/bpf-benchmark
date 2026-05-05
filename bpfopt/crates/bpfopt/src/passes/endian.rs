// SPDX-License-Identifier: MIT
//! ENDIAN_FUSION optimization pass.

use crate::analysis::BranchTargetAnalysis;
use crate::insn::*;
use crate::pass::*;

use super::utils::{
    emit_packed_kinsn_call_with_off, fixup_all_branches, kinsn_replacement_subprog_skip_reason,
    remap_kinsn_btf_metadata, resolve_kinsn_call_off_for_target,
};

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
///   sidecar(dst, src, off) + call
///
/// The payload carries the original memory offset directly. When a target
/// cannot natively encode a given offset in its packed endian JIT path, the
/// pass falls back to materializing the effective address around a zero-offset
/// packed call instead of using any legacy call ABI.
pub struct EndianFusionPass;

const BPF_TO_LE: u8 = 0x00;
const MAX_NARROW_SCAN: usize = 32;

/// An endian fusion site: a LDX_MEM followed by a byte-swap
/// on the same destination register, with matching or safely narrowed sizes.
struct EndianFusionSite {
    start_pc: usize,
    old_len: usize,
    dst_reg: u8,
    src_reg: u8,
    offset: i16,
    /// BPF size code: BPF_H (16), BPF_W (32), or BPF_DW (64).
    size: u8,
}

/// An endian fusion site that has passed safety checks, ready for transformation.
struct SafeEndianFusionSite {
    site: EndianFusionSite,
}

/// Scan for LDX_MEM + endian byte-swap patterns with matching or narrowed sizes.
fn scan_endian_fusion_sites(insns: &[BpfInsn]) -> Vec<EndianFusionSite> {
    let mut sites = Vec::new();
    let mut pc = 0;

    while pc + 1 < insns.len() {
        if let Some(site) = scan_endian_site(insns, pc) {
            pc = site.start_pc + site.old_len;
            sites.push(site);
        } else {
            pc += 1;
        }
    }

    sites
}

fn scan_endian_site(insns: &[BpfInsn], pc: usize) -> Option<EndianFusionSite> {
    let load = &insns[pc];
    if !load.is_ldx_mem() {
        return None;
    }

    let load_size = bpf_size(load.code);
    let dst = load.dst_reg();

    if let Some(endian) = insns.get(pc + 1) {
        if endian.dst_reg() == dst {
            if let Some(fused_size) =
                endian_swap_size(endian).and_then(|size| fusion_size(load_size, size))
            {
                return Some(endian_site(load, pc, 2, fused_size));
            }
        }
    }

    if !matches!(load_size, BPF_W | BPF_DW) {
        return None;
    }

    let end = insns.len().min(pc + MAX_NARROW_SCAN + 1);
    for scan_pc in pc + 1..end {
        let insn = &insns[scan_pc];
        if insn.dst_reg() == dst
            && endian_swap_size(insn).is_some_and(|size| is_narrowing(load_size, size))
        {
            return Some(endian_site(
                load,
                pc,
                scan_pc - pc + 1,
                bpf_size_from_endian(insn),
            ));
        }
        if blocks_narrow_window(insn, dst) {
            break;
        }
    }

    None
}

fn endian_site(load: &BpfInsn, start_pc: usize, old_len: usize, size: u8) -> EndianFusionSite {
    EndianFusionSite {
        start_pc,
        old_len,
        dst_reg: load.dst_reg(),
        src_reg: load.src_reg(),
        offset: load.off,
        size,
    }
}

fn bpf_size_from_endian(insn: &BpfInsn) -> u8 {
    endian_swap_size(insn).expect("caller checked endian size")
}

fn endian_swap_size(insn: &BpfInsn) -> Option<u8> {
    if insn.code != (BPF_ALU | BPF_END | BPF_TO_BE)
        && insn.code != (BPF_ALU64 | BPF_END | BPF_TO_LE)
    {
        return None;
    }
    Some(match insn.imm {
        16 => Some(BPF_H),
        32 => Some(BPF_W),
        64 => Some(BPF_DW),
        _ => None,
    }?)
}

fn fusion_size(load_size: u8, endian_size: u8) -> Option<u8> {
    if matches!(
        (load_size, endian_size),
        (BPF_H, BPF_H) | (BPF_W, BPF_W) | (BPF_DW, BPF_DW)
    ) {
        return Some(load_size);
    }
    if is_narrowing(load_size, endian_size) {
        return Some(endian_size);
    }
    None
}

fn is_narrowing(load_size: u8, endian_size: u8) -> bool {
    matches!(
        (load_size, endian_size),
        (BPF_W, BPF_H) | (BPF_DW, BPF_H) | (BPF_DW, BPF_W)
    )
}

fn find_blocked_narrow_sites(insns: &[BpfInsn]) -> Vec<SkipReason> {
    let mut skips = Vec::new();

    for load_pc in 0..insns.len().saturating_sub(2) {
        let load = &insns[load_pc];
        if !load.is_ldx_mem() || !matches!(bpf_size(load.code), BPF_W | BPF_DW) {
            continue;
        }

        let load_size = bpf_size(load.code);
        let dst = load.dst_reg();
        let mut read_before_endian = false;
        let end = insns.len().min(load_pc + MAX_NARROW_SCAN + 1);

        for pc in load_pc + 1..end {
            let insn = &insns[pc];
            if insn.dst_reg() == dst
                && endian_swap_size(insn).is_some_and(|size| is_narrowing(load_size, size))
            {
                if read_before_endian {
                    skips.push(SkipReason {
                        pc: load_pc,
                        reason:
                            "narrow endian fusion blocked: possible upper bits read before endian"
                                .into(),
                    });
                }
                break;
            }
            if is_window_barrier(insn) || writes_reg(insn, dst) {
                break;
            }
            read_before_endian |= reads_reg(insn, dst);
        }
    }

    skips
}

fn blocks_narrow_window(insn: &BpfInsn, reg: u8) -> bool {
    is_window_barrier(insn) || reads_reg(insn, reg) || writes_reg(insn, reg)
}

fn is_window_barrier(insn: &BpfInsn) -> bool {
    insn.is_ldimm64() || insn.is_jmp_class()
}

fn reads_reg(insn: &BpfInsn, reg: u8) -> bool {
    if insn.is_call() {
        return (BPF_REG_1..=BPF_REG_5).contains(&reg);
    }
    if insn.is_exit() {
        return reg == BPF_REG_0;
    }
    (bpf_src(insn.code) == BPF_X && insn.src_reg() == reg)
        || (matches!(insn.class(), BPF_ALU64 | BPF_ALU | BPF_ST | BPF_STX) && insn.dst_reg() == reg)
        || (matches!(insn.class(), BPF_JMP | BPF_JMP32) && !insn.is_ja() && insn.dst_reg() == reg)
        || (insn.class() == BPF_LDX && insn.src_reg() == reg)
}

fn writes_reg(insn: &BpfInsn, reg: u8) -> bool {
    if insn.is_call() {
        return reg <= BPF_REG_5;
    }
    matches!(insn.class(), BPF_ALU64 | BPF_ALU | BPF_LDX | BPF_LD) && insn.dst_reg() == reg
}

/// Select the appropriate BTF ID for a given load size.
fn btf_id_for_size(ctx: &PassContext, size: u8) -> i32 {
    match size {
        BPF_H => ctx.kinsn_registry.endian_load16_btf_id,
        BPF_W => ctx.kinsn_registry.endian_load32_btf_id,
        BPF_DW => ctx.kinsn_registry.endian_load64_btf_id,
        _ => -1,
    }
}

fn kfunc_name_for_size(size: u8) -> Option<&'static str> {
    match size {
        BPF_H => Some("bpf_endian_load16"),
        BPF_W => Some("bpf_endian_load32"),
        BPF_DW => Some("bpf_endian_load64"),
        _ => None,
    }
}

/// Check if any of the three endian_load kfuncs are available.
fn any_endian_kfunc_available(ctx: &PassContext) -> bool {
    ctx.kinsn_registry.endian_load16_btf_id >= 0
        || ctx.kinsn_registry.endian_load32_btf_id >= 0
        || ctx.kinsn_registry.endian_load64_btf_id >= 0
}

fn endian_payload(dst_reg: u8, base_reg: u8, offset: i16) -> u64 {
    (dst_reg as u64) | ((base_reg as u64) << 4) | ((offset as u16 as u64) << 8)
}

fn offset_is_directly_encodable(arch: Arch, size: u8, offset: i16) -> bool {
    match arch {
        Arch::X86_64 => true,
        Arch::Aarch64 => {
            let shift = match size {
                BPF_H => 1,
                BPF_W => 2,
                BPF_DW => 3,
                _ => return false,
            };
            (offset >= 0 && offset <= (0x0fff << shift) && (offset & ((1 << shift) - 1)) == 0)
                || (-256..=255).contains(&offset)
        }
    }
}

fn emit_endian_fusion_call(
    dst_reg: u8,
    src_reg: u8,
    offset: i16,
    btf_id: i32,
    kfunc_off: i16,
    arch: Arch,
    size: u8,
) -> Vec<BpfInsn> {
    let direct_offset = offset_is_directly_encodable(arch, size, offset);
    let mut out = Vec::with_capacity(if direct_offset || offset == 0 {
        2
    } else if src_reg != dst_reg && src_reg != 10 {
        4
    } else if dst_reg == src_reg {
        3
    } else {
        4
    });

    if direct_offset {
        out.extend_from_slice(&emit_packed_kinsn_call_with_off(
            endian_payload(dst_reg, src_reg, offset),
            btf_id,
            kfunc_off,
        ));
        return out;
    }

    // Preserve packed transport even when the target cannot directly encode
    // the original offset in its native JIT path.
    let base_reg = if offset == 0 {
        src_reg
    } else if src_reg != dst_reg && src_reg != 10 {
        out.push(BpfInsn::alu64_imm(BPF_ADD, src_reg, offset as i32));
        out.extend_from_slice(&emit_packed_kinsn_call_with_off(
            endian_payload(dst_reg, src_reg, 0),
            btf_id,
            kfunc_off,
        ));
        out.push(BpfInsn::alu64_imm(BPF_ADD, src_reg, -(offset as i32)));
        return out;
    } else {
        if dst_reg != src_reg {
            out.push(BpfInsn::mov64_reg(dst_reg, src_reg));
        }
        out.push(BpfInsn::alu64_imm(BPF_ADD, dst_reg, offset as i32));
        dst_reg
    };

    out.extend_from_slice(&emit_packed_kinsn_call_with_off(
        endian_payload(dst_reg, base_reg, 0),
        btf_id,
        kfunc_off,
    ));
    out
}

fn endian_fusion_replacement_len(
    dst_reg: u8,
    src_reg: u8,
    offset: i16,
    arch: Arch,
    size: u8,
) -> usize {
    if offset_is_directly_encodable(arch, size, offset) || offset == 0 {
        2
    } else if src_reg != dst_reg && src_reg != BPF_REG_10 {
        4
    } else if dst_reg == src_reg {
        3
    } else {
        4
    }
}

impl BpfPass for EndianFusionPass {
    fn name(&self) -> &str {
        "endian_fusion"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        // Check if any endian_load kfunc is available.
        if !any_endian_kfunc_available(ctx) {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "bpf_endian_loadXX kfuncs not available".into(),
                },
            ));
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);

        if !ctx
            .kinsn_registry
            .packed_supported_for_target_name("bpf_endian_load16")
            && !ctx
                .kinsn_registry
                .packed_supported_for_target_name("bpf_endian_load32")
            && !ctx
                .kinsn_registry
                .packed_supported_for_target_name("bpf_endian_load64")
        {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "bpf_endian_loadXX packed ABI not available".into(),
                },
            ));
        }

        let sites = scan_endian_fusion_sites(&program.insns);
        let mut safe_sites: Vec<SafeEndianFusionSite> = Vec::new();
        let mut skipped = find_blocked_narrow_sites(&program.insns);

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

            if !kfunc_name_for_size(site.size)
                .map(|name| ctx.kinsn_registry.packed_supported_for_target_name(name))
                .unwrap_or(false)
            {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: format!(
                        "bpf_endian_load{} packed ABI not available",
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

            let replacement_len = endian_fusion_replacement_len(
                site.dst_reg,
                site.src_reg,
                site.offset,
                ctx.platform.arch,
                site.size,
            ) + site.old_len.saturating_sub(2);
            if let Some(reason) = kinsn_replacement_subprog_skip_reason(
                &program.insns,
                site.start_pc,
                site.old_len,
                replacement_len,
            )? {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason,
                });
                continue;
            }

            safe_sites.push(SafeEndianFusionSite { site });
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
                let btf_id = btf_id_for_size(ctx, site.size);
                let kfunc_name = kfunc_name_for_size(site.size).ok_or_else(|| {
                    anyhow::anyhow!("unsupported endian fusion size {}", site.size)
                })?;
                let kfunc_off = resolve_kinsn_call_off_for_target(ctx, kfunc_name)?;

                let replacement = emit_endian_fusion_call(
                    site.dst_reg,
                    site.src_reg,
                    site.offset,
                    btf_id,
                    kfunc_off,
                    ctx.platform.arch,
                    site.size,
                );
                let call_len = replacement.len();
                new_insns.extend_from_slice(&replacement);
                let copy_start = pc + 1;
                let copy_end = pc + site.old_len - 1;
                new_insns.extend_from_slice(&program.insns[copy_start..copy_end]);
                map_endian_replacement(
                    &mut addr_map,
                    pc,
                    site.old_len,
                    new_pc,
                    call_len,
                    new_insns.len() - new_pc,
                );

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
        program.log_transform(TransformEntry {
            sites_applied: applied,
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

fn map_endian_replacement(
    addr_map: &mut [usize],
    old_start: usize,
    old_len: usize,
    new_start: usize,
    call_len: usize,
    new_len: usize,
) {
    addr_map[old_start] = new_start;
    for old_pc in old_start + 1..old_start + old_len - 1 {
        addr_map[old_pc] = new_start + call_len + (old_pc - old_start - 1);
    }
    addr_map[old_start + old_len - 1] = new_start + new_len;
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::pass::{AnalysisCache, PassContext};

    fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
        BpfProgram::new(insns)
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
    }

    fn endian_to_be(dst: u8, size: i32) -> BpfInsn {
        BpfInsn::new(
            BPF_ALU | BPF_END | BPF_TO_BE,
            BpfInsn::make_regs(dst, 0),
            0,
            size,
        )
    }

    fn sidecar_payload(insn: &BpfInsn) -> u64 {
        (insn.dst_reg() as u64)
            | (((insn.off as u16) as u64) << 4)
            | (((insn.imm as u32) as u64) << 20)
    }

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn::new(
            BPF_JMP | BPF_JEQ | BPF_K,
            BpfInsn::make_regs(dst, 0),
            off,
            imm,
        )
    }

    fn ctx_with_endian_kfuncs(btf_id16: i32, btf_id32: i32, btf_id64: i32) -> PassContext {
        let mut ctx = PassContext::test_default();
        ctx.kinsn_registry.endian_load16_btf_id = btf_id16;
        ctx.kinsn_registry.endian_load32_btf_id = btf_id32;
        ctx.kinsn_registry.endian_load64_btf_id = btf_id64;
        if btf_id16 >= 0 {
            ctx.kinsn_registry
                .target_supported_encodings
                .insert("bpf_endian_load16".to_string(), BPF_KINSN_ENC_PACKED_CALL);
        }
        if btf_id32 >= 0 {
            ctx.kinsn_registry
                .target_supported_encodings
                .insert("bpf_endian_load32".to_string(), BPF_KINSN_ENC_PACKED_CALL);
        }
        if btf_id64 >= 0 {
            ctx.kinsn_registry
                .target_supported_encodings
                .insert("bpf_endian_load64".to_string(), BPF_KINSN_ENC_PACKED_CALL);
        }
        ctx.platform.has_movbe = true;
        ctx
    }

    fn ctx_with_endian32_kfunc(btf_id: i32) -> PassContext {
        ctx_with_endian_kfuncs(-1, btf_id, -1)
    }

    // ── Pattern scanning tests ─────────────────────────────────────

    #[test]
    fn test_scan_endian_fusion_basic_32bit() {
        let insns = vec![
            BpfInsn::ldx_mem(BPF_W, 2, 1, 4), // LDX_MEM(W) r2, [r1+4]
            endian_to_be(2, 32),              // ENDIAN_TO_BE r2, 32
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
            endian_to_be(3, 32), // different dst
            exit_insn(),
        ];
        let sites = scan_endian_fusion_sites(&insns);
        assert!(sites.is_empty());
    }

    #[test]
    fn test_scan_endian_fusion_no_match_size_mismatch() {
        let insns = vec![
            BpfInsn::ldx_mem(BPF_H, 2, 1, 0), // 16-bit load
            endian_to_be(2, 32),              // 32-bit swap -- mismatch
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
        let mut ctx = PassContext::test_default(); // all btf_ids = -1
        ctx.platform.has_movbe = true; // platform has MOVBE, but kfunc is missing

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert_eq!(result.sites_applied, 0);
        assert!(result.sites_skipped[0]
            .reason
            .contains("kfuncs not available"));
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
        assert_eq!(result.sites_applied, 1);

        // Verify a kfunc call exists with the correct btf_id.
        let has_kfunc_call = prog
            .insns
            .iter()
            .any(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL);
        assert!(has_kfunc_call, "expected a kfunc call in the output");
        let call_insn = prog
            .insns
            .iter()
            .find(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL)
            .unwrap();
        assert_eq!(call_insn.imm, 8888);

        // Verify the last instruction is still EXIT.
        assert!(prog.insns.last().unwrap().is_exit());
    }

    #[test]
    fn test_endian_fusion_narrowing_cases() {
        let sites = scan_endian_fusion_sites(&[
            BpfInsn::ldx_mem(BPF_DW, 2, 6, 8),
            endian_to_be(2, 32),
            BpfInsn::ldx_mem(BPF_DW, 3, 6, 16),
            endian_to_be(3, 16),
            BpfInsn::ldx_mem(BPF_W, 4, 6, 24),
            endian_to_be(4, 16),
        ]);
        assert_eq!(sites.len(), 3);
        assert_eq!(sites[0].size, BPF_W);
        assert_eq!(sites[1].size, BPF_H);
        assert_eq!(sites[2].size, BPF_H);

        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_DW, 2, 6, 8),
            BpfInsn::mov64_imm(3, 7),
            endian_to_be(2, 32),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let result = EndianFusionPass
            .run(&mut prog, &mut cache, &ctx_with_endian32_kfunc(8888))
            .unwrap();
        assert_eq!(result.sites_applied, 1);
        assert!(prog.insns[0].is_kinsn_sidecar());
        assert!(prog.insns[1].is_call());
        assert_eq!(prog.insns[2], BpfInsn::mov64_imm(3, 7));

        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_DW, 2, 6, 8),
            BpfInsn::mov64_reg(3, 2),
            endian_to_be(2, 32),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let result = EndianFusionPass
            .run(&mut prog, &mut cache, &ctx_with_endian32_kfunc(8888))
            .unwrap();
        assert!(result
            .sites_skipped
            .iter()
            .any(|skip| skip.reason.contains("upper bits read")));
    }

    #[test]
    fn test_endian_fusion_pass_zero_offset() {
        // Zero-offset packed encoding stores the base register directly in the
        // low payload bits consumed by the endian kinsn decoder.
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            endian_to_be(2, 32),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert_eq!(result.sites_applied, 1);

        assert!(prog.insns[0].is_kinsn_sidecar());
        assert_eq!(prog.insns[0].dst_reg(), 2);
        assert_eq!(prog.insns[0].off, 6);
        assert_eq!(prog.insns[0].imm, 0);
    }

    #[test]
    fn test_endian_fusion_pass_nonzero_offset() {
        // Non-zero offsets are encoded directly in the packed payload on x86.
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_W, 2, 6, 12),
            endian_to_be(2, 32),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let _result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert_eq!(prog.insns.len(), 3);
        assert!(prog.insns[0].is_kinsn_sidecar());
        assert_eq!(sidecar_payload(&prog.insns[0]), endian_payload(2, 6, 12));
        assert!(prog.insns[1].is_call());
        assert!(prog.insns[2].is_exit());
    }

    #[test]
    fn test_endian_fusion_encodes_stack_offset_directly_on_x86() {
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_DW, 4, BPF_REG_10, -88),
            endian_to_be(4, 64),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian_kfuncs(-1, -1, 3333);

        let pass = EndianFusionPass;
        let _result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert_eq!(prog.insns.len(), 3);
        assert!(prog.insns[0].is_kinsn_sidecar());
        assert_eq!(
            sidecar_payload(&prog.insns[0]),
            endian_payload(4, BPF_REG_10, -88)
        );
        assert!(prog.insns[1].is_call());
        assert!(prog.insns[2].is_exit());
    }

    #[test]
    fn test_endian_fusion_pass_packed_keeps_live_regs() {
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(3, 99), // r3 = 99
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            endian_to_be(2, 32),
            BpfInsn::mov64_reg(0, 3), // uses r3 after site
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert_eq!(result.sites_applied, 1);
        let has_kfunc_call = prog
            .insns
            .iter()
            .any(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL);
        assert!(has_kfunc_call);
    }

    #[test]
    fn test_endian_fusion_pass_packed_no_callee_saved_dependency() {
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(3, 99),
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            endian_to_be(2, 32),
            BpfInsn::alu64_reg(BPF_OR, 0, 3),
            BpfInsn::alu64_reg(BPF_OR, 0, 6),
            BpfInsn::alu64_reg(BPF_OR, 0, 7),
            BpfInsn::alu64_reg(BPF_OR, 0, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 9),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert_eq!(result.sites_applied, 1);
    }

    #[test]
    fn test_endian_fusion_pass_interior_branch_target() {
        // A branch targets the ENDIAN_TO_BE instruction inside the site.
        let mut prog = make_program(vec![
            jeq_imm(5, 0, 1),                 // if r5 == 0, jump to pc=2
            BpfInsn::ldx_mem(BPF_W, 2, 1, 0), // pc=1
            endian_to_be(2, 32),              // pc=2 -- branch target
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result
            .sites_skipped
            .iter()
            .any(|s| s.reason.contains("interior branch")));
    }

    #[test]
    fn test_endian_fusion_pass_branch_fixup() {
        // Branch over a 2-insn site. After rewrite the site becomes
        // longer (kfunc call sequence), so branch offsets must be adjusted.
        let mut prog = make_program(vec![
            jeq_imm(5, 0, 2),                 // if r5==0, skip 2 insns to exit
            BpfInsn::ldx_mem(BPF_W, 2, 6, 4), // pc=1: site start
            endian_to_be(2, 32),              // pc=2: site end
            exit_insn(),                      // pc=3: branch target
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let _result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        // The branch at pc=0 should still reach the EXIT instruction.
        let last_pc = prog.insns.len() - 1;
        assert!(prog.insns[last_pc].is_exit());
        let branch_target = (1 + prog.insns[0].off as i64) as usize;
        assert_eq!(branch_target, last_pc);
    }

    #[test]
    fn test_endian_fusion_pass_uses_static_call_offset() {
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
            endian_to_be(2, 32),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let mut ctx = ctx_with_endian32_kfunc(8888);
        ctx.kinsn_registry
            .target_call_offsets
            .insert("bpf_endian_load32".to_string(), 42);

        let pass = EndianFusionPass;
        let _result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(prog
            .insns
            .iter()
            .any(|insn| insn.is_call() && insn.imm == 8888 && insn.off == 42));
    }

    #[test]
    fn test_endian_fusion_pass_uses_per_size_call_offsets() {
        let mut prog = make_program(vec![
            BpfInsn::ldx_mem(BPF_H, 2, 6, 0),
            endian_to_be(2, 16),
            BpfInsn::ldx_mem(BPF_W, 3, 6, 4),
            endian_to_be(3, 32),
            BpfInsn::ldx_mem(BPF_DW, 4, 6, 8),
            endian_to_be(4, 64),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let mut ctx = ctx_with_endian_kfuncs(111, 222, 333);
        ctx.kinsn_registry.target_call_offsets.extend([
            ("bpf_endian_load16".to_string(), 11),
            ("bpf_endian_load32".to_string(), 22),
            ("bpf_endian_load64".to_string(), 33),
        ]);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert_eq!(result.sites_applied, 3);
        assert!(prog
            .insns
            .iter()
            .any(|insn| insn.is_call() && insn.imm == 111 && insn.off == 11));
        assert!(prog
            .insns
            .iter()
            .any(|insn| insn.is_call() && insn.imm == 222 && insn.off == 22));
        assert!(prog
            .insns
            .iter()
            .any(|insn| insn.is_call() && insn.imm == 333 && insn.off == 33));
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
        assert_eq!(result.sites_applied, 0);
        assert!(result
            .sites_skipped
            .iter()
            .any(|s| s.reason.contains("load16")));
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
        assert_eq!(result.sites_applied, 1);
        // No redundant MOV r0, r0.
        let mov_r0_r0_count = prog
            .insns
            .iter()
            .filter(|i| {
                i.code == (BPF_ALU64 | BPF_MOV | BPF_X) && i.dst_reg() == 0 && i.src_reg() == 0
            })
            .count();
        assert_eq!(mov_r0_r0_count, 0, "should not emit redundant MOV r0, r0");
    }

    #[test]
    fn test_endian_fusion_pass_no_sites() {
        let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_endian32_kfunc(8888);

        let pass = EndianFusionPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert_eq!(result.sites_applied, 0);
    }

    #[test]
    fn test_endian_fusion_pass_two_consecutive_sites() {
        // Use different offsets to verify back-to-back packed endian sites.
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
        assert_eq!(result.sites_applied, 2);
        // Verify two kfunc calls exist.
        let call_count = prog
            .insns
            .iter()
            .filter(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL && i.imm == 8888)
            .count();
        assert_eq!(call_count, 2);
        assert!(prog.insns.last().unwrap().is_exit());
    }

    #[test]
    fn test_endian_fusion_pass_all_three_sizes() {
        // Verify all size variants use packed endian payloads.
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
        assert_eq!(result.sites_applied, 3);

        // Check we got the right BTF IDs for each size.
        let calls: Vec<i32> = prog
            .insns
            .iter()
            .filter(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL)
            .map(|i| i.imm)
            .collect();
        assert!(calls.contains(&1111), "should contain 16-bit kfunc btf_id");
        assert!(calls.contains(&2222), "should contain 32-bit kfunc btf_id");
        assert!(calls.contains(&3333), "should contain 64-bit kfunc btf_id");
    }
}
