# SkbLoadBytesSpecPass Implementation Report

Date: 2026-03-26

## Summary

Implemented `SkbLoadBytesSpecPass` in [daemon/src/passes/skb_load_bytes.rs](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/skb_load_bytes.rs).

The pass now:

- Applies only to `BPF_PROG_TYPE_SCHED_CLS` and `BPF_PROG_TYPE_SCHED_ACT`
- Scans for regular helper calls to `bpf_skb_load_bytes` (`call #26`)
- Tracks simple per-basic-block register state to prove:
  - `r1 == ctx`
  - `r2 == constant offset`
  - `r3 == fp + const` with a negative stack offset
  - `r4 == constant len`
- Replaces the helper call with:
  - `ctx->data` / `ctx->data_end` loads from `__sk_buff` offsets `76` and `80`
  - A direct packet bounds check
  - A fast copy path into the existing stack destination
  - A slow path that restores `r2`/`r4` and reissues helper `call #26`
- Rebuilds the instruction stream and fixes original branch offsets with `fixup_all_branches()`
- Restricts v1 specialization to `1 <= len <= 8`
- Requires `r1` to still be provably `ctx` at the call site, including after prior helper calls

## Copy Strategy

- All supported lengths use an unrolled byte-copy sequence.
- This avoids emitting wide direct packet loads/stores for `len == 2/4/8`, which can be verifier-risky on packet pointers because of range/alignment constraints.

## Verification

Focused pass tests:

```sh
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml skb_load
```

Result: `14 passed; 0 failed`

Full daemon suite:

```sh
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Result: `379 passed; 0 failed; 12 ignored`
