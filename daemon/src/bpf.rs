// SPDX-License-Identifier: MIT
//! Raw BPF syscall wrappers — zero libbpf dependency.
//!
//! All interaction with the kernel goes through `libc::syscall(SYS_bpf, ...)`.

use std::collections::HashMap;
use std::os::unix::io::{AsRawFd, FromRawFd, OwnedFd, RawFd};
use std::sync::OnceLock;

use anyhow::{bail, Context, Result};
use serde::Serialize;

use crate::insn::BpfInsn;

// ── bpf_cmd values (from vendor/linux-framework/include/uapi/linux/bpf.h) ───
// The enum starts at 0. We only define the commands we actually use.
// Note: BPF_MAP_FREEZE=22 sits between BTF_GET_FD_BY_ID and BTF_GET_NEXT_ID.
const BPF_MAP_LOOKUP_ELEM: u32 = 1;
const BPF_MAP_TYPE_ARRAY: u32 = 2;
const BPF_MAP_TYPE_PERCPU_HASH: u32 = 5;
const BPF_MAP_TYPE_PERCPU_ARRAY: u32 = 6;
const BPF_MAP_TYPE_LRU_PERCPU_HASH: u32 = 10;
const BPF_PROG_GET_NEXT_ID: u32 = 11;
const BPF_MAP_GET_NEXT_ID: u32 = 12;
const BPF_PROG_GET_FD_BY_ID: u32 = 13;
const BPF_MAP_GET_FD_BY_ID: u32 = 14;
const BPF_OBJ_GET_INFO_BY_FD: u32 = 15;
const BPF_BTF_LOAD: u32 = 18;
const BPF_BTF_GET_FD_BY_ID: u32 = 19;
// BPF_TASK_FD_QUERY=20, BPF_MAP_LOOKUP_AND_DELETE_ELEM=21, BPF_MAP_FREEZE=22
const BPF_BTF_GET_NEXT_ID: u32 = 23;
// BPF_PROG_REJIT is the last entry before __MAX_BPF_CMD.
// BPF_TOKEN_CREATE=36, BPF_PROG_STREAM_READ_BY_FD=37,
// BPF_PROG_ASSOC_STRUCT_OPS=38, BPF_PROG_REJIT=39
const BPF_PROG_REJIT: u32 = 39;

const BPF_OBJ_NAME_LEN: usize = 16;

// ── Syscall number ──────────────────────────────────────────────────
#[cfg(target_arch = "x86_64")]
const SYS_BPF: libc::c_long = 321;

#[cfg(target_arch = "aarch64")]
const SYS_BPF: libc::c_long = 280;

// ── bpf_attr union variants (repr(C), sized to 128 bytes) ──────────

/// Attr for BPF_PROG_GET_NEXT_ID.
#[repr(C)]
struct AttrGetNextId {
    start_id: u32,
    next_id: u32,
    open_flags: u32,
    _pad: [u8; 128 - 12],
}

/// Attr for BPF_PROG_GET_FD_BY_ID.
#[repr(C)]
struct AttrGetFdById {
    prog_id: u32,
    next_id: u32,
    open_flags: u32,
    _pad: [u8; 128 - 12],
}

/// Attr for BPF_OBJ_GET_INFO_BY_FD.
#[repr(C)]
struct AttrGetInfoByFd {
    bpf_fd: u32,
    info_len: u32,
    info: u64, // pointer
    _pad: [u8; 128 - 16],
}

/// Attr for BPF_MAP_LOOKUP_ELEM.
#[repr(C)]
struct AttrMapElem {
    map_fd: u32,
    _pad0: u32,
    key: u64,
    value: u64,
    flags: u64,
    _pad: [u8; 128 - 32],
}

/// Attr for BPF_PROG_REJIT — matches `bpf_attr.rejit`.
#[repr(C)]
struct AttrRejit {
    prog_fd: u32,
    insn_cnt: u32,
    insns: u64, // __aligned_u64
    log_level: u32,
    log_size: u32,
    log_buf: u64,  // __aligned_u64
    fd_array: u64, // __aligned_u64
    fd_array_cnt: u32,
    flags: u32,
    _pad: [u8; 128 - 48], // fields above total 48 bytes
}

// Safety: all-zeros is a valid representation for these C-compatible structs.
fn zeroed_attr<T>() -> T {
    unsafe { std::mem::zeroed() }
}

// ── BpfProgInfo ─────────────────────────────────────────────────────

/// Mirrors `struct bpf_prog_info` from the kernel UAPI header.
/// We define the full struct so the kernel fills all fields.
#[repr(C)]
#[derive(Clone, Debug)]
pub struct BpfProgInfo {
    pub prog_type: u32,
    pub id: u32,
    pub tag: [u8; 8],
    pub jited_prog_len: u32,
    pub xlated_prog_len: u32,
    pub jited_prog_insns: u64,
    pub xlated_prog_insns: u64,
    pub load_time: u64,
    pub created_by_uid: u32,
    pub nr_map_ids: u32,
    pub map_ids: u64,
    pub name: [u8; BPF_OBJ_NAME_LEN],
    pub ifindex: u32,
    pub gpl_compatible_pad: u32, // bitfield + padding
    pub netns_dev: u64,
    pub netns_ino: u64,
    pub nr_jited_ksyms: u32,
    pub nr_jited_func_lens: u32,
    pub jited_ksyms: u64,
    pub jited_func_lens: u64,
    pub btf_id: u32,
    pub func_info_rec_size: u32,
    pub func_info: u64,
    pub nr_func_info: u32,
    pub nr_line_info: u32,
    pub line_info: u64,
    pub jited_line_info: u64,
    pub nr_jited_line_info: u32,
    pub line_info_rec_size: u32,
    pub jited_line_info_rec_size: u32,
    pub nr_prog_tags: u32,
    pub prog_tags: u64,
    pub run_time_ns: u64,
    pub run_cnt: u64,
    pub recursion_misses: u64,
    pub verified_insns: u32,
    pub attach_btf_obj_id: u32,
    pub attach_btf_id: u32,
    pub orig_prog_len: u32,
    pub orig_prog_insns: u64,
}

