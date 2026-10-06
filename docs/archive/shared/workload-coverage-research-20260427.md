# Workload Coverage Research (2026-04-27)

Sources reviewed:
- `CLAUDE.md`
- `corpus/results/x86_kvm_corpus_20260427_204924_532478/details/result.json`
- `runner/libs/benchmark_catalog.py`
- `runner/libs/workload.py`
- `runner/libs/app_runners/*.py`
- `e2e/cases/tetragon/policies/*.yaml`

## Scope And Counting Notes

- This report is about workload coverage, so program counts below use `baseline.bpf[*].run_cnt_delta > 0` from each app result.
- On that basis, the artifact contains `503` baseline programs across `21` apps with baseline stats, and `142` of them were triggered at least once (`28.2%` coverage).
- `CLAUDE.md` explains why the top-level corpus metric is smaller: `summary.program_count = 140` only counts programs with `run_cnt_delta > 0` on both baseline and post-ReJIT.
- The `142` baseline-hit vs `140` corpus-metric difference comes from two programs that ran on baseline but had `0` post-ReJIT hits:
  - `bcc/vfsstat`: `kfunc__vmlinux__vfs_fsync_range` / post name `vfs_fsync_range`
  - `tetragon/observer`: `generic_kprobe_event` (program id `350`)
- `runner/libs/workloads/` does not exist in this checkout. Workload implementations live in `runner/libs/workload.py`.

## Per-App Coverage

| App | Runner | Selected workload | Status | Total | Triggered | Untriggered | Coverage |
| --- | --- | --- | --- | ---: | ---: | ---: | ---: |
| `bcc/capable` | `bcc` | `exec_storm` | `ok` | 1 | 1 | 0 | 100.0% |
| `bcc/execsnoop` | `bcc` | `exec_storm` | `ok` | 2 | 2 | 0 | 100.0% |
| `bcc/bindsnoop` | `bcc` | `bind_storm` | `ok` | 3 | 3 | 0 | 100.0% |
| `bcc/biosnoop` | `bcc` | `block_io` | `ok` | 3 | 3 | 0 | 100.0% |
| `bcc/vfsstat` | `bcc` | `vfs_create_fsync_exact` | `ok` | 5 | 4 | 1 | 80.0% |
| `bcc/opensnoop` | `bcc` | `open_family_storm` | `ok` | 3 | 2 | 1 | 66.7% |
| `bcc/syscount` | `bcc` | `file_open_storm` | `ok` | 2 | 2 | 0 | 100.0% |
| `bcc/tcpconnect` | `bcc` | `network` | `ok` | 3 | 3 | 0 | 100.0% |
| `bcc/tcplife` | `bcc` | `network` | `ok` | 1 | 1 | 0 | 100.0% |
| `bcc/runqlat` | `bcc` | `hackbench` | `ok` | 3 | 3 | 0 | 100.0% |
| `calico/felix` | `calico` | `network` | `ok` | 6 | 0 | 6 | 0.0% |
| `otelcol-ebpf-profiler/profiling` | `otelcol-ebpf-profiler` | `exec_storm` | `ok` | 13 | 2 | 11 | 15.4% |
| `cilium/agent` | `cilium` | `network` | `error` | N/A | N/A | N/A | N/A |
| `tetragon/observer` | `tetragon` | `tetragon_exec_connect_mix` | `ok` | 287 | 33 | 254 | 11.5% |
| `katran` | `katran` | `test_run` | `ok` | 3 | 1 | 2 | 33.3% |
| `tracee/monitor` | `tracee` | `tracee_system_edge_mix` | `error` | 158 | 72 | 86 | 45.6% |
| `bpftrace/capable` | `bpftrace` | `exec_storm` | `ok` | 1 | 1 | 0 | 100.0% |
| `bpftrace/biosnoop` | `bpftrace` | `block_io` | `ok` | 2 | 2 | 0 | 100.0% |
| `bpftrace/vfsstat` | `bpftrace` | `vfs_create_write_fsync` | `ok` | 2 | 2 | 0 | 100.0% |
| `bpftrace/runqlat` | `bpftrace` | `hackbench` | `ok` | 3 | 3 | 0 | 100.0% |
| `bpftrace/tcplife` | `bpftrace` | `network` | `ok` | 1 | 1 | 0 | 100.0% |
| `bpftrace/tcpretrans` | `bpftrace` | `tcp_retransmit` | `ok` | 1 | 1 | 0 | 100.0% |

