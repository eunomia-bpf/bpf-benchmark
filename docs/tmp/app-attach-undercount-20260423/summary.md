# App Attach Undercount Investigation (2026-04-23)

## Scope

- Read-only investigation. No code changes to runners, no VM runs.
- Ground truth for "current actual attach count" is `baseline.programs` from `corpus/results/x86_kvm_corpus_20260423_064352_754994/result.json`, summarized in `corpus/results/x86_kvm_corpus_20260423_064352_754994/result.md:17-36`.
- After the 2026-04-22 cleanup, the live runners no longer do post-discovery name filtering. The authoritative discovery path is global `bpftool prog show` before/after diff plus a 2s stable-set wait (`docs/tmp/delete-program-selection-20260422/summary.md:59-63`, `:118-128`, `runner/libs/app_runners/process_support.py:15-46`).
- Same-day e2e artifacts reproduce the same headline counts: `e2e/results/tracee_20260423_063045_530810/result.json` reports `tracee_programs=37`, and `e2e/results/tetragon_20260423_063348_563674/result.json` reports `tetragon_programs=35`.
- Therefore the remaining ambiguity is mostly not "discovery missed loaded programs", but "current config did not ask the app to load more" and, for BCC/bpftrace, "`bpftool prog show` counts program objects, not attach links/probe declarations".

## Part 1: Per-App Comparison

| App | Current actual from corpus | Native production default | Max benchmark-tuned estimate | Main reason for gap |
| --- | ---: | ---: | ---: | --- |
| Tracee | 37 | about 70-100 | about 120-154 | Current runner hard-pins a 4-event subset instead of native default or `all` |
| Tetragon | 35 | about 8 | about 200+ | Current runner injects a synthetic policy pack; native default is actually smaller, and hundreds only happen with many TracingPolicies |
| BCC (current 10-tool suite) | 26 | about 26-27 | about 30 | No major discovery bug; `bpftool` counts program objects, not every attach link |
| bpftrace (current 6-script suite) | 10 | about 10 | about 10-12 | No major discovery bug; one bpftrace action block can back multiple probes |
| SCX (`rusty`) | 13 | 13 | 13 | No gap; current count matches the scheduler object's `struct_ops` callbacks |
| Katran | 1 | 2 | 3 | Current runner forces `-hc_forwarding=false` and never installs/uses `xdp_root` |

### Main finding

- `tracee=37` is a real under-config/default issue.
- `katran=1` is also a real under-config/default issue.
- `tetragon=35` is not an under-count versus native default; it is already above native default because the runner injects 1 tracepoint + 3 kprobes worth of synthetic policies.
- `bcc`, `bpftrace`, and `scx` are broadly at expected program-object counts already.

### 1. Tracee

- Current config:
  - `e2e/cases/tracee/config.yaml:1-5` enables only 4 events: `execve`, `sched_process_exec`, `security_file_open`, `security_socket_connect`.
  - `runner/libs/app_runners/tracee.py:437-441` always builds `tracee --events <comma-list> ...`.
  - `runner/libs/app_runners/tracee.py:490-497` loads that YAML list as the default event set.
- Current actual loaded count:
  - 37 programs.
  - Types: 20 `raw_tracepoint`, 17 `kprobe`.
  - Programs: `cgroup_mkdir_signal[raw_tracepoint]`, `cgroup_rmdir_signal[raw_tracepoint]`, `lkm_seeker_kset_tail[kprobe]`, `lkm_seeker_mod_tree_tail[kprobe]`, `lkm_seeker_modtree_loop[kprobe]`, `lkm_seeker_new_mod_only_tail[kprobe]`, `lkm_seeker_proc_tail[kprobe]`, `process_execute_failed_tail[kprobe]`, `sched_process_exec_event_submit_tail[raw_tracepoint]`, `send_bin[kprobe]`, `send_bin_tp[raw_tracepoint]`, `sys_dup_exit_tail[kprobe]`, `sys_enter_init[raw_tracepoint]`, `sys_enter_submit[raw_tracepoint]`, `sys_exit_init[raw_tracepoint]`, `sys_exit_submit[raw_tracepoint]`, `syscall__accept4[raw_tracepoint]`, `syscall__execve_enter[raw_tracepoint]`, `syscall__execve_exit[raw_tracepoint]`, `syscall__execveat_enter[raw_tracepoint]`, `syscall__execveat_exit[raw_tracepoint]`, `syscall__init_module[raw_tracepoint]`, `syscall_checker[kprobe]`, `trace_load_elf_phdrs[kprobe]`, `trace_ret_kernel_write_tail[kprobe]`, `trace_ret_vfs_read_tail[kprobe]`, `trace_ret_vfs_readv_tail[kprobe]`, `trace_ret_vfs_write_tail[kprobe]`, `trace_ret_vfs_writev_tail[kprobe]`, `trace_security_file_open[kprobe]`, `trace_security_socket_connect[kprobe]`, `tracepoint__raw_syscalls__sys_enter[raw_tracepoint]`, `tracepoint__raw_syscalls__sys_exit[raw_tracepoint]`, `tracepoint__sched__sched_process_exec[raw_tracepoint]`, `tracepoint__sched__sched_process_exit[raw_tracepoint]`, `tracepoint__sched__sched_process_fork[raw_tracepoint]`, `tracepoint__sched__sched_process_free[raw_tracepoint]`.
