# Benchmark Status Review (2026-04-03)

## Scope

This review is based on:

- `docs/kernel-jit-optimization-plan.md`, especially §5, §5.35, §5.6, §6.4, §7
- root `Makefile`
- `corpus/`, `e2e/`, `micro/`, `runner/`, `tests/`
- latest checked-in artifacts under `micro/results/`, `corpus/results/`, `e2e/results/`
- recent local logs under `docs/tmp/`

The goal here is to describe current benchmark status, not to change code.

## Executive Summary

- Current x86 VM benchmark path is usable for regression and integration validation. The strongest current evidence is in task tracker entries #644 and #645 plus fresh 2026-04-03 artifacts.
- `make vm-corpus` is the strongest current benchmark target: latest run is `20/20 app ok`, `114` discovered/applied programs, `61` comparable samples, geomean `1.033x`.
- `make vm-e2e` is also healthy: latest sweep is `6/6 ok` across `tracee`, `tetragon`, `bpftrace`, `scx`, `bcc`, `katran`.
- `make vm-micro` and `make vm-micro-smoke` pass as regression targets, but they no longer match the old doc semantics. Current implementation is `llvmbpf` vs `kernel`, not `kernel` vs `kernel-rejit`.
- The framework is architecturally much closer to §5.6 than the old object-centric design, but it is not paper-ready. The biggest remaining gaps are baseline coverage, missing runner coverage, stale docs, low repeat counts, incomplete cross-hardware refresh, and the fact that not every corpus-discovered program yields comparable `exec_ns`.

## A. 各 Benchmark Target 状态

| Target | Current entrypoint | Latest evidence | Status | Notes |
|---|---|---|---|---|
| `make vm-micro` | `runner/Makefile:295-303` | `micro/results/vm_micro_20260403_051623/` | Can run; pass | `metadata.json` completed at `2026-04-03T05:17:33Z`. `details/result.json` has suite `micro_staged_codegen`, `62` benchmarks, defaults `samples=3`, `warmups=1`, `inner_repeat=100`. Tracker #644 explicitly says `make vm-micro` passed. |
| `make vm-corpus` | `runner/Makefile:305-313` | `corpus/results/vm_corpus_20260403_035346/` | Can run; pass | `result.json` is `status=ok`. `20/20 app ok`. `114` discovered programs. `114` applied programs in per-app totals. `61` comparable/applied samples. `all_comparable_geomean = applied_only_geomean = 1.0328579392552086`. |
| `make vm-e2e` | `runner/Makefile:315-323` | latest per-case dirs under `e2e/results/` plus `*_authoritative_20260403.json` | Can run; pass | Latest completed case dirs: `tracee_20260403_043753`, `tetragon_20260403_044745`, `bpftrace_20260403_044905`, `scx_20260403_045546`, `bcc_20260403_045709`, `katran_20260403_050750`. All six `result.json` files report `status=ok`. |
| `make vm-selftest` | `runner/Makefile:266-273` + `runner/scripts/vm-selftest.sh` | task tracker #644 | Can run; pass | No fresh structured `results/` artifact directory. Tracker #644 says `make vm-selftest` passed. Current implementation is broader than old docs: it runs all discovered `tests/unittest/build/rejit_*` binaries plus `adversarial_rejit` and `fuzz_rejit`. |
| `make vm-test` | `runner/Makefile:252-264` + `runner/scripts/run_all_tests.sh` | `docs/tmp/vm-test.latest.log` + task tracker #645 | Can run; pass | #645 says `make vm-test` passed on 2026-04-03. Latest log shows 5/5 kinsn modules loaded, then kernel selftest + unittest + negative + upstream `test_verifier` + upstream `test_progs` path executing. |
| `make vm-negative-test` | `runner/Makefile:275-283` | task tracker #644; latest explicit standalone numbers in `docs/tmp/20260325/batch1_test_results.md` | Can run; pass | #644 says it passed in the current full validation round. Latest explicit standalone log I found is older (`2026-03-25`): adversarial `23 passed / 0 failed / 0 skipped`, fuzz `1000` rounds, `scx_prog_show_race` `20/20`. |
| `make check` | `Makefile:395-399` | task tracker #645 | Can run; pass | Actual target is `all + daemon-tests + python-tests + smoke`. #645 says `make check` passed on 2026-04-03. |
| `make smoke` | `Makefile:385-387` | `micro/results/smoke_20260403_174351/` | Can run; pass | Latest local smoke artifact completed at `2026-04-03T17:43:51Z`. It is a 1-benchmark `simple` run with `samples=1`, `warmups=0`, `inner_repeat=10`, runtime `llvmbpf`. |

