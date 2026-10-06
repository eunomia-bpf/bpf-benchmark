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
- `docs/tmp/katran_host_loader_jit_map_inline_const_dce_20260513/`
- `docs/tmp/katran_map_inline_const_prop_dce_host_fixture/`

Important selector detail: selecting `name == "balancer_ingress"` is wrong for the verifier reload. The original libbpf-loaded object keeps `balancer_ingress`, while the reload through `bpf_prog_load()` is truncated by the kernel to `balancer_ingres`. The valid capture selects the latest XDP program whose name starts with `balancer_ingres`.

## Captured programs

| path | id | name | tag | bytes_xlated | bytes_jited |
| --- | ---: | --- | --- | ---: | ---: |
| noop | 14809 | `balancer_ingres` | `e87cf8744d63f1cd` | 23888 | 13663 |
| hardcoded `map_inline` | 14960 | `balancer_ingres` | `985938fc714f505e` | 17584 | 9978 |
| hardcoded `map_inline` + `const_prop` + `dce` | 17401 | `balancer_ingres` | `b80ece3ed8d31fba` | 17144 | 9653 |

The optimized program is a different live JIT image and is substantially smaller, so the earlier identical JIT capture was a selection bug, not evidence that `map_inline` failed to load.

## Static JIT / xlated deltas

| metric | noop | hardcoded `map_inline` | `map_inline` + `const_prop` + `dce` |
| --- | ---: | ---: | ---: |
| xlated BPF instructions | 2897 | 2132 | 2077 |
| JIT instruction lines (`bpftool ... jited opcodes`) | 3262 | 2392 | 2332 |
| x86 JIT bytes | 13663 | 9978 | 9653 |
| x86 `callq` sites | 31 | 18 | 18 |
| x86 `divq` sites | 2 | 2 | 1 |
| x86 `imulq $65537` sites | 2 | 2 | 0 |

BPF helper/static-call sites in xlated output:

| call target | noop | hardcoded `map_inline` |
| --- | ---: | ---: |
| `__htab_map_lookup_elem` | 8 | 6 |
| `bpf_map_lookup_elem` | 4 | 1 |
| `bpf_map_update_elem` | 4 | 0 |
| `bpf_ktime_get_ns` | 8 | 4 |
| `bpf_xdp_adjust_head` | 4 | 4 |
| BPF-to-BPF calls | 3 | 3 |

There is no obvious bad JIT lowering from this dump: the optimized live image is smaller and has fewer helper/static-call sites. `map_inline` alone leaves the `% 65537` lowering unchanged (`divq` + `imulq $65537` appears twice in both). The extra `const_prop` + `dce` chain removes more xlated/JIT code and the final live JIT has only one visible `divq` and no visible `imulq $65537` pattern.

## Timing retest

Raw `duration_ns` from `BPF_PROG_TEST_RUN repeat=10000`:

- `noop`: 106, 107, 110, 108, 102 ns
- hardcoded `map_inline`: 141, 140, 140 ns

The slowdown is reproducible for this host bpftestrun fixture even though the optimized JIT is smaller.

## Adding `const_prop` And `dce`

Directly running `const_prop` after `map_inline` with the original verifier log fails because `map_inline` changes PCs:

```text
error: verifier state pc 2034 is not present in the control-flow graph
```

The working chain is:

1. `map_inline` with Katran hardcoded hints and overlays.
2. Host `BPF_PROG_LOAD` of the `map_inline` output with `log_level=2`.
3. Promote that `verify.log` to the next pass verifier-state input.
4. `const_prop`.
5. `dce`.
6. Final host verify, `repeat=1` semantic check, then `repeat=10000` timing.

Pass reports from the temporary host runner:

| pass | matched | applied | skipped | insn before | insn after | delta |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `map_inline` | 67 | 10 | 57 | 2542 | 2515 | -27 |
| `const_prop` | 165 | 23 | 142 | 2515 | 2515 | 0 |
| `dce` | 58 | 58 | 0 | 2515 | 2457 | -58 |

Raw bytecode call counts do not change after `const_prop` + `dce`: the final bytecode still has 87 BPF call instructions, including 66 `map_lookup_elem` helper calls and the same four `bpf_xdp_adjust_head` helper calls. The extra speed is therefore not from removing more helper calls. The visible mechanism in these artifacts is scalar/code-path simplification that the verifier and JIT lower into less machine code.

Semantic check for the chain:

- `repeat=1`: `retval=3`, `data_size_out=84`.
- Output packet is byte-for-byte equal to the current baseline/noop output for `corpus/inputs/katran_vip_packet_64.bin`.
- Outer packet is IPIP to `10.200.0.2`; inner L3 bytes match the original input.

Raw `duration_ns` from the temporary host runner, `BPF_PROG_TEST_RUN repeat=10000`:

- `map_inline` + `const_prop` + `dce`: 29, 29, 32, 31, 33 ns

The repo loader testcase now runs the same hardcoded chain and produced:

