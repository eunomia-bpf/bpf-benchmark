# Corpus Runnability Report

- Generated: 2026-03-11T13:51:52.665630+00:00
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Corpus root: `/home/yunwei37/workspace/bpf-benchmark/corpus/build`
- Packet repeat: 200
- Tracing repeat: 10
- Recompile mode: `v5`
- BPF objects scanned: 34
- Programs discovered: 189
- Loadable programs: 62
- Programs with directive sites: 17
- Packet-test-run candidates: 2
- Packet baseline-runnable programs: 0
- Packet paired baseline/recompile programs: 0
- Tracing attach+trigger candidates: 65
- Tracing programs with positive run_cnt delta: 0
- Truly runnable programs: 0
- Truly runnable objects: 0
- Packet speedup geomean: n/a

## Strategy Summary

| Strategy | Programs |
| --- | --- |
| cgroup_custom_harness | 4 |
| iterator_custom_harness | 1 |
| kernel_registration_required | 60 |
| load_only_other | 1 |
| lsm_custom_harness | 15 |
| packet_test_run | 2 |
| synthetic_syscall_only | 11 |
| tracing_attach_trigger | 65 |
| user_tracing_custom_target | 30 |

## Directive Totals

| Metric | Value |
| --- | --- |
| CMOV sites | 53 |
| WIDE sites | 0 |
| ROTATE sites | 0 |
| LEA sites | 1 |
| Tracing avg ns/run min | n/a |
| Tracing avg ns/run max | n/a |

## By Program Type

| Prog Type | Objects | Programs | Loadable | Sites | Packet Runnable | Packet Paired | Tracing +Runs | Primary Strategy |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| struct_ops | 4 | 60 | 35 | 13 | 0 | 0 | 0 | kernel_registration_required |
| kprobe | 11 | 53 | 7 | 0 | 0 | 0 | 0 | user_tracing_custom_target |
| tracepoint | 3 | 18 | 0 | 0 | 0 | 0 | 0 | tracing_attach_trigger |
| lsm | 4 | 15 | 6 | 4 | 0 | 0 | 0 | lsm_custom_harness |
| raw_tracepoint | 6 | 15 | 6 | 0 | 0 | 0 | 0 | tracing_attach_trigger |
| syscall | 3 | 11 | 4 | 0 | 0 | 0 | 0 | synthetic_syscall_only |
| tracing | 4 | 10 | 2 | 0 | 0 | 0 | 0 | tracing_attach_trigger |
| cgroup_skb | 1 | 2 | 0 | 0 | 0 | 0 | 0 | packet_test_run |
| cgroup_sock_addr | 1 | 2 | 0 | 0 | 0 | 0 | 0 | cgroup_custom_harness |
| cgroup_sock | 1 | 1 | 1 | 0 | 0 | 0 | 0 | cgroup_custom_harness |
| cgroup_sysctl | 1 | 1 | 1 | 0 | 0 | 0 | 0 | cgroup_custom_harness |
| unspec | 1 | 1 | 0 | 0 | 0 | 0 | 0 | load_only_other |

## By Source

| Source | Objects | Programs | Loadable | Sites | Packet Runnable | Packet Paired | Tracing +Runs | True Runnable |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| scx | 4 | 85 | 39 | 13 | 0 | 0 | 0 | 0 |
| systemd | 6 | 14 | 9 | 4 | 0 | 0 | 0 | 0 |
| tetragon | 23 | 90 | 14 | 0 | 0 | 0 | 0 | 0 |

## Object Inventory

