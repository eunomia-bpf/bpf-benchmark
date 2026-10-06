# map_inline pattern fix report (2026-03-26)

## What changed

Patched `daemon/src/passes/map_inline.rs` in three places:

1. `find_r2_stack_pointer_setup()` now scans backward through up to 8 real instructions and skips intervening instructions that do not define `r2`.
   - New lookback constant: `daemon/src/passes/map_inline.rs:15`
   - New backward-def helper: `daemon/src/passes/map_inline.rs:588-607`
   - Relaxed `r2` matcher: `daemon/src/passes/map_inline.rs:569-586`

2. Array-style rewrites now only delete the lookup setup when the whole pattern is still a contiguous block.
   - If clang/interleaved setup breaks contiguity, the pass still rewrites the fixed `r0` loads to constants and keeps the lookup setup in place instead of skipping the site.
   - Rewrite gating: `daemon/src/passes/map_inline.rs:424-475`
   - Contiguity check helper: `daemon/src/passes/map_inline.rs:549-567`

3. Added regressions for the real ordering and the clobber case.
   - `test_map_inline_real_clang_order`: `daemon/src/passes/map_inline.rs:1198-1236`
   - `test_map_inline_interleaved_arg_setup`: `daemon/src/passes/map_inline.rs:1238-1270`
   - `test_map_inline_r2_clobbered_between`: `daemon/src/passes/map_inline.rs:1272-1302`

## Rust test results

Ran:

```sh
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml map_inline
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Results:

- `map_inline`-filtered test run: passed
  - 30 passed, 0 failed
- full daemon test run: passed
  - 451 passed, 0 failed, 12 ignored

## VM static verify result

Ran the requested command:

```sh
make vm-static-test STATIC_VERIFY_ARGS='--mode micro' TARGET=x86
```

Observed artifact:

- `daemon/tests/results/static_verify.json`
- generated at `2026-03-26T20:12:12.087105+00:00`

Observed counts from that artifact:

- total micro records: `62`
- changed programs: `55`
- records with `map_inline` in `passes_applied`: `0`

So the requested micro static-verify count did **not** increase above `55`; it remained `55`.

## Why the micro count stayed 55

The current micro catalog does not actually instantiate the true map-backed XDP helper path:

- The only macro that emits `bpf_map_lookup_elem(&input_map, &key)` is `DEFINE_MAP_BACKED_XDP_BENCH()` in `micro/programs/common.h:198-221`.
- Nothing under `micro/programs/` currently uses that macro.
- The TC and cgroup "map-backed" macros are aliases to staged/fixed packet-backed variants, not helper-based map lookup:
  - `DEFINE_MAP_BACKED_TC_BENCH`: `micro/programs/common.h:256-257`
  - `DEFINE_MAP_BACKED_CGROUP_SKB_BENCH`: `micro/programs/common.h:284-285`

That explains the static-verify artifact:

- no `map_inline` applications in micro mode
- unchanged aggregate changed-program count of `55`

## Extra spot-check

Host-side disassembly of `corpus/build/katran/balancer.bpf.o` shows the real clang ordering this fix targets, for example:

- `r2 = r10`
- `r2 += -off`
- `r1 = 0x0 ll` with `R_BPF_64_64 <map>`
- `call 0x1`

Example call sites were visible in `llvm-objdump` output for `katran_balancer`, including `stats`, `vip_map`, `ctl_array`, and related maps.

I also attempted a targeted macro VM run for `katran_balancer`, but the VM wrapper did not produce a fresh static-verify artifact before teardown stalled, so I am not claiming a macro-mode applied count from that attempt.
