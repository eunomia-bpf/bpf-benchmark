# Corpus `app_native` Coverage And E2E Dedup Review

Date: 2026-03-29

Scope:
- Static analysis only.
- Read `docs/kernel-jit-optimization-plan.md` (§5.6, §5.35), `corpus/config/macro_corpus.yaml`, `corpus/orchestrator.py`, `runner/libs/app_runners/*.py`, `e2e/cases/*/case.py`.
- No VM run, no benchmark run, no code modification.

## Executive Summary

- Current default `macro_corpus.yaml` contains **179 objects / 1112 programs**, not "~2019". The "~2019" number is close to **default macro corpus (1112) + opt-in linux selftests manifest (892) = 2004**.
- At the **object level**, the manifest has **130 `app_native` objects / 956 programs** and **49 `test_run` objects / 156 programs**.
- At the **program level**, after honoring per-program overrides already present in YAML, the corpus is actually **939 `app_native` + 173 `test_run`** programs.
- The current six shared runners only cover four repos that are actually present in current default `app_native` entries: **`bcc`, `tracee`, `tetragon`, `scx`**. `katran` has a runner but all five current katran programs are still marked `test_run`; `bpftrace` has a runner but no corpus entries.
- If all six runners are correctly wired into corpus orchestration, the realistic ceiling under current default manifest is:
  - **Object-level dispatch today:** **708 `app_native` programs** are runner-backed.
  - **Program-level split-aware dispatch:** **706 `app_native` + 173 `test_run` = 879 measurable programs**.
- **233 program-level `app_native` programs remain uncovered** even after perfect six-runner wiring. None of them is directly convertible to `test_run` under current prog types; they need a new native runner, a manifest split/reclassification, or removal from the default macro corpus to stay compliant with §5.35.
- E2E/app-runner dedup is not mainly copy-paste. Literal normalized overlap is small, but **five of six pairs have the ownership boundary inverted**: `app_runners` import `e2e/cases/*/case.py`, while those cases also import the runner, creating cycles. **BCC is the only pair already close to the target architecture.**

## 1. Architecture Expectations From The Plan

From `docs/kernel-jit-optimization-plan.md`:

- §5.35 requires that every corpus program has an `exec_ns` path, and that repos with real applications must use **app-native** loading rather than generic libbpf.
- §5.6 requires that **Corpus and E2E share the same AppRunner layer**, with corpus only coordinating lifecycle and measurement.

The code does not fully match that design yet:

- `runner/libs/app_runners/__init__.py:13-27` only recognizes six repos: `bcc`, `tracee`, `katran`, `tetragon`, `bpftrace`, `scx`.
- The plan explicitly names **KubeArmor** as an app-native repo, but there is **no `KubeArmorRunner`** in the shared runner layer.
- `e2e/case_common.py:492-506` still documents the intended direction ("E2E cases already share repo-specific runner implementations"), but five runner implementations actually depend on case-owned internals.

## 2. Current Corpus Coverage

### 2.1 Default Macro Corpus vs "~2019" Background Number

Static counts from the current files:

| source | objects | programs | note |
|---|---:|---:|---|
| `corpus/config/macro_corpus.yaml` | 179 | 1112 | current default corpus |
| `corpus/config/macro_corpus_linux_selftests.yaml` | 280 | 892 | opt-in manifest; entries have no measurement yet |
| combined | 459 | 2004 | close to the "~2019" background number |

Conclusion: the current default macro corpus is **1112** programs. The "~2019" estimate only makes sense if you mentally include the optional linux selftests manifest.

### 2.2 Object-Level vs Program-Level Measurement Counts

This distinction matters because the manifest already contains mixed-measurement objects.

| view | `app_native` | `test_run` | comment |
|---|---:|---:|---|
| object count | 130 | 49 | object field `measurement` |
| program count, object field only | 956 | 156 | what `corpus/orchestrator.py` effectively dispatches today |
| program count, honoring per-program overrides | 939 | 173 | what `runner/libs/corpus.py` records in `selected_programs_by_measurement` |

