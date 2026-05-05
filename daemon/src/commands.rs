// SPDX-License-Identifier: MIT
//! Socket command helpers.
//!
//! `bpfopt` remains the external bytecode CLI. The daemon owns live discovery,
//! pass orchestration, per-pass verifier acceptance, short-lived fd_array
//! construction, and per-pass `BPF_PROG_REJIT`.

use std::collections::{BTreeMap, HashMap};
use std::fs;
use std::io::Write;
use std::os::fd::{AsFd, AsRawFd, OwnedFd};
use std::path::{Path, PathBuf};
use std::process::{Command, Stdio};
use std::sync::atomic::{AtomicU64, Ordering};
use std::thread;
use std::time::{Duration, Instant};

use anyhow::{anyhow, bail, Context, Result};
use rayon::prelude::*;
use serde::{Deserialize, Serialize};

use crate::bpf;

static NEXT_WORKDIR_ID: AtomicU64 = AtomicU64::new(0);
/// CLI binary directory set once at startup; None means use PATH lookup.
static CLI_DIR: std::sync::OnceLock<Option<PathBuf>> = std::sync::OnceLock::new();
const MAP_VALUES_FILE: &str = "map-values.json";
const VERIFIER_STATES_FILE: &str = "verifier-states.json";
const DEFAULT_CLI_STAGE_TIMEOUT: Duration = Duration::from_secs(5);
const OPTIMIZE_CLI_STAGE_TIMEOUT: Duration = Duration::from_secs(60);
const CLI_STAGE_POLL_INTERVAL: Duration = Duration::from_millis(100);
const REJIT_LOG_BUF_SIZE: usize = 16 * 1024 * 1024;

#[derive(Clone, Debug)]
pub(crate) struct CliConfig {
    cli_dir: Option<PathBuf>,
}

