# 2026-05-27 ARM64 LLVM backend 大报告

## 结论

这是给代码仓库读者看的当前 ARM64 LLVM backend 总报告。它替代之前散落在
`/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-22` 到
`/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27` 下面的 ARM64 backend 临时报告。

原始实验记录仍保存在：

```text
/home/ruoji/github/bpf-opt/experiments
```

本目录只保存整理后的公开报告，不作为 raw data 的唯一来源。

总体目标：在 LLVM BPF backend 中实现 ARM64 kinsn-aware lowering path。LLVM 仍输出 BPF
object；在可证明安全的 BPF MachineInstr pattern 上，LLVM emit
`KINSN_SIDECAR + KINSN_CALL bpf_arm64_*`，由 verifier 检查 proof expansion，再由 ARM64
kinsn module lower 成 native AArch64 instruction。

当前总体状态：已有 module ABI 的 25 个 `bpf_arm64_*` target 已全部补齐 LLVM implementation，
并通过 development-grade full micro correctness 和 combined same-LLC attribution。最终 AWS
ARM64 full micro correctness 结果是 34/34 benchmark、68 个 runtime sample、0 个 bad sample。
combined same-LLC attribution 的 affected kernel geomean treatment/control 是 `0.9621843369`，
约 `3.78%` faster，但由于 `PRFM` forced selector 命中 33/34 个 benchmark，这只能作为
combined signal，不能替代 family-only 结论。`REV`、`EXTR`、`UBFM`、`LDR` selected-safe
subset、`LDP/STP` stack-only subset、`CSEL` selected target、`CCMP/CMP/CSET` selected-safe
subset 已达到 micro 级开发闭环。`LDRB`、direct `STR`、`PRFM`、`MOV` 作为 forced ABI coverage
已通过 correctness，但不进入默认策略。

## Family 总清单

| Family | kfunc count | targets | 当前状态 |
|---|---:|---|---|
| `REV` | 3 | `rev16_w`, `rev_w`, `rev_x` | development-complete on micro；corpus / paper-grade 未做。 |
| `EXTR` | 2 | `extr_w`, `extr_x` | development-complete on micro；selected kernel 改善主要来自这里。 |
| `UBFM` | 1 | `ubfm_x` | development-complete on micro；小样本 selected kernel 轻微改善。 |
| `LDR` | 4 | `ldrb`, `ldrh`, `ldr_w`, `ldr_x` | correctness-complete on micro；`ldrh` / `ldr_w` / `ldr_x` selected-safe subset complete，`ldrb` forced ABI coverage complete。 |
| `STR` | 4 | `strb`, `strh`, `str_w`, `str_x` | correctness-complete on micro；forced direct-store ABI coverage complete；store-widening 不做。 |
| `LDP/STP` | 2 | `ldp_x`, `stp_x` | stack-only subset development-complete on micro。 |
| `CSEL` | 2 | `tst`, `csel_ne` | selected target complete；当前不是 performance win。 |
| `CCMP/CMP/CSET` | 5 | `cmp_x`, `cmp_w`, `ccmp_x`, `ccmp_w`, `cset_x_cond` | selected-safe subset complete；当前不是 performance win。 |
| `PRFM` | 1 | `prfm_pldl1keep` | pass-level evidence complete；forced object path 已补齐，但不进默认策略。 |
| `MOV` | 1 | `mov_x` | forced object path 已补齐；普通 BPF `MOV64_REG` 已经生成同一 native MOV，micro 无自然命中。 |

## Same-LLC Combined Attribution

已有 ABI 全部补齐后，已补一次 full-suite same-LLC combined attribution：

```text
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/report.md
```

主结果：

| runtime | scope | benchmarks | geomean treatment/control | delta |
|---|---|---:|---:|---:|
| kernel | all | 34 | 0.9622314217 | -3.7768578293% |
| kernel | affected | 33 | 0.9621843369 | -3.7815663069% |
| native | all | 34 | 0.9831061409 | -1.6893859139% |
| native | affected | 33 | 0.9834447279 | -1.6555272111% |

限制：这是 all-existing-ABI combined treatment，不是 family-only treatment。`PRFM` forced
selector 命中 33/34 个 benchmark，因此该结果不能说明单个 family 的独立收益。

## Family 报告

每个 family 的公开整理报告都放在本目录的子目录里：

```text
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/families/rev/report.md
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/families/extr/report.md
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/families/ubfm/report.md
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/families/ldr/report.md
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/families/str/report.md
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/families/ldp-stp/report.md
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/families/csel/report.md
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/families/ccmp-cmp-cset/report.md
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/families/prfm/report.md
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/families/mov/report.md
```

## 完成标准

一个 family 只有通过下面 gate，才可以标为 development-complete on micro：

| Gate | 目的 |
|---|---|
| ABI/design | 读清 `/home/ruoji/github/bpf-opt/code/module/arm64` decoder，明确 payload、proof、native lowering 限制。 |
| LLVM implementation | 在 LLVM BPF backend 中实现 pseudo、AsmPrinter payload packing、selector 和 FileCheck。 |
| Object smoke | 证明 `all=disable` 是 0 kfunc，family-only treatment 只出现目标 `bpf_arm64_*`，没有 `bpf_x86_*`。 |
| AWS correctness | 证明 object 能 load，verifier 接受，`native` / `kernel` result 正确。 |
| Same-LLC performance attribution | 用同一个 custom `llc` 的 `all=disable` 作为 control，比较 family-only treatment。 |
| Combined regression | 和已完成 family 一起跑，证明不破坏旧 selector，也不破坏 target isolation。 |
| 收尾复查 | 回看旧失败、旧报告、旧文档和临时代码；只改文档时不需要重跑实验。 |

