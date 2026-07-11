# OTEL `native_tracer_entry` kop-only Regression Investigation

Date: 2026-05-07

## Scope

Task: investigate why `otelcol-ebpf-profiler/profiling` showed a `native_tracer_entry`
ratio of `2.486` under the kop-only pass set, making post-ReJIT about 2.5x slower
than baseline for this one BPF program.

Task context was read first from `docs/kernel-jit-optimization-plan.md`. The relevant
design constraints are:

- Do not filter or exclude programs from ReJIT.
- Do not add per-program or per-pass blacklist policy in benchmark config.
- Do not add framework-side summaries or derived metrics.
- Invoke benchmark reproductions only through `make <target>`.

## Artifact Used

Latest local artifact matching the dedicated kop-only list and containing the reported
`2.486` ratio:

`corpus/results/x86_kvm_corpus_20260507_025319_683029/`

Metadata:

- `started_at`: `2026-05-07T02:53:19.683029+00:00`
- `status`: `error` at suite level, but `otelcol-ebpf-profiler/profiling` has `status: ok`
- `samples`: `3`
- `workload_seconds`: `3.0`
- enabled passes:
  `wide_mem, rotate, cond_select, extract, endian_fusion, bulk_memory, prefetch`

Important mismatch with the prompt: this exact regression artifact does not include
`skb_load_bytes_spec`. Current default policy includes that pass, but the local
kop-only artifact that reproduces the `2.486` ratio does not. For this program,
`skb_load_bytes_spec` should be irrelevant anyway: it exits unchanged when there is no
packet context layout, and `native_tracer_entry` is `perf_event`.

## Source and Bytecode Location

Source:

- `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/native_stack_trace.ebpf.c:598`
  defines `SEC("perf_event/native_tracer_entry") int native_tracer_entry(...)`.
- The entry gets `pid/tid`, filters idle pid 0, reads time, then calls:
  `collect_trace((struct pt_regs *)&ctx->regs, TRACE_SAMPLING, pid, tid, ts, 0)`.
- `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h:735`
  defines `collect_trace()`.
- `collect_trace()` resets the per-CPU record, captures kernel/user state, chooses an
  unwinder, then tail-calls:
  `tail_call(ctx, unwinder)` at `tracemgmt.h:783`.
- `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h:539`
  defines `tail_call()`, which wraps `bpf_tail_call(ctx, &perf_progs, next)`.

Compiled object:

- `corpus/build/opentelemetry-ebpf-profiler/native_stack_trace.bpf.o`
- `llvm-objdump -h` shows section:
  `perf_event/native_tracer_entry`, size `0x2750`
- `llvm-objdump -t` shows global symbol:
  `native_tracer_entry`, section `perf_event/native_tracer_entry`, size `0x2750`
- `llvm-objdump -d --section=perf_event/native_tracer_entry` shows tail-call helper
  calls (`call 0xc`) at object instruction numbers `150` and `227`.

The object contains many `map_lookup_elem` helper calls (`call 0x1`) and immediate map
value dereferences. That shape matters because the prefetch pass structurally inserts
prefetches before the first dereference after `map_lookup_elem`.

## Raw Regression Evidence

From:

`corpus/results/x86_kvm_corpus_20260507_025319_683029/details/apps/otelcol-ebpf-profiler__profiling.json`

`native_tracer_entry` raw counters:

| phase | id | type | run_cnt_delta | run_time_ns_delta | bytes_jited | bytes_xlated |
| --- | ---: | --- | ---: | ---: | ---: | ---: |
| baseline | 55 | perf_event | 23839 | 69235032 | 3532 | 5496 |
| post_rejit | 55 | perf_event | 23885 | 172438793 | 3162 | 5136 |

Analysis-side check:

- baseline avg: `69235032 / 23839 = 2904.276 ns/run`
- post avg: `172438793 / 23885 = 7219.543 ns/run`
- ratio: `2.4858325`

The run counts are almost identical, so this is not caused by the post phase simply
executing many more perf events. The per-run BPF time increased sharply.

Tail-call accounting check:

All `perf_unwind_*` tail targets in this app JSON have `run_cnt_delta = 0` and
`run_time_ns_delta = 0` in both phases. That is expected for tail-called programs.
Their execution time is charged to the directly attached caller, `native_tracer_entry`.