- `repeat=1`: `{"data_size_out":84,"duration_ns":1990,"repeat":1,"retval":3}`
- `repeat=10000`: `{"data_size_out":0,"duration_ns":31,"repeat":10000,"retval":0}`

This is a strong host-fixture result, but it is still not a corpus forwarding result. The caveat from the previous section remains: `repeat > 1` uses XDP live-frames test-run mode, not the full Katran corpus path with `katran_server_grpc`, netns, and `wrk`.

## No-Hint Loader Control

Running the loader CLI with `--pass map_inline` but without Katran-specific hints uses `runner/config/passes/map_inline/default.yaml`.

Observed workdirs:

- `repeat=1`: `/tmp/bpfopt-katran-mapinline-nohint-r1-1778735331685350696`
- `repeat=10000`: `/tmp/bpfopt-katran-mapinline-nohint-r10000-1778735342079247202`

Results:

| mode | sites_applied | insn delta | input/output bytecode | timing |
| --- | ---: | ---: | --- | ---: |
| no-hint `map_inline`, repeat=1 | 0 | 0 | identical | 2346 ns, `retval=3`, IPIP output |
| no-hint `map_inline`, repeat=10000 | 0 | 0 | identical | 101 ns |

Skip reasons were mostly unavailable verifier-guided keys (`56/67`), plus skipped large maps, mutable maps, and map-in-map chains. This control shows that merely running the `map_inline` pass does not cause the slowdown. The slowdown comes from the Katran hardcoded hint/overlay inlining, not from the default no-hint pass path.

## Semantic Return And Packet Bytes

Current corpus input:

```text
02000000000a02000000001c08004500003200004000400625600a0000020a6401017a691f90000000010000000050102000591d00004b415452414e56495021
```

Current `repeat=1` semantic output is identical for baseline/noop, no-hint `map_inline`, hardcoded-hint `map_inline`, and the `map_inline` + `const_prop` + `dce` chain:

```text
02000000000b02000000000a0800450000460000000040045a62ac1069780ac800024500003200004000400625600a0000020a6401017a691f90000000010000000050102000591d00004b415452414e56495021
```

Decoded:

| path | retval | data_size_out | outer | inner |
| --- | ---: | ---: | --- | --- |
| baseline/noop | 3 (`XDP_TX`) | 84 | Ethernet dst `02:00:00:00:00:0b`, src `02:00:00:00:00:0a`; IPv4 proto IPIP, src `172.16.105.120`, dst `10.200.0.2`, TTL 64 | original input L3 bytes unchanged |
| no-hint `map_inline` | 3 (`XDP_TX`) | 84 | same as baseline | same as baseline |
| hardcoded-hint `map_inline` | 3 (`XDP_TX`) | 84 | same as baseline | same as baseline |
| hardcoded `map_inline` + `const_prop` + `dce` | 3 (`XDP_TX`) | 84 | same as baseline | same as baseline |

Artifact for hardcoded-hint semantic capture:

- `docs/tmp/katran_hardcoded_map_inline_semantic_current/`

`cmp` between current baseline output and the hardcoded optimized outputs returns equal.

For the checked corpus VIP packet, the optimized output is therefore correct and packet-identical to baseline. That does not prove every hard fold is globally safe, but it rules out a visible wrong-output issue on this packet.

## Interpretation

For this host loader testcase, the `map_inline`-only slowdown is not explained by code-size growth, extra helper calls, or a failed optimized reload. The optimized program is definitely loaded, verifier/JIT output is smaller, and the semantic `repeat=1` check still returns `XDP_TX` with IPIP output.

Adding `const_prop` and `dce` changes the host-fixture result substantially: the final live JIT is smaller again (`9653` bytes), one visible `% 65537` division site disappears, semantic output remains packet-identical, and `repeat=10000` drops to roughly `29-33 ns` in the temporary runner plus `31 ns` in the repo testcase.

The main caveat is that the timing path is the live XDP test-run path, not just a tight `bpf_prog_run_xdp()` loop. With `repeat > 1`, the loader sets `BPF_F_TEST_XDP_LIVE_FRAMES`; the kernel enters `bpf_test_run_xdp_live()`, allocates/resets test frames in `xdp_test_run_batch()`, runs the BPF program, updates the frame when packet bounds changed, and turns `XDP_TX` into redirect/flush work. That timing is still useful for the loader fixture, but it is not the same as corpus app-side forwarding counters.

The current evidence says:

1. Hardcoded `map_inline` is not obviously miscompiled for the corpus VIP packet.
2. `map_inline` alone makes live JIT smaller but host live-frame bpftestrun slower.
3. `map_inline` + `const_prop` + `dce` makes live JIT smaller again and host live-frame bpftestrun much faster.
4. This fixture alone is not enough to conclude the same speedup holds for Katran corpus forwarding.
5. Any next claim needs either corpus `make corpus` raw counters for Katran or a more isolated program-only timing mode that still uses the same packet/map state.
