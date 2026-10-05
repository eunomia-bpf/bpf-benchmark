# Major BPF Program Trigger Analysis - 2026-05-06

Scope: read-only diagnosis of whether the current corpus workloads execute the major BPF paths for `cilium/agent`, `katran`, and `tracee/monitor`.

Source note: the checked-out worktree currently reports `88e43e83`, while the requested pinned source was `e3c3388b`. Source inspection below used `git show e3c3388b:<path>` for framework files. Local upstream app source under `runner/repos/` was read only for role identification. No code or test changes were made; this file is the requested report.

Update note: `bcc_set` and `bpftrace_set` startup is now intentionally simple: snapshot `bpftool prog show -j`, spawn every tool/script, fixed-wait for attach, fail if any child exited, then use the after-minus-before program-ID diff as the tracked union. The set runners no longer use fdinfo, per-tool/script program attribution, `runner_details.*.tool_startup`, or a global stable-program-set wait.

Result data:

- `corpus/results/x86_kvm_corpus_20260506_073134_900272/details/result.json`
- `corpus/results/aws_arm64_corpus_20260506_194818_115918/details/result.json`
- `corpus/results/x86_kvm_corpus_20260506_180924_438650/details/result.json` was only background context for the shared `stress_ng_os_io_network` workload.

Relevant source facts:

- `benchmark_catalog.py` assigns `cilium/agent -> network_lossy_multi` for 5.0 s, `katran -> xdp_traffic` for default 3.0 s, and `tracee/monitor -> stress_ng_os_io_network` for 5.0 s.
- `corpus/driver.py` runs one warmup, then one measured baseline workload sample in these smoke results, applies ReJIT, then one measured post-ReJIT workload sample.
- `e2e/cases/` does not exist in this checkout, so there were no app-specific e2e hints to cross-reference.

## 1. Per-App Current State

### cilium/agent

Workload: `network_lossy_multi`, measured baseline duration 5.081855594 s, 631 HTTP requests, plus best-effort ping during the same 5 s window.

Framework setup from `cilium.py`:

- Creates a single veth pair: root namespace `bpfbench0` at `198.18.0.1/30`, peer `bpfbench1` inside `bpfbenchns` at `198.18.0.2/30`.
- Starts `cilium-agent` with `--enable-k8s=false`, native routing, `--devices=bpfbench0`, and `--direct-routing-device=bpfbench0`.
- Does not create a Cilium endpoint, pod, CNI attachment, workload endpoint identity, service, or policy path.

Traffic path from `workload.py`:

```text
root-ns wrk/ping client -> bpfbench0 -> bpfbench1/bpfbenchns HTTP server
HTTP server replies -> bpfbench1 -> bpfbench0 -> root-ns client
```

Major set definition for Cilium here: host/netdev datapath entry programs and their IPv4 continuation tail programs: `cil_from_host`, `cil_from_netdev`, `cil_to_netdev`, `cil_to_host`, `tail_handle_ipv4_from_host`, `tail_handle_ipv4_from_netdev`. Current result has no `cil_lxc`, `cil_from_container`, or `cil_to_container` programs loaded.

Counter-visible trigger coverage:

- All tracked programs: 43 total, 4 with nonzero baseline runs, 1 with >=100 baseline runs.
- Major datapath set: 30 total instances, 4 with nonzero baseline runs, 1 with >=100 baseline runs.
- Effective meaningful major coverage: 1/30. The three 1-run entries are trigger/setup noise for paper-perf purposes.

