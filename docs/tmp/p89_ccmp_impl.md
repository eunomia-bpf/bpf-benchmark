# P89-CCMP Implementation Report

Date: 2026-04-30

## Summary

Implemented `ccmp` as an ARM64-only kinsn pass for short zero-test conditional
compare chains.

- Module: `module/arm64/bpf_ccmp.c`
- Rust pass: `bpfopt/crates/bpfopt/src/passes/ccmp.rs`
- Registry: `ccmp` is in `PASS_REGISTRY` and `bpfopt list-passes`
- Default pipeline: included only in the ARM64 optimize default order
- No x86 module or x86 default-order entry was added

The kinsn payload encodes a predicate destination register, a 2-4 term chain,
branch fail polarity, BPF branch width, and compare registers. The proof
sequence is ordinary BPF and computes `dst = 1` only if every chain term
continues; the final branch to the original target remains outside the kinsn.

## Site Validity

The pass only rewrites contiguous same-target zero-test chains. Site-level
rejects cover:

- Non-ARM64 platform
- Missing `bpf_ccmp64` kfunc or packed ABI support
- Chains shorter than 2 or longer than 4 terms
- Mixed fail polarity or branch width
- Common target inside the chain boundary
- Interior branch targets entering the chain
- Replacement crossing a subprogram or tail-call boundary
- No dead predicate destination register available

## Corpus Metrics

`BPFREJIT_BENCH_PASSES=ccmp make aws-arm64-corpus SAMPLES=1` was attempted.
It did not reach the corpus workload. The command spent the run in the cold
`katran-artifacts` ARM64 Docker build and was stopped after the Folly build
phase reached about 51%.

- Corpus apply count: not measured
- Verifier acceptance rate: not measured
- Failure mode: setup did not complete; no corpus programs were optimized or
  verifier-tested in this attempt

## Verification

Passed:

- `cargo test -p bpfopt ccmp -- --nocapture`
- `cargo test -p bpfopt`
- `cargo test -p bpfget`
- `cargo test` in `daemon/`
- `for i in 1 2 3 4 5; do cargo test --workspace || exit 1; done` in `bpfopt/`
- `cargo fmt --check` in `bpfopt/`
- `cargo fmt --check` in `daemon/`
- `cargo run -q -p bpfopt -- list-passes | rg '^ccmp$'`

Blocked:

- `make -C module/arm64` failed before compiling CCMP because the local
  `vendor/linux-framework` tree is not prepared:
  `include/generated/autoconf.h` / `include/config/auto.conf` are missing.

Confirmed:

- `vendor/linux-framework` remains at
  `a1b8bade169fae6e174ef022fa96fb1c626d96df`.
