# 2026-03-30 Commit Review

## Scope

Reviewed the uncommitted benchmark-framework changes against `docs/kernel-jit-optimization-plan.md` §5.6.

Confirmed on the main repo:

- corpus/e2e orchestration is app-centric, not object-centric
- shared YAML schema uses `workload.corpus` / `workload.e2e`
- lifecycle is loader-instance based
- new error paths are generally fail-fast instead of silent degrade
- dead object-centric code removal is coherent with the redesign

## Findings Fixed Before Commit

1. `runner/src/common.cpp`
   Benchmark names regressed for `.bpf.o` inputs because `path.stem()` turned `foo.bpf.o` into `foo.bpf`. Restored the previous `.bpf.o` / `.o` stripping behavior.

2. `runner/libs/kinsn.py`
   `capture_daemon_kinsn_discovery()` read daemon stderr only once and raced daemon startup. Added bounded polling so `DaemonSession.start(load_kinsn=True)` fails only after the discovery log is genuinely missing.

3. `runner/libs/case_common.py`
   Lifecycle metadata could leave kinsn status as `completed` even if the post-ReJIT workload failed. Error exits now rewrite the final kinsn status to `error` unless the lifecycle was explicitly aborted.

4. `e2e/cases/scx/case.py`
   The payload status could stay `ok` when REJIT returned an error or when some program applied but post-ReJIT measurement was missing. The case now reports `error` in those states.

5. `daemon/src/commands.rs`
   `ServeOptimizeResponse::from(OptimizeOneResult)` dropped `attempts` entirely. It now preserves attempt metadata while stripping only the large `debug` payloads, matching the socket-response intent and tests.

6. `runner/libs/app_runners/katran_support.py`
   Removed a newly introduced silent fallback from repo-configured `bpftool` resolution to plain `"bpftool"`. Netns sysctl writes were also collapsed to a single fail-fast path instead of a silent fallback chain.

## Validation

- `python3 -m py_compile runner/libs/app_runners/katran_support.py runner/libs/kinsn.py runner/libs/case_common.py e2e/cases/scx/case.py e2e/cases/katran/case.py tests/python/test_case_common.py tests/python/test_app_suite_schema.py tests/python/test_metrics.py tests/python/test_scx_support.py`
- `pytest tests/python/ -q`
  - `77 passed`
- `make daemon-tests`
  - `535 passed`

## Commit Boundary

Included in this commit:

- main-repo benchmark framework / schema / orchestrator / e2e / runner / test changes
- this review note

Intentionally not included in this commit:

- generated result artifacts under `corpus/results/` and `e2e/results/`
- older working notes under `docs/tmp/20260329/`
- `vendor/linux-framework`
  - reviewed change is coherent, but it was not exercised by the requested validation set and should be handled as a dedicated submodule update
- `vendor/llvmbpf`
  - large independent lowering/lift work, plus an untracked nested `cli/libbpf_project/` checkout; not safe to mix into the benchmark-framework commit without separate validation
