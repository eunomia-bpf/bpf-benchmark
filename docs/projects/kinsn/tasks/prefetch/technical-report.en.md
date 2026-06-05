# Kinsn Prefetch Technical Report

Last updated: 2026-06-05.

## Summary

The Kinsn prefetch path is functional. `bpfopt` can scan BPF bytecode,
insert a `KINSN_SIDECAR + KINSN_CALL` pair, and the kernel Kinsn JIT can
translate that pair into x86 `prefetch*` or ARM64 `prfm` native hints.

Prefetch is not ready to be enabled by default. The main reason is not an ABI
or JIT issue. Prefetch is an insertion optimization: it adds a cache hint before
an existing demand load, while the original load remains in the program. A
prefetch is useful only when all of these conditions hold:

```text
1. The future address is known early enough.
2. There is enough lead time between the prefetch and the demand load.
3. The control case has meaningful cache-miss pressure.
4. The treatment lowers cache misses.
5. The extra prefetch instructions and hint overhead do not erase the miss win.
```

Current profile-gated candidates:

| Candidate policy | Test case | Current result |
|---|---|---|
| MLOP / index-field | `prefetch_mlop_index_field` | T/C exec `0.945284`, cache miss ratio `0.019193`; strongest signal. |
| Horizon-2 future address | `prefetch_pipeline_horizon2_page_stride` | T/C exec `0.961195`, cache miss ratio `0.009627`. |
| Degree-1 future address | `prefetch_degree123_page_stride` | Degree 1 T/C exec `0.958149`; degree 2/3 do not beat degree 1. |
| Next-iteration pipeline | `prefetch_pipeline_page_stride` | T/C exec `0.968297`, cache miss ratio `0.006868`. |
| Spatial within page | `prefetch_spatial_page_footprint` | T/C exec `0.971461`, cache miss ratio `0.000460`, with instruction overhead. |
| Struct-field fixed offset | `prefetch_struct_field_fixed_offsets` | T/C exec `0.986178`; weak positive. |
| Mixed per-PC policy table | `prefetch_mixed_policy_table` | T/C exec `0.977369`; mainly proves per-PC prefetch/skip control. |
| Stream of strides, degree 1 | `prefetch_stream_of_strides_high_miss` with a single-site profile | T/C exec `0.990870`, cache miss ratio `0.882631`, cycles T/C `0.981531`. |

Current rejects: same-iteration prefetch, plain structural packet prefetch,
standalone stride-class prefetch, x86 `nta` as default, and stream-of-strides
degree-2/two-site placement.

## 1. Goal

Kinsn is a mechanism for expressing target-native instructions that normal BPF
bytecode cannot express. A normal BPF JIT translates BPF loads, ALU operations,
and branches into native instructions. It does not provide a general way for an
optimizer to insert an ARM64 `prfm` or an x86 `prefetcht0` hint into a BPF
program.

Kinsn provides that mechanism. `bpfopt` inserts a sidecar payload and a kfunc
call into BPF bytecode. When the kernel Kinsn JIT sees the kfunc, it reads the
sidecar payload and emits a target-native instruction instead of executing a
normal helper call.

The prefetch task answers four questions:

```text
RQ1. Can Kinsn express x86 and ARM64 software prefetch hints?
RQ2. Which BPF memory access patterns are worth prefetching?
RQ3. How can microbenchmarks prove that a policy is valid or invalid?
RQ4. If a policy is useful, how should a profile-gated prefetcher be built?
```

## 2. How Kinsn Prefetch Works

The runtime path is:

```text
BPF C program
  -> clang/LLVM builds a BPF object
  -> bpfopt --pass prefetch scans BPF bytecode
  -> the policy/profile chooses sites
  -> bpfopt inserts KINSN_SIDECAR + KINSN_CALL
  -> the kernel loads the BPF program
  -> the Kinsn JIT reads the sidecar payload
  -> the JIT emits x86 prefetch* or ARM64 prfm
  -> BPF_PROG_TEST_RUN or the corpus runner executes the optimized program
```

Supported native hints:

| Architecture | Supported hints |
|---|---|
| x86 | `prefetchnta`, `prefetcht0`, `prefetcht1`, `prefetcht2` |
| ARM64 | `prfm pldl1keep`, `prfm pldl1strm`, `prfm pldl2keep`, `prfm pldl2strm` |

