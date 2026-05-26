# 2026-05-26 arm64-ccmp-performance-attribution

## 结论

本实验完成，状态是 `completed_with_cleanup_rerun`。

本次跑了三组 AWS ARM64 full micro。当前 full suite 是 31 个 benchmark：原始 micro
集合加上 selected targets `csel_select64` 和 `ccmp_all_nonzero`。

| group | 编译配置 | benchmarks | runtime samples | failed samples |
|---|---|---:|---:|---:|
| `baseline` | 普通 clang | 31 | 186 | 0 |
| `control-disabled` | custom `llc` + `-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable` | 31 | 186 | 0 |
| `treatment-ccmp-only` | custom `llc` + `all=disable` + `ccmp=force` | 31 | 186 | 0 |

主要结论：

- object coverage 符合预期：baseline/control 都 0 kfunc；CCMP treatment 有 2 个 object
  命中 `bpf_arm64_*`，0 个 `bpf_x86_*`。
- treatment 命中的 benchmark 是 `ccmp_all_nonzero` 和
  `cilium_socket_lb_service_select`。
- CCMP treatment 共 8 个 ARM64 relocation：
  `bpf_arm64_cmp_w` 2 个、`bpf_arm64_ccmp_w` 4 个、
  `bpf_arm64_cset_x_cond` 2 个；当前没有命中 X variant。
- same-LLC 主口径是 `treatment-ccmp-only / control-disabled`。
- selected target `ccmp_all_nonzero/kernel` median 是 control `17 ns`、treatment
  `17 ns`，`treatment/control = 1.0`，不是 performance win。
- affected-CCMP subset 的 kernel geomean 是 `1.0`，native geomean 是 `0.998484`，
  都是中性。
- full 31 suite 的 kernel geomean 是 `1.010064`，native geomean 是 `1.00086`。
  这不是 CCMP 自身收益；主要结论仍按 affected subset 和 selected target 判断。
- `ccmp_all_nonzero` 的 kernel native code compare 能看到 `cmp` / `ccmp` / `cset`
  lowering。
- control run 的 benchmark 数据已经同步成功，但 wrapper 在结束后的 AWS
  `DescribeInstances` 阶段遇到 `RequestExpired`，exit code 为 2。随后重新登录并执行
  terminate cleanup，最终三个 instance 都是 `terminated`。
- 三个 AWS instance 估算总费用约 `$0.00805741`。

这仍是 development-grade 小样本结果，不是 paper-grade performance result。它可以说明第一版
`CCMP/CMP/CSET` path 正确、可归因，但当前 selected target 和 affected subset 上没有 runtime
收益。

## 总体进度

总体目标：实现 ARM64 LLVM kinsn backend。LLVM 仍然输出 BPF object，只是在 LLVM BPF
backend 里把合适的 BPF MachineInstr pattern 改写成 ARM64 kinsn pseudo，再由
`KINSN_SIDECAR + KINSN_CALL bpf_arm64_*` 交给 verifier 和 ARM64 module lower 成 native
AArch64 指令。

Family 总清单：

| Family | kfunc count | 当前状态 |
|---|---:|---|
| `REV` | 3 | development-complete on micro |
| `EXTR` | 2 | development-complete on micro |
| `UBFM` | 1 | development-complete on micro |
| `LDR` | 4 | partial；`LDR_X`、`LDRH`、`LDR_W` selected-safe subset development-complete on micro；`LDRB` normal selector deferred |
| `STR` | 4 | design-complete；selector deferred |
| `LDP/STP` | 2 | not started |
| `CSEL` | 2 | selected correctness/performance/regression 完成；当前不是 performance win |
| `CCMP/CMP/CSET` | 5 | development-complete on micro；当前不是 performance win |
| `PRFM` | 1 | not started |
| `MOV` | 1 | not started |

单个 family 的完整 gate：

1. 读 module ABI 和 payload decoder。
2. 在 LLVM BPF backend 里实现 pseudo、AsmPrinter payload、selector、FileCheck。
3. 做 object smoke 和 target isolation。
4. 做 AWS runtime correctness。
5. 做 same-LLC performance attribution。
6. 做 combined regression 和文档 / 实验收尾。

本实验完成 `CCMP/CMP/CSET` family 的第 5 步 same-LLC performance attribution。下一步是
第 6 步 combined regression。

## 实验问题

本实验回答：

1. `CCMP/CMP/CSET` family-only treatment 是否相对 same-LLC `all=disable` control 有
   runtime 改善。
2. 哪些 micro benchmark 实际命中 `bpf_arm64_cmp_w` /
   `bpf_arm64_ccmp_w` / `bpf_arm64_cset_x_cond`。