## 当前证据摘要

| Family | object / correctness | performance attribution | combined regression |
|---|---|---|---|
| `REV` | 29 micro object；AWS full micro 0 failed sample | `REV-only` selected neutral | covered by REV+EXTR and later combined runs |
| `EXTR` | 29 micro object；AWS full micro 0 failed sample | selected kernel median `0.959916` in `EXTR-only` attribution | covered by REV+EXTR and later combined runs |
| `UBFM` | 29 object；AWS full micro 0 failed sample | selected kernel median `0.996766` | `REV+EXTR+UBFM` combined passed |
| `LDR` | `LDR_X` / `LDRH` / `LDR_W` object and AWS correctness passed；`LDRB` forced ABI coverage passed final full micro | `LDR_X` runtime neutral；`LDRH/LDR_W` selected kernel geomean `0.968229`；`LDRB` not a default performance target | LDR combined regressions and final full micro passed |
| `STR` | forced direct-store ABI coverage passed final full micro | direct store not a default performance target; store-widening deferred | final full micro passed |
| `LDP/STP` | `STP_X` and `LDP_X` selected correctness passed | `STP_X` selected kernel `0.909091`；`LDP_X` runtime neutral but native bytes 352 -> 344 | both full micro combined regressions passed |
| `CSEL` | selected `csel_select64` correctness passed | `csel_select64/kernel` treatment/control `1.06897` | combined regression passed |
| `CCMP/CMP/CSET` | 31 benchmark full micro correctness, 0 failed sample | affected kernel geomean `1.0` | combined regression passed |
| `PRFM` | pass-level PRFM emits 44 sites on `katran`; native `prfm` evidence captured；forced object path passed local smoke | expanded attribution not win | default policy disabled |
| `MOV` | forced object path passed FileCheck; no natural micro hit | selector would not reduce native instruction | default policy disabled |

## 原始实验索引

权威 raw report 和数据目录仍在 `experiments/`。关键目录如下：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-22-arm64-phase5-correctness-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-22-arm64-phase6-performance
/home/ruoji/github/bpf-opt/experiments/2026-05-22-arm64-phase7-regression
/home/ruoji/github/bpf-opt/experiments/2026-05-23-arm64-rev-extr-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-ubfm-llvm-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-ubfm-aws-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-ubfm-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-rev-extr-ubfm-combined-regression
/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-ldr-llvm-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-ldr-aws-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-llvm-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-aws-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-csel-coverage-correctness-gate
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-csel-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-local-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-aws-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-full-micro-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-stp-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-stp-aws-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-stp-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-stp-full-micro-combined-regression
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ldp-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ldp-aws-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ldp-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ldp-full-micro-combined-regression
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-prefetch-coverage-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-control-codegen-evidence
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-native-jit-dump-fix
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-expanded-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-existing-abi-completion
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-existing-abi-same-llc-attribution
```

Final existing ABI completion summary:

```text
benchmarks   34
samples      68
bad_samples 0
status      completed
```

Existing ABI combined same-LLC attribution summary:

```text
benchmarks per group 34
runtime samples per group 204
bad samples 0
affected benchmarks 33
affected kernel geomean treatment/control 0.9621843369
estimated AWS cost $0.009787630
```

## 清理规则

本次整理只删除过时的公开 report 副本，不删除 `experiments/` 原始实验目录。删除范围限定在：

```text
/home/ruoji/github/bpf-opt/code/docs/tmp/YYYY-MM-DD/arm64-llvm-backend
```

原因：这些目录是给他人看的临时报告副本，已经被本报告和 `families/` 子报告替代；raw data
仍可从 `experiments/` 查到。

## 收尾一致性复查

本次整理回看了：

- `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/guide.md`
- `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/implementation-plan.md`
- `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/experiment-matrix.md`
- family design 文档：`UBFM`、`LDR/STR`、`LDP/STP`、`CSEL`、`CCMP/CMP/CSET`、`PRFM`、`MOV`
- `experiments/` 下 ARM64 family 相关 report 中指向旧公开 report 副本的路径
- `code/docs/tmp` 下旧的 ARM64 backend 公开报告副本

发现和处理：

- 旧公开报告按日期和实验散落，读者需要知道 phase / chat context 才能读懂。已合并成当前
  总报告和每个 family 的子报告。
- 顶层 docs 里仍有多个旧公开 report 路径。已替换为当前总报告或 family 报告。
- `experiments/` 的历史 report 中有指向旧公开副本的路径。已统一替换为当前总报告入口；
  原始 raw data 仍保留在各自 `experiments/` 目录。
- 已删除旧 `code/docs/tmp/YYYY-MM-DD/arm64-llvm-backend` 公开副本，只保留当前
  `2026-05-27/arm64-llvm-backend`。

是否重跑实验：没有重跑。原因是本次只整理文档和公开报告，没有修改 LLVM、module、runner、
Makefile 或 benchmark framework 行为。

## 后续

短期下一步不是继续盲目加 family，而是决定交付口径：

1. 如果目标是 development branch，当前可以整理 commit / push。
2. 如果目标是论文级性能结论，需要选定 corpus / paper-grade benchmark，并用
   baseline、same-LLC control、family-only treatment、combined treatment 跑足样本。
3. 如果目标是继续扩展 selector，应先明确是否新增 kernel module ABI；当前已有 ABI 已全部覆盖。
