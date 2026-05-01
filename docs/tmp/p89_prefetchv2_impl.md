# P89 PrefetchV2 Implementation

## Scope

Converted `prefetch` from a PMU-required helper-key prefetch pass into a
default structural packet/map-value pass. PMU data is now optional: when a
candidate has a real `prefetch_sites` profile entry, the existing hot/missy
admission checks are applied; when it has no PMU entry, the structural candidate
is emitted.

## Files changed

- `bpfopt/crates/bpfopt/src/passes/prefetch.rs`
  - Removed the missing-profile hard gate.
  - Replaced lookup-key prefetching with map-value and packet-pointer
    prefetching.
  - Added branch-target analysis for packet provenance resets.
  - Kept CFG/subprogram/basic-block/instruction-boundary insertion checks.
- `bpfopt/crates/bpfopt/src/main.rs`
  - Added `prefetch` to x86 default optimize order: 11 -> 12 passes.
  - Added `prefetch` to arm64 default optimize order: 12 -> 13 passes.
  - Added `list-passes --arch <x86_64|arm64>` to print the arch default order.
- `bpfopt/crates/bpfopt/src/passes/mod.rs`
  - Updated pass description.
- `bpfopt/crates/bpfopt/src/pass.rs`
  - Updated PMU profile comments to reflect optional prefetch admission.
- `bpfopt/crates/bpfopt/tests/cli_pipeline.rs`
  - Updated default pipeline tests for 12-pass x86 and 13-pass arm64 listing.
- `corpus/config/benchmark_config.yaml`
  - Added `prefetch` to the benchmark default pass list.

## Site detection

Map value prefetch:

- Finds regular `bpf_map_lookup_elem` helper calls.
- Tracks `R0` aliases through `MOV64 reg` and constant `ADD/SUB`.
- Scans within the same subprogram for the first memory access whose base is
  the returned value pointer or an alias.
- Emits `bpf_prefetch(base)` before that dereference.
- Uses profile data attached either to the dereference PC or the helper-call PC
  if present.

Packet prefetch:

- Enabled for XDP and skb-like packet program types:
  `XDP`, `SCHED_CLS`, `SCHED_ACT`, `SK_SKB`, `LWT_IN`, `LWT_OUT`, `LWT_XMIT`.
- Tracks `ctx->data` loads using existing XDP/SKB context offsets.
- Propagates packet pointers through `MOV64` and constant `ADD/SUB`.
- Clears uncertain state at branch targets, helper caller-saved clobbers, and
  all tracked packet state after `bpf_xdp_adjust_head`.
- Emits `bpf_prefetch(base)` before direct packet loads/stores.

Insertion policy:

- Target distance is 8 BPF instructions, i.e. 64 BPF bytecode bytes.
- The pass chooses the nearest safe instruction boundary in the same CFG block,
  never inside `LD_IMM64`, and falls back to the dereference boundary when the
  post-guard window is short.
- `prefetch` is placed at the end of the default optimize order. This avoids
  shifting verifier-state PCs before `const_prop`, avoids DCE seeing the kinsn
  sidecar/call as ordinary code, and avoids disturbing later pattern matchers.

## Verification

- `cargo fmt`
- `cargo check --workspace`
- `cargo test --workspace --release prefetch`
  - 7 prefetch tests passed.
- `cargo test -p bpfopt --test cli_pipeline --release`
  - 11 tests passed.
- `cargo test --workspace --release`
  - all bpfopt workspace tests passed.
- `cargo run -q -p bpfopt -- list-passes --arch x86_64`
  - output ends with `prefetch`; x86 default has 12 passes.
- `cargo run -q -p bpfopt -- list-passes --arch arm64`
  - output ends with `prefetch`; arm64 default has 13 passes.
- `cd ../daemon && cargo build --release && cargo test --release`
  - 36 daemon tests passed.

Host dryrun:

- `runner/build-llvmbpf/` was not present on this host, so the smoke used raw
  BPF bytecode accepted by `bpfopt optimize`.
- Input: a 5-instruction map-lookup value dereference program with no PMU
  profile.
- Default x86 optimize report:
  - `prefetch changed=true`
  - `sites_applied=1`
  - instruction count `5 -> 7`

## Notes

- No `module/` or `vendor/linux-framework/` files were changed.
- `branch_flip` remains outside the default optimize order and still requires
  real per-site PMU data.
