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

/// Install a mock map into the thread-local store.
pub fn install_mock_map(map_id: u32, state: MockMapState) {
    MOCK_MAPS.with(|maps| {
        maps.borrow_mut().insert(map_id, state);
    });
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
