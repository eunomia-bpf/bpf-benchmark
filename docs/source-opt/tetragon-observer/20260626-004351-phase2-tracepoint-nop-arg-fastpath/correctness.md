# Correctness

- Source-only boundary: changed only Tetragon eBPF C/header files under `vendor/repos/tetragon/bpf/process/`.
- Loader path: `make corpus` copied `vendor/build/x86/tetragon/` into `/artifacts/tetragon/`; runner used the real Tetragon binary with `--bpf-lib`.
- App status: `ok`.
- App error: empty string.
- Workload return codes: `0, 0, 0`.
- ReJIT state: `SKIP_REJIT=all`; `post_rejit` is `null`; `rejit_result.mode` is `skip_rejit_all`.
- Semantics gate: no event/map/tail-call ABI fields were changed. `nop_ty` argument reads still produce 0; namespace/capability snapshots are materialized before the same selector consumers.
- Restore gate: `patch -R` applied cleanly after the run; `vendor/repos/tetragon` has no local diff.
