//! Shared BPF kernel interaction helpers for bpfopt-suite tools.
//!
//! Upstream BPF UAPI types, constants, and libbpf helpers are re-exported from
//! `libbpf-rs`/`libbpf-sys`. The only direct `bpf(2)` wrappers here are for
//! fork-only commands that upstream libbpf does not expose.

use std::ffi::c_char;
use std::os::fd::{AsRawFd, BorrowedFd, FromRawFd, OwnedFd};

use anyhow::{anyhow, bail, Result};

pub use libbpf_rs::{
    libbpf_sys, Object, ObjectBuilder, OpenObject, Program, ProgramMut, ProgramType,
};
pub use libbpf_sys::*;

/// Fork-only `enum bpf_cmd` value for in-place BPF program ReJIT.
///
/// The current daemon wrapper defines this as the last command before
/// `__MAX_BPF_CMD` in the forked UAPI.
pub const BPF_PROG_REJIT: u32 = 39;

/// Fork-only `enum bpf_cmd` value for retrieving original load-time bytecode.
///
/// Current bpfrejit-daemon sources retrieve original bytecode through forked
/// `bpf_prog_info.orig_prog_*` fields. The v3 syscall API reserves the next
/// fork command slot for `BPF_PROG_GET_ORIGINAL`.
pub const BPF_PROG_GET_ORIGINAL: u32 = 40;

const DEFAULT_PROG_NAME: &[u8] = b"kernel_sys_dryrun\0";
const DEFAULT_LICENSE: &[u8] = b"GPL\0";

#[repr(C)]
#[derive(Debug, Copy, Clone)]
struct AttrRejit {
    prog_fd: u32,
    insn_cnt: u32,
    insns: u64,
    log_level: u32,
    log_size: u32,
    log_buf: u64,
    fd_array: u64,
    fd_array_cnt: u32,
    flags: u32,
    _pad: [u8; 128 - 48],
}

#[repr(C)]
#[derive(Debug, Copy, Clone)]
struct AttrGetOriginal {
    prog_fd: u32,
    insn_cnt: u32,
    insns: u64,
    _pad: [u8; 128 - 16],
}

fn zeroed<T>() -> T {
    unsafe { std::mem::zeroed() }
}

fn errno_from_libbpf_ret(ret: libc::c_int) -> i32 {
    if ret < 0 {
        -ret
    } else {
        std::io::Error::last_os_error()
            .raw_os_error()
            .unwrap_or(libc::EIO)
    }
}

fn os_error(errno: i32) -> std::io::Error {
    std::io::Error::from_raw_os_error(errno)
}

fn libbpf_error(context: &str, ret: libc::c_int) -> anyhow::Error {
    anyhow!("{context}: {}", os_error(errno_from_libbpf_ret(ret)))
}

fn raw_syscall_error(context: &str) -> anyhow::Error {
    anyhow!("{context}: {}", std::io::Error::last_os_error())
}

fn extract_log_string(buf: &[u8]) -> String {
    let end = buf.iter().position(|&b| b == 0).unwrap_or(buf.len());
    String::from_utf8_lossy(&buf[..end]).trim_end().to_string()
}

unsafe fn sys_bpf<T>(cmd: u32, attr: *mut T, size: usize) -> libc::c_long {
    unsafe {
        libc::syscall(
            libc::SYS_bpf,
            cmd as libc::c_int,
            attr as *mut libc::c_void,
            size as libc::c_uint,
        )
    }
}

