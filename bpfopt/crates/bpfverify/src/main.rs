// SPDX-License-Identifier: MIT
//! bpfverify CLI entry point.

mod verifier_log;

use std::collections::{BTreeMap, HashMap};
use std::fs;
use std::io::{self, Read, Write};
use std::os::fd::{AsRawFd, OwnedFd};
use std::path::{Path, PathBuf};
use std::process::ExitCode;

use anyhow::{anyhow, bail, Context, Result};
use clap::Parser;
use serde::{Deserialize, Serialize};

const DEFAULT_LOG_BUF_SIZE: usize = 16 * 1024 * 1024;
const BPF_LD_IMM64: u8 = (kernel_sys::BPF_LD | kernel_sys::BPF_DW | kernel_sys::BPF_IMM) as u8;
const BPF_PSEUDO_MAP_FD: u8 = kernel_sys::BPF_PSEUDO_MAP_FD as u8;
const BPF_PSEUDO_MAP_VALUE: u8 = kernel_sys::BPF_PSEUDO_MAP_VALUE as u8;
const BPF_PSEUDO_MAP_IDX: u8 = kernel_sys::BPF_PSEUDO_MAP_IDX as u8;
const BPF_PSEUDO_MAP_IDX_VALUE: u8 = kernel_sys::BPF_PSEUDO_MAP_IDX_VALUE as u8;

#[derive(Parser, Debug)]
#[command(name = "bpfverify", version, about = "Verify raw BPF bytecode")]
struct Cli {
    /// BPF program type, such as xdp, socket_filter, or kprobe.
    #[arg(long, value_name = "TYPE")]
    prog_type: String,
    /// Expected attach type for program types that need one.
    #[arg(long, value_name = "TYPE")]
    expected_attach_type: Option<String>,
    /// BTF object ID associated with program func/line info.
    #[arg(long, value_name = "ID")]
    prog_btf_id: Option<u32>,
    /// Open BTF fd associated with program func/line info.
    #[arg(long, value_name = "FD")]
    prog_btf_fd: Option<i32>,
    /// BTF type ID for tracing/LSM/struct_ops attach context replay.
    #[arg(long, value_name = "ID")]
    attach_btf_id: Option<u32>,
    /// Kernel BTF object ID for the attach target. Zero means vmlinux BTF.
    #[arg(long, value_name = "ID")]
    attach_btf_obj_id: Option<u32>,
    /// Open BTF object fd for the attach target.
    #[arg(long, value_name = "FD")]
    attach_btf_obj_fd: Option<i32>,
    /// Map FD manifest from bpfget --full.
    #[arg(long, value_name = "FILE")]
    map_fds: Option<PathBuf>,
    /// kinsn fd_array JSON manifest.
    #[arg(long, value_name = "FILE")]
    fd_array: Option<PathBuf>,
    /// Verifier log level. Defaults to 0; --report and --verifier-states-out force 2.
    #[arg(long, default_value_t = 0, value_name = "N")]
    log_level: u32,
    /// Raw struct bpf_insn[] input file. Defaults to stdin.
    #[arg(long, value_name = "FILE")]
    input: Option<PathBuf>,
    /// Raw struct bpf_insn[] output file. Defaults to stdout on verifier pass.
    #[arg(long, value_name = "FILE")]
    output: Option<PathBuf>,
    /// Structured verifier report JSON.
    #[arg(long, value_name = "FILE")]
    report: Option<PathBuf>,
    /// v3 verifier-states.json side output.
    #[arg(long, value_name = "FILE")]
    verifier_states_out: Option<PathBuf>,
}

#[derive(Debug, Serialize)]
struct VerifyReport {
    status: &'static str,
    verifier_log: String,
    verifier_states: VerifierStatesJson,
    insn_count: usize,
    log_level: u32,
    #[serde(skip_serializing_if = "Option::is_none")]
    errno: Option<i32>,
    #[serde(skip_serializing_if = "Option::is_none")]
    jited_size: Option<u32>,
    #[serde(skip_serializing_if = "is_zero")]
    log_true_size: u32,
}

#[derive(Clone, Debug, Serialize)]
struct VerifierStatesJson {
    insns: Vec<VerifierInsnJson>,
}

#[derive(Clone, Debug, Serialize)]
struct VerifierInsnJson {
    pc: usize,
    #[serde(skip_serializing_if = "is_zero_usize")]
    frame: usize,
    regs: BTreeMap<String, VerifierRegJson>,
}

#[derive(Clone, Debug, Serialize)]
struct VerifierRegJson {
    #[serde(rename = "type")]
    reg_type: String,
    #[serde(skip_serializing_if = "Option::is_none")]
    const_val: Option<i64>,
    #[serde(skip_serializing_if = "Option::is_none")]
    min: Option<i64>,
    #[serde(skip_serializing_if = "Option::is_none")]
    max: Option<i64>,
    #[serde(skip_serializing_if = "Option::is_none")]
    tnum: Option<String>,
}