3. `ccmp=force` treatment 是否保持 full micro correctness。
4. treatment 是否只 emit `bpf_arm64_*`，没有 `bpf_x86_*` target leakage。

本实验不回答：

- corpus benchmark。
- paper-grade confidence interval。
- 64-bit X variant 的性能。当前自然命中的是 W variant。
- mixed condition、OR chain、nonzero immediate、arbitrary compare。

## 命令

所有 benchmark 都通过 AWS wrapper / Makefile 入口执行，没有直接调用底层 Python runner。

Preflight：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/check.sh arm64
ninja -C /home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4
```

Object smoke：

```bash
cd /home/ruoji/github/bpf-opt
make -C /home/ruoji/github/bpf-opt/code/micro/programs \
  OUTPUT_DIR=/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-performance-attribution/data/object-programs-baseline \
  KERNEL_OFFSETS_INPUT=/home/ruoji/github/bpf-opt/code/micro/programs/build-arm64/kernel_offsets.h \
  all

make -C /home/ruoji/github/bpf-opt/code/micro/programs \
  OUTPUT_DIR=/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-performance-attribution/data/object-programs-control-disabled \
  KERNEL_OFFSETS_INPUT=/home/ruoji/github/bpf-opt/code/micro/programs/build-arm64/kernel_offsets.h \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable" \
  all

make -C /home/ruoji/github/bpf-opt/code/micro/programs \
  OUTPUT_DIR=/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-performance-attribution/data/object-programs-treatment-ccmp-only \
  KERNEL_OFFSETS_INPUT=/home/ruoji/github/bpf-opt/code/micro/programs/build-arm64/kernel_offsets.h \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=ccmp=force" \
  all
```

AWS baseline：

```bash
cd /home/ruoji/github/bpf-opt
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu \
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUNTIMES="native kernel" \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

AWS control：

```bash
cd /home/ruoji/github/bpf-opt
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu \
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable" \
  RUNTIMES="native kernel" \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

AWS treatment：

```bash
cd /home/ruoji/github/bpf-opt
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu \
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=ccmp=force" \
  RUNTIMES="native kernel" \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

Cleanup after control wrapper expired during final AWS describe:

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 terminate
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- LLVM submodule：`/home/ruoji/github/bpf-opt/code/llvm-backend/llvm`
- custom `llc`：`/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc`
- platform / arch：AWS / ARM64
- instance type：`t4g.small`
- region：`us-east-1`
- remote user：`ec2-user`
- kernel：`7.0.0-rc2+`
- container image：`bpf-benchmark/runner-runtime:arm64`
- root volume：32 GiB gp3
- runtimes：`native kernel`

## 文件改动

本实验没有修改 LLVM、runner、module 或 benchmark framework code。

本实验依赖前序 CCMP 相关改动：

- `/home/ruoji/github/bpf-opt/code/llvm-backend/llvm/llvm/lib/Target/BPF/BPF.h`
- `/home/ruoji/github/bpf-opt/code/llvm-backend/llvm/llvm/lib/Target/BPF/BPFInstrInfo.td`
- `/home/ruoji/github/bpf-opt/code/llvm-backend/llvm/llvm/lib/Target/BPF/BPFAsmPrinter.h`
- `/home/ruoji/github/bpf-opt/code/llvm-backend/llvm/llvm/lib/Target/BPF/BPFAsmPrinter.cpp`
- `/home/ruoji/github/bpf-opt/code/llvm-backend/llvm/llvm/lib/Target/BPF/BPFKinsnSelect.cpp`
- `/home/ruoji/github/bpf-opt/code/micro/programs/ccmp_all_nonzero.bpf.c`
- `/home/ruoji/github/bpf-opt/code/micro/programs/ccmp_all_nonzero.md`
- `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- `/home/ruoji/github/bpf-opt/code/runner/libs/input_specs.yaml`

本次新增 / 更新实验记录和文档：

- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-performance-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-performance-attribution/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-performance-attribution/analysis/*.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-performance-attribution/attempts/*/data/`
- `/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-26/arm64-llvm-backend/ccmp-performance-attribution/report.md`
- `/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-26/arm64-llvm-backend/ccmp-performance-attribution/analysis/*`
- `/home/ruoji/github/bpf-opt/docs/arm64-ccmp-cmp-cset-family-design.md`
- `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend-implementation-plan.md`
- `/home/ruoji/github/bpf-opt/docs/arm64-kinsn-experiment-matrix.md`
- `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend-guide.md`

## 数据文件