| prog_name | type | instances | bytes_xlated | baseline_runs | post_runs | expected_role |
|---|---:|---:|---:|---:|---:|---|
| `cil_from_netdev` | sched_cls | 5 | 5368 | 0, 0, 0, 0, 1517 | 0, 0, 0, 0, 1307 | Main TC ingress from a Cilium-managed netdev. Only one instance sees meaningful traffic. |
| `cil_from_host` | sched_cls | 5 | 5952 | 0, 0, 1, 0, 0 | 0, 0, 1, 0, 0 | Host egress from `cilium_host`; current workload does not intentionally route through it. |
| `cil_to_netdev` | sched_cls | 4 | 2056 | 0, 0, 0, 0 | 0, 0, 0, 0 | Main TC egress to managed netdev; not hit by this root-to-netns veth setup. |
| `cil_to_host` | sched_cls | 4 | 952 | 0, 1, 1, 0 | 0, 1, 1, 0 | Host ingress on `cilium_host`/`cilium_net`; only 1-run noise. |
| `tail_handle_ipv4_from_host` | sched_cls | 6 | 1976 | 0, 0, 0, 0, 0, 0 | 0, 0, 0, 0, 0, 0 | IPv4 long-path continuation from host path; tail-call target, not counter-visible here. |
| `tail_handle_ipv4_from_netdev` | sched_cls | 6 | 592 | 0, 0, 0, 0, 0, 0 | 0, 0, 0, 0, 0, 0 | IPv4 long-path continuation from netdev path; tail-call target, not counter-visible here. |
| `tail_drop_notify` | sched_cls | 6 | 672 | 0, 0, 0, 0, 0, 0 | 0, 0, 0, 0, 0, 0 | Drop-notification tail path, not main forwarding. |
| `cil_host_policy` | sched_cls | 5 | 16 | 0, 0, 0, 0, 0 | 0, 0, 0, 0, 0 | Tiny host policy tail slot/fallback. |
| `dump_bpf_prog` | tracing | 1 | 520 | 0 | 0 | Cilium BPF introspection, not workload datapath. |
| `dump_bpf_map` | tracing | 1 | 280 | 0 | 0 | Cilium BPF introspection, not workload datapath. |

Visible one-run-cycle latency in this result:

- `cil_from_netdev`: 1517 runs, 1,671,430 ns total, about 1102 ns/run.
- `cil_from_host`: 1 run, 1412 ns. This is not a stable workload path.
- `cil_to_host`: 1 run each on two instances, 744 ns and 1357 ns. These are not stable workload paths.

### katran

Workload: `xdp_traffic`, but Katran does not use the generic `workload.py` HTTP helper. `KatranRunner.run_workload()` calls `run_parallel_http_load()` inside `katran-client` and sends HTTP requests to `VIP_IP=10.100.1.1`, `VIP_PORT=8080`.

Topology and wiring from `katran.py`:

- `katran0` in root namespace is paired with `rtlb0` in `katran-router`.
- `katran-client` routes through `katran-router`.
- `katran-router` routes `10.100.1.1/32` via `192.0.2.2` on `rtlb0`, so packets enter root namespace through `katran0` XDP ingress.
- `katran-real` has `REAL_IP=10.200.0.2` and also binds `VIP_IP=10.100.1.1/32` on loopback.
- Runner starts a real upstream `katran_server_grpc`, configures `vip_map`, `reals`, `ch_rings`, and `ctl_array`, then requires `success_count == request_count`.

Katran XDP composition:

- `xdp_root` is a 136-byte dispatcher. Upstream `xdp_root.c` loops root-array slots 0..2 and calls `bpf_tail_call(ctx, &root_array, i)`, then returns `XDP_PASS` if no tail call fires.
- The runner loads/pins `xdp_root`, passes the pinned `root_array` to `katran_server_grpc` with `-map_path=.../root_array -prog_pos=2`, and the upstream server registers `balancer_ingress` into that pinned prog array.
- This is tail-call dispatch, not `XDP_REDIRECT` into `balancer_ingress`.

Counter-visible trigger coverage:

- x86 KVM: all tracked programs 3 total, 1 with nonzero baseline runs. Strict main-forwarder program coverage by direct per-program counters: `balancer_ingress` 0/1.
- ARM64: same pattern.
- Operational coverage is different: successful VIP HTTP through this topology strongly implies the `xdp_root -> balancer_ingress` tail call is working. If `xdp_root` only returned `XDP_PASS`, there is no obvious plain Linux path from `katran-client` to the real HTTP server bound to VIP loopback in `katran-real`.

