//! Shared BPF kernel interaction helpers for bpfopt-suite tools.
//!
//! Upstream BPF UAPI types, constants, and libbpf helpers are re-exported from
//! `libbpf-rs`/`libbpf-sys`. The only direct `bpf(2)` wrappers here are for
//! fork-only commands that upstream libbpf does not expose.

mod verifier_log;

use std::collections::{BTreeMap, HashMap};
use std::ffi::{c_char, c_void, CString};
use std::os::fd::{AsFd, AsRawFd, BorrowedFd, FromRawFd, OwnedFd};
use std::ptr::NonNull;
use std::slice;
use std::time::Duration;

use anyhow::{anyhow, bail, Context, Result};
use serde::{Deserialize, Serialize};

pub use libbpf_rs::{
    libbpf_sys, Object, ObjectBuilder, OpenObject, Program, ProgramMut, ProgramType,
};
pub use libbpf_sys::*;

/// Fork-only `enum bpf_cmd` value for in-place BPF program ReJIT.
///
/// The current daemon wrapper defines this as the last command before
/// `__MAX_BPF_CMD` in the forked UAPI.
pub const BPF_PROG_REJIT: u32 = 39;

pub const BPF_FUNC_GET_BRANCH_SNAPSHOT: bpf_func_id = BPF_FUNC_get_branch_snapshot;
pub const BRANCH_SNAPSHOT_MAX_ENTRIES: usize = 32;
pub const BRANCH_SNAPSHOT_ENTRY_SIZE: usize = std::mem::size_of::<perf_branch_entry>();
pub const BRANCH_SNAPSHOT_EVENT_HEADER_SIZE: usize = 16;
pub const BRANCH_SNAPSHOT_EVENT_SIZE: usize =
    BRANCH_SNAPSHOT_EVENT_HEADER_SIZE + BRANCH_SNAPSHOT_MAX_ENTRIES * BRANCH_SNAPSHOT_ENTRY_SIZE;

const BPFPROF_SIDECAR_NAME: &[u8] = b"bpfprof_lbr\0";
const MAX_REJIT_LOG_BUF_SIZE: usize = 256 * 1024 * 1024;

