# P1-F const_prop frame-pointer materialization fix

Date: 2026-05-10

## Root cause

OTEL prog 13/14 failed ReJIT at the `const_prop` step because
`const_prop_alu_materialized` replaced frame-pointer arithmetic used as a
helper memory argument with scalar immediates:

- prog 13: `r1 = r10; r1 += -64` became `r1 = 0`
- prog 14: `r1 = r10; r1 += -16` became `r1 = 1`

`bpf_probe_read_user()` requires `r1` to be a verifier memory pointer type, so
the transformed programs were rejected with `R1 type=scalar expected=fp, ...`.

## Fix

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:13` adds a small forward
  verifier post-state lookahead for pointer evidence. The OTEL artifacts show
  the accepted ReJIT log can report the relevant post-state a few PCs ahead of
  bpfopt's current bytecode index after earlier transforms.
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:18` defines the required skip
  reason: `register has pointer type, cannot materialize`.
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:151` and
  `bpfopt/crates/bpfopt/src/passes/const_prop.rs:181` record non-scalar
  verifier post-states from `InsnDeltaState`.
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:311` checks exact-frame or
  frame-invariant pointer evidence for the destination register.
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:633` skips scalar
  materialization before emitting a replacement if the destination has pointer
  verifier type evidence.

The emit path is unchanged; this is only a site filter.

## Regression test

Added `const_prop_skips_frame_pointer_arithmetic_materialization` at
`bpfopt/crates/bpfopt/src/passes/const_prop_tests.rs:255`.

The test builds:

```text
r1 = r10
r1 += -16
r2 = 16
call bpf_probe_read_user
```

It also includes a stale scalar verifier fact at the unshifted ALU pc and an
`fp-16` post-state in the forward verifier-state window. The expected result is
no bytecode replacement and a recorded skip reason
`register has pointer type, cannot materialize`.

The existing packet-pointer copy test was updated to assert the same explicit
skip reason.

## Artifact check

Using the latest failure artifacts:

- `corpus/results/x86_kvm_corpus_20260510_085438_783442/details/failure-artifacts/13.tar.gz`
- `corpus/results/x86_kvm_corpus_20260510_085438_783442/details/failure-artifacts/14.tar.gz`

Re-running current `bpfopt --pass const_prop` on `output_step6.bin` with
`verifier_log_step6.log`:

- prog 13: materialized sites dropped from 31 to 22; pointer-type skips = 20.
  The `r1 = r10; r1 += -64; r2 = 16; call 112` sequence is preserved.
- prog 14: materialized sites dropped from 14 to 10; pointer-type skips = 4.
  The `r1 = r10; r1 += -16; r2 = 16; r3 = r8; call 112` sequence is preserved.

## Verification

```sh
cd /home/yunwei37/workspace/bpf-benchmark/bpfopt && cargo build --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/bpfopt && cargo test --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo build --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo test --workspace --locked
```

Results:

- `bpfopt` build: pass
- `bpfopt` tests: 349 lib + 16 main + 12 CLI = 377 pass
- `daemon` build: pass
- `daemon` tests: 25 pass
- Total tests: 402 pass

No commit was created.
