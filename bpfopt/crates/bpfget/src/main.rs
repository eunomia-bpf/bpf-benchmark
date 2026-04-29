// SPDX-License-Identifier: MIT
//! bpfget CLI entry point.

use std::collections::BTreeMap;
use std::fs;
use std::io::{self, Write};
use std::os::fd::{AsFd, AsRawFd, BorrowedFd};
use std::path::{Path, PathBuf};
use std::process::ExitCode;

use anyhow::{anyhow, bail, Context, Result};
use clap::Parser;
use serde::{Deserialize, Serialize};

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
    /// Use JSON output for --list.
    #[arg(long)]
    json: bool,
    /// Write target.json for the host platform.
    #[arg(long)]
    target: bool,
    /// Output file. Defaults to stdout.
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
    attach_btf_id: u32,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
struct MapInfoJson {
    map_id: u32,
    map_type: u32,
    key_size: u32,
    value_size: u32,
    max_entries: u32,
    name: String,
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
}

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
        return list_programs(cli.json, cli.output.as_deref());
    }
    if cli.target {
        return write_target_json(cli.output.as_deref(), &cli.kinsns);
    }

    let prog_id = cli.prog_id.expect("validated PROG_ID");
    if cli.info {
        let (info, map_ids) = get_prog_info_with_map_ids(prog_id)?;
        return write_json(
            cli.output.as_deref(),
            &ProgInfoJson::from_info(info, map_ids),
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
    fn from_info(info: kernel_sys::BpfProgInfoFork, map_ids: Vec<u32>) -> Self {
        let insn_size = std::mem::size_of::<kernel_sys::bpf_insn>() as u32;
        let insn_bytes = if info.orig_prog_len != 0 {
            info.orig_prog_len
        } else {
            info.xlated_prog_len
        };

        Self {
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
            attach_btf_id: info.attach_btf_id,
        }
    }
}

fn write_full(prog_id: u32, outdir: &Path) -> Result<()> {
    fs::create_dir_all(outdir).with_context(|| format!("failed to create {}", outdir.display()))?;

    let fd = open_prog_fd(prog_id)?;
    let insns = kernel_sys::prog_get_original(fd.as_fd())
        .with_context(|| format!("read original bytecode for BPF program id {prog_id}"))?;
    ensure_original_bytecode(&insns)?;
    let (info, map_ids) = get_prog_info_with_map_ids_from_fd(fd.as_fd(), prog_id)?;

    write_insns(Some(&outdir.join("prog.bin")), &insns)?;
    write_json(
        Some(&outdir.join("prog_info.json")),
        &ProgInfoJson::from_info(info, map_ids.clone()),
    )?;
    write_json(
        Some(&outdir.join("map_fds.json")),
        &get_map_infos(&map_ids)?,
    )?;
    Ok(())
}

fn list_programs(json: bool, output: Option<&Path>) -> Result<()> {
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

    if json {
        write_json(output, &rows)
    } else {
        let mut out = open_output(output)?;
        for row in rows {
            writeln!(out, "{} {} {}", row.id, row.name, row.prog_type.name)?;
        }
        out.flush()?;
        Ok(())
    }
}

fn write_target_json(output: Option<&Path>, kinsn_specs: &[String]) -> Result<()> {
    let target = TargetJson {
        arch: detect_arch(),
        features: detect_features(),
        kinsns: parse_kinsns(kinsn_specs)?,
    };
    if target.kinsns.is_empty() {
        eprintln!(
            "warning: kinsn BTF probing is not implemented yet; target.json uses empty kinsns"
        );
    }
    write_json(output, &target)
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
            .insert(name.to_string(), TargetKinsnJson { btf_func_id })
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
    if nr_map_ids == 0 {
        return Ok(Vec::new());
    }

    let mut map_ids = vec![0u32; nr_map_ids as usize];
    let mut info = kernel_sys::BpfProgInfoFork {
        nr_map_ids,
        map_ids: map_ids.as_mut_ptr() as u64,
        ..Default::default()
    };
    let mut info_len = std::mem::size_of::<kernel_sys::BpfProgInfoFork>() as u32;
    let ret = unsafe {
        kernel_sys::libbpf_sys::bpf_obj_get_info_by_fd(
            fd.as_raw_fd(),
            &mut info as *mut _ as *mut std::ffi::c_void,
            &mut info_len,
        )
    };
    if ret < 0 {
        bail!("BPF_OBJ_GET_INFO_BY_FD (map ids): {}", libbpf_os_error(ret));
    }
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

fn get_map_infos(map_ids: &[u32]) -> Result<Vec<MapInfoJson>> {
    let mut maps = Vec::with_capacity(map_ids.len());
    for &map_id in map_ids {
        let fd = kernel_sys::map_get_fd_by_id(map_id)
            .with_context(|| format!("open BPF map id {map_id}"))?;
        let info = kernel_sys::map_obj_get_info_by_fd(fd.as_fd())
            .with_context(|| format!("read info for BPF map id {map_id}"))?;
        maps.push(MapInfoJson {
            map_id,
            map_type: info.type_,
            key_size: info.key_size,
            value_size: info.value_size,
            max_entries: info.max_entries,
            name: c_name_i8(&info.name),
        });
    }
    Ok(maps)
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
    let mut out = open_output(output)?;
    for insn in insns {
        out.write_all(&insn_raw_bytes(insn))?;
    }
    out.flush()?;
    Ok(())
}

fn write_json<T: Serialize>(output: Option<&Path>, value: &T) -> Result<()> {
    let mut out = open_output(output)?;
    serde_json::to_writer_pretty(&mut out, value)?;
    writeln!(out)?;
    out.flush()?;
    Ok(())
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

fn libbpf_os_error(ret: i32) -> std::io::Error {
    let errno = if ret < 0 {
        -ret
    } else {
        std::io::Error::last_os_error().raw_os_error().unwrap_or(5)
    };
    std::io::Error::from_raw_os_error(errno)
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
            attach_btf_id: 0,
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