impl Default for BpfProgInfo {
    fn default() -> Self {
        // Safety: all-zero is valid for this repr(C) struct.
        unsafe { std::mem::zeroed() }
    }
}

impl BpfProgInfo {
    /// Returns the program name as a string (truncated at first NUL byte).
    pub fn name_str(&self) -> &str {
        let end = self
            .name
            .iter()
            .position(|&b| b == 0)
            .unwrap_or(self.name.len());
        std::str::from_utf8(&self.name[..end]).unwrap_or("<invalid-utf8>")
    }
}

/// Mirrors `struct bpf_map_info` from the kernel UAPI header.
#[repr(C)]
#[derive(Clone, Debug)]
pub struct BpfMapInfo {
    pub map_type: u32,
    pub id: u32,
    pub key_size: u32,
    pub value_size: u32,
    pub max_entries: u32,
    pub map_flags: u32,
    pub name: [u8; BPF_OBJ_NAME_LEN],
    pub ifindex: u32,
    pub btf_vmlinux_value_type_id: u32,
    pub netns_dev: u64,
    pub netns_ino: u64,
    pub btf_id: u32,
    pub btf_key_type_id: u32,
    pub btf_value_type_id: u32,
    pub btf_vmlinux_id: u32,
    pub map_extra: u64,
    pub hash: u64,
    pub hash_size: u32,
}

impl Default for BpfMapInfo {
    fn default() -> Self {
        // Safety: all-zero is valid for this repr(C) struct.
        unsafe { std::mem::zeroed() }
    }
}

#[cfg(test)]
#[derive(Clone, Debug, Default)]
pub struct MockMapState {
    pub info: BpfMapInfo,
    pub frozen: bool,
    pub values: std::collections::HashMap<Vec<u8>, Vec<u8>>,
}

#[cfg(test)]
fn mock_maps() -> &'static std::sync::Mutex<std::collections::HashMap<u32, MockMapState>> {
    static MOCK_MAPS: std::sync::OnceLock<
        std::sync::Mutex<std::collections::HashMap<u32, MockMapState>>,
    > = std::sync::OnceLock::new();
    MOCK_MAPS.get_or_init(|| std::sync::Mutex::new(std::collections::HashMap::new()))
}

#[cfg(test)]
fn mock_map_state(map_id: u32) -> Option<MockMapState> {
    mock_maps().lock().ok()?.get(&map_id).cloned()
}

/// Install a mock map for daemon unit tests.
#[cfg(test)]
pub fn install_mock_map(map_id: u32, state: MockMapState) {
    if let Ok(mut maps) = mock_maps().lock() {
        maps.insert(map_id, state);
    }
}

/// Clear all mock maps installed for daemon unit tests.
#[cfg(test)]
#[allow(dead_code)]
pub fn clear_mock_maps() {
    if let Ok(mut maps) = mock_maps().lock() {
        maps.clear();
    }
}

#[derive(Clone, Copy, Debug, Default)]
struct ProgImageRequest {
    fetch_orig: bool,
    fetch_xlated: bool,
    fetch_jited: bool,
}

#[derive(Clone, Debug, Default)]
pub struct BpfProgImages {
    pub info: BpfProgInfo,
    pub orig_insns: Vec<BpfInsn>,
    pub xlated_insns: Vec<BpfInsn>,
    pub jited_prog_insns: Vec<u8>,
}

#[derive(Clone, Debug, PartialEq, Eq, Serialize)]
pub struct MachineCodeLine {
    pub offset: usize,
    pub raw_hex: String,
}

#[derive(Clone, Debug, PartialEq, Eq, Serialize)]
pub struct MachineCodeDump {
    pub byte_len: usize,
    pub bytes_per_line: usize,
    pub lines: Vec<MachineCodeLine>,
}

fn hex_bytes(bytes: &[u8]) -> String {
    let mut out = String::with_capacity(bytes.len().saturating_mul(3).saturating_sub(1));
    for (idx, byte) in bytes.iter().enumerate() {
        if idx > 0 {
            out.push(' ');
        }
        use std::fmt::Write as _;
        let _ = write!(out, "{:02x}", byte);
    }
    out
}

pub fn dump_machine_code(bytes: &[u8]) -> MachineCodeDump {
    const BYTES_PER_LINE: usize = 16;

    MachineCodeDump {
        byte_len: bytes.len(),
        bytes_per_line: BYTES_PER_LINE,
        lines: bytes
            .chunks(BYTES_PER_LINE)
            .enumerate()
            .map(|(idx, chunk)| MachineCodeLine {
                offset: idx * BYTES_PER_LINE,
                raw_hex: hex_bytes(chunk),
            })
            .collect(),
    }
}

