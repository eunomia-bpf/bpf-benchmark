// SPDX-License-Identifier: MIT
//! Host-side developer loader for bpfopt.
//!
//! Single-flow CLI:
//!   1. libbpf-load a .bpf.o and capture the verifier log (level=2)
//!   2. dump map snapshots + metadata to a workdir
//!   3. invoke `bpfopt --canonicalize-map-refs`
//!   4. if `--pass` given: execute the daemon's per-pass yaml command
//!      (`runner/config/passes/<pass>/default.yaml`) and verify the output
//!      with a fresh BPF_PROG_LOAD
//!
//! `--workdir` is optional; if omitted the loader creates a tmp directory
//! and removes it on exit.

use std::collections::{BTreeMap, BTreeSet};
use std::ffi::{CStr, CString};
use std::fs;
use std::io::{self, Write};
use std::mem::{self, MaybeUninit};
use std::os::fd::{AsRawFd, FromRawFd, OwnedFd};
use std::os::raw::{c_char, c_void};
use std::path::{Path, PathBuf};
use std::process::{Command, ExitCode};
use std::{ptr, slice};

use anyhow::{anyhow, bail, Context, Result};
use clap::Parser;
use serde::{Deserialize, Serialize};

const DEFAULT_LOG_BYTES: usize = 16 * 1024 * 1024;
const INPUT_BIN: &str = "input.bin";
const CANONICALIZE_INPUT_BIN: &str = "canonicalize_input.bin";
const OUTPUT_BIN: &str = "output.bin";
const REPORT_JSON: &str = "report.json";
const MAP_IDS_JSON: &str = "map-ids.json";
const MAP_VALUES_DIR: &str = "map-values";
const METADATA_JSON: &str = "metadata.json";
const VERIFIER_LOG: &str = "verifier.log";
const VERIFY_LOG: &str = "verify.log";
const BPF_PSEUDO_MAP_IDX: u8 = 5;
const BPF_PSEUDO_MAP_IDX_VALUE: u8 = 6;

#[derive(Parser)]
#[command(
    name = "bpfopt-loader",
    version,
    about = "Host-side bpfopt fixture loader"
)]
struct Cli {
    /// BPF object file to open through libbpf.
    #[arg(long, value_name = "FILE")]
    obj: PathBuf,
    /// Program name or ELF section to select.
    #[arg(long, value_name = "NAME_OR_SECTION")]
    prog: String,
    /// Pass to run via daemon-style yaml (omit to only prepare the workdir).
    #[arg(long, value_name = "NAME")]
    pass: Option<String>,
    /// Optional bpfopt target JSON passed to the pass yaml.
    #[arg(long, value_name = "FILE")]
    target: Option<PathBuf>,
    /// Output workdir. If omitted, a tmp directory is created and removed on exit.
    #[arg(long, value_name = "DIR")]
    workdir: Option<PathBuf>,
    /// bpfopt binary. Defaults to BPFOPT, target sibling, then PATH.
    #[arg(long, value_name = "FILE")]
    bpfopt: Option<PathBuf>,
    /// Directory holding per-pass yaml configs (default: bpfopt/../runner/config/passes).
    #[arg(long, value_name = "DIR")]
    pass_config_dir: Option<PathBuf>,
    /// Per-program verifier log buffer size.
    #[arg(long, default_value_t = DEFAULT_LOG_BYTES)]
    log_bytes: usize,
}

/// RAII workdir: user-provided paths are kept; auto-created tmp dirs are removed on drop.
struct WorkDir {
    path: PathBuf,
    cleanup: bool,
}

impl WorkDir {
    fn open(user_provided: Option<PathBuf>) -> Result<Self> {
        match user_provided {
            Some(path) => {
                fs::create_dir_all(&path)
                    .with_context(|| format!("failed to create {}", path.display()))?;
                Ok(Self {
                    path,
                    cleanup: false,
                })
            }
            None => {
                let path = std::env::temp_dir().join(format!(
                    "bpfopt-loader-{}-{}",
                    std::process::id(),
                    unique_id()
                ));
                fs::create_dir_all(&path)
                    .with_context(|| format!("failed to create {}", path.display()))?;
                Ok(Self {
                    path,
                    cleanup: true,
                })
            }
        }
    }
}

impl Drop for WorkDir {
    fn drop(&mut self) {
        if self.cleanup {
            let _ = fs::remove_dir_all(&self.path);
        }
    }
}

fn unique_id() -> u64 {
    use std::time::{SystemTime, UNIX_EPOCH};
    SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .map(|d| d.as_nanos() as u64)
        .unwrap_or(0)
}

#[derive(Debug, Deserialize)]
struct PassYaml {
    command: String,
}

#[derive(Debug, Serialize, Deserialize)]
struct WorkdirMetadata {
    object: Option<String>,
    program: ProgramMetadata,
}

#[derive(Debug, Serialize, Deserialize)]
struct ProgramMetadata {
    name: String,
    section: String,
    prog_type: u32,
    #[serde(default, skip_serializing_if = "is_zero")]
    expected_attach_type: u32,
    #[serde(default, skip_serializing_if = "is_zero")]
    attach_btf_id: u32,
}

#[derive(Debug, Serialize, Deserialize)]
struct MapIdsJson {
    map_ids: Vec<u32>,
}

#[derive(Debug, Serialize, Deserialize)]
struct MapShowJson {
    id: u32,
    name: String,
    #[serde(rename = "type")]
    type_: u32,
    bytes_key: u32,
    bytes_value: u32,
    max_entries: u32,
    #[serde(default, skip_serializing_if = "is_zero")]
    map_flags: u32,
}

