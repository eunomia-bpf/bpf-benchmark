# PoC-C v2: shim-only speculative optimization design

Status: design only. No experiments were run for this note. The only output of
this task is this file.

This is the v2 redesign of PoC-C. It removes `bpfrejit-daemon` entirely. A
single in-process shim, installed by `LD_PRELOAD` for dynamic C/C++/Python paths
or by `bpfrejit-shimctl` hotpatch for Go/static raw-syscall paths, observes the
app's BPF control plane and owns the complete speculative optimization path:
load capture, pass orchestration through `bpfopt`, candidate `BPF_PROG_LOAD`,
attachment swap, verifier-state propagation, and swap logging.

The current active corpus list is `corpus/config/macro_apps.yaml:4-13`. The
runner dispatch table maps those app entries to concrete app-runner classes in
`runner/libs/app_runners/__init__.py:78-85`.

## 1. Goal and non-goals

Goal: app-transparent speculative optimization on a stock-kernel replacement
path without a separate daemon process. Each corpus app still starts the real
upstream binary or tool and loads its own BPF programs. The shim only observes
and reuses that real load/attach state. This preserves the app-level loader rule:
benchmark apps must load BPF through real application startup, not framework
`.bpf.o` loaders or custom replacement binaries (`CLAUDE.md:12-13`).

The paper-line still matches the idea #1 hub: runtime userspace-guided rewriting
of already-loaded eBPF programs (`docs/rejit-speculative-optimization-ebpf.md:21-26`).
The stock-kernel userspace design already established that candidate replacement
creates new program ids and requires attachment-aware swap
(`docs/tmp/userspace_speculative_opt_design.md:219-242`). v2 keeps that premise
but collapses all control into the app process.

Non-goals:

- Full atomicity. A microsecond-scale detach/reattach gap is acceptable for PoC
  measurement. Atomic link, map, XDP, and TCX updates are used where available,
  but perf-event, raw tracepoint, tracing, LSM, socket filter, and some legacy
  paths need a short replacement window.
- Beating verifier/JIT latency. Every candidate is a stock `BPF_PROG_LOAD`, so
  verifier and JIT time remain in the optimization path.
- Swap on every attach type. Unsupported attach classes must be recorded as
  explicit errors. The shim must not silently downgrade, skip, or hide them.
- Preserving the old `prog_id`. A stock candidate load creates a new program
  object. The shim records old-id to new-id mapping; preserving object identity
  needs an in-kernel in-place primitive.
- Capturing programs loaded before shim installation. Missing original bytecode
  is fatal for that logical program. Using verifier-rewritten `xlated_prog_insns`
  as original bytecode is forbidden by the userspace design
  (`docs/tmp/userspace_speculative_opt_design.md:72-80`).
- No daemon. Anything v1 delegated to `bpfrejit-daemon` is either absorbed into
  the shim or cut from v2.
- Global rate limiting and cross-shim scheduling are out of scope for v2 and are
  addressed separately. Multiple shims running `bpfopt` simultaneously is
  accepted for this design.

## 2. Why eliminate daemon

The strongest v2 justification is ownership. Even in v1, the candidate
`BPF_PROG_LOAD` and the attach swap had to execute inside the app process.
Stock Linux can duplicate a remote fd into a controller, but it cannot replace a
remote process's fd-table entry with a newly opened event/link. PoC-B found that
`PERF_EVENT_IOC_SET_BPF` returns `EEXIST` when used as replacement for an
already-attached perf event on the inspected repo kernel
(`docs/tmp/poc_b_bcc_perf_event_swap.md:9-20`). Therefore perf-event swap needs a
fresh event plus in-process `dup3()`/`dup2()` preservation of the app-visible fd.
PoC-A also found current Katran uses legacy netlink XDP, not an owned bpf-link fd
(`docs/tmp/poc_a_katran_pidfd_swap.md:15-19`), so a remote daemon cannot rely on
link-fd takeover for that key networking case.

The v1 daemon was therefore already only a control-plane participant for the
hard cases. v2 collapses that control plane into the actor that actually owns the
fds, memory, and attach surfaces.

