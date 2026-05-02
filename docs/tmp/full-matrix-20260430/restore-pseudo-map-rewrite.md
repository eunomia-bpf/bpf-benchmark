# Restore PSEUDO_MAP_FD/MAP_VALUE → daemon-fd Rewrite

## Background

Round 13 (commit `298211a0` "Refactor daemon to per-pass ReJIT") shipped the per-pass `BPF_PROG_REJIT(log_level=2)` architecture. It deleted the dry-run module, LoadAttr reconstruction, BTF replay normalization, and — incorrectly — the `PSEUDO_MAP_FD/PSEUDO_MAP_VALUE` immediate rewrite.

Result: every prog with map references failed `wide_mem` pass on the first REJIT attempt with errno 22 `fd N is not pointing to valid bpf_map`. bcc 9/9, calico, otelcol, cilium, tetragon, katran, tracee all hit it.

## Root cause

`BPF_PROG_GET_ORIGINAL` returns bytecode whose `LD_IMM64` instructions still encode the **loader process's map fds** (e.g. fd 4 was open in the bcc user-space loader). The daemon process has different fds for the same maps, opened via `BPF_MAP_GET_FD_BY_ID` from `prog_info.map_ids`. The kernel verifier rejects bytecode that references fd numbers absent from the calling process's fd table.

This is a fundamental requirement of cross-process ReJIT in user-space, not a v3 design accident. The v2 daemon had the same logic — see `git show daa5bd48^:daemon/src/bpf.rs` `relocate_map_fds_with_bindings` (~120 lines). Commit `d3c3a19d` re-added an equivalent rebinding for the (now-deleted) thin dry-run path. Commit `298211a0` removed both, conflating it with "BTF replay reconstruction" complexity that *is* unnecessary.

## Boundary clarification

| Daemon-side reconstruction | Necessary? | Why |
|---|---|---|
| `PSEUDO_MAP_FD/MAP_VALUE` imm rewrite to daemon-process fd | ✅ **Necessary** | fds are process-local; daemon must replace loader fds with its own |
| BTF `func_info` / `line_info` normalization | ❌ Not needed | REJIT reuses `prog->aux` BTF metadata; no need to refeed |
| LoadAttr field reconstruction (prog_type, attach_btf_id, ...) | ❌ Not needed | REJIT inherits all of these from `prog->aux` automatically |
| PSEUDO src_reg → fd_array index translation | ❌ Not needed here | REJIT accepts both `PSEUDO_MAP_FD imm=fd` and `PSEUDO_MAP_IDX imm=index`; we keep the simpler `PSEUDO_MAP_FD` form with rewritten imm |

## Implementation

`daemon/src/bpf.rs::relocate_map_fds_for_rejit(insns, map_ids, fd_array)`:

1. Scan `LD_IMM64` (`code == 0x18`) with `src_reg ∈ {PSEUDO_MAP_FD, PSEUDO_MAP_VALUE}`.
2. Collect unique `imm` values (stale loader fds) in first-seen order — matches the kernel's `used_maps` order.
3. Build `old_fd → daemon_fd` map by pairing each unique old fd with `fd_array[i]` (where `fd_array` was already constructed by `build_rejit_fd_array` from `prog_info.map_ids` via `BPF_MAP_GET_FD_BY_ID`).
4. Patch each matching instruction's `imm` to the daemon's fd. `src_reg` stays as `PSEUDO_MAP_FD/MAP_VALUE`.

`daemon/src/commands.rs::rejit_program` calls `relocate_map_fds_for_rejit` on a mutable clone of `insns` before invoking `kernel_sys::prog_rejit`. The `RejitFdArray._owned_fds` field already keeps the daemon's `OwnedFd` handles alive across the syscall.

## Code delta

| File | Change |
|---|---|
| `daemon/src/bpf.rs` | +85 lines (function + 6 unit tests) |
| `daemon/src/commands.rs` | +3 lines (`Vec::clone` + `relocate_map_fds_for_rejit` call) |
| **Net** | **+88 lines** |

This is a strictly necessary addition; the previous codex's claim that the rewrite was deletable was wrong.

## Validation

- `cargo build --manifest-path daemon/Cargo.toml --release` ✅
- `cargo test --manifest-path daemon/Cargo.toml --release` 28 passed
- New `bpf::tests::relocate_*` 6 tests passed
- `make check` `RESULTS: 27 passed, 0 failed`

VM-corpus validation deferred to Claude.

## Notes

- `bpfopt` CLI was not touched — it remains a pure bytecode transformer.
- v3 REJIT-only main path (`snapshot → bpfopt --pass <name> → BPF_PROG_REJIT`) preserved.
- Per-program parallel worker pool from `298211a0` preserved.
- All non-essential reconstruction (dry-run module, BTF replay, LoadAttr rebuild) stays deleted.
- This fix unblocks Round 14 vm-corpus.