Other Kinsn families are usually replacement optimizations. For example, a BPF
ALU sequence can be replaced by one native `rev` or `extr`. Prefetch is
different: the original demand load stays in the program, and the prefetch adds
an extra hint before that load. Therefore performance depends on timing, cache
misses, and microarchitecture behavior, not only on semantic equivalence.

## 3. Policies

A prefetch policy is a rule over memory access patterns:

```text
When this BPF memory access pattern appears,
prefetch this address at this earlier program point,
and skip these unsafe or unprofitable cases.
```

`horizon`, `degree`, and `hint variant` are parameters, not policies. They are
meaningful only when attached to a concrete access pattern.

| Policy | Pattern that may benefit | Why the control can be slow | Implementation/test method | Current status |
|---|---|---|---|---|
| Same-iteration current-address prefetch | No accepted positive pattern. The address is known only shortly before the same demand load. | The demand load can miss, but the prefetch has no time to hide that miss. | Insert a hint before the current demand load. | Rejected. |
| Packet structural prefetch | No accepted default positive pattern. A packet-derived pointer alone is insufficient. | Packet accesses are often hot, sequential, or already covered by local access behavior. | Scan packet-derived pointer loads. | Rejected by default; kept as skip-rule evidence. |
| Packet first-deref prefetch | A future packet-derived target address would need to be known early and be high-miss. | A dispersed final target can miss, but the current placement did not lower misses. | Depth-1 final deref candidates. | Current placement rejected. |
| Map-value same-iteration prefetch | No accepted positive pattern. | High-miss map-value access can still be too late to prefetch in the same iteration. | Track `bpf_map_lookup_elem` result pointers. | Rejected by default. |
| Future-address single stream | Loop iteration `i` can compute the address used by iteration `i+1` or `i+2`. | Demand loads repeatedly miss on a large working set. | Profile selects the future pointer register. | Candidate. |
| Stride-only future address | Only useful if the stride stream is also high-miss and has enough lead time. | Hardware prefetch or low miss pressure can make software prefetch useless. | Construct 64B, 256B, 4096B, and variable-stride streams. | Rejected as a standalone policy. |
| Spatial within page | A future page/region has several offsets that will be accessed. | Multiple offsets can miss unless the region is pulled in earlier. | Prefetch multiple future offsets. | Profile-gated candidate. |
| MLOP / index-field | Address is `base + index + field offset`, and the future field address is known early. | Indexed field loads are dispersed and miss-heavy. | Prefetch the future indexed field address. | Strongest candidate. |
| Struct-field fixed offset | The program scans records and fixed fields in future records are known early. | Fixed fields in future records can land on cold cache lines. | Prefetch fixed fields in the future record. | Weak candidate. |
| Mixed per-PC policy table | A program has both should-prefetch sites and should-skip sites. | A broad policy would prefetch hot or no-lead-time sites and add overhead. | Profile marks each PC as `prefetch` or `skip`. | Schema candidate. |
| Stream of strides | Multiple independent high-miss streams are interleaved and future addresses are known. | Each stream can miss, but multiple hints can add instruction and bandwidth pressure. | Profile opens one or two future stream sites. | Degree 1 weak candidate; degree 2 rejected. |
| Skip policy | Hot load, sequential stream, same-cacheline repeat, or deep dependent chain. | These are not prefetchable wins or are already hot. | Explicit skip/admission rules. | Kept. |

## 4. Microbenchmark Design

The existing repository micro suite was not designed for prefetch policies. The
prefetch task added synthetic-control microbenchmarks to isolate policy
mechanisms. These cases are not automatically extracted from real BPF programs.

A valid performance case must satisfy:

```text
1. The access pattern matches one policy question.
2. The control has meaningful cache-miss pressure, unless the case is an explicit negative control.
3. The future prefetch address is known early enough.
4. The treatment inserts the expected native prefetch.
5. Control and treatment differ only by the prefetch pass/profile.
```

Active cases:

