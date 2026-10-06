# Endian DW-load narrowing - 2026-05-05

## Implementation

- New narrowing matcher: `bpfopt/crates/bpfopt/src/passes/endian.rs:69`.
- Narrowing acceptance: `endian.rs:92` through `:103` scans up to 32 straight-line instructions from `LDX{W,DW}` to a same-dst endian byte-swap and emits the fused site with `BPF_H`/`BPF_W` size.
- Size policy: `endian.rs:142` through `:159` accepts exact sizes plus `(W,H)`, `(DW,H)`, and `(DW,W)`.
- Rewrite mapping: `endian.rs:503` through `:524` emits the packed endian kinsn, copies safe intervening instructions, and remaps the deleted endian op to the end of the replacement window.

## Flow Analysis

The local proof is intentionally conservative. For a non-adjacent narrowed candidate, the pass only accepts a straight-line window where the loaded destination register is never read or written before the byte-swap. `reads_reg`/`writes_reg` are local register-use checks, and any branch, call, exit, or `LDIMM64` stops the window. If a later narrowed endian op is found after a destination read, the pass leaves the bytecode unchanged and records `narrow endian fusion blocked: possible upper bits read before endian`.

This is stricter than an upper-bit-only proof, but it preserves semantics when the fused load+swap is moved to the original load PC.

## Validation

- `cargo test --release --workspace --manifest-path bpfopt/Cargo.toml`: pass.
- KVM smoke:
  - Command: `SAMPLES=1 BPFREJIT_BENCH_PASSES="endian_fusion" BPFREJIT_CORPUS_APPS="cilium/agent" make vm-corpus`
  - Artifact: `corpus/results/x86_kvm_corpus_20260505_151506_347859`
  - App status: `ok`
  - ReJIT exit: `0`
  - ReJIT errors: `0`
  - `endian_fusion` sites_applied: before `4`, after `5`
  - Note: this did not reach the requested `>=20`; the live Cilium run exposed five applied `cil_to_host` sites, with no verifier rejects.

## Delta

- Implementation commit containing `endian.rs`: `35ed1536fe00b11cf0507668a83a86df08256b1f`
- `endian.rs` delta in that commit: `+237/-44` (net `+193` LoC)
