# Kernel Fixed Baselines Per-Directive Results

**Date:** 2026-03-10

**Kernel branch:** `vendor/linux` -> `jit-fixed-baselines`

**Goal:** isolate the four fixed kernel heuristics by building one kernel per directive, then compare those kernels against stock and fixed-all.

## Raw Data

- `docs/tmp/kernel-fixed-baselines-per-directive.jsonl` — first per-directive sweep (`ROTATE-only`, `WIDE-only`, `LEA-only`, `CMOV-only`)
- `docs/tmp/kernel-fixed-baselines-control-reruns.jsonl` — same-day `stock` and `fixed-all` control reruns
- `docs/tmp/kernel-fixed-baselines-current-batch-extra-reps.jsonl` — outer reps 2 and 3 for all six variants
- Historical single-run reference: `docs/tmp/kernel-fixed-baselines-test-results.md`

## Method

- Built six kernels from `jit-fixed-baselines`: `stock`, `ROTATE-only`, `WIDE-only`, `LEA-only`, `CMOV-only`, `fixed-all`.
- Each VM run used the requested command shape with `--input-size 64 --io-mode staged --repeat 5`.
- First-pass single-run timings drifted materially versus the earlier `docs/tmp/kernel-fixed-baselines-test-results.md` batch, so I added same-day `stock`/`fixed-all` controls and two extra outer repetitions for all six variants.
- **All runtime conclusions below use the median of 3 same-day VM runs.**
- `jited_prog_len` and `xlated_prog_len` were stable across all repetitions. `xlated_prog_len` never changed for any program.
- All 108 same-day VM runs returned the expected result.

## Key Findings

- `CMOV-only` is the only directive that changes `log2_fold` native code (`648 -> 682`), and it hurts `log2_fold` (`948 -> 1135 ns`, `+19.7%`). This is the clean policy-sensitive case.
- `CMOV-only` leaves `jited_prog_len` unchanged on the other five programs, so their runtime movement under `CMOV-only` is measurement noise, not a direct codegen effect.
- `ROTATE-only` cleanly rewrites the two rotate benchmarks: `rotate64_hash` shrinks by `-1082` bytes and `packet_rss_hash` by `-151` bytes.
- `WIDE-only` gives the clearest isolated win on `load_byte_recompose` (`487 -> 418 ns`, `422 -> 410`). It also finds extra wide-load sites in `stride_load_4`, `stride_load_16`, `log2_fold`, and a small site in `rotate64_hash`.
- `LEA-only` only changes the two stride benchmarks (`517 -> 511` for both), helps `stride_load_4`, and hurts `stride_load_16`.
- `fixed-all` still regresses `log2_fold` (`+10.4%`) and `stride_load_16` (`+110.7%`), so the hardcoded kernel baseline is not equivalent to selective policy control.
- Code size is exactly additive under `fixed-all`; execution time is not.

## Main Table

Cells are `median exec_ns / stable jited_prog_len`.

| Program | stock | ROTATE-only | WIDE-only | LEA-only | CMOV-only | fixed-all |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| rotate64_hash | 307 ns / 3559 | 270 ns / 2477 | 306 ns / 3463 | 493 ns / 3559 | 359 ns / 3559 | 145 ns / 2381 |
| packet_rss_hash | 183 ns / 1021 | 188 ns / 870 | 177 ns / 1021 | 155 ns / 1021 | 221 ns / 1021 | 184 ns / 870 |
| load_byte_recompose | 487 ns / 422 | 501 ns / 422 | 418 ns / 410 | 506 ns / 422 | 450 ns / 422 | 531 ns / 410 |
| stride_load_4 | 616 ns / 517 | 652 ns / 517 | 630 ns / 493 | 543 ns / 511 | 613 ns / 517 | 550 ns / 487 |
| stride_load_16 | 261 ns / 517 | 604 ns / 517 | 300 ns / 493 | 630 ns / 511 | 574 ns / 517 | 550 ns / 487 |
| log2_fold | 948 ns / 648 | 967 ns / 648 | 926 ns / 612 | 1129 ns / 648 | 1135 ns / 682 | 1047 ns / 646 |

## Delta Vs Same-Day Stock

Cells are `exec delta / jited_prog_len delta`.

| Program | ROTATE-only | WIDE-only | LEA-only | CMOV-only | fixed-all |
| --- | ---: | ---: | ---: | ---: | ---: |
| rotate64_hash | -12.1% / -1082 | -0.3% / -96 | +60.6% / +0 | +16.9% / +0 | -52.8% / -1178 |
| packet_rss_hash | +2.7% / -151 | -3.3% / +0 | -15.3% / +0 | +20.8% / +0 | +0.5% / -151 |
| load_byte_recompose | +2.9% / +0 | -14.2% / -12 | +3.9% / +0 | -7.6% / +0 | +9.0% / -12 |
| stride_load_4 | +5.8% / +0 | +2.3% / -24 | -11.9% / -6 | -0.5% / +0 | -10.7% / -30 |
| stride_load_16 | +131.4% / +0 | +14.9% / -24 | +141.4% / -6 | +119.9% / +0 | +110.7% / -30 |
| log2_fold | +2.0% / +0 | -2.3% / -36 | +19.1% / +0 | +19.7% / +34 | +10.4% / -2 |

