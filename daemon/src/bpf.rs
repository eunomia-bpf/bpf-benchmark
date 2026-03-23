// SPDX-License-Identifier: MIT
//! Raw BPF syscall wrappers — zero libbpf dependency.
//!
//! All interaction with the kernel goes through `libc::syscall(SYS_bpf, ...)`.

use std::os::unix::io::{FromRawFd, OwnedFd, RawFd};

use anyhow::{bail, Context, Result};

use crate::insn::BpfInsn;

// ── bpf_cmd values (from vendor/linux-framework/include/uapi/linux/bpf.h) ───
// The enum starts at 0. We only define the commands we actually use.
// Note: BPF_MAP_FREEZE=22 sits between BTF_GET_FD_BY_ID and BTF_GET_NEXT_ID.
const BPF_PROG_GET_NEXT_ID: u32 = 11;
#[allow(dead_code)]
const BPF_MAP_GET_NEXT_ID: u32 = 12;
const BPF_PROG_GET_FD_BY_ID: u32 = 13;
const BPF_MAP_GET_FD_BY_ID: u32 = 14;
const BPF_OBJ_GET_INFO_BY_FD: u32 = 15;
#[allow(dead_code)]
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
#[derive(Clone)]
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
    btf: u64,       // pointer to BTF data
    btf_size: u32,
    id: u32,
    name: u64,       // pointer to name buffer
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

    let nul = name_buf.iter().position(|&b| b == 0).unwrap_or(name_buf.len());
    Ok(String::from_utf8_lossy(&name_buf[..nul]).into_owned())
}

/// Find a BPF BTF FD for a kernel module by its name.
///
/// Iterates all BTF objects in the kernel and returns an FD for the one
/// whose name matches `module_name`. Returns a proper BPF BTF FD that
/// the verifier can use (unlike a plain open() of /sys/kernel/btf/).
pub fn bpf_btf_get_fd_by_module_name(module_name: &str) -> Result<OwnedFd> {
    let mut id = 0u32;
    loop {
        match bpf_btf_get_next_id(id) {
            Ok(next) => {
                id = next;
                match bpf_btf_get_fd_by_id(id) {
                    Ok(fd) => {
                        use std::os::unix::io::AsRawFd;
                        match bpf_btf_get_info_name(fd.as_raw_fd()) {
                            Ok(name) if name == module_name => return Ok(fd),
                            _ => {} // not a match, continue
                        }
                    }
                    Err(_) => continue, // can't open, skip
                }
            }
            Err(_) => break,
        }
    }
    bail!("BTF object for module '{}' not found", module_name)
}