| Object | Source | Programs | Loadable | Site Programs | Sites | Packet Candidates | Packet Runnable | Packet Paired | Tracing +Runs | True Runnable | Top Strategies |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/scx/scx_rusty_main.bpf.o | scx | 13 | 13 | 7 | 28 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/scx/scx_flash_main.bpf.o | scx | 14 | 14 | 4 | 20 | 0 | 0 | 0 | 0 | no | kernel_registration_required, synthetic_syscall_only |
| corpus/build/systemd/userns-restrict.bpf.o | systemd | 7 | 7 | 4 | 4 | 0 | 0 | 0 | 0 | no | lsm_custom_harness, tracing_attach_trigger |
| corpus/build/scx/scx_bpfland_main.bpf.o | scx | 12 | 12 | 2 | 2 | 0 | 0 | 0 | 0 | no | kernel_registration_required, synthetic_syscall_only |
| corpus/build/scx/scx_lavd_main.bpf.o | scx | 46 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | kernel_registration_required, tracing_attach_trigger, synthetic_syscall_only |
| corpus/build/systemd/bind-iface.bpf.o | systemd | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | cgroup_custom_harness |
| corpus/build/systemd/restrict-fs.bpf.o | systemd | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/systemd/restrict-ifaces.bpf.o | systemd | 2 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/systemd/socket-bind.bpf.o | systemd | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | cgroup_custom_harness |
| corpus/build/systemd/sysctl-monitor.bpf.o | systemd | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | cgroup_custom_harness |
| corpus/build/tetragon/bpf_cgroup.bpf.o | tetragon | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_cgroup_mkdir.bpf.o | tetragon | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_cgroup_release.bpf.o | tetragon | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_cgroup_rmdir.bpf.o | tetragon | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_cgtracker.bpf.o | tetragon | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_enforcer.bpf.o | tetragon | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_execve_bprm_commit_creds.bpf.o | tetragon | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_execve_event.bpf.o | tetragon | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_execve_map_update.bpf.o | tetragon | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/tetragon/bpf_exit.bpf.o | tetragon | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_fmodret_enforcer.bpf.o | tetragon | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_fork.bpf.o | tetragon | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_generic_kprobe.bpf.o | tetragon | 12 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_generic_lsm_core.bpf.o | tetragon | 7 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/tetragon/bpf_generic_lsm_output.bpf.o | tetragon | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/tetragon/bpf_generic_rawtp.bpf.o | tetragon | 9 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_generic_retkprobe.bpf.o | tetragon | 5 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_generic_retuprobe.bpf.o | tetragon | 5 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/tetragon/bpf_generic_tracepoint.bpf.o | tetragon | 8 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_generic_uprobe.bpf.o | tetragon | 13 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/tetragon/bpf_generic_usdt.bpf.o | tetragon | 12 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/tetragon/bpf_multi_enforcer.bpf.o | tetragon | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_prog_iter.bpf.o | tetragon | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |

## Directive-Bearing But Not Yet Runnable

