// SPDX-License-Identifier: MIT
//! Socket command helpers.
//!
//! `bpfopt` remains the external bytecode CLI. The daemon owns live discovery,
//! pass orchestration, per-pass verifier acceptance, short-lived fd_array
//! construction, and per-pass `BPF_PROG_REJIT`.

use std::collections::{BTreeMap, HashMap, HashSet, VecDeque};
use std::fs;
use std::io::Write;
use std::os::fd::{AsFd, AsRawFd, OwnedFd};
use std::path::{Path, PathBuf};
use std::process::Command;
use std::sync::atomic::{AtomicU64, Ordering};

use anyhow::{anyhow, bail, Context, Result};
use rayon::prelude::*;
use serde::{Deserialize, Serialize};
use serde_json::Value;

use crate::bpf;

static NEXT_WORKDIR_ID: AtomicU64 = AtomicU64::new(0);
const REJIT_VERBOSE_LOG_BUF_SIZE: usize = 16 * 1024 * 1024;
const REJIT_BASIC_LOG_BUF_SIZE: usize = 1024 * 1024;

/// Variables daemon substitutes inside step templates.
///
/// Steps are bash command strings sent by runner. Daemon prepares per-prog
/// side-input files lazily based on which `${VAR}` placeholders the steps
/// reference, then `${VAR}` is replaced with either a path (file inputs) or
/// an inline value (`PROG_ID`, `MAP_IDS`, `PROG_TYPE`, `WORKDIR`).
const VAR_PROG_ID: &str = "PROG_ID";
const VAR_WORKDIR: &str = "WORKDIR";
const VAR_INPUT: &str = "INPUT";
const VAR_OUTPUT: &str = "OUTPUT";
const VAR_TARGET: &str = "TARGET";
const VAR_VERIFIER_STATES: &str = "VERIFIER_STATES";
const VAR_MAP_VALUES: &str = "MAP_VALUES";
const VAR_MAP_IDS: &str = "MAP_IDS";
const VAR_PROG_TYPE: &str = "PROG_TYPE";
const VAR_REPORT: &str = "REPORT";

const ALL_VARS: &[&str] = &[
    VAR_PROG_ID,
    VAR_WORKDIR,
    VAR_INPUT,
    VAR_OUTPUT,
    VAR_TARGET,
    VAR_VERIFIER_STATES,
    VAR_MAP_VALUES,
    VAR_MAP_IDS,
    VAR_PROG_TYPE,
    VAR_REPORT,
];

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
    pub program: ProgramInfo,
    pub passes: Vec<PassDetail>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub error_message: Option<String>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub workdir_tar_b64: Option<String>,
}

