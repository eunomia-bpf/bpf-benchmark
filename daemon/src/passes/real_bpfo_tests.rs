use crate::pass::{BpfProgram, PipelineResult};
use crate::test_utils::{
    assert_valid_bpf, hot_branch_profiling, load_fixture_program, load_program_from_path,
    pass_result, permissive_pass_ctx, repo_path, run_named_pipeline,
    run_named_pipeline_with_profiling, LoadedFixtureProgram,
};

#[derive(Clone, Copy)]
struct CapturedRealCase {
    object_path: &'static str,
    program_name: &'static str,
    capture_path: &'static str,
}

fn run_real_case(
    pass_names: &[&str],
    fixture: &str,
    program_name: &str,
    with_maps: bool,
    with_profiling: bool,
) -> (LoadedFixtureProgram, BpfProgram, PipelineResult) {
    let loaded = load_fixture_program(fixture, program_name).unwrap();
    let mut program = if with_maps {
        loaded.into_program_with_synthetic_maps()
    } else {
        loaded.into_program()
    };
    let ctx = permissive_pass_ctx(loaded.prog_type);
    let result = if with_profiling {
        let profiling = hot_branch_profiling(&program.insns);
        run_named_pipeline_with_profiling(&mut program, &ctx, pass_names, Some(&profiling)).unwrap()
    } else {
        run_named_pipeline(&mut program, &ctx, pass_names).unwrap()
    };
    assert_valid_bpf(&program);
    (loaded, program, result)
}

fn run_captured_real_case(
    pass_names: &[&str],
    case: CapturedRealCase,
) -> (LoadedFixtureProgram, BpfProgram, PipelineResult) {
    try_run_captured_real_case(pass_names, case).unwrap()
}

fn try_run_captured_real_case(
    pass_names: &[&str],
    case: CapturedRealCase,
) -> anyhow::Result<(LoadedFixtureProgram, BpfProgram, PipelineResult)> {
    let object_path = repo_path(case.object_path);
    let capture_path = repo_path(case.capture_path);
    let loaded = load_program_from_path(&object_path, case.program_name)?;
    let mut program = loaded.into_program_with_captured_maps(&capture_path)?;
    let ctx = permissive_pass_ctx(loaded.prog_type);
    let result = run_named_pipeline(&mut program, &ctx, pass_names)?;
    assert_valid_bpf(&program);
    Ok((loaded, program, result))
}

fn assert_pass_changed(result: &PipelineResult, pass_name: &str, fixture: &LoadedFixtureProgram) {
    let pass = pass_result(result, pass_name).unwrap();
    assert!(
        pass.changed,
        "{} on {}:{} did not change; skipped={:?}",
        pass_name,
        fixture.object_path.display(),
        fixture.section_name,
        pass.sites_skipped
    );
    assert!(
        pass.insns_after != pass.insns_before || pass.sites_applied > 0,
        "{} on {}:{} reported changed without any visible delta",
        pass_name,
        fixture.object_path.display(),
        fixture.section_name
    );
}

