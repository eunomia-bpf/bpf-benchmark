// SPDX-License-Identifier: MIT
//! Socket command helpers backed by bpfopt-suite CLI subprocesses.

use std::collections::{BTreeMap, HashMap};
use std::fs::{self, OpenOptions};
use std::io::Write;
use std::os::fd::{AsRawFd, OwnedFd};
use std::os::unix::fs::PermissionsExt;
use std::path::{Path, PathBuf};
use std::process::{Command, Stdio};
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::{Arc, Mutex};

use anyhow::{anyhow, bail, Context, Result};
use serde::{Deserialize, Serialize};

use crate::bpf;
use crate::invalidation::{BpfMapValueReader, MapInvalidationTracker};

static NEXT_WORKDIR_ID: AtomicU64 = AtomicU64::new(0);
const FAILURE_ROOT_ENV: &str = "BPFREJIT_DAEMON_FAILURE_ROOT";
const KEEP_ALL_WORKDIRS_ENV: &str = "BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS";
const DEFAULT_FAILURE_ROOT_NAME: &str = "bpfrejit-failures";
const DEBUG_WORKDIR_ROOT_NAME: &str = "workdirs";
const FUNC_INFO_FILE: &str = "func_info.bin";
const LINE_INFO_FILE: &str = "line_info.bin";
const MAP_VALUES_FILE: &str = "map-values.json";
const VERIFIER_STATES_FILE: &str = "verifier-states.json";

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

    #[cfg(test)]
    pub(crate) fn with_dir(path: PathBuf) -> Self {
        Self {
            cli_dir: Some(path),
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
    normalize_failure_artifacts(&failure_dir, prog_id)?;
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

fn normalize_failure_artifacts(failure_dir: &Path, prog_id: u32) -> Result<()> {
    copy_alias_if_present(&failure_dir.join("prog.bin"), &failure_dir.join("prog.bpf"))?;
    copy_alias_if_present(
        &failure_dir.join("prog_info.json"),
        &failure_dir.join("info.json"),
    )?;
    let rejit_verifier_log = failure_dir.join("bpfrejit_failure_verifier.log");
    if nonempty_regular_file(&rejit_verifier_log)? {
        fs::copy(&rejit_verifier_log, failure_dir.join("verifier.log")).with_context(|| {
            format!(
                "copy {} to {}",
                rejit_verifier_log.display(),
                failure_dir.join("verifier.log").display()
            )
        })?;
    }
    write_replay_script(failure_dir, prog_id)?;
    require_regular_file(&failure_dir.join("prog.bpf"), "failure prog.bpf")?;
    require_regular_file(&failure_dir.join("info.json"), "failure info.json")?;
    require_regular_file(&failure_dir.join("replay.sh"), "failure replay.sh")?;
    require_nonempty_file(&failure_dir.join("verifier.log"), "failure verifier.log")?;
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

fn nonempty_regular_file(path: &Path) -> Result<bool> {
    match fs::metadata(path) {
        Ok(metadata) => {
            if !metadata.is_file() {
                bail!("failure artifact {} is not a regular file", path.display());
            }
            Ok(metadata.len() > 0)
        }
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => Ok(false),
        Err(err) => Err(err).with_context(|| format!("stat {}", path.display())),
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

fn write_replay_script(failure_dir: &Path, prog_id: u32) -> Result<()> {
    let info_json = failure_dir.join("info.json");
    require_regular_file(&info_json, "failure info.json")?;
    let prog_info: ProgInfoJson = read_json_file(&info_json, "failure info.json")?;
    let load_context_args = replay_load_context_args(&prog_info);
    let verify_args = render_shell_args(&load_context_args);
    let btf_info_setup = replay_btf_info_setup(&prog_info);
    let script = format!(
        r#"#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"

prog_id="${{1:-{prog_id}}}"
candidate="${{BPFREJIT_REPLAY_CANDIDATE:-verified.bin}}"
if [ ! -f "$candidate" ]; then
    candidate=opt.bin
fi
if [ ! -f "$candidate" ]; then
    candidate=prog.bpf
fi

fd_array_args=()
if [ -s fd_array.json ]; then
    fd_array_args=(--fd-array fd_array.json)
fi

btf_info_args=()
{btf_info_setup}

"${{BPFVERIFY:-bpfverify}}" {verify_args} "${{btf_info_args[@]}}" "${{fd_array_args[@]}}" \
    --input "$candidate" \
    --output replay.verified.bin \
    --report replay_bpfverify_report.json
"${{BPFREJIT:-bpfrejit}}" "$prog_id" replay.verified.bin \
    --map-fds map_fds.json \
    --output replay_bpfrejit_summary.json \
    "${{fd_array_args[@]}}"
"#,
    );
    let script_path = failure_dir.join("replay.sh");
    fs::write(&script_path, script).with_context(|| format!("write {}", script_path.display()))?;
    let mut permissions = fs::metadata(&script_path)?.permissions();
    permissions.set_mode(0o755);
    fs::set_permissions(&script_path, permissions)
        .with_context(|| format!("chmod +x {}", script_path.display()))?;
    Ok(())
}

fn replay_load_context_args(prog_info: &ProgInfoJson) -> Vec<String> {
    let mut args = vec![
        "--prog-type".to_string(),
        prog_info.prog_type.name.clone(),
        "--map-fds".to_string(),
        "map_fds.json".to_string(),
    ];
    if let Some(attach_type) = &prog_info.expected_attach_type {
        args.push("--expected-attach-type".to_string());
        if attach_type.name.trim().is_empty() {
            args.push(attach_type.numeric.to_string());
        } else {
            args.push(attach_type.name.clone());
        }
    }
    if prog_info.btf_id != 0 {
        args.push("--prog-btf-id".to_string());
        args.push(prog_info.btf_id.to_string());
    }
    if prog_info.attach_btf_id != 0 {
        args.push("--attach-btf-id".to_string());
        args.push(prog_info.attach_btf_id.to_string());
    }
    if prog_info.attach_btf_obj_id != 0 {
        args.push("--attach-btf-obj-id".to_string());
        args.push(prog_info.attach_btf_obj_id.to_string());
    }
    args
}

fn replay_btf_info_setup(prog_info: &ProgInfoJson) -> String {
    let mut lines = Vec::new();
    if prog_info.nr_func_info != 0 {
        lines.push(format!(
            "if [ -s {} ]; then\n    btf_info_args+=(--func-info {} --func-info-rec-size {})\nfi",
            shell_quote(FUNC_INFO_FILE),
            shell_quote(FUNC_INFO_FILE),
            shell_quote(&prog_info.func_info_rec_size.to_string())
        ));
    }
    if prog_info.nr_line_info != 0 {
        lines.push(format!(
            "if [ -s {} ]; then\n    btf_info_args+=(--line-info {} --line-info-rec-size {})\nfi",
            shell_quote(LINE_INFO_FILE),
            shell_quote(LINE_INFO_FILE),
            shell_quote(&prog_info.line_info_rec_size.to_string())
        ));
    }
    lines.join("\n")
}

fn render_shell_args(args: &[String]) -> String {
    args.iter()
        .map(|arg| shell_quote(arg))
        .collect::<Vec<_>>()
        .join(" ")
}

fn shell_quote(value: &str) -> String {
    if !value.is_empty()
        && value.bytes().all(|byte| {
            byte.is_ascii_alphanumeric() || matches!(byte, b'_' | b'-' | b'.' | b'/' | b':')
        })
    {
        return value.to_string();
    }
    format!("'{}'", value.replace('\'', "'\\''"))
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

#[derive(Clone, Debug, Deserialize)]
struct TypeJson {
    name: String,
    numeric: u32,
}

#[derive(Clone, Debug, Deserialize)]
struct ProgInfoJson {
    id: u32,
    name: String,
    #[serde(rename = "type")]
    prog_type: TypeJson,
    insn_cnt: u32,
    #[serde(default)]
    map_ids: Vec<u32>,
    #[serde(default)]
    btf_id: u32,
    #[serde(default)]
    func_info_rec_size: u32,
    #[serde(default)]
    nr_func_info: u32,
    #[serde(default)]
    line_info_rec_size: u32,
    #[serde(default)]
    nr_line_info: u32,
    #[serde(default)]
    attach_btf_obj_id: u32,
    #[serde(default)]
    attach_btf_id: u32,
    #[serde(default)]
    expected_attach_type: Option<TypeJson>,
}

#[derive(Clone, Debug, Deserialize, Serialize)]
struct MapInfoJson {
    map_id: u32,
    map_type: u32,
    key_size: u32,
    value_size: u32,
    max_entries: u32,
    #[serde(default)]
    name: String,
}

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
struct BpfverifyReport {
    status: String,
    verifier_log: String,
    errno: Option<i32>,
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

#[derive(Debug, Serialize)]
struct FdArrayJsonEntry {
    slot: usize,
    name: String,
    btf_id: u32,
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
    try_apply_one_with_map_access(
        ApplyOneRequest {
            prog_id,
            config,
            enabled_passes,
            profile_path,
            invalidation_tracker,
            force_rejit: false,
        },
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
    try_apply_one_with_map_access(
        ApplyOneRequest {
            prog_id,
            config,
            enabled_passes,
            profile_path,
            invalidation_tracker,
            force_rejit: true,
        },
        bpf::bpf_map_get_fd_by_id,
        live_bpf_map_lookup,
        live_bpf_map_keys,
    )
}

fn try_apply_one_with_map_access<F, G, H>(
    request: ApplyOneRequest<'_>,
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
    let prog_info_json = workdir.path().join("prog_info.json");
    let map_fds_json = workdir.path().join("map_fds.json");
    let target_json = workdir.path().join("target.json");
    let fd_array_json = workdir.path().join("fd_array.json");
    let verifier_states_json = workdir.path().join(VERIFIER_STATES_FILE);
    let map_values_json = workdir.path().join(MAP_VALUES_FILE);
    let opt_bin = workdir.path().join("opt.bin");
    let verified_bin = workdir.path().join("verified.bin");
    let report_json = workdir.path().join("bpfopt_report.json");
    let rejit_summary_json = workdir.path().join("bpfrejit_summary.json");

    let result = (|| -> Result<OptimizeOneResult> {
        run_stage_output(
            "bpfget --full",
            config
                .command("bpfget")
                .arg(prog_id.to_string())
                .arg("--full")
                .arg("--outdir")
                .arg(workdir.path()),
        )
        .with_context(|| format!("bpfget --full failed for prog {prog_id}"))?;

        let prog_info: ProgInfoJson = read_json_file(&prog_info_json, "prog_info.json")?;
        let orig_bytes =
            fs::read(&prog_bin).with_context(|| format!("read {}", prog_bin.display()))?;
        let orig_insn_count = insn_count_from_bytes(&orig_bytes, "prog.bin")?;
        if prog_info.id != prog_id {
            bail!(
                "bpfget returned prog_info id {}, expected {prog_id}",
                prog_info.id
            );
        }
        if prog_info.insn_cnt as usize != orig_insn_count {
            bail!(
                "bpfget returned prog_info insn_cnt {}, but prog.bin contains {} instructions",
                prog_info.insn_cnt,
                orig_insn_count
            );
        }
        let mut side_inputs = Vec::<(String, PathBuf)>::new();
        let wants_const_prop = requested_passes
            .iter()
            .any(|pass| canonical_pass(pass) == "const_prop");
        let wants_map_inline = requested_passes
            .iter()
            .any(|pass| canonical_pass(pass) == "map_inline");

        if wants_const_prop {
            write_original_verifier_states(
                config,
                &prog_info,
                workdir.path(),
                &prog_bin,
                &map_fds_json,
                &verifier_states_json,
            )
            .with_context(|| format!("capture verifier states for prog {prog_id}"))?;
        }

        if wants_map_inline {
            write_live_map_values(
                &map_fds_json,
                &map_values_json,
                &mut open_map_fd,
                &mut lookup_map_value,
                &mut scan_map_keys,
            )
            .with_context(|| format!("build live map value snapshot for prog {prog_id}"))?;
        }

        let mut has_fd_array = false;
        if needs_target(requested_passes) {
            run_stage_output(
                "bpfget --target",
                config
                    .command("bpfget")
                    .arg("--target")
                    .arg("--output")
                    .arg(&target_json),
            )
            .with_context(|| {
                format!(
                    "bpfget --target failed for requested passes {}",
                    join_pass_csv(requested_passes)
                )
            })?;
            let missing_kinsns = missing_target_kinsns(&target_json, requested_passes)?;
            if !missing_kinsns.is_empty() {
                bail!(
                    "bpfget --target did not expose kinsns required by requested passes {}: {}",
                    join_pass_csv(requested_passes),
                    missing_kinsns.join(", ")
                );
            }
            write_fd_array_from_target(&target_json, requested_passes, &fd_array_json)?;
            has_fd_array = true;
            side_inputs.push(("--target".to_string(), target_json.clone()));
        }

        if wants_const_prop {
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
        append_btf_info_command_args(&mut bpfopt, &prog_info, workdir.path());
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
        if candidate_has_kinsn_call && !has_fd_array {
            bail!("candidate bytecode contains kinsn call but fd_array.json was not generated");
        }
        let use_fd_array = candidate_has_kinsn_call;

        let status = "ok".to_string();
        let mut applied = false;
        let error_message = None;

        if changed || force_rejit {
            let final_verify_report = workdir.path().join("bpfverify_report.json");
            let final_verify_log = workdir.path().join("verifier.log");
            let mut verify = config.command("bpfverify");
            verify
                .arg("--prog-type")
                .arg(&prog_info.prog_type.name)
                .arg("--map-fds")
                .arg(&map_fds_json)
                .arg("--input")
                .arg(&opt_bin)
                .arg("--output")
                .arg(&verified_bin)
                .arg("--report")
                .arg(&final_verify_report);
            append_candidate_load_context_args(&mut verify, &prog_info, workdir.path())?;
            if use_fd_array {
                verify.arg("--fd-array").arg(&fd_array_json);
            }
            let verify_result = run_bpfverify_reported(
                "bpfverify final verification",
                &mut verify,
                &final_verify_report,
                &final_verify_log,
            );
            verify_result.with_context(|| {
                format!("bpfverify final verification failed for prog {prog_id}")
            })?;

            let mut rejit = config.command("bpfrejit");
            rejit
                .arg(prog_id.to_string())
                .arg(&verified_bin)
                .arg("--map-fds")
                .arg(&map_fds_json)
                .arg("--output")
                .arg(&rejit_summary_json);
            if use_fd_array {
                rejit.arg("--fd-array").arg(&fd_array_json);
            }
            let rejit_result = run_stage_output("bpfrejit", &mut rejit);
            if let Err(rejit_err) = rejit_result {
                let verifier_context = match capture_rejit_failure_verifier_log(
                    config,
                    &prog_info,
                    &map_fds_json,
                    &fd_array_json,
                    use_fd_array,
                    &verified_bin,
                    workdir.path(),
                ) {
                    Ok(summary) => format!("\nverifier log summary:\n{summary}"),
                    Err(report_err) => {
                        format!("\npost-failure bpfverify --report failed: {report_err:#}")
                    }
                };
                return Err(rejit_err).with_context(|| {
                    format!("bpfrejit failed for prog {prog_id}{verifier_context}")
                });
            }
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

fn append_candidate_load_context_args(
    command: &mut Command,
    prog_info: &ProgInfoJson,
    workdir: &Path,
) -> Result<()> {
    append_load_context_base_args(command, prog_info);
    append_nonempty_btf_info_command_args(command, prog_info, workdir)
}

fn append_load_context_base_args(command: &mut Command, prog_info: &ProgInfoJson) {
    if let Some(attach_type) = &prog_info.expected_attach_type {
        let value = if attach_type.name.trim().is_empty() {
            attach_type.numeric.to_string()
        } else {
            attach_type.name.clone()
        };
        command.arg("--expected-attach-type").arg(value);
    }
    if prog_info.btf_id != 0 {
        command
            .arg("--prog-btf-id")
            .arg(prog_info.btf_id.to_string());
    }
    if prog_info.attach_btf_id != 0 {
        command
            .arg("--attach-btf-id")
            .arg(prog_info.attach_btf_id.to_string());
    }
    if prog_info.attach_btf_obj_id != 0 {
        command
            .arg("--attach-btf-obj-id")
            .arg(prog_info.attach_btf_obj_id.to_string());
    }
}

fn append_verifier_states_load_context_args(command: &mut Command, prog_info: &ProgInfoJson) {
    append_load_context_base_args(command, prog_info);
}

fn append_bpfopt_context_args(command: &mut Command, prog_info: &ProgInfoJson) {
    command.arg("--prog-type").arg(&prog_info.prog_type.name);
}

fn append_btf_info_command_args(command: &mut Command, prog_info: &ProgInfoJson, workdir: &Path) {
    if prog_info.nr_func_info != 0 {
        command
            .arg("--func-info")
            .arg(workdir.join(FUNC_INFO_FILE))
            .arg("--func-info-rec-size")
            .arg(prog_info.func_info_rec_size.to_string());
    }
    if prog_info.nr_line_info != 0 {
        command
            .arg("--line-info")
            .arg(workdir.join(LINE_INFO_FILE))
            .arg("--line-info-rec-size")
            .arg(prog_info.line_info_rec_size.to_string());
    }
}

fn append_nonempty_btf_info_command_args(
    command: &mut Command,
    prog_info: &ProgInfoJson,
    workdir: &Path,
) -> Result<()> {
    if prog_info.nr_func_info != 0 {
        append_btf_info_file_if_nonempty(
            command,
            &workdir.join(FUNC_INFO_FILE),
            "--func-info",
            "--func-info-rec-size",
            prog_info.func_info_rec_size,
        )?;
    }
    if prog_info.nr_line_info != 0 {
        append_btf_info_file_if_nonempty(
            command,
            &workdir.join(LINE_INFO_FILE),
            "--line-info",
            "--line-info-rec-size",
            prog_info.line_info_rec_size,
        )?;
    }
    Ok(())
}

fn append_btf_info_file_if_nonempty(
    command: &mut Command,
    path: &Path,
    file_flag: &str,
    rec_size_flag: &str,
    rec_size: u32,
) -> Result<()> {
    let metadata = fs::metadata(path).with_context(|| format!("stat {}", path.display()))?;
    if metadata.len() != 0 {
        command
            .arg(file_flag)
            .arg(path)
            .arg(rec_size_flag)
            .arg(rec_size.to_string());
    }
    Ok(())
}

fn run_bpfverify_reported(
    stage: &str,
    command: &mut Command,
    report_json: &Path,
    verifier_log_path: &Path,
) -> Result<BpfverifyReport> {
    let (output, report) =
        run_bpfverify_report_command(stage, command, report_json, "bpfverify report")?;
    fs::write(verifier_log_path, &report.verifier_log)
        .with_context(|| format!("write {}", verifier_log_path.display()))?;
    if report.status != "pass" {
        let message = format!(
            "{stage} rejected bytecode (returncode {}, verifier status {}, errno {}): verifier log summary:\n{}",
            returncode_label(&output),
            report.status,
            report
                .errno
                .map(|errno| errno.to_string())
                .unwrap_or_else(|| "unknown".to_string()),
            verifier_log_summary(&report.verifier_log)
        );
        eprintln!("daemon: {message}");
        bail!("{message}");
    }
    if !output.status.success() {
        let program = format!("{command:?}");
        let message = stage_failure_message(stage, &program, &output);
        eprintln!("daemon: {message}");
        bail!("{message}");
    }
    Ok(report)
}

fn run_bpfverify_report_command(
    stage: &str,
    command: &mut Command,
    report_json: &Path,
    report_label: &str,
) -> Result<(std::process::Output, BpfverifyReport)> {
    let program = format!("{command:?}");
    let output = command
        .output()
        .with_context(|| format!("spawn subprocess {program}"))?;
    let report: BpfverifyReport = read_json_file(report_json, report_label).with_context(|| {
        let failure = if output.status.success() {
            format!("read {report_label}")
        } else {
            stage_failure_message(stage, &program, &output)
        };
        format!("{failure}; expected report at {}", report_json.display())
    })?;
    Ok((output, report))
}

fn capture_rejit_failure_verifier_log(
    config: &CliConfig,
    prog_info: &ProgInfoJson,
    map_fds_json: &Path,
    fd_array_json: &Path,
    use_fd_array: bool,
    verified_bin: &Path,
    workdir: &Path,
) -> Result<String> {
    let report_json = workdir.join("bpfrejit_failure_bpfverify_report.json");
    let verifier_log_path = workdir.join("bpfrejit_failure_verifier.log");
    let mut verify = config.command("bpfverify");
    verify
        .arg("--prog-type")
        .arg(&prog_info.prog_type.name)
        .arg("--map-fds")
        .arg(map_fds_json)
        .arg("--input")
        .arg(verified_bin)
        .arg("--report")
        .arg(&report_json);
    append_candidate_load_context_args(&mut verify, prog_info, workdir)?;
    if use_fd_array {
        verify.arg("--fd-array").arg(fd_array_json);
    }
    let (output, report) = run_bpfverify_report_command(
        "bpfverify --report after bpfrejit failure",
        &mut verify,
        &report_json,
        "post-rejit-failure bpfverify report",
    )?;
    fs::write(&verifier_log_path, &report.verifier_log)
        .with_context(|| format!("write {}", verifier_log_path.display()))?;
    if !output.status.success() && report.status == "pass" {
        let program = format!("{verify:?}");
        let message = stage_failure_message(
            "bpfverify --report after bpfrejit failure",
            &program,
            &output,
        );
        eprintln!("daemon: {message}");
        bail!("{message}");
    }
    Ok(verifier_log_summary(&report.verifier_log))
}

fn write_original_verifier_states(
    config: &CliConfig,
    prog_info: &ProgInfoJson,
    workdir: &Path,
    prog_bin: &Path,
    map_fds_json: &Path,
    verifier_states_json: &Path,
) -> Result<()> {
    let original_verify_report = workdir.join("original_bpfverify_report.json");
    let mut verify = config.command("bpfverify");
    verify
        .arg("--prog-type")
        .arg(&prog_info.prog_type.name)
        .arg("--map-fds")
        .arg(map_fds_json)
        .arg("--input")
        .arg(prog_bin)
        .arg("--output")
        .arg(workdir.join("verified_original.bin"))
        .arg("--report")
        .arg(&original_verify_report)
        .arg("--verifier-states-out")
        .arg(verifier_states_json);
    append_verifier_states_load_context_args(&mut verify, prog_info);
    run_bpfverify_reported(
        "bpfverify original verifier-states",
        &mut verify,
        &original_verify_report,
        &workdir.join("verifier.log"),
    )
    .context("bpfverify --verifier-states-out failed")?;
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
    map_fds_json: &Path,
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
    let maps: Vec<MapInfoJson> = read_json_file(map_fds_json, "map_fds.json")?;
    let mut entries_by_map = BTreeMap::<u32, BTreeMap<Vec<u8>, Option<Vec<u8>>>>::new();

    for map in &maps {
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

    write_map_values_snapshot(&maps, &entries_by_map, output)
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

fn write_fd_array_from_target(target_path: &Path, passes: &[String], output: &Path) -> Result<()> {
    let target: TargetJson = read_json_file(target_path, "target.json")?;
    let mut target_value: serde_json::Value = read_json_file(target_path, "target.json")?;
    let mut entries = Vec::new();
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
        let slot = entries.len() + 1;
        let call_offset = i16::try_from(slot)
            .with_context(|| format!("fd_array slot {slot} for target kinsn {name}"))?;
        write_kinsn_call_offset(&mut target_value, name, call_offset)?;
        entries.push(FdArrayJsonEntry {
            slot,
            name: name.to_string(),
            btf_id,
        });
    }
    write_json_file(output, &entries)?;
    write_json_file(target_path, &target_value)
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

fn run_stage_output(stage: &str, command: &mut Command) -> Result<std::process::Output> {
    let program = format!("{command:?}");
    let output = command
        .output()
        .with_context(|| format!("spawn subprocess {program}"))?;
    if !output.status.success() {
        let message = stage_failure_message(stage, &program, &output);
        eprintln!("daemon: {message}");
        bail!("{message}");
    }
    Ok(output)
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
        .output()
        .with_context(|| format!("spawn subprocess {program}"))?;
    if !child_output.status.success() {
        let message = stage_failure_message(stage, &program, &child_output);
        eprintln!("daemon: {message}");
        bail!("{message}");
    }
    Ok(())
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

fn verifier_log_summary(log: &str) -> String {
    let trimmed = log.trim();
    if trimmed.is_empty() {
        return "<empty verifier log>".to_string();
    }
    const MAX_SUMMARY_CHARS: usize = 4096;
    let mut chars = trimmed.chars();
    let summary: String = chars.by_ref().take(MAX_SUMMARY_CHARS).collect();
    if chars.next().is_some() {
        format!("{summary}\n... verifier log truncated ...")
    } else {
        summary
    }
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
    use std::ffi::OsString;
    use std::os::unix::fs::PermissionsExt;
    use std::panic::{catch_unwind, resume_unwind, AssertUnwindSafe};
    use std::sync::Mutex as TestMutex;

    static ENV_LOCK: TestMutex<()> = TestMutex::new(());

    #[test]
    fn replay_btf_info_setup_uses_nonempty_metadata_files() {
        let prog_info = ProgInfoJson {
            id: 42,
            name: "conntrack_clean".to_string(),
            prog_type: TypeJson {
                name: "sched_cls".to_string(),
                numeric: kernel_sys::BPF_PROG_TYPE_SCHED_CLS,
            },
            insn_cnt: 12,
            map_ids: Vec::new(),
            btf_id: 108,
            func_info_rec_size: 8,
            nr_func_info: 2,
            line_info_rec_size: 16,
            nr_line_info: 3,
            attach_btf_obj_id: 0,
            attach_btf_id: 0,
            expected_attach_type: None,
        };

        let setup = replay_btf_info_setup(&prog_info);

        assert!(setup.contains("[ -s func_info.bin ]"));
        assert!(setup.contains("--func-info func_info.bin --func-info-rec-size 8"));
        assert!(setup.contains("[ -s line_info.bin ]"));
        assert!(setup.contains("--line-info line_info.bin --line-info-rec-size 16"));
    }

    #[test]
    fn candidate_load_context_skips_empty_btf_metadata_files() {
        let workdir = WorkDir::new("bpfrejit-daemon-empty-btf").unwrap();
        fs::write(workdir.path().join(FUNC_INFO_FILE), []).unwrap();
        fs::write(workdir.path().join(LINE_INFO_FILE), []).unwrap();
        let prog_info = ProgInfoJson {
            id: 42,
            name: "conntrack_clean".to_string(),
            prog_type: TypeJson {
                name: "sched_cls".to_string(),
                numeric: kernel_sys::BPF_PROG_TYPE_SCHED_CLS,
            },
            insn_cnt: 12,
            map_ids: Vec::new(),
            btf_id: 108,
            func_info_rec_size: 8,
            nr_func_info: 2,
            line_info_rec_size: 16,
            nr_line_info: 3,
            attach_btf_obj_id: 0,
            attach_btf_id: 0,
            expected_attach_type: None,
        };
        let mut command = Command::new("bpfverify");

        append_candidate_load_context_args(&mut command, &prog_info, workdir.path()).unwrap();

        let args = command
            .get_args()
            .map(|arg| arg.to_string_lossy().into_owned())
            .collect::<Vec<_>>();
        assert!(args.iter().any(|arg| arg == "--prog-btf-id"));
        assert!(!args.iter().any(|arg| arg == "--func-info"));
        assert!(!args.iter().any(|arg| arg == "--line-info"));
    }

    #[test]
    fn verifier_states_load_context_omits_optional_btf_metadata() {
        let prog_info = ProgInfoJson {
            id: 42,
            name: "conntrack_clean".to_string(),
            prog_type: TypeJson {
                name: "sched_cls".to_string(),
                numeric: kernel_sys::BPF_PROG_TYPE_SCHED_CLS,
            },
            insn_cnt: 12,
            map_ids: Vec::new(),
            btf_id: 108,
            func_info_rec_size: 8,
            nr_func_info: 2,
            line_info_rec_size: 16,
            nr_line_info: 3,
            attach_btf_obj_id: 0,
            attach_btf_id: 0,
            expected_attach_type: None,
        };
        let mut command = Command::new("bpfverify");

        append_verifier_states_load_context_args(&mut command, &prog_info);

        let args = command
            .get_args()
            .map(|arg| arg.to_string_lossy().into_owned())
            .collect::<Vec<_>>();
        assert!(args.iter().any(|arg| arg == "--prog-btf-id"));
        assert!(!args.iter().any(|arg| arg == "--func-info"));
        assert!(!args.iter().any(|arg| arg == "--line-info"));
    }

    #[test]
    fn live_map_values_snapshot_writes_values_and_lookup_misses() {
        let workdir = WorkDir::new("bpfrejit-daemon-map-values").unwrap();
        let map_fds = workdir.path().join("map_fds.json");
        let output = workdir.path().join(MAP_VALUES_FILE);
        fs::write(
            &map_fds,
            r#"[
  {"map_id":111,"map_type":2,"key_size":4,"value_size":4,"max_entries":8,"name":"array_map"},
  {"map_id":222,"map_type":1,"key_size":4,"value_size":4,"max_entries":8,"name":"hash_map"}
]
"#,
        )
        .unwrap();

        write_live_map_values(
            &map_fds,
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

    struct FakeCliDir {
        dir: WorkDir,
    }

    impl FakeCliDir {
        fn new() -> Result<Self> {
            let dir = WorkDir::new("bpfrejit-daemon-fake-cli")?;
            write_executable(
                &dir.path().join("bpfget"),
                r#"#!/usr/bin/env bash
set -euo pipefail
if [[ "${1:-}" == "--list" ]]; then
  printf '[{"id":42,"name":"demo","type":{"name":"xdp","numeric":6}}]\n'
  exit 0
fi
if [[ "${1:-}" == "--target" ]]; then
  out=""
  while [[ $# -gt 0 ]]; do
    case "$1" in
      --output) out="$2"; shift 2 ;;
      *) shift ;;
    esac
  done
  printf '{"arch":"x86_64","features":["cmov"],"kinsns":{}}\n' > "$out"
  exit 0
fi
prog_id="$1"
shift
outdir=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --full) shift ;;
    --outdir) outdir="$2"; shift 2 ;;
    *) shift ;;
  esac
done
printf '\xb7\x00\x00\x00\x00\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00' > "$outdir/prog.bin"
cat > "$outdir/prog_info.json" <<JSON
{"id":$prog_id,"name":"demo","type":{"name":"xdp","numeric":6},"insn_cnt":2,"map_ids":[],"func_info_rec_size":8,"nr_func_info":1,"line_info_rec_size":16,"nr_line_info":1}
JSON
cat > "$outdir/map_fds.json" <<JSON
[]
JSON
printf '\x00\x00\x00\x00\x01\x00\x00\x00' > "$outdir/func_info.bin"
printf '\x00\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00' > "$outdir/line_info.bin"
"#,
            )?;
            write_executable(
                &dir.path().join("bpfopt"),
                r#"#!/usr/bin/env bash
set -euo pipefail
report=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --report) report="$2"; shift 2 ;;
    --target) printf 'unexpected --target\n' >&2; exit 2 ;;
    *) shift ;;
  esac
done
cat >/dev/null
printf '\xb7\x00\x00\x00\x01\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00'
cat > "$report" <<JSON
{"passes":[{"pass":"wide_mem","changed":true,"sites_applied":2,"insn_count_before":2,"insn_count_after":2,"insn_delta":0}]}
JSON
"#,
            )?;
            write_executable(
                &dir.path().join("bpfverify"),
                r#"#!/usr/bin/env bash
set -euo pipefail
input=""
output=""
states=""
report=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --input) input="$2"; shift 2 ;;
    --output) output="$2"; shift 2 ;;
    --report) report="$2"; shift 2 ;;
    --verifier-states-out) states="$2"; shift 2 ;;
    *) shift ;;
  esac
done
if [[ -n "$input" && -n "$output" ]]; then cp "$input" "$output"; fi
if [[ -n "$report" ]]; then
  cat > "$report" <<JSON
{"status":"pass","verifier_log":"synthetic verifier log","verifier_states":{"insns":[]},"insn_count":2,"log_level":2,"errno":null,"jited_size":64,"log_true_size":0}
JSON
fi
if [[ -n "$states" ]]; then printf '{"insns":[]}\n' > "$states"; fi
"#,
            )?;
            write_executable(
                &dir.path().join("bpfrejit"),
                r#"#!/usr/bin/env bash
set -euo pipefail
prog_id="$1"
shift
out=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --output) out="$2"; shift 2 ;;
    *) shift ;;
  esac
done
if [[ -n "$out" ]]; then
  printf '{"status":"ok","prog_id":%s,"insn_count_before":2,"insn_count_after":2}\n' "$prog_id" > "$out"
fi
"#,
            )?;
            write_executable(
                &dir.path().join("bpfprof"),
                r#"#!/usr/bin/env bash
set -euo pipefail
outdir=""
per_site=0
while [[ $# -gt 0 ]]; do
  case "$1" in
    --per-site) per_site=1; shift ;;
    --output-dir) outdir="$2"; shift 2 ;;
    *) shift ;;
  esac
done
if [[ "$per_site" -ne 1 ]]; then
  echo "missing --per-site" >&2
  exit 1
fi
printf '{"prog_id":42,"duration_ms":1,"run_cnt_delta":1,"run_time_ns_delta":1,"branch_miss_rate":0.01,"branch_misses":1,"branch_instructions":100,"per_site":{"0":{"branch_count":100,"branch_misses":1,"miss_rate":0.01,"taken":90,"not_taken":10}}}\n' > "$outdir/42.json"
"#,
            )?;
            Ok(Self { dir })
        }

        fn config(&self) -> CliConfig {
            CliConfig::with_dir(self.dir.path().to_path_buf())
        }

        fn replace_command(&self, name: &str, text: &str) -> Result<()> {
            write_executable(&self.dir.path().join(name), text)
        }
    }

    fn write_executable(path: &Path, text: &str) -> Result<()> {
        let tmp_path = path.with_file_name(format!(
            "{}.tmp-{}",
            path.file_name()
                .and_then(|name| name.to_str())
                .unwrap_or("fake-cli"),
            NEXT_WORKDIR_ID.fetch_add(1, Ordering::Relaxed)
        ));
        fs::write(&tmp_path, text)?;
        let mut permissions = fs::metadata(&tmp_path)?.permissions();
        permissions.set_mode(0o755);
        fs::set_permissions(&tmp_path, permissions)?;
        fs::rename(&tmp_path, path)?;
        Ok(())
    }

    fn with_daemon_export_env<T>(
        failure_root: &Path,
        keep_all_workdirs: Option<&str>,
        f: impl FnOnce() -> T,
    ) -> T {
        let _guard = ENV_LOCK
            .lock()
            .expect("failure export env lock should not be poisoned");
        let old_root = std::env::var_os(FAILURE_ROOT_ENV);
        let old_keep_all_workdirs = std::env::var_os(KEEP_ALL_WORKDIRS_ENV);
        std::env::set_var(FAILURE_ROOT_ENV, failure_root);
        if let Some(value) = keep_all_workdirs {
            std::env::set_var(KEEP_ALL_WORKDIRS_ENV, value);
        } else {
            std::env::remove_var(KEEP_ALL_WORKDIRS_ENV);
        }
        let result = catch_unwind(AssertUnwindSafe(f));
        restore_env(FAILURE_ROOT_ENV, old_root);
        restore_env(KEEP_ALL_WORKDIRS_ENV, old_keep_all_workdirs);
        match result {
            Ok(value) => value,
            Err(payload) => resume_unwind(payload),
        }
    }

    fn with_failure_export_env<T>(failure_root: &Path, f: impl FnOnce() -> T) -> T {
        with_daemon_export_env(failure_root, None, f)
    }

    fn with_temp_failure_root<T>(f: impl FnOnce(&Path) -> T) -> T {
        let failure_root = WorkDir::new("bpfrejit-daemon-failure-root").unwrap();
        with_failure_export_env(failure_root.path(), || f(failure_root.path()))
    }

    fn with_clean_daemon_export_env<T>(f: impl FnOnce() -> T) -> T {
        let _guard = ENV_LOCK
            .lock()
            .expect("failure export env lock should not be poisoned");
        let old_root = std::env::var_os(FAILURE_ROOT_ENV);
        let old_keep_all_workdirs = std::env::var_os(KEEP_ALL_WORKDIRS_ENV);
        std::env::remove_var(FAILURE_ROOT_ENV);
        std::env::remove_var(KEEP_ALL_WORKDIRS_ENV);
        let result = catch_unwind(AssertUnwindSafe(f));
        restore_env(FAILURE_ROOT_ENV, old_root);
        restore_env(KEEP_ALL_WORKDIRS_ENV, old_keep_all_workdirs);
        match result {
            Ok(value) => value,
            Err(payload) => resume_unwind(payload),
        }
    }

    fn restore_env(name: &str, value: Option<OsString>) {
        if let Some(value) = value {
            std::env::set_var(name, value);
        } else {
            std::env::remove_var(name);
        }
    }

    #[test]
    fn failure_export_root_env_defaults_to_cwd() {
        with_clean_daemon_export_env(|| {
            let config = FailureExportConfig::from_env().unwrap();
            assert_eq!(
                config.root,
                std::env::current_dir()
                    .unwrap()
                    .join(DEFAULT_FAILURE_ROOT_NAME)
            );
        });
    }

    #[test]
    fn optimize_uses_cli_subprocesses_and_preserves_response_shape() {
        with_clean_daemon_export_env(|| {
            let fake = FakeCliDir::new().unwrap();
            let result = try_apply_one(
                42,
                &fake.config(),
                Some(&["wide_mem".to_string()]),
                None,
                None,
            )
            .unwrap();

            assert_eq!(result.status, "ok");
            assert_eq!(result.prog_id, 42);
            assert!(result.changed);
            assert_eq!(result.passes_applied, vec!["wide_mem"]);
            assert!(result.summary.applied);
            assert_eq!(result.summary.total_sites_applied, 2);
            assert_eq!(result.summary.passes_executed, 1);
            assert!(result.passes[0].changed);
        });
    }

    #[test]
    fn keep_all_workdirs_env_preserves_success_workdir() {
        let failure_root = WorkDir::new("bpfrejit-daemon-debug-failure-root").unwrap();
        with_daemon_export_env(failure_root.path(), Some("1"), || {
            let fake = FakeCliDir::new().unwrap();

            let result = try_apply_one(
                42,
                &fake.config(),
                Some(&["wide_mem".to_string()]),
                None,
                None,
            )
            .unwrap();

            assert_eq!(result.status, "ok");
            let debug_dir = failure_root.path().join("workdirs").join("42");
            assert!(debug_dir.is_dir());
            assert!(debug_dir.join("prog.bin").is_file());
            assert!(debug_dir.join("prog_info.json").is_file());
            assert!(debug_dir.join("map_fds.json").is_file());
            assert!(!debug_dir.join(MAP_VALUES_FILE).exists());
            assert!(!debug_dir.join(VERIFIER_STATES_FILE).exists());
            assert!(debug_dir.join("bpfopt_report.json").is_file());
        });
    }

    #[test]
    fn successful_optimize_does_not_preserve_debug_workdir_by_default() {
        with_temp_failure_root(|failure_root| {
            let fake = FakeCliDir::new().unwrap();

            let result = try_apply_one(
                42,
                &fake.config(),
                Some(&["wide_mem".to_string()]),
                None,
                None,
            )
            .unwrap();

            assert_eq!(result.status, "ok");
            assert!(!failure_root.join("workdirs").exists());
        });
    }

    #[test]
    fn optimize_passes_btf_metadata_to_bpfopt_for_in_place_remap() {
        with_clean_daemon_export_env(|| {
            let fake = FakeCliDir::new().unwrap();
            fake.replace_command(
                "bpfopt",
                r#"#!/usr/bin/env bash
set -euo pipefail
report=""
func_info=""
line_info=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --report) report="$2"; shift 2 ;;
    --func-info) func_info="$2"; shift 2 ;;
    --line-info) line_info="$2"; shift 2 ;;
    *) shift ;;
  esac
done
test -s "$func_info"
test -s "$line_info"
cat >/dev/null
printf '\xb7\x00\x00\x00\x01\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00'
cat > "$report" <<JSON
{"passes":[{"pass":"wide_mem","changed":true,"sites_applied":1,"insn_count_before":2,"insn_count_after":2,"insn_delta":0}]}
JSON
"#,
            )
            .unwrap();

            let result = try_apply_one(
                42,
                &fake.config(),
                Some(&["wide_mem".to_string()]),
                None,
                None,
            )
            .unwrap();

            assert_eq!(result.status, "ok");
            assert_eq!(result.summary.total_sites_applied, 1);
        });
    }

    #[test]
    fn fd_array_generation_rewrites_target_call_offsets() {
        let dir = WorkDir::new("bpfrejit-daemon-target-test").unwrap();
        let target = dir.path().join("target.json");
        let fd_array = dir.path().join("fd_array.json");
        fs::write(
            &target,
            r#"{
  "arch": "x86_64",
  "features": ["cmov"],
  "kinsns": {
    "bpf_rotate64": {"btf_func_id": 129879, "btf_id": 42},
    "bpf_select64": {"btf_func_id": 129880, "btf_id": 43}
  }
}
"#,
        )
        .unwrap();

        write_fd_array_from_target(
            &target,
            &["rotate".to_string(), "cond_select".to_string()],
            &fd_array,
        )
        .unwrap();

        let fd_entries: serde_json::Value =
            serde_json::from_slice(&fs::read(&fd_array).unwrap()).unwrap();
        assert_eq!(fd_entries[0]["slot"], 1);
        assert_eq!(fd_entries[0]["btf_id"], 42);
        assert_eq!(fd_entries[1]["slot"], 2);
        assert_eq!(fd_entries[1]["btf_id"], 43);

        let rewritten: serde_json::Value =
            serde_json::from_slice(&fs::read(&target).unwrap()).unwrap();
        assert_eq!(rewritten["kinsns"]["bpf_rotate64"]["call_offset"], 1);
        assert_eq!(rewritten["kinsns"]["bpf_select64"]["call_offset"], 2);
    }

    #[test]
    fn fd_array_generation_rewrites_prefetch_call_offset() {
        let dir = WorkDir::new("bpfrejit-daemon-prefetch-target-test").unwrap();
        let target = dir.path().join("target.json");
        let fd_array = dir.path().join("fd_array.json");
        fs::write(
            &target,
            r#"{
  "arch": "x86_64",
  "features": ["cmov"],
  "kinsns": {
    "bpf_prefetch": {"btf_func_id": 129900, "btf_id": 51}
  }
}
"#,
        )
        .unwrap();

        write_fd_array_from_target(&target, &["prefetch".to_string()], &fd_array).unwrap();

        let fd_entries: serde_json::Value =
            serde_json::from_slice(&fs::read(&fd_array).unwrap()).unwrap();
        assert_eq!(fd_entries[0]["slot"], 1);
        assert_eq!(fd_entries[0]["name"], "bpf_prefetch");
        assert_eq!(fd_entries[0]["btf_id"], 51);

        let rewritten: serde_json::Value =
            serde_json::from_slice(&fs::read(&target).unwrap()).unwrap();
        assert_eq!(rewritten["kinsns"]["bpf_prefetch"]["call_offset"], 1);
    }

    #[test]
    fn missing_target_kinsn_is_error() {
        with_temp_failure_root(|_| {
            let fake = FakeCliDir::new().unwrap();
            let err = try_apply_one(
                42,
                &fake.config(),
                Some(&["rotate".to_string()]),
                None,
                None,
            )
            .unwrap_err();

            let message = format!("{err:#}");
            assert!(message.contains("bpfget --target did not expose kinsns"));
            assert!(message.contains("bpf_rotate64"));
        });
    }

    #[test]
    fn verifier_states_failure_is_error() {
        with_temp_failure_root(|_| {
            let fake = FakeCliDir::new().unwrap();
            fake.replace_command(
                "bpfverify",
                r#"#!/usr/bin/env bash
set -euo pipefail
while [[ $# -gt 0 ]]; do
  case "$1" in
    --verifier-states-out) printf 'synthetic verifier state failure\n' >&2; exit 7 ;;
    *) shift ;;
  esac
done
"#,
            )
            .unwrap();

            let err = try_apply_one(
                42,
                &fake.config(),
                Some(&["const_prop".to_string()]),
                None,
                None,
            )
            .unwrap_err();

            let message = format!("{err:#}");
            assert!(message.contains("bpfverify --verifier-states-out failed"));
            assert!(message.contains("synthetic verifier state failure"));
        });
    }

    #[test]
    fn prefetch_does_not_capture_unused_verifier_states() {
        with_clean_daemon_export_env(|| {
            let fake = FakeCliDir::new().unwrap();
            fake.replace_command(
                "bpfget",
                r#"#!/usr/bin/env bash
set -euo pipefail
if [[ "${1:-}" == "--target" ]]; then
  out=""
  while [[ $# -gt 0 ]]; do
    case "$1" in
      --output) out="$2"; shift 2 ;;
      *) shift ;;
    esac
  done
  cat > "$out" <<JSON
{"arch":"x86_64","features":["cmov"],"kinsns":{"bpf_prefetch":{"btf_func_id":500,"btf_id":51}}}
JSON
  exit 0
fi
prog_id="$1"
shift
outdir=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --full) shift ;;
    --outdir) outdir="$2"; shift 2 ;;
    *) shift ;;
  esac
done
printf '\xb7\x00\x00\x00\x00\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00' > "$outdir/prog.bin"
cat > "$outdir/prog_info.json" <<JSON
{"id":$prog_id,"name":"demo","type":{"name":"xdp","numeric":6},"insn_cnt":2,"map_ids":[]}
JSON
printf '[]\n' > "$outdir/map_fds.json"
"#,
            )
            .unwrap();
            fake.replace_command(
                "bpfverify",
                r#"#!/usr/bin/env bash
set -euo pipefail
while [[ $# -gt 0 ]]; do
  case "$1" in
    --verifier-states-out) printf 'unexpected verifier state capture\n' >&2; exit 7 ;;
    *) shift ;;
  esac
done
"#,
            )
            .unwrap();
            fake.replace_command(
                "bpfopt",
                r#"#!/usr/bin/env bash
set -euo pipefail
report=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --report) report="$2"; shift 2 ;;
    *) shift ;;
  esac