Mixed-measurement objects currently present:

- `tracee/tracee.bpf.o`: 2 `cgroup_skb_*` programs are `test_run` inside an object marked `app_native`.
- Five `xdp-tools` objects marked `app_native` contain 23 per-program `test_run` overrides.
- One `xdp-tools` object marked `test_run` contains 8 per-program `app_native` overrides.

Total: **7 objects** with **33 per-program overrides**.

### 2.3 By-Repo Coverage Table

Table below uses the current default `macro_corpus.yaml`.

| repo | app_native objs | app_native progs | test_run objs | test_run progs | shared runner |
|---|---:|---:|---:|---:|---|
| KubeArmor | 3 | 63 | 0 | 0 | none |
| bcc | 57 | 365 | 0 | 0 | `BCCRunner` |
| calico | 0 | 0 | 8 | 59 | none |
| coroot-node-agent | 1 | 46 | 0 | 0 | none |
| datadog-agent | 1 | 1 | 0 | 0 | none |
| katran | 0 | 0 | 5 | 5 | `KatranRunner` |
| libbpf-bootstrap | 11 | 20 | 1 | 1 | none |
| loxilb | 0 | 0 | 3 | 18 | none |
| real_world_code_size | 13 | 22 | 2 | 2 | none |
| scx | 4 | 85 | 0 | 0 | `ScxRunner` |
| suricata | 0 | 0 | 2 | 2 | none |
| systemd | 7 | 14 | 1 | 2 | none |
| tetragon | 22 | 89 | 0 | 0 | `TetragonRunner` |
| tracee | 1 | 169 | 0 | 0 | `TraceeRunner` |
| tubular | 1 | 1 | 0 | 0 | none |
| xdp-tools | 7 | 72 | 6 | 27 | none |
| xdp-tutorial | 2 | 9 | 21 | 40 | none |

App-native repos with a matching shared runner today:

- `bcc`
- `tracee`
- `tetragon`
- `scx`

App-native repos without a matching shared runner today:

- `KubeArmor`
- `coroot-node-agent`
- `datadog-agent`
- `libbpf-bootstrap`
- `real_world_code_size`
- `systemd`
- `tubular`
- `xdp-tools`
- `xdp-tutorial`

Repos that do have a runner but do not currently expand default `app_native` coverage:

- `katran`: runner exists, but all five katran corpus programs are still marked `test_run`.
- `bpftrace`: runner exists, but there are no `repo: bpftrace` objects in the default macro corpus.

## 3. Corpus Orchestrator Integration Analysis

### 3.1 How `app_native` Runner Selection Works Today

Current dispatch path:

1. `load_targets_from_yaml()` resolves objects and programs, including per-program `measurement` and loader metadata.
2. `run_suite()` in `corpus/orchestrator.py:394-409` dispatches **per object**, using only `obj.measurement`.
3. `_run_app_native_entry()` in `corpus/orchestrator.py:182-245` constructs the runner with:
   - `obj.repo`
   - `object_path=obj.object_abs_path`
   - `expected_program_names=[...]`
4. `get_app_runner()` in `runner/libs/app_runners/__init__.py:13-27` lowercases `repo` and returns one of six hardcoded classes.

So the actual selection rule is:

```text
if obj.measurement == "app_native":
    runner = get_app_runner(obj.repo, object_path=..., expected_program_names=...)
```

There is no fallback path, and there is no use of repo-level loader metadata at runtime.

### 3.2 What Happens If A Repo Is Marked `app_native` But Its Runner Is Not Wired

If an object is marked `app_native` but `get_app_runner()` has no matching case:

- `get_app_runner()` raises `NotImplementedError("no shared app runner is implemented for repo ...")`.
- `run_suite()` catches that exception in `corpus/orchestrator.py:395-419`.
- The object result becomes:
  - `status: "error"`
  - `measurement: "app_native"`
  - `error: "no shared app runner is implemented for repo ..."`

So if `tracee` were removed from `get_app_runner()` while an object remained `repo: tracee`, the corpus would **fail loudly**. It would **not** fall back to generic libbpf or `test_run`. That matches the repo's "zero silent failure" policy.

### 3.3 Two Important Integration Gaps

#### Gap A: Per-program `measurement` is parsed but ignored by execution

Evidence:

- `runner/libs/corpus.py:326` resolves `program.measurement`.
- `runner/libs/corpus.py:539-549` summarizes counts by **program-level** measurement.
- But `corpus/orchestrator.py:396-403` dispatches by **object-level** `obj.measurement`.

Effect:

- `tracee.bpf.o` is always sent through `TraceeRunner`, even though two programs are explicitly tagged `test_run`.
- `xdp_redirect_cpumap.bpf.o` is always sent through `test_run`, even though eight programs are explicitly tagged `app_native`.

So the manifest schema already expresses mixed measurement, but the orchestrator does not honor it.

#### Gap B: Loader metadata is parsed but not consumed

Evidence:

- `runner/libs/corpus.py:279-296` resolves `loader`, `loader_binary`, `loader_args`, `loader_setup_script`, `loader_timeout_seconds`.
- The resolved object stores those fields (`runner/libs/corpus.py:404-407`).
- `_run_app_native_entry()` in `corpus/orchestrator.py:188-191` passes only `repo`, `object_path`, and `expected_program_names` into the runner constructor.

Effect:

- The existing repo-level loader config in `macro_corpus.yaml` is currently dead config at corpus runtime.
- The runner choice is tied to the `repo` string, not to an explicit runner/loader identity.

This matters because current and future app-native coverage is blocked not only by missing classes, but also by the absence of a real manifest-to-runner contract.

## 4. E2E And Corpus Dedup Review

### 4.1 Dependency Shape

Current dependency graph:

```text
corpus/orchestrator.py
  -> runner/libs/app_runners/__init__.py
     -> runner/libs/app_runners/<repo>.py

e2e/cases/tracee/case.py
  -> runner/libs/app_runners/tracee.py
  -> e2e/cases/tracee/case.py from inside TraceeRunner.start()

e2e/cases/tetragon/case.py
  -> runner/libs/app_runners/tetragon.py
  -> e2e/cases/tetragon/case.py from inside TetragonRunner.start()

e2e/cases/katran/case.py
  -> runner/libs/app_runners/katran.py
  -> e2e/cases/katran/case.py from inside KatranRunner.start()/run_workload()

e2e/cases/bpftrace/case.py
  -> runner/libs/app_runners/bpftrace.py
  -> e2e/cases/bpftrace/case.py from inside BpftraceRunner.start()/run_workload()/stop()

e2e/cases/scx/case.py
  -> runner/libs/app_runners/scx.py
  -> e2e/cases/scx/case.py from inside ScxRunner.start()/run_workload()

e2e/cases/bcc/case.py
  -> runner/libs/app_runners/bcc.py
  (no reverse import from runner back into case)
```

Interpretation:

- **Tracee / Tetragon / Katran / Bpftrace / Scx** all form **import cycles**.
- **BCC** is the only one-way reuse path and is the only pair that already resembles the target architecture from §5.6.

### 4.2 Duplication Matrix

`literal overlap` below is low for every pair (normalized nontrivial common lines were only 2-6 per pair), so this is **not primarily a copy-paste cleanup problem**. The real duplication is **functional ownership split across the wrong layer**.

`borrowed LOC` means:

- For the five cyclic pairs: how much case-owned LOC the runner directly depends on.
- For BCC: how much runner-owned LOC the E2E case directly reuses.