fn all_captured_real_cases() -> &'static [CapturedRealCase] {
    &[
        CapturedRealCase {
            object_path: "corpus/build/tetragon/bpf_execve_bprm_commit_creds.bpf.o",
            program_name: "tg_kp_bprm_committing_creds",
            capture_path:
                "corpus/fixtures/tetragon/bpf_execve_bprm_commit_creds.bpf.o/tg_kp_bprm_committing_creds.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tetragon/bpf_execve_event.bpf.o",
            program_name: "event_execve",
            capture_path:
                "corpus/fixtures/tetragon/bpf_execve_event.bpf.o/event_execve.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tetragon/bpf_execve_event.bpf.o",
            program_name: "execve_rate",
            capture_path:
                "corpus/fixtures/tetragon/bpf_execve_event.bpf.o/execve_rate.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tetragon/bpf_execve_event.bpf.o",
            program_name: "execve_send",
            capture_path:
                "corpus/fixtures/tetragon/bpf_execve_event.bpf.o/execve_send.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tetragon/bpf_execve_map_update.bpf.o",
            program_name: "execve_map_update",
            capture_path:
                "corpus/fixtures/tetragon/bpf_execve_map_update.bpf.o/execve_map_update.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tetragon/bpf_exit.bpf.o",
            program_name: "event_exit_acct_process",
            capture_path:
                "corpus/fixtures/tetragon/bpf_exit.bpf.o/event_exit_acct_process.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tetragon/bpf_fork.bpf.o",
            program_name: "event_wake_up_new_task",
            capture_path:
                "corpus/fixtures/tetragon/bpf_fork.bpf.o/event_wake_up_new_task.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tracee/tracee.bpf.o",
            program_name: "lkm_seeker_modtree_loop",
            capture_path:
                "corpus/fixtures/tracee/tracee.bpf.o/lkm_seeker_modtree_loop.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tracee/tracee.bpf.o",
            program_name: "sys_dup_exit_tail",
            capture_path:
                "corpus/fixtures/tracee/tracee.bpf.o/sys_dup_exit_tail.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tracee/tracee.bpf.o",
            program_name: "sys_enter_init",
            capture_path:
                "corpus/fixtures/tracee/tracee.bpf.o/sys_enter_init.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tracee/tracee.bpf.o",
            program_name: "sys_enter_submit",
            capture_path:
                "corpus/fixtures/tracee/tracee.bpf.o/sys_enter_submit.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tracee/tracee.bpf.o",
            program_name: "sys_exit_init",
            capture_path:
                "corpus/fixtures/tracee/tracee.bpf.o/sys_exit_init.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tracee/tracee.bpf.o",
            program_name: "sys_exit_submit",
            capture_path:
                "corpus/fixtures/tracee/tracee.bpf.o/sys_exit_submit.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tracee/tracee.bpf.o",
            program_name: "syscall__execve_enter",
            capture_path:
                "corpus/fixtures/tracee/tracee.bpf.o/syscall__execve_enter.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tracee/tracee.bpf.o",
            program_name: "syscall__execve_exit",
            capture_path:
                "corpus/fixtures/tracee/tracee.bpf.o/syscall__execve_exit.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tracee/tracee.bpf.o",
            program_name: "syscall__execveat_enter",
            capture_path:
                "corpus/fixtures/tracee/tracee.bpf.o/syscall__execveat_enter.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tracee/tracee.bpf.o",
            program_name: "syscall__execveat_exit",
            capture_path:
                "corpus/fixtures/tracee/tracee.bpf.o/syscall__execveat_exit.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tracee/tracee.bpf.o",
            program_name: "tracepoint__raw_syscalls__sys_enter",
            capture_path:
                "corpus/fixtures/tracee/tracee.bpf.o/tracepoint__raw_syscalls__sys_enter.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tracee/tracee.bpf.o",
            program_name: "tracepoint__raw_syscalls__sys_exit",
            capture_path:
                "corpus/fixtures/tracee/tracee.bpf.o/tracepoint__raw_syscalls__sys_exit.json",
        },
        CapturedRealCase {
            object_path: "corpus/build/tracee/tracee.bpf.o",
            program_name: "tracepoint__sched__sched_process_fork",
            capture_path:
                "corpus/fixtures/tracee/tracee.bpf.o/tracepoint__sched__sched_process_fork.json",
        },
    ]
}

macro_rules! real_single_pass_test {
    ($name:ident, $pass:literal, $fixture:literal, $program:literal, $with_maps:expr, $with_profile:expr, $expect_change:expr) => {
        #[test]
        fn $name() {
            let (fixture, _program, result) =
                run_real_case(&[$pass], $fixture, $program, $with_maps, $with_profile);
            if $expect_change {
                assert_pass_changed(&result, $pass, &fixture);
            } else {
                let _ = pass_result(&result, $pass).unwrap();
            }
        }
    };
}

