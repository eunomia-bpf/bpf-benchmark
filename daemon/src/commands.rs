// SPDX-License-Identifier: MIT
//! Shared optimize/apply helpers used by `serve`.

use std::collections::{BTreeMap, HashMap, HashSet};
use std::fmt::Write as _;
use std::os::unix::io::{AsRawFd, RawFd};
use std::sync::{Arc, Mutex};
use std::time::{Duration, Instant};

use anyhow::{Context, Result};
use serde::Serialize;

use crate::invalidation::{BpfMapValueReader, MapInvalidationTracker};
use crate::{bpf, insn, pass, passes, profiler, verifier_log};

const HELPER_MAP_LOOKUP_ELEM: i32 = 1;

// ── OptimizeOneResult — structured return from try_apply_one ────────

/// Structured result from a single optimize operation.
/// Serialized as JSON by the serve endpoint.
#[derive(Clone, Debug, Serialize)]
pub(crate) struct OptimizeOneResult {
    pub status: String,
    pub prog_id: u32,
    pub changed: bool,
    pub passes_applied: Vec<String>,
    pub program: ProgramInfo,
    pub summary: OptimizeSummary,
    pub passes: Vec<PassDetail>,
    pub attempts: Vec<AttemptRecord>,
    pub timings_ns: TimingsNs,
    #[serde(skip_serializing_if = "Vec::is_empty", default)]
    pub inlined_map_entries: Vec<InlinedMapEntry>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub error_message: Option<String>,
}

/// One deduplicated map entry that `map_inline` specialized for this program.
#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
pub(crate) struct InlinedMapEntry {
    pub map_id: u32,
    pub key_hex: String,
    pub value_hex: String,
}

/// Program identity and size information.
#[derive(Clone, Debug, Serialize)]
pub(crate) struct ProgramInfo {
    pub prog_id: u32,
    pub prog_name: String,
    pub prog_type: u32,
    pub orig_insn_count: usize,
    pub final_insn_count: usize,
    pub insn_delta: i64,
}

/// Top-level summary of the optimization outcome.
#[derive(Clone, Debug, Serialize)]
pub(crate) struct OptimizeSummary {
    pub applied: bool,
    pub program_changed: bool,
    pub total_sites_applied: usize,
    pub passes_executed: usize,
    pub passes_changed: usize,
    pub verifier_retries: usize,
    pub final_disabled_passes: Vec<String>,
}

/// Per-pass detail record.
#[derive(Clone, Debug, Serialize)]
pub(crate) struct PassDetail {
    pub pass_name: String,
    pub changed: bool,
    pub sites_applied: usize,
    pub sites_skipped: usize,
    pub skip_reasons: HashMap<String, usize>,
    pub insns_before: usize,
    pub insns_after: usize,
    pub insn_delta: i64,
    pub diagnostics: Vec<String>,
}

impl From<&pass::PassResult> for PassDetail {
    fn from(pr: &pass::PassResult) -> Self {
        Self {
            pass_name: pr.pass_name.clone(),
            changed: pr.changed,
            sites_applied: pr.sites_applied,
            sites_skipped: pr.sites_skipped.len(),
            skip_reasons: pr.skip_reason_counts(),
            insns_before: pr.insns_before,
            insns_after: pr.insns_after,
            insn_delta: pr.insns_after as i64 - pr.insns_before as i64,
            diagnostics: pr.diagnostics.clone(),
        }
    }
}

fn changed_pass_names(passes: &[PassDetail]) -> Vec<String> {
    passes
        .iter()
        .filter(|pass| pass.changed)
        .map(|pass| pass.pass_name.clone())
        .collect()
}