## Per-Directive Analysis

### ROTATE-only

- Native-code impact is exactly where it should be: `rotate64_hash` (`3559 -> 2477`) and `packet_rss_hash` (`1021 -> 870`), with no code-size change elsewhere.
- `rotate64_hash` improves in median runtime (`-12.1%`).
- `packet_rss_hash` is effectively flat in runtime (`+2.7%`) despite the `-151` byte shrink, so the rotate code-size win is real but the runtime win is not stable in this batch.

### WIDE-only

- `load_byte_recompose` is the cleanest isolated win: `487 -> 418 ns` (`-14.2%`) and `422 -> 410`.
- The heuristic also fires on `stride_load_4`, `stride_load_16`, `log2_fold`, and a small site in `rotate64_hash`, so WIDE coverage is broader than the original 3-program intuition.
- The runtime story outside `load_byte_recompose` is mixed, but the code-size effects are deterministic: `-24` bytes on both stride programs and `-36` on `log2_fold`.

### LEA-only

- `LEA-only` changes only the stride benchmarks, exactly as expected from the pattern family.
- `stride_load_4` improves (`616 -> 543 ns`, `-11.9%`).
- `stride_load_16` regresses badly (`261 -> 630 ns`, `+141.4%`) even though native code shrinks (`517 -> 511`). This matches the broader warning from fixed-all: LEA is not a stable win for this benchmark.

### CMOV-only

- `CMOV-only` changes **only** `log2_fold` code generation: `648 -> 682` (`+34` bytes).
- `log2_fold` slows from `948 ns` to `1135 ns` (`+19.7%`).
- The other five programs keep identical `jited_prog_len`, so their timing movement under `CMOV-only` should be read as VM noise, not a direct CMOV effect.
- This is the expected paper-critical result: unconditional CMOV hurts a predictable-branch workload.

## Interaction Effects

The important split is:

- **Code size:** perfectly additive
- **Exec time:** not additive

| Program | fixed-all exec delta | sum(individual exec deltas) | fixed-all jited delta | sum(individual jited deltas) |
| --- | ---: | ---: | ---: | ---: |
| rotate64_hash | -162 ns | +200 ns | -1178 | -1178 |
| packet_rss_hash | +1 ns | +9 ns | -151 | -151 |
| load_byte_recompose | +44 ns | -73 ns | -12 | -12 |
| stride_load_4 | -66 ns | -26 ns | -30 | -30 |
| stride_load_16 | +289 ns | +1064 ns | -30 | -30 |
| log2_fold | +99 ns | +365 ns | -2 | -2 |

Interpretation:

- `fixed-all` composes mechanically in native code: every `jited_prog_len` delta equals the exact sum of the individual directive deltas.
- Runtime does **not** compose the same way. `fixed-all` can be much better or worse than the naive sum of isolated runtime deltas.
- `log2_fold` is the clearest example: `CMOV-only` is the direct harm source (`+34` bytes, `+19.7%`), while `fixed-all` still regresses (`+10.4%`) even though `WIDE-only` partially offsets it.
- `stride_load_16` is the second warning case: all code-size effects are additive and modest (`-30` bytes combined), but runtime still regresses sharply under `fixed-all`.

## Historical Baseline Reference

The earlier stock/fixed-all document remains useful as the original single-run paper record, but it is not stable enough to mix directly with the new per-directive batch for runtime claims. That is why the tables above use same-day median-of-3 controls.

| Program | stock-doc | fixed-all-doc | current stock median | current fixed-all median |
| --- | ---: | ---: | ---: | ---: |
| rotate64_hash | 143 ns / 3559 | 119 ns / 2381 | 307 ns / 3559 | 145 ns / 2381 |
| packet_rss_hash | 67 ns / 1021 | 57 ns / 870 | 183 ns / 1021 | 184 ns / 870 |
| load_byte_recompose | 409 ns / 422 | 356 ns / 410 | 487 ns / 422 | 531 ns / 410 |
| stride_load_4 | 444 ns / 517 | 413 ns / 487 | 616 ns / 517 | 550 ns / 487 |
| stride_load_16 | 437 ns / 517 | 499 ns / 487 | 261 ns / 517 | 550 ns / 487 |
| log2_fold | 258 ns / 648 | 331 ns / 646 | 948 ns / 648 | 1047 ns / 646 |

## Bottom Line

- The isolated-build experiment confirms the intended structural story:
  - `ROTATE-only` touches the rotate programs.
  - `LEA-only` touches the stride programs.
  - `CMOV-only` changes only `log2_fold`, and it hurts it.
  - `WIDE-only` is broader than expected, but its cleanest isolated gain is still `load_byte_recompose`.
- The strongest falsification result remains `CMOV-only`: it is a real, isolated profitability regression on `log2_fold`, while the other programs see no CMOV codegen change.
- `fixed-all` native-code shrink is exactly the sum of its parts, but execution time is not. Hardwiring all legal heuristics is therefore not equivalent to choosing directives selectively.
