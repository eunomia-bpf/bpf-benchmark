# Corpus/E2E Benchmark YAML Redesign Report

Date: 2026-03-29

Scope:
- Static analysis only.
- Read `docs/kernel-jit-optimization-plan.md` §5.6 and the current corpus/e2e/runner code.
- No VM run, no benchmark run, no code modification in this report.

## Executive Summary

- Current default corpus config is still the old object/program manifest:
  - `179` objects
  - `1112` programs
  - program-level measurement mix: `939 app_native + 173 test_run`
- Current `corpus/orchestrator.py` is no longer purely per-object, but it still derives loader instances from object metadata. It is not driven by an explicit app list.
- Current app-native execution path already has several useful pieces:
  - one daemon session per suite
  - `enable_bpf_stats()` and `read_program_stats()`
  - reusable runner interface shaped around `start() / run_workload() / stop()`
- The big mismatches against the new design are:
  - YAML still enumerates objects/programs instead of apps
  - corpus and e2e do not share one suite config or one entrypoint
  - many runners are still object-centric (`object_path` decides the binary/mode)
  - several runners still use placeholder workloads such as `sleep`
  - `katran` is still loaded via `bpftool prog loadall`, which directly violates the new rule
  - `calico`, `loxilb`, and `suricata` still have no app runner at all
- Current object-derived `app_native` grouping in `corpus/orchestrator.py` produces `103` pseudo app batches. A full app-only redesign that covers every current corpus repo is estimated at about `132` app entries for the current corpus, or about `138` if existing e2e-only `bpftrace` apps are folded into the same shared YAML.

## 1. New Design Target

From `docs/kernel-jit-optimization-plan.md` §5.6, the new benchmark framework should obey:

1. YAML lists only app loader instances, not `.bpf.o` objects and not program names.
2. Every program is loaded by its native application or tool.
3. Program IDs are discovered automatically after app start.
4. Corpus and E2E share the same app runner layer and the same app YAML.
5. Corpus vs E2E differ only in measurement adapter:
   - corpus: per-program `exec_ns` from `bpf_stats`
   - e2e: app-level throughput/latency

The practical implication is:

```text
old center of gravity: object manifest -> derive loaders -> try to map live programs back
new center of gravity: app manifest -> start native app -> discover live programs -> measure
```

## 2. Current Code vs New Design: Gap Matrix

### 2.1 Top-Level Files

| File | Current state | Gap vs new design | Recommended action |
|---|---|---|---|
| `corpus/config/macro_corpus.yaml` | `schema_version: 2`, has `repos:` and `objects:`; enumerates `179` objects and `1112` programs; still mixes build artifacts, loader config, measurement mode, and per-program overrides | Wrong abstraction level. Object/program enumeration is the opposite of the new app-only schema. It also still carries `measurement: app_native/test_run`, which should disappear from shared corpus/e2e YAML. | Replace with a new app-only suite file, keep old file only as migration source. |
| `corpus/orchestrator.py` | Splits objects by per-program measurement, derives loader identity from repo/object heuristics (`_split_objects_by_program_measurement()`, `_loader_instance_identity()`, `_group_app_native_loader_instances()`), runs app-native groups, and marks every non-`app_native` unit as unsupported in `run_suite()` | Still object-derived. Loader identity is inferred from object paths instead of declared in YAML. New design wants explicit `apps:` and no object/program dispatch. | Replace with a shared app-suite engine; keep a thin `corpus` wrapper only if CLI compatibility is needed. |
| `corpus/driver.py` | Thin alias that just forwards to `corpus.orchestrator.main()` | Adds no design value once corpus becomes a thin wrapper over a shared suite engine | Optional compatibility shim; otherwise delete. |
| `corpus/modes.py` | Pure compatibility shim forwarding to `corpus.orchestrator` | Dead concept under the new app-only design | Delete. |
| `runner/libs/corpus.py` | Defines `ResolvedProgram`/`ResolvedObject`; parser still allows only `app_native` and `test_run`; loader kinds still `generic` or `app-native`; schema root is still `objects:` | Entire parser is built around the old manifest. Many fields (`fixture_path`, `compile_loader`, `io_mode`, packet/context inputs) are object/test-run concerns, not app-suite concerns. | Split reusable helpers out; replace manifest parsing with a new app-suite schema module. |
| `runner/libs/bpf_stats.py` | Good shared helper for `enable_bpf_stats()` and live per-program stats reads | Matches the new corpus measurement model well | Keep. No redesign needed beyond using it from the new suite engine. |
| `e2e/case_common.py` | Owns `run_case_lifecycle()` and still centralizes the baseline/apply/post-ReJIT lifecycle on the e2e side | This is an e2e-only orchestration layer. Under the new design, corpus and e2e should share one suite engine instead of having one corpus orchestrator plus one e2e lifecycle helper. | Retire most of it after moving orchestration into the shared app-suite engine. Keep only generic report/utility helpers if still useful. |
| `e2e/run.py` | Separate `CASE_SPECS` dispatcher with case names `tracee`, `tetragon`, `bpftrace`, `scx`, `katran`, `bcc`; separate parser and output handling | Not the same entrypoint as corpus; not driven by the same YAML; still selects repo cases rather than app entries | Turn into a thin wrapper over the shared suite engine with `measurement_mode=e2e`. |
| `Makefile` + `runner/Makefile` | `vm-corpus` and `vm-e2e` are separate backends with different commands, different prep logic, and different Python entrypoints | The outer entrypoints are not backed by one shared engine | Keep `vm-corpus` and `vm-e2e` as user-facing aliases if desired, but make both call one common `vm-app-bench MODE=corpus|e2e SUITE=...` backend. |

