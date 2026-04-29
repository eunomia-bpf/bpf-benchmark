// SPDX-License-Identifier: MIT
//! Socket command helpers backed by bpfopt-suite CLI subprocesses.

use std::collections::HashMap;
use std::fs;
use std::io::Write;
use std::path::{Path, PathBuf};
use std::process::{Command, Stdio};
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::{Arc, Mutex};
use std::time::Instant;

use anyhow::{anyhow, bail, Context, Result};
use serde::ser::{SerializeSeq, Serializer};
use serde::{Deserialize, Serialize};

use crate::invalidation::{BpfMapValueReader, MapInvalidationTracker};

static NEXT_WORKDIR_ID: AtomicU64 = AtomicU64::new(0);

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
        let _ = fs::remove_dir_all(&self.path);
    }
}

#[derive(Debug)]
pub(crate) struct ProfileSession {
    child: std::process::Child,
    output_dir: WorkDir,
    duration_ms: u64,
}

impl ProfileSession {
    pub(crate) fn duration_ms(&self) -> u64 {
        self.duration_ms
    }
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
    #[serde(
        skip_serializing_if = "Vec::is_empty",
        default,
        serialize_with = "serialize_attempts_without_debug"
    )]
    pub attempts: Vec<AttemptRecord>,
    pub timings_ns: TimingsNs,
    #[serde(skip_serializing_if = "Vec::is_empty", default)]
    pub inlined_map_entries: Vec<InlinedMapEntry>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub error_message: Option<String>,
}

#[cfg(test)]
pub(crate) type ServeOptimizeResponse = OptimizeOneResult;

fn serialize_attempts_without_debug<S>(
    attempts: &[AttemptRecord],
    serializer: S,
) -> std::result::Result<S::Ok, S::Error>
where
    S: Serializer,
{
    #[derive(Serialize)]
    struct AttemptRecordForServe<'a> {
        attempt: usize,
        disabled_passes: &'a [String],
        result: &'a str,
        #[serde(skip_serializing_if = "Option::is_none")]
        failure_pc: Option<usize>,
        #[serde(skip_serializing_if = "Option::is_none")]
        attributed_pass: Option<&'a str>,
    }

    let mut seq = serializer.serialize_seq(Some(attempts.len()))?;
    for attempt in attempts {
        seq.serialize_element(&AttemptRecordForServe {
            attempt: attempt.attempt,
            disabled_passes: &attempt.disabled_passes,
            result: &attempt.result,
            failure_pc: attempt.failure_pc,
            attributed_pass: attempt.attributed_pass.as_deref(),
        })?;
    }
    seq.end()
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
    pub verifier_rejections: usize,
}

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
#[serde(rename_all = "snake_case")]
pub(crate) enum PassVerifyStatus {
    NotNeeded,
    Accepted,
    Rejected,
}

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
pub(crate) struct PassVerifyResult {
    pub status: PassVerifyStatus,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub error_message: Option<String>,
}

impl PassVerifyResult {
    fn not_needed() -> Self {
        Self {
            status: PassVerifyStatus::NotNeeded,
            error_message: None,
        }
    }

    fn accepted() -> Self {
        Self {
            status: PassVerifyStatus::Accepted,
            error_message: None,
        }
    }

