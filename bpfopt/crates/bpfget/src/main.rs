// SPDX-License-Identifier: MIT
//! bpfget CLI entry point.

use std::collections::BTreeMap;
use std::fs::{self, OpenOptions};
use std::io::{self, Write};
use std::os::fd::{AsFd, BorrowedFd};
use std::path::{Path, PathBuf};
use std::process::ExitCode;
use std::sync::atomic::{AtomicU64, Ordering};

use anyhow::{anyhow, bail, Context, Result};
use clap::Parser;
use serde::{Deserialize, Serialize};

static NEXT_TMP_ID: AtomicU64 = AtomicU64::new(0);

const BPF_LD_IMM64: u8 = (kernel_sys::BPF_LD | kernel_sys::BPF_DW | kernel_sys::BPF_IMM) as u8;
const BPF_PSEUDO_MAP_FD: u8 = kernel_sys::BPF_PSEUDO_MAP_FD as u8;
const BPF_PSEUDO_MAP_VALUE: u8 = kernel_sys::BPF_PSEUDO_MAP_VALUE as u8;
const FUNC_INFO_FILE: &str = "func_info.bin";
const LINE_INFO_FILE: &str = "line_info.bin";

#[derive(Parser, Debug)]
#[command(
    name = "bpfget",
    version,
    about = "Read live BPF program bytecode and metadata"
)]
struct Cli {
    /// Live BPF program ID. Not used with --list or --target.
    #[arg(value_name = "PROG_ID")]
    prog_id: Option<u32>,
    /// Write program metadata JSON.
    #[arg(long)]
    info: bool,
    /// Write prog.bin, prog_info.json, and map_fds.json to --outdir.
    #[arg(long)]
    full: bool,
    /// Output directory for --full.
    #[arg(long, value_name = "DIR")]
    outdir: Option<PathBuf>,
    /// List live BPF programs.
    #[arg(long)]
    list: bool,
    /// Required JSON output mode for --list.
    #[arg(long)]
    json: bool,
    /// Write target.json for the host platform.
    #[arg(long)]
    target: bool,
    /// Output file. Required for JSON metadata modes; raw bytecode defaults to stdout.
    #[arg(long, value_name = "FILE")]
    output: Option<PathBuf>,
    /// Manual kinsn descriptors for --target, comma-separated name:btf_func_id.
    #[arg(long, value_name = "LIST", value_delimiter = ',')]
    kinsns: Vec<String>,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
struct TypeJson {
    name: String,
    numeric: u32,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
struct ProgInfoJson {
    id: u32,
    name: String,
    #[serde(rename = "type")]
    prog_type: TypeJson,
    insn_cnt: u32,
    map_ids: Vec<u32>,
    load_time: u64,
    created_by_uid: u32,
    xlated_prog_len: u32,
    orig_prog_len: u32,
    jited_prog_len: u32,
    btf_id: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    func_info_rec_size: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    nr_func_info: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    line_info_rec_size: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    nr_line_info: u32,
    attach_btf_obj_id: u32,
    attach_btf_id: u32,
    #[serde(skip_serializing_if = "Option::is_none")]
    expected_attach_type: Option<TypeJson>,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
struct MapInfoJson {
    #[serde(skip_serializing_if = "Option::is_none")]
    old_fd: Option<i32>,
    map_id: u32,
    map_type: u32,
    key_size: u32,
    value_size: u32,
    max_entries: u32,
    name: String,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    map_flags: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    ifindex: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    btf_id: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    btf_key_type_id: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    btf_value_type_id: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    btf_vmlinux_value_type_id: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    btf_vmlinux_id: u32,
    #[serde(default, skip_serializing_if = "is_zero_u64")]
    map_extra: u64,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
struct ListProgJson {
    id: u32,
    name: String,
    #[serde(rename = "type")]
    prog_type: TypeJson,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
struct TargetJson {
    arch: String,
    features: Vec<String>,
    kinsns: BTreeMap<String, TargetKinsnJson>,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
struct TargetKinsnJson {
    btf_func_id: i32,
    btf_id: u32,
}

struct KinsnProbeTarget {
    json_name: &'static str,
    probe_names: &'static [&'static str],
}

const KINSN_PROBE_TARGETS: &[KinsnProbeTarget] = &[
    KinsnProbeTarget {
        json_name: "bpf_rotate64",
        probe_names: &["bpf_rotate64"],
    },
    KinsnProbeTarget {
        json_name: "bpf_select64",
        probe_names: &["bpf_select64"],
    },
    KinsnProbeTarget {
        json_name: "bpf_ccmp64",
        probe_names: &["bpf_ccmp64"],
    },
    KinsnProbeTarget {
        json_name: "bpf_extract64",
        probe_names: &["bpf_extract64"],
    },
    KinsnProbeTarget {
        json_name: "bpf_endian_load64",
        probe_names: &["bpf_endian_load64"],
    },
    KinsnProbeTarget {
        json_name: "bpf_bulk_memcpy",
        probe_names: &["bpf_bulk_memcpy", "bpf_memcpy_bulk"],
    },
    KinsnProbeTarget {
        json_name: "bpf_bulk_memset",
        probe_names: &["bpf_bulk_memset", "bpf_memset_bulk"],
    },
];

fn main() -> ExitCode {
    match run() {
        Ok(()) => ExitCode::SUCCESS,
        Err(err) => {
            eprintln!("{err:#}");
            ExitCode::FAILURE
        }
    }
}

fn run() -> Result<()> {
    let cli = Cli::parse();
    validate_cli(&cli)?;

    if cli.list {
        return list_programs(cli.output.as_deref().expect("validated --output"));
    }
    if cli.target {
        return write_target_json(
            cli.output.as_deref().expect("validated --output"),
            &cli.kinsns,
        );
    }

    let prog_id = cli.prog_id.expect("validated PROG_ID");
    if cli.info {
        let (info, map_ids) = get_prog_info_with_map_ids(prog_id)?;
        let expected_attach_type = expected_attach_type_json(info.id, info.prog_type)?;
        let prog_info = ProgInfoJson::from_info(info, map_ids, expected_attach_type)?;
        return write_json_file(
            cli.output.as_deref().expect("validated --output"),
            &prog_info,
        );
    }
    if cli.full {
        return write_full(prog_id, cli.outdir.as_deref().expect("validated --outdir"));
    }

    let fd = open_prog_fd(prog_id)?;
    let insns = kernel_sys::prog_get_original(fd.as_fd())
        .with_context(|| format!("read original bytecode for BPF program id {prog_id}"))?;
    ensure_original_bytecode(&insns)?;
    write_insns(cli.output.as_deref(), &insns)
}

fn validate_cli(cli: &Cli) -> Result<()> {
    let mode_count = [cli.info, cli.full, cli.list, cli.target]
        .into_iter()
        .filter(|enabled| *enabled)
        .count();
    if mode_count > 1 {
        bail!("choose at most one of --info, --full, --list, or --target");
    }

    if cli.list || cli.target {
        if cli.prog_id.is_some() {
            bail!("PROG_ID is not valid with --list or --target");
        }
    } else if cli.prog_id.is_none() {
        bail!("PROG_ID is required unless --list or --target is used");
    }

    if cli.json && !cli.list {
        bail!("--json is only valid with --list");
    }
    if cli.list && !cli.json {
        bail!("--list requires --json");
    }
    if (cli.info || cli.list || cli.target) && cli.output.is_none() {
        bail!("--output FILE is required for JSON metadata modes");
    }
    if cli.full {
        if cli.outdir.is_none() {
            bail!("--full requires --outdir DIR");
        }
        if cli.output.is_some() {
            bail!("--output is not valid with --full");
        }
    } else if cli.outdir.is_some() {
        bail!("--outdir is only valid with --full");
    }
    if !cli.target && !cli.kinsns.is_empty() {
        bail!("--kinsns is only valid with --target");
    }

    Ok(())
}

impl ProgInfoJson {
    fn from_info(
        info: kernel_sys::BpfProgInfoFork,
        map_ids: Vec<u32>,
        expected_attach_type: Option<TypeJson>,
    ) -> Result<Self> {
        let insn_size = std::mem::size_of::<kernel_sys::bpf_insn>() as u32;
        let insn_bytes = if info.orig_prog_len != 0 {
            info.orig_prog_len
        } else {
            info.xlated_prog_len
        };

        let json = Self {
            id: info.id,
            name: c_name_u8(&info.name),
            prog_type: TypeJson {
                name: prog_type_name(info.prog_type).to_string(),
                numeric: info.prog_type,
            },
            insn_cnt: insn_bytes / insn_size,
            map_ids,
            load_time: info.load_time,
            created_by_uid: info.created_by_uid,
            xlated_prog_len: info.xlated_prog_len,
            orig_prog_len: info.orig_prog_len,
            jited_prog_len: info.jited_prog_len,
            btf_id: info.btf_id,
            func_info_rec_size: info.func_info_rec_size,
            nr_func_info: info.nr_func_info,
            line_info_rec_size: info.line_info_rec_size,
            nr_line_info: info.nr_line_info,
            attach_btf_obj_id: info.attach_btf_obj_id,
            attach_btf_id: info.attach_btf_id,
            expected_attach_type,
        };
        validate_required_load_metadata(&json)?;
        Ok(json)
    }
}

fn validate_required_load_metadata(info: &ProgInfoJson) -> Result<()> {
    let prog_type = info.prog_type.numeric;
    if prog_type_requires_prog_btf(prog_type) && info.btf_id == 0 {
        bail!(
            "prog type {} requires non-zero btf_id metadata",
            info.prog_type.name
        );
    }

    if prog_type_requires_attach_btf(prog_type) && info.attach_btf_id == 0 {
        bail!(
            "prog type {} requires non-zero attach_btf_id metadata",
            info.prog_type.name
        );
    }

    if prog_type_requires_expected_attach_type(prog_type) && info.expected_attach_type.is_none() {
        bail!(
            "prog type {} requires expected_attach_type metadata",
            info.prog_type.name
        );
    }
    validate_btf_record_metadata("func_info", info.nr_func_info, info.func_info_rec_size)?;
    validate_btf_record_metadata("line_info", info.nr_line_info, info.line_info_rec_size)?;

    Ok(())
}

fn validate_btf_record_metadata(label: &str, count: u32, rec_size: u32) -> Result<()> {
    if count != 0 && rec_size == 0 {
        bail!("{label} count is {count} but rec_size is zero");
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

fn expected_attach_type_json(
    prog_id: u32,
    prog_type: kernel_sys::bpf_prog_type,
) -> Result<Option<TypeJson>> {
    let Some(value) = kernel_sys::expected_attach_type_for_prog(prog_id, prog_type)
        .with_context(|| format!("recover expected attach type for BPF program id {prog_id}"))?
    else {
        return Ok(None);
    };
    Ok(Some(TypeJson {
        name: attach_type_name(value).unwrap_or("").to_string(),
        numeric: value,
    }))
}

fn write_full(prog_id: u32, outdir: &Path) -> Result<()> {
    ensure_existing_dir(outdir)?;

    let fd = open_prog_fd(prog_id)?;
    let insns = kernel_sys::prog_get_original(fd.as_fd())
        .with_context(|| format!("read original bytecode for BPF program id {prog_id}"))?;
    ensure_original_bytecode(&insns)?;
    let (info, map_ids) = get_prog_info_with_map_ids_from_fd(fd.as_fd(), prog_id)?;
    let expected_attach_type = expected_attach_type_json(info.id, info.prog_type)?;
    let btf_info = kernel_sys::prog_btf_info(fd.as_fd())
        .with_context(|| format!("read BTF record metadata for BPF program id {prog_id}"))?;
    let pseudo_map_old_fds = pseudo_map_old_fds(&insns);
    let map_infos = get_map_infos(&map_ids, &pseudo_map_old_fds)?;

    let prog_bin = encode_insns(&insns);
    let prog_info = ProgInfoJson::from_info(info, map_ids, expected_attach_type)?;
    let prog_info_json = json_bytes(&prog_info)?;
    let map_fds_json = json_bytes(&map_infos)?;

    validate_btf_record_blob(
        "func_info",
        prog_info.nr_func_info,
        prog_info.func_info_rec_size,
        &btf_info.func_info,
    )?;
    validate_btf_record_blob(
        "line_info",
        prog_info.nr_line_info,
        prog_info.line_info_rec_size,
        &btf_info.line_info,
    )?;

    let mut entries = vec![
        ("prog.bin", prog_bin.as_slice()),
        ("prog_info.json", prog_info_json.as_slice()),
        ("map_fds.json", map_fds_json.as_slice()),
    ];
    if !btf_info.func_info.is_empty() {
        entries.push((FUNC_INFO_FILE, btf_info.func_info.as_slice()));
    }
    if !btf_info.line_info.is_empty() {
        entries.push((LINE_INFO_FILE, btf_info.line_info.as_slice()));
    }

    write_full_files_atomic(outdir, &entries)
}

fn validate_btf_record_blob(label: &str, count: u32, rec_size: u32, bytes: &[u8]) -> Result<()> {
    let expected = (count as usize)
        .checked_mul(rec_size as usize)
        .ok_or_else(|| anyhow!("{label} byte length overflow"))?;
    if bytes.len() != expected {
        bail!(
            "{label} metadata expected {expected} bytes from {count} records of size {rec_size}, got {}",
            bytes.len()
        );
    }
    Ok(())
}

fn list_programs(output: &Path) -> Result<()> {
    let mut start_id = 0;
    let mut rows = Vec::new();

    loop {
        let Some(prog_id) = kernel_sys::prog_get_next_id(start_id)
            .with_context(|| format!("enumerate BPF programs after id {start_id}"))?
        else {
            break;
        };
        start_id = prog_id;

        match get_prog_info_with_map_ids(prog_id) {
            Ok((info, _)) => rows.push(ListProgJson {
                id: info.id,
                name: c_name_u8(&info.name),
                prog_type: TypeJson {
                    name: prog_type_name(info.prog_type).to_string(),
                    numeric: info.prog_type,
                },
            }),
            Err(err) if err.to_string().contains("No such file or directory") => continue,
            Err(err) => return Err(err),
        }
    }

    write_json_file(output, &rows)
}

fn write_target_json(output: &Path, kinsn_specs: &[String]) -> Result<()> {
    let kinsns = if kinsn_specs.is_empty() {
        let kinsns = probe_target_kinsns().with_context(|| {
            "failed to probe target kinsn BTF; --target requires readable kernel BTF or explicit --kinsns"
        })?;
        if kinsns.is_empty() {
            bail!("target kinsn BTF probing found no kinsn functions; target.json would be incomplete");
        }
        kinsns
    } else {
        parse_kinsns(kinsn_specs)?
    };
    if kinsns.is_empty() {
        bail!("target.json requires at least one kinsn descriptor");
    }

    let target = TargetJson {
        arch: detect_arch(),
        features: detect_features(),
        kinsns,
    };
    write_json_file(output, &target)
}

fn probe_target_kinsns() -> Result<BTreeMap<String, TargetKinsnJson>> {
    let mut found = BTreeMap::new();
    let mut start_id = 0u32;
    let mut saw_btf = false;
    let vmlinux_btf =
        kernel_sys::KernelBtf::load_vmlinux().context("load vmlinux BTF for split BTF probing")?;

    loop {
        let btf_id = match kernel_sys::btf_get_next_id(start_id) {
            Ok(Some(id)) => id,
            Ok(None) => break,
            Err(err) => {
                return Err(err)
                    .with_context(|| format!("enumerate BTF objects after id {start_id}"));
            }
        };
        saw_btf = true;
        start_id = btf_id;

        match kernel_sys::KernelBtf::load_from_kernel_by_id(btf_id) {
            Ok(btf) => {
                probe_kinsns_in_btf(btf_id, &btf, &mut found)?;
            }
            Err(err) => {
                let btf = kernel_sys::KernelBtf::load_from_kernel_by_id_split(btf_id, &vmlinux_btf)
                    .with_context(|| {
                        format!("load split BTF id {btf_id}; direct BTF load failed: {err:#}")
                    })?;
                probe_kinsns_in_btf(btf_id, &btf, &mut found)?;
            }
        }

        if found.len() == KINSN_PROBE_TARGETS.len() {
            break;
        }
    }

    if !saw_btf {
        bail!("no kernel BTF objects are visible");
    }

    Ok(found)
}

fn probe_kinsns_in_btf(
    btf_id: u32,
    btf: &kernel_sys::KernelBtf,
    found: &mut BTreeMap<String, TargetKinsnJson>,
) -> Result<()> {
    for target in KINSN_PROBE_TARGETS {
        if found.contains_key(target.json_name) {
            continue;
        }
        for &probe_name in target.probe_names {
            if let Some(btf_func_id) = btf
                .find_func_by_name(probe_name)
                .with_context(|| format!("inspect BTF id {btf_id} for {probe_name}"))?
            {
                let Ok(btf_func_id) = i32::try_from(btf_func_id) else {
                    bail!(
                        "BTF id {btf_id} function {probe_name} type id {btf_func_id} exceeds target.json i32 range"
                    );
                };
                found.insert(
                    target.json_name.to_string(),
                    TargetKinsnJson {
                        btf_func_id,
                        btf_id,
                    },
                );
                break;
            }
        }
    }
    Ok(())
}

fn parse_kinsns(specs: &[String]) -> Result<BTreeMap<String, TargetKinsnJson>> {
    let mut out = BTreeMap::new();
    for spec in specs {
        let (name, value) = spec
            .split_once(':')
            .or_else(|| spec.split_once('='))
            .ok_or_else(|| anyhow!("invalid --kinsns entry {spec:?}; expected name:btf_func_id"))?;
        if name.is_empty() {
            bail!("invalid --kinsns entry {spec:?}: name must not be empty");
        }
        let btf_func_id = value
            .parse::<i32>()
            .with_context(|| format!("invalid btf_func_id in --kinsns entry {spec:?}"))?;
        if out
            .insert(
                name.to_string(),
                TargetKinsnJson {
                    btf_func_id,
                    btf_id: 0,
                },
            )
            .is_some()
        {
            bail!("duplicate --kinsns entry for {name}");
        }
    }
    Ok(out)
}

fn detect_arch() -> String {
    match std::env::consts::ARCH {
        "x86_64" => "x86_64".to_string(),
        "aarch64" => "aarch64".to_string(),
        other => other.to_string(),
    }
}

fn detect_features() -> Vec<String> {
    let mut features = Vec::new();

    #[cfg(target_arch = "x86_64")]
    {
        features.push("cmov".to_string());
        if std::is_x86_feature_detected!("bmi1") {
            features.push("bmi1".to_string());
        }
        if std::is_x86_feature_detected!("bmi2") {
            features.push("bmi2".to_string());
            features.push("rorx".to_string());
        }
        if std::is_x86_feature_detected!("movbe") {
            features.push("movbe".to_string());
        }
    }

    #[cfg(target_arch = "aarch64")]
    {
        let cpu_features = cpuinfo_feature_tokens();
        for feature in ["lse", "atomics", "crc32", "asimd"] {
            if cpu_features.iter().any(|token| token == feature) {
                features.push(feature.to_string());
            }
        }
    }

    #[cfg(not(any(target_arch = "x86_64", target_arch = "aarch64")))]
    {
        features.extend(cpuinfo_feature_tokens());
    }

    features
}

#[cfg(any(
    target_arch = "aarch64",
    not(any(target_arch = "x86_64", target_arch = "aarch64"))
))]
fn cpuinfo_feature_tokens() -> Vec<String> {
    let Ok(cpuinfo) = fs::read_to_string("/proc/cpuinfo") else {
        return Vec::new();
    };

    let mut tokens = Vec::new();
    for line in cpuinfo.lines() {
        let Some((key, value)) = line.split_once(':') else {
            continue;
        };
        let key = key.trim().to_ascii_lowercase();
        if key != "features" && key != "flags" {
            continue;
        }
        for token in value.split_whitespace() {
            let token = token.to_ascii_lowercase();
            if !tokens.contains(&token) {
                tokens.push(token);
            }
        }
    }
    tokens
}

fn get_prog_info_with_map_ids(prog_id: u32) -> Result<(kernel_sys::BpfProgInfoFork, Vec<u32>)> {
    let fd = open_prog_fd(prog_id)?;
    get_prog_info_with_map_ids_from_fd(fd.as_fd(), prog_id)
}

fn get_prog_info_with_map_ids_from_fd(
    fd: BorrowedFd<'_>,
    prog_id: u32,
) -> Result<(kernel_sys::BpfProgInfoFork, Vec<u32>)> {
    let info = kernel_sys::obj_get_info_by_fd(fd)
        .with_context(|| format!("read info for BPF program id {prog_id}"))?;
    let map_ids = read_prog_map_ids(fd, info.nr_map_ids)
        .with_context(|| format!("read map ids for BPF program id {prog_id}"))?;
    Ok((info, map_ids))
}

fn read_prog_map_ids(fd: BorrowedFd<'_>, nr_map_ids: u32) -> Result<Vec<u32>> {
    kernel_sys::prog_map_ids(fd, nr_map_ids)
}

fn get_map_infos(map_ids: &[u32], pseudo_map_old_fds: &[i32]) -> Result<Vec<MapInfoJson>> {
    if pseudo_map_old_fds.len() > map_ids.len() {
        bail!(
            "original bytecode references {} pseudo-map fd values but prog_info exposes only {} map ids",
            pseudo_map_old_fds.len(),
            map_ids.len()
        );
    }

    let mut maps = Vec::with_capacity(map_ids.len());
    for (idx, &map_id) in map_ids.iter().enumerate() {
        let fd = kernel_sys::map_get_fd_by_id(map_id)
            .with_context(|| format!("open BPF map id {map_id}"))?;
        let info = kernel_sys::map_obj_get_info_by_fd(fd.as_fd())
            .with_context(|| format!("read info for BPF map id {map_id}"))?;
        maps.push(MapInfoJson {
            old_fd: pseudo_map_old_fds.get(idx).copied(),
            map_id,
            map_type: info.type_,
            key_size: info.key_size,
            value_size: info.value_size,
            max_entries: info.max_entries,
            name: c_name_i8(&info.name),
            map_flags: info.map_flags,
            ifindex: info.ifindex,
            btf_id: info.btf_id,
            btf_key_type_id: info.btf_key_type_id,
            btf_value_type_id: info.btf_value_type_id,
            btf_vmlinux_value_type_id: info.btf_vmlinux_value_type_id,
            btf_vmlinux_id: info.btf_vmlinux_id,
            map_extra: info.map_extra,
        });
    }
    Ok(maps)
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

fn open_prog_fd(prog_id: u32) -> Result<std::os::fd::OwnedFd> {
    kernel_sys::prog_get_fd_by_id(prog_id).with_context(|| format!("open BPF program id {prog_id}"))
}

fn ensure_original_bytecode(insns: &[kernel_sys::bpf_insn]) -> Result<()> {
    if insns.is_empty() {
        bail!("program has no original bytecode (not loaded by fork kernel?)");
    }
    Ok(())
}

fn write_insns(output: Option<&Path>, insns: &[kernel_sys::bpf_insn]) -> Result<()> {
    let bytes = encode_insns(insns);
    let mut out = open_output(output)?;
    out.write_all(&bytes)?;
    out.flush()?;
    Ok(())
}

fn write_json_file<T: Serialize>(output: &Path, value: &T) -> Result<()> {
    let bytes = json_bytes(value)?;
    fs::write(output, bytes).with_context(|| format!("write {}", output.display()))
}

fn open_output(output: Option<&Path>) -> Result<Box<dyn Write>> {
    match output {
        Some(path) => {
            Ok(Box::new(fs::File::create(path).with_context(|| {
                format!("failed to create {}", path.display())
            })?))
        }
        None => Ok(Box::new(io::stdout().lock())),
    }
}

fn ensure_existing_dir(path: &Path) -> Result<()> {
    let metadata =
        fs::metadata(path).with_context(|| format!("failed to stat {}", path.display()))?;
    if !metadata.is_dir() {
        bail!("{} is not a directory", path.display());
    }
    Ok(())
}

fn encode_insns(insns: &[kernel_sys::bpf_insn]) -> Vec<u8> {
    let mut bytes = Vec::with_capacity(std::mem::size_of_val(insns));
    for insn in insns {
        bytes.extend_from_slice(&insn_raw_bytes(insn));
    }
    bytes
}

fn json_bytes<T: Serialize>(value: &T) -> Result<Vec<u8>> {
    let mut bytes = Vec::new();
    serde_json::to_writer_pretty(&mut bytes, value)?;
    bytes.push(b'\n');
    Ok(bytes)
}

fn is_zero_u32(value: &u32) -> bool {
    *value == 0
}

fn is_zero_u64(value: &u64) -> bool {
    *value == 0
}

fn write_full_files_atomic(outdir: &Path, entries: &[(&str, &[u8])]) -> Result<()> {
    let tmp_paths = entries
        .iter()
        .map(|(name, _)| full_tmp_path(outdir, name))
        .collect::<Vec<_>>();

    let result = (|| {
        for ((name, bytes), tmp_path) in entries.iter().zip(&tmp_paths) {
            let mut file = OpenOptions::new()
                .write(true)
                .create_new(true)
                .open(tmp_path)
                .with_context(|| format!("failed to create {}", tmp_path.display()))?;
            file.write_all(bytes)
                .with_context(|| format!("failed to write {}", tmp_path.display()))?;
            file.flush()
                .with_context(|| format!("failed to flush {}", tmp_path.display()))?;
            drop(file);

            let final_path = outdir.join(name);
            if final_path == *tmp_path {
                bail!(
                    "temporary path unexpectedly matches final path {}",
                    final_path.display()
                );
            }
        }

        for ((name, _), tmp_path) in entries.iter().zip(&tmp_paths) {
            let final_path = outdir.join(name);
            fs::rename(tmp_path, &final_path).with_context(|| {
                format!(
                    "failed to rename {} to {}",
                    tmp_path.display(),
                    final_path.display()
                )
            })?;
        }
        Ok(())
    })();

    if let Err(err) = result {
        let mut cleanup_failures = Vec::new();
        for tmp_path in &tmp_paths {
            match fs::remove_file(tmp_path) {
                Ok(()) => {}
                Err(remove_err) if remove_err.kind() == io::ErrorKind::NotFound => {}
                Err(remove_err) => {
                    cleanup_failures.push(format!("{}: {remove_err}", tmp_path.display()));
                }
            }
        }
        if cleanup_failures.is_empty() {
            return Err(err);
        }
        return Err(err.context(format!(
            "also failed to remove temporary file(s): {}",
            cleanup_failures.join(", ")
        )));
    }

    Ok(())
}

fn full_tmp_path(outdir: &Path, name: &str) -> PathBuf {
    let id = NEXT_TMP_ID.fetch_add(1, Ordering::Relaxed);
    outdir.join(format!(".{name}.tmp.{}.{id}", std::process::id()))
}

fn insn_raw_bytes(insn: &kernel_sys::bpf_insn) -> [u8; 8] {
    let mut bytes = [0u8; 8];
    bytes[0] = insn.code;
    bytes[1] = (insn.dst_reg() & 0x0f) | ((insn.src_reg() & 0x0f) << 4);
    bytes[2..4].copy_from_slice(&insn.off.to_le_bytes());
    bytes[4..8].copy_from_slice(&insn.imm.to_le_bytes());
    bytes
}

fn c_name_u8(bytes: &[u8]) -> String {
    let end = bytes.iter().position(|&b| b == 0).unwrap_or(bytes.len());
    String::from_utf8_lossy(&bytes[..end]).to_string()
}

fn c_name_i8(bytes: &[std::os::raw::c_char]) -> String {
    let bytes = bytes.iter().map(|&b| b as u8).collect::<Vec<_>>();
    c_name_u8(&bytes)
}

fn prog_type_name(value: u32) -> &'static str {
    match value {
        v if v == kernel_sys::BPF_PROG_TYPE_UNSPEC => "unspec",
        v if v == kernel_sys::BPF_PROG_TYPE_SOCKET_FILTER => "socket_filter",
        v if v == kernel_sys::BPF_PROG_TYPE_KPROBE => "kprobe",
        v if v == kernel_sys::BPF_PROG_TYPE_SCHED_CLS => "sched_cls",
        v if v == kernel_sys::BPF_PROG_TYPE_SCHED_ACT => "sched_act",
        v if v == kernel_sys::BPF_PROG_TYPE_TRACEPOINT => "tracepoint",
        v if v == kernel_sys::BPF_PROG_TYPE_XDP => "xdp",
        v if v == kernel_sys::BPF_PROG_TYPE_PERF_EVENT => "perf_event",
        v if v == kernel_sys::BPF_PROG_TYPE_CGROUP_SKB => "cgroup_skb",
        v if v == kernel_sys::BPF_PROG_TYPE_CGROUP_SOCK => "cgroup_sock",
        v if v == kernel_sys::BPF_PROG_TYPE_LWT_IN => "lwt_in",
        v if v == kernel_sys::BPF_PROG_TYPE_LWT_OUT => "lwt_out",
        v if v == kernel_sys::BPF_PROG_TYPE_LWT_XMIT => "lwt_xmit",
        v if v == kernel_sys::BPF_PROG_TYPE_SOCK_OPS => "sock_ops",
        v if v == kernel_sys::BPF_PROG_TYPE_SK_SKB => "sk_skb",
        v if v == kernel_sys::BPF_PROG_TYPE_CGROUP_DEVICE => "cgroup_device",
        v if v == kernel_sys::BPF_PROG_TYPE_SK_MSG => "sk_msg",
        v if v == kernel_sys::BPF_PROG_TYPE_RAW_TRACEPOINT => "raw_tracepoint",
        v if v == kernel_sys::BPF_PROG_TYPE_CGROUP_SOCK_ADDR => "cgroup_sock_addr",
        v if v == kernel_sys::BPF_PROG_TYPE_LWT_SEG6LOCAL => "lwt_seg6local",
        v if v == kernel_sys::BPF_PROG_TYPE_LIRC_MODE2 => "lirc_mode2",
        v if v == kernel_sys::BPF_PROG_TYPE_SK_REUSEPORT => "sk_reuseport",
        v if v == kernel_sys::BPF_PROG_TYPE_FLOW_DISSECTOR => "flow_dissector",
        v if v == kernel_sys::BPF_PROG_TYPE_CGROUP_SYSCTL => "cgroup_sysctl",
        v if v == kernel_sys::BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE => "raw_tracepoint_writable",
        v if v == kernel_sys::BPF_PROG_TYPE_CGROUP_SOCKOPT => "cgroup_sockopt",
        v if v == kernel_sys::BPF_PROG_TYPE_TRACING => "tracing",
        v if v == kernel_sys::BPF_PROG_TYPE_STRUCT_OPS => "struct_ops",
        v if v == kernel_sys::BPF_PROG_TYPE_EXT => "ext",
        v if v == kernel_sys::BPF_PROG_TYPE_LSM => "lsm",
        v if v == kernel_sys::BPF_PROG_TYPE_SK_LOOKUP => "sk_lookup",
        v if v == kernel_sys::BPF_PROG_TYPE_SYSCALL => "syscall",
        v if v == kernel_sys::BPF_PROG_TYPE_NETFILTER => "netfilter",
        _ => "unknown",
    }
}

fn attach_type_name(value: u32) -> Option<&'static str> {
    let name = match value {
        v if v == kernel_sys::BPF_CGROUP_INET_INGRESS => "cgroup_inet_ingress",
        v if v == kernel_sys::BPF_CGROUP_INET_EGRESS => "cgroup_inet_egress",
        v if v == kernel_sys::BPF_CGROUP_INET_SOCK_CREATE => "cgroup_inet_sock_create",
        v if v == kernel_sys::BPF_CGROUP_SOCK_OPS => "cgroup_sock_ops",
        v if v == kernel_sys::BPF_SK_SKB_STREAM_PARSER => "sk_skb_stream_parser",
        v if v == kernel_sys::BPF_SK_SKB_STREAM_VERDICT => "sk_skb_stream_verdict",
        v if v == kernel_sys::BPF_CGROUP_DEVICE => "cgroup_device",
        v if v == kernel_sys::BPF_SK_MSG_VERDICT => "sk_msg_verdict",
        v if v == kernel_sys::BPF_CGROUP_INET4_BIND => "cgroup_inet4_bind",
        v if v == kernel_sys::BPF_CGROUP_INET6_BIND => "cgroup_inet6_bind",
        v if v == kernel_sys::BPF_CGROUP_INET4_CONNECT => "cgroup_inet4_connect",
        v if v == kernel_sys::BPF_CGROUP_INET6_CONNECT => "cgroup_inet6_connect",
        v if v == kernel_sys::BPF_CGROUP_INET4_POST_BIND => "cgroup_inet4_post_bind",
        v if v == kernel_sys::BPF_CGROUP_INET6_POST_BIND => "cgroup_inet6_post_bind",
        v if v == kernel_sys::BPF_CGROUP_UDP4_SENDMSG => "cgroup_udp4_sendmsg",
        v if v == kernel_sys::BPF_CGROUP_UDP6_SENDMSG => "cgroup_udp6_sendmsg",
        v if v == kernel_sys::BPF_CGROUP_SYSCTL => "cgroup_sysctl",
        v if v == kernel_sys::BPF_CGROUP_UDP4_RECVMSG => "cgroup_udp4_recvmsg",
        v if v == kernel_sys::BPF_CGROUP_UDP6_RECVMSG => "cgroup_udp6_recvmsg",
        v if v == kernel_sys::BPF_CGROUP_GETSOCKOPT => "cgroup_getsockopt",
        v if v == kernel_sys::BPF_CGROUP_SETSOCKOPT => "cgroup_setsockopt",
        v if v == kernel_sys::BPF_TRACE_RAW_TP => "trace_raw_tp",
        v if v == kernel_sys::BPF_TRACE_FENTRY => "trace_fentry",
        v if v == kernel_sys::BPF_TRACE_FEXIT => "trace_fexit",
        v if v == kernel_sys::BPF_MODIFY_RETURN => "modify_return",
        v if v == kernel_sys::BPF_LSM_MAC => "lsm_mac",
        v if v == kernel_sys::BPF_TRACE_ITER => "trace_iter",
        v if v == kernel_sys::BPF_CGROUP_INET4_GETPEERNAME => "cgroup_inet4_getpeername",
        v if v == kernel_sys::BPF_CGROUP_INET6_GETPEERNAME => "cgroup_inet6_getpeername",
        v if v == kernel_sys::BPF_CGROUP_INET4_GETSOCKNAME => "cgroup_inet4_getsockname",
        v if v == kernel_sys::BPF_CGROUP_INET6_GETSOCKNAME => "cgroup_inet6_getsockname",
        v if v == kernel_sys::BPF_XDP_DEVMAP => "xdp_devmap",
        v if v == kernel_sys::BPF_CGROUP_INET_SOCK_RELEASE => "cgroup_inet_sock_release",
        v if v == kernel_sys::BPF_XDP_CPUMAP => "xdp_cpumap",
        v if v == kernel_sys::BPF_SK_LOOKUP => "sk_lookup",
        v if v == kernel_sys::BPF_XDP => "xdp",
        v if v == kernel_sys::BPF_SK_SKB_VERDICT => "sk_skb_verdict",
        v if v == kernel_sys::BPF_SK_REUSEPORT_SELECT => "sk_reuseport_select",
        v if v == kernel_sys::BPF_SK_REUSEPORT_SELECT_OR_MIGRATE => {
            "sk_reuseport_select_or_migrate"
        }
        v if v == kernel_sys::BPF_TRACE_KPROBE_MULTI => "trace_kprobe_multi",
        v if v == kernel_sys::BPF_LSM_CGROUP => "lsm_cgroup",
        v if v == kernel_sys::BPF_NETFILTER => "netfilter",
        v if v == kernel_sys::BPF_TCX_INGRESS => "tcx_ingress",
        v if v == kernel_sys::BPF_TCX_EGRESS => "tcx_egress",
        v if v == kernel_sys::BPF_TRACE_UPROBE_MULTI => "trace_uprobe_multi",
        v if v == kernel_sys::BPF_CGROUP_UNIX_CONNECT => "cgroup_unix_connect",
        v if v == kernel_sys::BPF_CGROUP_UNIX_SENDMSG => "cgroup_unix_sendmsg",
        v if v == kernel_sys::BPF_CGROUP_UNIX_RECVMSG => "cgroup_unix_recvmsg",
        v if v == kernel_sys::BPF_CGROUP_UNIX_GETPEERNAME => "cgroup_unix_getpeername",
        v if v == kernel_sys::BPF_CGROUP_UNIX_GETSOCKNAME => "cgroup_unix_getsockname",
        v if v == kernel_sys::BPF_NETKIT_PRIMARY => "netkit_primary",
        v if v == kernel_sys::BPF_NETKIT_PEER => "netkit_peer",
        v if v == kernel_sys::BPF_TRACE_KPROBE_SESSION => "trace_kprobe_session",
        v if v == kernel_sys::BPF_TRACE_UPROBE_SESSION => "trace_uprobe_session",
        v if v == kernel_sys::BPF_TRACE_FSESSION => "trace_fsession",
        _ => return None,
    };
    Some(name)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn prog_info_json_schema_round_trips_requested_fields() {
        let info = ProgInfoJson {
            id: 7,
            name: "xdp_prog".to_string(),
            prog_type: TypeJson {
                name: "xdp".to_string(),
                numeric: kernel_sys::BPF_PROG_TYPE_XDP,
            },
            insn_cnt: 12,
            map_ids: vec![10, 11],
            load_time: 123,
            created_by_uid: 1000,
            xlated_prog_len: 96,
            orig_prog_len: 96,
            jited_prog_len: 64,
            btf_id: 0,
            func_info_rec_size: 8,
            nr_func_info: 1,
            line_info_rec_size: 16,
            nr_line_info: 2,
            attach_btf_obj_id: 0,
            attach_btf_id: 0,
            expected_attach_type: Some(TypeJson {
                name: "xdp".to_string(),
                numeric: kernel_sys::BPF_XDP,
            }),
        };

        let text = serde_json::to_string(&info).expect("serialize prog info");
        let round_trip: ProgInfoJson = serde_json::from_str(&text).expect("deserialize prog info");

        assert_eq!(round_trip, info);
        let value: serde_json::Value = serde_json::from_str(&text).expect("json value");
        assert!(value.get("id").is_some());
        assert!(value.get("type").is_some());
        assert_eq!(value["type"]["name"], "xdp");
        assert_eq!(value["type"]["numeric"], kernel_sys::BPF_PROG_TYPE_XDP);
        assert!(value.get("map_ids").is_some());
        assert!(value.get("orig_prog_len").is_some());
        assert_eq!(value["func_info_rec_size"], 8);
        assert_eq!(value["nr_func_info"], 1);
        assert_eq!(value["line_info_rec_size"], 16);
        assert_eq!(value["nr_line_info"], 2);
        assert_eq!(value["expected_attach_type"]["name"], "xdp");
        assert_eq!(
            value["expected_attach_type"]["numeric"],
            kernel_sys::BPF_XDP
        );
    }