### 2.2 `corpus/orchestrator.py` Specific Findings

Relevant lines:
- `_split_objects_by_program_measurement()` at `corpus/orchestrator.py:150`
- `_loader_instance_identity()` at `corpus/orchestrator.py:167`
- `_group_app_native_loader_instances()` at `corpus/orchestrator.py:191`
- `_run_app_native_loader_instance()` at `corpus/orchestrator.py:455`
- `run_suite()` at `corpus/orchestrator.py:594`
- unsupported non-app-native path at `corpus/orchestrator.py:618-619`

Assessment:

- Good:
  - already starts one daemon session for the whole suite
  - already measures baseline/rejit on the same live app session
  - already aggregates multiple objects into one loader batch for some repos
- Not good enough:
  - the grouping key is still derived from object paths and repo-specific heuristics
  - there is no first-class `AppSpec`
  - the old `test_run` world is still present in the file, even though the new design forbids it for corpus/e2e
  - `expected_program_names` still comes from manifest program enumeration

Bottom line:
- the current orchestrator is a transitional hybrid, not the new design.

### 2.3 `runner/libs/corpus.py` Specific Findings

Relevant lines:
- allowed measurements at `runner/libs/corpus.py:18`
- allowed loader kinds at `runner/libs/corpus.py:19`
- `ResolvedProgram` at `runner/libs/corpus.py:32`
- `ResolvedObject` at `runner/libs/corpus.py:68`
- repo loader config parsing at `runner/libs/corpus.py:159`
- old object parser at `runner/libs/corpus.py:248`
- manifest load entrypoint at `runner/libs/corpus.py:476`

Assessment:

- This module is fundamentally tied to the old schema:
  - object root
  - program list
  - per-program measurement override
  - object loader metadata
  - test-run fixtures and input generation
- Under the new app-only design, the parser should instead resolve:
  - `AppSpec`
  - runner ID
  - runner args
  - workload profile name

Recommended split:
- Keep reusable helpers that are not schema-specific.
- Move old object/test-run helpers out of the app benchmark path.
- Introduce a new `runner/libs/app_suite_schema.py` for the shared YAML.

### 2.4 `runner/libs/app_runners/*.py`: Per-File Review

#### Registry and Base Layer

| File | Current state | Gap | Recommended action |
|---|---|---|---|
| `runner/libs/app_runners/__init__.py` | `get_app_runner(repo, **kwargs)` dispatches by repo name | The new design wants `get_runner(app.runner, app.args)`, not repo-derived factory selection | Change registry key from repo name to explicit runner ID. |
| `runner/libs/app_runners/process_support.py` | Good generic `NativeProcessRunner` shape, but default workload is `run_sleep_workload()` and constructor is still `object_path/loader_binary/loader_args/expected_program_names` driven | `sleep` is not an acceptable benchmark workload. `object_path` and `expected_program_names` belong to the old manifest world. | Keep generic process/session utilities, but require each concrete runner to declare supported workload profiles and explicit app args. |

