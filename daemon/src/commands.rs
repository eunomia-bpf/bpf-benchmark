// SPDX-License-Identifier: MIT
//! Socket command helpers.
//!
//! `bpfopt` remains the external bytecode CLI. The daemon owns live discovery,
//! pass orchestration, per-pass verifier acceptance, short-lived fd_array
//! construction, and per-pass `BPF_PROG_REJIT`.

use std::collections::{BTreeMap, HashMap, HashSet};
use std::fs;
use std::io::Write;
use std::os::fd::{AsFd, AsRawFd, BorrowedFd, OwnedFd};
use std::path::{Path, PathBuf};
use std::process::{Command, Stdio};
use std::sync::atomic::{AtomicU64, AtomicUsize, Ordering};
use std::time::Instant;

use anyhow::{anyhow, bail, Context, Result};
use rayon::prelude::*;
use serde::{Deserialize, Serialize};
use serde_json::Value;

use crate::{bpf, syscall};

static NEXT_WORKDIR_ID: AtomicU64 = AtomicU64::new(0);
const REJIT_VERBOSE_LOG_BUF_SIZE: usize = 16 * 1024 * 1024;
const REJIT_BASIC_LOG_BUF_SIZE: usize = 1024 * 1024;
const MAP_SNAPSHOT_MAX_BYTES: u64 = 64 * 1024;
/// Tail size kept in PassDetail.error / OptimizeOneResult.error_message JSON
/// fields. Full verifier log is still written to disk by `rejit_program()` and
/// tarred into the failure workdir.
const RESPONSE_LOG_TAIL_BYTES: usize = 64 * 1024;

fn truncate_response_log(text: String) -> String {
    if text.len() <= RESPONSE_LOG_TAIL_BYTES {
        return text;
    }
    // Preserve the first line: callers format the syscall errno prefix
    // ("BPF_PROG_REJIT errno 28: No space left on device") on the first line
    // before appending the verifier log body. Dropping that line in favor of
    // the verifier-log tail makes ENOSPC look like a bytecode rejection.
    let prefix = text.lines().next().unwrap_or("");
    let dropped = text.len() - RESPONSE_LOG_TAIL_BYTES;
    let mut start = text.len() - RESPONSE_LOG_TAIL_BYTES;
    while start < text.len() && !text.is_char_boundary(start) {
        start += 1;
    }
    format!(
        "{prefix}\n... [truncated {dropped} leading bytes; full log in workdir tar]\n{}",
        &text[start..]
    )
}
const MAX_FAILURE_ARTIFACTS_PER_REQUEST: usize = 32;
static FAILURE_ARTIFACT_COUNT: AtomicUsize = AtomicUsize::new(0);

fn maybe_tar_workdir(workdir: &Path) -> Result<Option<String>> {
    if FAILURE_ARTIFACT_COUNT.fetch_add(1, Ordering::Relaxed) >= MAX_FAILURE_ARTIFACTS_PER_REQUEST {
        return Ok(None);
    }
    Ok(Some(tar_workdir(workdir)?))
}

#[derive(Serialize)]
struct MapSnapshotSkipMarker {
    skipped: bool,
    reason: &'static str,
    size_bytes: u64,
    limit_bytes: u64,
}

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
    /// Wall-clock duration of the bpfopt CLI invocation (Command::output).
    /// None on early-exit paths that never spawned the subprocess.
    #[serde(skip_serializing_if = "Option::is_none")]
    pub bpfopt_ms: Option<u64>,
    /// Wall-clock duration of the BPF_PROG_REJIT syscall (kernel verify+JIT+
    /// install). None for steps that did not reach the kernel call (bpfopt
    /// failure / no produced bytecode / utility steps).
    #[serde(skip_serializing_if = "Option::is_none")]
    pub rejit_syscall_ms: Option<u64>,
}

