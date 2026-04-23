# Workload Coverage Analysis (2026-04-23)

Read-only analysis over the latest VM corpus artifact `corpus/results/x86_kvm_corpus_20260423_064352_754994/result.json`.

## Executive Summary

- Corpus apps: `20;` live programs in `baseline.programs`: `122`.
- `missing_baseline_exec_ns` proxy (`run_cnt == 0`): `61` programs.
- Workload-fixable from current evidence: `28` programs via six targeted variants.
- Not obviously workload-fixable: `33` programs (`30` helper/pipeline, `2` lifecycle, plus `trace_ret_kernel_write_tail` left uncounted in unlock estimates).

Evidence base:

- `docs/kernel-jit-optimization-plan.md` for current corpus context.
- `corpus/results/x86_kvm_corpus_20260423_064352_754994/result.json` for the live `baseline.programs` census and `run_cnt` values.
- `runner/libs/workload.py:171-207,317-425,451-456,624-743` for workload semantics.
- `corpus/config/macro_apps.yaml:7-147` for per-app corpus workload selection.
- `runner/libs/app_runners/*.py` and `e2e/cases/*/case.py` for app-specific workload interpretation (`network_as_tcp_connect`, Tracee/Tetragon event sets, Katran `test_run`).

## Part 1: Per-App Program x Workload Coverage Matrix

### bcc/capable (1 programs, workload=`exec_storm`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:8-13`.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `cap_capable` | `kprobe` | `212057` | capability checks (`cap_capable`) during repeated execs | `yes` | `hit` |

### bcc/execsnoop (2 programs, workload=`exec_storm`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:15-20`.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `syscall__execve` | `kprobe` | `1865` | `execve(2)` entry/return | `yes` | `hit` |
| `do_ret_sys_execve` | `kprobe` | `1248` | `execve(2)` entry/return | `yes` | `hit` |

### bcc/bindsnoop (3 programs, workload=`bind_storm`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:22-27`.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `bindsnoop_entry` | `kprobe` | `125977` | `bind(2)` on IPv4/IPv6 sockets | `yes` | `hit` |
| `bindsnoop_v4_return` | `kprobe` | `62989` | `bind(2)` on IPv4/IPv6 sockets | `yes` | `hit` |
| `bindsnoop_v6_return` | `kprobe` | `62988` | `bind(2)` on IPv4/IPv6 sockets | `yes` | `hit` |

### bcc/biosnoop (3 programs, workload=`block_io`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:29-35`.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `trace_pid_start_tp` | `tracepoint` | `1671169` | block request issue/start | `yes` | `hit` |
| `trace_req_start` | `kprobe` | `1671169` | block request issue/start | `yes` | `hit` |
| `trace_req_completion_tp` | `tracepoint` | `1671169` | block request completion | `yes` | `hit` |

### bcc/vfsstat (5 programs, workload=`vfs_create_write_fsync`, missing=`2`)

- Workload config: `corpus/config/macro_apps.yaml:37-42`.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `vfs_create` | `tracing` | `0` | new-file create path (`open(..., O_CREAT)` -> `vfs_create`) | `ambiguous` | `missing:exact-probe-gap` |
| `kfunc__vmlinux__vfs_fsync_range` | `tracing` | `0` | `fsync(2)` / `vfs_fsync_range()` | `ambiguous` | `missing:exact-probe-gap` |
| `vfs_open` | `tracing` | `214` | VFS open path | `yes` | `hit` |
| `vfs_read` | `tracing` | `1684` | VFS read path | `yes` | `hit` |
| `vfs_write` | `tracing` | `5595` | VFS write path | `yes` | `hit` |

### bcc/opensnoop (3 programs, workload=`file_open_storm`, missing=`2`)

- Workload config: `corpus/config/macro_apps.yaml:44-49`.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `__x64_sys_open` | `tracing` | `0` | legacy `open(2)` syscall | `no` | `missing:event-gap` |
| `kretfunc__vmlinux____x64_sys_openat` | `tracing` | `1518` | `openat(2)` return path | `yes` | `hit` |
| `kretfunc__vmlinux____x64_sys_openat2` | `tracing` | `0` | `openat2(2)` return path | `no` | `missing:event-gap` |

### bcc/syscount (2 programs, workload=`file_open_storm`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:51-56`.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `tracepoint__raw_syscalls__sys_enter` | `tracepoint` | `72741` | any syscall entry/exit; file-open storm generates many syscalls | `yes` | `hit` |
| `tracepoint__raw_syscalls__sys_exit` | `tracepoint` | `72729` | any syscall entry/exit; file-open storm generates many syscalls | `yes` | `hit` |

