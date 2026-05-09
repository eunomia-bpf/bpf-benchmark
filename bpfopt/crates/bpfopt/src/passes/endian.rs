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
pub(super) struct EndianFusionSite {
    pub(super) start_pc: usize,
    pub(super) old_len: usize,
    pub(super) dst_reg: u8,
    pub(super) src_reg: u8,
    pub(super) offset: i16,
    /// BPF size code: BPF_H (16), BPF_W (32), or BPF_DW (64).
    pub(super) size: u8,
}

/// An endian fusion site that has passed safety checks, ready for transformation.
struct SafeEndianFusionSite {
    site: EndianFusionSite,
}

/// Scan for LDX_MEM + endian byte-swap patterns with matching or narrowed sizes.
pub(super) fn scan_endian_fusion_sites(insns: &[BpfInsn]) -> Vec<EndianFusionSite> {
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

pub(super) fn endian_payload(dst_reg: u8, base_reg: u8, offset: i16) -> u64 {
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
            .kinsn_registered_for_target_name("bpf_endian_load16")
            && !ctx
                .kinsn_registry
                .kinsn_registered_for_target_name("bpf_endian_load32")
            && !ctx
                .kinsn_registry
                .kinsn_registered_for_target_name("bpf_endian_load64")
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
                .map(|name| ctx.kinsn_registry.kinsn_registered_for_target_name(name))
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
