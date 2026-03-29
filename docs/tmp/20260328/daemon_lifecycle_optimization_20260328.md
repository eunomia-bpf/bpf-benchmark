# Daemon Lifecycle And Prepare Parallelism Review

Date: 2026-03-28

## Executive Summary

- Corpus benchmark does **not** restart `bpfrejit-daemon serve` for each object. In both local batch mode and VM guest batch mode, the daemon is started once per benchmark session and its socket is reused across objects.
- E2E **did** have unnecessary daemon churn: `scan_programs()` and `apply_daemon_rejit()` each started and stopped their own daemon session. This was a real bug. It is now fixed so each E2E case uses one daemon session for both scan and apply.
- Micro benchmark already uses session-scoped daemon management. The VM entrypoints start one daemon and pass `--daemon-socket` to the whole `micro/driver.py` run.
- Corpus object prepare is currently **serial**, not parallel. There is no cross-object preload or pipeline. This is deliberate in the current code path, although the batch runner has some parallel primitives.
- I did **not** enable corpus cross-object prepare parallelism by default. That would change benchmark semantics by overlapping compile/load timing with other compile/load work.

## 1. Current Daemon Lifecycle

### Corpus guest mode

`corpus/modes.py` starts one daemon before processing the selected objects and stops it once after the whole guest session finishes:

- `corpus/modes.py:266-270`
- `corpus/modes.py:324-326`

That socket is then passed into each `run_objects_locally_batch(...)` call:

- `corpus/modes.py:273-286`

Important nuance: guest mode currently chunks with `GUEST_BATCH_TARGETS_PER_CHUNK = 1`, so it still invokes the batch runner once per object, but **the daemon is reused**:

- `corpus/modes.py:86`
- `corpus/modes.py:273-286`

### Corpus local batch helper

`runner/libs/corpus.py::run_objects_locally_batch()` also uses a session-scoped daemon. If no socket is supplied, it starts one daemon once, reuses it for policy site scanning and the actual benchmark batch, then stops it at the end:

- `runner/libs/corpus.py:1922-1926`
- `runner/libs/corpus.py:1945-1967`
- `runner/libs/corpus.py:1968-1970`

So the corpus answer is:

- Per-object daemon restart: **No**
- Per-benchmark-session daemon reuse: **Yes**

### E2E case lifecycle

Before this fix, `run_case_lifecycle()` called `scan_programs()` and `apply_daemon_rejit()` back-to-back, and each helper started/stopped its own daemon internally. The underlying start/stop helpers are:

- `runner/libs/rejit.py:736-749`

After the fix, `run_case_lifecycle()` explicitly starts one daemon session, passes the socket into both scan and apply, then stops it once:

- `e2e/case_common.py:365-387`

The REJIT helpers now accept an existing socket path and reuse it instead of always spawning a fresh daemon:

- `runner/libs/rejit.py:526-581`
- `runner/libs/rejit.py:1002-1054`

### Micro benchmark

`micro/driver.py` does not manage daemon lifetime itself. It expects an already-running daemon socket:

- `micro/driver.py:75-82`

The VM entrypoints in `runner/Makefile` start one daemon, keep it alive for the whole `micro/driver.py` invocation, and pass `--daemon-socket` to all benchmark jobs:

- `runner/Makefile:299-317`

Inside the batch plan, micro jobs carry the same socket through prepare and run:

- `micro/driver.py:150-195`
- `micro/driver.py:520-593`

So the micro answer is:

- Session-level daemon startup once: **Yes**
- Per-benchmark/object daemon restart inside the driver: **No**

## 2. Current Object Prepare: Serial Or Parallel?

### Corpus plan generation

Corpus currently hard-codes all benchmark jobs as `execution="serial"` and fixes `scheduler.max_parallel_jobs = 1`:

- `runner/libs/corpus.py:1594-1615`
- `runner/libs/corpus.py:1621-1669`
- `runner/libs/corpus.py:1681-1733`
- `runner/libs/corpus.py:1735-1740`

That means:

- Baseline object/group prepare is serial.
- Baseline compile/run reuse of prepared state is serial.
- ReJIT compile/run is serial.
- There is no overlap where “object N is measuring while object N+1 is preparing”.

### Batch runner capabilities

The batch runner *can* execute parallel chunks:

- `runner/src/batch_runner.cpp:1080-1108`

It even defaults omitted `execution` to `"parallel"` for `compile_only=true` jobs:

- `runner/src/batch_runner.cpp:605-608`

Micro takes advantage of that by creating parallel prepare windows:

- `micro/driver.py:168-176`
- `micro/driver.py:520-593`

Corpus does not.

### Prepared-group constraint

A direct corpus flip to parallel prepare is not trivial because the batch runner currently assumes a parallel chunk has at most one `prepared_group`:

- `runner/src/batch_runner.cpp:1111-1126`
- `runner/src/batch_runner.cpp:1129-1140`

