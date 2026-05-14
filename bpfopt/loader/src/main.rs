// SPDX-License-Identifier: MIT
//! Host-side developer loader for bpfopt. Run from the project root.
//!
//! Flow:
//!   1. libbpf-load every program in `<obj>` with log_level=2; write per-program
//!      {bytecode, verifier log, metadata, map-ids} into `<workdir>/<prog_name>/`
//!   2. shell out to `bpftool map show -j` + `bpftool map dump -j` for each map
//!      referenced by the loaded programs → `<workdir>/map-values/`
//!   3. for each program: `bpfopt --canonicalize-map-refs`
//!   4. for each program (if `--pass` given): execute the daemon's per-pass yaml
//!      at `runner/config/passes/<pass>/default.yaml`, then re-verify the
//!      produced bytecode with `BPF_PROG_LOAD`
//!
//! `--workdir` is optional; if omitted a `/tmp/bpfopt-loader-<pid>-<n>` dir is
//! created and removed on exit. Map snapshots come straight from `bpftool` so
//! the file format is whatever bpfopt's downstream passes already expect.

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

const LOG_BYTES: usize = 64 * 1024 * 1024;
const KATRAN_CH_RING_SIZE: u32 = 65537;
const INPUT_BIN: &str = "input.bin";
const CANONICALIZE_INPUT_BIN: &str = "canonicalize_input.bin";
const OUTPUT_BIN: &str = "output.bin";
const REPORT_JSON: &str = "report.json";
const TEST_INPUT_BIN: &str = "test_input.bin";
const TEST_RUN_JSON: &str = "test_run.json";
const TEST_OUTPUT_BIN: &str = "test_output.bin";
const KATRAN_TEST_INPUT: &str = "corpus/inputs/katran_vip_packet_64.bin";
const MAP_IDS_JSON: &str = "map-ids.json";
const MAP_VALUES_DIR: &str = "map-values";
const MAP_DUMP_ENTRY_LIMIT: u32 = 8192;
const METADATA_JSON: &str = "metadata.json";
const VERIFIER_LOG: &str = "verifier.log";
const VERIFY_LOG: &str = "verify.log";

#[derive(Parser)]
#[command(
    name = "bpfopt-loader",
    version,
    about = "Host-side bpfopt fixture loader"
)]
struct Cli {
    /// BPF object file to open through libbpf. All programs inside it are
    /// loaded and processed; each ends up in `<workdir>/<prog_name>/`.
    #[arg(long, value_name = "FILE")]
    obj: PathBuf,
    /// Pass to run via the daemon's per-pass yaml.
    #[arg(long, value_name = "NAME")]
    pass: Option<String>,
    /// bpfopt executable to invoke.
    #[arg(long, value_name = "FILE", default_value = BPFOPT_BIN)]
    bpfopt: PathBuf,
    /// Target.json passed to the pass yaml (only needed by kinsn-class passes).
    #[arg(long, value_name = "FILE")]
    target: Option<PathBuf>,
    /// Workdir to use. If omitted, a tmp dir is created and removed on exit.
    #[arg(long, value_name = "DIR")]
    workdir: Option<PathBuf>,
    /// Run BPF_PROG_TEST_RUN after host verifier loading the pass output.
    #[arg(long)]
    bpftestrun: bool,
    /// Populate Katran balancer maps like runner/libs/app_runners/katran.py.
    #[arg(long)]
    katran_maps: bool,
    /// BPF_PROG_TEST_RUN repeat count.
    #[arg(long, default_value_t = 1)]
    repeat: u32,
}

struct PreparedProgram {
    dir: PathBuf,
    map_ids: Vec<u32>,
    map_fds: Vec<i32>,
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
}

struct MapRef {
    fd: i32,
    name: String,
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
    if cli.bpftestrun && cli.pass.is_none() {
        bail!("--bpftestrun requires --pass; use --pass noop for unoptimized bytecode");
    }
    let workdir = WorkDir::open(cli.workdir.clone())?;
    let map_values_dir = workdir.path.join(MAP_VALUES_DIR);
    let dump_values = cli.pass.as_deref() == Some("map_inline");
    let (_obj, prepared) = prepare_workdir(&workdir.path, &cli.obj, cli.katran_maps, dump_values)?;