- `data/run-contract.json`
- `data/aws-check.log`
- `data/aws-check.stderr.log`
- `data/ninja-build.log`
- `data/object-programs-*`
- `data/object-*.log`
- `data/aws-instances.json`
- `data/aws-pricing-ec2-t4g-small.raw.json`
- `data/aws-pricing-ebs-gp3.raw.json`
- `attempts/baseline/data/run.stdout.log`
- `attempts/baseline/data/run.stderr.log`
- `attempts/baseline/data/aws_arm64_micro_20260526_082413_267034`
- `attempts/control-disabled/data/run.stdout.log`
- `attempts/control-disabled/data/run.stderr.log`
- `attempts/control-disabled/data/cleanup.stdout.log`
- `attempts/control-disabled/data/cleanup.stderr.log`
- `attempts/control-disabled/data/aws_arm64_micro_20260526_083406_399615`
- `attempts/treatment-ccmp-only/data/run.stdout.log`
- `attempts/treatment-ccmp-only/data/run.stderr.log`
- `attempts/treatment-ccmp-only/data/aws_arm64_micro_20260526_084913_117561`
- `analysis/object-symbol-summary.tsv`
- `analysis/run-result-summary.tsv`
- `analysis/sample-summary.tsv`
- `analysis/median-summary.tsv`
- `analysis/ratio-summary.tsv`
- `analysis/affected-ccmp-ratio-summary.tsv`
- `analysis/aggregate-summary.tsv`
- `analysis/aws-cost-summary.tsv`
- `analysis/aws-cost-total.txt`

## 问题和处理

- performance run 没有启用 `llvmbpf` runtime，因为当前 userspace `llvmbpf` 不支持
  `bpf_arm64_*` extern；本实验显式使用 `RUNTIMES="native kernel"`。
- control run 的 benchmark 结果目录已经同步成功，但 wrapper 在结束后的 AWS
  `DescribeInstances` 阶段遇到 `RequestExpired`，exit code 为 2。该问题不是 benchmark
  correctness 失败。
- 处理方式：重新 `aws login` 后执行
  `/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 terminate`，cleanup exit code 为 0；
  后续 `data/aws-instances.json` 确认三个 instance 都是 `terminated`。
- treatment 的 native runtime 差异不代表 CCMP native lowering，因为 native runtime 不执行
  kernel kinsn path；主观察口径是 kernel runtime。

## 结果

Object summary：

```text
group                 objects  kfunc_symbol_objects  arm64_symbol_objects  x86_symbol_objects  arm64_relocations  x86_relocations  bpf_arm64_cmp_w_relocations  bpf_arm64_ccmp_w_relocations  bpf_arm64_cset_x_cond_relocations  hit_benchmarks
baseline              31       0                     0                     0                   0                  0                0                            0                             0                                  -
control-disabled      31       0                     0                     0                   0                  0                0                            0                             0                                  -
treatment-ccmp-only   31       2                     2                     0                   8                  0                2                            4                             2                                  ccmp_all_nonzero,cilium_socket_lb_service_select
```

Run result summary：

```text
group                 result_dir                            status     benchmarks  runtimes       samples  failed_samples
baseline              aws_arm64_micro_20260526_082413_267034 completed  31          kernel,native  186      0
control-disabled      aws_arm64_micro_20260526_083406_399615 completed  31          kernel,native  186      0
treatment-ccmp-only   aws_arm64_micro_20260526_084913_117561 completed  31          kernel,native  186      0
```

Affected CCMP ratio：

```text
benchmark                       runtime  control_ns  treatment_ns  treatment_over_control  control_bpf_bytes  treatment_bpf_bytes  control_native_bytes  treatment_native_bytes
ccmp_all_nonzero                kernel   17          17            1.0                     320                376                  248                   256
ccmp_all_nonzero                native   5           5             1.0                     0                  0                    100                   100
cilium_socket_lb_service_select kernel   1049        1049          1.0                     1872               1912                 1112                  1120
cilium_socket_lb_service_select native   330         329           0.996969696969697       0                  0                    348                   348
```

Aggregate treatment/control summary：

```text
scope                 runtime  benchmarks  geomean_treatment_over_control  wins_lt_0.98  losses_gt_1.02  neutral
all                   kernel   31          1.0100635890268639              1             5               25
all                   native   31          1.0008600010473123              0             1               30
affected-ccmp         kernel   2           1.0                             0             0               2
affected-ccmp         native   2           0.9984836989003361              0             0               2
selected-ccmp-target  kernel   1           1.0                             0             0               1
selected-ccmp-target  native   1           1.0                             0             0               1
```

