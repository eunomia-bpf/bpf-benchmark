//! Shared BPF kernel interaction helpers for bpfopt-suite tools.
//!
//! Upstream BPF UAPI types, constants, and libbpf helpers are re-exported from
//! `libbpf-rs`/`libbpf-sys`. The only direct `bpf(2)` wrappers here are for
//! fork-only commands that upstream libbpf does not expose.

use std::ffi::{c_char, CString};
use std::os::fd::{AsFd, AsRawFd, BorrowedFd, FromRawFd, OwnedFd};
use std::ptr::NonNull;

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

const DEFAULT_PROG_NAME: &[u8] = b"kernel_sys_dryrun\0";
const DEFAULT_LICENSE: &[u8] = b"GPL\0";

/// `union bpf_attr.rejit` prefix used by the fork-only `BPF_PROG_REJIT` cmd.
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
}

/// Fork-extended `struct bpf_prog_info`.
///
/// Upstream libbpf 1.7.0 does not know the fork-only `orig_prog_len` and
/// `orig_prog_insns` fields, so callers that need original bytecode must use
/// this layout with `bpf_obj_get_info_by_fd`.
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct BpfProgInfoFork {
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
    pub name: [u8; 16],
    pub ifindex: u32,
    pub gpl_compatible_pad: u32,
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

/// Options for a typed verifier dry-run load.
pub struct ProgLoadDryRunOptions<'a> {
    pub prog_type: bpf_prog_type,
    pub expected_attach_type: Option<bpf_attach_type>,
    pub prog_btf_fd: Option<i32>,
    pub attach_btf_id: Option<u32>,
    pub attach_btf_obj_fd: Option<i32>,
    pub insns: &'a [bpf_insn],
    pub fd_array: Option<&'a [i32]>,
    pub log_level: u32,
    pub log_buf: Option<&'a mut [u8]>,
}

/// Result of a verifier dry-run load. Kernel verifier rejection is represented
/// as `accepted = false`, while malformed inputs still return `Err`.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct ProgLoadDryRunReport {
    pub accepted: bool,
    pub errno: Option<i32>,
    pub verifier_log: String,
    pub log_true_size: u32,
    pub jited_size: Option<u32>,
}