## kop Pass Application on `native_tracer_entry`

From `.rejit_result.per_program[]` for program id `55` / `prog_name: native_tracer_e`:

- original instruction count: `1315`
- final instruction count: `1274`
- program type: `7` (`perf_event`)

| pass | sites_matched | sites_applied | sites_skipped | insns before | insns after | delta |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| wide_mem | 0 | 0 | 0 | 1315 | 1315 | 0 |
| rotate | 0 | 0 | 0 | 1315 | 1315 | 0 |
| cond_select | 2 | 2 | 0 | 1315 | 1320 | +5 |
| extract | 0 | 0 | 0 | 1320 | 1320 | 0 |
| endian_fusion | 0 | 0 | 0 | 1320 | 1320 | 0 |
| bulk_memory | 1 | 1 | 0 | 1320 | 1250 | -70 |
| prefetch | 12 | 12 | 0 | 1250 | 1274 | +24 |
| skb_load_bytes_spec | n/a | n/a | n/a | n/a | n/a | n/a |

Immediate exclusions:

- `wide_mem` is not the cause in this artifact: zero matched/applied sites.
- `rotate`, `extract`, and `endian_fusion` are not direct causes: zero sites.
- `skb_load_bytes_spec` was not in this artifact's pass list. If included in a later
  reproduction, it should be reported as unchanged for `perf_event`.

## Prior Nearby Runs

Two nearby May 6 artifacts are useful controls:

| artifact | pass list | native ratio | native pass behavior |
| --- | --- | ---: | --- |
| `x86_kvm_corpus_20260506_030539_506956` | rotate, cond_select, extract, endian_fusion, bulk_memory | `1.0557` | `cond_select` matched 2 but applied 0; `bulk_memory` matched 1 but applied 0; skipped because program had a tail-call helper |
| `x86_kvm_corpus_20260506_032056_815268` | rotate, cond_select, extract, endian_fusion, bulk_memory, prefetch | `1.0495` | same `cond_select`/`bulk_memory` skips; `prefetch` matched/applied 12 |
| `x86_kvm_corpus_20260507_025319_683029` | wide_mem, rotate, cond_select, extract, endian_fusion, bulk_memory, prefetch | `2.4858` | `cond_select` applied 2; `bulk_memory` applied 1; `prefetch` applied 12 |

This means the extreme regression coincides with `cond_select` and `bulk_memory`
starting to apply inside a tail-call-root program. It does not prove those two passes
alone caused the regression, but it makes the interaction important.

Current `kop_replacement_subprog_skip_reason()` only checks replacement/subprogram
boundaries. It does not contain the earlier "program with tail-call helper" guard that
appears in the May 6 skip reasons.

## Ranked Root-Cause Hypotheses

### 1. Most likely: `prefetch` over-insertion in a hot map-value path

Evidence:

- `prefetch` applied 12 sites, the largest site count of any active pass.
- Each prefetch insertion emits a packed kop call sequence, so 12 sites add 24 BPF
  instructions.
- `prefetch.rs` documents structural default behavior: if real per-site PMU data is
  missing, missing profile data does not block structural candidates.
- For map values, `prefetch` scans every `map_lookup_elem` and inserts before the first
  map-value dereference within `MAP_VALUE_LOOKAHEAD = 64`.
- `native_tracer_entry` is a perf-event hot path that repeatedly touches per-CPU record,
  metrics, PID metadata, and unwind dispatch state. Many of these map values are likely
  already hot or immediately consumed.

Why this can regress:

- Prefetching a value that is already hot adds call/setup overhead with no latency to hide.
- In a perf-event program, prefetch kfunc calls can increase register pressure and disrupt
  the already tight entry path.
- If inserted shortly before immediate dereference, the prefetch distance is too short to
  hide memory latency.

Counterpoint:

- A May 6 run with `prefetch` applied 12 but `cond_select`/`bulk_memory` skipped had only
  ratio `1.0495`, not `2.486`. So `prefetch` alone is suspicious but not proven as the
  sole cause.

### 2. High probability: `bulk_memory` rewrote per-CPU record reset/setup

Evidence:

- `bulk_memory` matched/applied 1 site and reduced bytecode by 70 instructions.
- `collect_trace()` starts by resetting/reinitializing the per-CPU trace record:
  `get_pristine_per_cpu_record()`, then writes trace fields.
- Earlier May 6 artifacts matched the same `bulk_memory` site but skipped it because the
  program had a tail-call helper.
- In the regression artifact, that site applies.

Why this can regress:

- The scalarized reset may have been compiler/JIT-friendly stores into a hot per-CPU
  record.
- Replacing it with bulk-memory kfunc calls can trade fewer BPF instructions for more
  expensive native call/setup behavior.
- The site is in the directly attached tail-call root, so any added cost is fully charged
  to `native_tracer_entry`.

### 3. Medium probability: `cond_select` changed predictable control flow

Evidence:

- `cond_select` matched/applied 2 sites and added 5 instructions.
- Earlier May 6 artifacts matched these same sites but skipped them because the program
  had a tail-call helper.

Why this can regress:

- Branchless select helps when a branch is unpredictable, but it can lose against a highly
  predictable branch.
- The pass lowers to a kfunc-shaped replacement before JIT lowering, which may add register
  shuffling or spills.

Counterpoint:

- Only two sites applied and the instruction delta is small. This is less likely than
  `prefetch` or `bulk_memory`, unless it interacts badly with register allocation.

### 4. Medium-low probability: register pressure / spills from combined kop calls

Evidence:

- Active transformations introduce packed kop call sequences:
  `cond_select`, `bulk_memory`, and `prefetch`.
- `native_tracer_entry` already has a large inlined body (`collect_trace`) and tail-call
  dispatch.

What is missing:

- The app JSON does not include native JIT disassembly or spill counts.
- `bytes_jited` decreased from `3532` to `3162`, so native size alone does not explain the
  slowdown. The regression could still be caused by worse instruction mix, call overhead,
  or spills, but that needs per-pass native disassembly.

### 5. Low probability: direct tail-call epilogue/inlining breakage

Evidence against:

- The object's explicit `bpf_tail_call` helper sites are present at instruction numbers
  around `150` and `227`.
- The active pass stats do not show a pass specifically targeting tail-call helpers.
- Tail target stats remain zero as expected; the time is correctly charged to the caller.

Why still worth checking:

- Earlier results skipped `cond_select`/`bulk_memory` specifically because the program had
  a tail-call helper. The guard removal/change may have exposed a verifier/JIT interaction
  in tail-call-root programs.

## Isolation Experiments

All runs must use `make vm-corpus`. Keep the app subset to OTEL only.

Use this baseline reproduction first:

```bash
BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
BPFREJIT_BENCH_PASSES="wide_mem,rotate,cond_select,extract,endian_fusion,bulk_memory,prefetch" \
SAMPLES=3 \
WORKLOAD_DURATION=5 \
KEEP_WORKDIRS=all \
make vm-corpus
```

If the prompt's pass list must be matched exactly, add `skb_load_bytes_spec` before
`bulk_memory`:

```bash
BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
BPFREJIT_BENCH_PASSES="wide_mem,rotate,cond_select,extract,endian_fusion,skb_load_bytes_spec,bulk_memory,prefetch" \
SAMPLES=3 \
WORKLOAD_DURATION=5 \
KEEP_WORKDIRS=all \
make vm-corpus
```

Single-pass isolation, highest priority first:

```bash
BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
BPFREJIT_BENCH_PASSES="prefetch" \
SAMPLES=3 \
WORKLOAD_DURATION=5 \
KEEP_WORKDIRS=all \
make vm-corpus
```

```bash
BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
BPFREJIT_BENCH_PASSES="bulk_memory" \
SAMPLES=3 \
WORKLOAD_DURATION=5 \
KEEP_WORKDIRS=all \
make vm-corpus
```

```bash
BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
BPFREJIT_BENCH_PASSES="cond_select" \
SAMPLES=3 \
WORKLOAD_DURATION=5 \
KEEP_WORKDIRS=all \
make vm-corpus
```

Zero-site controls:

```bash
BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
BPFREJIT_BENCH_PASSES="wide_mem" \
SAMPLES=3 \
WORKLOAD_DURATION=5 \
make vm-corpus
```