#### Runners That Are Close To The Target Interface

| File | Current state | Gap | Recommended action |
|---|---|---|---|
| `runner/libs/app_runners/bcc.py` | Best current fit. Has real `start() / run_workload() / stop()`, real tool discovery, and a real workload catalog | Still accepts `object_path`; explicit workload mapping covers only the current e2e subset, not the full `57` corpus tools | Keep, but normalize on `args.tool` and make the tool/workload catalog cover the full BCC corpus. |
| `runner/libs/app_runners/bpftrace.py` | Good lifecycle wrapper for real `bpftrace` scripts | Still E2E-only in practice; current corpus has no shared YAML entries for it | Keep and wire into the shared app YAML via `args.script`. |
| `runner/libs/app_runners/bpftrace_support.py` | Useful shared script catalog and workload mapping | Currently only backing the e2e case path | Promote as shared corpus/e2e runner data. |
| `runner/libs/app_runners/tracee.py` | Good lifecycle shape; uses native tracee binary and runner-owned support code | `workload_spec` is externally mutated by the e2e case; `expected_program_names` still comes from manifest program lists | Keep, but make workload profile selection internal to the runner or shared YAML, not case-owned. |
| `runner/libs/app_runners/tracee_support.py` | Good shared support module | No structural issue; just needs to serve the shared suite engine instead of only e2e/corpus adapters | Keep. |
| `runner/libs/app_runners/tetragon.py` | Good lifecycle shape; native binary, policy dir, workload call | Current workload/config ownership still lives in `e2e/cases/tetragon/case.py`; runner args are not yet first-class app YAML args | Keep, but move workload/policy profile selection into the shared runner/app config contract. |
| `runner/libs/app_runners/tetragon_support.py` | Good shared support module | Needs to back the shared suite engine rather than the current per-case layer | Keep. |
| `runner/libs/app_runners/scx.py` | Good lifecycle shape | Still infers scheduler binary from `object_path` instead of explicit app args | Keep, but make scheduler selection explicit in `args`. |
| `runner/libs/app_runners/scx_support.py` | Useful shared support/workload code | No major structural problem | Keep. |

#### Runners That Exist But Are Still Object-Centric or Workload-Incomplete

| File | Current state | Gap | Recommended action |
|---|---|---|---|
| `runner/libs/app_runners/coroot_node_agent.py` | Thin binary wrapper over `NativeProcessRunner` | No repo-specific workload; inherits default `sleep` workload | Keep only as a start point; add real workload profile(s) and app args. |
| `runner/libs/app_runners/datadog_agent.py` | Thin wrapper for `system-probe run` | No OOM stress workload and no app-specific configuration contract | Keep only as a start point; add `oom_stress` workload and app args. |
| `runner/libs/app_runners/kubearmor.py` | Thin wrapper for `kubearmor` binary | No policy/workload profile; inherits default `sleep` workload | Keep only as a start point; add `security_policy_mix` workload and policy config. |
| `runner/libs/app_runners/libbpf_bootstrap.py` | Maps `object_path` to binary name; only `bootstrap*` gets `exec_storm`, most others fall back to `sleep` | Still object-centric and workload-incomplete | Keep the process utility pieces, but redesign around explicit app names and full workload profiles per example. |
| `runner/libs/app_runners/real_world_code_size.py` | Same design as `libbpf_bootstrap.py`, still object-path driven | Same gaps as above | Same action as above. |
| `runner/libs/app_runners/systemd.py` | Maps object basename to binary via `systemd_binary_for_object()` | Still uses object identity to choose app config; no workload catalog | Keep only as a starting point; redesign around explicit feature/profile args. |
| `runner/libs/app_runners/tubular.py` | Thin wrapper over `tubectl load` | No real workload; still generic wrapper | Keep only as a starting point; add network workload and native app args. |
| `runner/libs/app_runners/xdp_tools.py` | Object stem decides binary subcommand; workload is still `sleep` | Still object-centric and not valid for network benchmarks | Keep only the invocation logic; redesign around explicit `tool`/`mode` args and real network workload. |
| `runner/libs/app_runners/xdp_tutorial.py` | Only the tracing examples are wired; workload is `network` | Still object-path driven and covers only a small subset of the tutorial directories | Expand to all tutorial app directories and explicit app args. |