| Policy | Test case | Source | Construction |
|---|---|---|---|
| MLOP / index-field | `prefetch_mlop_index_field` | `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c` | Builds an address from record index plus field offset and materializes a future field pointer. |
| Future-address single stream | `prefetch_pipeline_page_stride`, `prefetch_pipeline_horizon1/2/4_page_stride` | same file | Iteration `i` prefetches a pointer for a later iteration. |
| Degree parameter | `prefetch_degree123_page_stride`, `prefetch_pipeline_degree_page_stride` | same file | Materializes several future pointers and controls how many hints are emitted. |
| Spatial within page | `prefetch_spatial_page_footprint` | same file | Accesses several offsets in the same future page/region. |
| Struct-field fixed offset | `prefetch_struct_field_fixed_offsets` | same file | Accesses fixed fields in future records. |
| Mixed per-PC table | `prefetch_mixed_policy_table` | same file | Mixes hot, no-lead-time, and future-address sites; the profile opens only the future site. |
| Same-iteration current address | `prefetch_upper_page_stride`, `prefetch_map_page_stride` | same file | High-miss accesses with no useful lead time. |
| Packet first-deref | `prefetch_first_deref_page_stride`, `prefetch_future_first_deref_window` | same file | Page-spread target pointer shaped like a first-deref pattern. |
| Stream of strides | `prefetch_stream_of_strides_high_miss` | same file | Two page-spread future streams, tested with one-site and two-site profiles. |
| Stride-only | `prefetch_stride64/256/4096_page_stride` | same file | Changes only the stride class. |
| Skip rules | `prefetch_hot_l1_load`, `prefetch_sequential_scan`, `prefetch_indirect_two_stage` | `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.bpf.c` | Hot, sequential, or dependent-chain shapes used as negative controls. |

## 5. Measurement Method

Benchmarks are run through the Makefile/AWS wrapper path. The basic comparison is:

```text
control: no prefetch pass
treatment: bpfopt --pass prefetch with the selected profile JSON
runner: kernel runtime executes BPF_PROG_TEST_RUN and saves raw measurements
analysis: compute treatment/control ratios from raw samples
```

Representative command:

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.large \
  BENCH=prefetch_pipeline_horizon2_page_stride \
  RUNTIMES=kernel \
  SAMPLES=3 \
  WARMUPS=1 \
  INNER_REPEAT=10000 \
  PERF_COUNTERS=1 \
  PERF_SCOPE=full_repeat_raw \
  CPU=0