macro_rules! real_pipeline_test {
    ($name:ident, [$($pass:literal),+ $(,)?], assert_pass=$assert_pass:literal, fixture=$fixture:literal, program=$program:literal, maps=$with_maps:expr, profile=$with_profile:expr, change=$expect_change:expr) => {
        #[test]
        fn $name() {
            let (fixture, _program, result) = run_real_case(
                &[$($pass),+],
                $fixture,
                $program,
                $with_maps,
                $with_profile,
            );
            if $expect_change {
                assert_pass_changed(&result, $assert_pass, &fixture);
            } else {
                let _ = pass_result(&result, $assert_pass).unwrap();
            }
        }
    };
}

real_single_pass_test!(
    test_map_inline_real_katran_xdp,
    "map_inline",
    "katran/xdp_pktcntr.bpf.o",
    "xdp",
    true,
    false,
    true
);

#[test]
fn test_map_inline_real_katran_balancer_ingress() {
    let object_path = repo_path("corpus/build/katran/balancer.bpf.o");
    let loaded = load_program_from_path(&object_path, "balancer_ingress").unwrap();
    let mut program = loaded.into_program_with_synthetic_maps();
    let ctx = permissive_pass_ctx(loaded.prog_type);
    let result = run_named_pipeline(&mut program, &ctx, &["map_inline"]).unwrap();
    assert_valid_bpf(&program);
    let pass = pass_result(&result, "map_inline").unwrap();
    assert!(
        pass.changed && pass.sites_applied > 0,
        "expected map_inline to apply on {}:{}; applied={} skipped={:?} diagnostics={:?}",
        loaded.object_path.display(),
        loaded.section_name,
        pass.sites_applied,
        pass.sites_skipped,
        pass.diagnostics
    );
    assert!(
        !pass.map_inline_records.is_empty(),
        "expected balancer_ingress to record inlined map entries on {}:{}",
        loaded.object_path.display(),
        loaded.section_name
    );
}

#[test]
fn test_map_inline_real_tracee_cgroup_skb_ingress() {
    let (fixture, _program, result) = run_real_case(
        &["map_inline"],
        "tracee/tracee.bpf.o",
        "cgroup_skb_ingress",
        true,
        false,
    );
    assert_pass_changed(&result, "map_inline", &fixture);
    let pass = pass_result(&result, "map_inline").unwrap();
    assert!(
        !pass.sites_skipped.iter().any(|skip| skip
            .reason
            .contains("speculative map inline requires an immediate null check")),
        "unexpected null-check skips on {}:{}: {:?}",
        fixture.object_path.display(),
        fixture.section_name,
        pass.sites_skipped
    );
}

#[test]
fn test_map_inline_real_tracee_cgroup_skb_egress() {
    let (fixture, _program, result) = run_real_case(
        &["map_inline"],
        "tracee/tracee.bpf.o",
        "cgroup_skb_egress",
        true,
        false,
    );
    assert_pass_changed(&result, "map_inline", &fixture);
    let pass = pass_result(&result, "map_inline").unwrap();
    assert!(
        !pass.sites_skipped.iter().any(|skip| skip
            .reason
            .contains("speculative map inline requires an immediate null check")),
        "unexpected null-check skips on {}:{}: {:?}",
        fixture.object_path.display(),
        fixture.section_name,
        pass.sites_skipped
    );
}

#[test]
fn test_map_inline_real_tetragon_event_exit_acct_partially_applies_but_still_rejects_dynamic_sites()
{
    let object_path = repo_path("corpus/build/tetragon/bpf_exit.bpf.o");
    let capture_path =
        repo_path("corpus/fixtures/tetragon/bpf_exit.bpf.o/event_exit_acct_process.json");
    let loaded = load_program_from_path(&object_path, "event_exit_acct_process").unwrap();
    let mut program = loaded
        .into_program_with_captured_maps(&capture_path)
        .unwrap();
    let ctx = permissive_pass_ctx(loaded.prog_type);
    let result = run_named_pipeline(&mut program, &ctx, &["map_inline"]).unwrap();
    assert_valid_bpf(&program);
    let pass = pass_result(&result, "map_inline").unwrap();
    assert!(
        pass.changed && pass.sites_applied >= 1,
        "map_inline should partially apply on {}:{}; skipped={:?}",
        loaded.object_path.display(),
        loaded.section_name,
        pass.sites_skipped
    );
    assert!(
        pass.sites_skipped.iter().any(|skip| {
            skip.reason == "lookup key is not a constant stack or pseudo-map-value materialization"
        }),
        "expected dynamic-key skip on {}:{}; skipped={:?}",
        loaded.object_path.display(),
        loaded.section_name,
        pass.sites_skipped
    );
}