| pair | case LOC | runner LOC | dependency shape | borrowed LOC | borrowed symbols | assessment |
|---|---:|---:|---|---:|---|---|
| `tracee` | 1949 | 140 | cycle | 121 case LOC | `TraceeAgentSession`, `build_tracee_commands`, `resolve_tracee_binary`, `run_setup_script` | high ownership inversion |
| `tetragon` | 1314 | 146 | cycle | 151 case LOC | `TetragonAgentSession`, `resolve_tetragon_binary`, `run_setup_script`, `write_tetragon_policies` | high ownership inversion |
| `katran` | 2215 | 128 | cycle | 488 case LOC | `KatranDirectSession`, `KatranDsrTopology`, `NamespaceHttpServer`, `configure_katran_maps`, `run_katran_prog_test_run`, `run_parallel_http_load`, constants | very high ownership inversion |
| `bpftrace` | 830 | 130 | cycle | 101 case LOC | `SCRIPTS`, `wait_for_attached_programs`, `run_named_workload`, `finalize_process_output` | high ownership inversion |
| `scx` | 884 | 79 | cycle | 138 case LOC | `ScxSchedulerSession`, `run_hackbench` | high ownership inversion |
| `bcc` | 762 | 415 | one-way reuse | 237 runner LOC | `BCCRunner`, `find_tool_binary`, `resolve_tools_dir`, `run_setup_script` | closest to intended shared-runner model |

### 4.3 Pair-by-Pair Notes

#### `tracee`

- `e2e/cases/tracee/case.py:40` imports `TraceeRunner`.
- `runner/libs/app_runners/tracee.py:96-100` imports `e2e.cases.tracee.case` back and uses case-owned setup/binary/session helpers.
- Result: the runner is a thin facade over case internals, not the shared ownership boundary.

#### `tetragon`

- `e2e/cases/tetragon/case.py:34` imports `TetragonRunner`.
- `runner/libs/app_runners/tetragon.py:88-95` imports `e2e.cases.tetragon.case` back and uses case-owned policy/session/setup helpers.
- Result: same cycle as tracee.

#### `katran`

- `e2e/cases/katran/case.py:38` imports `KatranRunner`.
- `runner/libs/app_runners/katran.py:48-72` imports `e2e.cases.katran.case` back and depends on large case-owned topology/session/map/workload code.
- This is the heaviest entanglement by far.
- The current runner is also still **balancer-specific**, not a general katran corpus adapter.

#### `bpftrace`

- `e2e/cases/bpftrace/case.py:30` imports `BpftraceRunner`.
- `runner/libs/app_runners/bpftrace.py:76`, `:115`, `:122` import `e2e.cases.bpftrace.case` back.
- The runner delegates script metadata, attach detection, workload selection, and stop-time output formatting to the case file.

#### `scx`

- `e2e/cases/scx/case.py:30` imports `ScxRunner`.
- `runner/libs/app_runners/scx.py:54-67` imports `e2e.cases.scx.case` back.
- The session owner still lives in the case file, not in the shared runner layer.

#### `bcc`

- `e2e/cases/bcc/case.py:32` imports `BCCRunner` and related helpers from `runner/libs/app_runners/bcc.py`.
- `runner/libs/app_runners/bcc.py` does **not** import the case file back.
- This is the right direction: the case is a consumer of shared runner code instead of the runner being a consumer of case code.

## 5. Reachable Measured-Program Estimate

### 5.1 Ceiling If You Keep Today's Object-Level Dispatch

Object-level `app_native` coverage reachable through the existing six-runner registry:

- `bcc`: 365
- `tracee`: 169
- `tetragon`: 89
- `scx`: 85

Total: **708 programs across 84 objects**.

Object-level `app_native` programs still not covered by the six-runner registry:

| repo | objects | programs |
|---|---:|---:|
| xdp-tools | 7 | 72 |
| KubeArmor | 3 | 63 |
| coroot-node-agent | 1 | 46 |
| real_world_code_size | 13 | 22 |
| libbpf-bootstrap | 11 | 20 |
| systemd | 7 | 14 |
| xdp-tutorial | 2 | 9 |
| datadog-agent | 1 | 1 |
| tubular | 1 | 1 |

Two important caveats:

- `katran` contributes **0** today because its five corpus programs are still marked `test_run`.
- `bpftrace` contributes **0** today because the default macro corpus has no `repo: bpftrace` entries.

### 5.2 Ceiling If You Honor Program-Level Overrides

Program-level measurement distribution in current YAML:

- `app_native`: **939**
- `test_run`: **173**

Program-level `app_native` programs backed by existing shared runners:

- `bcc`: 365
- `tracee`: 167
- `tetragon`: 89
- `scx`: 85

Total: **706 runner-backed `app_native` programs**.

Program-level `test_run` programs already expressed in YAML: **173**.

Therefore, if corpus orchestration correctly:

1. split mixed objects by program measurement, and
2. used the existing six-runner registry correctly,

then the current default manifest could theoretically measure:

- **706 `app_native` programs**
- **173 `test_run` programs**
- **879 total programs**

### 5.3 What Still Remains Uncovered After Perfect Six-Runner Wiring

Program-level uncovered `app_native` programs:

| repo | uncovered `app_native` programs |
|---|---:|
| KubeArmor | 63 |
| xdp-tools | 57 |
| coroot-node-agent | 46 |
| real_world_code_size | 22 |
| libbpf-bootstrap | 20 |
| systemd | 14 |
| xdp-tutorial | 9 |
| datadog-agent | 1 |
| tubular | 1 |

Total: **233**.

These 233 are the real remaining gap once you account for per-program overrides.

### 5.4 Can The Uncovered Repos Be Reclassified To `test_run`?

For the **current program set**, direct answer: **no**.

I checked the uncovered program-level `app_native` set against the test-runable prog-type bucket used by corpus (`xdp`, `sched_cls`, `sched_act`, `cgroup_skb`, `socket_filter`). Result:

- **0** uncovered `app_native` programs are directly eligible for `test_run`.

Why:

- `KubeArmor`: `lsm` + `kprobe`
- `coroot-node-agent`: `tracepoint` / `uprobe`
- `datadog-agent`: `kprobe`
- `libbpf-bootstrap`: `tracepoint`, `tracing`, `kprobe`, `lsm`, `perf_event`
- `real_world_code_size`: same shape as `libbpf-bootstrap`
- `systemd`: `cgroup_sock`, `cgroup_sock_addr`, `cgroup_sysctl`, `lsm`
- `tubular`: `sk_lookup`
- `xdp-tutorial`: remaining uncovered entries are `tracepoint`
- `xdp-tools`: the remaining uncovered entries are the tracing/helper programs; the XDP programs are already the ones explicitly moved toward `test_run`

So the choice for these repos is not "flip a YAML bit to `test_run`". The real options are:

- add a repo-specific native runner,
- split out different objects/program groups so that only truly test-runable programs stay in corpus, or
- remove the repo from the default exec_ns corpus until one of the above exists.

### 5.5 Katran And Bpftrace Special Cases

#### `katran`

- `KatranRunner` exists.
- The default corpus has **5 katran programs**, all currently marked `test_run`.
- The current runner implementation is still **balancer-specific**:
  - default object is `balancer.bpf.o`
  - default program is `balancer_ingress`
  - startup path assumes DSR topology + namespace HTTP server + katran map configuration

Static inference: only `corpus/build/katran/balancer.bpf.o` is an obvious near-term `app_native` candidate. The other four katran objects should stay `test_run` unless the runner is generalized.

#### `bpftrace`

- `BpftraceRunner` exists.
- The default macro corpus currently has **0** `repo: bpftrace` objects.
- So full six-runner wiring does not expand current coverage unless bpftrace entries are added to the corpus.