done
cat >/dev/null
printf '\xb7\x00\x00\x00\x00\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00'
cat > "$report" <<JSON
{"passes":[{"pass":"prefetch","changed":false,"sites_applied":0,"insn_count_before":2,"insn_count_after":2,"insn_delta":0}]}
JSON
"#,
            )
            .unwrap();

            let result = try_apply_one(
                42,
                &fake.config(),
                Some(&["prefetch".to_string()]),
                None,
                None,
            )
            .unwrap();

            assert_eq!(result.status, "ok");
            assert!(!result.changed);
            assert_eq!(result.summary.total_sites_applied, 0);
        });
    }

    #[test]
    fn final_verify_failure_is_error() {
        with_temp_failure_root(|_| {
            let fake = FakeCliDir::new().unwrap();
            fake.replace_command(
                "bpfverify",
                r#"#!/usr/bin/env bash
set -euo pipefail
input=""
output=""
states=""
report=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --input) input="$2"; shift 2 ;;
    --output) output="$2"; shift 2 ;;
    --report) report="$2"; shift 2 ;;
    --verifier-states-out) states="$2"; shift 2 ;;
    *) shift ;;
  esac
done
if [[ -n "$states" ]]; then
  if [[ -n "$input" && -n "$output" ]]; then cp "$input" "$output"; fi
  if [[ -n "$report" ]]; then
    cat > "$report" <<JSON
{"status":"pass","verifier_log":"synthetic verifier log","verifier_states":{"insns":[]},"insn_count":2,"log_level":2,"errno":null,"jited_size":64,"log_true_size":0}
JSON
  fi
  printf '{"insns":[]}\n' > "$states"
  exit 0