/// Load raw BPF instructions through libbpf and immediately close the returned fd.
///
/// This is useful as a verifier dry-run. If `log_buf` is provided, verifier
/// logging is enabled with `log_level=2`; on failure the log text is included
/// in the returned error.
pub fn prog_load_dryrun(
    prog_type: bpf_prog_type,
    insns: &[bpf_insn],
    mut log_buf: Option<&mut [u8]>,
) -> Result<()> {
    let insn_cnt: size_t = insns
        .len()
        .try_into()
        .map_err(|_| anyhow!("instruction count does not fit libbpf size_t"))?;
    let mut opts = bpf_prog_load_opts::default();
    opts.sz = std::mem::size_of::<bpf_prog_load_opts>() as size_t;
    opts.attempts = 1;

    if let Some(buf) = log_buf.as_deref_mut() {
        if buf.is_empty() {
            bail!("BPF_PROG_LOAD dry-run log buffer must not be empty");
        }
        opts.log_level = 2;
        opts.log_size = buf.len() as u32;
        opts.log_buf = buf.as_mut_ptr() as *mut c_char;
    }

    let fd = unsafe {
        bpf_prog_load(
            prog_type,
            DEFAULT_PROG_NAME.as_ptr() as *const c_char,
            DEFAULT_LICENSE.as_ptr() as *const c_char,
            insns.as_ptr(),
            insn_cnt,
            &mut opts,
        )
    };

    if fd < 0 {
        let log = log_buf
            .as_deref()
            .map(extract_log_string)
            .unwrap_or_default();
        if log.is_empty() {
            return Err(libbpf_error("BPF_PROG_LOAD dry-run", fd));
        }
        return Err(anyhow!(
            "BPF_PROG_LOAD dry-run: {}\nverifier log:\n{}",
            os_error(errno_from_libbpf_ret(fd)),
            log
        ));
    }

    drop(unsafe { OwnedFd::from_raw_fd(fd) });
    Ok(())
}

/// Return the next live BPF program ID after `start_id`.
pub fn prog_get_next_id(start_id: u32) -> Result<Option<u32>> {
    let mut next_id = 0;
    let ret = unsafe { bpf_prog_get_next_id(start_id, &mut next_id) };
    if ret < 0 {
        let errno = errno_from_libbpf_ret(ret);
        if errno == libc::ENOENT {
            return Ok(None);
        }
        return Err(libbpf_error("BPF_PROG_GET_NEXT_ID", ret));
    }
    Ok(Some(next_id))
}

/// Open a live BPF program by ID.
pub fn prog_get_fd_by_id(id: u32) -> Result<OwnedFd> {
    let fd = unsafe { bpf_prog_get_fd_by_id(id) };
    if fd < 0 {
        return Err(libbpf_error("BPF_PROG_GET_FD_BY_ID", fd));
    }
    Ok(unsafe { OwnedFd::from_raw_fd(fd) })
}

/// Retrieve `struct bpf_prog_info` for an open program fd.
pub fn obj_get_info_by_fd(fd: BorrowedFd<'_>) -> Result<bpf_prog_info> {
    let mut info = bpf_prog_info::default();
    let mut info_len = std::mem::size_of::<bpf_prog_info>() as u32;
    let ret = unsafe {
        bpf_obj_get_info_by_fd(
            fd.as_raw_fd(),
            &mut info as *mut _ as *mut libc::c_void,
            &mut info_len,
        )
    };
    if ret < 0 {
        return Err(libbpf_error("BPF_OBJ_GET_INFO_BY_FD", ret));
    }
    Ok(info)
}

/// Enable kernel BPF runtime stats and return the owning fd.
pub fn enable_stats(stats_type: bpf_stats_type) -> Result<OwnedFd> {
    let fd = unsafe { bpf_enable_stats(stats_type) };
    if fd < 0 {
        return Err(libbpf_error("BPF_ENABLE_STATS", fd));
    }
    Ok(unsafe { OwnedFd::from_raw_fd(fd) })
}

/// Submit replacement bytecode through the fork-only `BPF_PROG_REJIT` command.
pub fn prog_rejit(prog_fd: BorrowedFd<'_>, new_insns: &[bpf_insn], fd_array: &[i32]) -> Result<()> {
    let mut attr: AttrRejit = zeroed();
    attr.prog_fd = prog_fd.as_raw_fd() as u32;
    attr.insn_cnt = new_insns.len() as u32;
    attr.insns = new_insns.as_ptr() as u64;
    if !fd_array.is_empty() {
        attr.fd_array = fd_array.as_ptr() as u64;
        attr.fd_array_cnt = fd_array.len() as u32;
    }

    let ret = unsafe { sys_bpf(BPF_PROG_REJIT, &mut attr, std::mem::size_of::<AttrRejit>()) };
    if ret < 0 {
        return Err(raw_syscall_error("BPF_PROG_REJIT"));
    }
    Ok(())
}