    #[test]
    fn map_info_json_schema_preserves_old_fd_binding() {
        let info = MapInfoJson {
            old_fd: Some(42),
            map_id: 77,
            map_type: 1,
            key_size: 4,
            value_size: 8,
            max_entries: 16,
            name: "events".to_string(),
            map_flags: 8,
            ifindex: 0,
            btf_id: 0,
            btf_key_type_id: 0,
            btf_value_type_id: 0,
            btf_vmlinux_value_type_id: 0,
            btf_vmlinux_id: 0,
            map_extra: 0,
        };

        let text = serde_json::to_string(&info).expect("serialize map info");
        let round_trip: MapInfoJson = serde_json::from_str(&text).expect("deserialize map info");

        assert_eq!(round_trip, info);
        let value: serde_json::Value = serde_json::from_str(&text).expect("json value");
        assert_eq!(value["old_fd"], 42);
        assert_eq!(value["map_id"], 77);
        assert_eq!(value["map_flags"], 8);
    }

    #[test]
    fn pseudo_map_old_fds_preserves_unique_load_order() {
        let insns = [
            ldimm64(BPF_PSEUDO_MAP_FD, 11),
            ldimm64(BPF_PSEUDO_MAP_VALUE, 22),
            ldimm64(BPF_PSEUDO_MAP_FD, 11),
        ]
        .concat();

        assert_eq!(pseudo_map_old_fds(&insns), vec![11, 22]);
    }