#### Runner That Violates The New Design Directly

| File | Current state | Gap | Recommended action |
|---|---|---|---|
| `runner/libs/app_runners/katran.py` | Current runner takes an object path and uses a direct session object | It is not starting the native katran loader as required by the new design | Rewrite around the native katran app/server lifecycle. |
| `runner/libs/app_runners/katran_support.py` | Still does `bpftool prog loadall` (`runner/libs/app_runners/katran_support.py:670`) | This is explicitly forbidden by the new design | Remove from the corpus/e2e path; keep only if needed for separate diagnostics. |

#### Missing Runner Files

These repos are present in the current corpus but still have no runner file at all:

- `calico`
- `loxilb`
- `suricata`

Under the new design, these are implementation gaps, not reasons to keep `test_run`.

### 2.5 `e2e/cases/*/case.py`: Shared Yet?

Short answer:
- partially shared at the runner level
- not shared at the suite/config/orchestration level

Per case:

| File | Current state | Gap | Recommended action |
|---|---|---|---|
| `e2e/cases/bcc/case.py` | Uses `BCCRunner`, but still owns its own `config.yaml`, tool selection, metric aggregation, and lifecycle around `run_case_lifecycle()` | Still not using the same YAML or the same suite engine as corpus | Move app selection to shared YAML; keep only BCC-specific report formatting or metric post-processing if still needed. |
| `e2e/cases/bpftrace/case.py` | Uses `BpftraceRunner`, but still owns `selected_scripts()` and script selection | Still E2E-only selection logic | Replace with shared app entries such as `bpftrace/tcplife`, `bpftrace/runqlat`, etc. |
| `e2e/cases/tracee/case.py` | Large case file; owns `config.yaml`, workload list, statistics, latency probes, and runner orchestration | Strongly case-owned today; not driven by shared app YAML | Move lifecycle out; keep only tracee-specific app metric collectors if needed. |
| `e2e/cases/tetragon/case.py` | Owns config parsing and workload list, then drives `TetragonRunner` via `run_case_lifecycle()` | Same issue as tracee | Same action as tracee. |
| `e2e/cases/scx/case.py` | Uses `ScxRunner`, but workload discovery still lives in the case (`workload_specs()`) | Still not shared with corpus | Move workload selection to the shared app YAML or shared workload registry. |
| `e2e/cases/katran/case.py` | Still owns large bespoke topology, sampling, and lifecycle logic | Far from the shared-suite target | Split katran-specific topology/metrics into runner/support modules; remove case-owned orchestration. |

Conclusion:
- The runners are reusable.
- The e2e suite definition and orchestration are not yet shared.

## 3. Proposed New YAML Schema

### 3.1 File Location

Recommended location:

- `corpus/config/macro_apps.yaml`

Reason:
- minimal churn from the current `make vm-corpus` path
- easy to migrate from the current `macro_corpus.yaml`
- `e2e` can consume the same file even if it lives under `corpus/config/`

If the repository later wants a cleaner top-level shared suite directory, this file can be moved without changing the schema itself.

### 3.2 Schema

Recommended normalized schema:

```yaml
schema_version: 1
suite_name: macro_apps
defaults:
  duration_s: 10

apps:
  - name: tracee/default
    runner: tracee
    workload: tracee_default
    args: {}

  - name: bcc/execsnoop
    runner: bcc
    workload: exec_storm
    args:
      tool: execsnoop

  - name: katran/default
    runner: katran
    workload: network
    args: {}
```

Rules:

- `apps:` is the only suite payload.
- No `.bpf.o` paths.
- No program lists.
- No `measurement: app_native/test_run`.
- No repo-level loader config block.
- `name` is the human/report identity.
- `runner` selects the runner class.
- `workload` selects a symbolic workload profile.
- `args` is runner-specific loader configuration.

### 3.3 Workload Profile Conventions

Shared generic profiles:

- `exec_storm`
- `file_open_storm`
- `network`
- `fio`
- `hackbench`
- `bind_storm`
- `oom_stress`
- `sysctl_write`
- `userns_unshare`
- `iterator_poll`
- `minimal_syscall`
- `mixed_system`

Composite profiles inferred to preserve coverage of current repos:

- `tracee_default`
  - expands to exec/file/network triggers, because one tracee instance loads many unrelated programs
- `security_policy_mix`
  - for KubeArmor-like policy bundles
- `system_telemetry_mix`
  - for agent-style telemetry repos such as coroot-node-agent

These composite profiles still satisfy the new design because the YAML remains app-only; they are just symbolic workload IDs.

## 4. Proposed Directory Layout And Responsibilities

### 4.1 Ideal Layout

```text
runner/
  libs/
    app_suite_schema.py        # shared YAML parser for apps:
    app_suite.py               # shared suite engine for corpus/e2e
    workload_registry.py       # symbolic workload -> implementation
    measurement_adapters/
      corpus.py                # bpf_stats exec_ns collection
      e2e.py                   # app-level throughput/latency collection
    app_runners/
      ...                      # per-repo loader lifecycle only
    app_metrics/
      ...                      # optional repo-specific e2e metric collectors
    bpf_stats.py               # existing, keep
    daemon_session.py          # existing, keep

corpus/
  config/
    macro_apps.yaml            # shared app suite definition
  orchestrator.py              # thin wrapper -> runner.libs.app_suite(main, mode="corpus")

e2e/
  run.py                       # thin wrapper -> runner.libs.app_suite(main, mode="e2e")

micro/
  ...                          # unchanged; still separate
```

### 4.2 Shared Suite Engine

Recommended control flow:

```text
load AppSpec[] from macro_apps.yaml
select measurement adapter (corpus | e2e)
start daemon once

for each app in apps:
    runner = get_runner(app.runner, **app.args)
    prog_ids = runner.start()
    baseline = measure_phase(runner, prog_ids, app.workload, duration_s)
    daemon.apply_rejit(prog_ids)
    rejit = measure_phase(runner, prog_ids, app.workload, duration_s)
    runner.stop()
    emit result
```

Key difference from current code:
- the suite iterates explicit `AppSpec`, not `ResolvedObject`

### 4.3 What Corpus And E2E Share

Shared:
- same `macro_apps.yaml`
- same `AppRunner` objects
- same daemon session semantics
- same app lifecycle
- same workload registry

Different:
- only the measurement adapter

That preserves the rule:
- same lifecycle
- different metrics

### 4.4 Files That Can Be Deleted After Migration

Delete:
- `corpus/modes.py`
- old object/program parsing path inside `runner/libs/corpus.py`
- the old object/test-run code path inside `corpus/orchestrator.py`
- `e2e/case_common.py` lifecycle machinery
- `vm-corpus-new` target once the shared suite is the only backend

Can remain as thin compatibility wrappers:
- `corpus/driver.py`
- `corpus/orchestrator.py`
- `e2e/run.py`

Retire or reduce heavily:
- `e2e/cases/*/case.py`
  - move orchestration out
  - keep only repo-specific app metric collectors or report formatting if still necessary

## 5. Complete Proposed App Inventory

Important note:
- counts below are design estimates based on current corpus contents, current runner coverage, and current repo/executable layout
- for `KubeArmor`, `calico`, `loxilb`, `suricata`, and parts of `systemd`, the exact native loader args still need runner implementation confirmation
- the point here is the new app granularity, not finalized CLI details

### 5.1 Count Summary By Repo