### bcc/tcpconnect (3 programs, workload=`network`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:58-63`.
- Note: runner.libs.app_runners.bcc.BCCRunner passes `network_as_tcp_connect=True`, so corpus `network` resolves to loopback TCP connect load, not `wrk` (`runner/libs/app_runners/bcc.py:488-507`, `runner/libs/workload.py:726-731`, `651-665`).

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `trace_connect_entry` | `kprobe` | `302` | TCP connect entry/return on IPv4/IPv6 | `yes` | `hit` |
| `trace_connect_v4_return` | `kprobe` | `151` | TCP connect entry/return on IPv4/IPv6 | `yes` | `hit` |
| `trace_connect_v6_return` | `kprobe` | `151` | TCP connect entry/return on IPv4/IPv6 | `yes` | `hit` |

### bcc/tcplife (1 programs, workload=`network`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:65-70`.
- Note: runner.libs.app_runners.bcc.BCCRunner passes `network_as_tcp_connect=True`, so corpus `network` resolves to loopback TCP connect load, not `wrk` (`runner/libs/app_runners/bcc.py:488-507`, `runner/libs/workload.py:726-731`, `651-665`).

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `tracepoint__sock__inet_sock_set_state` | `tracepoint` | `3322` | TCP socket state transitions during loopback connects | `yes` | `hit` |

### bcc/runqlat (3 programs, workload=`hackbench`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:72-77`.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `sched_switch` | `raw_tracepoint` | `150403` | scheduler context switches | `yes` | `hit` |
| `sched_wakeup` | `raw_tracepoint` | `97547` | task wakeups / wakeup_new | `yes` | `hit` |
| `raw_tracepoint__sched_wakeup_new` | `raw_tracepoint` | `12594` | task wakeups / wakeup_new | `yes` | `hit` |

### scx/rusty (13 programs, workload=`hackbench`, missing=`2`)

- Workload config: `corpus/config/macro_apps.yaml:79-84`.
- Note: The selected corpus workload is `hackbench`, so `rusty_init`/`rusty_exit` are lifecycle callbacks at scheduler attach/detach time, not steady-state hackbench callbacks.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `rusty_select_cpu` | `struct_ops` | `90220` | sched_ext struct_ops callback during runnable/enqueue/dispatch/task lifecycle | `yes` | `hit` |
| `rusty_enqueue` | `struct_ops` | `90540` | sched_ext struct_ops callback during runnable/enqueue/dispatch/task lifecycle | `yes` | `hit` |
| `rusty_dispatch` | `struct_ops` | `90228` | sched_ext struct_ops callback during runnable/enqueue/dispatch/task lifecycle | `yes` | `hit` |
| `rusty_runnable` | `struct_ops` | `90669` | sched_ext struct_ops callback during runnable/enqueue/dispatch/task lifecycle | `yes` | `hit` |
| `rusty_running` | `struct_ops` | `90970` | sched_ext struct_ops callback during runnable/enqueue/dispatch/task lifecycle | `yes` | `hit` |
| `rusty_stopping` | `struct_ops` | `90966` | sched_ext struct_ops callback during runnable/enqueue/dispatch/task lifecycle | `yes` | `hit` |
| `rusty_quiescent` | `struct_ops` | `90665` | sched_ext struct_ops callback during runnable/enqueue/dispatch/task lifecycle | `yes` | `hit` |
| `rusty_set_weight` | `struct_ops` | `324` | sched_ext struct_ops callback during runnable/enqueue/dispatch/task lifecycle | `yes` | `hit` |
| `rusty_set_cpumask` | `struct_ops` | `6` | sched_ext struct_ops callback during runnable/enqueue/dispatch/task lifecycle | `yes` | `hit` |
| `rusty_init_task` | `struct_ops` | `324` | sched_ext struct_ops callback during runnable/enqueue/dispatch/task lifecycle | `yes` | `hit` |
| `rusty_exit_task` | `struct_ops` | `324` | sched_ext struct_ops callback during runnable/enqueue/dispatch/task lifecycle | `yes` | `hit` |
| `rusty_init` | `struct_ops` | `0` | scheduler attach/detach lifecycle only | `no` | `missing:lifecycle` |
| `rusty_exit` | `struct_ops` | `0` | scheduler attach/detach lifecycle only | `no` | `missing:lifecycle` |

### tetragon/default (35 programs, workload=`exec_storm`, missing=`27`)