impl OptimizeOneResult {
    pub(crate) fn error(prog_id: u32, message: impl Into<String>) -> Self {
        Self {
            status: "error".to_string(),
            prog_id,
            program: ProgramInfo {
                prog_id,
                prog_name: String::new(),
                prog_type: 0,
                orig_insn_count: 0,
                final_insn_count: 0,
            },
            passes: Vec::new(),
            error_message: Some(message.into()),
            workdir_tar_b64: None,
        }
    }
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct ProgramInfo {
    pub prog_id: u32,
    pub prog_name: String,
    pub prog_type: u32,
    pub orig_insn_count: usize,
    pub final_insn_count: usize,
}

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
#[serde(rename_all = "snake_case")]
pub(crate) enum PassStatus {
    Ok,
    FailedBpfopt,
    FailedRejit,
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct PassDetail {
    /// Echo of the input StepSpec so consumers see {name, command, log_level}
    /// without any field duplication. `name` doubles as the legacy pass label.
    pub step: StepSpec,
    pub status: PassStatus,
    pub error: Option<String>,
    pub bpfopt_summary: Value,
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
    log_level: u32,
    log_buf_size: usize,
) -> Result<RejitReport> {
    let prog_fd = kernel_sys::prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open BPF program id {prog_id} for BPF_PROG_REJIT"))?;
    let mut log_buf = vec![0u8; log_buf_size];
    if let Err(err) = kernel_sys::prog_rejit(
        prog_fd.as_fd(),
        insns,
        fd_array.as_slice(),
        Some(&mut log_buf),
        log_level,
    ) {
        let log = c_log_string(&log_buf);
        fs::write(verifier_log_path, log)
            .with_context(|| format!("write {}", verifier_log_path.display()))?;
        return Err(err).context("kernel rejected BPF_PROG_REJIT");
    }
    let verifier_log = c_log_string(&log_buf);
    fs::write(verifier_log_path, &verifier_log)
        .with_context(|| format!("write {}", verifier_log_path.display()))?;
    if log_level != 2 {
        return Ok(RejitReport {
            verifier_states: kernel_sys::VerifierStatesJson { insns: Vec::new() },
        });
    }
    if verifier_log.is_empty() {
        bail!("BPF_PROG_REJIT for prog {prog_id} returned an empty verifier log");
    }
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

type MapInfoJson = bpf::MapInfo;

#[derive(Debug, Serialize)]
struct MapValuesJson {
    maps: Vec<MapValuesMapJson>,
}

#[derive(Debug, Serialize)]
struct MapValuesMapJson {
    map_id: u32,
    name: String,
    map_type: u32,
    key_size: u32,
    value_size: u32,
    max_entries: u32,
    entries_partial: bool,
    entries: Vec<MapValuesEntryJson>,
}

#[derive(Debug, Serialize)]
struct MapValuesEntryJson {
    key: String,
    value: Option<String>,
    #[serde(skip_serializing_if = "Option::is_none")]
    inner_map_id: Option<u32>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct MapValueSnapshotEntry {
    value: Option<Vec<u8>>,
    inner_map_id: Option<u32>,
}

#[derive(Clone, Debug, Default, PartialEq, Eq)]
struct MapKeySnapshot {
    keys: Vec<Vec<u8>>,
    entries_partial: bool,
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

fn base64_bytes(bytes: &[u8]) -> String {
    const TABLE: &[u8; 64] = b"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    let mut out = String::with_capacity(((bytes.len() + 2) / 3) * 4);
    for chunk in bytes.chunks(3) {
        let n = ((chunk[0] as u32) << 16)
            | ((chunk.get(1).copied().unwrap_or(0) as u32) << 8)
            | chunk.get(2).copied().unwrap_or(0) as u32;
        out.push(TABLE[((n >> 18) & 0x3f) as usize] as char);
        out.push(TABLE[((n >> 12) & 0x3f) as usize] as char);
        out.push(if chunk.len() > 1 {
            TABLE[((n >> 6) & 0x3f) as usize] as char
        } else {
            '='
        });
        out.push(if chunk.len() > 2 {
            TABLE[(n & 0x3f) as usize] as char
        } else {
            '='
        });
    }
    out
}

fn tar_workdir(workdir: &Path) -> Result<String> {
    let output = Command::new("tar")
        .args(["-czf", "-", "-C"])
        .arg(workdir)
        .arg(".")
        .output()
        .with_context(|| format!("tar workdir {}", workdir.display()))?;
    if !output.status.success() {
        bail!(
            "tar workdir {} failed: {}",
            workdir.display(),
            String::from_utf8_lossy(&output.stderr).trim()
        );
    }
    Ok(base64_bytes(&output.stdout))
}

fn live_bpf_map_lookup(_map: &MapInfoJson, fd: i32, key: &[u8]) -> Result<Option<Vec<u8>>> {
    let info = bpf::bpf_map_get_info(fd)?;
    let value_size = bpf::bpf_map_lookup_value_size(&info)?;
    bpf::bpf_map_lookup_elem_optional(fd, key, value_size)
}

fn live_bpf_map_keys(map: &MapInfoJson, fd: i32) -> Result<MapKeySnapshot> {
    live_bpf_map_keys_with(map, |previous_key, key_size| {
        bpf::bpf_map_get_next_key(fd, previous_key, key_size)
    })
}

fn live_bpf_map_keys_with<F>(map: &MapInfoJson, mut next_key: F) -> Result<MapKeySnapshot>
where
    F: FnMut(Option<&[u8]>, usize) -> Result<Option<Vec<u8>>>,
{
    if !is_map_snapshot_map_type(map.map_type) {
        return Ok(MapKeySnapshot::default());
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
        if keys.len() == map.max_entries as usize {
            let entries_partial = next_key(previous_key.as_deref(), key_size)?.is_some();
            return Ok(MapKeySnapshot {
                keys,
                entries_partial,
            });
        }
        let Some(key) = next_key(previous_key.as_deref(), key_size)? else {
            break;
        };
        previous_key = Some(key.clone());
        keys.push(key);
    }
    Ok(MapKeySnapshot {
        keys,
        entries_partial: false,
    })
}

pub(crate) struct ApplyProgramOutcome {
    pub prog_id: u32,
    pub result: OptimizeOneResult,
}

fn apply_program_result<F>(prog_id: u32, apply: F) -> OptimizeOneResult
where
    F: FnOnce() -> Result<OptimizeOneResult>,
{
    apply().unwrap_or_else(|err| OptimizeOneResult::error(prog_id, format!("{err:#}")))
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
                let result = apply_program_result(prog_id, || apply_one(prog_id));
                ApplyProgramOutcome { prog_id, result }
            })
            .collect()
    }))
}

/// One step in a program plan. `command` is the bash template the daemon
/// runs through `sh -c`, after substituting `${VAR}` placeholders.
/// `name` is the human-readable label echoed back inside `step` in the
/// response so analysis tools see canonical pass names. `log_level` is the
/// BPF_PROG_REJIT verifier log level used when the step produces a
/// non-empty `${OUTPUT}` bytecode and triggers a ReJIT.
#[derive(Clone, Debug, Serialize)]
pub(crate) struct StepSpec {
    pub name: String,
    pub command: String,
    pub log_level: u32,
}

/// One program plan: the prog_id to operate on plus a sequence of step
/// specs. An empty `steps` list means the runner deliberately skipped this
/// program — daemon performs no work and returns a status-`ok` result with no
/// step details.
#[derive(Clone, Debug)]
pub(crate) struct ProgramPlan {
    pub prog_id: u32,
    pub steps: Vec<StepSpec>,
}

