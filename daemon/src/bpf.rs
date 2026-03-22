// SPDX-License-Identifier: MIT
//! Raw BPF syscall wrappers — zero libbpf dependency.
//!
//! All interaction with the kernel goes through `libc::syscall(SYS_bpf, ...)`.

use std::os::unix::io::{FromRawFd, OwnedFd, RawFd};

use anyhow::{bail, Context, Result};

use crate::insn::BpfInsn;

// ── bpf_cmd values (from include/uapi/linux/bpf.h) ─────────────────
// The enum starts at 0. We only define the commands we actually use.
const BPF_PROG_GET_NEXT_ID: u32 = 11; // BPF_MAP_GET_NEXT_ID = 12
const BPF_PROG_GET_FD_BY_ID: u32 = 13;
const BPF_OBJ_GET_INFO_BY_FD: u32 = 15;
// BPF_PROG_REJIT is the last entry before __MAX_BPF_CMD.
// From the enum: BPF_TOKEN_CREATE=36, BPF_PROG_STREAM_READ_BY_FD=37,
//                BPF_PROG_ASSOC_STRUCT_OPS=38, BPF_PROG_REJIT=39
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
    _pad: [u8; 128 - 44],
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
