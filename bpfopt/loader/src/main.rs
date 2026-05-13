// SPDX-License-Identifier: MIT
//! Host-side developer loader for bpfopt. Run from the project root.
//!
//! Flow:
//!   1. libbpf-load `<obj>:<prog>` with log_level=2, capture verifier log
//!   2. dump map snapshots + metadata into a workdir
//!   3. invoke `bpfopt --canonicalize-map-refs`
//!   4. if `--pass` given: run the daemon's per-pass yaml
//!      (`runner/config/passes/<pass>/default.yaml`) and re-verify the output
//!      with `BPF_PROG_LOAD`
//!
//! `--workdir` is optional; if omitted a `/tmp/bpfopt-loader-<pid>-<n>` dir is
//! created and removed on exit.

use std::collections::BTreeSet;
use std::ffi::{CStr, CString};
use std::fs;
use std::io::{self, Write};
use std::mem;
use std::os::fd::{AsRawFd, FromRawFd, OwnedFd};
use std::os::raw::{c_char, c_void};
use std::path::{Path, PathBuf};
use std::process::{Command, ExitCode};
use std::sync::atomic::{AtomicU64, Ordering};
use std::{ptr, slice};

use anyhow::{anyhow, bail, Context, Result};
use clap::Parser;
use serde::{Deserialize, Serialize};

// All paths are relative to the project root; the binary expects to be invoked
// from there (`cargo test` chdirs to the crate dir, so the smoke test does the
// chdir itself).
const BPFOPT_BIN: &str = "bpfopt/target/debug/bpfopt";
const PASS_CONFIG_DIR: &str = "runner/config/passes";
#[cfg(test)]
const CORPUS_BUILD_DIR: &str = "corpus/build";

const LOG_BYTES: usize = 16 * 1024 * 1024;
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
    /// Pass to run via the daemon's per-pass yaml.
    #[arg(long, value_name = "NAME")]
    pass: Option<String>,
    /// Target.json passed to the pass yaml (only needed by kinsn-class passes).
    #[arg(long, value_name = "FILE")]
    target: Option<PathBuf>,
    /// Workdir to use. If omitted, a tmp dir is created and removed on exit.
    #[arg(long, value_name = "DIR")]
    workdir: Option<PathBuf>,
}

/// Allocate a workdir. Caller-supplied paths are not cleaned up; tmp dirs are
/// removed when the returned [`WorkDir`] drops.
struct WorkDir {
    path: PathBuf,
    cleanup: bool,
}

impl WorkDir {
    fn open(user_provided: Option<PathBuf>) -> Result<Self> {
        let (path, cleanup) = match user_provided {
            Some(p) => (p, false),
            None => {
                static N: AtomicU64 = AtomicU64::new(0);
                let id = N.fetch_add(1, Ordering::Relaxed);
                (
                    PathBuf::from(format!("/tmp/bpfopt-loader-{}-{id}", std::process::id())),
                    true,
                )
            }
        };
        fs::create_dir_all(&path)
            .with_context(|| format!("failed to create {}", path.display()))?;
        Ok(Self { path, cleanup })
    }
}

impl Drop for WorkDir {
    fn drop(&mut self) {
        if self.cleanup {
            let _ = fs::remove_dir_all(&self.path);
        }
    }
}

#[derive(Debug, Serialize, Deserialize)]
struct ProgramMetadata {
    name: String,
    prog_type: u32,
    #[serde(default)]
    expected_attach_type: u32,
    #[serde(default)]
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
    #[serde(default)]
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
    let workdir = WorkDir::open(cli.workdir.clone())?;
    let map_ids = prepare_workdir(&workdir.path, &cli.obj, &cli.prog)?;