- Native production default:
  - The binary help says Tracee exposes "hundreds of events" (`corpus/build/x86_64/tracee/bin/tracee --help`, same build as benchmark).
  - The same build's `tracee list events` reports `Detector Events (33)` and `Syscall Events (447)`.
  - `tracee list events tag=default --json` on the same build returns 74 default-tag events: 33 `detector`, 25 `syscall`, 10 `other`, 6 `network`.
  - Upstream event registry is large: `pkg/events/core.go` enumerates the common event IDs and categories, not a 4-event toy set ([aquasecurity/tracee `pkg/events/core.go#L83-L239`](https://github.com/aquasecurity/tracee/blob/main/pkg/events/core.go#L83-L239)).
  - The built object also has a hard object-level ceiling far above 37: `llvm-objdump -h corpus/build/tracee/tracee.bpf.o` shows about 154 BPF program sections.
- Assessment:
  - This is a config/policy problem, not a `bpftool` diff miss.
  - Current runner cannot reach native default semantics because it unconditionally passes `--events ...`; there is no "omit `--events` and let Tracee choose default" path today.
  - 37 is much smaller than native default should be, but "several hundred loaded programs" is still too high for this build. Even `--events all` is bounded by roughly the object ceiling, about 154 program sections.
- Estimated counts:
  - Native default: about 70-100 loaded program objects.
  - Max benchmark-tuned (`--events all`): about 120-154 loaded program objects.

### 2. Tetragon

- Current config:
  - `e2e/cases/tetragon/config_execve_rate.yaml:3-5` passes only `--cgroup-rate 1000,1s`.
  - `runner/libs/app_runners/tetragon.py:84-90` writes two temporary policies at startup:
    - one tracepoint policy for `syscalls:sys_enter_execve`
    - one kprobe policy for `security_bprm_check`, `security_file_open`, `tcp_connect`
  - `runner/libs/app_runners/tetragon.py:216-218` sets `DEFAULT_TETRAGON_EXTRA_ARGS = ("--cgroup-rate", "1000,1s")`.
  - `runner/libs/app_runners/tetragon.py:262-276` always appends `--tracing-policy-dir <tempdir>` and therefore always loads the synthetic policies.
- Current actual loaded count:
  - 35 programs.
  - Types: 24 `kprobe`, 9 `tracepoint`, 1 `socket_filter`, 1 `raw_tracepoint`.
  - Programs:
    - Built-ins: `event_execve[tracepoint]`, `event_exit_acct_process[kprobe]`, `event_wake_up_new_task[kprobe]`, `execve_map_update[socket_filter]`, `execve_rate[tracepoint]`, `execve_send[tracepoint]`, `tg_cgroup_rmdir[raw_tracepoint]`, `tg_kp_bprm_committing_creds[kprobe]`.
    - Generic tracepoint instance for the injected `sys_enter_execve` policy: `generic_tracepoint_actions`, `generic_tracepoint_arg`, `generic_tracepoint_event`, `generic_tracepoint_filter`, `generic_tracepoint_output`, `generic_tracepoint_process_event`.
    - Generic kprobe instances for the 3 injected kprobes: three copies each of `generic_kprobe_actions`, `generic_kprobe_event`, `generic_kprobe_filter_arg`, `generic_kprobe_output`, `generic_kprobe_process_event`, `generic_kprobe_process_filter`, `generic_kprobe_setup_event`.
- Native production default:
  - Upstream README is explicit: Tetragon emits `process_exec` and `process_exit` by default; generic kprobe/tracepoint/uprobe events are for `TracingPolicy`-driven custom use cases ([cilium/tetragon `README.md#L43-L55`](https://github.com/cilium/tetragon/blob/main/README.md#L43-L55)).
  - Upstream flags default to no policy file, a policy directory, and disabled cgroup-rate:
    - `flags.String(KeyTracingPolicy, "", ...)` and `flags.String(KeyTracingPolicyDir, defaults.DefaultTpDir, ...)` ([cilium/tetragon `pkg/option/flags.go#L427-L429`](https://github.com/cilium/tetragon/blob/main/pkg/option/flags.go#L427-L429))
    - `flags.String(KeyCgroupRate, "", "Base sensor events cgroup rate ... disabled by default")` ([cilium/tetragon `pkg/option/flags.go#L494-L494`](https://github.com/cilium/tetragon/blob/main/pkg/option/flags.go#L494-L494))
  - The Helm chart also does not turn on extra args by default: `tetragon.extraArgs: {}` ([cilium/tetragon `install/kubernetes/tetragon/values.yaml#L38-L46`](https://github.com/cilium/tetragon/blob/main/install/kubernetes/tetragon/values.yaml#L38-L46)).
- Assessment:
  - The current 35 is not "too small compared with production default"; it is already larger than native default.
  - From the current baseline itself, the math is visible:
    - built-in base sensors: 8 programs
    - 1 injected tracepoint hook: 6 generic tracepoint programs
    - 3 injected kprobe hooks: 3 x 7 = 21 generic kprobe programs
    - total: 8 + 6 + 21 = 35
  - So the real issue is policy strategy, not discovery.
  - Hundreds are plausible only if we deliberately load many `TracingPolicy` hooks. The runner does not do that today.
- Estimated counts:
  - Native default, with no extra policy pack: about 8 loaded program objects.
  - Max benchmark-tuned: about 200+ if we replace the current synthetic pack with a real multi-policy pack. Using the current observed expansion ratio, 20 kprobes + 10 tracepoints would already be about `8 + 20*7 + 10*6 = 208`.

### 3. BCC

- Current config:
  - `e2e/cases/bcc/config.yaml:15-56` scopes the suite to 10 tools: `tcplife`, `biosnoop`, `runqlat`, `syscount`, `execsnoop`, `opensnoop`, `capable`, `vfsstat`, `tcpconnect`, `bindsnoop`.
  - `runner/libs/app_runners/bcc.py:212-233` loads that YAML.
  - `runner/libs/app_runners/bcc.py:428-486` launches each tool binary and uses the same global `bpftool` stable-set discovery as the other runners.
- Current actual loaded count:
  - 26 total program objects across the current 10-tool suite.
  - By tool:
    - `bcc/capable`: `cap_capable[kprobe]`
    - `bcc/execsnoop`: `do_ret_sys_execve[kprobe]`, `syscall__execve[kprobe]`
    - `bcc/bindsnoop`: `bindsnoop_entry[kprobe]`, `bindsnoop_v4_return[kprobe]`, `bindsnoop_v6_return[kprobe]`
    - `bcc/biosnoop`: `trace_pid_start_tp[tracepoint]`, `trace_req_completion_tp[tracepoint]`, `trace_req_start[kprobe]`
    - `bcc/vfsstat`: `kfunc__vmlinux__vfs_fsync_range[tracing]`, `vfs_create[tracing]`, `vfs_open[tracing]`, `vfs_read[tracing]`, `vfs_write[tracing]`
    - `bcc/opensnoop`: `__x64_sys_open[tracing]`, `kretfunc__vmlinux____x64_sys_openat[tracing]`, `kretfunc__vmlinux____x64_sys_openat2[tracing]`
    - `bcc/syscount`: `tracepoint__raw_syscalls__sys_enter[tracepoint]`, `tracepoint__raw_syscalls__sys_exit[tracepoint]`
    - `bcc/tcpconnect`: `trace_connect_entry[kprobe]`, `trace_connect_v4_return[kprobe]`, `trace_connect_v6_return[kprobe]`
    - `bcc/tcplife`: `tracepoint__sock__inet_sock_set_state[tracepoint]`
    - `bcc/runqlat`: `raw_tracepoint__sched_wakeup_new[raw_tracepoint]`, `sched_switch[raw_tracepoint]`, `sched_wakeup[raw_tracepoint]`
- Native production default for the current 10-tool suite:
  - `capable`: 1 program (`/usr/sbin/capable-bpfcc:159`)
  - `execsnoop`: 2 attach calls, 2 program objects (`/usr/sbin/execsnoop-bpfcc:244-245`)
  - `bindsnoop`: 4 attach calls, but only 3 program objects because the same `bindsnoop_entry` program is attached to both `inet_bind` and `inet6_bind` (`/usr/sbin/bindsnoop-bpfcc:469-472`)
  - `biosnoop`: current-kernel path is effectively 3 program objects (`/usr/sbin/biosnoop-bpfcc:335-350`)
  - `vfsstat`: 5 program objects on kfunc/kprobe path (`/usr/sbin/vfsstat-bpfcc:77-81`, `:107-111`)
  - `opensnoop`: 4-6 attach links depending kernel support, but fewer program objects because shared return handlers and current tracing mode collapse them (`/usr/sbin/opensnoop-bpfcc:387-397`)
  - `syscount`: 2 (`/usr/sbin/syscount-bpfcc:114`, `:147`)
  - `tcpconnect`: 4 attach links for TCP-only mode, but 3 program objects because `trace_connect_entry` is shared between v4/v6 (`/usr/sbin/tcpconnect-bpfcc:531-534`); DNS mode would add 3 more only if `-d` is enabled (`:535-538`)
  - `tcplife`: 1 active path on current kernels, tracepoint preferred over kprobe (`/usr/sbin/tcplife-bpfcc:376-379`)
  - `runqlat`: 3 raw tracepoints on modern kernels (`/usr/sbin/runqlat-bpfcc:189-203`)
- Assessment:
  - There is no large discovery miss here.
  - The main semantic trap is object count vs attach-link count.
  - For BCC, several tools intentionally attach one BPF program object to multiple hooks. `bpftool prog show` will still count one program object, not one link per attach site.
- Estimated counts:
  - Native default for the current 10-tool suite: about 26-27 program objects.
  - Max benchmark-tuned for the same 10 tools: about 30 if we deliberately enable richer tool flags such as `tcpconnect -d`.

### 4. bpftrace

- Current config:
  - The runner hardcodes 6 scripts in `runner/libs/app_runners/bpftrace.py:24-55`.
  - Startup is `bpftrace -q <script>` in `runner/libs/app_runners/bpftrace.py:133-170`.
- Current actual loaded count:
  - 10 total program objects across the current 6-script suite.
  - By script:
    - `bpftrace/capable`: `cap_capable[kprobe]`
    - `bpftrace/biosnoop`: `block_io_done[tracepoint]`, `block_io_start[tracepoint]`
    - `bpftrace/vfsstat`: `1[perf_event]`, `vfs_create[kprobe]`
    - `bpftrace/runqlat`: `sched_switch[tracepoint]`, `sched_wakeup[tracepoint]`, `tracepoint_sched_sched_wakeup_new[tracepoint]`
    - `bpftrace/tcplife`: `tcp_set_state[kprobe]`
    - `bpftrace/tcpretrans`: `kprobe_tcp_retransmit_skb[kprobe]`
- Native production default for the current 6-script suite:
  - `capable.bt`: 1 kprobe (`e2e/cases/bpftrace/scripts/capable.bt:72-78`)
  - `biosnoop.bt`: 2 tracepoints (`e2e/cases/bpftrace/scripts/biosnoop.bt:33-53`)
  - `runqlat.bt`: 3 tracepoints (`e2e/cases/bpftrace/scripts/runqlat.bt:44-66`)
  - `tcplife.bt`: 1 kprobe (`e2e/cases/bpftrace/scripts/tcplife.bt:47-104`)
  - `tcpretrans.bt`: 1 kprobe (`e2e/cases/bpftrace/scripts/tcpretrans.bt:64-90`)
  - `vfsstat.bt`: script comment says "Attaching 8 probes...", but the script only defines two BPF action blocks: one shared kprobe block for 5 VFS probes and one `interval:s:1` block (`e2e/cases/bpftrace/scripts/vfsstat.bt:10-12`, `:33-47`)
- Assessment:
  - There is no meaningful discovery miss here.
  - The apparent gap is again semantic: probe declarations or attach links are not the same thing as `bpftool` program objects.
  - `vfsstat.bt` is the clearest example: 5 VFS probe declarations plus one interval timer still become only 2 program objects in `baseline.programs`.
- Estimated counts:
  - Native default for the current 6-script suite: about 10 program objects.
  - Max benchmark-tuned for the same 6 scripts: about 10-12 program objects, depending on kernel lowering.

### 5. SCX

- Current config:
  - `runner/libs/app_runners/scx.py:313-331` defaults to scheduler `rusty`.
  - `e2e/cases/scx/case.py:561-566` launches `ScxRunner(... scheduler_extra_args=[], workload_spec={"name": "hackbench", ...})`.
  - `runner/libs/app_runners/scx.py:96-126` starts `scx_rusty --stats 1`.
- Current actual loaded count:
  - 13 `struct_ops` programs.
  - Programs: `rusty_dispatch`, `rusty_enqueue`, `rusty_exit`, `rusty_exit_task`, `rusty_init`, `rusty_init_task`, `rusty_quiescent`, `rusty_runnable`, `rusty_running`, `rusty_select_cpu`, `rusty_set_cpumask`, `rusty_set_weight`, `rusty_stopping`.
- Native production default:
  - `llvm-objdump -h corpus/build/x86_64/scx/scx_rusty_main.bpf.o` shows exactly 13 `struct_ops` sections for `rusty`.
- Assessment:
  - No under-count. Current 13 matches the object exactly.
  - If we want more programs, that is a different scheduler-selection question, not a discovery/config bug inside the current `rusty` case.
- Estimated counts:
  - Native default: 13.
  - Max benchmark-tuned inside the current `rusty` case: 13.

### 6. Katran

- Current config:
  - `e2e/cases/katran/case.py:110-116` fixes workload to `{"kind": "network"}`.
  - `runner/libs/app_runners/katran.py:437-438` starts `katran_server_grpc` with `-balancer_prog=... -intf=... -hc_forwarding=false`.
  - `runner/libs/app_runners/katran.py:690-705` never installs `xdp_root`; it only starts the server, optionally reattaches XDP generic, and configures maps.
- Current actual loaded count:
  - 1 program: `balancer_ingress[xdp]`.
- Native production default:
  - Upstream CLI defaults:
    - `healthchecker_prog="./healthchecking_ipip.o"`
    - `map_path=""`
    - `prog_pos=2`
    - `hc_forwarding=true`
    - see `runner/repos/katran/example_grpc/katran_server.cpp:43-59`
  - Those defaults flow into `KatranConfig.enableHc`, `rootMapPath`, and `rootMapPos` in `runner/repos/katran/example_grpc/katran_server.cpp:117-128`.
  - Load behavior is explicit in `runner/repos/katran/katran/lib/KatranLb.cpp:758-787`:
    - always load main balancer program
    - load healthchecking program if `config_.enableHc`
  - Katran standalone mode is the default; shared mode with root XDP requires a pinned root map (`runner/repos/katran/katran/lib/KatranLbStructs.h:169-182`, `runner/repos/katran/EXAMPLE.md:151-210`, `runner/repos/katran/USAGE.md:99-105`).
  - Object inventory:
    - `corpus/build/x86_64/katran/balancer.bpf.o` has one `xdp` section
    - `corpus/build/katran/healthchecking_ipip.bpf.o` has one `tc` section
    - `corpus/build/katran/xdp_root.bpf.o` has one `xdp` section
- Assessment:
  - The current runner is below upstream default because it explicitly disables healthchecking.
  - The current runner also never enters the shared/root mode that would add `xdp_root`.
  - The source does not support the assumption that `katran_server_grpc` automatically loads a large multi-program set such as `xdp_root + healthcheck + stats reader` in standalone mode. In the current source path, the guaranteed default programs are just balancer + optional healthchecking.
- Estimated counts:
  - Native default standalone mode: 2 programs (`balancer_ingress` + healthchecking).
  - Max benchmark-tuned shared mode: 3 programs (`xdp_root` + balancer + healthchecking).

## Part 2: Concrete Change Suggestions

### Tracee

- Goal: native-default-faithful.
  - Change `runner/libs/app_runners/tracee.py:437-441` so `--events` is omitted when the resolved event list is empty.
  - Then change `e2e/cases/tracee/config.yaml:1-5` from the hard-coded 4-event list to an empty/default mode.
- Goal: maximize attach count.
  - Change `e2e/cases/tracee/config.yaml:1-5` to a larger event set such as `all` or `tag=default`.
  - If the goal is "production default", prefer native default / `tag=default`.
  - If the goal is "maximize attach", prefer `all`.
- Optional safety margin.
  - If switching to `all`, also consider increasing `load_timeout_s` / startup settle because the attach burst will be larger, even though the current 2s stable-set wait is already correct.

### Tetragon

- Decide first which semantics you want:
  - native default: fewer programs, about 8
  - policy-pack mode: many more programs, 200+ is plausible
- Goal: native-default-faithful.
  - Stop injecting the temporary policies from `runner/libs/app_runners/tetragon.py:84-90`.
  - Stop forcing non-default `--cgroup-rate` from `runner/libs/app_runners/tetragon.py:216-218`.
  - Do not always append `--tracing-policy-dir <tempdir>` in `runner/libs/app_runners/tetragon.py:262-276`.
- Goal: maximize attach count.
  - Keep `--tracing-policy-dir`, but point it at a real directory of multiple `TracingPolicy` YAMLs instead of the current 1 tracepoint + 3 kprobe synthetic pack.
  - The simple planning rule from current evidence is:
    - each extra kprobe hook currently adds about 7 programs
    - each extra tracepoint hook currently adds about 6 programs

### Katran

- Goal: native-default-faithful.
  - Remove the forced `-hc_forwarding=false` from `runner/libs/app_runners/katran.py:437-438`.
- Goal: maximize attach count.
  - Install/use `xdp_root` first, then pass `-map_path` and `-prog_pos` so katran runs in shared mode.
  - This change point is `runner/libs/app_runners/katran.py:437-438` plus the topology/setup in `:690-705`.

### BCC

- No discovery fix is needed.
- If you want slightly higher counts, change tool flags instead of discovery:
  - example: enable `tcpconnect -d` to add the UDP/DNS helpers.
- If you want "attach link count" instead of "program object count", `baseline.programs` is the wrong metric. You would need a `bpftool link show`-style collector or tool-native introspection.

### bpftrace

- No discovery fix is needed.
- If you want more program objects than the current 10, the only reliable way is to split multi-probe scripts into more independent action blocks. That changes the script design, not the discovery layer.

### SCX

- No change recommended. Current count is already exact for `scx_rusty`.

## Part 3: Estimated Totals

### Current total

- `37 (tracee) + 35 (tetragon) + 26 (bcc) + 10 (bpftrace) + 13 (scx) + 1 (katran) = 122`

### Native-default-faithful total

- Tracee: about 70-100
- Tetragon: about 8
- BCC: about 26-27
- bpftrace: about 10
- SCX: 13
- Katran: 2
- Total: about 129-160

### Max benchmark-tuned total

- Assumptions:
  - Tracee uses `--events all`
  - Tetragon uses a real multi-policy pack roughly equivalent to 20 kprobes + 10 tracepoints
  - BCC enables a small number of richer flags but keeps the current 10-tool suite
  - bpftrace and SCX stay within current suite shape
  - Katran runs in shared mode with healthchecking enabled
- Estimate:
  - Tracee: about 120-154
  - Tetragon: about 208
  - BCC: about 30
  - bpftrace: about 10-12
  - SCX: 13
  - Katran: 3
  - Total: about 384-420

### Important caveat

- The Tetragon upper bound is policy-count dependent, not a hard binary ceiling. If we load a bigger `TracingPolicy` pack than the 20-kprobe + 10-tracepoint planning assumption above, Tetragon alone can exceed 208 and total attach count can go beyond 420.

## Part 4: Implementation Priority

1. Tracee
   The biggest real under-config issue. Smallest conceptual change. Most likely source of the user's "should be much larger" intuition.
2. Katran
   Small but clear gap versus upstream default. Also a simple fix: stop forcing `-hc_forwarding=false`, then optionally add shared-mode root XDP.
3. Tetragon
   Not a discovery bug. Needs a product decision first: do we want native default semantics (`~8`) or deliberately policy-heavy semantics (`200+`)?
4. BCC / bpftrace / SCX
   No discovery fix needed. Only revisit if we intentionally change the metric from "program objects" to "attach links", or if we broaden the suite itself.

## Bottom line

- The current `122` is not primarily caused by `bpftool diff` still missing programs.
- The real "too small versus source default" problems are `tracee` and `katran`.
- `tetragon` is the opposite: current `35` is already larger than native default, because the runner injects extra policies.
- `bcc` and `bpftrace` look "small" only if you mentally count attach links/probe declarations. `baseline.programs` is counting loaded BPF program objects, and for these two stacks that is the correct explanation for most of the apparent gap.