Native lowering evidence：

```text
ccmp_all_nonzero:
cmp  w2, #0x0
ccmp w7, #0x0, #0x4, ne
ccmp w4, #0x0, #0x4, ne
ccmp w3, #0x0, #0x4, ne
cset x1, ne

cilium_socket_lb_service_select:
ccmp w19, #0x0, #0x4, ne
cset x20, ne
```

结论：`CCMP/CMP/CSET` family-only treatment 在当前 micro suite 上 correctness 通过，但
selected target 和 affected subset 都没有 runtime win。

## AWS 时间和费用

```text
group                 instance_id           instance_type  state       launch_time_utc            end_time_utc               wall_seconds  compute_usd  ebs_usd     total_usd
baseline              i-0e4d362a7e76883e1   t4g.small      terminated  2026-05-26T08:18:01+00:00  2026-05-26T08:24:13+00:00  372           0.00173600  0.00036741  0.00210341
control-disabled      i-000efc17c8f4e994b   t4g.small      terminated  2026-05-26T08:28:54+00:00  2026-05-26T08:40:00+00:00  666           0.00310800  0.00065778  0.00376578
treatment-ccmp-only   i-02ae9e706334f516a   t4g.small      terminated  2026-05-26T08:43:33+00:00  2026-05-26T08:50:00+00:00  387           0.00180600  0.00038222  0.00218822
```

合计估算：

```text
total_estimated_usd  0.00805741
```

价格口径：

- EC2：AWS Pricing API，`t4g.small` Linux on-demand，US East (N. Virginia)。
- EBS：AWS Pricing API，gp3 volume usage，US East (N. Virginia)。
- root volume：`32 GB`。
- wall time：从 EC2 `LaunchTime` 到结果完成或 cleanup 确认时间；control 因为 AWS token
  过期后手动 cleanup，wall time 包含该清理窗口。
- 不包含 data transfer、tax、free tier、credits、Savings Plans、Reserved Instances 或账号折扣。
- EBS 估算只按 volume usage rate 计算，未单独计入 provisioned IOPS / throughput。

## 后续

2026-05-26 状态更新：`CCMP/CMP/CSET` combined regression 已完成，记录见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-rev-extr-ubfm-ldr-csel-ccmp-combined-regression
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-26/arm64-llvm-backend/rev-extr-ubfm-ldr-csel-ccmp-combined-regression/report.md
```

combined flags 覆盖已完成 family：

```text
-bpf-kinsn-target=arm64
-bpf-kinsn-mode=all=disable
-bpf-kinsn-mode=unary=force
-bpf-kinsn-mode=rotate=force
-bpf-kinsn-mode=bextr=force
-bpf-kinsn-mode=wide-load=force
-bpf-kinsn-mode=cmov=force
-bpf-kinsn-mode=ccmp=force
```

必须确认：

- ARM64 combined object 不出现 `bpf_x86_*`。
- scoped x86 treatment 不出现 `bpf_arm64_*`。
- full micro `native` / `kernel` 0 failed sample。
- selected targets `csel_select64` 和 `ccmp_all_nonzero` 仍命中各自 kfunc。

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-local-object-smoke`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-aws-correctness`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-full-micro-correctness`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-csel-performance-attribution`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-rev-extr-ubfm-ldr-csel-combined-regression`
- `/home/ruoji/github/bpf-opt/docs/arm64-ccmp-cmp-cset-family-design.md`
- `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend-implementation-plan.md`
- `/home/ruoji/github/bpf-opt/docs/arm64-kinsn-experiment-matrix.md`
- `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend-guide.md`

发现和处理：

- 旧文档仍写 `CCMP/CMP/CSET` performance attribution pending。已更新为 completed，并明确
  当前不是 performance win。
- 本实验发现除 selected target `ccmp_all_nonzero` 之外，真实 micro
  `cilium_socket_lb_service_select` 也命中 CCMP W variant。已把该覆盖面写入 report 和文档。
- control run 的 wrapper exit code 为 2，但 raw result 已同步且样本 0 failed。已在 report 中
  分开记录 benchmark status 和 AWS cleanup issue，避免误读为 correctness 失败。
- 未发现需要删除的 LLVM、runner、module 或 benchmark framework 临时代码。

是否重跑：

- 本次收尾只修改实验记录和文档，没有修改代码行为，因此不需要重跑 LLVM build 或 micro。
- 本实验已覆盖当前 gate：baseline、same-LLC control、`ccmp=force` treatment，object
  isolation、AWS full micro correctness、same-LLC performance attribution、AWS cleanup
  和费用记录。
