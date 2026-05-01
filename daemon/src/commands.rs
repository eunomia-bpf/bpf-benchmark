// SPDX-License-Identifier: MIT
//! Socket command helpers.
//!
//! `bpfopt` and `bpfprof` remain CLI tools. The daemon owns live discovery,
//! short-lived fd_array construction, automatic side-input capture,
//! and final `BPF_PROG_REJIT`.

use std::collections::{BTreeMap, HashMap};
use std::fs::{self, OpenOptions};
use std::io::Write;
use std::os::fd::{AsFd, AsRawFd, OwnedFd};
use std::path::{Path, PathBuf};
use std::process::{Command, Stdio};
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::{Arc, Mutex};
use std::thread;
use std::time::{Duration, Instant};

use anyhow::{anyhow, bail, Context, Result};
use serde::{Deserialize, Serialize};

use crate::bpf;
use crate::dry_run;
use crate::invalidation::{BpfMapValueReader, MapInvalidationTracker};

static NEXT_WORKDIR_ID: AtomicU64 = AtomicU64::new(0);
const FAILURE_ROOT_ENV: &str = "BPFREJIT_DAEMON_FAILURE_ROOT";
const KEEP_ALL_WORKDIRS_ENV: &str = "BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS";
const DEFAULT_FAILURE_ROOT_NAME: &str = "bpfrejit-failures";
const DEBUG_WORKDIR_ROOT_NAME: &str = "workdirs";
const MAP_VALUES_FILE: &str = "map-values.json";
const VERIFIER_STATES_FILE: &str = "verifier-states.json";
const DEFAULT_CLI_STAGE_TIMEOUT: Duration = Duration::from_secs(5);
const OPTIMIZE_CLI_STAGE_TIMEOUT: Duration = Duration::from_secs(60);
const CLI_STAGE_POLL_INTERVAL: Duration = Duration::from_millis(100);
const REJIT_LOG_BUF_SIZE: usize = 16 * 1024 * 1024;
const BPF_LD_IMM64: u8 = (kernel_sys::BPF_LD | kernel_sys::BPF_DW | kernel_sys::BPF_IMM) as u8;
const BPF_PSEUDO_MAP_FD: u8 = kernel_sys::BPF_PSEUDO_MAP_FD as u8;
const BPF_PSEUDO_MAP_VALUE: u8 = kernel_sys::BPF_PSEUDO_MAP_VALUE as u8;
const BPF_PSEUDO_MAP_IDX: u8 = kernel_sys::BPF_PSEUDO_MAP_IDX as u8;
const BPF_PSEUDO_MAP_IDX_VALUE: u8 = kernel_sys::BPF_PSEUDO_MAP_IDX_VALUE as u8;

#[derive(Clone, Debug)]
pub(crate) struct CliConfig {
    cli_dir: Option<PathBuf>,
}

impl CliConfig {
    pub(crate) fn from_env() -> Self {
        Self {
            cli_dir: std::env::var_os("BPFREJIT_CLI_DIR").map(PathBuf::from),
        }
    }

    fn command(&self, name: &str) -> Command {
        let path = self
            .cli_dir
            .as_ref()
            .map(|dir| dir.join(name))
            .unwrap_or_else(|| PathBuf::from(name));
        Command::new(path)
    }
}

#[derive(Debug)]
struct WorkDir {
    path: PathBuf,
}

impl WorkDir {
    fn new(prefix: &str) -> Result<Self> {
        let base = std::env::temp_dir();
        let pid = std::process::id();
        for _ in 0..100 {
            let id = NEXT_WORKDIR_ID.fetch_add(1, Ordering::Relaxed);
            let path = base.join(format!("{prefix}-{pid}-{id}"));
            match fs::create_dir(&path) {
                Ok(()) => return Ok(Self { path }),
                Err(err) if err.kind() == std::io::ErrorKind::AlreadyExists => continue,
                Err(err) => return Err(err).with_context(|| format!("create {}", path.display())),
            }
        }
        bail!("failed to allocate temporary work directory");
    }

    fn path(&self) -> &Path {
        &self.path
    }
}

impl Drop for WorkDir {
    fn drop(&mut self) {
        if let Err(err) = fs::remove_dir_all(&self.path) {
            eprintln!(
                "daemon: failed to remove work directory {}: {err}",
                self.path.display()
            );
        }
    }
}

#[derive(Debug)]
struct FailureExportConfig {
    root: PathBuf,
}

impl FailureExportConfig {
    fn from_env() -> Result<Self> {
        let root = match std::env::var_os(FAILURE_ROOT_ENV) {
            Some(raw) => {
                if raw.is_empty() {
                    bail!("{FAILURE_ROOT_ENV} must not be empty");
                }
                PathBuf::from(raw)
            }
            None => std::env::current_dir()
                .context("resolve current directory for default failure export root")?
                .join(DEFAULT_FAILURE_ROOT_NAME),
        };
        Ok(Self { root })
    }

    fn validate_configured_root(&self) -> Result<()> {
        ensure_writable_dir(&self.root, "failure export root")
            .with_context(|| format!("{FAILURE_ROOT_ENV}={}", self.root.display()))
    }

    fn resolve_failure_root(&self) -> Result<PathBuf> {
        self.validate_configured_root()?;
        Ok(self.root.clone())
    }

    fn resolve_debug_workdir_root(&self) -> Result<PathBuf> {
        self.validate_configured_root()?;
        Ok(self.root.join(DEBUG_WORKDIR_ROOT_NAME))
    }
}

pub(crate) fn validate_failure_export_root_from_env() -> Result<()> {
    keep_all_workdirs_enabled_from_env()?;
    FailureExportConfig::from_env()?.validate_configured_root()
}

fn ensure_writable_dir(path: &Path, description: &str) -> Result<()> {
    fs::create_dir_all(path).with_context(|| format!("create {description} {}", path.display()))?;
    let metadata =
        fs::metadata(path).with_context(|| format!("stat {description} {}", path.display()))?;
    if !metadata.is_dir() {
        bail!("{description} {} is not a directory", path.display());
    }
    let probe = path.join(format!(
        ".bpfrejit-write-probe-{}-{}",
        std::process::id(),
        NEXT_WORKDIR_ID.fetch_add(1, Ordering::Relaxed)
    ));
    let mut file = OpenOptions::new()
        .write(true)
        .create_new(true)
        .open(&probe)
        .with_context(|| format!("create write probe {}", probe.display()))?;
    file.write_all(b"probe")
        .with_context(|| format!("write probe {}", probe.display()))?;
    drop(file);
    fs::remove_file(&probe).with_context(|| format!("remove write probe {}", probe.display()))?;
    Ok(())
}

fn preserve_failure_workdir(workdir: &WorkDir, prog_id: u32) -> Result<PathBuf> {
    let config = FailureExportConfig::from_env()?;
    let failure_root = config.resolve_failure_root()?;
    ensure_writable_dir(&failure_root, "failure directory")
        .with_context(|| format!("prepare failure directory {}", failure_root.display()))?;
    let failure_dir = failure_root.join(prog_id.to_string());
    fs::create_dir(&failure_dir)
        .with_context(|| format!("create failure workdir {}", failure_dir.display()))?;
    copy_dir_contents(workdir.path(), &failure_dir)?;
    normalize_failure_artifacts(&failure_dir)?;
    Ok(failure_dir)
}

fn preserve_debug_workdir_if_requested(workdir: &WorkDir, prog_id: u32) -> Result<Option<PathBuf>> {
    if !keep_all_workdirs_enabled_from_env()? {
        return Ok(None);
    }
    let config = FailureExportConfig::from_env()?;
    let debug_root = config.resolve_debug_workdir_root()?;
    ensure_writable_dir(&debug_root, "debug workdir directory")
        .with_context(|| format!("prepare debug workdir directory {}", debug_root.display()))?;
    let debug_dir = debug_root.join(prog_id.to_string());
    fs::create_dir(&debug_dir)
        .with_context(|| format!("create debug workdir {}", debug_dir.display()))?;
    copy_dir_contents(workdir.path(), &debug_dir)?;
    Ok(Some(debug_dir))
}

fn keep_all_workdirs_enabled_from_env() -> Result<bool> {
    match std::env::var(KEEP_ALL_WORKDIRS_ENV) {
        Ok(value) if value == "1" => Ok(true),
        Ok(value) => bail!("{KEEP_ALL_WORKDIRS_ENV} must be 1 when set, got {value:?}"),
        Err(std::env::VarError::NotPresent) => Ok(false),
        Err(err) => Err(err).with_context(|| format!("read {KEEP_ALL_WORKDIRS_ENV}")),
    }
}

fn copy_dir_contents(src: &Path, dst: &Path) -> Result<()> {
    for entry in fs::read_dir(src).with_context(|| format!("read {}", src.display()))? {
        let entry = entry?;
        let source = entry.path();
        let target = dst.join(entry.file_name());
        let file_type = entry.file_type()?;
        if file_type.is_dir() {
            fs::create_dir(&target).with_context(|| format!("create {}", target.display()))?;
            copy_dir_contents(&source, &target)?;
        } else if file_type.is_file() {
            fs::copy(&source, &target)
                .with_context(|| format!("copy {} to {}", source.display(), target.display()))?;
        } else {
            bail!(
                "cannot preserve non-regular workdir entry {}",
                source.display()
            );
        }
    }
    Ok(())
}

fn normalize_failure_artifacts(failure_dir: &Path) -> Result<()> {
    copy_alias_if_present(&failure_dir.join("prog.bin"), &failure_dir.join("prog.bpf"))?;
    require_regular_file(&failure_dir.join("prog.bpf"), "failure prog.bpf")?;
    require_regular_file(&failure_dir.join("info.json"), "failure info.json")?;
    let verifier_log = failure_dir.join("verifier.log");
    match fs::metadata(&verifier_log) {
        Ok(_) => require_nonempty_file(&verifier_log, "failure verifier.log")?,
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => {}
        Err(err) => return Err(err).with_context(|| format!("stat {}", verifier_log.display())),
    }
    Ok(())
}