    // Canonicalize loader-FD map refs into stable IDX form.
    let mut canon = Command::new(BPFOPT_BIN);
    canon
        .arg("--canonicalize-map-refs")
        .arg("--input")
        .arg(workdir.path.join(CANONICALIZE_INPUT_BIN))
        .arg("--output")
        .arg(workdir.path.join(INPUT_BIN));
    if !map_ids.is_empty() {
        canon.arg("--map-ids").arg(join_u32_csv(&map_ids));
    }
    let status = canon
        .status()
        .with_context(|| format!("failed to run {BPFOPT_BIN}"))?;
    if !status.success() {
        bail!("bpfopt canonicalize failed with {status}");
    }

    if let Some(pass) = cli.pass.as_deref() {
        run_pass_via_yaml(&workdir.path, pass, cli.target.as_deref(), &map_ids)?;
        verify_workdir(&workdir.path)?;
    }
    Ok(())
}

/// libbpf-load `<obj_path>:<prog_selector>` and dump bytecode, verifier log,
/// metadata, and map snapshots into `workdir`. Returns the bytecode map ids.
fn prepare_workdir(workdir: &Path, obj_path: &Path, prog_selector: &str) -> Result<Vec<u32>> {
    fs::create_dir_all(workdir.join(MAP_VALUES_DIR))?;

    let obj = open_bpf_object(obj_path)?;
    let selected = select_program(&obj, prog_selector)?;
    // Disable autoload for every program except the selected one, and set
    // log_level=2 on the selected program so the verifier log lands in log_buf.
    for prog in programs(&obj)? {
        libbpf_ok(
            unsafe { libbpf_sys::bpf_program__set_autoload(prog.ptr, prog.ptr == selected.ptr) },
            "bpf_program__set_autoload",
        )?;
        unsafe { libbpf_sys::bpf_program__set_autoattach(prog.ptr, false) };
    }
    let mut log_buf = vec![0 as c_char; LOG_BYTES];
    libbpf_ok(
        unsafe { libbpf_sys::bpf_program__set_log_level(selected.ptr, 2) },
        "bpf_program__set_log_level",
    )?;
    libbpf_ok(
        unsafe {
            libbpf_sys::bpf_program__set_log_buf(
                selected.ptr,
                log_buf.as_mut_ptr(),
                LOG_BYTES as libbpf_sys::size_t,
            )
        },
        "bpf_program__set_log_buf",
    )?;

    let ret = unsafe { libbpf_sys::bpf_object__load(obj.ptr) };
    if ret < 0 {
        fs::write(workdir.join(VERIFIER_LOG), log_buf_to_string(&log_buf))?;
        bail!(
            "libbpf failed to load {}: {}",
            obj_path.display(),
            neg_errno(ret)
        );
    }

    let prog_fd = unsafe { libbpf_sys::bpf_program__fd(selected.ptr) };
    if prog_fd < 0 {
        bail!("selected program has no loaded fd");
    }
    let prog_info: libbpf_sys::bpf_prog_info = unsafe { obj_info(prog_fd)? };
    let loaded_maps = maps(&obj)?;

    let insn_cnt = unsafe { libbpf_sys::bpf_program__insn_cnt(selected.ptr) };
    let insn_ptr = unsafe { libbpf_sys::bpf_program__insns(selected.ptr) };
    if insn_ptr.is_null() && insn_cnt != 0 {
        bail!("selected program has null instruction pointer");
    }
    let insns = unsafe { slice::from_raw_parts(insn_ptr, insn_cnt as usize) }.to_vec();
    let map_ids = bytecode_map_ids(&insns, &loaded_maps)?;

    write_json(
        &workdir.join(MAP_IDS_JSON),
        &MapIdsJson {
            map_ids: map_ids.clone(),
        },
    )?;
    let bytes =
        unsafe { slice::from_raw_parts(insns.as_ptr().cast::<u8>(), mem::size_of_val(&insns[..])) };
    fs::write(workdir.join(CANONICALIZE_INPUT_BIN), bytes)?;
    dump_map_snapshots(&loaded_maps, &map_ids, &workdir.join(MAP_VALUES_DIR))?;
    fs::write(workdir.join(VERIFIER_LOG), log_buf_to_string(&log_buf))?;
    write_json(
        &workdir.join(METADATA_JSON),
        &ProgramMetadata {
            name: selected.name,
            prog_type: unsafe { libbpf_sys::bpf_program__type(selected.ptr) },
            expected_attach_type: unsafe {
                libbpf_sys::bpf_program__expected_attach_type(selected.ptr)
            },
            attach_btf_id: prog_info.attach_btf_id,
        },
    )?;
    Ok(map_ids)
}