| Program | Type | Section | Strategy | Sites | Reason |
| --- | --- | --- | --- | --- | --- |
| corpus/build/scx/scx_flash_main.bpf.o:flash_enqueue | struct_ops | struct_ops/flash_enqueue | kernel_registration_required | 15 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/scx/scx_rusty_main.bpf.o:rusty_enqueue | struct_ops | struct_ops/rusty_enqueue | kernel_registration_required | 12 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/scx/scx_rusty_main.bpf.o:rusty_stopping | struct_ops | struct_ops/rusty_stopping | kernel_registration_required | 10 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/scx/scx_flash_main.bpf.o:flash_stopping | struct_ops | struct_ops/flash_stopping | kernel_registration_required | 3 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/scx/scx_rusty_main.bpf.o:rusty_set_cpumask | struct_ops | struct_ops/rusty_set_cpumask | kernel_registration_required | 2 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/scx/scx_bpfland_main.bpf.o:bpfland_enqueue | struct_ops | struct_ops/bpfland_enqueue | kernel_registration_required | 1 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/scx/scx_bpfland_main.bpf.o:bpfland_running | struct_ops | struct_ops/bpfland_running | kernel_registration_required | 1 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/scx/scx_flash_main.bpf.o:flash_quiescent | struct_ops | struct_ops/flash_quiescent | kernel_registration_required | 1 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/scx/scx_flash_main.bpf.o:flash_select_cpu | struct_ops | struct_ops/flash_select_cpu | kernel_registration_required | 1 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/scx/scx_rusty_main.bpf.o:rusty_init | struct_ops | struct_ops.s/rusty_init | kernel_registration_required | 1 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/scx/scx_rusty_main.bpf.o:rusty_init_task | struct_ops | struct_ops.s/rusty_init_task | kernel_registration_required | 1 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/scx/scx_rusty_main.bpf.o:rusty_quiescent | struct_ops | struct_ops/rusty_quiescent | kernel_registration_required | 1 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/scx/scx_rusty_main.bpf.o:rusty_runnable | struct_ops | struct_ops/rusty_runnable | kernel_registration_required | 1 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/systemd/userns-restrict.bpf.o:userns_restrict_path_link | lsm | lsm/path_link | lsm_custom_harness | 1 | requires security hook attachment; current automation only records loadability and sites |
| corpus/build/systemd/userns-restrict.bpf.o:userns_restrict_path_mkdir | lsm | lsm/path_mkdir | lsm_custom_harness | 1 | requires security hook attachment; current automation only records loadability and sites |
| corpus/build/systemd/userns-restrict.bpf.o:userns_restrict_path_mknod | lsm | lsm/path_mknod | lsm_custom_harness | 1 | requires security hook attachment; current automation only records loadability and sites |
| corpus/build/systemd/userns-restrict.bpf.o:userns_restrict_path_symlink | lsm | lsm/path_symlink | lsm_custom_harness | 1 | requires security hook attachment; current automation only records loadability and sites |

## Inventory Failures

| Object | Failure |
| --- | --- |
| corpus/build/netbird/prog.bpf.o | bpf_object__open_file failed: Operation not supported (exit=1) |

## Top Load Failures

| Reason | Count |
| --- | --- |
| bpf_object__load failed: Bad file descriptor (exit=1) | 66 |
| bpf_object__load failed: Operation not supported (exit=1) | 46 |
| bpf_object__load failed: Invalid argument (exit=1) | 12 |
| bpf_object__load failed: No such process (exit=1) | 2 |
| bpf_object__load failed: Permission denied (exit=1) | 1 |

## Top Tracing Skip Reasons

| Reason | Count |
| --- | --- |
| no trigger heuristic for section `kprobe/retire_userns_sysctls` / program `userns_restrict_retire_userns_sysctls` | 1 |
| no trigger heuristic for section `kprobe/enforcer` / program `kprobe_enforcer` | 1 |
| no trigger heuristic for section `kprobe/security_bprm_committing_creds` / program `tg_kp_bprm_committing_creds` | 1 |
| no trigger heuristic for section `kprobe/acct_process` / program `event_exit_acct_process` | 1 |
| no trigger heuristic for section `kprobe/disassociate_ctty` / program `event_exit_disassociate_ctty` | 1 |
| no trigger heuristic for section `fmod_ret/security_task_prctl` / program `fmodret_enforcer` | 1 |
| no trigger heuristic for section `kprobe/wake_up_new_task` / program `event_wake_up_new_task` | 1 |
| no trigger heuristic for section `kprobe.multi/enforcer` / program `kprobe_multi_enforcer` | 1 |

## Notes

- Program type comes from `micro_exec list-programs`, which now surfaces libbpf-inferred `prog_type` and `expected_attach_type` per program.
- Packet-backed measurements use `bpf_prog_test_run_opts()` and the existing `micro_exec run-kernel` path.
- Tracing measurements use real load + attach + trigger, then read `run_cnt` and `run_time_ns` from `bpf_prog_info`.
- Directive counts prefer the live recompile probe. When that fails but the program still loads, the report falls back to `dump-xlated` plus `bpf-jit-scanner scan --xlated --v5`.
- `syscall` programs are counted separately because the kernel has a synthetic test-run path, but this report does not treat that as a real attached workload benchmark.

