# ARM64 CSEL performance attribution

日期：2026-05-25。

## 结论

本实验已完成。结果不是 performance win。

三组 AWS ARM64 full micro 都跑完。因为新增了 `csel_select64`，当前 suite 是 30 个
benchmark：

```text
group                  benchmarks  samples  failed_samples
baseline               30          180      0
control-disabled       30          180      0
treatment-csel-only    30          180      0
```

主性能口径是 `treatment-csel-only / control-disabled`：

```text
benchmark       runtime  control_ns  treatment_ns  treatment_over_control
csel_select64   kernel   29          31            1.0689655172413792
csel_select64   native   4           5             1.25
```

`csel_select64/kernel` 小样本下变慢，不能声称 CSEL 带来 runtime 提升。

Full suite summary：

```text
scope           runtime  benchmarks  geomean_treatment_over_control  wins_lt_0.98  losses_gt_1.02  neutral
all             kernel   30          1.002833111504977               2             3               25
all             native   30          1.0236538606421075              0             6               24
selected-csel   kernel   1           1.0689655172413792              0             1               0
selected-csel   native   1           1.25                            0             1               0
```

## 背景

ARM LLVM backend 仍输出 BPF object，只是在 LLVM BPF backend 里把特定 pattern emit 为
ARM64 kinsn request：

```text
BPF MachineInstr pattern
  -> ARM64 kinsn pseudo
  -> KINSN_SIDECAR + KINSN_CALL bpf_arm64_*
  -> verifier proof expansion
  -> ARM64 module native lowering
```

本实验只测 CSEL 第一版 selected-safe pattern：

```text
dst = (cond_reg != 0) ? true_reg : false_reg
```

## Object Coverage

```text
group                  objects  kfunc_symbol_objects  arm64_symbol_objects  x86_symbol_objects  arm64_tst_relocations  arm64_csel_ne_relocations
baseline               30       0                     0                     0                   0                      0
control-disabled       30       0                     0                     0                   0                      0
treatment-csel-only    30       1                     1                     0                   2                      2
```

## AWS 成本

```text
group                  instance_id           state       wall_seconds  total_cost_usd
baseline               i-0d1f5cede3e2a5f4f   terminated  502           0.00283346
control-disabled       i-080a8b074d1d3a6a7   terminated  475           0.00267709
treatment-csel-only    i-05466c6d6c3f53ac9   terminated  555           0.00313197
```

合计估算：`$0.00864251`。价格口径是 EC2 `t4g.small` Linux on-demand 加 gp3 root volume
usage，不含折扣、税、data transfer、free tier、credits、Savings Plans 或 Reserved Instances。

## 数据

摘要数据在：

```text
code/docs/tmp/2026-05-25/arm64-llvm-backend/csel-performance-attribution/analysis
```

完整本地实验记录在：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-csel-performance-attribution
```

## 限制

- 原始 29 个 production-like micro 仍然没有 CSEL coverage；CSEL coverage 来自 selected target
  `csel_select64`。
- 当前是 `SAMPLES=3` 的 development-grade 小样本，不是 paper-grade performance result。
- `llvmbpf` runtime 不支持 `bpf_arm64_*` extern，本实验只跑 `native kernel`。

## 下一步

CSEL combined regression 记录在：

```text
code/docs/tmp/2026-05-25/arm64-llvm-backend/rev-extr-ubfm-ldr-csel-combined-regression/report.md
```
