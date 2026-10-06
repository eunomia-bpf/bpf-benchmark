# E2E Benchmark Complexity Review (2026-04-24)

## Quick answers to the 9 review questions

- `bootstrap_mean_ci` / `summarize_numeric_distribution` / `exact_paired_permutation_pvalue` / `paired_metric_report` style code: not present in the reviewed source files. Current hits are only in out-of-scope `runner/libs/reporting.py` and in historical `e2e/results/tracee_*` artifacts.
- `paired_cycles` style storage: not present in the reviewed source files. Current hits are historical `tracee` result artifacts only.
- `verify_phase_measurement` style over-checks: yes. The main live analogue is `corpus/driver.py:_has_phase_measurement()` plus `_finalize_app_result()` hard-failing on zero observed counters. There are also stricter-than-needed stabilization/health checks in `case_common.py` and `app_runners/process_support.py`.
- `latency probe` style rarely-used complexity: no current `latency_probe` field in source, but there is still comparable unused complexity in `runner/libs/app_runners/tracee.py` (`TraceeOutputCollector.wait_for_event()`, event queues/counters/parse-error bookkeeping) and extra latency/stat parsing in `scx` / `katran`.
- Huge redundant `result.json` fields: yes. Current code still writes large duplicated structures: `initial_stats` + `final_stats` + `bpf` delta, repeated `scan_results/programs/process` in both phases, derived `summary/comparison/programs/per_app` layers, and `e2e/driver.py` copies payloads again into `metadata.json`.
- Overgrown error handling / fallbacks: yes. Biggest sources are `e2e/driver.py`, `runner/libs/case_common.py`, `corpus/driver.py`, `runner/libs/app_runners/tracee.py`, and `runner/libs/app_runners/tetragon.py`.
- Dead code / never-hit branches: yes. The clearest live examples are `runner/libs/case_common.py:percentile()`, `runner/libs/app_runners/tracee.py:TraceeOutputCollector.wait_for_event()`, and Tracee multi-command launch fallback even though current `build_tracee_commands()` returns one command.
- `case_common.py` functionality only used by one case: yes. `measure_app_runner_workload()`, `run_app_runner_phase_records()`, and `zero_site_totals()` are effectively `bcc`/`bpftrace`-specific.
- Boilerplate repeated across cases: yes. `bcc` and `bpftrace` are near-clones. `scx` and `tetragon` repeat the same measure -> summarize -> compare -> markdown pattern.

## Size evidence from current artifacts

- Historical pre-simplification Tracee artifacts still in-tree show the old failure mode clearly:
  - `e2e/results/tracee_20260423_225754_021437/result.json`: `89,393,213` bytes
  - `e2e/results/tracee_20260423_225754_021437/metadata.json`: `50,328,198` bytes
- Current non-tracee cases still have meaningful bloat:
  - `e2e/results/tetragon_20260423_232610_287844/result.json`: `15,847,935` bytes
  - `e2e/results/scx_20260424_021605_922802/result.json`: `438,587` bytes
  - `e2e/results/bcc_20260423_234256_188825/result.json`: `800,476` bytes
  - `corpus/results/vm_corpus.json`: `6,026,497` bytes
- `e2e/driver.py` also duplicates payloads into `metadata.json`, which is why metadata can still be hundreds of KB to tens of MB even after trimming.

## Per-file findings

### `e2e/cases/bcc/case.py`

- HIGH: `summarize_tool()`, `geomean()`, `collect_record_errors()`, `build_markdown()`, `build_report()`, and the top-level aggregate `summary` build a second derived data model on top of raw phase data. This is exactly the kind of analysis/aggregation layer the stated principle says to delete. Lines `184-400`, `483-523`. Estimated removal: `~220-250` lines.
- MEDIUM: Missing-binary handling manufactures a full fake baseline + summary record instead of emitting one simple case error. Lines `430-464`. Estimated removal: `~30-35` lines.
- MEDIUM: This file is a near-clone of `e2e/cases/bpftrace/case.py`; roughly `~150-180` lines of the code above are duplicated boilerplate, not unique logic. Do not double-count this against the first item.

### `e2e/cases/bpftrace/case.py`

- HIGH: Same problem as `bcc`: `summarize_script()`, `geomean()`, `collect_record_errors()`, `build_markdown()`, `build_report()`, and top-level `summary` add derived stats and duplicate representations instead of keeping raw phase outputs only. Lines `157-388`, `421-463`. Estimated removal: `~210-240` lines.
- MEDIUM: `ensure_required_tools()` stores a fairly rich environment/version report in payload purely for reporting/debugging. Under the stated principle, that belongs outside benchmark results. Lines `54-81`, `445-452`. Estimated removal: `~25-35` lines.
- MEDIUM: Near-duplicate of `e2e/cases/bcc/case.py`; roughly `~150-180` lines of the code above are repeated structure, not unique logic. Overlaps the first item.

