# KVM x86 Micro BpfReJIT Smoke Investigation - 2026-04-28

## Summary

The requested KVM x86 micro BpfReJIT smoke could not be run on the current
`main` checkout without changing source code.  The current micro suite exposes
only the pure-JIT characterization path (`llvmbpf` vs `kernel`), and the current
driver rejects ReJIT runtimes before any VM execution can reach a
baseline -> ReJIT -> post-ReJIT sequence.

No `.rs`, `Cargo.toml`, `Makefile`, `Dockerfile`, or Python source files were
modified.

## Current Checkout

- HEAD at investigation start: `a441e221`
- Previous micro fix in history: `defad0a6`
- Report path: `docs/tmp/micro-rejit-smoke-20260428.md`

## Config And Mode Inventory

Command:

```bash
ls micro/config
```

Output:

```text
micro_pure_jit.yaml
```

The only current micro manifest is:

```text
micro/config/micro_pure_jit.yaml
```

Current manifest details from `python3 micro/driver.py --list` and
`micro.catalog.load_manifest()`:

- Benchmark count: `62`
- Runtime list: `llvmbpf`, `kernel`
- Default runtime list: `llvmbpf`, `kernel`
- Default manifest path: `micro/config/micro_pure_jit.yaml`

Relevant source anchors:

- `micro/catalog.py:12` sets `DEFAULT_MICRO_MANIFEST` to
  `micro/config/micro_pure_jit.yaml`.
- `micro/catalog.py:32-36` classifies any runtime containing `rejit` as
  `policy_mode = "rejit"`.
- `micro/driver.py:212-224` rejects any runtime whose policy mode is not
  `stock`.

Probe command:

```bash
python3 micro/driver.py --runtime kernel-rejit --samples 3 --warmups 0 --inner-repeat 10 --bench simple --output /tmp/micro-rejit-probe.json
```

Result:

```text
unknown runtime: kernel-rejit
```

Even if a temporary manifest added a `kernel-rejit` runtime, the current
`select_runtimes()` guard would reject it as non-stock.

## Makefile And Suite Entrypoints

Current root Makefile:

```make
vm-micro:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm micro
```

Current `runner.suites.micro` runtime defaults:

```python
runtimes = args.runtimes or ["llvmbpf", "kernel"]
```

`runner/libs/suite_args.py` only wires these environment overrides for the
micro suite:

- `SAMPLES`
- `WARMUPS`
- `INNER_REPEAT`
- `BENCH`

No current `vm-micro-rejit`, `vm-micro-bpfrejit`, `micro-rejit`, or
`micro-bpfrejit` target exists.  There is also no `MICRO_CONFIG`/environment
switch in the current Makefile path; `runner.suites.micro` supports a `--suite`
argument only when explicitly passed through the lower-level runner CLI.

The current C++ runner entrypoint confirms the ReJIT command surface is gone:

- `runner/src/main.cpp:10-24` accepts `list-programs`, `test-run`, and
  `run-llvmbpf` only.
- There is no current `run-rejit` or daemon-socket command in `runner/src/`.

## Historical ReJIT Entrypoint

Historical code did have a micro ReJIT path.  For example, commit `317d2c9a`
had:

```make
vm-micro-smoke: micro_exec micro-programs daemon-binary kernel-image kinsn-modules-build
	... bpfrejit-daemon --pgo serve --socket "$(DAEMON_SOCKET)" ...
	... python3 micro/driver.py --runtime kernel --runtime kernel-rejit --daemon-socket "$(DAEMON_SOCKET)" ...

vm-micro: micro_exec micro-programs daemon-binary kernel-image kinsn-modules-build
	... bpfrejit-daemon --pgo serve --socket "$(DAEMON_SOCKET)" ...
	... python3 micro/driver.py --runtime llvmbpf --runtime kernel --runtime kernel-rejit --daemon-socket "$(DAEMON_SOCKET)" ...
```

That historical driver and runner surface included `--daemon-socket`,
`kernel-rejit`, ReJIT summaries, and daemon socket optimization.  Those surfaces
are not present in the current checkout.

