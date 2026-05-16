// SPDX-License-Identifier: MIT
use crate::analysis::{InsnSite, ProgramCFG};
use crate::insn::*;
use crate::pass::*;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        name: "bpf_x86_shrq",
        register_uses: x86_alu_register_uses,
        register_defs: x86_alu_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_x86_andl",
        register_uses: x86_alu_register_uses,
        register_defs: x86_alu_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_arm64_ubfm_x",
        register_uses: extract_register_uses,
        register_defs: extract_register_defs,
    },
];
fn extract_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0])
}
fn extract_register_defs(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0])
}
fn x86_alu_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[4])
}
fn x86_alu_register_defs(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[4])
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
    fn run(&self, prog: &mut ProgramCFG, _ctx: &PassContext) -> anyhow::Result<PassResult> {
        let mut skipped = collect_cross_block_pair_skips(
            prog,
            |i0, i1| extract_site_from_pair(i0, i1).is_some(),
            "interior branch target",
        )?;
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
                Ok((2, emit_extract_replacement(prog, _ctx.arch, site)?))
            })?;
        Ok(PassResult::with_sites(applied, skipped))
    }
}

fn emit_extract_replacement(
    prog: &ProgramCFG,
    arch: Arch,
    site: &ExtractSite,
) -> anyhow::Result<Vec<BpfInsn>> {
    match arch {
        Arch::X86_64 => {
            let mut out = Vec::new();
            out.extend_from_slice(&prog.kinsn_emit(
                "bpf_x86_shrq",
                x86_alu_imm_payload(site.dst_reg, site.shift_amount),
            )?);
            if site.bit_len == 64 {
                return Ok(out);
            }
            let mask = if site.bit_len == 32 {
                u32::MAX
            } else {
                (1u32 << site.bit_len) - 1
            };
            out.extend_from_slice(
                &prog.kinsn_emit("bpf_x86_andl", x86_alu_imm_payload(site.dst_reg, mask))?,
            );
            Ok(out)
        }
        Arch::Aarch64 => {
            let payload = BpfInsn::pack_u4(site.dst_reg, 0)
                | BpfInsn::pack_u8(site.shift_amount as u8, 8)
                | BpfInsn::pack_u8(site.bit_len as u8, 16);
            prog.kinsn_emit("bpf_arm64_ubfm_x", payload)
        }
    }
}

fn x86_alu_imm_payload(dst_reg: u8, imm: u32) -> u64 {
    BpfInsn::pack_u4(2, 0) | BpfInsn::pack_u4(dst_reg, 4) | BpfInsn::pack_u32(imm, 12)
}
