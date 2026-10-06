# P1-B Fix 2: KinsnRegistry call_offset=0 Compound Key - 2026-05-09

## Option

Implemented Option A: an atomic `KinsnRegistry::set_kinsn_call_for_target_name(target, btf_id, call_off)` setter.

Reason: the registry identity is the full runtime call key `(btf_id, call_off)`. Updating the two fields independently created invalid intermediate keys, and `call_offset=0` is a legal final key. The atomic setter keeps duplicate detection on the final compound key only, while preserving fail-fast rejection for true duplicate `(btf_id, call_off)` ownership.

## Code Diff Summary

- `bpfopt/crates/bpfopt/src/pass.rs`
  - Replaced the split public setters with `set_kinsn_call_for_target_name()`.
  - Moved `by_call` maintenance to the atomic final-key update path.
  - Kept duplicate detection for exact `(btf_id, call_off)` collisions.
- `bpfopt/crates/bpfopt/src/main.rs`
  - `kinsn_registry_from_target()` now installs target JSON entries with the atomic setter.
  - `apply_kinsn_list()` uses the atomic setter with default `call_off=0`.
- `bpfopt/crates/bpfopt/src/passes/*_tests.rs` and `passes/utils.rs`
  - Updated test contexts and proof-remap tests to construct registered kinsn calls through the atomic API.

The emit path is unchanged: passes still read `btf_id_for_target_name()` and `call_off_for_target_name()` and emit the same kinsn call instruction fields.

## Test Coverage

- `pass_tests.rs`
  - `kinsn_registry_atomic_call_setter_allows_shared_btf_id_with_zero_call_offset`
  - `kinsn_registry_atomic_call_setter_rejects_duplicate_call_key`
- `main.rs`
  - `target_json_allows_shared_btf_id_when_zero_call_offset_is_first`

These cover the review edge where two targets share `btf_id`, one has final `call_offset=0`, and the zero-offset target is parsed before the non-zero target.

## Test Results

Commands run:

```sh
cd /home/yunwei37/workspace/bpf-benchmark/bpfopt && cargo build --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/bpfopt && cargo test --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo build --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo test --workspace --locked
```

Results:

```text
bpfopt cargo build: pass
bpfopt cargo test:  pass
  lib tests:        334 passed
  main tests:       16 passed
  cli tests:        12 passed
daemon cargo build: pass
daemon cargo test:  25 passed
```

Total observed Rust tests: 387. I did not run `make corpus`.