fn rejit_program(
    prog_id: u32,
    insns: &[libbpf_sys::bpf_insn],
    fd_array: &RejitFdArray,
    verifier_log_path: &Path,
    log_level: u32,
    log_buf_size: usize,
) -> Result<()> {
    let prog_fd = syscall::prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open BPF program id {prog_id} for BPF_PROG_REJIT"))?;
    let mut log_buf = vec![0u8; log_buf_size];
    if let Err(err) = syscall::prog_rejit(
        prog_fd.as_fd(),
        insns,
        fd_array.as_slice(),
        Some(&mut log_buf),
        log_level,
    ) {
        fs::write(verifier_log_path, c_log_bytes(&log_buf))
            .with_context(|| format!("write {}", verifier_log_path.display()))?;
        return Err(err).context("kernel rejected BPF_PROG_REJIT");
    }
    fs::write(verifier_log_path, c_log_bytes(&log_buf))
        .with_context(|| format!("write {}", verifier_log_path.display()))?;
    Ok(())
}

fn c_log_bytes(buf: &[u8]) -> &[u8] {
    let end = buf.iter().position(|&b| b == 0).unwrap_or(buf.len());
    &buf[..end]
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

fn bpftool_map_show_path(output_dir: &Path, map_id: u32) -> PathBuf {
    output_dir.join(format!("map-{map_id}.show.json"))
}

fn bpftool_map_dump_path(output_dir: &Path, map_id: u32) -> PathBuf {
    output_dir.join(format!("map-{map_id}.dump.json"))
}

fn bpftool_map_inner_map_ids_path(output_dir: &Path, map_id: u32) -> PathBuf {
    output_dir.join(format!("map-{map_id}.inner_map_ids.json"))
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
    FAILURE_ARTIFACT_COUNT.store(0, Ordering::Relaxed);
    let prog_ids: Vec<u32> = plans.iter().map(|plan| plan.prog_id).collect();
    let plans_by_id: HashMap<u32, Vec<StepSpec>> = plans
        .iter()
        .map(|plan| (plan.prog_id, plan.steps.clone()))
        .collect();
    let kinsn_probes = kinsn_probes.to_vec();

    try_apply_programs_with(&prog_ids, default_worker_count(), |prog_id| {
        let steps = plans_by_id
            .get(&prog_id)
            .cloned()
            .ok_or_else(|| anyhow!("missing execution plan for prog_id {prog_id}"))?;
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
                result.workdir_tar_b64 = maybe_tar_workdir(workdir.path())?;
            }
            Ok(result)
        }
        Err(err) => {
            let mut result = OptimizeOneResult::error(prog_id, format!("{err:#}"));
            result.workdir_tar_b64 = maybe_tar_workdir(workdir.path())?;
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

fn canonicalize_snapshot_map_refs(
    prog_id: u32,
    workdir: &Path,
    snapshot_bytes: &[u8],
    map_ids: &[u32],
    target_input: Option<&Path>,
    target_output: Option<&Path>,
) -> Result<Vec<u8>> {
    let input_path = workdir.join("canonicalize_input.bin");
    let output_path = workdir.join("canonicalize_output.bin");
    fs::write(&input_path, snapshot_bytes)
        .with_context(|| format!("write {}", input_path.display()))?;

    let mut command = Command::new("bpfopt");
    command
        .arg("--canonicalize-map-refs")
        .arg("--input")
        .arg(&input_path)
        .arg("--output")
        .arg(&output_path);
    if !map_ids.is_empty() {
        command.arg("--map-ids").arg(join_u32_csv(map_ids));
    }
    match (target_input, target_output) {
        (Some(input), Some(output)) => {
            command.arg("--target").arg(input);
            command.arg("--target-output").arg(output);
        }
        (None, None) => {}
        (Some(_), None) => bail!("target input path requires target output path"),
        (None, Some(_)) => bail!("target output path requires target input path"),
    }

    let output = command
        .output()
        .with_context(|| format!("spawn bpfopt canonicalize-map-refs for prog {prog_id}"))?;
    if !output.status.success() {
        let code = output
            .status
            .code()
            .map(|code| code.to_string())
            .unwrap_or_else(|| "signal".to_string());
        let stderr = String::from_utf8_lossy(&output.stderr).trim().to_string();
        let stdout = String::from_utf8_lossy(&output.stdout).trim().to_string();
        let details = if stderr.is_empty() { stdout } else { stderr };
        bail!(
            "bpfopt --canonicalize-map-refs failed for prog {prog_id} (exit {code}): {}",
            if details.is_empty() {
                "<no subprocess output>".to_string()
            } else {
                truncate_response_log(details)
            }
        );
    }

    fs::read(&output_path).with_context(|| format!("read {}", output_path.display()))
}

fn run_program_steps(
    prog_id: u32,
    steps: &[StepSpec],
    kinsn_probes: &[bpf::KinsnProbeTarget],
    referenced: &HashSet<String>,
    workdir: &WorkDir,
) -> Result<OptimizeOneResult> {
    let snapshot = bpf::snapshot_program(prog_id)
        .with_context(|| format!("snapshot live BPF program {prog_id}"))?;
    let prog_info = snapshot.info.clone();
    let snapshot_bytes = bpf::encode_insns(&snapshot.insns);
    let target_path = workdir.path().join("target.json");
    let target_probe_path = workdir.path().join("target_probe.json");
    let map_values_path = workdir.path().join("map-values");

    let target_paths = if referenced.contains(VAR_TARGET) {
        let probed = bpf::target_json_for_probes(kinsn_probes)
            .with_context(|| format!("prepare target.json for prog {prog_id}"))?;
        write_json_file(&target_probe_path, &probed)
            .with_context(|| format!("write {}", target_probe_path.display()))?;
        (
            Some(target_probe_path.as_path()),
            Some(target_path.as_path()),
        )
    } else {
        (None, None)
    };

    let orig_bytes = canonicalize_snapshot_map_refs(
        prog_id,
        workdir.path(),
        &snapshot_bytes,
        &snapshot.info.map_ids,
        target_paths.0,
        target_paths.1,
    )
    .with_context(|| format!("canonicalize map references for prog {prog_id}"))?;
    let orig_insn_count = insn_count_from_bytes(&orig_bytes, "snapshot")?;

    let initial_input_path = workdir.path().join("input_step0.bin");
    fs::write(&initial_input_path, &orig_bytes)
        .with_context(|| format!("write {}", initial_input_path.display()))?;

    let mut probed_kinsns: HashMap<String, TargetKinsnJson> = HashMap::new();

    if referenced.contains(VAR_TARGET) {
        let target: bpf::TargetJson =
            read_json_file(&target_path, "target.json after canonicalize-map-refs")
                .with_context(|| format!("read {}", target_path.display()))?;
        for (name, kinsn) in &target.kinsns {
            probed_kinsns.insert(
                name.clone(),
                TargetKinsnJson {
                    btf_func_id: kinsn.btf_func_id,
                    btf_id: kinsn.btf_id,
                    call_offset: kinsn.call_offset,
                },
            );
        }
    }

    if referenced.contains(VAR_MAP_VALUES) {
        write_bpftool_map_snapshots(prog_id, &snapshot.maps, &map_values_path)
            .with_context(|| format!("build bpftool map snapshot for prog {prog_id}"))?;
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
    let mut verifier_states_path = workdir.path().join("verifier_log_initial.log");
    let mut current_bytes = orig_bytes.clone();
    let mut step_details: Vec<PassDetail> = Vec::with_capacity(steps.len());

    for (idx, step) in steps.iter().enumerate() {
        let output_path = workdir.path().join(format!("output_step{idx}.bin"));
        let report_path = workdir.path().join(format!("report_step{idx}.json"));
        let verifier_log_path = workdir.path().join(format!("verifier_log_step{idx}.log"));

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
                    None,
                    None,
                ));
                break;
            }
        };

        // Capture stdout+stderr so we can attribute bpfopt failures per-step
        // instead of cross-referencing a global daemon stderr log when many
        // progs run concurrently.
        let bpfopt_t0 = Instant::now();
        let cmd_output = match Command::new("sh").arg("-c").arg(&cmd).output() {
            Ok(out) => out,
            Err(err) => {
                step_details.push(pass_detail(
                    step,
                    PassStatus::FailedBpfopt,
                    Some(format!("spawn sh for step {idx}: {err}")),
                    None,
                    None,
                    None,
                ));
                break;
            }
        };
        let bpfopt_ms = Some(bpfopt_t0.elapsed().as_millis() as u64);
        let exit_status = cmd_output.status;

        // Surface a corrupt or unreadable step report as a step failure
        // rather than silently degrading to null. Steps that legitimately
        // produce no report leave ${REPORT} absent — that path stays Null.
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
                        bpfopt_ms,
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
                truncate_response_log(summary)
            };
            step_details.push(pass_detail(
                step,
                PassStatus::FailedBpfopt,
                Some(format!(
                    "step {idx} failed (exit {code}): {cmd}\nsubprocess output:\n{captured}"
                )),
                Some(bpfopt_summary),
                bpfopt_ms,
                None,
            ));
            // Keep going: prior input_path / verifier_states_path / current_bytes
            // are still the last successful pass's outputs, so the next step
            // gets the same inputs as if this failed step had been omitted.
            continue;
        }

        // Step succeeded. If it produced a non-empty bytecode at $OUTPUT,
        // ReJIT and chain. Otherwise, move on with input/states unchanged.
        let produced_bytecode = match fs::metadata(&output_path) {
            Ok(meta) => meta.len() > 0,
            Err(err) if err.kind() == std::io::ErrorKind::NotFound => false,
            Err(err) => {
                step_details.push(pass_detail(
                    step,
                    PassStatus::FailedBpfopt,
                    Some(format!("stat {}: {err}", output_path.display())),
                    Some(bpfopt_summary),
                    bpfopt_ms,
                    None,
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
                bpfopt_ms,
                None,
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
                    bpfopt_ms,
                    None,
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
                    bpfopt_ms,
                    None,
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
        let rejit_t0 = Instant::now();
        let rejit_outcome = rejit_program(
            prog_id,
            &pass_insns,
            &fd_array,
            &verifier_log_path,
            step.log_level,
            log_buf_size,
        );
        let rejit_syscall_ms = Some(rejit_t0.elapsed().as_millis() as u64);
        match rejit_outcome {
            Ok(()) => {}
            Err(err) => {
                step_details.push(pass_detail(
                    step,
                    PassStatus::FailedRejit,
                    Some(truncate_response_log(format!("{err:#}"))),
                    Some(bpfopt_summary),
                    bpfopt_ms,
                    rejit_syscall_ms,
                ));
                // Keep going on ReJIT failure: don't advance input/state
                // pointers, so the next pass works against the last
                // successfully-ReJITted bytecode and verifier log.
                continue;
            }
        };

        verifier_states_path = verifier_log_path;
        input_path = output_path;
        current_bytes = pass_bytes;

        step_details.push(pass_detail(
            step,
            PassStatus::Ok,
            None,
            Some(bpfopt_summary),
            bpfopt_ms,
            rejit_syscall_ms,
        ));
    }

    let final_insn_count = insn_count_from_bytes(&current_bytes, "final")?;
    let any_failed = step_details
        .iter()
        .any(|step| step.status != PassStatus::Ok);
    let status = if any_failed { "error" } else { "ok" }.to_string();

    // No error_message aggregation: passes[*].error is the single source of
    // truth for per-pass failures. Setting error_message here would just
    // re-join the same strings.
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
        error_message: None,
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
    bpfopt_ms: Option<u64>,
    rejit_syscall_ms: Option<u64>,
) -> PassDetail {
    PassDetail {
        step: step.clone(),
        status,
        error,
        bpfopt_summary: bpfopt_summary.unwrap_or(Value::Null),
        bpfopt_ms,
        rejit_syscall_ms,
    }
}

fn write_bpftool_map_snapshots(
    prog_id: u32,
    maps: &[bpf::MapInfo],
    output_dir: &Path,
) -> Result<()> {
    fs::create_dir(output_dir).with_context(|| format!("create {}", output_dir.display()))?;
    for map in maps {
        run_bpftool_map_json(
            &["-j", "map", "show", "id", &map.map_id.to_string()],
            &bpftool_map_show_path(output_dir, map.map_id),
        )
        .with_context(|| format!("bpftool map show for map {}", map.map_id))?;
        if !needs_bpftool_map_dump(map.map_type) {
            log_bpftool_map_snapshot_decision(prog_id, map.map_id, map.map_type, 0, "skip_type");
            continue;
        }
        let dump_path = bpftool_map_dump_path(output_dir, map.map_id);
        run_bpftool_map_json(
            &["-j", "map", "dump", "id", &map.map_id.to_string()],
            &dump_path,
        )
        .with_context(|| format!("bpftool map dump for map {}", map.map_id))?;
        let dump_size = fs::metadata(&dump_path)
            .with_context(|| format!("stat {}", dump_path.display()))?
            .len();
        if needs_inner_map_id_supplement(map.map_type) && dump_size <= MAP_SNAPSHOT_MAX_BYTES {
            write_inner_map_ids_supplement(map, output_dir)
                .with_context(|| format!("write inner_map_id supplement for map {}", map.map_id))?;
        }
        if dump_size > MAP_SNAPSHOT_MAX_BYTES {
            write_map_snapshot_skip_marker(&dump_path, dump_size)?;
            log_bpftool_map_snapshot_decision(
                prog_id,
                map.map_id,
                map.map_type,
                dump_size,
                "skip_size",
            );
        } else {
            log_bpftool_map_snapshot_decision(
                prog_id,
                map.map_id,
                map.map_type,
                dump_size,
                "dumped",
            );
        }
    }
    Ok(())
}

fn write_map_snapshot_skip_marker(path: &Path, size_bytes: u64) -> Result<()> {
    let marker = MapSnapshotSkipMarker {
        skipped: true,
        reason: "size_limit",
        size_bytes,
        limit_bytes: MAP_SNAPSHOT_MAX_BYTES,
    };
    let mut file = fs::File::create(path).with_context(|| format!("create {}", path.display()))?;
    serde_json::to_writer(&mut file, &marker)
        .with_context(|| format!("write skip marker {}", path.display()))?;
    writeln!(file).with_context(|| format!("write newline {}", path.display()))?;
    Ok(())
}

fn write_inner_map_ids_supplement(map: &bpf::MapInfo, output_dir: &Path) -> Result<()> {
    let outer_fd = syscall::map_get_fd_by_id(map.map_id)
        .with_context(|| format!("open map-in-map outer map id {}", map.map_id))?;
    let entries = collect_inner_map_id_supplement_entries(
        map,
        |key| lookup_inner_map_id_for_outer_key(outer_fd.as_fd(), map.map_id, key),
        |previous_key, key| syscall::map_get_next_key(outer_fd.as_fd(), previous_key, key),
    )?;
    write_inner_map_ids_supplement_entries(output_dir, map.map_id, entries)
}

fn collect_inner_map_id_supplement_entries<L, N>(
    map: &bpf::MapInfo,
    mut lookup_inner_map_id: L,
    mut get_next_hash_key: N,
) -> Result<BTreeMap<String, String>>
where
    L: FnMut(&[u8]) -> Result<Option<u32>>,
    N: FnMut(Option<&[u8]>, &mut [u8]) -> Result<bool>,
{
    let mut entries = BTreeMap::new();
    match map.map_type {
        libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS => {
            if map.key_size != std::mem::size_of::<u32>() as u32 {
                bail!(
                    "ARRAY_OF_MAPS outer map {} has {}-byte keys, expected 4",
                    map.map_id,
                    map.key_size
                );
            }
            for i in 0..map.max_entries {
                let key = i.to_le_bytes();
                insert_inner_map_id_supplement_entry(
                    map.map_id,
                    &key,
                    &mut lookup_inner_map_id,
                    &mut entries,
                )?;
            }
        }
        libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS => {
            let key_size = usize::try_from(map.key_size).with_context(|| {
                format!("HASH_OF_MAPS outer map {} key size overflow", map.map_id)
            })?;
            if key_size == 0 {
                bail!("HASH_OF_MAPS outer map {} has zero-byte keys", map.map_id);
            }
            let mut previous_key: Option<Vec<u8>> = None;
            loop {
                let mut key = vec![0u8; key_size];
                if !get_next_hash_key(previous_key.as_deref(), &mut key)
                    .with_context(|| format!("BPF_MAP_GET_NEXT_KEY on outer map {}", map.map_id))?
                {
                    break;
                }
                insert_inner_map_id_supplement_entry(
                    map.map_id,
                    &key,
                    &mut lookup_inner_map_id,
                    &mut entries,
                )?;
                previous_key = Some(key);
            }
        }
        other => bail!(
            "inner_map_id supplement requested for unsupported map type {} on map {}",
            other,
            map.map_id
        ),
    }
    Ok(entries)
}

fn insert_inner_map_id_supplement_entry<L>(
    outer_map_id: u32,
    key: &[u8],
    lookup_inner_map_id: &mut L,
    entries: &mut BTreeMap<String, String>,
) -> Result<()>
where
    L: FnMut(&[u8]) -> Result<Option<u32>>,
{
    let Some(inner_map_id) = lookup_inner_map_id(key).with_context(|| {
        format!(
            "lookup inner map id for outer map {} key {}",
            outer_map_id,
            hex_bytes(key)
        )
    })?
    else {
        return Ok(());
    };
    entries.insert(hex_bytes(key), inner_map_id.to_string());
    Ok(())
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

fn lookup_inner_map_id_for_outer_key(
    outer_fd: BorrowedFd<'_>,
    outer_map_id: u32,
    key: &[u8],
) -> Result<Option<u32>> {
    let mut value_bytes = [0u8; 4];
    if !syscall::map_lookup_elem(outer_fd, key, &mut value_bytes)
        .with_context(|| format!("BPF_MAP_LOOKUP_ELEM on outer map {outer_map_id}"))?
    {
        return Ok(None);
    }
    let inner_map_id = u32::from_ne_bytes(value_bytes);
    if inner_map_id == 0 {
        return Ok(None);
    }
    Ok(Some(inner_map_id))
}

fn write_inner_map_ids_supplement_entries(
    output_dir: &Path,
    map_id: u32,
    entries: BTreeMap<String, String>,
) -> Result<()> {
    let mut root = BTreeMap::new();
    root.insert(map_id.to_string(), entries);
    let path = bpftool_map_inner_map_ids_path(output_dir, map_id);
    let mut file = fs::File::create(&path).with_context(|| format!("create {}", path.display()))?;
    serde_json::to_writer_pretty(&mut file, &root)
        .with_context(|| format!("write {}", path.display()))?;
    writeln!(file).with_context(|| format!("write newline {}", path.display()))?;
    Ok(())
}

fn run_bpftool_map_json(args: &[&str], output: &Path) -> Result<()> {
    let command = format!("bpftool {}", args.join(" "));
    let file = fs::File::create(output).with_context(|| format!("create {}", output.display()))?;
    let status = Command::new("bpftool")
        .args(args)
        .stdout(Stdio::from(file))
        .stderr(Stdio::piped())
        .spawn()
        .with_context(|| format!("spawn {command}"))?
        .wait_with_output()
        .with_context(|| format!("wait {command}"))?;
    if !status.status.success() {
        let stderr = String::from_utf8_lossy(&status.stderr).trim().to_string();
        let cleanup_error = match fs::remove_file(output) {
            Ok(()) => None,
            Err(err) if err.kind() == std::io::ErrorKind::NotFound => None,
            Err(err) => Some(err),
        };
        if let Some(cleanup_error) = cleanup_error {
            bail!(
                "{command} failed with status {}: {}; additionally failed to remove {}: {}",
                status.status,
                if stderr.is_empty() {
                    "<no stderr>".to_string()
                } else {
                    stderr
                },
                output.display(),
                cleanup_error
            );
        }
        bail!(
            "{command} failed with status {}: {}",
            status.status,
            if stderr.is_empty() {
                "<no stderr>".to_string()
            } else {
                stderr
            }
        );
    }
    Ok(())
}

fn log_bpftool_map_snapshot_decision(
    prog_id: u32,
    map_id: u32,
    map_type: u32,
    size_bytes: u64,
    action: &str,
) {
    eprintln!(
        "daemon: map_snapshot prog_id={} map_id={} map_type={} size_bytes={} action={}",
        prog_id, map_id, map_type, size_bytes, action
    );
}

fn needs_bpftool_map_dump(map_type: u32) -> bool {
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

fn needs_inner_map_id_supplement(map_type: u32) -> bool {
    matches!(
        map_type,
        libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS | libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS
    )
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
        &mut |btf_id| syscall::btf_get_fd_by_id(btf_id),
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

fn decode_insns(bytes: &[u8], label: &str) -> Result<Vec<libbpf_sys::bpf_insn>> {
    insn_count_from_bytes(bytes, label)?;
    Ok(bytes
        .chunks_exact(8)
        .map(|chunk| {
            let mut insn = libbpf_sys::bpf_insn {
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
    use std::collections::BTreeMap;

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
                "bpf_x86_rolq_imm".to_string(),
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
            "bpf_x86_rolq_imm".to_string(),
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

    #[test]
    fn array_of_maps_supplement_iterates_all_slots_without_bpftool_keys() {
        let dir = temp_test_dir("inner-map-ids");
        fs::create_dir(&dir).unwrap();
        let map = bpf::MapInfo {
            map_id: 42,
            name: "outer".to_string(),
            map_type: libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS,
            key_size: 4,
            value_size: 4,
            max_entries: 4,
        };

        let mut looked_up = Vec::new();
        let entries = collect_inner_map_id_supplement_entries(
            &map,
            |key| {
                looked_up.push(key.to_vec());
                let key: [u8; 4] = key.try_into().unwrap();
                let inner_map_id = 9000 + u32::from_le_bytes(key);
                Ok(Some(inner_map_id))
            },
            |_previous_key, _key| bail!("HASH_OF_MAPS key iterator must not run for ARRAY_OF_MAPS"),
        )
        .unwrap();
        write_inner_map_ids_supplement_entries(&dir, map.map_id, entries).unwrap();

        let supplement = fs::read_to_string(bpftool_map_inner_map_ids_path(&dir, 42)).unwrap();
        remove_dir(&dir);
        assert_eq!(
            looked_up,
            (0..map.max_entries)
                .map(|i| i.to_le_bytes().to_vec())
                .collect::<Vec<_>>()
        );
        assert!(supplement.contains(r#""42""#), "json={supplement}");
        assert!(
            supplement.contains(r#""00000000": "9000""#),
            "json={supplement}"
        );
        assert!(
            supplement.contains(r#""01000000": "9001""#),
            "json={supplement}"
        );
        assert!(
            supplement.contains(r#""02000000": "9002""#),
            "json={supplement}"
        );
        assert!(
            supplement.contains(r#""03000000": "9003""#),
            "json={supplement}"
        );
    }

    fn successful_batch_result(prog_id: u32) -> OptimizeOneResult {
        OptimizeOneResult {
            status: "ok".to_string(),
            prog_id,
            program: ProgramInfo {
                prog_id,
                prog_name: "mock_prog".to_string(),
                prog_type: libbpf_sys::BPF_PROG_TYPE_XDP,
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

    fn temp_test_dir(name: &str) -> PathBuf {
        let id = NEXT_WORKDIR_ID.fetch_add(1, Ordering::Relaxed);
        std::env::temp_dir().join(format!(
            "bpfrejit-daemon-test-{}-{id}-{name}",
            std::process::id()
        ))
    }

    fn remove_dir(path: &Path) {
        match fs::remove_dir_all(path) {
            Ok(()) => {}
            Err(err) if err.kind() == std::io::ErrorKind::NotFound => {}
            Err(err) => panic!("remove {}: {err}", path.display()),
        }
    }
}