- Workload config: `corpus/config/macro_apps.yaml:86-90`.
- Tetragon policy/write path: `runner/libs/app_runners/tetragon.py:84-90`; load evidence in `result.json:23437-23454`.
- Note: The Tetragon runner writes policies for `sys_enter_execve`, `security_bprm_check`, `security_file_open`, and `tcp_connect` (`runner/libs/app_runners/tetragon.py:84-90`). The current artifact confirms the three generic kprobe sensors and the generic tracepoint sensor were loaded in that order (`result.json:23437-23454`), so the three 7-program `generic_kprobe_*` blocks map to `security_bprm_check`, `security_file_open`, and `tcp_connect` respectively by load order.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `event_exit_acct_process` | `kprobe` | `1805` | process exit accounting after exec workload children terminate | `yes` | `hit` |
| `event_wake_up_new_task` | `kprobe` | `2661` | new task wakeup/fork path while stress-ng spawns workers | `yes` | `hit` |
| `execve_rate` | `tracepoint` | `0` | `sys_enter_execve` rate-limit path inside Tetragon exec pipeline | `yes` | `missing:helper-or-pipeline` |
| `execve_send` | `tracepoint` | `0` | exec-event export/send path inside Tetragon exec pipeline | `yes` | `missing:helper-or-pipeline` |
| `event_execve` | `tracepoint` | `1442` | `sys_enter_execve` tracepoint event | `yes` | `hit` |
| `tg_kp_bprm_committing_creds` | `kprobe` | `1442` | `security_bprm_committing_creds` during exec credential commit | `yes` | `hit` |
| `execve_map_update` | `socket_filter` | `0` | execve map-update / socket-filter stage inside Tetragon exec pipeline | `yes` | `missing:helper-or-pipeline` |
| `tg_cgroup_rmdir` | `raw_tracepoint` | `1` | cgroup removal from Tetragon temp cgroup cleanup | `yes` | `hit` |
| `generic_kprobe_process_event` | `kprobe` | `0` | helper stage for generic kprobe attached to `security_bprm_check` | `yes` | `missing:helper-or-pipeline` |
| `generic_kprobe_filter_arg` | `kprobe` | `0` | helper stage for generic kprobe attached to `security_bprm_check` | `yes` | `missing:helper-or-pipeline` |
| `generic_kprobe_output` | `kprobe` | `0` | helper stage for generic kprobe attached to `security_bprm_check` | `yes` | `missing:helper-or-pipeline` |
| `generic_kprobe_setup_event` | `kprobe` | `0` | helper stage for generic kprobe attached to `security_bprm_check` | `yes` | `missing:helper-or-pipeline` |
| `generic_kprobe_process_filter` | `kprobe` | `0` | helper stage for generic kprobe attached to `security_bprm_check` | `yes` | `missing:helper-or-pipeline` |
| `generic_kprobe_actions` | `kprobe` | `0` | helper stage for generic kprobe attached to `security_bprm_check` | `yes` | `missing:helper-or-pipeline` |
| `generic_kprobe_event` | `kprobe` | `1642` | main generic kprobe event on `security_bprm_check` | `yes` | `hit` |
| `generic_kprobe_output` | `kprobe` | `0` | helper stage for generic kprobe attached to `security_file_open` | `yes` | `missing:helper-or-pipeline` |
| `generic_kprobe_setup_event` | `kprobe` | `0` | helper stage for generic kprobe attached to `security_file_open` | `yes` | `missing:helper-or-pipeline` |
| `generic_kprobe_actions` | `kprobe` | `0` | helper stage for generic kprobe attached to `security_file_open` | `yes` | `missing:helper-or-pipeline` |
| `generic_kprobe_process_filter` | `kprobe` | `0` | helper stage for generic kprobe attached to `security_file_open` | `yes` | `missing:helper-or-pipeline` |
| `generic_kprobe_process_event` | `kprobe` | `0` | helper stage for generic kprobe attached to `security_file_open` | `yes` | `missing:helper-or-pipeline` |
| `generic_kprobe_filter_arg` | `kprobe` | `0` | helper stage for generic kprobe attached to `security_file_open` | `yes` | `missing:helper-or-pipeline` |
| `generic_kprobe_event` | `kprobe` | `94728` | main generic kprobe event on `security_file_open` | `yes` | `hit` |
| `generic_kprobe_process_event` | `kprobe` | `0` | helper stage for generic kprobe attached to `tcp_connect` | `no` | `missing:event-gap` |
| `generic_kprobe_actions` | `kprobe` | `0` | helper stage for generic kprobe attached to `tcp_connect` | `no` | `missing:event-gap` |
| `generic_kprobe_filter_arg` | `kprobe` | `0` | helper stage for generic kprobe attached to `tcp_connect` | `no` | `missing:event-gap` |
| `generic_kprobe_event` | `kprobe` | `0` | main `tcp_connect` generic kprobe event | `no` | `missing:event-gap` |
| `generic_kprobe_output` | `kprobe` | `0` | helper stage for generic kprobe attached to `tcp_connect` | `no` | `missing:event-gap` |
| `generic_kprobe_setup_event` | `kprobe` | `0` | helper stage for generic kprobe attached to `tcp_connect` | `no` | `missing:event-gap` |
| `generic_kprobe_process_filter` | `kprobe` | `0` | helper stage for generic kprobe attached to `tcp_connect` | `no` | `missing:event-gap` |
| `generic_tracepoint_filter` | `tracepoint` | `0` | helper stage for generic tracepoint attached to `syscalls/sys_enter_execve` | `yes` | `missing:helper-or-pipeline` |
| `generic_tracepoint_arg` | `tracepoint` | `0` | helper stage for generic tracepoint attached to `syscalls/sys_enter_execve` | `yes` | `missing:helper-or-pipeline` |
| `generic_tracepoint_actions` | `tracepoint` | `0` | helper stage for generic tracepoint attached to `syscalls/sys_enter_execve` | `yes` | `missing:helper-or-pipeline` |
| `generic_tracepoint_output` | `tracepoint` | `0` | helper stage for generic tracepoint attached to `syscalls/sys_enter_execve` | `yes` | `missing:helper-or-pipeline` |
| `generic_tracepoint_process_event` | `tracepoint` | `0` | helper stage for generic tracepoint attached to `syscalls/sys_enter_execve` | `yes` | `missing:helper-or-pipeline` |
| `generic_tracepoint_event` | `tracepoint` | `1808` | main generic tracepoint event on `syscalls/sys_enter_execve` | `yes` | `hit` |