| arch/result | prog_name | type | bytes_xlated | baseline_runs | post_runs | expected_role |
|---|---|---:|---:|---:|---:|---|
| x86 KVM | `balancer_ingress` | xdp | 23840 | 0 | 0 | Main Katran load-balancer forwarder. Counter-zero because it is reached as a tail-call target, not as top-level XDP entry. |
| x86 KVM | `healthcheck_encap` | sched_cls | 1000 | 0 | 0 | Healthcheck encapsulation path; no healthcheck traffic in this workload. |
| x86 KVM | `xdp_root` | xdp | 136 | 103451 | 106632 | Root XDP dispatcher and top-level accounting point for the tail-called datapath. |
| ARM64 | `balancer_ingress` | xdp | 23824 | 0 | 0 | Main Katran load-balancer forwarder; same tail-call accounting issue. |
| ARM64 | `healthcheck_encap` | sched_cls | 1000 | 0 | 0 | Healthcheck path; no healthcheck traffic. |
| ARM64 | `xdp_root` | xdp | 136 | 13067 | 13164 | Root XDP dispatcher/top-level accounting point. |

Visible one-run-cycle latency:

- x86 KVM: 17,242 successful VIP HTTP requests in 3.000853252 s; `xdp_root` has 103,451 runs, 35,437,243 ns total, about 343 ns/run.
- ARM64: 2,178 successful VIP HTTP requests in 3.022160555 s; `xdp_root` has 13,067 runs, 12,108,569 ns total, about 927 ns/run.
- Those `xdp_root` timings likely include tail-called `balancer_ingress` execution time from the kernel's top-level BPF stats accounting perspective.

### tracee/monitor

Workload: `stress_ng_os_io_network`, measured baseline duration 5.232683948 s, 17,667,049 stress-ng bogo ops.

Tracee setup from `tracee.py`:

- Starts upstream `tracee` with `--events *`, `--output none`, and healthz server.
- The runner workload only invokes stress-ng classes: OS, IO, network, memory, and filesystem stressors. It does not perform kernel module load/unload, debugfs writes, kprobe/tracepoint registration, or syscall-table tampering.

Major set definition for Tracee here: `bytes_xlated > 1000`, which captures the event handlers rather than tiny attachment helpers.

Counter-visible trigger coverage:

- All tracked programs: 158 total, 81 with nonzero baseline runs, 70 with >=100 baseline runs.
- Major set: 135 total, 66 with nonzero baseline runs, 56 with >=100 baseline runs.
- The largest specialized detector programs are not triggered at all.

Representative major rows:

| prog_name | type | bytes_xlated | baseline_runs | post_runs | expected_role |
|---|---:|---:|---:|---:|---|
| `lkm_seeker_kset_tail` | kprobe | 111768 | 0 | 0 | Hidden/LKM seeker long path; needs module/proc/kset seeker trigger. |
| `lkm_seeker_modtree_loop` | kprobe | 108072 | 0 | 0 | Hidden/LKM seeker module-tree scan; no module lifecycle trigger. |
| `lkm_seeker_proc_tail` | kprobe | 102120 | 0 | 0 | Hidden/LKM seeker proc/modules scan; no matching trigger. |
| `uprobe_syscall_table_check` | kprobe | 97056 | 0 | 0 | Syscall-table/hooked-syscall checker path; workload does not invoke the checker. |
| `tracepoint__exec_test` | raw_tracepoint | 96032 | 2 | 2 | Exec-related detector/test path; only startup/rare exec noise. |
| `trace_security_task_prctl` | kprobe | 76688 | 383820 | 413748 | Main prctl/security event handler; stress-ng drives this heavily. |
| `trace_security_mmap_file` | kprobe | 60888 | 1212559 | 468612 | Main mmap security handler; stress-ng drives this heavily. |
| `trace_security_file_mprotect` | kprobe | 59616 | 1730261 | 3156177 | Main mprotect security handler; stress-ng drives this heavily. |
| `trace_security_bprm_check` | kprobe | 52904 | 2 | 2 | Exec/security path; only rare startup/worker execs. |
| `trace_ret_vfs_write_tail` | kprobe | 51704 | 0 | 0 | Tail/slow return path for write event; not reached by observed write pattern or not counter-visible as tail. |
| `trace_ret_kernel_write_tail` | kprobe | 51704 | 0 | 0 | Kernel write tail path; no kernel-write trigger. |
| `trace_ret_vfs_writev_tail` | kprobe | 51680 | 0 | 0 | Writev tail path; not reached by observed writev pattern or not counter-visible as tail. |
| `sched_process_exec_event_submit_tail` | raw_tracepoint | 38432 | 0 | 0 | Exec event submit tail path; no sustained exec path. |
| `trace_execute_finished` | kprobe | 38400 | 2 | 2 | Exec completion path; only rare execs. |
| `vfs_writev_magic_return` | kprobe | 37648 | 139 | 115 | Writev return handler; barely above threshold. |
| `trace_security_file_open` | kprobe | 37160 | 687605 | 510674 | Main file-open security handler; stress-ng drives this. |
| `vfs_write_magic_return` | kprobe | 36792 | 340091 | 264048 | Main write return handler; stress-ng drives this. |
| `kernel_write_magic_return` | kprobe | 36792 | 0 | 0 | Kernel write return path; no kernel-write trigger. |
| `trace_call_usermodehelper` | kprobe | 36784 | 0 | 0 | Usermode-helper/module-adjacent path; no trigger. |
| `tracepoint__sched__sched_process_exec` | raw_tracepoint | 35424 | 2 | 2 | Exec tracepoint; only rare execs. |
| `trace_mmap_alert` | kprobe | 32864 | 1247955 | 637048 | Main mmap detector path; stress-ng drives this. |
| `tracepoint__module__module_load` | raw_tracepoint | 32720 | 0 | 0 | Kernel module load event; no module load in workload. |
| `syscall__execveat_enter` | raw_tracepoint | 32400 | 0 | 0 | Execveat syscall path; stress-ng did not use execveat. |
| `syscall__execve_enter` | raw_tracepoint | 31992 | 0 | 0 | Execve syscall path; not sustained by workload. |
| `trace_ret_vfs_read` | kprobe | 31808 | 2172734 | 1375624 | Main read return handler; stress-ng drives this. |
| `trace_ret_vfs_write` | kprobe | 31808 | 340091 | 264048 | Main write return handler; stress-ng drives this. |
| `trace_ret_file_modified` | kprobe | 31400 | 220627 | 136533 | File modification return handler; stress-ng drives this. |
| `cgroup_skb_ingress` | cgroup_skb | 31088 | 832432 | 694108 | Network/cgroup packet handler; stress-ng network drives this. |
| `cgroup_skb_egress` | cgroup_skb | 31088 | 1285541 | 1437455 | Network/cgroup packet handler; stress-ng network drives this. |
| `trace_security_kernel_read_file` | kprobe | 30720 | 0 | 0 | Kernel file-read path often used by module/firmware loading; no trigger. |
| `trace_security_sb_mount` | kprobe | 30680 | 0 | 0 | Mount security hook; no mount workload. |
| `trace_security_kernel_post_read_file` | kprobe | 30536 | 0 | 0 | Kernel post-read path; no module/firmware trigger. |
| `trace_security_bpf` | kprobe | 26984 | 7386 | 7386 | BPF syscall/security path; framework/Tracee startup activity drives it. |

Visible one-run-cycle latency examples:

- `trace_security_task_prctl`: about 333 ns/run.
- `trace_security_file_mprotect`: about 407 ns/run.
- `trace_security_file_open`: about 561 ns/run.
- `cgroup_skb_ingress`: about 258 ns/run; `cgroup_skb_egress`: about 249 ns/run.
- Rare exec paths with 2 to 4 runs are not stable workload coverage.

Tracee major category coverage from baseline counters:

| category | major_count | nonzero | >=100 | zero | blocker for zero rows |
|---|---:|---:|---:|---:|---|
| LKM/uprobe seeker and syscall-table checker | 11 | 0 | 0 | 11 | No hidden-module, syscall-table, or seeker trigger. |
| Module load/free and kernel read-file family | 5 | 0 | 0 | 5 | No module load/unload or firmware/module read path. |
| Execve/raw exec family | 11 | 5 | 0 | 6 | Only startup/worker exec noise, not sustained exec workload. |
| File, mmap, write/read, inode family | 32 | 22 | 22 | 10 | Stress-ng covers common file/mmap paths but not every tail/slow path. |
| Network/cgroup/socket family | 13 | 12 | 10 | 1 | Stress-ng network mostly covers this family. |
| Generic syscall enter/exit family | 5 | 2 | 2 | 3 | Main sys_enter/sys_exit run, submit/checker helpers do not. |
| Process/sched/creds/caps family | 26 | 22 | 19 | 4 | Stress-ng covers sched/caps/prctl heavily, not rare branches. |

## 2. Per-App Diagnosis

### cilium/agent

The current workload drives one host-device ingress instance, not the production pod/endpoint datapath.