/// `BPF_OBJ_GET_INFO_BY_FD` for any sized info struct.
unsafe fn obj_info<T: Default>(fd: i32) -> Result<T> {
    let mut info = T::default();
    let mut len = mem::size_of::<T>() as u32;
    syscall_ok(
        libbpf_sys::bpf_obj_get_info_by_fd(fd, (&mut info as *mut T).cast(), &mut len),
        "bpf_obj_get_info_by_fd",
    )?;
    Ok(info)
}

/// Read `runner/config/passes/<pass>/default.yaml`, substitute `${VAR}` tokens
/// with workdir paths and metadata, and execute the command via `sh -c`. The
/// yaml's bare `bpfopt` is rewritten to the hardcoded binary path.
fn run_pass_via_yaml(
    workdir: &Path,
    pass: &str,
    target: Option<&Path>,
    map_ids: &[u32],
) -> Result<()> {
    let yaml_path = Path::new(PASS_CONFIG_DIR).join(pass).join("default.yaml");
    let yaml: serde_yaml::Value = serde_yaml::from_slice(&fs::read(&yaml_path)?)?;
    let template = yaml
        .get("command")
        .and_then(|v| v.as_str())
        .ok_or_else(|| anyhow!("{} missing `command` string", yaml_path.display()))?;

    let metadata = read_json::<ProgramMetadata>(&workdir.join(METADATA_JSON))?;
    let p = |sub: &str| workdir.join(sub).display().to_string();
    let map_ids_arg = if map_ids.is_empty() {
        "0".into()
    } else {
        join_u32_csv(map_ids)
    };
    let target_arg = target.map(|t| t.display().to_string()).unwrap_or_default();
    let command = template
        .replacen("bpfopt ", &format!("{BPFOPT_BIN} "), 1)
        .replace("${INPUT}", &p(INPUT_BIN))
        .replace("${OUTPUT}", &p(OUTPUT_BIN))
        .replace("${REPORT}", &p(REPORT_JSON))
        .replace("${VERIFIER_STATES}", &p(VERIFIER_LOG))
        .replace("${MAP_VALUES}", &p(MAP_VALUES_DIR))
        .replace("${MAP_IDS}", &map_ids_arg)
        .replace("${PROG_TYPE}", &metadata.prog_type.to_string())
        .replace("${TARGET}", &target_arg);

    let status = Command::new("sh").arg("-c").arg(&command).status()?;
    if !status.success() {
        bail!("pass {pass} exited with {status}");
    }
    Ok(())
}