### katran (1 programs, workload=`test_run`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:92-96`.
- Note: Katran corpus workload is `test_run`, which replays packets through `bpftool prog test run` instead of issuing real network traffic (`runner/libs/app_runners/katran.py:690-745`).

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `balancer_ingress` | `xdp` | `26880` | XDP packet path via `bpftool prog test run` replay | `yes` | `hit` |

### tracee/default (37 programs, workload=`tracee_default`, missing=`28`)

- Workload config: `corpus/config/macro_apps.yaml:98-103`.
- Tracee event set: `e2e/cases/tracee/config.yaml:1-33`.
- Note: Tracee is configured only for `execve`, `sched_process_exec`, `security_file_open`, and `security_socket_connect` (`e2e/cases/tracee/config.yaml:1-33`). `tracee_default` mixes only exec, open, and connect (`runner/libs/workload.py:451-456`; `runner/libs/app_runners/tracee.py:461-481`).

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `tracepoint__raw_syscalls__sys_enter` | `raw_tracepoint` | `2056942` | raw syscall-enter fast path for all syscalls | `yes` | `hit` |
| `sys_enter_init` | `raw_tracepoint` | `0` | Tracee syscall-enter helper after raw syscall entry | `yes` | `missing:helper-or-pipeline` |
| `sys_enter_submit` | `raw_tracepoint` | `0` | Tracee syscall-enter submit helper after raw syscall entry | `yes` | `missing:helper-or-pipeline` |
| `tracepoint__raw_syscalls__sys_exit` | `raw_tracepoint` | `2056818` | raw syscall-exit fast path for all syscalls | `yes` | `hit` |
| `sys_exit_init` | `raw_tracepoint` | `0` | Tracee syscall-exit helper after raw syscall exit | `yes` | `missing:helper-or-pipeline` |
| `sys_exit_submit` | `raw_tracepoint` | `0` | Tracee syscall-exit submit helper after raw syscall exit | `yes` | `missing:helper-or-pipeline` |
| `syscall__execve_enter` | `raw_tracepoint` | `0` | `execve(2)`-specific syscall enter helper | `yes` | `missing:helper-or-pipeline` |
| `syscall__execve_exit` | `raw_tracepoint` | `0` | `execve(2)`-specific syscall exit helper | `yes` | `missing:helper-or-pipeline` |
| `syscall__execveat_enter` | `raw_tracepoint` | `0` | `execveat(2)` syscall enter | `no` | `missing:event-gap` |
| `syscall__execveat_exit` | `raw_tracepoint` | `0` | `execveat(2)` syscall exit | `no` | `missing:event-gap` |
| `sys_dup_exit_tail` | `kprobe` | `0` | `dup`/`dup2`/`dup3`/`fcntl(F_DUPFD*)` return path | `no` | `missing:event-gap` |
| `tracepoint__sched__sched_process_fork` | `raw_tracepoint` | `2237` | process fork event from exec workload | `yes` | `hit` |
| `lkm_seeker_modtree_loop` | `kprobe` | `0` | kernel-module discovery / LKM walk | `no` | `missing:event-gap` |
| `lkm_seeker_kset_tail` | `kprobe` | `0` | kernel-module discovery / LKM walk | `no` | `missing:event-gap` |
| `lkm_seeker_mod_tree_tail` | `kprobe` | `0` | kernel-module discovery / LKM walk | `no` | `missing:event-gap` |
| `lkm_seeker_proc_tail` | `kprobe` | `0` | kernel-module discovery / LKM walk | `no` | `missing:event-gap` |
| `lkm_seeker_new_mod_only_tail` | `kprobe` | `0` | new module discovery / LKM load | `no` | `missing:event-gap` |
| `tracepoint__sched__sched_process_exec` | `raw_tracepoint` | `4471` | `sched_process_exec` tracepoint from successful exec | `yes` | `hit` |
| `sched_process_exec_event_submit_tail` | `raw_tracepoint` | `0` | Tracee exec submit helper after `sched_process_exec` | `yes` | `missing:helper-or-pipeline` |
| `tracepoint__sched__sched_process_exit` | `raw_tracepoint` | `2237` | process exit tracepoint from short-lived exec workload | `yes` | `hit` |
| `tracepoint__sched__sched_process_free` | `raw_tracepoint` | `2246` | process free tracepoint after exit | `yes` | `hit` |
| `syscall__accept4` | `raw_tracepoint` | `0` | `accept4(2)` on the loopback server side of connect storm | `ambiguous` | `missing:exact-probe-gap` |
| `trace_security_file_open` | `kprobe` | `76156` | `security_file_open` from open storm | `yes` | `hit` |
| `trace_security_socket_connect` | `kprobe` | `12413` | `security_socket_connect` from loopback connect storm | `yes` | `hit` |
| `send_bin` | `kprobe` | `0` | Tracee binary-send/export helper path | `yes` | `missing:helper-or-pipeline` |
| `send_bin_tp` | `raw_tracepoint` | `0` | Tracee binary-send/export tracepoint helper path | `yes` | `missing:helper-or-pipeline` |
| `trace_ret_vfs_write_tail` | `kprobe` | `0` | `write(2)` return path | `no` | `missing:event-gap` |
| `trace_ret_vfs_writev_tail` | `kprobe` | `0` | `writev(2)` return path | `no` | `missing:event-gap` |
| `trace_ret_kernel_write_tail` | `kprobe` | `0` | `kernel_write()` path (module or kernel-managed writes) | `no` | `missing:event-gap` |
| `trace_ret_vfs_read_tail` | `kprobe` | `0` | `read(2)` return path | `no` | `missing:event-gap` |
| `trace_ret_vfs_readv_tail` | `kprobe` | `0` | `readv(2)` return path | `no` | `missing:event-gap` |
| `syscall__init_module` | `raw_tracepoint` | `0` | `init_module(2)` / `finit_module(2)` | `no` | `missing:event-gap` |
| `trace_load_elf_phdrs` | `kprobe` | `8942` | ELF program-header load during successful exec | `yes` | `hit` |
| `process_execute_failed_tail` | `kprobe` | `0` | failed exec path (`execve` returning error) | `no` | `missing:event-gap` |
| `syscall_checker` | `kprobe` | `0` | Tracee syscall-check helper path | `yes` | `missing:helper-or-pipeline` |
| `cgroup_mkdir_signal` | `raw_tracepoint` | `0` | cgroup mkdir/create signal | `no` | `missing:event-gap` |
| `cgroup_rmdir_signal` | `raw_tracepoint` | `0` | cgroup rmdir/remove signal | `no` | `missing:event-gap` |