    for prog in &prepared {
        canonicalize_program(prog, &cli.bpfopt)?;
        if let Some(pass) = cli.pass.as_deref() {
            run_pass_via_yaml(
                &prog.dir,
                &map_values_dir,
                pass,
                &cli.bpfopt,
                cli.target.as_deref(),
                &prog.map_ids,
            )?;
            let fd = verify_workdir(&prog.dir, &prog.map_fds)?;
            if cli.bpftestrun {
                run_bpftestrun(fd.as_raw_fd(), &prog.dir, &cli)?;
            }
        }
    }
    Ok(())
}

fn canonicalize_program(prog: &PreparedProgram, bpfopt: &Path) -> Result<()> {
    let mut canon = Command::new(bpfopt);
    canon
        .arg("--canonicalize-map-refs")
        .arg("--input")
        .arg(prog.dir.join(CANONICALIZE_INPUT_BIN))
        .arg("--output")
        .arg(prog.dir.join(INPUT_BIN));
    if !prog.map_ids.is_empty() {
        canon.arg("--map-ids").arg(join_u32_csv(&prog.map_ids));
    }
    let status = canon.status()?;
    if !status.success() {
        bail!("canonicalize failed for {} ({status})", prog.dir.display());
    }
    Ok(())
}

fn shell_quote_path(path: &Path) -> String {
    format!("'{}'", path.display().to_string().replace('\'', "'\\''"))
}