## Current Workload Implementations

- Registry and runner-side selection live in `runner/libs/benchmark_catalog.py`.
- Workload implementations live in `runner/libs/workload.py`.
- The low-coverage app workloads are currently:
  - `bcc/vfsstat`: `vfs_create_fsync_exact`
  - `bcc/opensnoop`: `open_family_storm`
  - `calico/felix`: `network`
  - `otelcol-ebpf-profiler/profiling`: `exec_storm`
  - `tetragon/observer`: `tetragon_exec_connect_mix`
  - `katran`: `test_run`
  - `tracee/monitor`: `tracee_system_edge_mix`
  - `cilium/agent`: `network`, but the run failed before baseline BPF stats could be collected
- Relevant behavior from `runner/libs/workload.py`:
  - `tetragon_exec_connect_mix` is `exec_storm` plus a TCP `connect_storm`; it does not send payload data.
  - `tracee_system_edge_mix` covers successful and failed `execveat`, `dup2`, `socketpair`, `accept4`, and one cgroup mkdir/rmdir sequence.
  - `tracee_module_load_loop` and `tracee_io_vector_mix` already exist, but are not used by the corpus case.
  - `open_family_storm` uses libc `open()`, `openat()`, and a direct `openat2()` syscall.
  - `vfs_create_fsync_exact` uses `os.open(..., O_CREAT|O_EXCL|O_RDWR)` and `fsync`.
  - `vfs_create_write_fsync` uses path-based create, write, fsync, read, unlink; this is what the fully covered `bpftrace/vfsstat` case uses.
  - `network` uses real HTTP traffic; for Calico/Cilium/Katran runners this is interface-bound traffic, not loopback-only traffic.
  - `katran` already has a `network` workload path in its runner, but the corpus case selects `test_run` instead.

## Untriggered Program Inventory

Apps not listed here had `0` untriggered programs in this artifact.

### `bcc/vfsstat`

- Hook types: `tracing` x1
- Untriggered programs:
  - `vfs_create` (`tracing`)

### `bcc/opensnoop`

- Hook types: `tracing` x1
- Untriggered programs:
  - `__x64_sys_open` (`tracing`)

### `calico/felix`

- Hook types: `sched_cls` x6
- Untriggered programs:
  - `calico_tc_allow` (`sched_cls`) x2
  - `calico_tc_deny` (`sched_cls`) x2
  - `cali_tcx_test` (`sched_cls`)
  - `conntrack_cleanup` (`sched_cls`)

### `otelcol-ebpf-profiler/profiling`

- Hook types: `perf_event` x11
- Untriggered programs:
  - `perf_go_labels` (`perf_event`)
  - `perf_unwind_beam` (`perf_event`)
  - `perf_unwind_dotnet` (`perf_event`)
  - `perf_unwind_hotspot` (`perf_event`)
  - `perf_unwind_native` (`perf_event`)
  - `perf_unwind_perl` (`perf_event`)
  - `perf_unwind_php` (`perf_event`)
  - `perf_unwind_python` (`perf_event`)
  - `perf_unwind_ruby` (`perf_event`)
  - `perf_unwind_stop` (`perf_event`)
  - `perf_unwind_v8` (`perf_event`)

### `cilium/agent`

- Baseline BPF inventory unavailable in this artifact.
- Error: `failed to read BPF stats for requested program ids: 181, 182, 183, 185, 187, 188, 190, 191, 193, 195, 196, 197, 198, 199, 200, 201, 203, 204, 207, 208, 209, 210, 211, 212, 215, 216, 224, 225, 226, 227, 230, 233, 235`

### `tetragon/observer`