#[derive(Debug, Clone)]
struct MapBinding {
    old_fd: Option<i32>,
    map_id: u32,
}

#[derive(Debug, Deserialize)]
struct FdArrayEntry {
    slot: Option<usize>,
    name: Option<String>,
    btf_fd: Option<i32>,
    btf_id: Option<u32>,
    btf_obj_id: Option<u32>,
    btf_module: Option<String>,
}

struct FdArray {
    fds: Vec<i32>,
    _owned_fds: Vec<OwnedFd>,
}

impl FdArray {
    fn empty() -> Self {
        Self {
            fds: Vec::new(),
            _owned_fds: Vec::new(),
        }
    }

    fn is_empty(&self) -> bool {
        self.fds.is_empty()
    }

    fn as_slice(&self) -> &[i32] {
        &self.fds
    }
}

struct AttachBtfObjFd {
    fd: Option<i32>,
    _owned_fd: Option<OwnedFd>,
}

fn main() -> ExitCode {
    match run() {
        Ok(code) => code,
        Err(err) => {
            eprintln!("{err:#}");
            ExitCode::FAILURE
        }
    }
}

fn run() -> Result<ExitCode> {
    let cli = Cli::parse();
    if cli.log_level > 2 {
        bail!("--log-level must be 0, 1, or 2");
    }

    let prog_type = parse_prog_type(&cli.prog_type)?;
    let expected_attach_type = cli
        .expected_attach_type
        .as_deref()
        .map(parse_attach_type)
        .transpose()?;
    validate_required_load_metadata(
        prog_type,
        expected_attach_type,
        cli.prog_btf_id,
        cli.prog_btf_fd,
        cli.attach_btf_id,
    )?;
    let input_bytes = read_input(cli.input.as_deref())?;
    let mut insns = decode_insns(&input_bytes)?;
    let _map_fds = apply_map_fds(cli.map_fds.as_deref(), &mut insns)?;
    let fd_array = read_fd_array(cli.fd_array.as_deref())?;
    let prog_btf_fd = resolve_optional_btf_fd(cli.prog_btf_fd, cli.prog_btf_id, "prog BTF")?;
    let attach_btf_obj_fd = resolve_optional_btf_fd(
        cli.attach_btf_obj_fd,
        cli.attach_btf_obj_id,
        "attach BTF object",
    )?;
    let log_level = effective_log_level(&cli);

    let mut log_buf = vec![0u8; DEFAULT_LOG_BUF_SIZE];
    let dryrun = kernel_sys::prog_load_dryrun_report(kernel_sys::ProgLoadDryRunOptions {
        prog_type,
        expected_attach_type,
        prog_btf_fd: prog_btf_fd.fd,
        attach_btf_id: cli.attach_btf_id,
        attach_btf_obj_fd: attach_btf_obj_fd.fd,
        insns: &insns,
        fd_array: (!fd_array.is_empty()).then_some(fd_array.as_slice()),
        log_level,
        log_buf: (log_level > 0).then_some(log_buf.as_mut_slice()),
    })
    .context("BPF_PROG_LOAD dry-run failed")?;

    let parsed_verifier_states = verifier_log::parse_verifier_log(&dryrun.verifier_log);
    let verifier_states = convert_verifier_states(&parsed_verifier_states);

    let report = VerifyReport {
        status: if dryrun.accepted { "pass" } else { "fail" },
        verifier_log: dryrun.verifier_log.clone(),
        verifier_states: verifier_states.clone(),
        insn_count: insns.len(),
        log_level,
        errno: dryrun.errno,
        jited_size: dryrun.jited_size,
        log_true_size: dryrun.log_true_size,
    };

    if let Some(path) = &cli.report {
        write_json_file(path, &report).with_context(|| format!("write {}", path.display()))?;
    }

    if let Some(path) = &cli.verifier_states_out {
        if !dryrun.accepted {
            print_verifier_failure(&dryrun);
            return Ok(ExitCode::FAILURE);
        }
        ensure_verifier_states_parseable(&dryrun.verifier_log, &parsed_verifier_states)?;
        write_json_file(path, &verifier_states)
            .with_context(|| format!("write {}", path.display()))?;
    }

    if dryrun.accepted {
        write_output(cli.output.as_deref(), &input_bytes)?;
        return Ok(ExitCode::SUCCESS);
    }

    if cli.report.is_some() && cli.verifier_states_out.is_none() {
        return Ok(ExitCode::SUCCESS);
    }

    print_verifier_failure(&dryrun);
    Ok(ExitCode::FAILURE)
}

fn effective_log_level(cli: &Cli) -> u32 {
    if cli.report.is_some() || cli.verifier_states_out.is_some() {
        2
    } else {
        cli.log_level
    }
}

