# ARM64 REV+EXTR+UBFM+LDR+CSEL combined regression

日期：2026-05-25。

## 结论

本 combined regression 已完成并通过。

结果：

- ARM64 `all=disable` control：30 个 object，0 个 kfunc extern。
- ARM64 combined treatment：30 个 object，27 个 object 命中 `bpf_arm64_*`，0 个
  `bpf_x86_*`。
- CSEL 覆盖来自 `csel_select64`：`bpf_arm64_tst` 和 `bpf_arm64_csel_ne` relocation 各 2 个。
- x86 scoped treatment：30 个 object，25 个 object 命中 `bpf_x86_*`，0 个
  `bpf_arm64_*`。
- AWS ARM64 correctness：30 个 benchmark，`native/kernel` 共 60 个 sample，0 failure。

这个实验不测性能；CSEL performance attribution 的结论是当前 selected target 上不是 win。

## Object Isolation

```text
case                 objects  kfunc_symbol_objects  arm64_symbol_objects  x86_symbol_objects  arm64_tst_relocations  arm64_csel_ne_relocations
arm64-all-disable    30       0                     0                     0                   0                      0
arm64-combined       30       27                    27                    0                   2                      2
x86-scoped           30       25                    0                     25                  0                      0
```

ARM64 combined relocation coverage：

```text
kfunc                 object_count  relocations
bpf_arm64_csel_ne     1             2
bpf_arm64_extr_w      4             40
bpf_arm64_extr_x      4             120
bpf_arm64_ldr_w       21            43
bpf_arm64_ldr_x       2             12
bpf_arm64_ldrh        4             11
bpf_arm64_rev16_w     1             2
bpf_arm64_rev_w       1             2
bpf_arm64_tst         1             2
bpf_arm64_ubfm_x      12            38
```

## AWS Correctness

```text
attempt          result_dir                            status     benchmarks  runtimes       samples  failed_samples
aws-full-micro   aws_arm64_micro_20260526_024018_987733 completed  30          kernel,native  60       0
```

AWS instance：

```text
instance_id          instance_type  state       wall_seconds  total_cost_usd
i-08c63e9efa27f662a t4g.small      terminated  317           0.00178616
```

## 数据

摘要数据在：

```text
code/docs/tmp/2026-05-25/arm64-llvm-backend/rev-extr-ubfm-ldr-csel-combined-regression/analysis
```

完整本地实验记录在：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-rev-extr-ubfm-ldr-csel-combined-regression
```

## 限制

- 这不是 performance run。
- x86 default broad policy 的已知 crash 不作为本实验 gate；这里使用 scoped x86 flags 只检查
  target isolation。
- `llvmbpf` runtime 不支持 `bpf_arm64_*` extern，本实验只跑 `native kernel`。

## 下一步

CSEL 第一版 selected-safe subset 已完成 correctness/performance/regression 闭环，但当前不是
performance win，且原始 29 个 micro 仍无覆盖。下一步应进入 `CCMP/CMP/CSET` design，或者先
设计 CSEL v2 的 ABI / selector 扩展。