- Hook types: `kprobe` x240, `tracepoint` x7, `raw_tracepoint` x6, `socket_filter` x1
- Untriggered programs:
  - `generic_kprobe_actions` (`kprobe`) x33
  - `generic_kprobe_filter_arg` (`kprobe`) x33
  - `generic_kprobe_output` (`kprobe`) x33
  - `generic_kprobe_process_event` (`kprobe`) x33
  - `generic_kprobe_process_filter` (`kprobe`) x33
  - `generic_kprobe_setup_event` (`kprobe`) x33
  - `generic_kprobe_event` (`kprobe`) x12
  - `generic_retkprobe_actions` (`kprobe`) x9
  - `generic_retkprobe_filter_arg` (`kprobe`) x9
  - `generic_retkprobe_output` (`kprobe`) x9
  - `generic_retkprobe_event` (`kprobe`) x3
  - `generic_tracepoint_actions` (`tracepoint`)
  - `generic_tracepoint_arg` (`tracepoint`)
  - `generic_tracepoint_filter` (`tracepoint`)
  - `generic_tracepoint_output` (`tracepoint`)
  - `generic_tracepoint_process_event` (`tracepoint`)
  - `execve_send` (`tracepoint`)
  - `execve_rate` (`tracepoint`)
  - `generic_rawtp_actions` (`raw_tracepoint`)
  - `generic_rawtp_filter_arg` (`raw_tracepoint`)
  - `generic_rawtp_output` (`raw_tracepoint`)
  - `generic_rawtp_process_event` (`raw_tracepoint`)
  - `generic_rawtp_process_filter` (`raw_tracepoint`)
  - `generic_rawtp_setup_event` (`raw_tracepoint`)
  - `execve_map_update` (`socket_filter`)

### `katran`

- Hook types: `xdp` x1, `sched_cls` x1
- Untriggered programs:
  - `xdp_root` (`xdp`)
  - `healthcheck_encap` (`sched_cls`)

### `tracee/monitor`

- Hook types: `kprobe` x71, `raw_tracepoint` x15
- Untriggered programs:
  - `kprobe` process manipulation: `trace_ptrace`, `trace_ret_ptrace`, `trace_process_vm_writev`, `trace_ret_process_vm_writev`, `trace_dup`, `trace_ret_dup`, `trace_dup3`, `trace_ret_dup3`, `sys_dup_exit_tail`
  - `kprobe` module and LKM monitoring: `lkm_seeker_modtree_loop`, `uprobe_lkm_seeker_submitter`, `uprobe_lkm_seeker`, `lkm_seeker_kset_tail`, `lkm_seeker_mod_tree_tail`, `lkm_seeker_proc_tail`, `lkm_seeker_new_mod_only_tail`, `trace_security_kernel_read_file`, `trace_security_kernel_post_read_file`, `trace_do_init_module`, `trace_ret_do_init_module`, `trace_call_usermodehelper`
  - `kprobe` vectored and kernel I/O: `trace_ret_vfs_write_tail`, `trace_vfs_writev`, `vfs_writev_magic_enter`, `trace_ret_vfs_writev`, `vfs_writev_magic_return`, `trace_ret_vfs_writev_tail`, `trace_kernel_write`, `kernel_write_magic_enter`, `trace_ret_kernel_write`, `kernel_write_magic_return`, `trace_ret_kernel_write_tail`, `trace_ret_vfs_read_tail`, `trace_vfs_readv`, `trace_ret_vfs_readv`, `trace_ret_vfs_readv_tail`
  - `kprobe` filesystem metadata and notifications: `trace_security_sb_mount`, `trace_security_inode_symlink`, `trace_proc_create`, `trace_debugfs_create_file`, `trace_debugfs_create_dir`, `trace_security_inode_mknod`, `trace_security_inode_rename`, `trace_vfs_utimes`, `trace_utimes_common`, `trace_file_modified`, `trace_ret_file_modified`, `trace_inotify_find_inode`, `trace_ret_inotify_find_inode`, `trace_security_path_notify`, `trace_chmod_common`, `trace_security_sb_umount`, `trace_security_settime64`
  - `kprobe` BPF and kernel introspection: `trace_register_kprobe`, `trace_ret_register_kprobe`, `trace_bpf_check`, `trace_check_map_func_compatibility`, `trace_check_helper_call`, `trace_device_add`, `trace___register_chrdev`, `trace_ret__register_chrdev`, `trace_kallsyms_lookup_name`, `trace_ret_kallsyms_lookup_name`, `trace_tracepoint_probe_register_prio_may_exist`, `uprobe_syscall_table_check`, `uprobe_seq_ops_trigger`, `uprobe_mem_dump_trigger`, `send_bin`, `process_execute_failed_tail`, `syscall_checker`, `uprobe__features_fallback_arena`
  - `raw_tracepoint` exec and syscall helpers: `sys_enter_init`, `sys_enter_submit`, `sys_exit_init`, `sys_exit_submit`, `syscall__execve_enter`, `syscall__execve_exit`, `syscall__execveat_enter`, `syscall__execveat_exit`, `sched_process_exec_event_submit_tail`, `syscall__accept4`
  - `raw_tracepoint` cgroup and module lifecycle: `tracepoint__cgroup__cgroup_attach_task`, `send_bin_tp`, `syscall__init_module`, `tracepoint__module__module_load`, `tracepoint__module__module_free`

