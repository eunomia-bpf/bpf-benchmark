# Macro eBPF Benchmark Design

Date: 2026-03-10

## Goal

Build a standardized macro or real-program benchmark layer on top of the existing `micro_exec` and scanner stack without modifying existing `micro/` sources. The deliverables in this pass are:

- a production-program search and triage matrix
- a declarative corpus manifest at `config/macro_corpus.yaml`
- a runner at `micro/run_macro_corpus.py`
- a curated set of compiled `.bpf.o` artifacts under `corpus/build/`

## Search and triage method

For each candidate project I did the following:

1. verified public GitHub visibility with `curl https://api.github.com/repos/<owner>/<repo>`
2. used sparse or shallow clones under `/tmp/bpf-macro-bench/` when the repo was not already present locally
3. located representative BPF sources by scanning for `*.bpf.c`, `*_kern.c`, `*.ebpf.c`, `main.bpf.c`, or project-specific BPF directories
4. classified build complexity as:
   - `low`: direct clang compile with ordinary include paths
   - `medium`: repo-specific headers or generated `vmlinux.h`
   - `high`: custom macros, composite linking, externs, or nonstandard sections
5. evaluated runtime fit for one of:
   - `bpf_prog_test_run`
   - `attach_trigger`
   - `compile_only`

## Search results summary

The table below is the usable corpus inventory after search, shallow clone, source-path discovery, and first-pass compile or runtime triage.

