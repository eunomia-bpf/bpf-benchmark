use super::*;
use std::cell::RefCell;
use std::collections::HashMap;
use std::fs::File;
use std::os::unix::io::AsRawFd;
use std::rc::Rc;

use crate::invalidation::{BatchLookupValue, MapInvalidationTracker, MapValueReader};
use crate::pipeline;

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
    fn lookup_values_batch(&self, map_fd: u32, keys: &[Vec<u8>]) -> Result<Vec<BatchLookupValue>> {
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
fn test_kinsn_fd_arrays_reserve_slot_zero() {
    assert!(build_rejit_fd_array(&[]).is_empty());

    let required = [11, 22];
    assert_eq!(build_rejit_fd_array(&required), vec![11, 11, 22]);
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
            total_sites_applied: 3,
            passes_executed: 2,
            passes_changed: 1,
            verifier_rejections: 0,
        },
        passes: vec![
            PassDetail {
                pass_name: "wide_mem".to_string(),
                changed: true,
                verify_result: pipeline::PassVerifyStatus::Accepted,
                verify_error: None,
                action: "kept".to_string(),
                verify: pipeline::PassVerifyResult::accepted(),
                rollback: None,
                sites_applied: 3,
                sites_skipped: 1,
                skip_reasons: HashMap::from([("subprog_unsupported".to_string(), 1)]),
                skipped_sites: vec![],
                insns_before: 100,
                insns_after: 90,
                insn_delta: -10,
                diagnostics: vec![],
            },
            PassDetail {
                pass_name: "rotate".to_string(),
                changed: false,
                verify_result: pipeline::PassVerifyStatus::NotNeeded,
                verify_error: None,
                action: "kept".to_string(),
                verify: pipeline::PassVerifyResult::not_needed(),
                rollback: None,
                sites_applied: 0,
                sites_skipped: 0,
                skip_reasons: HashMap::new(),
                skipped_sites: vec![],
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
    let parsed: serde_json::Value = serde_json::from_str(&json).expect("JSON should parse back");

    assert_eq!(parsed["status"], "ok");
    assert_eq!(parsed["prog_id"], 42);
    assert_eq!(parsed["changed"], true);
    assert_eq!(parsed["passes_applied"][0], "wide_mem");
    assert_eq!(parsed["program"]["prog_id"], 42);
    assert_eq!(parsed["program"]["insn_delta"], -10);
    assert_eq!(parsed["summary"]["applied"], true);
    assert_eq!(parsed["summary"]["total_sites_applied"], 3);
    assert_eq!(parsed["summary"]["verifier_rejections"], 0);
    assert_eq!(parsed["passes"].as_array().unwrap().len(), 2);
    assert_eq!(parsed["passes"][0]["pass"], "wide_mem");
    assert!(parsed["passes"][0].get("pass_name").is_none());
    assert_eq!(parsed["passes"][0]["changed"], true);
    assert_eq!(parsed["passes"][0]["verify_result"], "accepted");
    assert!(parsed["passes"][0]["verify_error"].is_null());
    assert_eq!(parsed["passes"][0]["action"], "kept");
    assert_eq!(parsed["passes"][0]["verify"]["status"], "accepted");
    assert_eq!(
        parsed["passes"][0]["skip_reasons"]["subprog_unsupported"],
        1
    );
    assert_eq!(parsed["passes"][1]["changed"], false);
    assert_eq!(parsed["passes"][1]["verify_result"], "not_needed");
    assert_eq!(parsed["passes"][1]["verify"]["status"], "not_needed");
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
fn test_serve_optimize_response_omits_attempt_debug_payloads() {
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
        passes: vec![PassDetail {
            pass_name: "map_inline".to_string(),
            changed: false,
            verify_result: pipeline::PassVerifyStatus::Rejected,
            verify_error: Some("BPF_PROG_REJIT: Operation not permitted".to_string()),
            action: "rolled_back".to_string(),
            verify: pipeline::PassVerifyResult::rejected("BPF_PROG_REJIT: Operation not permitted"),
            rollback: None,
            sites_applied: 0,
            sites_skipped: 1,
            skip_reasons: HashMap::from([("verifier_rejected".to_string(), 1)]),
            skipped_sites: vec![],
            insns_before: 10,
            insns_after: 10,
            insn_delta: 0,
            diagnostics: vec![],
        }],
        attempts: vec![AttemptRecord {
            attempt: 0,
            disabled_passes: vec![],
            result: "rejit_failed".to_string(),
            failure_pc: Some(42),
            attributed_pass: Some("map_inline".to_string()),
            debug: Some(AttemptDebug {
                pass_traces: vec![],
                pre_rejit_bytecode: None,
                verifier_log: Some(VerifierLogRecord {
                    source: "BPF_PROG_REJIT".to_string(),
                    log_level: 2,
                    log: "very large verifier log".to_string(),
                }),
                final_xlated_bytecode: None,
                final_jited_machine_code: None,
                warnings: vec!["warn".to_string()],
            }),
        }],
        timings_ns: TimingsNs {
            pipeline_run_ns: 10,
            rejit_syscall_ns: 20,
            total_ns: 30,
        },
        inlined_map_entries: vec![],
        error_message: Some("BPF_PROG_REJIT: Operation not permitted".to_string()),
    };

    let json = serde_json::to_string(&ServeOptimizeResponse::from(result))
        .expect("serve response serialization should succeed");
    let parsed: serde_json::Value = serde_json::from_str(&json).expect("JSON should parse back");

    assert_eq!(parsed["status"], "error");
    assert_eq!(parsed["program"]["prog_name"], "demo_prog");
    assert_eq!(
        parsed["passes"][0]["verify_error"],
        "BPF_PROG_REJIT: Operation not permitted"
    );
    assert_eq!(
        parsed["error_message"],
        "BPF_PROG_REJIT: Operation not permitted"
    );
    assert_eq!(parsed["attempts"].as_array().unwrap().len(), 1);
    assert_eq!(parsed["attempts"][0]["result"], "rejit_failed");
    assert_eq!(parsed["attempts"][0]["failure_pc"], 42);
    assert_eq!(parsed["attempts"][0]["attributed_pass"], "map_inline");
    assert!(parsed["attempts"][0].get("debug").is_none());
}

#[test]
fn test_optimize_one_result_records_rejected_pass_verify_status() {
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
            total_sites_applied: 2,
            passes_executed: 3,
            passes_changed: 1,
            verifier_rejections: 1,
        },
        passes: vec![
            PassDetail {
                pass_name: "branch_flip".to_string(),
                changed: false,
                verify_result: pipeline::PassVerifyStatus::Rejected,
                verify_error: Some("BPF_PROG_LOAD: Permission denied (os error 13)".to_string()),
                action: "rolled_back".to_string(),
                verify: pipeline::PassVerifyResult::rejected(
                    "BPF_PROG_LOAD: Permission denied (os error 13)",
                ),
                rollback: Some(pipeline::PassRollbackResult::restored_pre_pass_snapshot(
                    110,
                )),
                sites_applied: 4,
                sites_skipped: 0,
                skip_reasons: HashMap::new(),
                skipped_sites: vec![],
                insns_before: 110,
                insns_after: 110,
                insn_delta: 0,
                diagnostics: vec![],
            },
            PassDetail {
                pass_name: "extract".to_string(),
                changed: true,
                verify_result: pipeline::PassVerifyStatus::Accepted,
                verify_error: None,
                action: "kept".to_string(),
                verify: pipeline::PassVerifyResult::accepted(),
                rollback: None,
                sites_applied: 2,
                sites_skipped: 0,
                skip_reasons: HashMap::new(),
                skipped_sites: vec![],
                insns_before: 110,
                insns_after: 100,
                insn_delta: -10,
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
            pipeline_run_ns: 200_000,
            rejit_syscall_ns: 100_000,
            total_ns: 400_000,
        },
        inlined_map_entries: vec![],
        error_message: None,
    };

    let json = serde_json::to_string(&result).expect("serialization should succeed");
    let parsed: serde_json::Value = serde_json::from_str(&json).expect("JSON should parse back");

    assert_eq!(parsed["summary"]["verifier_rejections"], 1);
    assert_eq!(parsed["passes_applied"][0], "extract");
    assert_eq!(parsed["passes"].as_array().unwrap().len(), 2);
    assert_eq!(parsed["passes"][0]["verify_result"], "rejected");
    assert_eq!(parsed["passes"][0]["verify"]["status"], "rejected");
    assert_eq!(
        parsed["passes"][0]["verify_error"],
        "BPF_PROG_LOAD: Permission denied (os error 13)"
    );
    assert_eq!(parsed["passes"][0]["action"], "rolled_back");
    assert_eq!(
        parsed["passes"][0]["rollback"]["action"],
        "restored_pre_pass_snapshot"
    );
    assert_eq!(parsed["passes"][0]["rollback"]["restored_insn_count"], 110);
    assert_eq!(parsed["passes"][1]["verify"]["status"], "accepted");
    assert_eq!(parsed["attempts"].as_array().unwrap().len(), 1);
    assert_eq!(parsed["attempts"][0]["result"], "applied");
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

    let verified = pipeline::VerifiedPassResult {
        result: pr,
        verify: pipeline::PassVerifyResult::accepted(),
        rollback: None,
    };
    let detail = PassDetail::from(&verified);

    assert_eq!(detail.pass_name, "wide_mem");
    assert_eq!(detail.changed, true);
    assert_eq!(detail.verify_result, pipeline::PassVerifyStatus::Accepted);
    assert_eq!(detail.verify_error, None);
    assert_eq!(detail.action, "kept");
    assert_eq!(detail.verify.status, pipeline::PassVerifyStatus::Accepted);
    assert_eq!(detail.sites_applied, 5);
    assert_eq!(detail.sites_skipped, 3);
    assert_eq!(detail.skip_reasons["subprog_unsupported"], 2);
    assert_eq!(detail.skip_reasons["kfunc_unavailable"], 1);
    assert_eq!(detail.skipped_sites.len(), 3);
    assert_eq!(detail.skipped_sites[0].pc, 10);
    assert_eq!(detail.skipped_sites[1].pc, 20);
    assert_eq!(detail.skipped_sites[2].pc, 30);
    assert_eq!(detail.insns_before, 100);
    assert_eq!(detail.insns_after, 95);
    assert_eq!(detail.insn_delta, -5);
    assert_eq!(detail.rollback, None);
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
fn test_collect_map_inline_records_ignores_rejected_passes() {
    let rejected = pipeline::VerifiedPassResult {
        result: pass::PassResult {
            pass_name: "map_inline".to_string(),
            changed: false,
            map_inline_records: vec![pass::MapInlineRecord {
                map_id: 17,
                key: 0u32.to_le_bytes().to_vec(),
                expected_value: 11u32.to_le_bytes().to_vec(),
            }],
            ..Default::default()
        },
        verify: pipeline::PassVerifyResult::rejected("synthetic verifier rejection"),
        rollback: Some(pipeline::PassRollbackResult::restored_pre_pass_snapshot(
            100,
        )),
    };
    let accepted = pipeline::VerifiedPassResult {
        result: pass::PassResult {
            pass_name: "map_inline".to_string(),
            changed: true,
            map_inline_records: vec![pass::MapInlineRecord {
                map_id: 18,
                key: 1u32.to_le_bytes().to_vec(),
                expected_value: 22u32.to_le_bytes().to_vec(),
            }],
            ..Default::default()
        },
        verify: pipeline::PassVerifyResult::accepted(),
        rollback: None,
    };

    let records = collect_map_inline_records(&[rejected, accepted]);
    assert_eq!(records.len(), 1);
    assert_eq!(records[0].map_id, 18);
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

// ── Per-pass verification unit tests ─────────────────────────

#[test]
fn test_verifier_rejection_count_counts_rejected_passes() {
    let passes = vec![
        PassDetail {
            pass_name: "wide_mem".to_string(),
            changed: false,
            verify_result: pipeline::PassVerifyStatus::Rejected,
            verify_error: Some("synthetic verifier rejection".to_string()),
            action: "rolled_back".to_string(),
            verify: pipeline::PassVerifyResult::rejected("synthetic verifier rejection"),
            rollback: Some(pipeline::PassRollbackResult::restored_pre_pass_snapshot(
                100,
            )),
            sites_applied: 0,
            sites_skipped: 0,
            skip_reasons: HashMap::new(),
            skipped_sites: vec![],
            insns_before: 100,
            insns_after: 100,
            insn_delta: 0,
            diagnostics: vec![],
        },
        PassDetail {
            pass_name: "extract".to_string(),
            changed: true,
            verify_result: pipeline::PassVerifyStatus::Accepted,
            verify_error: None,
            action: "kept".to_string(),
            verify: pipeline::PassVerifyResult::accepted(),
            rollback: None,
            sites_applied: 2,
            sites_skipped: 0,
            skip_reasons: HashMap::new(),
            skipped_sites: vec![],
            insns_before: 100,
            insns_after: 104,
            insn_delta: 4,
            diagnostics: vec![],
        },
    ];

    assert_eq!(verifier_rejection_count(&passes), 1);
}

#[test]
fn test_build_pipeline_default() {
    let ctx = pass::PassContext::test_default();
    let pm = bpfopt::passes::build_full_pipeline();
    let exit_insn =
        bpfopt::insn::BpfInsn::new(bpfopt::insn::BPF_JMP | bpfopt::insn::BPF_EXIT, 0, 0, 0);
    let mut prog = pass::BpfProgram::new(vec![exit_insn]);
    let result = pm.run(&mut prog, &ctx).unwrap();
    assert!(!result.program_changed);
}
