# Strict Final Review 2026-03-29

## Scope
- Baseline: `docs/kernel-jit-optimization-plan.md` §5.6.
- Method: static code review only. I did not run VM workloads, kernel tests, or benchmarks.
- Principle legend:
  - `P1`: all programs must be loaded by native apps; `bpftool` may only be used for stats/introspection
  - `P2`: YAML must list apps only, not objects/programs
  - `P3`: no object-level planning/scheduling/routing
  - `P4`: lifecycle unit is the loader instance
  - `P5`: corpus and E2E share app runners; only metrics differ
  - `P6`: zero fallback / compatibility / silent failure
  - `P7`: app runner must be self-contained and must not import `e2e`
  - `P8`: daemon is started once per benchmark session

## Coverage
- Mandatory files missing from the tree: `corpus/config/macro_corpus.yaml`, `e2e/case_common.py`, `e2e/cases/katran/case.py`, `runner/libs/app_runners/katran.py`, `runner/libs/app_runners/katran_support.py`, `runner/libs/corpus.py`, `runner/src/batch_runner.cpp`.
- Additional framework files reviewed because they are directly on the live path or are the surviving replacements for missing files: `runner/libs/case_common.py`, `runner/libs/catalog.py`, `runner/libs/commands.py`, `runner/libs/object_discovery.py`, `runner/libs/app_runners/tracee_support.py`, `runner/libs/app_runners/tetragon_support.py`, `runner/libs/app_runners/scx_support.py`, `runner/scripts/x86_remote_benchmark.py`, `runner/scripts/arm64_t4g_remote_benchmark.py`.
- `P7` check passed on the reviewed app-runner tree: no `runner/libs/app_runners/**` module imports `e2e` or `corpus`.
- `P1` check passed on the mandatory file set: no `bpftool loadall` loader path remains there. The only live `P1` violations I found are in the extra remote benchmark scripts listed below.

## CRITICAL
- `runner/scripts/x86_remote_benchmark.py:323,392` still loads programs with `bpftool prog loadall` and documents the method as `"bpftool prog loadall/run pinned + daemon serve optimize"`. This is a direct violation of the new loader contract. Violates: `P1`.
- `runner/scripts/arm64_t4g_remote_benchmark.py:297,366` contains the same `bpftool prog loadall` loader path and the same documented method string. This is the same design violation on the ARM64 remote path. Violates: `P1`.
- `corpus/orchestrator.py:151-155,248-303` parses `repeat`, emits `repeat` in the result payload, and exposes it to tests, but `_run_app()` is executed exactly once per app. The framework therefore reports repeated measurements that never happened. Violates: `P6`.
- `runner/libs/rejit.py:454-466` explicitly discards `prog_fds` via `del prog_fds` before scanning. Tracee's lifecycle code goes out of its way to capture loader-owned FDs, but the scan path ignores that identity and falls back to raw prog IDs. That breaks the rule that the lifecycle unit is the loader instance. Violates: `P4`, `P6`.
- `runner/libs/app_runners/tracee_support.py:39-56,208-216,233-238` silently falls back from `pidfd_getfd` to `/proc/<pid>/fd`, silently skips programs whose FDs cannot be duplicated, and suppresses FD close errors with `pass`. Combined with `scan_programs()` ignoring `prog_fds`, the Tracee path tolerates loader-instance identity loss instead of aborting. Violates: `P4`, `P6`.