### `e2e/cases/katran/case.py`

- HIGH: The case computes only a derived `comparison` object and drops raw baseline/post-ReJIT measurements entirely. Under the stated principle this layer should disappear and raw measurements should be kept instead. Lines `122-161`. Estimated removal: `~35-45` lines.
- MEDIUM: `comparison` carries extra ratios/deltas (`bpf_speedup`, workload ratio, CPU delta) rather than a raw measurement record. Lines `139-152`. Estimated removal: `~15-20` lines.
- MEDIUM: `measure_workload()` stores `system_cpu` and `runner_summary`, but the final payload never preserves the raw measurement anyway. This is pure wasted complexity. Lines `45-72`. Estimated removal: `~20-25` lines.

### `e2e/cases/scx/case.py`

- HIGH: `summarize_phase()`, `compare_phases()`, `build_markdown()`, and `site_summary` add a large derived reporting layer on top of raw measurements. Lines `318-476`, `623-667`. Estimated removal: `~220-280` lines.
- HIGH: `measure_workload()` stores non-core extras: agent CPU, system CPU, context switches, process count, latency p50/p95, command, stdout/stderr tails, live program-id maps, and full live program snapshots. The stated principle only keeps raw throughput + BPF delta. Lines `107-216`. Estimated removal: `~110-150` lines.
- MEDIUM: Runtime-counter / site-total validation can fail the whole case for metadata issues rather than just preserving the raw run result with a limitation note. Lines `603-644`, `647-654`. Estimated removal: `~35-45` lines.
- MEDIUM: The overall shape is very close to `tetragon/case.py` and could be collapsed into a smaller shared pattern. Rough overlap: `~150-200` lines.

### `e2e/cases/tetragon/case.py`

- HIGH: `summarize_phase()`, `aggregate_programs()`, `build_program_summary()`, `compare_phases()`, and `build_markdown()` create a second and third representation of the same run. Lines `189-451`, `576-599`. Estimated removal: `~230-300` lines.
- HIGH: `measure_workload()` stores extra CPU fields, `events_total`, `events_per_sec`, and stdout/stderr tails. `events_total/events_per_sec` are themselves derived from BPF delta summary, so this is aggregation on top of aggregation. Lines `113-186`. Estimated removal: `~80-110` lines.
- MEDIUM: `before_rejit()` aborts the case if the agent looks unhealthy after baseline, and several branches hard-fail on missing per-program records/post phase. This is stricter than needed if the goal is to preserve raw outputs and mark the run limited. Lines `521-563`, `575-582`. Estimated removal: `~35-50` lines.
- MEDIUM: Like `scx`, this repeats the same measure -> summarize -> compare -> markdown skeleton. Rough overlap: `~150-200` lines.

### `e2e/cases/tracee/case.py`

- LOW: This is the clean reference. No current `paired_cycles`, `control_app_throughput`, `latency_probe`, bootstrap/permutation stats, or significance layers remain in source.
- LOW: Remaining extras are mostly metadata (`setup`, `host`, `config`, `tracee_launch_command`, `limitations`) around otherwise raw `baseline` / `post_rejit` / `rejit_result` records. Lines `126-190`, `193-223`, `381-397`. Estimated removable extras: `~20-40` lines.

### `e2e/driver.py`

- HIGH: `build_run_metadata()` stores a second trimmed copy of the whole payload in `metadata.json` via `_trim_e2e_value(payload)`. This duplicates `result.json` and materially increases artifact size. Lines `193-216`. Estimated removal: `~20-30` lines.
- MEDIUM: The `build_report` / `report.md` plumbing exists only to support extra analysis layers in `bcc` / `bpftrace`. Lines `69-117`, `270-294`. Estimated removal: `~15-25` lines.
- MEDIUM: Invalid-status normalization plus double error-write paths are more defensive than the benchmark needs. Lines `275-347`. Estimated removal: `~25-35` lines.

### `runner/libs/case_common.py`

