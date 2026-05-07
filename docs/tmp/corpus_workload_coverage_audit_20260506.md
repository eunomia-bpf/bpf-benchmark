# Corpus Workload Coverage Audit - 2026-05-06

Scope: all 7 supported corpus apps. This audits workload coverage only; it does not compute performance ratios or summaries.

Run inputs:
- `corpus/results/x86_kvm_corpus_20260507_023000_475311/` (`noop,map_inline`, `SAMPLES=3`)
- `corpus/results/x86_kvm_corpus_20260507_025319_683029/` (kinsn-only, `SAMPLES=3`)

Method notes:
- Tables use the kinsn-only run for all apps with complete baseline/post data.
- Cilium is the exception: the kinsn-only app JSON contains no phase BPF records, while the noop+map_inline app JSON contains baseline records but no `post_rejit.bpf`. Cilium therefore has zero strict qualified programs in these latest runs.
- `qualified` means `min(baseline run_cnt_delta, post_rejit run_cnt_delta) >= 100`.
- Large zero-run programs (>5KB JIT) are treated as coverage gaps unless source/context shows they are optional selector/action tails. Tiny high-run programs (<500B) are called out as suspect dispatchers unless the app source/script shows they are complete tracing probe bodies.

Second-pass source/doc checks used: local runner/app source under `runner/libs/app_runners/`, Cilium BPF source under `runner/repos/cilium/bpf/`, Katran BPF source under `runner/repos/katran/katran/lib/bpf/`, Tetragon policies under `runner/assets/tetragon_policies/`, plus upstream docs linked in References.

## Cross-App Summary

| app | table source | total programs in table | qualified programs | baseline programs >=100 | heavy unqualified >5KB | tiny high-run <500B | verdict | workload fix |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- | --- |
| bcc/set | kinsn-only baseline+post | 21 | 20 | 20 | 0 | 14 | **GREEN** | None required for coverage; current stress_ng_os_io_network workload drives the selected BCC tools. |
| bpftrace/set | kinsn-only baseline+post | 9 | 8 | 8 | 0 | 4 | **GREEN** | None required for coverage; current stress_ng_os_io_network workload drives the selected scripts except the low-rate interval perf_event. |
| cilium/agent | noop+map_inline baseline-only | 60 | 0 | 6 | 24 | 1 | **YELLOW** | Fix the post-ReJIT stats/ID-disappearance failure first, then make the endpoint traffic matrix authoritative for both phases and add service/NodePort plus policy traffic so cil_lxc_policy and tail_nodeport/tail_ct paths run. |
| tetragon/observer | kinsn-only baseline+post | 287 | 30 | 30 | 117 | 0 | **YELLOW** | Add a short policy-aware trigger phase: repeated execs plus module-load/read-file events and targeted file/socket syscalls that match the loaded policies, so event_execve and generic_*_process_event paths reach >=100. |
| katran | kinsn-only baseline+post | 3 | 1 | 1 | 1 | 1 | **RED** | Known #177: send VIP traffic through Katran so xdp_root tail-calls balancer_ingress instead of only exercising the root dispatcher. |
| tracee/monitor | kinsn-only baseline+post | 158 | 78 | 78 | 61 | 15 | **YELLOW** | Add Tracee event-generator coverage for LKM/syscall-table/exec security paths, e.g. module load/unload or lsm-check plus repeated execve/execveat, while retaining the OS/IO/network stress. |
| otelcol-ebpf-profiler | kinsn-only baseline+post | 13 | 1 | 1 | 8 | 0 | **RED** | Run sustained native and interpreter CPU workloads after profiler metadata is ready, and fail if perf_unwind_native plus at least one interpreter unwinder stays at zero. |

## Action List

- Known separately: Katran #177 remains RED because `xdp_root` is qualified while `balancer_ingress` is 0/0.
- Additional workload fixes needed: `cilium/agent`, `tetragon/observer`, `tracee/monitor`, and `otelcol-ebpf-profiler`.
- No coverage fix required now for `bcc/set` or `bpftrace/set`; their selected script/tool hooks are exercised by the OS/IO/network stress workload.

## Verdict Key

- **GREEN**: qualified set is representative hot-path work for this app selection.
- **YELLOW**: qualified set is real but partial, or the latest run is invalid for strict qualification while baseline shows real hot paths.
- **RED**: qualified set is dispatcher/init/entry only, so the measurement is misleading.

## bcc/set

Coverage verdict: **GREEN**

Status/source: `ok` from `corpus/results/x86_kvm_corpus_20260507_025319_683029`. kinsn-only app JSON; noop+map_inline run has the same coverage shape.

A. Currently exercised: 20/21 program IDs are qualified. They are the expected BCC tools: capable, biosnoop, vfsstat, opensnoop, syscount, tcpconnect, tcplife, and runqlat hooks.

B. Hot-path but unqualified: Only trace_connect_v6_return is unqualified (0/0) because the workload is IPv4-only. It is not a hidden heavy program.

C. Representative or dispatcher-only? Qualified programs are real tracing hook bodies. Several are tiny (<500B), but for BCC these are the complete counter/update probes, not dispatchers.

Programs sorted by `bytes_jited` descending:

| prog_id | name | type | bytes_jited | baseline run_cnt_delta | post_rejit run_cnt_delta | qualified | judgment |
| ---: | --- | --- | ---: | ---: | ---: | --- | --- |
| 38 | `tracepoint__sock__inet_sock_set_state` | tracepoint | 1,067 | 2,244,265 | 1,900,189 | YES | HOT PATH - real tracing probe body |
| 27 | `sched_switch` | raw_tracepoint | 662 | 5,030,608 | 5,545,570 | YES | HOT PATH - real tracing probe body |
| 35 | `kretfunc__vmlinux____x64_sys_openat2` | tracing | 590 | 3,026 | 2,102 | YES | HOT PATH - real tracing probe body |
| 40 | `trace_req_completion_tp` | tracepoint | 550 | 243,923 | 218,025 | YES | HOT PATH - real tracing probe body |
| 32 | `__x64_sys_open` | tracing | 517 | 15,675 | 11,175 | YES | HOT PATH - real tracing probe body |
| 34 | `kretfunc__vmlinux____x64_sys_openat` | tracing | 517 | 5,006,078 | 5,453,296 | YES | HOT PATH - real tracing probe body |
| 23 | `trace_connect_v4_return` | kprobe | 480 | 208,749 | 182,988 | YES | HOT PATH - tiny but complete tracing probe |
| 24 | `trace_connect_v6_return` | kprobe | 477 | 0 | 0 | NO | COLD - IPv6 hook not hit by IPv4 workload |
| 39 | `trace_req_start` | kprobe | 335 | 241,859 | 216,304 | YES | HOT PATH - tiny but complete tracing probe |
| 33 | `trace_pid_start_tp` | tracepoint | 267 | 240,082 | 214,799 | YES | HOT PATH - tiny but complete tracing probe |
| 7 | `tracepoint__raw_syscalls__sys_exit` | tracepoint | 236 | 292,113,402 | 269,771,758 | YES | HOT PATH - tiny but complete tracing probe |
| 17 | `cap_capable` | kprobe | 203 | 13,733,391 | 11,978,706 | YES | HOT PATH - tiny but complete tracing probe |
| 29 | `raw_tracepoint__sched_wakeup_new` | raw_tracepoint | 149 | 90,013 | 80,585 | YES | HOT PATH - tiny but complete tracing probe |
| 28 | `sched_wakeup` | raw_tracepoint | 149 | 3,600,651 | 4,004,846 | YES | HOT PATH - tiny but complete tracing probe |
| 11 | `kfunc__vmlinux__vfs_fsync_range` | tracing | 90 | 39,674 | 37,897 | YES | HOT PATH - tiny but complete tracing probe |
| 10 | `vfs_create` | tracing | 90 | 357,156 | 282,840 | YES | HOT PATH - tiny but complete tracing probe |
| 12 | `vfs_open` | tracing | 90 | 6,745,321 | 7,019,983 | YES | HOT PATH - tiny but complete tracing probe |
| 14 | `vfs_write` | tracing | 90 | 2,988,187 | 3,866,173 | YES | HOT PATH - tiny but complete tracing probe |
| 13 | `vfs_read` | tracing | 87 | 10,324,490 | 10,850,455 | YES | HOT PATH - tiny but complete tracing probe |
| 22 | `trace_connect_entry` | kprobe | 75 | 208,749 | 182,988 | YES | HOT PATH - tiny but complete tracing probe |
| 6 | `tracepoint__raw_syscalls__sys_enter` | tracepoint | 72 | 292,112,877 | 269,771,282 | YES | HOT PATH - tiny but complete tracing probe |