That fits micro’s “window group” design, but corpus assigns distinct prepared groups per baseline group and per REJIT compile group:

- `runner/libs/corpus.py:1586-1590`
- `runner/libs/corpus.py:1675-1677`

### Kernel-side prepare behavior

`prepare_kernel()` itself is synchronous:

- materialize input bytes
- `bpf_object__open_file`
- `bpf_object__load`
- enumerate loaded programs
- optionally apply daemon REJIT for compile-only REJIT jobs

Code:

- `runner/src/kernel_runner.cpp:3416-3489`
- `runner/src/kernel_runner.cpp:3505-3575`

Prepared kernel state is then reused for later compile/run jobs:

- `runner/src/kernel_runner.cpp:3588-3604`

There is no background thread or pipeline that preloads the next object while the current object is being measured.

### Existing object-scope optimization

There is already one useful optimization inside a single loaded object: if a prepared object contains multiple programs and daemon REJIT is requested, the code can apply daemon REJIT across the loaded object in object scope:

- `runner/src/kernel_runner.cpp:2616-2623`
- `runner/src/kernel_runner.cpp:2710-2724`

That is intra-object reuse, not cross-object parallelism.

## 3. Unnecessary Repeated Start/Stop

### Confirmed unnecessary churn

E2E had unnecessary repeated daemon lifecycle work:

- One daemon for scan
- A second daemon for apply

This has now been removed.

### Not actually a problem

Corpus does **not** restart daemon per object.

### Related but separate overhead

Guest corpus mode still has per-object orchestration overhead because `GUEST_BATCH_TARGETS_PER_CHUNK = 1`, so it builds and runs one batch plan per object:

- `corpus/modes.py:86`
- `corpus/modes.py:273-286`

This is not a daemon lifecycle bug, but it is avoidable session wall-clock overhead.

## 4. Concrete Optimization Recommendations

### Applied in this change

1. Reuse a single daemon session for each E2E case.
   - `runner/libs/rejit.py`
   - `e2e/case_common.py`

Implementation details:

- `scan_programs()` can now reuse a supplied daemon socket: `runner/libs/rejit.py:526-581`
- `apply_daemon_rejit()` can now reuse a supplied daemon socket: `runner/libs/rejit.py:1002-1054`
- `run_case_lifecycle()` now starts one daemon and passes it to both steps: `e2e/case_common.py:365-387`

### Safe next optimization for corpus

2. Batch more than one object per guest chunk without introducing measurement parallelism.
   - Primary change site: `corpus/modes.py:86`
   - Supporting progress/report logic: `corpus/modes.py:273-323`

This would reduce:

- repeated Python batch-plan construction
- repeated `run_batch_runner(...)` process startup
- repeated per-chunk policy resolution/scanning overhead

while keeping actual benchmark jobs serial inside a single batch.

### Optional throughput-mode optimization, not recommended as default

3. Add an explicit non-authoritative throughput mode for parallel prepare.
   - Plan generation: `runner/libs/corpus.py:1546-1740`
   - Batch runner prepared-group semantics: `runner/src/batch_runner.cpp:1111-1140`

To do this correctly, corpus would need:

- a separate prepare phase/window structure, not the current inline prepare/run ordering
- explicit policy for multiple simultaneously-live `prepared_group` values
- a clear CLI/config flag marking the mode as non-authoritative

I do **not** recommend enabling this for default corpus benchmark runs because it would overlap timing-sensitive compile/load work across objects and make `compile_ns/object_load_ns/rejit_apply_ns` less comparable.

## 5. Expected Speedup

These are code-structure estimates, not measured numbers.

### E2E daemon reuse

- Savings: one daemon startup + one daemon shutdown per E2E case
- Expected effect: modest wall-clock improvement, usually low single-digit percent unless the case workload itself is very short

Why modest:

- The case still does the same scan and optimize RPCs.
- The improvement is limited to removing one extra `serve` lifecycle.

### Corpus guest chunking > 1

- Savings: fewer `run_objects_locally_batch()` and `run_batch_runner()` invocations
- Expected effect: meaningful session wall-clock reduction for large corpora, without changing serial job semantics

The gain should scale roughly with how much time is currently spent outside the per-job kernel measurements.

### Corpus cross-object parallel prepare

- Potential effect: larger end-to-end wall-clock reduction if prepare dominates
- Cost: benchmark semantics become noisier because compile/load timing now competes with other prepare jobs

For authoritative results, this tradeoff is not worth taking by default.

## Validation

Executed:

```bash
python3 -m py_compile runner/libs/rejit.py e2e/case_common.py tests/python/test_rejit.py tests/python/test_case_common.py
pytest -q tests/python/test_rejit.py tests/python/test_case_common.py tests/python/test_corpus_modes.py tests/python/test_micro_driver.py
```

Result:

- `28 passed in 1.53s`

Relevant new regression test:

- `tests/python/test_case_common.py:12-131`
