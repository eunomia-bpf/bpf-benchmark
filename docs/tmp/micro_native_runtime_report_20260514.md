# Micro Native Runtime / ReJIT Full-Pass Report - 2026-05-14

## Scope

This report covers the micro native runtime work and x86 KVM validation for:

- native C micro runtime alongside `llvmbpf`, `kernel`, and `kernel_rejit`
- default `INNER_REPEAT=1000`
- full x86 ReJIT pass sequence from `BPFREJIT_BENCH_PASSES=default`
- final machine-code size comparison using recorded JIT sizes plus native symbol/.text inspection

No framework-side aggregation or summary fields were added to result payloads. All ratios below are post-hoc analysis from raw `metadata.json` samples.

## Code Changes

- `runner/suites/micro.py`
  - Fixed the suite wrapper default runtimes from hard-coded `llvmbpf,kernel` to `native,llvmbpf,kernel`.
  - Without this, the manifest default was silently overridden before entering the VM.
- `runner/src/native_runner.cpp`
  - Changed native `code_size.native_code_bytes` from whole `.native.so` file size to the actual entry symbol size via `dladdr1(..., RTLD_DL_SYMENT)`.
  - This makes native code-size numbers comparable to `llvmbpf` compiled-code size and kernel `jited_prog_len`.
  - Failure to resolve symbol size is fail-fast.

## Validation Runs

Build and syntax checks:

```sh
python3 -m py_compile micro/catalog.py micro/driver.py runner/suites/micro.py
BPFREJIT_IMAGE_BUILD=1 make image-runner-artifacts
```

Native symbol-size smoke:

```sh
BPFREJIT_BENCH_PASSES=lea BENCH="simple" SAMPLES=1 WARMUPS=0 make micro
```

Result:

- `micro/results/x86_kvm_micro_20260514_204331_406449/metadata.json`
- `native` simple code size is now 58 B, versus `llvmbpf` 59 B, `kernel` 107 B, `kernel_rejit` 101 B.

LEA full micro correctness:

```sh
BPFREJIT_BENCH_PASSES=lea SAMPLES=1 WARMUPS=0 make micro
```

Result:

- `micro/results/x86_kvm_micro_20260514_203603_510400/metadata.json`
- 29/29 benchmarks completed.
- `native`, `llvmbpf`, `kernel`, and `kernel_rejit` all matched expected results.

Full x86 pass correctness/performance:

```sh
BPFREJIT_BENCH_PASSES=default WARMUPS=0 make micro
```

Result:

- `micro/results/x86_kvm_micro_20260514_205607_714679/metadata.json`
- `SAMPLES=3`, `INNER_REPEAT=1000`, `WARMUPS=0`
- 29/29 benchmarks completed.
- 87/87 `kernel_rejit` samples returned ReJIT status `ok`.
- No verifier error, no result mismatch.

Environment caveat from runner warnings:

- CPU governor reported as `unknown`
- turbo boost enabled
- no CPU affinity set
- PMU unavailable except software events

Use these as micro smoke/performance-direction numbers, not final publication numbers.

## Full-Pass Apply Counts

Totals across 29 benchmarks x 3 samples:

| pass | applied | matched | skipped |
|---|---:|---:|---:|
| `lea` | 552 | 552 | 0 |
| `rotate` | 492 | 492 | 0 |
| `wide_mem` | 186 | 255 | 69 |
| `dce` | 126 | 126 | 0 |
| `cond_select` | 33 | 33 | 0 |
| `extract` | 33 | 33 | 0 |
| `prefetch` | 9 | 9 | 0 |
| `ccmp` | 0 | 87 | 87 |
| `const_prop` | 0 | 567 | 567 |
| `bounds_check_merge` | 0 | 0 | 0 |
| `bulk_memory` | 0 | 0 | 0 |
| `endian_fusion` | 0 | 0 | 0 |
| `map_inline` | 0 | 0 | 0 |
| `skb_load_bytes_spec` | 0 | 0 | 0 |

Per one full suite sample, divide by 3: `lea=184`, `rotate=164`, `wide_mem=62`, `dce=42`, `cond_select=11`, `extract=11`, `prefetch=3`.

## Median Performance Summary

Ratios use median `exec_ns` per benchmark/runtime from the `SAMPLES=3` run. Ratio `< 1.0` means the left side is faster/smaller.