/// Record of a single REJIT attempt (for rollback history).
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
    pub pass_traces: Vec<pass::PassDebugTrace>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub pre_rejit_bytecode: Option<insn::BpfBytecodeDump>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub verifier_log: Option<VerifierLogRecord>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub final_xlated_bytecode: Option<insn::BpfBytecodeDump>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub final_jited_machine_code: Option<bpf::MachineCodeDump>,
    #[serde(skip_serializing_if = "Vec::is_empty", default)]
    pub warnings: Vec<String>,
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct VerifierLogRecord {
    pub source: String,
    pub log_level: u32,
    pub log: String,
}

/// Timing breakdown in nanoseconds.
#[derive(Clone, Debug, Serialize)]
pub(crate) struct TimingsNs {
    pub pipeline_run_ns: u64,
    pub rejit_syscall_ns: u64,
    pub total_ns: u64,
}

#[derive(Clone, Copy, Debug)]
pub(crate) struct PgoConfig {
    pub interval: Duration,
}

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub(crate) enum OptimizeMode {
    Apply,
    DryRun,
}

impl OptimizeMode {
    fn should_apply(self) -> bool {
        matches!(self, Self::Apply)
    }
}

pub(crate) fn collect_pgo_data(
    prog_id: u32,
    pgo_config: Option<&PgoConfig>,
) -> Option<pass::ProfilingData> {
    let config = pgo_config?;
    match profiler::collect_program_profiling(prog_id, config.interval) {
        Ok((profiling, analysis)) => {
            if analysis.is_hot() {
                eprintln!(
                    "  pgo: prog {} is hot (delta_run_cnt={}, avg_ns={})",
                    prog_id,
                    analysis.delta_run_cnt,
                    analysis
                        .delta_avg_ns
                        .map_or("-".to_string(), |value| format!("{value:.2}")),
                );
            } else {
                eprintln!("  pgo: prog {} is cold (no activity during observation)");
            }

            if profiling.branch_miss_rate.is_none() {
                eprintln!(
                    "  pgo: prog {} has no PMU branch_miss_rate data; branch_flip will remain gated",
                    prog_id
                );
            }

            Some(profiling)
        }
        Err(err) => {
            eprintln!("  pgo: failed to profile prog {}: {:#}", prog_id, err);
            None
        }
    }
}

// ── Pipeline helpers ────────────────────────────────────────────────

/// Build the daemon's default optimization pipeline.
pub(crate) fn build_pipeline() -> pass::PassManager {
    passes::build_full_pipeline()
}

pub(crate) type SharedInvalidationTracker = Arc<Mutex<MapInvalidationTracker<BpfMapValueReader>>>;

pub(crate) fn new_invalidation_tracker() -> SharedInvalidationTracker {
    Arc::new(Mutex::new(MapInvalidationTracker::new(BpfMapValueReader)))
}

fn collect_map_inline_records(pass_results: &[pass::PassResult]) -> Vec<pass::MapInlineRecord> {
    pass_results
        .iter()
        .flat_map(|result| result.map_inline_records.iter().cloned())
        .collect()
}

fn hex_bytes(bytes: &[u8]) -> String {
    let mut out = String::with_capacity(bytes.len() * 2);
    for byte in bytes {
        let _ = write!(out, "{:02x}", byte);
    }
    out
}

fn collect_inlined_map_entries(
    map_inline_records: &[pass::MapInlineRecord],
) -> Vec<InlinedMapEntry> {
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
    map_inline_records: &[pass::MapInlineRecord],
    mut open_map_fd: F,
) -> Result<()>
where
    F: FnMut(u32) -> Result<std::os::unix::io::OwnedFd>,
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

fn tracker_tracks_prog(tracker: Option<&SharedInvalidationTracker>, prog_id: u32) -> Result<bool> {
    let Some(tracker) = tracker else {
        return Ok(false);
    };

    let tracker = tracker
        .lock()
        .map_err(|_| anyhow::anyhow!("invalidation tracker lock poisoned"))?;
    Ok(tracker.tracks_prog(prog_id))
}

