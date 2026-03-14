# Non-Networking eBPF Evaluation Plan

Generated: 2026-03-11

## Executive summary

The current paired recompile evaluation is still overwhelmingly networking: 79 paired packet programs across 7 projects, dominated by `sched_cls` and `xdp`, with only 2 non-XDP/TC programs in the measured set (`tracee`'s `cgroup_skb` ingress/egress pair). However, the corpus already contains a much broader non-networking base:

- The latest runnability report lists 1007 tracing attach+trigger candidates and 215 tracing programs with positive `run_cnt` deltas.
- Large uncovered program classes already exist in the corpus: `kprobe` (508 programs), `tracing` (442), `tracepoint` (151), `raw_tracepoint` (103), `lsm` (75), and `struct_ops` (51).
- Local non-networking objects already built in this tree include `tracee`, `tetragon`, `systemd`, `coroot-node-agent`, `datadog-agent`, `opentelemetry-ebpf-profiler`, and `scx`.

The right OSDI move is not "more packet replay". It is an honest end-to-end attach+trigger path for security and observability agents, plus a real scheduler deployment path for `sched_ext`.

Recommended headline suite:

1. Tracee: best near-term security monitor because the object is already in the corpus, has diverse hook families, and already shows substantial directive coverage.
2. Tetragon: strongest second security case because it spans tracepoints, kprobes, and policy-driven enforcement, and already exposes BPF-side overhead metrics.
3. bpftrace: best observability case because it can emit ELF directly (`--emit-elf`) and gives a clear "same script, different JIT codegen" story.
4. `sched_ext` (`scx_rusty`, `scx_lavd`): best hot-path non-networking case; likely the strongest place for CMOV and possibly LEA to matter.

Useful backup or expansion cases:

- Falco modern eBPF probe: important security story, but build/integration complexity is higher than Tracee/Tetragon.
- Pixie/Stirling: valuable observability story, but the build path is more integrated and less `.bpf.o`-friendly.
- Hubble: useful observability-adjacent control, but it is still fundamentally Cilium networking datapath, so it does not carry the "beyond networking" claim by itself.
- systemd LSM, KubeArmor, Coroot, Datadog, and the OpenTelemetry profiler are good follow-on corpus additions or fallback demos.

## What "throughput" means outside networking

For non-networking eBPF systems, throughput should not be framed as packets per second. The right tuple is:

- Event throughput: sustained kernel events per second captured by the agent before drop or backpressure.
- Workload throughput: application-level throughput under monitoring, such as `execve`/s, file ops/s, HTTP req/s, Redis ops/s, or build tasks/min.
- Drop rate: lost perf/ringbuf events, probe overruns, or agent-side dropped events.
- Overhead: agent CPU, target CPU, p50/p99 latency inflation, and if available per-program BPF execution time.

For OSDI, each end-to-end experiment should report at least:

- Target workload throughput or latency.
- Sensor event rate.
- Drop/loss counters.
- CPU split between monitored workload and monitor agent.
- A "baseline JIT vs BpfReJIT" comparison with the same policy set, same workload, and same event volume.

## Current local corpus facts that matter

From `docs/tmp/corpus-runnability-report.md` and `docs/tmp/corpus-batch-recompile-results.md`:

- The current paired recompile suite contains 79 programs and is almost entirely packet replay.
- `tracee` is the only currently measured project that is not plain XDP/TC, and even there the measured pair is the `cgroup_skb` fallback path, not the main tracing hooks.
- The corpus already contains many non-networking program types that are loadable or at least buildable, but the current runner does not yet benchmark them honestly.

Important local objects already present:

| Local object | What it shows |
| --- | --- |
| `corpus/build/tracee/tracee.bpf.o` | Monolithic security tracer with `raw_tracepoint`, `kprobe`, `kretprobe`, `uprobe`, `cgroup_skb`, and `lsm` sections. The object is huge: about 3.49 MB text. |
| `corpus/build/tracee/lsm_check.bpf.o` | Minimal `lsm/bpf` support probe. |
| `corpus/build/tetragon/bpf_execve_event.bpf.o` | `tracepoint/sys_execve` sensor object, about 37 KB total. |
| `corpus/build/tetragon/bpf_generic_kprobe.bpf.o` | `kprobe` plus `fmod_ret` sensor object, about 156 KB total. |
| `corpus/build/scx/scx_rusty_main.bpf.o` | 11 `struct_ops` hooks plus 2 sleepable `struct_ops.s` hooks. |
| `corpus/build/scx/scx_lavd_main.bpf.o` | 22 `struct_ops` hooks plus 3 sleepable `struct_ops.s` hooks. |
| `corpus/build/systemd/userns-restrict.bpf.o` | Small real-world LSM object: 6 LSM hooks plus 1 kprobe. Good harness bring-up target. |
| `corpus/build/coroot-node-agent/ebpf.bpf.o` | Rich observability tracer with many `tracepoint`, `uprobe`, and `kprobe` sections; about 297 KB total. |
| `corpus/build/opentelemetry-ebpf-profiler/sched_monitor.bpf.o` | Small tracepoint-based observability object. |
| `corpus/build/datadog-agent/oom-kill-kern.bpf.o` | Small real-world `kprobe/oom_kill_process` object. |

Local Tracee detail is especially strong:

- The runnability report shows `tracee.bpf.o` contains 169 programs, 110 site-bearing programs, and 555 total directive sites.
- In the current measured packet suite, only `cgroup_skb_ingress` and `cgroup_skb_egress` are exercised, each with 110 sites.
- The current batch recompile results for those two programs show 214 WIDE sites and 6 CMOV sites total, with a code-size ratio of 1.090x and an exec-time ratio of 0.632x.

Implication: the paper already has local evidence that non-networking security code carries directive sites. What is missing is the honest end-to-end trigger path.

## 1. Security use cases

### 1.1 Tracee

#### What BPF programs does it use?

Local object inspection of `corpus/build/tracee/tracee.bpf.o` shows:

- 83 `kprobe/*` sections
- 27 `kretprobe/*` sections
- 28 `raw_tracepoint/*` sections
- 15 `uprobe/*` sections
- 2 `cgroup_skb/*` sections
- 1 `lsm/*` section

Representative hooks in the local object include:

- `raw_tracepoint/sys_enter`, `raw_tracepoint/sys_exit`, `raw_tracepoint/sched_process_exec`, `raw_tracepoint/sched_process_fork`, `raw_tracepoint/module_load`
- `kprobe/security_bprm_check`, `kprobe/security_file_open`, `kprobe/security_socket_connect`, `kprobe/cap_capable`, `kprobe/security_bpf`
- `uprobe/*` sections used for helper or feature fallback paths
- `cgroup_skb/ingress`, `cgroup_skb/egress`
- `lsm/file_open`

This is the best evidence in the current tree that Tracee is not "just one tracing hook"; it is a broad security monitor spanning syscall, process lifecycle, file, module, socket, and BPF-related hooks.

#### How should throughput be measured?

For Tracee, throughput should be reported as event-processing throughput, not packet throughput:

- Kernel events captured per second, broken down by event class if possible.
- Target workload throughput under monitoring:
  - `stress-ng --exec` or a fork/exec storm for process events
  - `fs_mark`, `fio`, or unpack/build workloads for file events
  - `wrk`/`redis-benchmark` for socket/connect activity
- Drop rate from perf/ringbuf backpressure.
- Tracee daemon CPU and memory.

Best OSDI-style experiment:

- Fix a realistic Tracee event set, such as `execve`, `open`, `security_file_open`, `connect`, and `module_load`.
- Run Tracee in CO-RE mode.
- Drive a workload mix that produces those events at controlled rates.
- Compare application slowdown and event loss between stock JIT and BpfReJIT.

#### Relevant directive families

- WIDE: high relevance. Tracee copies syscall arguments, paths, and event payloads. Current local measured pair already shows WIDE domination.
- CMOV: medium relevance. Security policies and event filters create branch-heavy predicates; the current pair already shows some CMOV sites.
- ROTATE: low relevance. Security tracing is not packet-bitfield heavy; any ROTATE wins will likely come from hashing or helper logic, not the common case.
- LEA: low to medium relevance. Possible in index arithmetic and serialization helpers, but not yet supported by local evidence.

#### What would end-to-end look like?

The honest path is attach+trigger, not synthetic `test_run`:

- Use Tracee itself to load and attach the programs.
- After the programs are loaded, identify the relevant program FDs or IDs and invoke `BPF_PROG_JIT_RECOMPILE`.
- Trigger real kernel events from user workloads.
- Measure target slowdown, Tracee CPU, event throughput, and drop rate.

`test_run` feasibility:

- Feasible today only for the two `cgroup_skb` programs already in the packet suite.
- Not honest for the main `raw_tracepoint`, `kprobe`, `uprobe`, or `lsm` paths.

#### Viability

Very high. Tracee is the strongest near-term non-networking end-to-end case already present in the corpus.

Sources:

- Local: `docs/tmp/corpus-runnability-report.md`
- Local: `docs/tmp/corpus-batch-recompile-results.md`
- Local: `corpus/build/tracee/tracee.bpf.o`, `corpus/build/tracee/lsm_check.bpf.o`
- Upstream: <https://github.com/aquasecurity/tracee/blob/main/pkg/ebpf/c/tracee.bpf.c>
- Upstream: <https://github.com/aquasecurity/tracee/blob/main/pkg/ebpf/c/lsmsupport/lsm_check.bpf.c>
- Docs: <https://aquasecurity.github.io/tracee/latest/>

### 1.2 Falco

#### What BPF programs does it use?

Falco's modern driver is a CO-RE eBPF probe embedded in the Falco userspace stack. Falco documents that its data source is primarily system calls, and the modern probe is the recommended probe on modern kernels. Internal source-tree notes from earlier corpus expansion also identified a multi-file modern BPF layout under `falcosecurity/libs` with attached event programs, dispatcher programs, and tail-called event handlers.

Practically, this means the Falco eBPF hot path is:

- syscall entry/exit capture
- event dispatch and event-specific formatting/filtering
- event export to userspace

This is a strong security-monitoring use case even if it does not look like a single monolithic `.bpf.o`.

#### How should throughput be measured?

Falco is the clearest place to use a two-axis throughput definition:

- Syscall capture throughput: sustained syscalls/s before event loss.
- Security-monitoring throughput: alerts/s or matched events/s under a fixed ruleset.
- Protected workload throughput: workload-level req/s or ops/s while Falco is running.

A clean experiment would pair:

- Falco with the modern eBPF probe enabled.
- `falcosecurity/event-generator` for known malicious or policy-triggering activity.
- A background system-call-heavy workload such as `sysbench fileio`, `fio`, `wrk`, or build/unpack activity.

The metric tuple should be:

- syscalls/s or events/s
- Falco dropped-event counters
- Falco CPU
- target workload throughput and p99 latency

#### Relevant directive families

- WIDE: medium to high relevance. Syscall argument extraction and event serialization should create byte-copy patterns.
- CMOV: medium relevance. Filtering, policy predicates, and dispatcher decisions should expose branch-sensitive sites.
- ROTATE: low relevance. Falco is not primarily a header parser.
- LEA: low to medium relevance. Possible in dispatch/index arithmetic, but not the first-order story.

#### What would end-to-end look like?

- Build or extract the modern BPF probe from the Falco/libs build.
- Start Falco with a fixed ruleset and modern probe.
- Re-JIT the loaded Falco programs after startup.
- Drive the event-generator plus a throughput workload.
- Measure alerts/s, drops, workload slowdown, and CPU.

`test_run` feasibility:

- No honest `test_run` path for the main Falco tracing/security hooks.
- This should be a live attach+trigger benchmark only.

#### How to obtain the `.bpf.o` files

Most concrete path:

- Build `falcosecurity/libs` or Falco with the modern BPF probe enabled, and capture the generated modern probe artifacts from the build output.
- If a single standalone checked-in `.bpf.o` is awkward to extract, add Falco to the corpus as a source-level build target instead of a raw object drop.

This is more complex than Tracee or Tetragon, but still viable.

#### Viability

High paper value, medium engineering complexity. Falco is worth adding, but it is not the fastest first implementation.

Sources:

- Local: `docs/tmp/corpus-expansion-round2.md`
- Local: `docs/tmp/macro-benchmark-design.md`
- Docs: <https://falco.org/docs/concepts/event-sources/kernel/>
- Docs: <https://falco.org/docs/setup/packages/>
- Performance PDF: <https://github.com/falcosecurity/libs/blob/master/test/e2e/tests/perf/test-output/Falco.eBPF.Kernel.Module.Performance.pdf>
- Event generator: <https://github.com/falcosecurity/event-generator>

### 1.3 Tetragon

#### What BPF programs does it use?

Tetragon is policy-driven runtime security and observability. Official docs expose `TracingPolicy` hook types including:

- kprobes
- tracepoints
- uprobes
- LSM hooks
- USDTs

Local objects already built in this tree:

- `corpus/build/tetragon/bpf_execve_event.bpf.o`
  - contains `tracepoint/sys_execve`
  - about 37 KB total
- `corpus/build/tetragon/bpf_generic_kprobe.bpf.o`
  - contains `kprobe/generic_kprobe`
  - contains `kprobe/generic_kprobe_override`
  - contains `fmod_ret/security_task_prctl`
  - about 156 KB total

So the answer to "are they available as `.bpf.o`?" is:

- Yes in this repository today, as build artifacts under `corpus/build/tetragon/`.
- Upstream they are build outputs, not the core unit of distribution.

#### How should throughput be measured?

Tetragon already publishes BPF overhead metrics, which is a major advantage over some other security agents. The best throughput plan is:

- Policy-hit throughput: matched events/s for a fixed `TracingPolicy`.
- Protected workload throughput: req/s, ops/s, or job completion time under the monitored workload.
- Tetragon BPF overhead metrics:
  - `tetragon_overhead_program_seconds_total`
  - `tetragon_overhead_program_runs_total`
  - `tetragon_missed_events_total`

Suggested workload mix:

- `sysbench` CPU/fileio
- `redis-benchmark`
- `wrk` or `nginx` HTTP load
- targeted trigger scripts for `execve`, `open`, `connect`, and policy hits

This gives both sustained event throughput and end-user slowdown.

#### Relevant directive families

- CMOV: medium to high relevance. Generic kprobe policy checks and override paths are predicate-heavy.
- WIDE: medium relevance. `execve` and argument/path capture should expose copy and serialization patterns.
- ROTATE: low relevance.
- LEA: low to medium relevance. Some arithmetic/indexing logic is plausible, but not yet locally measured.

#### What would end-to-end look like?

Best first end-to-end story:

- Use a small set of Tetragon `TracingPolicy` rules around `execve`, `open`, and selected security hooks.
- Start Tetragon agent.
- Re-JIT the corresponding loaded programs.
- Run controlled trigger workloads plus a steady-state throughput workload.
- Measure app slowdown, Tetragon overhead metrics, and event loss.

`test_run` feasibility:

- No honest `test_run` path for the real Tetragon `tracepoint`, `kprobe`, `uprobe`, or `fmod_ret` execution.
- This should be a live attach+trigger benchmark.

#### Viability

Very high. Tetragon is the cleanest security-monitoring complement to Tracee.

Sources:

- Local: `corpus/build/tetragon/bpf_execve_event.bpf.o`, `corpus/build/tetragon/bpf_generic_kprobe.bpf.o`
- Local: `docs/tmp/corpus-runnability-report.md`
- Docs: <https://tetragon.io/docs/concepts/tracing-policy/hooks/>
- Metrics: <https://tetragon.io/docs/reference/metrics/>
- Upstream: <https://github.com/cilium/tetragon/tree/main/bpf/process>

## 2. Observability use cases

### 2.1 bpftrace

#### Can we recompile bpftrace-generated programs?

Yes.

This is no longer speculative: the current bpftrace CLI exposes `--emit-elf FILE`, described in the source as "Emit ELF file with bpf programs". It also supports AOT generation (`--aot`) for a portable executable path.

That gives two viable routes:

- Artifact-first route: use `bpftrace --emit-elf out.o script.bt` to generate ELF and run the resulting BPF program via a controlled loader.
- Product-end-to-end route: minimally patch bpftrace so that after load, before attach or immediately after attach, it invokes `BPF_PROG_JIT_RECOMPILE` on the program FDs it already manages.

The first route is easier; the second is the stronger "real bpftrace deployment" claim.

#### What BPF programs does it generate?

bpftrace generates programs for whichever attach points the script requests, commonly:

- `kprobe` / `kretprobe`
- `tracepoint`
- `uprobe` / `uretprobe`
- `profile` / `perf_event`
- USDT

The right benchmark scripts are not toy one-liners. Use scripts that resemble real observability tools:

- syscall/open latency
- run queue latency
- off-CPU or wakeup timing
- malloc/free or TLS library probes

#### Relevant directive families

- CMOV: medium relevance in filters and aggregation conditions.
- WIDE: low to medium relevance, especially in string/path copies and argument marshaling.
- ROTATE: low relevance.
- LEA: low relevance.

#### What would end-to-end look like?

- Choose 3 to 5 representative scripts.
- Generate ELF with `--emit-elf`, or use stock bpftrace with a tiny re-JIT hook.
- Run a meaningful workload such as Linux kernel build, `fio`, `wrk`, or `redis-benchmark`.
- Measure traced workload slowdown, bpftrace CPU, events/s, and lost-event counters.

`test_run` feasibility:

- No general honest `test_run` path for the real generated tracing programs.
- Use live attach+trigger.

#### Viability

High. bpftrace is the cleanest observability-specific "same source script, same semantics, better JIT lowering" story.

Sources:

- Upstream CLI source: <https://github.com/bpftrace/bpftrace/blob/master/src/main.cpp>
- Upstream AOT runtime: <https://github.com/bpftrace/bpftrace/blob/master/src/aot/aot_main.cpp>
- Docs: <https://bpftrace.org/docs/release_024/language>

### 2.2 Pixie / Stirling

#### What BPF programs does it use?

Pixie documents that Stirling uses BCC and a mix of:

- kprobes for kernel-side socket and syscall visibility
- uprobes for user-library and application protocol visibility
- perf-event or sampling paths for profiling

The public architecture and source tree point especially at:

- socket tracing
- TLS tracing
- application-layer protocol tracing
- continuous profiling

Local source-mirroring notes already concluded that Pixie is build-system-integrated rather than a clean checked-in `.bpf.o` corpus. That is still the key friction point.

#### Relevant directive families

- WIDE: medium to high relevance. Socket payload and TLS read/write handling are copy-heavy.
- CMOV: medium relevance. Protocol dispatch and filtering create branch-heavy paths.
- ROTATE: low relevance.
- LEA: low to medium relevance in protocol parsing and buffer indexing.

#### What would end-to-end look like?

- Run Pixie/Stirling on a node or small cluster.
- Enable one focused connector set, such as HTTP/TLS or socket tracing, rather than the full platform.
- Drive app traffic with `wrk`, `fortio`, or `redis-benchmark`.
- Measure app throughput, agent CPU, event throughput, and drop counters.

`test_run` feasibility:

- Not practical as a headline path.
- Use live attach+trigger only.

#### How to obtain the `.bpf.o` files

This is the main weakness:

- Pixie's production probes are not exposed as a simple stable `.bpf.o` inventory the way Tracee or Tetragon can be.
- The likely path is to capture build artifacts from Pixie's build pipeline or, for a first paper pass, use a simpler observability project already in the corpus such as Coroot or the OpenTelemetry profiler.

#### Viability

Medium paper value, medium to high engineering cost. Good second-wave observability target, but not the fastest path to a polished OSDI result.

Sources:

- Local: `docs/tmp/corpus-expansion-round2.md`
- Local: `docs/tmp/macro-benchmark-design.md`
- Architecture blog: <https://px.dev/blog/how-we-built-pixie>
- Docs: <https://docs.px.dev/about-pixie/pixie-ebpf/>
- Upstream tree: <https://github.com/pixie-io/pixie/tree/main/src/stirling>

### 2.3 Hubble

#### What BPF programs does it use?

Hubble itself is not the right place to look for standalone BPF objects. The BPF hot path lives in Cilium's datapath and Hubble consumes the resulting flow visibility.

Local Cilium objects already built here show:

- `corpus/build/cilium/bpf_xdp.bpf.o`
  - `xdp/entry`
  - `xdp/tail`
- `corpus/build/cilium/bpf_lxc.bpf.o`
  - `tc/entry`
  - `tc/tail`
- `corpus/build/cilium/bpf_overlay.bpf.o`
  - `tc/entry`
  - `tc/tail`

So Hubble is useful as observability-adjacent evidence, but it does not add a new non-networking program class. It is still fundamentally XDP/TC networking datapath plus flow export.

#### Relevant directive families

- CMOV: high relevance
- WIDE: high relevance
- ROTATE: medium to high relevance
- LEA: low

This is basically the same directive mix as Cilium datapath benchmarking, not a new domain.

#### What would end-to-end look like?

- Run Cilium with Hubble enabled.
- Generate network flows and consume them with `hubble observe`.
- Measure flow export throughput, cilium-agent CPU, and app throughput.

This is valid as an observability deployment, but weak as "beyond networking".

`test_run` feasibility:

- Yes for isolated XDP/TC datapath programs.
- No for the full Hubble observability path.

#### Viability

Useful supporting evidence, not a headline non-networking case.

Sources:

- Local: `corpus/build/cilium/bpf_xdp.bpf.o`, `corpus/build/cilium/bpf_lxc.bpf.o`, `corpus/build/cilium/bpf_overlay.bpf.o`
- Docs: <https://docs.cilium.io/en/latest/observability/hubble/>
- Docs: <https://docs.cilium.io/en/latest/observability/>

## 3. Scheduler use cases (`sched_ext`)

### 3.1 `scx_rusty`

Local object inspection of `corpus/build/scx/scx_rusty_main.bpf.o` shows:

- 11 `struct_ops/*` hooks
- 2 `struct_ops.s/*` sleepable hooks
- about 91 KB total object size

Representative hooks:

- `rusty_select_cpu`
- `rusty_enqueue`
- `rusty_dispatch`
- `rusty_runnable`
- `rusty_running`
- `rusty_init`
- `rusty_init_task`

This is clearly not a toy demo. It is rich enough to be a real hot-path scheduler candidate.

### 3.2 `scx_lavd`

Local object inspection of `corpus/build/scx/scx_lavd_main.bpf.o` shows:

- 22 `struct_ops/*` hooks
- 3 `struct_ops.s/*` sleepable hooks
- about 1.08 MB total size because of large BSS/state

Representative hooks:

- `lavd_select_cpu`
- `lavd_enqueue`
- `lavd_dequeue`
- `lavd_dispatch`
- `lavd_runnable`
- `lavd_running`
- `lavd_tick`
- `lavd_cpu_online`
- `lavd_cpu_offline`
- `lavd_init`

This is probably the richest non-networking hot path in the current local tree.

### 3.3 Would JIT directives help here?

Probably yes, and the directive mix is different from networking:

- CMOV: likely the most important family. CPU selection, queue choice, and runnable-state tests are branch-heavy and latency-sensitive.
- LEA: more plausible here than in tracing/security. Scheduler code often computes indices, weights, queue positions, and scaled values.
- WIDE: lower relevance than Tracee/Falco/Tetragon because scheduler logic is not mainly byte-copy or event serialization.
- ROTATE: likely negligible.

This makes `sched_ext` valuable for two reasons:

- It broadens the paper beyond tracing and networking.
- It is one of the best bets for finding a domain where CMOV and perhaps LEA matter more than WIDE.

### 3.4 What would end-to-end look like?

Do not make `struct_ops test_run` the headline result. Earlier local design notes are right: the current `struct_ops test_run` path is dummy-oriented and not faithful to real scheduler execution.

The honest path is:

- boot a kernel with `CONFIG_SCHED_CLASS_EXT`
- register `scx_rusty` or `scx_lavd`
- re-JIT the loaded scheduler programs
- run real scheduler-sensitive workloads

Recommended metrics:

- scheduler latency: wakeup-to-run p50/p99
- throughput: `hackbench`, `schbench`, `sysbench`, memcached/redis throughput, kernel build wall time
- context switches/s
- CPU migrations/s
- CPU utilization
- tail latency under contention

`test_run` feasibility:

- Exists in the kernel in some form for `struct_ops`.
- Not strong enough to be the paper's end-to-end claim for `scx_rusty` or `scx_lavd`.

### 3.5 Viability

Very high paper value, medium to high environment complexity. This is the best "hot-path non-networking" story in the tree.

Sources:

- Local: `corpus/build/scx/scx_rusty_main.bpf.o`, `corpus/build/scx/scx_lavd_main.bpf.o`
- Local: `docs/tmp/real-world-benchmark-design.md`
- Upstream: <https://github.com/sched-ext/scx>
- Docs: <https://sched-ext.com/>

## 4. Practical evaluation plan

### 4.1 Recommended use-case matrix

| Use case | How to obtain `.bpf.o` | Load and run | `test_run` feasibility | Metrics | Expected directive coverage | Recommendation |
| --- | --- | --- | --- | --- | --- | --- |
| Tracee | Use existing `corpus/build/tracee/tracee.bpf.o` or build from `pkg/ebpf/c/tracee.bpf.c` | Start Tracee normally, re-JIT loaded program FDs, drive exec/file/socket workloads | Honest only for `cgroup_skb`; main tracing paths need live attach | events/s, drops, app ops/s, p99 latency, Tracee CPU | Measured high WIDE, some CMOV; full object estimated medium/high CMOV+WIDE | Primary security case |
| Falco modern probe | Build `falcosecurity/libs`/Falco modern probe and capture generated objects from build output | Start Falco with modern probe, re-JIT loaded programs, run event-generator plus workload | No honest `test_run` | syscalls/s, alerts/s, drops, app req/s, Falco CPU | Estimated medium CMOV, medium/high WIDE, low ROTATE/LEA | Strong second-wave security case |
| Tetragon | Use existing `corpus/build/tetragon/*.bpf.o` or build from `bpf/process/*.c` | Start Tetragon with selected `TracingPolicy`, re-JIT loaded programs, run trigger workloads | No honest `test_run` | policy hits/s, app ops/s, `tetragon_overhead_program_seconds_total`, `tetragon_overhead_program_runs_total`, `tetragon_missed_events_total` | Estimated medium/high CMOV, medium WIDE, low ROTATE | Primary security case |
| bpftrace | Use `bpftrace --emit-elf out.o script.bt`, or patch bpftrace to re-JIT its own loaded FDs | Run background tracing during build/web/storage workload | No general honest `test_run` | traced-workload slowdown, events/s, lost events, bpftrace CPU | Expected low/medium CMOV, low/medium WIDE | Primary observability case |
| Pixie / Stirling | Capture build artifacts from Pixie build, or postpone in favor of simpler observability projects | Run focused connector set on app traffic | No practical headline `test_run` | app req/s, agent CPU, events/s, drops | Estimated medium CMOV, medium/high WIDE | Good but not first-wave |
| Hubble / Cilium | Use existing `corpus/build/cilium/*.bpf.o` | Run Cilium+Hubble and generate flows | XDP/TC programs can use `test_run`, but Hubble end-to-end cannot | flows/s, cilium-agent CPU, app throughput | High CMOV/WIDE/ROTATE, but still networking | Supporting control, not headline |
| `scx_rusty` | Use existing `corpus/build/scx/scx_rusty_main.bpf.o` or upstream build output | Enable scheduler, register scheduler, re-JIT loaded programs, run scheduler workloads | `struct_ops test_run` exists but is not headline-quality | wakeup latency, throughput, migrations, context switches, CPU | Expected high CMOV, medium LEA, low WIDE/ROTATE | Primary scheduler case |
| `scx_lavd` | Use existing `corpus/build/scx/scx_lavd_main.bpf.o` or upstream build output | Same as above | Same caveat | Same as above | Expected high CMOV, medium LEA, low WIDE/ROTATE | Primary scheduler case |

### 4.2 Best phased rollout

Phase 1, fastest credible OSDI additions:

1. Tracee
2. Tetragon
3. bpftrace

Phase 2, strongest extra breadth:

1. `scx_rusty`
2. `scx_lavd`
3. Falco

Phase 3, backup or expansion:

1. systemd LSM
2. Coroot node agent
3. OpenTelemetry profiler
4. Pixie

## 5. Current corpus gap analysis

### 5.1 What program types are missing from the current measured evaluation?

The measured paired-recompile suite is almost entirely `sched_cls` and `xdp`. That is the main gap.

From the latest runnability report, the corpus already contains large non-networking classes that are not represented in the current paired evaluation:

- `kprobe`: 78 objects, 508 programs, 405 loadable
- `tracing`: 156 objects, 442 programs, 241 loadable
- `tracepoint`: 42 objects, 151 programs, 130 loadable
- `raw_tracepoint`: 43 objects, 103 programs, 78 loadable
- `lsm`: 29 objects, 75 programs, 49 loadable
- `struct_ops`: 13 objects, 51 programs, 35 loadable
- `perf_event`: 17 objects, 21 programs, 19 loadable
- `syscall`: 23 objects, 74 programs, 49 loadable

The paper gap is therefore not corpus discovery. It is runnable, honest end-to-end measurement for these classes.

### 5.2 What workload categories are underrepresented?

Most underrepresented today:

- Security monitoring agents
- Observability and tracing agents
- LSM-based enforcement and policy
- Uprobe-heavy userspace instrumentation
- Scheduler hot paths (`struct_ops`)
- Storage and file-I/O tracing
- Process lifecycle and exec tracing

Overrepresented today:

- packet parsing and forwarding
- XDP and TC datapaths

### 5.3 What does the corpus already have that we are not exploiting?

Already present in this tree:

- Tracee: the strongest current security object
- Tetragon: build artifacts already exist
- systemd LSM: small real-world LSM program, good pilot
- Coroot node agent: rich observability tracer, already built
- OpenTelemetry profiler: small tracepoint observability probe
- Datadog agent: simple real-world `kprobe`
- `scx`: scheduler objects already built locally

Important nuance:

- `scx` is not yet represented in `corpus/repos.yaml`, so the official corpus manifest still undercounts scheduler coverage even though local build artifacts exist.
- Falco and Pixie were scanned in earlier corpus work but not promoted because the project focus was networking. For the OSDI non-networking story, that decision should be revisited.

### 5.4 Specific projects to add or promote

Highest priority additions or promotions:

1. `falcosecurity/libs` / Falco modern probe
   - Why: major production security monitor, strong syscall-throughput framing
   - Missing today: source-level build integration into the corpus and live attach benchmark
2. `sched-ext/scx`
   - Why: unique scheduler/hot-path story, likely strongest CMOV/LEA case
   - Missing today: manifest integration and real scheduler benchmark path
3. `bpftrace` script corpus
   - Why: best observability-specific story, ELF emission already supported
   - Missing today: curated script set and a small re-JIT integration path
4. Pixie or a simpler observability fallback
   - Best full target: Pixie/Stirling
   - Best pragmatic fallback: Coroot node agent or OpenTelemetry profiler
5. LSM security corpus
   - systemd `userns-restrict`
   - KubeArmor
   - Tetragon LSM policies

Recommended ranking by "paper value per engineering week":

1. Tracee
2. Tetragon
3. bpftrace
4. `scx_rusty`
5. `scx_lavd`
6. Falco
7. systemd LSM
8. Coroot
9. Pixie

## Bottom line

For OSDI, the strongest beyond-networking story is:

- security monitoring: Tracee and Tetragon
- observability: bpftrace
- scheduling: `scx_rusty` or `scx_lavd`

Falco is worth adding if time allows, but it is not the shortest path. Hubble should be treated as observability-adjacent supporting evidence, not as the main non-networking claim. The corpus gap is no longer "do we have programs?" but "do we have an honest live attach+trigger and scheduler deployment path for the programs we already have?"