/// libbpf-load every program in `obj_path` with log_level=2 and dump bytecode,
/// verifier log, metadata, and shared map snapshots into `workdir`. Each
/// program lands in `<workdir>/<prog_name>/`; map snapshots are shared at
/// `<workdir>/map-values/`.
fn prepare_workdir(
    workdir: &Path,
    obj_path: &Path,
    katran_maps: bool,
    dump_values: bool,
) -> Result<(BpfObject, Vec<PreparedProgram>)> {
    let map_values_dir = workdir.join(MAP_VALUES_DIR);
    fs::create_dir_all(&map_values_dir)?;

    let obj = open_bpf_object(obj_path)?;
    let progs = programs(&obj)?;
    let mut log_bufs: Vec<Vec<c_char>> = (0..progs.len()).map(|_| vec![0; LOG_BYTES]).collect();
    for (prog, buf) in progs.iter().zip(log_bufs.iter_mut()) {
        libbpf_ok(
            unsafe { libbpf_sys::bpf_program__set_log_level(prog.ptr, 2) },
            "bpf_program__set_log_level",
        )?;
        libbpf_ok(
            unsafe {
                libbpf_sys::bpf_program__set_log_buf(
                    prog.ptr,
                    buf.as_mut_ptr(),
                    LOG_BYTES as libbpf_sys::size_t,
                )
            },
            "bpf_program__set_log_buf",
        )?;
        unsafe { libbpf_sys::bpf_program__set_autoattach(prog.ptr, false) };
    }

    let ret = unsafe { libbpf_sys::bpf_object__load(obj.ptr) };
    if ret < 0 {
        // Dump whatever verifier output libbpf produced so the user can diagnose.
        for (prog, buf) in progs.iter().zip(&log_bufs) {
            let dir = workdir.join(&prog.name);
            let _ = fs::create_dir_all(&dir);
            let _ = fs::write(dir.join(VERIFIER_LOG), log_buf_to_string(buf));
        }
        bail!(
            "libbpf failed to load {}: {}",
            obj_path.display(),
            neg_errno(ret)
        );
    }

    let loaded_maps = maps(&obj)?;
    if katran_maps {
        populate_katran_maps(&loaded_maps)?;
    }
    let mut prepared = Vec::with_capacity(progs.len());
    let mut all_map_ids = BTreeSet::new();
    for (prog, log_buf) in progs.into_iter().zip(log_bufs) {
        let dir = workdir.join(&prog.name);
        fs::create_dir_all(&dir)?;

        let prog_fd = unsafe { libbpf_sys::bpf_program__fd(prog.ptr) };
        if prog_fd < 0 {
            bail!("program {} has no loaded fd", prog.name);
        }
        let prog_info: libbpf_sys::bpf_prog_info = unsafe { obj_info(prog_fd)? };
        let insn_cnt = unsafe { libbpf_sys::bpf_program__insn_cnt(prog.ptr) };
        let insn_ptr = unsafe { libbpf_sys::bpf_program__insns(prog.ptr) };
        if insn_ptr.is_null() && insn_cnt != 0 {
            bail!("program {} has a null instruction pointer", prog.name);
        }
        let insns = unsafe { slice::from_raw_parts(insn_ptr, insn_cnt as usize) }.to_vec();
        let (map_ids, map_fds) = bytecode_maps(&insns, &loaded_maps)?;

        write_json(
            &dir.join(MAP_IDS_JSON),
            &MapIdsJson {
                map_ids: map_ids.clone(),
            },
        )?;
        let bytes = unsafe {
            slice::from_raw_parts(insns.as_ptr().cast::<u8>(), mem::size_of_val(&insns[..]))
        };
        fs::write(dir.join(CANONICALIZE_INPUT_BIN), bytes)?;
        fs::write(dir.join(VERIFIER_LOG), log_buf_to_string(&log_buf))?;
        write_json(
            &dir.join(METADATA_JSON),
            &ProgramMetadata {
                name: prog.name.clone(),
                prog_type: unsafe { libbpf_sys::bpf_program__type(prog.ptr) },
                expected_attach_type: unsafe {
                    libbpf_sys::bpf_program__expected_attach_type(prog.ptr)
                },
                attach_btf_id: prog_info.attach_btf_id,
            },
        )?;
        all_map_ids.extend(map_ids.iter().copied());
        prepared.push(PreparedProgram {
            dir,
            map_ids,
            map_fds,
        });
    }

    let all_map_ids: Vec<u32> = all_map_ids.into_iter().collect();
    dump_map_snapshots(&all_map_ids, &map_values_dir, &loaded_maps, dump_values)?;
    Ok((obj, prepared))
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
/// with `prog_dir` paths + the shared `map_values_dir`, and execute the command
/// via `sh -c`. The yaml's bare `bpfopt` is rewritten to the selected binary.
fn run_pass_via_yaml(
    prog_dir: &Path,
    map_values_dir: &Path,
    pass: &str,
    bpfopt: &Path,
    target: Option<&Path>,
    map_ids: &[u32],
) -> Result<()> {
    let yaml_path = Path::new(PASS_CONFIG_DIR).join(pass).join("default.yaml");
    let yaml: serde_yaml::Value = serde_yaml::from_slice(&fs::read(&yaml_path)?)?;
    let template = yaml
        .get("command")
        .and_then(|v| v.as_str())
        .ok_or_else(|| anyhow!("{} missing `command` string", yaml_path.display()))?;

    let metadata = read_json::<ProgramMetadata>(&prog_dir.join(METADATA_JSON))?;
    let p = |sub: &str| prog_dir.join(sub).display().to_string();
    let map_ids_arg = if map_ids.is_empty() {
        "0".into()
    } else {
        join_u32_csv(map_ids)
    };
    let target_arg = target.map(|t| t.display().to_string()).unwrap_or_default();
    let command = template
        .replacen("bpfopt ", &format!("{} ", shell_quote_path(bpfopt)), 1)
        .replace("${INPUT}", &p(INPUT_BIN))
        .replace("${OUTPUT}", &p(OUTPUT_BIN))
        .replace("${REPORT}", &p(REPORT_JSON))
        .replace("${VERIFIER_STATES}", &p(VERIFIER_LOG))
        .replace("${MAP_VALUES}", &map_values_dir.display().to_string())
        .replace("${MAP_IDS}", &map_ids_arg)
        .replace("${PROG_TYPE}", &metadata.prog_type.to_string())
        .replace("${TARGET}", &target_arg);

    let status = Command::new("sh").arg("-c").arg(&command).status()?;
    if !status.success() {
        bail!("pass {pass} exited with {status}");
    }
    Ok(())
}

/// Reload the bytecode produced for `prog_dir` via BPF_PROG_LOAD as a sanity
/// check, using the shared map snapshots at `map_values_dir`.
fn verify_workdir(prog_dir: &Path, map_fds: &[i32]) -> Result<OwnedFd> {
    verify_workdir_with_log_level(prog_dir, map_fds, 1)
}

fn verify_workdir_with_log_level(
    prog_dir: &Path,
    map_fds: &[i32],
    log_level: u32,
) -> Result<OwnedFd> {
    let metadata = read_json::<ProgramMetadata>(&prog_dir.join(METADATA_JSON))?;
    let input = prog_dir.join(OUTPUT_BIN);

    let raw = fs::read(&input)?;
    let stride = mem::size_of::<libbpf_sys::bpf_insn>();
    if !raw.len().is_multiple_of(stride) {
        bail!("{} length is not a multiple of 8 bytes", input.display());
    }
    let mut insns = vec![libbpf_sys::bpf_insn::default(); raw.len() / stride];
    unsafe { ptr::copy_nonoverlapping(raw.as_ptr(), insns.as_mut_ptr().cast(), raw.len()) };
    rewrite_map_indices_to_fds(&mut insns, map_fds)?;

    let name = CString::new(metadata.name.as_str())?;
    let license = CString::new("GPL").unwrap();
    let mut log_buf = vec![0 as c_char; LOG_BYTES];
    let mut opts = libbpf_sys::bpf_prog_load_opts {
        sz: mem::size_of::<libbpf_sys::bpf_prog_load_opts>() as libbpf_sys::size_t,
        log_level,
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
    fs::write(prog_dir.join(VERIFY_LOG), &log)?;
    if fd < 0 {
        bail!(
            "BPF_PROG_LOAD rejected {}: {}; verifier log: {}",
            input.display(),
            io::Error::last_os_error(),
            log.trim()
        );
    }
    Ok(unsafe { OwnedFd::from_raw_fd(fd) })
}

fn run_bpftestrun(prog_fd: i32, prog_dir: &Path, cli: &Cli) -> Result<()> {
    let data_in = if cli.katran_maps {
        fs::read(KATRAN_TEST_INPUT)
            .with_context(|| format!("failed to read Katran test input {KATRAN_TEST_INPUT}"))?
    } else {
        Vec::new()
    };
    fs::write(prog_dir.join(TEST_INPUT_BIN), &data_in)?;
    let live_xdp = cli.katran_maps && cli.repeat > 1;
    let mut data_out = if live_xdp {
        Vec::new()
    } else {
        let mut out = data_in.clone();
        if out.len() < 4096 {
            out.resize(4096, 0);
        }
        out
    };
    let mut opts = libbpf_sys::bpf_test_run_opts {
        sz: mem::size_of::<libbpf_sys::bpf_test_run_opts>() as libbpf_sys::size_t,
        data_in: if data_in.is_empty() {
            ptr::null()
        } else {
            data_in.as_ptr().cast()
        },
        data_out: if data_out.is_empty() {
            ptr::null_mut()
        } else {
            data_out.as_mut_ptr().cast()
        },
        data_size_in: u32::try_from(data_in.len()).context("test input is too large")?,
        data_size_out: u32::try_from(data_out.len()).context("test output is too large")?,
        repeat: i32::try_from(cli.repeat).context("repeat exceeds i32")?,
        flags: if live_xdp {
            libbpf_sys::BPF_F_TEST_XDP_LIVE_FRAMES
        } else {
            0
        },
        ..Default::default()
    };
    syscall_ok(
        unsafe { libbpf_sys::bpf_prog_test_run_opts(prog_fd, &mut opts) },
        "bpf_prog_test_run_opts",
    )?;
    let output_path = prog_dir.join(TEST_OUTPUT_BIN);
    if live_xdp {
        if output_path.exists() {
            fs::remove_file(&output_path)
                .with_context(|| format!("failed to remove {}", output_path.display()))?;
        }
    } else {
        data_out.truncate(opts.data_size_out as usize);
        fs::write(&output_path, &data_out)?;
    }
    let report = serde_json::json!({
        "retval": opts.retval,
        "duration_ns": opts.duration,
        "repeat": cli.repeat,
        "data_size_out": if live_xdp { 0 } else { opts.data_size_out },
    });
    write_json(&prog_dir.join(TEST_RUN_JSON), &report)?;
    println!("{}", serde_json::to_string(&report)?);
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

fn programs(obj: &BpfObject) -> Result<Vec<ProgramRef>> {
    let mut out = Vec::new();
    let mut prev = ptr::null_mut();
    loop {
        let prog = unsafe { libbpf_sys::bpf_object__next_program(obj.ptr, prev) };
        if prog.is_null() {
            break;
        }
        let name_ptr = unsafe { libbpf_sys::bpf_program__name(prog) };
        if name_ptr.is_null() {
            bail!("libbpf returned a null program name");
        }
        let name = unsafe { CStr::from_ptr(name_ptr) }
            .to_string_lossy()
            .into_owned();
        out.push(ProgramRef { ptr: prog, name });
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
            let info: libbpf_sys::bpf_map_info = unsafe { obj_info(fd)? };
            let name = log_buf_to_string(&info.name);
            out.push(MapRef { fd, name, info });
        }
        prev = map;
    }
    Ok(out)
}

/// Shell out to `bpftool map show -j` and `bpftool map dump -j` for each map.
/// We don't reimplement libbpf's map iteration — bpftool's JSON is exactly
/// what `bpfopt`'s downstream passes (e.g. map_inline) already consume.
fn dump_map_snapshots(
    map_ids: &[u32],
    dir: &Path,
    loaded_maps: &[MapRef],
    dump_values: bool,
) -> Result<()> {
    let unique_ids = map_ids.iter().copied().collect::<BTreeSet<_>>();
    for map_id in unique_ids {
        let id = map_id.to_string();
        bpftool_to(
            &["map", "show", "-j", "-p", "id", &id],
            &dir.join(format!("map-{map_id}.show.json")),
        )?;
        let entries = loaded_maps
            .iter()
            .find(|map| map.info.id == map_id)
            .map(|map| map.info.max_entries)
            .unwrap_or(0);
        if dump_values && entries <= MAP_DUMP_ENTRY_LIMIT {
            bpftool_to(
                &["map", "dump", "-j", "-p", "id", &id],
                &dir.join(format!("map-{map_id}.dump.json")),
            )?;
        } else if dump_values {
            let (size_bytes, limit_bytes) = loaded_maps
                .iter()
                .find(|map| map.info.id == map_id)
                .map(|map| {
                    let entry_size = u64::from(map.info.key_size) + u64::from(map.info.value_size);
                    (
                        u64::from(map.info.max_entries) * entry_size,
                        u64::from(MAP_DUMP_ENTRY_LIMIT) * entry_size,
                    )
                })
                .unwrap_or((u64::from(entries), u64::from(MAP_DUMP_ENTRY_LIMIT)));
            write_json(
                &dir.join(format!("map-{map_id}.dump.json")),
                &serde_json::json!({
                    "skipped": true,
                    "reason": "size_limit",
                    "size_bytes": size_bytes,
                    "limit_bytes": limit_bytes,
                }),
            )?;
        }
    }
    Ok(())
}

fn bpftool_to(args: &[&str], out: &Path) -> Result<()> {
    let output = Command::new("bpftool")
        .args(args)
        .output()
        .context("failed to spawn bpftool")?;
    if !output.status.success() {
        bail!(
            "bpftool {} failed: {}",
            args.join(" "),
            String::from_utf8_lossy(&output.stderr).trim()
        );
    }
    fs::write(out, &output.stdout).with_context(|| format!("write {}", out.display()))
}

fn bytecode_maps(
    insns: &[libbpf_sys::bpf_insn],
    loaded_maps: &[MapRef],
) -> Result<(Vec<u32>, Vec<i32>)> {
    let mut map_ids = Vec::new();
    let mut map_fds = Vec::new();
    let mut seen_fds = BTreeSet::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = &insns[pc];
        if !is_ldimm64(insn) {
            pc += 1;
            continue;
        }
        let src = insn.src_reg();
        let is_fd_ref = src == libbpf_sys::BPF_PSEUDO_MAP_FD as u8
            || src == libbpf_sys::BPF_PSEUDO_MAP_VALUE as u8;
        if is_fd_ref && seen_fds.insert(insn.imm) {
            let map = loaded_maps
                .iter()
                .find(|m| m.fd == insn.imm)
                .ok_or_else(|| {
                    anyhow!("bytecode references loader map fd {} at pc {pc}", insn.imm)
                })?;
            map_ids.push(map.info.id);
            map_fds.push(map.fd);
        }
        pc += 2;
    }
    Ok((map_ids, map_fds))
}

fn populate_katran_maps(maps: &[MapRef]) -> Result<()> {
    let map = |name: &str| -> Result<i32> {
        maps.iter()
            .find(|map| map.name == name)
            .map(|map| map.fd)
            .ok_or_else(|| anyhow!("--katran-maps requested but map {name:?} is absent"))
    };
    let zero = 0u32.to_ne_bytes();
    let one = 1u32.to_ne_bytes();
    let mut vip = [0u8; 20];
    vip[..4].copy_from_slice(&[10, 100, 1, 1]);
    vip[16..18].copy_from_slice(&8080u16.to_be_bytes());
    vip[18] = 6;
    let mut real_def = [0u8; 20];
    real_def[..4].copy_from_slice(&[10, 200, 0, 2]);

    map_update(map("ctl_array")?, &zero, &[0x02, 0, 0, 0, 0, 0x0b, 0, 0])?;
    map_update(map("vip_map")?, &vip, &[2, 0, 0, 0, 0, 0, 0, 0])?;
    map_update(map("reals")?, &one, &real_def)?;
    if let Some(server_id_map) = maps.iter().find(|map| map.name == "server_id_map") {
        map_update(server_id_map.fd, &zero, &zero)?;
    }
    let rings = map("ch_rings")?;
    for ring_pos in 0..KATRAN_CH_RING_SIZE {
        map_update(rings, &ring_pos.to_ne_bytes(), &one)?;
    }
    Ok(())
}

fn map_update(fd: i32, key: &[u8], value: &[u8]) -> Result<()> {
    syscall_ok(
        unsafe {
            libbpf_sys::bpf_map_update_elem(fd, key.as_ptr().cast(), value.as_ptr().cast(), 0)
        },
        "bpf_map_update_elem",
    )
}

fn rewrite_map_indices_to_fds(insns: &mut [libbpf_sys::bpf_insn], fds: &[i32]) -> Result<()> {
    let idx_form = libbpf_sys::BPF_PSEUDO_MAP_IDX as u8;
    let idx_value_form = libbpf_sys::BPF_PSEUDO_MAP_IDX_VALUE as u8;
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = &mut insns[pc];
        if !is_ldimm64(insn) {
            pc += 1;
            continue;
        }
        let src = insn.src_reg();
        if src == idx_form || src == idx_value_form {
            let idx = usize::try_from(insn.imm)
                .with_context(|| format!("negative map index at pc {pc}"))?;
            let fd = fds
                .get(idx)
                .copied()
                .ok_or_else(|| anyhow!("map index {idx} at pc {pc} has no verify map fd"))?;
            insn.imm = fd;
            insn.set_src_reg(if src == idx_form {
                libbpf_sys::BPF_PSEUDO_MAP_FD as u8
            } else {
                libbpf_sys::BPF_PSEUDO_MAP_VALUE as u8
            });
        }
        pc += 2;
    }
    Ok(())
}