| Repo | Current programs | Current program-level mix | Proposed app entries | Current runner status |
|---|---:|---|---:|---|
| `KubeArmor` | 63 | `63 app_native` | 1 | runner exists but skeletal |
| `bcc` | 365 | `365 app_native` | 57 | runner exists and is closest to target |
| `calico` | 59 | `59 test_run` | 1 | missing runner |
| `coroot-node-agent` | 46 | `46 app_native` | 1 | runner exists but skeletal |
| `datadog-agent` | 1 | `1 app_native` | 1 | runner exists but skeletal |
| `katran` | 5 | `5 test_run` | 1 | runner exists but violates native-loader rule |
| `libbpf-bootstrap` | 21 | `20 app_native + 1 test_run` | 12 | runner exists but object-centric |
| `loxilb` | 18 | `18 test_run` | 1 | missing runner |
| `real_world_code_size` | 24 | `22 app_native + 2 test_run` | 15 | runner exists but object-centric |
| `scx` | 85 | `85 app_native` | 4 | runner exists and is close to target |
| `suricata` | 2 | `2 test_run` | 2 | missing runner |
| `systemd` | 16 | `14 app_native + 2 test_run` | 6 | runner exists but object-centric/skeletal |
| `tetragon` | 89 | `89 app_native` | 1 | runner exists and is close to target |
| `tracee` | 169 | `167 app_native + 2 test_run` | 1 | runner exists and is close to target |
| `tubular` | 1 | `1 app_native` | 1 | runner exists but skeletal |
| `xdp-tools` | 99 | `57 app_native + 42 test_run` | 13 | runner exists but incomplete and still object-centric |
| `xdp-tutorial` | 49 | `9 app_native + 40 test_run` | 14 | runner exists for only part of the repo |

Estimated total for current corpus repos:
- `132` app entries

If the same shared YAML also absorbs the existing e2e-only `bpftrace` scripts:
- add `6` more app entries
- shared total becomes about `138`

### 5.2 Detailed App List

#### `KubeArmor` (1 app)

| Workload | Apps | Runner |
|---|---|---|
| `security_policy_mix` | `KubeArmor/default` | `kubearmor` |

#### `bcc` (57 apps)

| Workload | Apps | Runner |
|---|---|---|
| `exec_storm` | `bcc/capable`, `bcc/execsnoop` | `bcc` |
| `bind_storm` | `bcc/bindsnoop` | `bcc` |
| `fio` | `bcc/biolatency`, `bcc/biopattern`, `bcc/biosnoop`, `bcc/biostacks`, `bcc/biotop`, `bcc/readahead`, `bcc/vfsstat` | `bcc` |
| `file_open_storm` | `bcc/drsnoop`, `bcc/filelife`, `bcc/filetop`, `bcc/fsdist`, `bcc/fsslower`, `bcc/mountsnoop`, `bcc/opensnoop`, `bcc/statsnoop`, `bcc/syscount` | `bcc` |
| `network` | `bcc/solisten`, `bcc/tcpconnect`, `bcc/tcpconnlat`, `bcc/tcplife`, `bcc/tcppktlat`, `bcc/tcprtt`, `bcc/tcpstates`, `bcc/tcpsynbl`, `bcc/tcptop`, `bcc/tcptracer` | `bcc` |
| `hackbench` | `bcc/cpudist`, `bcc/cpufreq`, `bcc/futexctn`, `bcc/hardirqs`, `bcc/klockstat`, `bcc/llcstat`, `bcc/mdflush`, `bcc/memleak`, `bcc/numamove`, `bcc/offcputime`, `bcc/profile`, `bcc/runqlat`, `bcc/runqlen`, `bcc/runqslower`, `bcc/slabratetop`, `bcc/softirqs`, `bcc/wakeuptime` | `bcc` |
| `mixed_system` | `bcc/bashreadline`, `bcc/bitesize`, `bcc/cachestat`, `bcc/exitsnoop`, `bcc/funclatency`, `bcc/gethostlatency`, `bcc/javagc`, `bcc/ksnoop`, `bcc/oomkill`, `bcc/sigsnoop`, `bcc/syncsnoop` | `bcc` |

#### `calico` (1 app)

| Workload | Apps | Runner |
|---|---|---|
| `network` | `calico/felix` | `calico` |

#### `coroot-node-agent` (1 app)

| Workload | Apps | Runner |
|---|---|---|
| `system_telemetry_mix` | `coroot-node-agent/default` | `coroot-node-agent` |

#### `datadog-agent` (1 app)

| Workload | Apps | Runner |
|---|---|---|
| `oom_stress` | `datadog-agent/system-probe-oomkill` | `datadog-agent` |

#### `katran` (1 app)

| Workload | Apps | Runner |
|---|---|---|
| `network` | `katran/default` | `katran` |