- HIGH: `measure_app_runner_workload()` stores `initial_stats`, `final_stats`, and `bpf` delta all at once. That is duplicate storage of the same measurement. Lines `598-638`. Estimated removal: `~25-35` lines.
- HIGH: `run_app_runner_phase_records()` duplicates `programs`, `prog_ids`, `scan_results`, `site_totals`, and `process` into both baseline and post-ReJIT payloads; this helper is effectively only for `bcc` / `bpftrace`. Lines `645-709`. Estimated removal: `~60-90` lines.
- HIGH: `_resolve_scan_pass_selection()`, `_resolve_apply_passes_by_program()`, `_merge_group_rejit_results()`, and `_slice_rejit_result()` enrich raw daemon apply output with `scan`, `enabled_passes`, grouped apply synthesis, and program-count summaries. Under the stated principle these are extra derived metadata, not canonical results. Lines `186-352`. Estimated removal: `~160-220` lines.
- MEDIUM: `wait_for_suite_quiescence()` can fail an entire suite run on stabilization noise even though it is not core benchmark data. Lines `26-52`. Estimated removal: `~25-30` lines.
- LOW: `percentile()` is dead in the reviewed source set. Lines `744-751`. Estimated removal: `~8` lines.

### `runner/libs/bpf_stats.py`

- HIGH: `compute_delta()` returns both raw per-program deltas and a derived `summary`. Under the stated principle, the `summary` block is extra aggregation and should disappear. Lines `64-96`. Estimated removal: `~10-15` lines.
- MEDIUM: `sample_bpf_stats()` / `compute_delta()` carry static `bytes_jited` and `bytes_xlated` fields that are not part of the delta signal. Lines `26-38`, `85-86`. Estimated removal: `~6-10` lines.

### `runner/libs/metrics.py`

- HIGH: This entire file exists to compute agent/system CPU overhead extras. If benchmark payloads keep only throughput + BPF delta, most or all of this file becomes unnecessary. Lines `1-83`. Estimated removal: `~70-80` lines.

### `runner/libs/app_runners/__init__.py`

- LOW: No major unnecessary complexity found relative to the rest of the framework.

### `runner/libs/app_runners/base.py`

- LOW: `last_workload_details` is mainly an escape hatch for extra per-case metadata (`scx` / `katran`). If those extras go away, this abstraction can shrink. Lines `31-37`. Estimated removal: `~5-10` lines.
- LOW: `_fail_start()` spends non-trivial logic formatting stdout/stderr tails for diagnostics. Helpful, but not core benchmark logic. Lines `39-50`. Estimated removal: `~10-12` lines.

### `runner/libs/app_runners/bcc.py`

- MEDIUM: Custom `_TailCapture` + stream-drain logic duplicates the generic process-output collector pattern already used elsewhere, mostly to retain stdout/stderr tails. Lines `173-208`, `413-505`. Estimated removal: `~70-90` lines.
- LOW: `_prepare_bcc_kernel_source()` and `_prepare_bcc_python_compat()` are large environment-compatibility hacks, not benchmark logic. They are non-core complexity, but risky to remove without changing the supported environment. Lines `288-364`. Estimated removable non-core code: `~140-190` lines.

### `runner/libs/app_runners/bpftrace.py`

- MEDIUM: `finalize_process_output()` plus manual stdout/stderr capture exists mainly for diagnostics and result payload tails, not measurement. Lines `58-66`, `113-180`. Estimated removal: `~25-35` lines.
- LOW: This runner duplicates patterns already centralized in `process_support.py`. Overlap only, not extra total.

### `runner/libs/app_runners/katran.py`

- HIGH: The embedded parallel client computes latency distribution (`p50/p90/p99`), byte totals, failure previews, and concurrency summaries even though the e2e case only needs throughput. Lines `663-770`. Estimated removal: `~90-140` lines.
- HIGH: `last_request_summary` persists those extra stats and `e2e/cases/katran/case.py` copies them into `runner_summary`, but the final case payload still throws away the raw baseline/post-ReJIT measurement. Lines `909-918`, `981-995`. Estimated removal: `~20-30` lines.
- MEDIUM: The runner also carries substantial topology/setup/artifact logic (`topology`, namespace HTTP server, map configuration, validation) that is operationally necessary but not benchmark-data logic. Keep separate from canonical result payloads if retained.

### `runner/libs/app_runners/process_support.py`

- MEDIUM: `wait_until_program_set_stable()` adds a strict stabilization gate and a lot of diagnostic text composition. This is useful for bring-up, but it is non-core control-flow complexity and can cause avoidable failures. Lines `27-89`. Estimated removal: `~45-60` lines.
- MEDIUM: `ProcessOutputCollector`, `AgentSession`, and `ManagedProcessSession` exist largely to capture stdout/stderr tails and surface richer failure messages. Under the stated principle this can be much smaller. Lines `92-268`. Estimated removal: `~70-100` lines.

### `runner/libs/app_runners/scx.py`

- HIGH: Workload helpers parse latency p50/p95 and retain command/stdout/stderr history, but the benchmark principle only needs throughput + BPF delta. Lines `148-249`. Estimated removal: `~45-70` lines.
- MEDIUM: `last_workload_extra` / `last_workload_details` exist only to feed those extra latency/command fields into `e2e/cases/scx/case.py`. Lines `309-350`. Estimated removal: `~10-15` lines.