### bpftrace/capable (1 programs, workload=`exec_storm`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:105-110`.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `cap_capable` | `kprobe` | `210860` | capability checks (`cap_capable`) during repeated execs | `yes` | `hit` |

### bpftrace/biosnoop (2 programs, workload=`block_io`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:112-118`.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `block_io_start` | `tracepoint` | `1753088` | block request issue/start | `yes` | `hit` |
| `block_io_done` | `tracepoint` | `1753088` | block request completion | `yes` | `hit` |

### bpftrace/vfsstat (2 programs, workload=`vfs_create_write_fsync`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:120-125`.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `1` | `perf_event` | `1` | periodic perf-event wakeup for bpftrace interval output | `yes` | `hit` |
| `vfs_create` | `kprobe` | `10591` | VFS create path on file creation | `yes` | `hit` |

### bpftrace/runqlat (3 programs, workload=`hackbench`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:127-132`.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `sched_wakeup` | `tracepoint` | `64077` | task wakeups / wakeup_new | `yes` | `hit` |
| `tracepoint_sched_sched_wakeup_new` | `tracepoint` | `12337` | task wakeups / wakeup_new | `yes` | `hit` |
| `sched_switch` | `tracepoint` | `143224` | scheduler context switches | `yes` | `hit` |

### bpftrace/tcplife (1 programs, workload=`network`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:134-139`.
- Note: runner.libs.app_runners.bpftrace.BpftraceRunner passes `network_as_tcp_connect=True`, so corpus `network` resolves to loopback TCP connect load (`runner/libs/app_runners/bpftrace.py:172-198`, `runner/libs/workload.py:726-731`, `651-665`).

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `tcp_set_state` | `kprobe` | `2997` | TCP socket state transitions during loopback connects | `yes` | `hit` |