### A.1 Target-by-target details

#### `make vm-micro`

- Latest artifact: `micro/results/vm_micro_20260403_051623/`
- Evidence:
  - `metadata.json`: `status=completed`
  - `details/result.json`: suite `micro_staged_codegen`, `62` benchmarks
  - task tracker #644: `make vm-micro` passed
- Important caveat:
  - Current implementation runs `--runtime llvmbpf --runtime kernel` (`runner/Makefile:295-303`), not `kernel + kernel-rejit` as §6.4 still claims.

#### `make vm-corpus`

- Latest artifact: `corpus/results/vm_corpus_20260403_035346/`
- Evidence:
  - `result.json`: `status=ok`
  - `summary.selected_apps = 20`
  - `summary.statuses = {"ok": 20}`
  - `summary.discovered_programs = 114`
  - `summary.sample_count = 61`
  - `summary.applied_sample_count = 61`
  - `summary.comparison_exclusion_reason_counts = {"missing_baseline_exec_ns": 43, "missing_rejit_exec_ns": 11}`
- Interpretation:
  - This target is runnable and healthy as a regression/evaluation harness.
  - It is not yet satisfying the strictest reading of §5.35, because `114` programs were discovered/applied but only `61` produced comparable samples.

#### `make vm-e2e`

- Latest completed cases:
  - `tracee`
  - `tetragon`
  - `bpftrace`
  - `scx`
  - `bcc`
  - `katran`
- Evidence:
  - six latest per-case directories all have `result.json` with `status=ok`
  - six checked-in authoritative snapshots exist for `20260403`
- Notable per-case data from authoritative backups:
  - `bcc`: `baseline_successes=10`, `rejit_successes=10`, site total `961`
  - `bpftrace`: `baseline_successes=6`, `rejit_successes=6`, site total `33`
  - `scx`: comparable workload summary present
  - `tetragon`: comparable workload summary present
  - `tracee`: `sample_count=5`
  - `katran`: comparable `baseline/rejit` BPF + workload summary present

#### `make vm-selftest`

- Current behavior no longer matches the old one-line description in §6.4.
- `runner/scripts/vm-selftest.sh` now:
  - loads kinsn modules once
  - auto-discovers all `rejit_*` binaries in `tests/unittest/build`
  - runs `adversarial_rejit`
  - runs `fuzz_rejit`
- So this target is no longer just `rejit_poc + rejit_safety_tests`.

#### `make vm-test`

- This is the real umbrella VM validation target now.
- `runner/scripts/run_all_tests.sh` covers:
  - kernel selftest
  - repo-owned unittest suite
  - repo-owned negative suite
  - upstream `test_verifier`
  - upstream `test_progs`
- In practice, `validate` and `vm-all` use `vm-test`, not `vm-selftest`.

## B. Benchmark Framework 完成度

### B.1 App Runners: implemented vs used vs missing

Current shared runner registry (`runner/libs/app_runners/__init__.py:136-154`) contains `17` runner families:

- `bcc`
- `bpftrace`
- `calico`
- `coroot-node-agent`
- `datadog-agent`
- `katran`
- `kubearmor`
- `libbpf-bootstrap`
- `loxilb`
- `scx`
- `suricata`
- `systemd`
- `tetragon`
- `tracee`
- `tubular`
- `xdp-tools`
- `xdp-tutorial`

Current active benchmark suite (`corpus/config/macro_apps.yaml`) uses only `6` runner families and `20` apps:

- `bcc`: 10 apps
- `bpftrace`: 6 apps
- `scx`: 1 app
- `tetragon`: 1 app
- `katran`: 1 app
- `tracee`: 1 app

Implemented but currently unused in the suite:

- `calico`
- `coroot-node-agent`
- `datadog-agent`
- `kubearmor`
- `libbpf-bootstrap`
- `loxilb`
- `suricata`
- `systemd`
- `tubular`
- `xdp-tools`
- `xdp-tutorial`

Repos listed in `runner/repos.yaml` but still lacking aligned shared runner coverage:

- `cilium`
- `linux-selftests`
- `netbird`
- `opentelemetry-ebpf-profiler`
- `xdp-examples`
- `KubeArmor` is also mismatched by naming: repo list uses `KubeArmor`, runner registry uses lowercase `kubearmor`

Bottom line:

- The app-runner layer is no longer the blocker it used to be.
- But the suite is still narrower than the planned real-program coverage in §5.3 and §5.6.

### B.2 Orchestrator 是否符合 §5.6 设计

Mostly yes, architecturally.

What matches §5.6:

- YAML is app-centric, not object-centric:
  - `corpus/config/macro_apps.yaml` lists apps/loaders only
- Corpus and E2E share the AppRunner layer:
  - runner registry in `runner/libs/app_runners/__init__.py`
- Corpus uses loader-instance lifecycle:
  - `run_app_runner_lifecycle()` in `runner/libs/case_common.py:735-782`
- Same-image paired measurement exists:
  - baseline measure -> REJIT -> post-REJIT measure inside one loader lifetime (`corpus/driver.py:693-804`)
- Daemon is started once per suite, not once per program:
  - `with DaemonSession.start(...)` wraps the whole corpus suite (`corpus/driver.py:823-889`)
- Daemon crash is fail-fast at suite level:
  - after each app, the suite checks daemon exit and turns the remainder into fatal error (`corpus/driver.py:863-887`)
- `micro` still uses the separate minimal tool path, which matches the “micro 保留极简 C++ tool” direction:
  - `runner/build/micro_exec`

What does not fully match §5.6 or current repo rules:

- `scx` corpus measurement is app-level, not per-program `exec_ns`:
  - `runner/libs/app_runners/scx.py:56-57` returns `corpus_measurement_mode() == "app"`
  - latest corpus artifact therefore treats `scx/rusty` as one comparable app-level row, not 13 comparable program rows
- The idealized “corpus/driver.py ~200 lines” is no longer true:
  - current corpus driver is much larger and carries more reporting/metadata logic
- Repo-level “corpus bulk prepare/load all, then optimize all, then measure all” is not what current implementation does:
  - current corpus loops app-by-app, each with start -> baseline -> REJIT -> post -> stop
  - this follows loader-instance design, but not the stricter “bulk prepare” wording in repo instructions

### B.3 测量方法是否符合 §5.5 约定

Partially yes.

What is aligned:

- Program-mode corpus/E2E compare `exec_ns`, not `wall_exec_ns`
- `wall_exec_ns` is recorded in micro artifacts but is not the headline comparison field
- App-native cases use real loaders and real workloads
- Tracee artifacts contain explicit paired statistics and p-values

Current deviations / limitations:

- §5.35 says every corpus program must have `exec_ns`; current corpus result still excludes many discovered programs:
  - `43` with `missing_baseline_exec_ns`
  - `11` with `missing_rejit_exec_ns`
- `scx` corpus is app-throughput based, not per-program `exec_ns`
- Current default repetition counts are well below the stated statistical floor:
  - corpus default: `samples=30`
  - tracee E2E: `sample_count=5`
  - vm-micro default: `samples=3`, `inner_repeat=100`
  - vm-micro-smoke: `samples=1`, `inner_repeat=50`
  - local smoke: `samples=1`, `inner_repeat=10`
- I do not see current 2026-04-03 corpus headline artifacts satisfying the “repeat >= 50, paper >= 500” requirement