/// Reload the produced bytecode via BPF_PROG_LOAD as a sanity check.
fn verify_workdir(workdir: &Path) -> Result<()> {
    let metadata = read_json::<ProgramMetadata>(&workdir.join(METADATA_JSON))?;
    let map_ids = read_json::<MapIdsJson>(&workdir.join(MAP_IDS_JSON))?.map_ids;
    let input = workdir.join(OUTPUT_BIN);
    let map_fds = create_verify_maps(&workdir.join(MAP_VALUES_DIR), &map_ids)?;
    let fd_nums = map_fds.iter().map(|fd| fd.as_raw_fd()).collect::<Vec<_>>();
    let mut insns = read_insns(&input)?;
    rewrite_map_indices_to_fds(&mut insns, &fd_nums)?;

    let name = CString::new(metadata.name.as_str())?;
    let license = CString::new("GPL").unwrap();
    let mut log_buf = vec![0 as c_char; LOG_BYTES];
    let mut opts = libbpf_sys::bpf_prog_load_opts {
        sz: mem::size_of::<libbpf_sys::bpf_prog_load_opts>() as libbpf_sys::size_t,
        log_level: 1,
        log_size: log_buf.len() as u32,
        log_buf: log_buf.as_mut_ptr(),
        expected_attach_type: metadata.expected_attach_type,
        attach_btf_id: metadata.attach_btf_id,
        ..Default::default()
    };
    let fd = unsafe {
        libbpf_sys::bpf_prog_load(
            metadata.prog_type,
            name.as_ptr(),
            license.as_ptr(),
            insns.as_ptr(),
            insns.len() as libbpf_sys::size_t,
            &mut opts,
        )
    };
    let log = log_buf_to_string(&log_buf);
    fs::write(workdir.join(VERIFY_LOG), &log)?;
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

fn open_bpf_object(path: &Path) -> Result<BpfObject> {
    let c_path = CString::new(path.as_os_str().as_encoded_bytes())
        .with_context(|| format!("path contains NUL byte: {}", path.display()))?;
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
            out.push(MapRef {
                fd,
                info: unsafe { obj_info(fd)? },
            });
        }
        prev = map;
    }
    Ok(out)
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
        let name_bytes: Vec<u8> = map
            .info
            .name
            .iter()
            .take_while(|&&c| c != 0)
            .map(|&c| c as u8)
            .collect();
        let show = MapShowJson {
            id: map.info.id,
            name: String::from_utf8(name_bytes).context("kernel map name is not UTF-8")?,
            type_: map.info.type_,
            bytes_key: map.info.key_size,
            bytes_value: map.info.value_size,
            max_entries: map.info.max_entries,
            map_flags: map.info.map_flags,
        };
        write_json(&dir.join(format!("map-{map_id}.show.json")), &show)?;
        if matches!(
            map.info.type_,
            libbpf_sys::BPF_MAP_TYPE_HASH
                | libbpf_sys::BPF_MAP_TYPE_ARRAY
                | libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY
                | libbpf_sys::BPF_MAP_TYPE_LRU_HASH
                | libbpf_sys::BPF_MAP_TYPE_LPM_TRIE
                | libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS
                | libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS
        ) {
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

fn dump_map_entries(map: &MapRef, path: &Path) -> Result<()> {
    if matches!(
        map.info.type_,
        libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS | libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS
    ) {
        bail!("map-in-map snapshots are not implemented");
    }
    let value_size = map.info.value_size as usize;
    let is_percpu = map.info.type_ == libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY;
    let stride = if is_percpu {
        (value_size + 7) & !7
    } else {
        value_size
    };
    let buf_size = if is_percpu {
        stride * possible_cpu_count()?
    } else {
        value_size
    };

    let mut entries = Vec::new();
    for key in map_keys(map.fd, map.info.key_size as usize)? {
        let mut raw = vec![0u8; buf_size];
        syscall_ok(
            unsafe {
                libbpf_sys::bpf_map_lookup_elem(
                    map.fd,
                    key.as_ptr().cast::<c_void>(),
                    raw.as_mut_ptr().cast::<c_void>(),
                )
            },
            "bpf_map_lookup_elem",
        )?;
        let entry = if is_percpu {
            MapDumpEntryJson {
                key: hex_byte_array(&key),
                value: None,
                values: raw
                    .chunks_exact(stride)
                    .map(|c| PerCpuValueJson {
                        value: hex_byte_array(&c[..value_size]),
                    })
                    .collect(),
            }
        } else {
            MapDumpEntryJson {
                key: hex_byte_array(&key),
                value: Some(hex_byte_array(&raw)),
                values: Vec::new(),
            }
        };
        entries.push(entry);
    }
    write_json(path, &entries)
}

fn map_keys(fd: i32, key_size: usize) -> Result<Vec<Vec<u8>>> {
    let mut keys = Vec::new();
    let mut previous: Option<Vec<u8>> = None;
    loop {
        let mut next = vec![0u8; key_size];
        let prev_ptr = previous.as_ref().map_or(ptr::null(), |k| k.as_ptr().cast());
        let ret =
            unsafe { libbpf_sys::bpf_map_get_next_key(fd, prev_ptr, next.as_mut_ptr().cast()) };
        if ret == 0 {
            previous = Some(next.clone());
            keys.push(next);
            continue;
        }
        if io::Error::last_os_error().kind() == io::ErrorKind::NotFound {
            return Ok(keys);
        }
        return Err(io::Error::last_os_error()).context("bpf_map_get_next_key");
    }
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

fn read_insns(path: &Path) -> Result<Vec<libbpf_sys::bpf_insn>> {
    let bytes = fs::read(path)?;
    let stride = mem::size_of::<libbpf_sys::bpf_insn>();
    if !bytes.len().is_multiple_of(stride) {
        bail!("{} length is not a multiple of 8 bytes", path.display());
    }
    let mut insns = vec![libbpf_sys::bpf_insn::default(); bytes.len() / stride];
    unsafe { ptr::copy_nonoverlapping(bytes.as_ptr(), insns.as_mut_ptr().cast(), bytes.len()) };
    Ok(insns)
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

/// Parse `/sys/devices/system/cpu/possible`. Kernel almost always writes a
/// single range `0-N` (or `0` on a uniprocessor). No multi-range/comma support.
fn possible_cpu_count() -> Result<usize> {
    let text = fs::read_to_string("/sys/devices/system/cpu/possible")?;
    let trimmed = text.trim();
    let last = match trimmed.split_once('-') {
        Some((_, end)) => end.parse::<usize>()?,
        None => trimmed.parse::<usize>()?,
    };
    Ok(last + 1)
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

#[cfg(test)]
mod tests {
    use super::*;

    /// End-to-end smoke test: for up to `SMOKE_OBJECTS` BPF objects under
    /// `corpus/build`, run `--pass noop` + verify. Skipped on non-root hosts.
    /// Must be invoked from the project root (cargo test chdirs the test to
    /// the crate dir, so we chdir back to project root first).
    const SMOKE_OBJECTS: usize = 200;

    #[test]
    fn prepare_noop_verify_many_objects() -> Result<()> {
        if !is_root() {
            eprintln!("skipping prepare_noop_verify_many_objects: not running as root");
            return Ok(());
        }
        std::env::set_current_dir("../..").context("chdir to project root")?;

        let objects = find_bpf_objects(Path::new(CORPUS_BUILD_DIR))?;
        if objects.is_empty() {
            eprintln!(
                "skipping prepare_noop_verify_many_objects: no objects under {CORPUS_BUILD_DIR}"
            );
            return Ok(());
        }

        let mut failures = Vec::new();
        for obj in objects.iter().take(SMOKE_OBJECTS) {
            let selector = match first_program_selector(obj) {
                Ok(sel) => sel,
                Err(err) => {
                    failures.push(format!("{}: {err:#}", obj.display()));
                    continue;
                }
            };
            let cli = Cli {
                obj: obj.clone(),
                prog: selector,
                pass: Some("noop".into()),
                target: None,
                workdir: None,
            };
            if let Err(err) = run(cli) {
                failures.push(format!("{}: {err:#}", obj.display()));
            }
        }

        if !failures.is_empty() {
            bail!(
                "{} of {} smoke object(s) failed:\n{}",
                failures.len(),
                SMOKE_OBJECTS.min(objects.len()),
                failures.join("\n")
            );
        }
        Ok(())
    }

    fn is_root() -> bool {
        extern "C" {
            fn geteuid() -> u32;
        }
        unsafe { geteuid() == 0 }
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
            .output()?;
        if !output.status.success() {
            bail!("find {} failed with {}", root.display(), output.status);
        }
        let mut objects = String::from_utf8(output.stdout)?
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
        if progs.iter().filter(|p| p.name == first.name).count() == 1 {
            Ok(first.name.clone())
        } else if progs.iter().filter(|p| p.section == first.section).count() == 1 {
            Ok(first.section.clone())
        } else {
            bail!(
                "{} first program ambiguous by name and section",
                path.display()
            )
        }
    }
}