fn refresh_invalidation_tracking(
    tracker: Option<&SharedInvalidationTracker>,
    prog_id: u32,
    map_inline_records: &[pass::MapInlineRecord],
) -> Result<()> {
    let Some(tracker) = tracker else {
        return Ok(());
    };

    let mut tracker = tracker
        .lock()
        .map_err(|_| anyhow::anyhow!("invalidation tracker lock poisoned"))?;
    record_map_inline_records(
        &mut tracker,
        prog_id,
        map_inline_records,
        bpf::bpf_map_get_fd_by_id,
    )
}

fn build_rejit_fd_array(required_btf_fds: &[RawFd]) -> Vec<RawFd> {
    if required_btf_fds.is_empty() {
        return Vec::new();
    }

    // CALL.off uses 0 for vmlinux and 1-based slots for descriptor BTFs.
    // The REJIT fd_array pre-scan requires every populated slot to be a valid
    // map or BTF fd, so reserve slot 0 with a duplicate valid BTF fd.
    let mut fd_array = Vec::with_capacity(required_btf_fds.len() + 1);
    fd_array.push(required_btf_fds[0]);
    fd_array.extend(required_btf_fds.iter().copied());
    fd_array
}

fn sorted_strings(values: impl IntoIterator<Item = String>) -> Vec<String> {
    let mut values: Vec<String> = values.into_iter().collect();
    values.sort();
    values
}

fn new_attempt_debug(pass_traces: Vec<pass::PassDebugTrace>) -> Option<AttemptDebug> {
    Some(AttemptDebug {
        pass_traces,
        pre_rejit_bytecode: None,
        verifier_log: None,
        final_xlated_bytecode: None,
        final_jited_machine_code: None,
        warnings: Vec::new(),
    })
}

fn push_debug_warning(debug: &mut Option<AttemptDebug>, warning: impl Into<String>) {
    if let Some(debug) = debug.as_mut() {
        debug.warnings.push(warning.into());
    }
}

pub(crate) fn emit_debug_result(result: &OptimizeOneResult) {
    match serde_json::to_string(result) {
        Ok(json) => eprintln!("{}", json),
        Err(err) => eprintln!("debug-log: failed to serialize optimize result: {err}"),
    }
}

/// Attribute a verifier failure to a specific pass using the pipeline's
/// transform attribution data and the verifier log.
///
/// Returns the name of the pass that likely caused the failure, or `None`
/// if the failure cannot be attributed.
fn attribute_verifier_failure(
    verifier_log_text: &str,
    attribution: &[pass::TransformAttribution],
) -> Option<String> {
    let failed_pc = verifier_log::extract_failure_pc(verifier_log_text)?;

    // If multiple passes touch the same PC, pick the last one (most recently
    // applied).
    let mut candidate: Option<&str> = None;
    for attr in attribution {
        if attr
            .pc_ranges
            .iter()
            .any(|range| range.contains(&failed_pc))
        {
            candidate = Some(&attr.pass_name);
        }
    }

    candidate.map(|s| s.to_string())
}

fn verifier_log_looks_complete(verifier_log_text: &str) -> bool {
    verifier_log_text.contains("\nprocessed ")
        || verifier_log_text.contains("\nSCC exit")
        || verifier_log_text.lines().any(|line| line.trim() == "safe")
}

fn should_treat_as_verifier_rejection(err_msg: &str, verifier_log_text: &str) -> bool {
    if verifier_log_text.is_empty() {
        return false;
    }

    let Some(first_line) = err_msg.lines().next() else {
        return false;
    };
    let first_line = first_line.to_ascii_lowercase();
    if first_line.contains("no space left on device")
        || first_line.contains("out of memory")
        || first_line.contains("operation not supported")
    {
        return false;
    }

    !verifier_log_looks_complete(verifier_log_text)
}