// ── Raw syscall helper ──────────────────────────────────────────────

/// Issue the bpf(2) syscall. Returns the raw return value (>= 0 on success).
unsafe fn sys_bpf(cmd: u32, attr: *mut u8, size: u32) -> libc::c_long {
    unsafe {
        libc::syscall(
            SYS_BPF,
            cmd as libc::c_long,
            attr as libc::c_long,
            size as libc::c_long,
        )
    }
}

fn bpf_err(context: &str) -> anyhow::Error {
    anyhow::anyhow!("{}: {}", context, std::io::Error::last_os_error())
}

fn bpf_obj_get_info_by_fd(fd: RawFd, info: &mut BpfProgInfo, context: &str) -> Result<()> {
    let mut attr: AttrGetInfoByFd = zeroed_attr();
    attr.bpf_fd = fd as u32;
    attr.info_len = std::mem::size_of::<BpfProgInfo>() as u32;
    attr.info = info as *mut _ as u64;

    let ret = unsafe {
        sys_bpf(
            BPF_OBJ_GET_INFO_BY_FD,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrGetInfoByFd>() as u32,
        )
    };
    if ret < 0 {
        bail!(bpf_err(context));
    }
    Ok(())
}

fn bpf_map_obj_get_info_by_fd(fd: RawFd, info: &mut BpfMapInfo, context: &str) -> Result<()> {
    let mut attr: AttrGetInfoByFd = zeroed_attr();
    attr.bpf_fd = fd as u32;
    attr.info_len = std::mem::size_of::<BpfMapInfo>() as u32;
    attr.info = info as *mut _ as u64;

    let ret = unsafe {
        sys_bpf(
            BPF_OBJ_GET_INFO_BY_FD,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrGetInfoByFd>() as u32,
        )
    };
    if ret < 0 {
        bail!(bpf_err(context));
    }
    Ok(())
}

fn bpf_map_try_detect_frozen(fd: RawFd) -> bool {
    const SHA256_DIGEST_SIZE: usize = 32;

    let mut info = BpfMapInfo::default();
    let mut hash = [0u8; SHA256_DIGEST_SIZE];
    info.hash = hash.as_mut_ptr() as u64;
    info.hash_size = SHA256_DIGEST_SIZE as u32;

    bpf_map_obj_get_info_by_fd(fd, &mut info, "BPF_OBJ_GET_INFO_BY_FD (map hash)").is_ok()
}

fn parse_bpf_insn_bytes(bytes: &[u8], field_name: &str) -> Result<Vec<BpfInsn>> {
    if bytes.is_empty() {
        return Ok(Vec::new());
    }
    if !bytes.len().is_multiple_of(std::mem::size_of::<BpfInsn>()) {
        bail!(
            "{} length {} is not a multiple of {} bytes",
            field_name,
            bytes.len(),
            std::mem::size_of::<BpfInsn>()
        );
    }

    let mut insns = Vec::with_capacity(bytes.len() / std::mem::size_of::<BpfInsn>());
    for chunk in bytes.chunks_exact(8) {
        insns.push(BpfInsn {
            code: chunk[0],
            regs: chunk[1],
            off: i16::from_le_bytes([chunk[2], chunk[3]]),
            imm: i32::from_le_bytes([chunk[4], chunk[5], chunk[6], chunk[7]]),
        });
    }
    Ok(insns)
}

fn bpf_prog_get_images(fd: RawFd, request: ProgImageRequest) -> Result<BpfProgImages> {
    let mut info = BpfProgInfo::default();
    bpf_obj_get_info_by_fd(fd, &mut info, "BPF_OBJ_GET_INFO_BY_FD (first pass)")?;

    let need_second_pass = (request.fetch_orig && info.orig_prog_len > 0)
        || (request.fetch_xlated && info.xlated_prog_len > 0)
        || (request.fetch_jited && info.jited_prog_len > 0);
    if !need_second_pass {
        return Ok(BpfProgImages {
            info,
            ..Default::default()
        });
    }

    let mut orig_bytes = if request.fetch_orig && info.orig_prog_len > 0 {
        vec![0u8; info.orig_prog_len as usize]
    } else {
        Vec::new()
    };
    let mut xlated_bytes = if request.fetch_xlated && info.xlated_prog_len > 0 {
        vec![0u8; info.xlated_prog_len as usize]
    } else {
        Vec::new()
    };
    let mut jited_bytes = if request.fetch_jited && info.jited_prog_len > 0 {
        vec![0u8; info.jited_prog_len as usize]
    } else {
        Vec::new()
    };

    let mut second_info = BpfProgInfo::default();
    if !orig_bytes.is_empty() {
        second_info.orig_prog_len = orig_bytes.len() as u32;
        second_info.orig_prog_insns = orig_bytes.as_mut_ptr() as u64;
    }
    if !xlated_bytes.is_empty() {
        second_info.xlated_prog_len = xlated_bytes.len() as u32;
        second_info.xlated_prog_insns = xlated_bytes.as_mut_ptr() as u64;
    }
    if !jited_bytes.is_empty() {
        second_info.jited_prog_len = jited_bytes.len() as u32;
        second_info.jited_prog_insns = jited_bytes.as_mut_ptr() as u64;
    }

    bpf_obj_get_info_by_fd(fd, &mut second_info, "BPF_OBJ_GET_INFO_BY_FD (images)")?;

    orig_bytes.truncate(second_info.orig_prog_len as usize);
    xlated_bytes.truncate(second_info.xlated_prog_len as usize);
    jited_bytes.truncate(second_info.jited_prog_len as usize);

    Ok(BpfProgImages {
        info: second_info,
        orig_insns: parse_bpf_insn_bytes(&orig_bytes, "orig_prog_insns")?,
        xlated_insns: parse_bpf_insn_bytes(&xlated_bytes, "xlated_prog_insns")?,
        jited_prog_insns: jited_bytes,
    })
}