#### `libbpf-bootstrap` (12 apps)

| Workload | Apps | Runner |
|---|---|---|
| `exec_storm` | `libbpf-bootstrap/bootstrap`, `libbpf-bootstrap/bootstrap_legacy`, `libbpf-bootstrap/fentry`, `libbpf-bootstrap/kprobe`, `libbpf-bootstrap/ksyscall`, `libbpf-bootstrap/uprobe`, `libbpf-bootstrap/usdt` | `libbpf-bootstrap` |
| `file_open_storm` | `libbpf-bootstrap/lsm` | `libbpf-bootstrap` |
| `hackbench` | `libbpf-bootstrap/profile` | `libbpf-bootstrap` |
| `network` | `libbpf-bootstrap/tc` | `libbpf-bootstrap` |
| `iterator_poll` | `libbpf-bootstrap/task_iter` | `libbpf-bootstrap` |
| `minimal_syscall` | `libbpf-bootstrap/minimal` | `libbpf-bootstrap` |

#### `loxilb` (1 app)

| Workload | Apps | Runner |
|---|---|---|
| `network` | `loxilb/default` | `loxilb` |

#### `real_world_code_size` (15 apps)

| Workload | Apps | Runner |
|---|---|---|
| `exec_storm` | `real_world_code_size/bootstrap`, `real_world_code_size/bootstrap_legacy`, `real_world_code_size/fentry`, `real_world_code_size/kprobe`, `real_world_code_size/ksyscall`, `real_world_code_size/uprobe`, `real_world_code_size/usdt` | `real_world_code_size` |
| `file_open_storm` | `real_world_code_size/lsm` | `real_world_code_size` |
| `hackbench` | `real_world_code_size/profile` | `real_world_code_size` |
| `network` | `real_world_code_size/sockfilter`, `real_world_code_size/tc` | `real_world_code_size` |
| `iterator_poll` | `real_world_code_size/task_iter` | `real_world_code_size` |
| `minimal_syscall` | `real_world_code_size/minimal`, `real_world_code_size/minimal_legacy`, `real_world_code_size/minimal_ns` | `real_world_code_size` |

#### `scx` (4 apps)

| Workload | Apps | Runner |
|---|---|---|
| `hackbench` | `scx/bpfland`, `scx/flash`, `scx/lavd`, `scx/rusty` | `scx` |

#### `suricata` (2 apps)

| Workload | Apps | Runner |
|---|---|---|
| `network` | `suricata/xdp-filter`, `suricata/xdp-lb` | `suricata` |

#### `systemd` (6 apps)

| Workload | Apps | Runner |
|---|---|---|
| `network` | `systemd/bind-iface`, `systemd/restrict-ifaces`, `systemd/socket-bind` | `systemd` |
| `file_open_storm` | `systemd/restrict-fs` | `systemd` |
| `sysctl_write` | `systemd/sysctl-monitor` | `systemd` |
| `userns_unshare` | `systemd/userns-restrict` | `systemd` |

#### `tetragon` (1 app)

| Workload | Apps | Runner |
|---|---|---|
| `exec_storm` | `tetragon/default` | `tetragon` |

#### `tracee` (1 app)

| Workload | Apps | Runner |
|---|---|---|
| `tracee_default` | `tracee/default` | `tracee` |

#### `tubular` (1 app)

| Workload | Apps | Runner |
|---|---|---|
| `network` | `tubular/default` | `tubular` |

#### `xdp-tools` (13 apps)

| Workload | Apps | Runner |
|---|---|---|
| `network` | `xdp-tools/xdp_basic`, `xdp-tools/xdp_flowtable`, `xdp-tools/xdp_flowtable_sample`, `xdp-tools/xdp_forward`, `xdp-tools/xdp_load_bytes`, `xdp-tools/xdp_monitor`, `xdp-tools/xdp_redirect_basic`, `xdp-tools/xdp_redirect_cpumap`, `xdp-tools/xdp_redirect_devmap`, `xdp-tools/xdp_redirect_devmap_multi`, `xdp-tools/xdp_sample`, `xdp-tools/xdp_trafficgen`, `xdp-tools/xdpsock` | `xdp-tools` |

#### `xdp-tutorial` (14 apps)

