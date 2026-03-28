
use super::*;
use std::cell::RefCell;
use std::collections::HashMap;
use std::fs::File;
use std::os::unix::io::AsRawFd;
use std::rc::Rc;

use crate::invalidation::{BatchLookupValue, MapInvalidationTracker, MapValueReader};

#[derive(Clone, Debug, Default)]
struct MockTrackerReader {
    values: Rc<RefCell<HashMap<u32, HashMap<Vec<u8>, Vec<u8>>>>>,
}

impl MockTrackerReader {
    fn set_value(&self, map_fd: u32, key: Vec<u8>, value: Vec<u8>) {
        self.values
            .borrow_mut()
            .entry(map_fd)
            .or_default()
            .insert(key, value);
    }
}

impl MapValueReader for MockTrackerReader {
    fn lookup_values_batch(
        &self,
        map_fd: u32,
        keys: &[Vec<u8>],
    ) -> Result<Vec<BatchLookupValue>> {
        let values = self.values.borrow();
        let map_values = values.get(&map_fd).cloned().unwrap_or_default();
        Ok(keys
            .iter()
            .cloned()
            .map(|key| BatchLookupValue {
                value: map_values.get(&key).cloned(),
                key,
            })
            .collect())
    }
}

#[test]
fn test_optimize_one_result_serialization() {
    let result = OptimizeOneResult {
        status: "ok".to_string(),
        prog_id: 42,
        changed: true,
        passes_applied: vec!["wide_mem".to_string()],
        program: ProgramInfo {
            prog_id: 42,
            prog_name: "test_prog".to_string(),
            prog_type: 6,
            orig_insn_count: 100,
            final_insn_count: 90,
            insn_delta: -10,
        },
        summary: OptimizeSummary {
            applied: true,
            program_changed: true,
            total_sites_applied: 3,
            passes_executed: 2,
            passes_changed: 1,
            verifier_retries: 0,
            final_disabled_passes: vec![],
        },
        passes: vec![
            PassDetail {
                pass_name: "wide_mem".to_string(),
                changed: true,
                sites_applied: 3,
                sites_skipped: 1,
                skip_reasons: HashMap::from([("subprog_unsupported".to_string(), 1)]),
                insns_before: 100,
                insns_after: 90,
                insn_delta: -10,
                diagnostics: vec![],
            },
            PassDetail {
                pass_name: "rotate".to_string(),
                changed: false,
                sites_applied: 0,
                sites_skipped: 0,
                skip_reasons: HashMap::new(),
                insns_before: 90,
                insns_after: 90,
                insn_delta: 0,
                diagnostics: vec![],
            },
        ],
        attempts: vec![AttemptRecord {
            attempt: 0,
            disabled_passes: vec![],
            result: "applied".to_string(),
            failure_pc: None,
            attributed_pass: None,
            debug: None,
        }],
        timings_ns: TimingsNs {
            pipeline_run_ns: 100_000,
            rejit_syscall_ns: 50_000,
            total_ns: 200_000,
        },
        inlined_map_entries: vec![InlinedMapEntry {
            map_id: 7,
            key_hex: "00000000".to_string(),
            value_hex: "0b000000".to_string(),
        }],
        error_message: None,
    };

    let json = serde_json::to_string(&result).expect("serialization should succeed");
    let parsed: serde_json::Value =
        serde_json::from_str(&json).expect("JSON should parse back");

    assert_eq!(parsed["status"], "ok");
    assert_eq!(parsed["prog_id"], 42);
    assert_eq!(parsed["changed"], true);
    assert_eq!(parsed["passes_applied"][0], "wide_mem");
    assert_eq!(parsed["program"]["prog_id"], 42);
    assert_eq!(parsed["program"]["insn_delta"], -10);
    assert_eq!(parsed["summary"]["applied"], true);
    assert_eq!(parsed["summary"]["total_sites_applied"], 3);
    assert_eq!(parsed["summary"]["verifier_retries"], 0);
    assert_eq!(parsed["passes"].as_array().unwrap().len(), 2);
    assert_eq!(parsed["passes"][0]["pass_name"], "wide_mem");
    assert_eq!(parsed["passes"][0]["changed"], true);
    assert_eq!(
        parsed["passes"][0]["skip_reasons"]["subprog_unsupported"],
        1
    );
    assert_eq!(parsed["passes"][1]["changed"], false);
    assert_eq!(parsed["attempts"].as_array().unwrap().len(), 1);
    assert_eq!(parsed["attempts"][0]["result"], "applied");
    // failure_pc and attributed_pass should be absent when None
    assert!(parsed["attempts"][0].get("failure_pc").is_none());
    assert!(parsed["attempts"][0].get("attributed_pass").is_none());
    assert!(parsed["attempts"][0].get("debug").is_none());
    assert_eq!(parsed["timings_ns"]["pipeline_run_ns"], 100_000);
    assert_eq!(parsed["timings_ns"]["rejit_syscall_ns"], 50_000);
    assert_eq!(parsed["timings_ns"]["total_ns"], 200_000);
    assert_eq!(parsed["inlined_map_entries"][0]["map_id"], 7);
    assert_eq!(parsed["inlined_map_entries"][0]["key_hex"], "00000000");
    assert_eq!(parsed["inlined_map_entries"][0]["value_hex"], "0b000000");
    assert!(parsed.get("error_message").is_none());
}

