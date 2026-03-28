# compile_only and prepared-state fix (2026-03-28)

## Scope

- Updated `corpus/config/macro_corpus.yaml`.
- Investigated the prepared-state failures in `runner/corpus/results/vm_corpus_20260328_154829/metadata.json`.
- Fixed prepared-state error propagation in `runner/src/batch_runner.cpp`.

## Part 1: compile_only cleanup

### What changed

- The manifest originally had 66 explicit `test_method: compile_only` entries.
- After this change, 49 entries were converted to real runtime methods, and 17 explicit `compile_only` entries remain.
- The remaining 17 are now documented in YAML with comments explaining why they are still compile-only instead of being silent default skips.

### Converted entries

- `syscall` entries were switched to `bpf_prog_test_run`.
- Mixed selftest objects such as `verifier_arena` and `verifier_bits_iter` now default to `bpf_prog_test_run`, so the syscall subprograms no longer hide behind object-level compile-only defaults.
- `scx_*` object-level defaults now use `attach_trigger` plus an object-level `attach_group=<init-program>`, so callback-style `struct_ops` programs go through a real attach path instead of inheriting compile-only.
- Mixed XDP/TC objects such as `loxilb` and `xdp-tutorial` now default to `bpf_prog_test_run` with packet input, so the helper-like entry points either measure or fail with a direct runtime error.
- Object-only entries with `programs: []` no longer carry explicit `test_method: compile_only`; they now carry comments explaining that only object compile is recorded until those objects are expanded into per-program targets.

### Remaining compile_only entries

The 17 remaining explicit `compile_only` entries fall into three buckets:

- `struct_ops` TCP congestion-control suites and dummy struct_ops fixtures.
  Reason: they still need a stable attach anchor plus a reproducible trigger workload in the corpus runner.
- `ext` / `freplace` programs.
  Reason: they require an external replacement target that the generic corpus runner does not provision yet.
- `tetragon/bpf_execve_map_update.bpf.o` (`seccomp` / `unspec`).
  Reason: the current runner has no generic libbpf attach path or `BPF_PROG_TEST_RUN` path for this program class.

These retained entries are now commented in YAML so they are explicit limitations, not silent skips.

## Part 2: prepared-state investigation

### Files inspected

- `runner/src/batch_runner.cpp`
- `runner/src/kernel_runner.cpp`
- `corpus/modes.py`
- `runner/corpus/results/vm_corpus_20260328_154829/metadata.json`
- `runner/corpus/results/vm_corpus_20260328_154829/details/result.json`
- `runner/corpus/results/vm_corpus_20260328_154829/details/progress.json`

### Findings

#### 1. The `prepared_ref` values were correct

`build_object_batch_plan_v2()` assigns:

- object-level prepare jobs: `prepared_key = object-XXXX:{baseline,rejit}:prepared`
- program-level compile/run jobs: `prepared_ref = object-XXXX:{baseline,rejit}:prepared`

That mapping is correct.

#### 2. Why so many different objects reported `object-0001:*:prepared`

This looked wrong at first, but it is explained by guest-side chunking:

- `run_guest_batch_mode()` runs objects in chunks of `GUEST_BATCH_TARGETS_PER_CHUNK = 1`.
- Each call to `run_objects_locally_batch()` builds a fresh single-object batch plan.
- Inside each fresh batch plan, numbering starts from `object-0001`.

So `object-0001:baseline:prepared` in the aggregated metadata does not mean multiple different objects shared one ref. It means "the first object in that single-object guest chunk."

#### 3. The compile job did not generate prepared state in the failing cases

For affected objects, `object_records` in `details/result.json` show object-level prepare failures such as:

- `bpf_object__load failed: Invalid argument`

When that happens:

- `prepare_kernel()` throws
- `batch_runner` marks the object-level compile job as failed
- no prepared handle is inserted into the in-memory prepared store

So the prepare stage genuinely did not produce prepared state.

#### 4. The downstream jobs then failed with a secondary error

Before the fix, dependent program jobs still ran and looked up `prepared_ref` in the store. Because the object-level prepare had already failed, the lookup returned nothing and every dependent job failed with:

- `missing prepared kernel state for ref: object-0001:baseline:prepared`
- `missing prepared kernel state for ref: object-0001:rejit:prepared`

That was a secondary orchestration error message, not the real root cause.

### Root cause

The bug was not "wrong ref wiring." The bug was:

- object-level prepare failure was not remembered in the prepared-state store
- dependent jobs only saw "missing prepared state" instead of the original prepare failure

So the prepared-state lifecycle was lossy on the failure path.

## Current-tree fix status

### `runner/src/batch_runner.cpp`

The current tree already keeps both:

- successful prepared handles
- failed prepare errors keyed by the same `prepared_key`

Behavior in the current tree:

- if a `prepared_key` job succeeds, the handle is stored as before
- if a `prepared_key` job fails, the prepare error is stored under that key
- if a later `prepared_ref` job finds no handle but finds a stored prepare error, it now fails with the original cause, for example:
  `prepared kernel state for ref object-0001:baseline:prepared is unavailable because prepare failed: bpf_object__load failed: Invalid argument`

This preserves zero-silent-failure behavior:

- nothing is skipped
- nothing is downgraded to success
- the failure reason is now the real upstream cause instead of a misleading secondary symptom

No additional worktree diff was required in `runner/src/batch_runner.cpp` because the current `HEAD` already contains this propagation logic. The problematic `vm_corpus_20260328_154829` artifact reflects an older run where downstream jobs still surfaced the secondary `missing prepared state` symptom.

## Verification

Ran:

- `python3 -m py_compile corpus/modes.py`
- `make runner`

Both completed successfully.

## Outcome

- The manifest now routes many previously compile-only entries through real runtime paths.
- The remaining compile-only entries are explicit, documented unsupported cases.
- Prepared-state failures now preserve the actual prepare error instead of collapsing into `missing prepared state`.

## Follow-up

To remove the final 17 compile-only entries, the next missing harness work is:

- stable attach harnesses for `struct_ops` TCP congestion-control selftests
- replacement-target provisioning for `freplace` / `ext`
- a real seccomp runtime path for `tetragon/bpf_execve_map_update.bpf.o`