#[derive(Debug, Serialize)]
struct MapDumpEntryJson {
    key: Vec<String>,
    #[serde(skip_serializing_if = "Option::is_none")]
    value: Option<Vec<String>>,
    #[serde(default, skip_serializing_if = "Vec::is_empty")]
    values: Vec<PerCpuValueJson>,
}

#[derive(Debug, Serialize)]
struct PerCpuValueJson {
    value: Vec<String>,
}

struct BpfObject {
    ptr: *mut libbpf_sys::bpf_object,
}

impl Drop for BpfObject {
    fn drop(&mut self) {
        unsafe {
            libbpf_sys::bpf_object__close(self.ptr);
        }
    }
}

struct ProgramRef {
    ptr: *mut libbpf_sys::bpf_program,
    name: String,
    section: String,
}

struct MapRef {
    fd: i32,
    info: libbpf_sys::bpf_map_info,
}

fn main() -> ExitCode {
    match run(Cli::parse()) {
        Ok(()) => ExitCode::SUCCESS,
        Err(err) => {
            eprintln!("error: {err:#}");
            ExitCode::from(1)
        }
    }
}

fn run(cli: Cli) -> Result<()> {
    if cli.log_bytes == 0 {
        bail!("--log-bytes must be non-zero");
    }
    let workdir = WorkDir::open(cli.workdir.clone())?;
    let map_ids = prepare_workdir(&workdir.path, &cli.obj, &cli.prog, cli.log_bytes)?;
    canonicalize_input(&workdir.path, cli.bpfopt.as_deref(), &map_ids)?;
    if let Some(pass) = cli.pass.as_deref() {
        run_pass_via_yaml(&workdir.path, pass, &cli, &map_ids)?;
        verify_workdir(&workdir.path, cli.log_bytes)?;
    }
    Ok(())
}

/// libbpf-load the program at `obj`/`prog` and dump bytecode, verifier log,
/// metadata, and map snapshots into `workdir`. Returns the bytecode map id list.
fn prepare_workdir(
    workdir: &Path,
    obj_path: &Path,
    prog_selector: &str,
    log_bytes: usize,
) -> Result<Vec<u32>> {
    let map_values_dir = workdir.join(MAP_VALUES_DIR);
    fs::create_dir_all(&map_values_dir)
        .with_context(|| format!("failed to create {}", map_values_dir.display()))?;

    let obj = open_bpf_object(obj_path)?;
    let selected = select_program(&obj, prog_selector)?;
    set_autoload_only(&obj, selected.ptr)?;

    let mut log_buf = vec![0 as c_char; log_bytes];
    set_program_log(selected.ptr, 2, &mut log_buf)?;

    let ret = unsafe { libbpf_sys::bpf_object__load(obj.ptr) };
    if ret < 0 {
        let log = log_buf_to_string(&log_buf);
        fs::write(workdir.join(VERIFIER_LOG), &log)
            .with_context(|| format!("failed to write {}", workdir.join(VERIFIER_LOG).display()))?;
        bail!(
            "libbpf failed to load {}: {}",
            obj_path.display(),
            neg_errno(ret)
        );
    }

    let prog_fd = program_fd(selected.ptr)?;
    let prog_info = program_info(prog_fd)?;
    let loaded_maps = maps(&obj)?;
    let insns = program_insns(selected.ptr)?;
    let map_ids = bytecode_map_ids(&insns, &loaded_maps)?;
    validate_kernel_map_ids(&map_ids, &program_map_ids(prog_fd)?)?;
    write_json(
        &workdir.join(MAP_IDS_JSON),
        &MapIdsJson {
            map_ids: map_ids.clone(),
        },
    )?;
    write_insns(&workdir.join(CANONICALIZE_INPUT_BIN), &insns)?;
    dump_map_snapshots(&loaded_maps, &map_ids, &map_values_dir)?;

    let verifier_log = log_buf_to_string(&log_buf);
    if verifier_log.trim().is_empty() {
        bail!("host verifier produced an empty log for {}", selected.name);
    }
    fs::write(workdir.join(VERIFIER_LOG), verifier_log)
        .with_context(|| format!("failed to write {}", workdir.join(VERIFIER_LOG).display()))?;

    let metadata = WorkdirMetadata {
        object: Some(obj_path.display().to_string()),
        program: ProgramMetadata {
            name: selected.name,
            section: selected.section,
            prog_type: program_type(selected.ptr)?,
            expected_attach_type: expected_attach_type(selected.ptr),
            attach_btf_id: prog_info.attach_btf_id,
        },
    };
    write_json(&workdir.join(METADATA_JSON), &metadata)?;
    Ok(map_ids)
}

