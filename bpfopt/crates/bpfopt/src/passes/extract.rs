// SPDX-License-Identifier: MIT
use crate::analysis::{BBProgram, InsnSite, Terminator};
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
pub struct ExtractPass;
pub(super) struct ExtractSite {
    pub(super) old_len: usize,
    pub(super) dst_reg: u8,
    pub(super) shift_amount: u32,
    pub(super) bit_len: u32,
}
pub(super) fn contiguous_mask_len(mask: u64) -> Option<u32> {
    if mask == 0 {
        return None;
    }
    if mask & (mask.wrapping_add(1)) == 0 {
        Some(mask.count_ones())
    } else {
        None
    }
}
fn extract_site_from_pair(i0: &BpfInsn, i1: &BpfInsn) -> Option<ExtractSite> {
    let is_rsh = i0.code == (BPF_ALU64 | BPF_RSH | BPF_K);
    let is_and = i1.code == (BPF_ALU64 | BPF_AND | BPF_K);
    if !is_rsh || !is_and || i0.dst_reg() != i1.dst_reg() {
        return None;
    }
    let shift = i0.imm as u32;
    let mask = i1.imm as i64 as u64;
    let bit_len = contiguous_mask_len(mask)?;
    (shift + bit_len <= 64).then_some(ExtractSite {
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
    let mut safe_sites = Vec::new();
    let mut skipped = Vec::new();
    for block in prog.block_ids().collect::<Vec<_>>() {
        for start in prog.sites_in_block(block)? {
            if let Some(skip) = cross_block_extract_skip(prog, start)? {
                skipped.push(skip);
            };
        }
        for [start, next] in prog.adjacent_windows_in_block::<2>(block) {
            let i0 = prog
                .insn_at(start)
                .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", start))?;
            let i1 = prog
                .insn_at(next)
                .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", next))?;
            let Some(site) = extract_site_from_pair(i0, i1) else {
                continue;
            };
            let Some((admission_block, admission_range)) =
                prog.rep_admit_kinsn_site_window(start, site.old_len, 2, &mut skipped)?
            else {
                continue;
            };
            safe_sites.push((admission_block, admission_range, site));
        }
    }
    if safe_sites.is_empty() {
        return Ok(PassResult {
            site_skipped: skipped,
            ..PassResult::unchanged()
        });
    }
    let kfunc_off = ctx
        .kinsn_registry
        .call_off_for_target_name("bpf_extract64")?;
    for (block, range, site) in safe_sites.iter().rev() {
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
            *block,
            range.clone(),
            emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off),
        )?;
    }
    Ok(PassResult {
        sites_applied: safe_sites.len(),
        site_skipped: skipped,
        ..Default::default()
    })
}
fn cross_block_extract_skip(
    prog: &BBProgram,
    start: InsnSite,
) -> anyhow::Result<Option<SiteSkipReason>> {
    let i0 = prog
        .insn_at(start)
        .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", start))?;
    if prog.next_site_in_block(start).is_some() {
        return Ok(None);
    }
    let next_block = match prog.terminator(start.block)? {
        Terminator::Fallthrough { next } => next,
        _ => return Ok(None),
    };
    let successors = prog.successors(start.block);
    if successors.len() != 1 || successors[0] != next_block {
        anyhow::bail!(
            "fallthrough block {:?} has inconsistent successors",
            start.block
        );
    }
    let Some(next) = prog.block_first_body_site(next_block) else {
        return Ok(None);
    };
    let i1 = prog
        .insn_at(next)
        .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", next))?;
    Ok(extract_site_from_pair(i0, i1).map(|_| SiteSkipReason {
        site: start,
        reason: "interior branch target".into(),
    }))
}