// ── Public API ──────────────────────────────────────────────────────

/// Enumerate BPF program IDs starting from `start_id`.
/// Returns `Ok(None)` when no more programs remain (ENOENT).
pub fn bpf_prog_get_next_id(start_id: u32) -> Result<Option<u32>> {
    let mut attr: AttrGetNextId = zeroed_attr();
    attr.start_id = start_id;
    let ret = unsafe {
        sys_bpf(
            BPF_PROG_GET_NEXT_ID,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrGetNextId>() as u32,
        )
    };
    if ret < 0 {
        let err = std::io::Error::last_os_error();
        if err.raw_os_error() == Some(libc::ENOENT) {
            return Ok(None);
        }
        bail!("BPF_PROG_GET_NEXT_ID: {}", err);
    }
    Ok(Some(attr.next_id))
}

/// Open a file descriptor for the BPF program with the given ID.
pub fn bpf_prog_get_fd_by_id(id: u32) -> Result<OwnedFd> {
    let mut attr: AttrGetFdById = zeroed_attr();
    attr.prog_id = id;
    let ret = unsafe {
        sys_bpf(
            BPF_PROG_GET_FD_BY_ID,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrGetFdById>() as u32,
        )
    };
    if ret < 0 {
        bail!(bpf_err(&format!("BPF_PROG_GET_FD_BY_ID({})", id)));
    }
    // Safety: the kernel returned a valid new fd.
    Ok(unsafe { OwnedFd::from_raw_fd(ret as RawFd) })
}

/// Open a file descriptor for the BPF map with the given ID.
pub fn bpf_map_get_fd_by_id(id: u32) -> Result<OwnedFd> {
    let mut attr: AttrGetFdById = zeroed_attr();
    attr.prog_id = id; // same field position as map_id in the union
    let ret = unsafe {
        sys_bpf(
            BPF_MAP_GET_FD_BY_ID,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrGetFdById>() as u32,
        )
    };
    if ret < 0 {
        bail!(bpf_err(&format!("BPF_MAP_GET_FD_BY_ID({})", id)));
    }
    Ok(unsafe { OwnedFd::from_raw_fd(ret as RawFd) })
}

/// Retrieve `bpf_map_info` for an open map fd.
pub fn bpf_map_get_info(fd: RawFd) -> Result<BpfMapInfo> {
    let mut info = BpfMapInfo::default();
    bpf_map_obj_get_info_by_fd(fd, &mut info, "BPF_OBJ_GET_INFO_BY_FD (map)")?;
    Ok(info)
}

/// Retrieve `bpf_map_info` and a best-effort frozen bit for a map ID.
pub fn bpf_map_get_info_by_id(id: u32) -> Result<(BpfMapInfo, bool)> {
    #[cfg(test)]
    if let Some(state) = mock_map_state(id) {
        return Ok((state.info, state.frozen));
    }

    let fd = bpf_map_get_fd_by_id(id)?;
    let info = bpf_map_get_info(fd.as_raw_fd())?;
    let frozen = bpf_map_try_detect_frozen(fd.as_raw_fd());
    Ok((info, frozen))
}

/// Lookup a map element by fd and return the raw value bytes.
pub fn bpf_map_lookup_elem(fd: RawFd, key: &[u8], value_size: usize) -> Result<Vec<u8>> {
    let mut attr: AttrMapElem = zeroed_attr();
    let mut value = vec![0u8; value_size];

    attr.map_fd = fd as u32;
    attr.key = key.as_ptr() as u64;
    attr.value = value.as_mut_ptr() as u64;
    attr.flags = 0;

    let ret = unsafe {
        sys_bpf(
            BPF_MAP_LOOKUP_ELEM,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrMapElem>() as u32,
        )
    };
    if ret < 0 {
        bail!(bpf_err("BPF_MAP_LOOKUP_ELEM"));
    }

    Ok(value)
}

/// Lookup a map element by fd and return `None` when the key is absent.
pub fn bpf_map_lookup_elem_optional(
    fd: RawFd,
    key: &[u8],
    value_size: usize,
) -> Result<Option<Vec<u8>>> {
    let mut attr: AttrMapElem = zeroed_attr();
    let mut value = vec![0u8; value_size];

    attr.map_fd = fd as u32;
    attr.key = key.as_ptr() as u64;
    attr.value = value.as_mut_ptr() as u64;
    attr.flags = 0;

    let ret = unsafe {
        sys_bpf(
            BPF_MAP_LOOKUP_ELEM,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrMapElem>() as u32,
        )
    };
    if ret < 0 {
        let err = std::io::Error::last_os_error();
        if err.raw_os_error() == Some(libc::ENOENT) {
            return Ok(None);
        }
        bail!("BPF_MAP_LOOKUP_ELEM: {}", err);
    }

    Ok(Some(value))
}