#[test]
fn test_map_inline_real_tetragon_execve_rate() {
    let object_path = repo_path("corpus/build/tetragon/bpf_execve_event.bpf.o");
    let capture_path =
        repo_path("corpus/fixtures/tetragon/bpf_execve_event.bpf.o/execve_rate.json");
    let loaded = load_program_from_path(&object_path, "execve_rate").unwrap();
    let mut program = loaded
        .into_program_with_captured_maps(&capture_path)
        .unwrap();
    let ctx = permissive_pass_ctx(loaded.prog_type);
    let result = run_named_pipeline(&mut program, &ctx, &["map_inline"]).unwrap();
    assert_valid_bpf(&program);
    assert_pass_changed(&result, "map_inline", &loaded);
    let pass = pass_result(&result, "map_inline").unwrap();
    assert!(
        pass.sites_applied > 0,
        "expected map_inline to apply on {}:{}; skipped={:?}",
        loaded.object_path.display(),
        loaded.section_name,
        pass.sites_skipped
    );
}

#[test]
fn test_map_inline_real_tetragon_event_execve() {
    let case = CapturedRealCase {
        object_path: "corpus/build/tetragon/bpf_execve_event.bpf.o",
        program_name: "event_execve",
        capture_path: "corpus/fixtures/tetragon/bpf_execve_event.bpf.o/event_execve.json",
    };
    let (loaded, _program, result) = run_captured_real_case(&["map_inline"], case);
    assert_pass_changed(&result, "map_inline", &loaded);
    let pass = pass_result(&result, "map_inline").unwrap();
    assert!(
        pass.sites_applied > 0,
        "expected map_inline to apply on {}:{}; skipped={:?}",
        loaded.object_path.display(),
        loaded.section_name,
        pass.sites_skipped
    );
}

#[test]
fn test_map_inline_real_tetragon_event_wake_up_new_task() {
    let case = CapturedRealCase {
        object_path: "corpus/build/tetragon/bpf_fork.bpf.o",
        program_name: "event_wake_up_new_task",
        capture_path: "corpus/fixtures/tetragon/bpf_fork.bpf.o/event_wake_up_new_task.json",
    };
    let (loaded, _program, result) = run_captured_real_case(&["map_inline"], case);
    assert_pass_changed(&result, "map_inline", &loaded);
    let pass = pass_result(&result, "map_inline").unwrap();
    assert!(
        pass.sites_applied > 0,
        "expected map_inline to apply on {}:{}; skipped={:?}",
        loaded.object_path.display(),
        loaded.section_name,
        pass.sites_skipped
    );
}

#[test]
fn test_map_inline_real_all_captured_fixtures_smoke() {
    let mut changed_cases = 0usize;
    let mut attempted_cases = 0usize;

    for case in all_captured_real_cases() {
        let (loaded, _program, result) = match try_run_captured_real_case(&["map_inline"], *case) {
            Ok(result) => result,
            Err(err) => {
                eprintln!(
                    "captured fixture {}:{} skipped during smoke scan: {:#}",
                    case.object_path, case.program_name, err
                );
                continue;
            }
        };
        attempted_cases += 1;
        let pass = pass_result(&result, "map_inline").unwrap();
        eprintln!(
            "captured fixture {}:{} changed={} applied={} skipped={}",
            loaded.object_path.display(),
            loaded.section_name,
            pass.changed,
            pass.sites_applied,
            pass.sites_skipped.len()
        );
        if pass.changed {
            changed_cases += 1;
        }
    }

    assert!(
        changed_cases >= 2,
        "expected at least two captured real fixtures to hit map_inline, got {}",
        changed_cases
    );
    assert!(
        attempted_cases >= 10,
        "expected to scan at least ten captured real fixtures, got {}",
        attempted_cases
    );
}