| Workload | Apps | Runner |
|---|---|---|
| `network` | `xdp-tutorial/advanced03-AF_XDP`, `xdp-tutorial/basic01-xdp-pass`, `xdp-tutorial/basic02-prog-by-name`, `xdp-tutorial/basic03-map-counter`, `xdp-tutorial/basic04-pinning-maps`, `xdp-tutorial/experiment01-tailgrow`, `xdp-tutorial/packet-solutions`, `xdp-tutorial/packet01-parsing`, `xdp-tutorial/packet02-rewriting`, `xdp-tutorial/packet03-redirecting`, `xdp-tutorial/tracing01-xdp-simple`, `xdp-tutorial/tracing02-xdp-monitor`, `xdp-tutorial/tracing03-xdp-debug-print`, `xdp-tutorial/tracing04-xdp-tcpdump` | `xdp-tutorial` |

### 5.3 Existing E2E-Only Apps That Fit The Shared Schema Cleanly

These are not in the current corpus manifest, but they already fit the new shared app-only schema and should use the same infrastructure:

| Workload | Apps | Runner |
|---|---|---|
| `exec_storm` | `bpftrace/capable` | `bpftrace` |
| `fio` | `bpftrace/biosnoop`, `bpftrace/vfsstat` | `bpftrace` |
| `hackbench` | `bpftrace/runqlat` | `bpftrace` |
| `network` | `bpftrace/tcplife`, `bpftrace/tcpretrans` | `bpftrace` |

## 6. Migration Plan

### Phase 1: Freeze The Old Schema

1. Stop extending `corpus/config/macro_corpus.yaml`.
2. Treat it as migration input only.
3. Add `corpus/config/macro_apps.yaml`.

### Phase 2: Introduce The Shared Suite Engine

1. Add `runner/libs/app_suite_schema.py`.
2. Add `runner/libs/app_suite.py`.
3. Add `runner/libs/measurement_adapters/corpus.py`.
4. Add `runner/libs/measurement_adapters/e2e.py`.
5. Make `corpus/orchestrator.py` and `e2e/run.py` thin wrappers.

### Phase 3: Normalize Runner Contracts

1. Change runner factory lookup from repo name to explicit `runner`.
2. Remove `object_path` and `expected_program_names` from the app benchmark contract.
3. Require every runner to advertise supported workload profiles.
4. Remove default `sleep` workloads from benchmark-visible runners.

### Phase 4: Fill Coverage Gaps

Must implement or redesign:

- new runners:
  - `calico`
  - `loxilb`
  - `suricata`
- runner rewrites:
  - `katran` native loader rewrite
- runner upgrades:
  - `kubearmor`
  - `coroot-node-agent`
  - `datadog-agent`
  - `systemd`
  - `tubular`
  - `xdp-tools`
  - `xdp-tutorial`
  - `libbpf-bootstrap`
  - `real_world_code_size`

### Phase 5: Retire Old E2E Case Control Flow

1. Move app selection out of `e2e/cases/*/case.py`.
2. Move lifecycle orchestration out of `e2e/case_common.py`.
3. Keep only:
   - runner support code
   - repo-specific app metric collectors
   - result/report formatting

### Phase 6: Makefile Convergence

1. Add one backend target, for example:

```make
vm-app-bench:
	# MODE=corpus|e2e
	# SUITE=corpus/config/macro_apps.yaml
```

2. Make `vm-corpus` call `vm-app-bench MODE=corpus`.
3. Make `vm-e2e` call `vm-app-bench MODE=e2e`.
4. Delete `vm-corpus-new`.

## 7. Bottom Line

- The repository already has enough building blocks to make the new design straightforward:
  - one-daemon-per-suite orchestration
  - live `bpf_stats`
  - reusable runner objects
- But the center of gravity is still wrong:
  - config is still object/program centric
  - corpus and e2e still branch too early
  - several runners are still object-driven wrappers rather than explicit app loaders

The redesign should therefore be:

```text
delete old object-driven suite definition
add one app-only YAML
add one shared suite engine
make corpus/e2e thin measurement wrappers
finish native runners for every remaining repo
```

That gives a framework that finally matches the latest §5.6 design instead of the current transitional hybrid.