fn copy_alias_if_present(source: &Path, target: &Path) -> Result<()> {
    match fs::metadata(source) {
        Ok(metadata) => {
            if !metadata.is_file() {
                bail!(
                    "failure artifact {} is not a regular file",
                    source.display()
                );
            }
            fs::copy(source, target)
                .with_context(|| format!("copy {} to {}", source.display(), target.display()))?;
            Ok(())
        }
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => Ok(()),
        Err(err) => Err(err).with_context(|| format!("stat {}", source.display())),
    }
}

fn require_regular_file(path: &Path, description: &str) -> Result<()> {
    match fs::metadata(path) {
        Ok(metadata) => {
            if !metadata.is_file() {
                bail!("{description} {} is not a regular file", path.display());
            }
            Ok(())
        }
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => {
            bail!("{description} {} is missing", path.display())
        }
        Err(err) => Err(err).with_context(|| format!("stat {}", path.display())),
    }
}

fn require_nonempty_file(path: &Path, description: &str) -> Result<()> {
    require_regular_file(path, description)?;
    let metadata = fs::metadata(path).with_context(|| format!("stat {}", path.display()))?;
    if metadata.len() == 0 {
        bail!("{description} {} is empty", path.display());
    }
    Ok(())
}

#[derive(Debug)]
pub(crate) struct ProfileSession {
    child: std::process::Child,
    output_dir: WorkDir,
    duration_ms: u64,
}

#[derive(Debug)]
pub(crate) struct FrozenProfile {
    output_dir: WorkDir,
    duration_ms: u64,
    programs_profiled: usize,
}

impl FrozenProfile {
    pub(crate) fn profile_path_for(&self, prog_id: u32) -> Option<PathBuf> {
        let path = self.output_dir.path().join(format!("{prog_id}.json"));
        path.exists().then_some(path)
    }

    pub(crate) fn duration_ms(&self) -> u64 {
        self.duration_ms
    }

