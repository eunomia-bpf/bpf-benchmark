# P89 Full Review Fix Report

Date: 2026-05-01

## Findings

1. HIGH `corpus/driver.py` rediscovery ID drift: FIXED.
   Rediscovery now raises when refreshed BPF program IDs differ from the tracked set, including expected IDs, refreshed IDs, missing IDs, unexpected IDs, and discovery source. The warning-and-replace path was removed.

2. HIGH `runner/libs/suite_commands.py` runtime tmp bind mount: FIXED.
   Runtime containers now bind only suite result directories plus system mounts. `docs/tmp/runtime-container-tmp` host directory creation, mount flags, and cleanup paths were removed.

3. HIGH `runner/libs/aws_executor.py` full host root installer mount: FIXED.
   The AWS kernel installer no longer runs `docker run -v /:/host`; it streams kernel artifacts over SSH and runs host `depmod`, `dracut`, and `grubby` directly.

4. MEDIUM `bpfopt/src/pass.rs` unknown analysis names: FIXED.
   `run_required_analyses()` now returns `Result<()>` and errors when a pass declares an unregistered required analysis. A regression test covers the failure path.

5. MEDIUM `bpfopt/src/main.rs` unknown target features: FIXED.
   `apply_features()` now returns `Result<()>` and rejects unknown target feature names with `unknown target feature: ...`.

6. MEDIUM `bpfopt/src/main.rs` unknown encoding names: FIXED.
   `parse_supported_encodings()` now returns `Result<u32>` and rejects unknown encoding names instead of collapsing them to zero bits.

7. MEDIUM `map_inline.rs` resolver fallback: FIXED.
   Pseudo-map-value provider and lookup errors now propagate. Only explicit ineligible cases, such as missing binding, non-frozen maps, and hash-like null snapshots, return `None`.

8. MEDIUM `prefetch.rs` budget accounting: FIXED.
   The global `PREFETCH_SITE_BUDGET` cap was removed, so structural candidates are no longer silently dropped by budget truncation.

9. MEDIUM verifier-state duplication: FIXED.
   `VerifierInsnKind`, `VerifierValueWidth`, `Tnum`, `ScalarRange`, `VerifierInsn`, `RegState`, `StackState`, and the verifier-states JSON DTOs now live in `kernel-sys`. `bpfverify` serializes the shared DTO and `bpfopt` deserializes it. `kernel-sys` has JSON ABI round-trip/default tests.

10. MEDIUM `fd_array` parsing duplication: FIXED.
    `FdArrayEntry`, dense slot validation, BTF fd resolution, owned fd storage, and ReJIT fd-array construction now live in `kernel-sys::FdArray`. `bpfverify` and `bpfrejit` both call the shared implementation.

11. MEDIUM `environment.py` perf_event_paranoid warning: FIXED.
    `perf_event_paranoid > 1` now goes through `report_publication_issue()`, so strict publication mode exits 1 instead of warning only.

12. MEDIUM `rejit.py` malformed aggregate totals: FIXED.
    Non-object ReJIT results, non-object `per_program`, and non-object per-program records now raise `RuntimeError` instead of returning zero counts or skipping records.

## Verification

Commands run:

```bash
cargo check --workspace
cargo test --workspace --release
cargo build --release
cargo test --release
python -m pytest tests/python/ -v
```

Results:

- `bpfopt`: `cargo check --workspace` passed.
- `bpfopt`: `cargo test --workspace --release` passed.
- `daemon`: `cargo build --release` passed.
- `daemon`: `cargo test --release` passed.
- Python: `tests/python/` does not exist; pytest exited 4 after collecting 0 tests.