fi
printf 'synthetic final verifier failure\n' >&2
exit 9
"#,
            )
            .unwrap();

            let err = try_apply_one(
                42,
                &fake.config(),
                Some(&["wide_mem".to_string()]),
                None,
                None,
            )
            .unwrap_err();

            let message = format!("{err:#}");
            assert!(message.contains("bpfverify final verification failed"));
            assert!(message.contains("synthetic final verifier failure"));
        });
    }

    #[test]
    fn rejit_failure_is_error() {
        with_temp_failure_root(|_| {
            let fake = FakeCliDir::new().unwrap();
            fake.replace_command(
                "bpfrejit",
                r#"#!/usr/bin/env bash
set -euo pipefail
printf 'synthetic rejit failure\n' >&2
exit 11
"#,
            )
            .unwrap();

            let err = try_apply_one(
                42,
                &fake.config(),
                Some(&["wide_mem".to_string()]),
                None,
                None,
            )
            .unwrap_err();

            let message = format!("{err:#}");
            assert!(message.contains("bpfrejit failed for prog 42"));
            assert!(message.contains("synthetic rejit failure"));
        });
    }

    #[test]
    fn rejit_failure_preserves_workdir_and_captures_verifier_log() {
        with_temp_failure_root(|failure_root| {
            let fake = FakeCliDir::new().unwrap();
            fake.replace_command(
                "bpfrejit",
                r#"#!/usr/bin/env bash
set -euo pipefail
printf 'synthetic rejit failure\n' >&2
exit 11
"#,
            )
            .unwrap();

            let err = try_apply_one(
                42,
                &fake.config(),
                Some(&["wide_mem".to_string()]),
                None,
                None,
            )
            .unwrap_err();

            let message = format!("{err:#}");
            assert!(message.contains("preserved failure workdir"));
            assert!(message.contains("bpfrejit failed for prog 42"));
            assert!(message.contains("verifier log summary"));
            assert!(message.contains("synthetic verifier log"));

            let failure_dir = failure_root.join("42");
            assert!(failure_dir.is_dir());
            for name in [
                "prog.bin",
                "prog.bpf",
                "opt.bin",
                "verified.bin",
                "map_fds.json",
                "info.json",
                "replay.sh",
                "bpfopt_report.json",
                "bpfverify_report.json",
                "verifier.log",
                "bpfrejit_failure_bpfverify_report.json",
                "bpfrejit_failure_verifier.log",
            ] {
                assert!(
                    failure_dir.join(name).exists(),
                    "missing preserved artifact {name}"
                );
            }
            assert_eq!(
                fs::read_to_string(failure_dir.join("verifier.log")).unwrap(),
                "synthetic verifier log"
            );
        });
    }

    #[test]
    fn reapply_force_rejit_reinstalls_candidate_even_when_unchanged() {
        with_clean_daemon_export_env(|| {
            let fake = FakeCliDir::new().unwrap();
            let marker = fake.dir.path().join("rejit-called");
            let marker_arg = marker.to_string_lossy().to_string();
            fake.replace_command(
                "bpfopt",
r#"#!/usr/bin/env bash
set -euo pipefail
report=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --report) report="$2"; shift 2 ;;
    *) shift ;;
  esac
done
cat >/dev/null
printf '\xb7\x00\x00\x00\x00\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00'
cat > "$report" <<JSON
{"passes":[{"pass":"wide_mem","changed":false,"sites_applied":0,"insn_count_before":2,"insn_count_after":2,"insn_delta":0}]}
JSON
"#,
            )
            .unwrap();
            fake.replace_command(
                "bpfrejit",
                &format!(
                    r#"#!/usr/bin/env bash
set -euo pipefail
prog_id="$1"
shift
out=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --output) out="$2"; shift 2 ;;
    *) shift ;;
  esac
done
printf 'called\n' > {marker_arg:?}
if [[ -n "$out" ]]; then
  printf '{{"status":"ok","prog_id":%s,"insn_count_before":2,"insn_count_after":2}}\n' "$prog_id" > "$out"
fi
"#
                ),
            )
            .unwrap();

            let result = try_reapply_one(
                42,
                &fake.config(),
                Some(&["wide_mem".to_string()]),
                None,
                None,
            )
            .unwrap();

            assert!(!result.changed);
            assert!(result.summary.applied);
            assert!(marker.exists());
        });
    }

    #[test]
    fn map_inline_report_records_refresh_invalidation_tracker_after_rejit() {
        with_clean_daemon_export_env(|| {
            let fake = FakeCliDir::new().unwrap();
            fake.replace_command(
                "bpfget",
                r#"#!/usr/bin/env bash
set -euo pipefail
prog_id="$1"
shift
outdir=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --full) shift ;;
    --outdir) outdir="$2"; shift 2 ;;
    *) shift ;;
  esac
done
printf '\xb7\x00\x00\x00\x00\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00' > "$outdir/prog.bin"
cat > "$outdir/prog_info.json" <<JSON
{"id":$prog_id,"name":"demo","type":{"name":"xdp","numeric":6},"insn_cnt":2,"map_ids":[111]}
JSON
cat > "$outdir/map_fds.json" <<JSON
[{"map_id":111,"map_type":2,"key_size":4,"value_size":4,"max_entries":8,"name":"demo_map"}]
JSON
"#,
            )
            .unwrap();
            fake.replace_command(
                "bpfopt",
r#"#!/usr/bin/env bash
set -euo pipefail
report=""
map_values=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --report) report="$2"; shift 2 ;;
    --map-values) map_values="$2"; shift 2 ;;
    *) shift ;;
  esac