/// Retrieve original load-time bytecode through fork-only `BPF_PROG_GET_ORIGINAL`.
pub fn prog_get_original(prog_fd: BorrowedFd<'_>) -> Result<Vec<bpf_insn>> {
    let mut attr: AttrGetOriginal = zeroed();
    attr.prog_fd = prog_fd.as_raw_fd() as u32;

    let ret = unsafe {
        sys_bpf(
            BPF_PROG_GET_ORIGINAL,
            &mut attr,
            std::mem::size_of::<AttrGetOriginal>(),
        )
    };
    if ret < 0 {
        return Err(raw_syscall_error("BPF_PROG_GET_ORIGINAL (count)"));
    }

    let insn_cnt = if attr.insn_cnt != 0 {
        attr.insn_cnt as usize
    } else {
        ret as usize
    };
    if insn_cnt == 0 {
        return Ok(Vec::new());
    }

    let mut insns = vec![bpf_insn::default(); insn_cnt];
    let mut attr: AttrGetOriginal = zeroed();
    attr.prog_fd = prog_fd.as_raw_fd() as u32;
    attr.insn_cnt = insns.len() as u32;
    attr.insns = insns.as_mut_ptr() as u64;

    let ret = unsafe {
        sys_bpf(
            BPF_PROG_GET_ORIGINAL,
            &mut attr,
            std::mem::size_of::<AttrGetOriginal>(),
        )
    };
    if ret < 0 {
        return Err(raw_syscall_error("BPF_PROG_GET_ORIGINAL (insns)"));
    }

    let returned_cnt = if attr.insn_cnt != 0 {
        attr.insn_cnt as usize
    } else {
        ret as usize
    };
    insns.truncate(returned_cnt.min(insns.len()));
    Ok(insns)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn daemon_const(name: &str) -> Option<u32> {
        let path =
            std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../../daemon/src/bpf.rs");
        let src = std::fs::read_to_string(path).ok()?;
        let prefix = format!("const {name}: u32 = ");
        src.lines().find_map(|line| {
            line.trim()
                .strip_prefix(&prefix)
                .and_then(|value| value.trim_end_matches(';').parse().ok())
        })
    }

    #[test]
    fn reexport_names_compile() {
        let mut insn = bpf_insn::default();
        insn.code = (BPF_ALU64 | BPF_MOV | BPF_K) as u8;
        insn.set_dst_reg(BPF_REG_0 as u8);
        insn.set_src_reg(BPF_REG_1 as u8);

        let _: bpf_prog_type = BPF_PROG_TYPE_XDP;
        let _: ProgramType = ProgramType::Xdp;
        let _: *const libc::c_void = std::ptr::null::<bpf_object>().cast();

        assert_eq!(insn.dst_reg(), BPF_REG_0 as u8);
        assert_eq!(insn.src_reg(), BPF_REG_1 as u8);
    }

    #[test]
    fn bpf_insn_size_is_eight_bytes() {
        assert_eq!(std::mem::size_of::<bpf_insn>(), 8);
    }

    #[test]
    fn custom_command_constants_match_daemon_and_fork_slot() {
        assert_eq!(daemon_const("BPF_PROG_REJIT"), Some(BPF_PROG_REJIT));

        match daemon_const("BPF_PROG_GET_ORIGINAL") {
            Some(value) => assert_eq!(value, BPF_PROG_GET_ORIGINAL),
            None => assert_eq!(BPF_PROG_GET_ORIGINAL, BPF_PROG_REJIT + 1),
        }
    }

    #[test]
    fn fork_attr_layouts_are_128_bytes() {
        assert_eq!(std::mem::size_of::<AttrRejit>(), 128);
        assert_eq!(std::mem::size_of::<AttrGetOriginal>(), 128);
    }
}
