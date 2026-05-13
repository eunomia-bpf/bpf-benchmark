// SPDX-License-Identifier: MIT
use crate::analysis::{InsnSite, ProgramCFG};
use crate::insn::*;
use crate::pass::*;

pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        name: "bpf_lea64",
        register_uses: lea_register_uses,
    },
    KinsnDescriptor {
        name: "bpf_lea32",
        register_uses: lea_register_uses,
    },
];

fn lea_register_uses(payload: u64) -> RegSet {
    let mut regs = RegSet::new();
    if lea_payload_has_base(payload) {
        regs.insert(kinsn_payload_reg(payload, 4));
    }
    if lea_payload_has_index(payload) {
        regs.insert(kinsn_payload_reg(payload, 8));
    }
    regs
}

pub struct LeaPass;

#[derive(Clone, Copy)]
struct LeaSite {
    old_len: usize,
    dst_reg: u8,
    base_reg: u8,
    index_reg: Option<u8>,
    disp: i32,
    width: LeaWidth,
}

#[repr(u8)]
#[derive(Clone, Copy, PartialEq, Eq)]
enum LeaWidth {
    W32 = BPF_ALU,
    W64 = BPF_ALU64,
}

impl LeaWidth {
    const MATCH_ORDER: [Self; 2] = [Self::W64, Self::W32];

    fn alu_class(self) -> u8 {
        self as u8
    }

    fn target_name(self) -> &'static str {
        match self {
            Self::W32 => "bpf_lea32",
            Self::W64 => "bpf_lea64",
        }
    }
}

impl BpfPass for LeaPass {
    fn run(&self, prog: &mut ProgramCFG, _ctx: &PassContext) -> anyhow::Result<PassResult> {
        let mut skipped = collect_cross_block_pair_skips(
            prog,
            |i0, i1| lea_site_from_pair(i0, i1).is_some(),
            "interior branch target",
        )?;
        let candidates: Vec<(InsnSite, LeaSite)> = prog
            .scan_block_starts(2, |window| {
                if window.lookahead.len() < 2 {
                    return Ok(None);
                }
                Ok(
                    lea_site_from_pair(&window.lookahead[0], &window.lookahead[1])
                        .map(|site| (window.start_idx, site.old_len, site)),
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
                let (btf_id, kfunc_off) = prog.kinsn_call(site.width.target_name())?;
                let payload = lea_payload(site);
                Ok((
                    site.old_len,
                    emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off),
                ))
            })?;

        Ok(PassResult::with_sites(applied, skipped))
    }
}

fn lea_site_from_pair(i0: &BpfInsn, i1: &BpfInsn) -> Option<LeaSite> {
    LeaWidth::MATCH_ORDER
        .into_iter()
        .find_map(|width| lea_site_from_pair_width(i0, i1, width))
}

fn lea_site_from_pair_width(i0: &BpfInsn, i1: &BpfInsn, width: LeaWidth) -> Option<LeaSite> {
    if !i0.is_alu_reg(width.alu_class(), BPF_MOV)
        || i0.dst_reg() > BPF_REG_10
        || i0.src_reg() > BPF_REG_10
        || i1.dst_reg() != i0.dst_reg()
    {
        return None;
    }

    if i1.is_alu_imm(width.alu_class(), BPF_ADD) {
        return (i1.imm != 0).then_some(LeaSite {
            old_len: 2,
            dst_reg: i0.dst_reg(),
            base_reg: i0.src_reg(),
            index_reg: None,
            disp: i1.imm,
            width,
        });
    }

    if !i1.is_alu_reg(width.alu_class(), BPF_ADD)
        || i1.src_reg() > BPF_REG_10
        || i1.src_reg() == i1.dst_reg()
    {
        return None;
    }

    Some(LeaSite {
        old_len: 2,
        dst_reg: i0.dst_reg(),
        base_reg: i0.src_reg(),
        index_reg: Some(i1.src_reg()),
        disp: 0,
        width,
    })
}

fn lea_payload(site: &LeaSite) -> u64 {
    BpfInsn::pack_u4(site.dst_reg, 0)
        | BpfInsn::pack_u4(site.base_reg, 4)
        | BpfInsn::pack_u4(site.index_reg.unwrap_or(0), 8)
        | ((site.index_reg.is_some() as u64) << 14)
        | (1 << 15)
        | BpfInsn::pack_u32(site.disp as u32, 16)
}

fn lea_payload_has_index(payload: u64) -> bool {
    ((payload >> 14) & 1) != 0
}

fn lea_payload_has_base(payload: u64) -> bool {
    ((payload >> 15) & 1) != 0
}