real_single_pass_test!(
    test_map_inline_real_bindsnoop,
    "map_inline",
    "bcc/libbpf-tools/bindsnoop.bpf.o",
    "kprobe/inet_bind",
    true,
    false,
    false
);
real_single_pass_test!(
    test_map_inline_real_cilium_xdp_entry,
    "map_inline",
    "cilium/bpf_xdp.bpf.o",
    "xdp/entry",
    true,
    false,
    false
);

real_pipeline_test!(
    test_const_prop_real_katran_xdp,
    ["map_inline", "const_prop"],
    assert_pass = "const_prop",
    fixture = "katran/xdp_pktcntr.bpf.o",
    program = "xdp",
    maps = true,
    profile = false,
    change = true
);
real_pipeline_test!(
    test_const_prop_real_bindsnoop,
    ["map_inline", "const_prop"],
    assert_pass = "const_prop",
    fixture = "bcc/libbpf-tools/bindsnoop.bpf.o",
    program = "kprobe/inet_bind",
    maps = true,
    profile = false,
    change = false
);
real_pipeline_test!(
    test_const_prop_real_cilium_xdp_entry,
    ["map_inline", "const_prop"],
    assert_pass = "const_prop",
    fixture = "cilium/bpf_xdp.bpf.o",
    program = "xdp/entry",
    maps = true,
    profile = false,
    change = false
);

real_pipeline_test!(
    test_dce_real_katran_xdp,
    ["map_inline", "const_prop", "dce"],
    assert_pass = "dce",
    fixture = "katran/xdp_pktcntr.bpf.o",
    program = "xdp",
    maps = true,
    profile = false,
    change = true
);
real_pipeline_test!(
    test_dce_real_bindsnoop,
    ["map_inline", "const_prop", "dce"],
    assert_pass = "dce",
    fixture = "bcc/libbpf-tools/bindsnoop.bpf.o",
    program = "kprobe/inet_bind",
    maps = true,
    profile = false,
    change = false
);
real_pipeline_test!(
    test_dce_real_cilium_xdp_entry,
    ["map_inline", "const_prop", "dce"],
    assert_pass = "dce",
    fixture = "cilium/bpf_xdp.bpf.o",
    program = "xdp/entry",
    maps = true,
    profile = false,
    change = false
);

real_single_pass_test!(
    test_skb_load_bytes_real_cilium_lxc_tail,
    "skb_load_bytes_spec",
    "cilium/bpf_lxc.bpf.o",
    "tc/tail",
    false,
    false,
    true
);
real_single_pass_test!(
    test_skb_load_bytes_real_cilium_overlay_tail,
    "skb_load_bytes_spec",
    "cilium/bpf_overlay.bpf.o",
    "tc/tail",
    false,
    false,
    true
);
real_single_pass_test!(
    test_skb_load_bytes_real_decap_sanity,
    "skb_load_bytes_spec",
    "linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o",
    "tc",
    false,
    false,
    true
);

real_single_pass_test!(
    test_bounds_check_merge_real_cilium_xdp_entry,
    "bounds_check_merge",
    "cilium/bpf_xdp.bpf.o",
    "xdp/entry",
    false,
    false,
    false
);
real_single_pass_test!(
    test_bounds_check_merge_real_xdp_flowtable,
    "bounds_check_merge",
    "xdp-tools/xdp_flowtable.bpf.o",
    "xdp",
    false,
    false,
    false
);
real_single_pass_test!(
    test_bounds_check_merge_real_calico_from_hep,
    "bounds_check_merge",
    "calico/from_hep_debug.bpf.o",
    "tc",
    false,
    false,
    false
);