| comparison | exec geomean | wins/losses/ties | note |
|---|---:|---:|---|
| `kernel_rejit / kernel` | 0.933 | 14 / 8 / 7 | full-pass ReJIT is about 6.7% faster on median micro geomean |
| `kernel / native` | 2.058 | 0 / 28 / 1 | kernel JIT remains about 2.1x slower than native C entry code |
| `kernel_rejit / native` | 1.920 | 1 / 26 / 2 | ReJIT narrows but does not close native gap |
| `llvmbpf / native` | 1.180 | 8 / 14 / 7 | llvmbpf is closer to native; some cases beat native |

Compile/load-time medians:

| comparison | compile geomean |
|---|---:|
| `kernel_rejit / kernel` | 0.989 |
| `kernel / native` | 63.946 |
| `kernel_rejit / native` | 63.225 |
| `llvmbpf / native` | 272.126 |

Native `compile_ns` is `dlopen+dlsym`, so compile-time comparisons are only useful as harness cost context, not a JIT compile-time claim.

## Binary Size Summary

Recorded `native_code_bytes` uses the entry symbol size for native, llvmbpf compiled-code size for llvmbpf, and kernel `jited_prog_len` for kernel runtimes.

| comparison | code-size geomean | avg delta | wins/losses/ties |
|---|---:|---:|---:|
| `kernel_rejit / kernel` | 0.879 | -143 B | 27 / 0 / 2 |
| `kernel / native` | 2.361 | +589 B | 0 / 29 / 0 |
| `kernel_rejit / native` | 2.077 | +446 B | 0 / 28 / 1 |
| `llvmbpf / native` | 1.325 | +147 B | 3 / 23 / 3 |

Native-code-size caveat:

- Native runner records the entry symbol size.
- For benchmarks with static native subprograms, entry-symbol size undercounts all code that can execute.
- Example: `bpf_local_call_fanout_dispatch_xdp` entry is 269 B, but reachable local native symbols add up to about 752 B; the `.text` section is 971 B.
- Using full native `.text` instead of entry-symbol size gives:
  - `kernel / native_text` code-size geomean: 1.376
  - `kernel_rejit / native_text` code-size geomean: 1.210
  - `llvmbpf / native_text` code-size geomean: 0.772

The entry-symbol metric is still useful for single-entry, single-function micro cases, but `.text` is better when comparing total native binary footprint.

## Representative Cases

Median rows from `SAMPLES=3` full-pass run:

| benchmark | runtime | exec median | native code bytes | compile/load median |
|---|---|---:|---:|---:|
| `katran_lb_consistent_hash_select` | native | 12 ns | 1945 | 0.041 ms |
|  | llvmbpf | 12 ns | 1824 | 30.074 ms |
|  | kernel | 43 ns | 3463 | 0.641 ms |
|  | kernel_rejit | 29 ns | 2969 | 0.621 ms |
| `packet_record_bounds_window` | native | 64 ns | 248 | 0.044 ms |
|  | llvmbpf | 62 ns | 280 | 9.992 ms |
|  | kernel | 146 ns | 716 | 1.176 ms |
|  | kernel_rejit | 103 ns | 511 | 1.175 ms |
| `flow_5tuple_rss_hash` | native | 9 ns | 520 | 0.042 ms |
|  | llvmbpf | 13 ns | 633 | 13.205 ms |
|  | kernel | 26 ns | 1009 | 0.355 ms |
|  | kernel_rejit | 20 ns | 795 | 0.327 ms |
| `packet_toeplitz_rss_hash` | native | 245 ns | 321 | 0.043 ms |
|  | llvmbpf | 117 ns | 846 | 13.413 ms |
|  | kernel | 266 ns | 1086 | 2.108 ms |
|  | kernel_rejit | 239 ns | 1098 | 2.119 ms |
| `packet_checksum_fold` | native | 13369 ns | 170 | 0.039 ms |
|  | llvmbpf | 13332 ns | 161 | 8.300 ms |
|  | kernel | 17656 ns | 424 | 34.056 ms |
|  | kernel_rejit | 17633 ns | 340 | 34.014 ms |
| `trace_event_type_switch_dispatch` | native | 55 ns | 170 | 0.040 ms |
|  | llvmbpf | 255 ns | 1261 | 15.297 ms |
|  | kernel | 289 ns | 1621 | 30.528 ms |
|  | kernel_rejit | 296 ns | 1531 | 30.451 ms |