## bpftrace/set

Coverage verdict: **GREEN**

Status/source: `ok` from `corpus/results/x86_kvm_corpus_20260507_025319_683029`. kinsn-only app JSON; noop+map_inline run has the same coverage shape.

A. Currently exercised: 8/9 program IDs are qualified: tcp_set_state, block_io_done/start, cap_capable, sched_switch, vfs_create, sched_wakeup, and sched_wakeup_new.

B. Hot-path but unqualified: The interval perf_event program has only 19/18 runs; it is a reporting timer, not the data-path work.

C. Representative or dispatcher-only? Qualified programs are the actual script hook bodies. The small scheduler/VFS probes are expected for bpftrace one-liners and are not loader stubs.

Programs sorted by `bytes_jited` descending:

| prog_id | name | type | bytes_jited | baseline run_cnt_delta | post_rejit run_cnt_delta | qualified | judgment |
| ---: | --- | --- | ---: | ---: | ---: | --- | --- |
| 740 | `tcp_set_state` | kprobe | 2,017 | 1,272,865 | 1,208,464 | YES | HOT PATH - real tracing probe body |
| 747 | `block_io_done` | tracepoint | 931 | 221,841 | 275,201 | YES | HOT PATH - real tracing probe body |
| 725 | `cap_capable` | kprobe | 769 | 14,900,338 | 17,479,064 | YES | HOT PATH - real tracing probe body |
| 734 | `sched_switch` | tracepoint | 515 | 6,592,795 | 5,737,195 | YES | HOT PATH - real tracing probe body |
| 718 | `1` | perf_event | 362 | 19 | 18 | NO | COLD/REPORTING TIMER - not data path |
| 746 | `block_io_start` | tracepoint | 222 | 229,697 | 279,214 | YES | HOT PATH - tiny but complete tracing probe |
| 719 | `vfs_create` | kprobe | 140 | 31,554,552 | 31,223,500 | YES | HOT PATH - tiny but complete tracing probe |
| 731 | `sched_wakeup` | tracepoint | 86 | 4,574,867 | 4,235,915 | YES | HOT PATH - tiny but complete tracing probe |
| 733 | `tracepoint_sched_sched_wakeup_new` | tracepoint | 86 | 129,182 | 99,984 | YES | HOT PATH - tiny but complete tracing probe |

## cilium/agent

Coverage verdict: **YELLOW**

Status/source: `error` from `corpus/results/x86_kvm_corpus_20260507_023000_475311`. Cilium table uses the noop+map_inline run because it is the only latest run with Cilium baseline BPF records. That run has no post_rejit BPF stats; the kinsn-only run has no phase records. Strict qualified count is therefore zero.
Error: `BPF stats missing requested program IDs: 171, 174, 176, 177, 183, 185, 186`

A. Currently exercised: Strictly none are qualified because post_rejit stats are missing. Baseline-only exercised >=100: cil_from_container (two IDs), cil_to_netdev, cil_from_netdev, cil_from_host, and cil_xdp_entry.

B. Hot-path but unqualified: all baseline-exercised datapath entries have missing post counts; heavy NodePort/CT/policy tails (tail_handle_snat_fwd_ipv4, tail_nodeport_nat_*, tail_ipv4_ct_*, cil_lxc_policy) are 0 in baseline because the workload does not create NodePort/service/policy conditions and post stats failed.

C. Representative or dispatcher-only? Baseline coverage is not just bpf_xdp/bpf_lxc/bpf_overlay loader health checks: it hits real per-packet datapath entries cil_from_container, cil_to_netdev, cil_from_netdev, and cil_from_host. cil_xdp_entry is a tiny XDP prefilter/dispatcher and should not be the only Cilium signal. No strict post-ReJIT measurement is valid in these runs.

D. Cilium-specific qualified names: Qualified progs with names: none under the required min(baseline, post)>=100 rule. Baseline-only hot names are cil_from_container, cil_to_netdev, cil_from_netdev, cil_from_host; cil_xdp_entry is the small XDP entry. Missing or unqualified: cil_to_overlay absent, cil_lxc_drop absent, cil_to_host only 2 runs, cil_lxc_policy 0, NodePort/CT tailcalls 0.

Programs sorted by `bytes_jited` descending:

| prog_id | name | type | bytes_jited | baseline run_cnt_delta | post_rejit run_cnt_delta | qualified | judgment |
| ---: | --- | --- | ---: | ---: | ---: | --- | --- |
| 180 | `tail_handle_snat_fwd_ipv4` | sched_cls | 12,653 | 0 | n/a | NO | HOT PATH UNQUAL - NodePort/NAT tail not driven |
| 189 | `tail_handle_snat_fwd_ipv4` | sched_cls | 12,653 | 0 | n/a | NO | HOT PATH UNQUAL - NodePort/NAT tail not driven |
| 169 | `tail_handle_snat_fwd_ipv4` | sched_cls | 12,622 | 0 | n/a | NO | HOT PATH UNQUAL - NodePort/NAT tail not driven |
| 205 | `cil_lxc_policy` | sched_cls | 11,128 | 0 | n/a | NO | HOT PATH UNQUAL - endpoint policy program not driven |
| 215 | `cil_lxc_policy` | sched_cls | 11,128 | 0 | n/a | NO | HOT PATH UNQUAL - endpoint policy program not driven |
| 166 | `tail_nodeport_nat_ingress_ipv4` | sched_cls | 8,699 | 0 | n/a | NO | HOT PATH UNQUAL - NodePort/NAT tail not driven |
| 182 | `tail_nodeport_nat_ingress_ipv4` | sched_cls | 8,699 | 0 | n/a | NO | HOT PATH UNQUAL - NodePort/NAT tail not driven |
| 194 | `tail_nodeport_nat_ingress_ipv4` | sched_cls | 8,699 | 0 | n/a | NO | HOT PATH UNQUAL - NodePort/NAT tail not driven |
| 181 | `tail_handle_ipv4_from_netdev` | sched_cls | 8,056 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 188 | `tail_handle_ipv4_from_netdev` | sched_cls | 8,056 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 170 | `tail_handle_ipv4_from_netdev` | sched_cls | 8,048 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 195 | `tail_handle_ipv4_cont` | sched_cls | 5,832 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 217 | `tail_handle_ipv4_cont` | sched_cls | 5,832 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 161 | `tail_nodeport_nat_egress_ipv4` | sched_cls | 5,818 | 0 | n/a | NO | HOT PATH UNQUAL - NodePort/NAT tail not driven |
| 173 | `tail_nodeport_nat_egress_ipv4` | sched_cls | 5,818 | 0 | n/a | NO | HOT PATH UNQUAL - NodePort/NAT tail not driven |
| 192 | `tail_nodeport_nat_egress_ipv4` | sched_cls | 5,818 | 0 | n/a | NO | HOT PATH UNQUAL - NodePort/NAT tail not driven |
| 198 | `tail_ipv4_to_endpoint` | sched_cls | 5,749 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 213 | `tail_ipv4_to_endpoint` | sched_cls | 5,749 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 202 | `tail_ipv4_ct_egress` | sched_cls | 5,424 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 219 | `tail_ipv4_ct_egress` | sched_cls | 5,424 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 206 | `tail_handle_ipv4` | sched_cls | 5,418 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 211 | `tail_handle_ipv4` | sched_cls | 5,418 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 200 | `tail_ipv4_ct_ingress` | sched_cls | 5,306 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 209 | `tail_ipv4_ct_ingress` | sched_cls | 5,306 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 171 | `cil_to_netdev` | sched_cls | 4,845 | 0 | n/a | NO | HOT PATH - real Cilium datapath entry; no valid post count |
| 193 | `cil_to_netdev` | sched_cls | 4,845 | 1,825,396 | n/a | NO | HOT PATH - real Cilium datapath entry; no valid post count |
| 203 | `tail_nodeport_rev_dnat_ipv4` | sched_cls | 3,605 | 0 | n/a | NO | HOT PATH UNQUAL - NodePort/NAT tail not driven |
| 214 | `tail_nodeport_rev_dnat_ipv4` | sched_cls | 3,605 | 0 | n/a | NO | HOT PATH UNQUAL - NodePort/NAT tail not driven |
| 165 | `cil_from_host` | sched_cls | 3,340 | 1,609,524 | n/a | NO | HOT PATH - real Cilium datapath entry; no valid post count |
| 174 | `cil_from_host` | sched_cls | 3,340 | 0 | n/a | NO | HOT PATH - real Cilium datapath entry; no valid post count |
| 185 | `cil_from_host` | sched_cls | 3,340 | 0 | n/a | NO | HOT PATH - real Cilium datapath entry; no valid post count |
| 177 | `cil_from_netdev` | sched_cls | 3,112 | 0 | n/a | NO | HOT PATH - real Cilium datapath entry; no valid post count |
| 187 | `cil_from_netdev` | sched_cls | 3,112 | 1,611,256 | n/a | NO | HOT PATH - real Cilium datapath entry; no valid post count |
| 175 | `tail_no_service_ipv4` | sched_cls | 2,792 | 0 | n/a | NO | COLD/UNCLASSIFIED Cilium path |
| 190 | `tail_no_service_ipv4` | sched_cls | 2,792 | 0 | n/a | NO | COLD/UNCLASSIFIED Cilium path |
| 207 | `tail_no_service_ipv4` | sched_cls | 2,774 | 0 | n/a | NO | COLD/UNCLASSIFIED Cilium path |
| 216 | `tail_no_service_ipv4` | sched_cls | 2,774 | 0 | n/a | NO | COLD/UNCLASSIFIED Cilium path |
| 168 | `tail_handle_ipv4_from_host` | sched_cls | 1,183 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 179 | `tail_handle_ipv4_from_host` | sched_cls | 1,183 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 184 | `tail_handle_ipv4_from_host` | sched_cls | 1,183 | 0 | n/a | NO | HOT PATH UNQUAL - IPv4 datapath tail not reached |
| 199 | `tail_handle_arp` | sched_cls | 927 | 0 | n/a | NO | COLD/ERROR-RARE path |
| 218 | `tail_handle_arp` | sched_cls | 927 | 0 | n/a | NO | COLD/ERROR-RARE path |
| 201 | `cil_from_container` | sched_cls | 908 | 4,020,722 | n/a | NO | HOT PATH - real Cilium datapath entry; no valid post count |
| 210 | `cil_from_container` | sched_cls | 908 | 2,430 | n/a | NO | HOT PATH - real Cilium datapath entry; no valid post count |
| 64 | `dump_bpf_prog` | tracing | 740 | 0 | n/a | NO | INIT/DEBUG tracing helper |
| 167 | `cil_to_host` | sched_cls | 526 | 2 | n/a | NO | HOT PATH - real Cilium datapath entry; no valid post count |
| 178 | `cil_to_host` | sched_cls | 526 | 2 | n/a | NO | HOT PATH - real Cilium datapath entry; no valid post count |
| 183 | `cil_to_host` | sched_cls | 526 | 0 | n/a | NO | HOT PATH - real Cilium datapath entry; no valid post count |
| 159 | `cil_xdp_entry` | xdp | 490 | 1,611,256 | n/a | NO | DISPATCHER/SUSPECT - tiny XDP prefilter entry; baseline hot, no post |
| 160 | `tail_drop_notify` | sched_cls | 364 | 0 | n/a | NO | COLD/ERROR-RARE path |
| 172 | `tail_drop_notify` | sched_cls | 364 | 0 | n/a | NO | COLD/ERROR-RARE path |
| 191 | `tail_drop_notify` | sched_cls | 364 | 0 | n/a | NO | COLD/ERROR-RARE path |
| 204 | `tail_drop_notify` | sched_cls | 330 | 0 | n/a | NO | COLD/ERROR-RARE path |
| 212 | `tail_drop_notify` | sched_cls | 330 | 0 | n/a | NO | COLD/ERROR-RARE path |
| 63 | `dump_bpf_map` | tracing | 167 | 0 | n/a | NO | INIT/DEBUG tracing helper |
| 163 | `cil_host_policy` | sched_cls | 16 | 0 | n/a | NO | COLD/DISABLED STUB |
| 176 | `cil_host_policy` | sched_cls | 16 | 0 | n/a | NO | COLD/DISABLED STUB |
| 186 | `cil_host_policy` | sched_cls | 16 | 0 | n/a | NO | COLD/DISABLED STUB |
| 197 | `cil_lxc_policy_egress` | sched_cls | 16 | 0 | n/a | NO | COLD/DISABLED STUB |
| 220 | `cil_lxc_policy_egress` | sched_cls | 16 | 0 | n/a | NO | COLD/DISABLED STUB |

## tetragon/observer

Coverage verdict: **YELLOW**

Status/source: `ok` from `corpus/results/x86_kvm_corpus_20260507_025319_683029`. kinsn-only app JSON; noop+map_inline run has the same 30-qualified-program shape.

A. Currently exercised: 30/287 program IDs are qualified: 20 generic_kprobe_event instances, 7 generic_retkprobe_event instances, generic_tracepoint_event, event_wake_up_new_task, and event_exit_acct_process.

B. Hot-path but unqualified: event_execve and tg_kp_bprm_committing_creds only see 4/4 runs; generic_kprobe_process_event/filter_arg/process_filter families are loaded many times and stay 0/0. The stress workload triggers generic kprobe/tracepoint hooks but not the process-enriched or module/exec-heavy policy paths enough.

C. Representative or dispatcher-only? Qualified set includes real Tetragon hook work (generic kprobe/retkprobe/tracepoint programs), but it is partial. The dormant 17KB process-event tail programs mean the workload misses a major Tetragon policy-output path.

Programs sorted by `bytes_jited` descending:

| prog_id | name | type | bytes_jited | baseline run_cnt_delta | post_rejit run_cnt_delta | qualified | judgment |
| ---: | --- | --- | ---: | ---: | ---: | --- | --- |
| 249 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 255 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 261 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 266 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 283 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 284 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 295 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 303 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 312 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 320 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 329 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 331 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 338 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 345 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 356 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 368 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 377 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 392 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 400 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 412 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 418 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 439 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 446 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 449 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 459 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 466 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 472 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 483 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 488 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 501 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 508 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 513 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 522 | `generic_kprobe_process_event` | kprobe | 17,149 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 428 | `generic_rawtp_process_event` | raw_tracepoint | 17,059 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 420 | `generic_tracepoint_process_event` | tracepoint | 14,876 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 276 | `generic_retkprobe_event` | kprobe | 14,043 | 139,626 | 217,362 | YES | HOT PATH - real Tetragon hook work |
| 298 | `generic_retkprobe_event` | kprobe | 14,043 | 139,626 | 217,362 | YES | HOT PATH - real Tetragon hook work |
| 352 | `generic_retkprobe_event` | kprobe | 14,043 | 8,121,383 | 7,839,888 | YES | HOT PATH - real Tetragon hook work |
| 363 | `generic_retkprobe_event` | kprobe | 14,043 | 924,753 | 914,511 | YES | HOT PATH - real Tetragon hook work |
| 373 | `generic_retkprobe_event` | kprobe | 14,043 | 129 | 106 | YES | HOT PATH - real Tetragon hook work |
| 386 | `generic_retkprobe_event` | kprobe | 14,043 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 398 | `generic_retkprobe_event` | kprobe | 14,043 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 464 | `generic_retkprobe_event` | kprobe | 14,043 | 139,626 | 217,362 | YES | HOT PATH - real Tetragon hook work |
| 496 | `generic_retkprobe_event` | kprobe | 14,043 | 47,270 | 56,694 | YES | HOT PATH - real Tetragon hook work |
| 239 | `event_execve` | tracepoint | 11,213 | 4 | 4 | NO | HOT PATH UNQUAL - exec/security lifecycle underdriven |
| 421 | `generic_tracepoint_filter` | tracepoint | 11,087 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 247 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 257 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 263 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 269 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 280 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 289 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 297 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 308 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 309 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 319 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 328 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 334 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 339 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 349 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 357 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 371 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 382 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 389 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 401 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 410 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 419 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 436 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 445 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 453 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 455 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 470 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 474 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 479 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 491 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 497 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 504 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 514 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 520 | `generic_kprobe_process_filter` | kprobe | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 426 | `generic_rawtp_process_filter` | raw_tracepoint | 11,080 | 0 | 0 | NO | HOT PATH UNQUAL - process-enriched policy path stayed 0 |
| 425 | `generic_tracepoint_event` | tracepoint | 10,899 | 116,287,408 | 115,091,146 | YES | HOT PATH - real Tetragon hook work |
| 251 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 258 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 259 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 272 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 277 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 286 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 291 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 306 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 314 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 316 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 324 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 332 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 340 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 347 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 361 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 372 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 378 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 391 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 402 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 407 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 413 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 434 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 441 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 451 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 456 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 471 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 476 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 480 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 492 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 498 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 509 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 515 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 521 | `generic_kprobe_filter_arg` | kprobe | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 431 | `generic_rawtp_filter_arg` | raw_tracepoint | 10,676 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 422 | `generic_tracepoint_arg` | tracepoint | 10,676 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 273 | `generic_retkprobe_filter_arg` | kprobe | 10,581 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 299 | `generic_retkprobe_filter_arg` | kprobe | 10,581 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 354 | `generic_retkprobe_filter_arg` | kprobe | 10,581 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 364 | `generic_retkprobe_filter_arg` | kprobe | 10,581 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 376 | `generic_retkprobe_filter_arg` | kprobe | 10,581 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 384 | `generic_retkprobe_filter_arg` | kprobe | 10,581 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 395 | `generic_retkprobe_filter_arg` | kprobe | 10,581 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 462 | `generic_retkprobe_filter_arg` | kprobe | 10,581 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 495 | `generic_retkprobe_filter_arg` | kprobe | 10,581 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 237 | `event_wake_up_new_task` | kprobe | 7,335 | 50,169 | 51,801 | YES | HOT PATH - real Tetragon hook work |
| 238 | `execve_send` | tracepoint | 4,992 | 0 | 0 | NO | COLD/LOW - exec tail not reached enough |
| 246 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 253 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 262 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 271 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 281 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 285 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 292 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 304 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 313 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 317 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 325 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 333 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 337 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 350 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 358 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 369 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 379 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 390 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 403 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 409 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 416 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 435 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 442 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 452 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 457 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 468 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 478 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 481 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 490 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 503 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 506 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 512 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 519 | `generic_kprobe_actions` | kprobe | 4,893 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 424 | `generic_tracepoint_actions` | tracepoint | 4,754 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 430 | `generic_rawtp_actions` | raw_tracepoint | 3,770 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 275 | `generic_retkprobe_actions` | kprobe | 3,770 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 300 | `generic_retkprobe_actions` | kprobe | 3,770 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 351 | `generic_retkprobe_actions` | kprobe | 3,770 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 362 | `generic_retkprobe_actions` | kprobe | 3,770 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 374 | `generic_retkprobe_actions` | kprobe | 3,770 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 387 | `generic_retkprobe_actions` | kprobe | 3,770 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 396 | `generic_retkprobe_actions` | kprobe | 3,770 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 463 | `generic_retkprobe_actions` | kprobe | 3,770 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 493 | `generic_retkprobe_actions` | kprobe | 3,770 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 248 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 252 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 260 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 270 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 278 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 288 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 293 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 307 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 311 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 321 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 323 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 336 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 341 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 346 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 355 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 366 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 380 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 393 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 404 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 408 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 414 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 438 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 444 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 448 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 460 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 465 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 477 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 484 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 486 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 502 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 510 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 516 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 518 | `generic_kprobe_output` | kprobe | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 427 | `generic_rawtp_output` | raw_tracepoint | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 423 | `generic_tracepoint_output` | tracepoint | 1,877 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 245 | `generic_kprobe_event` | kprobe | 1,722 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 256 | `generic_kprobe_event` | kprobe | 1,722 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 264 | `generic_kprobe_event` | kprobe | 1,722 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 267 | `generic_kprobe_event` | kprobe | 1,722 | 139,626 | 217,362 | YES | HOT PATH - real Tetragon hook work |
| 282 | `generic_kprobe_event` | kprobe | 1,722 | 168,415 | 242,297 | YES | HOT PATH - real Tetragon hook work |
| 290 | `generic_kprobe_event` | kprobe | 1,722 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 296 | `generic_kprobe_event` | kprobe | 1,722 | 139,626 | 217,362 | YES | HOT PATH - real Tetragon hook work |
| 305 | `generic_kprobe_event` | kprobe | 1,722 | 168,415 | 242,297 | YES | HOT PATH - real Tetragon hook work |
| 315 | `generic_kprobe_event` | kprobe | 1,722 | 2,004,403 | 1,776,612 | YES | HOT PATH - real Tetragon hook work |
| 318 | `generic_kprobe_event` | kprobe | 1,722 | 3,818,884 | 4,045,247 | YES | HOT PATH - real Tetragon hook work |
| 326 | `generic_kprobe_event` | kprobe | 1,722 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 335 | `generic_kprobe_event` | kprobe | 1,722 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 343 | `generic_kprobe_event` | kprobe | 1,722 | 3,853,784 | 3,584,522 | YES | HOT PATH - real Tetragon hook work |
| 348 | `generic_kprobe_event` | kprobe | 1,722 | 8,121,383 | 7,839,888 | YES | HOT PATH - real Tetragon hook work |
| 359 | `generic_kprobe_event` | kprobe | 1,722 | 924,753 | 914,511 | YES | HOT PATH - real Tetragon hook work |
| 370 | `generic_kprobe_event` | kprobe | 1,722 | 129 | 106 | YES | HOT PATH - real Tetragon hook work |
| 381 | `generic_kprobe_event` | kprobe | 1,722 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 394 | `generic_kprobe_event` | kprobe | 1,722 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 405 | `generic_kprobe_event` | kprobe | 1,722 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 411 | `generic_kprobe_event` | kprobe | 1,722 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 415 | `generic_kprobe_event` | kprobe | 1,722 | 4 | 4 | NO | COLD/UNTRIGGERED policy path |
| 437 | `generic_kprobe_event` | kprobe | 1,722 | 74,232 | 71,096 | YES | HOT PATH - real Tetragon hook work |
| 440 | `generic_kprobe_event` | kprobe | 1,722 | 129,397 | 146,382 | YES | HOT PATH - real Tetragon hook work |
| 450 | `generic_kprobe_event` | kprobe | 1,722 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 458 | `generic_kprobe_event` | kprobe | 1,722 | 139,626 | 217,362 | YES | HOT PATH - real Tetragon hook work |
| 467 | `generic_kprobe_event` | kprobe | 1,722 | 168,415 | 242,297 | YES | HOT PATH - real Tetragon hook work |
| 475 | `generic_kprobe_event` | kprobe | 1,722 | 373,745 | 447,739 | YES | HOT PATH - real Tetragon hook work |
| 482 | `generic_kprobe_event` | kprobe | 1,722 | 94,572 | 113,421 | YES | HOT PATH - real Tetragon hook work |
| 489 | `generic_kprobe_event` | kprobe | 1,722 | 47,270 | 56,694 | YES | HOT PATH - real Tetragon hook work |
| 499 | `generic_kprobe_event` | kprobe | 1,722 | 47,272 | 56,696 | YES | HOT PATH - real Tetragon hook work |
| 507 | `generic_kprobe_event` | kprobe | 1,722 | 94,572 | 113,421 | YES | HOT PATH - real Tetragon hook work |
| 511 | `generic_kprobe_event` | kprobe | 1,722 | 1,492,878 | 1,251,400 | YES | HOT PATH - real Tetragon hook work |
| 524 | `generic_kprobe_event` | kprobe | 1,722 | 0 | 0 | NO | COLD/UNTRIGGERED policy path |
| 429 | `generic_rawtp_event` | raw_tracepoint | 1,722 | 4 | 4 | NO | COLD/UNTRIGGERED policy path |
| 241 | `tg_kp_bprm_committing_creds` | kprobe | 1,533 | 4 | 4 | NO | HOT PATH UNQUAL - exec/security lifecycle underdriven |
| 240 | `execve_rate` | tracepoint | 1,381 | 0 | 0 | NO | COLD/LOW - exec tail not reached enough |
| 250 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 254 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 265 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 268 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 279 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 287 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 294 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 302 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 310 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 322 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 327 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 330 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 342 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 344 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 360 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 367 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 383 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 388 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 399 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 406 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 417 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 433 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 443 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 447 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 454 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 469 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 473 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 485 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 487 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 500 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 505 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 517 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 523 | `generic_kprobe_setup_event` | kprobe | 1,313 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 235 | `event_exit_acct_process` | kprobe | 1,012 | 15,329 | 16,018 | YES | HOT PATH - real Tetragon hook work |
| 274 | `generic_retkprobe_output` | kprobe | 799 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 301 | `generic_retkprobe_output` | kprobe | 799 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 353 | `generic_retkprobe_output` | kprobe | 799 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 365 | `generic_retkprobe_output` | kprobe | 799 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 375 | `generic_retkprobe_output` | kprobe | 799 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 385 | `generic_retkprobe_output` | kprobe | 799 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 397 | `generic_retkprobe_output` | kprobe | 799 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 461 | `generic_retkprobe_output` | kprobe | 799 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 494 | `generic_retkprobe_output` | kprobe | 799 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 432 | `generic_rawtp_setup_event` | raw_tracepoint | 741 | 0 | 0 | NO | COLD TAIL - selector/action/output tail not reached |
| 242 | `execve_map_update` | socket_filter | 303 | 0 | 0 | NO | COLD/LOW - exec tail not reached enough |