The loaded program set itself is already a signal: no `cil_lxc`, `cil_from_container`, `cil_to_container`, `cil_lxc_policy`, or service/pod policy programs appear in the result. The runner starts Cilium with `--enable-k8s=false` and a single host veth device, but it never registers the peer namespace as a Cilium endpoint with endpoint identity, policy, ipcache state, or endpoint routes.

The observed counters match the topology:

- Replies from the netns HTTP server can arrive at `bpfbench0` ingress and hit one `cil_from_netdev` instance 1517 times.
- Outbound root-namespace client traffic is ordinary host-to-veth traffic, not a Cilium-managed workload endpoint. `cil_to_netdev` stays at 0.
- `cil_from_host` and `cil_to_host` 1-run entries are initialization/health/route noise, not workload coverage.
- Multiple same-name instances correspond to separate Cilium program attachments or generated instances. Only the instance attached to the traffic-bearing root-side interface sees packets.
- Tail-call target counters (`tail_handle_ipv4_*`) are zero. That does not prove bytecode in tail-called continuations never ran, because kernel BPF stats commonly attribute tail-called work to the top-level program entry. It does mean the framework has no per-program measurement for those continuation programs.

Specific blocker: the workload creates packet volume, but not Cilium endpoint traffic. It lacks a Cilium-managed container endpoint and traffic matrix that exercises endpoint ingress/egress, host firewall, service/lb, and policy paths.

### katran

The workload is probably driving the main LB path operationally, but the result format cannot attribute that work to `balancer_ingress`.

Evidence:

- The client sends to the Katran VIP, not to a generic local HTTP server.
- The runner configures the upstream Katran maps for `VIP_IP=10.100.1.1:8080` and real `10.200.0.2`.
- The runner fails the workload if any request fails. Both x86 and ARM64 result files have status `ok` and successful request counts.
- `xdp_root` is the attached top-level XDP program. Upstream `xdp_root` dispatches by `bpf_tail_call` through `root_array`; the runner passes this pinned map to `katran_server_grpc`, and upstream Katran registers `balancer_ingress` at slot 2.
- If the root program only bounced packets with `XDP_PASS`, the router-to-LB packet would enter the root namespace stack for destination VIP and should not reach the HTTP server in `katran-real` loopback.

Specific blocker: not traffic generation. The blocker is measurement attribution. Direct per-program counters show `balancer_ingress` as 0 because it is not the top-level entry program. The visible `xdp_root` counter is likely the aggregate accounting point for root plus tail-called balancer work. `healthcheck_encap` is genuinely not covered because the workload sends client VIP traffic, not healthcheck traffic.

### tracee/monitor

Tracee is partially representative: common syscall/security/network event handlers are strongly covered, but the largest specialized detector programs are idle.

The subscription is broad (`--events *`), so the main problem is not event selection. The workload is `stress_ng_os_io_network`; it generates many reads, writes, mmap/mprotect, socket, cgroup skb, prctl, caps, and scheduler events. It does not generate kernel module lifecycle events, debugfs creation/writes, kprobe/tracepoint registration, syscall-table tampering, or Tracee's own hidden-module/syscall-table seeker trigger path.

Specific blockers:

- LKM seeker programs need module load/unload or explicit hidden-module seeker activity. No `tracepoint__module__module_load`, `tracepoint__module__module_free`, or `trace_ret_do_init_module` runs were observed.
- `uprobe_syscall_table_check` needs the syscall-table checker path to execute. Stress-ng syscalls alone do not invoke this checker.
- Debugfs/proc/kprobe registration programs (`trace_debugfs_create_file`, `trace_proc_create`, `trace_ret_register_kprobe`, `trace_tracepoint_probe_register_prio_may_exist`) need privileged kernel instrumentation setup activity, not ordinary IO/network stress.
- Exec paths are present but only at 2 to 4 runs for the largest exec handlers. They are startup/worker noise, not a sustained exec workload.

## 3. Recommended Workload/Config Changes

These are operational recipes only, not code patches or tests.

### cilium/agent

Use a real Cilium endpoint path.

