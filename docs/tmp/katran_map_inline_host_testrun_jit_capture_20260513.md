# Katran host bpftestrun map_inline live JIT capture

Date: 2026-05-13

## Goal

Capture the actual host-loaded JIT for the Katran loader testcase and explain why the hardcoded `map_inline` path is slower than `noop` in `BPF_PROG_TEST_RUN`.

The testcase input is `corpus/inputs/katran_vip_packet_64.bin`. The semantic check is `repeat=1` and expects `XDP_TX` plus IPIP output. Timing uses `repeat=10000`, where `bpfopt/loader/src/main.rs` sets `BPF_F_TEST_XDP_LIVE_FRAMES`.

## Capture method

`bpftool prog dump jited` cannot be run after the loader exits because the verifier-loaded fd is dropped. The capture used `gdb` breakpoints on `bpfopt_loader::run_bpftestrun` and dumped the live program before the fd was closed.

Artifacts:

- `docs/tmp/katran_host_loader_jit_map_inline_20260513_214450/baseline_noop/`
- `docs/tmp/katran_host_loader_jit_map_inline_20260513_214450/optimized_map_inline/`

Important selector detail: selecting `name == "balancer_ingress"` is wrong for the verifier reload. The original libbpf-loaded object keeps `balancer_ingress`, while the reload through `bpf_prog_load()` is truncated by the kernel to `balancer_ingres`. The valid capture selects the latest XDP program whose name starts with `balancer_ingres`.

## Captured programs

| path | id | name | tag | bytes_xlated | bytes_jited |
| --- | ---: | --- | --- | ---: | ---: |
| noop | 14809 | `balancer_ingres` | `e87cf8744d63f1cd` | 23888 | 13663 |
| hardcoded `map_inline` | 14960 | `balancer_ingres` | `985938fc714f505e` | 17584 | 9978 |

The optimized program is a different live JIT image and is substantially smaller, so the earlier identical JIT capture was a selection bug, not evidence that `map_inline` failed to load.

## Static JIT / xlated deltas

| metric | noop | hardcoded `map_inline` |
| --- | ---: | ---: |
| xlated BPF instructions | 2897 | 2132 |
| JIT instruction lines (`bpftool ... jited opcodes`) | 3262 | 2392 |
| x86 JIT bytes | 13663 | 9978 |
| x86 `callq` sites | 31 | 18 |
| x86 `divq` sites | 2 | 2 |
| x86 `imulq $65537` sites | 2 | 2 |

BPF helper/static-call sites in xlated output:

| call target | noop | hardcoded `map_inline` |
| --- | ---: | ---: |
| `__htab_map_lookup_elem` | 8 | 6 |
| `bpf_map_lookup_elem` | 4 | 1 |
| `bpf_map_update_elem` | 4 | 0 |
| `bpf_ktime_get_ns` | 8 | 4 |
| `bpf_xdp_adjust_head` | 4 | 4 |
| BPF-to-BPF calls | 3 | 3 |

There is no obvious bad JIT lowering from this dump: the optimized live image is smaller and has fewer helper/static-call sites. The `% 65537` lowering remains unchanged (`divq` + `imulq $65537` appears twice in both), so this capture does not support a claim that `map_inline` accidentally made const-mod lowering worse.

## Timing retest

Raw `duration_ns` from `BPF_PROG_TEST_RUN repeat=10000`:

- `noop`: 106, 107, 110, 108, 102 ns
- hardcoded `map_inline`: 141, 140, 140 ns

The slowdown is reproducible for this host bpftestrun fixture even though the optimized JIT is smaller.

## Interpretation

For this host loader testcase, the slower result is not explained by code-size growth, extra helper calls, or a failed optimized reload. The optimized program is definitely loaded, verifier/JIT output is smaller, and the semantic `repeat=1` check still returns `XDP_TX` with IPIP output.

The main caveat is that the timing path is the live XDP test-run path, not just a tight `bpf_prog_run_xdp()` loop. With `repeat > 1`, the loader sets `BPF_F_TEST_XDP_LIVE_FRAMES`; the kernel enters `bpf_test_run_xdp_live()`, allocates/resets test frames in `xdp_test_run_batch()`, runs the BPF program, updates the frame when packet bounds changed, and turns `XDP_TX` into redirect/flush work. That timing is still useful for the loader fixture, but it is not the same as corpus app-side forwarding counters.

The current evidence says:

1. Hardcoded `map_inline` is not obviously miscompiled for the corpus VIP packet.
2. Live JIT is smaller and has fewer calls.
3. The host live-frame bpftestrun measurement still gets slower, so this fixture alone is not enough to conclude `map_inline` helps Katran forwarding.
4. Any next claim needs either corpus `make corpus` raw counters for Katran or a more isolated program-only timing mode that still uses the same packet/map state.