/// Read `<pass_config_dir>/<pass>/default.yaml`, substitute `${VAR}` tokens
/// using workdir paths and metadata, and execute the command via `sh -c`.
fn run_pass_via_yaml(workdir: &Path, pass: &str, cli: &Cli, map_ids: &[u32]) -> Result<()> {
    let config_dir = resolve_pass_config_dir(cli.pass_config_dir.as_deref())?;
    let yaml_path = config_dir.join(pass).join("default.yaml");
    let yaml_bytes =
        fs::read(&yaml_path).with_context(|| format!("failed to read {}", yaml_path.display()))?;
    let yaml: PassYaml = serde_yaml::from_slice(&yaml_bytes)
        .with_context(|| format!("failed to parse {}", yaml_path.display()))?;

    let metadata = read_json::<WorkdirMetadata>(&workdir.join(METADATA_JSON))?;
    let bpfopt = resolve_bpfopt(cli.bpfopt.as_deref());
    let map_ids_arg = if map_ids.is_empty() {
        String::from("0")
    } else {
        join_u32_csv(map_ids)
    };
    let target_arg = cli
        .target
        .as_deref()
        .map(|p| p.display().to_string())
        .unwrap_or_default();

    let mut vars = BTreeMap::<&str, String>::new();
    vars.insert("INPUT", workdir.join(INPUT_BIN).display().to_string());
    vars.insert("OUTPUT", workdir.join(OUTPUT_BIN).display().to_string());
    vars.insert("REPORT", workdir.join(REPORT_JSON).display().to_string());
    vars.insert("PROG_TYPE", metadata.program.prog_type.to_string());
    vars.insert(
        "VERIFIER_STATES",
        workdir.join(VERIFIER_LOG).display().to_string(),
    );
    vars.insert("TARGET", target_arg);
    vars.insert(
        "MAP_VALUES",
        workdir.join(MAP_VALUES_DIR).display().to_string(),
    );
    vars.insert("MAP_IDS", map_ids_arg);
    vars.insert("BPFOPT", bpfopt.display().to_string());

    let expanded = substitute_vars(&yaml.command, &vars);
    // The yaml command invokes `bpfopt ...` (and may wrap with `timeout`). We
    // expose `BPFOPT` so a `--bpfopt` override can be honored via env in callers
    // that templated `${BPFOPT}`; in-tree yamls just say `bpfopt` and we rely on
    // PATH augmentation below.
    let status = Command::new("sh")
        .arg("-c")
        .arg(&expanded)
        .env("PATH", augmented_path_for_bpfopt(&bpfopt))
        .status()
        .with_context(|| format!("failed to run yaml command for {pass}"))?;
    if !status.success() {
        bail!("pass {pass} exited with {status}");
    }
    Ok(())
}

/// Reload the produced bytecode via BPF_PROG_LOAD as a sanity check.
fn verify_workdir(workdir: &Path, log_bytes: usize) -> Result<()> {
    let metadata = read_json::<WorkdirMetadata>(&workdir.join(METADATA_JSON))?;
    let map_ids = read_json::<MapIdsJson>(&workdir.join(MAP_IDS_JSON))?.map_ids;
    let input = workdir.join(OUTPUT_BIN);
    let map_fds = create_verify_maps(&workdir.join(MAP_VALUES_DIR), &map_ids)?;
    let fd_nums = map_fds.iter().map(|fd| fd.as_raw_fd()).collect::<Vec<_>>();
    let mut insns = read_insns(&input)?;
    rewrite_map_indices_to_fds(&mut insns, &fd_nums)?;

    let name = CString::new(metadata.program.name.as_str()).context("program name has NUL byte")?;
    let license = CString::new("GPL").unwrap();
    let mut log_buf = vec![0 as c_char; log_bytes];
    let mut opts = libbpf_sys::bpf_prog_load_opts {
        sz: mem::size_of::<libbpf_sys::bpf_prog_load_opts>() as libbpf_sys::size_t,
        log_level: 1,
        log_size: u32::try_from(log_buf.len()).context("verifier log buffer exceeds u32")?,
        log_buf: log_buf.as_mut_ptr(),
        expected_attach_type: metadata.program.expected_attach_type,
        attach_btf_id: metadata.program.attach_btf_id,
        ..Default::default()
    };
    let fd = unsafe {
        libbpf_sys::bpf_prog_load(
            metadata.program.prog_type,
            name.as_ptr(),
            license.as_ptr(),
            insns.as_ptr(),
            insns.len() as libbpf_sys::size_t,
            &mut opts,
        )
    };
    let log = log_buf_to_string(&log_buf);
    fs::write(workdir.join(VERIFY_LOG), &log)
        .with_context(|| format!("failed to write {}", workdir.join(VERIFY_LOG).display()))?;
    if fd < 0 {
        bail!(
            "BPF_PROG_LOAD rejected {}: {}; verifier log: {}",
            input.display(),
            io::Error::last_os_error(),
            log.trim()
        );
    }
    drop(unsafe { OwnedFd::from_raw_fd(fd) });
    Ok(())
}

fn substitute_vars(template: &str, vars: &BTreeMap<&str, String>) -> String {
    let mut out = String::with_capacity(template.len());
    let mut rest = template;
    while let Some(start) = rest.find("${") {
        out.push_str(&rest[..start]);
        let after = &rest[start + 2..];
        let Some(end) = after.find('}') else {
            out.push_str(&rest[start..]);
            return out;
        };
        let name = &after[..end];
        if let Some(value) = vars.get(name) {
            out.push_str(value);
        } else {
            // unknown vars are left verbatim so failures surface in the shell
            out.push_str("${");
            out.push_str(name);
            out.push('}');
        }
        rest = &after[end + 1..];
    }
    out.push_str(rest);
    out
}

/// Prepend the directory containing the chosen `bpfopt` binary to `PATH` so
/// the yaml's bare `bpfopt` invocation resolves to it.
fn augmented_path_for_bpfopt(bpfopt: &Path) -> std::ffi::OsString {
    let mut path = std::env::var_os("PATH").unwrap_or_default();
    if let Some(dir) = bpfopt.parent().filter(|d| !d.as_os_str().is_empty()) {
        let mut prefix = std::ffi::OsString::from(dir);
        if !path.is_empty() {
            prefix.push(":");
            prefix.push(&path);
        }
        path = prefix;
    }
    path
}