fn is_ldimm64(insn: &libbpf_sys::bpf_insn) -> bool {
    insn.code == (libbpf_sys::BPF_LD | libbpf_sys::BPF_DW | libbpf_sys::BPF_IMM) as u8
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

fn join_u32_csv(values: &[u32]) -> String {
    values
        .iter()
        .map(u32::to_string)
        .collect::<Vec<_>>()
        .join(",")
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

    // reals[1] currently trips map_inline CFG lowering after the fold; keep
    // this test on the hardcoded Katran path that verifies end-to-end.
    const KATRAN_INLINE_HINTS: [&str; 4] = [
        "--inline-hint=ctl_array:!00000000",
        "--inline-hint=vip_map:!0a6401010000000000000000000000001f900600",
        "--inline-hint=ch_rings:!00000000",
        "--inline-hint=server_id_map:!00000000",
    ];
    const KATRAN_OVERLAY_MAPS: [(&str, &str); 2] = [
        ("ch_rings", "ch_rings.json"),
        ("server_id_map", "server_id_map.json"),
    ];

    /// End-to-end smoke test: for up to `SMOKE_OBJECTS` BPF objects under
    /// `corpus/build`, run `--pass noop` + verify. Skipped on non-root hosts.
    /// Must be invoked from the project root (cargo test chdirs the test to
    /// the crate dir, so we chdir back to project root first).
    const SMOKE_OBJECTS: usize = 200;

    #[test]
    fn katran_optimization_path() -> Result<()> {
        if !is_root() {
            eprintln!("skipping katran_optimization_path: not running as root");
            return Ok(());
        }
        let root = Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../..")
            .canonicalize()
            .context("resolve project root")?;
        std::env::set_current_dir(&root).context("chdir to project root")?;
        let obj = root.join("bpfopt/testobject/katran_balancer.bpf.o");
        let bpfopt = root.join(BPFOPT_BIN);
        let overlay_dir = root.join("runner/config/passes/map_inline/overlays/katran");
        let workdir = WorkDir::open(None)?;
        let map_values_dir = workdir.path.join(MAP_VALUES_DIR);
        let (_obj, prepared) = prepare_workdir(&workdir.path, &obj, true, true)?;
        for prog in &prepared {
            let metadata = read_json::<ProgramMetadata>(&prog.dir.join(METADATA_JSON))?;
            if metadata.name != "balancer_ingress" {
                continue;
            }
            canonicalize_program(prog, &bpfopt)?;
            write_katran_overlays(&map_values_dir, &overlay_dir)?;
            run_katran_map_inline(prog, &map_values_dir, &bpfopt)?;
            refresh_katran_verifier_log(prog)?;
            promote_output_to_input(prog)?;
            run_katran_bytecode_pass(prog, &bpfopt, "const_prop", true)?;
            promote_output_to_input(prog)?;
            run_katran_bytecode_pass(prog, &bpfopt, "dce", false)?;
            let fd = verify_workdir(&prog.dir, &prog.map_fds)?;
            run_bpftestrun(fd.as_raw_fd(), &prog.dir, &katran_test_cli(1))?;
            assert_katran_forwarding_output(&prog.dir)?;
            run_bpftestrun(fd.as_raw_fd(), &prog.dir, &katran_test_cli(10_000))?;
            return Ok(());
        }
        bail!("katran_balancer.bpf.o did not contain balancer_ingress")
    }

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
            let cli = Cli {
                obj: obj.clone(),
                pass: Some("noop".into()),
                bpfopt: PathBuf::from(BPFOPT_BIN),
                target: None,
                workdir: None,
                bpftestrun: false,
                katran_maps: false,
                repeat: 1,
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

    fn run_katran_bytecode_pass(
        prog: &PreparedProgram,
        bpfopt: &Path,
        pass: &str,
        needs_verifier_log: bool,
    ) -> Result<()> {
        let metadata = read_json::<ProgramMetadata>(&prog.dir.join(METADATA_JSON))?;
        let mut command = Command::new(bpfopt);
        command
            .arg("--pass")
            .arg(pass)
            .arg("--input")
            .arg(prog.dir.join(INPUT_BIN))
            .arg("--output")
            .arg(prog.dir.join(OUTPUT_BIN))
            .arg("--report")
            .arg(prog.dir.join(REPORT_JSON))
            .arg("--prog-type")
            .arg(metadata.prog_type.to_string());
        if needs_verifier_log {
            command
                .arg("--verifier-states")
                .arg(prog.dir.join(VERIFIER_LOG));
        }
        let status = command.status()?;
        if !status.success() {
            bail!("hardcoded katran {pass} exited with {status}");
        }
        Ok(())
    }

    fn refresh_katran_verifier_log(prog: &PreparedProgram) -> Result<()> {
        drop(verify_workdir_with_log_level(&prog.dir, &prog.map_fds, 2)?);
        fs::copy(prog.dir.join(VERIFY_LOG), prog.dir.join(VERIFIER_LOG))
            .with_context(|| format!("failed to promote {} to {}", VERIFY_LOG, VERIFIER_LOG))?;
        Ok(())
    }

    fn promote_output_to_input(prog: &PreparedProgram) -> Result<()> {
        fs::copy(prog.dir.join(OUTPUT_BIN), prog.dir.join(INPUT_BIN)).with_context(|| {
            format!(
                "failed to promote {} to {} for {}",
                OUTPUT_BIN,
                INPUT_BIN,
                prog.dir.display()
            )
        })?;
        Ok(())
    }

    fn write_katran_overlays(map_values_dir: &Path, overlay_dir: &Path) -> Result<()> {
        let mut overlays = serde_json::Map::new();
        for (map_name, overlay_file) in KATRAN_OVERLAY_MAPS {
            let map_id = katran_map_id(map_values_dir, map_name)?;
            if !map_dump_was_skipped(map_values_dir, map_id)? {
                continue;
            }
            let overlay: serde_json::Value = read_json(&overlay_dir.join(overlay_file))?;
            overlays.insert(map_id.to_string(), overlay);
        }
        write_json(&map_values_dir.join("overlays.json"), &overlays)
    }

    fn map_dump_was_skipped(map_values_dir: &Path, map_id: u32) -> Result<bool> {
        let dump: serde_json::Value =
            read_json(&map_values_dir.join(format!("map-{map_id}.dump.json")))?;
        Ok(dump.get("skipped").and_then(|value| value.as_bool()) == Some(true))
    }

    fn katran_map_id(map_values_dir: &Path, expected_name: &str) -> Result<u32> {
        for entry in fs::read_dir(map_values_dir)? {
            let path = entry?.path();
            let Some(file_name) = path.file_name().and_then(|name| name.to_str()) else {
                continue;
            };
            if !file_name.ends_with(".show.json") {
                continue;
            }
            let show: serde_json::Value = read_json(&path)?;
            if show.get("name").and_then(|name| name.as_str()) == Some(expected_name) {
                return show
                    .get("id")
                    .and_then(|id| id.as_u64())
                    .and_then(|id| u32::try_from(id).ok())
                    .ok_or_else(|| anyhow!("{} has no u32 id", path.display()));
            }
        }
        bail!("katran map {expected_name:?} missing from map snapshot")
    }

    fn run_katran_map_inline(
        prog: &PreparedProgram,
        map_values_dir: &Path,
        bpfopt: &Path,
    ) -> Result<()> {
        let metadata = read_json::<ProgramMetadata>(&prog.dir.join(METADATA_JSON))?;
        let status = Command::new(bpfopt)
            .arg("--pass")
            .arg("map_inline")
            .arg("--input")
            .arg(prog.dir.join(INPUT_BIN))
            .arg("--output")
            .arg(prog.dir.join(OUTPUT_BIN))
            .arg("--report")
            .arg(prog.dir.join(REPORT_JSON))
            .arg("--prog-type")
            .arg(metadata.prog_type.to_string())
            .arg("--verifier-states")
            .arg(prog.dir.join(VERIFIER_LOG))
            .arg("--")
            .arg("--map-values")
            .arg(map_values_dir)
            .arg("--map-ids")
            .arg(join_u32_csv(&prog.map_ids))
            .args(KATRAN_INLINE_HINTS)
            .status()?;
        if !status.success() {
            bail!("hardcoded katran map_inline exited with {status}");
        }
        Ok(())
    }

    fn katran_test_cli(repeat: u32) -> Cli {
        Cli {
            obj: PathBuf::from("bpfopt/testobject/katran_balancer.bpf.o"),
            pass: Some("map_inline".into()),
            bpfopt: PathBuf::from(BPFOPT_BIN),
            target: None,
            workdir: None,
            bpftestrun: true,
            katran_maps: true,
            repeat,
        }
    }

    fn assert_katran_forwarding_output(prog_dir: &Path) -> Result<()> {
        const XDP_TX: i64 = 3;

        let report: serde_json::Value = read_json(&prog_dir.join(TEST_RUN_JSON))?;
        let retval = report
            .get("retval")
            .and_then(|value| value.as_i64())
            .ok_or_else(|| anyhow!("{} missing integer retval", TEST_RUN_JSON))?;
        if retval != XDP_TX {
            bail!("Katran semantic test returned {retval}, expected XDP_TX({XDP_TX})");
        }

        let output = fs::read(prog_dir.join(TEST_OUTPUT_BIN)).with_context(|| {
            format!(
                "failed to read {}",
                prog_dir.join(TEST_OUTPUT_BIN).display()
            )
        })?;
        let data_size_out = report
            .get("data_size_out")
            .and_then(|value| value.as_u64())
            .and_then(|value| usize::try_from(value).ok())
            .ok_or_else(|| anyhow!("{} missing integer data_size_out", TEST_RUN_JSON))?;
        if data_size_out != output.len() {
            bail!(
                "Katran semantic output size mismatch: report says {data_size_out}, file has {}",
                output.len()
            );
        }

        let input = fs::read(KATRAN_TEST_INPUT)
            .with_context(|| format!("failed to read Katran test input {KATRAN_TEST_INPUT}"))?;
        assert_katran_ipip_packet(&input, &output)
    }

    fn assert_katran_ipip_packet(input: &[u8], output: &[u8]) -> Result<()> {
        const ETH_HLEN: usize = 14;
        const IPV4_MIN_HLEN: usize = 20;
        const IPPROTO_IPIP: u8 = 4;

        if input.len() < ETH_HLEN + IPV4_MIN_HLEN {
            bail!(
                "Katran input is too short for Ethernet + IPv4: {}",
                input.len()
            );
        }
        if output.len() < ETH_HLEN + IPV4_MIN_HLEN {
            bail!(
                "Katran output is too short for Ethernet + outer IPv4: {}",
                output.len()
            );
        }
        if output[12..14] != [0x08, 0x00] {
            bail!("Katran output is not IPv4 Ethernet");
        }
        let version = output[ETH_HLEN] >> 4;
        let outer_ihl = usize::from(output[ETH_HLEN] & 0x0f) * 4;
        if version != 4 || outer_ihl < IPV4_MIN_HLEN {
            bail!("Katran output has invalid outer IPv4 header");
        }
        if output[ETH_HLEN + 9] != IPPROTO_IPIP {
            bail!(
                "Katran output outer protocol is {}, expected IPIP({IPPROTO_IPIP})",
                output[ETH_HLEN + 9]
            );
        }

        let inner = ETH_HLEN + outer_ihl;
        let expected_len = inner + input.len() - ETH_HLEN;
        if output.len() != expected_len {
            bail!(
                "Katran IPIP output length is {}, expected {expected_len}",
                output.len()
            );
        }
        if output[inner..] != input[ETH_HLEN..] {
            bail!("Katran IPIP inner IPv4 packet does not match corpus input");
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
}
