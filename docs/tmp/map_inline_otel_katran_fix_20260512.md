# map_inline otel/katran regression fix - 2026-05-12

## Scope

Only `bpfopt` code under `bpfopt/crates/bpfopt/src/` was changed. No daemon or kernel code was changed, and no commit was created.

## Symptoms reproduced

### otelcol-ebpf-profiler/profiling

Command:

```sh
KEEP_WORKDIRS=1 BPFREJIT_CORPUS_APPS=otelcol-ebpf-profiler/profiling BPFREJIT_BENCH_PASSES=noop,map_inline SAMPLES=1 WORKLOAD_DURATION=15 make corpus
```

Failing run captured artifacts under:

```text
/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260512_202959_147735
```

The daemon passed raw `verifier_log_step0.log` files to `bpfopt --pass map_inline`. Host replay of one failing artifact reproduced the CLI failure:

```text
error: verifier states ... verifier_log_step0.log must be JSON; raw verifier logs are not accepted by the production CLI
```

This explained the observed all-program failure: `applied=0`, `matched=0`, with all 13 programs exiting at the `bpfopt` step before `map_inline` could run.

### katran

The first katran replay after fixing raw verifier-log input exposed a separate `map_inline` issue. The pass exited before using the configured hints:

```text
error: snapshot skipped map 3
```

After making skipped-size maps a site-level skip instead of a pass-fatal error, katran reached `sites_applied=12`, but `BPF_PROG_REJIT` rejected the rewritten program:

```text
R8 invalid mem access 'scalar'
```

The failure artifact was:

```text
/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260512_205045_912993/details/failure-artifacts/9.tar.gz
```

Disassembling the original and rewritten bytecode around the `vip_map` lookup showed that `map_inline` removed a hash-map fallback lookup/null-check sequence for a hard hint. On katran's hash `vip_map`, the actual lookup can still return NULL on runtime fallback paths, so deleting the check produced an unsafe pointer/scalar flow that the verifier rejected.

## Root causes

1. `read_verifier_states()` rejected raw verifier logs even though the v3 daemon passes raw verifier logs from the previous successful `BPF_PROG_REJIT(log_level=2)` step.

2. `map_inline` treated any size-skipped snapshot map with no overlay as pass-fatal, even when the failing site was unrelated to later explicit inline hints. This blocked katran's independent hints.

3. Hard hints on hash-style map lookups removed the original lookup/null-check pattern. That is only safe for proven removable lookup patterns, not for nullable hash lookups whose fallback path still depends on verifier-visible pointer checks.

## Code changes

- `crates/bpfopt/src/main.rs`
  - `read_verifier_states()` now accepts both JSON verifier-state files and raw verifier logs. JSON input keeps the existing path; non-JSON input is parsed through `verifier_states_from_log()`.

- `crates/bpfopt/src/passes/map_inline.rs`
  - Size-skipped snapshot maps now produce a per-site skip when there is no explicit hint for that call site, instead of aborting the whole pass.
  - Hard hints only remove the lookup pattern when `MapInfo::has_removable_lookup_pattern()` is true. Nullable hash lookup/null-check paths are retained while fixed-offset loads are still constantized.

- Tests:
  - Added raw verifier-log acceptance coverage.
  - Updated the CLI pipeline test to require raw verifier-log input to succeed.
  - Added coverage that size-skipped maps do not block independent hinted sites.
  - Added coverage that hard hash hints keep the lookup and null check.

## Validation

### Unit/integration tests

```sh
cargo fmt
cargo test
```

Result: passed.

### otelcol-ebpf-profiler/profiling

Command:

```sh
KEEP_WORKDIRS=1 BPFREJIT_CORPUS_APPS=otelcol-ebpf-profiler/profiling BPFREJIT_BENCH_PASSES=noop,map_inline SAMPLES=1 WORKLOAD_DURATION=15 make corpus
```

Result:

```text
/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260512_204619_060219
```

Summary from `details/apps/otelcol-ebpf-profiler__profiling.json`:

```text
status=ok
rejit_status=ok
program_count=13
failed=0
map_inline_applied=1192
map_inline_matched=1593
failure_artifacts=none
```

The applied count is restored to the historical baseline of 1192.

### katran

Command:

```sh
KEEP_WORKDIRS=1 BPFREJIT_CORPUS_APPS=katran BPFREJIT_BENCH_PASSES=noop,map_inline SAMPLES=1 WORKLOAD_DURATION=15 make corpus
```

Result:

```text
/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260512_210059_769499
```

Summary from `details/apps/katran.json`:

```text
status=ok
rejit_status=ok
program_count=1
failed=0
map_inline_applied=13
map_inline_matched=67
failure_artifacts=none
```

The hint-enabled katran apply count is restored to 13, and the kernel accepts the rewritten program.