## Hook-Type Summary For Low-Coverage Apps

| App | Main untriggered hook types | What that implies |
| --- | --- | --- |
| `bcc/vfsstat` | `tracing` | one missing VFS create path variant |
| `bcc/opensnoop` | `tracing` | one missing legacy `open(2)` syscall path |
| `calico/felix` | `sched_cls` | TC programs are loaded but not reached by current minimal Felix setup |
| `otelcol-ebpf-profiler/profiling` | `perf_event` | profiler needs long-lived CPU-sampled processes, not short exec churn |
| `tetragon/observer` | mostly `kprobe`, plus `tracepoint`, `raw_tracepoint`, `socket_filter` | policy coverage is dominated by missed kernel events rather than loader failure |
| `katran` | `xdp`, `sched_cls` | corpus uses synthetic test replay instead of real interface traffic |
| `tracee/monitor` | mostly `kprobe`, some `raw_tracepoint` | current mix misses module, vectored I/O, ptrace, metadata, and attach-task activity |

## Low-Coverage Analysis

### `tetragon/observer` (`287` total, `33` triggered, `254` untriggered)

- The current workload is too narrow. `tetragon_exec_connect_mix` only generates exec churn and bare TCP connect/close traffic.
- Most of the `254` misses are not distinct user-visible features. Only `18` are entry-style programs:
  - `generic_kprobe_event` x12
  - `generic_retkprobe_event` x3
  - `execve_send`, `execve_rate`, `execve_map_update`
- The other `236` misses are helper shards such as `generic_kprobe_actions`, `generic_kprobe_process_event`, `generic_kprobe_output`, and similar pipeline stages. Once a missing policy event fires, several of these helpers usually light up together.
- From `e2e/cases/tetragon/policies/*.yaml`, the current workload is missing whole policy families:
  - UDP and skb path activity: `sk_filter_trim_cap`, `ip_output`, `ip_mc_output`, `ip6_output`, `__cgroup_bpf_run_filter_skb`
  - TCP payload and accept path activity: `tcp_sendmsg`, `tcp_create_openreq_child`, `tcp_set_state`
  - filesystem/security activity: `security_file_permission`, `security_mmap_file`, `security_path_truncate`, `security_inode_follow_link`
  - host-change activity: `security_kernel_module_request`, `security_kernel_read_file`, `do_init_module`, `free_module`
  - mount and TTY activity: `sys_mount`, `tty_write`
  - BPF-loader activity: `bpf_check`, `security_bpf_map_*`
- Workload activity needed:
  - real UDP send/receive, not just TCP connect
  - client/server TCP with payload sends and server accepts
  - symlink follow, file mmap, truncation
  - PTY writes
  - mount/umount
  - module load/unload
- Highest-upside point: Tetragon is the best place to spend workload effort because each newly hit event tends to fan out into several helper programs.

### `tracee/monitor` (`158` total, `72` triggered, `86` untriggered)