impl Default for BpfProgInfoFork {
    fn default() -> Self {
        zeroed()
    }
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

fn libbpf_ptr_error(context: &str, ptr: *const libc::c_void) -> anyhow::Error {
    let ret = unsafe { libbpf_get_error(ptr) };
    let errno = if ret < 0 { -ret as i32 } else { ret as i32 };
    anyhow!("{context}: {}", os_error(errno))
}

fn raw_syscall_error(context: &str) -> anyhow::Error {
    anyhow!("{context}: {}", std::io::Error::last_os_error())
}

fn extract_log_string(buf: &[u8]) -> String {
    let end = buf.iter().position(|&b| b == 0).unwrap_or(buf.len());
    String::from_utf8_lossy(&buf[..end]).trim_end().to_string()
}

fn verifier_log_summary(log: &str) -> String {
    const MAX_SUMMARY_CHARS: usize = 4096;
    let mut chars = log.chars();
    let summary: String = chars.by_ref().take(MAX_SUMMARY_CHARS).collect();
    if chars.next().is_some() {
        format!("{summary}\n... verifier log truncated ...")
    } else {
        summary
    }
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

/// Load raw BPF instructions through libbpf with optional fd_array side input.
///
/// This is useful as a verifier dry-run. If `log_buf` is provided, verifier
/// logging is enabled with `log_level=2`; on failure the log text is included
/// in the returned error. The `fd_array` slice is only borrowed for the
/// duration of the load attempt, so callers must keep the backing fds alive
/// until this function returns.
pub fn prog_load_dryrun_with_fd_array(
    prog_type: bpf_prog_type,
    insns: &[bpf_insn],
    fd_array: Option<&[i32]>,
    log_buf: Option<&mut [u8]>,
) -> Result<()> {
    let log_level = if log_buf.is_some() { 2 } else { 0 };
    let report = prog_load_dryrun_report(ProgLoadDryRunOptions {
        prog_type,
        expected_attach_type: None,
        prog_btf_fd: None,
        attach_btf_id: None,
        attach_btf_obj_fd: None,
        insns,
        fd_array,
        log_level,
        log_buf,
    })?;
    if report.accepted {
        return Ok(());
    }

    if report.verifier_log.is_empty() {
        let errno = report.errno.unwrap_or(libc::EIO);
        return Err(anyhow!("BPF_PROG_LOAD dry-run: {}", os_error(errno)));
    }
    let errno = report.errno.unwrap_or(libc::EIO);
    Err(anyhow!(
        "BPF_PROG_LOAD dry-run: {}\nverifier log:\n{}",
        os_error(errno),
        report.verifier_log
    ))
}

/// Load raw BPF instructions through libbpf and report verifier status without
/// treating verifier rejection as an API error.
pub fn prog_load_dryrun_report(
    mut options: ProgLoadDryRunOptions<'_>,
) -> Result<ProgLoadDryRunReport> {
    let insn_cnt: size_t = options
        .insns
        .len()
        .try_into()
        .map_err(|_| anyhow!("instruction count does not fit libbpf size_t"))?;
    let mut opts = bpf_prog_load_opts {
        sz: std::mem::size_of::<bpf_prog_load_opts>() as size_t,
        attempts: 1,
        ..Default::default()
    };

    if let Some(expected_attach_type) = options.expected_attach_type {
        opts.expected_attach_type = expected_attach_type;
    }
    if let Some(prog_btf_fd) = options.prog_btf_fd {
        if prog_btf_fd < 0 {
            bail!("prog_btf_fd must be non-negative");
        }
        opts.prog_btf_fd = prog_btf_fd as u32;
    }
    if let Some(attach_btf_id) = options.attach_btf_id.filter(|id| *id != 0) {
        opts.attach_btf_id = attach_btf_id;
    }
    if let Some(attach_btf_obj_fd) = options.attach_btf_obj_fd {
        if attach_btf_obj_fd < 0 {
            bail!("attach_btf_obj_fd must be non-negative");
        }
        opts.attach_btf_obj_fd = attach_btf_obj_fd as u32;
    }

    if let Some(fd_array) = options.fd_array.filter(|fds| !fds.is_empty()) {
        opts.fd_array_cnt = fd_array
            .len()
            .try_into()
            .map_err(|_| anyhow!("fd_array length does not fit libbpf __u32"))?;
        opts.fd_array = fd_array.as_ptr();
    }

    if options.log_level > 0 {
        let Some(buf) = options.log_buf.as_deref_mut() else {
            bail!("BPF_PROG_LOAD dry-run log_level requires a log buffer");
        };
        if buf.is_empty() {
            bail!("BPF_PROG_LOAD dry-run log buffer must not be empty");
        }
        buf.fill(0);
        opts.log_level = options.log_level;
        opts.log_size = buf.len() as u32;
        opts.log_buf = buf.as_mut_ptr() as *mut c_char;
    }

    let fd = unsafe {
        bpf_prog_load(
            options.prog_type,
            DEFAULT_PROG_NAME.as_ptr() as *const c_char,
            DEFAULT_LICENSE.as_ptr() as *const c_char,
            options.insns.as_ptr(),
            insn_cnt,
            &mut opts,
        )
    };

    let log = match options.log_buf.as_deref() {
        Some(buf) => extract_log_string(buf),
        None => String::new(),
    };
    if fd < 0 {
        return Ok(ProgLoadDryRunReport {
            accepted: false,
            errno: Some(errno_from_libbpf_ret(fd)),
            verifier_log: log,
            log_true_size: opts.log_true_size,
            jited_size: None,
        });
    }

    let fd = unsafe { OwnedFd::from_raw_fd(fd) };
    let jited_size = Some(obj_get_info_by_fd(fd.as_fd())?.jited_prog_len);
    drop(fd);
    Ok(ProgLoadDryRunReport {
        accepted: true,
        errno: None,
        verifier_log: log,
        log_true_size: opts.log_true_size,
        jited_size,
    })
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

/// Return the next live BTF object ID after `start_id`.
pub fn btf_get_next_id(start_id: u32) -> Result<Option<u32>> {
    let mut next_id = 0;
    let ret = unsafe { bpf_btf_get_next_id(start_id, &mut next_id) };
    if ret < 0 {
        let errno = errno_from_libbpf_ret(ret);
        if errno == libc::ENOENT {
            return Ok(None);
        }
        return Err(libbpf_error("BPF_BTF_GET_NEXT_ID", ret));
    }
    Ok(Some(next_id))
}

/// Open a live BTF object by ID.
pub fn btf_get_fd_by_id(id: u32) -> Result<OwnedFd> {
    let fd = unsafe { bpf_btf_get_fd_by_id(id) };
    if fd < 0 {
        return Err(libbpf_error("BPF_BTF_GET_FD_BY_ID", fd));
    }
    Ok(unsafe { OwnedFd::from_raw_fd(fd) })
}

/// Parsed kernel BTF object loaded through libbpf.
pub struct KernelBtf {
    ptr: NonNull<btf>,
}

impl KernelBtf {
    fn from_raw(context: &str, raw: *mut btf) -> Result<Self> {
        let err = unsafe { libbpf_get_error(raw as *const libc::c_void) };
        if err != 0 {
            return Err(libbpf_ptr_error(context, raw as *const libc::c_void));
        }
        let ptr = NonNull::new(raw).ok_or_else(|| anyhow!("{context} returned NULL"))?;
        Ok(Self { ptr })
    }

    /// Load vmlinux BTF through libbpf.
    pub fn load_vmlinux() -> Result<Self> {
        let raw = unsafe { btf__load_vmlinux_btf() };
        Self::from_raw("btf__load_vmlinux_btf", raw)
    }

    /// Load a kernel or module BTF object by kernel BTF ID.
    pub fn load_from_kernel_by_id(id: u32) -> Result<Self> {
        let raw = unsafe { btf__load_from_kernel_by_id(id) };
        Self::from_raw(&format!("btf__load_from_kernel_by_id({id})"), raw)
    }

    /// Load a split kernel/module BTF object by ID using `base` as vmlinux BTF.
    pub fn load_from_kernel_by_id_split(id: u32, base: &KernelBtf) -> Result<Self> {
        let raw = unsafe { btf__load_from_kernel_by_id_split(id, base.ptr.as_ptr()) };
        Self::from_raw(&format!("btf__load_from_kernel_by_id_split({id})"), raw)
    }

    /// Find a BTF_KIND_FUNC type by name. Returns `None` if the function is absent.
    pub fn find_func_by_name(&self, name: &str) -> Result<Option<u32>> {
        let c_name =
            CString::new(name).map_err(|_| anyhow!("BTF function name contains NUL: {name:?}"))?;
        let ret =
            unsafe { btf__find_by_name_kind(self.ptr.as_ptr(), c_name.as_ptr(), BTF_KIND_FUNC) };
        if ret >= 0 {
            return Ok(Some(ret as u32));
        }
        if errno_from_libbpf_ret(ret) == libc::ENOENT {
            return Ok(None);
        }
        Err(libbpf_error(
            &format!("btf__find_by_name_kind({name})"),
            ret,
        ))
    }
}

impl Drop for KernelBtf {
    fn drop(&mut self) {
        unsafe { btf__free(self.ptr.as_ptr()) };
    }
}

fn prog_obj_get_info_by_fd_into(fd: BorrowedFd<'_>, info: &mut BpfProgInfoFork) -> Result<()> {
    let mut info_len = std::mem::size_of::<BpfProgInfoFork>() as u32;
    let ret = unsafe {
        bpf_obj_get_info_by_fd(
            fd.as_raw_fd(),
            info as *mut _ as *mut libc::c_void,
            &mut info_len,
        )
    };
    if ret < 0 {
        return Err(libbpf_error("BPF_OBJ_GET_INFO_BY_FD", ret));
    }
    Ok(())
}

/// Retrieve fork-extended `struct bpf_prog_info` for an open program fd.
pub fn obj_get_info_by_fd(fd: BorrowedFd<'_>) -> Result<BpfProgInfoFork> {
    let mut info = BpfProgInfoFork::default();
    prog_obj_get_info_by_fd_into(fd, &mut info)?;
    Ok(info)
}

/// Retrieve map IDs referenced by an open BPF program fd.
pub fn prog_map_ids(fd: BorrowedFd<'_>, nr_map_ids: u32) -> Result<Vec<u32>> {
    if nr_map_ids == 0 {
        return Ok(Vec::new());
    }

    let mut map_ids = vec![0u32; nr_map_ids as usize];
    let mut info = BpfProgInfoFork {
        nr_map_ids,
        map_ids: map_ids.as_mut_ptr() as u64,
        ..Default::default()
    };
    prog_obj_get_info_by_fd_into(fd, &mut info)?;
    if info.nr_map_ids as usize > map_ids.len() {
        bail!(
            "program map id count grew while reading map ids: first pass {}, second pass {}",
            map_ids.len(),
            info.nr_map_ids
        );
    }
    map_ids.truncate(info.nr_map_ids as usize);
    Ok(map_ids)
}

/// Open a live BPF map by ID.
pub fn map_get_fd_by_id(id: u32) -> Result<OwnedFd> {
    let fd = unsafe { bpf_map_get_fd_by_id(id) };
    if fd < 0 {
        return Err(libbpf_error("BPF_MAP_GET_FD_BY_ID", fd));
    }
    Ok(unsafe { OwnedFd::from_raw_fd(fd) })
}

/// Retrieve `struct bpf_map_info` for an open map fd.
pub fn map_obj_get_info_by_fd(fd: BorrowedFd<'_>) -> Result<bpf_map_info> {
    let mut info = bpf_map_info::default();
    let mut info_len = std::mem::size_of::<bpf_map_info>() as u32;
    let ret = unsafe { bpf_map_get_info_by_fd(fd.as_raw_fd(), &mut info, &mut info_len) };
    if ret < 0 {
        return Err(libbpf_error("BPF_OBJ_GET_INFO_BY_FD (map)", ret));
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
pub fn prog_rejit(
    prog_fd: BorrowedFd<'_>,
    new_insns: &[bpf_insn],
    fd_array: &[i32],
    mut log_buf: Option<&mut [u8]>,
) -> Result<()> {
    let mut attr: AttrRejit = zeroed();
    attr.prog_fd = prog_fd.as_raw_fd() as u32;
    attr.insn_cnt = new_insns.len() as u32;
    attr.insns = new_insns.as_ptr() as u64;
    if let Some(buf) = log_buf.as_deref_mut() {
        if buf.is_empty() {
            bail!("BPF_PROG_REJIT log buffer must not be empty");
        }
        buf.fill(0);
        attr.log_level = 2;
        attr.log_size = buf.len() as u32;
        attr.log_buf = buf.as_mut_ptr() as u64;
    }
    if !fd_array.is_empty() {
        attr.fd_array = fd_array.as_ptr() as u64;
        attr.fd_array_cnt = fd_array.len() as u32;
    }

    let ret = unsafe { sys_bpf(BPF_PROG_REJIT, &mut attr, std::mem::size_of::<AttrRejit>()) };
    if ret < 0 {
        let log = match log_buf.as_deref() {
            Some(buf) => extract_log_string(buf),
            None => String::new(),
        };
        if !log.is_empty() {
            return Err(anyhow!(
                "BPF_PROG_REJIT: {}\nverifier log summary:\n{}",
                std::io::Error::last_os_error(),
                verifier_log_summary(&log)
            ));
        }
        return Err(raw_syscall_error("BPF_PROG_REJIT"));
    }
    Ok(())
}

/// Retrieve original load-time bytecode through fork `bpf_prog_info.orig_prog_*`.
pub fn prog_get_original(prog_fd: BorrowedFd<'_>) -> Result<Vec<bpf_insn>> {
    let info = obj_get_info_by_fd(prog_fd)?;
    let byte_len = info.orig_prog_len as usize;
    if byte_len == 0 {
        return Ok(Vec::new());
    }

    let insn_size = std::mem::size_of::<bpf_insn>();
    if !byte_len.is_multiple_of(insn_size) {
        bail!(
            "orig_prog_len {} is not a multiple of struct bpf_insn size {}",
            byte_len,
            insn_size
        );
    }

    let mut insns = vec![bpf_insn::default(); byte_len / insn_size];
    let mut info = BpfProgInfoFork {
        orig_prog_len: byte_len as u32,
        orig_prog_insns: insns.as_mut_ptr() as u64,
        ..Default::default()
    };
    prog_obj_get_info_by_fd_into(prog_fd, &mut info)?;

    let returned_len = info.orig_prog_len as usize;
    if returned_len > byte_len {
        bail!(
            "orig_prog_len grew while reading original bytecode: first pass {} bytes, second pass {} bytes",
            byte_len,
            returned_len
        );
    }
    if !returned_len.is_multiple_of(insn_size) {
        bail!(
            "returned orig_prog_len {} is not a multiple of struct bpf_insn size {}",
            returned_len,
            insn_size
        );
    }
    if returned_len != 0 && info.orig_prog_insns == 0 {
        bail!("BPF_OBJ_GET_INFO_BY_FD did not return original bytecode");
    }

    insns.truncate(returned_len / insn_size);
    Ok(insns)
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::mem::{offset_of, size_of};

    #[test]
    fn attr_rejit_field_offsets_match_fork_uapi() {
        assert_eq!(offset_of!(AttrRejit, prog_fd), 0);
        assert_eq!(offset_of!(AttrRejit, insn_cnt), 4);
        assert_eq!(offset_of!(AttrRejit, insns), 8);
        assert_eq!(offset_of!(AttrRejit, log_level), 16);
        assert_eq!(offset_of!(AttrRejit, log_size), 20);
        assert_eq!(offset_of!(AttrRejit, log_buf), 24);
        assert_eq!(offset_of!(AttrRejit, fd_array), 32);
        assert_eq!(offset_of!(AttrRejit, fd_array_cnt), 40);
        assert_eq!(offset_of!(AttrRejit, flags), 44);
        assert_eq!(
            size_of::<AttrRejit>(),
            48,
            "AttrRejit should pass the minimal zero-extended rejit prefix"
        );
    }

    #[test]
    fn bpf_prog_info_fork_field_offsets_match_fork_uapi() {
        assert_eq!(offset_of!(BpfProgInfoFork, prog_type), 0);
        assert_eq!(offset_of!(BpfProgInfoFork, id), 4);
        assert_eq!(offset_of!(BpfProgInfoFork, tag), 8);
        assert_eq!(offset_of!(BpfProgInfoFork, jited_prog_len), 16);
        assert_eq!(offset_of!(BpfProgInfoFork, xlated_prog_len), 20);
        assert_eq!(offset_of!(BpfProgInfoFork, jited_prog_insns), 24);
        assert_eq!(offset_of!(BpfProgInfoFork, xlated_prog_insns), 32);
        assert_eq!(offset_of!(BpfProgInfoFork, load_time), 40);
        assert_eq!(offset_of!(BpfProgInfoFork, created_by_uid), 48);
        assert_eq!(offset_of!(BpfProgInfoFork, nr_map_ids), 52);
        assert_eq!(offset_of!(BpfProgInfoFork, map_ids), 56);
        assert_eq!(offset_of!(BpfProgInfoFork, name), 64);
        assert_eq!(offset_of!(BpfProgInfoFork, ifindex), 80);
        assert_eq!(offset_of!(BpfProgInfoFork, gpl_compatible_pad), 84);
        assert_eq!(offset_of!(BpfProgInfoFork, netns_dev), 88);
        assert_eq!(offset_of!(BpfProgInfoFork, netns_ino), 96);
        assert_eq!(offset_of!(BpfProgInfoFork, nr_jited_ksyms), 104);
        assert_eq!(offset_of!(BpfProgInfoFork, nr_jited_func_lens), 108);
        assert_eq!(offset_of!(BpfProgInfoFork, jited_ksyms), 112);
        assert_eq!(offset_of!(BpfProgInfoFork, jited_func_lens), 120);
        assert_eq!(offset_of!(BpfProgInfoFork, btf_id), 128);
        assert_eq!(offset_of!(BpfProgInfoFork, func_info_rec_size), 132);
        assert_eq!(offset_of!(BpfProgInfoFork, func_info), 136);
        assert_eq!(offset_of!(BpfProgInfoFork, nr_func_info), 144);
        assert_eq!(offset_of!(BpfProgInfoFork, nr_line_info), 148);
        assert_eq!(offset_of!(BpfProgInfoFork, line_info), 152);
        assert_eq!(offset_of!(BpfProgInfoFork, jited_line_info), 160);
        assert_eq!(offset_of!(BpfProgInfoFork, nr_jited_line_info), 168);
        assert_eq!(offset_of!(BpfProgInfoFork, line_info_rec_size), 172);
        assert_eq!(offset_of!(BpfProgInfoFork, jited_line_info_rec_size), 176);
        assert_eq!(offset_of!(BpfProgInfoFork, nr_prog_tags), 180);
        assert_eq!(offset_of!(BpfProgInfoFork, prog_tags), 184);
        assert_eq!(offset_of!(BpfProgInfoFork, run_time_ns), 192);
        assert_eq!(offset_of!(BpfProgInfoFork, run_cnt), 200);
        assert_eq!(offset_of!(BpfProgInfoFork, recursion_misses), 208);
        assert_eq!(offset_of!(BpfProgInfoFork, verified_insns), 216);
        assert_eq!(offset_of!(BpfProgInfoFork, attach_btf_obj_id), 220);
        assert_eq!(offset_of!(BpfProgInfoFork, attach_btf_id), 224);
        assert_eq!(offset_of!(BpfProgInfoFork, orig_prog_len), 228);
        assert_eq!(offset_of!(BpfProgInfoFork, orig_prog_insns), 232);
        assert_eq!(size_of::<BpfProgInfoFork>(), 240);
    }
}