/// Lookup a map element by map ID and return the raw value bytes.
pub fn bpf_map_lookup_elem_by_id(map_id: u32, key: &[u8], value_size: usize) -> Result<Vec<u8>> {
    #[cfg(test)]
    if let Some(state) = mock_map_state(map_id) {
        let value = match state.values.get(key).cloned() {
            Some(value) => value,
            None => mock_zero_filled_lookup_value(&state, key, value_size)
                .ok_or_else(|| anyhow::anyhow!("mock map {} missing key {:?}", map_id, key))?,
        };
        if value.len() != value_size {
            bail!(
                "mock map {} returned value size {}, expected {}",
                map_id,
                value.len(),
                value_size
            );
        }
        return Ok(value);
    }

    let fd = bpf_map_get_fd_by_id(map_id)?;
    match bpf_map_lookup_elem_optional(fd.as_raw_fd(), key, value_size)? {
        Some(value) => Ok(value),
        None => {
            let info = bpf_map_get_info(fd.as_raw_fd())?;
            zero_filled_lookup_value(&info, key, value_size)
                .ok_or_else(|| anyhow::anyhow!("map {} missing key {:?}", map_id, key))
        }
    }
}

pub fn bpf_map_lookup_value_size(info: &BpfMapInfo) -> usize {
    if is_percpu_map_type(info.map_type) {
        round_up_8(info.value_size as usize).saturating_mul(possible_cpu_count())
    } else {
        info.value_size as usize
    }
}

pub fn bpf_map_lookup_value_size_by_id(map_id: u32) -> Result<usize> {
    #[cfg(test)]
    if let Some(state) = mock_map_state(map_id) {
        return Ok(mock_lookup_value_size(&state));
    }

    let (info, _) = bpf_map_get_info_by_id(map_id)?;
    Ok(bpf_map_lookup_value_size(&info))
}

fn is_percpu_map_type(map_type: u32) -> bool {
    matches!(
        map_type,
        BPF_MAP_TYPE_PERCPU_HASH | BPF_MAP_TYPE_PERCPU_ARRAY | BPF_MAP_TYPE_LRU_PERCPU_HASH
    )
}

fn round_up_8(value: usize) -> usize {
    (value + 7) & !7
}

fn possible_cpu_count() -> usize {
    static POSSIBLE_CPU_COUNT: OnceLock<usize> = OnceLock::new();
    *POSSIBLE_CPU_COUNT.get_or_init(|| read_possible_cpu_count().unwrap_or(1))
}

fn read_possible_cpu_count() -> Option<usize> {
    let text = std::fs::read_to_string("/sys/devices/system/cpu/possible").ok()?;
    parse_possible_cpu_list(&text)
        .or_else(|| std::thread::available_parallelism().ok().map(usize::from))
}

fn parse_possible_cpu_list(text: &str) -> Option<usize> {
    let mut count = 0usize;
    for segment in text.trim().split(',').filter(|segment| !segment.is_empty()) {
        let parsed = if let Some((start, end)) = segment.split_once('-') {
            let start = start.trim().parse::<usize>().ok()?;
            let end = end.trim().parse::<usize>().ok()?;
            end.checked_sub(start)?.checked_add(1)?
        } else {
            segment.trim().parse::<usize>().ok()?;
            1
        };
        count = count.checked_add(parsed)?;
    }
    (count > 0).then_some(count)
}

#[cfg(test)]
fn mock_zero_filled_lookup_value(
    state: &MockMapState,
    key: &[u8],
    value_size: usize,
) -> Option<Vec<u8>> {
    zero_filled_lookup_value(&state.info, key, value_size)
}

#[cfg(test)]
fn mock_lookup_value_size(state: &MockMapState) -> usize {
    state
        .values
        .values()
        .next()
        .map(|value| value.len())
        .unwrap_or_else(|| bpf_map_lookup_value_size(&state.info))
}

fn zero_filled_lookup_value(info: &BpfMapInfo, key: &[u8], value_size: usize) -> Option<Vec<u8>> {
    if !matches!(
        info.map_type,
        BPF_MAP_TYPE_ARRAY | BPF_MAP_TYPE_PERCPU_ARRAY
    ) {
        return None;
    }
    if info.key_size as usize != key.len() || key.len() > 8 {
        return None;
    }

    let expected_size = bpf_map_lookup_value_size(info);
    if value_size != expected_size {
        return None;
    }

    let mut raw = [0u8; 8];
    raw[..key.len()].copy_from_slice(key);
    let index = u64::from_le_bytes(raw);
    (index < info.max_entries as u64).then_some(vec![0u8; value_size])
}

/// Open a file descriptor for the BPF BTF object with the given ID.
pub fn bpf_btf_get_fd_by_id(id: u32) -> Result<OwnedFd> {
    let mut attr: AttrGetFdById = zeroed_attr();
    attr.prog_id = id; // same field position as btf_id in the union
    let ret = unsafe {
        sys_bpf(
            BPF_BTF_GET_FD_BY_ID,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrGetFdById>() as u32,
        )
    };
    if ret < 0 {
        bail!(bpf_err(&format!("BPF_BTF_GET_FD_BY_ID({})", id)));
    }
    Ok(unsafe { OwnedFd::from_raw_fd(ret as RawFd) })
}

/// Enumerate BTF object IDs starting from `start_id`.
pub fn bpf_btf_get_next_id(start_id: u32) -> Result<u32> {
    let mut attr: AttrGetNextId = zeroed_attr();
    attr.start_id = start_id;
    let ret = unsafe {
        sys_bpf(
            BPF_BTF_GET_NEXT_ID,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrGetNextId>() as u32,
        )
    };
    if ret < 0 {
        bail!(bpf_err("BPF_BTF_GET_NEXT_ID"));
    }
    Ok(attr.next_id)
}

