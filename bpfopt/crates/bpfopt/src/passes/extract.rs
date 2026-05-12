// SPDX-License-Identifier: MIT
use crate::analysis::{BBProgram, InsnSite, MakeReplacement, Terminator};
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
    pub(super) dst_reg: u8,
    pub(super) shift_amount: u32,
    pub(super) bit_len: u32,
}
pub(super) fn contiguous_mask_len(mask: u64) -> Option<u32> {
    (mask != 0 && mask & mask.wrapping_add(1) == 0).then_some(mask.count_ones())
}
fn extract_site_from_pair(i0: &BpfInsn, i1: &BpfInsn) -> Option<ExtractSite> {
    if !i0.is_alu_imm(BPF_ALU64, BPF_RSH)
        || !i1.is_alu_imm(BPF_ALU64, BPF_AND)
        || i0.dst_reg() != i1.dst_reg()
    {
        return None;
    }
    let shift = u32::try_from(i0.imm).ok()?;
    let mask = i1.imm as i64 as u64;
    let bit_len = contiguous_mask_len(mask)?;
    shift
        .checked_add(bit_len)
        .is_some_and(|end| end <= 64)
        .then_some(ExtractSite {
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
pub fn run_on_bbprogram(prog: &mut BBProgram, _ctx: &PassContext) -> anyhow::Result<PassResult> {
    let mut skipped = Vec::new();
    for block in prog.block_ids().collect::<Vec<_>>() {
        for start in prog.sites_in_block(block)? {
            if let Some(skip) = cross_block_extract_skip(prog, start)? {
                skipped.push(skip);
            };
        }
    }
    let raw_sites = prog.scan_block_starts(2, |window| {
        if window.lookahead.len() < 2 {
            return Ok(None);
        }
        Ok(
            extract_site_from_pair(&window.lookahead[0], &window.lookahead[1])
                .map(|site| window.hit(window.start_idx, 2, site)),
        )
    })?;
    if raw_sites.is_empty() {
        return Ok(PassResult {
            site_skipped: skipped,
            ..PassResult::unchanged()
        });
    }
    let mut applied = 0usize;
    for hit in raw_sites.iter().rev() {
        let site = &hit.value;
        let (btf_id, kfunc_off) = prog.kinsn_call("bpf_extract64")?;
        let payload = BpfInsn::pack_u4(site.dst_reg, 0)
            | BpfInsn::pack_u8(site.shift_amount as u8, 8)
            | BpfInsn::pack_u8(site.bit_len as u8, 16);
        if prog.try_replace_range_with_skips(hit.start, 2, 2, &mut skipped, || {
            Ok(MakeReplacement::Use(emit_packed_kinsn_call_with_off(
                payload, btf_id, kfunc_off,
            )))
        })? {
            applied += 1;
        }
    }
    Ok(PassResult {
        sites_applied: applied,
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
    let body = prog.block_body_view(prog.site_block(start))?;
    if start.idx + 1 < body.sites.len() {
        return Ok(None);
    }
    let start_block = prog.site_block(start);
    let next_block = match prog.terminator_at_site(start)? {
        Terminator::Fallthrough { next } => next,
        _ => return Ok(None),
    };
    let successors = prog.successors(start_block);
    if successors.len() != 1 || successors[0] != next_block {
        anyhow::bail!(
            "fallthrough block {:?} has inconsistent successors",
            start_block
        );
    }
    let Some(next) = prog.sites_in_block(next_block)?.first().copied() else {
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