real_single_pass_test!(
    test_wide_mem_real_cilium_xdp_entry,
    "wide_mem",
    "cilium/bpf_xdp.bpf.o",
    "xdp/entry",
    false,
    false,
    false
);
real_single_pass_test!(
    test_wide_mem_real_cilium_lxc_entry,
    "wide_mem",
    "cilium/bpf_lxc.bpf.o",
    "tc/entry",
    false,
    false,
    false
);
real_single_pass_test!(
    test_wide_mem_real_calico_to_hep,
    "wide_mem",
    "calico/to_hep_debug.bpf.o",
    "tc",
    false,
    false,
    false
);

real_single_pass_test!(
    test_bulk_memory_real_calico_to_hep,
    "bulk_memory",
    "calico/to_hep_debug.bpf.o",
    "tc",
    false,
    false,
    false
);
real_single_pass_test!(
    test_bulk_memory_real_calico_from_hep,
    "bulk_memory",
    "calico/from_hep_debug.bpf.o",
    "tc",
    false,
    false,
    false
);
real_single_pass_test!(
    test_bulk_memory_real_xdp_flowtable,
    "bulk_memory",
    "xdp-tools/xdp_flowtable.bpf.o",
    "xdp",
    false,
    false,
    false
);

real_single_pass_test!(
    test_rotate_real_cilium_xdp_entry,
    "rotate",
    "cilium/bpf_xdp.bpf.o",
    "xdp/entry",
    false,
    false,
    false
);
real_single_pass_test!(
    test_rotate_real_cilium_lxc_entry,
    "rotate",
    "cilium/bpf_lxc.bpf.o",
    "tc/entry",
    false,
    false,
    false
);

real_single_pass_test!(
    test_cond_select_real_cilium_xdp_tail,
    "cond_select",
    "cilium/bpf_xdp.bpf.o",
    "xdp/tail",
    false,
    false,
    false
);
real_single_pass_test!(
    test_cond_select_real_cilium_lxc_tail,
    "cond_select",
    "cilium/bpf_lxc.bpf.o",
    "tc/tail",
    false,
    false,
    false
);
real_single_pass_test!(
    test_cond_select_real_calico_to_hep,
    "cond_select",
    "calico/to_hep_debug.bpf.o",
    "tc",
    false,
    false,
    false
);

real_single_pass_test!(
    test_extract_real_cilium_xdp_entry,
    "extract",
    "cilium/bpf_xdp.bpf.o",
    "xdp/entry",
    false,
    false,
    false
);
real_single_pass_test!(
    test_extract_real_calico_to_hep,
    "extract",
    "calico/to_hep_debug.bpf.o",
    "tc",
    false,
    false,
    false
);
real_single_pass_test!(
    test_extract_real_tracee_sys_enter,
    "extract",
    "tracee/tracee.bpf.o",
    "tracepoint__raw_syscalls__sys_enter",
    false,
    false,
    false
);

real_single_pass_test!(
    test_endian_real_selftest,
    "endian_fusion",
    "linux-selftests/tools/testing/selftests/bpf/progs/test_endian.bpf.o",
    "raw_tp/sys_enter",
    false,
    false,
    true
);
real_single_pass_test!(
    test_endian_real_calico_to_hep,
    "endian_fusion",
    "calico/to_hep_debug.bpf.o",
    "tc",
    false,
    false,
    false
);
real_single_pass_test!(
    test_endian_real_cilium_lxc_entry,
    "endian_fusion",
    "cilium/bpf_lxc.bpf.o",
    "tc/entry",
    false,
    false,
    false
);

real_single_pass_test!(
    test_branch_flip_real_cilium_xdp_entry,
    "branch_flip",
    "cilium/bpf_xdp.bpf.o",
    "xdp/entry",
    false,
    true,
    true
);
real_single_pass_test!(
    test_branch_flip_real_cilium_lxc_entry,
    "branch_flip",
    "cilium/bpf_lxc.bpf.o",
    "tc/entry",
    false,
    true,
    true
);
real_single_pass_test!(
    test_branch_flip_real_tracee_sys_enter,
    "branch_flip",
    "tracee/tracee.bpf.o",
    "tracepoint__raw_syscalls__sys_enter",
    false,
    true,
    false
);