```bash
BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
BPFREJIT_BENCH_PASSES="rotate,extract,endian_fusion,skb_load_bytes_spec" \
SAMPLES=3 \
WORKLOAD_DURATION=5 \
make vm-corpus
```

Interaction controls:

```bash
BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
BPFREJIT_BENCH_PASSES="wide_mem,rotate,cond_select,extract,endian_fusion,bulk_memory" \
SAMPLES=3 \
WORKLOAD_DURATION=5 \
KEEP_WORKDIRS=all \
make vm-corpus
```

```bash
BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
BPFREJIT_BENCH_PASSES="wide_mem,rotate,cond_select,extract,endian_fusion,prefetch" \
SAMPLES=3 \
WORKLOAD_DURATION=5 \
KEEP_WORKDIRS=all \
make vm-corpus
```

```bash
BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
BPFREJIT_BENCH_PASSES="bulk_memory,prefetch" \
SAMPLES=3 \
WORKLOAD_DURATION=5 \
KEEP_WORKDIRS=all \
make vm-corpus
```

Evaluation should remain external/post-hoc:

- Read only raw `baseline.bpf` and `post_rejit.bpf` counters for `native_tracer_entry`.
- Confirm `sites_matched/sites_applied/sites_skipped` in `.rejit_result.per_program[]`.
- Do not add derived summaries to framework output.

## Last-Resort Policy-Compatible Fix Paths

Do not implement a blacklist for `native_tracer_entry`, OTEL, `perf_event`, or any
per-program/per-pass combination. That would violate the No ReJIT Filtering rule.

Allowed fix direction: change pass admission heuristics so the pass declines weak sites
based on bytecode/profile evidence, consistently for all programs.

Potential `prefetch` fixes:

- Require real per-site profile data for map-value prefetch in non-packet programs, or
  at least require observed cache misses before applying.
- Add a minimum useful prefetch distance: skip if the dereference is too close to the
  insertion point to hide latency.
- Cap prefetch insertions per subprogram/basic block so one hot entry path cannot receive
  many packed kop calls.
- Skip map-value prefetch when the first dereference is immediately after `map_lookup_elem`
  and there is no independent work between prefetch and use.
- If map metadata is available, treat per-CPU scratch/state maps conservatively because
  they are usually hot in the sampling path.

Potential `bulk_memory` fixes:

- Raise the minimum byte threshold or add a cost model that accounts for kfunc call/setup
  overhead, not only bytecode instruction count reduction.
- Skip bulk-memory replacement when the scalarized stores target stack/per-CPU scratch
  state in a perf-event entry path and the replacement would introduce packed kop calls.
- Preserve the previous conservative behavior for replacement sites in subprograms with
  tail-call helpers until native disassembly proves the transformation is profitable.

Potential `cond_select` fixes:

- Require branch profile evidence before replacing likely-predictable diamonds in hot
  perf-event programs.
- Add a static cost model that rejects sites where lowering requires extra register moves
  and the original branch is short.

## 精确诊断与推荐下一步动作

The `2.4858` ratio artifact shows that `native_tracer_entry` was changed only by:

- `cond_select`: 2 sites, `+5` instructions
- `bulk_memory`: 1 site, `-70` instructions
- `prefetch`: 12 sites, `+24` instructions

`wide_mem`, `rotate`, `extract`, and `endian_fusion` had zero sites. The reported
wide-memory chain-load hypothesis does not apply to this artifact.

Most likely root cause is over-aggressive `prefetch` in the hot map-value path, possibly
amplified by newly enabled `bulk_memory` and `cond_select` replacements in a tail-call-root
program. Existing data does not isolate a single pass conclusively because the closest
prior prefetch run had `prefetch` applied but `bulk_memory`/`cond_select` skipped and only
regressed by about 5%.

推荐下一步动作:

1. Re-run the exact OTEL-only 7-pass reproduction to confirm the `2.486` regression is
   repeatable on the current tree.
2. Run `prefetch` only. If it reproduces most of the slowdown, fix prefetch admission
   first.
3. Run `bulk_memory` only and `bulk_memory,prefetch`. If slowdown appears only in the
   combination, inspect native disassembly and call/register pressure around the
   per-CPU-record reset.
4. Run `cond_select` only as a lower-probability check.
5. Do not blacklist `native_tracer_entry`; implement a pass-level bytecode/profile
   heuristic instead.
