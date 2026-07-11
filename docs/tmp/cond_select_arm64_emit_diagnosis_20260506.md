# cond_select ARM64 otel diagnosis - 2026-05-06

All code citations below were read with `git show HEAD:<path>`. Local `HEAD` during this investigation was `88e43e83`.

## 1. Evidence from corpus result

Input artifact: `corpus/results/aws_arm64_corpus_20260506_193211_995298/details/result.json`

The run is `otelcol-ebpf-profiler/profiling`, selected workload `stress_ng_cpu`, with 12 programs. All `cond_select` steps have `status=ok` and `error=null`; the overall `rejit_result.status` is `ok`.

The kop module loader loaded `bpf_select` along with the other expected kop modules. The artifact does not preserve the generated per-program `target.json`, but the run evidence is inconsistent with a missing `bpf_select64` target: `cond_select` required `--target ${TARGET}`, `bpfopt` exited successfully for every program, and the pass reports are normal per-site skips rather than `bpf_select64 kfunc not available` or a `kop 'bpf_select64' not in target` command failure.

Per-program `cond_select` report:

| prog_id | prog_name | prog_type | orig_insns | matched | applied | skipped | skip evidence |
|---:|---|---:|---:|---:|---:|---:|---|
| 82 | `perf_unwind_sto` | 7 | 1616 | 3 | 0 | 3 | all 3: `kop site in program with tail-call helper`, tail call pc 1324, site pcs 545/692/695 |
| 83 | `perf_unwind_nat` | 7 | 7152 | 8 | 0 | 8 | all 8: `kop site in program with tail-call helper`, tail call pc 6941, site pcs 2086/2472/3644/4055/5271/5445/5864/6488 |
| 84 | `perf_unwind_hot` | 7 | 6448 | 7 | 0 | 7 | 6 tail-call skips at tail call pc 6292, site pcs 1332/1513/1524/2742/4155/5848; 1 `no dead register available to materialize immediate operand` |
| 85 | `perf_unwind_per` | 7 | 7396 | 0 | 0 | 0 | none |
| 86 | `perf_unwind_php` | 7 | 6939 | 2 | 0 | 2 | all 2: `kop site in program with tail-call helper`, tail call pc 6835, site pcs 46/162 |
| 87 | `perf_unwind_pyt` | 7 | 5869 | 1 | 0 | 1 | `kop site in program with tail-call helper`, tail call pc 5836, site pc 882 |
| 88 | `perf_unwind_rub` | 7 | 5178 | 0 | 0 | 0 | none |
| 89 | `perf_unwind_v8` | 7 | 7940 | 8 | 0 | 8 | all 8: `kop site in program with tail-call helper`, tail call pc 7782, site pcs 814/1701/2588/3472/4415/5305/7135/7334 |
| 90 | `perf_go_labels` | 7 | 679 | 0 | 0 | 0 | none |
| 91 | `perf_unwind_bea` | 7 | 242 | 0 | 0 | 0 | none |
| 92 | `tracepoint__sch` | 5 | 283 | 0 | 0 | 0 | none |
| 93 | `native_tracer_e` | 7 | 1332 | 2 | 0 | 2 | all 2: `kop site in program with tail-call helper`, tail call pc 232, site pcs 728/731 |

Aggregate skip reasons for the 31 matched-but-not-applied sites:

- 30/31: `kop site in program with tail-call helper (...)`
- 1/31: `no dead register available to materialize immediate operand`
- Diagnostics were empty for every `cond_select` report.

So the 31 sites were not silently lost after an ARM64 native emit attempt. They were counted as matched/skipped by the bpfopt report, and no site reached the `safe_sites` rewrite path.

## 2. Code citations

`bpfopt/crates/bpfopt/src/passes/mod.rs:90-92` declares `cond_select` as a target-using pass with `KopRef::new("bpf_select64", &["bpf_select64"])`. `runner/libs/rejit_plan.py:102-131` unions each selected pass's `kops_used` into the daemon `kop_probes` request. `daemon/src/server.rs:207-262` parses those probes, and `daemon/src/bpf.rs:84-99` / `daemon/src/bpf.rs:166-275` probes kernel BTF and writes target kop metadata.

`bpfopt/crates/bpfopt/src/main.rs:647-665` reads `target.json`, applies its `arch`, features, and kop registry. `bpfopt/crates/bpfopt/src/main.rs:451-480` makes `cond_select` fail fast if `bpf_select64` is absent from the target. The observed successful `cond_select` steps therefore argue that `bpf_select64` was present enough for bpfopt admission.