### bpftrace/tcpretrans (1 programs, workload=`tcp_retransmit`, missing=`0`)

- Workload config: `corpus/config/macro_apps.yaml:141-147`.

| Program | Type | run_cnt | Trigger requirement | Current workload should hit? | Verdict |
| --- | --- | ---: | --- | --- | --- |
| `kprobe_tcp_retransmit_skb` | `kprobe` | `15` | TCP retransmit path under forced loss on loopback | `yes` | `hit` |

## Part 2: 61 Missing Programs, Categories, and Event Distribution

### Missing By App

| App | Missing programs | Missing names |
| --- | ---: | --- |
| `tracee/default` | `28` | `sys_enter_init`, `sys_enter_submit`, `sys_exit_init`, `sys_exit_submit`, `syscall__execve_enter`, `syscall__execve_exit`, ... |
| `tetragon/default` | `27` | `execve_rate`, `execve_send`, `execve_map_update`, `generic_kprobe_process_event`, `generic_kprobe_filter_arg`, `generic_kprobe_output`, ... |
| `bcc/vfsstat` | `2` | `vfs_create`, `kfunc__vmlinux__vfs_fsync_range` |
| `bcc/opensnoop` | `2` | `__x64_sys_open`, `kretfunc__vmlinux____x64_sys_openat2` |
| `scx/rusty` | `2` | `rusty_init`, `rusty_exit` |

### Missing Program Name Distribution

| Program name | Count | App(s) |
| --- | ---: | --- |
| `generic_kprobe_actions` | `3` | `tetragon/default` |
| `generic_kprobe_filter_arg` | `3` | `tetragon/default` |
| `generic_kprobe_output` | `3` | `tetragon/default` |
| `generic_kprobe_process_event` | `3` | `tetragon/default` |
| `generic_kprobe_process_filter` | `3` | `tetragon/default` |
| `generic_kprobe_setup_event` | `3` | `tetragon/default` |
| `__x64_sys_open` | `1` | `bcc/opensnoop` |
| `cgroup_mkdir_signal` | `1` | `tracee/default` |
| `cgroup_rmdir_signal` | `1` | `tracee/default` |
| `execve_map_update` | `1` | `tetragon/default` |
| `execve_rate` | `1` | `tetragon/default` |
| `execve_send` | `1` | `tetragon/default` |
| `generic_kprobe_event` | `1` | `tetragon/default` |
| `generic_tracepoint_actions` | `1` | `tetragon/default` |
| `generic_tracepoint_arg` | `1` | `tetragon/default` |
| `generic_tracepoint_filter` | `1` | `tetragon/default` |
| `generic_tracepoint_output` | `1` | `tetragon/default` |
| `generic_tracepoint_process_event` | `1` | `tetragon/default` |
| `kfunc__vmlinux__vfs_fsync_range` | `1` | `bcc/vfsstat` |
| `kretfunc__vmlinux____x64_sys_openat2` | `1` | `bcc/opensnoop` |
| `lkm_seeker_kset_tail` | `1` | `tracee/default` |
| `lkm_seeker_mod_tree_tail` | `1` | `tracee/default` |
| `lkm_seeker_modtree_loop` | `1` | `tracee/default` |
| `lkm_seeker_new_mod_only_tail` | `1` | `tracee/default` |
| `lkm_seeker_proc_tail` | `1` | `tracee/default` |
| `process_execute_failed_tail` | `1` | `tracee/default` |
| `rusty_exit` | `1` | `scx/rusty` |
| `rusty_init` | `1` | `scx/rusty` |
| `sched_process_exec_event_submit_tail` | `1` | `tracee/default` |
| `send_bin` | `1` | `tracee/default` |
| `send_bin_tp` | `1` | `tracee/default` |
| `sys_dup_exit_tail` | `1` | `tracee/default` |
| `sys_enter_init` | `1` | `tracee/default` |
| `sys_enter_submit` | `1` | `tracee/default` |
| `sys_exit_init` | `1` | `tracee/default` |
| `sys_exit_submit` | `1` | `tracee/default` |
| `syscall__accept4` | `1` | `tracee/default` |
| `syscall__execve_enter` | `1` | `tracee/default` |
| `syscall__execve_exit` | `1` | `tracee/default` |
| `syscall__execveat_enter` | `1` | `tracee/default` |
| `syscall__execveat_exit` | `1` | `tracee/default` |
| `syscall__init_module` | `1` | `tracee/default` |
| `syscall_checker` | `1` | `tracee/default` |
| `trace_ret_kernel_write_tail` | `1` | `tracee/default` |
| `trace_ret_vfs_read_tail` | `1` | `tracee/default` |
| `trace_ret_vfs_readv_tail` | `1` | `tracee/default` |
| `trace_ret_vfs_write_tail` | `1` | `tracee/default` |
| `trace_ret_vfs_writev_tail` | `1` | `tracee/default` |
| `vfs_create` | `1` | `bcc/vfsstat` |

