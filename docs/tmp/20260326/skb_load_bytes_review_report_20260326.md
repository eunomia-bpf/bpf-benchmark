# SkbLoadBytesSpecPass Review Report

Date: 2026-03-26

## Code Quality Assessment

- `SkbLoadBytesSpecPass` is correctly registered in `daemon/src/passes/mod.rs` and present in the default pipeline between `dce` and `bounds_check_merge`.
- Helper matching is scoped to regular helper call `#26`, TC prog types, constant `r2`/`r4`, and fp-relative stack destinations in `r3`.
- Rewrite integration is sound: the pass rebuilds the instruction stream, remaps annotations, and reuses `fixup_all_branches()` for control-flow repair.
- Unit coverage now includes positive/negative matcher cases, branch fixup, multi-site rewrites, helper-call clobber handling, and the `len=2/4/8` verifier-safety path.

## Test Results

Command:

```sh
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml skb_load
```

Result: `14 passed; 0 failed`

Command:

```sh
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Result: `379 passed; 0 failed; 12 ignored`

## Issues Found And Fixed

1. The matcher accepted `len > 8`, which exceeded the v1 design scope and could overflow the internal slow-path branch offset for very large lengths. Fixed by rejecting `len > 8` in site classification and adding a regression test.
2. The fast path emitted `BPF_H`/`BPF_W`/`BPF_DW` direct packet accesses for `len=2/4/8`. On packet pointers, that can be verifier-risky because of range/alignment constraints even when `bpf_skb_load_bytes()` itself is valid. Fixed by keeping all supported fast-path copies bytewise and adding coverage for `len=2/4/8`.
3. The local register-state scan treated `r1` as still holding `ctx` after any helper call, which is not the eBPF calling convention. Fixed by leaving `r1` unknown after calls and adding positive/negative tests for explicit ctx reload.
4. The existing multi-call test fixture modeled a second helper site without reloading `r1` after the first helper call. Fixed the test program to save/restore `ctx` through a callee-saved register so it reflects a verifier-valid sequence.

## Commit Hash

- Implementation commit: `bf0742d9540f`