#[test]
fn test_optimize_one_result_with_rollback() {
    let result = OptimizeOneResult {
        status: "ok".to_string(),
        prog_id: 99,
        changed: true,
        passes_applied: vec!["extract".to_string()],
        program: ProgramInfo {
            prog_id: 99,
            prog_name: "xdp_main".to_string(),
            prog_type: 6,
            orig_insn_count: 110,
            final_insn_count: 100,
            insn_delta: -10,
        },
        summary: OptimizeSummary {
            applied: true,
            program_changed: true,
            total_sites_applied: 2,
            passes_executed: 3,
            passes_changed: 1,
            verifier_retries: 1,
            final_disabled_passes: vec!["branch_flip".to_string()],
        },
        passes: vec![],
        attempts: vec![
            AttemptRecord {
                attempt: 0,
                disabled_passes: vec![],
                result: "verifier_rejected".to_string(),
                failure_pc: Some(76),
                attributed_pass: Some("branch_flip".to_string()),
                debug: None,
            },
            AttemptRecord {
                attempt: 1,
                disabled_passes: vec!["branch_flip".to_string()],
                result: "applied".to_string(),
                failure_pc: None,
                attributed_pass: None,
                debug: None,
            },
        ],
        timings_ns: TimingsNs {
            pipeline_run_ns: 200_000,
            rejit_syscall_ns: 100_000,
            total_ns: 400_000,
        },
        inlined_map_entries: vec![],
        error_message: None,
    };

    let json = serde_json::to_string(&result).expect("serialization should succeed");
    let parsed: serde_json::Value =
        serde_json::from_str(&json).expect("JSON should parse back");

    assert_eq!(parsed["summary"]["verifier_retries"], 1);
    assert_eq!(parsed["passes_applied"][0], "extract");
    assert_eq!(parsed["summary"]["final_disabled_passes"][0], "branch_flip");
    assert_eq!(parsed["attempts"].as_array().unwrap().len(), 2);
    assert_eq!(parsed["attempts"][0]["failure_pc"], 76);
    assert_eq!(parsed["attempts"][0]["attributed_pass"], "branch_flip");
    assert_eq!(parsed["attempts"][1]["result"], "applied");
    assert!(parsed.get("inlined_map_entries").is_none());
}

#[test]
fn test_pass_detail_from_pass_result() {
    let pr = pass::PassResult {
        pass_name: "wide_mem".to_string(),
        changed: true,
        sites_applied: 5,
        sites_skipped: vec![
            pass::SkipReason {
                pc: 10,
                reason: "subprog_unsupported".to_string(),
            },
            pass::SkipReason {
                pc: 20,
                reason: "subprog_unsupported".to_string(),
            },
            pass::SkipReason {
                pc: 30,
                reason: "kfunc_unavailable".to_string(),
            },
        ],
        diagnostics: vec!["test".to_string()],
        map_inline_records: vec![],
        insns_before: 100,
        insns_after: 95,
    };

    let detail = PassDetail::from(&pr);

    assert_eq!(detail.pass_name, "wide_mem");
    assert_eq!(detail.changed, true);
    assert_eq!(detail.sites_applied, 5);
    assert_eq!(detail.sites_skipped, 3);
    assert_eq!(detail.skip_reasons["subprog_unsupported"], 2);
    assert_eq!(detail.skip_reasons["kfunc_unavailable"], 1);
    assert_eq!(detail.insns_before, 100);
    assert_eq!(detail.insns_after, 95);
    assert_eq!(detail.insn_delta, -5);
}