### Missing Event-Type Distribution

| Event type | Missing count | Representative programs |
| --- | ---: | --- |
| `exec` | `22` | `execve_rate`, `syscall__execveat_enter`, `process_execute_failed_tail` |
| `fs` | `13` | `kfunc__vmlinux__vfs_fsync_range`, `generic_kprobe_output`@security_file_open, `trace_ret_vfs_write_tail` |
| `syscall` | `8` | `__x64_sys_open`, `sys_dup_exit_tail`, `sys_enter_submit` |
| `network` | `8` | `generic_kprobe_event`@tcp_connect, `syscall__accept4` |
| `scheduler` | `2` | `rusty_init`, `rusty_exit` |
| `other` | `8` | `lkm_seeker_modtree_loop`, `syscall__init_module`, `cgroup_mkdir_signal` |

### Root Cause Buckets

| Root cause bucket | Count | Meaning |
| --- | ---: | --- |
| `missing:event-gap` | `26` | Current workload does not generate the needed event class for that app. |
| `missing:exact-probe-gap` | `3` | Workload nominally aims at the right family, but the implementation does not reach the exact kernel probe. |
| `missing:helper-or-pipeline` | `30` | Primary event exists, but an internal helper/export/tail path still never runs. |
| `missing:lifecycle` | `2` | Probe is only hit at app/scheduler startup or teardown, not by steady-state workload. |

### Event Classes Missing From Current Workload Variants

- `tetragon/default`: no corpus variant currently adds `tcp_connect` on top of the existing exec-heavy path, so `109-115` stay uncovered even though the runner loaded the `tcp_connect` generic kprobe (`result.json:23439-23448`).
- `tracee/default`: no corpus variant deliberately generates `execveat`, failed `execve`, `dup*`, cgroup mkdir/rmdir, module load/unload, or `readv/writev`; the current mixed workload is only exec/open/connect (`runner/libs/workload.py:451-456`).
- `bcc/opensnoop`: no corpus variant deliberately exercises the syscall family split between `open`, `openat`, and `openat2`; current Python open storm only demonstrates `openat` in practice.
- `bcc/vfsstat`: the existing `vfs_create_write_fsync` kind is too weak/indirect for exact `vfs_create` and `vfs_fsync_range` coverage in this artifact, even though it does reach `vfs_open/read/write`.

## Part 3: Recommended New Workload Variants