fn read_input(path: Option<&Path>) -> Result<Vec<u8>> {
    let mut bytes = Vec::new();
    match path {
        Some(path) => {
            bytes = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
        }
        None => {
            io::stdin()
                .lock()
                .read_to_end(&mut bytes)
                .context("failed to read stdin")?;
        }
    }
    Ok(bytes)
}

fn write_output(path: Option<&Path>, bytes: &[u8]) -> Result<()> {
    match path {
        Some(path) => {
            fs::write(path, bytes).with_context(|| format!("failed to write {}", path.display()))
        }
        None => {
            let mut stdout = io::stdout().lock();
            stdout.write_all(bytes)?;
            stdout.flush()?;
            Ok(())
        }
    }
}

fn decode_insns(bytes: &[u8]) -> Result<Vec<kernel_sys::bpf_insn>> {
    let size = std::mem::size_of::<kernel_sys::bpf_insn>();
    if bytes.is_empty() {
        bail!("input bytecode is empty");
    }
    if !bytes.len().is_multiple_of(size) {
        bail!("bytecode size not aligned to {size}");
    }

    Ok(bytes
        .chunks_exact(size)
        .map(|chunk| {
            let mut insn = kernel_sys::bpf_insn {
                code: chunk[0],
                _bitfield_align_1: [],
                _bitfield_1: Default::default(),
                off: i16::from_le_bytes([chunk[2], chunk[3]]),
                imm: i32::from_le_bytes([chunk[4], chunk[5], chunk[6], chunk[7]]),
            };
            insn.set_dst_reg(chunk[1] & 0x0f);
            insn.set_src_reg((chunk[1] >> 4) & 0x0f);
            insn
        })
        .collect())
}

fn apply_map_fds(path: Option<&Path>, insns: &mut [kernel_sys::bpf_insn]) -> Result<Vec<OwnedFd>> {
    let Some(path) = path else {
        return Ok(Vec::new());
    };
    let bindings = read_map_bindings(path)?;
    let old_fds = pseudo_map_old_fds(insns);
    let mut old_fd_to_map_id = HashMap::new();

    for binding in bindings.iter().filter(|binding| binding.old_fd.is_some()) {
        old_fd_to_map_id.insert(binding.old_fd.unwrap(), binding.map_id);
    }
    let positional_old_fd_map_ids = bindings
        .iter()
        .filter(|binding| binding.old_fd.is_none())
        .map(|binding| binding.map_id)
        .collect::<Vec<_>>();
    let indexed_map_ids = bindings
        .iter()
        .map(|binding| binding.map_id)
        .collect::<Vec<_>>();
    for (idx, old_fd) in old_fds.iter().copied().enumerate() {
        if old_fd_to_map_id.contains_key(&old_fd) {
            continue;
        }
        let Some(&map_id) = positional_old_fd_map_ids.get(idx) else {
            bail!(
                "{} does not provide a map_id for pseudo-map old fd {}",
                path.display(),
                old_fd
            );
        };
        old_fd_to_map_id.insert(old_fd, map_id);
    }

    let mut opened = HashMap::<u32, OwnedFd>::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        if is_pseudo_map_fd_ldimm64(&insns[pc]) {
            let old_fd = insns[pc].imm;
            let map_id = *old_fd_to_map_id
                .get(&old_fd)
                .ok_or_else(|| anyhow!("no map binding for pseudo-map old fd {old_fd}"))?;
            let new_fd = open_map_fd(&mut opened, map_id, path)?.as_raw_fd();
            insns[pc].imm = new_fd;
            pc += 2;
        } else if is_pseudo_map_idx_ldimm64(&insns[pc]) {
            let raw_idx = insns[pc].imm;
            if raw_idx < 0 {
                bail!("pseudo-map fd_array index {raw_idx} is negative");
            }
            let idx = raw_idx as usize;
            let Some(&map_id) = indexed_map_ids.get(idx) else {
                bail!(
                    "{} does not provide a map_id for pseudo-map fd_array index {}",
                    path.display(),
                    idx
                );
            };
            let new_fd = open_map_fd(&mut opened, map_id, path)?.as_raw_fd();
            let src_reg = if insns[pc].src_reg() == BPF_PSEUDO_MAP_IDX {
                BPF_PSEUDO_MAP_FD
            } else {
                BPF_PSEUDO_MAP_VALUE
            };
            insns[pc].set_src_reg(src_reg);
            insns[pc].imm = new_fd;
            pc += 2;
        } else {
            pc += 1;
        }
    }

    Ok(opened.into_values().collect())
}

fn open_map_fd<'a>(
    opened: &'a mut HashMap<u32, OwnedFd>,
    map_id: u32,
    path: &Path,
) -> Result<&'a OwnedFd> {
    match opened.entry(map_id) {
        std::collections::hash_map::Entry::Occupied(entry) => Ok(entry.into_mut()),
        std::collections::hash_map::Entry::Vacant(entry) => {
            Ok(entry
                .insert(kernel_sys::map_get_fd_by_id(map_id).with_context(|| {
                    format!("open BPF map id {map_id} from {}", path.display())
                })?))
        }
    }
}