/// BTF info structure for BPF_OBJ_GET_INFO_BY_FD on BTF objects.
#[repr(C)]
struct BtfInfo {
    btf: u64, // pointer to BTF data
    btf_size: u32,
    id: u32,
    name: u64, // pointer to name buffer
    name_len: u32,
    kernel_btf: u32, // 1 if kernel/module BTF
    _pad: [u8; 128 - 32],
}

/// Get the name of a BTF object by its FD.
fn bpf_btf_get_info_name(btf_fd: RawFd) -> Result<String> {
    let mut name_buf = [0u8; 64];
    let mut info: BtfInfo = zeroed_attr();
    info.name = name_buf.as_mut_ptr() as u64;
    info.name_len = name_buf.len() as u32;

    let mut attr: AttrGetInfoByFd = zeroed_attr();
    attr.bpf_fd = btf_fd as u32;
    attr.info_len = std::mem::size_of::<BtfInfo>() as u32;
    attr.info = &mut info as *mut _ as u64;

    let ret = unsafe {
        sys_bpf(
            BPF_OBJ_GET_INFO_BY_FD,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrGetInfoByFd>() as u32,
        )
    };
    if ret < 0 {
        bail!(bpf_err("BPF_OBJ_GET_INFO_BY_FD (btf)"));
    }

    let nul = name_buf
        .iter()
        .position(|&b| b == 0)
        .unwrap_or(name_buf.len());
    Ok(String::from_utf8_lossy(&name_buf[..nul]).into_owned())
}

/// Find a BPF BTF FD for a kernel module by its name.
///
/// Iterates all BTF objects in the kernel and returns an FD for the one
/// whose name matches `module_name`. Returns a proper BPF BTF FD that
/// the verifier can use (unlike a plain open() of /sys/kernel/btf/).
pub fn bpf_btf_get_fd_by_module_name(module_name: &str) -> Result<OwnedFd> {
    let mut id = 0u32;
    while let Ok(next) = bpf_btf_get_next_id(id) {
        id = next;
        if let Ok(fd) = bpf_btf_get_fd_by_id(id) {
            use std::os::unix::io::AsRawFd;
            if let Ok(name) = bpf_btf_get_info_name(fd.as_raw_fd()) {
                if name == module_name {
                    return Ok(fd);
                }
            }
        }
    }
    bail!("BTF object for module '{}' not found", module_name)
}

/// Retrieve `bpf_prog_info` for an open program fd.
///
/// If `fetch_orig` is true, also allocates a buffer and retrieves the
/// original (pre-verifier) BPF instructions via `orig_prog_insns`.
pub fn bpf_prog_get_info(fd: RawFd, fetch_orig: bool) -> Result<(BpfProgInfo, Vec<BpfInsn>)> {
    let images = bpf_prog_get_images(
        fd,
        ProgImageRequest {
            fetch_orig,
            ..Default::default()
        },
    )?;
    Ok((images.info, images.orig_insns))
}

/// Retrieve the kernel-visible xlated BPF and final JIT image for a program fd.
pub fn bpf_prog_get_runtime_images(fd: RawFd) -> Result<BpfProgImages> {
    bpf_prog_get_images(
        fd,
        ProgImageRequest {
            fetch_xlated: true,
            fetch_jited: true,
            ..Default::default()
        },
    )
}

/// Retrieve map IDs used by a loaded BPF program.
///
/// Calls `BPF_OBJ_GET_INFO_BY_FD` twice: first to learn `nr_map_ids`,
/// then with a buffer to receive the actual map IDs.
pub fn bpf_prog_get_map_ids(fd: RawFd) -> Result<Vec<u32>> {
    // First call: learn nr_map_ids.
    let mut info = BpfProgInfo::default();
    let mut attr: AttrGetInfoByFd = zeroed_attr();
    attr.bpf_fd = fd as u32;
    attr.info_len = std::mem::size_of::<BpfProgInfo>() as u32;
    attr.info = &mut info as *mut _ as u64;

    let ret = unsafe {
        sys_bpf(
            BPF_OBJ_GET_INFO_BY_FD,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrGetInfoByFd>() as u32,
        )
    };
    if ret < 0 {
        bail!(bpf_err("BPF_OBJ_GET_INFO_BY_FD (map_ids first pass)"));
    }

    let nr = info.nr_map_ids as usize;
    if nr == 0 {
        return Ok(Vec::new());
    }

    // Second call: fetch the map IDs.
    let mut map_ids = vec![0u32; nr];
    info = BpfProgInfo::default();
    info.nr_map_ids = nr as u32;
    info.map_ids = map_ids.as_mut_ptr() as u64;

    attr = zeroed_attr();
    attr.bpf_fd = fd as u32;
    attr.info_len = std::mem::size_of::<BpfProgInfo>() as u32;
    attr.info = &mut info as *mut _ as u64;

    let ret = unsafe {
        sys_bpf(
            BPF_OBJ_GET_INFO_BY_FD,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrGetInfoByFd>() as u32,
        )
    };
    if ret < 0 {
        bail!(bpf_err("BPF_OBJ_GET_INFO_BY_FD (map_ids second pass)"));
    }

    // Truncate to the actual number returned (should match nr).
    map_ids.truncate(info.nr_map_ids as usize);
    Ok(map_ids)
}