| Project | Repo | GitHub status | Representative BPF source paths | BPF source scale | Build complexity | Current status | Best benchmark method | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Cilium datapath / Hubble substrate | https://github.com/cilium/cilium | public `200` | `bpf/bpf_xdp.c`, `bpf/bpf_lxc.c`, `bpf/bpf_overlay.c` | large, `bpf/` has about 139 C sources | high | existing local objects compile, but current libbpf open path rejects static `xdp/tail` and `tc/tail` sections | not in runnable corpus yet | Hubble observability is built on Cilium BPF state; `https://github.com/cilium/hubble` is public but does not provide a richer standalone `.bpf.c` corpus than Cilium itself |
| Katran | https://github.com/facebookincubator/katran | public `200` | `katran/lib/bpf/balancer.bpf.c`, `katran/lib/bpf/healthchecking.bpf.c` | 2 main production objects | medium | `balancer.bpf.o` already compiled and verified with `bpf_prog_test_run` | `bpf_prog_test_run` | cleanest production XDP LB in the current corpus |
| Calico | https://github.com/projectcalico/calico | public `200` | local compiled objects include `xdp_no_log.bpf.o`, `from_hep_debug.bpf.o`, `to_wep_debug.bpf.o` | multiple large datapath objects | high | existing local objects compile and selected XDP or TC programs run successfully | `bpf_prog_test_run` | `calico_xdp_main` and `calico_tc_maglev` are in the runnable corpus |
| loxilb | https://github.com/loxilb-io/loxilb | public `200` | local compiled objects include `llb_xdp_main.bpf.o`, `llb_ebpf_main.bpf.o` | several custom datapath objects | high | compiles, but current standalone load fails because sections such as `xdp_packet_hook` do not map cleanly to libbpf prog types | not in runnable corpus yet | good future candidate once the runner supports explicit prog-type overrides on custom section names |
| Cloudflare flowtrackd / xdp-filter | not found as public GitHub repos under `cloudflare/flowtrackd` or `cloudflare/xdp-filter` | `404` | n/a | n/a | n/a | no public repo found in this pass | n/a | keep out of corpus until a public source repo is identified |
| Tracee | https://github.com/aquasecurity/tracee | public `200` | `pkg/ebpf/c/tracee.bpf.c`, `pkg/ebpf/c/lsmsupport/lsm_check.bpf.c` | 3 main sources in sparse checkout, one monolithic multi-probe object | medium to high | `lsm_check.bpf.o` and `tracee.bpf.o` compiled; load and attach checks succeeded | `attach_trigger` | `lsm_check` is a minimal single-prog LSM probe; `tracee.bpf.o` is a realistic monolithic tracing object |
| Tetragon | https://github.com/cilium/tetragon | public `200` | `bpf/process/bpf_execve_event.c`, `bpf/process/bpf_generic_kprobe.c` | about 32 BPF sources under `bpf/` | medium to high | representative objects compiled; `bpf_execve_event.bpf.o` is stable as `bpftool loadall` compile-only, while `autoattach` is not stable enough for the current runner | `compile_only` today | still valuable as a real security and observability tracepoint pipeline |
| KubeArmor | https://github.com/kubearmor/KubeArmor | public `200` | `KubeArmor/BPF/enforcer.bpf.c`, `system_monitor.c`, `protectproc.bpf.c` | at least 9 BPF sources | medium to high | objects compile, but load currently fails on `kubearmor_containers` map creation with `-EINVAL` | not in runnable corpus yet | valuable LSM corpus once map/init assumptions are modeled |
| Coroot node agent | https://github.com/coroot/coroot-node-agent | public `200` | `ebpftracer/ebpf/ebpf.c`, plus included fragments like `proc.c`, `file.c`, `tcp/state.c`, `l7/*.c` | one top-level object pulling many fragments | medium | `ebpf.bpf.o` compiles and loads cleanly with `bpftool loadall`; full autoattach is not stable enough for the default suite | `compile_only` today | best fit in the current framework is a scoped compile-only slice such as `task_newtask`, `sched_process_exit`, `oom_mark_victim` |
| Datadog agent | https://github.com/DataDog/datadog-agent | public `200` | `pkg/collector/corechecks/ebpf/c/runtime/oom-kill-kern.c`, `tcp-queue-length-kern.c`, `noisy-neighbor-kern.c`, `pkg/network/ebpf/c/tracer.c` | at least 4 direct production C entrypoints in this pass | medium to high | `oom-kill-kern.c` compiles in `COMPILE_CORE` mode and load/compile-only checks succeed; `noisy-neighbor-kern.c` compiles but standalone load fails on unresolved extern telemetry state | `compile_only` today | a good source of observability and security probes even when safe triggers are unavailable |
| Parca agent | https://github.com/parca-dev/parca-agent | public `200` | no primary C probes in repo; Go module depends on `go.opentelemetry.io/ebpf-profiler` and replaces it with `github.com/parca-dev/opentelemetry-ebpf-profiler` | wrapper around external profiler repo | medium | cataloged, but its BPF sources live in the profiler dependency rather than inside `parca-agent` | indirect via OTel profiler | treat as provenance for the profiler corpus, not an independent `.bpf.c` repository |
| OpenTelemetry eBPF profiler | https://github.com/open-telemetry/opentelemetry-ebpf-profiler | public `200` | `support/ebpf/native_stack_trace.ebpf.c`, `sched_monitor.ebpf.c`, `generic_probe.ebpf.c`, many language tracers | about 17 `*.ebpf.c` sources | high | representative sources compile, but standalone load fails because objects expect extern maps or composite linking | not in runnable corpus yet | strong compile corpus, weak standalone runtime corpus |
| bpftrace AOT | https://github.com/bpftrace/bpftrace | public `200` | AOT runtime is in `src/aot/aot_main.cpp`; probes are generated from scripts rather than checked in as stable `.bpf.c` objects | generated at build or runtime, not a fixed source corpus | high | cataloged only | not used directly | useful conceptually, but not a declarative fixed-object corpus without a separate script corpus and generation step |
| Pixie / Stirling | https://github.com/pixie-io/pixie | public `200` | sparse checkout under `src/stirling/bpf_tools/` showed mostly tests or helper C files such as `rr/testing/bpf/rr_test.c` and `bcc_bpf/task_struct_mem_read.c` | very limited standalone C in the sparse path | high | cataloged only | not used directly | the production tracer pipeline is more build-system integrated than the current corpus can ingest directly |
| Falco modern eBPF driver | https://github.com/falcosecurity/libs | public `200` | `driver/modern_bpf/programs/attached/events/*.bpf.c`, `.../dispatchers/*.bpf.c`, `.../tail_called/events/*.bpf.c` | very large, at least about 172 `*.bpf.c` sources in sparse checkout | high | cataloged, no compile pass yet | likely `attach_trigger` | large and valuable future security corpus, but needs composite build logic and event dispatcher setup |
| sched_ext / SCX | https://github.com/sched-ext/scx | public `200` | `scheds/rust/scx_rusty/src/bpf/main.bpf.c`, `scheds/rust/scx_lavd/src/bpf/main.bpf.c`, many `lib/*.bpf.c` helpers | about 68 BPF sources | high | representative schedulers compile, but object open fails on missing extern BTF such as `sdt_alloc_init` or `get_task_ctx_internal` | not in runnable corpus yet | compile-successful, standalone-load blocked |
| Linux selftests | https://github.com/torvalds/linux | public `200` | `tools/testing/selftests/bpf/progs/test_tc_bpf.c`, `xdp_synproxy_kern.c`, `tools/testing/selftests/sched_ext/minimal.bpf.c` | about 44 relevant BPF sources in sparse checkout | low to high | TC and XDP selftests compile and run; sched_ext minimal compiles but is not a clean fit for the current runner | `bpf_prog_test_run` and selective `compile_only` | used as support or control benchmarks, not as headline production corpus |
| systemd cgroup BPF | local existing corpus, repo search not repeated in this pass | local compiled object `corpus/build/systemd/sysctl-monitor.bpf.o` | multiple systemd-managed policy objects already in `corpus/build/systemd/` | medium | `sysctl-monitor.bpf.o` compile-only path succeeds; `bpf_prog_test_run` does not work for this hook in current kernel | `compile_only` | useful non-network real-world hook coverage |
| Netfilter BPF hooks / OVS BPF datapath / fuse-bpf | search inconclusive in this pass | n/a | no stable public standalone production corpus identified quickly enough for this pass | n/a | catalog only | not yet compiled | future work | kernel support exists in parts of the stack, but I did not identify a clean public standalone corpus to ingest today |