fn pseudo_map_old_fds(insns: &[kernel_sys::bpf_insn]) -> Vec<i32> {
    let mut old_fds = Vec::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        if is_pseudo_map_fd_ldimm64(&insns[pc]) {
            let old_fd = insns[pc].imm;
            if !old_fds.contains(&old_fd) {
                old_fds.push(old_fd);
            }
            pc += 2;
        } else {
            pc += 1;
        }
    }
    old_fds
}

fn is_pseudo_map_fd_ldimm64(insn: &kernel_sys::bpf_insn) -> bool {
    insn.code == BPF_LD_IMM64 && matches!(insn.src_reg(), BPF_PSEUDO_MAP_FD | BPF_PSEUDO_MAP_VALUE)
}

fn is_pseudo_map_idx_ldimm64(insn: &kernel_sys::bpf_insn) -> bool {
    insn.code == BPF_LD_IMM64
        && matches!(
            insn.src_reg(),
            BPF_PSEUDO_MAP_IDX | BPF_PSEUDO_MAP_IDX_VALUE
        )
}

fn read_map_bindings(path: &Path) -> Result<Vec<MapBinding>> {
    let text =
        fs::read_to_string(path).with_context(|| format!("failed to read {}", path.display()))?;
    let value: serde_json::Value = serde_json::from_str(&text)
        .with_context(|| format!("failed to parse map_fds JSON {}", path.display()))?;
    let rows = if let Some(array) = value.as_array() {
        array.clone()
    } else if let Some(array) = value.get("maps").and_then(|v| v.as_array()) {
        array.clone()
    } else if let Some(array) = value.get("map_ids").and_then(|v| v.as_array()) {
        array
            .iter()
            .map(|map_id| serde_json::json!({ "map_id": map_id }))
            .collect()
    } else {
        bail!(
            "{} must be an array or contain maps/map_ids",
            path.display()
        );
    };

    rows.into_iter()
        .enumerate()
        .map(|(idx, row)| {
            let map_id = row
                .get("map_id")
                .and_then(|v| v.as_u64())
                .ok_or_else(|| anyhow!("map_fds entry {idx} is missing map_id"))?;
            let old_fd = row.get("old_fd").and_then(|v| v.as_i64());
            Ok(MapBinding {
                old_fd: old_fd.map(|fd| fd as i32),
                map_id: u32::try_from(map_id)
                    .with_context(|| format!("map_fds entry {idx} map_id out of range"))?,
            })
        })
        .collect()
}

fn read_fd_array(path: Option<&Path>) -> Result<FdArray> {
    let Some(path) = path else {
        return Ok(FdArray::empty());
    };
    let text =
        fs::read_to_string(path).with_context(|| format!("failed to read {}", path.display()))?;
    let entries: Vec<FdArrayEntry> = serde_json::from_str(&text)
        .with_context(|| format!("failed to parse fd_array JSON {}", path.display()))?;
    let (required, owned_fds) = required_btf_fds(&entries)?;
    Ok(FdArray {
        fds: build_rejit_fd_array(&required),
        _owned_fds: owned_fds,
    })
}

fn required_btf_fds(entries: &[FdArrayEntry]) -> Result<(Vec<i32>, Vec<OwnedFd>)> {
    let has_slots = entries.iter().any(|entry| entry.slot.is_some());
    let has_missing_slots = entries.iter().any(|entry| entry.slot.is_none());
    if has_slots && has_missing_slots {
        bail!("fd_array entries must either all specify slot or all omit slot");
    }

    let mut rows = Vec::with_capacity(entries.len());
    let mut owned_fds = Vec::new();
    for (index, entry) in entries.iter().enumerate() {
        let label = entry
            .name
            .as_deref()
            .map(|name| format!(" ({name})"))
            .unwrap_or_else(String::new);
        let btf_fd = resolve_btf_fd(entry, index, &label, &mut owned_fds)?;
        let slot = entry.slot.unwrap_or(index + 1);
        if slot == 0 {
            bail!("fd_array entry {index}{label} uses invalid slot 0");
        }
        rows.push((slot, btf_fd));
    }

    rows.sort_by_key(|(slot, _)| *slot);
    let mut out = Vec::with_capacity(rows.len());
    for (expected, (slot, btf_fd)) in (1usize..).zip(rows) {
        if slot != expected {
            bail!(
                "fd_array slots must be dense starting at 1; expected slot {expected}, got {slot}"
            );
        }
        out.push(btf_fd);
    }
    Ok((out, owned_fds))
}