fn should_retry_post_verify_rejit_failure(err_msg: &str, verifier_log_text: &str) -> bool {
    if !verifier_log_looks_complete(verifier_log_text) {
        return false;
    }

    let Some(first_line) = err_msg.lines().next() else {
        return false;
    };
    let first_line = first_line.to_ascii_lowercase();
    first_line.contains("no space left on device")
        || first_line.contains("argument list too long")
        || first_line.contains("invalid argument")
        || first_line.contains("out of memory")
}

fn attribute_post_verify_rejit_failure(passes: &[PassDetail]) -> Option<String> {
    passes
        .iter()
        .rev()
        .find(|pass| pass.changed)
        .map(|pass| pass.pass_name.clone())
}

fn program_has_map_lookup_elem(insns: &[insn::BpfInsn]) -> bool {
    insns
        .iter()
        .any(|insn| insn.is_call() && insn.src_reg() == 0 && insn.imm == HELPER_MAP_LOOKUP_ELEM)
}

fn maybe_attach_original_verifier_states(
    prog_fd: RawFd,
    orig_insns: &[insn::BpfInsn],
    map_ids: &[u32],
    program: &mut pass::BpfProgram,
) {
    if !program_has_map_lookup_elem(orig_insns) {
        return;
    }

    let mut probe_insns = orig_insns.to_vec();
    let map_fd_bindings = pass::build_map_fd_bindings(orig_insns, map_ids);
    let capture = (|| -> Result<Vec<verifier_log::VerifierInsn>> {
        let _map_fds_guard =
            bpf::relocate_map_fds_with_bindings(&mut probe_insns, map_ids, &map_fd_bindings)
                .context("relocate map FDs for verifier-log capture")?;
        let result = bpf::bpf_prog_rejit_capture_verifier_log(prog_fd, &probe_insns, &[])
            .context("capture original-program verifier log via BPF_PROG_REJIT(log_level=2)")?;
        Ok(verifier_log::parse_verifier_log(&result.verifier_log))
    })();

    match capture {
        Ok(states) if !states.is_empty() => program.set_verifier_states(states),
        Ok(_) => {}
        Err(err) => {
            eprintln!(
                "    warning: failed to capture original-program verifier log for prog fd {}: {:#}",
                prog_fd, err
            );
        }
    }
}

