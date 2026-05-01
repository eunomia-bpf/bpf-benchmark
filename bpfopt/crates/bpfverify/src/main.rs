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
use kernel_sys::{FdArray, VerifierInsnJson, VerifierRegJson, VerifierStatesJson};
use serde::{Deserialize, Serialize};

const DEFAULT_LOG_BUF_SIZE: usize = 16 * 1024 * 1024;
const MAX_LOG_BUF_SIZE: usize = 256 * 1024 * 1024;
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
    /// Raw func_info records captured by bpfget --full.
    #[arg(long, value_name = "FILE")]
    func_info: Option<PathBuf>,
    /// Byte size of one func_info record.
    #[arg(long, value_name = "BYTES")]
    func_info_rec_size: Option<u32>,
    /// Raw line_info records captured by bpfget --full.
    #[arg(long, value_name = "FILE")]
    line_info: Option<PathBuf>,
    /// Byte size of one line_info record.
    #[arg(long, value_name = "BYTES")]
    line_info_rec_size: Option<u32>,
    /// Map FD manifest from bpfget --full.
    #[arg(long, value_name = "FILE")]
    map_fds: Option<PathBuf>,
    /// Program metadata fixture from bpfget --full, required with --dummy-map-fds.
    #[arg(long, value_name = "FILE")]
    prog_info: Option<PathBuf>,
    /// Create host-local dummy maps from --map-fds instead of reopening live map IDs.
    #[arg(long)]
    dummy_map_fds: bool,
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

#[derive(Debug, Clone)]
struct MapBinding {
    old_fd: Option<i32>,
    map_id: u32,
    metadata: Option<MapMetadata>,
}

#[derive(Debug, Clone)]
struct MapMetadata {
    map_type: u32,
    key_size: u32,
    value_size: u32,
    max_entries: u32,
    name: String,
    map_flags: u32,
    ifindex: u32,
    map_extra: u64,
}

#[derive(Debug, Deserialize)]
struct MapBindingJson {
    old_fd: Option<i64>,
    map_id: u64,
    map_type: Option<u32>,
    key_size: Option<u32>,
    value_size: Option<u32>,
    max_entries: Option<u32>,
    #[serde(default)]
    name: String,
    #[serde(default)]
    map_flags: u32,
    #[serde(default)]
    ifindex: u32,
    #[serde(default)]
    map_extra: u64,
}

#[derive(Debug, Deserialize)]
struct ProgInfoMapIds {
    #[serde(default)]
    map_ids: Vec<u32>,
}

struct AttachBtfObjFd {
    fd: Option<i32>,
    _owned_fd: Option<OwnedFd>,
}

#[derive(Debug)]
struct OwnedBtfInfoRecords {
    rec_size: u32,
    bytes: Vec<u8>,
}