fn resolve_btf_fd(
    entry: &FdArrayEntry,
    index: usize,
    label: &str,
    owned_fds: &mut Vec<OwnedFd>,
) -> Result<i32> {
    if entry.btf_module.is_some() {
        bail!("fd_array entry {index}{label} uses unsupported btf_module");
    }
    if let Some(btf_fd) = entry.btf_fd {
        if btf_fd < 0 {
            bail!("fd_array entry {index}{label} has negative btf_fd {btf_fd}");
        }
        return Ok(btf_fd);
    }
    let btf_id = entry
        .btf_id
        .or(entry.btf_obj_id)
        .ok_or_else(|| anyhow!("fd_array entry {index}{label} is missing btf_fd or btf_id"))?;
    if btf_id == 0 {
        bail!("fd_array entry {index}{label} has invalid btf_id 0");
    }
    let fd = kernel_sys::btf_get_fd_by_id(btf_id).with_context(|| {
        format!("open BTF fd for fd_array entry {index}{label} btf_id {btf_id}")
    })?;
    let raw_fd = fd.as_raw_fd();
    owned_fds.push(fd);
    Ok(raw_fd)
}

fn build_rejit_fd_array(required_btf_fds: &[i32]) -> Vec<i32> {
    if required_btf_fds.is_empty() {
        return Vec::new();
    }
    let mut fd_array = Vec::with_capacity(required_btf_fds.len() + 1);
    fd_array.push(required_btf_fds[0]);
    fd_array.extend_from_slice(required_btf_fds);
    fd_array
}

fn ensure_verifier_states_parseable(
    log: &str,
    states: &[verifier_log::VerifierInsn],
) -> Result<()> {
    if !log.trim().is_empty() && states.is_empty() {
        bail!("verifier log did not contain parseable state snapshots");
    }
    Ok(())
}

fn convert_verifier_states(states: &[verifier_log::VerifierInsn]) -> VerifierStatesJson {
    let has_delta = states
        .iter()
        .any(|state| state.kind == verifier_log::VerifierInsnKind::InsnDeltaState);
    let insns = states
        .iter()
        .filter(|state| state.kind != verifier_log::VerifierInsnKind::BranchDeltaState)
        .filter(|state| !has_delta || state.kind == verifier_log::VerifierInsnKind::InsnDeltaState)
        .filter_map(convert_verifier_state)
        .collect();
    VerifierStatesJson { insns }
}

