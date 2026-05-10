// SPDX-License-Identifier: MIT

use std::collections::HashMap;

use crate::bpf::{install_mock_map, BpfMapInfo, MockMapState};
use crate::insn::BpfInsn;
use crate::pass::{
    BpfProgram, RegState, ScalarRange, StackState, Tnum, VerifierInsn, VerifierInsnKind,
    VerifierValueWidth,
};

pub fn scalar_reg(value: u64) -> RegState {
    let mut reg = RegState::new("scalar", VerifierValueWidth::Bits64);
    reg.precise = true;
    reg.exact_value = Some(value);
    reg.tnum = Some(Tnum { value, mask: 0 });
    reg.range = ScalarRange {
        smin: Some(value as i64),
        smax: Some(value as i64),
        umin: Some(value),
        umax: Some(value),
        smin32: Some(value as u32 as i32),
        smax32: Some(value as u32 as i32),
        umin32: Some(value as u32),
        umax32: Some(value as u32),
    };
    reg
}

pub fn fp_reg(offset: i32) -> RegState {
    let mut reg = RegState::new("fp", VerifierValueWidth::Bits64);
    reg.offset = Some(offset);
    reg
}

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
    install_map(map_id, libbpf_sys::BPF_MAP_TYPE_ARRAY, 8, values);
}

pub fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
    BpfProgram::new(insns)
}