pub(crate) fn try_execute_plan(
    plans: &[ProgramPlan],
    kinsn_probes: &[bpf::KinsnProbeTarget],
) -> Result<Vec<ApplyProgramOutcome>> {
    if plans.is_empty() {
        return Ok(Vec::new());
    }
    let prog_ids: Vec<u32> = plans.iter().map(|plan| plan.prog_id).collect();
    let plans_by_id: HashMap<u32, Vec<StepSpec>> = plans
        .iter()
        .map(|plan| (plan.prog_id, plan.steps.clone()))
        .collect();
    let kinsn_probes = kinsn_probes.to_vec();

    try_apply_programs_with(&prog_ids, default_worker_count(), |prog_id| {
        let steps = plans_by_id.get(&prog_id).cloned().unwrap_or_default();
        execute_one(prog_id, &steps, &kinsn_probes)
    })
}

fn execute_one(
    prog_id: u32,
    steps: &[StepSpec],
    kinsn_probes: &[bpf::KinsnProbeTarget],
) -> Result<OptimizeOneResult> {
    if steps.is_empty() {
        return Ok(skipped_program_result(prog_id));
    }

    // Validate every step command references only known vars before we touch
    // the kernel. Bad templates fail-fast without snapshotting bytecode.
    for (idx, step) in steps.iter().enumerate() {
        validate_step_template(&step.command)
            .map_err(|err| anyhow!("programs[].steps[{idx}].command invalid template: {err}"))?;
    }

    let referenced = collect_referenced_vars(steps);
    let workdir = WorkDir::new("bpfrejit-daemon-plan")?;

    let result = run_program_steps(prog_id, steps, kinsn_probes, &referenced, &workdir);

    match result {
        Ok(mut result) => {
            let any_failed = result
                .passes
                .iter()
                .any(|step| step.status != PassStatus::Ok);
            if result.status != "ok" || any_failed {
                result.workdir_tar_b64 = Some(tar_workdir(workdir.path())?);
            }
            Ok(result)
        }
        Err(err) => {
            let mut result = OptimizeOneResult::error(prog_id, format!("{err:#}"));
            result.workdir_tar_b64 = Some(tar_workdir(workdir.path())?);
            Ok(result)
        }
    }
}

fn skipped_program_result(prog_id: u32) -> OptimizeOneResult {
    OptimizeOneResult {
        status: "ok".to_string(),
        prog_id,
        program: ProgramInfo {
            prog_id,
            prog_name: String::new(),
            prog_type: 0,
            orig_insn_count: 0,
            final_insn_count: 0,
        },
        passes: Vec::new(),
        error_message: None,
        workdir_tar_b64: None,
    }
}

