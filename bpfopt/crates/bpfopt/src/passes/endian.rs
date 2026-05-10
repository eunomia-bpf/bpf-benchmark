// SPDX-License-Identifier: MIT
//! ENDIAN_FUSION optimization pass.

use crate::analysis::{iter_sites, BranchTargetAnalysis};
use crate::insn::*;
use crate::pass::*;

use crate::rewrite::{BtfRemapPolicy, RewritePlan};
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        canonical_name: "bpf_endian_load16",
        aliases: &["endian_load16"],
        decode_proof: decode_endian_proof,
        register_uses: endian_register_uses,
    },
    KinsnDescriptor {
        canonical_name: "bpf_endian_load32",
        aliases: &["endian_load32"],
        decode_proof: decode_endian_proof,
        register_uses: endian_register_uses,
    },
    KinsnDescriptor {
        canonical_name: "bpf_endian_load64",
        aliases: &["endian_load64"],
        decode_proof: decode_endian_proof,
        register_uses: endian_register_uses,
    },
];

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

fn decode_endian_proof(payload: &[u8]) -> ProofRegion {
    ProofRegion::from_result(decode_packed_kinsn_payload(payload).and_then(endian_proof_len))
}

fn endian_proof_len(payload: u64) -> anyhow::Result<usize> {
    validate_bpf_reg("endian dst", kinsn_payload_reg(payload, 0))?;
    validate_bpf_reg("endian base", kinsn_payload_reg(payload, 4))?;
    Ok(2)
}

fn endian_register_uses(payload: u64) -> RegSet {
    [kinsn_payload_reg(payload, 0), kinsn_payload_reg(payload, 4)]
        .into_iter()
        .collect()
}

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
    iter_sites(insns, |insns, pc| {
        scan_endian_site(insns, pc).map(|site| site.old_len)
    })
    .into_iter()
    .filter_map(|site| scan_endian_site(insns, site.pc))
    .collect()
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
fn btf_id_for_size(ctx: &PassContext, size: u8) -> anyhow::Result<i32> {
    let name = kfunc_name_for_size(size)
        .ok_or_else(|| anyhow::anyhow!("unsupported endian fusion size {size}"))?;
    ctx.kinsn_registry.btf_id_for_target_name(name)
}

fn kfunc_name_for_size(size: u8) -> Option<&'static str> {
    match size {
        BPF_H => Some("bpf_endian_load16"),
        BPF_W => Some("bpf_endian_load32"),
        BPF_DW => Some("bpf_endian_load64"),
        _ => None,
    }
}

pub(super) fn endian_payload(dst_reg: u8, base_reg: u8, offset: i16) -> u64 {
    BpfInsn::pack_u4(dst_reg, 0)
        | BpfInsn::pack_u4(base_reg, 4)
        | BpfInsn::pack_u16(offset as u16, 8)
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
    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let bt = analyses.get::<BranchTargetAnalysis>(program);

        let sites = scan_endian_fusion_sites(&program.insns);
        let mut safe_sites: Vec<SafeEndianFusionSite> = Vec::new();
        let mut skipped = find_blocked_narrow_sites(&program.insns);

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
                ..PassResult::unchanged()
            });
        }

        let mut plan = RewritePlan::new();
        for safe_site in &safe_sites {
            let site = &safe_site.site;
            let btf_id = btf_id_for_size(ctx, site.size)?;
            let kfunc_name = kfunc_name_for_size(site.size)
                .ok_or_else(|| anyhow::anyhow!("unsupported endian fusion size {}", site.size))?;
            let kfunc_off = ctx.kinsn_registry.call_off_for_target_name(kfunc_name)?;
            plan.replace_range(
                site.start_pc,
                1,
                emit_endian_fusion_call(
                    site.dst_reg,
                    site.src_reg,
                    site.offset,
                    btf_id,
                    kfunc_off,
                    ctx.platform.arch,
                    site.size,
                ),
            )?;
            plan.delete_range(site.start_pc + site.old_len - 1, 1)?;
        }

        let mut result = plan.commit(program, BtfRemapPolicy::RemapKinsn(&ctx.kinsn_registry))?;
        result.sites_applied = safe_sites.len();
        result.sites_skipped = skipped;
        Ok(result)
    }
}
