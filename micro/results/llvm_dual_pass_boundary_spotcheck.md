# LLVM Dual-Pass Boundary Spot Check

- Iterations per config: `10`
- Repeat per sample: `500`
- Runtime: `llvmbpf` only
- Comparison: baseline `-O3` vs `-O3 -InstCombinePass -SimplifyCFGPass`

## Benchmark Summary

| Benchmark | Backend gap of interest | Baseline median exec_ns | Ablated median exec_ns | Exec ratio (ablated/base, mean) | Baseline size | Ablated size | Size ratio | |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| switch_dispatch | cmov/branchless lowering | 290.5 | 341.0 | 1.168x | 1294 | 1266 | 0.978x | |
| log2_fold | policy-sensitive cmov + partial wide-load coverage | 434.0 | 225.0 | 0.518x | 423 | 416 | 0.983x | |
| load_byte_recompose | byte-recompose / wide-load lowering | 110.0 | 111.0 | 1.003x | 162 | 162 | 1.000x | |
| stride_load_16 | lea fusion | 142.0 | 142.0 | 0.999x | 173 | 173 | 1.000x | |
| packet_rss_hash | rotate fusion | 29.5 | 29.0 | 0.997x | 630 | 640 | 1.016x | |
| rotate64_hash | rotate fusion | 84.5 | 66.5 | 0.811x | 1871 | 1857 | 0.993x | |

## Configuration Summary

- Geomean exec ratio (ablated/base): `0.888x`
- Geomean size ratio (ablated/base): `0.995x`
- Geomean compile ratio (ablated/base): `0.806x`

## Interpretation

- This is not a K2/Merlin reproduction. It only upper-bounds the contribution of the two LLVM passes that previously showed measurable effects on BPF programs.
- If disabling both passes leaves the representative backend-gap benchmarks largely intact, the residual gap must come from backend/native lowering rather than bytecode/IR canonicalization alone.