done
grep -q '"value": "07000000"' "$map_values"
cat >/dev/null
printf '\xb7\x00\x00\x00\x01\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00'
cat > "$report" <<JSON
{"passes":[{"pass":"map_inline","changed":true,"sites_applied":1,"insn_count_before":2,"insn_count_after":2,"insn_delta":0,"map_inline_records":[{"map_id":111,"key_hex":"01000000","value_hex":"07000000"}]}]}
JSON
"#,
            )
            .unwrap();
            let tracker = new_invalidation_tracker();
            let config = fake.config();
            let enabled_passes = ["map_inline".to_string()];

            let result = try_apply_one_with_map_access(
                ApplyOneRequest {
                    prog_id: 42,
                    config: &config,
                    enabled_passes: Some(&enabled_passes),
                    profile_path: None,
                    invalidation_tracker: Some(&tracker),
                    force_rejit: false,
                },
                |_map_id| Ok(std::fs::File::open("/dev/null")?.into()),
                |_map, _fd, key| {
                    assert_eq!(key, 1u32.to_le_bytes().as_slice());
                    Ok(Some(7u32.to_le_bytes().to_vec()))
                },
                |_map, _fd| Ok(vec![1u32.to_le_bytes().to_vec()]),
            )
            .unwrap();

            assert_eq!(
                result.inlined_map_entries,
                vec![InlinedMapEntry {
                    map_id: 111,
                    key_hex: "01000000".to_string(),
                    value_hex: "07000000".to_string(),
                }]
            );
            let tracker = tracker.lock().expect("tracker lock should not be poisoned");
            assert!(tracker.tracks_prog(42));
            assert_eq!(tracker.entry_count(), 1);
        });
    }

    #[test]
    fn reapply_map_inline_hash_lookup_miss_completes_rejit() {
        with_clean_daemon_export_env(|| {
            let fake = FakeCliDir::new().unwrap();
            fake.replace_command(
                "bpfget",
                r#"#!/usr/bin/env bash
set -euo pipefail
prog_id="$1"
shift
outdir=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --full) shift ;;
    --outdir) outdir="$2"; shift 2 ;;
    *) shift ;;
  esac
done
printf '\xb7\x00\x00\x00\x00\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00' > "$outdir/prog.bin"
cat > "$outdir/prog_info.json" <<JSON
{"id":$prog_id,"name":"demo","type":{"name":"xdp","numeric":6},"insn_cnt":2,"map_ids":[111]}
JSON
cat > "$outdir/map_fds.json" <<JSON
[{"map_id":111,"map_type":1,"key_size":4,"value_size":4,"max_entries":8,"name":"hash_map"}]
JSON
"#,
            )
            .unwrap();
            fake.replace_command(
                "bpfopt",
r#"#!/usr/bin/env bash
set -euo pipefail
report=""
map_values=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --report) report="$2"; shift 2 ;;
    --map-values) map_values="$2"; shift 2 ;;
    *) shift ;;
  esac