## C. 结果 Artifact

### C.1 `micro/results/`

Latest relevant entries:

| Artifact | Completed | Meaning |
|---|---|---|
| `micro/results/smoke_20260403_174351/` | `2026-04-03T17:43:51Z` | latest local `make smoke` artifact |
| `micro/results/vm_micro_smoke_20260403_051538/` | `2026-04-03T05:16:02Z` | latest `make vm-micro-smoke` artifact |
| `micro/results/vm_micro_20260403_051623/` | `2026-04-03T05:17:33Z` | latest `make vm-micro` artifact |

Observations:

- local smoke is current and directly machine-readable
- `vm-micro-smoke` currently covers `62` benchmarks, not just `simple + load_byte_recompose + cmov_dense`
- latest `vm-micro` result schema is detailed but not uniform with corpus/e2e:
  - `metadata.json` has `status=completed`
  - `details/result.json` has no single top-level `pass/fail` field like corpus/e2e

Authoritative backup status:

- `micro/results/README.md` explains the directory convention correctly
- but top-level authoritative JSONs are stale
- latest top-level authoritative micro backups I found are from `20260320` / `20260318` / `20260313`
- there is no top-level `vm_micro_authoritative_20260403.json`

### C.2 `corpus/results/`

Latest full run:

- `corpus/results/vm_corpus_20260403_035346/`
- `metadata.json` completed at `2026-04-03T04:36:58Z`
- `result.json` is the best current machine-readable source for corpus status

Current authority situation:

- the run directory is current and good
- but there is no new top-level corpus authoritative JSON for `2026-04-03`
- `corpus/results/README.md` still lists old authority files up to mid-March and is stale

### C.3 `e2e/results/`

Latest full sweep is stored as six per-case directories, not one monolithic suite artifact:

- `tracee_20260403_043753`
- `tetragon_20260403_044745`
- `bpftrace_20260403_044905`
- `scx_20260403_045546`
- `bcc_20260403_045709`
- `katran_20260403_050750`

Authoritative backups are best here:

- `e2e/results/tracee_authoritative_20260403.json`
- `e2e/results/tetragon_authoritative_20260403.json`
- `e2e/results/bpftrace_authoritative_20260403.json`
- `e2e/results/scx_authoritative_20260403.json`
- `e2e/results/bcc_authoritative_20260403.json`
- `e2e/results/katran_authoritative_20260403.json`

But:

- `e2e/results/README.md` is stale; it still lists only much older authoritative snapshots

### C.4 权威数据备份

What exists:

- `e2e/results/*_authoritative_20260403.json` for all six current E2E cases
- historical AWS tarballs:
  - `.cache/aws-arm64/results/benchmark_20260329_200533.tar.gz`
  - multiple `.cache/aws-x86/results/benchmark_20260329_*.tar.gz`

What is missing:

- no fresh `20260403` top-level authoritative corpus JSON
- no fresh `20260403` top-level authoritative micro JSON
- `vm-test`, `vm-selftest`, `vm-negative-test`, `check` do not have a standardized machine-readable artifact tree comparable to `micro/results`, `corpus/results`, `e2e/results`

## D. 已知问题和 Gap

### D.1 Plan doc 里仍未完成或仍未真正闭环的 benchmark 任务

Still open in §5:

- §5.2 question 3: legality substrate acceptance on real programs is still marked `🔄`
- §5.2 question 5: operator-safe policy management in production-like deployment is still marked `🔄`
- §5.4 hardware item 2: smaller-core / Atom-like x86 is still `❌`
- §5.4 hardware item 3: arm64 is still only `🔄`, with “性能数据有限”

The suite has improved since those lines were written, but the underlying paper-level gaps remain real.

### D.2 Code / script TODO / FIXME / HACK markers

Relevant repo-owned markers I found:

- `runner/src/kernel_runner.cpp:968`
  - `TODO: moved to Python orchestrator (§5.6)`
  - This suggests old runner-side logic is still present even after the Python orchestrator became canonical.