fn resolve_pass_config_dir(explicit: Option<&Path>) -> Result<PathBuf> {
    if let Some(path) = explicit {
        return Ok(path.to_path_buf());
    }
    if let Ok(env_path) = std::env::var("BPFOPT_PASS_CONFIG_DIR") {
        return Ok(PathBuf::from(env_path));
    }
    // Best-effort default relative to the current executable: ../../runner/config/passes
    if let Ok(exe) = std::env::current_exe() {
        for parent in exe.ancestors() {
            let candidate = parent.join("runner/config/passes");
            if candidate.exists() {
                return Ok(candidate);
            }
        }
    }
    Ok(PathBuf::from("runner/config/passes"))
}

fn open_bpf_object(path: &Path) -> Result<BpfObject> {
    let c_path = path_to_cstring(path)?;
    let opts = libbpf_sys::bpf_object_open_opts {
        sz: mem::size_of::<libbpf_sys::bpf_object_open_opts>() as libbpf_sys::size_t,
        ..Default::default()
    };
    let ptr = unsafe { libbpf_sys::bpf_object__open_file(c_path.as_ptr(), &opts) };
    if ptr.is_null() {
        bail!(
            "failed to open {}: {}",
            path.display(),
            io::Error::last_os_error()
        );
    }
    let err = unsafe { libbpf_sys::libbpf_get_error(ptr.cast::<c_void>()) };
    if err != 0 {
        bail!(
            "failed to open {}: {}",
            path.display(),
            neg_errno(err as i32)
        );
    }
    Ok(BpfObject { ptr })
}

fn select_program(obj: &BpfObject, selector: &str) -> Result<ProgramRef> {
    let matches = programs(obj)?
        .into_iter()
        .filter(|prog| prog.name == selector || prog.section == selector)
        .collect::<Vec<_>>();
    match matches.len() {
        0 => bail!("program {selector:?} not found in object"),
        1 => Ok(matches.into_iter().next().unwrap()),
        _ => bail!("program selector {selector:?} is ambiguous"),
    }
}

fn programs(obj: &BpfObject) -> Result<Vec<ProgramRef>> {
    let mut out = Vec::new();
    let mut prev = ptr::null_mut();
    loop {
        let prog = unsafe { libbpf_sys::bpf_object__next_program(obj.ptr, prev) };
        if prog.is_null() {
            break;
        }
        out.push(ProgramRef {
            ptr: prog,
            name: c_string(unsafe { libbpf_sys::bpf_program__name(prog) })?,
            section: c_string(unsafe { libbpf_sys::bpf_program__section_name(prog) })?,
        });
        prev = prog;
    }
    if out.is_empty() {
        bail!("object has no BPF programs");
    }
    Ok(out)
}

fn maps(obj: &BpfObject) -> Result<Vec<MapRef>> {
    let mut out = Vec::new();
    let mut prev = ptr::null_mut();
    loop {
        let map = unsafe { libbpf_sys::bpf_object__next_map(obj.ptr, prev) };
        if map.is_null() {
            break;
        }
        let fd = unsafe { libbpf_sys::bpf_map__fd(map) };
        if fd >= 0 {
            let info = map_info(fd)?;
            out.push(MapRef { fd, info });
        }
        prev = map;
    }
    Ok(out)
}

fn set_autoload_only(obj: &BpfObject, selected: *mut libbpf_sys::bpf_program) -> Result<()> {
    for prog in programs(obj)? {
        libbpf_ok(
            unsafe { libbpf_sys::bpf_program__set_autoload(prog.ptr, prog.ptr == selected) },
            "failed to set program autoload",
        )?;
        unsafe {
            libbpf_sys::bpf_program__set_autoattach(prog.ptr, false);
        }
    }
    Ok(())
}

fn set_program_log(
    prog: *mut libbpf_sys::bpf_program,
    level: u32,
    buf: &mut [c_char],
) -> Result<()> {
    libbpf_ok(
        unsafe { libbpf_sys::bpf_program__set_log_level(prog, level) },
        "failed to set verifier log level",
    )?;
    libbpf_ok(
        unsafe {
            libbpf_sys::bpf_program__set_log_buf(
                prog,
                buf.as_mut_ptr(),
                buf.len() as libbpf_sys::size_t,
            )
        },
        "failed to set verifier log buffer",
    )
}

fn program_fd(prog: *mut libbpf_sys::bpf_program) -> Result<i32> {
    let fd = unsafe { libbpf_sys::bpf_program__fd(prog) };
    if fd < 0 {
        bail!("selected program has no loaded fd");
    }
    Ok(fd)
}

fn program_type(prog: *mut libbpf_sys::bpf_program) -> Result<u32> {
    Ok(unsafe { libbpf_sys::bpf_program__type(prog) })
}

fn expected_attach_type(prog: *mut libbpf_sys::bpf_program) -> u32 {
    unsafe { libbpf_sys::bpf_program__expected_attach_type(prog) }
}

fn program_insns(prog: *mut libbpf_sys::bpf_program) -> Result<Vec<libbpf_sys::bpf_insn>> {
    let cnt = unsafe { libbpf_sys::bpf_program__insn_cnt(prog) };
    let ptr = unsafe { libbpf_sys::bpf_program__insns(prog) };
    if ptr.is_null() && cnt != 0 {
        bail!("selected program has null instruction pointer");
    }
    Ok(unsafe { slice::from_raw_parts(ptr, cnt as usize) }.to_vec())
}