- `tracee_system_edge_mix` already covers some exec, cgroup mkdir/rmdir, and socket activity, but it does not exercise the other major Tracee event families.
- The cleanest missed groups are:
  - module lifecycle and LKM seekers
  - vectored I/O and kernel write paths
  - ptrace and `process_vm_writev`
  - `dup` and `dup3` variants
  - filesystem metadata operations such as symlink, rename, mknod, chmod, utimes, and notification paths
  - cgroup attach-task, not just cgroup create/remove
- Existing reusable workloads already exist in `runner/libs/workload.py`:
  - `tracee_module_load_loop`
  - `tracee_io_vector_mix`
- Some misses are probably not purely workload-fixable:
  - raw helper programs such as `sys_enter_init`, `sys_enter_submit`, `send_bin_tp`
  - introspection-heavy probes such as `trace_bpf_check`, `trace_register_kprobe`, `trace_kallsyms_lookup_name`
  - feature-gated uprobes such as `uprobe__features_fallback_arena`
- Practical reading: a better Tracee mix can likely recover a large fraction of the `86` misses, but probably not all of them without enabling extra Tracee features or self-observation paths.

### `otelcol-ebpf-profiler/profiling` (`13` total, `2` triggered, `11` untriggered)

- The current `exec_storm` workload is the wrong shape for a sampling profiler.
- The two triggered programs are lifecycle/entry oriented:
  - `tracepoint__sched_process_free`
  - `native_tracer_entry`
- All `11` misses are `perf_event` unwind or runtime-specific sampling programs. They need long-lived CPU-active processes, not lots of short-lived execs.
- Runtime availability on this host:
  - present: `python3`, `perl`, `ruby`, `node`, `java`, `go`
  - absent: `php`, `dotnet`, `erl`
- Workload activity needed:
  - one persistent native CPU burner
  - one persistent Python burner
  - one persistent Java burner
  - one persistent Node/V8 burner
  - one persistent Ruby burner
  - one persistent Perl burner
  - one Go burner that uses pprof labels for `perf_go_labels`
- The `php`, `.NET`, and BEAM unwinders are not workload-fixable in the current environment because the runtimes are missing.

### `calico/felix` (`6` total, `0` triggered, `6` untriggered)

- This is not a simple “send more packets” problem.
- The selected workload is already real interface-bound HTTP traffic. The workload is not idle.
- `cali_tcx_test` is a TCX capability probe program, not a datapath program.
- `conntrack_cleanup` is run by Felix userspace via `RunBPFProgram`, not by normal packet traffic.
- `calico_tc_allow` and `calico_tc_deny` are policy tail-call programs. In this artifact, the result inventory does not show the usual main datapath entry programs that would tail-call into them.
- Practical conclusion: with the current minimal Felix-only setup, there is probably no workload-only change that will make these six programs hot.
- The missing prerequisite is control-plane state:
  - workload or host endpoints
  - policy attachment
  - main TC/XDP datapath programs actually provisioned on real interfaces
- Full Kubernetes may not be strictly required, but Calico needs more than “Felix running plus traffic”.

### `katran` (`3` total, `1` triggered, `2` untriggered)

- The corpus case chooses `test_run`, which replays a packet through `balancer_ingress` using `bpftool prog test run`.
- That explains why `balancer_ingress` runs while `xdp_root` does not: the synthetic replay bypasses the real interface-attached XDP chain.
- `healthcheck_encap` is also untriggered because the current corpus case does not exercise Katran’s healthcheck path.
- There is already a real `network` workload path in the Katran runner. That is the obvious first change if the goal is coverage rather than deterministic packet replay.

### Small BCC misses

- `bcc/vfsstat`
  - Miss: `vfs_create`
  - Evidence: `bpftrace/vfsstat` reaches full coverage with the sibling `vfs_create_write_fsync` workload, while `bcc/vfsstat` uses `vfs_create_fsync_exact`.
  - Likely fix: align the BCC case with the path-based create/write/fsync workload.
- `bcc/opensnoop`
  - Miss: `__x64_sys_open`
  - Evidence: `open_family_storm` already hits `openat` and `openat2`, but not the legacy `open(2)` probe.
  - Likely fix: add an explicit direct `syscall(SYS_open, ...)` path instead of relying on libc `open()`.