## What The Native Code Shows

Local native build used for inspection:

```sh
make -C micro/programs OUTPUT_DIR=/tmp/bpf-benchmark-micro-native-analysis all
llvm-nm -S --size-sort /tmp/bpf-benchmark-micro-native-analysis/*.native.so
llvm-objdump -d --no-show-raw-insn --symbolize-operands --disassemble-symbols=<symbol> <file>.native.so
```

Observed native code shapes:

- `trace_event_type_switch_dispatch_xdp`
  - Entry symbol: 170 B; `.text`: 362 B.
  - Clang lowers the dense `switch` to an indexed table load from `.rodata`.
  - BPF/ReJIT still carries a much larger branch/data-movement shape: 1621 B baseline, 1531 B after full ReJIT.
  - Missing class: switch/table reconstruction or equivalent dense dispatch lowering at BPF/ReJIT level.

- `packet_checksum_fold_xdp`
  - Entry symbol: 170 B; `.text`: 362 B.
  - Native code is still scalar, but compact: a tight nested loop with 16-bit loads/fold.
  - ReJIT shrinks kernel code 424 B -> 340 B but does not materially change runtime: 17656 ns -> 17633 ns.
  - Missing class: loop-level optimization, unrolling/vectorization, or checksum-specific recognition. Current passes are mostly local peepholes.

- `bpf_local_call_fanout_dispatch_xdp`
  - Entry symbol: 269 B; reachable local native function symbols total about 752 B; `.text`: 971 B.
  - Kernel shrinks 2173 B -> 1786 B and speeds 144 ns -> 130 ns.
  - Missing class: BPF subprogram call ABI/prologue/register-save overhead and local call inlining or interprocedural layout.

- `packet_toeplitz_rss_hash_xdp`
  - Entry symbol: 321 B; `.text`: 513 B.
  - Full ReJIT applies `cond_select` and `lea`, and improves kernel runtime 266 ns -> 239 ns, but code size slightly grows 1086 B -> 1098 B.
  - llvmbpf is much faster at 117 ns despite larger code size.
  - Missing class: loop/key-table lowering and deeper instruction scheduling/register allocation, not just bytecode peepholes.

- `katran_lb_consistent_hash_select`
  - Native/llvmbpf are both around 12 ns; kernel is 43 ns; full ReJIT gets to 29 ns.
  - Applied passes include `rotate`, `extract`, `lea`, `wide_mem`, and `dce`.
  - Missing class: more global packet hot-path cleanup after successful local transforms.

## Interpretation

The native runtime itself works: all 29 micro benchmarks execute through native, llvmbpf, kernel, and kernel_rejit with matching results.

The full x86 pass suite is also currently work-capable on micro: all 87 ReJIT samples succeeded, with no verifier rejection.

Performance is mixed but directionally positive for full-pass ReJIT:

- Code size improves strongly and consistently: 27/29 kernel_rejit programs smaller than kernel baseline.
- Runtime improves on more cases than it regresses: 14 wins, 8 losses, 7 ties by median.
- The remaining native gap is not mainly LEA anymore. The largest gaps are in codegen classes that current BPF bytecode passes do not attempt:
  - dense switch/table lowering
  - loop-level transformations
  - local-call/subprogram inlining or ABI cleanup
  - cross-instruction scheduling/register allocation
  - broader packet hot-path canonicalization after local rewrites

## TODO

- Add an analysis-side script, outside the framework result writer, that reads `metadata.json` and emits these comparisons reproducibly.
- Add an optional analysis-only native `.text` / reachable-symbol size extractor for micro `.native.so` files.
- For final-code inspection, add a controlled artifact mode that captures post-ReJIT `bpftool prog dump jited` for selected micro cases without changing benchmark result payloads.
- Investigate dense switch/table lowering first; `trace_event_type_switch_dispatch` has the largest native code-size gap and a clear lowering difference.
- Investigate checksum/loop cases separately; `packet_checksum_fold` shows size reduction without runtime movement, so peepholes are not enough there.
- Treat local-call size numbers carefully; entry-symbol size is not total executable native code for multi-function native cases.