## Compiled and verified artifacts

These are the concrete objects currently compiled into `corpus/build/` and their runtime disposition in this environment.

| Output object | Source or provenance | Status | Benchmark method | Notes |
| --- | --- | --- | --- | --- |
| `corpus/build/katran/balancer.bpf.o` | Katran `balancer.bpf.c` | `bpf_prog_test_run` success | `bpf_prog_test_run` | program `balancer_ingress` |
| `corpus/build/calico/xdp_no_log.bpf.o` | Calico XDP datapath | `bpf_prog_test_run` success | `bpf_prog_test_run` | program `calico_xdp_main` |
| `corpus/build/calico/from_hep_debug.bpf.o` | Calico TC host-endpoint datapath | `bpf_prog_test_run` success | `bpf_prog_test_run` | program `calico_tc_maglev` |
| `corpus/build/suricata/xdp_filter.bpf.o` | Suricata XDP filter | `bpf_prog_test_run` success | `bpf_prog_test_run` | program `xdp_hashfilter` |
| `corpus/build/linux-selftests/test_tc_bpf.bpf.o` | Linux selftests | `bpf_prog_test_run` success | `bpf_prog_test_run` | programs `cls` and `pkt_ptr` |
| `corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o` | Linux selftests | `bpf_prog_test_run` success | `bpf_prog_test_run` | programs `syncookie_xdp` and `syncookie_tc` |
| `corpus/build/systemd/sysctl-monitor.bpf.o` | existing local systemd corpus | load success, runtime replay unsupported | `compile_only` | `--compile-only` succeeds, direct `bpf_prog_test_run` fails |
| `corpus/build/datadog-agent/oom-kill-kern.bpf.o` | Datadog `oom-kill-kern.c` compiled in `COMPILE_CORE` mode | load success, no safe trigger | `compile_only` | direct `micro_exec --compile-only` succeeds |
| `corpus/build/tracee/lsm_check.bpf.o` | Tracee LSM support probe | attach and trigger success | `attach_trigger` | trigger via `bpftool prog show` |
| `corpus/build/tetragon/bpf_execve_event.bpf.o` | Tetragon execve pipeline | load success, autoattach unstable | `compile_only` | `bpftool prog loadall` succeeds and is used by the compile-only backend |
| `corpus/build/tracee/tracee.bpf.o` | Tracee monolithic tracer | autoattach succeeds, but default suite runtime is too heavy | excluded from default manifest | kept as a verified future candidate |
| `corpus/build/coroot-node-agent/ebpf.bpf.o` | Coroot multi-fragment tracer | load success, autoattach unstable | `compile_only` | current manifest uses `bpftool loadall` compile-only with a scoped process-lifecycle subset |
| `corpus/build/KubeArmor/enforcer.bpf.o` | KubeArmor LSM enforcer | compile success, load fail | excluded | map `kubearmor_containers` fails with `-EINVAL` |
| `corpus/build/KubeArmor/protectproc.bpf.o` | KubeArmor | compile success, load fail | excluded | same map issue |
| `corpus/build/opentelemetry-ebpf-profiler/*.bpf.o` | OTel profiler | compile success, load fail | excluded | unresolved extern state or composite-link assumptions |
| `corpus/build/scx/scx_rusty_main.bpf.o` | SCX | compile success, open fail | excluded | missing extern BTF `sdt_alloc_init` |
| `corpus/build/scx/scx_lavd_main.bpf.o` | SCX | compile success, open fail | excluded | missing extern BTF `get_task_ctx_internal` |
| `corpus/build/cilium/*.bpf.o` | Cilium | compile success, object open fail | excluded | static tail sections rejected by current load path |
| `corpus/build/loxilb/*.bpf.o` | loxilb | compile success, load fail | excluded | custom section names need explicit prog-type handling |