// BPF instruction encoding constants for map FD relocation.
const BPF_LD: u8 = 0x00;
const BPF_IMM: u8 = 0x00;
const BPF_DW: u8 = 0x18;
const BPF_PSEUDO_MAP_FD: u8 = 1;
const BPF_PSEUDO_MAP_VALUE: u8 = 2;

/// Relocate map file descriptors in BPF bytecode.
///
/// The original bytecode from `BPF_PROG_GET_ORIGINAL` contains `BPF_LD_IMM64`
/// instructions with `src_reg = BPF_PSEUDO_MAP_FD` (or `BPF_PSEUDO_MAP_VALUE`)
/// whose `imm` field holds the FD number from the original loading process.
/// These FDs are stale in the daemon's process context.
///
/// This function:
/// 1. Scans for `BPF_LD_IMM64` map reference instructions
/// 2. Collects unique old FDs in first-seen order (matching the kernel's `used_maps` order)
/// 3. Maps each old FD to a map ID (from `map_ids`, in the same order)
/// 4. Opens new FDs for each map ID via `BPF_MAP_GET_FD_BY_ID`
/// 5. Patches the bytecode to use the new FDs
///
/// Returns the list of opened map `OwnedFd`s (caller must keep them alive until REJIT completes).
pub fn relocate_map_fds(insns: &mut [BpfInsn], map_ids: &[u32]) -> Result<Vec<OwnedFd>> {
    relocate_map_fds_with_bindings(insns, map_ids, &HashMap::new())
}

pub fn relocate_map_fds_with_bindings(
    insns: &mut [BpfInsn],
    map_ids: &[u32],
    map_fd_bindings: &HashMap<i32, u32>,
) -> Result<Vec<OwnedFd>> {
    use std::os::unix::io::AsRawFd;

    // Step 1: Scan for BPF_LD_IMM64 with BPF_PSEUDO_MAP_FD or BPF_PSEUDO_MAP_VALUE.
    // Collect unique old FDs in first-seen order.
    let mut unique_old_fds: Vec<i32> = Vec::new();
    let mut seen: HashMap<i32, usize> = HashMap::new();

    let mut i = 0;
    while i < insns.len() {
        let code = insns[i].code;
        // BPF_LD | BPF_IMM | BPF_DW = 0x18
        if code == (BPF_LD | BPF_IMM | BPF_DW) {
            let src_reg = (insns[i].regs >> 4) & 0x0f;
            if src_reg == BPF_PSEUDO_MAP_FD || src_reg == BPF_PSEUDO_MAP_VALUE {
                let old_fd = insns[i].imm;
                if let std::collections::hash_map::Entry::Vacant(e) = seen.entry(old_fd) {
                    let idx = unique_old_fds.len();
                    unique_old_fds.push(old_fd);
                    e.insert(idx);
                }
            }
            i += 2; // BPF_LD_IMM64 is a 2-instruction wide instruction
            continue;
        }
        i += 1;
    }

    if unique_old_fds.is_empty() {
        return Ok(Vec::new());
    }

    let relocation_targets =
        resolve_map_ids_for_relocation(&unique_old_fds, map_ids, map_fd_bindings);

    if relocation_targets.len() != unique_old_fds.len() {
        bail!(
            "relocate_map_fds: found {} unique FDs in bytecode but only resolved {} map IDs",
            unique_old_fds.len(),
            relocation_targets.len()
        );
    }

    // Step 3: Open new FDs for each map ID and build old_fd -> new_fd mapping.
    let mut owned_fds: Vec<OwnedFd> = Vec::new();
    let mut fd_map: HashMap<i32, i32> = HashMap::new();

    for (&old_fd, &map_id) in &relocation_targets {
        let new_fd = bpf_map_get_fd_by_id(map_id).with_context(|| {
            format!(
                "relocate_map_fds: open map ID {} for old fd {}",
                map_id, old_fd
            )
        })?;
        let raw = new_fd.as_raw_fd();
        fd_map.insert(old_fd, raw);
        owned_fds.push(new_fd);
    }

    // Step 4: Patch the bytecode.
    i = 0;
    while i < insns.len() {
        let code = insns[i].code;
        if code == (BPF_LD | BPF_IMM | BPF_DW) {
            let src_reg = (insns[i].regs >> 4) & 0x0f;
            if src_reg == BPF_PSEUDO_MAP_FD || src_reg == BPF_PSEUDO_MAP_VALUE {
                let old_fd = insns[i].imm;
                if let Some(&new_fd) = fd_map.get(&old_fd) {
                    insns[i].imm = new_fd;
                }
            }
            i += 2;
            continue;
        }
        i += 1;
    }

    Ok(owned_fds)
}

fn resolve_map_ids_for_relocation(
    unique_old_fds: &[i32],
    map_ids: &[u32],
    map_fd_bindings: &HashMap<i32, u32>,
) -> HashMap<i32, u32> {
    let mut resolved = HashMap::new();

    for (idx, &old_fd) in unique_old_fds.iter().enumerate() {
        if let Some(&map_id) = map_fd_bindings.get(&old_fd) {
            resolved.insert(old_fd, map_id);
            continue;
        }
        if let Some(&map_id) = map_ids.get(idx) {
            resolved.insert(old_fd, map_id);
        }
    }

    resolved
}