fn program_map_ids(fd: i32) -> Result<Vec<u32>> {
    let info = program_info(fd)?;
    if info.nr_map_ids == 0 {
        return Ok(Vec::new());
    }
    let mut map_ids = vec![0u32; info.nr_map_ids as usize];
    let mut map_info = libbpf_sys::bpf_prog_info {
        nr_map_ids: map_ids.len() as u32,
        map_ids: map_ids.as_mut_ptr() as u64,
        ..Default::default()
    };
    let mut len = mem::size_of::<libbpf_sys::bpf_prog_info>() as u32;
    syscall_ok(
        unsafe {
            libbpf_sys::bpf_obj_get_info_by_fd(
                fd,
                (&mut map_info as *mut _) as *mut c_void,
                &mut len,
            )
        },
        "failed to read bpf_prog_info map ids",
    )?;
    map_ids.truncate(map_info.nr_map_ids as usize);
    Ok(map_ids)
}

fn program_info(fd: i32) -> Result<libbpf_sys::bpf_prog_info> {
    let mut info = libbpf_sys::bpf_prog_info::default();
    let mut len = mem::size_of::<libbpf_sys::bpf_prog_info>() as u32;
    syscall_ok(
        unsafe {
            libbpf_sys::bpf_obj_get_info_by_fd(fd, (&mut info as *mut _) as *mut c_void, &mut len)
        },
        "failed to read bpf_prog_info",
    )?;
    Ok(info)
}

fn map_info(fd: i32) -> Result<libbpf_sys::bpf_map_info> {
    let mut info = libbpf_sys::bpf_map_info::default();
    let mut len = mem::size_of::<libbpf_sys::bpf_map_info>() as u32;
    syscall_ok(
        unsafe {
            libbpf_sys::bpf_obj_get_info_by_fd(fd, (&mut info as *mut _) as *mut c_void, &mut len)
        },
        "failed to read bpf_map_info",
    )?;
    Ok(info)
}

fn dump_map_snapshots(loaded_maps: &[MapRef], map_ids: &[u32], dir: &Path) -> Result<()> {
    let unique_ids = map_ids.iter().copied().collect::<BTreeSet<_>>();
    for map_id in unique_ids {
        let map = loaded_maps
            .iter()
            .find(|map| map.info.id == map_id)
            .ok_or_else(|| {
                anyhow!("program uses map id {map_id}, but loaded object has no matching map")
            })?;
        let show = MapShowJson {
            id: map.info.id,
            name: c_name(&map.info.name)?,
            type_: map.info.type_,
            bytes_key: map.info.key_size,
            bytes_value: map.info.value_size,
            max_entries: map.info.max_entries,
            map_flags: map.info.map_flags,
        };
        write_json(&dir.join(format!("map-{map_id}.show.json")), &show)?;
        if needs_map_dump(map.info.type_) {
            dump_map_entries(map, &dir.join(format!("map-{map_id}.dump.json")))?;
        }
    }
    Ok(())
}

fn bytecode_map_ids(insns: &[libbpf_sys::bpf_insn], loaded_maps: &[MapRef]) -> Result<Vec<u32>> {
    let mut map_ids = Vec::new();
    let mut seen_fds = BTreeSet::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = &insns[pc];
        if is_ldimm64(insn) {
            if matches!(
                insn.src_reg(),
                x if x == libbpf_sys::BPF_PSEUDO_MAP_FD as u8
                    || x == libbpf_sys::BPF_PSEUDO_MAP_VALUE as u8
            ) && seen_fds.insert(insn.imm)
            {
                let map = loaded_maps
                    .iter()
                    .find(|map| map.fd == insn.imm)
                    .ok_or_else(|| {
                        anyhow!("bytecode references loader map fd {} at pc {pc}", insn.imm)
                    })?;
                map_ids.push(map.info.id);
            }
            pc += 2;
        } else {
            pc += 1;
        }
    }
    Ok(map_ids)
}

fn validate_kernel_map_ids(bytecode_map_ids: &[u32], kernel_map_ids: &[u32]) -> Result<()> {
    let kernel_set = kernel_map_ids.iter().copied().collect::<BTreeSet<_>>();
    let missing = bytecode_map_ids
        .iter()
        .copied()
        .filter(|map_id| !kernel_set.contains(map_id))
        .collect::<Vec<_>>();
    if !missing.is_empty() {
        bail!(
            "bytecode map refs {:?} are missing from kernel used_maps {:?}",
            missing,
            kernel_map_ids
        );
    }
    Ok(())
}

fn dump_map_entries(map: &MapRef, path: &Path) -> Result<()> {
    if matches!(
        map.info.type_,
        libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS | libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS
    ) {
        bail!("map-in-map snapshots are not implemented in bpfopt-loader");
    }
    let mut entries = Vec::new();
    for key in map_keys(map.fd, map.info.key_size as usize)? {
        if map.info.type_ == libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY {
            let values = lookup_percpu_values(map, &key)?;
            entries.push(MapDumpEntryJson {
                key: hex_byte_array(&key),
                value: None,
                values,
            });
        } else {
            let value = lookup_value(map.fd, &key, map.info.value_size as usize)?;
            entries.push(MapDumpEntryJson {
                key: hex_byte_array(&key),
                value: Some(hex_byte_array(&value)),
                values: Vec::new(),
            });
        }
    }
    write_json(path, &entries)
}

