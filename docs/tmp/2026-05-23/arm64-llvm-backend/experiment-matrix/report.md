# ARM64 Kinsn Experiment Matrix

Date: 2026-05-23.

## Summary

Future ARM64 kinsn families should use a fixed validation matrix. A family is
not complete just because a BPF object contains a `bpf_arm64_*` symbol, and a
single benchmark smoke is not enough to support a performance claim.

The current ARM64 `REV` and `EXTR` families now have development-grade
correctness, regression coverage, and per-family performance attribution.
The performance result is still not paper-grade because it uses only 3 samples
per configuration and does not include confidence intervals.

## Required Gates

| Gate | Purpose | Required question |
|---|---|---|
| LLVM FileCheck | Compile-time selection and emission | Does the selector only fire for `-bpf-kinsn-target=arm64`? Does the AsmPrinter payload match the module decoder? |
| Object smoke | Object-level isolation | Does `all=disable` emit 0 kfuncs? Does family-only treatment emit only the expected `bpf_arm64_*` symbols and no `bpf_x86_*` symbols? |
| AWS single-benchmark correctness | Fast load/verifier/runtime check | Does the object load, does the verifier accept the proof expansion, and do `native` / `kernel` results match expected output? |
| AWS full micro correctness | Semantic coverage | Do all 29 micro benchmarks pass under `native` and `kernel` with 0 failed samples? |
| Same-LLC performance | Attribution | Is treatment faster than the same custom `llc` with `all=disable`? |
| Selected benchmark report | Coverage explanation | Which benchmarks actually selected the family? Are full-suite and selected-subset results reported separately? |
| Target regression | Target isolation | Does ARM64 treatment avoid `bpf_x86_*`, and does scoped x86 treatment avoid `bpf_arm64_*`? |
| Final consistency review | Cleanup | Were old failures, stale docs, temporary workarounds, and redundant code reviewed? |

Minimum performance configurations:

| Configuration | Compiler setup | Purpose |
|---|---|---|
| `baseline` | normal clang | Original performance baseline. |
| `control-disabled` | custom `llc`, `-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable` | Isolate custom LLVM overhead. |
| `family-only treatment` | custom `llc`, `all=disable`, target family forced | Attribute a single family. |
| `combined treatment` | custom `llc`, multiple completed families forced | Measure the combined effect. |

The main performance comparison is:

```text
family-only treatment / same-LLC control-disabled
combined treatment / same-LLC control-disabled
```

The clang baseline is useful context, but it is not a replacement for the
same-LLC control.

## Current REV / EXTR Status

| Item | `REV` | `EXTR` | `REV+EXTR` |
|---|---|---|---|
| LLVM pseudo / AsmPrinter payload | done | done | done |
| Selector | done | done | done |
| FileCheck | done | done | done |
| Object smoke | done | done | done |
| AWS single-benchmark smoke | done | done | done |
| AWS full micro correctness | done | done | done |
| Same-LLC performance | done, small sample | done, small sample | done, small sample |
| Corpus benchmark | missing | missing | missing |
| Paper-grade performance | missing | missing | missing |

Correctness summary:

| Configuration | Benchmarks | Runs | Failed samples | Objects | ARM64 REV | ARM64 EXTR | x86 |
|---|---:|---:|---:|---:|---:|---:|---:|
| `rev-only` | 29 | 58 | 0 | 29 | 2 | 0 | 0 |
| `extr-only` | 29 | 58 | 0 | 29 | 0 | 7 | 0 |
| `rev-extr` | 29 | 58 | 0 | 29 | 2 | 7 | 0 |

Combined performance summary:

| Scope | Runtime | Benchmarks | Median treatment/control | Wins `<0.98` | Losses `>1.02` | Neutral |
|---|---|---:|---:|---:|---:|---:|
| all | native | 29 | 1.000000 | 2 | 6 | 21 |
| all | kernel | 29 | 1.000000 | 5 | 3 | 21 |
| selected | native | 7 | 1.006711 | 0 | 2 | 5 |
| selected | kernel | 7 | 0.968354 | 4 | 0 | 3 |

Target regression summary:

| Case | Objects | Kfunc symbols | ARM64 symbols | x86 symbols | Status |
|---|---:|---:|---:|---:|---|
| `micro-arm64-all-disable` | 29 | 0 | 0 | 0 | completed |
| `micro-arm64-rev-extr` | 29 | 9 | 9 | 0 | completed |
| `micro-x86-scoped-kinsn` | 29 | 9 | 0 | 9 | completed |
| `micro-x86-default-kinsn` | 18 | 62 | 0 | 62 | failed, known x86 issue |

## Per-Family Attribution Result

The 2026-05-23 attribution run completed. The first baseline attempt hit an
AWS session expiry before AMI resolution; after reauthentication, the valid
baseline rerun and all three comparison runs completed. Summary:

```text
attempt              benchmarks  runs  failed_samples  status     object_count  kfunc_symbols  arm64_rev_symbols  arm64_extr_symbols  arm64_symbols  x86_symbols
baseline             29          174   0               completed  29            0              0                  0                   0              0
control-disabled     29          174   0               completed  29            0              0                  0                   0              0
treatment-rev-only   29          174   0               completed  29            2              2                  0                   2              0
treatment-extr-only  29          174   0               completed  29            7              0                  7                   7              0
```

Directional summary:

```text
treatment  scope     runtime  benchmarks  median_treatment_over_control  wins_lt_0_98  losses_gt_1_02  neutral
rev        selected  native   1           1.000000                       0             0               1
rev        selected  kernel   1           1.000000                       0             0               1
extr       selected  native   7           1.000000                       0             2               5
extr       selected  kernel   7           0.959916                       4             1               2
```

This means the current selected-kernel performance signal is primarily from
`EXTR`, not `REV`.

Full record:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-23-arm64-rev-extr-performance-attribution
```

## Next Experiment

The next implementation family may start, but it should use this matrix from
the beginning. The next family should have its own family-only correctness,
same-LLC performance, selected benchmark analysis, object symbol check, AWS cost
record, and final consistency review.

## Data Files

The summary tables used by this report are copied next to the report:

```text
data/previous-correctness-summary.tsv
data/previous-combined-perf-directional-summary.tsv
data/previous-regression-object-symbol-summary.tsv
data/run-result-summary.tsv
data/perf-directional-summary.tsv
data/perf-selected-kfunc-benchmarks.tsv
```