const PERF_EVENT_IOC_ENABLE: libc::c_ulong = 0x2400;
const PERF_EVENT_IOC_DISABLE: libc::c_ulong = 0x2401;
const PERF_EVENT_IOC_RESET: libc::c_ulong = 0x2403;

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

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum PerfEventCommand {
    Enable,
    Disable,
    Reset,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct ProgFuncInfo {
    pub insn_off: u32,
    pub type_id: u32,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct JitedFuncRange {
    pub start_addr: u64,
    pub byte_len: u32,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct JitedLineInfo {
    pub insn_off: u32,
    pub jited_addr: u64,
}

#[allow(clippy::enum_variant_names)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum VerifierInsnKind {
    EdgeFullState,
    PcFullState,
    BranchDeltaState,
    InsnDeltaState,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum VerifierValueWidth {
    Unknown,
    Bits32,
    Bits64,
}

#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct Tnum {
    pub value: u64,
    pub mask: u64,
}

#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct ScalarRange {
    pub smin: Option<i64>,
    pub smax: Option<i64>,
    pub umin: Option<u64>,
    pub umax: Option<u64>,
    pub smin32: Option<i32>,
    pub smax32: Option<i32>,
    pub umin32: Option<u32>,
    pub umax32: Option<u32>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct VerifierInsn {
    pub pc: usize,
    pub frame: usize,
    pub from_pc: Option<usize>,
    pub kind: VerifierInsnKind,
    pub speculative: bool,
    pub regs: HashMap<u8, RegState>,
    pub stack: HashMap<i16, StackState>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct RegState {
    pub reg_type: String,
    pub value_width: VerifierValueWidth,
    pub precise: bool,
    pub exact_value: Option<u64>,
    pub tnum: Option<Tnum>,
    pub range: ScalarRange,
    pub offset: Option<i32>,
    pub id: Option<u32>,
}

impl RegState {
    pub fn new(reg_type: impl Into<String>, value_width: VerifierValueWidth) -> Self {
        Self {
            reg_type: reg_type.into(),
            value_width,
            precise: false,
            exact_value: None,
            tnum: None,
            range: ScalarRange::default(),
            offset: None,
            id: None,
        }
    }

    pub fn exact_u64(&self) -> Option<u64> {
        if self.reg_type != "scalar" {
            return None;
        }

        match self.value_width {
            VerifierValueWidth::Bits32 => None,
            VerifierValueWidth::Bits64 | VerifierValueWidth::Unknown => self.exact_value,
        }
    }

    pub fn exact_u32(&self) -> Option<u32> {
        if self.reg_type != "scalar" {
            return None;
        }

        self.exact_value.map(|value| value as u32)
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct StackState {
    pub slot_types: Option<String>,
    pub value: Option<RegState>,
}

#[derive(Clone, Debug, Deserialize, Serialize, PartialEq, Eq)]
pub struct VerifierStatesJson {
    #[serde(default)]
    pub insns: Vec<VerifierInsnJson>,
}

#[derive(Clone, Debug, Deserialize, Serialize, PartialEq, Eq)]
pub struct VerifierInsnJson {
    pub pc: usize,
    #[serde(default, skip_serializing_if = "is_zero_usize")]
    pub frame: usize,
    #[serde(default)]
    pub regs: BTreeMap<String, VerifierRegJson>,
}

#[derive(Clone, Debug, Deserialize, Serialize, PartialEq, Eq)]
pub struct VerifierRegJson {
    #[serde(rename = "type", default = "default_reg_type")]
    pub reg_type: String,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub offset: Option<i32>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub const_val: Option<i64>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub min: Option<i64>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub max: Option<i64>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub tnum: Option<String>,
}

fn default_reg_type() -> String {
    "scalar".to_string()
}

fn is_zero_usize(value: &usize) -> bool {
    *value == 0
}

pub struct BranchSnapshotSidecar {
    pub prog_fd: OwnedFd,
    pub link_fd: OwnedFd,
}

type RingBufferSampleFn<'a> = dyn FnMut(&[u8]) -> i32 + 'a;

struct RingBufferCallback<'a> {
    callback: Box<RingBufferSampleFn<'a>>,
}

pub struct RingBuffer<'a> {
    ptr: NonNull<ring_buffer>,
    _callback: Box<RingBufferCallback<'a>>,
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
    pub prog_flags: u32,
}

/// Options for a typed verifier dry-run load.
pub struct ProgLoadDryRunOptions<'a> {
    pub prog_type: bpf_prog_type,
    pub expected_attach_type: Option<bpf_attach_type>,
    pub prog_flags: u32,
    pub prog_btf_fd: Option<i32>,
    pub attach_btf_id: Option<u32>,
    pub attach_btf_obj_fd: Option<i32>,
    pub func_info: Option<BtfInfoRecords<'a>>,
    pub line_info: Option<BtfInfoRecords<'a>>,
    pub insns: &'a [bpf_insn],
    pub fd_array: Option<&'a [i32]>,
    pub log_level: u32,
    pub log_buf: Option<&'a mut [u8]>,
}

/// Raw BTF func_info or line_info records supplied to `BPF_PROG_LOAD`.
#[derive(Clone, Copy, Debug)]
pub struct BtfInfoRecords<'a> {
    pub rec_size: u32,
    pub bytes: &'a [u8],
}

/// Raw BTF metadata captured from an already-loaded program.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct ProgBtfInfo {
    pub func_info_rec_size: u32,
    pub func_info: Vec<u8>,
    pub line_info_rec_size: u32,
    pub line_info: Vec<u8>,
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

pub fn verifier_log_summary(log: &str) -> String {
    let log = log.trim();
    if log.is_empty() {
        return "<empty verifier log>".to_string();
    }
    const MAX_SUMMARY_CHARS: usize = 4096;
    let mut chars = log.chars();
    let summary: String = chars.by_ref().take(MAX_SUMMARY_CHARS).collect();
    if chars.next().is_some() {
        format!("{summary}\n... verifier log truncated ...")
    } else {
        summary
    }
}

pub fn verifier_states_from_log(log: &str) -> VerifierStatesJson {
    let parsed = verifier_log::parse_verifier_log(log);
    convert_verifier_states(&parsed)
}

fn convert_verifier_states(states: &[VerifierInsn]) -> VerifierStatesJson {
    let has_delta = states
        .iter()
        .any(|state| state.kind == VerifierInsnKind::InsnDeltaState);
    let insns = states
        .iter()
        .filter(|state| state.kind != VerifierInsnKind::BranchDeltaState)
        .filter(|state| !has_delta || state.kind == VerifierInsnKind::InsnDeltaState)
        .filter_map(convert_verifier_state)
        .collect();
    VerifierStatesJson { insns }
}

fn convert_verifier_state(state: &VerifierInsn) -> Option<VerifierInsnJson> {
    let regs = state
        .regs
        .iter()
        .filter_map(|(&regno, reg)| convert_reg_state(reg).map(|reg| (format!("r{regno}"), reg)))
        .collect::<BTreeMap<_, _>>();
    (!regs.is_empty()).then_some(VerifierInsnJson {
        pc: state.pc,
        frame: state.frame,
        regs,
    })
}

fn convert_reg_state(reg: &RegState) -> Option<VerifierRegJson> {
    let const_val = reg
        .exact_u64()
        .or_else(|| reg.exact_u32().map(u64::from))
        .map(|value| value as i64);
    let (min, max) = if let (Some(min), Some(max)) = (reg.range.umin, reg.range.umax) {
        if min <= i64::MAX as u64 && max <= i64::MAX as u64 {
            (Some(min as i64), Some(max as i64))
        } else {
            (reg.range.smin, reg.range.smax)
        }
    } else {
        (reg.range.smin, reg.range.smax)
    };
    let tnum = reg
        .tnum
        .map(|tnum| format!("0x{:x}/0x{:x}", tnum.value, tnum.mask));

    (reg.offset.is_some()
        || const_val.is_some()
        || min.is_some()
        || max.is_some()
        || tnum.is_some())
    .then_some(VerifierRegJson {
        reg_type: reg.reg_type.clone(),
        offset: reg.offset,
        const_val,
        min,
        max,
        tnum,
    })
}

struct ProgRejitFailure {
    error: std::io::Error,
    log: String,
}

fn format_prog_rejit_failure(failure: ProgRejitFailure) -> anyhow::Error {
    if !failure.log.is_empty() {
        anyhow!(
            "BPF_PROG_REJIT: {}\nverifier log summary:\n{}",
            failure.error,
            verifier_log_summary(&failure.log)
        )
    } else {
        anyhow!("BPF_PROG_REJIT: {}", failure.error)
    }
}

fn btf_record_count(label: &str, records: BtfInfoRecords<'_>) -> Result<Option<u32>> {
    if records.bytes.is_empty() {
        return Ok(None);
    }
    if records.rec_size == 0 {
        bail!("{label} rec_size must be non-zero when records are present");
    }
    let rec_size = records.rec_size as usize;
    if !records.bytes.len().is_multiple_of(rec_size) {
        bail!(
            "{label} byte length {} is not a multiple of rec_size {}",
            records.bytes.len(),
            records.rec_size
        );
    }
    let count = records.bytes.len() / rec_size;
    let count = count
        .try_into()
        .map_err(|_| anyhow!("{label} record count does not fit libbpf __u32"))?;
    Ok(Some(count))
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
    opts.prog_flags = options.prog_flags;
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
    if let Some(func_info) = options.func_info {
        if let Some(count) = btf_record_count("func_info", func_info)? {
            opts.func_info = func_info.bytes.as_ptr() as *const libc::c_void;
            opts.func_info_cnt = count;
            opts.func_info_rec_size = func_info.rec_size;
        }
    }
    if let Some(line_info) = options.line_info {
        if let Some(count) = btf_record_count("line_info", line_info)? {
            opts.line_info = line_info.bytes.as_ptr() as *const libc::c_void;
            opts.line_info_cnt = count;
            opts.line_info_rec_size = line_info.rec_size;
        }
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
        let errno = errno_from_libbpf_ret(fd);
        let log_true_size = opts.log_true_size;
        return Ok(ProgLoadDryRunReport {
            accepted: false,
            errno: Some(errno),
            verifier_log: log,
            log_true_size,
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

fn link_get_next_id(start_id: u32) -> Result<Option<u32>> {
    let mut next_id = 0;
    let ret = unsafe { bpf_link_get_next_id(start_id, &mut next_id) };
    if ret < 0 {
        let errno = errno_from_libbpf_ret(ret);
        if errno == libc::ENOENT {
            return Ok(None);
        }
        return Err(libbpf_error("BPF_LINK_GET_NEXT_ID", ret));
    }
    Ok(Some(next_id))
}

fn link_get_fd_by_id(id: u32) -> Result<OwnedFd> {
    let fd = unsafe { bpf_link_get_fd_by_id(id) };
    if fd < 0 {
        return Err(libbpf_error("BPF_LINK_GET_FD_BY_ID", fd));
    }
    Ok(unsafe { OwnedFd::from_raw_fd(fd) })
}

fn link_obj_get_info_by_fd(fd: BorrowedFd<'_>) -> Result<bpf_link_info> {
    let mut info = bpf_link_info::default();
    let mut info_len = std::mem::size_of::<bpf_link_info>() as u32;
    let ret = unsafe { bpf_link_get_info_by_fd(fd.as_raw_fd(), &mut info, &mut info_len) };
    if ret < 0 {
        return Err(libbpf_error("BPF_OBJ_GET_INFO_BY_FD (link)", ret));
    }
    Ok(info)
}

/// Recover the load-time expected attach type for a live program from its link.
///
/// `struct bpf_prog_info` does not expose `prog->expected_attach_type`, while
/// `BPF_PROG_LOAD` replay needs it for tracing, LSM, cgroup, and link-backed
/// attach contexts. Link enumeration is the only stable userspace source for
/// this metadata without adding another fork-only kernel ABI.
pub fn expected_attach_type_for_prog(
    prog_id: u32,
    prog_type: bpf_prog_type,
) -> Result<Option<bpf_attach_type>> {
    let mut start_id = 0;
    let mut expected = None;

    loop {
        let Some(link_id) = link_get_next_id(start_id)
            .with_context(|| format!("enumerate BPF links after id {start_id}"))?
        else {
            break;
        };
        start_id = link_id;

        let fd =
            link_get_fd_by_id(link_id).with_context(|| format!("open BPF link id {link_id}"))?;
        let info = link_obj_get_info_by_fd(fd.as_fd())
            .with_context(|| format!("read info for BPF link id {link_id}"))?;
        if info.prog_id != prog_id {
            continue;
        }

        let Some(link_attach_type) = expected_attach_type_from_link_info(&info, prog_type) else {
            if prog_type_requires_expected_attach_type(prog_type) {
                bail!(
                    "program id {prog_id} is attached through unsupported BPF link type {} for required expected_attach_type recovery",
                    info.type_
                );
            }
            continue;
        };
        match expected {
            Some(prev) if prev != link_attach_type => {
                bail!(
                    "program id {prog_id} has conflicting link attach types {prev} and {link_attach_type}"
                );
            }
            Some(_) => {}
            None => expected = Some(link_attach_type),
        }
    }

    Ok(expected)
}

fn prog_type_requires_expected_attach_type(prog_type: bpf_prog_type) -> bool {
    matches!(prog_type, BPF_PROG_TYPE_TRACING | BPF_PROG_TYPE_LSM)
}

fn expected_attach_type_from_link_info(
    info: &bpf_link_info,
    prog_type: bpf_prog_type,
) -> Option<bpf_attach_type> {
    match info.type_ {
        BPF_LINK_TYPE_RAW_TRACEPOINT if prog_type == BPF_PROG_TYPE_TRACING => {
            Some(BPF_TRACE_RAW_TP)
        }
        BPF_LINK_TYPE_TRACING => Some(unsafe { info.__bindgen_anon_1.tracing.attach_type }),
        BPF_LINK_TYPE_CGROUP => Some(unsafe { info.__bindgen_anon_1.cgroup.attach_type }),
        BPF_LINK_TYPE_ITER => Some(BPF_TRACE_ITER),
        BPF_LINK_TYPE_NETNS => Some(unsafe { info.__bindgen_anon_1.netns.attach_type }),
        BPF_LINK_TYPE_XDP => Some(BPF_XDP),
        BPF_LINK_TYPE_NETFILTER => Some(BPF_NETFILTER),
        BPF_LINK_TYPE_KPROBE_MULTI if prog_type == BPF_PROG_TYPE_KPROBE => {
            Some(BPF_TRACE_KPROBE_MULTI)
        }
        BPF_LINK_TYPE_UPROBE_MULTI if prog_type == BPF_PROG_TYPE_KPROBE => {
            Some(BPF_TRACE_UPROBE_MULTI)
        }
        BPF_LINK_TYPE_TCX => Some(unsafe { info.__bindgen_anon_1.tcx.attach_type }),
        BPF_LINK_TYPE_NETKIT => Some(unsafe { info.__bindgen_anon_1.netkit.attach_type }),
        BPF_LINK_TYPE_SOCKMAP => Some(unsafe { info.__bindgen_anon_1.sockmap.attach_type }),
        _ => None,
    }
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

/// Retrieve raw func_info and line_info records referenced by an open BPF program fd.
pub fn prog_btf_info(fd: BorrowedFd<'_>) -> Result<ProgBtfInfo> {
    let first = obj_get_info_by_fd(fd)?;
    let mut func_info =
        allocate_btf_records("func_info", first.nr_func_info, first.func_info_rec_size)?;
    let mut line_info =
        allocate_btf_records("line_info", first.nr_line_info, first.line_info_rec_size)?;
    if func_info.is_empty() && line_info.is_empty() {
        return Ok(ProgBtfInfo {
            func_info_rec_size: first.func_info_rec_size,
            func_info,
            line_info_rec_size: first.line_info_rec_size,
            line_info,
        });
    }

    let mut info = BpfProgInfoFork {
        func_info_rec_size: first.func_info_rec_size,
        func_info: ptr_u64(func_info.as_mut_ptr()),
        nr_func_info: first.nr_func_info,
        nr_line_info: first.nr_line_info,
        line_info: ptr_u64(line_info.as_mut_ptr()),
        line_info_rec_size: first.line_info_rec_size,
        ..Default::default()
    };
    prog_obj_get_info_by_fd_into(fd, &mut info)?;

    shrink_btf_records(
        "func_info",
        &mut func_info,
        first.nr_func_info,
        info.nr_func_info,
        first.func_info_rec_size,
        info.func_info_rec_size,
    )?;
    shrink_btf_records(
        "line_info",
        &mut line_info,
        first.nr_line_info,
        info.nr_line_info,
        first.line_info_rec_size,
        info.line_info_rec_size,
    )?;

    Ok(ProgBtfInfo {
        func_info_rec_size: info.func_info_rec_size,
        func_info,
        line_info_rec_size: info.line_info_rec_size,
        line_info,
    })
}

fn allocate_btf_records(label: &str, count: u32, rec_size: u32) -> Result<Vec<u8>> {
    if count == 0 {
        return Ok(Vec::new());
    }
    if rec_size == 0 {
        bail!("{label} count is {count} but rec_size is zero");
    }
    let len = btf_record_bytes(label, count, rec_size)?;
    Ok(vec![0; len])
}

fn shrink_btf_records(
    label: &str,
    bytes: &mut Vec<u8>,
    requested_count: u32,
    returned_count: u32,
    requested_rec_size: u32,
    returned_rec_size: u32,
) -> Result<()> {
    if returned_count > requested_count {
        bail!(
            "{label} count grew while reading records: first pass {requested_count}, second pass {returned_count}"
        );
    }
    if returned_count != 0 && returned_rec_size != requested_rec_size {
        bail!(
            "{label} rec_size changed while reading records: first pass {requested_rec_size}, second pass {returned_rec_size}"
        );
    }
    bytes.truncate(btf_record_bytes(label, returned_count, returned_rec_size)?);
    Ok(())
}

fn btf_record_bytes(label: &str, count: u32, rec_size: u32) -> Result<usize> {
    let count = count as usize;
    let rec_size = rec_size as usize;
    count
        .checked_mul(rec_size)
        .ok_or_else(|| anyhow!("{label} byte length overflow"))
}

fn ptr_u64<T>(ptr: *mut T) -> u64 {
    if ptr.is_null() {
        0
    } else {
        ptr as u64
    }
}

fn read_u32_ne(bytes: &[u8], offset: usize, label: &str) -> Result<u32> {
    let end = offset
        .checked_add(std::mem::size_of::<u32>())
        .ok_or_else(|| anyhow!("{label} offset overflow"))?;
    let raw = bytes
        .get(offset..end)
        .ok_or_else(|| anyhow!("{label} record is truncated at offset {offset}"))?;
    Ok(u32::from_ne_bytes(
        raw.try_into().expect("slice length checked"),
    ))
}

fn read_u64_ne(bytes: &[u8], offset: usize, label: &str) -> Result<u64> {
    let end = offset
        .checked_add(std::mem::size_of::<u64>())
        .ok_or_else(|| anyhow!("{label} offset overflow"))?;
    let raw = bytes
        .get(offset..end)
        .ok_or_else(|| anyhow!("{label} record is truncated at offset {offset}"))?;
    Ok(u64::from_ne_bytes(
        raw.try_into().expect("slice length checked"),
    ))
}

fn bpf_insn_raw(code: u32, dst_reg: u32, src_reg: u32, off: i16, imm: i32) -> bpf_insn {
    let mut insn = bpf_insn {
        code: code as u8,
        off,
        imm,
        ..Default::default()
    };
    insn.set_dst_reg(dst_reg as u8);
    insn.set_src_reg(src_reg as u8);
    insn
}

fn ld_map_fd(dst_reg: u32, fd: i32) -> [bpf_insn; 2] {
    [
        bpf_insn_raw(BPF_LD | BPF_DW | BPF_IMM, dst_reg, BPF_PSEUDO_MAP_FD, 0, fd),
        bpf_insn_raw(0, 0, 0, 0, 0),
    ]
}

fn mov64_imm(dst_reg: u32, imm: i32) -> bpf_insn {
    bpf_insn_raw(BPF_ALU64 | BPF_MOV | BPF_K, dst_reg, 0, 0, imm)
}

fn mov64_reg(dst_reg: u32, src_reg: u32) -> bpf_insn {
    bpf_insn_raw(BPF_ALU64 | BPF_MOV | BPF_X, dst_reg, src_reg, 0, 0)
}

fn add64_imm(dst_reg: u32, imm: i32) -> bpf_insn {
    bpf_insn_raw(BPF_ALU64 | BPF_ADD | BPF_K, dst_reg, 0, 0, imm)
}

fn st_mem_w(dst_reg: u32, off: i16, imm: i32) -> bpf_insn {
    bpf_insn_raw(BPF_ST | BPF_MEM | BPF_W, dst_reg, 0, off, imm)
}

fn stx_mem_dw(dst_reg: u32, src_reg: u32, off: i16) -> bpf_insn {
    bpf_insn_raw(BPF_STX | BPF_MEM | BPF_DW, dst_reg, src_reg, off, 0)
}

fn jmp_imm(code: u32, dst_reg: u32, imm: i32, off: i16) -> bpf_insn {
    bpf_insn_raw(BPF_JMP | code | BPF_K, dst_reg, 0, off, imm)
}

fn call_helper(helper: bpf_func_id) -> bpf_insn {
    bpf_insn_raw(BPF_JMP | BPF_CALL, 0, 0, 0, helper as i32)
}

fn exit_insn() -> bpf_insn {
    bpf_insn_raw(BPF_JMP | BPF_EXIT, 0, 0, 0, 0)
}

fn branch_snapshot_sidecar_insns(ringbuf_fd: BorrowedFd<'_>, prog_id: u32) -> Vec<bpf_insn> {
    let mut insns = Vec::with_capacity(19);
    insns.extend(ld_map_fd(BPF_REG_1, ringbuf_fd.as_raw_fd()));
    insns.push(mov64_imm(BPF_REG_2, BRANCH_SNAPSHOT_EVENT_SIZE as i32));
    insns.push(mov64_imm(BPF_REG_3, 0));
    insns.push(call_helper(BPF_FUNC_ringbuf_reserve));
    insns.push(jmp_imm(BPF_JEQ, BPF_REG_0, 0, 12));
    insns.push(mov64_reg(BPF_REG_6, BPF_REG_0));
    insns.push(st_mem_w(BPF_REG_6, 0, prog_id as i32));
    insns.push(mov64_reg(BPF_REG_1, BPF_REG_6));
    insns.push(add64_imm(
        BPF_REG_1,
        BRANCH_SNAPSHOT_EVENT_HEADER_SIZE as i32,
    ));
    insns.push(mov64_imm(
        BPF_REG_2,
        (BRANCH_SNAPSHOT_MAX_ENTRIES * BRANCH_SNAPSHOT_ENTRY_SIZE) as i32,
    ));
    insns.push(mov64_imm(BPF_REG_3, 0));
    insns.push(call_helper(BPF_FUNC_GET_BRANCH_SNAPSHOT));
    insns.push(stx_mem_dw(BPF_REG_6, BPF_REG_0, 8));
    insns.push(mov64_reg(BPF_REG_1, BPF_REG_6));
    insns.push(mov64_imm(BPF_REG_2, 0));
    insns.push(call_helper(BPF_FUNC_ringbuf_submit));
    insns.push(mov64_imm(BPF_REG_0, 0));
    insns.push(exit_insn());
    insns
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

/// Read the next key from an open BPF map.
pub fn map_get_next_key(
    fd: BorrowedFd<'_>,
    key: Option<&[u8]>,
    next_key: &mut [u8],
) -> Result<bool> {
    if let Some(key) = key {
        if key.len() != next_key.len() {
            bail!(
                "BPF_MAP_GET_NEXT_KEY key size mismatch: current key has {} bytes, next key buffer has {} bytes",
                key.len(),
                next_key.len()
            );
        }
    }
    let key_ptr = key.map_or(std::ptr::null(), |key| key.as_ptr()) as *const libc::c_void;
    let ret = unsafe {
        bpf_map_get_next_key(
            fd.as_raw_fd(),
            key_ptr,
            next_key.as_mut_ptr() as *mut libc::c_void,
        )
    };
    if ret == 0 {
        return Ok(true);
    }
    let errno = errno_from_libbpf_ret(ret);
    if errno == libc::ENOENT {
        return Ok(false);
    }
    Err(anyhow!("BPF_MAP_GET_NEXT_KEY: {}", os_error(errno)))
}

/// Enable kernel BPF runtime stats and return the owning fd.
pub fn enable_stats(stats_type: bpf_stats_type) -> Result<OwnedFd> {
    let fd = unsafe { bpf_enable_stats(stats_type) };
    if fd < 0 {
        return Err(libbpf_error("BPF_ENABLE_STATS", fd));
    }
    Ok(unsafe { OwnedFd::from_raw_fd(fd) })
}

/// Open a perf event through `perf_event_open(2)`.
pub fn perf_event_open(
    attr: &mut perf_event_attr,
    pid: libc::pid_t,
    cpu: libc::c_int,
    group_fd: libc::c_int,
    flags: libc::c_ulong,
) -> Result<OwnedFd> {
    let fd = unsafe {
        libc::syscall(
            libc::SYS_perf_event_open,
            attr as *mut perf_event_attr,
            pid,
            cpu,
            group_fd,
            flags,
        )
    };
    if fd < 0 {
        return Err(raw_syscall_error("perf_event_open"));
    }
    Ok(unsafe { OwnedFd::from_raw_fd(fd as i32) })
}

/// Issue a perf event ioctl used to reset, enable, or disable an event.
pub fn perf_event_ioctl(fd: BorrowedFd<'_>, command: PerfEventCommand) -> Result<()> {
    let request = match command {
        PerfEventCommand::Enable => PERF_EVENT_IOC_ENABLE,
        PerfEventCommand::Disable => PERF_EVENT_IOC_DISABLE,
        PerfEventCommand::Reset => PERF_EVENT_IOC_RESET,
    };
    let ret = unsafe { libc::ioctl(fd.as_raw_fd(), request, 0) };
    if ret < 0 {
        return Err(raw_syscall_error("perf_event ioctl"));
    }
    Ok(())
}

/// Create a BPF ring buffer map.
pub fn create_ringbuf_map(name: &str, max_entries: u32) -> Result<OwnedFd> {
    create_map(BPF_MAP_TYPE_RINGBUF, name, 0, 0, max_entries, 0, 0, 0)
}

/// Create a BPF map through libbpf using metadata captured from a fixture.
pub fn create_map(
    map_type: bpf_map_type,
    name: &str,
    key_size: u32,
    value_size: u32,
    max_entries: u32,
    map_flags: u32,
    map_extra: u64,
    map_ifindex: u32,
) -> Result<OwnedFd> {
    let c_name = CString::new(name).map_err(|_| anyhow!("map name contains NUL: {name:?}"))?;
    let opts = bpf_map_create_opts {
        sz: std::mem::size_of::<bpf_map_create_opts>() as size_t,
        map_flags,
        map_extra,
        map_ifindex,
        ..Default::default()
    };
    let fd = unsafe {
        bpf_map_create(
            map_type,
            c_name.as_ptr(),
            key_size,
            value_size,
            max_entries,
            &opts,
        )
    };
    if fd < 0 {
        return Err(libbpf_error("BPF_MAP_CREATE", fd));
    }
    Ok(unsafe { OwnedFd::from_raw_fd(fd) })
}

/// Decode raw BPF func_info records from an open program fd.
pub fn prog_func_infos(fd: BorrowedFd<'_>) -> Result<Vec<ProgFuncInfo>> {
    let btf_info = prog_btf_info(fd)?;
    if btf_info.func_info.is_empty() {
        return Ok(Vec::new());
    }
    let rec_size = btf_info.func_info_rec_size as usize;
    if rec_size < std::mem::size_of::<bpf_func_info>() {
        bail!(
            "func_info rec_size {} is too small for bpf_func_info",
            btf_info.func_info_rec_size
        );
    }

    let count = btf_info.func_info.len() / rec_size;
    let mut records = Vec::with_capacity(count);
    for idx in 0..count {
        let base = idx
            .checked_mul(rec_size)
            .ok_or_else(|| anyhow!("func_info byte offset overflow"))?;
        records.push(ProgFuncInfo {
            insn_off: read_u32_ne(&btf_info.func_info, base, "func_info.insn_off")?,
            type_id: read_u32_ne(&btf_info.func_info, base + 4, "func_info.type_id")?,
        });
    }
    Ok(records)
}

/// Return the BTF function type ID for the main BPF function at instruction 0.
pub fn prog_main_func_btf_id(fd: BorrowedFd<'_>) -> Result<u32> {
    let records = prog_func_infos(fd)?;
    records
        .iter()
        .find_map(|record| (record.insn_off == 0).then_some(record.type_id))
        .filter(|type_id| *type_id != 0)
        .ok_or_else(|| anyhow!("target BPF program has no func_info record for insn_off 0"))
}

/// Retrieve native JIT function ranges for an open program fd.
pub fn prog_jited_func_ranges(fd: BorrowedFd<'_>) -> Result<Vec<JitedFuncRange>> {
    let first = obj_get_info_by_fd(fd)?;
    if first.nr_jited_ksyms == 0 || first.nr_jited_func_lens == 0 {
        bail!("target BPF program has no JIT function address metadata");
    }
    if first.nr_jited_ksyms != first.nr_jited_func_lens {
        bail!(
            "target BPF program has mismatched JIT metadata counts: nr_jited_ksyms={} nr_jited_func_lens={}",
            first.nr_jited_ksyms,
            first.nr_jited_func_lens
        );
    }

    let count = first.nr_jited_ksyms as usize;
    let mut ksyms = vec![0u64; count];
    let mut lens = vec![0u32; count];
    let mut info = BpfProgInfoFork {
        nr_jited_ksyms: first.nr_jited_ksyms,
        nr_jited_func_lens: first.nr_jited_func_lens,
        jited_ksyms: ptr_u64(ksyms.as_mut_ptr()),
        jited_func_lens: ptr_u64(lens.as_mut_ptr()),
        ..Default::default()
    };
    prog_obj_get_info_by_fd_into(fd, &mut info)?;
    if info.nr_jited_ksyms > first.nr_jited_ksyms
        || info.nr_jited_func_lens > first.nr_jited_func_lens
    {
        bail!(
            "target BPF program JIT metadata grew while reading: ksyms {}->{}, lens {}->{}",
            first.nr_jited_ksyms,
            info.nr_jited_ksyms,
            first.nr_jited_func_lens,
            info.nr_jited_func_lens
        );
    }
    if info.nr_jited_ksyms != info.nr_jited_func_lens {
        bail!(
            "target BPF program returned mismatched JIT metadata counts: nr_jited_ksyms={} nr_jited_func_lens={}",
            info.nr_jited_ksyms,
            info.nr_jited_func_lens
        );
    }

    ksyms.truncate(info.nr_jited_ksyms as usize);
    lens.truncate(info.nr_jited_func_lens as usize);
    let ranges = ksyms
        .into_iter()
        .zip(lens)
        .map(|(start_addr, byte_len)| JitedFuncRange {
            start_addr,
            byte_len,
        })
        .collect::<Vec<_>>();
    if ranges
        .iter()
        .any(|range| range.start_addr == 0 || range.byte_len == 0)
    {
        bail!("target BPF program returned empty JIT function range metadata");
    }
    Ok(ranges)
}

/// Retrieve kernel-provided native-address to BPF-PC line mapping.
pub fn prog_jited_line_info(fd: BorrowedFd<'_>) -> Result<Vec<JitedLineInfo>> {
    let first = obj_get_info_by_fd(fd)?;
    if first.nr_line_info == 0 || first.nr_jited_line_info == 0 {
        bail!("target BPF program has no jited_line_info metadata");
    }
    if first.nr_line_info != first.nr_jited_line_info {
        bail!(
            "target BPF program has mismatched line metadata counts: nr_line_info={} nr_jited_line_info={}",
            first.nr_line_info,
            first.nr_jited_line_info
        );
    }
    if first.line_info_rec_size < std::mem::size_of::<u32>() as u32 {
        bail!(
            "line_info_rec_size {} is too small to hold insn_off",
            first.line_info_rec_size
        );
    }
    if first.jited_line_info_rec_size < std::mem::size_of::<u64>() as u32 {
        bail!(
            "jited_line_info_rec_size {} is too small to hold a JIT address",
            first.jited_line_info_rec_size
        );
    }

    let mut line_info =
        allocate_btf_records("line_info", first.nr_line_info, first.line_info_rec_size)?;
    let mut jited_line_info = allocate_btf_records(
        "jited_line_info",
        first.nr_jited_line_info,
        first.jited_line_info_rec_size,
    )?;
    let mut info = BpfProgInfoFork {
        nr_line_info: first.nr_line_info,
        line_info_rec_size: first.line_info_rec_size,
        line_info: ptr_u64(line_info.as_mut_ptr()),
        nr_jited_line_info: first.nr_jited_line_info,
        jited_line_info_rec_size: first.jited_line_info_rec_size,
        jited_line_info: ptr_u64(jited_line_info.as_mut_ptr()),
        ..Default::default()
    };
    prog_obj_get_info_by_fd_into(fd, &mut info)?;
    shrink_btf_records(
        "line_info",
        &mut line_info,
        first.nr_line_info,
        info.nr_line_info,
        first.line_info_rec_size,
        info.line_info_rec_size,
    )?;
    shrink_btf_records(
        "jited_line_info",
        &mut jited_line_info,
        first.nr_jited_line_info,
        info.nr_jited_line_info,
        first.jited_line_info_rec_size,
        info.jited_line_info_rec_size,
    )?;
    if info.nr_line_info != info.nr_jited_line_info {
        bail!(
            "target BPF program returned mismatched line metadata counts: nr_line_info={} nr_jited_line_info={}",
            info.nr_line_info,
            info.nr_jited_line_info
        );
    }

    let count = info.nr_line_info as usize;
    let line_rec_size = info.line_info_rec_size as usize;
    let jited_rec_size = info.jited_line_info_rec_size as usize;
    let mut lines = Vec::with_capacity(count);
    for idx in 0..count {
        lines.push(JitedLineInfo {
            insn_off: read_u32_ne(&line_info, idx * line_rec_size, "line_info.insn_off")?,
            jited_addr: read_u64_ne(
                &jited_line_info,
                idx * jited_rec_size,
                "jited_line_info.addr",
            )?,
        });
    }
    if lines.iter().any(|line| line.jited_addr == 0) {
        bail!("target BPF program returned zero jited_line_info address");
    }
    lines.sort_by_key(|line| line.jited_addr);
    Ok(lines)
}

/// Load and attach a fexit sidecar that writes LBR snapshots to `ringbuf_fd`.
pub fn attach_branch_snapshot_sidecar(
    target_prog_fd: BorrowedFd<'_>,
    target_func_btf_id: u32,
    ringbuf_fd: BorrowedFd<'_>,
    prog_id: u32,
    mut log_buf: Option<&mut [u8]>,
) -> Result<BranchSnapshotSidecar> {
    if target_func_btf_id == 0 {
        bail!("target_func_btf_id must be non-zero");
    }
    if let Some(buf) = log_buf.as_deref_mut() {
        if buf.is_empty() {
            bail!("branch snapshot sidecar verifier log buffer must not be empty");
        }
        buf.fill(0);
    }

    let insns = branch_snapshot_sidecar_insns(ringbuf_fd, prog_id);
    let mut opts = bpf_prog_load_opts {
        sz: std::mem::size_of::<bpf_prog_load_opts>() as size_t,
        attempts: 1,
        expected_attach_type: BPF_TRACE_FEXIT,
        attach_prog_fd: target_prog_fd.as_raw_fd() as u32,
        attach_btf_id: target_func_btf_id,
        ..Default::default()
    };
    if let Some(buf) = log_buf.as_deref_mut() {
        opts.log_level = 2;
        opts.log_size = buf.len() as u32;
        opts.log_buf = buf.as_mut_ptr() as *mut c_char;
    }

    let prog_fd = unsafe {
        bpf_prog_load(
            BPF_PROG_TYPE_TRACING,
            BPFPROF_SIDECAR_NAME.as_ptr() as *const c_char,
            DEFAULT_LICENSE.as_ptr() as *const c_char,
            insns.as_ptr(),
            insns.len() as size_t,
            &mut opts,
        )
    };
    if prog_fd < 0 {
        let log = match log_buf.as_deref() {
            Some(buf) => extract_log_string(buf),
            None => String::new(),
        };
        if !log.is_empty() {
            return Err(anyhow!(
                "load branch snapshot sidecar: {}\nverifier log summary:\n{}",
                os_error(errno_from_libbpf_ret(prog_fd)),
                verifier_log_summary(&log)
            ));
        }
        return Err(libbpf_error("load branch snapshot sidecar", prog_fd));
    }
    let prog_fd = unsafe { OwnedFd::from_raw_fd(prog_fd) };

    let mut link_opts = bpf_link_create_opts {
        sz: std::mem::size_of::<bpf_link_create_opts>() as size_t,
        ..Default::default()
    };
    let link_fd = unsafe {
        bpf_link_create(
            prog_fd.as_raw_fd(),
            0,
            BPF_TRACE_FEXIT,
            &mut link_opts as *mut bpf_link_create_opts,
        )
    };
    if link_fd < 0 {
        return Err(libbpf_error("attach branch snapshot sidecar", link_fd));
    }

    Ok(BranchSnapshotSidecar {
        prog_fd,
        link_fd: unsafe { OwnedFd::from_raw_fd(link_fd) },
    })
}

impl<'a> RingBuffer<'a> {
    pub fn new<F>(map_fd: BorrowedFd<'_>, callback: F) -> Result<Self>
    where
        F: FnMut(&[u8]) -> i32 + 'a,
    {
        let mut callback = Box::new(RingBufferCallback {
            callback: Box::new(callback),
        });
        let ptr = unsafe {
            ring_buffer__new(
                map_fd.as_raw_fd(),
                Some(ring_buffer_sample_callback),
                callback.as_mut() as *mut RingBufferCallback<'a> as *mut c_void,
                std::ptr::null_mut(),
            )
        };
        let err = unsafe { libbpf_get_error(ptr as *const c_void) };
        if err != 0 {
            return Err(libbpf_ptr_error("ring_buffer__new", ptr as *const c_void));
        }
        let ptr = NonNull::new(ptr).ok_or_else(|| anyhow!("ring_buffer__new returned NULL"))?;
        Ok(Self {
            ptr,
            _callback: callback,
        })
    }

    pub fn poll(&self, timeout: Duration) -> Result<i32> {
        let timeout_ms = if timeout == Duration::MAX {
            -1
        } else {
            timeout
                .as_millis()
                .try_into()
                .map_err(|_| anyhow!("ring buffer poll timeout does not fit i32 milliseconds"))?
        };
        let ret = unsafe { ring_buffer__poll(self.ptr.as_ptr(), timeout_ms) };
        if ret < 0 {
            return Err(anyhow!("ring_buffer__poll: {}", os_error(-ret)));
        }
        Ok(ret)
    }
}

impl Drop for RingBuffer<'_> {
    fn drop(&mut self) {
        unsafe { ring_buffer__free(self.ptr.as_ptr()) };
    }
}

unsafe extern "C" fn ring_buffer_sample_callback(
    ctx: *mut c_void,
    data: *mut c_void,
    size: size_t,
) -> libc::c_int {
    let callback = unsafe { &mut *(ctx as *mut RingBufferCallback<'_>) };
    let Ok(size) = usize::try_from(size) else {
        return -libc::EOVERFLOW;
    };
    let sample = unsafe { slice::from_raw_parts(data as *const u8, size) };
    (callback.callback)(sample)
}

/// Submit replacement bytecode through the fork-only `BPF_PROG_REJIT` command.
pub fn prog_rejit(
    prog_fd: BorrowedFd<'_>,
    new_insns: &[bpf_insn],
    fd_array: &[i32],
    log_buf: Option<&mut Vec<u8>>,
) -> Result<()> {
    if prog_fd.as_raw_fd() < 0 {
        bail!("BPF_PROG_REJIT prog_fd must be non-negative");
    }
    let insn_cnt: u32 = new_insns
        .len()
        .try_into()
        .map_err(|_| anyhow!("BPF_PROG_REJIT instruction count does not fit __u32"))?;
    let fd_array_cnt: u32 = fd_array
        .len()
        .try_into()
        .map_err(|_| anyhow!("BPF_PROG_REJIT fd_array length does not fit __u32"))?;

    if let Some(buf) = log_buf {
        return prog_rejit_with_log_buf(buf, |log_buf| {
            prog_rejit_once(
                prog_fd,
                insn_cnt,
                new_insns,
                fd_array_cnt,
                fd_array,
                Some(log_buf),
            )
        });
    }

    prog_rejit_once(prog_fd, insn_cnt, new_insns, fd_array_cnt, fd_array, None)
        .map_err(format_prog_rejit_failure)
}

fn prog_rejit_with_log_buf<F>(log_buf: &mut Vec<u8>, mut run_once: F) -> Result<()>
where
    F: FnMut(&mut [u8]) -> std::result::Result<(), ProgRejitFailure>,
{
    validate_rejit_log_buf(log_buf)?;
    let mut log_buf_size = log_buf.len();
    loop {
        log_buf.resize(log_buf_size, 0);
        match run_once(log_buf.as_mut_slice()) {
            Ok(()) => return Ok(()),
            Err(failure) => {
                if failure.error.raw_os_error() == Some(libc::ENOSPC) {
                    if let Some(next_size) = next_rejit_log_buf_size(log_buf_size) {
                        log_buf_size = next_size;
                        continue;
                    }
                }
                return Err(format_prog_rejit_failure(failure));
            }
        }
    }
}

fn validate_rejit_log_buf(buf: &[u8]) -> Result<()> {
    if buf.is_empty() {
        bail!("BPF_PROG_REJIT log buffer must not be empty");
    }
    if buf.len() > u32::MAX as usize {
        bail!(
            "BPF_PROG_REJIT log buffer length {} does not fit __u32",
            buf.len()
        );
    }
    Ok(())
}

fn next_rejit_log_buf_size(current: usize) -> Option<usize> {
    if current >= MAX_REJIT_LOG_BUF_SIZE {
        return None;
    }
    let doubled = match current.checked_mul(2) {
        Some(value) => value,
        None => MAX_REJIT_LOG_BUF_SIZE,
    };
    let next = doubled.min(MAX_REJIT_LOG_BUF_SIZE);
    if next > current {
        Some(next)
    } else {
        None
    }
}

fn prog_rejit_once(
    prog_fd: BorrowedFd<'_>,
    insn_cnt: u32,
    new_insns: &[bpf_insn],
    fd_array_cnt: u32,
    fd_array: &[i32],
    mut log_buf: Option<&mut [u8]>,
) -> std::result::Result<(), ProgRejitFailure> {
    let mut attr: AttrRejit = zeroed();
    attr.prog_fd = prog_fd.as_raw_fd() as u32;
    attr.insn_cnt = insn_cnt;
    attr.insns = new_insns.as_ptr() as u64;
    if let Some(buf) = log_buf.as_deref_mut() {
        buf.fill(0);
        attr.log_level = 2;
        attr.log_size = buf.len() as u32;
        attr.log_buf = buf.as_mut_ptr() as u64;
    }
    if !fd_array.is_empty() {
        attr.fd_array = fd_array.as_ptr() as u64;
        attr.fd_array_cnt = fd_array_cnt;
    }

    let ret = unsafe { sys_bpf(BPF_PROG_REJIT, &mut attr, std::mem::size_of::<AttrRejit>()) };
    if ret < 0 {
        let error = std::io::Error::last_os_error();
        let log = match log_buf.as_deref() {
            Some(buf) => extract_log_string(buf),
            None => String::new(),
        };
        return Err(ProgRejitFailure { error, log });
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

/// Retrieve the kernel-translated instruction stream for an open program fd.
pub fn prog_xlated_insns(prog_fd: BorrowedFd<'_>) -> Result<Vec<bpf_insn>> {
    let info = obj_get_info_by_fd(prog_fd)?;
    let byte_len = info.xlated_prog_len as usize;
    if byte_len == 0 {
        bail!("target BPF program has no translated bytecode metadata");
    }

    let insn_size = std::mem::size_of::<bpf_insn>();
    if !byte_len.is_multiple_of(insn_size) {
        bail!(
            "xlated_prog_len {} is not a multiple of struct bpf_insn size {}",
            byte_len,
            insn_size
        );
    }

    let mut insns = vec![bpf_insn::default(); byte_len / insn_size];
    let mut info = BpfProgInfoFork {
        xlated_prog_len: byte_len as u32,
        xlated_prog_insns: insns.as_mut_ptr() as u64,
        ..Default::default()
    };
    prog_obj_get_info_by_fd_into(prog_fd, &mut info)?;

    let returned_len = info.xlated_prog_len as usize;
    if returned_len > byte_len {
        bail!(
            "xlated_prog_len grew while reading translated bytecode: first pass {} bytes, second pass {} bytes",
            byte_len,
            returned_len
        );
    }
    if !returned_len.is_multiple_of(insn_size) {
        bail!(
            "returned xlated_prog_len {} is not a multiple of struct bpf_insn size {}",
            returned_len,
            insn_size
        );
    }
    if returned_len == 0 || info.xlated_prog_insns == 0 {
        bail!("BPF_OBJ_GET_INFO_BY_FD did not return translated bytecode");
    }

    insns.truncate(returned_len / insn_size);
    Ok(insns)
}

/// Retrieve native JIT image bytes for an open program fd.
pub fn prog_jited_insns(prog_fd: BorrowedFd<'_>) -> Result<Vec<u8>> {
    let info = obj_get_info_by_fd(prog_fd)?;
    let byte_len = info.jited_prog_len as usize;
    if byte_len == 0 {
        bail!("target BPF program has no JIT image metadata");
    }

    let mut bytes = vec![0u8; byte_len];
    let mut info = BpfProgInfoFork {
        jited_prog_len: byte_len as u32,
        jited_prog_insns: bytes.as_mut_ptr() as u64,
        ..Default::default()
    };
    prog_obj_get_info_by_fd_into(prog_fd, &mut info)?;

    let returned_len = info.jited_prog_len as usize;
    if returned_len > byte_len {
        bail!(
            "jited_prog_len grew while reading JIT image: first pass {} bytes, second pass {} bytes",
            byte_len,
            returned_len
        );
    }
    if returned_len == 0 || info.jited_prog_insns == 0 {
        bail!("BPF_OBJ_GET_INFO_BY_FD did not return JIT image bytes");
    }

    bytes.truncate(returned_len);
    Ok(bytes)
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::fs::File;
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
    fn rejit_log_retry_doubles_until_limit() {
        assert_eq!(next_rejit_log_buf_size(1024), Some(2048));
        assert_eq!(
            next_rejit_log_buf_size(MAX_REJIT_LOG_BUF_SIZE / 2 + 1),
            Some(MAX_REJIT_LOG_BUF_SIZE)
        );
        assert_eq!(next_rejit_log_buf_size(MAX_REJIT_LOG_BUF_SIZE), None);
    }

    #[test]
    fn rejit_enospc_retry_exposes_final_log_to_caller() {
        let mut log_buf = vec![0u8; 8];
        let mut calls = 0usize;

        let err = prog_rejit_with_log_buf(&mut log_buf, |buf| {
            calls += 1;
            buf.fill(0);
            let (errno, message) = if calls == 1 {
                (libc::ENOSPC, "first")
            } else {
                (libc::EINVAL, "retry-log")
            };
            buf[..message.len()].copy_from_slice(message.as_bytes());
            Err(ProgRejitFailure {
                error: std::io::Error::from_raw_os_error(errno),
                log: extract_log_string(buf),
            })
        })
        .unwrap_err();

        assert_eq!(calls, 2);
        assert!(log_buf.len() >= 16);
        assert_eq!(extract_log_string(&log_buf), "retry-log");
        assert!(err.to_string().contains("retry-log"), "err={err:#}");
    }

    #[test]
    fn branch_snapshot_event_layout_matches_perf_branch_entry_abi() {
        assert_eq!(BRANCH_SNAPSHOT_ENTRY_SIZE, 24);
        assert_eq!(BRANCH_SNAPSHOT_EVENT_HEADER_SIZE, 16);
        assert_eq!(BRANCH_SNAPSHOT_EVENT_SIZE, 784);
    }

    #[test]
    fn branch_snapshot_sidecar_bytecode_calls_required_helpers() {
        let ringbuf = File::open("/dev/null").unwrap();
        let insns = branch_snapshot_sidecar_insns(ringbuf.as_fd(), 42);

        assert_eq!(insns.len(), 19);
        assert_eq!(insns[0].code as u32, BPF_LD | BPF_DW | BPF_IMM);
        assert_eq!(insns[0].dst_reg() as u32, BPF_REG_1);
        assert_eq!(insns[0].src_reg() as u32, BPF_PSEUDO_MAP_FD);
        assert_eq!(insns[2].imm, BRANCH_SNAPSHOT_EVENT_SIZE as i32);
        assert_eq!(insns[4].imm, BPF_FUNC_ringbuf_reserve as i32);
        assert_eq!(insns[5].off, 12);
        assert_eq!(insns[7].imm, 42);
        assert_eq!(insns[12].imm, BPF_FUNC_GET_BRANCH_SNAPSHOT as i32);
        assert_eq!(insns[16].imm, BPF_FUNC_ringbuf_submit as i32);
        assert_eq!(insns[18].code as u32, BPF_JMP | BPF_EXIT);
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
        assert_eq!(offset_of!(BpfProgInfoFork, prog_flags), 240);
        assert_eq!(size_of::<BpfProgInfoFork>(), 248);
    }

    #[test]
    fn btf_record_count_rejects_partial_record() {
        let records = BtfInfoRecords {
            rec_size: 8,
            bytes: &[0; 12],
        };

        let err = btf_record_count("func_info", records).unwrap_err();

        assert!(
            err.to_string().contains("not a multiple of rec_size"),
            "err={err:#}"
        );
    }

    #[test]
    fn btf_record_count_accepts_exact_records() {
        let records = BtfInfoRecords {
            rec_size: 8,
            bytes: &[0; 16],
        };

        assert_eq!(btf_record_count("func_info", records).unwrap(), Some(2));
    }

    #[test]
    fn verifier_states_json_round_trips_public_abi_fields() {
        let states = VerifierStatesJson {
            insns: vec![VerifierInsnJson {
                pc: 7,
                frame: 1,
                regs: BTreeMap::from([(
                    "r2".to_string(),
                    VerifierRegJson {
                        reg_type: "scalar".to_string(),
                        offset: Some(-8),
                        const_val: Some(42),
                        min: Some(0),
                        max: Some(63),
                        tnum: Some("0x2a/0x0".to_string()),
                    },
                )]),
            }],
        };

        let encoded = serde_json::to_string(&states).unwrap();
        assert!(encoded.contains("\"pc\":7"));
        assert!(encoded.contains("\"frame\":1"));
        assert!(encoded.contains("\"type\":\"scalar\""));

        let decoded: VerifierStatesJson = serde_json::from_str(&encoded).unwrap();
        assert_eq!(decoded, states);
    }

    #[test]
    fn verifier_states_json_defaults_frame_and_scalar_type() {
        let decoded: VerifierStatesJson =
            serde_json::from_str(r#"{"insns":[{"pc":3,"regs":{"r1":{"const_val":9}}}]}"#).unwrap();

        assert_eq!(decoded.insns[0].frame, 0);
        assert_eq!(decoded.insns[0].regs["r1"].reg_type, "scalar");
        assert_eq!(decoded.insns[0].regs["r1"].const_val, Some(9));
    }
}
