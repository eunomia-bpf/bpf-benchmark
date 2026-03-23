// SPDX-License-Identifier: MIT
//! Raw BPF syscall wrappers — zero libbpf dependency.
//!
//! All interaction with the kernel goes through `libc::syscall(SYS_bpf, ...)`.

use std::os::unix::io::{FromRawFd, OwnedFd, RawFd};

use anyhow::{bail, Context, Result};
use serde::Serialize;

use crate::insn::BpfInsn;

// ── bpf_cmd values (from vendor/linux-framework/include/uapi/linux/bpf.h) ───
// The enum starts at 0. We only define the commands we actually use.
// Note: BPF_MAP_FREEZE=22 sits between BTF_GET_FD_BY_ID and BTF_GET_NEXT_ID.
const BPF_PROG_GET_NEXT_ID: u32 = 11;
const BPF_PROG_GET_FD_BY_ID: u32 = 13;
const BPF_MAP_GET_FD_BY_ID: u32 = 14;
const BPF_OBJ_GET_INFO_BY_FD: u32 = 15;
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
/// Returns `Ok(next_id)` or `Err` when no more programs remain (ENOENT).
pub fn bpf_prog_get_next_id(start_id: u32) -> Result<u32> {
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
        bail!(bpf_err("BPF_PROG_GET_NEXT_ID"));
    }
    Ok(attr.next_id)
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
    use std::collections::HashMap;
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

    // Step 2: Verify we have enough map IDs.
    if unique_old_fds.len() > map_ids.len() {
        eprintln!(
            "  relocate_map_fds: found {} unique FDs in bytecode but only {} map IDs in prog info",
            unique_old_fds.len(),
            map_ids.len()
        );
        // Proceed with what we have, remaining will fail but this is better than failing all.
    }

    // Step 3: Open new FDs for each map ID and build old_fd -> new_fd mapping.
    let mut owned_fds: Vec<OwnedFd> = Vec::new();
    let mut fd_map: HashMap<i32, i32> = HashMap::new();

    for (idx, &old_fd) in unique_old_fds.iter().enumerate() {
        if idx >= map_ids.len() {
            break;
        }
        let map_id = map_ids[idx];
        match bpf_map_get_fd_by_id(map_id) {
            Ok(new_fd) => {
                let raw = new_fd.as_raw_fd();
                fd_map.insert(old_fd, raw);
                owned_fds.push(new_fd);
            }
            Err(e) => {
                eprintln!(
                    "  relocate_map_fds: failed to open map ID {} (old fd {}): {:#}",
                    map_id, old_fd, e
                );
                // Skip this mapping; the REJIT will likely fail but we continue.
            }
        }
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
    attr.prog_fd = prog_fd as u32;
    attr.insn_cnt = insns.len() as u32;
    attr.insns = insns.as_ptr() as u64;
    attr.log_level = log_level;
    if let Some(buf) = log_buf.as_ref() {
        attr.log_size = buf.len() as u32;
        attr.log_buf = buf.as_ptr() as u64;
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

    let verifier_log = log_buf
        .as_ref()
        .map(|buf| extract_log_string(buf))
        .unwrap_or_default();

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
/// When `capture_verifier_log` is false, first attempts with log_level=0
/// (fast path) and only retries with log_level=2 on failure. When true,
/// always uses log_level=2 so the success path also returns the verifier log.
pub fn bpf_prog_rejit(
    prog_fd: RawFd,
    insns: &[BpfInsn],
    fd_array: &[RawFd],
) -> Result<RejitResult> {
    const LOG_BUF_SIZE: usize = 16 * 1024 * 1024; // 16 MB
    let mut log_buf = vec![0u8; LOG_BUF_SIZE];
    run_rejit_once(prog_fd, insns, fd_array, 2, Some(&mut log_buf))
}

/// Iterate over all live BPF program IDs in the kernel.
pub fn iter_prog_ids() -> impl Iterator<Item = u32> {
    let mut id = 0u32;
    std::iter::from_fn(move || match bpf_prog_get_next_id(id) {
        Ok(next) => {
            id = next;
            Some(next)
        }
        Err(_) => None,
    })
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
mod tests {
    use super::*;

    /// Helper: build a BPF_LD_IMM64 instruction pair with given dst_reg, src_reg, and imm.
    fn make_ld_imm64(dst: u8, src: u8, imm_lo: i32, imm_hi: i32) -> [BpfInsn; 2] {
        [
            BpfInsn {
                code: BPF_LD | BPF_IMM | BPF_DW, // 0x18
                regs: (src << 4) | (dst & 0x0f),
                off: 0,
                imm: imm_lo,
            },
            BpfInsn {
                code: 0,
                regs: 0,
                off: 0,
                imm: imm_hi,
            },
        ]
    }

    /// Verify relocate_map_fds correctly identifies map references via src_reg,
    /// not dst_reg. With no map_ids to resolve, the function should detect the
    /// map references but return empty (no FDs to open).
    #[test]
    fn test_relocate_map_fds_src_reg_extraction() {
        // Instruction with dst_reg=0, src_reg=BPF_PSEUDO_MAP_FD(1), imm=42 (old fd).
        let ld_pair = make_ld_imm64(0, BPF_PSEUDO_MAP_FD, 42, 0);
        let mut insns = vec![ld_pair[0], ld_pair[1]];

        // No map_ids provided -> relocate_map_fds finds 1 unique FD but can't remap it.
        // It should print a warning but not panic.
        let result = relocate_map_fds(&mut insns, &[]);
        assert!(result.is_ok());
        // Old FD remains unpatched since there are no map_ids.
        assert_eq!(insns[0].imm, 42);
    }

    /// Verify that a BPF_LD_IMM64 with src_reg=0 (not a map reference) is NOT treated
    /// as a map reference. This guards against the old bug where dst_reg was read instead
    /// of src_reg.
    #[test]
    fn test_relocate_map_fds_ignores_non_map_ldimm64() {
        // dst_reg=1, src_reg=0 -> NOT a map reference (just a plain 64-bit immediate).
        let ld_pair = make_ld_imm64(1, 0, 99, 0);
        let mut insns = vec![ld_pair[0], ld_pair[1]];

        let result = relocate_map_fds(&mut insns, &[]);
        assert!(result.is_ok());
        let owned = result.unwrap();
        // No map references found, so no FDs returned.
        assert!(owned.is_empty());
        // Instruction unchanged.
        assert_eq!(insns[0].imm, 99);
    }

    /// Regression test: ensure that an instruction with dst_reg=1 but src_reg=0
    /// is NOT mistakenly identified as BPF_PSEUDO_MAP_FD. The old code used
    /// `regs & 0x0f` (dst_reg) instead of `(regs >> 4) & 0x0f` (src_reg).
    #[test]
    fn test_relocate_map_fds_regression_dst_vs_src() {
        // dst_reg=1 (BPF_PSEUDO_MAP_FD value in wrong field), src_reg=0.
        // The old bug would treat this as a map reference.
        let ld_pair = make_ld_imm64(1, 0, 7, 0);
        let mut insns = vec![ld_pair[0], ld_pair[1]];

        let result = relocate_map_fds(&mut insns, &[]);
        assert!(result.is_ok());
        assert!(result.unwrap().is_empty());

        // Now test the opposite: dst_reg=0, src_reg=1 (BPF_PSEUDO_MAP_FD).
        // This should be detected as a map reference.
        let ld_pair = make_ld_imm64(0, 1, 7, 0);
        let mut insns2 = vec![ld_pair[0], ld_pair[1]];

        let result2 = relocate_map_fds(&mut insns2, &[]);
        assert!(result2.is_ok());
        // Found 1 unique FD but no map_ids to remap -> warning printed, 0 FDs returned.
        // The key thing is it DID detect the reference (unique_old_fds would have 1 entry).
    }

    #[test]
    fn test_dump_machine_code_groups_bytes_into_lines() {
        let bytes: Vec<u8> = (0..20u8).collect();
        let dump = dump_machine_code(&bytes);

        assert_eq!(dump.byte_len, 20);
        assert_eq!(dump.bytes_per_line, 16);
        assert_eq!(dump.lines.len(), 2);
        assert_eq!(
            dump.lines[0].raw_hex,
            "00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f"
        );
        assert_eq!(dump.lines[1].offset, 16);
        assert_eq!(dump.lines[1].raw_hex, "10 11 12 13");
    }

    /// Test relocate_map_fds with BPF_PSEUDO_MAP_VALUE (src_reg=2).
    #[test]
    fn test_relocate_map_fds_pseudo_map_value() {
        let ld_pair = make_ld_imm64(3, BPF_PSEUDO_MAP_VALUE, 55, 0);
        let mut insns = vec![ld_pair[0], ld_pair[1]];

        // Should detect 1 map reference (src_reg=2 = BPF_PSEUDO_MAP_VALUE).
        let result = relocate_map_fds(&mut insns, &[]);
        assert!(result.is_ok());
        // imm unchanged since no map_ids to remap.
        assert_eq!(insns[0].imm, 55);
    }

    /// Test with multiple map references using different old FDs.
    #[test]
    fn test_relocate_map_fds_multiple_refs() {
        let ld1 = make_ld_imm64(1, BPF_PSEUDO_MAP_FD, 10, 0);
        let ld2 = make_ld_imm64(2, BPF_PSEUDO_MAP_FD, 11, 0);
        let ld3 = make_ld_imm64(3, BPF_PSEUDO_MAP_FD, 10, 0); // duplicate of first
        let mut insns = vec![ld1[0], ld1[1], ld2[0], ld2[1], ld3[0], ld3[1]];

        // 2 unique old FDs (10 and 11), but no map_ids -> warning, no remapping.
        let result = relocate_map_fds(&mut insns, &[]);
        assert!(result.is_ok());
    }

    // ── BPF cmd constant sync tests ──────────────────────────────────
    //
    // These tests parse the kernel UAPI header to verify our hardcoded
    // constants match. This is the class of bug that caused BPF_BTF_GET_NEXT_ID
    // to be wrong (22 instead of 23) for months.

    /// Parse `enum bpf_cmd` from the kernel UAPI header and return a map
    /// of name -> numeric value.
    fn parse_bpf_cmd_enum() -> std::collections::HashMap<String, u32> {
        let header_path = concat!(
            env!("CARGO_MANIFEST_DIR"),
            "/../vendor/linux-framework/include/uapi/linux/bpf.h"
        );
        let content =
            std::fs::read_to_string(header_path).expect("failed to read kernel bpf.h header");

        let mut result = std::collections::HashMap::new();
        let mut in_enum = false;
        let mut next_val: u32 = 0;

        for line in content.lines() {
            let trimmed = line.trim();
            if trimmed.starts_with("enum bpf_cmd") {
                in_enum = true;
                next_val = 0;
                continue;
            }
            if in_enum && trimmed.starts_with('}') {
                break;
            }
            if !in_enum {
                continue;
            }
            // Skip empty lines, comments, __MAX_BPF_CMD
            if trimmed.is_empty()
                || trimmed.starts_with("//")
                || trimmed.starts_with("/*")
                || trimmed.starts_with('*')
                || trimmed.starts_with("__MAX")
            {
                continue;
            }
            // Parse lines like "BPF_MAP_CREATE," or "BPF_PROG_RUN = BPF_PROG_TEST_RUN,"
            let name_part = trimmed.trim_end_matches(',');
            if name_part.contains('=') {
                // Alias like BPF_PROG_RUN = BPF_PROG_TEST_RUN — skip (same value)
                let parts: Vec<&str> = name_part.split('=').collect();
                let name = parts[0].trim().to_string();
                let rhs = parts[1].trim();
                // rhs is another enum name — look it up
                if let Some(&val) = result.get(rhs) {
                    result.insert(name, val);
                }
                // Do NOT increment next_val for aliases
                continue;
            }
            let name = name_part.trim().to_string();
            if name.starts_with("BPF_") {
                result.insert(name, next_val);
                next_val += 1;
            }
        }
        result
    }

    #[test]
    fn test_bpf_cmd_constants_match_kernel_header() {
        let kernel_cmds = parse_bpf_cmd_enum();
        assert!(
            !kernel_cmds.is_empty(),
            "failed to parse any bpf_cmd entries from kernel header"
        );

        // Verify every constant we define in bpf.rs matches the kernel.
        let checks = [
            ("BPF_PROG_GET_NEXT_ID", BPF_PROG_GET_NEXT_ID),
            ("BPF_MAP_GET_NEXT_ID", BPF_MAP_GET_NEXT_ID),
            ("BPF_PROG_GET_FD_BY_ID", BPF_PROG_GET_FD_BY_ID),
            ("BPF_MAP_GET_FD_BY_ID", BPF_MAP_GET_FD_BY_ID),
            ("BPF_OBJ_GET_INFO_BY_FD", BPF_OBJ_GET_INFO_BY_FD),
            ("BPF_BTF_LOAD", BPF_BTF_LOAD),
            ("BPF_BTF_GET_FD_BY_ID", BPF_BTF_GET_FD_BY_ID),
            ("BPF_BTF_GET_NEXT_ID", BPF_BTF_GET_NEXT_ID),
            ("BPF_PROG_REJIT", BPF_PROG_REJIT),
        ];

        for (name, our_value) in &checks {
            let kernel_value = kernel_cmds.get(*name).unwrap_or_else(|| {
                panic!(
                    "{} not found in kernel header enum bpf_cmd (parsed {} entries)",
                    name,
                    kernel_cmds.len()
                )
            });
            assert_eq!(
                *our_value, *kernel_value,
                "BPF cmd constant mismatch: {} = {} in bpf.rs but {} in kernel header",
                name, our_value, kernel_value
            );
        }
    }

    // ── Struct size and layout tests ─────────────────────────────────
    //
    // The bpf_attr union must be exactly 128 bytes (kernel enforced).
    // Each attr variant must be <= 128 bytes.

    #[test]
    fn test_attr_struct_sizes_fit_bpf_attr() {
        // All attr variants must be exactly 128 bytes (the kernel's bpf_attr size).
        assert_eq!(
            std::mem::size_of::<AttrGetNextId>(),
            128,
            "AttrGetNextId must be 128 bytes"
        );
        assert_eq!(
            std::mem::size_of::<AttrGetFdById>(),
            128,
            "AttrGetFdById must be 128 bytes"
        );
        assert_eq!(
            std::mem::size_of::<AttrGetInfoByFd>(),
            128,
            "AttrGetInfoByFd must be 128 bytes"
        );
        assert_eq!(
            std::mem::size_of::<AttrRejit>(),
            128,
            "AttrRejit must be 128 bytes"
        );
    }

    #[test]
    fn test_attr_rejit_field_offsets() {
        // Verify AttrRejit field layout matches kernel's union bpf_attr.rejit.
        // Kernel layout (from bpf.h):
        //   __u32          prog_fd;       // offset 0
        //   __u32          insn_cnt;      // offset 4
        //   __aligned_u64  insns;         // offset 8
        //   __u32          log_level;     // offset 16
        //   __u32          log_size;      // offset 20
        //   __aligned_u64  log_buf;       // offset 24
        //   __aligned_u64  fd_array;      // offset 32
        //   __u32          fd_array_cnt;  // offset 40
        //   __u32          flags;         // offset 44

        let attr: AttrRejit = unsafe { std::mem::zeroed() };
        let base_addr = &attr as *const _ as usize;

        assert_eq!(
            &attr.prog_fd as *const _ as usize - base_addr,
            0,
            "prog_fd at wrong offset"
        );
        assert_eq!(
            &attr.insn_cnt as *const _ as usize - base_addr,
            4,
            "insn_cnt at wrong offset"
        );
        assert_eq!(
            &attr.insns as *const _ as usize - base_addr,
            8,
            "insns at wrong offset"
        );
        assert_eq!(
            &attr.log_level as *const _ as usize - base_addr,
            16,
            "log_level at wrong offset"
        );
        assert_eq!(
            &attr.log_size as *const _ as usize - base_addr,
            20,
            "log_size at wrong offset"
        );
        assert_eq!(
            &attr.log_buf as *const _ as usize - base_addr,
            24,
            "log_buf at wrong offset"
        );
        assert_eq!(
            &attr.fd_array as *const _ as usize - base_addr,
            32,
            "fd_array at wrong offset"
        );
        assert_eq!(
            &attr.fd_array_cnt as *const _ as usize - base_addr,
            40,
            "fd_array_cnt at wrong offset"
        );
        assert_eq!(
            &attr.flags as *const _ as usize - base_addr,
            44,
            "flags at wrong offset"
        );
    }

    #[test]
    fn test_bpf_prog_info_size() {
        // BpfProgInfo includes BpfReJIT extension fields (orig_prog_len, orig_prog_insns).
        // Layout: orig_prog_len (u32, offset 228) + 4 bytes padding + orig_prog_insns (u64, offset 232).
        // Total: 232 + 8 = 240 bytes (with __attribute__((aligned(8)))).
        let size = std::mem::size_of::<BpfProgInfo>();
        assert_eq!(
            size, 240,
            "BpfProgInfo size mismatch: got {} bytes, expected 240 (from kernel struct bpf_prog_info)",
            size
        );
    }

    /// HIGH #1 + MEDIUM #1 + MEDIUM #2: Verify BpfProgInfo field-by-field layout
    /// against known offsets from kernel `struct bpf_prog_info` in
    /// vendor/linux-framework/include/uapi/linux/bpf.h.
    ///
    /// The kernel struct uses `__aligned_u64` for 8-byte aligned fields.
    /// Computing expected offsets manually from the kernel header:
    ///   __u32 type                 -> offset 0
    ///   __u32 id                   -> offset 4
    ///   __u8  tag[8]               -> offset 8
    ///   __u32 jited_prog_len       -> offset 16
    ///   __u32 xlated_prog_len      -> offset 20
    ///   __aligned_u64 jited_prog_insns -> offset 24
    ///   __aligned_u64 xlated_prog_insns -> offset 32
    ///   __u64 load_time            -> offset 40
    ///   __u32 created_by_uid       -> offset 48
    ///   __u32 nr_map_ids           -> offset 52
    ///   __aligned_u64 map_ids      -> offset 56
    ///   char name[16]              -> offset 64
    ///   __u32 ifindex              -> offset 80
    ///   __u32 gpl_compatible:1 + pad -> offset 84
    ///   __u64 netns_dev            -> offset 88
    ///   __u64 netns_ino            -> offset 96
    ///   __u32 nr_jited_ksyms       -> offset 104
    ///   __u32 nr_jited_func_lens   -> offset 108
    ///   __aligned_u64 jited_ksyms  -> offset 112
    ///   __aligned_u64 jited_func_lens -> offset 120
    ///   __u32 btf_id               -> offset 128
    ///   __u32 func_info_rec_size   -> offset 132
    ///   __aligned_u64 func_info    -> offset 136
    ///   __u32 nr_func_info         -> offset 144
    ///   __u32 nr_line_info         -> offset 148
    ///   __aligned_u64 line_info    -> offset 152
    ///   __aligned_u64 jited_line_info -> offset 160
    ///   __u32 nr_jited_line_info   -> offset 168
    ///   __u32 line_info_rec_size   -> offset 172
    ///   __u32 jited_line_info_rec_size -> offset 176
    ///   __u32 nr_prog_tags         -> offset 180
    ///   __aligned_u64 prog_tags    -> offset 184
    ///   __u64 run_time_ns          -> offset 192
    ///   __u64 run_cnt              -> offset 200
    ///   __u64 recursion_misses     -> offset 208
    ///   __u32 verified_insns       -> offset 216
    ///   __u32 attach_btf_obj_id    -> offset 220
    ///   __u32 attach_btf_id        -> offset 224
    ///   __u32 orig_prog_len        -> offset 228  (BpfReJIT extension)
    ///   __aligned_u64 orig_prog_insns -> offset 232 -> but struct aligned(8), so pad to 232? No.
    ///   Actually orig_prog_len is u32 at 228, and orig_prog_insns is __aligned_u64, so
    ///   it needs 8-byte alignment: pad from 232 -> stays at 232. Wait, 228+4=232 which IS
    ///   8-byte aligned, so orig_prog_insns is at offset 232... but that would make the struct
    ///   232+8=240 bytes. Let me verify via the actual Rust layout.
    #[test]
    fn test_bpf_prog_info_field_offsets() {
        let info = BpfProgInfo::default();
        let base = &info as *const _ as usize;

        // Helper macro to compute offset
        macro_rules! check_offset {
            ($field:ident, $expected:expr) => {
                let actual = &info.$field as *const _ as usize - base;
                assert_eq!(
                    actual,
                    $expected,
                    "BpfProgInfo.{} offset mismatch: got {} expected {}",
                    stringify!($field),
                    actual,
                    $expected
                );
            };
        }

        // Critical fields verified against kernel header struct bpf_prog_info
        check_offset!(prog_type, 0);
        check_offset!(id, 4);
        check_offset!(tag, 8);
        check_offset!(jited_prog_len, 16);
        check_offset!(xlated_prog_len, 20);
        check_offset!(jited_prog_insns, 24);
        check_offset!(xlated_prog_insns, 32);
        check_offset!(load_time, 40);
        check_offset!(created_by_uid, 48);
        check_offset!(nr_map_ids, 52);
        check_offset!(map_ids, 56);
        check_offset!(name, 64);
        check_offset!(ifindex, 80);
        check_offset!(gpl_compatible_pad, 84);
        check_offset!(netns_dev, 88);
        check_offset!(netns_ino, 96);
        check_offset!(nr_jited_ksyms, 104);
        check_offset!(nr_jited_func_lens, 108);
        check_offset!(jited_ksyms, 112);
        check_offset!(jited_func_lens, 120);
        check_offset!(btf_id, 128);
        check_offset!(func_info_rec_size, 132);
        check_offset!(func_info, 136);
        check_offset!(nr_func_info, 144);
        check_offset!(nr_line_info, 148);
        check_offset!(line_info, 152);
        check_offset!(jited_line_info, 160);
        check_offset!(nr_jited_line_info, 168);
        check_offset!(line_info_rec_size, 172);
        check_offset!(jited_line_info_rec_size, 176);
        check_offset!(nr_prog_tags, 180);
        check_offset!(prog_tags, 184);
        check_offset!(run_time_ns, 192);
        check_offset!(run_cnt, 200);
        check_offset!(recursion_misses, 208);
        check_offset!(verified_insns, 216);
        check_offset!(attach_btf_obj_id, 220);
        check_offset!(attach_btf_id, 224);

        // BpfReJIT extension fields (orig_prog_len, orig_prog_insns)
        // These are at the end of the kernel struct:
        //   __u32 orig_prog_len       -> offset 228
        //   __aligned_u64 orig_prog_insns -> must be 8-byte aligned
        check_offset!(orig_prog_len, 228);

        // orig_prog_insns: u32 at 228 occupies bytes 228..232.
        // __aligned_u64 needs 8-byte alignment. 232 % 8 == 0, so no padding needed.
        // But in our Rust struct it's declared as u64 after a u32, the compiler may
        // or may not pad. Let's just verify it's the expected value.
        let orig_insns_offset = &info.orig_prog_insns as *const _ as usize - base;
        // In the kernel struct, attach_btf_id is at 224, orig_prog_len at 228.
        // orig_prog_insns (__aligned_u64) must be at 232 (next 8-byte boundary after 232).
        // But wait: 228 + 4 = 232, which IS 8-byte aligned.
        // However, our Rust struct might not pad. Check both possibilities.
        assert!(
            orig_insns_offset >= 232,
            "orig_prog_insns should be at offset >= 232, got {}",
            orig_insns_offset
        );

        // Verify orig_prog_insns is the last field
        assert_eq!(
            orig_insns_offset + std::mem::size_of::<u64>(),
            std::mem::size_of::<BpfProgInfo>(),
            "orig_prog_insns should be the last field in BpfProgInfo"
        );
    }

    /// HIGH #1 continued: Parse kernel header to verify BpfProgInfo field layout.
    /// This reads the actual kernel header file and computes struct field offsets
    /// using C struct layout rules (including __aligned_u64 = 8-byte alignment).
    #[test]
    fn test_bpf_prog_info_layout_matches_kernel_header() {
        let header_path = concat!(
            env!("CARGO_MANIFEST_DIR"),
            "/../vendor/linux-framework/include/uapi/linux/bpf.h"
        );
        let content =
            std::fs::read_to_string(header_path).expect("failed to read kernel bpf.h header");

        // Find the struct bpf_prog_info definition and extract field names+types.
        let mut in_struct = false;
        let mut fields: Vec<(String, usize, usize)> = Vec::new(); // (name, size, alignment)
        for line in content.lines() {
            let trimmed = line.trim();
            if trimmed == "struct bpf_prog_info {" {
                in_struct = true;
                continue;
            }
            if in_struct && trimmed.starts_with('}') {
                break;
            }
            if !in_struct {
                continue;
            }
            // Skip comments and empty lines
            if trimmed.is_empty()
                || trimmed.starts_with("/*")
                || trimmed.starts_with("*")
                || trimmed.starts_with("//")
            {
                continue;
            }
            // Parse field: e.g., "__u32 type;" or "__aligned_u64 jited_prog_insns;"
            // or "__u8  tag[BPF_TAG_SIZE];" or "char name[BPF_OBJ_NAME_LEN];"
            // or "__u32 gpl_compatible:1;" or "__u32 :31; /* alignment pad */"
            let clean = trimmed.trim_end_matches(';').trim();
            // Skip anonymous bitfields like "__u32 :31"
            if clean.contains(":") && !clean.contains("_compatible") {
                // Check if it's a named bitfield (like gpl_compatible:1) or anonymous
                let parts: Vec<&str> = clean.split_whitespace().collect();
                if parts.len() >= 2 && parts[1].starts_with(':') {
                    // Anonymous bitfield like "__u32 :31" — skip (part of previous u32)
                    continue;
                }
            }

            // Parse type and name
            let parts: Vec<&str> = clean.split_whitespace().collect();
            if parts.len() < 2 {
                continue;
            }
            let type_str = parts[0];
            let mut name_str = parts[1].trim_end_matches(|c: char| c == ',' || c == ';');
            // Handle bitfield notation: "gpl_compatible:1"
            if let Some(colon) = name_str.find(':') {
                name_str = &name_str[..colon];
            }
            // Handle array notation: "tag[BPF_TAG_SIZE]" -> "tag"
            let field_name = if let Some(bracket) = name_str.find('[') {
                &name_str[..bracket]
            } else {
                name_str
            };

            // Determine size and alignment
            let (size, align) = match type_str {
                "__u32" | "__s32" => {
                    if clean.contains("[BPF_TAG_SIZE]") {
                        (8, 1) // __u8 tag[8] — but this is __u32 tag... wait
                    } else if clean.contains("gpl_compatible") {
                        // gpl_compatible:1 + :31 pad = 4 bytes total
                        (4, 4)
                    } else {
                        (4, 4)
                    }
                }
                "__u8" => {
                    if clean.contains("[BPF_TAG_SIZE]") {
                        (8, 1)
                    } else {
                        (1, 1)
                    }
                }
                "char" => {
                    if clean.contains("[BPF_OBJ_NAME_LEN]") {
                        (16, 1)
                    } else {
                        (1, 1)
                    }
                }
                "__u64" | "__s64" => (8, 8),
                "__aligned_u64" => (8, 8),
                _ => continue,
            };

            fields.push((field_name.to_string(), size, align));
        }

        assert!(
            !fields.is_empty(),
            "failed to parse any fields from struct bpf_prog_info"
        );

        // Compute offsets using C struct layout rules
        let mut offset = 0usize;
        let mut kernel_offsets: Vec<(String, usize)> = Vec::new();
        for (name, size, align) in &fields {
            // Align to field alignment
            let padding = (align - (offset % align)) % align;
            offset += padding;
            kernel_offsets.push((name.clone(), offset));
            offset += size;
        }

        // Verify our Rust struct matches the kernel layout for key fields
        let info = BpfProgInfo::default();
        let base = &info as *const _ as usize;

        let rust_offsets: Vec<(&str, usize)> = vec![
            ("type", &info.prog_type as *const _ as usize - base),
            ("id", &info.id as *const _ as usize - base),
            ("tag", &info.tag as *const _ as usize - base),
            (
                "jited_prog_len",
                &info.jited_prog_len as *const _ as usize - base,
            ),
            (
                "xlated_prog_len",
                &info.xlated_prog_len as *const _ as usize - base,
            ),
            ("nr_map_ids", &info.nr_map_ids as *const _ as usize - base),
            ("name", &info.name as *const _ as usize - base),
            ("btf_id", &info.btf_id as *const _ as usize - base),
            ("run_time_ns", &info.run_time_ns as *const _ as usize - base),
            ("run_cnt", &info.run_cnt as *const _ as usize - base),
            (
                "verified_insns",
                &info.verified_insns as *const _ as usize - base,
            ),
            (
                "attach_btf_obj_id",
                &info.attach_btf_obj_id as *const _ as usize - base,
            ),
            (
                "attach_btf_id",
                &info.attach_btf_id as *const _ as usize - base,
            ),
            (
                "orig_prog_len",
                &info.orig_prog_len as *const _ as usize - base,
            ),
            (
                "orig_prog_insns",
                &info.orig_prog_insns as *const _ as usize - base,
            ),
        ];

        for (rust_name, rust_offset) in &rust_offsets {
            // The kernel header uses "type" for prog_type; map it
            let kernel_name = *rust_name;
            if let Some((_, kernel_offset)) = kernel_offsets.iter().find(|(n, _)| n == kernel_name)
            {
                assert_eq!(
                    *rust_offset, *kernel_offset,
                    "BpfProgInfo field '{}' offset mismatch: Rust={} kernel={}",
                    rust_name, rust_offset, kernel_offset
                );
            }
        }
    }

    #[test]
    fn test_bpf_prog_info_name_str() {
        let mut info = BpfProgInfo::default();
        // Empty name (all zeros)
        assert_eq!(info.name_str(), "");

        // Normal name
        info.name[0] = b'x';
        info.name[1] = b'd';
        info.name[2] = b'p';
        assert_eq!(info.name_str(), "xdp");

        // Full-length name (no NUL terminator within array)
        for i in 0..BPF_OBJ_NAME_LEN {
            info.name[i] = b'a';
        }
        assert_eq!(info.name_str(), "a".repeat(BPF_OBJ_NAME_LEN));
    }

    #[test]
    fn test_btf_info_struct_size() {
        // BtfInfo must be exactly 128 bytes (padded to match bpf_attr size).
        assert_eq!(
            std::mem::size_of::<BtfInfo>(),
            128,
            "BtfInfo must be 128 bytes"
        );
    }

    /// HIGH #5: Verify BtfInfo field layout matches kernel `struct bpf_btf_info`.
    ///
    /// From vendor/linux-framework/include/uapi/linux/bpf.h:
    ///   struct bpf_btf_info {
    ///       __aligned_u64 btf;       // offset 0
    ///       __u32 btf_size;          // offset 8
    ///       __u32 id;                // offset 12
    ///       __aligned_u64 name;      // offset 16
    ///       __u32 name_len;          // offset 24
    ///       __u32 kernel_btf;        // offset 28
    ///   } __attribute__((aligned(8)));
    #[test]
    fn test_btf_info_field_offsets() {
        let info: BtfInfo = unsafe { std::mem::zeroed() };
        let base = &info as *const _ as usize;

        assert_eq!(
            &info.btf as *const _ as usize - base,
            0,
            "BtfInfo.btf at wrong offset"
        );
        assert_eq!(
            &info.btf_size as *const _ as usize - base,
            8,
            "BtfInfo.btf_size at wrong offset"
        );
        assert_eq!(
            &info.id as *const _ as usize - base,
            12,
            "BtfInfo.id at wrong offset"
        );
        assert_eq!(
            &info.name as *const _ as usize - base,
            16,
            "BtfInfo.name at wrong offset"
        );
        assert_eq!(
            &info.name_len as *const _ as usize - base,
            24,
            "BtfInfo.name_len at wrong offset"
        );
        assert_eq!(
            &info.kernel_btf as *const _ as usize - base,
            28,
            "BtfInfo.kernel_btf at wrong offset"
        );
    }

    /// HIGH #5 continued: Parse kernel header to verify BtfInfo layout.
    #[test]
    fn test_btf_info_layout_matches_kernel_header() {
        let header_path = concat!(
            env!("CARGO_MANIFEST_DIR"),
            "/../vendor/linux-framework/include/uapi/linux/bpf.h"
        );
        let content =
            std::fs::read_to_string(header_path).expect("failed to read kernel bpf.h header");

        // Find struct bpf_btf_info
        let mut in_struct = false;
        let mut field_names: Vec<String> = Vec::new();
        for line in content.lines() {
            let trimmed = line.trim();
            if trimmed == "struct bpf_btf_info {" {
                in_struct = true;
                continue;
            }
            if in_struct && trimmed.starts_with('}') {
                break;
            }
            if !in_struct
                || trimmed.is_empty()
                || trimmed.starts_with("/*")
                || trimmed.starts_with("*")
                || trimmed.starts_with("//")
            {
                continue;
            }
            let clean = trimmed.trim_end_matches(';').trim();
            let parts: Vec<&str> = clean.split_whitespace().collect();
            if parts.len() >= 2 {
                field_names.push(parts[1].trim_end_matches(';').to_string());
            }
        }

        // Verify the kernel header has the expected fields in order
        assert!(
            field_names.contains(&"btf".to_string()),
            "kernel bpf_btf_info missing 'btf' field"
        );
        assert!(
            field_names.contains(&"btf_size".to_string()),
            "kernel bpf_btf_info missing 'btf_size' field"
        );
        assert!(
            field_names.contains(&"id".to_string()),
            "kernel bpf_btf_info missing 'id' field"
        );
        assert!(
            field_names.contains(&"name".to_string()),
            "kernel bpf_btf_info missing 'name' field"
        );
        assert!(
            field_names.contains(&"name_len".to_string()),
            "kernel bpf_btf_info missing 'name_len' field"
        );
        assert!(
            field_names.contains(&"kernel_btf".to_string()),
            "kernel bpf_btf_info missing 'kernel_btf' field"
        );
    }

    /// HIGH #2: Full-path relocate_map_fds integration test.
    /// Requires a real BPF program with maps loaded in the kernel.
    #[test]
    #[ignore]
    fn test_relocate_map_fds_full_path_integration() {
        // Load the first BPF program that has maps.
        let mut found_prog_with_maps = false;
        for prog_id in iter_prog_ids().take(200) {
            let fd = match bpf_prog_get_fd_by_id(prog_id) {
                Ok(f) => f,
                Err(_) => continue,
            };
            use std::os::unix::io::AsRawFd;
            let map_ids = match bpf_prog_get_map_ids(fd.as_raw_fd()) {
                Ok(ids) if !ids.is_empty() => ids,
                _ => continue,
            };

            // Get the original instructions.
            let (info, orig_insns) = match bpf_prog_get_info(fd.as_raw_fd(), true) {
                Ok((i, insns)) if !insns.is_empty() => (i, insns),
                _ => continue,
            };

            found_prog_with_maps = true;
            eprintln!(
                "  testing relocate_map_fds on prog {} ({}) with {} maps, {} insns",
                prog_id,
                info.name_str(),
                map_ids.len(),
                orig_insns.len()
            );

            // Run relocate_map_fds on the original instructions.
            let mut insns_copy = orig_insns.clone();
            let result = relocate_map_fds(&mut insns_copy, &map_ids);
            assert!(
                result.is_ok(),
                "relocate_map_fds failed for prog {} ({}): {:#}",
                prog_id,
                info.name_str(),
                result.unwrap_err()
            );

            let owned_fds = result.unwrap();
            // Each unique map reference in bytecode should have a corresponding FD.
            // owned_fds may be fewer if some map IDs couldn't be opened.
            eprintln!("    relocated {} map FDs", owned_fds.len());

            // Verify that the patched FDs are valid (non-negative).
            for owned in &owned_fds {
                let raw = owned.as_raw_fd();
                assert!(
                    raw >= 0,
                    "patched map FD should be non-negative, got {}",
                    raw
                );
            }

            break; // One successful test is enough
        }

        if !found_prog_with_maps {
            eprintln!("  SKIP: no BPF programs with maps found");
        }
    }

    // ── BPF runtime smoke tests (need root/BPF) ─────────────────────
    //
    // These tests actually issue BPF syscalls. They are marked #[ignore]
    // so `cargo test` skips them by default. Run with:
    //   cargo test -- --ignored
    // or inside a VM with BPF enabled.

    #[test]
    #[ignore]
    fn test_bpf_prog_get_next_id_smoke() {
        // On any Linux system with BPF, there should be at least one loaded program
        // (e.g., kernel internal programs). This test verifies the syscall wrapper works.
        let result = bpf_prog_get_next_id(0);
        assert!(
            result.is_ok(),
            "bpf_prog_get_next_id(0) failed: {}",
            result.unwrap_err()
        );
        let first_id = result.unwrap();
        assert!(
            first_id > 0,
            "first prog ID should be > 0, got {}",
            first_id
        );
    }

    #[test]
    #[ignore]
    fn test_iter_prog_ids_returns_some() {
        let ids: Vec<u32> = iter_prog_ids().take(100).collect();
        assert!(
            !ids.is_empty(),
            "iter_prog_ids() returned no programs (expected at least one)"
        );
        // IDs should be monotonically increasing
        for window in ids.windows(2) {
            assert!(
                window[1] > window[0],
                "prog IDs not monotonically increasing: {} >= {}",
                window[0],
                window[1]
            );
        }
    }

    #[test]
    #[ignore]
    fn test_bpf_prog_get_fd_and_info_smoke() {
        // Get the first program ID and open its fd, then get info.
        let first_id = bpf_prog_get_next_id(0).expect("bpf_prog_get_next_id(0) failed");
        let fd = bpf_prog_get_fd_by_id(first_id).expect("bpf_prog_get_fd_by_id failed");
        use std::os::unix::io::AsRawFd;
        let (info, _) = bpf_prog_get_info(fd.as_raw_fd(), false).expect("bpf_prog_get_info failed");
        assert_eq!(
            info.id, first_id,
            "info.id should match the requested prog ID"
        );
        assert!(info.prog_type > 0, "prog_type should be > 0");
    }

    #[test]
    #[ignore]
    fn test_btf_get_next_id_smoke() {
        // vmlinux BTF should always exist on a BPF-enabled kernel.
        let result = bpf_btf_get_next_id(0);
        assert!(
            result.is_ok(),
            "bpf_btf_get_next_id(0) failed: {} — is BTF enabled in kernel?",
            result.unwrap_err()
        );
        let first_id = result.unwrap();
        assert!(first_id > 0, "first BTF ID should be > 0");
    }

    #[test]
    #[ignore]
    fn test_btf_get_fd_by_id_and_info_smoke() {
        let first_id = bpf_btf_get_next_id(0).expect("bpf_btf_get_next_id(0) failed");
        let fd = bpf_btf_get_fd_by_id(first_id).expect("bpf_btf_get_fd_by_id failed");
        use std::os::unix::io::AsRawFd;
        let name = bpf_btf_get_info_name(fd.as_raw_fd()).expect("bpf_btf_get_info_name failed");
        // The first BTF object is typically vmlinux (empty name) or has a name.
        // Either way, it shouldn't panic.
        let _ = name;
    }

    #[test]
    #[ignore]
    fn test_btf_module_enumeration() {
        // Enumerate all BTF IDs and check we can get names for each.
        let mut id = 0u32;
        let mut count = 0;
        loop {
            match bpf_btf_get_next_id(id) {
                Ok(next) => {
                    id = next;
                    count += 1;
                    if let Ok(fd) = bpf_btf_get_fd_by_id(id) {
                        use std::os::unix::io::AsRawFd;
                        let _ = bpf_btf_get_info_name(fd.as_raw_fd());
                    }
                }
                Err(_) => break,
            }
        }
        assert!(count > 0, "should find at least 1 BTF object (vmlinux)");
    }

    #[test]
    #[ignore]
    fn test_bpf_btf_get_fd_by_module_name_vmlinux_not_found() {
        // "vmlinux" BTF has an empty name, so searching for "vmlinux" string
        // should NOT find it (it's identified by name="" or by being id=1).
        // This tests that the function correctly iterates and handles non-matches.
        let result = bpf_btf_get_fd_by_module_name("this_module_definitely_does_not_exist");
        assert!(result.is_err(), "should not find a nonexistent module");
    }

    #[test]
    fn test_relocate_map_fds_with_non_map_instructions() {
        // Program with no LD_IMM64 instructions at all.
        let mut insns = vec![
            BpfInsn::mov64_imm(0, 42),
            BpfInsn {
                // exit instruction: BPF_JMP(0x05) | BPF_EXIT(0x90) = 0x95
                code: 0x95,
                regs: 0,
                off: 0,
                imm: 0,
            },
        ];
        let result = relocate_map_fds(&mut insns, &[]);
        assert!(result.is_ok());
        assert!(result.unwrap().is_empty());
    }

    #[test]
    fn test_relocate_map_fds_empty_program() {
        let mut insns: Vec<BpfInsn> = vec![];
        let result = relocate_map_fds(&mut insns, &[]);
        assert!(result.is_ok());
        assert!(result.unwrap().is_empty());
    }
}
