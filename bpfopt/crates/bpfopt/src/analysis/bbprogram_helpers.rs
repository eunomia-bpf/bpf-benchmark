// SPDX-License-Identifier: MIT
//! Shared BBProgram and pass helpers used by production passes.

use std::fs;
use std::path::Path;

use anyhow::{Context, Result};
use serde::de::DeserializeOwned;

use crate::analysis::bbprogram_use_def::insn_use_def_set;
use crate::analysis::{BBProgram, InsnSite, Terminator};
use crate::insn::*;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(crate) struct PacketCtxLayout {
    pub data_off: i16,
    pub data_end_off: i16,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(crate) enum PacketCtxLayoutScope {
    SkbHelper,
    PacketAccess,
}

pub(crate) fn program_sites(prog: &BBProgram) -> anyhow::Result<Vec<InsnSite>> {
    let mut sites = Vec::new();
    for block in prog.block_ids().collect::<Vec<_>>() {
        sites.extend(prog.sites_in_block_with_terminator(block)?);
    }
    Ok(sites)
}

pub(crate) fn control_flow_target_sites(
    prog: &BBProgram,
) -> anyhow::Result<std::collections::BTreeSet<InsnSite>> {
    let mut targets = std::collections::BTreeSet::new();
    for block in prog.blocks() {
        let target = match prog.terminator(block.id)? {
            Terminator::Jump { target, .. } => Some(target),
            Terminator::CondBranch { taken, .. } => Some(taken),
            Terminator::Call { callee, .. } => Some(callee),
            Terminator::Fallthrough { .. } | Terminator::Exit { .. } | Terminator::End => None,
        };
        if let Some(target) = target {
            if let Some(site) = prog.first_site_in_block(target)? {
                targets.insert(site);
            }
        }
    }
    for &target in prog.pc_relative_ldimm64_targets.values() {
        if let Some(site) = prog.first_site_in_block(target)? {
            targets.insert(site);
        }
    }
    Ok(targets)
}

pub(crate) fn packet_ctx_layout(
    prog_type: u32,
    scope: PacketCtxLayoutScope,
) -> Option<PacketCtxLayout> {
    match (scope, prog_type) {
        (PacketCtxLayoutScope::PacketAccess, libbpf_sys::BPF_PROG_TYPE_XDP) => {
            Some(PacketCtxLayout {
                data_off: XDP_PACKET_DATA_OFFSET,
                data_end_off: XDP_PACKET_DATA_END_OFFSET,
            })
        }
        (
            PacketCtxLayoutScope::PacketAccess,
            libbpf_sys::BPF_PROG_TYPE_SCHED_CLS
            | libbpf_sys::BPF_PROG_TYPE_SCHED_ACT
            | libbpf_sys::BPF_PROG_TYPE_SK_SKB
            | libbpf_sys::BPF_PROG_TYPE_LWT_IN
            | libbpf_sys::BPF_PROG_TYPE_LWT_OUT
            | libbpf_sys::BPF_PROG_TYPE_LWT_XMIT,
        )
        | (
            PacketCtxLayoutScope::SkbHelper,
            libbpf_sys::BPF_PROG_TYPE_SCHED_CLS | libbpf_sys::BPF_PROG_TYPE_SCHED_ACT,
        ) => Some(PacketCtxLayout {
            data_off: SKB_PACKET_DATA_OFFSET,
            data_end_off: SKB_PACKET_DATA_END_OFFSET,
        }),
        _ => None,
    }
}

pub(crate) fn read_json_file<T: DeserializeOwned>(path: &Path, label: &str) -> Result<T> {
    let data = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
    serde_json::from_slice(&data)
        .with_context(|| format!("failed to parse {label} from {}", path.display()))
}

pub(crate) trait SimpleRegValue: Copy {
    fn unknown() -> Self;
    fn const64(value: i64) -> Self;
    fn const32(value: u32) -> Self;
    fn mov32(value: Self) -> Self;
    fn xor_self() -> Self {
        Self::unknown()
    }
    fn alu64_imm(value: Self, op: u8, imm: i32) -> Self;
    fn alu32_add_sub(value: Self, imm: i32, is_add: bool) -> Self;
}

pub(crate) fn advance_reg_state<V: SimpleRegValue>(
    insn: &BpfInsn,
    ldimm64_hi: Option<&BpfInsn>,
    regs: &mut [V; 11],
) -> anyhow::Result<()> {
    if insn.is_call() {
        for reg in insn_use_def_set(insn).defs {
            regs[reg as usize] = V::unknown();
        }
        return Ok(());
    }

    if insn.is_ldimm64() {
        let hi =
            ldimm64_hi.ok_or_else(|| anyhow::anyhow!("LD_IMM64 is missing its second slot"))?;
        regs[insn.dst_reg() as usize] = V::const64(decode_ldimm64_value(insn, hi) as i64);
        return Ok(());
    }

    match insn.class() {
        BPF_ALU64 => advance_alu64_state(insn, regs),
        BPF_ALU => advance_alu32_state(insn, regs),
        BPF_LDX | BPF_LD => regs[insn.dst_reg() as usize] = V::unknown(),
        _ => {}
    }
    Ok(())
}

fn advance_alu64_state<V: SimpleRegValue>(insn: &BpfInsn, regs: &mut [V; 11]) {
    let dst = insn.dst_reg() as usize;
    let next = match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_K) => V::const64(insn.imm as i64),
        (BPF_MOV, BPF_X) => regs[insn.src_reg() as usize],
        (BPF_ADD | BPF_SUB, BPF_K) => V::alu64_imm(regs[dst], bpf_op(insn.code), insn.imm),
        (BPF_XOR, BPF_X) if insn.dst_reg() == insn.src_reg() => V::xor_self(),
        _ => V::unknown(),
    };
    regs[dst] = next;
}

fn advance_alu32_state<V: SimpleRegValue>(insn: &BpfInsn, regs: &mut [V; 11]) {
    let dst = insn.dst_reg() as usize;
    let next = match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_K) => V::const32(insn.imm as u32),
        (BPF_MOV, BPF_X) => V::mov32(regs[insn.src_reg() as usize]),
        (BPF_ADD, BPF_K) => V::alu32_add_sub(regs[dst], insn.imm, true),
        (BPF_SUB, BPF_K) => V::alu32_add_sub(regs[dst], insn.imm, false),
        (BPF_XOR, BPF_X) if insn.dst_reg() == insn.src_reg() => V::xor_self(),
        _ => V::unknown(),
    };
    regs[dst] = next;
}
