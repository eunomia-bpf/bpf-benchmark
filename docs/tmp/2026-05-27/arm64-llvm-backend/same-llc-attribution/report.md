# 2026-05-27 ARM64 LLVM backend same-LLC attribution

## 结论

本报告是给代码仓库读者看的整理版。原始实验记录在：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-existing-abi-same-llc-attribution
```

本次实验用同一个 custom `llc` 比较：

```text
control:   -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable
treatment: control + all existing ARM64 ABI family force
```

结果是 development-grade positive combined signal：

| runtime | scope | benchmarks | geomean treatment/control | delta |
|---|---|---:|---:|---:|
| kernel | all | 34 | 0.9622314217 | -3.7768578293% |
| kernel | affected | 33 | 0.9621843369 | -3.7815663069% |
| native | all | 34 | 0.9831061409 | -1.6893859139% |
| native | affected | 33 | 0.9834447279 | -1.6555272111% |

这不是 paper-grade 结论，也不是 family-only 结论。原因是 treatment 同时打开所有已有 ABI
family，尤其 `PRFM` forced selector 命中 33 / 34 个 benchmark，会掩盖其他 family 的独立影响。

## What Was Measured

Same-LLC attribution 中的 LLC 是 LLVM 的 `llc` 编译器，不是 CPU cache。

本实验固定：

- 同一个 custom `llc` binary。
- 同一个 AWS ARM64 instance type：`t4g.small`。
- 同一套 full micro benchmark：34 个 benchmark。
- 同一套 runtime：`native kernel`。
- 同一套样本参数：`SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000`。

只改变：

```text
-bpf-kinsn-mode
```

## Coverage

Object-level coverage:

| family | affected benchmarks | symbols | calls |
|---|---:|---:|---:|
| CCMP/CMP/CSET | 3 | 4 | 7 |
| CSEL | 1 | 1 | 1 |
| EXTR | 10 | 2 | 10 |
| LDP/STP | 2 | 2 | 2 |
| LDR | 1 | 4 | 4 |
| PRFM | 33 | 1 | 33 |
| REV | 1 | 2 | 2 |
| STR | 1 | 4 | 4 |
| UBFM | 12 | 1 | 12 |

Control object 中没有 `bpf_arm64_*` 或 `bpf_x86_*`。Treatment object 中没有 `bpf_x86_*`。

`MOV` 有 forced object path，但 full micro 没有自然 `bpf_arm64_mov_x` hit；普通
`BPF_MOV64_REG` 已经由 ARM64 JIT lower 成同等 native MOV。

## Correctness

| group | benchmarks | runtime samples | bad samples | kernel |
|---|---:|---:|---:|---|
| baseline | 34 | 204 | 0 | 7.0.0-rc2+ |
| control-disabled | 34 | 204 | 0 | 7.0.0-rc2+ |
| treatment-all-existing-abi | 34 | 204 | 0 | 7.0.0-rc2+ |

## Kernel Runtime

Best affected improvements:

| benchmark | families | treatment/control |
|---|---|---:|
| `siphash_rotate64_mixer` | EXTR, PRFM | 0.66875 |
| `flow_5tuple_rss_hash` | EXTR, PRFM, UBFM | 0.78 |
| `simple` | PRFM | 0.8125 |
| `simple_packet` | PRFM | 0.8666666667 |
| `tracee_http_method_prefix_detect` | PRFM | 0.8823529412 |

Worst affected regressions:

| benchmark | families | treatment/control |
|---|---|---:|
| `payload_prefix_memcmp_scan` | EXTR, PRFM | 1.1684210526 |
| `stp_stack_pair` | LDP/STP, PRFM | 1.05 |
| `sorted_rule_binary_search` | PRFM | 1.0398344542 |
| `bpftrace_comm_key_fnv_hash` | PRFM, UBFM | 1.0392512077 |
| `tracee_syscall_name_table_lookup` | PRFM | 1.0176991150 |

## Data Files

Key copied TSV files:

```text
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/data/correctness-summary.tsv
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/data/object-family-summary.tsv
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/data/affected-benchmarks.tsv
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/data/geomean-summary.tsv
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/data/affected-kernel-ratios.tsv
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/data/ratio-summary.tsv
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/data/aws-cost-summary.tsv
```

Raw runner data remains under:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-existing-abi-same-llc-attribution/attempts
```

## AWS Cost

All three instances were `t4g.small` in `us-east-1` and ended in `terminated`.

| group | instance | wall seconds | estimated cost |
|---|---|---:|---:|
| baseline | `i-095a134ccaf52b006` | 566 | `$0.003200346` |
| control-disabled | `i-0e94c89b374318c4b` | 575 | `$0.003251235` |
| treatment-all-existing-abi | `i-028d131a6eef3b170` | 590 | `$0.003336049` |

Estimated total: `$0.009787630`.

Price source:

```text
EC2 t4g.small Linux On-Demand us-east-1: $0.0168 / hour
EBS gp3 us-east-1: $0.08 / GB-month
Root volume: 32 GB
```

Estimate excludes data transfer, tax, free tier, credits, Savings Plans, Reserved Instances, and account discounts.

## Interpretation

This run is useful for deciding whether the completed ABI set is worth deeper performance work. It shows a
positive combined signal on micro, but the next rigorous step is not to claim a broad performance win.

Next rigorous performance work:

1. Run PRFM-disabled combined treatment to separate memory-prefetch insertion from replacement-style kinsns.
2. Run family-only treatment for remaining families that do not already have clean attribution.
3. For a paper claim, rerun with paper-grade samples and corpus workloads.