done
grep -q '"value": null' "$map_values"
cat >/dev/null
printf '\xb7\x00\x00\x00\x00\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00'
cat > "$report" <<JSON
{"passes":[{"pass":"map_inline","changed":false,"sites_applied":0,"insn_count_before":2,"insn_count_after":2,"insn_delta":0}]}
JSON
"#,
            )
            .unwrap();
            let config = fake.config();
            let enabled_passes = ["map_inline".to_string()];

            let result = try_apply_one_with_map_access(
                ApplyOneRequest {
                    prog_id: 42,
                    config: &config,
                    enabled_passes: Some(&enabled_passes),
                    profile_path: None,
                    invalidation_tracker: None,
                    force_rejit: true,
                },
                |_map_id| Ok(std::fs::File::open("/dev/null")?.into()),
                |_map, _fd, key| {
                    assert_eq!(key, 1u32.to_le_bytes().as_slice());
                    Ok(None)
                },
                |_map, _fd| Ok(vec![1u32.to_le_bytes().to_vec()]),
            )
            .unwrap();

            assert!(!result.changed);
            assert!(result.summary.applied);
            assert_eq!(result.summary.total_sites_applied, 0);
            assert!(result.inlined_map_entries.is_empty());
        });
    }

    #[test]
    fn profile_start_stop_uses_bpfprof_per_site_output_dir() {
        let fake = FakeCliDir::new().unwrap();
        let session = start_profile(&fake.config(), 1).unwrap();
        let frozen = stop_profile(session).unwrap();

        assert_eq!(frozen.programs_profiled(), 1);
        let profile_path = frozen.profile_path_for(42).unwrap();
        let profile: serde_json::Value =
            serde_json::from_slice(&std::fs::read(profile_path).unwrap()).unwrap();
        assert_eq!(profile["branch_miss_rate"], 0.01);
        assert_eq!(profile["per_site"]["0"]["branch_count"], 100);
        assert!(profile.get("per_insn").is_none());
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
}