`bpfopt/crates/bpfopt/src/pass.rs:643-659` maps `cond_select` to `bpf_select64` and stores `select64_btf_id`. `bpfopt/crates/bpfopt/src/pass.rs:994-1000` implements `PassContext::has_branchless_select()` as `has_cmov || kop_registered_for_target_name("bpf_select64")`. This is the HEAD gate that allows ARM64 with a registered select kop even when `has_cmov=false`.

`bpfopt/crates/bpfopt/src/passes/cond_select.rs:99-138` checks `has_branchless_select()` and then `select64_btf_id`. If either failed, the pass would return platform/kfunc skip reasons before normal per-site processing. That did not happen in the artifact.

`bpfopt/crates/bpfopt/src/passes/cond_select.rs:145-203` is the important path. The pass scans sites, builds lowering, checks interior branch targets, then calls `kop_replacement_subprog_skip_reason(...)`. Any returned reason is pushed into `skipped` and the site is not added to `safe_sites`.

`bpfopt/crates/bpfopt/src/passes/cond_select.rs:205-210` returns unchanged with `sites_skipped` when `safe_sites` is empty. `bpfopt/crates/bpfopt/src/passes/cond_select.rs:212-270` is the only rewrite path that emits the packed kop sidecar/call and records `sites_applied`; otel never reaches it for the 31 candidates.

`bpfopt/crates/bpfopt/src/passes/cond_select.rs:402-447`, `449-545`, and `563-589` show the matcher/lowering constraint layer. The single non-tail-call skip is produced at `materialize_value`, where `choose_temp_reg(...)` fails and returns `no dead register available to materialize immediate operand`.

`bpfopt/crates/bpfopt/src/passes/utils.rs:728-785` implements the generic kop replacement subprogram/tail-call safety check used by `cond_select`. `bpfopt/crates/bpfopt/src/passes/utils.rs:787-803` returns the exact skip string seen in the result. `bpfopt/crates/bpfopt/src/passes/utils.rs:823-844` identifies tail-call helpers and defines the protected prefix ending at the last tail-call instruction.

`bpfopt/crates/bpfopt/src/main.rs:1307-1318` explains why the report says `matched=31`: `sites_matched` is serialized as `sites_applied + sites_skipped.len()`. For this run, the sites are all skipped candidates, not successfully emitted rewrites.

`bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:271-292` already covers the ARM64 no-CMOV admission case: a context with `Arch::Aarch64`, `has_cmov=false`, and `select64_btf_id` set applies one site and emits a `BPF_PSEUDO_KOP_CALL`.

`module/arm64/bpf_select.c:8-14` defines/registers the `bpf_select64` kfunc. `module/arm64/bpf_select.c:71-114` decodes the packed payload and emits ARM64 `TST` + `CSEL`. This ARM64 kernel emitter exists, but the otel artifact provides no evidence that it was reached by any `cond_select` site.

## 3. Verdict

Dominant cause: hypothesis 3, matcher / emit constraint mismatch, specifically a generic kop replacement safety constraint around programs containing tail-call helpers. Confidence: high.

The ARM64 otel result is not primarily a `bpf_select64` registration failure. If `bpf_select64` were absent from `target.json`, `bpfopt` would fail `validate_required_kops` or report kfunc-unavailable/platform skip behavior, not 31 concrete per-site skip reasons. The loaded-module evidence also shows `bpf_select` resident.

It is also not primarily an ARM64 native emitter defect. The bpfopt pass has no ARM64-specific emit branch; it emits a cross-platform packed kop call only after a site enters `safe_sites`. In this artifact, `safe_sites` is empty: 30 candidates are rejected by the generic tail-call/KOperation replacement guard, and 1 candidate is rejected by a lowering-register constraint. The ARM64 `TST`/`CSEL` module emitter is therefore not exercised for these sites.

The x86 comparison does not isolate architecture. The x86 examples applied because their matched sites passed these generic constraints. The otel ARM64 programs are dominated by tail-call-helper programs where changing instruction count before/around the protected tail-call region is currently disallowed.

## 4. Fix dimensions

- Tail-call safety model: decide what invariants the kop replacement guard must preserve for programs with tail-call helpers and whether any cond_select replacements can be admitted without invalidating tail-call poke descriptor indexing.
- Replacement length accounting: reason about old length versus replacement length, including cond_select prefixes and the 2-instruction packed kop form, because the current guard admits only length-preserving cases after the protected tail-call prefix.
- Candidate diagnostics: keep reporting skip reasons at per-site granularity so `matched` cannot be misread as attempted native emission.
- Register-pressure handling: separately account for the one site rejected before the tail-call guard due to no dead temporary register for immediate materialization.
- Validation coverage: test representative tail-call-helper programs and high-register-pressure cond_select patterns independently from architecture-specific CSEL/CMOV lowering.