- `e2e/cases/bpftrace/scripts/biosnoop.bt:5`
  - `TODO: Add offset and size columns.`
  - Minor, but still a visible TODO in a benchmarked case asset.
- `runner/libs/app_runners/scx_support.py`
  - `HACKBENCH_TIME_RE = ...`
  - Not necessarily wrong, but it is a “hacky” parser boundary in one of the active runners.

### D.3 与 §5.35 / §5.6 / §6.4 的主要偏差

1. Not every discovered corpus program has comparable `exec_ns`.

- Latest corpus run discovered `114` programs but reports only `61` comparable samples.
- Exclusion counts are:
  - `missing_baseline_exec_ns = 43`
  - `missing_rejit_exec_ns = 11`
- Largest exclusion sources:
  - `tracee/default`: `31` exclusions out of `44` programs
  - `scx/rusty`: `13` exclusions out of `13` programs, with one app-level comparable row instead
  - `bcc/opensnoop`: `4` exclusions out of `6`

2. `scx` corpus is app-level, not per-program.

- This is the clearest single deviation from the strict wording of §5.35 and §5.6.

3. §6.4 command descriptions are stale in multiple places.

- `make check`
  - doc says `all + daemon-tests + smoke`
  - actual `Makefile:395-399` is `all + daemon-tests + python-tests + smoke`
- `make validate`
  - doc says `check + vm-selftest + vm-micro-smoke`
  - actual `Makefile:401-404` is `check + vm-test + vm-micro-smoke`
- `make vm-all`
  - doc says `vm-selftest + vm-micro + vm-corpus + vm-e2e`
  - actual root and runner makefiles use `vm-test + vm-micro + vm-corpus + vm-e2e`
- `make vm-selftest`
  - doc still describes the old tiny selftest set
  - actual script runs full repo unittest auto-discovery plus negative fuzz/adversarial
- `make vm-micro-smoke`
  - doc says 3 benchmark subset with `kernel + kernel-rejit`
  - actual implementation is `62` benchmarks with `llvmbpf + kernel`
- `make vm-micro`
  - doc says `kernel + kernel-rejit`
  - actual implementation is `llvmbpf + kernel`
- `make vm-e2e`
  - doc text still emphasizes older case set and retired `xdp_forwarding`
  - actual live suite is `tracee + tetragon + bpftrace + scx + bcc + katran`

4. Result README files are stale.

- `corpus/results/README.md` and `e2e/results/README.md` do not reflect the 2026-04-03 authoritative snapshots now present in-tree.

5. Root `Makefile` is not very “thin”.

- VM targets themselves are thin wrappers into `runner/Makefile`, which is good.
- But the root file still owns a lot of AWS/ARM64/kernel/test orchestration and is wider than the stated repo preference.

6. AWS benchmark entrypoints are exposed but retired.

- Root `Makefile` still advertises AWS commands.
- But:
  - `runner/scripts/aws_arm64.sh:633` says remote benchmark flow was retired
  - `runner/scripts/aws_x86.sh:1089` says remote benchmark flow was retired
- So there is a visible entrypoint/implementation mismatch.

## E. 论文级 Benchmark 还差什么

### E.1 对照 §5.1 Required Baselines

| Required baseline | Current status | Notes |
|---|---|---|
| Stock kernel JIT | Present | This is the active baseline in current corpus/e2e. |
| `kernel-fixed-cmov/wide/rotate/lea` fixed peephole | Missing from current vm-* path | Historical analysis exists in tracker #611, but current 2026-04-03 artifacts do not rerun this baseline. |
| `advisor-static` | Missing | I did not find a live benchmark path or fresh artifacts for it. |
| `advisor-profiled` | Missing | Same as above. |
| llvmbpf upper bound | Partial | Present in micro and local smoke; not integrated into current corpus/e2e headline runs. |

Conclusion:

- Current benchmarking can answer “stock vs current BpfReJIT path” on x86.
- It cannot yet answer the full baseline matrix promised in §5.1.

### E.2 对照 §5.2 Required Questions