## katran

Coverage verdict: **RED**

Status/source: `ok` from `corpus/results/x86_kvm_corpus_20260507_025319_683029`. kinsn-only app JSON; noop+map_inline run has the same dispatcher-only shape.

A. Currently exercised: Only xdp_root is qualified.

B. Hot-path but unqualified: balancer_ingress is the 13.6KB real XDP load balancer and remains 0/0. healthcheck_encap sees only 1/1.

C. Representative or dispatcher-only? The qualified program is a 176B XDP root dispatcher. This is the exact misleading coverage shape: the workload never reaches the heavy load-balancing program.

Programs sorted by `bytes_jited` descending:

| prog_id | name | type | bytes_jited | baseline run_cnt_delta | post_rejit run_cnt_delta | qualified | judgment |
| ---: | --- | --- | ---: | ---: | ---: | --- | --- |
| 537 | `balancer_ingress` | xdp | 13,629 | 0 | 0 | NO | HOT PATH UNQUAL - real L4 balancer bypassed |
| 539 | `healthcheck_encap` | sched_cls | 541 | 1 | 1 | NO | COLD/LOW - health-check path barely hit |
| 531 | `xdp_root` | xdp | 176 | 327,649 | 323,215 | YES | DISPATCHER - tiny XDP root, qualified but misleading |

## tracee/monitor

Coverage verdict: **YELLOW**

Status/source: `ok` from `corpus/results/x86_kvm_corpus_20260507_025319_683029`. kinsn-only app JSON; noop+map_inline run has the same 78-qualified-program shape.

A. Currently exercised: 78/158 program IDs are qualified, including heavy LSM/file/network programs such as trace_security_task_prctl, trace_security_mmap_file, trace_security_file_mprotect, trace_security_file_open, cgroup_skb_ingress/egress, trace_ret_vfs_read/write, and raw syscall entry/exit.

B. Hot-path but unqualified: lkm_seeker_* and uprobe_syscall_table_check are 0/0; security_bprm_check and exec-finished/test programs see only 4/4; several writev/readv/kernel_write tails are zero or just above 200. Generic OS/IO/network stress does not load modules, patch syscalls, or generate enough exec/security-bprm events.

C. Representative or dispatcher-only? Qualified set is real heavy Tracee monitoring work, not just dispatchers. Coverage is still partial because several large security-detection programs are dormant.

Programs sorted by `bytes_jited` descending:

| prog_id | name | type | bytes_jited | baseline run_cnt_delta | post_rejit run_cnt_delta | qualified | judgment |
| ---: | --- | --- | ---: | ---: | ---: | --- | --- |
| 583 | `lkm_seeker_kset_tail` | kprobe | 62,309 | 0 | 0 | NO | HOT PATH UNQUAL - security detector not triggered |
| 580 | `lkm_seeker_modtree_loop` | kprobe | 59,266 | 0 | 0 | NO | HOT PATH UNQUAL - security detector not triggered |
| 710 | `tracepoint__exec_test` | raw_tracepoint | 58,693 | 4 | 4 | NO | HOT PATH UNQUAL - event class underdriven |
| 585 | `lkm_seeker_proc_tail` | kprobe | 57,791 | 0 | 0 | NO | HOT PATH UNQUAL - security detector not triggered |
| 596 | `uprobe_syscall_table_check` | kprobe | 56,303 | 0 | 0 | NO | HOT PATH UNQUAL - security detector not triggered |
| 695 | `trace_security_task_prctl` | kprobe | 47,182 | 781,334 | 772,857 | YES | HOT PATH - real Tracee monitor hook |
| 647 | `trace_security_mmap_file` | kprobe | 36,984 | 1,861,854 | 1,891,715 | YES | HOT PATH - real Tracee monitor hook |
| 648 | `trace_security_file_mprotect` | kprobe | 34,612 | 8,245,201 | 6,991,775 | YES | HOT PATH - real Tracee monitor hook |
| 604 | `trace_security_bprm_check` | kprobe | 33,399 | 4 | 4 | NO | HOT PATH UNQUAL - event class underdriven |
| 637 | `trace_ret_kernel_write_tail` | kprobe | 29,921 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 627 | `trace_ret_vfs_write_tail` | kprobe | 29,921 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 632 | `trace_ret_vfs_writev_tail` | kprobe | 29,845 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 631 | `vfs_writev_magic_return` | kprobe | 24,540 | 236 | 257 | YES | HOT PATH - real Tracee monitor hook |
| 689 | `trace_execute_finished` | kprobe | 24,495 | 4 | 4 | NO | HOT PATH UNQUAL - event class underdriven |
| 588 | `sched_process_exec_event_submit_tail` | raw_tracepoint | 24,434 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 636 | `kernel_write_magic_return` | kprobe | 23,804 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 626 | `vfs_write_magic_return` | kprobe | 23,804 | 574,928 | 852,555 | YES | HOT PATH - real Tracee monitor hook |
| 594 | `trace_call_usermodehelper` | kprobe | 23,523 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 605 | `trace_security_file_open` | kprobe | 22,985 | 2,868,521 | 2,983,688 | YES | HOT PATH - real Tracee monitor hook |
| 576 | `syscall__execveat_enter` | raw_tracepoint | 20,997 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 577 | `syscall__execveat_exit` | raw_tracepoint | 20,965 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 644 | `trace_mmap_alert` | kprobe | 20,742 | 2,358,702 | 2,128,736 | YES | HOT PATH - real Tracee monitor hook |
| 574 | `syscall__execve_enter` | raw_tracepoint | 20,734 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 575 | `syscall__execve_exit` | raw_tracepoint | 20,705 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 587 | `tracepoint__sched__sched_process_exec` | raw_tracepoint | 20,556 | 4 | 4 | NO | HOT PATH UNQUAL - event class underdriven |
| 683 | `trace_ret_file_modified` | kprobe | 20,180 | 632,203 | 725,656 | YES | HOT PATH - real Tracee monitor hook |
| 681 | `trace_ret_file_update_time` | kprobe | 20,045 | 93,628 | 109,019 | YES | HOT PATH - real Tracee monitor hook |
| 664 | `tracepoint__module__module_load` | raw_tracepoint | 19,884 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 579 | `tracepoint__sched__sched_process_fork` | raw_tracepoint | 19,722 | 47,180 | 48,494 | YES | HOT PATH - real Tracee monitor hook |
| 706 | `cgroup_skb_egress` | cgroup_skb | 19,660 | 4,622,981 | 4,387,489 | YES | HOT PATH - real Tracee monitor hook |
| 705 | `cgroup_skb_ingress` | cgroup_skb | 19,660 | 2,162,068 | 2,247,631 | YES | HOT PATH - real Tracee monitor hook |
| 646 | `trace_ret_do_mmap` | kprobe | 19,582 | 1,861,866 | 1,891,727 | YES | HOT PATH - real Tracee monitor hook |
| 635 | `trace_ret_kernel_write` | kprobe | 19,142 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 639 | `trace_ret_vfs_read` | kprobe | 19,142 | 3,091,130 | 3,931,479 | YES | HOT PATH - real Tracee monitor hook |
| 625 | `trace_ret_vfs_write` | kprobe | 19,139 | 574,928 | 852,555 | YES | HOT PATH - real Tracee monitor hook |
| 642 | `trace_ret_vfs_readv` | kprobe | 19,138 | 236 | 257 | YES | HOT PATH - real Tracee monitor hook |
| 630 | `trace_ret_vfs_writev` | kprobe | 19,138 | 236 | 257 | YES | HOT PATH - real Tracee monitor hook |
| 606 | `trace_security_sb_mount` | kprobe | 18,653 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 658 | `trace_security_kernel_read_file` | kprobe | 18,650 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 676 | `trace_utimes_common` | kprobe | 18,577 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 675 | `trace_vfs_utimes` | kprobe | 18,577 | 490,979 | 637,732 | YES | HOT PATH - real Tracee monitor hook |
| 668 | `trace_load_elf_phdrs` | kprobe | 18,493 | 8 | 8 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 690 | `trace_security_path_notify` | kprobe | 18,408 | 702 | 945 | YES | HOT PATH - real Tracee monitor hook |
| 691 | `trace_set_fs_pwd` | kprobe | 18,267 | 66,662 | 121,942 | YES | HOT PATH - real Tracee monitor hook |
| 685 | `trace_ret_inotify_find_inode` | kprobe | 18,061 | 702 | 945 | YES | HOT PATH - real Tracee monitor hook |
| 643 | `trace_ret_vfs_readv_tail` | kprobe | 17,892 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 694 | `trace_chmod_common` | kprobe | 17,596 | 193,894 | 162,288 | YES | HOT PATH - real Tracee monitor hook |
| 556 | `sys_enter_submit` | raw_tracepoint | 17,446 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 659 | `trace_security_kernel_post_read_file` | kprobe | 17,285 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 640 | `trace_ret_vfs_read_tail` | kprobe | 17,164 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 678 | `trace_fd_install` | kprobe | 17,005 | 2,840,996 | 2,970,649 | YES | HOT PATH - real Tracee monitor hook |
| 679 | `trace_filp_close` | kprobe | 16,933 | 587,218 | 546,894 | YES | HOT PATH - real Tracee monitor hook |
| 688 | `trace_security_bprm_creds_for_exec` | kprobe | 16,714 | 4 | 4 | NO | HOT PATH UNQUAL - event class underdriven |
| 687 | `trace_exec_binprm` | kprobe | 16,503 | 4 | 4 | NO | HOT PATH UNQUAL - event class underdriven |
| 650 | `trace_security_bpf` | kprobe | 15,620 | 7,386 | 7,386 | YES | HOT PATH - real Tracee monitor hook |
| 696 | `syscall_checker` | kprobe | 14,930 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 667 | `trace_ret_do_init_module` | kprobe | 14,587 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 686 | `process_execute_failed_tail` | kprobe | 12,887 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 578 | `sys_dup_exit_tail` | kprobe | 12,292 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 559 | `sys_exit_submit` | raw_tracepoint | 11,583 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 599 | `trace_security_file_ioctl` | kprobe | 11,476 | 9,788,165 | 7,420,515 | YES | HOT PATH - real Tracee monitor hook |
| 618 | `trace_security_socket_accept` | kprobe | 11,320 | 113,907 | 112,410 | YES | HOT PATH - real Tracee monitor hook |
| 567 | `trace_ret_arch_prctl` | kprobe | 11,319 | 2,208,152 | 2,182,641 | YES | HOT PATH - real Tracee monitor hook |
| 569 | `trace_ret_dup` | kprobe | 11,319 | 5,927 | 6,003 | YES | HOT PATH - real Tracee monitor hook |
| 571 | `trace_ret_dup2` | kprobe | 11,319 | 7,902 | 7,833 | YES | HOT PATH - real Tracee monitor hook |
| 573 | `trace_ret_dup3` | kprobe | 11,319 | 8,384 | 8,241 | YES | HOT PATH - real Tracee monitor hook |
| 565 | `trace_ret_process_vm_writev` | kprobe | 11,319 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 563 | `trace_ret_ptrace` | kprobe | 11,319 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 620 | `trace_security_socket_setsockopt` | kprobe | 11,072 | 418,777 | 657,565 | YES | HOT PATH - real Tracee monitor hook |
| 616 | `trace_security_socket_listen` | kprobe | 10,837 | 60 | 60 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 608 | `trace_commit_creds` | kprobe | 10,745 | 415,364 | 566,898 | YES | HOT PATH - real Tracee monitor hook |
| 619 | `trace_security_socket_bind` | kprobe | 10,606 | 72 | 72 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 617 | `trace_security_socket_connect` | kprobe | 10,093 | 114,458 | 114,377 | YES | HOT PATH - real Tracee monitor hook |
| 674 | `trace_do_sigaction` | kprobe | 10,070 | 21,649 | 21,428 | YES | HOT PATH - real Tracee monitor hook |
| 609 | `trace_switch_task_namespaces` | kprobe | 10,034 | 47,367 | 48,643 | YES | HOT PATH - real Tracee monitor hook |
| 607 | `trace_security_inode_unlink` | kprobe | 9,997 | 578,488 | 668,152 | YES | HOT PATH - real Tracee monitor hook |
| 671 | `trace_security_inode_rename` | kprobe | 9,837 | 158,034 | 151,490 | YES | HOT PATH - real Tracee monitor hook |
| 600 | `trace_tracepoint_probe_register_prio_may_exist` | kprobe | 9,747 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 654 | `trace_security_bpf_prog` | kprobe | 9,601 | 161 | 161 | YES | HOT PATH - real Tracee monitor hook |
| 677 | `trace_do_truncate` | kprobe | 9,550 | 11,798 | 13,984 | YES | HOT PATH - real Tracee monitor hook |
| 614 | `trace_debugfs_create_file` | kprobe | 9,523 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 697 | `trace_security_sb_umount` | kprobe | 9,521 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 660 | `trace_security_inode_mknod` | kprobe | 9,251 | 3,916 | 3,984 | YES | HOT PATH - real Tracee monitor hook |
| 615 | `trace_debugfs_create_dir` | kprobe | 9,235 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 612 | `trace_security_inode_symlink` | kprobe | 9,217 | 62,948 | 82,084 | YES | HOT PATH - real Tracee monitor hook |
| 591 | `syscall__accept4` | raw_tracepoint | 9,155 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 665 | `tracepoint__module__module_free` | raw_tracepoint | 9,004 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 592 | `tracepoint__sched__sched_switch` | raw_tracepoint | 8,945 | 2,079,534 | 2,718,710 | YES | HOT PATH - real Tracee monitor hook |
| 701 | `trace_security_socket_recvmsg` | kprobe | 8,895 | 1,646,718 | 1,562,801 | YES | HOT PATH - real Tracee monitor hook |
| 702 | `trace_security_socket_sendmsg` | kprobe | 8,895 | 4,702,851 | 4,476,512 | YES | HOT PATH - real Tracee monitor hook |
| 663 | `trace_ret__register_chrdev` | kprobe | 8,828 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 652 | `trace_ret_register_kprobe` | kprobe | 8,826 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 669 | `trace_security_file_permission` | kprobe | 8,719 | 6,033,930 | 7,352,354 | YES | HOT PATH - real Tracee monitor hook |
| 589 | `tracepoint__sched__sched_process_exit` | raw_tracepoint | 8,700 | 47,367 | 48,643 | YES | HOT PATH - real Tracee monitor hook |
| 661 | `trace_device_add` | kprobe | 8,685 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 693 | `trace_security_settime64` | kprobe | 8,670 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 601 | `tracepoint__cgroup__cgroup_attach_task` | raw_tracepoint | 8,649 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 699 | `trace_ret_sock_alloc_file` | kprobe | 8,648 | 292,799 | 412,237 | YES | HOT PATH - real Tracee monitor hook |
| 692 | `trace_security_task_setrlimit` | kprobe | 8,645 | 775,830 | 1,018,716 | YES | HOT PATH - real Tracee monitor hook |
| 602 | `tracepoint__cgroup__cgroup_mkdir` | raw_tracepoint | 8,624 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 603 | `tracepoint__cgroup__cgroup_rmdir` | raw_tracepoint | 8,624 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 670 | `tracepoint__task__task_rename` | raw_tracepoint | 8,512 | 13,079 | 12,979 | YES | HOT PATH - real Tracee monitor hook |
| 611 | `trace_security_socket_create` | kprobe | 8,478 | 178,933 | 299,867 | YES | HOT PATH - real Tracee monitor hook |
| 673 | `trace_ret_kallsyms_lookup_name` | kprobe | 8,431 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 653 | `trace_security_bpf_map` | kprobe | 8,362 | 2,608 | 2,608 | YES | HOT PATH - real Tracee monitor hook |
| 613 | `trace_proc_create` | kprobe | 8,301 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 593 | `trace_filldir64` | kprobe | 8,201 | 4,409,701 | 3,493,498 | YES | HOT PATH - real Tracee monitor hook |
| 610 | `trace_cap_capable` | kprobe | 8,199 | 6,651,194 | 6,664,602 | YES | HOT PATH - real Tracee monitor hook |
| 561 | `trace_sys_exit` | raw_tracepoint | 8,189 | 103,972,116 | 101,684,345 | YES | HOT PATH - real Tracee monitor hook |
| 560 | `trace_sys_enter` | raw_tracepoint | 8,156 | 103,971,558 | 101,683,841 | YES | HOT PATH - real Tracee monitor hook |
| 595 | `trace_do_exit` | kprobe | 7,959 | 47,367 | 48,643 | YES | HOT PATH - real Tracee monitor hook |
| 711 | `lsm_file_open_test` | lsm | 7,328 | 2,868,521 | 2,983,688 | YES | HOT PATH - real Tracee monitor hook |
| 597 | `uprobe_seq_ops_trigger` | kprobe | 6,788 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 657 | `trace_check_helper_call` | kprobe | 6,618 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 656 | `trace_check_map_func_compatibility` | kprobe | 6,612 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 598 | `uprobe_mem_dump_trigger` | kprobe | 6,553 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 655 | `trace_bpf_check` | kprobe | 6,376 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 581 | `uprobe_lkm_seeker_submitter` | kprobe | 6,232 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 703 | `cgroup_bpf_run_filter_skb` | kprobe | 5,668 | 6,980,724 | 6,843,802 | YES | HOT PATH - real Tracee monitor hook |
| 712 | `uprobe__features_fallback_arena` | kprobe | 5,384 | 0 | 0 | NO | HOT PATH UNQUAL - heavy Tracee path dormant |
| 582 | `uprobe_lkm_seeker` | kprobe | 4,339 | 0 | 0 | NO | COLD/LOW - not enough matching events |
| 586 | `lkm_seeker_new_mod_only_tail` | kprobe | 3,889 | 0 | 0 | NO | HOT PATH UNQUAL - security detector not triggered |
| 555 | `sys_enter_init` | raw_tracepoint | 2,513 | 0 | 0 | NO | COLD/LOW - not enough matching events |
| 566 | `trace_arch_prctl` | kprobe | 2,356 | 2,208,152 | 2,182,641 | YES | HOT PATH - real Tracee monitor hook |
| 568 | `trace_dup` | kprobe | 2,356 | 5,927 | 6,003 | YES | HOT PATH - real Tracee monitor hook |
| 570 | `trace_dup2` | kprobe | 2,356 | 7,902 | 7,833 | YES | HOT PATH - real Tracee monitor hook |
| 572 | `trace_dup3` | kprobe | 2,356 | 8,384 | 8,241 | YES | HOT PATH - real Tracee monitor hook |
| 564 | `trace_process_vm_writev` | kprobe | 2,356 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 562 | `trace_ptrace` | kprobe | 2,356 | 0 | 0 | NO | COLD/LOW - not enough matching events |
| 558 | `sys_exit_init` | raw_tracepoint | 2,093 | 0 | 0 | NO | COLD/LOW - not enough matching events |
| 621 | `send_bin` | kprobe | 949 | 0 | 0 | NO | COLD/LOW - not enough matching events |
| 622 | `send_bin_tp` | raw_tracepoint | 949 | 0 | 0 | NO | COLD/LOW - not enough matching events |
| 707 | `cgroup_mkdir_signal` | raw_tracepoint | 928 | 0 | 0 | NO | COLD/LOW - not enough matching events |
| 708 | `cgroup_rmdir_signal` | raw_tracepoint | 910 | 0 | 0 | NO | COLD/LOW - not enough matching events |
| 584 | `lkm_seeker_mod_tree_tail` | kprobe | 652 | 0 | 0 | NO | HOT PATH UNQUAL - security detector not triggered |
| 649 | `syscall__init_module` | raw_tracepoint | 622 | 0 | 0 | NO | COLD/LOW - not enough matching events |
| 682 | `trace_file_modified` | kprobe | 483 | 632,195 | 725,667 | YES | HOT DISPATCH/ENTRY - tiny but paired with heavy Tracee handlers |
| 680 | `trace_file_update_time` | kprobe | 469 | 93,628 | 109,019 | YES | HOT DISPATCH/ENTRY - tiny but paired with heavy Tracee handlers |
| 700 | `trace_security_sk_clone` | kprobe | 344 | 110,176 | 109,307 | YES | HOT DISPATCH/ENTRY - tiny but paired with heavy Tracee handlers |
| 698 | `trace_sock_alloc_file` | kprobe | 331 | 292,799 | 412,237 | YES | HOT DISPATCH/ENTRY - tiny but paired with heavy Tracee handlers |
| 634 | `kernel_write_magic_enter` | kprobe | 279 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 624 | `vfs_write_magic_enter` | kprobe | 279 | 574,928 | 852,555 | YES | HOT PATH - real Tracee monitor hook |
| 629 | `vfs_writev_magic_enter` | kprobe | 279 | 236 | 257 | YES | HOT PATH - real Tracee monitor hook |
| 557 | `tracepoint__raw_syscalls__sys_exit` | raw_tracepoint | 263 | 103,972,116 | 101,684,345 | YES | HOT DISPATCH/ENTRY - tiny but paired with heavy Tracee handlers |
| 590 | `tracepoint__sched__sched_process_free` | raw_tracepoint | 248 | 47,305 | 48,789 | YES | HOT PATH - real Tracee monitor hook |
| 554 | `tracepoint__raw_syscalls__sys_enter` | raw_tracepoint | 234 | 103,971,558 | 101,683,841 | YES | HOT DISPATCH/ENTRY - tiny but paired with heavy Tracee handlers |
| 662 | `trace___register_chrdev` | kprobe | 152 | 0 | 0 | NO | COLD/LOW - not enough matching events |
| 666 | `trace_do_init_module` | kprobe | 152 | 0 | 0 | NO | COLD/LOW - not enough matching events |
| 645 | `trace_do_mmap` | kprobe | 152 | 1,861,866 | 1,891,727 | YES | HOT DISPATCH/ENTRY - tiny but paired with heavy Tracee handlers |
| 684 | `trace_inotify_find_inode` | kprobe | 152 | 702 | 945 | YES | HOT DISPATCH/ENTRY - tiny but paired with heavy Tracee handlers |
| 672 | `trace_kallsyms_lookup_name` | kprobe | 152 | 0 | 0 | NO | COLD/LOW - not enough matching events |
| 633 | `trace_kernel_write` | kprobe | 152 | 0 | 0 | NO | HOT PATH UNQUAL - event class underdriven |
| 651 | `trace_register_kprobe` | kprobe | 152 | 0 | 0 | NO | COLD/LOW - not enough matching events |
| 638 | `trace_vfs_read` | kprobe | 152 | 3,091,131 | 3,931,479 | YES | HOT DISPATCH/ENTRY - tiny but paired with heavy Tracee handlers |
| 641 | `trace_vfs_readv` | kprobe | 152 | 236 | 257 | YES | HOT DISPATCH/ENTRY - tiny but paired with heavy Tracee handlers |
| 623 | `trace_vfs_write` | kprobe | 152 | 574,928 | 852,555 | YES | HOT DISPATCH/ENTRY - tiny but paired with heavy Tracee handlers |
| 628 | `trace_vfs_writev` | kprobe | 152 | 236 | 257 | YES | HOT DISPATCH/ENTRY - tiny but paired with heavy Tracee handlers |
| 709 | `empty_kprobe` | kprobe | 16 | 4 | 4 | NO | COLD/LOW - not enough matching events |