fn convert_verifier_state(state: &verifier_log::VerifierInsn) -> Option<VerifierInsnJson> {
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

fn convert_reg_state(reg: &verifier_log::RegState) -> Option<VerifierRegJson> {
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

    (const_val.is_some() || min.is_some() || max.is_some() || tnum.is_some()).then_some(
        VerifierRegJson {
            reg_type: reg.reg_type.clone(),
            const_val,
            min,
            max,
            tnum,
        },
    )
}

fn write_json_file<T: Serialize>(path: &Path, value: &T) -> Result<()> {
    let mut bytes = Vec::new();
    serde_json::to_writer_pretty(&mut bytes, value)?;
    bytes.push(b'\n');
    fs::write(path, bytes)?;
    Ok(())
}

fn print_verifier_failure(report: &kernel_sys::ProgLoadDryRunReport) {
    if !report.verifier_log.trim().is_empty() {
        eprintln!("{}", report.verifier_log);
    } else if let Some(errno) = report.errno {
        eprintln!(
            "BPF_PROG_LOAD dry-run failed: {}",
            io::Error::from_raw_os_error(errno)
        );
    } else {
        eprintln!("BPF_PROG_LOAD dry-run failed");
    }
}

fn resolve_optional_btf_fd(
    btf_fd: Option<i32>,
    btf_id: Option<u32>,
    label: &str,
) -> Result<AttachBtfObjFd> {
    match (btf_fd, btf_id) {
        (Some(_), Some(_)) => {
            bail!("{label}: fd and id options are mutually exclusive")
        }
        (Some(fd), None) => {
            if fd < 0 {
                bail!("{label}: fd must be non-negative");
            }
            Ok(AttachBtfObjFd {
                fd: Some(fd),
                _owned_fd: None,
            })
        }
        (None, Some(0) | None) => Ok(AttachBtfObjFd {
            fd: None,
            _owned_fd: None,
        }),
        (None, Some(id)) => {
            let owned_fd = kernel_sys::btf_get_fd_by_id(id)
                .with_context(|| format!("open {label} id {id}"))?;
            let fd = owned_fd.as_raw_fd();
            Ok(AttachBtfObjFd {
                fd: Some(fd),
                _owned_fd: Some(owned_fd),
            })
        }
    }
}

fn parse_prog_type(input: &str) -> Result<kernel_sys::bpf_prog_type> {
    let normalized = normalize_type_name(input, "bpf_prog_type_");
    let value = match normalized.as_str() {
        "socket_filter" => kernel_sys::BPF_PROG_TYPE_SOCKET_FILTER,
        "kprobe" => kernel_sys::BPF_PROG_TYPE_KPROBE,
        "sched_cls" => kernel_sys::BPF_PROG_TYPE_SCHED_CLS,
        "sched_act" => kernel_sys::BPF_PROG_TYPE_SCHED_ACT,
        "tracepoint" => kernel_sys::BPF_PROG_TYPE_TRACEPOINT,
        "xdp" => kernel_sys::BPF_PROG_TYPE_XDP,
        "perf_event" => kernel_sys::BPF_PROG_TYPE_PERF_EVENT,
        "cgroup_skb" => kernel_sys::BPF_PROG_TYPE_CGROUP_SKB,
        "cgroup_sock" => kernel_sys::BPF_PROG_TYPE_CGROUP_SOCK,
        "lwt_in" => kernel_sys::BPF_PROG_TYPE_LWT_IN,
        "lwt_out" => kernel_sys::BPF_PROG_TYPE_LWT_OUT,
        "lwt_xmit" => kernel_sys::BPF_PROG_TYPE_LWT_XMIT,
        "sock_ops" => kernel_sys::BPF_PROG_TYPE_SOCK_OPS,
        "sk_skb" => kernel_sys::BPF_PROG_TYPE_SK_SKB,
        "cgroup_device" => kernel_sys::BPF_PROG_TYPE_CGROUP_DEVICE,
        "sk_msg" => kernel_sys::BPF_PROG_TYPE_SK_MSG,
        "raw_tracepoint" => kernel_sys::BPF_PROG_TYPE_RAW_TRACEPOINT,
        "cgroup_sock_addr" => kernel_sys::BPF_PROG_TYPE_CGROUP_SOCK_ADDR,
        "lwt_seg6local" => kernel_sys::BPF_PROG_TYPE_LWT_SEG6LOCAL,
        "lirc_mode2" => kernel_sys::BPF_PROG_TYPE_LIRC_MODE2,
        "sk_reuseport" => kernel_sys::BPF_PROG_TYPE_SK_REUSEPORT,
        "flow_dissector" => kernel_sys::BPF_PROG_TYPE_FLOW_DISSECTOR,
        "cgroup_sysctl" => kernel_sys::BPF_PROG_TYPE_CGROUP_SYSCTL,
        "raw_tracepoint_writable" => kernel_sys::BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE,
        "cgroup_sockopt" => kernel_sys::BPF_PROG_TYPE_CGROUP_SOCKOPT,
        "tracing" => kernel_sys::BPF_PROG_TYPE_TRACING,
        "struct_ops" => kernel_sys::BPF_PROG_TYPE_STRUCT_OPS,
        "ext" => kernel_sys::BPF_PROG_TYPE_EXT,
        "lsm" => kernel_sys::BPF_PROG_TYPE_LSM,
        "sk_lookup" => kernel_sys::BPF_PROG_TYPE_SK_LOOKUP,
        "syscall" => kernel_sys::BPF_PROG_TYPE_SYSCALL,
        "netfilter" => kernel_sys::BPF_PROG_TYPE_NETFILTER,
        _ => bail!("unknown prog type '{input}'"),
    };
    Ok(value)
}

fn parse_attach_type(input: &str) -> Result<kernel_sys::bpf_attach_type> {
    if let Ok(value) = input.parse::<kernel_sys::bpf_attach_type>() {
        return Ok(value);
    }
    let normalized = normalize_type_name(input, "bpf_");
    let value = match normalized.as_str() {
        "cgroup_inet_ingress" => kernel_sys::BPF_CGROUP_INET_INGRESS,
        "cgroup_inet_egress" => kernel_sys::BPF_CGROUP_INET_EGRESS,
        "cgroup_inet_sock_create" => kernel_sys::BPF_CGROUP_INET_SOCK_CREATE,
        "cgroup_sock_ops" => kernel_sys::BPF_CGROUP_SOCK_OPS,
        "sk_skb_stream_parser" => kernel_sys::BPF_SK_SKB_STREAM_PARSER,
        "sk_skb_stream_verdict" => kernel_sys::BPF_SK_SKB_STREAM_VERDICT,
        "cgroup_device" => kernel_sys::BPF_CGROUP_DEVICE,
        "sk_msg_verdict" => kernel_sys::BPF_SK_MSG_VERDICT,
        "cgroup_inet4_bind" => kernel_sys::BPF_CGROUP_INET4_BIND,
        "cgroup_inet6_bind" => kernel_sys::BPF_CGROUP_INET6_BIND,
        "cgroup_inet4_connect" => kernel_sys::BPF_CGROUP_INET4_CONNECT,
        "cgroup_inet6_connect" => kernel_sys::BPF_CGROUP_INET6_CONNECT,
        "cgroup_inet4_post_bind" => kernel_sys::BPF_CGROUP_INET4_POST_BIND,
        "cgroup_inet6_post_bind" => kernel_sys::BPF_CGROUP_INET6_POST_BIND,
        "cgroup_udp4_sendmsg" => kernel_sys::BPF_CGROUP_UDP4_SENDMSG,
        "cgroup_udp6_sendmsg" => kernel_sys::BPF_CGROUP_UDP6_SENDMSG,
        "cgroup_sysctl" => kernel_sys::BPF_CGROUP_SYSCTL,
        "cgroup_udp4_recvmsg" => kernel_sys::BPF_CGROUP_UDP4_RECVMSG,
        "cgroup_udp6_recvmsg" => kernel_sys::BPF_CGROUP_UDP6_RECVMSG,
        "cgroup_getsockopt" => kernel_sys::BPF_CGROUP_GETSOCKOPT,
        "cgroup_setsockopt" => kernel_sys::BPF_CGROUP_SETSOCKOPT,
        "xdp_devlmap" | "xdp_devmap" => kernel_sys::BPF_XDP_DEVMAP,
        "xdp_cpumap" => kernel_sys::BPF_XDP_CPUMAP,
        "xdp" => kernel_sys::BPF_XDP,
        "trace_raw_tp" => kernel_sys::BPF_TRACE_RAW_TP,
        "trace_fentry" => kernel_sys::BPF_TRACE_FENTRY,
        "trace_fexit" => kernel_sys::BPF_TRACE_FEXIT,
        "modify_return" => kernel_sys::BPF_MODIFY_RETURN,
        "lsm_mac" => kernel_sys::BPF_LSM_MAC,
        "trace_iter" => kernel_sys::BPF_TRACE_ITER,
        "cgroup_inet4_getpeername" => kernel_sys::BPF_CGROUP_INET4_GETPEERNAME,
        "cgroup_inet6_getpeername" => kernel_sys::BPF_CGROUP_INET6_GETPEERNAME,
        "cgroup_inet4_getsockname" => kernel_sys::BPF_CGROUP_INET4_GETSOCKNAME,
        "cgroup_inet6_getsockname" => kernel_sys::BPF_CGROUP_INET6_GETSOCKNAME,
        "cgroup_inet_sock_release" => kernel_sys::BPF_CGROUP_INET_SOCK_RELEASE,
        "sk_lookup" => kernel_sys::BPF_SK_LOOKUP,
        "sk_skb_verdict" => kernel_sys::BPF_SK_SKB_VERDICT,
        "sk_reuseport_select" => kernel_sys::BPF_SK_REUSEPORT_SELECT,
        "sk_reuseport_select_or_migrate" => kernel_sys::BPF_SK_REUSEPORT_SELECT_OR_MIGRATE,
        "trace_kprobe_multi" => kernel_sys::BPF_TRACE_KPROBE_MULTI,
        "lsm_cgroup" => kernel_sys::BPF_LSM_CGROUP,
        "netfilter" => kernel_sys::BPF_NETFILTER,
        "tcx_ingress" => kernel_sys::BPF_TCX_INGRESS,
        "tcx_egress" => kernel_sys::BPF_TCX_EGRESS,
        "trace_uprobe_multi" => kernel_sys::BPF_TRACE_UPROBE_MULTI,
        "cgroup_unix_connect" => kernel_sys::BPF_CGROUP_UNIX_CONNECT,
        "cgroup_unix_sendmsg" => kernel_sys::BPF_CGROUP_UNIX_SENDMSG,
        "cgroup_unix_recvmsg" => kernel_sys::BPF_CGROUP_UNIX_RECVMSG,
        "cgroup_unix_getpeername" => kernel_sys::BPF_CGROUP_UNIX_GETPEERNAME,
        "cgroup_unix_getsockname" => kernel_sys::BPF_CGROUP_UNIX_GETSOCKNAME,
        "netkit_primary" => kernel_sys::BPF_NETKIT_PRIMARY,
        "netkit_peer" => kernel_sys::BPF_NETKIT_PEER,
        "trace_kprobe_session" => kernel_sys::BPF_TRACE_KPROBE_SESSION,
        "trace_uprobe_session" => kernel_sys::BPF_TRACE_UPROBE_SESSION,
        "trace_fsession" => kernel_sys::BPF_TRACE_FSESSION,
        _ => bail!("unknown attach type '{input}'"),
    };
    Ok(value)
}

fn validate_required_load_metadata(
    prog_type: kernel_sys::bpf_prog_type,
    expected_attach_type: Option<kernel_sys::bpf_attach_type>,
    prog_btf_id: Option<u32>,
    prog_btf_fd: Option<i32>,
    attach_btf_id: Option<u32>,
) -> Result<()> {
    if prog_type_requires_prog_btf(prog_type)
        && prog_btf_fd.is_none()
        && !matches!(prog_btf_id, Some(id) if id != 0)
    {
        bail!(
            "prog type {} requires replaying non-zero prog BTF metadata; pass --prog-btf-id or --prog-btf-fd",
            prog_type
        );
    }

    if prog_type_requires_attach_btf(prog_type) && !matches!(attach_btf_id, Some(id) if id != 0) {
        bail!(
            "prog type {} requires replaying non-zero attach_btf_id metadata",
            prog_type
        );
    }

    if prog_type_requires_expected_attach_type(prog_type) && expected_attach_type.is_none() {
        bail!(
            "prog type {} requires replaying expected_attach_type metadata",
            prog_type
        );
    }

    Ok(())
}

fn prog_type_requires_prog_btf(prog_type: kernel_sys::bpf_prog_type) -> bool {
    matches!(
        prog_type,
        kernel_sys::BPF_PROG_TYPE_KPROBE
            | kernel_sys::BPF_PROG_TYPE_TRACING
            | kernel_sys::BPF_PROG_TYPE_LSM
            | kernel_sys::BPF_PROG_TYPE_EXT
    )
}

fn prog_type_requires_attach_btf(prog_type: kernel_sys::bpf_prog_type) -> bool {
    matches!(
        prog_type,
        kernel_sys::BPF_PROG_TYPE_TRACING
            | kernel_sys::BPF_PROG_TYPE_LSM
            | kernel_sys::BPF_PROG_TYPE_STRUCT_OPS
            | kernel_sys::BPF_PROG_TYPE_EXT
    )
}

fn prog_type_requires_expected_attach_type(prog_type: kernel_sys::bpf_prog_type) -> bool {
    matches!(
        prog_type,
        kernel_sys::BPF_PROG_TYPE_TRACING | kernel_sys::BPF_PROG_TYPE_LSM
    )
}

fn normalize_type_name(input: &str, prefix: &str) -> String {
    input
        .trim()
        .trim_start_matches(prefix)
        .trim_start_matches(&prefix.to_ascii_uppercase())
        .replace(['-', ' '], "_")
        .to_ascii_lowercase()
}

fn is_zero(value: &u32) -> bool {
    *value == 0
}

fn is_zero_usize(value: &usize) -> bool {
    *value == 0
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn prog_type_parser_accepts_common_names() {
        assert_eq!(
            parse_prog_type("xdp").unwrap(),
            kernel_sys::BPF_PROG_TYPE_XDP
        );
        assert_eq!(
            parse_prog_type("socket-filter").unwrap(),
            kernel_sys::BPF_PROG_TYPE_SOCKET_FILTER
        );
        assert!(parse_prog_type("not-a-type").is_err());
    }

    #[test]
    fn log_level_default_is_zero_and_outputs_force_two() {
        let cli = Cli::try_parse_from(["bpfverify", "--prog-type", "xdp"]).unwrap();
        assert_eq!(cli.log_level, 0);
        assert_eq!(effective_log_level(&cli), 0);

        let report_cli =
            Cli::try_parse_from(["bpfverify", "--prog-type", "xdp", "--report", "r.json"]).unwrap();
        assert_eq!(effective_log_level(&report_cli), 2);

        let states_cli = Cli::try_parse_from([
            "bpfverify",
            "--prog-type",
            "xdp",
            "--log-level",
            "0",
            "--verifier-states-out",
            "states.json",
        ])
        .unwrap();
        assert_eq!(effective_log_level(&states_cli), 2);
    }

    #[test]
    fn verifier_state_conversion_prefers_delta_states() {
        let parsed = verifier_log::parse_verifier_log(
            r#"
0: R1=ctx() R10=fp0
1: (b7) r2 = 42                       ; R2=42
2: (07) r2 += 1                       ; R2=scalar(umin=42,umax=43,var_off=(0x2a; 0x1))
"#,
        );

        let converted = convert_verifier_states(&parsed);

        assert_eq!(converted.insns.len(), 2);
        assert_eq!(converted.insns[0].pc, 1);
        let r2 = &converted.insns[0].regs["r2"];
        assert_eq!(r2.reg_type, "scalar");
        assert_eq!(r2.const_val, Some(42));
        assert_eq!(
            converted.insns[1].regs["r2"].tnum.as_deref(),
            Some("0x2a/0x1")
        );
    }

    #[test]
    fn verifier_state_conversion_drops_branch_delta_states() {
        let parsed = verifier_log::parse_verifier_log(
            r#"
8: (85) call bpf_map_lookup_elem#1     ; R0=map_value_or_null(id=1)
9: (55) if r0 != 0x0 goto pc+1        ; R0=0 R2=0
from 9 to 11: R0=map_ptr(ks=4,vs=64) R10=fp0
11: (b7) r3 = 8                       ; R3=8
"#,
        );

        let converted = convert_verifier_states(&parsed);

        assert_eq!(
            converted
                .insns
                .iter()
                .map(|insn| insn.pc)
                .collect::<Vec<_>>(),
            vec![11]
        );
        assert_eq!(converted.insns[0].regs["r3"].const_val, Some(8));
    }

    #[test]
    fn fd_array_reserves_slot_zero() {
        assert_eq!(build_rejit_fd_array(&[]), Vec::<i32>::new());
        assert_eq!(build_rejit_fd_array(&[11, 22]), vec![11, 11, 22]);
    }
}