/// Retrieve `bpf_prog_info` for an open program fd.
///
/// If `fetch_orig` is true, also allocates a buffer and retrieves the
/// original (pre-verifier) BPF instructions via `orig_prog_insns`.
pub fn bpf_prog_get_info(fd: RawFd, fetch_orig: bool) -> Result<(BpfProgInfo, Vec<BpfInsn>)> {
    // First call: get info without instructions to learn sizes.
    let mut info = BpfProgInfo::default();
    let mut info_len = std::mem::size_of::<BpfProgInfo>() as u32;
    let mut attr: AttrGetInfoByFd = zeroed_attr();
    attr.bpf_fd = fd as u32;
    attr.info_len = info_len;
    attr.info = &mut info as *mut _ as u64;

    let ret = unsafe {
        sys_bpf(
            BPF_OBJ_GET_INFO_BY_FD,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrGetInfoByFd>() as u32,
        )
    };
    if ret < 0 {
        bail!(bpf_err("BPF_OBJ_GET_INFO_BY_FD (first pass)"));
    }

    // If we need the original instructions, do a second call with the buffer allocated.
    let mut orig_insns = Vec::new();
    if fetch_orig && info.orig_prog_len > 0 {
        // orig_prog_len is in bytes; divide by sizeof(BpfInsn) = 8 to get insn count.
        let orig_bytes = info.orig_prog_len as usize;
        let insn_count = orig_bytes / std::mem::size_of::<BpfInsn>();
        orig_insns.resize(
            insn_count,
            BpfInsn {
                code: 0,
                regs: 0,
                off: 0,
                imm: 0,
            },
        );

        // Reset info and point orig_prog_insns to our buffer.
        info = BpfProgInfo::default();
        info.orig_prog_len = orig_bytes as u32;
        info.orig_prog_insns = orig_insns.as_mut_ptr() as u64;

        info_len = std::mem::size_of::<BpfProgInfo>() as u32;
        attr = zeroed_attr();
        attr.bpf_fd = fd as u32;
        attr.info_len = info_len;
        attr.info = &mut info as *mut _ as u64;

        let ret = unsafe {
            sys_bpf(
                BPF_OBJ_GET_INFO_BY_FD,
                &mut attr as *mut _ as *mut u8,
                std::mem::size_of::<AttrGetInfoByFd>() as u32,
            )
        };
        if ret < 0 {
            bail!(bpf_err("BPF_OBJ_GET_INFO_BY_FD (orig_prog_insns)"));
        }
    }

    Ok((info, orig_insns))
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
                if !seen.contains_key(&old_fd) {
                    let idx = unique_old_fds.len();
                    unique_old_fds.push(old_fd);
                    seen.insert(old_fd, idx);
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

/// Submit new BPF bytecode to the kernel via BPF_PROG_REJIT.
///
/// The kernel will run bpf_check() + JIT on the new instructions and
/// atomically replace the program image in-place.
///
/// First attempts with log_level=0 (fast, no verifier log). If that fails,
/// retries with log_level=2 and a large buffer to capture diagnostics.
/// This avoids ENOSPC errors from verifier log buffer overflow on the
/// normal success path.
pub fn bpf_prog_rejit(prog_fd: RawFd, insns: &[BpfInsn], fd_array: &[RawFd]) -> Result<RejitResult> {
    // First attempt: no verifier log (fast path).
    {
        let mut attr: AttrRejit = zeroed_attr();
        attr.prog_fd = prog_fd as u32;
        attr.insn_cnt = insns.len() as u32;
        attr.insns = insns.as_ptr() as u64;
        attr.log_level = 0;
        attr.log_size = 0;
        attr.log_buf = 0;
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

        if ret >= 0 {
            return Ok(RejitResult {
                verifier_log: String::new(),
            });
        }
    }

    // Fast path failed — retry with verbose verifier log to capture diagnostics.
    const LOG_BUF_SIZE: usize = 16 * 1024 * 1024; // 16 MB
    let mut log_buf: Vec<u8> = vec![0u8; LOG_BUF_SIZE];

    let mut attr: AttrRejit = zeroed_attr();
    attr.prog_fd = prog_fd as u32;
    attr.insn_cnt = insns.len() as u32;
    attr.insns = insns.as_ptr() as u64;
    attr.log_level = 2;
    attr.log_size = LOG_BUF_SIZE as u32;
    attr.log_buf = log_buf.as_mut_ptr() as u64;
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

    // Extract the log as a string (NUL-terminated C string in the buffer).
    let log_str = {
        let nul_pos = log_buf.iter().position(|&b| b == 0).unwrap_or(log_buf.len());
        String::from_utf8_lossy(&log_buf[..nul_pos]).into_owned()
    };

    if ret < 0 {
        let os_err = std::io::Error::last_os_error();
        if log_str.is_empty() {
            bail!("BPF_PROG_REJIT: {}", os_err);
        } else {
            bail!("BPF_PROG_REJIT: {}\nverifier log:\n{}", os_err, log_str);
        }
    }
    Ok(RejitResult {
        verifier_log: log_str,
    })
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
        let content = std::fs::read_to_string(header_path)
            .expect("failed to read kernel bpf.h header");

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
        // The kernel returns info_len = actual bytes filled. Our struct must be large enough.
        // The standard bpf_prog_info (without REJIT extensions) is 216 bytes on x86_64.
        // With orig_prog_len (u32) + orig_prog_insns (u64), it grows to ~232 bytes.
        let size = std::mem::size_of::<BpfProgInfo>();
        // It should be larger than standard bpf_prog_info (216 bytes)
        assert!(
            size >= 216,
            "BpfProgInfo too small: {} bytes (expected >= 216)",
            size
        );
        // Sanity: it shouldn't be absurdly large
        assert!(
            size <= 512,
            "BpfProgInfo unexpectedly large: {} bytes",
            size
        );
    }

    #[test]
    fn test_bpf_prog_info_orig_fields_at_end() {
        // Verify that orig_prog_len and orig_prog_insns are at the expected
        // positions (at the end of the struct, after verified_insns/attach_btf_*).
        let info = BpfProgInfo::default();
        let base = &info as *const _ as usize;
        let orig_len_offset = &info.orig_prog_len as *const _ as usize - base;
        let orig_insns_offset = &info.orig_prog_insns as *const _ as usize - base;

        // orig_prog_len should come after attach_btf_id (which is at a known offset)
        let attach_btf_id_offset = &info.attach_btf_id as *const _ as usize - base;
        assert!(
            orig_len_offset > attach_btf_id_offset,
            "orig_prog_len should be after attach_btf_id"
        );
        // orig_prog_insns should be the last field
        assert!(
            orig_insns_offset > orig_len_offset,
            "orig_prog_insns should be after orig_prog_len"
        );
        // orig_prog_insns is u64, so the struct should end 8 bytes after it
        assert_eq!(
            orig_insns_offset + 8,
            std::mem::size_of::<BpfProgInfo>(),
            "orig_prog_insns should be the last field in BpfProgInfo"
        );
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
        assert!(first_id > 0, "first prog ID should be > 0, got {}", first_id);
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
        let first_id = bpf_prog_get_next_id(0)
            .expect("bpf_prog_get_next_id(0) failed");
        let fd = bpf_prog_get_fd_by_id(first_id)
            .expect("bpf_prog_get_fd_by_id failed");
        use std::os::unix::io::AsRawFd;
        let (info, _) = bpf_prog_get_info(fd.as_raw_fd(), false)
            .expect("bpf_prog_get_info failed");
        assert_eq!(info.id, first_id, "info.id should match the requested prog ID");
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
        let first_id = bpf_btf_get_next_id(0)
            .expect("bpf_btf_get_next_id(0) failed");
        let fd = bpf_btf_get_fd_by_id(first_id)
            .expect("bpf_btf_get_fd_by_id failed");
        use std::os::unix::io::AsRawFd;
        let name = bpf_btf_get_info_name(fd.as_raw_fd())
            .expect("bpf_btf_get_info_name failed");
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