## HIGH
- `runner/libs/agent.py:41-45` `wait_healthy()` swallows every exception from `health_check_fn()` and retries silently. Loader health failures become invisible until timeout instead of surfacing immediately. Violates: `P6`.
- `runner/libs/app_runners/scx_support.py:64-84,100-103` unreadable sched_ext state becomes `"missing"` or `[]`, unreadable ops entries are skipped, and scheduler launch uses `ulimit -l unlimited >/dev/null 2>&1 || true;`. This is explicit compatibility fallback in the loader path. Violates: `P6`.
- `e2e/cases/scx/case.py:403-406,411-414,426-450` missing per-program runtime counters are demoted to `limitations`, and loader exceptions are preserved as strings while payload construction continues. A degraded SCX run can still come out as a normal structured payload instead of a hard failure at the first invalid state. Violates: `P6`.
- `runner/libs/case_common.py:68-79,122-141,189-201,469-474` missing kinsn module directories collapse to an empty expected set, missing `module/load_all.sh` becomes `"missing_script"`, missing daemon discovery becomes `"missing"`, and provenance errors become `"unknown"`. This is shared silent-failure behavior in lifecycle/provenance code. Violates: `P6`.
- `runner/libs/bpf_stats.py:68-78,94-114,146-190` stats collection opportunistically uses libbpf when it can, otherwise degrades to whatever `bpftool prog show` provided. The benchmark behavior therefore depends on environment-specific compatibility rather than failing fast on missing capability. Violates: `P6`.
- `runner/libs/workload.py:367-388` `run_rapid_connect_storm()` treats connection errors as transient noise and only fails if `ops_total <= 0`. Partial workload failure is tolerated and hidden in a stderr string. Violates: `P6`.
- `runner/Makefile:168-180` Tracee and Tetragon setup targets opportunistically reuse cached/system binaries when present and only run setup scripts otherwise. The same benchmark can silently use different loaders/toolchains depending on host state. Violates: `P6`.
- `runner/libs/app_runners/tracee_support.py:277-293` Tracee binary resolution cascades through explicit path, setup output, `PATH`, cached binary, and `/tmp/tracee-bin/tracee`. That is a compatibility chain in a benchmark loader path. Violates: `P6`.
- `runner/libs/app_runners/tetragon_support.py:206-214` Tetragon binary resolution cascades through explicit path, setup output, and `which("tetragon")`. Same design problem, smaller surface. Violates: `P6`.
- `runner/src/kernel_runner.cpp:355-364` Katran fixture initialization still prints `"maps not found, skipping"` and returns. Katran's app-runner/case have already been removed from Python, but the C++ runner still preserves a skip-based old path instead of deleting it. Violates: `P6`.
- `runner/src/kernel_runner.cpp:808-820` failure to preload vmlinux BTF only logs and returns from `process_runtime_state()`; the runner continues in a degraded mode instead of failing construction. Violates: `P6`.
- `runner/libs/catalog.py:80-109,237-279` the active catalog model is still centered on `object_path`, `program_object`, `trigger`, `trigger_timeout_seconds`, and synthetic `.bpf.o` construction. This is direct object-level architecture surviving next to the app-only design. Violates: `P2`, `P3`.
- `runner/libs/commands.py:6-12` and `runner/libs/object_discovery.py:12-61` retain the old `list-programs --program <object>` discovery API, including `ProgramListingEntry.object_path`. `rg` shows no production caller outside legacy paths/docs. This is undeleted object-layer discovery code. Violates: `P2`, `P3`.
- `runner/src/common.cpp:207-218` benchmark identity is still derived from `.bpf.o` filenames. That bakes object naming into active C++ runner output. Violates: `P2`, `P3`.
- `e2e/cases/bpftrace/case.py:53-66,94-99,604-606,672` the bpftrace E2E case still takes `--runner`, requires `micro_exec` to exist, and records that path in its output even though actual execution is through `BpftraceRunner`. This is live coupling to the retired micro/object architecture. Violates: `P5`, `P6`.

## MEDIUM
- `runner/libs/results.py:232-372` `summarize_corpus_batch_results()` is still an exported object-centric summarizer (`object_records`, `grouped_by_object`, `canonical_object_name`, `objects_attempted`, `by_object`). Search shows only tests/docs still use it. This is dead v1 schema that should have been deleted. Violates: `P2`, `P3`, `P5`.
- `e2e/run.py:134` and `e2e/cases/tetragon/case.py:963` still expose `--runner` defaulting to `runner/build/micro_exec`. In the unified E2E entrypoint it leaks the old micro path into every case CLI; in Tetragon it appears to be unused residue. Violates: `P5`.
- `e2e/cases/bcc/case.py:182-331` and `e2e/cases/bpftrace/case.py:209-329` duplicate the same lifecycle scaffolding, baseline/post-rejit assembly, and error handling around shared app runners. This should be one shared app-runner measurement layer, not per-case copy/paste. Violates: `P5`.
- `e2e/cases/tracee/case.py:102-135` and `e2e/cases/tetragon/case.py:160-193` implement near-identical program-selection helpers that differ only in names and error text. Same abstraction repeated in two cases. Violates: `P5`.
- `e2e/cases/tetragon/case.py:113-119` `bpftool_binary()` still contains a compatibility fallback chain, but grep shows no call sites. This is dead compatibility residue that should have been deleted. Violates: `P6`.
- `runner/libs/run_artifacts.py:120-133` unreadable or malformed `metadata.json` is treated as “not a managed artifact” and silently ignored. Artifact corruption disappears instead of surfacing. Violates: `P6`.

## LOW
- `runner/libs/results.py:341,370-371` exported field names `objects_attempted` and `by_object` still use old object-centric vocabulary. Even if the function is dead, the public naming is inconsistent with the app-only design. Violates: `P2`.

