use std::collections::HashMap;
use std::sync::{Mutex, OnceLock};

use anyhow::{anyhow, bail, Result};

#[derive(Clone, Debug, Default)]
pub struct BpfMapInfo {
    pub id: u32,
    pub map_type: u32,
    pub key_size: u32,
    pub value_size: u32,
    pub max_entries: u32,
    pub map_flags: u32,
}

#[derive(Clone, Debug, Default)]
pub struct MockMapState {
    pub info: BpfMapInfo,
    pub frozen: bool,
    pub values: HashMap<Vec<u8>, Vec<u8>>,
}

fn mock_maps() -> &'static Mutex<HashMap<u32, MockMapState>> {
    static MOCK_MAPS: OnceLock<Mutex<HashMap<u32, MockMapState>>> = OnceLock::new();
    MOCK_MAPS.get_or_init(|| Mutex::new(HashMap::new()))
}

pub fn install_mock_map(map_id: u32, state: MockMapState) {
    if let Ok(mut maps) = mock_maps().lock() {
        maps.insert(map_id, state);
    }
}

pub fn clear_mock_maps() {
    if let Ok(mut maps) = mock_maps().lock() {
        maps.clear();
    }
}

pub fn bpf_map_get_info_by_id(map_id: u32) -> Result<(BpfMapInfo, bool)> {
    let maps = mock_maps()
        .lock()
        .map_err(|_| anyhow!("mock map registry lock poisoned"))?;
    let state = maps
        .get(&map_id)
        .cloned()
        .ok_or_else(|| anyhow!("mock map {} not found", map_id))?;
    Ok((state.info, state.frozen))
}

pub fn bpf_map_lookup_elem_by_id(map_id: u32, key: &[u8], value_size: usize) -> Result<Vec<u8>> {
    let maps = mock_maps()
        .lock()
        .map_err(|_| anyhow!("mock map registry lock poisoned"))?;
    let state = maps
        .get(&map_id)
        .ok_or_else(|| anyhow!("mock map {} not found", map_id))?;
    let value = state
        .values
        .get(key)
        .cloned()
        .ok_or_else(|| anyhow!("mock map {} missing key {}", map_id, hex_bytes(key)))?;
    if value.len() != value_size {
        bail!(
            "mock map {} returned {} bytes, expected {}",
            map_id,
            value.len(),
            value_size
        );
    }
    Ok(value)
}

fn hex_bytes(bytes: &[u8]) -> String {
    let mut out = String::with_capacity(bytes.len() * 2);
    for byte in bytes {
        out.push_str(&format!("{:02x}", byte));
    }
    out
}