| Axis | v1 daemon + shim | v2 shim-only |
| --- | --- | --- |
| Process count | App process plus shim, plus one `bpfrejit-daemon` process. | App process plus shim only. `bpfopt` still runs as short-lived subprocesses. |
| IPC | Shim/daemon Unix sockets, `SCM_RIGHTS`, memfd blobs, event sequencing, and daemon runner socket. | No optimization IPC. The shim writes JSONL swap records to `/var/run/bpfrejit/.swaps.jsonl`. |
| Cilium SIGSTOP behavior | The daemon can keep running, but it still cannot make the app process execute candidate load/swap while all app threads are stopped. | The shim worker is stopped with Cilium. Swap must occur before the runner sends SIGSTOP, same real constraint but more explicit. |
| Fd lifetime | Daemon mirrors state but cannot directly mutate the app fd table. Remote fd duplication is diagnostic, not sufficient for transparent swap. | Hidden duplicates and fd aliases live in the same fd table as the app. Candidate load and fd-number preservation happen locally. |
| Runner interface | Runner starts daemon and sends `execute_plan` over `/var/tmp/bpfrejit-daemon.sock` (`runner/libs/rejit.py:259-390`). | Recommended path: no optimize RPC. Runner reads raw counters and `/var/run/bpfrejit/.swaps.jsonl`. Optional path: per-shim socket only if synchronous control is required. |
| Single point of failure | Daemon crash kills optimization for all apps in the suite. | A shim crash affects one app process. Other apps and their shims are isolated. |
| LOC | v1 was estimated at 7-12 KLOC for all seven apps and 3-5 KLOC for a C/C++-only PoC (`docs/tmp/poc_c_bpf_syscall_shim_design.md:377-391`). | v2 removes daemon protocol, remote fd passing, daemon-side mirrors, and runner socket code. Estimate: 5-8 KLOC all-seven-app, 2-3 KLOC C/C++-only PoC. |