## otelcol-ebpf-profiler

Coverage verdict: **RED**

Status/source: `ok` from `corpus/results/x86_kvm_corpus_20260507_025319_683029`. kinsn-only app JSON; noop+map_inline run has the same native-entry-only shape.

A. Currently exercised: Only native_tracer_entry is qualified.

B. Hot-path but unqualified: perf_unwind_native, perf_unwind_dotnet, perf_unwind_v8, perf_unwind_python, perf_unwind_hotspot, perf_unwind_perl, perf_unwind_ruby, and perf_unwind_php are all 0/0 despite 15KB-22KB JIT sizes.

C. Representative or dispatcher-only? The qualified set is the profiler entry path, while the heavy real unwinders are bypassed. This is misleading for a cross-language profiler measurement.

Programs sorted by `bytes_jited` descending:

| prog_id | name | type | bytes_jited | baseline run_cnt_delta | post_rejit run_cnt_delta | qualified | judgment |
| ---: | --- | --- | ---: | ---: | ---: | --- | --- |
| 44 | `perf_unwind_native` | perf_event | 22,575 | 0 | 0 | NO | HOT PATH UNQUAL - real unwinder stayed 0 |
| 51 | `perf_unwind_dotnet` | perf_event | 22,565 | 0 | 0 | NO | HOT PATH UNQUAL - real unwinder stayed 0 |
| 50 | `perf_unwind_v8` | perf_event | 20,050 | 0 | 0 | NO | HOT PATH UNQUAL - real unwinder stayed 0 |
| 48 | `perf_unwind_python` | perf_event | 19,909 | 0 | 0 | NO | HOT PATH UNQUAL - real unwinder stayed 0 |
| 45 | `perf_unwind_hotspot` | perf_event | 18,290 | 0 | 0 | NO | HOT PATH UNQUAL - real unwinder stayed 0 |
| 46 | `perf_unwind_perl` | perf_event | 17,737 | 0 | 0 | NO | HOT PATH UNQUAL - real unwinder stayed 0 |
| 49 | `perf_unwind_ruby` | perf_event | 16,540 | 0 | 0 | NO | HOT PATH UNQUAL - real unwinder stayed 0 |
| 47 | `perf_unwind_php` | perf_event | 15,178 | 0 | 0 | NO | HOT PATH UNQUAL - real unwinder stayed 0 |
| 43 | `perf_unwind_stop` | perf_event | 3,721 | 0 | 0 | NO | HOT PATH UNQUAL - real unwinder stayed 0 |
| 55 | `native_tracer_entry` | perf_event | 3,532 | 23,839 | 23,885 | YES | HOT ENTRY - qualified, but only profiler entry |
| 52 | `perf_go_labels` | perf_event | 1,580 | 0 | 0 | NO | COLD/INIT - not reached |
| 54 | `tracepoint__sched_process_free` | tracepoint | 788 | 16 | 16 | NO | COLD/INIT - not reached |
| 53 | `perf_unwind_beam` | perf_event | 696 | 0 | 0 | NO | HOT PATH UNQUAL - real unwinder stayed 0 |

## References

- Cilium eBPF datapath docs, Life of a Packet: https://docs.cilium.io/en/latest/network/ebpf/lifeofapacket/
- Tetragon overview and tracing-policy docs: https://tetragon.io/docs/overview/ and https://tetragon.io/docs/concepts/tracing-policy/
- Tracee `security_bprm_check` event docs: https://aquasecurity.github.io/tracee/v0.19/docs/events/builtin/extra/security_bprm_check/
- OpenTelemetry eBPF profiler README: https://github.com/open-telemetry/opentelemetry-ebpf-profiler
- Katran README: https://github.com/facebookincubator/katran
- Local source cross-checks: `runner/repos/cilium/bpf/bpf_host.c`, `runner/repos/cilium/bpf/bpf_lxc.c`, `runner/repos/cilium/bpf/bpf_xdp.c`, `runner/repos/katran/katran/lib/bpf/balancer.bpf.c`, `runner/repos/katran/katran/lib/bpf/xdp_root.c`, `runner/libs/workload.py`, and `runner/assets/tetragon_policies/`.