impl CliConfig {
    /// Read cli_dir from the process-global set by init_cli_dir.
    /// In tests where init_cli_dir was not called, returns CliConfig { cli_dir: None }.
    pub(crate) fn from_global() -> Self {
        let cli_dir = CLI_DIR.get().and_then(|opt| opt.clone());
        Self { cli_dir }
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

/// Initialise the CLI dir (None = use PATH lookup).
/// Must be called exactly once before the server loop starts.
pub(crate) fn init_cli_dir() -> Result<()> {
    CLI_DIR
        .set(None)
        .map_err(|_| anyhow!("CLI dir already initialised"))
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
    #[serde(skip_serializing_if = "Vec::is_empty", default)]
    pub skipped_maps: Vec<SkippedMapEntry>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub error_message: Option<String>,
}

impl OptimizeOneResult {
    pub(crate) fn error(prog_id: u32, message: impl Into<String>) -> Self {
        Self {
            status: "error".to_string(),
            prog_id,
            changed: false,
            passes_applied: Vec::new(),
            program: ProgramInfo {
                prog_id,
                prog_name: String::new(),
                prog_type: 0,
                orig_insn_count: 0,
                final_insn_count: 0,
                insn_delta: 0,
            },
            summary: OptimizeSummary {
                applied: false,
                total_sites_applied: 0,
                passes_executed: 0,
                passes_changed: 0,
            },
            passes: Vec::new(),
            inlined_map_entries: Vec::new(),
            skipped_maps: Vec::new(),
            error_message: Some(message.into()),
        }
    }
}

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
pub(crate) struct InlinedMapEntry {
    pub map_id: u32,
    pub key_hex: String,
    pub value_hex: String,
}

/// A map whose keys could not be fully scanned during map_inline value preparation.
/// The map is excluded from map-value side-input (fewer inline opportunities) but the
/// pass and program are NOT skipped — this is a capability limitation, not an error.
#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
pub(crate) struct SkippedMapEntry {
    pub map_id: u32,
    pub reason: String,
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

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
#[serde(rename_all = "snake_case")]
pub(crate) enum PassStatus {
    Ok,
    Unchanged,
    SkippedMissingStates,
    FailedBpfopt,
    FailedRejit,
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct PassDetail {
    #[serde(rename = "pass")]
    pub pass_name: String,
    pub status: PassStatus,
    pub changed: bool,
    pub sites_applied: usize,
    pub insns_before: usize,
    pub insns_after: usize,
    pub insn_delta: i64,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub error: Option<String>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub verifier_log: Option<String>,
}

#[derive(Clone, Debug)]
struct RejitReport {
    verifier_states: kernel_sys::VerifierStatesJson,
}

fn rejit_program(
    prog_id: u32,
    insns: &[kernel_sys::bpf_insn],
    fd_array: &RejitFdArray,
    verifier_log_path: &Path,
) -> Result<RejitReport> {
    let prog_fd = kernel_sys::prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open BPF program id {prog_id} for BPF_PROG_REJIT"))?;
    let mut log_buf = vec![0u8; REJIT_LOG_BUF_SIZE];
    if let Err(err) = kernel_sys::prog_rejit(
        prog_fd.as_fd(),
        insns,
        fd_array.as_slice(),
        Some(&mut log_buf),
    ) {
        let log = c_log_string(&log_buf);
        if !log.is_empty() {
            fs::write(verifier_log_path, log)
                .with_context(|| format!("write {}", verifier_log_path.display()))?;
        }
        return Err(err).context("kernel rejected BPF_PROG_REJIT");
    }
    let verifier_log = c_log_string(&log_buf);
    if verifier_log.is_empty() {
        bail!("BPF_PROG_REJIT for prog {prog_id} returned an empty verifier log");
    }
    fs::write(verifier_log_path, &verifier_log)
        .with_context(|| format!("write {}", verifier_log_path.display()))?;
    let verifier_states = kernel_sys::verifier_states_from_log(&verifier_log);
    if verifier_states.insns.is_empty() {
        bail!("BPF_PROG_REJIT verifier log for prog {prog_id} did not contain parseable state snapshots");
    }
    Ok(RejitReport { verifier_states })
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
    #[serde(default)]
    map_inline_records: Vec<BpfoptMapInlineRecord>,
}

#[derive(Clone, Debug, Deserialize)]
struct BpfoptMapInlineRecord {
    map_id: u32,
    key_hex: String,
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct MapInlineRecord {
    map_id: u32,
    key: Vec<u8>,
}

type MapValueSnapshot = BTreeMap<(u32, Vec<u8>), Vec<u8>>;

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
    /// BTF object ID containing this kinsn function.
    btf_id: u32,
    /// Non-zero fd_array index for the BTF module fd (0 = vmlinux, no fd needed).
    call_offset: u32,
}

pub(crate) fn default_worker_count() -> usize {
    let cpus = std::thread::available_parallelism()
        .map(|count| count.get())
        .unwrap_or(1);
    let capped = cpus.min(16);
    if cpus <= 4 {
        (capped / 2).max(1)
    } else {
        capped
    }
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

fn collect_map_inline_records(reports: &[BpfoptPassReport]) -> Result<Vec<MapInlineRecord>> {
    let mut records = Vec::new();
    for pass in reports {
        if canonical_pass(&pass.pass) != "map_inline" || !pass.changed {
            continue;
        }
        for record in &pass.map_inline_records {
            records.push(MapInlineRecord {
                map_id: record.map_id,
                key: decode_hex(&record.key_hex)
                    .with_context(|| format!("decode map_inline key for map {}", record.map_id))?,
            });
        }
    }
    Ok(records)
}

fn collect_inlined_map_entries(
    map_inline_records: &[MapInlineRecord],
    map_values: &MapValueSnapshot,
) -> Result<Vec<InlinedMapEntry>> {
    let mut deduped: BTreeMap<(u32, String), String> = BTreeMap::new();
    for record in map_inline_records {
        let value = map_values
            .get(&(record.map_id, record.key.clone()))
            .with_context(|| {
                format!(
                    "map_inline report referenced map {} key {} missing from live snapshot",
                    record.map_id,
                    hex_bytes(&record.key)
                )
            })?;
        deduped.insert((record.map_id, hex_bytes(&record.key)), hex_bytes(value));
    }

    Ok(deduped
        .into_iter()
        .map(|((map_id, key_hex), value_hex)| InlinedMapEntry {
            map_id,
            key_hex,
            value_hex,
        })
        .collect())
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

pub(crate) struct ApplyProgramOutcome {
    pub prog_id: u32,
    pub result: OptimizeOneResult,
}

fn panic_payload_message(payload: &(dyn std::any::Any + Send)) -> String {
    if let Some(message) = payload.downcast_ref::<String>() {
        return message.clone();
    }
    if let Some(message) = payload.downcast_ref::<&'static str>() {
        return (*message).to_string();
    }
    "non-string panic payload".to_string()
}

fn apply_program_catching_unwind<F>(prog_id: u32, apply: F) -> OptimizeOneResult
where
    F: FnOnce() -> Result<OptimizeOneResult>,
{
    match std::panic::catch_unwind(std::panic::AssertUnwindSafe(apply)) {
        Ok(Ok(result)) => result,
        Ok(Err(err)) => OptimizeOneResult::error(prog_id, format!("{err:#}")),
        Err(payload) => {
            let message = panic_payload_message(payload.as_ref());
            eprintln!("daemon: optimize worker panicked for prog {prog_id}: {message}");
            OptimizeOneResult::error(
                prog_id,
                format!("worker panicked while optimizing prog {prog_id}: {message}"),
            )
        }
    }
}

fn try_apply_programs_with<F>(
    prog_ids: &[u32],
    worker_count: usize,
    apply_one: F,
) -> Result<Vec<ApplyProgramOutcome>>
where
    F: Fn(u32) -> Result<OptimizeOneResult> + Sync,
{
    if prog_ids.is_empty() {
        bail!("optimize requires at least one prog_id");
    }
    let pool = rayon::ThreadPoolBuilder::new()
        .num_threads(worker_count)
        .thread_name(|idx| format!("bpfrejit-worker-{idx}"))
        .build()
        .context("build daemon optimization worker pool")?;

    Ok(pool.install(|| {
        prog_ids
            .par_iter()
            .map(|&prog_id| {
                let result = apply_program_catching_unwind(prog_id, || apply_one(prog_id));
                ApplyProgramOutcome { prog_id, result }
            })
            .collect()
    }))
}

pub(crate) fn try_apply_programs(
    prog_ids: &[u32],
    config: &CliConfig,
    enabled_passes: &[String],
) -> Result<Vec<ApplyProgramOutcome>> {
    let config = config.clone();
    let passes = enabled_passes.to_vec();

    try_apply_programs_with(prog_ids, default_worker_count(), |prog_id| {
        try_apply_one(prog_id, &config, &passes)
    })
}

pub(crate) fn try_apply_one(
    prog_id: u32,
    config: &CliConfig,
    enabled_passes: &[String],
) -> Result<OptimizeOneResult> {
    if enabled_passes.is_empty() {
        bail!("no enabled_passes provided by runner");
    }
    let pass_list = enabled_passes
        .iter()
        .map(|pass| canonical_pass(pass))
        .collect::<Vec<_>>();
    if pass_list.iter().any(|pass| pass.is_empty()) {
        bail!("enabled_passes entries must not be blank");
    }
    let workdir = WorkDir::new("bpfrejit-daemon-optimize")?;
    let prog_bin = workdir.path().join("prog.bin");
    let target_json = workdir.path().join("target.json");
    let verifier_states_json = workdir.path().join(VERIFIER_STATES_FILE);
    let map_values_json = workdir.path().join(MAP_VALUES_FILE);
    let opt_bin = workdir.path().join("opt.bin");
    let mut open_map_fd = bpf::bpf_map_get_fd_by_id;
    let mut lookup_map_value = live_bpf_map_lookup;
    let mut scan_map_keys = live_bpf_map_keys;

    let result = (|| -> Result<OptimizeOneResult> {
        let mut snapshot = bpfget::snapshot_program(prog_id)
            .with_context(|| format!("snapshot live BPF program {prog_id}"))?;
        bpf::canonicalize_map_refs_to_idx(&mut snapshot.insns, None, &snapshot.info.map_ids)
            .with_context(|| format!("canonicalize map references for prog {prog_id}"))?;
        let prog_info = snapshot.info.clone();
        let orig_bytes = bpfget::encode_insns(&snapshot.insns);
        fs::write(&prog_bin, &orig_bytes)
            .with_context(|| format!("write {}", prog_bin.display()))?;
        let orig_insn_count = insn_count_from_bytes(&orig_bytes, "prog.bin")?;
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
        let wants_map_inline = pass_list
            .iter()
            .any(|pass| canonical_pass(pass) == "map_inline");

        let mut skipped_maps = Vec::<SkippedMapEntry>::new();
        let mut map_value_snapshot = MapValueSnapshot::new();
        if wants_map_inline {
            (skipped_maps, map_value_snapshot) = write_live_map_values(
                &snapshot.maps,
                &map_values_json,
                &mut open_map_fd,
                &mut lookup_map_value,
                &mut scan_map_keys,
            )
            .with_context(|| format!("build live map value snapshot for prog {prog_id}"))?;
        }

        let mut probed_kinsns: HashMap<String, TargetKinsnJson> = HashMap::new();
        if needs_target(&pass_list) {
            let mut probed = bpfget::probe_target_json().with_context(|| {
                format!(
                    "probe target kinsns failed for requested passes {}",
                    join_pass_csv(&pass_list)
                )
            })?;
            shift_target_module_call_offsets_for_map_prefix(
                &mut probed,
                snapshot.info.map_ids.len(),
            )
            .with_context(|| format!("shift target module call_offsets for prog {prog_id}"))?;
            // Keep kinsns in memory for fd_array construction; also write to file
            // so bpfopt CLI can read it.
            for (name, kinsn) in &probed.kinsns {
                probed_kinsns.insert(
                    name.clone(),
                    TargetKinsnJson {
                        btf_func_id: kinsn.btf_func_id,
                        btf_id: kinsn.btf_id,
                        call_offset: kinsn.call_offset,
                    },
                );
            }
            write_json_file(&target_json, &probed)?;
            let missing_kinsns = missing_target_kinsns(&target_json, &pass_list)?;
            if !missing_kinsns.is_empty() {
                bail!(
                    "target probing did not expose kinsns required by requested passes {}: {}",
                    join_pass_csv(&pass_list),
                    missing_kinsns.join(", ")
                );
            }
        }
        let fd_array =
            build_rejit_fd_array(&snapshot.info.map_ids, &probed_kinsns, &mut open_map_fd)
                .with_context(|| format!("build fd_array for prog {prog_id}"))?;

        let map_ids = if wants_map_inline {
            Some(if prog_info.map_ids.is_empty() {
                "0".to_string()
            } else {
                join_u32_csv(&prog_info.map_ids)
            })
        } else {
            None
        };

        let mut current_bytes = orig_bytes.clone();
        let mut committed_reports = Vec::new();
        let mut verifier_states_ready = false;
        let mut committed_passes = 0usize;
        let reports = run_pass_chain(&pass_list, |idx, pass| -> Result<PassDetail> {
            let stem = pass_file_stem(idx, pass);
            let pass_input = workdir.path().join(format!("{stem}.in.bin"));
            let pass_output = workdir.path().join(format!("{stem}.out.bin"));
            let pass_report = workdir.path().join(format!("{stem}.report.json"));
            let pass_verifier_log = workdir.path().join(format!("{stem}.verifier.log"));
            fs::write(&pass_input, &current_bytes)
                .with_context(|| format!("write {}", pass_input.display()))?;

            let needs_states = pass_needs_verifier_states(pass);
            if needs_states && !verifier_states_ready {
                return pass_detail_without_report(
                    pass,
                    PassStatus::SkippedMissingStates,
                    &current_bytes,
                    Some(format!(
                        "pass {pass} requires verifier states from a previous successful per-pass ReJIT"
                    )),
                    None,
                );
            }
            let target_arg = pass_needs_target(pass).then_some(target_json.as_path());
            let verifier_states_arg = needs_states.then_some(verifier_states_json.as_path());
            let map_values_arg = (pass == "map_inline").then_some(map_values_json.as_path());
            let map_ids_arg = if pass == "map_inline" {
                Some(
                    map_ids
                        .as_deref()
                        .ok_or_else(|| anyhow!("map_inline pass missing map ids"))?,
                )
            } else {
                None
            };
            let report = match run_bpfopt_pass(
                config,
                pass,
                &prog_info,
                target_arg,
                verifier_states_arg,
                map_values_arg,
                map_ids_arg,
                &pass_input,
                &pass_output,
                &pass_report,
            ) {
                Ok(report) => report,
                Err(err) => {
                    return pass_detail_without_report(
                        pass,
                        PassStatus::FailedBpfopt,
                        &current_bytes,
                        Some(format!("{err:#}")),
                        None,
                    );
                }
            };
            let pass_bytes = match fs::read(&pass_output) {
                Ok(bytes) => bytes,
                Err(err) => {
                    return pass_detail_without_report(
                        pass,
                        PassStatus::FailedBpfopt,
                        &current_bytes,
                        Some(format!("read {}: {err}", pass_output.display())),
                        None,
                    );
                }
            };
            if !report.changed {
                return Ok(pass_detail_from_report(
                    &report,
                    PassStatus::Unchanged,
                    false,
                    None,
                    None,
                ));
            }
            let pass_insns = match decode_insns(&pass_bytes, pass_output.to_string_lossy().as_ref())
            {
                Ok(insns) => insns,
                Err(err) => {
                    return pass_detail_without_report(
                        pass,
                        PassStatus::FailedBpfopt,
                        &current_bytes,
                        Some(format!("{err:#}")),
                        None,
                    );
                }
            };
            let rejit_result = rejit_program(prog_id, &pass_insns, &fd_array, &pass_verifier_log);
            let rejit_report = match rejit_result {
                Ok(report) => report,
                Err(err) => {
                    return Ok(pass_detail_from_report(
                        &report,
                        PassStatus::FailedRejit,
                        false,
                        Some(format!("{err:#}")),
                        verifier_log_summary_from_path(&pass_verifier_log)?,
                    ));
                }
            };
            write_verifier_states_for_next_pass(&verifier_states_json, &rejit_report)
                .with_context(|| format!("write verifier states after pass {pass}"))?;
            verifier_states_ready = true;
            current_bytes = pass_bytes;
            committed_passes += 1;
            committed_reports.push(report.clone());
            Ok(pass_detail_from_report(
                &report,
                PassStatus::Ok,
                true,
                None,
                None,
            ))
        })?;
        fs::write(&opt_bin, &current_bytes)
            .with_context(|| format!("write {}", opt_bin.display()))?;
        let passes = reports;
        let map_inline_records = collect_map_inline_records(&committed_reports)?;
        let inlined_map_entries =
            collect_inlined_map_entries(&map_inline_records, &map_value_snapshot)?;
        let opt_bytes = current_bytes;
        let final_insn_count = insn_count_from_bytes(&opt_bytes, "opt.bin")?;
        let changed = opt_bytes != orig_bytes;
        let candidate_has_kinsn_call = bytecode_has_kinsn_call(&opt_bytes, "opt.bin")?;
        if candidate_has_kinsn_call && !needs_target(&pass_list) {
            bail!(
                "candidate bytecode contains kinsn call but requested passes did not require target probing"
            );
        }
        let status = "ok".to_string();
        let applied = committed_passes > 0;
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
            skipped_maps,
            error_message: None,
        })
    })();

    result
}

fn append_bpfopt_context_args(command: &mut Command, prog_info: &ProgInfoJson) {
    command.arg("--prog-type").arg(&prog_info.prog_type.name);
}

fn pass_needs_verifier_states(pass: &str) -> bool {
    matches!(pass, "const_prop" | "map_inline")
}

fn pass_needs_target(pass: &str) -> bool {
    matches!(
        pass,
        "rotate"
            | "cond_select"
            | "ccmp"
            | "extract"
            | "endian_fusion"
            | "bulk_memory"
            | "prefetch"
    )
}

fn pass_file_stem(index: usize, pass: &str) -> String {
    format!("pass-{index:02}-{pass}")
}

fn run_pass_chain<F>(pass_list: &[String], mut run_pass: F) -> Result<Vec<PassDetail>>
where
    F: FnMut(usize, &str) -> Result<PassDetail>,
{
    let mut reports = Vec::with_capacity(pass_list.len());
    for (idx, pass) in pass_list.iter().enumerate() {
        reports.push(run_pass(idx, pass)?);
    }
    Ok(reports)
}

fn run_bpfopt_pass(
    config: &CliConfig,
    pass: &str,
    prog_info: &ProgInfoJson,
    target: Option<&Path>,
    verifier_states: Option<&Path>,
    map_values: Option<&Path>,
    map_ids: Option<&str>,
    input: &Path,
    output: &Path,
    report: &Path,
) -> Result<BpfoptPassReport> {
    let mut bpfopt = config.command("bpfopt");
    bpfopt.arg("--pass").arg(pass).arg("--report").arg(report);
    append_bpfopt_context_args(&mut bpfopt, prog_info);
    if let Some(target) = target {
        bpfopt.arg("--target").arg(target);
    }
    if let Some(verifier_states) = verifier_states {
        bpfopt.arg("--verifier-states").arg(verifier_states);
    }
    if let Some(map_values) = map_values {
        bpfopt.arg("--map-values").arg(map_values);
    }
    if let Some(map_ids) = map_ids {
        bpfopt.arg("--map-ids").arg(map_ids);
    }
    run_stage_with_file_io("bpfopt pass", &mut bpfopt, input, output)
        .with_context(|| format!("bpfopt pass {pass} failed"))?;
    read_json_file(report, "bpfopt pass report")
        .with_context(|| format!("read bpfopt report for pass {pass}"))
}

fn write_verifier_states_for_next_pass(path: &Path, report: &RejitReport) -> Result<()> {
    if path.exists() {
        fs::remove_file(path).with_context(|| format!("remove stale {}", path.display()))?;
    }
    write_json_file(path, &report.verifier_states)?;
    require_nonempty_file(path, "verifier states")?;
    Ok(())
}

fn pass_detail_from_report(
    report: &BpfoptPassReport,
    status: PassStatus,
    changed: bool,
    error: Option<String>,
    verifier_log: Option<String>,
) -> PassDetail {
    let sites_applied = if changed { report.sites_applied } else { 0 };
    let insns_after = if changed {
        report.insn_count_after
    } else {
        report.insn_count_before
    };
    PassDetail {
        pass_name: report.pass.clone(),
        status,
        changed,
        sites_applied,
        insns_before: report.insn_count_before,
        insns_after,
        insn_delta: insns_after as i64 - report.insn_count_before as i64,
        error,
        verifier_log,
    }
}

fn pass_detail_without_report(
    pass: &str,
    status: PassStatus,
    current_bytes: &[u8],
    error: Option<String>,
    verifier_log: Option<String>,
) -> Result<PassDetail> {
    let insn_count = insn_count_from_bytes(current_bytes, "current pass input")?;
    Ok(PassDetail {
        pass_name: pass.to_string(),
        status,
        changed: false,
        sites_applied: 0,
        insns_before: insn_count,
        insns_after: insn_count,
        insn_delta: 0,
        error,
        verifier_log,
    })
}

fn verifier_log_summary_from_path(path: &Path) -> Result<Option<String>> {
    match fs::read_to_string(path) {
        Ok(log) => Ok(Some(kernel_sys::verifier_log_summary(&log))),
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => Ok(None),
        Err(err) => Err(err).with_context(|| format!("read {}", path.display())),
    }
}

fn write_live_map_values<F, G, H>(
    maps: &[MapInfoJson],
    output: &Path,
    open_map_fd: &mut F,
    lookup_map_value: &mut G,
    scan_map_keys: &mut H,
) -> Result<(Vec<SkippedMapEntry>, MapValueSnapshot)>
where
    F: FnMut(u32) -> Result<OwnedFd>,
    G: FnMut(&MapInfoJson, i32, &[u8]) -> Result<Option<Vec<u8>>>,
    H: FnMut(&MapInfoJson, i32) -> Result<Vec<Vec<u8>>>,
{
    let mut entries_by_map = BTreeMap::<u32, BTreeMap<Vec<u8>, Option<Vec<u8>>>>::new();
    let mut value_snapshot = MapValueSnapshot::new();
    let mut skipped = Vec::<SkippedMapEntry>::new();

    for map in maps {
        if !is_map_inlineable_map_type(map.map_type) {
            continue;
        }
        let fd = open_map_fd(map.map_id)
            .with_context(|| format!("open BPF map id {} for map-inline values", map.map_id))?;
        let keys = match scan_map_keys(map, fd.as_raw_fd()) {
            Ok(keys) => keys,
            Err(err) => {
                // A scan overflow is a known capability limitation: the kernel returns more
                // keys than max_entries (e.g. LRU maps with concurrent inserts). Skip this
                // map's entries so the pass can still run for other maps. Real IO/syscall
                // errors propagate unchanged because they represent unexpected failures.
                let reason = format!("{err:#}");
                if reason.contains("more than max_entries") {
                    eprintln!(
                        "daemon: map_inline skipping map {} (scan overflow: {})",
                        map.map_id, reason
                    );
                    skipped.push(SkippedMapEntry {
                        map_id: map.map_id,
                        reason,
                    });
                    continue;
                }
                return Err(err).with_context(|| format!("scan live keys for map {}", map.map_id));
            }
        };
        for key in keys {
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
            if let Some(value) = value.as_ref() {
                value_snapshot.insert((map.map_id, key.clone()), value.clone());
            }
            entries_by_map
                .entry(map.map_id)
                .or_default()
                .insert(key, value);
        }
    }

    write_map_values_snapshot(maps, &entries_by_map, output)?;
    Ok((skipped, value_snapshot))
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

fn shift_target_module_call_offsets_for_map_prefix(
    target: &mut bpfget::TargetJson,
    map_count: usize,
) -> Result<()> {
    let module_base = module_fd_array_base(map_count)?;
    for (name, kinsn) in &mut target.kinsns {
        if kinsn.call_offset == 0 {
            continue;
        }
        if kinsn.btf_id == 0 {
            bail!(
                "target kinsn {name} has call_offset {} but no BTF object id",
                kinsn.call_offset
            );
        }
        let shifted = module_base
            .checked_add(kinsn.call_offset - 1)
            .with_context(|| format!("target kinsn {name} call_offset overflow"))?;
        if shifted > i16::MAX as u32 {
            bail!(
                "target kinsn {name} shifted call_offset {shifted} exceeds BPF instruction off field"
            );
        }
        kinsn.call_offset = shifted;
    }
    Ok(())
}

#[derive(Debug)]
struct RejitFdArray {
    /// Full fd_array: map fds first so PSEUDO_MAP_IDX imm matches
    /// prog_info.map_ids order, followed by any BTF module fds at the
    /// target.json call_offset slots.
    fds: Vec<i32>,
    _owned_fds: Vec<OwnedFd>,
}

impl RejitFdArray {
    fn as_slice(&self) -> &[i32] {
        &self.fds
    }
}

/// Build the fd_array for BPF_PROG_REJIT.
///
/// Layout: map fds are stored at indexes 0..map_ids.len(), matching canonical
/// `PSEUDO_MAP_IDX` immediates. Module BTF fds follow at their non-zero
/// target.json `call_offset` indexes. If a program has no maps, slot 0 is a
/// duplicate valid BTF fd because module `CALL.off=0` is reserved for vmlinux.
fn build_rejit_fd_array<F>(
    map_ids: &[u32],
    kinsns: &HashMap<String, TargetKinsnJson>,
    open_map_fd: &mut F,
) -> Result<RejitFdArray>
where
    F: FnMut(u32) -> Result<OwnedFd>,
{
    build_rejit_fd_array_with_openers(
        map_ids,
        kinsns,
        &mut |btf_id| kernel_sys::btf_get_fd_by_id(btf_id),
        open_map_fd,
    )
}

fn build_rejit_fd_array_with_openers<B, F>(
    map_ids: &[u32],
    kinsns: &HashMap<String, TargetKinsnJson>,
    open_btf_fd: &mut B,
    open_map_fd: &mut F,
) -> Result<RejitFdArray>
where
    B: FnMut(u32) -> Result<OwnedFd>,
    F: FnMut(u32) -> Result<OwnedFd>,
{
    let mut fds = Vec::new();
    let mut owned_fds = Vec::new();

    // Collect distinct BTF module objects that have a non-zero call_offset.
    // Deduplicate by btf_id (multiple kinsns can share a module), then sort
    // by call_offset so fd_array[call_offset] holds the right module fd.
    let mut module_entries: Vec<(u32, u32)> = Vec::new(); // (call_offset, btf_id)
    for kinsn in kinsns.values() {
        if kinsn.call_offset == 0 {
            continue;
        }
        if kinsn.btf_id == 0 {
            bail!(
                "target.json kinsn has call_offset {} but no BTF object id",
                kinsn.call_offset
            );
        }
        if let Some((slot, _)) = module_entries
            .iter()
            .find(|(_, btf_id)| *btf_id == kinsn.btf_id)
        {
            if *slot != kinsn.call_offset {
                bail!(
                    "target.json BTF module id {} has conflicting call_offsets: {} and {}",
                    kinsn.btf_id,
                    slot,
                    kinsn.call_offset
                );
            }
        } else {
            module_entries.push((kinsn.call_offset, kinsn.btf_id));
        }
    }
    module_entries.sort_by_key(|(slot, _)| *slot);

    let module_base = module_fd_array_base(map_ids.len())?;

    // Validate: call_offsets must be contiguous after the map-fd prefix.
    for (expected_slot, (actual_slot, btf_id)) in module_entries
        .iter()
        .enumerate()
        .map(|(i, e)| (module_base + i as u32, e))
    {
        if *actual_slot != expected_slot {
            bail!(
                "target.json BTF module call_offsets are not contiguous: \
                 expected slot {expected_slot} but got slot {actual_slot} for btf_id {btf_id}"
            );
        }
    }

    // Append map fds first; canonical map indexes directly address this prefix.
    for &map_id in map_ids {
        let fd = open_map_fd(map_id).with_context(|| format!("open BPF map id {map_id}"))?;
        fds.push(fd.as_raw_fd());
        owned_fds.push(fd);
    }

    // Open BTF module fds after maps. With zero maps, fd_array[0] is a
    // duplicate valid BTF fd only to satisfy the verifier's fd_array pre-scan.
    let mut module_fds = Vec::with_capacity(module_entries.len());
    for (_, btf_id) in &module_entries {
        let fd = open_btf_fd(*btf_id)
            .with_context(|| format!("open BTF module id {btf_id} for fd_array"))?;
        module_fds.push(fd);
    }
    if fds.is_empty() {
        if let Some(first_module_fd) = module_fds.first() {
            fds.push(first_module_fd.as_raw_fd());
        }
    }
    for fd in module_fds {
        fds.push(fd.as_raw_fd());
        owned_fds.push(fd);
    }

    Ok(RejitFdArray {
        fds,
        _owned_fds: owned_fds,
    })
}

fn module_fd_array_base(map_count: usize) -> Result<u32> {
    let map_count = u32::try_from(map_count).context("map count exceeds u32")?;
    Ok(map_count.max(1))
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
        "bpfopt pass" => OPTIMIZE_CLI_STAGE_TIMEOUT,
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

#[cfg(test)]
mod tests {
    use super::*;

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
    fn pass_chain_records_failed_rejit_and_still_attempts_later_passes() {
        let pass_list = ["rotate", "cond_select", "endian_fusion"].map(str::to_string);
        let mut attempted = Vec::new();
        let reports = run_pass_chain(&pass_list, |idx, pass| {
            attempted.push(pass.to_string());
            let report = BpfoptPassReport {
                pass: pass.to_string(),
                changed: idx != 2,
                sites_applied: 1,
                insn_count_before: 1,
                insn_count_after: 2,
                map_inline_records: Vec::new(),
            };
            Ok(match idx {
                0 => pass_detail_from_report(&report, PassStatus::Ok, true, None, None),
                1 => pass_detail_from_report(
                    &report,
                    PassStatus::FailedRejit,
                    false,
                    Some("kernel rejected BPF_PROG_REJIT: EINVAL".to_string()),
                    Some("verifier rejected candidate".to_string()),
                ),
                2 => pass_detail_from_report(&report, PassStatus::Unchanged, false, None, None),
                _ => unreachable!(),
            })
        })
        .unwrap();

        assert_eq!(attempted, pass_list.to_vec());
        assert_eq!(reports.len(), 3);
        assert_eq!(reports[1].status, PassStatus::FailedRejit);
        assert_eq!(reports[2].pass_name, "endian_fusion");
        assert_eq!(reports[2].status, PassStatus::Unchanged);
    }

    #[test]
    fn rejit_fd_array_builder_keeps_map_fds_without_target() {
        let mut opened_maps = Vec::new();
        let fd_array = build_rejit_fd_array(&[11, 22], &HashMap::new(), &mut |map_id| {
            opened_maps.push(map_id);
            fake_owned_fd()
        })
        .unwrap();

        assert_eq!(opened_maps, vec![11, 22]);
        assert_eq!(fd_array.as_slice().len(), 2);
    }

    #[test]
    fn rejit_fd_array_builder_places_maps_first_and_module_btf_fds_at_call_offsets() {
        let mut opened_btfs = Vec::new();
        let mut opened_btf_fds = Vec::new();
        let mut opened_maps = Vec::new();
        let mut opened_map_fds = Vec::new();
        let kinsns = HashMap::from([
            (
                "bpf_rotate64".to_string(),
                TargetKinsnJson {
                    btf_func_id: 129876,
                    btf_id: 101,
                    call_offset: 2,
                },
            ),
            (
                "bpf_extract64".to_string(),
                TargetKinsnJson {
                    btf_func_id: 129876,
                    btf_id: 202,
                    call_offset: 3,
                },
            ),
            (
                "bpf_prefetch".to_string(),
                TargetKinsnJson {
                    btf_func_id: 129876,
                    btf_id: 202,
                    call_offset: 3,
                },
            ),
        ]);

        let fd_array = build_rejit_fd_array_with_openers(
            &[11, 22],
            &kinsns,
            &mut |btf_id| {
                opened_btfs.push(btf_id);
                let fd = fake_owned_fd()?;
                opened_btf_fds.push(fd.as_raw_fd());
                Ok(fd)
            },
            &mut |map_id| {
                opened_maps.push(map_id);
                let fd = fake_owned_fd()?;
                opened_map_fds.push(fd.as_raw_fd());
                Ok(fd)
            },
        )
        .unwrap();

        assert_eq!(opened_btfs, vec![101, 202]);
        assert_eq!(opened_maps, vec![11, 22]);
        assert_eq!(fd_array.as_slice().len(), 4);
        assert_eq!(&fd_array.as_slice()[..2], opened_map_fds.as_slice());
        assert_eq!(&fd_array.as_slice()[2..], opened_btf_fds.as_slice());
    }

    #[test]
    fn rejit_fd_array_builder_uses_btf_placeholder_when_no_maps() {
        let mut opened_btf_fds = Vec::new();
        let kinsns = HashMap::from([(
            "bpf_rotate64".to_string(),
            TargetKinsnJson {
                btf_func_id: 129876,
                btf_id: 101,
                call_offset: 1,
            },
        )]);

        let fd_array = build_rejit_fd_array_with_openers(
            &[],
            &kinsns,
            &mut |_btf_id| {
                let fd = fake_owned_fd()?;
                opened_btf_fds.push(fd.as_raw_fd());
                Ok(fd)
            },
            &mut |_map_id| fake_owned_fd(),
        )
        .unwrap();

        assert_eq!(fd_array.as_slice().len(), 2);
        assert_eq!(fd_array.as_slice()[0], opened_btf_fds[0]);
        assert_eq!(fd_array.as_slice()[1], opened_btf_fds[0]);
    }

    #[test]
    fn rejit_fd_array_builder_rejects_missing_module_slot() {
        let kinsns = HashMap::from([(
            "bpf_extract64".to_string(),
            TargetKinsnJson {
                btf_func_id: 129876,
                btf_id: 202,
                call_offset: 2,
            },
        )]);

        let err = build_rejit_fd_array_with_openers(
            &[],
            &kinsns,
            &mut |_btf_id| fake_owned_fd(),
            &mut |_map_id| fake_owned_fd(),
        )
        .unwrap_err();

        assert!(
            err.to_string().contains("call_offsets are not contiguous"),
            "err={err:#}"
        );
    }

    #[test]
    fn rejit_fd_array_builder_rejects_conflicting_module_offsets() {
        let kinsns = HashMap::from([
            (
                "bpf_extract64".to_string(),
                TargetKinsnJson {
                    btf_func_id: 129876,
                    btf_id: 202,
                    call_offset: 1,
                },
            ),
            (
                "bpf_prefetch".to_string(),
                TargetKinsnJson {
                    btf_func_id: 129876,
                    btf_id: 202,
                    call_offset: 2,
                },
            ),
        ]);

        let err = build_rejit_fd_array_with_openers(
            &[],
            &kinsns,
            &mut |_btf_id| fake_owned_fd(),
            &mut |_map_id| fake_owned_fd(),
        )
        .unwrap_err();

        assert!(
            err.to_string().contains("conflicting call_offsets"),
            "err={err:#}"
        );
    }

    #[test]
    fn target_call_offsets_shift_after_map_prefix() {
        let mut target = bpfget::TargetJson {
            arch: "x86_64".to_string(),
            features: Vec::new(),
            kinsns: BTreeMap::from([
                (
                    "bpf_rotate64".to_string(),
                    bpfget::TargetKinsnJson {
                        btf_func_id: 1,
                        btf_id: 100,
                        call_offset: 1,
                    },
                ),
                (
                    "bpf_extract64".to_string(),
                    bpfget::TargetKinsnJson {
                        btf_func_id: 2,
                        btf_id: 200,
                        call_offset: 2,
                    },
                ),
                (
                    "bpf_select64".to_string(),
                    bpfget::TargetKinsnJson {
                        btf_func_id: 3,
                        btf_id: 0,
                        call_offset: 0,
                    },
                ),
            ]),
        };

        shift_target_module_call_offsets_for_map_prefix(&mut target, 5).unwrap();

        assert_eq!(target.kinsns["bpf_rotate64"].call_offset, 5);
        assert_eq!(target.kinsns["bpf_extract64"].call_offset, 6);
        assert_eq!(target.kinsns["bpf_select64"].call_offset, 0);
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
            },
            MapInfoJson {
                map_id: 222,
                map_type: kernel_sys::BPF_MAP_TYPE_HASH,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
            },
        ];

        let (skipped, _) = write_live_map_values(
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

        assert!(skipped.is_empty());
        let json: serde_json::Value = serde_json::from_slice(&fs::read(output).unwrap()).unwrap();
        assert_eq!(json["maps"][0]["entries"][0]["key"], "01000000");
        assert_eq!(json["maps"][0]["entries"][0]["value"], "07000000");
        assert_eq!(json["maps"][1]["entries"][0]["key"], "02000000");
        assert!(json["maps"][1]["entries"][0]["value"].is_null());
    }

    /// Bug regression: an overflow on one map must not fail the whole map_inline pass.
    /// The overflowing map is reported in `skipped_maps`; the normal map still produces entries.
    #[test]
    fn map_scan_overflow_skips_one_map_and_continues() {
        let workdir = WorkDir::new("bpfrejit-daemon-overflow").unwrap();
        let output = workdir.path().join(MAP_VALUES_FILE);
        let maps = vec![
            MapInfoJson {
                map_id: 10,
                map_type: kernel_sys::BPF_MAP_TYPE_ARRAY,
                key_size: 4,
                value_size: 4,
                max_entries: 1,
            },
            MapInfoJson {
                map_id: 20,
                map_type: kernel_sys::BPF_MAP_TYPE_HASH,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
            },
        ];

        let (skipped, _) = write_live_map_values(
            &maps,
            &output,
            &mut |_map_id| Ok(std::fs::File::open("/dev/null")?.into()),
            &mut |_map, _fd, _key| Ok(Some(42u32.to_le_bytes().to_vec())),
            &mut |map, _fd| {
                if map.map_id == 10 {
                    // Simulate a BPF_MAP_GET_NEXT_KEY overflow: more keys than max_entries.
                    bail!(
                        "BPF_MAP_GET_NEXT_KEY for map {} returned more than max_entries={}",
                        map.map_id,
                        map.max_entries
                    )
                } else {
                    Ok(vec![5u32.to_le_bytes().to_vec()])
                }
            },
        )
        .unwrap();

        // Overflow map must appear in skipped_maps with a meaningful reason.
        assert_eq!(skipped.len(), 1);
        assert_eq!(skipped[0].map_id, 10);
        assert!(
            skipped[0].reason.contains("more than max_entries"),
            "unexpected reason: {}",
            skipped[0].reason
        );

        // The normal map's entries must be present in the output file.
        let json: serde_json::Value = serde_json::from_slice(&fs::read(&output).unwrap()).unwrap();
        let map20_entries = &json["maps"]
            .as_array()
            .unwrap()
            .iter()
            .find(|m| m["map_id"] == 20)
            .expect("map 20 not found")["entries"];
        assert_eq!(map20_entries[0]["key"], "05000000");
        assert_eq!(map20_entries[0]["value"], "2a000000");

        // The overflowing map must have no entries (excluded from snapshot).
        let map10_entries = &json["maps"]
            .as_array()
            .unwrap()
            .iter()
            .find(|m| m["map_id"] == 10)
            .expect("map 10 not found")["entries"];
        assert!(
            map10_entries.as_array().unwrap().is_empty(),
            "overflow map should have no entries in snapshot"
        );
    }

    #[test]
    fn try_apply_programs_converts_failures_and_panics_to_program_results() {
        let prog_ids = [7, 8, 9, 10];

        let outcomes =
            try_apply_programs_with(&prog_ids, 2, |prog_id| -> Result<OptimizeOneResult> {
                match prog_id {
                    7 => Ok(successful_batch_result(prog_id)),
                    8 => Ok(failed_batch_result(prog_id)),
                    9 => bail!("missing program {prog_id}"),
                    10 => panic!("mock worker panic"),
                    _ => bail!("unexpected prog_id {prog_id}"),
                }
            })
            .unwrap();

        assert_eq!(outcomes.len(), prog_ids.len());
        let by_id = outcomes
            .into_iter()
            .map(|outcome| (outcome.prog_id, outcome.result))
            .collect::<BTreeMap<_, _>>();
        assert_eq!(by_id[&7].status, "ok");
        assert_eq!(by_id[&8].status, "error");
        assert_eq!(by_id[&9].status, "error");
        assert!(by_id[&9]
            .error_message
            .as_deref()
            .unwrap_or("")
            .contains("missing program 9"));
        assert_eq!(by_id[&10].status, "error");
        assert!(by_id[&10]
            .error_message
            .as_deref()
            .unwrap_or("")
            .contains("worker panicked while optimizing prog 10: mock worker panic"));
    }

    fn successful_batch_result(prog_id: u32) -> OptimizeOneResult {
        OptimizeOneResult {
            status: "ok".to_string(),
            prog_id,
            changed: true,
            passes_applied: vec!["rotate".to_string()],
            program: ProgramInfo {
                prog_id,
                prog_name: "mock_prog".to_string(),
                prog_type: kernel_sys::BPF_PROG_TYPE_XDP,
                orig_insn_count: 1,
                final_insn_count: 2,
                insn_delta: 1,
            },
            summary: OptimizeSummary {
                applied: true,
                total_sites_applied: 1,
                passes_executed: 1,
                passes_changed: 1,
            },
            passes: Vec::new(),
            inlined_map_entries: Vec::new(),
            skipped_maps: Vec::new(),
            error_message: None,
        }
    }

    fn failed_batch_result(prog_id: u32) -> OptimizeOneResult {
        OptimizeOneResult::error(prog_id, "batch pass failed")
    }

    fn fake_owned_fd() -> Result<OwnedFd> {
        Ok(std::fs::File::open("/dev/null")?.into())
    }
}
