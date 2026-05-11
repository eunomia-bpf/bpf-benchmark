// SPDX-License-Identifier: MIT
//! EXTRACT optimization pass.

use std::ops::Range;

use crate::analysis::{block_slot_offset, BBProgram, BlockId, InsnSite};
use crate::insn::*;
use crate::pass::*;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[KinsnDescriptor {
    canonical_name: "bpf_extract64",
    aliases: &["extract64"],
    decode_proof: decode_extract_proof,
    register_uses: extract_register_uses,
}];

fn decode_extract_proof(payload: &[u8]) -> ProofRegion {
    ProofRegion::from_result(decode_packed_kinsn_payload(payload).and_then(extract_proof_len))
}

fn extract_proof_len(payload: u64) -> anyhow::Result<usize> {
    validate_bpf_reg("extract dst", kinsn_payload_reg(payload, 0))?;
    let start = kinsn_payload_u8(payload, 8);
    let bit_len = kinsn_payload_u8(payload, 16);
    if start >= 64 || bit_len == 0 || bit_len > 64 || u16::from(start) + u16::from(bit_len) > 64 {
        anyhow::bail!("extract payload has invalid range start={start} bit_len={bit_len}");
    }
    Ok(usize::from(start != 0) + 1)
}

fn extract_register_uses(payload: u64) -> RegSet {
    [kinsn_payload_reg(payload, 0)].into_iter().collect()
}

/// EXTRACT optimization pass: replaces RSH+AND bitfield extraction patterns
/// with bpf_extract64() kfunc calls.
///
/// Pattern:
///   RSH64_IMM dst, shift
///   AND64_IMM dst, mask
///
/// Where `mask` is a contiguous bitmask (all 1s), i.e. `(1 << len) - 1`.
///
/// Replacement:
///   r1 = dst (value)
///   r2 = start (shift amount)
///   r3 = len (popcount of mask)
///   call bpf_extract64
///   dst = r0
pub struct ExtractPass;

pub(super) struct ExtractSite {
    pub(super) start_pc: usize,
    pub(super) old_len: usize,
    pub(super) dst_reg: u8,
    pub(super) shift_amount: u32,
    pub(super) bit_len: u32,
}

/// An extract site that has passed safety checks, ready for transformation.
struct SafeExtractSite {
    block: BlockId,
    range: Range<usize>,
    site: ExtractSite,
}

/// Check if a value is a contiguous bitmask of 1s starting from bit 0.
/// Returns the number of set bits (popcount) if valid, or None.
pub(super) fn contiguous_mask_len(mask: u64) -> Option<u32> {
    if mask == 0 {
        return None;
    }
    // A contiguous mask from bit 0 has the form (1 << n) - 1.
    // Check: mask & (mask + 1) == 0
    if mask & (mask.wrapping_add(1)) == 0 {
        Some(mask.count_ones())
    } else {
        None
    }
}

fn extract_site_at(insns: &[BpfInsn], pc: usize) -> Option<ExtractSite> {
    let i0 = insns.get(pc)?;
    let i1 = insns.get(pc + 1)?;
    extract_site_from_pair(i0, i1, pc)
}

fn extract_site_from_pair(i0: &BpfInsn, i1: &BpfInsn, start_pc: usize) -> Option<ExtractSite> {
    let is_rsh = i0.code == (BPF_ALU64 | BPF_RSH | BPF_K);
    let is_and = i1.code == (BPF_ALU64 | BPF_AND | BPF_K);
    if !is_rsh || !is_and || i0.dst_reg() != i1.dst_reg() {
        return None;
    }
    let shift = i0.imm as u32;
    let mask = i1.imm as i64 as u64;
    let bit_len = contiguous_mask_len(mask)?;
    (shift + bit_len <= 64).then_some(ExtractSite {
        start_pc,
        old_len: 2,
        dst_reg: i0.dst_reg(),
        shift_amount: shift,
        bit_len,
    })
}

impl BpfPass for ExtractPass {
    fn name(&self) -> &str {
        "extract"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx)
    }
}

pub fn run_on_bbprogram(prog: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
    let btf_id = ctx.kinsn_registry.btf_id_for_target_name("bpf_extract64")?;
    let mut safe_sites: Vec<SafeExtractSite> = Vec::new();
    let mut skipped = Vec::new();

    for block in prog.block_ids().collect::<Vec<_>>() {
        let insns = prog.copied_body_insns(block)?;
        for start in prog.sites_in_block(block)? {
            if let Some(skip) = cross_block_extract_skip(prog, start)? {
                skipped.push(skip);
                continue;
            }

            let Some(mut site) = extract_site_at(&insns, start.idx) else {
                continue;
            };
            let start_slot = block_slot_offset(prog, start)?;
            site.start_pc = prog.report_pc(start)?;
            let range = start.idx..start.idx + site.old_len;

            if let Some(reason) =
                prog.kinsn_replacement_subprog_skip_reason(block, start_slot, site.old_len, 2)?
            {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason,
                });
                continue;
            }

            safe_sites.push(SafeExtractSite { block, range, site });
        }
    }

    if safe_sites.is_empty() {
        return Ok(PassResult {
            sites_skipped: skipped,
            ..PassResult::unchanged()
        });
    }

    let kfunc_off = ctx
        .kinsn_registry
        .call_off_for_target_name("bpf_extract64")?;

    for safe_site in safe_sites.iter().rev() {
        let site = &safe_site.site;
        let shift_amount = u8::try_from(site.shift_amount).map_err(|_| {
            anyhow::anyhow!(
                "extract shift amount {} exceeds packed payload width",
                site.shift_amount
            )
        })?;
        let bit_len = u8::try_from(site.bit_len).map_err(|_| {
            anyhow::anyhow!(
                "extract bit length {} exceeds packed payload width",
                site.bit_len
            )
        })?;
        let payload = BpfInsn::pack_u4(site.dst_reg, 0)
            | BpfInsn::pack_u8(shift_amount, 8)
            | BpfInsn::pack_u8(bit_len, 16);
        prog.replace_range(
            safe_site.block,
            safe_site.range.clone(),
            emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off),
        )?;
    }

    Ok(PassResult {
        sites_applied: safe_sites.len(),
        sites_skipped: skipped,
        ..Default::default()
    })
}

fn cross_block_extract_skip(
    prog: &BBProgram,
    start: InsnSite,
) -> anyhow::Result<Option<SkipReason>> {
    let i0 = prog
        .insn_at(start)
        .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", start))?;
    let start_pc = prog.report_pc(start)?;
    let Some(next) = prog.next_site_in_linear_order(start)? else {
        return Ok(None);
    };
    if next.block == start.block {
        return Ok(None);
    }
    let i1 = prog
        .insn_at(next)
        .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", next))?;
    Ok(
        extract_site_from_pair(i0, i1, start_pc).map(|_| SkipReason {
            pc: start_pc,
            reason: "interior branch target".into(),
        }),
    )
}
