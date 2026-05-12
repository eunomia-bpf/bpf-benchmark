// SPDX-License-Identifier: MIT
use crate::analysis::{BBProgram, InsnSite};
use crate::insn::*;
use crate::pass::*;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[KinsnDescriptor {
    canonical_name: "bpf_extract64",
    aliases: &["extract64"],
    proof_len: extract_proof_len,
    register_uses: extract_register_uses,
}];
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
    regs_from_offsets(payload, &[0])
}
pub struct ExtractPass;
pub(super) struct ExtractSite {
    pub(super) dst_reg: u8,
    pub(super) shift_amount: u32,
    pub(super) bit_len: u32,
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
    if mask == 0 || mask & mask.wrapping_add(1) != 0 {
        return None;
    }
    let bit_len = mask.count_ones();
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
            if let Some(skip) = check_cross_block_pair_pattern(
                prog,
                start,
                |i0, i1| extract_site_from_pair(i0, i1).is_some(),
                "interior branch target",
            )? {
                skipped.push(skip);
            };
        }
    }
    let candidates: Vec<(InsnSite, ExtractSite)> = prog
        .scan_block_starts(2, |window| {
            if window.lookahead.len() < 2 {
                return Ok(None);
            }
            Ok(
                extract_site_from_pair(&window.lookahead[0], &window.lookahead[1])
                    .map(|site| (window.start_idx, 2, site)),
            )
        })?
        .into_iter()
        .map(|hit| (hit.start, hit.value))
        .collect();
    if candidates.is_empty() {
        return Ok(PassResult::with_sites(0, skipped));
    }
    let applied =
        apply_candidates_reverse(prog, &candidates, &mut skipped, |prog, _start, site| {
            let (btf_id, kfunc_off) = prog.kinsn_call("bpf_extract64")?;
            let payload = BpfInsn::pack_u4(site.dst_reg, 0)
                | BpfInsn::pack_u8(site.shift_amount as u8, 8)
                | BpfInsn::pack_u8(site.bit_len as u8, 16);
            Ok((
                2,
                emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off),
            ))
        })?;
    Ok(PassResult::with_sites(applied, skipped))
}