fn map_keys(fd: i32, key_size: usize) -> Result<Vec<Vec<u8>>> {
    let mut keys = Vec::new();
    let mut previous: Option<Vec<u8>> = None;
    loop {
        let mut next = vec![0u8; key_size];
        let previous_ptr = previous
            .as_ref()
            .map_or(ptr::null(), |key| key.as_ptr().cast::<c_void>());
        let ret =
            unsafe { libbpf_sys::bpf_map_get_next_key(fd, previous_ptr, next.as_mut_ptr().cast()) };
        if ret == 0 {
            previous = Some(next.clone());
            keys.push(next);
            continue;
        }
        let err = io::Error::last_os_error();
        if err.kind() == io::ErrorKind::NotFound {
            break;
        }
        return Err(err).context("failed to iterate map keys");
    }
    Ok(keys)
}

fn lookup_value(fd: i32, key: &[u8], value_size: usize) -> Result<Vec<u8>> {
    let mut value = vec![0u8; value_size];
    syscall_ok(
        unsafe {
            libbpf_sys::bpf_map_lookup_elem(
                fd,
                key.as_ptr().cast::<c_void>(),
                value.as_mut_ptr().cast::<c_void>(),
            )
        },
        "failed to lookup map value",
    )?;
    Ok(value)
}

fn lookup_percpu_values(map: &MapRef, key: &[u8]) -> Result<Vec<PerCpuValueJson>> {
    let cpus = possible_cpu_count()?;
    let value_size = map.info.value_size as usize;
    let stride = (value_size + 7) & !7;
    let mut raw = vec![0u8; stride * cpus];
    syscall_ok(
        unsafe {
            libbpf_sys::bpf_map_lookup_elem(
                map.fd,
                key.as_ptr().cast::<c_void>(),
                raw.as_mut_ptr().cast::<c_void>(),
            )
        },
        "failed to lookup per-cpu map value",
    )?;
    Ok(raw
        .chunks_exact(stride)
        .map(|chunk| PerCpuValueJson {
            value: hex_byte_array(&chunk[..value_size]),
        })
        .collect())
}

fn create_verify_maps(dir: &Path, map_ids: &[u32]) -> Result<Vec<OwnedFd>> {
    let mut fds = Vec::new();
    for &map_id in map_ids {
        let show = read_json::<MapShowJson>(&dir.join(format!("map-{map_id}.show.json")))?;
        if matches!(
            show.type_,
            libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS | libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS
        ) {
            bail!("verify does not support map-in-map map {}", show.id);
        }
        let name = CString::new(show.name.as_str()).context("map name has NUL byte")?;
        let opts = libbpf_sys::bpf_map_create_opts {
            sz: mem::size_of::<libbpf_sys::bpf_map_create_opts>() as libbpf_sys::size_t,
            map_flags: show.map_flags,
            ..Default::default()
        };
        let fd = unsafe {
            libbpf_sys::bpf_map_create(
                show.type_,
                name.as_ptr(),
                show.bytes_key,
                show.bytes_value,
                show.max_entries,
                &opts,
            )
        };
        if fd < 0 {
            bail!(
                "failed to create verify map {}: {}",
                show.id,
                io::Error::last_os_error()
            );
        }
        fds.push(unsafe { OwnedFd::from_raw_fd(fd) });
    }
    Ok(fds)
}

fn canonicalize_input(workdir: &Path, bpfopt_arg: Option<&Path>, map_ids: &[u32]) -> Result<()> {
    let bpfopt = resolve_bpfopt(bpfopt_arg);
    let mut cmd = Command::new(&bpfopt);
    cmd.arg("--canonicalize-map-refs")
        .arg("--input")
        .arg(workdir.join(CANONICALIZE_INPUT_BIN))
        .arg("--output")
        .arg(workdir.join(INPUT_BIN));
    if !map_ids.is_empty() {
        cmd.arg("--map-ids").arg(join_u32_csv(map_ids));
    }
    let status = cmd
        .status()
        .with_context(|| format!("failed to run {}", bpfopt.display()))?;
    if !status.success() {
        bail!("bpfopt canonicalize failed with {}", status);
    }
    Ok(())
}

fn read_insns(path: &Path) -> Result<Vec<libbpf_sys::bpf_insn>> {
    let bytes = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
    if !bytes
        .len()
        .is_multiple_of(mem::size_of::<libbpf_sys::bpf_insn>())
    {
        bail!("{} length is not a multiple of 8 bytes", path.display());
    }
    bytes
        .chunks_exact(mem::size_of::<libbpf_sys::bpf_insn>())
        .map(|chunk| {
            let mut insn = MaybeUninit::<libbpf_sys::bpf_insn>::uninit();
            unsafe {
                ptr::copy_nonoverlapping(
                    chunk.as_ptr(),
                    insn.as_mut_ptr().cast::<u8>(),
                    chunk.len(),
                );
                Ok(insn.assume_init())
            }
        })
        .collect()
}

fn write_insns(path: &Path, insns: &[libbpf_sys::bpf_insn]) -> Result<()> {
    let bytes =
        unsafe { slice::from_raw_parts(insns.as_ptr().cast::<u8>(), mem::size_of_val(insns)) };
    fs::write(path, bytes).with_context(|| format!("failed to write {}", path.display()))
}