## 6. Recommended Fixes, In Priority Order

### P0. Fix Corpus Dispatch Semantics

1. **Make corpus dispatch program-aware, not just object-aware.**
   - Split mixed objects into per-measurement execution units before dispatch.
   - Or fail fast on mixed objects until split support is implemented.
   - Do not continue pretending `obj.measurement` is authoritative when the manifest already encodes per-program overrides.

2. **Use a real manifest-to-runner contract.**
   - Stop selecting the runner only from `obj.repo`.
   - Pass `loader_binary`, `loader_args`, `loader_setup_script`, and `loader_timeout_seconds` into the runner layer.
   - Prefer an explicit `app_runner` identity or a fully honored `loader` contract over implicit repo-name matching.

3. **Add a corpus preflight for unsupported `app_native` repos.**
   - Before starting the daemon, enumerate all selected `app_native` repos/programs.
   - Fail once with a complete unsupported-repo summary instead of discovering the gap object by object.

4. **Make reporting consistent with actual execution units.**
   - Today `manifest_summary.selected_programs_by_measurement` is program-level, but `run_suite().summary.measurements` is object-level.
   - After split support, summary counts should describe the same unit that was actually executed.

### P1. Eliminate E2E/AppRunner Boundary Inversion

5. **Break all five import cycles.**
   - `runner/libs/app_runners/*` must stop importing `e2e/cases/*/case.py`.
   - Move session/startup/workload helpers into shared library code under `runner/libs/`.
   - Let both corpus and E2E cases import the shared layer; neither should depend on the other's case file.

6. **Use `bcc` as the template.**
   - `bcc` already has the right ownership direction: case imports runner, runner does not import case.
   - Refactor `tracee`, `tetragon`, `katran`, `bpftrace`, and `scx` to match that shape.

7. **Refactor in this order: `katran` -> `tracee`/`tetragon` -> `scx`/`bpftrace`.**
   - `katran` has the heaviest entanglement (488 borrowed case LOC).
   - `tracee` and `tetragon` both still keep loader/session ownership in the case.
   - `scx` and `bpftrace` are smaller but still cyclic.

### P1. Restore Real `app_native` Coverage

8. **Implement `KubeArmorRunner` first.**
   - It is explicitly in the plan's app-native set.
   - It unlocks **63 currently uncovered programs**.
   - It is the clearest plan/implementation mismatch.

9. **Decide repo-by-repo whether the corpus wants "real app coverage" or "remove until runnable".**
   - `coroot-node-agent`, `systemd`, `tubular`, `datadog-agent` need real runners or removal.
   - `libbpf-bootstrap` and `real_world_code_size` are example/sample bundles with no obvious native control plane; without a runner, they should not remain in the default exec_ns corpus.

10. **Finish the xdp-tools/tracee mixed-measurement cleanup after split support exists.**
   - The manifest already contains the intended direction.
   - The orchestrator is the missing piece.

11. **Revisit katran object classification after runner generalization.**
   - Likely move only `balancer_ingress` to `app_native`.
   - Keep helper objects in `test_run` unless there is a real native workload for them.

### P2. Keep The Default Macro Corpus Honest

12. **Do not leave permanently unmeasurable repos labeled `app_native` in the default macro corpus.**
   - §5.35 explicitly forbids "code size only" fallback.
   - If a repo has neither a native runner nor a valid `test_run` path, it should not stay in the default exec_ns corpus.

## Bottom Line

The central problem is not that the shared runner layer is missing entirely; it is that:

- corpus still dispatches at the wrong granularity,
- runner selection is still repo-string-based rather than manifest-contract-based, and
- five of six shared runners are not really shared ownership boundaries yet.

After fixing those architectural issues, the current default macro corpus still tops out at **879 measurable programs**, with **233 remaining `app_native` programs** that need new runners or removal from the default corpus.