```

PMU-capable attribution uses AWS ARM64 `c7g.large` or `c7g.medium`. The default
ARM64 micro instance, `t4g.small`, does not expose the generic
`cache_misses/cache_references` counters needed for attribution.

Raw measurement fields:

| Field | Source | Unit/granularity |
|---|---|---|
| `exec_ns` | micro runner wall-clock measurement around one full repeated sample | ns per full sample |
| `cycles` | Linux `perf_event` generic cycles counter | cycles per full sample |
| `instructions` | Linux `perf_event` generic retired-instructions counter | retired instructions per full sample |
| `cache_references` | Linux generic cache reference counter | cache references per full sample |
| `cache_misses` | Linux generic cache miss counter | cache misses per full sample |

With `PERF_SCOPE=full_repeat_raw`, PMU counters are raw totals over the whole
`INNER_REPEAT` loop, not per-BPF-run averages.

Analysis formulas:

```text
mean_control_X = average(control samples' X)
mean_treatment_X = average(treatment samples' X)
X T/C = mean_treatment_X / mean_control_X
miss_count_ratio = mean_treatment_cache_misses / mean_control_cache_misses
miss_rate = mean_cache_misses / mean_cache_references
miss_rate_delta = treatment_miss_rate - control_miss_rate
```

## 6. Results

### 6.1 Positive Performance Cases

| Policy | Test case | T/C exec | cycles T/C | instructions T/C | miss_count_ratio | miss_rate_delta | Decision |
|---|---|---:|---:|---:|---:|---:|---|
| MLOP / index-field | `prefetch_mlop_index_field` | `0.945284` | `0.970091` | `0.957288` | `0.019193` | `-0.051594` | Keep; strongest signal. |
| Future-address horizon2 | `prefetch_pipeline_horizon2_page_stride` | `0.961195` | `0.997167` | `0.970903` | `0.009627` | `-0.037009` | Keep; current default horizon. |
| Future-address degree1 | `prefetch_degree123_page_stride` | `0.958149` | `1.000250` | `0.969921` | `0.006768` | `-0.035913` | Keep degree1; not degree>1. |
| Next-iteration future address | `prefetch_pipeline_page_stride` | `0.968297` | `0.935296` | `0.970491` | `0.006868` | `-0.040931` | Keep, but horizon2 is more stable. |
| Spatial within page | `prefetch_spatial_page_footprint` | `0.971461` | `0.957085` | `1.037390` | `0.000460` | `-0.046003` | Keep only with profile gate. |
| Struct-field fixed offset | `prefetch_struct_field_fixed_offsets` | `0.986178` | `0.970069` | `1.022834` | `0.150586` | `-0.004231` | Weak keep. |
| Mixed per-PC table | `prefetch_mixed_policy_table` | `0.977369` | `0.983388` | `1.025640` | `0.010690` | `-0.026663` | Keep schema. |
| Stream of strides degree1 | `prefetch_stream_of_strides_high_miss` | `0.990870` | `0.981531` | `0.993567` | `0.882631` | `-0.004916` | Weak keep; degree1 only. |

Positive cases share the same structure: future address is known early, control
miss pressure is high, treatment inserts the intended `prfm`, miss count/rate
drops, and instruction overhead does not erase the miss reduction.

### 6.2 Diagnostic Rejects

| Placement / parameter | Test case | T/C exec | cycles T/C | instructions T/C | miss_count_ratio | miss_rate_delta | Reason | Decision |
|---|---|---:|---:|---:|---:|---:|---|---|
| Same-iteration current address | `prefetch_upper_page_stride` | `0.996947` | `0.993570` | `1.000640` | `0.994163` | `-0.000419` | High miss, but no lead time; misses barely fall. | Reject. |
| Map-value same iteration | `prefetch_map_page_stride` | `0.994264` | `0.986915` | `1.008210` | `0.964509` | `-0.000858` | Small miss drop, instruction overhead. | Reject default. |
| Packet first-deref current placement | `prefetch_first_deref_page_stride` | `1.000208` | `1.024748` | `1.024585` | `0.999198` | `-0.000334` | JIT emits `prfm`, but demand misses do not fall. | Reject placement. |
| Packet future-first diagnostic | `prefetch_future_first_deref_window` | `0.997711` | `0.994716` | `0.999671` | `1.003498` | `0.000031` | Timing signal has no cache-miss evidence. | Not policy evidence. |
| Stream degree2 / two-site | `prefetch_stream_of_strides_high_miss` | `1.002240` | `1.005900` | `1.014335` | `0.834258` | `-0.006383` | Misses fall, but two hints add enough overhead to lose. | Reject degree2 placement. |
| Standalone stride64 | `prefetch_stride64_page_stride` | `0.998684` | `0.998030` | `1.002690` | `0.759427` | `-0.000012` | Control miss pressure too low. | Reject standalone stride. |
| Standalone stride256 | `prefetch_stride256_page_stride` | `0.999031` | `0.997228` | `1.002940` | `0.820329` | `-0.000155` | Miss pressure not enough, instructions rise. | Reject standalone stride. |
| Standalone stride4096 | `prefetch_stride4096_page_stride` | `1.000230` | `1.000520` | `1.004340` | `0.984768` | `-0.000014` | Misses barely fall, instructions rise. | Reject standalone stride. |

Reject reasons fall into three buckets:

```text
1. No lead time: same-iteration and current first-deref placements.
2. Not enough miss pressure: standalone stride cases.
3. Misses fall but overhead wins: stream-of-strides degree2/two-site placement.
```

## 7. Current Status and Next Steps

Prefetch task status:

```text
1. Kinsn PREFETCH/PRFM ABI and JIT emit: done.
2. Literature review and policy extraction: done.
3. Synthetic-control micro cases: current policy set covered.
4. Correctness and emit smoke: done.
5. Paired runtime attribution: done.
6. PMU-capable attribution: done for the main candidate/reject cases.
7. Documentation cleanup: current round done.
8. Reworked missing performance cases: first-deref, future-first diagnostic, and stream degree1 done.
9. Integrated profile-gated prefetcher: not started.
10. Real corpus evidence-backed profile generation: not started.
```

Current conclusion:

```text
prefetch = research-only / profile-gated candidate
default policy = disabled
```

Next concrete step is commit/publish cleanup for the current prefetch batch:

```text
1. Commit the profile-gated prefetch selector support.
2. Commit the prefetch microbenchmark/config additions.
3. Commit the self-contained documents and compact experiment artifacts.
```

Integrated prefetcher work should start only after the current micro evidence is
accepted as complete enough for the policy set.

## 8. Artifact Index

Primary documents:

| Document | Purpose |
|---|---|
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md` | Task entry point. |
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/technical-report.md` | Chinese technical report. |
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/technical-report.en.md` | English technical report. |
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md` | Policy taxonomy and status. |
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-design.md` | Microbenchmark construction. |
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md` | Results appendix and artifact links. |

Experiment records:

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-05-prefetch-reworked-performance-cases
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments
```