impl OwnedBtfInfoRecords {
    fn as_kernel_records(&self) -> kernel_sys::BtfInfoRecords<'_> {
        kernel_sys::BtfInfoRecords {
            rec_size: self.rec_size,
            bytes: &self.bytes,
        }
    }
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
    validate_cli(&cli)?;
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
    let prog_map_ids = match cli.prog_info.as_deref() {
        Some(path) => Some(read_prog_info_map_ids(path)?),
        None => None,
    };
    let _map_fds = apply_map_fds(
        cli.map_fds.as_deref(),
        cli.dummy_map_fds,
        prog_map_ids.as_deref(),
        &mut insns,
    )?;
    let fd_array = read_fd_array(cli.fd_array.as_deref())?;
    let func_info = read_btf_info_records(
        cli.func_info.as_deref(),
        cli.func_info_rec_size,
        "func-info",
    )?;
    let line_info = read_btf_info_records(
        cli.line_info.as_deref(),
        cli.line_info_rec_size,
        "line-info",
    )?;
    let prog_btf_fd = resolve_optional_btf_fd(cli.prog_btf_fd, cli.prog_btf_id, "prog BTF")?;
    let attach_btf_obj_fd = resolve_optional_btf_fd(
        cli.attach_btf_obj_fd,
        cli.attach_btf_obj_id,
        "attach BTF object",
    )?;
    let log_level = effective_log_level(&cli);

    let mut log_buf_size = DEFAULT_LOG_BUF_SIZE;
    let dryrun = loop {
        let mut log_buf = if log_level > 0 {
            vec![0u8; log_buf_size]
        } else {
            Vec::new()
        };
        let report = kernel_sys::prog_load_dryrun_report(kernel_sys::ProgLoadDryRunOptions {
            prog_type,
            expected_attach_type,
            prog_btf_fd: prog_btf_fd.fd,
            attach_btf_id: cli.attach_btf_id,
            attach_btf_obj_fd: attach_btf_obj_fd.fd,
            func_info: func_info
                .as_ref()
                .map(OwnedBtfInfoRecords::as_kernel_records),
            line_info: line_info
                .as_ref()
                .map(OwnedBtfInfoRecords::as_kernel_records),
            insns: &insns,
            fd_array: (!fd_array.is_empty()).then_some(fd_array.as_slice()),
            log_level,
            log_buf: if log_level > 0 {
                Some(log_buf.as_mut_slice())
            } else {
                None
            },
        })
        .context("BPF_PROG_LOAD dry-run failed")?;

        if log_level > 0 && report.errno == Some(libc::ENOSPC) {
            match next_log_buf_size(log_buf_size, report.log_true_size)? {
                Some(next_size) => {
                    log_buf_size = next_size;
                    continue;
                }
                None => {}
            }
        }
        break report;
    };

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

fn next_log_buf_size(current: usize, log_true_size: u32) -> Result<Option<usize>> {
    if current == 0 {
        bail!("verifier log retry requires a non-zero current buffer size");
    }
    if current >= MAX_LOG_BUF_SIZE {
        return Ok(None);
    }

    let doubled = match current.checked_mul(2) {
        Some(value) => value,
        None => MAX_LOG_BUF_SIZE,
    };
    let requested_by_kernel = if log_true_size == 0 {
        current
    } else {
        usize::try_from(log_true_size)
            .map_err(|_| anyhow!("kernel verifier log_true_size does not fit usize"))?
            .checked_add(1)
            .ok_or_else(|| anyhow!("kernel verifier log_true_size overflow"))?
    };
    let desired = doubled.max(requested_by_kernel);
    let next = desired.min(MAX_LOG_BUF_SIZE);
    if next > current {
        Ok(Some(next))
    } else {
        Ok(None)
    }
}

