# 2026-05-27 ARM64 LLVM backend PRFM-disabled combined attribution

## 结论

本报告是给代码仓库读者看的整理版。原始实验记录在：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-prfm-disabled-combined-attribution
```

本实验复用 same-LLC 方法。这里的 LLC 是 LLVM 的 `llc` compiler，不是 CPU cache。

Control：

```text
-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable
```

Treatment：

```text
control + unary=force,rotate=force,bextr=force,direct-load=force,direct-store=force,pair-mem=force,mov=force,ccmp=force,cmov=force
```

Treatment 故意不包含：

```text
prefetch=force
```

目的：排除 `PRFM` 后，判断当前已有 ARM64 kinsn ABI 的其它 family 是否仍有 combined
performance signal。

主结果：

| runtime | scope | benchmarks | geomean treatment/control | delta |
|---|---|---:|---:|---:|
| kernel | all | 34 | 0.968236086 | -3.176391% |
| kernel | affected | 21 | 0.953473712 | -4.652629% |
| kernel | unaffected | 13 | 0.992567348 | -0.743265% |
| native | all | 34 | 0.979571493 | -2.042851% |
| native | affected | 21 | 0.976769097 | -2.323090% |
| native | unaffected | 13 | 0.984115435 | -1.588457% |

结论：排除 `PRFM` 后，kernel affected set 仍有正向 combined signal。但 native runtime
同向漂移约 2%，所以这仍是 development-grade attribution，不能作为精确 speedup claim。
下一步需要 family-only treatment。

## Correctness

| group | runtime | benchmarks | samples | bad samples | status |
|---|---|---:|---:|---:|---|
| control-disabled | kernel | 34 | 102 | 0 | pass |
| control-disabled | native | 34 | 102 | 0 | pass |
| treatment-prfm-disabled | kernel | 34 | 102 | 0 | pass |
| treatment-prfm-disabled | native | 34 | 102 | 0 | pass |

## Coverage

Treatment object coverage:

| family | unique kfuncs | symbol refs | objects |
|---|---:|---:|---:|
| REV | 2 | 2 | 1 |
| EXTR | 2 | 10 | 10 |
| UBFM | 1 | 12 | 12 |
| LDR | 4 | 4 | 1 |
| STR | 4 | 4 | 1 |
| LDP/STP | 2 | 2 | 2 |
| CSEL | 1 | 1 | 1 |
| CCMP/CMP/CSET | 4 | 7 | 3 |
| PRFM | 0 | 0 | 0 |
| MOV | 0 | 0 | 0 |

`PRFM` coverage 为 0，是本实验成立的关键检查。

## Data Files

Copied analysis files:

```text
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/prfm-disabled-combined/data/correctness-summary.tsv
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/prfm-disabled-combined/data/object-family-summary.tsv
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/prfm-disabled-combined/data/affected-benchmarks.tsv
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/prfm-disabled-combined/data/geomean-summary.tsv
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/prfm-disabled-combined/data/ratio-summary.tsv
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/prfm-disabled-combined/data/kernel-ratio-ranked.tsv
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/prfm-disabled-combined/data/aws-cost-summary.tsv
```

Raw runner data remains under:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-prfm-disabled-combined-attribution/attempts
```

## AWS Cost

Both instances were `t4g.small` in `us-east-1` and ended in `terminated`.

| group | instance | wall seconds | estimated cost |
|---|---|---:|---:|
| control-disabled | `i-0331e6bd077d8dbae` | 517 | `$0.002923284` |
| treatment-prfm-disabled | `i-0bf00796cb9ce8696` | 571 | `$0.003228617` |

Estimated total: `$0.006151901`.

Price source:

```text
EC2 t4g.small Linux On-Demand us-east-1: $0.0168 / hour
EBS gp3 us-east-1: $0.08 / GB-month
Root volume: 32 GB
```

Estimate excludes data transfer, tax, free tier, credits, Savings Plans, Reserved Instances, and account discounts.

## Interpretation

This experiment answers one narrow question: the previous combined signal was not solely a `PRFM`
artifact. It does not prove each non-PRFM family is independently profitable.

Next rigorous performance work:

1. Run family-only same-LLC attribution for `EXTR`, `UBFM`, `LDR/STR`, `LDP/STP`,
   `CSEL`, and `CCMP/CMP/CSET`.
2. Use the same `all=disable` control and report native drift for each family.
3. Only after family-only attribution should default selector policy be reconsidered.