fn run_program_steps(
    prog_id: u32,
    steps: &[StepSpec],
    kinsn_probes: &[bpf::KinsnProbeTarget],
    referenced: &HashSet<String>,
    workdir: &WorkDir,
) -> Result<OptimizeOneResult> {
    let mut snapshot = bpf::snapshot_program(prog_id)
        .with_context(|| format!("snapshot live BPF program {prog_id}"))?;
    bpf::canonicalize_map_refs_to_idx(&mut snapshot.insns, None, &snapshot.info.map_ids)
        .with_context(|| format!("canonicalize map references for prog {prog_id}"))?;
    let prog_info = snapshot.info.clone();
    let orig_bytes = bpf::encode_insns(&snapshot.insns);
    let orig_insn_count = insn_count_from_bytes(&orig_bytes, "snapshot")?;

    let initial_input_path = workdir.path().join("input_step0.bin");
    fs::write(&initial_input_path, &orig_bytes)
        .with_context(|| format!("write {}", initial_input_path.display()))?;

    let target_path = workdir.path().join("target.json");
    let map_values_path = workdir.path().join("map-values.json");
    let mut probed_kinsns: HashMap<String, TargetKinsnJson> = HashMap::new();

    if referenced.contains(VAR_TARGET) {
        let mut probed = bpf::probe_target_json(kinsn_probes)
            .with_context(|| format!("probe target kinsns for prog {prog_id}"))?;
        shift_target_module_call_offsets_for_map_prefix(&mut probed, snapshot.info.map_ids.len())
            .with_context(|| format!("shift target module call_offsets for prog {prog_id}"))?;
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
        write_json_file(&target_path, &probed)?;
    }

    if referenced.contains(VAR_MAP_VALUES) {
        let mut open_map_fd = bpf::bpf_map_get_fd_by_id;
        let mut lookup_map_value = live_bpf_map_lookup;
        let mut scan_map_keys = live_bpf_map_keys;
        let mut load_map_info = bpf::bpf_map_info_by_id;
        write_live_map_values(
            &snapshot.maps,
            &map_values_path,
            &mut open_map_fd,
            &mut lookup_map_value,
            &mut scan_map_keys,
            &mut load_map_info,
        )
        .with_context(|| format!("build live map value snapshot for prog {prog_id}"))?;
    }

    let mut open_map_fd = bpf::bpf_map_get_fd_by_id;
    let fd_array = build_rejit_fd_array(&snapshot.info.map_ids, &probed_kinsns, &mut open_map_fd)
        .with_context(|| format!("build fd_array for prog {prog_id}"))?;

    let map_ids_csv = if prog_info.map_ids.is_empty() {
        "0".to_string()
    } else {
        join_u32_csv(&prog_info.map_ids)
    };

    // First step starts with a non-existent verifier states path. Any pass
    // that requires `--verifier-states` will fail at bpfopt's `fs::read` with
    // ENOENT, forcing the runner to put a state-producing pass (`noop`) first
    // in the plan. Daemon does not silently provide an empty placeholder.
    let mut input_path = initial_input_path.clone();
    let mut verifier_states_path = workdir.path().join("verifier_states_initial.json");
    let mut current_bytes = orig_bytes.clone();
    let mut step_details: Vec<PassDetail> = Vec::with_capacity(steps.len());

    for (idx, step) in steps.iter().enumerate() {
        let output_path = workdir.path().join(format!("output_step{idx}.bin"));
        let report_path = workdir.path().join(format!("report_step{idx}.json"));
        let verifier_log_path = workdir.path().join(format!("verifier_log_step{idx}.log"));
        let next_states_path = workdir
            .path()
            .join(format!("verifier_states_step{idx}.json"));

        let vars = step_vars(
            prog_id,
            workdir.path(),
            &input_path,
            &output_path,
            &target_path,
            &verifier_states_path,
            &map_values_path,
            &map_ids_csv,
            &prog_info.prog_type.name,
            &report_path,
        );

        let cmd = match substitute_vars(&step.command, &vars) {
            Ok(cmd) => cmd,
            Err(err) => {
                step_details.push(pass_detail(
                    step,
                    PassStatus::FailedBpfopt,
                    Some(format!("substitute vars in step {idx}: {err}")),
                    None,
                ));
                break;
            }
        };

        // Capture stdout+stderr so we can attribute bpfopt failures per-step
        // instead of cross-referencing a global daemon stderr log when many
        // progs run concurrently.
        let cmd_output = match Command::new("sh").arg("-c").arg(&cmd).output() {
            Ok(out) => out,
            Err(err) => {
                step_details.push(pass_detail(
                    step,
                    PassStatus::FailedBpfopt,
                    Some(format!("spawn sh for step {idx}: {err}")),
                    None,
                ));
                break;
            }
        };
        let exit_status = cmd_output.status;

        // Surface a corrupt or unreadable step report as a step failure
        // rather than silently degrading to null. Steps that legitimately
        // produce no report (e.g., `bpfprof profile > prof.json`) leave
        // ${REPORT} absent — that path stays Null.
        let bpfopt_summary = if report_path.exists() {
            match read_json_file::<Value>(&report_path, "step report") {
                Ok(value) => value,
                Err(err) => {
                    step_details.push(pass_detail(
                        step,
                        PassStatus::FailedBpfopt,
                        Some(format!(
                            "read step report at {}: {err:#}",
                            report_path.display()
                        )),
                        None,
                    ));
                    break;
                }
            }
        } else {
            Value::Null
        };

        if !exit_status.success() {
            let code = exit_status
                .code()
                .map(|c| c.to_string())
                .unwrap_or_else(|| "signal".to_string());
            let stderr_text = String::from_utf8_lossy(&cmd_output.stderr)
                .trim()
                .to_string();
            let summary = if stderr_text.is_empty() {
                String::from_utf8_lossy(&cmd_output.stdout)
                    .trim()
                    .to_string()
            } else {
                stderr_text
            };
            let captured = if summary.is_empty() {
                "<no subprocess output>".to_string()
            } else {
                summary.lines().take(40).collect::<Vec<_>>().join("\n")
            };
            step_details.push(pass_detail(
                step,
                PassStatus::FailedBpfopt,
                Some(format!(
                    "step {idx} failed (exit {code}): {cmd}\nsubprocess output:\n{captured}"
                )),
                Some(bpfopt_summary),
            ));
            break;
        }

        // Step succeeded. If it produced a non-empty bytecode at $OUTPUT,
        // ReJIT and chain. Otherwise (e.g., bpfprof / `test` / pipeline),
        // move on with input/states unchanged.
        let produced_bytecode = match fs::metadata(&output_path) {
            Ok(meta) => meta.len() > 0,
            Err(err) if err.kind() == std::io::ErrorKind::NotFound => false,
            Err(err) => {
                step_details.push(pass_detail(
                    step,
                    PassStatus::FailedBpfopt,
                    Some(format!("stat {}: {err}", output_path.display())),
                    Some(bpfopt_summary),
                ));
                break;
            }
        };

        if !produced_bytecode {
            step_details.push(pass_detail(
                step,
                PassStatus::Ok,
                None,
                Some(bpfopt_summary),
            ));
            continue;
        }

        let pass_bytes = match fs::read(&output_path) {
            Ok(bytes) => bytes,
            Err(err) => {
                step_details.push(pass_detail(
                    step,
                    PassStatus::FailedBpfopt,
                    Some(format!("read {}: {err}", output_path.display())),
                    Some(bpfopt_summary),
                ));
                break;
            }
        };

        let pass_insns = match decode_insns(&pass_bytes, output_path.to_string_lossy().as_ref()) {
            Ok(insns) => insns,
            Err(err) => {
                step_details.push(pass_detail(
                    step,
                    PassStatus::FailedBpfopt,
                    Some(format!("{err:#}")),
                    Some(bpfopt_summary),
                ));
                break;
            }
        };

        // log_level=1 uses a smaller log buffer (no mark_precise traces) for
        // passes that don't need to chain verifier states downstream. Steps
        // that require log_level=2 (e.g., a bootstrap noop feeding map_inline)
        // declare it explicitly in the step spec.
        let log_buf_size = if step.log_level == 2 {
            REJIT_VERBOSE_LOG_BUF_SIZE
        } else {
            REJIT_BASIC_LOG_BUF_SIZE
        };
        let rejit_report = match rejit_program(
            prog_id,
            &pass_insns,
            &fd_array,
            &verifier_log_path,
            step.log_level,
            log_buf_size,
        ) {
            Ok(report) => report,
            Err(err) => {
                step_details.push(pass_detail(
                    step,
                    PassStatus::FailedRejit,
                    Some(format!("{err:#}")),
                    Some(bpfopt_summary),
                ));
                break;
            }
        };

        write_json_file(&next_states_path, &rejit_report.verifier_states)
            .with_context(|| format!("write verifier states after step {idx}"))?;
        require_nonempty_file(&next_states_path, "verifier states")?;

        verifier_states_path = next_states_path;
        input_path = output_path;
        current_bytes = pass_bytes;

        step_details.push(pass_detail(
            step,
            PassStatus::Ok,
            None,
            Some(bpfopt_summary),
        ));
    }

    let final_insn_count = insn_count_from_bytes(&current_bytes, "final")?;
    let any_failed = step_details
        .iter()
        .any(|step| step.status != PassStatus::Ok);
    let status = if any_failed { "error" } else { "ok" }.to_string();
    let error_message = if any_failed {
        let combined = step_details
            .iter()
            .filter_map(|step| step.error.clone())
            .collect::<Vec<_>>()
            .join("; ");
        Some(combined)
    } else {
        None
    };

    Ok(OptimizeOneResult {
        status,
        prog_id,
        program: ProgramInfo {
            prog_id,
            prog_name: prog_info.name,
            prog_type: prog_info.prog_type.numeric,
            orig_insn_count,
            final_insn_count,
        },
        passes: step_details,
        error_message,
        workdir_tar_b64: None,
    })
}

