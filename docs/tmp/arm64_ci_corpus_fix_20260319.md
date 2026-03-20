# ARM64 CI Corpus Exec-Time Fix

Date: 2026-03-19

## Root Cause

`corpus/run_real_world_exec_time.py` hardcoded `--io-mode packet` for every program and skipped the `llvmbpf` run whenever the kernel run failed first. On the ARM64 `libbpf-bootstrap` CI set, that caused 23 of 24 programs to fail before measurement with:

- `io-mode packet requires an XDP or skb packet context`

The affected sections were primarily non-packet programs (`tracepoint`, `kprobe`-family, `perf_event`, `lsm`, `iter`, `socket_filter`, `fentry/fexit`).

## Changes

1. `corpus/run_real_world_code_size.py`
   - Persist `prog_type`, `expected_attach_type`, `prog_type_name`, and `attach_type_name` into the code-size JSON so exec-time runs can make per-program decisions directly.

2. `corpus/run_real_world_exec_time.py`
   - Add per-program exec I/O mode selection:
     - `packet` for XDP / skb-backed program types
     - `context` otherwise
   - Materialize a zero-filled context buffer (`--context-size`, default `256`) for `io-mode=context`.
   - Re-query `micro_exec list-programs` when the input JSON does not already contain program-type metadata, so older code-size outputs still work.
   - Attempt kernel and `llvmbpf` exec runs independently instead of suppressing `llvmbpf` when kernel test-run is unsupported.
   - Reclassify kernel `ENOTSUP`/unsupported `BPF_PROG_TEST_RUN` cases as `skipped` instead of hard `error`.
   - Add `any_runtime_exec_ok` and skip breakdowns to the JSON/report.
   - Preserve signal-based failures explicitly, e.g. `terminated by signal 11`.

3. `.github/workflows/arm64-benchmark.yml`
   - Run corpus exec-time with `--context-size 256`.
   - Publish the new coverage counts in the GitHub step summary:
     - any-runtime exec coverage
     - paired coverage
     - kernel ok/skipped
     - llvmbpf ok/error

## Local Validation

Commands:

```bash
python3 corpus/run_real_world_code_size.py \
  --repo libbpf-bootstrap \
  --runtime llvmbpf \
  --runtime kernel \
  --max-sources 20 \
  --output /tmp/real_world_code_size_local_v2.json \
  --report /tmp/real_world_code_size_local_v2.md

python3 corpus/run_real_world_exec_time.py \
  --input /tmp/real_world_code_size_local_v2.json \
  --output /tmp/real_world_exec_time_local_v2.json \
  --report /tmp/real_world_exec_time_local_v2.md \
  --iterations 1 \
  --repeat 1 \
  --context-size 256
```

Result summary on the local host:

- `paired_from_code_size=23`
- `kernel_test_run_ok=3`
- `llvmbpf_run_ok=20`
- `any_runtime_exec_ok=22`
- `paired_exec_ok=1`

Observed skip/failure buckets:

- Kernel skipped unsupported:
  - `tracepoint`: 7
  - `kprobe`: 10
  - `perf_event`: 1
  - `socket_filter`: 1
- Kernel hard failure:
  - `task_iter`: `bpf_prog_test_run_opts failed: Bad address`
- `llvmbpf` hard failures:
  - 3 cases, all `terminated by signal 11`

The important behavioral change is coverage: the old flow effectively collapsed to the kernel packet-mode result set, while the patched flow preserved exec data for 22 of 23 locally testable programs by not suppressing `llvmbpf`.

## ARM64 Expectation

Expected CI improvement:

- eliminate the blanket packet-context failure mode for non-packet programs
- raise `any_runtime_exec_ok` above 50% of the paired code-size set
- keep paired ratios limited to the subset where both runtimes can actually execute

## CI Follow-Up

Pending after push:

- branch push
- workflow dispatch
- run URL
- final ARM64 summary
