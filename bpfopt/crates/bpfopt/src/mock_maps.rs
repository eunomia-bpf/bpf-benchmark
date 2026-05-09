// SPDX-License-Identifier: MIT
//! Thread-local mock map provider for tests.

use std::cell::RefCell;
use std::collections::HashMap;
use std::sync::Arc;

use crate::pass::{BpfProgram, MapLookupError, MapMetadata, MapProvider, SnapshotMapProvider};

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
    pub values: HashMap<Vec<u8>, Vec<u8>>,
}

thread_local! {
    static MOCK_MAPS: RefCell<HashMap<u32, MockMapState>> = RefCell::new(HashMap::new());
}

const BPF_MAP_TYPE_PERCPU_ARRAY: u32 = libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY;

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
    ) -> std::result::Result<Option<crate::passes::MapInfo>, String> {
        if let Some(metadata) = program.map_metadata.get(&map_id) {
            return Ok(Some(map_info_from_metadata(metadata)));
        }

        Ok(mock_map_metadata(map_id).map(|metadata| map_info_from_metadata(&metadata)))
    }

    fn lookup_value_size(
        &self,
        program: &BpfProgram,
        info: &crate::passes::MapInfo,
    ) -> std::result::Result<usize, String> {
        if let Some(overlay) = program.map_value_overlays.get(&info.map_id) {
            return Ok(overlay.value_size);
        }
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
    ) -> std::result::Result<Vec<u8>, MapLookupError> {
        if let Some(overlay) = program.map_value_overlays.get(&map_id) {
            return match overlay.lookup(key) {
                Some(value) => {
                    if value.len() != value_size {
                        Err(MapLookupError::Failed(format!(
                            "compressed map {} returned value size {}, expected {}",
                            map_id,
                            value.len(),
                            value_size
                        )))
                    } else {
                        Ok(value)
                    }
                }
                None => Err(MapLookupError::MissingKey {
                    map_id,
                    key: key.to_vec(),
                }),
            };
        }
        if program.map_snapshots_skipped_by_size.contains(&map_id) {
            return Err(MapLookupError::SkippedBySize { map_id });
        }
        if let Some(value) = program.map_values.get(&(map_id, key.to_vec())) {
            if value.len() != value_size {
                return Err(MapLookupError::Failed(format!(
                    "snapshot map {} returned value size {}, expected {}",
                    map_id,
                    value.len(),
                    value_size
                )));
            }
            return Ok(value.clone());
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

fn map_info_from_metadata(metadata: &MapMetadata) -> crate::passes::MapInfo {
    crate::passes::MapInfo {
        map_type: metadata.map_type,
        key_size: metadata.key_size,
        value_size: metadata.value_size,
        max_entries: metadata.max_entries,
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
            map_id,
            name: String::new(),
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

fn mock_lookup_elem(
    map_id: u32,
    key: &[u8],
    value_size: usize,
) -> Option<Result<Vec<u8>, MapLookupError>> {
    MOCK_MAPS.with(|maps| {
        let maps = maps.borrow();
        let state = maps.get(&map_id)?;
        if let Some(value) = state.values.get(key) {
            if value.len() != value_size {
                return Some(Err(MapLookupError::Failed(format!(
                    "mock map {} returned value size {}, expected {}",
                    map_id,
                    value.len(),
                    value_size
                ))));
            }
            return Some(Ok(value.clone()));
        }

        Some(Err(MapLookupError::MissingKey {
            map_id,
            key: key.to_vec(),
        }))
    })
}

fn round_up_8(value: usize) -> usize {
    (value + 7) & !7
}
