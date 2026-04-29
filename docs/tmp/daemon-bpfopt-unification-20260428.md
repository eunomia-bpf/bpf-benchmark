# daemon / bpfopt unification result (2026-04-28)

## Decision

Keep `daemon/src/` as the single pass implementation and delete `bpfopt/`.

Rationale:

- `daemon serve` is the only runtime entry point.
- daemon owns the required runtime semantics: raw BPF syscalls, per-pass `BPF_PROG_LOAD` verify, rollback on verifier rejection, final `BPF_PROG_REJIT`, kinsn BTF FD transport, live map lookup, profiling, and invalidation.
- `bpfopt-core` was an offline fork, not a daemon dependency. Its kinsn and map-inline APIs had diverged from the live REJIT path, and some tests still referenced daemon-only BTF FD APIs that no longer existed in `bpfopt-core`.

## Pass comparison

Both trees contained the same pass set:

- `map_inline`
- `const_prop`
- `dce`
- `skb_load_bytes`
- `bounds_check_merge`
- `wide_mem`
- `bulk_memory`
- `rotate`
- `cond_select`
- `extract`
- `endian_fusion`
- `branch_flip`

There were no daemon-only pass names and no bpfopt-only pass names.

Byte-identical files under `passes/`:

- `mod.rs`
- `bulk_memory_tests.rs`
- `cond_select_tests.rs`
- `wide_mem_tests.rs`

Implementation files with only wrapper/API-shape differences:

- `bounds_check_merge.rs`
- `branch_flip.rs`
- `const_prop.rs`
- `dce.rs`
- `skb_load_bytes.rs`
- `wide_mem.rs`

In these files, bpfopt mostly expanded daemon helpers such as `PassResult::unchanged()` and `PassResult::skipped()` because its `PassResult` type had removed daemon-specific verify/rollback fields.

Kinsn transport differences:

- `bulk_memory.rs`
- `rotate.rs`
- `cond_select.rs`
- `extract.rs`
- `endian.rs`

daemon records module BTF FDs via `ensure_btf_fd_slot()` and `BpfProgram.required_btf_fds`, then sends the corresponding `fd_array` during verify/REJIT. bpfopt replaced that with static `target_call_offsets`, which is unsuitable for the live daemon path without a linker/adapter layer.

Functional `map_inline` differences:

- daemon reads live map metadata and values through raw BPF syscalls.
- bpfopt reads preloaded `map_metadata` and `map_values` snapshots.
- daemon has newer alias-offset tracking for map value pointer adjustments; bpfopt kept the older alias-as-set model.
- daemon keeps verifier-guided source PC tracking for stack stores; bpfopt dropped part of that path.

## IR and analysis comparison

Byte-identical files:

- `analysis/branch_target.rs`
- `analysis/cfg.rs`
- `analysis/liveness.rs`
- `analysis/mod.rs`

Different files:

- `analysis/map_info.rs`: daemon resolves live map info via raw BPF syscall; bpfopt resolves from preloaded metadata.
- `insn.rs`: comments only, describing daemon fd_array slots versus offline call metadata.
- `pass.rs`: major divergence. daemon contains `required_btf_fds`, `PassVerifyResult`, `PassRollbackResult`, `run_with_verifier()`, verifier-state propagation, and rollback. bpfopt removed those and added offline `map_values`, `map_metadata`, and `target_call_offsets`.
- `verifier_log.rs`: comments only.
- `elf_parser.rs`: daemon keeps struct_ops program type inference and fails on oversized global data sections; bpfopt had test-only dead-code allowance and a silent size fallback.
- `test_utils.rs`: daemon uses syscall mock maps in `daemon/src/bpf.rs`; bpfopt used its own `mock_maps.rs`.
- `mock_maps.rs`: bpfopt-only test helper.

## Applied result

- Deleted `bpfopt/` and its workspace `Cargo.toml`.
- Kept daemon pass pipeline behavior unchanged.
- Updated the active plan and archive entry to record that `bpfopt/` is removed and `daemon/src/` is the single pass source.