## Standardized benchmark framework

## Design principles

The macro layer should be declarative and minimally invasive:

- one YAML entry per benchmark unit
- one prebuilt `.bpf.o` per entry
- no modifications to existing `micro/` sources
- reuse `micro/build/runner/micro_exec` whenever possible
- preserve the micro JSON result shape so downstream analysis does not fork

## Benchmark methods

The runner supports exactly three benchmark methods:

### 1. `bpf_prog_test_run`

Use `micro_exec run-kernel` with:

- explicit `--program-name`
- packet or context fixtures
- optional `--recompile-v5 --recompile-all`

This is the preferred path for:

- XDP
- TC
- any other prog type already handled by the existing kernel runner

### 2. `attach_trigger`

Use:

1. `bpftool prog loadall <obj> <pin-dir> [kernel_btf ...] autoattach`
2. enumerate attached programs from pinned links
3. optionally apply BpfReJIT v5 using `scanner/build/bpf-jit-scanner apply --prog-fd ...`
4. execute a user-specified trigger command
5. query `bpftool prog show id <id>` for code size metadata

This is the right path for:

- kprobe
- tracepoint
- raw tracepoint
- LSM
- fentry or fexit style probes when they are designed for real attach points

Important limitation:

- `bpftool loadall autoattach` loads the whole object. `program_names` currently scope reporting, selected-code-size accounting, and recompile targets, but they do not prevent the rest of the object from loading if the object is monolithic.

### 3. `compile_only`

Use either:

- `micro_exec run-kernel --compile-only`, or
- `bpftool prog loadall <obj> <pin-dir>` without `autoattach`

to measure:

- object open time
- kernel load and JIT time
- code size

without invoking runtime replay.

This is the current fallback for:

- hooks unsupported by `bpf_prog_test_run`
- probes with no safe deterministic trigger
- real objects that load cleanly but do not autoattach cleanly as a unit

## YAML schema

The new manifest lives at `config/macro_corpus.yaml`.

Top-level fields:

- `suite_name`: logical suite identifier
- `corpus`: optional provenance block for repo inventory
- `defaults`: default `iterations`, `warmups`, `repeat`, and output path
- `build`: paths to `micro_exec`, `bpftool`, and the scanner
- `runtimes`: runtime modes, currently `kernel` and `kernel_recompile_v5`
- `programs`: array of benchmark entries

