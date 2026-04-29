// SPDX-License-Identifier: MIT
//! Thread-local mock map facility for tests.
//!
//! Provides the same `install_mock_map` / `BpfMapInfo` / `MockMapState` API
//! that daemon/src/bpf.rs had, but stores data in a thread-local instead of
//! doing real BPF syscalls. Tests call `apply_mock_maps(&mut program)` to
//! flush the mock data onto BpfProgram fields before running passes.

use std::cell::RefCell;
use std::collections::HashMap;

use crate::pass::{BpfProgram, MapMetadata};

/// Mirror of the old `bpf::BpfMapInfo` struct — just enough fields for tests.
#[derive(Clone, Debug, Default)]
pub struct BpfMapInfo {
    pub id: u32,
    pub map_type: u32,
    pub key_size: u32,
    pub value_size: u32,
    pub max_entries: u32,
    pub map_flags: u32,
}

/// Mirror of the old `bpf::MockMapState`.
#[derive(Clone, Debug)]
pub struct MockMapState {
    pub info: BpfMapInfo,
    pub frozen: bool,
    pub values: HashMap<Vec<u8>, Vec<u8>>,
}

thread_local! {
    static MOCK_MAPS: RefCell<HashMap<u32, MockMapState>> = RefCell::new(HashMap::new());
}

const BPF_MAP_TYPE_PERCPU_ARRAY: u32 = kernel_sys::BPF_MAP_TYPE_PERCPU_ARRAY;

/// Install a mock map into the thread-local store.
pub fn install_mock_map(map_id: u32, state: MockMapState) {
    MOCK_MAPS.with(|maps| {
        maps.borrow_mut().insert(map_id, state);
    });
}

pub fn mock_map_metadata(map_id: u32) -> Option<MapMetadata> {
    MOCK_MAPS.with(|maps| {
        maps.borrow().get(&map_id).map(|state| MapMetadata {
            map_type: state.info.map_type,
            key_size: state.info.key_size,
            value_size: state.info.value_size,
            max_entries: state.info.max_entries,
            frozen: state.frozen,
            map_id,
        })
    })
}

pub fn mock_lookup_value_size(map_id: u32) -> Option<usize> {
    MOCK_MAPS.with(|maps| {
        let maps = maps.borrow();
        let state = maps.get(&map_id)?;
        state.values.values().next().map(Vec::len).or_else(|| {
            if state.info.map_type == BPF_MAP_TYPE_PERCPU_ARRAY {
                Some(round_up_8(state.info.value_size as usize))
            } else {
                Some(state.info.value_size as usize)
            }
        })
    })
}

pub fn mock_lookup_elem(
    map_id: u32,
    key: &[u8],
    value_size: usize,
) -> Option<Result<Vec<u8>, String>> {
    MOCK_MAPS.with(|maps| {
        let maps = maps.borrow();
        let state = maps.get(&map_id)?;
        if let Some(value) = state.values.get(key) {
            if value.len() != value_size {
                return Some(Err(format!(
                    "mock map {} returned value size {}, expected {}",
                    map_id,
                    value.len(),
                    value_size
                )));
            }
            return Some(Ok(value.clone()));
        }

        Some(Err(crate::pass::missing_map_value_snapshot_message(
            map_id, key,
        )))
    })
}

fn round_up_8(value: usize) -> usize {
    (value + 7) & !7
}

/// Flush all thread-local mock maps onto the given program's `map_metadata`
/// and `map_values` fields, then clear the thread-local store.
pub fn apply_mock_maps(program: &mut BpfProgram) {
    MOCK_MAPS.with(|maps| {
        let mut maps = maps.borrow_mut();
        for (map_id, state) in maps.drain() {
            program.map_metadata.insert(
                map_id,
                MapMetadata {
                    map_type: state.info.map_type,
                    key_size: state.info.key_size,
                    value_size: state.info.value_size,
                    max_entries: state.info.max_entries,
                    frozen: state.frozen,
                    map_id,
                },
            );
            for (key, value) in state.values {
                program.map_values.insert((map_id, key), value);
            }
        }
    });
}