| Question | Current status | Review |
|---|---|---|
| Q1: policy differs by hardware/workload/program? | Partial | Local x86 data exists. Historical AWS x86/arm64 data exists. Fresh 2026-04-03 cross-hardware rerun is not present. |
| Q2: can it beat fixed kernel heuristics? | Not currently answered by fresh artifacts | No fresh fixed-baseline runs in current vm-* outputs. |
| Q3: legality substrate acceptance on real programs? | Partial | Apply-site counts and per-program exclusions exist, but suite coverage is still narrow and acceptance-rate reporting is not complete. |
| Q4: does it generalize across directive families? | Partial-to-good | Current default pass set spans multiple in-scope families, but isolated ablation data is not part of the fresh authority set. |
| Q5: can operators manage policy safely in production-like deployment? | Partial | E2E harness is much better now, but a stronger operational story is still missing. |

### E.3 对照 §5.3 Required Workloads

What is already there:

- Mechanism-isolation micro coverage is strong
  - the suite includes `load_byte_recompose`, `binary_search`, `switch_dispatch`, `branch_layout`, `cmov_select`, `log2_fold`, etc.
- Real app-native runners are now live for:
  - BCC
  - bpftrace
  - SCX
  - Tetragon
  - Katran
  - Tracee
- E2E production-like cases do exist now
  - especially `Katran`, `Tracee`, `Tetragon`

What is still missing or thin:

- The current suite is still narrower than the “Cilium / Katran / loxilb / Calico / xdp-tools / selftests” workload list in §5.3.
- Missing or not-yet-used real-program families are still substantial:
  - `cilium`
  - `xdp-examples`
  - `linux-selftests`
  - `netbird`
  - `opentelemetry-ebpf-profiler`
  - plus implemented-but-unused runners like `calico`, `loxilb`, `xdp-tools`, `xdp-tutorial`, `systemd`
- The retired dataplane E2E case leaves current dataplane/deployment coverage thinner than the plan originally implied.

### E.4 对照 §5.4 Required Hardware

| Hardware requirement | Current status | Review |
|---|---|---|
| Modern wide OoO x86 | Yes | Current local VM runs cover this. |
| Smaller-core / Atom-like x86 | No | Still effectively missing. Historical AWS x86 `t3.micro` exists, but that is not the same as the stated smaller-core target. |
| arm64 | Partial / stale | Historical AWS arm64 tarballs exist, but current remote benchmark flow is retired and there is no fresh 2026-04-03 arm64 suite artifact. |

### E.5 统计要求：`repeat >= 50`, 论文级 `>= 500`

Current fresh artifacts do not meet the stated bar.

- corpus:
  - default suite is `samples=30`
  - below the minimum `50`
- tracee E2E:
  - `sample_count=5`
- other E2E cases:
  - current configs are mostly duration-based baseline/post measurements, not `50+` paired repetitions
- vm-micro:
  - `samples=3`, `inner_repeat=100`
  - useful for regression, not paper-grade
- vm-micro-smoke:
  - `samples=1`, `inner_repeat=50`
- local smoke:
  - `samples=1`, `inner_repeat=10`

There is some statistical machinery in the code/artifacts, especially in Tracee:

- paired deltas
- p-values
- bootstrap-like summaries / confidence intervals

But the sample counts are still far below the paper-level target, so the presence of the machinery does not make the current artifact set paper-ready.

## Final Assessment

Current benchmark status is:

- good enough for day-to-day regression checking
- good enough to support the claim that the new app-centric corpus/E2E framework is working on local x86
- not yet good enough for the full paper-quality evaluation promised by §5.1-§5.4 and §5.35

The highest-value next steps are:

1. Refresh docs so §6.4 matches reality.
2. Decide whether corpus should strictly require per-program `exec_ns` for every discovered program, or explicitly bless the current exclusion/app-mode behavior.
3. Fill runner/suite coverage gaps for the missing real-program families.
4. Restore a supported cross-hardware evaluation path, especially arm64.
5. Rerun with paper-level repetition counts and fresh non-stock baselines.