#[allow(clippy::too_many_arguments)]
fn step_vars(
    prog_id: u32,
    workdir: &Path,
    input_path: &Path,
    output_path: &Path,
    target_path: &Path,
    verifier_states_path: &Path,
    map_values_path: &Path,
    map_ids_csv: &str,
    prog_type_name: &str,
    report_path: &Path,
) -> HashMap<&'static str, String> {
    HashMap::from([
        (VAR_PROG_ID, prog_id.to_string()),
        (VAR_WORKDIR, workdir.display().to_string()),
        (VAR_INPUT, input_path.display().to_string()),
        (VAR_OUTPUT, output_path.display().to_string()),
        (VAR_TARGET, target_path.display().to_string()),
        (
            VAR_VERIFIER_STATES,
            verifier_states_path.display().to_string(),
        ),
        (VAR_MAP_VALUES, map_values_path.display().to_string()),
        (VAR_MAP_IDS, map_ids_csv.to_string()),
        (VAR_PROG_TYPE, prog_type_name.to_string()),
        (VAR_REPORT, report_path.display().to_string()),
    ])
}

/// Replace `${VAR}` placeholders in `template` with looked-up values.
///
/// Supports only the daemon-known set in [`ALL_VARS`]. Unknown vars and
/// unterminated `${` are errors. `$VAR` (no braces) and `$$` are left alone
/// so steps can still use shell positional/process expansions like `$(cmd)`.
fn substitute_vars(
    template: &str,
    vars: &HashMap<&'static str, String>,
) -> std::result::Result<String, String> {
    let mut out = String::with_capacity(template.len());
    let mut chars = template.char_indices().peekable();
    while let Some((i, ch)) = chars.next() {
        if ch != '$' {
            out.push(ch);
            continue;
        }
        match chars.peek() {
            Some(&(_, '{')) => {
                chars.next();
                let mut name = String::new();
                let mut closed = false;
                for (_, c) in chars.by_ref() {
                    if c == '}' {
                        closed = true;
                        break;
                    }
                    name.push(c);
                }
                if !closed {
                    return Err(format!("unterminated ${{ at byte {i}"));
                }
                let value = vars
                    .get(name.as_str())
                    .ok_or_else(|| format!("unknown var ${{{name}}}"))?;
                out.push_str(value);
            }
            _ => out.push('$'),
        }
    }
    Ok(out)
}

