# Corpus Benchmark Prepare Pipeline Optimization

Date: 2026-03-29

## Scope

This note evaluates whether the corpus benchmark can overlap `prepare` and
`measure` work as a pipeline, based on these code paths:

- `runner/libs/corpus.py`
- `runner/src/batch_runner.cpp`
- `runner/src/kernel_runner.cpp`

I did not modify the benchmark implementation. The conclusion below is that
the default corpus benchmark should keep `prepare` and `measure` non-overlapped.

## Current Execution Model

The corpus batch plan is fully serialized today.

- `build_object_batch_plan_v2()` emits every baseline prepare, baseline
  compile, baseline run, REJIT compile, and REJIT run job with
  `execution="serial"` and hard-codes `scheduler.max_parallel_jobs = 1`
  ([runner/libs/corpus.py](../../../runner/libs/corpus.py#L1546),
  [runner/libs/corpus.py](../../../runner/libs/corpus.py#L1594),
  [runner/libs/corpus.py](../../../runner/libs/corpus.py#L1621),
  [runner/libs/corpus.py](../../../runner/libs/corpus.py#L1646),
  [runner/libs/corpus.py](../../../runner/libs/corpus.py#L1681),
  [runner/libs/corpus.py](../../../runner/libs/corpus.py#L1708),
  [runner/libs/corpus.py](../../../runner/libs/corpus.py#L1735)).

- `run_batch_cli()` keeps only one active prepared group at a time and erases
  the previous group when the next group begins
  ([runner/src/batch_runner.cpp](../../../runner/src/batch_runner.cpp#L1129),
  [runner/src/batch_runner.cpp](../../../runner/src/batch_runner.cpp#L1285)).

- `execute_parallel_chunk()` is only a blind worker pool over a contiguous
  chunk of jobs. It has no dependency graph, no producer/consumer ordering,
  and no back-pressure between `prepared_key` producers and `prepared_ref`
  consumers ([runner/src/batch_runner.cpp](../../../runner/src/batch_runner.cpp#L1080)).

## Can `prepare` And `measure` Overlap?

### 1. Overlap on the same prepared handle: no

This is not safe.

`run_prepared_kernel()` is not read-only on `prepared_kernel_state`.

- The prepared state owns the loaded `bpf_object`, program FDs, program info,
  REJIT state, and per-program fixture state
  ([runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L2558)).

- Runtime measurement mutates shared state before and during execution:
  - fixture initialization writes into object maps
    ([runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L2751),
    [runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L334));
  - runtime map I/O updates `input_map` and `result_map`
    ([runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L3141));
  - daemon REJIT and bytecode REJIT mutate the loaded program FD and cached
    `program_info/rejit_*` fields in-place
    ([runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L2797),
    [runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L2824),
    [runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L3097),
    [runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L3346));
  - attach-mode measurement temporarily attaches the program and enables BPF
    runtime stats
    ([runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L2945)).

Two concurrent jobs sharing one prepared handle would race on map contents,
REJIT state, and derived metadata even before considering benchmark noise.

### 2. Overlap on different prepared handles: technically possible, benchmark-unsafe

Preparing object N+1 while measuring object N is technically implementable,
but it is not safe for the default corpus benchmark.

Reasons:

- `prepare_kernel()` performs real kernel work: `bpf_object__open_file`,
  `bpf_object__load`, program discovery, and sometimes REJIT application
  ([runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L3416)).
  That is not a cheap bookkeeping stage; it allocates maps/programs and drives
  verifier/JIT activity while the measured job is active.

- The measurement side is explicitly timing-sensitive. The non-prepared
  `run_kernel()` path already contains a comment explaining that even an idle
  gap between stock and REJIT phases was enough to cause CPU-frequency
  regression, so daemon REJIT is forced before measurement
  ([runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L3714)).
  A background prepare thread would add more concurrent activity, not less.

- The measurement path records `rdtsc`-derived wall time and optionally perf
  counters around the measured callback
  ([runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L414),
  [runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L453),
  [runner/src/perf_counters.cpp](../../../runner/src/perf_counters.cpp#L82)).
  Concurrent prepare work can perturb:
  - CPU scheduling and runnable pressure
  - turbo/frequency behavior
  - LLC/I-cache/branch predictor state
  - memory bandwidth and allocator pressure
  - compile-side wall-clock samples for the next object

- I did not find any CPU-affinity or isolation logic in `runner/src`
  (`sched_setaffinity`, cpuset pinning, or equivalent). So even a
  “prepare on another thread” design has no isolation boundary in the current
  runner.

My conclusion: overlapping different prepared handles is feasible as a
throughput optimization, but it is not safe as the default measurement mode for
the corpus benchmark.

## Resource Conflict Risks

### BPF FD and kernel object residency

`prepared_kernel_store` retains `prepared_kernel_handle`s until group cleanup
([runner/src/batch_runner.cpp](../../../runner/src/batch_runner.cpp#L140)).
Each handle keeps the loaded `bpf_object`, program FDs, and map FDs alive
([runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L2569)).

Today the scheduler intentionally keeps one active prepared group at a time
([runner/src/batch_runner.cpp](../../../runner/src/batch_runner.cpp#L1129),
[runner/src/batch_runner.cpp](../../../runner/src/batch_runner.cpp#L1285)).
A pipeline would keep at least two groups resident: the group being measured
and the next group being prepared.

Risks:

- higher peak FD count
- higher peak kernel map/program memory
- larger memlock pressure
- larger chance of load failures on heavy objects

### Shared map and fixture state

Runtime execution rewrites per-object state:

- `result_map` is reset before each test run
  ([runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L381)).
- `input_map` / `result_map` are updated for map-mode jobs
  ([runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L3141)).
- fixture loading writes object maps
  ([runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L1278),
  [runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L2751)).

This makes same-handle overlap unsafe, and it also means pipelined lifetime
management must never accidentally allow two jobs to share one prepared state
concurrently.

### Instruction-image and I-cache effects

REJIT changes the program image in-place on the loaded program FD
([runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L2797),
[runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L2824),
[runner/src/kernel_runner.cpp](../../../runner/src/kernel_runner.cpp#L3346)).

Even when two jobs use different prepared handles, concurrent `bpf_object__load`
/ verifier / JIT work can perturb shared instruction and last-level cache state
for the measured job. That matters here because the benchmark reports runtime,
cycles, and wall time, not just functional success.

## Scheduler Constraints If We Tried Anyway

The current batch runner cannot express a prepare/measure pipeline by just
changing `execution` or `max_parallel_jobs`.

- If a producer (`prepared_key`) and consumer (`prepared_ref`) land in the same
  parallel chunk, the consumer may run first and fail because
  `execute_parallel_chunk()` does not wait for the producer
  ([runner/src/batch_runner.cpp](../../../runner/src/batch_runner.cpp#L1026),
  [runner/src/batch_runner.cpp](../../../runner/src/batch_runner.cpp#L1080)).

- `group_for_chunk()` rejects a parallel chunk that spans multiple
  `prepared_group` values
  ([runner/src/batch_runner.cpp](../../../runner/src/batch_runner.cpp#L1111)).

- Cleanup is currently based on a single `active_prepared_group`, not on
  reference counting or explicit DAG edges
  ([runner/src/batch_runner.cpp](../../../runner/src/batch_runner.cpp#L1129),
  [runner/src/batch_runner.cpp](../../../runner/src/batch_runner.cpp#L1322)).

So a real pipeline would require new scheduler semantics, not just a plan tweak.

## Safest Recommendation

Do not overlap `prepare` with any measured corpus runtime job in the default
benchmark path.

That means:

- keep `execution="serial"` for all measured corpus jobs
- keep `max_parallel_jobs = 1` for this benchmark path
- do not attempt to pipeline baseline prepare, REJIT prepare, or next-object
  prepare behind an active measurement

## What Would Be Safe Enough To Revisit Later

If shorter end-to-end wall-clock becomes important, the only defensible next
step is an opt-in throughput mode that is explicitly **not** the default corpus
benchmark:

- separate a non-measured “prepare cache” phase from the measured run
- do not report compile/runtime numbers from overlapped runs
- add explicit residency limits for prepared groups
- add dependency-aware scheduling instead of current chunk-level parallelism
- ideally run the prepare side on a different VM or otherwise isolated CPU set

That would be a different experimental mode, not a safe drop-in optimization
for the existing corpus benchmark.

## Decision

I did not implement prepare/measure pipelining.

The codebase can support more concurrency mechanically, but the current corpus
benchmark is performance-sensitive enough that overlapping prepare with measure
would change benchmark conditions and introduce avoidable noise and resource
pressure.