fn rewrite_map_indices_to_fds(insns: &mut [libbpf_sys::bpf_insn], fds: &[i32]) -> Result<()> {
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = &mut insns[pc];
        if is_ldimm64(insn) {
            match insn.src_reg() {
                BPF_PSEUDO_MAP_IDX | BPF_PSEUDO_MAP_IDX_VALUE => {
                    let idx = usize::try_from(insn.imm)
                        .with_context(|| format!("negative map index at pc {pc}"))?;
                    let fd = fds.get(idx).copied().ok_or_else(|| {
                        anyhow!("map index {idx} at pc {pc} has no verify map fd")
                    })?;
                    insn.imm = fd;
                    insn.set_src_reg(if insn.src_reg() == BPF_PSEUDO_MAP_IDX {
                        libbpf_sys::BPF_PSEUDO_MAP_FD as u8
                    } else {
                        libbpf_sys::BPF_PSEUDO_MAP_VALUE as u8
                    });
                }
                _ => {}
            }
            pc += 2;
        } else {
            pc += 1;
        }
    }
    Ok(())
}

fn is_ldimm64(insn: &libbpf_sys::bpf_insn) -> bool {
    insn.code == (libbpf_sys::BPF_LD | libbpf_sys::BPF_DW | libbpf_sys::BPF_IMM) as u8
}

fn needs_map_dump(map_type: u32) -> bool {
    matches!(
        map_type,
        libbpf_sys::BPF_MAP_TYPE_HASH
            | libbpf_sys::BPF_MAP_TYPE_ARRAY
            | libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY
            | libbpf_sys::BPF_MAP_TYPE_LRU_HASH
            | libbpf_sys::BPF_MAP_TYPE_LPM_TRIE
            | libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS
            | libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS
    )
}

fn possible_cpu_count() -> Result<usize> {
    let text = fs::read_to_string("/sys/devices/system/cpu/possible")
        .context("failed to read possible CPU set")?;
    parse_cpu_set(text.trim())
}

fn parse_cpu_set(input: &str) -> Result<usize> {
    let mut count = 0usize;
    for part in input.split(',') {
        let part = part.trim();
        if part.is_empty() {
            continue;
        }
        if let Some((start, end)) = part.split_once('-') {
            let start = start.parse::<usize>()?;
            let end = end.parse::<usize>()?;
            if end < start {
                bail!("invalid CPU range {part:?}");
            }
            count += end - start + 1;
        } else {
            part.parse::<usize>()?;
            count += 1;
        }
    }
    if count == 0 {
        bail!("empty possible CPU set");
    }
    Ok(count)
}

fn resolve_bpfopt(explicit: Option<&Path>) -> PathBuf {
    if let Some(path) = explicit {
        return path.to_path_buf();
    }
    if let Ok(path) = std::env::var("BPFOPT") {
        return PathBuf::from(path);
    }
    if let Ok(exe) = std::env::current_exe() {
        if let Some(dir) = exe.parent() {
            let sibling = dir.join("bpfopt");
            if sibling.exists() {
                return sibling;
            }
        }
    }
    PathBuf::from("bpfopt")
}

fn read_json<T: for<'de> Deserialize<'de>>(path: &Path) -> Result<T> {
    let bytes = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
    serde_json::from_slice(&bytes).with_context(|| format!("failed to parse {}", path.display()))
}

fn write_json<T: Serialize>(path: &Path, value: &T) -> Result<()> {
    let mut file =
        fs::File::create(path).with_context(|| format!("failed to create {}", path.display()))?;
    serde_json::to_writer_pretty(&mut file, value)
        .with_context(|| format!("failed to serialize {}", path.display()))?;
    writeln!(file).with_context(|| format!("failed to write {}", path.display()))
}

fn hex_byte_array(bytes: &[u8]) -> Vec<String> {
    bytes.iter().map(|byte| format!("0x{byte:02x}")).collect()
}

fn join_u32_csv(values: &[u32]) -> String {
    values
        .iter()
        .map(u32::to_string)
        .collect::<Vec<_>>()
        .join(",")
}

fn c_string(ptr: *const c_char) -> Result<String> {
    if ptr.is_null() {
        bail!("libbpf returned a null string");
    }
    Ok(unsafe { CStr::from_ptr(ptr) }
        .to_string_lossy()
        .into_owned())
}

fn c_name(name: &[c_char]) -> Result<String> {
    let bytes = name
        .iter()
        .take_while(|&&ch| ch != 0)
        .map(|&ch| ch as u8)
        .collect::<Vec<_>>();
    String::from_utf8(bytes).context("kernel map name is not UTF-8")
}

fn path_to_cstring(path: &Path) -> Result<CString> {
    CString::new(path.as_os_str().as_encoded_bytes())
        .with_context(|| format!("path contains NUL byte: {}", path.display()))
}

fn log_buf_to_string(buf: &[c_char]) -> String {
    let bytes = buf
        .iter()
        .take_while(|&&ch| ch != 0)
        .map(|&ch| ch as u8)
        .collect::<Vec<_>>();
    String::from_utf8_lossy(&bytes).into_owned()
}

fn libbpf_ok(ret: i32, context: &str) -> Result<()> {
    if ret < 0 {
        Err(anyhow!("{context}: {}", neg_errno(ret)))
    } else {
        Ok(())
    }
}

fn syscall_ok(ret: i32, context: &str) -> Result<()> {
    if ret < 0 {
        Err(anyhow!("{context}: {}", io::Error::last_os_error()))
    } else {
        Ok(())
    }
}