- Create at least one Cilium-managed endpoint namespace rather than only a raw veth peer. The endpoint should have a Cilium identity, endpoint route, ipcache entry, policy map state, and TC attachment for the endpoint-facing program set.
- Drive traffic both ways: endpoint-to-host, host-to-endpoint, endpoint-to-endpoint, endpoint-to-external, and external-to-endpoint.
- Include a service or NodePort/VIP case if the paper claim includes Cilium service/LB code paths.
- Bind the HTTP server/client so traffic traverses `cil_from_container`/`cil_lxc` and the host netdev paths, not just `bpfbench0` ingress replies.
- To specifically cover `cil_from_host`/`cil_to_host`, route host-originated traffic through `cilium_host`/`cilium_net` into a managed endpoint rather than through an unmanaged root veth.
- Keep ICMP/TCP/UDP mix if multi-protocol coverage is desired, but the primary missing piece is endpoint/policy setup, not packet rate.

### katran

Keep the VIP topology, but interpret or configure measurement around tail-call accounting.

- Continue sending client namespace traffic to `10.100.1.1:8080`; this is the right traffic shape for the main LB path.
- Before paper runs, operationally verify the pinned `root_array` slot 2 contains the `balancer_ingress` program fd after `katran_server_grpc` starts.
- Treat `xdp_root` run count/time as the observable top-level accounting point for the tail-called Katran datapath if shared-root mode remains in use.
- If a paper table requires a direct per-program row for `balancer_ingress`, run upstream Katran in standalone mode with `balancer_ingress` attached as the top-level XDP program, or otherwise collect a measurement method that attributes tail-call target execution. Do not interpret the current 0 direct run count as proof of no forwarding execution.
- To cover `healthcheck_encap`, add a separate healthcheck traffic recipe that targets the healthcheck interface/key path. The current VIP HTTP workload should not be expected to run it.

### tracee/monitor

Add explicit rare-event phases alongside the current stress-ng phase.

- Keep `--events *` unless startup cost becomes a problem. If narrowing, include the module load/free, hidden kernel module seeker, hooked/syscall-table checker, debugfs/proc creation, kprobe registration, file/mmap, socket, cgroup skb, and exec event families.
- Generate repeated module lifecycle events during the measured window using a harmless module that is not built into the kernel: load it, unload it, and repeat. The VM/container must have the needed privilege and module files available.
- Ensure tracefs/debugfs are mounted and readable/writable as required by Tracee's detector paths. Generate debugfs/proc/kprobe/tracepoint registration activity if those detectors are in scope.
- Trigger syscall-table/hooked-syscall checker execution explicitly through Tracee's relevant detection event or trigger utility. Ordinary high-rate syscalls are insufficient.
- Add a sustained exec workload if exec event handlers are in scope; current runs of 2 to 4 are startup noise.
- Keep the current `stress_ng_os_io_network` phase for common security hook, file, mmap, socket, cgroup skb, caps, prctl, and scheduler coverage. It is useful, just incomplete for LKM/syscall-table detectors.

## 4. Verdict

| app | Are major programs triggered? | Paper-perf representativeness |
|---|---|---|
| `cilium/agent` | Mostly no. One `cil_from_netdev` instance is meaningfully measured; `cil_from_host`/`cil_to_host` only have 1-run noise; endpoint/pod programs are not loaded. | Not representative for production Cilium forwarding/policy. Current data is dominated by a host-device ingress slice and missing endpoint/LXC/service paths. |
| `katran` | Operationally yes for the main LB path, but direct per-program counters say no for `balancer_ingress` because it is tail-called from `xdp_root`. `healthcheck_encap` is not triggered. | Representative only if `xdp_root` is treated as the aggregate accounting point for the tail-called LB path. Not representative as a per-program `balancer_ingress` row, because the major program has 0 direct counters. |
| `tracee/monitor` | Partially. Common file/mmap/socket/cgroup/security hooks run heavily; LKM seeker and syscall-table checker programs do not run. | Representative for common stress-ng-triggered Tracee event handling, not representative for the largest LKM/syscall-table detector code. A paper rollup over all Tracee programs would be skewed by missing rare-event coverage. |

Bottom line: current `cilium/agent` measurements are not paper-representative for major Cilium datapath code. Current `katran` traffic is likely correct, but the framework's per-program counter view is misleading for tail-called `balancer_ingress`. Current `tracee/monitor` measurements cover many real handlers but miss the highest-byte specialized detectors, so they need a targeted rare-event phase before being used as full-app Tracee evidence.