#[test]
fn test_collect_inlined_map_entries_deduplicates_map_key_pairs() {
    let entries = collect_inlined_map_entries(&[
        pass::MapInlineRecord {
            map_id: 17,
            key: 0u32.to_le_bytes().to_vec(),
            expected_value: 11u32.to_le_bytes().to_vec(),
        },
        pass::MapInlineRecord {
            map_id: 17,
            key: 0u32.to_le_bytes().to_vec(),
            expected_value: 22u32.to_le_bytes().to_vec(),
        },
        pass::MapInlineRecord {
            map_id: 18,
            key: 1u32.to_le_bytes().to_vec(),
            expected_value: 33u32.to_le_bytes().to_vec(),
        },
    ]);

    assert_eq!(
        entries,
        vec![
            InlinedMapEntry {
                map_id: 17,
                key_hex: "00000000".to_string(),
                value_hex: "16000000".to_string(),
            },
            InlinedMapEntry {
                map_id: 18,
                key_hex: "01000000".to_string(),
                value_hex: "21000000".to_string(),
            },
        ]
    );
}

#[test]
fn test_record_map_inline_records_updates_tracker() {
    let reader = MockTrackerReader::default();
    let mut tracker = MapInvalidationTracker::new(reader.clone());
    let key = 1u32.to_le_bytes().to_vec();
    let expected_value = 11u32.to_le_bytes().to_vec();
    let records = vec![pass::MapInlineRecord {
        map_id: 77,
        key: key.clone(),
        expected_value: expected_value.clone(),
    }];
    let mut opened_fds = HashMap::new();

    record_map_inline_records(&mut tracker, 101, &records, |map_id| {
        let file = File::open("/dev/null")?;
        opened_fds.insert(map_id, file.as_raw_fd() as u32);
        Ok(file.into())
    })
    .expect("record_map_inline_records should succeed");

    assert_eq!(tracker.entry_count(), 1);

    let map_fd = opened_fds[&77];
    reader.set_value(map_fd, key.clone(), expected_value);
    assert!(tracker
        .check_for_invalidations()
        .expect("check_for_invalidations should succeed")
        .is_empty());

    reader.set_value(map_fd, key, 99u32.to_le_bytes().to_vec());
    assert_eq!(
        tracker
            .check_for_invalidations()
            .expect("check_for_invalidations should succeed"),
        vec![101]
    );
}

#[test]
fn test_record_map_inline_records_preserves_existing_entries_on_open_failure() {
    let reader = MockTrackerReader::default();
    let mut tracker = MapInvalidationTracker::new(reader);
    tracker.record_inline_site(
        101,
        7,
        1u32.to_le_bytes().to_vec(),
        11u32.to_le_bytes().to_vec(),
    );

    let records = vec![pass::MapInlineRecord {
        map_id: 77,
        key: 2u32.to_le_bytes().to_vec(),
        expected_value: 22u32.to_le_bytes().to_vec(),
    }];

    let err = record_map_inline_records(&mut tracker, 101, &records, |_map_id| {
        anyhow::bail!("synthetic open failure")
    })
    .expect_err("record_map_inline_records should fail");

    assert!(err.to_string().contains("synthetic open failure"));
    assert_eq!(tracker.entry_count(), 1);
    assert!(tracker.tracks_prog(101));
}

// ── HIGH #3: Orchestration unit tests ───────────────────────────

/// Test attribute_verifier_failure — the core attribution logic used by
/// the rollback loop in cmd_apply / try_apply_one.
///
/// The verifier log format requires state lines (e.g., "15: R0=scalar R1=ctx()")
/// followed by error lines. extract_failure_pc extracts the PC from the last
/// state line before an error keyword.
#[test]
fn test_attribute_verifier_failure_basic() {
    let attribution = vec![
        pass::TransformAttribution {
            pass_name: "wide_mem".to_string(),
            pc_ranges: vec![10..20],
        },
        pass::TransformAttribution {
            pass_name: "rotate".to_string(),
            pc_ranges: vec![30..40],
        },
    ];

    // Failure at PC 15 -> attributed to wide_mem
    // Use realistic verifier log format: state line, then error line
    let log_wide_mem = "\
0: R1=ctx() R10=fp0
15: R0=scalar R2=pkt(r=8)
R2 type=scalar expected=pkt_ptr
";
    let result = attribute_verifier_failure(log_wide_mem, &attribution);
    assert_eq!(result, Some("wide_mem".to_string()));

    // Failure at PC 35 -> attributed to rotate
    let log_rotate = "\
0: R1=ctx() R10=fp0
35: R0=scalar R1=ctx()
invalid func bpf_rotate64#12345
";
    let result = attribute_verifier_failure(log_rotate, &attribution);
    assert_eq!(result, Some("rotate".to_string()));

    // Failure at PC 5 (before any pass range) -> None
    let log_before = "\
0: R1=ctx() R10=fp0
5: R0=scalar R2=pkt(r=8)
R2 invalid mem access
";
    let result = attribute_verifier_failure(log_before, &attribution);
    assert_eq!(result, None);

    // Failure at PC 25 (between pass ranges) -> None
    let log_gap = "\
0: R1=ctx() R10=fp0
25: R0=scalar R1=ctx()
R1 type=scalar expected=fp
";
    let result = attribute_verifier_failure(log_gap, &attribution);
    assert_eq!(result, None);
}

