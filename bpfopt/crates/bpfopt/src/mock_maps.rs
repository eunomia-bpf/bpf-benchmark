// SPDX-License-Identifier: MIT
//! Thread-local mock map provider for tests.

use std::cell::RefCell;
use std::collections::HashMap;
use std::sync::Arc;

use crate::pass::{BpfProgram, MapMetadata, MapProvider, SnapshotMapProvider};

#[derive(Clone, Debug, Default)]
pub struct BpfMapInfo {
    pub map_type: u32,
    pub key_size: u32,
    pub value_size: u32,
    pub max_entries: u32,
}

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

pub fn install_mock_map(map_id: u32, state: MockMapState) {
    MOCK_MAPS.with(|maps| {
        maps.borrow_mut().insert(map_id, state);
    });
}

#[derive(Clone, Debug, Default)]
pub struct MockMapProvider;

impl MapProvider for MockMapProvider {
    fn map_info(
        &self,
        program: &BpfProgram,
        map_id: u32,
    ) -> std::result::Result<Option<crate::analysis::MapInfo>, String> {
        if let Some(metadata) = program.map_metadata.get(&map_id) {
            return Ok(Some(map_info_from_metadata(metadata)));
        }

        Ok(mock_map_metadata(map_id).map(|metadata| map_info_from_metadata(&metadata)))
    }

    fn lookup_value_size(
        &self,
        program: &BpfProgram,
        info: &crate::analysis::MapInfo,
    ) -> std::result::Result<usize, String> {
        if let Some(value_size) = program
            .map_values
            .iter()
            .find_map(|((map_id, _), value)| (*map_id == info.map_id).then_some(value.len()))
        {
            return Ok(value_size);
        }

        Ok(mock_lookup_value_size(info.map_id).unwrap_or(info.value_size as usize))
    }

    fn lookup_elem(
        &self,
        program: &BpfProgram,
        map_id: u32,
        key: &[u8],
        value_size: usize,
    ) -> std::result::Result<Vec<u8>, String> {
        if let Some(value) = program.map_values.get(&(map_id, key.to_vec())) {
            if value.len() != value_size {
                return Err(format!(
                    "snapshot map {} returned value size {}, expected {}",
                    map_id,
                    value.len(),
                    value_size
                ));
            }
            return Ok(value.clone());
        }
        if program.map_value_nulls.contains(&(map_id, key.to_vec())) {
            return Err(crate::pass::null_map_value_snapshot_message(map_id, key));
        }

        if let Some(result) = mock_lookup_elem(map_id, key, value_size) {
            return result;
        }

        SnapshotMapProvider.lookup_elem(program, map_id, key, value_size)
    }
}

pub fn use_mock_maps(program: &mut BpfProgram) {
    program.set_map_provider(Arc::new(MockMapProvider));
}

fn map_info_from_metadata(metadata: &MapMetadata) -> crate::analysis::MapInfo {
    crate::analysis::MapInfo {
        map_type: metadata.map_type,
        key_size: metadata.key_size,
        value_size: metadata.value_size,
        max_entries: metadata.max_entries,
        frozen: metadata.frozen,
        map_id: metadata.map_id,
    }
}

fn mock_map_metadata(map_id: u32) -> Option<MapMetadata> {
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

fn mock_lookup_value_size(map_id: u32) -> Option<usize> {
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

fn mock_lookup_elem(map_id: u32, key: &[u8], value_size: usize) -> Option<Result<Vec<u8>, String>> {
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