fn validate_cli(cli: &Cli) -> Result<()> {
    if cli.dummy_map_fds {
        if cli.map_fds.is_none() {
            bail!("--dummy-map-fds requires --map-fds FILE");
        }
        if cli.prog_info.is_none() {
            bail!("--dummy-map-fds requires --prog-info FILE");
        }
    } else if cli.prog_info.is_some() {
        bail!("--prog-info is only valid with --dummy-map-fds");
    }
    Ok(())
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

fn read_btf_info_records(
    path: Option<&Path>,
    rec_size: Option<u32>,
    label: &str,
) -> Result<Option<OwnedBtfInfoRecords>> {
    let (path, rec_size) = match (path, rec_size) {
        (None, None) => return Ok(None),
        (Some(path), Some(rec_size)) => (path, rec_size),
        (Some(_), None) => bail!("--{label} requires --{label}-rec-size"),
        (None, Some(_)) => bail!("--{label}-rec-size requires --{label}"),
    };
    if rec_size == 0 {
        bail!("--{label}-rec-size must be non-zero");
    }
    let bytes = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
    if bytes.is_empty() {
        bail!("{label} file {} is empty", path.display());
    }
    if bytes.len() % rec_size as usize != 0 {
        bail!(
            "{label} file {} length {} is not a multiple of rec_size {rec_size}",
            path.display(),
            bytes.len()
        );
    }
    Ok(Some(OwnedBtfInfoRecords { rec_size, bytes }))
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

fn apply_map_fds(
    path: Option<&Path>,
    dummy_map_fds: bool,
    prog_map_ids: Option<&[u32]>,
    insns: &mut [kernel_sys::bpf_insn],
) -> Result<Vec<OwnedFd>> {
    let Some(path) = path else {
        return Ok(Vec::new());
    };
    let bindings = read_map_bindings(path)?;
    let dummy_prog_map_ids = if dummy_map_fds {
        let prog_map_ids =
            prog_map_ids.ok_or_else(|| anyhow!("--dummy-map-fds requires --prog-info FILE"))?;
        validate_dummy_map_fixtures(path, &bindings, prog_map_ids)?;
        Some(prog_map_ids)
    } else {
        None
    };
    let old_fds = pseudo_map_old_fds(insns);
    let old_fd_to_map_id = if let Some(map_ids) = dummy_prog_map_ids {
        build_old_fd_map_from_prog_info(map_ids, &old_fds, path)?
    } else {
        build_old_fd_map(&bindings, &old_fds, path)?
    };
    let indexed_map_ids = prog_map_ids
        .map(|ids| ids.to_vec())
        .unwrap_or_else(|| bindings.iter().map(|binding| binding.map_id).collect());

    let mut opened = HashMap::<u32, OwnedFd>::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        if is_pseudo_map_fd_ldimm64(&insns[pc]) {
            let old_fd = insns[pc].imm;
            let map_id = *old_fd_to_map_id
                .get(&old_fd)
                .ok_or_else(|| anyhow!("no map binding for pseudo-map old fd {old_fd}"))?;
            let new_fd =
                open_map_fd(&mut opened, &bindings, map_id, dummy_map_fds, path)?.as_raw_fd();
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
            let new_fd =
                open_map_fd(&mut opened, &bindings, map_id, dummy_map_fds, path)?.as_raw_fd();
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

fn build_old_fd_map(
    bindings: &[MapBinding],
    old_fds: &[i32],
    path: &Path,
) -> Result<HashMap<i32, u32>> {
    let mut old_fd_to_map_id = HashMap::new();

    for binding in bindings {
        let Some(old_fd) = binding.old_fd else {
            continue;
        };
        if let Some(previous) = old_fd_to_map_id.insert(old_fd, binding.map_id) {
            bail!(
                "{} maps pseudo-map old fd {} to both map {} and {}",
                path.display(),
                old_fd,
                previous,
                binding.map_id
            );
        }
    }

    let mut positional_map_ids = bindings
        .iter()
        .filter(|binding| binding.old_fd.is_none())
        .map(|binding| binding.map_id);
    for old_fd in old_fds.iter().copied() {
        if old_fd_to_map_id.contains_key(&old_fd) {
            continue;
        }
        let Some(map_id) = positional_map_ids.next() else {
            bail!(
                "{} does not provide a map_id for pseudo-map old fd {}",
                path.display(),
                old_fd
            );
        };
        old_fd_to_map_id.insert(old_fd, map_id);
    }

    Ok(old_fd_to_map_id)
}

fn build_old_fd_map_from_prog_info(
    prog_map_ids: &[u32],
    old_fds: &[i32],
    path: &Path,
) -> Result<HashMap<i32, u32>> {
    if old_fds.len() > prog_map_ids.len() {
        bail!(
            "{} prog_info exposes {} map ids but bytecode references {} pseudo-map old fds",
            path.display(),
            prog_map_ids.len(),
            old_fds.len()
        );
    }

    let mut old_fd_to_map_id = HashMap::new();
    for (old_fd, map_id) in old_fds.iter().copied().zip(prog_map_ids.iter().copied()) {
        if let Some(previous) = old_fd_to_map_id.insert(old_fd, map_id) {
            bail!(
                "{} maps pseudo-map old fd {} to both map {} and {}",
                path.display(),
                old_fd,
                previous,
                map_id
            );
        }
    }
    Ok(old_fd_to_map_id)
}

fn open_map_fd<'a>(
    opened: &'a mut HashMap<u32, OwnedFd>,
    bindings: &[MapBinding],
    map_id: u32,
    dummy_map_fds: bool,
    path: &Path,
) -> Result<&'a OwnedFd> {
    if !opened.contains_key(&map_id) {
        let fd = if dummy_map_fds {
            create_dummy_map_fd(bindings, map_id, path)?
        } else {
            kernel_sys::map_get_fd_by_id(map_id)
                .with_context(|| format!("open BPF map id {map_id} from {}", path.display()))?
        };
        opened.insert(map_id, fd);
    }
    opened
        .get(&map_id)
        .ok_or_else(|| anyhow!("internal error opening map id {map_id}"))
}

fn create_dummy_map_fd(bindings: &[MapBinding], map_id: u32, path: &Path) -> Result<OwnedFd> {
    let binding = bindings
        .iter()
        .find(|binding| binding.map_id == map_id)
        .ok_or_else(|| anyhow!("{} has no fixture for map id {map_id}", path.display()))?;
    let metadata = binding.metadata.as_ref().ok_or_else(|| {
        anyhow!(
            "{} map fixture {} is missing map metadata required by --dummy-map-fds",
            path.display(),
            map_id
        )
    })?;
    let name = dummy_map_name(map_id, &metadata.name)?;
    kernel_sys::create_map(
        metadata.map_type,
        &name,
        metadata.key_size,
        metadata.value_size,
        metadata.max_entries,
        metadata.map_flags,
        metadata.map_extra,
        metadata.ifindex,
    )
    .with_context(|| {
        format!(
            "create dummy BPF map id {map_id} type {} key_size {} value_size {} max_entries {} from {}",
            metadata.map_type,
            metadata.key_size,
            metadata.value_size,
            metadata.max_entries,
            path.display()
        )
    })
}

fn dummy_map_name(map_id: u32, fixture_name: &str) -> Result<String> {
    let name = if fixture_name.trim().is_empty() {
        format!("m{map_id}")
    } else {
        fixture_name.to_string()
    };
    if name.as_bytes().len() > 15 {
        bail!("dummy map name {name:?} exceeds BPF map name limit");
    }
    Ok(name)
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
        .map(map_binding_from_json)
        .collect()
}

fn map_binding_from_json((idx, row): (usize, serde_json::Value)) -> Result<MapBinding> {
    let row: MapBindingJson = serde_json::from_value(row)
        .with_context(|| format!("failed to parse map_fds entry {idx}"))?;
    let map_id = u32::try_from(row.map_id)
        .with_context(|| format!("map_fds entry {idx} map_id out of range"))?;
    let old_fd = row
        .old_fd
        .map(i32::try_from)
        .transpose()
        .with_context(|| format!("map_fds entry {idx} old_fd out of range"))?;
    let metadata = map_metadata_from_json(idx, &row)?;
    Ok(MapBinding {
        old_fd,
        map_id,
        metadata,
    })
}

fn map_metadata_from_json(idx: usize, row: &MapBindingJson) -> Result<Option<MapMetadata>> {
    let present = [
        row.map_type.is_some(),
        row.key_size.is_some(),
        row.value_size.is_some(),
        row.max_entries.is_some(),
    ];
    if present.iter().all(|value| !value) {
        return Ok(None);
    }
    if !present.iter().all(|value| *value) {
        bail!("map_fds entry {idx} has partial map metadata");
    }
    let map_type = row
        .map_type
        .ok_or_else(|| anyhow!("map_fds entry {idx} missing map_type"))?;
    let key_size = row
        .key_size
        .ok_or_else(|| anyhow!("map_fds entry {idx} missing key_size"))?;
    let value_size = row
        .value_size
        .ok_or_else(|| anyhow!("map_fds entry {idx} missing value_size"))?;
    let max_entries = row
        .max_entries
        .ok_or_else(|| anyhow!("map_fds entry {idx} missing max_entries"))?;
    Ok(Some(MapMetadata {
        map_type,
        key_size,
        value_size,
        max_entries,
        name: row.name.clone(),
        map_flags: row.map_flags,
        ifindex: row.ifindex,
        map_extra: row.map_extra,
    }))
}

fn read_prog_info_map_ids(path: &Path) -> Result<Vec<u32>> {
    let text =
        fs::read_to_string(path).with_context(|| format!("failed to read {}", path.display()))?;
    let info: ProgInfoMapIds = serde_json::from_str(&text)
        .with_context(|| format!("failed to parse prog_info JSON {}", path.display()))?;
    Ok(info.map_ids)
}

fn validate_dummy_map_fixtures(
    path: &Path,
    bindings: &[MapBinding],
    prog_map_ids: &[u32],
) -> Result<()> {
    let mut by_id = HashMap::new();
    for binding in bindings {
        if by_id.insert(binding.map_id, binding).is_some() {
            bail!(
                "{} contains duplicate fixture for map id {}",
                path.display(),
                binding.map_id
            );
        }
        if binding.metadata.is_none() {
            bail!(
                "{} map fixture {} is missing map metadata required by --dummy-map-fds",
                path.display(),
                binding.map_id
            );
        }
    }
    for map_id in prog_map_ids {
        if !by_id.contains_key(map_id) {
            bail!(
                "{} is missing map fixture for prog_info map id {}",
                path.display(),
                map_id
            );
        }
    }
    Ok(())
}

fn read_fd_array(path: Option<&Path>) -> Result<FdArray> {
    let Some(path) = path else {
        return Ok(FdArray::empty());
    };
    FdArray::from_json_file(path)
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
    fn verifier_log_retry_uses_kernel_true_size_when_available() {
        assert_eq!(next_log_buf_size(16, 100).unwrap(), Some(101));
    }

    #[test]
    fn verifier_log_retry_stops_at_configured_limit() {
        assert_eq!(next_log_buf_size(MAX_LOG_BUF_SIZE, 0).unwrap(), None);
        assert_eq!(
            next_log_buf_size(MAX_LOG_BUF_SIZE - 1, u32::MAX).unwrap(),
            Some(MAX_LOG_BUF_SIZE)
        );
    }

    #[test]
    fn dummy_map_fds_requires_portable_prog_info_fixture() {
        let cli = Cli::try_parse_from([
            "bpfverify",
            "--prog-type",
            "xdp",
            "--map-fds",
            "map_fds.json",
            "--dummy-map-fds",
        ])
        .unwrap();

        let err = validate_cli(&cli).unwrap_err();

        assert!(
            err.to_string()
                .contains("--dummy-map-fds requires --prog-info"),
            "err={err:#}"
        );
    }

    #[test]
    fn old_fd_bindings_use_positional_fixtures_only_for_unbound_fds() {
        let bindings = vec![
            MapBinding {
                old_fd: Some(10),
                map_id: 100,
                metadata: None,
            },
            MapBinding {
                old_fd: None,
                map_id: 200,
                metadata: None,
            },
        ];

        let resolved = build_old_fd_map(&bindings, &[10, 20], Path::new("map_fds.json")).unwrap();

        assert_eq!(resolved[&10], 100);
        assert_eq!(resolved[&20], 200);
    }

    #[test]
    fn dummy_old_fd_bindings_are_derived_from_prog_info_order() {
        let resolved =
            build_old_fd_map_from_prog_info(&[700, 800], &[31, 41], Path::new("map_fds.json"))
                .unwrap();

        assert_eq!(resolved[&31], 700);
        assert_eq!(resolved[&41], 800);
    }

    #[test]
    fn dummy_map_fixtures_require_metadata_for_each_prog_map() {
        let bindings = vec![MapBinding {
            old_fd: None,
            map_id: 7,
            metadata: None,
        }];

        let err =
            validate_dummy_map_fixtures(Path::new("map_fds.json"), &bindings, &[7]).unwrap_err();

        assert!(
            err.to_string().contains("missing map metadata"),
            "err={err:#}"
        );
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
    fn btf_info_records_require_matching_rec_size_arg() {
        let err =
            read_btf_info_records(Some(Path::new("func_info.bin")), None, "func-info").unwrap_err();

        assert!(
            err.to_string()
                .contains("--func-info requires --func-info-rec-size"),
            "err={err:#}"
        );
    }
}