bpftime is useful precedent for the insertion technique, not for the execution
model. Its README describes a userspace eBPF runtime with a loader, verifier,
helpers, maps, attach events, and an `LD_PRELOAD` loader library
([bpftime README](https://github.com/eunomia-bpf/bpftime):345-364). Its design
docs describe syscall hooks based on binary rewriting and running-process
injection through ptrace/frida-gum
([bpftime design](https://eunomia.dev/bpftime/documents/how-it-works/):322-328),
and its usage docs show direct `LD_PRELOAD` deployment
([bpftime usage](https://eunomia.dev/bpftime/documents/usage/):436-447). PoC-C
v2 borrows the "put the control-plane hook in the process" idea, but it does not
run BPF in userspace, emulate maps, or replace the kernel verifier.

## 3. Shim architecture

The shim has two internal execution paths.

| Thread/path | Responsibility | Blocking policy |
| --- | --- | --- |
| Intercept path | Runs synchronously in the app's syscall path. It wraps or hotpatches `bpf()`, `syscall(SYS_bpf)`, `perf_event_open`, `ioctl`, `close`, fd duplication, route netlink `sendmsg`, and `setsockopt`. It deep-copies BPF load attrs and records successful fds, ids, and attachments. | Must be fast. It may copy bounded user buffers and update state under short locks, but must not run `bpfopt`, parse large verifier logs, or do network/file-heavy work. |
| Worker thread | Owns delayed optimization. It snapshots shim state, runs `bpfopt` subprocesses, loads accepted candidates, parses verifier logs, applies swaps, and writes JSONL records. | May block for seconds. It never runs in the app's original syscall stack. |

State tables:

| Table | Key | Contents |
| --- | --- | --- |
| Program table | `prog_id` and stable `logical_id` | Original `BPF_PROG_LOAD` attr, original bytecode, current accepted bytecode, prog type, expected attach type, program name, license, BTF/func/line info pointers copied into shim-owned storage, `fd_array` snapshot, hidden dup fds for maps/BTF/attach targets, active attach ids, candidate fd/id, state, error string, and original load metadata. |
| Map table | app fd alias, hidden fd, and `map_id` | Map type, key/value sizes, max entries, flags, name, BTF ids, inner map template, fd aliases, hidden refcount, map generation, and special `PROG_ARRAY` slots observed through map updates. |
| Link/attach table | `attach_id` | Method (`bpf_link`, legacy XDP netlink, TCX, legacy TC, perf event, raw tracepoint, tracing, cgroup, prog array, socket option), generation, current prog id, app-visible fd if any, hidden duplicate, target identity, expected old prog id/fd, and restore/swap recipe. |

The intercept path records original bytecode before verifier rewrite. This is
mandatory because stock `BPF_OBJ_GET_INFO_BY_FD` exposes xlated instructions, not
original load input (`docs/tmp/userspace_speculative_opt_design.md:36-60`).

In-process synchronization:

- Every shim-internal syscall runs under a thread-local recursion guard, so
  candidate loads and swap syscalls are not re-recorded as app-originated events.
- The intercept path takes a short state mutex or write lock only to install
  records after the real syscall succeeds. It does not hold the lock while the
  kernel verifier runs for app-originated `BPF_PROG_LOAD`.
- The worker snapshots program/map/attach state under lock, releases the lock
  while running `bpfopt`, then reacquires an exclusive "swap lock" for candidate
  load validation and attach replacement.
- Attach records carry generation counters. If the app closes, duplicates,
  detaches, reattaches, or updates a prog-array slot after the worker snapshot,
  the worker aborts that logical program with an explicit generation-mismatch
  error instead of swapping stale state.
- During the actual swap window, app-side BPF control-plane syscalls block behind
  the swap lock. Non-BPF syscalls are not intercepted and continue normally.

## 4. Optimization pipeline owned by shim worker thread

Per-program state machine:

```text
OBSERVED -> ELIGIBLE -> OPTIMIZING -> APPLIED
                               \-> FAILED
```

State meanings:

- `OBSERVED`: original load attr and bytecode were copied, and the real app load
  succeeded.
- `ELIGIBLE`: required map/BTF/target fds and at least one supported attach
  record are present.
- `OPTIMIZING`: the worker owns the logical program and is running the pass list.
- `APPLIED`: a final accepted candidate was loaded and all selected attachments
  were swapped.
- `FAILED`: any required capture, `bpfopt`, candidate load, verifier-log parse,
  generation check, or swap step failed. The original attachment remains live
  unless the swap failure happened after a non-atomic detach; that partial result
  must be logged explicitly.

Trigger policy, recommended path (a):

- The shim arms a quiet-window timer after every observed `BPF_PROG_LOAD`.
- The timer fires `N` seconds after the most recent load if no new loads arrived.
- Use `N ~= 5s` for the first benchmark design. It is long enough for normal
  multi-program app startup bursts to finish, short enough to run before long
  steady-state workloads dominate the process lifetime, and matches the runner's
  existing pattern of waiting for the program set to stabilize after app startup
  (`runner/libs/app_runners/process_support.py:54-106`).

Pipeline for one logical program:

1. Create a private workdir under `/var/run/bpfrejit/shim-$pid/$logical_id/`.
2. Write current bytecode to `input_stepN.bin`.
3. Execute `bpfopt` as a CLI subprocess. `bpfopt` remains a separate binary and
   is not linked, dlopened, or embedded in the shim. The worker uses stdin/stdout
   for raw `struct bpf_insn[]` bytecode and files for side inputs/outputs:

   ```sh
   bpfopt --pass "$pass" \
     --prog-type "$prog_type" \
     --target "$target_json" \
     --report "$workdir/report_stepN.json" \
     --verifier-states "$workdir/verifier-states-prev.json" \
     < "$workdir/input_stepN.bin" \
     > "$workdir/output_stepN.bin"
   ```

   Pass-specific side inputs, such as map values and map ids for `map_inline`,
   remain file arguments after `--`.
4. If `bpfopt` exits nonzero, mark the logical program `FAILED` and record the
   stderr/stdout tail. Do not continue with later passes as a silent fallback.
5. If output bytecode is empty or byte-for-byte unchanged, record the report and
   continue with the prior accepted bytecode.
6. If output bytecode changed, call stock `BPF_PROG_LOAD` inside the app process
   using the captured load attr, the candidate bytecode, the same map/BTF/target
   fds from shim state, and `log_level=2` when the next pass needs verifier
   state. The current UAPI supports `fd_array` / `fd_array_cnt` on
   `BPF_PROG_LOAD`, and the verifier consumes that array
   (`docs/tmp/userspace_speculative_opt_design.md:144-149`).
7. If candidate load fails, mark `FAILED`, write the verifier log and error, and
   leave live traffic on the original program.
8. If candidate load succeeds, parse the verifier log into
   `verifier-states.json`, close the previous unneeded candidate fd, and make
   the accepted candidate bytecode the input to the next pass.
9. After the last accepted pass, reacquire the swap lock, validate all attachment
   generations, and apply the per-attach swap recipe below.
10. Write one JSONL record to `/var/run/bpfrejit/.swaps.jsonl`.

The v2 worker owns the v1 per-attach recipe with no daemon involvement:

| Attach type | Recipe | Atomicity and notes |
| --- | --- | --- |
| XDP bpf-link | Load candidate as `BPF_PROG_TYPE_XDP`, then `BPF_LINK_UPDATE(link_fd, new_prog_fd, BPF_F_REPLACE, old_prog_fd)`. | Atomic. XDP update support is covered in the userspace design (`docs/tmp/userspace_speculative_opt_design.md:96`). |
| Legacy XDP netlink | Synthesize `RTM_SETLINK` with `IFLA_XDP_FD = new_prog_fd`, original mode flag, `XDP_FLAGS_REPLACE`, and expected old fd/id. | Atomic under RTNL if expected old matches. Required for current Katran because PoC-A found legacy netlink attach (`docs/tmp/poc_a_katran_pidfd_swap.md:15-19`). |
| TCX link | `BPF_LINK_UPDATE` on the TCX link fd. | Atomic. TCX support is covered in the userspace design (`docs/tmp/userspace_speculative_opt_design.md:98`). |
| Legacy TC `cls_bpf` | Reconstruct ifindex, ingress/egress, parent, chain, prio, handle, protocol, direct-action flag, and old prog id from observed netlink. Send `tc filter replace` equivalent with the candidate fd. | Replacement is under rtnl, but only works if the shim captured exact filter identity. Cilium is the main risk because TC attachments survive process death as interface-scoped state (`runner/libs/app_runners/cilium.py:614-618`). |
| perf-event attach for kprobe/uprobe/tracepoint/perf_event | Disable old event if enabled; open a fresh event with captured `perf_event_attr`, pid, cpu, group, and flags; call `PERF_EVENT_IOC_SET_BPF` on the fresh event; enable if old was enabled; preserve the app-visible fd with in-process `dup3()`/`dup2()`; close temporary fds. | Non-atomic. PoC-B shows `SET_BPF` cannot replace an already-attached event on the inspected kernel (`docs/tmp/poc_b_bcc_perf_event_swap.md:9-20`), so fresh-event plus fd-number preservation is mandatory. |
| raw tracepoint | Close/detach old raw tracepoint link fd, issue `BPF_RAW_TRACEPOINT_OPEN` with the same name and candidate fd, preserve fd number if the app keeps it. | Non-atomic gap. Raw tracepoint link ops lack update support (`docs/tmp/userspace_speculative_opt_design.md:94`). |
| fentry/fexit/LSM/freplace/tracing link | Close/detach old link fd, then `BPF_LINK_CREATE` again with captured target BTF/prog metadata and candidate fd. | Non-atomic gap. Tracing link ops lack update support (`docs/tmp/userspace_speculative_opt_design.md:95`). Missing target fd is fatal. |
| `PROG_ARRAY` tail-call slot | `BPF_MAP_UPDATE_ELEM(prog_array_fd, key, new_prog_fd, BPF_ANY)` on the same map/key. | Atomic per map slot. Tail targets can report zero `run_cnt`; caller counters measure descendant time (`CLAUDE.md:60-62`). |
| cgroup link / netns link / sockmap link | Prefer `BPF_LINK_UPDATE` for link-backed attachment. For legacy cgroup attach, use `BPF_PROG_ATTACH` with replace flags and captured target cgroup fd. | Link-backed path is atomic; legacy path depends on captured target fd and attach flags (`docs/tmp/userspace_speculative_opt_design.md:100-104`). |
| socket filter / reuseport socket option | Use captured socket fd. Detach old filter where applicable, then `setsockopt(... SO_ATTACH_BPF or SO_ATTACH_REUSEPORT_EBPF ..., new_prog_fd)`. | Non-atomic gap. Required for socket-filter programs in Tetragon-style workloads. |

Swap log record shape:

```json
{"ts_ns":123,"pid":456,"process_start_time":"...","logical_id":"456:17","status":"ok","old_prog_id":101,"new_prog_id":202,"prog_name":"cil_xdp_entry","prog_type":"xdp","attach_ids":[7],"attach_methods":["legacy_xdp_netlink"],"passes":["noop","map_inline"],"reports":[".../report_step0.json",".../report_step1.json"],"error":null}
```

This is raw metadata for result interpretation, not a performance summary.

## 5. Verifier-states propagation across passes

Verifier-state propagation moves from daemon to shim worker.

Current policy evidence:

- The default policy puts `noop` before `map_inline` / `const_prop` in the
  map-focused and full groups (`corpus/config/benchmark_config.yaml:3-15`).
- `map_inline` and `const_prop` pass configs consume `${VERIFIER_STATES}`
  (`runner/config/passes/map_inline/default.yaml:4-6`,
  `runner/config/passes/const_prop/default.yaml:4-6`).
- Existing daemon code intentionally starts with a missing verifier-state path
  so a pass that needs states fails unless a state-producing step such as `noop`
  ran first (`daemon/src/commands.rs:587-590`).

v2 rule:

1. The shim uses `log_level=2` for any candidate load whose verifier log feeds a
   downstream state-consuming pass.
2. After successful candidate `BPF_PROG_LOAD`, the shim parses the verifier log
   into `verifier-states.json`.
3. The next `bpfopt` subprocess receives that path through
   `--verifier-states`.
4. `noop` remains the bootstrap memory rule before `map_inline` and
   `const_prop`. Missing verifier states are a hard per-program failure.
5. Verifier logs and parsed state files are kept in the shim workdir and listed
   in the swap JSONL record.

## 6. Runner Python interface

Recommended benchmark path: option (a), shim auto-triggers.

The runner does not enumerate shims or send "optimize now". It starts real apps
with the shim installed, runs workloads, samples raw BPF counters, and reads
`/var/run/bpfrejit/.swaps.jsonl` to connect logical programs to kernel ids.
This removes the daemon socket boundary currently used by `apply_daemon_rejit`
(`runner/libs/rejit.py:340-390`) and makes benchmark image delivery simpler.

Methodology change versus current `BPF_PROG_REJIT`:

- Current in-place ReJIT keeps the same `prog_id`, and the corpus driver samples
  `result.state.prog_ids` in both baseline and post phases
  (`corpus/driver.py:576-582`, `corpus/driver.py:680-686`).
- Stock userspace candidate load creates a new `prog_id`. Existing runner logic
  rejects tracked id changes during rediscovery (`corpus/driver.py:303-390`) and
  `sample_bpf_stats_from_records()` errors if requested ids are absent
  (`runner/libs/bpf_stats.py:52-74`).
- Therefore the runner must merge raw counter records by shim `logical_id`, not
  by assuming old and new kernel ids are the same. The prior userspace design
  already calls out this requirement (`docs/tmp/userspace_speculative_opt_design.md:219-242`).

Recommended raw result model:

- `baseline.bpf` records raw counters for the old program id that was active
  before swap.
- `post_rejit.bpf` records raw counters for the active candidate id after swap.
- `rejit_result.per_program[old_id].candidate_prog_id` or an equivalent
  `logical_id` mapping links the two raw records.
- For tail-call-target swaps, the log must also record `measured_prog_id` when
  runtime savings appear in the directly attached caller rather than the swapped
  tail target (`CLAUDE.md:60-62`).

The runner may still use the swap JSONL as a phase-boundary signal. That is not
an optimize RPC; it is reading raw state. If the existing baseline/post timing
needs exact synchronous control, use alternative (b).

Alternative path (b): each shim exposes a Unix socket under
`/var/run/bpfrejit/$pid.sock`. The runner enumerates shims and sends
`optimize_now` for specific logical programs. This restores current-style
phase control at the cost of per-shim sockets, a small control protocol, and
more runner changes. It is not the recommended first v2 benchmark path.

## 7. 7-app coverage and per-app notes

`katran` and `katran/wrk` are separate macro entries
(`corpus/config/macro_apps.yaml:9-11`) but share the same upstream Katran runner
and count as one supported app here.

| App | Current launch path | Shim injection | Attach types and swap plan | Expected limitations |
| --- | --- | --- | --- | --- |
| `katran` / `katran/wrk` | Real `katran_server_grpc` is resolved from repo artifacts (`runner/libs/app_runners/katran.py:193-196`). The runner starts it with real balancer and healthchecking objects (`runner/libs/app_runners/katran.py:536-548`) from `KatranRunner.start()` (`runner/libs/app_runners/katran.py:731-777`). | C++ upstream binary. Use `LD_PRELOAD` plus netlink observer. | XDP. If a bpf-link exists, use `BPF_LINK_UPDATE`; current expected path is legacy XDP netlink replace because PoC-A found legacy netlink attach (`docs/tmp/poc_a_katran_pidfd_swap.md:15-19`). | Current runner calls `reattach_xdpgeneric()` after app startup (`runner/libs/app_runners/katran.py:631-633`, `runner/libs/app_runners/katran.py:748`). The shim must observe that helper's attach transition or the runner must move the rebind into shim-owned netlink logic. |
| `cilium/agent` | `CiliumRunner` resolves `cilium-agent` from artifacts or system paths (`runner/libs/app_runners/cilium.py:246-257`) and launches it with BPF/XDP datapath options (`runner/libs/app_runners/cilium.py:284-337`). | Go. Use `bpfrejit-shimctl` syscall hotpatch plus route-netlink parser. Local checkout says `go 1.25.0` (`runner/repos/cilium/go.mod:1-3`). | XDP, TC/sched_cls, tracing, and prog-array tail calls. Use XDP link/netlink replace, TCX link update or legacy TC replace, and prog-array map updates for tail targets. | Legacy TC identity reconstruction is the hardest part. Runner freezes userspace after endpoint setup while TC/XDP programs and pinned maps stay resident (`runner/libs/app_runners/cilium.py:549-557`). Since SIGSTOP stops the shim worker too, auto swap must finish before that pause. |
| `tracee/monitor` | Runner resolves upstream Tracee artifacts (`runner/libs/app_runners/tracee.py:149-167`) and starts Tracee with `--events *`, output mode, health server, and signatures dir (`runner/libs/app_runners/tracee.py:204-208`, `runner/libs/app_runners/tracee.py:279-296`). Runtime image copies upstream `tracee` and `tracee-ebpf` artifacts (`runner/containers/runner-runtime.Dockerfile:215-221`). | Go/hybrid upstream artifact. Use Go hotpatch and propagate into helper process if `tracee-ebpf` execs or spawns. | Current userspace design lists raw tracepoint, kprobe, cgroup_skb, and LSM for Tracee (`docs/tmp/userspace_speculative_opt_design.md:113`). Use raw_tp/tracing recreate, perf-event recreate, and cgroup replace where captured. | LSM/tracing replacement is non-atomic and target-fd capture is mandatory. Helper-process ownership must be audited. |
| `tetragon/observer` | Runner starts upstream `tetragon` with server address, health address, policy directory, and optional BPF lib dir (`runner/libs/app_runners/tetragon.py:165-181`). Runtime image copies Tetragon artifacts (`runner/containers/runner-runtime.Dockerfile:223-224`). | Go. Use Go syscall hotpatch. | Policies include kprobes (`runner/assets/tetragon_policies/security-socket-connect.yaml:6-13`), tracepoints (`runner/assets/tetragon_policies/raw_syscalls.yaml:6-12`), and raw tracepoint mode (`runner/assets/tetragon_policies/rawtp.yaml:6-12`). Use perf-event recreate, raw_tp/tracing recreate, prog-array updates for tail-call chains, and `setsockopt` for socket filters. | Generic kprobe/raw_tp chains are non-atomic. Socket filter replacement requires `setsockopt` capture, not just `bpf()` capture. |
| `bpftrace/set` | Runner starts five scripts (`runner/libs/app_runners/bpftrace_set.py:24-30`) and launches each child as `bpftrace -q <script>` (`runner/libs/app_runners/bpftrace_set.py:131-139`). | C++ bpftrace from distro packages. Use `LD_PRELOAD`. | kprobe, tracepoint, interval/perf-event programs. Scripts explicitly use kprobes and tracepoints, e.g. `capable.bt` kprobe (`runner/assets/bpftrace_scripts/capable.bt:72-78`), `vfsstat.bt` kprobes (`runner/assets/bpftrace_scripts/vfsstat.bt:33-42`), `runqlat.bt` scheduler tracepoints (`runner/assets/bpftrace_scripts/runqlat.bt:44-50`), and `biosnoop.bt` block tracepoints (`runner/assets/bpftrace_scripts/biosnoop.bt:33-40`). | Multiple BPF loads per process lifetime and one process per script. Perf-event replacement must preserve fd numbers so bpftrace bookkeeping remains valid. |
| `bcc/set` | Runner runs eight BCC tools (`runner/libs/app_runners/bcc_set.py:34-43`) and spawns each resolved tool command with a prepared environment (`runner/libs/app_runners/bcc_set.py:144-167`). The single-tool runner uses the same subprocess launch pattern (`runner/libs/app_runners/bcc.py:372-389`). | CPython plus libbcc/libbpf C/C++ extension. Use `LD_PRELOAD`. | Mostly kprobe, tracepoint, raw tracepoint, and tracing variants; current userspace design summarizes observed classes (`docs/tmp/userspace_speculative_opt_design.md:116`). Use perf-event recreate, raw_tp/tracing recreate, and record fentry/kfunc variants. | Eight independent processes mean eight shim instances. PoC-B shows cross-process fd acquisition is not enough; replacement must happen inside each BCC process (`docs/tmp/poc_b_bcc_perf_event_swap.md:9-20`). |
| `otelcol-ebpf-profiler/profiling` | Runner writes a minimal config enabling all tracers (`runner/libs/app_runners/otel_profiler.py:33-62`) and starts `otelcol-ebpf-profiler` with feature gates and config (`runner/libs/app_runners/otel_profiler.py:123-130`). Local checkout says `go 1.25.0` (`runner/repos/opentelemetry-ebpf-profiler/go.mod:1-11`). | Go. Use `bpfrejit-shimctl` syscall hotpatch. | Perf-event and tracepoint entries plus tail-called `perf_unwind_*` programs. Use perf-event recreate for direct entries and `PROG_ARRAY` updates for tail-call targets. | Tail-called programs report zero `run_cnt`; measurement must use caller counters (`runner/libs/app_runners/otel_profiler.py:21-30`, `CLAUDE.md:60-62`). Perf-event mmap/read behavior must be audited before fd replacement is considered transparent. |

## 8. Comparison vs v1 daemon+shim

LOC delta:

- v1 estimated 7-12 KLOC all-seven-app and 3-5 KLOC for a C/C++-only PoC
  (`docs/tmp/poc_c_bpf_syscall_shim_design.md:377-391`).
- v2 removes daemon/shim protocol code, `SCM_RIGHTS` blob passing, remote fd
  passing, daemon-side state mirrors, daemon runner socket protocol, and daemon
  discovery bookkeeping.
- v2 adds a bigger worker inside the shim, but the net all-seven-app estimate is
  5-8 KLOC. The C/C++-only PoC estimate is 2-3 KLOC.

Cilium freeze case: Cilium's runner sends SIGSTOP after setup to prevent userspace
reloads while datapath programs remain resident (`runner/libs/app_runners/cilium.py:549-557`).
In v1, a daemon could still compute candidates during SIGSTOP but could not make
the stopped app execute the required in-process candidate load and swap. In v2,
the shim worker also stops. The mitigation is the same: swap before SIGSTOP. v2
makes the constraint sharper but not worse.

Crash behavior: one shim crash is scoped to one app process. A v1 daemon crash
would disable optimization for every app in the suite. The cost is that the shim
lives inside production app address space, so memory safety in the shim matters
more.

Honest tradeoff: v2 loses centralized scheduling, centralized policy dispatch,
and one daemon log. It gains simpler ownership, no control-plane IPC, and
per-app isolation. Global rate limiting and cross-shim coordination remain out
of scope for this v2 document.

## 9. Implementation sketch

Suggested component layout:

```text
shim/
  interpose.c              # LD_PRELOAD wrappers for bpf/syscall/ioctl/close/dup/sendmsg/setsockopt
  raw_syscall_trampoline.c # common handler target for Go/static hotpatches
  attr_copy.c              # deep-copy BPF attrs and pointed-to buffers
  state.c                  # program/map/fd/link/attach tables and generation counters
  worker.c                 # quiet-window timer, per-prog state machine
  bpfopt_exec.c            # fork+exec/posix_spawn bpfopt, stdin/stdout bytecode, side files
  candidate_load.c         # in-process BPF_PROG_LOAD with captured attrs/fd_array
  verifier_states.c        # log_level=2 parser and verifier-states.json writer
  swap.c                   # per-attach replacement recipes
  netlink.c                # minimal IFLA_XDP and TCA_BPF parser/emitter
  jsonl.c                  # /var/run/bpfrejit/.swaps.jsonl writer
  recursion_guard.c        # TLS guard for shim-internal syscalls

bpfrejit-shimctl/
  main.go                  # Go/static launch wrapper and syscall-stub hotpatcher
  patch_amd64.go
  patch_arm64.go
```

Modules deliberately absent in v2:

- no daemon protocol module,
- no remote fd passing module,
- no daemon-side state mirror,
- no runner socket protocol,
- no linked or dlopened `bpfopt` library.

Approximate LOC:

| Area | Estimate |
| --- | ---: |
| LD_PRELOAD wrappers and raw syscall handler ABI | 700-1000 |
| Attr copy, fd aliasing, and object metadata | 900-1300 |
| Program/map/link/attach state tables | 900-1400 |
| Worker, quiet-window timer, and bpfopt subprocess runner | 700-1100 |
| Candidate load and verifier-state parsing | 700-1200 |
| Attach swap recipes | 1100-1900 |
| Netlink and socket-option support | 700-1200 |
| Go syscall hotpatch launcher, x86_64 + arm64 | 900-1700 |

Total first all-seven-app implementation: roughly 5-8 KLOC. A C/C++-only PoC
for Katran, bpftrace, and BCC is roughly 2-3 KLOC.

Delivery:

- Build `libbpfrejit_shim.so` into the runtime image and set `LD_PRELOAD` in the
  suite entrypoint or per-runner environment.
- For Go apps, launch the real upstream binary through `bpfrejit-shimctl -- <real
  app> ...`, which hotpatches raw syscall stubs and starts the same in-process
  shim handler.
- Do not bind-mount the host workspace into benchmark containers. The repo rule
  forbids host workspace bind mounts; files must be delivered through image
  layers, with only system paths and result directories mounted
  (`CLAUDE.md:170-171`).
- Do not replace upstream app binaries with custom loaders. The shim is
  instrumentation around real startup, not a loader replacement
  (`CLAUDE.md:12-13`).

## 10. Risks and open questions

- Go symbol and syscall-stub stability. Cilium and OTel local checkouts say
  `go 1.25.0` (`runner/repos/cilium/go.mod:1-3`,
  `runner/repos/opentelemetry-ebpf-profiler/go.mod:1-11`), but Tracee and
  Tetragon are copied from upstream artifacts
  (`runner/containers/runner-runtime.Dockerfile:215-224`). Exact compiler
  versions, stripped symbols, and syscall stub layouts must be audited before
  hotpatching.
- `fork+exec` from inside a Go process. Go's own `os/exec` wraps process start
  through Go runtime/library machinery (`os/exec` source says it wraps
  `os.StartProcess`, [go.dev source](https://go.dev/src/os/exec/exec.go):115-117).
  The `syscall.ForkExec` docs call it a fork+exec combination that is careful to
  be thread safe ([pkg.go.dev syscall](https://pkg.go.dev/syscall@go1.26.0):2945-2950),
  and Go's `ForkLock` coordinates fd inheritance races
  ([pkg.go.dev syscall](https://pkg.go.dev/syscall@go1.26.0):2760-2774). A raw
  C `fork()` from an injected helper thread bypasses that coordination. Linux
  man-pages warn that after `fork()` in a multithreaded program, the child may
  safely call only async-signal-safe functions until `execve()`
  ([fork(2)](https://man7.org/linux/man-pages/man2/fork.2.html):92-101). The
  worker must use `posix_spawn()` where practical, or a minimal fork child that
  only performs async-signal-safe fd setup and `execve()` / `_exit()`. This
  needs real validation on Go apps.
- Static binaries. If any app ignores the dynamic loader, it must use the
  hotpatch path rather than `LD_PRELOAD`.
- Shim recursion. Candidate loads, internal `BPF_OBJ_GET_INFO_BY_FD`, hidden fd
  opens, map updates, and replacement attaches must stay under the recursion
  guard.
- Multi-process apps. `bcc/set` starts eight children; bpftrace/set starts one
  process per script; Tracee may involve a helper artifact. LD_PRELOAD can
  propagate through normal `execve`, but Go hotpatch and helper-process coverage
  need explicit launch handling.
- SUID/SGID binaries. `LD_PRELOAD` is ignored in secure-execution mode. Corpus
  artifacts should be audited before relying on preload.
- bpftrace ad-hoc scripts. The shim must tolerate repeated loads, many maps,
  perf events, and script exit cleanup in one process lifetime.
- Netlink correctness. Legacy XDP and TC replacement require exact parse and
  reconstruction of route netlink messages. Cilium legacy TC remains the largest
  correctness risk.
- Hidden fd lifetime. Hidden duplicates can extend object lifetime past the
  app-visible close. The shim must release them on detach, generation invalidity,
  failed optimization, and process exit.
- Perf-event fd replacement. `dup3()` preserves the numeric fd, but may not
  preserve mmap rings or app-specific event assumptions. OTel and bpftrace need
  audit before treating this as transparent.
- Thread concurrency. The swap lock must avoid fd-table corruption while
  accepting that non-atomic attach classes can have a short event gap.
- Runner measurement mapping. Userspace swap creates new program ids; runner and
  analysis must consume `logical_id` mapping instead of assuming id stability
  (`docs/tmp/userspace_speculative_opt_design.md:219-242`).
- Per-app shim crash recovery. A crash inside `libbpfrejit_shim.so` can terminate
  the app. The design needs crash-only behavior, clear logs, and probably a
  per-app "disable optimization after fatal internal error" mode, but that policy
  must not silently report success.
- `bpf_stats` ownership. The runner currently expects BPF stats to be enabled
  before sampling and errors otherwise (`runner/libs/bpf_stats.py:9-22`). Because
  the shim is the candidate loader, it may be tempting to call
  `bpf_enable_stats` from inside the shim for new programs. That interaction with
  runner sampling and global `/proc/sys/kernel/bpf_stats_enabled` needs a clear
  rule. Recommended benchmark default: runner owns stats enablement; shim only
  reads/logs whether stats were enabled.

## 11. What this design explicitly does not solve

- It does not help if the app loaded a BPF program before shim injection, or if
  the program appears only as an already-pinned kernel object with no captured
  original load attr.
- It does not preserve old `prog_id`s on a stock kernel. Result collection must
  treat old and candidate ids as distinct raw counter objects linked by shim
  metadata.
- It does not eliminate verifier/JIT latency during optimization. Candidate load
  still pays stock `BPF_PROG_LOAD` cost.
- It does not make all attach classes atomic. Perf-event, raw tracepoint,
  tracing, LSM, socket-filter, and some legacy netlink paths can have a short
  gap.
- It does not address concurrency between the app's own reload/swap behavior and
  shim-driven swap beyond generation checks. If the attachment generation
  changed after snapshot, first implementation should fail that logical program.
- It does not fully recover from every partial swap. The shim needs rollback
  recipes using hidden old prog/target fds, but some classes may fail after the
  old attachment has already been detached. Those failures must surface as
  errors.
- It does not cover non-standard control planes that bypass the observed syscall,
  ioctl, netlink, and socket-option surfaces. The correct behavior is an
  unsupported-attach error with enough captured evidence to add the surface.
- It does not solve concurrent `bpfopt` invocations from multiple shims. That
  global rate-limiting / cross-shim coordination problem is out of scope for v2
  and is addressed separately.