/// Try to apply rewrites to a single program via PassManager.
///
/// Returns a structured `OptimizeOneResult` describing everything that happened:
/// program info, per-pass details, rollback attempts, and timings.
pub(crate) fn try_apply_one(
    prog_id: u32,
    ctx: &pass::PassContext,
    pgo_config: Option<&PgoConfig>,
    rollback_enabled: bool,
    invalidation_tracker: Option<&SharedInvalidationTracker>,
    mode: OptimizeMode,
) -> Result<OptimizeOneResult> {
    let total_start = Instant::now();
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id)?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(fd.as_raw_fd(), true)?;

    let prog_name = info.name_str().to_string();
    let orig_insn_count = if !orig_insns.is_empty() {
        orig_insns.len()
    } else {
        info.orig_prog_len as usize / 8
    };

    let make_result = |status: &str,
                       applied: bool,
                       program_changed: bool,
                       total_sites_applied: usize,
                       final_count: usize,
                       passes: Vec<PassDetail>,
                       attempts: Vec<AttemptRecord>,
                       pipeline_ns: u64,
                       rejit_ns: u64,
                       final_disabled_passes: Vec<String>,
                       inlined_map_entries: Vec<InlinedMapEntry>,
                       error_message: Option<String>|
     -> OptimizeOneResult {
        let total_ns = total_start.elapsed().as_nanos() as u64;
        let verifier_retries = attempts
            .iter()
            .filter(|attempt| attempt.result == "verifier_rejected")
            .count();
        OptimizeOneResult {
            status: status.to_string(),
            prog_id,
            changed: program_changed,
            passes_applied: changed_pass_names(&passes),
            program: ProgramInfo {
                prog_id,
                prog_name: prog_name.clone(),
                prog_type: info.prog_type,
                orig_insn_count,
                final_insn_count: final_count,
                insn_delta: final_count as i64 - orig_insn_count as i64,
            },
            summary: OptimizeSummary {
                applied,
                program_changed,
                total_sites_applied,
                passes_executed: passes.len(),
                passes_changed: passes.iter().filter(|pass| pass.changed).count(),
                verifier_retries,
                final_disabled_passes,
            },
            passes,
            attempts,
            timings_ns: TimingsNs {
                pipeline_run_ns: pipeline_ns,
                rejit_syscall_ns: rejit_ns,
                total_ns,
            },
            inlined_map_entries,
            error_message,
        }
    };

    if orig_insns.is_empty() {
        return Ok(make_result(
            "ok",
            false,
            false,
            0,
            orig_insn_count,
            vec![],
            vec![],
            0,
            0,
            vec![],
            vec![],
            None,
        ));
    }

    // Fetch map IDs for FD relocation before REJIT.
    let map_ids =
        bpf::bpf_prog_get_map_ids(fd.as_raw_fd()).context("fetch program map IDs for apply")?;
    let original_verifier_states = {
        let mut seed_program = pass::BpfProgram::new(orig_insns.clone());
        maybe_attach_original_verifier_states(
            fd.as_raw_fd(),
            &orig_insns,
            &map_ids,
            &mut seed_program,
        );
        seed_program.verifier_states.clone()
    };
    let profiling = collect_pgo_data(prog_id, pgo_config);

    let mut disabled_passes: HashSet<String> = HashSet::new();
    let max_retries = 10;
    let mut attempts: Vec<AttemptRecord> = Vec::new();
    let mut last_pass_details: Vec<PassDetail> = Vec::new();
    let mut total_pipeline_ns: u64 = 0;
    let mut total_rejit_ns: u64 = 0;
    let had_tracked_inline_sites = tracker_tracks_prog(invalidation_tracker, prog_id)?;
    for attempt in 0..=max_retries {
        let mut program = pass::BpfProgram::new(orig_insns.clone());
        program.set_map_ids(map_ids.clone());
        program.verifier_states = original_verifier_states.clone();
        let pm = build_pipeline();
        let mut local_ctx = ctx.clone();
        local_ctx.prog_type = info.prog_type;
        for disabled in sorted_strings(disabled_passes.iter().cloned()) {
            local_ctx.policy.disabled_passes.push(disabled.clone());
        }

        let pipeline_start = Instant::now();
        let pipeline_result = pm.run_with_profiling(&mut program, &local_ctx, profiling.as_ref())?;
        let pipeline_elapsed = pipeline_start.elapsed().as_nanos() as u64;
        total_pipeline_ns += pipeline_elapsed;
        let attempt_map_inline_records = collect_map_inline_records(&pipeline_result.pass_results);
        let attempt_inlined_map_entries = collect_inlined_map_entries(&attempt_map_inline_records);

        // Build per-pass details from the latest pipeline run.
        last_pass_details = pipeline_result
            .pass_results
            .iter()
            .map(PassDetail::from)
            .collect();
        let mut attempt_debug = new_attempt_debug(pipeline_result.debug_traces.clone());
        let disabled_passes_sorted = sorted_strings(disabled_passes.iter().cloned());

        if !pipeline_result.program_changed {
            if !mode.should_apply() {
                attempts.push(AttemptRecord {
                    attempt,
                    disabled_passes: disabled_passes_sorted.clone(),
                    result: "dry_run".to_string(),
                    failure_pc: None,
                    attributed_pass: None,
                    debug: attempt_debug,
                });

                return Ok(make_result(
                    "ok",
                    false,
                    false,
                    0,
                    orig_insn_count,
                    last_pass_details,
                    attempts,
                    total_pipeline_ns,
                    total_rejit_ns,
                    disabled_passes_sorted,
                    vec![],
                    None,
                ));
            }

            let mut restore_insns = orig_insns.clone();
            let _map_fds_guard = bpf::relocate_map_fds_with_bindings(
                &mut restore_insns,
                &map_ids,
                &program.map_fd_bindings,
            )
            .context("relocate map FDs before identity REJIT")?;

            if let Some(debug) = attempt_debug.as_mut() {
                debug.pre_rejit_bytecode = Some(insn::dump_bytecode_compact(&restore_insns));
                debug.warnings.push(
                    "program was unchanged; issuing identity REJIT with original bytecode"
                        .to_string(),
                );
            }

            let rejit_start = Instant::now();
            bpf::bpf_prog_rejit(fd.as_raw_fd(), &restore_insns, &[])?;
            total_rejit_ns += rejit_start.elapsed().as_nanos() as u64;

            if had_tracked_inline_sites {
                if let Err(err) = refresh_invalidation_tracking(invalidation_tracker, prog_id, &[])
                {
                    eprintln!(
                        "    warning: failed to clear invalidation tracking for prog {}: {:#}",
                        prog_id, err
                    );
                }
            }

            attempts.push(AttemptRecord {
                attempt,
                disabled_passes: disabled_passes_sorted.clone(),
                result: "identity_rejit".to_string(),
                failure_pc: None,
                attributed_pass: None,
                debug: attempt_debug,
            });

            return Ok(make_result(
                "ok",
                true,
                false,
                0,
                orig_insn_count,
                last_pass_details,
                attempts,
                total_pipeline_ns,
                total_rejit_ns,
                disabled_passes_sorted,
                vec![],
                None,
            ));
        }

        let final_insn_count = program.insns.len();

        if !mode.should_apply() {
            attempts.push(AttemptRecord {
                attempt,
                disabled_passes: disabled_passes_sorted.clone(),
                result: "dry_run".to_string(),
                failure_pc: None,
                attributed_pass: None,
                debug: attempt_debug,
            });

            return Ok(make_result(
                "ok",
                false,
                true,
                pipeline_result.total_sites_applied,
                final_insn_count,
                last_pass_details,
                attempts,
                total_pipeline_ns,
                total_rejit_ns,
                disabled_passes_sorted,
                attempt_inlined_map_entries,
                None,
            ));
        }

        if disabled_passes.is_empty() {
            println!(
                "  prog {} ({}): {} sites, {} -> {} insns",
                prog_id,
                info.name_str(),
                pipeline_result.total_sites_applied,
                orig_insns.len(),
                final_insn_count,
            );
        }

        // Relocate stale map FDs in the rewritten bytecode.
        let _map_fds_guard = bpf::relocate_map_fds_with_bindings(
            &mut program.insns,
            &map_ids,
            &program.map_fd_bindings,
        )
        .context("relocate map FDs before REJIT")?;

        if let Some(debug) = attempt_debug.as_mut() {
            debug.pre_rejit_bytecode = Some(insn::dump_bytecode_compact(&program.insns));
        }

        let fd_array = build_rejit_fd_array(&program.required_btf_fds);
        let all_fds = local_ctx.kinsn_registry.all_btf_fds();
        for &fd_needed in &program.required_btf_fds {
            if !all_fds.contains(&fd_needed) {
                eprintln!(
                    "    warning: required kinsn BTF fd {} not in registry ({:?})",
                    fd_needed, all_fds
                );
                push_debug_warning(
                    &mut attempt_debug,
                    format!(
                        "required kinsn BTF fd {fd_needed} missing from registry {:?}",
                        all_fds
                    ),
                );
            }
        }

        let rejit_start = Instant::now();
        match bpf::bpf_prog_rejit(fd.as_raw_fd(), &program.insns, &fd_array) {
            Ok(rejit_result) => {
                let rejit_elapsed = rejit_start.elapsed().as_nanos() as u64;
                total_rejit_ns += rejit_elapsed;

                if disabled_passes.is_empty() {
                    println!("    REJIT ok");
                } else {
                    println!(
                        "    REJIT ok (after disabling: {})",
                        disabled_passes
                            .iter()
                            .cloned()
                            .collect::<Vec<_>>()
                            .join(", ")
                    );
                }

                if let Some(debug) = attempt_debug.as_mut() {
                    if rejit_result.verifier_log.is_empty() {
                        debug.warnings.push(
                            "REJIT succeeded but the verifier log buffer was empty".to_string(),
                        );
                    } else {
                        debug.verifier_log = Some(VerifierLogRecord {
                            source: "BPF_PROG_REJIT".to_string(),
                            log_level: 2,
                            log: rejit_result.verifier_log.clone(),
                        });
                        debug.warnings.push(
                            "verifier log captured from BPF_PROG_REJIT(log_level=2); daemon-only debug mode cannot reconstruct the full original BPF_PROG_LOAD attr for arbitrary live programs".to_string(),
                        );
                    }

                    match bpf::bpf_prog_get_runtime_images(fd.as_raw_fd()) {
                        Ok(images) => {
                            debug.final_xlated_bytecode =
                                Some(insn::dump_bytecode_compact(&images.xlated_insns));
                            debug.final_jited_machine_code =
                                Some(bpf::dump_machine_code(&images.jited_prog_insns));
                        }
                        Err(err) => debug.warnings.push(format!(
                            "failed to fetch final xlated/jited images: {err:#}"
                        )),
                    }
                }

                attempts.push(AttemptRecord {
                    attempt,
                    disabled_passes: disabled_passes_sorted.clone(),
                    result: "applied".to_string(),
                    failure_pc: None,
                    attributed_pass: None,
                    debug: attempt_debug,
                });

                if let Err(err) = refresh_invalidation_tracking(
                    invalidation_tracker,
                    prog_id,
                    &attempt_map_inline_records,
                ) {
                    eprintln!(
                        "    warning: failed to refresh invalidation tracking for prog {}: {:#}",
                        prog_id, err
                    );
                }

                return Ok(make_result(
                    "ok",
                    true,
                    true,
                    pipeline_result.total_sites_applied,
                    final_insn_count,
                    last_pass_details,
                    attempts,
                    total_pipeline_ns,
                    total_rejit_ns,
                    disabled_passes_sorted,
                    attempt_inlined_map_entries,
                    None,
                ));
            }
            Err(e) => {
                let rejit_elapsed = rejit_start.elapsed().as_nanos() as u64;
                total_rejit_ns += rejit_elapsed;

                let err_msg = format!("{:#}", e);
                let log_text = err_msg
                    .find("verifier log:\n")
                    .map(|pos| &err_msg[pos + "verifier log:\n".len()..])
                    .unwrap_or("");

                if let Some(debug) = attempt_debug.as_mut() {
                    if !log_text.is_empty() {
                        debug.verifier_log = Some(VerifierLogRecord {
                            source: "BPF_PROG_REJIT".to_string(),
                            log_level: 2,
                            log: log_text.to_string(),
                        });
                        debug.warnings.push(
                            "verifier log captured from BPF_PROG_REJIT(log_level=2) failure path"
                                .to_string(),
                        );
                    } else {
                        debug
                            .warnings
                            .push("REJIT failed without returning a verifier log".to_string());
                    }
                }

                let failed_pc = verifier_log::extract_failure_pc(log_text);
                let verifier_rejected = should_treat_as_verifier_rejection(&err_msg, log_text);
                let post_verify_retryable =
                    should_retry_post_verify_rejit_failure(&err_msg, log_text);

                // Attempt rollback if enabled.
                if rollback_enabled && verifier_rejected {
                    if let Some(ref failed_pass_name) =
                        attribute_verifier_failure(log_text, &pipeline_result.attribution)
                    {
                        if !disabled_passes.contains(failed_pass_name) {
                            eprintln!(
                                "    WARN: pass '{}' caused verifier rejection{} for prog {} ({})",
                                failed_pass_name,
                                failed_pc.map_or(String::new(), |pc| format!(" at PC {}", pc)),
                                prog_id,
                                info.name_str(),
                            );
                            eprintln!("          Disabling '{}', retrying...", failed_pass_name,);

                            attempts.push(AttemptRecord {
                                attempt,
                                disabled_passes: disabled_passes_sorted.clone(),
                                result: "verifier_rejected".to_string(),
                                failure_pc: failed_pc,
                                attributed_pass: Some(failed_pass_name.clone()),
                                debug: attempt_debug,
                            });

                            disabled_passes.insert(failed_pass_name.clone());
                            continue;
                        }
                    }
                }

                if rollback_enabled && post_verify_retryable {
                    if let Some(failed_pass_name) =
                        attribute_post_verify_rejit_failure(&last_pass_details)
                    {
                        if !disabled_passes.contains(&failed_pass_name) {
                            let first_line = match err_msg.lines().next() {
                                Some(line) => line,
                                None => "<empty error message>",
                            };
                            eprintln!(
                                "    WARN: pass '{}' caused post-verifier REJIT failure ({}) for prog {} ({})",
                                failed_pass_name,
                                first_line,
                                prog_id,
                                info.name_str(),
                            );
                            eprintln!("          Disabling '{}', retrying...", failed_pass_name);

                            attempts.push(AttemptRecord {
                                attempt,
                                disabled_passes: disabled_passes_sorted.clone(),
                                result: "rejit_failed".to_string(),
                                failure_pc: None,
                                attributed_pass: Some(failed_pass_name.clone()),
                                debug: attempt_debug,
                            });

                            disabled_passes.insert(failed_pass_name);
                            continue;
                        }
                    }
                }

                // Cannot attribute or rollback disabled — record final attempt and fail.
                attempts.push(AttemptRecord {
                    attempt,
                    disabled_passes: disabled_passes_sorted.clone(),
                    result: if verifier_rejected {
                        "verifier_rejected".to_string()
                    } else {
                        "rejit_failed".to_string()
                    },
                    failure_pc: if verifier_rejected { failed_pc } else { None },
                    attributed_pass: None,
                    debug: attempt_debug,
                });

                if verifier_rejected && !log_text.is_empty() {
                    let parsed = verifier_log::parse_verifier_log(log_text);
                    eprintln!(
                        "    REJIT failed: verifier rejected with {} state snapshots",
                        parsed.len()
                    );
                    for vi in &parsed {
                        let regs: Vec<String> = vi
                            .regs
                            .iter()
                            .map(|(r, s)| format!("R{}={}", r, s.reg_type))
                            .collect();
                        eprintln!("      pc={}: {}", vi.pc, regs.join(" "));
                    }
                }

                {
                    let failure_result = make_result(
                        "error",
                        false,
                        true,
                        pipeline_result.total_sites_applied,
                        final_insn_count,
                        last_pass_details.clone(),
                        attempts.clone(),
                        total_pipeline_ns,
                        total_rejit_ns,
                        disabled_passes_sorted,
                        vec![],
                        Some(err_msg),
                    );
                    emit_debug_result(&failure_result);
                }
                return Err(e);
            }
        }
    }

    let exhausted_msg = format!(
        "prog {}: exhausted rollback retries ({} passes disabled)",
        prog_id,
        disabled_passes.len()
    );

    {
        let failure_result = make_result(
            "error",
            false,
            true,
            0,
            orig_insn_count,
            last_pass_details,
            attempts,
            total_pipeline_ns,
            total_rejit_ns,
            sorted_strings(disabled_passes.iter().cloned()),
            vec![],
            Some(exhausted_msg.clone()),
        );
        emit_debug_result(&failure_result);
    }

    anyhow::bail!(exhausted_msg)
}

// ── Tests ───────────────────────────────────────────────────────────

#[cfg(test)]
#[path = "commands_tests.rs"]
mod tests;