    #[test]
    fn required_load_metadata_rejects_missing_tracing_attach_context() {
        let mut info = prog_info_for_type(kernel_sys::BPF_PROG_TYPE_TRACING);
        info.btf_id = 10;
        info.attach_btf_id = 20;

        let err = validate_required_load_metadata(&info).unwrap_err();

        assert!(
            err.to_string().contains("expected_attach_type"),
            "err={err:#}"
        );
    }

    #[test]
    fn required_load_metadata_rejects_missing_kprobe_prog_btf() {
        let info = prog_info_for_type(kernel_sys::BPF_PROG_TYPE_KPROBE);

        let err = validate_required_load_metadata(&info).unwrap_err();

        assert!(err.to_string().contains("btf_id"), "err={err:#}");
    }

    fn prog_info_for_type(prog_type: kernel_sys::bpf_prog_type) -> ProgInfoJson {
        ProgInfoJson {
            id: 7,
            name: "prog".to_string(),
            prog_type: TypeJson {
                name: prog_type_name(prog_type).to_string(),
                numeric: prog_type,
            },
            insn_cnt: 2,
            map_ids: Vec::new(),
            load_time: 0,
            created_by_uid: 0,
            xlated_prog_len: 16,
            orig_prog_len: 16,
            jited_prog_len: 16,
            btf_id: 0,
            func_info_rec_size: 0,
            nr_func_info: 0,
            line_info_rec_size: 0,
            nr_line_info: 0,
            attach_btf_obj_id: 0,
            attach_btf_id: 0,
            expected_attach_type: None,
        }
    }

    fn ldimm64(src_reg: u8, imm: i32) -> [kernel_sys::bpf_insn; 2] {
        let mut first = kernel_sys::bpf_insn {
            code: BPF_LD_IMM64,
            _bitfield_align_1: [],
            _bitfield_1: Default::default(),
            off: 0,
            imm,
        };
        first.set_src_reg(src_reg);
        let second = kernel_sys::bpf_insn {
            code: 0,
            _bitfield_align_1: [],
            _bitfield_1: Default::default(),
            off: 0,
            imm: 0,
        };
        [first, second]
    }

    #[test]
    fn target_kinsn_specs_reject_missing_btf_func_id() {
        let err = parse_kinsns(&["bpf_rotate64".to_string()]).unwrap_err();
        assert!(
            err.to_string().contains("expected name:btf_func_id"),
            "err={err:#}"
        );
    }
}