/// Result of a REJIT attempt, including any verifier log on failure.
#[derive(Debug)]
pub struct RejitResult {
    /// Raw verifier log captured from the kernel (may be empty on success or
    /// if the kernel didn't write anything).
    pub verifier_log: String,
}

fn extract_log_string(log_buf: &[u8]) -> String {
    let nul_pos = log_buf
        .iter()
        .position(|&b| b == 0)
        .unwrap_or(log_buf.len());
    String::from_utf8_lossy(&log_buf[..nul_pos]).into_owned()
}

fn run_rejit_once(
    prog_fd: RawFd,
    insns: &[BpfInsn],
    fd_array: &[RawFd],
    log_level: u32,
    log_buf: Option<&mut [u8]>,
) -> Result<RejitResult> {
    let mut attr: AttrRejit = zeroed_attr();
    let mut log_buf = log_buf;

    attr.prog_fd = prog_fd as u32;
    attr.insn_cnt = insns.len() as u32;
    attr.insns = insns.as_ptr() as u64;
    attr.log_level = log_level;
    if let Some(buf) = log_buf.as_mut() {
        attr.log_size = buf.len() as u32;
        attr.log_buf = (*buf).as_mut_ptr() as u64;
    }
    if !fd_array.is_empty() {
        attr.fd_array = fd_array.as_ptr() as u64;
        attr.fd_array_cnt = fd_array.len() as u32;
    }

    let ret = unsafe {
        sys_bpf(
            BPF_PROG_REJIT,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrRejit>() as u32,
        )
    };

    let verifier_log = match log_buf.as_ref() {
        Some(buf) => extract_log_string(buf),
        None => String::new(),
    };

    if ret < 0 {
        let os_err = std::io::Error::last_os_error();
        if verifier_log.is_empty() {
            bail!("BPF_PROG_REJIT: {}", os_err);
        } else {
            bail!(
                "BPF_PROG_REJIT: {}\nverifier log:\n{}",
                os_err,
                verifier_log
            );
        }
    }

    Ok(RejitResult { verifier_log })
}

/// Submit new BPF bytecode to the kernel via BPF_PROG_REJIT.
///
/// The kernel will run bpf_check() + JIT on the new instructions and
/// atomically replace the program image in-place.
///
/// First attempts with `log_level=0` (fast path) and only retries with
/// `log_level=2` on failure.
pub fn bpf_prog_rejit(
    prog_fd: RawFd,
    insns: &[BpfInsn],
    fd_array: &[RawFd],
) -> Result<RejitResult> {
    const LOG_BUF_SIZE: usize = 16 * 1024 * 1024; // 16 MB

    match run_rejit_once(prog_fd, insns, fd_array, 0, None) {
        Ok(_) => Ok(RejitResult {
            verifier_log: String::new(),
        }),
        Err(first_err) => {
            let mut log_buf = vec![0u8; LOG_BUF_SIZE];
            match run_rejit_once(prog_fd, insns, fd_array, 2, Some(&mut log_buf)) {
                Ok(result) => Ok(result),
                Err(second_err) => {
                    let first_msg = format!("{first_err:#}");
                    let second_msg = format!("{second_err:#}");

                    if second_msg.contains("No space left on device") {
                        bail!(
                            "{second_msg}\ninitial REJIT failure without verifier log:\n{first_msg}"
                        );
                    }

                    Err(second_err)
                }
            }
        }
    }
}

/// Submit BPF bytecode to the kernel via `BPF_PROG_REJIT(log_level=2)` and
/// return the verifier log even on success.
pub fn bpf_prog_rejit_capture_verifier_log(
    prog_fd: RawFd,
    insns: &[BpfInsn],
    fd_array: &[RawFd],
) -> Result<RejitResult> {
    const LOG_BUF_SIZE: usize = 16 * 1024 * 1024; // 16 MB

    let mut log_buf = vec![0u8; LOG_BUF_SIZE];
    run_rejit_once(prog_fd, insns, fd_array, 2, Some(&mut log_buf))
}

pub struct ProgIdIter {
    next_id: u32,
    done: bool,
}

impl Iterator for ProgIdIter {
    type Item = Result<u32>;

    fn next(&mut self) -> Option<Self::Item> {
        if self.done {
            return None;
        }

        match bpf_prog_get_next_id(self.next_id) {
            Ok(Some(next_id)) => {
                self.next_id = next_id;
                Some(Ok(next_id))
            }
            Ok(None) => {
                self.done = true;
                None
            }
            Err(err) => {
                self.done = true;
                Some(Err(err))
            }
        }
    }
}

/// Iterate over all live BPF program IDs in the kernel.
pub fn iter_prog_ids() -> ProgIdIter {
    ProgIdIter {
        next_id: 0,
        done: false,
    }
}

/// Convenience: get the original BPF instructions for a program by ID.
pub fn get_orig_insns_by_id(prog_id: u32) -> Result<(BpfProgInfo, Vec<BpfInsn>)> {
    let fd = bpf_prog_get_fd_by_id(prog_id).with_context(|| format!("open prog {}", prog_id))?;
    use std::os::unix::io::AsRawFd;
    bpf_prog_get_info(fd.as_raw_fd(), true)
        .with_context(|| format!("get info for prog {}", prog_id))
}

// ── Tests ────────────────────────────────────────────────────────────

#[cfg(test)]
#[path = "bpf_tests.rs"]
mod tests;