fn neg_errno(ret: i32) -> io::Error {
    io::Error::from_raw_os_error(-ret)
}

fn is_zero(value: &u32) -> bool {
    *value == 0
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::env;

    /// End-to-end smoke test: for a sample of BPF objects under
    /// `$BPFOPT_LOADER_OBJECT_ROOT` (default `../../corpus/build`), run the full
    /// loader flow with `--pass noop --verify`. Auto-skips on non-root hosts.
    #[test]
    fn prepare_noop_verify_many_objects() -> Result<()> {
        if !is_root()? {
            eprintln!("skipping prepare_noop_verify_many_objects: not running as root");
            return Ok(());
        }
        let bpfopt = test_bpfopt_path()?;
        let root = env::var_os("BPFOPT_LOADER_OBJECT_ROOT")
            .map(PathBuf::from)
            .unwrap_or_else(|| Path::new(env!("CARGO_MANIFEST_DIR")).join("../../corpus/build"));
        let object_count = env::var("BPFOPT_LOADER_SMOKE_OBJECTS")
            .unwrap_or_else(|_| "200".to_string())
            .parse::<usize>()
            .context("BPFOPT_LOADER_SMOKE_OBJECTS must be a positive integer")?;
        if object_count == 0 {
            bail!("BPFOPT_LOADER_SMOKE_OBJECTS must be non-zero");
        }
        let objects = find_bpf_objects(&root)?;
        if objects.is_empty() {
            eprintln!(
                "skipping prepare_noop_verify_many_objects: no BPF objects under {}",
                root.display()
            );
            return Ok(());
        }

        let mut failures = Vec::new();
        for obj in objects.iter().take(object_count) {
            let selector = match first_program_selector(obj) {
                Ok(sel) => sel,
                Err(err) => {
                    failures.push(format!("{}: {}", obj.display(), short_error(&err)));
                    continue;
                }
            };
            // No `--workdir`: each iteration uses a tmp dir auto-removed on drop.
            let cli = Cli {
                obj: obj.clone(),
                prog: selector,
                pass: Some("noop".to_string()),
                target: None,
                workdir: None,
                bpfopt: Some(bpfopt.clone()),
                pass_config_dir: None,
                log_bytes: DEFAULT_LOG_BYTES,
            };
            if let Err(err) = run(cli) {
                failures.push(format!("{}: {}", obj.display(), short_error(&err)));
            }
        }

        if !failures.is_empty() {
            bail!(
                "{} of {} loader smoke object(s) failed:\n{}",
                failures.len(),
                object_count.min(objects.len()),
                failures.join("\n")
            );
        }
        Ok(())
    }

    fn is_root() -> Result<bool> {
        let out = Command::new("id")
            .arg("-u")
            .output()
            .context("failed to run id -u")?;
        if !out.status.success() {
            bail!("id -u failed with {}", out.status);
        }
        Ok(String::from_utf8(out.stdout)
            .context("id -u output is not UTF-8")?
            .trim()
            == "0")
    }

    fn test_bpfopt_path() -> Result<PathBuf> {
        if let Some(path) = env::var_os("BPFOPT").map(PathBuf::from) {
            if path.exists() {
                return Ok(path);
            }
            bail!("BPFOPT points to missing binary {}", path.display());
        }
        let exe = env::current_exe().context("failed to resolve current test binary")?;
        let target_dir = exe
            .parent()
            .and_then(|p| p.parent())
            .ok_or_else(|| anyhow!("test binary path has no target dir: {}", exe.display()))?;
        let bpfopt = target_dir.join("bpfopt");
        if !bpfopt.exists() {
            bail!(
                "missing {}; run `cargo build -p bpfopt` or set BPFOPT",
                bpfopt.display()
            );
        }
        Ok(bpfopt)
    }

    fn find_bpf_objects(root: &Path) -> Result<Vec<PathBuf>> {
        if !root.exists() {
            return Ok(Vec::new());
        }
        let output = Command::new("find")
            .arg(root)
            .args([
                "-type", "f", "(", "-name", "*.bpf.o", "-o", "-name", "bpf_*.o", ")",
            ])
            .output()
            .with_context(|| format!("failed to run find under {}", root.display()))?;
        if !output.status.success() {
            bail!("find {} failed with {}", root.display(), output.status);
        }
        let mut objects = String::from_utf8(output.stdout)
            .context("find output is not UTF-8")?
            .lines()
            .map(PathBuf::from)
            .collect::<Vec<_>>();
        objects.sort();
        Ok(objects)
    }

    fn first_program_selector(path: &Path) -> Result<String> {
        let obj = open_bpf_object(path)?;
        let progs = programs(&obj)?;
        let first = progs
            .first()
            .ok_or_else(|| anyhow!("{} has no BPF programs", path.display()))?;
        if progs.iter().filter(|prog| prog.name == first.name).count() == 1 {
            return Ok(first.name.clone());
        }
        if progs
            .iter()
            .filter(|prog| prog.section == first.section)
            .count()
            == 1
        {
            return Ok(first.section.clone());
        }
        bail!(
            "{} first program is ambiguous by name {:?} and section {:?}",
            path.display(),
            first.name,
            first.section
        );
    }

    fn short_error(err: &anyhow::Error) -> String {
        let text = format!("{err:#}");
        const LIMIT: usize = 1200;
        if text.len() <= LIMIT {
            text
        } else {
            format!("{}...[truncated]", &text[..LIMIT])
        }
    }
}