## Recommended Workload Changes

### Highest Priority

| Priority | Change | Why | Expected impact |
| --- | --- | --- | --- |
| `P0` | Expand `tetragon_exec_connect_mix` into a composite network-and-system mix | Tetragon has the largest upside, and each newly hit policy event tends to activate several helper programs | Highest program gain per added workload step |
| `P0` | Expand `tracee_system_edge_mix` by reusing `tracee_module_load_loop` and `tracee_io_vector_mix`, then add ptrace, `process_vm_writev`, `dup`, `dup3`, and cgroup attach-task | These cover the cleanest missed Tracee families and reuse code that already exists | Likely dozens of additional hits |
| `P0` | Replace Otel’s `exec_storm` with long-lived CPU burners across native plus available managed runtimes | All `11` misses are `perf_event` unwind programs | Likely `+6` to `+8` immediately with current host runtimes |

### Medium Priority

| Priority | Change | Why | Expected impact |
| --- | --- | --- | --- |
| `P1` | Switch Katran corpus case from `test_run` to real `network` traffic | The current synthetic replay bypasses `xdp_root` | Likely at least `+1` program, possibly more if healthcheck traffic is added |
| `P1` | Align `bcc/vfsstat` with `vfs_create_write_fsync` | The bpftrace variant already proves this path reaches the missing VFS probe | Likely `+1` program |
| `P1` | Add a direct `SYS_open` step to `open_family_storm` | Targets the lone missed `__x64_sys_open` probe | Likely `+1` program |

### Lower Priority Or Not Workload-Only

| Priority | Change | Why | Expected impact |
| --- | --- | --- | --- |
| `P2` | Add a separate Katran healthcheck workload | Needed specifically for `healthcheck_encap` | Narrow coverage gain |
| `P2` | Add optional PHP, .NET, and BEAM Otel runtime burners after provisioning runtimes | Current environment lacks those runtimes | Up to `+3` more Otel programs after extra environment work |
| `P3` | Rework Calico setup to provision actual endpoints and policy state before measuring traffic | Current zero-hit set is blocked by control-plane state, not traffic volume | Potentially meaningful, but higher setup cost than workload-only changes |
| `P3` | Fix `cilium/agent` BPF stats collection before workload tuning | No reliable baseline inventory exists in this artifact | Prerequisite, not a workload recommendation |

## Concrete Workload Shapes To Add

### For `tetragon/observer`

- Add a UDP loopback send/receive phase.
- Change the TCP phase from connect-only to connect plus payload send plus server-side accept.
- Add a symlink-follow phase.
- Add a file mmap plus truncate phase.
- Add a PTY write phase.
- Add a mount/umount phase.
- Add a module load/unload phase.
- Keep BPF-loader activity separate and low priority.

### For `tracee/monitor`

- Reuse `tracee_module_load_loop`.
- Reuse `tracee_io_vector_mix`.
- Add `ptrace(PTRACE_ATTACH)` plus a child target.
- Add `process_vm_writev` against a traced child.
- Add explicit `dup()` and `dup3()` calls.
- Add a cgroup attach-task phase by moving a child into a created cgroup.
- Add symlink, rename, mknod, chmod, utimes, and inotify-triggering filesystem operations.
- Treat time-setting and some introspection-heavy probes as optional follow-up work.

### For `otelcol-ebpf-profiler/profiling`

- Run a native CPU burner for the full workload window.
- Run small CPU-bound loops in Python, Java, Node, Ruby, and Perl for the same window.
- Add a tiny Go program with pprof labels.
- Do not expect `php`, `.NET`, or `BEAM` coverage until those runtimes are installed.

## Bottom Line

- The best immediate returns are `tetragon`, `tracee`, and `otelcol-ebpf-profiler`.
- `katran`, `bcc/vfsstat`, and `bcc/opensnoop` are cheap follow-up wins.
- `calico/felix` is not currently blocked on workload intensity; it is blocked on the minimal control-plane setup not loading reachable datapath state.
