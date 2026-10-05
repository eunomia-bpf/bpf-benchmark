# Remove ReJIT Skip Logic Summary

Date: 2026-04-25

## Scope

This change removed repository logic that proactively skipped or excluded live ReJIT for specific BPF programs, especially `struct_ops` and Tracee's `syscall__init_module`.

Changed files:

- `runner/libs/app_runners/scx.py`
- `e2e/cases/scx/case.py`
- `corpus/driver.py`
- `runner/libs/app_runners/tracee.py`
- `corpus/config/benchmark_config.yaml`
- `daemon/src/elf_parser.rs`

## Code Changes

### 1. Removed `scx` live-ReJIT skip logic

- Deleted `ScxRunner.live_rejit_skip_reason()`.
- Removed the `before_rejit` abort hook from `e2e/cases/scx/case.py`.
- Removed the `before_rejit` abort hook from `corpus/driver.py`.

Result:

- `scx` is no longer proactively marked `skipped` before ReJIT.
- ReJIT now proceeds and real failures surface as actual runtime errors.

### 2. Removed Tracee program-name exclusion

- Deleted the `syscall__init_module` exclusion list in `runner/libs/app_runners/tracee.py`.
- Deleted the `TraceeRunner.live_rejit_programs()` override that filtered excluded program names.

Result:

- Tracee now uses the default live-program set instead of silently dropping `syscall__init_module`.

### 3. Removed `struct_ops` pass exclusions from corpus config

- Deleted the `policy.rules` entry in `corpus/config/benchmark_config.yaml` that disabled:
  - `map_inline`
  - `dce`
  for `prog_type: struct_ops`.

Result:

- `struct_ops` programs now receive the same pass set as other programs.

### 4. Fixed daemon `struct_ops` program-type mapping

- In `daemon/src/elf_parser.rs`, changed `struct_ops`/`struct_ops/*` section mapping from `BPF_PROG_TYPE_TRACING` to `BPF_PROG_TYPE_STRUCT_OPS`.
- Added a unit test covering both:
  - `struct_ops`
  - `struct_ops/test_sched`

Result:

- The daemon now reports the correct BPF program type for `struct_ops`.

## Source Audit

Targeted source checks after the change confirmed:

- no remaining `live_rejit_skip_reason()` in source
- no remaining `syscall__init_module` ReJIT exclusion in source
- no remaining `struct_ops` pass-disable rule in benchmark config
- `daemon/src/*.rs` has no remaining `struct_ops` skip/exclude special-case logic; only the corrected type mapping remains in `elf_parser.rs`

Notes:

- Generic lifecycle support for `LifecycleAbort` still exists in `runner/libs/case_common.py`, but the concrete ReJIT skip callers in `e2e` and `corpus` were removed.
- Remaining `skip_reasons` under `daemon/src/` are pass-internal diagnostics and are not per-program ReJIT exclusion lists.

## Local Verification

### Python syntax check

Command:

```bash
python -m py_compile \
  runner/libs/app_runners/scx.py \
  runner/libs/app_runners/tracee.py \
  e2e/cases/scx/case.py \
  corpus/driver.py
```

Result: passed

### Daemon unit test

Command:

```bash
cargo test --manifest-path daemon/Cargo.toml infer_struct_ops_section_type_correctly
```

Result: passed

## E2E Verification

Command:

```bash
make vm-e2e
```

Final suite result:

- all 6 e2e cases were launched and executed
- `make vm-e2e` exited with code `1`
- the only failing case was `scx`
- suite output ended with `e2e: FAILED cases: scx`

Case results:

| Case | Run dir | Status | Notes |
| --- | --- | --- | --- |
| `tracee` | `e2e/results/tracee_20260425_182618_554918` | `ok` | completed |
| `tetragon` | `e2e/results/tetragon_20260425_183159_083110` | `ok` | completed |
| `bpftrace` | `e2e/results/bpftrace_20260425_183501_119379` | `ok` | completed |
| `scx` | `e2e/results/scx_20260425_183748_202347` | `error` | not skipped; failed during real execution |
| `bcc` | `e2e/results/bcc_20260425_183826_399737` | `ok` | completed |
| `katran` | `e2e/results/katran_20260425_184252_813236` | `ok` | completed |

### `scx` failure detail

`scx` was not aborted by a `before_rejit` hook and was not marked `skipped`.

Observed error:

```text
scx case could not run: post_rejit/hackbench: scx runner did not expose any live scheduler programs for BPF stats sampling
```

This is a real runtime/problem-state failure after the case entered the post-ReJIT path, not a proactive skip or exclusion.

## Conclusion

The repository no longer contains the targeted repo-level logic that proactively excludes or skips live ReJIT for:

- `struct_ops` programs in `scx`
- Tracee's `syscall__init_module`
- corpus `struct_ops` pass selection

The daemon now classifies `struct_ops` ELF sections as `BPF_PROG_TYPE_STRUCT_OPS`.

`make vm-e2e` confirms that all 6 cases now run, and `scx` fails because of a real technical/runtime issue instead of being intentionally skipped.