### `runner/libs/app_runners/setup_support.py`

- LOW: No major unnecessary complexity found.

### `runner/libs/app_runners/tetragon.py`

- MEDIUM: `TetragonAgentSession` has layered cleanup/error-rewrite paths whose main value is nicer diagnostics, not benchmark data. Lines `31-74`. Estimated removal: `~35-50` lines.
- LOW: `inspect_tetragon_setup()` returns a verbose setup payload purely for reporting/debug output. Lines `96-115`. Estimated removal: `~15-20` lines.

### `runner/libs/app_runners/tracee.py`

- HIGH: `TraceeOutputCollector` keeps `events`, `event_counts`, `total_events`, parse-error samples, and `wait_for_event()`, but the current `e2e/cases/tracee/case.py` never consumes this as benchmark data. This is the strongest live dead-complexity pocket in the framework. Lines `70-289`. Estimated removal: `~140-200` lines.
- MEDIUM: `TraceeAgentSession.__enter__()` supports trying multiple commands, but current `build_tracee_commands()` returns a single command. That fallback structure is effectively unused now. Lines `301-358`, `438-442`. Estimated removal: `~20-30` lines.
- LOW: `latest_stats` is propagated into `process_output` but never consumed by the e2e case. Lines `239-257`, `571-577`. Estimated removal: `~10-15` lines.

### `corpus/driver.py`

- HIGH: `_measure_runner_phase()` stores `workload`, `workloads`, `initial_stats`, `final_stats`, `live_prog_id_map`, and `live_programs`; `_finalize_app_result()` then derives `program_measurements` containing nested `baseline`, `rejit`, and `apply` again. This is the biggest live duplicate-storage problem outside historical Tracee. Lines `189-299`, `447-487`, `685-746`. Estimated removal: `~280-360` lines.
- HIGH: `_comparison_rows()`, `_per_app_breakdown()`, `_build_summary()`, and `build_markdown()` add another aggregate/report layer (`geomean`, `per_app`, `sample_count`) on top of already-derived app results. Lines `498-612`. Estimated removal: `~80-120` lines.
- HIGH: `_has_phase_measurement()` plus `_finalize_app_result()` hard-fail apps when no counters are observed in a phase. This is a direct `verify_phase_measurement` analogue and can reject otherwise useful raw runs. Lines `143-154`, `713-720`. Estimated removal: `~20-30` lines.
- MEDIUM: `run_suite()` contains a large amount of startup/failure salvage and per-app result reconstruction logic. Some is needed, but the current shape is far more defensive and verbose than the benchmark contract requires. Lines `758-914`. Estimated removal: `~120-180` lines.

## Boilerplate duplication summary

- `e2e/cases/bcc/case.py` and `e2e/cases/bpftrace/case.py` repeat the same structure almost function-for-function:
  - phase wrapper
  - summarizer
  - geomean/error collection
  - markdown/report builders
  - aggregate loop
- `e2e/cases/scx/case.py` and `e2e/cases/tetragon/case.py` repeat the same pattern:
  - measure workload with CPU extras
  - summarize phase
  - compare baseline/post
  - build markdown
  - append limitation/error metadata
- `runner/libs/app_runners/bcc.py`, `bpftrace.py`, `tetragon.py`, and `tracee.py` all carry variants of:
  - process launch
  - stdout/stderr capture
  - wait for programs to stabilize
  - stop and snapshot output

## Overall reduction estimate

- Conservative removable code in the reviewed files: `~1,700-2,100` lines.
- If the framework is pushed all the way to the stated principle:
  - keep one raw daemon output copy
  - keep one raw benchmark measurement copy (`throughput` + raw BPF delta)
  - remove summaries/comparisons/report builders/duplicate snapshots/metadata re-copy
  - then the reduction could move closer to `~2,300` lines, but that higher number overlaps multiple "duplicate boilerplate" findings above.

## Recommended deletion order

- 1. Delete payload duplication first:
  - `e2e/driver.py` metadata copy
  - `case_common.measure_app_runner_workload()` `initial_stats/final_stats`
  - `case_common.run_app_runner_phase_records()` repeated phase metadata
- 2. Delete derived reporting layers next:
  - `bcc` / `bpftrace` summary + report code
  - `scx` / `tetragon` summary + comparison + markdown-heavy layers
  - `corpus` summary/per_app/program_measurements layers
- 3. Delete runner-only extras last:
  - CPU metrics in `runner/libs/metrics.py`
  - `scx` latency parsing
  - `katran` latency/failure-preview summary
  - unused Tracee event collector machinery