fn collect_referenced_vars(steps: &[StepSpec]) -> HashSet<String> {
    let mut refs = HashSet::new();
    for step in steps {
        for var in ALL_VARS {
            if step.command.contains(&format!("${{{var}}}")) {
                refs.insert((*var).to_string());
            }
        }
    }
    refs
}

fn validate_step_template(step: &str) -> std::result::Result<(), String> {
    let dummy: HashMap<&'static str, String> =
        ALL_VARS.iter().map(|v| (*v, String::new())).collect();
    substitute_vars(step, &dummy).map(|_| ())
}

fn pass_detail(
    step: &StepSpec,
    status: PassStatus,
    error: Option<String>,
    bpfopt_summary: Option<Value>,
) -> PassDetail {
    PassDetail {
        step: step.clone(),
        status,
        error,
        bpfopt_summary: bpfopt_summary.unwrap_or(Value::Null),
    }
}

fn write_live_map_values<F, G, H, I>(
    maps: &[MapInfoJson],
    output: &Path,
    open_map_fd: &mut F,
    lookup_map_value: &mut G,
    scan_map_keys: &mut H,
    load_map_info: &mut I,
) -> Result<()>
where
    F: FnMut(u32) -> Result<OwnedFd>,
    G: FnMut(&MapInfoJson, i32, &[u8]) -> Result<Option<Vec<u8>>>,
    H: FnMut(&MapInfoJson, i32) -> Result<MapKeySnapshot>,
    I: FnMut(u32) -> Result<MapInfoJson>,
{
    let mut map_metadata = BTreeMap::<u32, MapInfoJson>::new();
    let mut map_order = Vec::new();
    for map in maps {
        insert_snapshot_map_metadata(&mut map_metadata, &mut map_order, map.clone())?;
    }

    let mut entries_by_map = BTreeMap::<u32, BTreeMap<Vec<u8>, MapValueSnapshotEntry>>::new();
    let mut entries_partial_by_map = BTreeMap::<u32, bool>::new();
    let mut queue = VecDeque::from(map_order.clone());
    let mut scanned = HashSet::new();

    while let Some(map_id) = queue.pop_front() {
        if !scanned.insert(map_id) {
            continue;
        }
        let map = map_metadata
            .get(&map_id)
            .with_context(|| format!("missing snapshot metadata for map {map_id}"))?
            .clone();
        if !is_map_snapshot_map_type(map.map_type) {
            continue;
        }
        let fd = open_map_fd(map.map_id)
            .with_context(|| format!("open BPF map id {} for map-inline values", map.map_id))?;
        let key_snapshot = scan_map_keys(&map, fd.as_raw_fd())
            .with_context(|| format!("scan live keys for map {}", map.map_id))?;
        entries_partial_by_map.insert(map.map_id, key_snapshot.entries_partial);
        for key in key_snapshot.keys {
            let value = lookup_map_value(&map, fd.as_raw_fd(), &key).with_context(|| {
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
            let inner_map_id = if is_map_in_map_type(map.map_type) {
                decode_inner_map_id_from_outer_value(&map, &key, value.as_deref())?
            } else {
                None
            };
            if let Some(inner_map_id) = inner_map_id {
                let inner_map = load_map_info(inner_map_id).with_context(|| {
                    format!(
                        "read metadata for inner map {} referenced by outer map {} key {}",
                        inner_map_id,
                        map.map_id,
                        hex_bytes(&key)
                    )
                })?;
                insert_snapshot_map_metadata(&mut map_metadata, &mut map_order, inner_map)?;
                queue.push_back(inner_map_id);
            }
            entries_by_map.entry(map.map_id).or_default().insert(
                key,
                MapValueSnapshotEntry {
                    value,
                    inner_map_id,
                },
            );
        }
    }

    let maps = map_order
        .iter()
        .map(|map_id| {
            map_metadata
                .get(map_id)
                .with_context(|| format!("missing snapshot metadata for map {map_id}"))
                .cloned()
        })
        .collect::<Result<Vec<_>>>()?;
    write_map_values_snapshot(&maps, &entries_by_map, &entries_partial_by_map, output)?;
    Ok(())
}

fn write_map_values_snapshot(
    maps: &[MapInfoJson],
    entries_by_map: &BTreeMap<u32, BTreeMap<Vec<u8>, MapValueSnapshotEntry>>,
    entries_partial_by_map: &BTreeMap<u32, bool>,
    output: &Path,
) -> Result<()> {
    let payload = MapValuesJson {
        maps: maps
            .iter()
            .map(|map| {
                let entries = match entries_by_map.get(&map.map_id) {
                    Some(entries) => entries
                        .iter()
                        .map(|(key, entry)| MapValuesEntryJson {
                            key: hex_bytes(key),
                            value: entry.value.as_ref().map(|value| hex_bytes(value)),
                            inner_map_id: entry.inner_map_id,
                        })
                        .collect(),
                    None => Vec::new(),
                };

                MapValuesMapJson {
                    map_id: map.map_id,
                    name: map.name.clone(),
                    map_type: map.map_type,
                    key_size: map.key_size,
                    value_size: map.value_size,
                    max_entries: map.max_entries,
                    entries_partial: entries_partial_by_map
                        .get(&map.map_id)
                        .copied()
                        .unwrap_or(false),
                    entries,
                }
            })
            .collect(),
    };
    write_json_file(output, &payload)
}

fn insert_snapshot_map_metadata(
    map_metadata: &mut BTreeMap<u32, MapInfoJson>,
    map_order: &mut Vec<u32>,
    map: MapInfoJson,
) -> Result<()> {
    if let Some(existing) = map_metadata.get(&map.map_id) {
        if existing != &map {
            bail!(
                "conflicting metadata for map {}: existing type/key/value/max={}/{}/{}/{} new={}/{}/{}/{}",
                map.map_id,
                existing.map_type,
                existing.key_size,
                existing.value_size,
                existing.max_entries,
                map.map_type,
                map.key_size,
                map.value_size,
                map.max_entries
            );
        }
        return Ok(());
    }
    map_order.push(map.map_id);
    map_metadata.insert(map.map_id, map);
    Ok(())
}

fn decode_inner_map_id_from_outer_value(
    map: &MapInfoJson,
    key: &[u8],
    value: Option<&[u8]>,
) -> Result<Option<u32>> {
    let Some(value) = value else {
        return Ok(None);
    };
    let bytes: [u8; 4] = value.try_into().with_context(|| {
        format!(
            "map-in-map {} key {} returned {} value bytes, expected 4-byte inner map id",
            map.map_id,
            hex_bytes(key),
            value.len()
        )
    })?;
    let inner_map_id = u32::from_ne_bytes(bytes);
    if inner_map_id == 0 {
        bail!(
            "map-in-map {} key {} returned invalid inner map id 0",
            map.map_id,
            hex_bytes(key)
        );
    }
    Ok(Some(inner_map_id))
}

fn is_array_like_map(map_type: u32) -> bool {
    matches!(
        map_type,
        kernel_sys::BPF_MAP_TYPE_ARRAY | kernel_sys::BPF_MAP_TYPE_PERCPU_ARRAY
    )
}

fn is_map_snapshot_map_type(map_type: u32) -> bool {
    is_direct_value_inlineable_map_type(map_type) || is_map_in_map_type(map_type)
}

fn is_direct_value_inlineable_map_type(map_type: u32) -> bool {
    matches!(
        map_type,
        kernel_sys::BPF_MAP_TYPE_HASH
            | kernel_sys::BPF_MAP_TYPE_ARRAY
            | kernel_sys::BPF_MAP_TYPE_PERCPU_ARRAY
            | kernel_sys::BPF_MAP_TYPE_LRU_HASH
    )
}

fn is_map_in_map_type(map_type: u32) -> bool {
    matches!(
        map_type,
        kernel_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS | kernel_sys::BPF_MAP_TYPE_HASH_OF_MAPS
    )
}

fn shift_target_module_call_offsets_for_map_prefix(
    target: &mut bpf::TargetJson,
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

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn bytecode_decoder_rejects_unaligned_input() {
        let err = decode_insns(&[0u8; 9], "bad").unwrap_err();
        assert!(err.to_string().contains("multiple of 8"), "err={err:#}");
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
        let mut target = bpf::TargetJson {
            arch: "x86_64".to_string(),
            features: Vec::new(),
            kinsns: BTreeMap::from([
                (
                    "bpf_rotate64".to_string(),
                    bpf::TargetKinsnJson {
                        btf_func_id: 1,
                        btf_id: 100,
                        call_offset: 1,
                    },
                ),
                (
                    "bpf_extract64".to_string(),
                    bpf::TargetKinsnJson {
                        btf_func_id: 2,
                        btf_id: 200,
                        call_offset: 2,
                    },
                ),
                (
                    "bpf_select64".to_string(),
                    bpf::TargetKinsnJson {
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
        let output = workdir.path().join("map-values.json");
        let maps = vec![
            MapInfoJson {
                map_id: 111,
                name: String::new(),
                map_type: kernel_sys::BPF_MAP_TYPE_ARRAY,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
            },
            MapInfoJson {
                map_id: 222,
                name: String::new(),
                map_type: kernel_sys::BPF_MAP_TYPE_HASH,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
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
                    Ok(MapKeySnapshot {
                        keys: vec![1u32.to_le_bytes().to_vec()],
                        entries_partial: false,
                    })
                } else {
                    Ok(MapKeySnapshot {
                        keys: vec![2u32.to_le_bytes().to_vec()],
                        entries_partial: false,
                    })
                }
            },
            &mut |map_id| bail!("unexpected recursive map metadata request for {map_id}"),
        )
        .unwrap();

        let json: serde_json::Value = serde_json::from_slice(&fs::read(output).unwrap()).unwrap();
        assert_eq!(json["maps"][0]["entries"][0]["key"], "01000000");
        assert_eq!(json["maps"][0]["entries"][0]["value"], "07000000");
        assert_eq!(json["maps"][1]["entries"][0]["key"], "02000000");
        assert!(json["maps"][1]["entries"][0]["value"].is_null());
    }

    #[test]
    fn live_bpf_map_keys_caps_at_max_entries_and_marks_partial() {
        let map = MapInfoJson {
            map_id: 123,
            name: String::new(),
            map_type: kernel_sys::BPF_MAP_TYPE_HASH,
            key_size: 4,
            value_size: 8,
            max_entries: 2,
        };
        let returned_keys = [
            1u32.to_le_bytes().to_vec(),
            2u32.to_le_bytes().to_vec(),
            3u32.to_le_bytes().to_vec(),
        ];
        let mut calls = 0usize;

        let snapshot = live_bpf_map_keys_with(&map, |_previous_key, _key_size| {
            let key = returned_keys.get(calls).cloned();
            calls += 1;
            Ok(key)
        })
        .unwrap();

        assert_eq!(
            snapshot.keys,
            vec![1u32.to_le_bytes().to_vec(), 2u32.to_le_bytes().to_vec()]
        );
        assert!(snapshot.entries_partial);
        assert_eq!(calls, 3);
    }

    #[test]
    fn live_map_values_snapshot_recurses_map_in_map_entries() {
        let workdir = WorkDir::new("bpfrejit-daemon-map-in-map-values").unwrap();
        let output = workdir.path().join("map-values.json");
        let outer_map_id = 333u32;
        let inner_map_id = 444u32;
        let maps = vec![MapInfoJson {
            map_id: outer_map_id,
            name: String::new(),
            map_type: kernel_sys::BPF_MAP_TYPE_HASH_OF_MAPS,
            key_size: 4,
            value_size: 4,
            max_entries: 8,
        }];

        write_live_map_values(
            &maps,
            &output,
            &mut |_map_id| Ok(std::fs::File::open("/dev/null")?.into()),
            &mut |map, _fd, key| {
                if map.map_id == outer_map_id && key == 7u32.to_le_bytes().as_slice() {
                    Ok(Some(inner_map_id.to_ne_bytes().to_vec()))
                } else if map.map_id == inner_map_id && key == 2u32.to_le_bytes().as_slice() {
                    Ok(Some(99u32.to_le_bytes().to_vec()))
                } else {
                    Ok(None)
                }
            },
            &mut |map, _fd| {
                if map.map_id == outer_map_id {
                    Ok(MapKeySnapshot {
                        keys: vec![7u32.to_le_bytes().to_vec()],
                        entries_partial: false,
                    })
                } else if map.map_id == inner_map_id {
                    Ok(MapKeySnapshot {
                        keys: vec![2u32.to_le_bytes().to_vec()],
                        entries_partial: false,
                    })
                } else {
                    bail!("unexpected key scan for map {}", map.map_id)
                }
            },
            &mut |map_id| {
                if map_id != inner_map_id {
                    bail!("unexpected recursive map metadata request for {map_id}");
                }
                Ok(MapInfoJson {
                    map_id: inner_map_id,
                    name: String::new(),
                    map_type: kernel_sys::BPF_MAP_TYPE_ARRAY,
                    key_size: 4,
                    value_size: 4,
                    max_entries: 8,
                })
            },
        )
        .unwrap();

        let json: serde_json::Value = serde_json::from_slice(&fs::read(output).unwrap()).unwrap();
        let maps = json["maps"].as_array().unwrap();
        assert_eq!(maps.len(), 2);
        let outer = maps
            .iter()
            .find(|map| map["map_id"] == outer_map_id)
            .unwrap();
        let inner = maps
            .iter()
            .find(|map| map["map_id"] == inner_map_id)
            .unwrap();
        assert_eq!(outer["entries"][0]["key"], "07000000");
        assert_eq!(outer["entries"][0]["inner_map_id"], inner_map_id);
        assert_eq!(inner["entries"][0]["key"], "02000000");
        assert_eq!(inner["entries"][0]["value"], "63000000");
    }

    #[test]
    fn try_apply_programs_converts_failures_to_program_results() {
        let prog_ids = [7, 8, 9];

        let outcomes =
            try_apply_programs_with(&prog_ids, 2, |prog_id| -> Result<OptimizeOneResult> {
                match prog_id {
                    7 => Ok(successful_batch_result(prog_id)),
                    8 => Ok(failed_batch_result(prog_id)),
                    9 => bail!("missing program {prog_id}"),
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
    }

    fn successful_batch_result(prog_id: u32) -> OptimizeOneResult {
        OptimizeOneResult {
            status: "ok".to_string(),
            prog_id,
            program: ProgramInfo {
                prog_id,
                prog_name: "mock_prog".to_string(),
                prog_type: kernel_sys::BPF_PROG_TYPE_XDP,
                orig_insn_count: 1,
                final_insn_count: 2,
            },
            passes: Vec::new(),
            error_message: None,
            workdir_tar_b64: None,
        }
    }

    fn failed_batch_result(prog_id: u32) -> OptimizeOneResult {
        OptimizeOneResult::error(prog_id, "batch pass failed")
    }

    fn fake_owned_fd() -> Result<OwnedFd> {
        Ok(std::fs::File::open("/dev/null")?.into())
    }
}
