# Wave 1 silent fallback removal

Date: 2026-04-21 America/Vancouver

## Scope

Removed the silent fallback paths called out in `docs/tmp/code-review-20260420/review.md` section 2, plus the related section 6 provenance/masking issues touched by the same codepaths.

### Fixes

- `runner/libs/rejit.py`
  - explicit `BPFREJIT_DAEMON_TMPDIR` now fails when unusable; implicit daemon temp roots are validated before use.
  - daemon pass-site counters are schema-checked for known passes instead of silently coercing malformed values to `0`.
  - benchmark pass selection now requires a valid active benchmark profile/config unless an explicit env override is present; the hardcoded old 3-pass default fallback is gone.
  - daemon `passes` payloads are now rejected when they contain malformed entries, unknown pass names, or invalid site counts.
  - apply results now require explicit `summary.applied`, `summary.program_changed`, and `summary.total_sites_applied`; exit-code-0 daemon replies no longer imply success by default.
- `daemon/src/server.rs`
  - map invalidation re-optimization failures now fail the daemon instead of printing to stderr and returning a clean status.
  - candidate collection now requires real original bytecode from `BPF_PROG_GET_ORIGINAL`; it no longer falls back to `orig_prog_len`.
  - stale socket cleanup now ignores only `NotFound`; all other remove failures propagate.
- `runner/libs/aws_executor.py` + `runner/libs/aws_common.py`
  - AWS describe/lookup helpers now distinguish legitimate "not found" from AWS CLI failure; CLI stderr and non-zero exit status now raise real errors.
  - remote root-volume discovery now hard-fails on SSH/`lsblk` errors instead of returning `None`.
  - remote result sync now hard-fails if the remote suite exited `0` but the expected results directory is missing.
  - failed-run cleanup now surfaces termination failures instead of warning and continuing.
- `corpus/driver.py`, `e2e/driver.py`, `e2e/cases/bcc/case.py`
  - runner stop failures are now included in app error records.
  - empty effective pass provenance is preserved as empty/missing instead of silently substituting the requested pass set.
  - invalid payload error messages now preserve the original bad status instead of the synthetic replacement.
  - `all` case expansion now rewrites only the positional case argument, not unrelated flag values.

## Validation

Commands:

```sh
make vm-e2e
make vm-corpus
```

### KVM x86 e2e

Result: pass, `e2e: ALL PASSED`

Result sessions:

- `e2e/results/tracee_20260421_225302_087997`
- `e2e/results/tetragon_20260421_230225_644505`
- `e2e/results/bpftrace_20260421_230337_830485`
- `e2e/results/scx_20260421_231112_541188`
- `e2e/results/bcc_20260421_231227_084072`
- `e2e/results/katran_20260421_232323_651808`

### KVM x86 corpus

Result: pass, corpus status `ok`

Result session:

- `corpus/results/x86_kvm_corpus_20260421_232916_947372`

Metric delta vs previous KVM x86 baseline `corpus/results/x86_kvm_corpus_20260421_181829_750236`:

- `summary.applied_sample_count`: `10 -> 12`
- `summary.sample_count`: `10 -> 12`
- `no_programs_changed_in_loader`: `38 -> 36`
- applied-only geomean: `1.010x -> 1.010x` (stable to three decimals)

Comparison exclusions removed in this rerun:

- `bcc/bindsnoop:bindsnoop_v6_return#15`
- `scx/rusty:rusty_exit_task#67`

## New errors surfaced

- None in the KVM smoke runs. The stricter schema checks did not surface any malformed daemon replies during `make vm-e2e` or `make vm-corpus`.

## Follow-up

- AWS x86 and AWS arm64 suites were intentionally not rerun in this session to avoid AWS spend, per task constraints.
- Follow-up work is to re-run AWS e2e + corpus on both arches and confirm the stricter AWS error propagation and daemon/client schema checks stay green there as well.
