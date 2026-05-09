// SPDX-License-Identifier: MIT
//! Shared test helper functions for pass unit tests.
//!
//! This module is `#[cfg(test)]` only. Import with:
//! `use crate::test_helpers::*;`

use crate::insn::*;
use crate::pass::{
    BpfProgram, RegState, ScalarRange, StackState, Tnum, VerifierInsn, VerifierInsnKind,
    VerifierValueWidth,
};
use std::collections::HashMap;

use crate::bpf::{install_mock_map, BpfMapInfo, MockMapState};

// BPF instruction constructors

/// Return a BPF EXIT instruction.
pub fn exit_insn() -> BpfInsn {
    BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
}

/// Return a BPF helper-call instruction (src_reg = 0).
pub fn call_helper(imm: i32) -> BpfInsn {
    BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, imm)
}

/// Return a BPF_PSEUDO_CALL instruction whose offset encodes
/// `target_pc - (call_pc + 1)`.
pub fn pseudo_call_to(call_pc: usize, target_pc: usize) -> BpfInsn {
    let imm = target_pc as i64 - (call_pc as i64 + 1);
    BpfInsn::new(
        BPF_JMP | BPF_CALL,
        BpfInsn::make_regs(0, BPF_PSEUDO_CALL),
        0,
        imm as i32,
    )
}

pub fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP | BPF_JEQ | BPF_K,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

pub fn jne_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP | BPF_JNE | BPF_K,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

pub fn jgt_reg(dst: u8, src: u8, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP | BPF_JGT | BPF_X,
        BpfInsn::make_regs(dst, src),
        off,
        0,
    )
}

pub fn ld_imm64(dst: u8, src: u8, imm: i64) -> [BpfInsn; 2] {
    [
        BpfInsn::new(
            BPF_LD | BPF_DW | BPF_IMM,
            BpfInsn::make_regs(dst, src),
            0,
            imm as i32,
        ),
        BpfInsn::new(0, 0, 0, (imm >> 32) as i32),
    ]
}

pub fn mov32_reg(dst: u8, src: u8) -> BpfInsn {
    BpfInsn::new(
        BPF_ALU | BPF_MOV | BPF_X,
        BpfInsn::make_regs(dst, src),
        0,
        0,
    )
}

pub fn add64_imm(dst: u8, imm: i32) -> BpfInsn {
    BpfInsn::new(
        BPF_ALU64 | BPF_ADD | BPF_K,
        BpfInsn::make_regs(dst, 0),
        0,
        imm,
    )
}

pub fn st_mem(size: u8, dst: u8, off: i16, imm: i32) -> BpfInsn {
    BpfInsn::new(
        BPF_ST | size | BPF_MEM,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

pub fn scalar_reg(value: u64) -> RegState {
    RegState {
        reg_type: "scalar".to_string(),
        value_width: VerifierValueWidth::Bits64,
        precise: true,
        exact_value: Some(value),
        tnum: Some(Tnum { value, mask: 0 }),
        range: ScalarRange {
            smin: Some(value as i64),
            smax: Some(value as i64),
            umin: Some(value),
            umax: Some(value),
            smin32: Some(value as u32 as i32),
            smax32: Some(value as u32 as i32),
            umin32: Some(value as u32),
            umax32: Some(value as u32),
        },
        offset: None,
        id: None,
    }
}

pub fn fp_reg(offset: i32) -> RegState {
    RegState {
        reg_type: "fp".to_string(),
        value_width: VerifierValueWidth::Bits64,
        precise: false,
        exact_value: None,
        tnum: None,
        range: ScalarRange::default(),
        offset: Some(offset),
        id: None,
    }
}

// Verifier state constructors

pub fn verifier_delta_state(pc: usize, regs: HashMap<u8, RegState>) -> VerifierInsn {
    verifier_delta_state_with_stack(pc, regs, HashMap::new())
}

pub fn verifier_delta_state_with_stack(
    pc: usize,
    regs: HashMap<u8, RegState>,
    stack: HashMap<i16, StackState>,
) -> VerifierInsn {
    VerifierInsn {
        pc,
        frame: 0,
        from_pc: None,
        kind: VerifierInsnKind::InsnDeltaState,
        speculative: false,
        regs,
        stack,
    }
}

pub fn stack_snapshot_from_key(stack_off: i16, key: &[u8]) -> HashMap<i16, StackState> {
    let mut slots = HashMap::<i16, ([u8; 8], [u8; 8])>::new();
    for (idx, byte) in key.iter().enumerate() {
        let absolute_off = i32::from(stack_off) + idx as i32;
        let slot_index = ((-absolute_off - 1) / 8) + 1;
        let slot_start_i32 = -slot_index * 8;
        let slot_start = i16::try_from(slot_start_i32).unwrap();
        let byte_index = usize::try_from(absolute_off - slot_start_i32).unwrap();
        let type_index = 7 - byte_index;
        let entry = slots.entry(slot_start).or_insert(([0u8; 8], [b'?'; 8]));
        entry.0[byte_index] = *byte;
        entry.1[type_index] = b'r';
    }

    slots
        .into_iter()
        .map(|(off, (bytes, types))| {
            (
                off,
                StackState {
                    slot_types: Some(String::from_utf8(types.to_vec()).unwrap()),
                    value: Some(scalar_reg(u64::from_le_bytes(bytes))),
                },
            )
        })
        .collect()
}

// Map fixtures

pub fn install_map(
    map_id: u32,
    map_type: u32,
    max_entries: u32,
    values: HashMap<Vec<u8>, Vec<u8>>,
) {
    let info = BpfMapInfo {
        map_type,
        key_size: 4,
        value_size: values.values().next().map(|value| value.len()).unwrap_or(0) as u32,
        max_entries,
    };

    install_mock_map(map_id, MockMapState { info, values });
}

pub fn install_array_map(map_id: u32, value: Vec<u8>) {
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), value);
    install_map(map_id, kernel_sys::BPF_MAP_TYPE_ARRAY, 8, values);
}

// Program fixtures

pub fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
    BpfProgram::new(insns)
}

// Sidecar/kinsn helpers

pub fn sidecar_payload(insn: &BpfInsn) -> u64 {
    (u64::from(insn.dst_reg()) & 0xf)
        | (u64::from(insn.off as u16) << 4)
        | (u64::from(insn.imm as u32) << 20)
}