    pub(crate) fn programs_profiled(&self) -> usize {
        self.programs_profiled
    }
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct OptimizeOneResult {
    pub status: String,
    pub prog_id: u32,
    pub changed: bool,
    pub passes_applied: Vec<String>,
    pub program: ProgramInfo,
    pub summary: OptimizeSummary,
    pub passes: Vec<PassDetail>,
    #[serde(skip_serializing_if = "Vec::is_empty", default)]
    pub inlined_map_entries: Vec<InlinedMapEntry>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub error_message: Option<String>,
}

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
pub(crate) struct InlinedMapEntry {
    pub map_id: u32,
    pub key_hex: String,
    pub value_hex: String,
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct ProgramInfo {
    pub prog_id: u32,
    pub prog_name: String,
    pub prog_type: u32,
    pub orig_insn_count: usize,
    pub final_insn_count: usize,
    pub insn_delta: i64,
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct OptimizeSummary {
    pub applied: bool,
    pub total_sites_applied: usize,
    pub passes_executed: usize,
    pub passes_changed: usize,
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct PassDetail {
    #[serde(rename = "pass")]
    pub pass_name: String,
    pub changed: bool,
    pub sites_applied: usize,
    pub insns_before: usize,
    pub insns_after: usize,
    pub insn_delta: i64,
}

struct ApplyOneRequest<'a> {
    prog_id: u32,
    config: &'a CliConfig,
    enabled_passes: Option<&'a [String]>,
    profile_path: Option<&'a Path>,
    invalidation_tracker: Option<&'a SharedInvalidationTracker>,
    force_rejit: bool,
}

pub(crate) type SharedInvalidationTracker = Arc<Mutex<MapInvalidationTracker<BpfMapValueReader>>>;

trait KernelOps {
    fn snapshot_program(&mut self, prog_id: u32) -> Result<bpfget::ProgramSnapshot>;
    fn probe_target(&mut self) -> Result<bpfget::TargetJson>;
    fn verifier_states(
        &mut self,
        snapshot: &bpfget::ProgramSnapshot,
        insns: &[kernel_sys::bpf_insn],
        fd_array: &[i32],
    ) -> Result<kernel_sys::VerifierStatesJson>;
    fn rejit(
        &mut self,
        prog_id: u32,
        snapshot: &bpfget::ProgramSnapshot,
        insns: &[kernel_sys::bpf_insn],
        fd_array: &[i32],
        verifier_log_path: &Path,
    ) -> Result<RejitSummary>;
}

struct LiveKernelOps;

impl KernelOps for LiveKernelOps {
    fn snapshot_program(&mut self, prog_id: u32) -> Result<bpfget::ProgramSnapshot> {
        bpfget::snapshot_program(prog_id)
    }

    fn probe_target(&mut self) -> Result<bpfget::TargetJson> {
        bpfget::probe_target_json()
    }

    fn verifier_states(
        &mut self,
        snapshot: &bpfget::ProgramSnapshot,
        insns: &[kernel_sys::bpf_insn],
        fd_array: &[i32],
    ) -> Result<kernel_sys::VerifierStatesJson> {
        dry_run::capture_verifier_states(snapshot, insns, fd_array)
    }

    fn rejit(
        &mut self,
        prog_id: u32,
        snapshot: &bpfget::ProgramSnapshot,
        insns: &[kernel_sys::bpf_insn],
        fd_array: &[i32],
        verifier_log_path: &Path,
    ) -> Result<RejitSummary> {
        rejit_program(prog_id, snapshot, insns, fd_array, verifier_log_path)
    }
}

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
struct RejitSummary {
    status: String,
    prog_id: u32,
    insn_count_before: usize,
    insn_count_after: usize,
}

fn rejit_program(
    prog_id: u32,
    snapshot: &bpfget::ProgramSnapshot,
    insns: &[kernel_sys::bpf_insn],
    fd_array: &[i32],
    verifier_log_path: &Path,
) -> Result<RejitSummary> {
    let prog_fd = kernel_sys::prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open BPF program id {prog_id} for BPF_PROG_REJIT"))?;
    let mut log_buf = vec![0u8; REJIT_LOG_BUF_SIZE];
    if let Err(err) = kernel_sys::prog_rejit(prog_fd.as_fd(), insns, fd_array, Some(&mut log_buf)) {
        let log = c_log_string(&log_buf);
        if !log.is_empty() {
            fs::write(verifier_log_path, log)
                .with_context(|| format!("write {}", verifier_log_path.display()))?;
        }
        return Err(err).context("kernel rejected BPF_PROG_REJIT");
    }
    Ok(RejitSummary {
        status: "ok".to_string(),
        prog_id,
        insn_count_before: snapshot.insns.len(),
        insn_count_after: insns.len(),
    })
}

fn c_log_string(buf: &[u8]) -> String {
    let end = buf.iter().position(|&b| b == 0).unwrap_or(buf.len());
    String::from_utf8_lossy(&buf[..end]).trim_end().to_string()
}

type ProgInfoJson = bpfget::ProgramInfo;
type MapInfoJson = bpfget::MapInfo;

#[derive(Clone, Debug, Deserialize)]
struct BpfoptPassReport {
    pass: String,
    changed: bool,
    sites_applied: usize,
    insn_count_before: usize,
    insn_count_after: usize,
    insn_delta: isize,
    #[serde(default)]
    map_inline_records: Vec<BpfoptMapInlineRecord>,
}

#[derive(Clone, Debug, Deserialize)]
struct BpfoptOptimizeReport {
    passes: Vec<BpfoptPassReport>,
}

#[derive(Clone, Debug, Deserialize)]
struct BpfoptMapInlineRecord {
    map_id: u32,
    key_hex: String,
    #[serde(alias = "expected_value_hex")]
    value_hex: String,
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct MapInlineRecord {
    map_id: u32,
    key: Vec<u8>,
    expected_value: Vec<u8>,
}

#[derive(Debug, Serialize)]
struct MapValuesJson {
    maps: Vec<MapValuesMapJson>,
}

#[derive(Debug, Serialize)]
struct MapValuesMapJson {
    map_id: u32,
    map_type: u32,
    key_size: u32,
    value_size: u32,
    max_entries: u32,
    frozen: bool,
    entries: Vec<MapValuesEntryJson>,
}

#[derive(Debug, Serialize)]
struct MapValuesEntryJson {
    key: String,
    value: Option<String>,
}

#[derive(Debug, Deserialize)]
struct TargetJson {
    #[serde(default)]
    kinsns: HashMap<String, TargetKinsnJson>,
}

#[derive(Clone, Debug, Deserialize, Serialize)]
struct TargetKinsnJson {
    btf_func_id: i32,
    #[serde(default)]
    btf_id: u32,
    #[serde(default)]
    btf_obj_id: u32,
}

pub(crate) fn new_invalidation_tracker() -> SharedInvalidationTracker {
    Arc::new(Mutex::new(MapInvalidationTracker::new(BpfMapValueReader)))
}

fn hex_bytes(bytes: &[u8]) -> String {
    const HEX: &[u8; 16] = b"0123456789abcdef";
    let mut out = String::with_capacity(bytes.len() * 2);
    for byte in bytes {
        out.push(HEX[(byte >> 4) as usize] as char);
        out.push(HEX[(byte & 0x0f) as usize] as char);
    }
    out
}

fn decode_hex(input: &str) -> Result<Vec<u8>> {
    let mut hex = input
        .chars()
        .filter(|ch| !ch.is_ascii_whitespace())
        .collect::<String>();
    if let Some(stripped) = hex.strip_prefix("0x") {
        hex = stripped.to_string();
    }
    if !hex.len().is_multiple_of(2) {
        bail!("hex string has odd length");
    }

    let bytes = hex.as_bytes();
    let mut out = Vec::with_capacity(bytes.len() / 2);
    for pair in bytes.chunks_exact(2) {
        let hi = hex_nibble(pair[0]).ok_or_else(|| anyhow!("invalid hex digit"))?;
        let lo = hex_nibble(pair[1]).ok_or_else(|| anyhow!("invalid hex digit"))?;
        out.push((hi << 4) | lo);
    }
    Ok(out)
}

fn hex_nibble(byte: u8) -> Option<u8> {
    match byte {
        b'0'..=b'9' => Some(byte - b'0'),
        b'a'..=b'f' => Some(byte - b'a' + 10),
        b'A'..=b'F' => Some(byte - b'A' + 10),
        _ => None,
    }
}

fn collect_map_inline_records(report: &BpfoptOptimizeReport) -> Result<Vec<MapInlineRecord>> {
    let mut records = Vec::new();
    for pass in &report.passes {
        if canonical_pass(&pass.pass) != "map_inline" || !pass.changed {
            continue;
        }
        for record in &pass.map_inline_records {
            records.push(MapInlineRecord {
                map_id: record.map_id,
                key: decode_hex(&record.key_hex)
                    .with_context(|| format!("decode map_inline key for map {}", record.map_id))?,
                expected_value: decode_hex(&record.value_hex).with_context(|| {
                    format!("decode map_inline value for map {}", record.map_id)
                })?,
            });
        }
    }
    Ok(records)
}

fn collect_inlined_map_entries(map_inline_records: &[MapInlineRecord]) -> Vec<InlinedMapEntry> {
    let mut deduped: BTreeMap<(u32, String), String> = BTreeMap::new();
    for record in map_inline_records {
        deduped.insert(
            (record.map_id, hex_bytes(&record.key)),
            hex_bytes(&record.expected_value),
        );
    }

    deduped
        .into_iter()
        .map(|((map_id, key_hex), value_hex)| InlinedMapEntry {
            map_id,
            key_hex,
            value_hex,
        })
        .collect()
}

fn record_map_inline_records<A, F>(
    tracker: &mut MapInvalidationTracker<A>,
    prog_id: u32,
    map_inline_records: &[MapInlineRecord],
    mut open_map_fd: F,
) -> Result<()>
where
    F: FnMut(u32) -> Result<OwnedFd>,
{
    let mut raw_fds_by_map_id: HashMap<u32, u32> = HashMap::new();
    let mut owned_fds = Vec::new();
    let mut tracked_sites = Vec::new();
    for record in map_inline_records {
        let map_fd = match raw_fds_by_map_id.get(&record.map_id) {
            Some(&map_fd) => map_fd,
            None => {
                let fd = open_map_fd(record.map_id)?;
                let raw_fd = fd.as_raw_fd() as u32;
                raw_fds_by_map_id.insert(record.map_id, raw_fd);
                owned_fds.push(fd);
                raw_fd
            }
        };

        tracked_sites.push((map_fd, record.key.clone(), record.expected_value.clone()));
    }

    tracker.remove_prog(prog_id);
    for fd in owned_fds {
        tracker.remember_map_fd(fd);
    }
    for (map_fd, key, expected_value) in tracked_sites {
        tracker.record_inline_site(prog_id, map_fd, key, expected_value);
    }

    Ok(())
}

fn refresh_invalidation_tracking<F>(
    tracker: Option<&SharedInvalidationTracker>,
    prog_id: u32,
    map_inline_records: &[MapInlineRecord],
    open_map_fd: F,
) -> Result<()>
where
    F: FnMut(u32) -> Result<OwnedFd>,
{
    let Some(tracker) = tracker else {
        return Ok(());
    };

    let mut tracker = tracker
        .lock()
        .map_err(|_| anyhow!("invalidation tracker lock poisoned"))?;
    record_map_inline_records(&mut tracker, prog_id, map_inline_records, open_map_fd)
}

fn live_bpf_map_lookup(_map: &MapInfoJson, fd: i32, key: &[u8]) -> Result<Option<Vec<u8>>> {
    let info = bpf::bpf_map_get_info(fd)?;
    let value_size = bpf::bpf_map_lookup_value_size(&info)?;
    bpf::bpf_map_lookup_elem_optional(fd, key, value_size)
}

fn live_bpf_map_keys(map: &MapInfoJson, fd: i32) -> Result<Vec<Vec<u8>>> {
    if !is_map_inlineable_map_type(map.map_type) {
        return Ok(Vec::new());
    }
    let key_size = map.key_size as usize;
    if key_size == 0 {
        bail!("map {} has zero key_size", map.map_id);
    }
    if map.max_entries == 0 {
        bail!("map {} has zero max_entries", map.map_id);
    }

    let mut keys = Vec::new();
    let mut previous_key = None;
    loop {
        let Some(key) = bpf::bpf_map_get_next_key(fd, previous_key.as_deref(), key_size)? else {
            break;
        };
        previous_key = Some(key.clone());
        keys.push(key);
        if keys.len() > map.max_entries as usize {
            bail!(
                "BPF_MAP_GET_NEXT_KEY for map {} returned more than max_entries={}",
                map.map_id,
                map.max_entries
            );
        }
    }
    Ok(keys)
}

pub(crate) fn start_profile(config: &CliConfig, duration_ms: u64) -> Result<ProfileSession> {
    let output_dir = WorkDir::new("bpfrejit-daemon-profile")?;
    let mut child = config
        .command("bpfprof")
        .arg("--all")
        .arg("--per-site")
        .arg("--duration")
        .arg(format!("{duration_ms}ms"))
        .arg("--output-dir")
        .arg(output_dir.path())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
        .context("spawn bpfprof --all --per-site")?;

    if let Some(status) = child.try_wait().context("poll bpfprof after spawn")? {
        let output = child.wait_with_output().context("collect bpfprof output")?;
        bail!(
            "bpfprof exited during profile-start with status {}: {}",
            status,
            stderr_summary(&output)
        );
    }

    Ok(ProfileSession {
        child,
        output_dir,
        duration_ms,
    })
}

pub(crate) fn stop_profile(session: ProfileSession) -> Result<FrozenProfile> {
    let output = session
        .child
        .wait_with_output()
        .context("wait for bpfprof profile session")?;
    if !output.status.success() {
        bail!(
            "bpfprof profile session failed with status {}: {}",
            output.status,
            stderr_summary(&output)
        );
    }
    let programs_profiled = count_json_files(session.output_dir.path())?;
    Ok(FrozenProfile {
        output_dir: session.output_dir,
        duration_ms: session.duration_ms,
        programs_profiled,
    })
}

pub(crate) fn try_apply_one(
    prog_id: u32,
    config: &CliConfig,
    enabled_passes: Option<&[String]>,
    profile_path: Option<&Path>,
    invalidation_tracker: Option<&SharedInvalidationTracker>,
) -> Result<OptimizeOneResult> {
    let mut kernel = LiveKernelOps;
    try_apply_one_with_map_access(
        ApplyOneRequest {
            prog_id,
            config,
            enabled_passes,
            profile_path,
            invalidation_tracker,
            force_rejit: false,
        },
        &mut kernel,
        bpf::bpf_map_get_fd_by_id,
        live_bpf_map_lookup,
        live_bpf_map_keys,
    )
}

pub(crate) fn try_reapply_one(
    prog_id: u32,
    config: &CliConfig,
    enabled_passes: Option<&[String]>,
    profile_path: Option<&Path>,
    invalidation_tracker: Option<&SharedInvalidationTracker>,
) -> Result<OptimizeOneResult> {
    let mut kernel = LiveKernelOps;
    try_apply_one_with_map_access(
        ApplyOneRequest {
            prog_id,
            config,
            enabled_passes,
            profile_path,
            invalidation_tracker,
            force_rejit: true,
        },
        &mut kernel,
        bpf::bpf_map_get_fd_by_id,
        live_bpf_map_lookup,
        live_bpf_map_keys,
    )
}

fn try_apply_one_with_map_access<F, G, H>(
    request: ApplyOneRequest<'_>,
    kernel: &mut dyn KernelOps,
    mut open_map_fd: F,
    mut lookup_map_value: G,
    mut scan_map_keys: H,
) -> Result<OptimizeOneResult>
where
    F: FnMut(u32) -> Result<OwnedFd>,
    G: FnMut(&MapInfoJson, i32, &[u8]) -> Result<Option<Vec<u8>>>,
    H: FnMut(&MapInfoJson, i32) -> Result<Vec<Vec<u8>>>,
{
    let ApplyOneRequest {
        prog_id,
        config,
        enabled_passes,
        profile_path,
        invalidation_tracker,
        force_rejit,
    } = request;
    let requested_passes =
        enabled_passes.ok_or_else(|| anyhow!("enabled_passes is required for bpfopt optimize"))?;
    if requested_passes.is_empty() {
        bail!("enabled_passes must include at least one pass for bpfopt optimize");
    }
    let workdir = WorkDir::new("bpfrejit-daemon-optimize")?;
    let prog_bin = workdir.path().join("prog.bin");
    let info_json = workdir.path().join("info.json");
    let target_json = workdir.path().join("target.json");
    let verifier_states_json = workdir.path().join(VERIFIER_STATES_FILE);
    let map_values_json = workdir.path().join(MAP_VALUES_FILE);
    let opt_bin = workdir.path().join("opt.bin");
    let report_json = workdir.path().join("bpfopt_report.json");
    let rejit_summary_json = workdir.path().join("bpfrejit_summary.json");

    let result = (|| -> Result<OptimizeOneResult> {
        let snapshot = kernel
            .snapshot_program(prog_id)
            .with_context(|| format!("snapshot live BPF program {prog_id}"))?;
        let prog_info = snapshot.info.clone();
        let orig_bytes = bpfget::encode_insns(&snapshot.insns);
        fs::write(&prog_bin, &orig_bytes)
            .with_context(|| format!("write {}", prog_bin.display()))?;
        write_json_file(&info_json, &prog_info)?;
        let orig_insn_count = insn_count_from_bytes(&orig_bytes, "prog.bin")?;
        let map_fd_indices = pseudo_map_fd_indices(&snapshot.insns, &prog_info.map_ids)
            .with_context(|| format!("resolve pseudo-map fd bindings for prog {prog_id}"))?;
        if prog_info.id != prog_id {
            bail!(
                "program snapshot returned id {}, expected {prog_id}",
                prog_info.id
            );
        }
        if prog_info.insn_cnt as usize != orig_insn_count {
            bail!(
                "program snapshot returned insn_cnt {}, but prog.bin contains {} instructions",
                prog_info.insn_cnt,
                orig_insn_count
            );
        }
        let mut side_inputs = Vec::<(String, PathBuf)>::new();
        let wants_verifier_states = needs_verifier_states(requested_passes);
        let wants_map_inline = requested_passes
            .iter()
            .any(|pass| canonical_pass(pass) == "map_inline");

        if wants_map_inline {
            write_live_map_values(
                &snapshot.maps,
                &map_values_json,
                &mut open_map_fd,
                &mut lookup_map_value,
                &mut scan_map_keys,
            )
            .with_context(|| format!("build live map value snapshot for prog {prog_id}"))?;
        }

        let mut target = None;
        if needs_target(requested_passes) {
            let probed = kernel.probe_target().with_context(|| {
                format!(
                    "probe target kinsns failed for requested passes {}",
                    join_pass_csv(requested_passes)
                )
            })?;
            write_json_file(&target_json, &probed)?;
            let missing_kinsns = missing_target_kinsns(&target_json, requested_passes)?;
            if !missing_kinsns.is_empty() {
                bail!(
                    "target probing did not expose kinsns required by requested passes {}: {}",
                    join_pass_csv(requested_passes),
                    missing_kinsns.join(", ")
                );
            }
            target = Some(target_json.clone());
        }
        let fd_array = build_rejit_fd_array(
            &snapshot.info.map_ids,
            target.as_deref(),
            requested_passes,
            &mut open_map_fd,
        )
        .with_context(|| format!("build fd_array for prog {prog_id}"))?;
        if let Some(target_json) = target.as_ref() {
            side_inputs.push(("--target".to_string(), target_json.clone()));
        }

        if wants_verifier_states {
            write_original_verifier_states(
                kernel,
                &snapshot,
                &map_fd_indices,
                fd_array.as_slice(),
                &verifier_states_json,
            )
            .with_context(|| format!("capture verifier states for prog {prog_id}"))?;
            side_inputs.push((
                "--verifier-states".to_string(),
                verifier_states_json.clone(),
            ));
        }

        if wants_map_inline {
            side_inputs.push(("--map-values".to_string(), map_values_json.clone()));
            let map_ids = if prog_info.map_ids.is_empty() {
                "0".to_string()
            } else {
                join_u32_csv(&prog_info.map_ids)
            };
            side_inputs.push(("--map-ids".to_string(), PathBuf::from(map_ids)));
        }

        let wants_branch_flip = requested_passes
            .iter()
            .any(|pass| canonical_pass(pass) == "branch_flip");
        let wants_prefetch = requested_passes
            .iter()
            .any(|pass| canonical_pass(pass) == "prefetch");
        if wants_branch_flip {
            let profile_path = profile_path
                .ok_or_else(|| anyhow!("branch_flip requested but no profile is loaded"))?;
            side_inputs.push(("--profile".to_string(), profile_path.to_path_buf()));
        } else if wants_prefetch {
            if let Some(profile_path) = profile_path {
                side_inputs.push(("--profile".to_string(), profile_path.to_path_buf()));
            }
        }

        let mut bpfopt = config.command("bpfopt");
        bpfopt.arg("optimize").arg("--report").arg(&report_json);
        append_bpfopt_context_args(&mut bpfopt, &prog_info);
        if !requested_passes.is_empty() {
            bpfopt.arg("--passes").arg(join_pass_csv(requested_passes));
        }
        for (flag, value) in &side_inputs {
            bpfopt.arg(flag);
            if flag == "--map-ids" {
                bpfopt.arg(value.as_os_str());
            } else {
                bpfopt.arg(value);
            }
        }
        run_stage_with_file_io("bpfopt optimize", &mut bpfopt, &prog_bin, &opt_bin)
            .context("bpfopt optimize failed")?;

        let report: BpfoptOptimizeReport = read_json_file(&report_json, "bpfopt optimize report")?;
        let passes = report
            .passes
            .iter()
            .map(pass_detail_from_report)
            .collect::<Vec<_>>();
        let map_inline_records = collect_map_inline_records(&report)?;
        let inlined_map_entries = collect_inlined_map_entries(&map_inline_records);
        let opt_bytes =
            fs::read(&opt_bin).with_context(|| format!("read {}", opt_bin.display()))?;
        let final_insn_count = insn_count_from_bytes(&opt_bytes, "opt.bin")?;
        let changed = opt_bytes != orig_bytes;
        let candidate_has_kinsn_call = bytecode_has_kinsn_call(&opt_bytes, "opt.bin")?;
        if candidate_has_kinsn_call && !needs_target(requested_passes) {
            bail!(
                "candidate bytecode contains kinsn call but requested passes did not require target probing"
            );
        }
        let opt_insns = decode_insns(&opt_bytes, "opt.bin")?;
        let mut rejit_insns = opt_insns;
        rewrite_pseudo_map_fds_to_indices(&mut rejit_insns, &prog_info.map_ids, &map_fd_indices)
            .with_context(|| format!("rewrite pseudo-map fd references for prog {prog_id}"))?;

        let status = "ok".to_string();
        let mut applied = false;
        let error_message = None;

        if changed || force_rejit {
            let rejit_verifier_log = workdir.path().join("verifier.log");
            let rejit_summary = kernel
                .rejit(
                    prog_id,
                    &snapshot,
                    &rejit_insns,
                    fd_array.as_slice(),
                    &rejit_verifier_log,
                )
                .with_context(|| format!("in-process BPF_PROG_REJIT failed for prog {prog_id}"))?;
            write_json_file(&rejit_summary_json, &rejit_summary)?;
            refresh_invalidation_tracking(
                invalidation_tracker,
                prog_id,
                &map_inline_records,
                &mut open_map_fd,
            )
            .with_context(|| {
                format!("refresh map-inline invalidation tracking for prog {prog_id}")
            })?;
            applied = true;
        }

        let passes_applied = passes
            .iter()
            .filter(|pass| pass.changed)
            .map(|pass| pass.pass_name.clone())
            .collect::<Vec<_>>();
        let total_sites_applied = passes.iter().map(|pass| pass.sites_applied).sum();
        let passes_changed = passes.iter().filter(|pass| pass.changed).count();
        Ok(OptimizeOneResult {
            status,
            prog_id,
            changed,
            passes_applied,
            program: ProgramInfo {
                prog_id,
                prog_name: prog_info.name,
                prog_type: prog_info.prog_type.numeric,
                orig_insn_count,
                final_insn_count,
                insn_delta: final_insn_count as i64 - orig_insn_count as i64,
            },
            summary: OptimizeSummary {
                applied,
                total_sites_applied,
                passes_executed: passes.len(),
                passes_changed,
            },
            passes,
            inlined_map_entries,
            error_message,
        })
    })();

    match result {
        Ok(result) => {
            if let Some(path) = preserve_debug_workdir_if_requested(&workdir, prog_id)? {
                eprintln!(
                    "daemon: preserved debug workdir for prog {prog_id} at {}",
                    path.display()
                );
            }
            Ok(result)
        }
        Err(err) => match preserve_failure_workdir(&workdir, prog_id) {
            Ok(path) => {
                eprintln!(
                    "daemon: preserved failure workdir for prog {prog_id} at {}",
                    path.display()
                );
                Err(err).with_context(|| format!("preserved failure workdir: {}", path.display()))
            }
            Err(preserve_err) => Err(err).with_context(|| {
                format!("failed to preserve failure workdir for prog {prog_id}: {preserve_err:#}")
            }),
        },
    }
}

fn append_bpfopt_context_args(command: &mut Command, prog_info: &ProgInfoJson) {
    command.arg("--prog-type").arg(&prog_info.prog_type.name);
}

fn write_original_verifier_states(
    kernel: &mut dyn KernelOps,
    snapshot: &bpfget::ProgramSnapshot,
    map_fd_indices: &HashMap<i32, usize>,
    fd_array: &[i32],
    verifier_states_json: &Path,
) -> Result<()> {
    if verifier_states_json.exists() {
        fs::remove_file(verifier_states_json)
            .with_context(|| format!("remove stale {}", verifier_states_json.display()))?;
    }
    let mut dry_run_insns = snapshot.insns.clone();
    rewrite_pseudo_map_fds_to_indices(&mut dry_run_insns, &snapshot.info.map_ids, map_fd_indices)
        .context("rewrite pseudo-map fd references for thin dry-run")?;
    let states = kernel
        .verifier_states(snapshot, &dry_run_insns, fd_array)
        .context("thin verifier dry-run failed")?;
    write_json_file(verifier_states_json, &states)?;
    require_nonempty_file(verifier_states_json, "verifier states")?;
    Ok(())
}

fn pass_detail_from_report(report: &BpfoptPassReport) -> PassDetail {
    PassDetail {
        pass_name: report.pass.clone(),
        changed: report.changed,
        sites_applied: report.sites_applied,
        insns_before: report.insn_count_before,
        insns_after: report.insn_count_after,
        insn_delta: report.insn_delta as i64,
    }
}

fn write_live_map_values<F, G, H>(
    maps: &[MapInfoJson],
    output: &Path,
    open_map_fd: &mut F,
    lookup_map_value: &mut G,
    scan_map_keys: &mut H,
) -> Result<()>
where
    F: FnMut(u32) -> Result<OwnedFd>,
    G: FnMut(&MapInfoJson, i32, &[u8]) -> Result<Option<Vec<u8>>>,
    H: FnMut(&MapInfoJson, i32) -> Result<Vec<Vec<u8>>>,
{
    let mut entries_by_map = BTreeMap::<u32, BTreeMap<Vec<u8>, Option<Vec<u8>>>>::new();

    for map in maps {
        if !is_map_inlineable_map_type(map.map_type) {
            continue;
        }
        let fd = open_map_fd(map.map_id)
            .with_context(|| format!("open BPF map id {} for map-inline values", map.map_id))?;
        for key in scan_map_keys(map, fd.as_raw_fd())
            .with_context(|| format!("scan live keys for map {}", map.map_id))?
        {
            let value = lookup_map_value(map, fd.as_raw_fd(), &key).with_context(|| {
                format!(
                    "lookup live value for map {} key {}",
                    map.map_id,
                    hex_bytes(&key)
                )
            })?;
            if value.is_none() && is_array_like_map(map.map_type) {
                bail!(
                    "array-like map {} has no live value for key {}",
                    map.map_id,
                    hex_bytes(&key)
                );
            }
            entries_by_map
                .entry(map.map_id)
                .or_default()
                .insert(key, value);
        }
    }

    write_map_values_snapshot(maps, &entries_by_map, output)
}

fn write_map_values_snapshot(
    maps: &[MapInfoJson],
    entries_by_map: &BTreeMap<u32, BTreeMap<Vec<u8>, Option<Vec<u8>>>>,
    output: &Path,
) -> Result<()> {
    let payload = MapValuesJson {
        maps: maps
            .iter()
            .map(|map| {
                let entries = match entries_by_map.get(&map.map_id) {
                    Some(entries) => entries
                        .iter()
                        .map(|(key, value)| MapValuesEntryJson {
                            key: hex_bytes(key),
                            value: value.as_ref().map(|value| hex_bytes(value)),
                        })
                        .collect(),
                    None => Vec::new(),
                };

                MapValuesMapJson {
                    map_id: map.map_id,
                    map_type: map.map_type,
                    key_size: map.key_size,
                    value_size: map.value_size,
                    max_entries: map.max_entries,
                    frozen: false,
                    entries,
                }
            })
            .collect(),
    };
    write_json_file(output, &payload)
}

fn is_array_like_map(map_type: u32) -> bool {
    matches!(
        map_type,
        kernel_sys::BPF_MAP_TYPE_ARRAY | kernel_sys::BPF_MAP_TYPE_PERCPU_ARRAY
    )
}

fn is_map_inlineable_map_type(map_type: u32) -> bool {
    matches!(
        map_type,
        kernel_sys::BPF_MAP_TYPE_HASH
            | kernel_sys::BPF_MAP_TYPE_ARRAY
            | kernel_sys::BPF_MAP_TYPE_PERCPU_ARRAY
            | kernel_sys::BPF_MAP_TYPE_LRU_HASH
    )
}

fn needs_verifier_states(passes: &[String]) -> bool {
    passes
        .iter()
        .any(|pass| matches!(canonical_pass(pass).as_str(), "const_prop" | "map_inline"))
}

fn needs_target(passes: &[String]) -> bool {
    passes.iter().any(|pass| {
        matches!(
            canonical_pass(pass).as_str(),
            "rotate"
                | "cond_select"
                | "ccmp"
                | "extract"
                | "endian_fusion"
                | "bulk_memory"
                | "prefetch"
        )
    })
}

fn missing_target_kinsns(path: &Path, passes: &[String]) -> Result<Vec<&'static str>> {
    let target: TargetJson = read_json_file(path, "target.json")?;
    let mut missing = Vec::new();
    for pass in passes {
        match canonical_pass(pass).as_str() {
            "rotate" => push_missing_target(&mut missing, &target, &["bpf_rotate64"]),
            "cond_select" => push_missing_target(&mut missing, &target, &["bpf_select64"]),
            "ccmp" => push_missing_target(&mut missing, &target, &["bpf_ccmp64"]),
            "prefetch" => push_missing_target(&mut missing, &target, &["bpf_prefetch"]),
            "extract" => push_missing_target(&mut missing, &target, &["bpf_extract64"]),
            "endian_fusion" => push_missing_target(
                &mut missing,
                &target,
                &[
                    "bpf_endian_load16",
                    "bpf_endian_load32",
                    "bpf_endian_load64",
                ],
            ),
            "bulk_memory" => {
                push_missing_target(
                    &mut missing,
                    &target,
                    &["bpf_bulk_memcpy", "bpf_memcpy_bulk"],
                );
                push_missing_target(
                    &mut missing,
                    &target,
                    &["bpf_bulk_memset", "bpf_memset_bulk"],
                );
            }
            _ => {}
        }
    }
    Ok(missing)
}

fn target_has_any(target: &TargetJson, names: &[&str]) -> bool {
    names.iter().any(|name| target.kinsns.contains_key(*name))
}

fn push_missing_target(
    missing: &mut Vec<&'static str>,
    target: &TargetJson,
    aliases: &[&'static str],
) {
    if target_has_any(target, aliases) {
        return;
    }
    if let Some(name) = aliases.first() {
        push_unique(missing, name);
    }
}

struct RejitFdArray {
    fds: Vec<i32>,
    _owned_fds: Vec<OwnedFd>,
}

impl RejitFdArray {
    fn as_slice(&self) -> &[i32] {
        &self.fds
    }
}

fn build_rejit_fd_array<F>(
    map_ids: &[u32],
    target_path: Option<&Path>,
    passes: &[String],
    open_map_fd: &mut F,
) -> Result<RejitFdArray>
where
    F: FnMut(u32) -> Result<OwnedFd>,
{
    build_rejit_fd_array_with_btf_open(map_ids, target_path, passes, open_map_fd, &mut |btf_id| {
        kernel_sys::btf_get_fd_by_id(btf_id)
    })
}

fn build_rejit_fd_array_with_btf_open<F, G>(
    map_ids: &[u32],
    target_path: Option<&Path>,
    passes: &[String],
    open_map_fd: &mut F,
    open_btf_fd: &mut G,
) -> Result<RejitFdArray>
where
    F: FnMut(u32) -> Result<OwnedFd>,
    G: FnMut(u32) -> Result<OwnedFd>,
{
    let mut fds = Vec::new();
    let mut owned_fds = Vec::new();
    for &map_id in map_ids {
        let fd = open_map_fd(map_id).with_context(|| format!("open BPF map id {map_id}"))?;
        fds.push(fd.as_raw_fd());
        owned_fds.push(fd);
    }

    let Some(target_path) = target_path else {
        return Ok(RejitFdArray {
            fds,
            _owned_fds: owned_fds,
        });
    };

    let target: TargetJson = read_json_file(target_path, "target.json")?;
    let mut target_value: serde_json::Value = read_json_file(target_path, "target.json")?;
    let map_fd_count = fds.len();
    let mut btf_fds = Vec::<OwnedFd>::new();
    let mut btf_raw_fds = Vec::<(&'static str, i32)>::new();
    for name in required_kinsn_names(passes) {
        let Some(kinsn) = target.kinsns.get(name) else {
            continue;
        };
        if kinsn.btf_func_id < 0 {
            bail!("target kinsn {name} has negative btf_func_id");
        }
        let btf_id = if kinsn.btf_id != 0 {
            kinsn.btf_id
        } else {
            kinsn.btf_obj_id
        };
        if btf_id == 0 {
            bail!("target kinsn {name} is missing btf_id for fd_array");
        }
        let fd = open_btf_fd(btf_id)
            .with_context(|| format!("open BTF fd for target kinsn {name} btf_id {btf_id}"))?;
        btf_raw_fds.push((name, fd.as_raw_fd()));
        btf_fds.push(fd);
    }

    if map_fd_count == 0 && !btf_raw_fds.is_empty() {
        fds.push(btf_raw_fds[0].1);
    }
    for (idx, (name, raw_fd)) in btf_raw_fds.iter().enumerate() {
        let offset = kinsn_fd_array_offset(map_fd_count, idx);
        let call_offset = i16::try_from(offset)
            .with_context(|| format!("fd_array offset {offset} for target kinsn {name}"))?;
        write_kinsn_call_offset(&mut target_value, name, call_offset)?;
        fds.push(*raw_fd);
    }
    owned_fds.extend(btf_fds);
    write_json_file(target_path, &target_value)?;
    Ok(RejitFdArray {
        fds,
        _owned_fds: owned_fds,
    })
}

fn kinsn_fd_array_offset(map_fd_count: usize, kinsn_index: usize) -> usize {
    if map_fd_count == 0 {
        kinsn_index + 1
    } else {
        map_fd_count + kinsn_index
    }
}

fn write_kinsn_call_offset(
    target: &mut serde_json::Value,
    name: &str,
    call_offset: i16,
) -> Result<()> {
    let Some(kinsns) = target
        .get_mut("kinsns")
        .and_then(|value| value.as_object_mut())
    else {
        bail!("target.json is missing object field kinsns");
    };
    let Some(kinsn) = kinsns.get_mut(name).and_then(|value| value.as_object_mut()) else {
        bail!("target.json kinsn {name} is not an object");
    };
    kinsn.insert(
        "call_offset".to_string(),
        serde_json::Value::from(call_offset),
    );
    Ok(())
}

fn required_kinsn_names(passes: &[String]) -> Vec<&'static str> {
    let mut names = Vec::new();
    for pass in passes {
        match canonical_pass(pass).as_str() {
            "rotate" => push_unique(&mut names, "bpf_rotate64"),
            "cond_select" => push_unique(&mut names, "bpf_select64"),
            "ccmp" => push_unique(&mut names, "bpf_ccmp64"),
            "prefetch" => push_unique(&mut names, "bpf_prefetch"),
            "extract" => push_unique(&mut names, "bpf_extract64"),
            "endian_fusion" => push_unique(&mut names, "bpf_endian_load64"),
            "bulk_memory" => {
                push_unique(&mut names, "bpf_bulk_memcpy");
                push_unique(&mut names, "bpf_bulk_memset");
            }
            _ => {}
        }
    }
    names
}

fn push_unique(values: &mut Vec<&'static str>, value: &'static str) {
    if !values.contains(&value) {
        values.push(value);
    }
}

fn canonical_pass(pass: &str) -> String {
    match pass.trim() {
        "wide-mem" | "wide_mem" => "wide_mem",
        "rotate" => "rotate",
        "const-prop" | "const_prop" => "const_prop",
        "cond-select" | "cond_select" => "cond_select",
        "extract" => "extract",
        "endian" | "endian-fusion" | "endian_fusion" => "endian_fusion",
        "branch-flip" | "branch_flip" => "branch_flip",
        "prefetch" => "prefetch",
        "dce" => "dce",
        "map-inline" | "map_inline" => "map_inline",
        "bulk-memory" | "bulk_memory" => "bulk_memory",
        "bounds-check-merge" | "bounds_check_merge" => "bounds_check_merge",
        "skb-load-bytes" | "skb_load_bytes" | "skb-load-bytes-spec" | "skb_load_bytes_spec" => {
            "skb_load_bytes_spec"
        }
        other => return other.replace('-', "_"),
    }
    .to_string()
}

fn join_pass_csv(passes: &[String]) -> String {
    passes
        .iter()
        .map(|pass| pass.trim())
        .filter(|pass| !pass.is_empty())
        .collect::<Vec<_>>()
        .join(",")
}

fn join_u32_csv(values: &[u32]) -> String {
    values
        .iter()
        .map(u32::to_string)
        .collect::<Vec<_>>()
        .join(",")
}

fn insn_count_from_bytes(bytes: &[u8], label: &str) -> Result<usize> {
    if !bytes.len().is_multiple_of(8) {
        bail!("{label} length {} is not a multiple of 8", bytes.len());
    }
    Ok(bytes.len() / 8)
}

fn decode_insns(bytes: &[u8], label: &str) -> Result<Vec<kernel_sys::bpf_insn>> {
    insn_count_from_bytes(bytes, label)?;
    Ok(bytes
        .chunks_exact(8)
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

fn pseudo_map_fd_indices(
    insns: &[kernel_sys::bpf_insn],
    map_ids: &[u32],
) -> Result<HashMap<i32, usize>> {
    let mut old_fd_to_index = HashMap::new();
    let mut next_index = 0usize;
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = &insns[pc];
        if is_ldimm64(insn) {
            if matches!(insn.src_reg(), BPF_PSEUDO_MAP_FD | BPF_PSEUDO_MAP_VALUE) {
                let old_fd = insn.imm;
                if let std::collections::hash_map::Entry::Vacant(entry) =
                    old_fd_to_index.entry(old_fd)
                {
                    if next_index >= map_ids.len() {
                        bail!(
                            "original bytecode references pseudo-map old fd {old_fd}, but prog_info exposes only {} map ids",
                            map_ids.len()
                        );
                    }
                    entry.insert(next_index);
                    next_index += 1;
                }
            } else if matches!(
                insn.src_reg(),
                BPF_PSEUDO_MAP_IDX | BPF_PSEUDO_MAP_IDX_VALUE
            ) {
                validate_pseudo_map_index(insn.imm, map_ids.len())?;
            }
            pc += 2;
        } else {
            pc += 1;
        }
    }
    Ok(old_fd_to_index)
}

fn rewrite_pseudo_map_fds_to_indices(
    insns: &mut [kernel_sys::bpf_insn],
    map_ids: &[u32],
    old_fd_to_index: &HashMap<i32, usize>,
) -> Result<()> {
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = &mut insns[pc];
        if is_ldimm64(insn) {
            match insn.src_reg() {
                BPF_PSEUDO_MAP_FD | BPF_PSEUDO_MAP_VALUE => {
                    let old_fd = insn.imm;
                    let Some(&index) = old_fd_to_index.get(&old_fd) else {
                        bail!("no map binding for pseudo-map old fd {old_fd}");
                    };
                    if index >= map_ids.len() {
                        bail!(
                            "pseudo-map old fd {old_fd} resolved to map index {index}, but prog_info exposes only {} map ids",
                            map_ids.len()
                        );
                    }
                    insn.imm = i32::try_from(index)
                        .with_context(|| format!("map index {index} does not fit i32"))?;
                    let src_reg = if insn.src_reg() == BPF_PSEUDO_MAP_FD {
                        BPF_PSEUDO_MAP_IDX
                    } else {
                        BPF_PSEUDO_MAP_IDX_VALUE
                    };
                    insn.set_src_reg(src_reg);
                }
                BPF_PSEUDO_MAP_IDX | BPF_PSEUDO_MAP_IDX_VALUE => {
                    validate_pseudo_map_index(insn.imm, map_ids.len())?;
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

fn validate_pseudo_map_index(raw_index: i32, map_id_count: usize) -> Result<()> {
    if raw_index < 0 {
        bail!("pseudo-map fd_array index {raw_index} is negative");
    }
    let index = raw_index as usize;
    if index >= map_id_count {
        bail!("pseudo-map fd_array index {index} is out of range for {map_id_count} map ids");
    }
    Ok(())
}

fn is_ldimm64(insn: &kernel_sys::bpf_insn) -> bool {
    insn.code == BPF_LD_IMM64
}

fn bytecode_has_kinsn_call(bytes: &[u8], label: &str) -> Result<bool> {
    insn_count_from_bytes(bytes, label)?;
    let call_code = (kernel_sys::BPF_JMP | kernel_sys::BPF_CALL) as u8;
    const BPF_PSEUDO_KINSN_CALL: u8 = 4;
    Ok(bytes.chunks_exact(8).any(|insn| {
        let src_reg = insn[1] >> 4;
        insn[0] == call_code && src_reg == BPF_PSEUDO_KINSN_CALL
    }))
}

fn read_json_file<T: for<'de> Deserialize<'de>>(path: &Path, label: &str) -> Result<T> {
    let data = fs::read(path).with_context(|| format!("read {}", path.display()))?;
    serde_json::from_slice(&data).with_context(|| format!("parse {label} from {}", path.display()))
}

fn write_json_file<T: Serialize>(path: &Path, value: &T) -> Result<()> {
    let mut file = fs::File::create(path).with_context(|| format!("create {}", path.display()))?;
    serde_json::to_writer_pretty(&mut file, value)?;
    writeln!(file)?;
    file.flush()?;
    Ok(())
}

fn run_stage_with_file_io(
    stage: &str,
    command: &mut Command,
    input: &Path,
    output: &Path,
) -> Result<()> {
    let program = format!("{command:?}");
    let input_file = fs::File::open(input).with_context(|| format!("open {}", input.display()))?;
    let output_file =
        fs::File::create(output).with_context(|| format!("create {}", output.display()))?;
    let child_output = command
        .stdin(Stdio::from(input_file))
        .stdout(Stdio::from(output_file))
        .stderr(Stdio::piped())
        .spawn()
        .with_context(|| format!("spawn subprocess {program}"))?;
    let child_output = wait_with_timeout(stage, &program, child_output)?;
    if !child_output.status.success() {
        let message = stage_failure_message(stage, &program, &child_output);
        eprintln!("daemon: {message}");
        bail!("{message}");
    }
    Ok(())
}

fn wait_with_timeout(
    stage: &str,
    program: &str,
    child: std::process::Child,
) -> Result<std::process::Output> {
    wait_with_timeout_for(
        stage,
        program,
        child,
        timeout_for_stage(stage),
        CLI_STAGE_POLL_INTERVAL,
    )
}

fn timeout_for_stage(stage: &str) -> Duration {
    match stage {
        "bpfopt optimize" => OPTIMIZE_CLI_STAGE_TIMEOUT,
        _ => DEFAULT_CLI_STAGE_TIMEOUT,
    }
}

fn wait_with_timeout_for(
    stage: &str,
    program: &str,
    mut child: std::process::Child,
    timeout: Duration,
    poll_interval: Duration,
) -> Result<std::process::Output> {
    let start = Instant::now();
    loop {
        if child
            .try_wait()
            .with_context(|| format!("poll subprocess {program}"))?
            .is_some()
        {
            return child
                .wait_with_output()
                .with_context(|| format!("collect subprocess {program}"));
        }
        if start.elapsed() >= timeout {
            kill_and_reap_timed_out_child(program, child)?;
            bail!(
                "{stage} timed out after {}: killed subprocess {program}",
                duration_label(timeout)
            );
        }
        thread::sleep(poll_interval);
    }
}

fn kill_and_reap_timed_out_child(program: &str, mut child: std::process::Child) -> Result<()> {
    match child.kill() {
        Ok(()) => {}
        Err(err) if err.kind() == std::io::ErrorKind::InvalidInput => {}
        Err(err) => {
            return Err(err).with_context(|| format!("kill timed-out subprocess {program}"))
        }
    }
    let program = program.to_string();
    thread::spawn(move || {
        if let Err(err) = child.wait() {
            eprintln!("daemon: failed to reap timed-out subprocess {program}: {err}");
        }
    });
    Ok(())
}

fn duration_label(duration: Duration) -> String {
    let millis = duration.as_millis();
    if millis < 1_000 {
        format!("{millis}ms")
    } else {
        format!("{}s", duration.as_secs())
    }
}

fn stage_failure_message(stage: &str, program: &str, output: &std::process::Output) -> String {
    format!(
        "{stage} failed (returncode {}, status {}): subprocess {program}: {}",
        returncode_label(output),
        output.status,
        stderr_summary(output)
    )
}

fn returncode_label(output: &std::process::Output) -> String {
    output
        .status
        .code()
        .map(|code| code.to_string())
        .unwrap_or_else(|| "signal".to_string())
}

fn stderr_summary(output: &std::process::Output) -> String {
    let stderr = String::from_utf8_lossy(&output.stderr);
    let stdout = String::from_utf8_lossy(&output.stdout);
    let mut text = stderr.trim().to_string();
    if text.is_empty() {
        text = stdout.trim().to_string();
    }
    if text.is_empty() {
        text = "<no subprocess output>".to_string();
    }
    text.lines().take(20).collect::<Vec<_>>().join("\n")
}

fn count_json_files(path: &Path) -> Result<usize> {
    let mut count = 0usize;
    for entry in fs::read_dir(path).with_context(|| format!("read {}", path.display()))? {
        let entry = entry?;
        if entry.path().extension().and_then(|value| value.to_str()) == Some("json") {
            count += 1;
        }
    }
    Ok(count)
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::os::unix::fs::PermissionsExt;

    #[test]
    fn bytecode_decoder_rejects_unaligned_input() {
        let err = decode_insns(&[0u8; 9], "bad").unwrap_err();
        assert!(err.to_string().contains("multiple of 8"), "err={err:#}");
    }

    #[test]
    fn bytecode_has_kinsn_call_detects_project_pseudo_call() {
        let mut normal_call = [0u8; 8];
        normal_call[0] = (kernel_sys::BPF_JMP | kernel_sys::BPF_CALL) as u8;
        normal_call[1] = (kernel_sys::BPF_PSEUDO_CALL as u8) << 4;
        assert!(!bytecode_has_kinsn_call(&normal_call, "normal_call").unwrap());

        let mut kinsn_call = normal_call;
        kinsn_call[1] = 4 << 4;
        assert!(bytecode_has_kinsn_call(&kinsn_call, "kinsn_call").unwrap());
    }

    #[test]
    fn pseudo_map_fd_rewrite_preserves_original_map_binding_after_elimination() {
        let mut original = Vec::new();
        original.extend(ldimm64(BPF_PSEUDO_MAP_FD, 4));
        original.extend(ldimm64(BPF_PSEUDO_MAP_FD, 5));
        original.push(exit_insn());
        let map_ids = vec![101, 202];
        let bindings = pseudo_map_fd_indices(&original, &map_ids).unwrap();

        let mut candidate = Vec::new();
        candidate.extend(ldimm64(BPF_PSEUDO_MAP_FD, 5));
        candidate.push(exit_insn());
        rewrite_pseudo_map_fds_to_indices(&mut candidate, &map_ids, &bindings).unwrap();

        assert_eq!(candidate[0].src_reg(), BPF_PSEUDO_MAP_IDX);
        assert_eq!(candidate[0].imm, 1);
    }

    #[test]
    fn write_verifier_states_rewrites_stale_loader_map_fd() {
        let workdir = WorkDir::new("bpfrejit-daemon-verifier-state-rewrite").unwrap();
        let output = workdir.path().join(VERIFIER_STATES_FILE);
        let mut snapshot = test_snapshot(6);
        snapshot.info.map_ids = vec![1234];
        snapshot.insns = {
            let mut insns = Vec::new();
            insns.extend(ldimm64(BPF_PSEUDO_MAP_FD, 4));
            insns.push(exit_insn());
            insns
        };
        snapshot.info.insn_cnt = snapshot.insns.len() as u32;
        let bindings = pseudo_map_fd_indices(&snapshot.insns, &snapshot.info.map_ids).unwrap();
        let mut kernel = MockKernelOps {
            verifier_states: Some(kernel_sys::VerifierStatesJson { insns: Vec::new() }),
            ..Default::default()
        };

        write_original_verifier_states(&mut kernel, &snapshot, &bindings, &[77], &output).unwrap();

        assert_eq!(kernel.verifier_state_calls, 1);
        assert_eq!(kernel.last_verifier_fd_array, vec![77]);
        assert_eq!(kernel.last_verifier_insns[0].src_reg(), BPF_PSEUDO_MAP_IDX);
        assert_eq!(kernel.last_verifier_insns[0].imm, 0);
    }

    #[test]
    fn fd_array_generation_rewrites_target_call_offsets_in_memory() {
        assert_eq!(kinsn_fd_array_offset(0, 0), 1);
        assert_eq!(kinsn_fd_array_offset(0, 1), 2);
        assert_eq!(kinsn_fd_array_offset(2, 0), 2);
        assert_eq!(kinsn_fd_array_offset(2, 1), 3);
    }

    #[test]
    fn rejit_fd_array_builder_keeps_map_fds_without_target() {
        let mut opened_maps = Vec::new();
        let fd_array = build_rejit_fd_array_with_btf_open(
            &[11, 22],
            None,
            &["dce".to_string()],
            &mut |map_id| {
                opened_maps.push(map_id);
                fake_owned_fd()
            },
            &mut |_btf_id| bail!("test did not expect BTF fd opens"),
        )
        .unwrap();

        assert_eq!(opened_maps, vec![11, 22]);
        assert_eq!(fd_array.as_slice().len(), 2);
    }

    #[test]
    fn rejit_fd_array_builder_appends_kinsn_btf_fds_after_maps() {
        let workdir = WorkDir::new("bpfrejit-daemon-target-fd-array").unwrap();
        let target = workdir.path().join("target.json");
        write_json_file(
            &target,
            &serde_json::json!({
                "arch": "x86_64",
                "features": ["bmi2"],
                "kinsns": {
                    "bpf_rotate64": {"btf_func_id": 123, "btf_id": 55},
                    "bpf_select64": {"btf_func_id": 124, "btf_id": 56}
                }
            }),
        )
        .unwrap();
        let mut opened_maps = Vec::new();
        let mut opened_btfs = Vec::new();

        let fd_array = build_rejit_fd_array_with_btf_open(
            &[11],
            Some(&target),
            &["rotate".to_string(), "cond_select".to_string()],
            &mut |map_id| {
                opened_maps.push(map_id);
                fake_owned_fd()
            },
            &mut |btf_id| {
                opened_btfs.push(btf_id);
                fake_owned_fd()
            },
        )
        .unwrap();

        assert_eq!(opened_maps, vec![11]);
        assert_eq!(opened_btfs, vec![55, 56]);
        assert_eq!(fd_array.as_slice().len(), 3);
        let rewritten: serde_json::Value = read_json_file(&target, "target.json").unwrap();
        assert_eq!(rewritten["kinsns"]["bpf_rotate64"]["call_offset"], 1);
        assert_eq!(rewritten["kinsns"]["bpf_select64"]["call_offset"], 2);
    }

    #[test]
    fn rejit_fd_array_builder_reserves_slot_zero_when_only_btf_fds_exist() {
        let workdir = WorkDir::new("bpfrejit-daemon-target-fd-array-no-map").unwrap();
        let target = workdir.path().join("target.json");
        write_json_file(
            &target,
            &serde_json::json!({
                "arch": "x86_64",
                "features": ["bmi2"],
                "kinsns": {
                    "bpf_rotate64": {"btf_func_id": 123, "btf_id": 55},
                    "bpf_select64": {"btf_func_id": 124, "btf_id": 56}
                }
            }),
        )
        .unwrap();
        let mut opened_btfs = Vec::new();

        let fd_array = build_rejit_fd_array_with_btf_open(
            &[],
            Some(&target),
            &["rotate".to_string(), "cond_select".to_string()],
            &mut |_map_id| bail!("test did not expect map fd opens"),
            &mut |btf_id| {
                opened_btfs.push(btf_id);
                fake_owned_fd()
            },
        )
        .unwrap();

        assert_eq!(opened_btfs, vec![55, 56]);
        assert_eq!(fd_array.as_slice().len(), 3);
        assert_eq!(fd_array.as_slice()[0], fd_array.as_slice()[1]);
        let rewritten: serde_json::Value = read_json_file(&target, "target.json").unwrap();
        assert_eq!(rewritten["kinsns"]["bpf_rotate64"]["call_offset"], 1);
        assert_eq!(rewritten["kinsns"]["bpf_select64"]["call_offset"], 2);
    }

    #[test]
    fn live_map_values_snapshot_writes_values_and_lookup_misses() {
        let workdir = WorkDir::new("bpfrejit-daemon-map-values").unwrap();
        let output = workdir.path().join(MAP_VALUES_FILE);
        let maps = vec![
            MapInfoJson {
                map_id: 111,
                map_type: kernel_sys::BPF_MAP_TYPE_ARRAY,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
                name: "array_map".to_string(),
                map_flags: 0,
                ifindex: 0,
                btf_id: 0,
                btf_key_type_id: 0,
                btf_value_type_id: 0,
                btf_vmlinux_value_type_id: 0,
                btf_vmlinux_id: 0,
                map_extra: 0,
            },
            MapInfoJson {
                map_id: 222,
                map_type: kernel_sys::BPF_MAP_TYPE_HASH,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
                name: "hash_map".to_string(),
                map_flags: 0,
                ifindex: 0,
                btf_id: 0,
                btf_key_type_id: 0,
                btf_value_type_id: 0,
                btf_vmlinux_value_type_id: 0,
                btf_vmlinux_id: 0,
                map_extra: 0,
            },
        ];

        write_live_map_values(
            &maps,
            &output,
            &mut |_map_id| Ok(std::fs::File::open("/dev/null")?.into()),
            &mut |map, _fd, key| {
                if map.map_id == 111 && key == 1u32.to_le_bytes().as_slice() {
                    Ok(Some(7u32.to_le_bytes().to_vec()))
                } else {
                    Ok(None)
                }
            },
            &mut |map, _fd| {
                if map.map_id == 111 {
                    Ok(vec![1u32.to_le_bytes().to_vec()])
                } else {
                    Ok(vec![2u32.to_le_bytes().to_vec()])
                }
            },
        )
        .unwrap();

        let json: serde_json::Value = serde_json::from_slice(&fs::read(output).unwrap()).unwrap();
        assert_eq!(json["maps"][0]["entries"][0]["key"], "01000000");
        assert_eq!(json["maps"][0]["entries"][0]["value"], "07000000");
        assert_eq!(json["maps"][1]["entries"][0]["key"], "02000000");
        assert!(json["maps"][1]["entries"][0]["value"].is_null());
    }

    #[test]
    fn rejit_error_preserves_log_and_prog_id_in_error() {
        let harness = ApplyHarness::new();
        let mut kernel = MockKernelOps {
            rejit_error: Some("mock rejit verifier log".to_string()),
            ..Default::default()
        };

        let err = harness.apply(&mut kernel).unwrap_err();

        let message = format!("{err:#}");
        assert!(message.contains("prog 42"), "err={message}");
        assert!(message.contains("mock rejit verifier log"), "err={message}");
        assert_eq!(kernel.rejit_calls, 1);
        let verifier_log =
            fs::read_to_string(harness.failure_root.path().join("42/verifier.log")).unwrap();
        assert_eq!(verifier_log, "mock rejit verifier log");
    }

    #[test]
    fn rejit_enospc_retry_log_reaches_failure_artifact() {
        let harness = ApplyHarness::new();
        let retry_log = "retry after ENOSPC full verifier log".to_string();
        let mut kernel = MockKernelOps {
            rejit_error: Some(retry_log.clone()),
            ..Default::default()
        };

        let err = harness.apply(&mut kernel).unwrap_err();

        let message = format!("{err:#}");
        assert!(message.contains(&retry_log), "err={message}");
        assert_eq!(kernel.rejit_calls, 1);
        let verifier_log =
            fs::read_to_string(harness.failure_root.path().join("42/verifier.log")).unwrap();
        assert_eq!(verifier_log, retry_log);
    }

    #[test]
    fn bpfopt_success_reaches_rejit_and_returns_success() {
        let harness = ApplyHarness::new();
        let mut kernel = MockKernelOps {
            ..Default::default()
        };

        let result = harness.apply(&mut kernel).unwrap();

        assert_eq!(result.status, "ok");
        assert_eq!(result.prog_id, 42);
        assert!(result.changed);
        assert!(result.summary.applied);
        assert_eq!(kernel.rejit_calls, 1);
    }

    #[test]
    fn const_prop_request_captures_verifier_states_automatically() {
        let harness = ApplyHarness::new();
        let mut kernel = MockKernelOps {
            verifier_states: Some(kernel_sys::VerifierStatesJson { insns: Vec::new() }),
            ..Default::default()
        };
        let enabled_passes = ["const_prop".to_string(), "dce".to_string()];

        let result = harness
            .apply_with_passes(&mut kernel, &enabled_passes)
            .unwrap();

        assert_eq!(kernel.verifier_state_calls, 1);
        assert_eq!(kernel.rejit_calls, 1);
        assert!(result
            .passes
            .iter()
            .any(|pass| pass.pass_name == "const_prop"));
    }

    struct ApplyHarness {
        _env_lock: std::sync::MutexGuard<'static, ()>,
        _cli_dir: WorkDir,
        _failure_env: EnvGuard,
        failure_root: WorkDir,
        config: CliConfig,
    }

    impl ApplyHarness {
        fn new() -> Self {
            static TEST_ENV_LOCK: Mutex<()> = Mutex::new(());
            let env_lock = TEST_ENV_LOCK
                .lock()
                .expect("test env lock should not be poisoned");
            let cli_dir = WorkDir::new("bpfrejit-daemon-fake-cli").unwrap();
            write_fake_bpfopt(cli_dir.path());
            let failure_root = WorkDir::new("bpfrejit-daemon-failures").unwrap();
            let failure_env = EnvGuard::set(FAILURE_ROOT_ENV, failure_root.path());
            let config = CliConfig {
                cli_dir: Some(cli_dir.path().to_path_buf()),
            };
            Self {
                _env_lock: env_lock,
                _cli_dir: cli_dir,
                _failure_env: failure_env,
                failure_root,
                config,
            }
        }

        fn apply(&self, kernel: &mut dyn KernelOps) -> Result<OptimizeOneResult> {
            self.apply_with_passes(kernel, &["dce".to_string()])
        }

        fn apply_with_passes(
            &self,
            kernel: &mut dyn KernelOps,
            enabled_passes: &[String],
        ) -> Result<OptimizeOneResult> {
            try_apply_one_with_map_access(
                ApplyOneRequest {
                    prog_id: 42,
                    config: &self.config,
                    enabled_passes: Some(enabled_passes),
                    profile_path: None,
                    invalidation_tracker: None,
                    force_rejit: false,
                },
                kernel,
                |_map_id| -> Result<OwnedFd> { bail!("test did not expect map fd opens") },
                |_map, _fd, _key| -> Result<Option<Vec<u8>>> {
                    bail!("test did not expect map value lookups")
                },
                |_map, _fd| -> Result<Vec<Vec<u8>>> { bail!("test did not expect map key scans") },
            )
        }
    }

    struct EnvGuard {
        key: &'static str,
        previous: Option<std::ffi::OsString>,
    }

    impl EnvGuard {
        fn set(key: &'static str, value: &Path) -> Self {
            let previous = std::env::var_os(key);
            std::env::set_var(key, value.as_os_str());
            Self { key, previous }
        }
    }

    impl Drop for EnvGuard {
        fn drop(&mut self) {
            match &self.previous {
                Some(value) => std::env::set_var(self.key, value),
                None => std::env::remove_var(self.key),
            }
        }
    }

    #[derive(Default)]
    struct MockKernelOps {
        rejit_error: Option<String>,
        rejit_calls: usize,
        verifier_state_calls: usize,
        verifier_states: Option<kernel_sys::VerifierStatesJson>,
        last_verifier_insns: Vec<kernel_sys::bpf_insn>,
        last_verifier_fd_array: Vec<i32>,
    }

    impl KernelOps for MockKernelOps {
        fn snapshot_program(&mut self, prog_id: u32) -> Result<bpfget::ProgramSnapshot> {
            Ok(test_snapshot(prog_id))
        }

        fn probe_target(&mut self) -> Result<bpfget::TargetJson> {
            bail!("test did not expect target probing")
        }

        fn verifier_states(
            &mut self,
            _snapshot: &bpfget::ProgramSnapshot,
            insns: &[kernel_sys::bpf_insn],
            fd_array: &[i32],
        ) -> Result<kernel_sys::VerifierStatesJson> {
            self.verifier_state_calls += 1;
            self.last_verifier_insns = insns.to_vec();
            self.last_verifier_fd_array = fd_array.to_vec();
            self.verifier_states
                .clone()
                .ok_or_else(|| anyhow!("test did not expect verifier-state capture"))
        }

        fn rejit(
            &mut self,
            prog_id: u32,
            _snapshot: &bpfget::ProgramSnapshot,
            insns: &[kernel_sys::bpf_insn],
            _fd_array: &[i32],
            verifier_log_path: &Path,
        ) -> Result<RejitSummary> {
            self.rejit_calls += 1;
            if let Some(message) = &self.rejit_error {
                fs::write(verifier_log_path, message)
                    .with_context(|| format!("write {}", verifier_log_path.display()))?;
                bail!("{message}");
            }
            Ok(RejitSummary {
                status: "ok".to_string(),
                prog_id,
                insn_count_before: 1,
                insn_count_after: insns.len(),
            })
        }
    }

    fn write_fake_bpfopt(dir: &Path) {
        let path = dir.join("bpfopt");
        fs::write(
            &path,
            r#"#!/bin/sh
set -eu
if [ "$1" != "optimize" ]; then
    echo "unexpected bpfopt subcommand: $1" >&2
    exit 1
fi
report=""
passes=""
verifier_states=""
while [ "$#" -gt 0 ]; do
    if [ "$1" = "--report" ]; then
        shift
        report="$1"
    elif [ "$1" = "--passes" ]; then
        shift
        passes="$1"
    elif [ "$1" = "--verifier-states" ]; then
        shift
        verifier_states="$1"
    fi
    shift || true
done
if [ -z "$report" ]; then
    echo "missing --report" >&2
    exit 1
fi
case ",$passes," in
    *,const_prop,*|*,map_inline,*)
        if [ -z "$verifier_states" ]; then
            echo "missing --verifier-states" >&2
            exit 2
        fi
        if [ ! -s "$verifier_states" ]; then
            echo "empty --verifier-states" >&2
            exit 3
        fi
        ;;
esac
first_pass="${passes%%,*}"
if [ -z "$first_pass" ]; then
    first_pass="dce"
fi
cat
printf '\225\000\000\000\000\000\000\000'
printf '{"passes":[{"pass":"%s","changed":true,"sites_applied":1,"insn_count_before":1,"insn_count_after":2,"insn_delta":1}]}\n' "$first_pass" > "$report"
"#,
        )
        .unwrap();
        let mut permissions = fs::metadata(&path).unwrap().permissions();
        permissions.set_mode(0o755);
        fs::set_permissions(&path, permissions).unwrap();
    }

    fn test_snapshot(prog_id: u32) -> bpfget::ProgramSnapshot {
        bpfget::ProgramSnapshot {
            info: bpfget::ProgramInfo {
                id: prog_id,
                name: "mock_prog".to_string(),
                prog_type: bpfget::TypeInfo {
                    name: "xdp".to_string(),
                    numeric: kernel_sys::BPF_PROG_TYPE_XDP,
                },
                insn_cnt: 1,
                map_ids: Vec::new(),
                load_time: 0,
                created_by_uid: 0,
                xlated_prog_len: 8,
                orig_prog_len: 8,
                jited_prog_len: 0,
                btf_id: 0,
                prog_flags: 0,
                attach_btf_obj_id: 0,
                attach_btf_id: 0,
                expected_attach_type: None,
            },
            maps: Vec::new(),
            insns: vec![exit_insn()],
        }
    }

    fn exit_insn() -> kernel_sys::bpf_insn {
        kernel_sys::bpf_insn {
            code: (kernel_sys::BPF_JMP | kernel_sys::BPF_EXIT) as u8,
            _bitfield_align_1: [],
            _bitfield_1: Default::default(),
            off: 0,
            imm: 0,
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
        first.set_dst_reg(1);
        first.set_src_reg(src_reg);
        [
            first,
            kernel_sys::bpf_insn {
                code: 0,
                _bitfield_align_1: [],
                _bitfield_1: Default::default(),
                off: 0,
                imm: 0,
            },
        ]
    }

    fn fake_owned_fd() -> Result<OwnedFd> {
        Ok(std::fs::File::open("/dev/null")?.into())
    }
}