| Priority | New workload kind | Files to touch | App/workload change | Estimated unlock | Evidence / target probes |
| ---: | --- | --- | --- | ---: | --- |
| `1` | `tetragon_exec_connect_mix` | `runner/libs/workload.py`, `corpus/config/macro_apps.yaml` | `corpus/config/macro_apps.yaml:86-90` (`tetragon/default`) | `7` | The Tetragon runner loads a `tcp_connect` generic kprobe (`runner/libs/app_runners/tetragon.py:84-90`; `result.json:23437-23448`), but the whole third `generic_kprobe_*` block (`109-115`) has `run_cnt=0` under current `exec_storm`. Targets: `109-115 generic_kprobe_*@tcp_connect`. |
| `2` | `tracee_system_edge_mix` | `runner/libs/workload.py`, `corpus/config/macro_apps.yaml` | `corpus/config/macro_apps.yaml:98-103` (`tracee/default`) | `7` | Current `tracee_default` mixes only exec/open/connect (`runner/libs/workload.py:451-456`) while Tracee still has zero-run probes for `execveat`, `dup`, `accept4`, failed exec, and cgroup mkdir/rmdir (`144,145,146,157,169,171,172`). Targets: `144,145,146,157,169,171,172`. |
| `3` | `tracee_module_load_loop` | `runner/libs/workload.py`, `corpus/config/macro_apps.yaml` | `corpus/config/macro_apps.yaml:98-103` (`tracee/default`) | `6` | Tracee has six zero-run module-related probes (`148-152`, `167`) and no current workload variant performs `init_module/finit_module` or LKM churn. Targets: `148-152 lkm_seeker_*`, `167 syscall__init_module`. |
| `4` | `tracee_io_vector_mix` | `runner/libs/workload.py`, `corpus/config/macro_apps.yaml` | `corpus/config/macro_apps.yaml:98-103` (`tracee/default`) | `4` | Current `tracee_default` open phase only opens files and does not issue `read/write/readv/writev` (`runner/libs/workload.py:317-329`, `451-456`), leaving `162,163,165,166` at `run_cnt=0`. Targets: `162,163,165,166`. |
| `5` | `open_family_storm` | `runner/libs/workload.py`, `corpus/config/macro_apps.yaml` | `corpus/config/macro_apps.yaml:44-49` (`bcc/opensnoop`) | `2` | Current file-open storm is Python `Path.open()` (`runner/libs/workload.py:317-329`, `423-425`); in the artifact only `openat` hits while `__x64_sys_open` and `__x64_sys_openat2` stay at `run_cnt=0`. Targets: `30 __x64_sys_open`, `32 __x64_sys_openat2`. |
| `6` | `vfs_create_fsync_exact` | `runner/libs/workload.py`, `corpus/config/macro_apps.yaml` | `corpus/config/macro_apps.yaml:37-42` (`bcc/vfsstat`) | `2` | Current `vfs_create_write_fsync` intends to create/write/fsync/read/unlink (`runner/libs/workload.py:624-634`), but the live artifact still shows `vfs_create` and `vfs_fsync_range` at `run_cnt=0` while `vfs_open/read/write` do run. Targets: `23 vfs_create`, `24 kfunc__vmlinux__vfs_fsync_range`. |

Suggested implementation shape for each new kind:

- `tetragon_exec_connect_mix`: compose `run_exec_storm()` with `run_connect_storm()` so `event_execve`/`security_bprm_check` remain hot while adding real `tcp_connect` hits for `109-115`.
- `tracee_system_edge_mix`: a deterministic loop over `execveat`, failed `execve`, `dup3`, explicit `accept4`, and cgroup mkdir/rmdir. This should be a new kind rather than mutating `tracee_default`, because the current variant is intentionally lightweight.
- `tracee_module_load_loop`: repeatedly load/unload a tiny test module (or a stub module artifact prepared by the repo) to cover `lkm_seeker_*` plus `init_module`. Do not count `trace_ret_kernel_write_tail` in the estimate until the module path proves it fires.
- `tracee_io_vector_mix`: issue `read`, `write`, `readv`, and `writev` directly (for example via `os.readv` / `os.writev`) so the vector tails are guaranteed instead of relying on high-level buffered I/O.
- `open_family_storm`: explicitly call `open`, `openat`, and `openat2` in one loop so `bcc/opensnoop` stops depending on Python/libc implementation details.
- `vfs_create_fsync_exact`: use low-level `os.open(..., O_CREAT|O_EXCL)`, `os.write`, `os.fsync`, `os.read`, and `os.unlink` so `vfs_create` and `vfs_fsync_range` are exercised directly instead of indirectly through Python file objects.

## Part 4: Implementation Priority

| Rank | Variant | Estimated unlock | Why it comes here |
| ---: | --- | ---: | --- |
| `1` | `tetragon_exec_connect_mix` | `7` | Largest single-app unlock with the clearest evidence: a whole 7-program `tcp_connect` block is loaded but idle. |
| `2` | `tracee_system_edge_mix` | `7` | Same unlock count as Tetragon and covers five distinct missing event classes in one variant. |
| `3` | `tracee_module_load_loop` | `6` | Best remaining ROI after the two 7-probe variants; isolates all module-related misses in one place. |
| `4` | `tracee_io_vector_mix` | `4` | Smaller unlock count, but it removes an entire file-I/O blind spot from `tracee_default`. |
| `5` | `open_family_storm` | `2` | Small but high-certainty fix; current `bcc/opensnoop` coverage clearly depends on Python choosing `openat`. |
| `6` | `vfs_create_fsync_exact` | `2` | Also a 2-probe fix, but slightly less certain because the current kind already aims at create/fsync and still misses the exact probes. |

### After These Six Variants

- Best-case unlock from workload work alone: `28` / `61` missing programs.
- Remaining misses are mostly not workload-shaped:
  - `30` helper/pipeline programs already sit under events that are present today (notably Tetragon `generic_*` helper stages and Tracee syscall/submit/export helpers).
  - `2` scheduler lifecycle callbacks (`rusty_init`, `rusty_exit`) need runner/lifecycle accounting rather than a new steady-state workload kind.
- Therefore the highest-leverage next step is: add the six variants above first, then reassess the remaining 33 misses as runner/app-internal coverage gaps rather than workload gaps.