    fn rejected(message: impl Into<String>) -> Self {
        Self {
            status: PassVerifyStatus::Rejected,
            error_message: Some(message.into()),
        }
    }
}

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
pub(crate) struct PassRollbackResult {
    pub action: String,
    pub restored_insn_count: usize,
}

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
pub(crate) struct SkippedSiteDetail {
    pub pc: usize,
    pub reason: String,
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct PassDetail {
    #[serde(rename = "pass")]
    pub pass_name: String,
    pub changed: bool,
    pub verify_result: PassVerifyStatus,
    pub verify_error: Option<String>,
    pub action: String,
    pub verify: PassVerifyResult,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub rollback: Option<PassRollbackResult>,
    pub sites_applied: usize,
    pub sites_skipped: usize,
    pub skip_reasons: HashMap<String, usize>,
    #[serde(skip_serializing_if = "Vec::is_empty", default)]
    pub skipped_sites: Vec<SkippedSiteDetail>,
    pub insns_before: usize,
    pub insns_after: usize,
    pub insn_delta: i64,
    pub diagnostics: Vec<String>,
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct AttemptRecord {
    pub attempt: usize,
    pub disabled_passes: Vec<String>,
    pub result: String,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub failure_pc: Option<usize>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub attributed_pass: Option<String>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub debug: Option<AttemptDebug>,
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct AttemptDebug {
    #[serde(skip_serializing_if = "Vec::is_empty", default)]
    pub warnings: Vec<String>,
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct TimingsNs {
    pub pipeline_run_ns: u64,
    pub rejit_syscall_ns: u64,
    pub total_ns: u64,
}

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub(crate) enum OptimizeMode {
    Apply,
    DryRun,
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
}

#[derive(Clone, Debug, Deserialize)]
pub(crate) struct ListProgJson {
    pub id: u32,
    pub name: String,
    #[serde(rename = "type")]
    prog_type: TypeJson,
}

impl ListProgJson {
    pub(crate) fn prog_type_name(&self) -> &str {
        &self.prog_type.name
    }
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
}

#[derive(Clone, Debug, Deserialize)]
struct BpfoptOptimizeReport {
    passes: Vec<BpfoptPassReport>,
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

pub(crate) fn available_passes_help(config: &CliConfig) -> Result<String> {
    let output = run_output(config.command("bpfopt").arg("list-passes"))?;
    Ok(String::from_utf8_lossy(&output.stdout).trim().to_string())
}

pub(crate) fn list_programs(config: &CliConfig) -> Result<Vec<ListProgJson>> {
    let output = run_output(config.command("bpfget").arg("--list").arg("--json"))?;
    serde_json::from_slice(&output.stdout).context("parse bpfget --list --json output")
}

pub(crate) fn start_profile(config: &CliConfig, duration_ms: u64) -> Result<ProfileSession> {
    let output_dir = WorkDir::new("bpfrejit-daemon-profile")?;
    let mut child = config
        .command("bpfprof")
        .arg("--all")
        .arg("--duration")
        .arg(format!("{duration_ms}ms"))
        .arg("--output-dir")
        .arg(output_dir.path())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
        .context("spawn bpfprof --all")?;

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

pub(crate) fn save_profile(profile: &FrozenProfile, path: &Path) -> Result<()> {
    let mut rows = Vec::<serde_json::Value>::new();
    for entry in fs::read_dir(profile.output_dir.path())
        .with_context(|| format!("read {}", profile.output_dir.path().display()))?
    {
        let entry = entry?;
        if entry.path().extension().and_then(|value| value.to_str()) != Some("json") {
            continue;
        }
        let data = fs::read(entry.path())?;
        rows.push(serde_json::from_slice(&data)?);
    }
    let mut file = fs::File::create(path).with_context(|| format!("create {}", path.display()))?;
    serde_json::to_writer_pretty(&mut file, &rows)?;
    writeln!(file)?;
    file.flush()?;
    Ok(())
}

pub(crate) fn load_profile(path: &Path) -> Result<FrozenProfile> {
    let data = fs::read(path).with_context(|| format!("read {}", path.display()))?;
    let rows: Vec<serde_json::Value> = serde_json::from_slice(&data)
        .with_context(|| format!("parse profile JSON array from {}", path.display()))?;
    let output_dir = WorkDir::new("bpfrejit-daemon-profile-load")?;
    for row in &rows {
        let prog_id = row
            .get("prog_id")
            .and_then(|value| value.as_u64())
            .ok_or_else(|| anyhow!("profile row is missing prog_id"))?;
        let out_path = output_dir.path().join(format!("{prog_id}.json"));
        let mut file = fs::File::create(&out_path)
            .with_context(|| format!("create {}", out_path.display()))?;
        serde_json::to_writer_pretty(&mut file, row)?;
        writeln!(file)?;
    }
    Ok(FrozenProfile {
        output_dir,
        duration_ms: 0,
        programs_profiled: rows.len(),
    })
}

pub(crate) fn try_apply_one(
    prog_id: u32,
    config: &CliConfig,
    enabled_passes: Option<&[String]>,
    profile_path: Option<&Path>,
    _invalidation_tracker: Option<&SharedInvalidationTracker>,
    mode: OptimizeMode,
) -> Result<OptimizeOneResult> {
    let total_start = Instant::now();
    let workdir = WorkDir::new("bpfrejit-daemon-optimize")?;
    let prog_bin = workdir.path().join("prog.bin");
    let prog_info_json = workdir.path().join("prog_info.json");
    let map_fds_json = workdir.path().join("map_fds.json");
    let target_json = workdir.path().join("target.json");
    let fd_array_json = workdir.path().join("fd_array.json");
    let verifier_states_json = workdir.path().join("verifier_states.json");
    let map_values_json = workdir.path().join("map_values.json");
    let opt_bin = workdir.path().join("opt.bin");
    let verified_bin = workdir.path().join("verified.bin");
    let report_json = workdir.path().join("bpfopt_report.json");
    let rejit_summary_json = workdir.path().join("bpfrejit_summary.json");

    run_output(
        config
            .command("bpfget")
            .arg(prog_id.to_string())
            .arg("--full")
            .arg("--outdir")
            .arg(workdir.path()),
    )
    .with_context(|| format!("bpfget --full failed for prog {prog_id}"))?;

    let prog_info: ProgInfoJson = read_json_file(&prog_info_json, "prog_info.json")?;
    let orig_bytes = fs::read(&prog_bin).with_context(|| format!("read {}", prog_bin.display()))?;
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
    let requested_passes = enabled_passes.unwrap_or(&[]);
    let mut side_inputs = Vec::<(String, PathBuf)>::new();

    let mut has_fd_array = false;
    if needs_target(requested_passes) {
        match run_output(
            config
                .command("bpfget")
                .arg("--target")
                .arg("--output")
                .arg(&target_json),
        ) {
            Ok(_) => {
                if target_satisfies_requested_kinsns(&target_json, requested_passes)? {
                    write_fd_array_from_target(&target_json, requested_passes, &fd_array_json)?;
                    has_fd_array = true;
                    side_inputs.push(("--target".to_string(), target_json.clone()));
                } else {
                    eprintln!(
                        "warning: bpfget --target did not expose all requested kinsns; bpfopt will skip target-dependent passes"
                    );
                }
            }
            Err(err) => {
                eprintln!("warning: bpfget --target failed; bpfopt will skip target-dependent passes: {err:#}");
            }
        }
    }

    if requested_passes
        .iter()
        .any(|pass| canonical_pass(pass) == "const_prop")
    {
        match run_output(
            config
                .command("bpfverify")
                .arg("--prog-type")
                .arg(&prog_info.prog_type.name)
                .arg("--map-fds")
                .arg(&map_fds_json)
                .arg("--input")
                .arg(&prog_bin)
                .arg("--output")
                .arg(workdir.path().join("verified_original.bin"))
                .arg("--verifier-states-out")
                .arg(&verifier_states_json),
        ) {
            Ok(_) => side_inputs.push((
                "--verifier-states".to_string(),
                verifier_states_json.clone(),
            )),
            Err(err) => {
                eprintln!(
                    "warning: bpfverify --verifier-states-out failed for prog {prog_id}; bpfopt will skip const_prop: {err:#}"
                );
            }
        }
    }

    if requested_passes
        .iter()
        .any(|pass| canonical_pass(pass) == "map_inline")
    {
        write_empty_map_values(&map_fds_json, &map_values_json)?;
        side_inputs.push(("--map-values".to_string(), map_values_json.clone()));
        let map_ids = if prog_info.map_ids.is_empty() {
            "0".to_string()
        } else {
            join_u32_csv(&prog_info.map_ids)
        };
        side_inputs.push(("--map-ids".to_string(), PathBuf::from(map_ids)));
    }

    if requested_passes
        .iter()
        .any(|pass| canonical_pass(pass) == "branch_flip")
    {
        let profile_path = profile_path
            .ok_or_else(|| anyhow!("branch_flip requested but no profile is loaded"))?;
        side_inputs.push(("--profile".to_string(), profile_path.to_path_buf()));
    }

    let pipeline_start = Instant::now();
    let mut bpfopt = config.command("bpfopt");
    bpfopt.arg("optimize").arg("--report").arg(&report_json);
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
    run_with_file_io(&mut bpfopt, &prog_bin, &opt_bin).context("bpfopt optimize failed")?;
    let pipeline_ns = pipeline_start.elapsed().as_nanos() as u64;

    let report: BpfoptOptimizeReport = read_json_file(&report_json, "bpfopt optimize report")?;
    let mut passes = report
        .passes
        .iter()
        .map(pass_detail_from_report)
        .collect::<Vec<_>>();
    let opt_bytes = fs::read(&opt_bin).with_context(|| format!("read {}", opt_bin.display()))?;
    let final_insn_count = insn_count_from_bytes(&opt_bytes, "opt.bin")?;
    let mut changed = opt_bytes != orig_bytes;
    let use_fd_array = has_fd_array && bytecode_has_kinsn_call(&opt_bytes, "opt.bin")?;

    let mut total_rejit_ns = 0u64;
    let mut attempts = Vec::new();
    let status = "ok".to_string();
    let mut applied = false;
    let error_message = None;

    if !changed {
        attempts.push(AttemptRecord {
            attempt: 0,
            disabled_passes: Vec::new(),
            result: "no_change".to_string(),
            failure_pc: None,
            attributed_pass: None,
            debug: None,
        });
    } else {
        let mut final_verify_accepted = false;
        let verify_start = Instant::now();
        let mut verify = config.command("bpfverify");
        verify
            .arg("--prog-type")
            .arg(&prog_info.prog_type.name)
            .arg("--map-fds")
            .arg(&map_fds_json)
            .arg("--input")
            .arg(&opt_bin)
            .arg("--output")
            .arg(&verified_bin);
        if use_fd_array {
            verify.arg("--fd-array").arg(&fd_array_json);
        }
        match run_output(&mut verify) {
            Ok(_) => {
                total_rejit_ns += verify_start.elapsed().as_nanos() as u64;
                final_verify_accepted = true;
                for pass in &mut passes {
                    if pass.changed {
                        pass.verify = PassVerifyResult::accepted();
                        pass.verify_result = PassVerifyStatus::Accepted;
                    }
                }
            }
            Err(err) => {
                total_rejit_ns += verify_start.elapsed().as_nanos() as u64;
                let message = error_headline(&err);
                for pass in &mut passes {
                    if pass.changed {
                        pass.verify = PassVerifyResult::rejected(message.clone());
                        pass.verify_result = PassVerifyStatus::Rejected;
                        pass.verify_error = Some(message.clone());
                        pass.action = "rolled_back".to_string();
                        pass.rollback = Some(PassRollbackResult {
                            action: "restored_pre_pass_snapshot".to_string(),
                            restored_insn_count: pass.insns_before,
                        });
                    }
                }
                changed = false;
                attempts.push(AttemptRecord {
                    attempt: 0,
                    disabled_passes: Vec::new(),
                    result: "verify_failed".to_string(),
                    failure_pc: None,
                    attributed_pass: None,
                    debug: None,
                });
            }
        }

        if final_verify_accepted && matches!(mode, OptimizeMode::Apply) {
            let rejit_start = Instant::now();
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
            match run_output(&mut rejit) {
                Ok(_) => {
                    total_rejit_ns += rejit_start.elapsed().as_nanos() as u64;
                    applied = true;
                    attempts.push(AttemptRecord {
                        attempt: 0,
                        disabled_passes: Vec::new(),
                        result: "applied".to_string(),
                        failure_pc: None,
                        attributed_pass: None,
                        debug: None,
                    });
                }
                Err(err) => {
                    total_rejit_ns += rejit_start.elapsed().as_nanos() as u64;
                    let message = error_headline(&err);
                    changed = false;
                    for pass in &mut passes {
                        if pass.changed {
                            pass.action = "rolled_back".to_string();
                            pass.rollback = Some(PassRollbackResult {
                                action: "restored_pre_pass_snapshot".to_string(),
                                restored_insn_count: pass.insns_before,
                            });
                            pass.verify_error = Some(message.clone());
                        }
                    }
                    attempts.push(AttemptRecord {
                        attempt: 0,
                        disabled_passes: Vec::new(),
                        result: "rejit_failed".to_string(),
                        failure_pc: None,
                        attributed_pass: None,
                        debug: None,
                    });
                }
            }
        } else if final_verify_accepted {
            attempts.push(AttemptRecord {
                attempt: 0,
                disabled_passes: Vec::new(),
                result: "dry_run".to_string(),
                failure_pc: None,
                attributed_pass: None,
                debug: None,
            });
        }
    }

    let passes_applied = passes
        .iter()
        .filter(|pass| pass.changed && pass.action != "rolled_back")
        .map(|pass| pass.pass_name.clone())
        .collect::<Vec<_>>();
    let total_sites_applied = passes
        .iter()
        .filter(|pass| pass.action != "rolled_back")
        .map(|pass| pass.sites_applied)
        .sum();
    let verifier_rejections = passes
        .iter()
        .filter(|pass| matches!(pass.verify.status, PassVerifyStatus::Rejected))
        .count();
    let passes_changed = passes
        .iter()
        .filter(|pass| pass.changed && pass.action != "rolled_back")
        .count();
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
            verifier_rejections,
        },
        passes,
        attempts,
        timings_ns: TimingsNs {
            pipeline_run_ns: pipeline_ns,
            rejit_syscall_ns: total_rejit_ns,
            total_ns: total_start.elapsed().as_nanos() as u64,
        },
        inlined_map_entries: Vec::new(),
        error_message,
    })
}

fn pass_detail_from_report(report: &BpfoptPassReport) -> PassDetail {
    let verify = PassVerifyResult::not_needed();
    PassDetail {
        pass_name: report.pass.clone(),
        changed: report.changed,
        verify_result: verify.status.clone(),
        verify_error: None,
        action: "kept".to_string(),
        verify,
        rollback: None,
        sites_applied: report.sites_applied,
        sites_skipped: 0,
        skip_reasons: HashMap::new(),
        skipped_sites: Vec::new(),
        insns_before: report.insn_count_before,
        insns_after: report.insn_count_after,
        insn_delta: report.insn_delta as i64,
        diagnostics: Vec::new(),
    }
}

fn write_empty_map_values(map_fds_json: &Path, output: &Path) -> Result<()> {
    let maps: Vec<MapInfoJson> = read_json_file(map_fds_json, "map_fds.json")?;
    let payload = MapValuesJson {
        maps: maps
            .into_iter()
            .map(|map| MapValuesMapJson {
                map_id: map.map_id,
                map_type: map.map_type,
                key_size: map.key_size,
                value_size: map.value_size,
                max_entries: map.max_entries,
                frozen: false,
                entries: Vec::new(),
            })
            .collect(),
    };
    write_json_file(output, &payload)
}

fn needs_target(passes: &[String]) -> bool {
    passes.iter().any(|pass| {
        matches!(
            canonical_pass(pass).as_str(),
            "rotate" | "cond_select" | "extract" | "endian_fusion" | "bulk_memory"
        )
    })
}

fn target_satisfies_requested_kinsns(path: &Path, passes: &[String]) -> Result<bool> {
    let target: TargetJson = read_json_file(path, "target.json")?;
    Ok(passes
        .iter()
        .all(|pass| match canonical_pass(pass).as_str() {
            "rotate" => target_has_any(&target, &["bpf_rotate64"]),
            "cond_select" => target_has_any(&target, &["bpf_select64"]),
            "extract" => target_has_any(&target, &["bpf_extract64"]),
            "endian_fusion" => target_has_any(
                &target,
                &[
                    "bpf_endian_load16",
                    "bpf_endian_load32",
                    "bpf_endian_load64",
                ],
            ),
            "bulk_memory" => {
                target_has_any(&target, &["bpf_bulk_memcpy", "bpf_memcpy_bulk"])
                    && target_has_any(&target, &["bpf_bulk_memset", "bpf_memset_bulk"])
            }
            _ => true,
        }))
}

fn target_has_any(target: &TargetJson, names: &[&str]) -> bool {
    names.iter().any(|name| target.kinsns.contains_key(*name))
}

fn write_fd_array_from_target(target_path: &Path, passes: &[String], output: &Path) -> Result<()> {
    let target: TargetJson = read_json_file(target_path, "target.json")?;
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
        entries.push(FdArrayJsonEntry {
            slot: entries.len() + 1,
            name: name.to_string(),
            btf_id,
        });
    }
    write_json_file(output, &entries)
}

fn required_kinsn_names(passes: &[String]) -> Vec<&'static str> {
    let mut names = Vec::new();
    for pass in passes {
        match canonical_pass(pass).as_str() {
            "rotate" => push_unique(&mut names, "bpf_rotate64"),
            "cond_select" => push_unique(&mut names, "bpf_select64"),
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

fn run_output(command: &mut Command) -> Result<std::process::Output> {
    let program = format!("{command:?}");
    let output = command
        .output()
        .with_context(|| format!("spawn subprocess {program}"))?;
    if !output.status.success() {
        bail!("subprocess {program} failed: {}", stderr_summary(&output));
    }
    Ok(output)
}

fn run_with_file_io(command: &mut Command, input: &Path, output: &Path) -> Result<()> {
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
        bail!(
            "subprocess {program} failed: {}",
            stderr_summary(&child_output)
        );
    }
    Ok(())
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

fn error_headline(err: &anyhow::Error) -> String {
    format!("{err:#}")
        .lines()
        .next()
        .unwrap_or("<empty error message>")
        .to_string()
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::os::unix::fs::PermissionsExt;

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
{"id":$prog_id,"name":"demo","type":{"name":"xdp","numeric":6},"insn_cnt":2,"map_ids":[]}
JSON
printf '[]\n' > "$outdir/map_fds.json"
"#,
            )?;
            write_executable(
                &dir.path().join("bpfopt"),
                r#"#!/usr/bin/env bash
set -euo pipefail
if [[ "${1:-}" == "list-passes" ]]; then
  printf 'wide-mem\ndce\n'
  exit 0
fi
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
while [[ $# -gt 0 ]]; do
  case "$1" in
    --input) input="$2"; shift 2 ;;
    --output) output="$2"; shift 2 ;;
    --verifier-states-out) states="$2"; shift 2 ;;
    *) shift ;;
  esac
done
if [[ -n "$input" && -n "$output" ]]; then cp "$input" "$output"; fi
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
  printf '{"status":"ok","prog_id":%s,"insn_count_before":2,"insn_count_after":2,"dry_run":false}\n' "$prog_id" > "$out"
fi
"#,
            )?;
            write_executable(
                &dir.path().join("bpfprof"),
                r#"#!/usr/bin/env bash
set -euo pipefail
outdir=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --output-dir) outdir="$2"; shift 2 ;;
    *) shift ;;
  esac
done
printf '{"prog_id":42,"duration_ms":1,"run_cnt_delta":1,"run_time_ns_delta":1,"pmu_available":false,"branch_miss_rate":null,"branch_misses":null,"branch_instructions":null,"per_insn":{}}\n' > "$outdir/42.json"
"#,
            )?;
            Ok(Self { dir })
        }

        fn config(&self) -> CliConfig {
            CliConfig::with_dir(self.dir.path().to_path_buf())
        }
    }

    fn write_executable(path: &Path, text: &str) -> Result<()> {
        fs::write(path, text)?;
        let mut permissions = fs::metadata(path)?.permissions();
        permissions.set_mode(0o755);
        fs::set_permissions(path, permissions)?;
        Ok(())
    }

    #[test]
    fn optimize_uses_cli_subprocesses_and_preserves_response_shape() {
        let fake = FakeCliDir::new().unwrap();
        let result = try_apply_one(
            42,
            &fake.config(),
            Some(&["wide_mem".to_string()]),
            None,
            None,
            OptimizeMode::Apply,
        )
        .unwrap();

        assert_eq!(result.status, "ok");
        assert_eq!(result.prog_id, 42);
        assert!(result.changed);
        assert_eq!(result.passes_applied, vec!["wide_mem"]);
        assert!(result.summary.applied);
        assert_eq!(result.summary.total_sites_applied, 2);
        assert_eq!(result.summary.passes_executed, 1);
        assert_eq!(result.passes[0].verify_result, PassVerifyStatus::Accepted);
        assert_eq!(result.attempts[0].result, "applied");
    }

    #[test]
    fn incomplete_target_is_not_passed_to_bpfopt_optimize() {
        let fake = FakeCliDir::new().unwrap();
        let result = try_apply_one(
            42,
            &fake.config(),
            Some(&["rotate".to_string()]),
            None,
            None,
            OptimizeMode::Apply,
        )
        .unwrap();

        assert_eq!(result.status, "ok");
        assert!(result.summary.applied);
    }

    #[test]
    fn serve_optimize_response_omits_attempt_debug_payloads() {
        let result = OptimizeOneResult {
            status: "error".to_string(),
            prog_id: 7,
            changed: false,
            passes_applied: vec![],
            program: ProgramInfo {
                prog_id: 7,
                prog_name: "demo_prog".to_string(),
                prog_type: 6,
                orig_insn_count: 10,
                final_insn_count: 10,
                insn_delta: 0,
            },
            summary: OptimizeSummary {
                applied: false,
                total_sites_applied: 0,
                passes_executed: 1,
                passes_changed: 0,
                verifier_rejections: 1,
            },
            passes: vec![],
            attempts: vec![AttemptRecord {
                attempt: 0,
                disabled_passes: vec![],
                result: "rejit_failed".to_string(),
                failure_pc: Some(42),
                attributed_pass: Some("map_inline".to_string()),
                debug: Some(AttemptDebug {
                    warnings: vec!["large debug payload".to_string()],
                }),
            }],
            timings_ns: TimingsNs {
                pipeline_run_ns: 10,
                rejit_syscall_ns: 20,
                total_ns: 30,
            },
            inlined_map_entries: vec![],
            error_message: Some("kernel rejected BPF_PROG_REJIT".to_string()),
        };

        let json = serde_json::to_string(&ServeOptimizeResponse::from(result)).unwrap();
        let parsed: serde_json::Value = serde_json::from_str(&json).unwrap();

        assert_eq!(parsed["status"], "error");
        assert_eq!(parsed["attempts"][0]["failure_pc"], 42);
        assert_eq!(parsed["attempts"][0]["attributed_pass"], "map_inline");
        assert!(parsed["attempts"][0].get("debug").is_none());
    }

    #[test]
    fn profile_start_stop_uses_bpfprof_output_dir() {
        let fake = FakeCliDir::new().unwrap();
        let session = start_profile(&fake.config(), 1).unwrap();
        let frozen = stop_profile(session).unwrap();

        assert_eq!(frozen.programs_profiled(), 1);
        assert!(frozen.profile_path_for(42).is_some());
    }

    #[test]
    fn list_programs_parses_bpfget_json() {
        let fake = FakeCliDir::new().unwrap();
        let programs = list_programs(&fake.config()).unwrap();

        assert_eq!(programs.len(), 1);
        assert_eq!(programs[0].id, 42);
        assert_eq!(programs[0].name, "demo");
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