Per-program fields:

- `name`: stable benchmark id
- `description`: human-readable description
- `source`: compiled `.bpf.o`
- `prog_type`: declared hook family
- `test_method`: one of `bpf_prog_test_run`, `attach_trigger`, `compile_only`
- `compile_loader`: optional compile-only backend, currently `micro_exec` or `bpftool_loadall`
- `program_name` or `program_names`: exact program selection inside the object
- `sections`: optional section filters
- `io_mode`: packet or context for `test_run`
- `test_input`: packet or context blob
- `input_size`: bytes of input fixture
- `trigger`: shell command for `attach_trigger`
- `trigger_timeout_seconds`: timeout for the trigger command
- `category`, `family`, `level`, `hypothesis`, `tags`: metadata reused in output JSON
- `btf_path`: optional kernel BTF override
- `recompile_supported`: optional runtime mask when re-JIT should be disabled

Example:

```yaml
  - name: tetragon_execve
    source: corpus/build/tetragon/bpf_execve_event.bpf.o
    prog_type: tracepoint
    test_method: compile_only
    compile_loader: bpftool_loadall
    program_names: [event_execve, execve_rate, execve_send]
    tags: [security, observability, production, compile-only]
```

## Integration with the existing micro framework

The integration approach is additive:

- new runner: `micro/run_macro_corpus.py`
- new config: `config/macro_corpus.yaml`
- no edits to existing `micro/run_micro.py`, `benchmark_catalog.py`, or kernel runner sources

The macro runner reuses the existing micro runner for all `test_run` and `compile_only` cases and emits the same top-level JSON structure:

- `suite_name`
- `manifest_path`
- `generated_at`
- `host`
- `defaults`
- `benchmarks[]`

Each benchmark still contains `runs[]`, and each run still reports:

- `compile_ns`
- `exec_ns`
- `timing_source`
- `phases_ns`
- `perf_counters`
- `perf_counters_meta`
- `derived_metrics`
- `result_distribution`
- `code_size`

`attach_trigger` adds sample-level metadata without breaking the schema:

- `attached_programs`
- `trigger`
- `bpftool_command`
- recompile details when v5 re-JIT is enabled

## BpfReJIT support

The macro runner supports two runtimes:

- `kernel`
- `kernel_recompile_v5`

For `attach_trigger`, BpfReJIT works by:

1. loading and autoattaching the object
2. resolving program ids from pinned links
3. obtaining live program fds via `libbpf.bpf_prog_get_fd_by_id`
4. invoking `scanner/build/bpf-jit-scanner apply --prog-fd <fd> --all --v5`
5. running the configured trigger

For `bpf_prog_test_run` and `compile_only`, the runner forwards `--recompile-v5 --recompile-all` directly to `micro_exec`.

## Current gaps and next steps

The current framework is useful now, but a few real-program classes remain outside the runnable corpus:

- Cilium needs either a libbpf path that tolerates the static tail sections in these objects or a preprocessing step that strips non-loadable static sections.
- loxilb needs explicit prog-type overrides for its custom section names.
- KubeArmor needs map initialization or compat handling for `kubearmor_containers`.
- OTel profiler and likely Parca need composite-link or extern-map modeling instead of standalone source compilation.
- SCX and Linux `sched_ext` need a dedicated struct-ops aware loader and code-size accounting path.
- Falco is a strong future corpus, but it needs dispatcher or tail-call aware build automation before it can be loaded as a faithful unit.

## Output files from this pass

- Design doc: `docs/tmp/macro-benchmark-design.md`
- Manifest: `config/macro_corpus.yaml`
- Runner: `micro/run_macro_corpus.py`
- New compiled artifact: `corpus/build/datadog-agent/oom-kill-kern.bpf.o`
- Previously compiled artifacts reused by the corpus remain under `corpus/build/katran`, `corpus/build/calico`, `corpus/build/suricata`, `corpus/build/linux-selftests`, `corpus/build/systemd`, `corpus/build/tracee`, `corpus/build/tetragon`, and `corpus/build/coroot-node-agent`