This matches existing checked-in review notes:

- `docs/tmp/benchmark_status_review_20260403.md` says current `vm-micro` is
  `llvmbpf` vs `kernel`, not `kernel` vs `kernel-rejit`.
- `docs/tmp/runner-cli-migration-20260428.md` says current `micro/driver.py`
  does not do live ReJIT and a future live ReJIT micro path would need a new
  runtime/driver path.
- `docs/tmp/micro-smoke-fix-20260428.md` records the latest successful
  `make vm-micro SAMPLES=3` as pure-JIT only, with `total_sites_applied = 0`.

## KVM BpfReJIT Smoke Status

Requested command shape:

```bash
make vm-micro SAMPLES=3
```

This command is not a BpfReJIT smoke in the current checkout.  It invokes only
the pure-JIT runtimes (`llvmbpf`, `kernel`), so running it again would not
exercise baseline -> ReJIT -> post-ReJIT and would necessarily report
`total_sites_applied = 0`.

The correct current lower-level ReJIT probe fails before VM execution:

```bash
python3 micro/driver.py --runtime kernel-rejit --samples 3 --warmups 0 --inner-repeat 10 --bench simple --output /tmp/micro-rejit-probe.json
```

Result:

```text
unknown runtime: kernel-rejit
```

Therefore:

- Baseline phase: not run for BpfReJIT mode.
- ReJIT phase: not reachable in current micro driver.
- Post-ReJIT phase: not reachable in current micro driver.
- Applied count: not measured; cannot be `> 0` on the current micro path.
- Failed list: one run-level blocker, `unknown runtime: kernel-rejit`.
- Daemon panic / Rust panic: none observed; no daemon was started because the
  current micro path has no daemon/ReJIT entrypoint.

## Pure-JIT Smoke Reference

Latest checked local pure-JIT KVM smoke artifact from the previous fix:

- Artifact: `micro/results/x86_kvm_micro_20260429_035938_203074/metadata.json`
- Command recorded in prior report: `make vm-micro SAMPLES=3`
- Status: `completed`
- Benchmarks: `62/62`
- Runtime names: `kernel`, `llvmbpf`
- Correctness mismatches: `0`
- Daemon debug entries: `0`
- `total_sites_applied`: `0`
- `passes_applied`: `{}`

Pure-JIT geomean for `llvmbpf_over_kernel_exec_ratio` over the 62 benchmarks:

```text
0.5918392418309552
```

This is only a pure-JIT characterization number.  There is no current ReJIT
micro artifact to compare against for the same 62 benchmarks.

## Per-Benchmark Pure-JIT Reference

`kernel_median_ns` and `llvmbpf_median_ns` are from
`micro/results/x86_kvm_micro_20260429_035938_203074/details/result.json`.
`rejit_ratio` is unavailable because the current checkout cannot run micro
ReJIT mode.

