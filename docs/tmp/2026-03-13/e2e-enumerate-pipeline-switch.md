# E2E Pipeline Switch: enumerate --prog-id path

**Date:** 2026-03-13
**Status:** Implementation complete, syntax verified, awaiting runtime test.

## Summary

Modified `e2e/common/recompile.py` to switch from the legacy `scan --prog-fd` + `apply --prog-fd`
pipeline to the new `enumerate --prog-id` pipeline.  The case files
(`tracee/case.py`, `tetragon/case.py`, `bpftrace/case.py`, `xdp_forwarding/case.py`) did **not**
need changes — they all go through `scan_programs()` and `apply_recompile()`.

---

## Old flow

```
app loads BPF
  → bpftool finds prog_id
  → caller opens fd (bpf_prog_get_fd_by_id)
  → scanner scan --prog-fd <fd> --all --json        # get live manifest
  → remap_policy_v3_to_live                         # address remapping
  → scanner apply --prog-fd <fd> --config <tmpfile> # recompile
```

The caller had to hold a valid, inheritable fd throughout. `scan` and `apply` are two separate
subprocess invocations, each requiring the caller-held fd.

## New flow

```
app loads BPF
  → bpftool finds prog_id
  → scanner enumerate --prog-id <id> --all --json   # scan (scanner opens fd internally)
  → [if policy needed: remap policy → write tmpdir/<name>.policy.yaml]
  → scanner enumerate --prog-id <id> --recompile [--policy-dir <tmpdir>]  # recompile
```

The scanner opens the fd itself via `BPF_PROG_GET_FD_BY_ID` internally.  No caller-held fd is
needed for the enumerate path.

---

## Implementation details

### `_USE_ENUMERATE_PATH` feature flag

A module-level constant `_USE_ENUMERATE_PATH = True` (line ~18) controls the path.
Set to `False` to force the legacy `scan --prog-fd` / `apply --prog-fd` path.

### New functions added to `recompile.py`

| Function | Description |
|---|---|
| `_enumerate_scan_one(scanner, prog_id)` | Calls `enumerate --prog-id <id> --all --json`, returns first record dict |
| `_enumerate_apply_one(scanner, prog_id, *, policy_dir)` | Calls `enumerate --prog-id <id> --recompile [--policy-dir <dir>] --json`, returns first record |
| `_scan_counts_from_enumerate(record)` | Converts enumerate JSON record to `_scanner_counts` shape |
| `_scan_one_legacy(...)` | Extracted legacy `scan --prog-fd` logic (unchanged) |
| `_apply_one_enumerate(...)` | New enumerate-path apply; falls back to `_apply_one_legacy` on any error |
| `_apply_one_legacy(...)` | Extracted legacy `apply --prog-fd` logic (unchanged) |

### `scan_programs()` changes

- Tries `_enumerate_scan_one()` first.
- On success, result includes an extra `"enumerate_record"` key with the raw JSON.
- On any exception (enumerate not available, kernel too old, etc.), falls back to
  `_scan_one_legacy()` automatically.

### `apply_recompile()` changes

- For `blind_apply=True` or `selected_policy is None` → was already handled by early return
  (no-op stock path), unchanged.
- For `selected_policy` set (policy-file mode) with `_USE_ENUMERATE_PATH`:
  1. Call `_enumerate_scan_one()` to learn the live program name.
  2. Open a caller-held fd **only** to call `_scan_live_manifest()` (needed for address remapping).
  3. Write remapped policy to `<tmpdir>/<program_name>.policy.yaml`.
  4. Call `_enumerate_apply_one(..., policy_dir=tmpdir)`.
  5. Falls back to full `_apply_one_legacy()` at any failure point.
- For `blind_apply=True` (no policy needed):
  1. Call `_enumerate_apply_one(scanner, prog_id, policy_dir=None)` directly.
  2. Falls back to `_apply_one_legacy()` on failure.
- Result dict gains `"enumerate_record"` key when enumerate path succeeds.

### Fallback strategy

Every enumerate call is wrapped in `try/except`.  If `enumerate` subcommand is absent (older
scanner build), returns a non-zero exit code, or returns malformed JSON, the code falls back
transparently to the legacy `--prog-fd` path.  Error messages in fallback results are prefixed
with `"enumerate failed (<reason>), ..."` for traceability.

---

## Files changed

| File | Change |
|---|---|
| `e2e/common/recompile.py` | Core implementation — new enumerate path with fallback |

## Files unchanged (no modification needed)

| File | Reason |
|---|---|
| `e2e/cases/tracee/case.py` | Calls `scan_programs()` + `apply_recompile()` — unchanged API |
| `e2e/cases/tetragon/case.py` | Same |
| `e2e/cases/bpftrace/case.py` | Same |
| `e2e/cases/xdp_forwarding/case.py` | Same |
| `corpus/_driver_impl_run_macro_corpus.py` | Same |
| `corpus/_driver_impl_run_corpus_tracing_exec.py` | Same |

---

## Verification

```bash
python3 -m py_compile e2e/common/recompile.py           # OK
python3 -m py_compile e2e/cases/tracee/case.py          # OK
python3 -m py_compile e2e/cases/tetragon/case.py        # OK
python3 -m py_compile e2e/cases/bpftrace/case.py        # OK
python3 -m py_compile e2e/cases/xdp_forwarding/case.py  # OK
```

---

## Known limitations / next steps

1. **address remapping still requires a caller-held fd**: `_scan_live_manifest()` is still called
   via `--prog-fd` to get the per-site address map for policy remapping.  A future improvement
   would be to extend `enumerate --json` output to include per-site details so the fd can be
   dropped entirely.
2. **per-family site counts not available from enumerate**: The enumerate JSON record only reports
   `total_sites` / `applied_sites`, not per-family breakdown. The `_scan_counts_from_enumerate()`
   function returns zeros for all per-family counters. If per-family stats are needed, the legacy
   `scan --prog-fd --json` path still returns them (used in the fallback).
3. **runtime test pending**: functional test requires a live kernel with BPF enabled and a running
   agent (Tracee / Tetragon). Syntax is verified; integration test should be run in VM.