/// Test attribute_verifier_failure with overlapping ranges —
/// should pick the last (most recently applied) pass.
#[test]
fn test_attribute_verifier_failure_overlapping_ranges() {
    let attribution = vec![
        pass::TransformAttribution {
            pass_name: "wide_mem".to_string(),
            pc_ranges: vec![10..30],
        },
        pass::TransformAttribution {
            pass_name: "rotate".to_string(),
            pc_ranges: vec![20..40],
        },
    ];

    // PC 25 is in both ranges — should pick "rotate" (last)
    let log = "\
0: R1=ctx() R10=fp0
25: R0=scalar R2=pkt(r=8)
R2 invalid mem access 'scalar'
";
    let result = attribute_verifier_failure(log, &attribution);
    assert_eq!(result, Some("rotate".to_string()));
}

#[test]
fn test_verifier_log_completion_marker_detection() {
    let log = "\
10: R0=scalar
55: safe
processed 49965 insns (limit 1000000) max_states_per_insn 32 total_states 1318 peak_states 232 mark_read 0
";
    assert!(verifier_log_looks_complete(log));
    assert!(!should_treat_as_verifier_rejection(
        "BPF_PROG_REJIT: No space left on device (os error 28)",
        log,
    ));
}

#[test]
fn test_incomplete_verifier_log_still_treated_as_rejection() {
    let log = "\
35: R0=scalar R1=ctx()
invalid func bpf_rotate64#12345
";
    assert!(!verifier_log_looks_complete(log));
    assert!(should_treat_as_verifier_rejection(
        "BPF_PROG_REJIT: Permission denied (os error 13)",
        log,
    ));
}

#[test]
fn test_complete_verifier_log_e2big_is_retryable_post_verify_failure() {
    let log = "\
10: R0=scalar
55: safe
processed 49965 insns (limit 1000000) max_states_per_insn 32 total_states 1318 peak_states 232 mark_read 0
";
    assert!(!should_treat_as_verifier_rejection(
        "BPF_PROG_REJIT: Argument list too long (os error 7)",
        log,
    ));
    assert!(should_retry_post_verify_rejit_failure(
        "BPF_PROG_REJIT: Argument list too long (os error 7)",
        log,
    ));
}

#[test]
fn test_complete_verifier_log_einval_is_retryable_post_verify_failure() {
    let log = "\
10: R0=scalar
55: safe
processed 26 insns (limit 1000000) max_states_per_insn 1 total_states 3 peak_states 3 mark_read 0
";
    assert!(!should_treat_as_verifier_rejection(
        "BPF_PROG_REJIT: Invalid argument (os error 22)",
        log,
    ));
    assert!(should_retry_post_verify_rejit_failure(
        "BPF_PROG_REJIT: Invalid argument (os error 22)",
        log,
    ));
}

#[test]
fn test_attribute_post_verify_rejit_failure_uses_last_changed_pass() {
    let passes = vec![
        PassDetail {
            pass_name: "wide_mem".to_string(),
            changed: false,
            sites_applied: 0,
            sites_skipped: 0,
            skip_reasons: HashMap::new(),
            insns_before: 100,
            insns_after: 100,
            insn_delta: 0,
            diagnostics: vec![],
        },
        PassDetail {
            pass_name: "extract".to_string(),
            changed: true,
            sites_applied: 2,
            sites_skipped: 0,
            skip_reasons: HashMap::new(),
            insns_before: 100,
            insns_after: 104,
            insn_delta: 4,
            diagnostics: vec![],
        },
        PassDetail {
            pass_name: "endian_fusion".to_string(),
            changed: true,
            sites_applied: 3,
            sites_skipped: 0,
            skip_reasons: HashMap::new(),
            insns_before: 104,
            insns_after: 110,
            insn_delta: 6,
            diagnostics: vec![],
        },
    ];

    assert_eq!(
        attribute_post_verify_rejit_failure(&passes),
        Some("endian_fusion".to_string())
    );
}

#[test]
fn test_build_pipeline_default() {
    let ctx = pass::PassContext::test_default();
    let pm = build_pipeline();
    let exit_insn = crate::insn::BpfInsn {
        code: crate::insn::BPF_JMP | crate::insn::BPF_EXIT,
        regs: 0,
        off: 0,
        imm: 0,
    };
    let mut prog = pass::BpfProgram::new(vec![exit_insn]);
    let result = pm.run(&mut prog, &ctx).unwrap();
    assert!(!result.program_changed);
}