| benchmark | kernel_median_ns | llvmbpf_median_ns | pure_jit_llvmbpf_over_kernel | rejit_ratio |
|---|---:|---:|---:|---|
| simple | 71 | 41 | 0.577465 | n/a |
| simple_packet | 73 | 52 | 0.712329 | n/a |
| memory_pair_sum | 74 | 44 | 0.594595 | n/a |
| bitcount | 4651 | 5536 | 1.190282 | n/a |
| log2_fold | 395 | 311 | 0.787342 | n/a |
| dep_chain_short | 156 | 167 | 1.070513 | n/a |
| dep_chain_long | 979 | 419 | 0.427988 | n/a |
| binary_search | 731 | 319 | 0.436389 | n/a |
| branch_layout | 694 | 201 | 0.289625 | n/a |
| switch_dispatch | 782 | 588 | 0.751918 | n/a |
| branch_dense | 844 | 1240 | 1.469194 | n/a |
| cmov_select | 529 | 402 | 0.759924 | n/a |
| cmov_dense | 117 | 110 | 0.940171 | n/a |
| checksum | 17893 | 11586 | 0.647516 | n/a |
| load_word32 | 194 | 124 | 0.639175 | n/a |
| load_byte | 462 | 216 | 0.467532 | n/a |
| load_byte_recompose | 187 | 98 | 0.524064 | n/a |
| load_native_u64 | 166 | 76 | 0.457831 | n/a |
| packet_parse | 230 | 84 | 0.365217 | n/a |
| bounds_ladder | 218 | 113 | 0.518349 | n/a |
| bounds_check_heavy | 555 | 414 | 0.745946 | n/a |
| stride_load_4 | 457 | 117 | 0.256018 | n/a |
| stride_load_16 | 525 | 140 | 0.266667 | n/a |
| mixed_alu_mem | 1567 | 898 | 0.573070 | n/a |
| spill_pressure | 276 | 306 | 1.108696 | n/a |
| multi_acc_4 | 226 | 305 | 1.349558 | n/a |
| multi_acc_8 | 1032 | 478 | 0.463178 | n/a |
| fibonacci_iter | 1562 | 655 | 0.419334 | n/a |
| fibonacci_iter_packet | 1567 | 661 | 0.421825 | n/a |
| fixed_loop_small | 220 | 130 | 0.590909 | n/a |
| fixed_loop_large | 2519 | 1534 | 0.608972 | n/a |
| nested_loop_2 | 1010 | 854 | 0.845545 | n/a |
| nested_loop_3 | 1428 | 273 | 0.191176 | n/a |
| code_clone_2 | 690 | 676 | 0.979710 | n/a |
| code_clone_8 | 3051 | 2371 | 0.777122 | n/a |
| large_mixed_500 | 1628 | 783 | 0.480958 | n/a |
| large_mixed_1000 | 2553 | 1754 | 0.687035 | n/a |
| bpf_call_chain | 773 | 221 | 0.285899 | n/a |
| memcmp_prefix_64 | 254 | 87 | 0.342520 | n/a |
| packet_parse_vlans_tcpopts | 92 | 66 | 0.717391 | n/a |
| local_call_fanout | 311 | 188 | 0.604502 | n/a |
| packet_rss_hash | 54 | 67 | 1.240741 | n/a |
| imm64_storm | 373 | 190 | 0.509383 | n/a |
| alu32_64_pingpong | 888 | 209 | 0.235360 | n/a |
| branch_fanout_32 | 970 | 420 | 0.432990 | n/a |
| deep_guard_tree_8 | 225 | 75 | 0.333333 | n/a |
| mega_basic_block_2048 | 2763 | 1156 | 0.418386 | n/a |
| rotate64_hash | 180 | 113 | 0.627778 | n/a |
| packet_redundant_bounds | 342 | 92 | 0.269006 | n/a |
| const_fold_chain | 560 | 164 | 0.292857 | n/a |
| struct_field_cluster | 246 | 162 | 0.658537 | n/a |
| bitfield_extract | 510 | 417 | 0.817647 | n/a |
| smallmul_strength_reduce | 616 | 409 | 0.663961 | n/a |
| cond_select_dense | 237 | 149 | 0.628692 | n/a |
| rotate_dense | 409 | 301 | 0.735941 | n/a |
| addr_calc_stride | 355 | 122 | 0.343662 | n/a |
| extract_dense | 257 | 181 | 0.704280 | n/a |
| endian_swap_dense | 183 | 195 | 1.065574 | n/a |
| branch_flip_dense | 621 | 665 | 1.070853 | n/a |
| tc_bitcount | 3039 | 4869 | 1.602172 | n/a |
| tc_checksum | 11835 | 10834 | 0.915420 | n/a |
| cgroup_hash_chain | 255 | 315 | 1.235294 | n/a |

## Conclusion

The historical "BpfReJIT micro" smoke path existed in older code, but it is not
available in the current checkout.  The only current KVM micro entrypoint is
pure-JIT.  A BpfReJIT micro smoke with `applied > 0` requires restoring or
redesigning a live micro ReJIT runtime/driver path, which was outside this task's
constraints.
