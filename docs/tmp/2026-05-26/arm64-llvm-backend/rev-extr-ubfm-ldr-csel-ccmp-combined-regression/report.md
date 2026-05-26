# 2026-05-26 arm64-rev-extr-ubfm-ldr-csel-ccmp-combined-regression

## 结论

本实验完成，状态是 `completed`。

本次 combined regression 通过：

- ARM64 `all=disable` control：31 个 object，0 个 kfunc extern。
- ARM64 combined treatment：31 个 object，28 个 object 命中 `bpf_arm64_*`，0 个
  `bpf_x86_*`。
- x86 scoped treatment：31 个 object，25 个 object 命中 `bpf_x86_*`，0 个
  `bpf_arm64_*`。
- Selected targets 仍命中：
  - `csel_select64` 命中 `bpf_arm64_tst` / `bpf_arm64_csel_ne`。
  - `ccmp_all_nonzero` 命中 `bpf_arm64_cmp_w` / `bpf_arm64_ccmp_w` /
    `bpf_arm64_cset_x_cond`。
- AWS ARM64 full micro correctness：31 个 benchmark，`native` / `kernel` 共 62 个
  runtime sample，0 failed sample。
- AWS instance `i-0a658c46ed71b3734` 已 `terminated`，估算费用 `$0.00226196`。

因此，`CCMP/CMP/CSET` 第一版 selected-safe subset 已完成 micro 级闭环：LLVM emit、object
isolation、AWS correctness、same-LLC performance attribution、combined regression 都完成。当前
performance attribution 不是 win，但 correctness 和组合回归通过。

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
| `CSEL` | 2 | development-complete on micro；当前不是 performance win |
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

本实验完成 `CCMP/CMP/CSET` family 的第 6 步 combined regression。

## 实验问题

本实验回答：

1. 打开 `REV+EXTR+UBFM+LDR_X+LDRH+LDR_W+CSEL+CCMP` 后，ARM64 object 是否仍只 emit
   `bpf_arm64_*`。
2. 同一批 scoped x86 policy 是否仍只 emit `bpf_x86_*`。
3. `all=disable` control 是否仍生成 0 kfunc extern。
4. Combined ARM64 treatment 是否能在 AWS ARM64 上通过 31 个 micro 的 `native` / `kernel`
   correctness。
5. `csel_select64` 和 `ccmp_all_nonzero` selected targets 是否仍命中各自 kfunc。

本实验不回答 combined treatment 的性能。

## 命令

Preflight：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/check.sh arm64
cd /home/ruoji/github/bpf-opt/code
ninja -C /home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4
```

Object smoke：

```bash
cd /home/ruoji/github/bpf-opt
make -C /home/ruoji/github/bpf-opt/code/micro/programs \
  OUTPUT_DIR=/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-rev-extr-ubfm-ldr-csel-ccmp-combined-regression/data/object-programs-arm64-all-disable \
  KERNEL_OFFSETS_INPUT=/home/ruoji/github/bpf-opt/code/micro/programs/build-arm64/kernel_offsets.h \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable" \
  all

make -C /home/ruoji/github/bpf-opt/code/micro/programs \
  OUTPUT_DIR=/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-rev-extr-ubfm-ldr-csel-ccmp-combined-regression/data/object-programs-arm64-combined \
  KERNEL_OFFSETS_INPUT=/home/ruoji/github/bpf-opt/code/micro/programs/build-arm64/kernel_offsets.h \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=unary=force -bpf-kinsn-mode=rotate=force -bpf-kinsn-mode=bextr=force -bpf-kinsn-mode=wide-load=force -bpf-kinsn-mode=cmov=force -bpf-kinsn-mode=ccmp=force" \
  all

make -C /home/ruoji/github/bpf-opt/code/micro/programs \
  OUTPUT_DIR=/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-rev-extr-ubfm-ldr-csel-ccmp-combined-regression/data/object-programs-x86-scoped \
  KERNEL_OFFSETS_INPUT=/home/ruoji/github/bpf-opt/code/micro/programs/build-arm64/kernel_offsets.h \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=x86 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=unary=force -bpf-kinsn-mode=rotate=force -bpf-kinsn-mode=bextr=force -bpf-kinsn-mode=wide-load=force -bpf-kinsn-mode=cmov=force" \
  all
```

AWS full micro correctness：

```bash
cd /home/ruoji/github/bpf-opt
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu \
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=unary=force -bpf-kinsn-mode=rotate=force -bpf-kinsn-mode=bextr=force -bpf-kinsn-mode=wide-load=force -bpf-kinsn-mode=cmov=force -bpf-kinsn-mode=ccmp=force" \
  RUNTIMES="native kernel" \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=10000
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

## 文件改动

本实验没有修改 LLVM、runner、module 或 benchmark framework code。

新增实验记录、分析和 public tmp 摘要：

- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-rev-extr-ubfm-ldr-csel-ccmp-combined-regression/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-rev-extr-ubfm-ldr-csel-ccmp-combined-regression/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-rev-extr-ubfm-ldr-csel-ccmp-combined-regression/analysis/*.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-rev-extr-ubfm-ldr-csel-ccmp-combined-regression/attempts/aws-full-micro/data/`
- `/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-26/arm64-llvm-backend/rev-extr-ubfm-ldr-csel-ccmp-combined-regression/report.md`
- `/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-26/arm64-llvm-backend/rev-extr-ubfm-ldr-csel-ccmp-combined-regression/analysis/*.tsv`

同步更新状态文档：

- `/home/ruoji/github/bpf-opt/docs/arm64-ccmp-cmp-cset-family-design.md`
- `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend-implementation-plan.md`
- `/home/ruoji/github/bpf-opt/docs/arm64-kinsn-experiment-matrix.md`
- `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend-guide.md`
- `/home/ruoji/github/bpf-opt/docs/arm64-load-store-family-design.md`
- `/home/ruoji/github/bpf-opt/docs/arm64-csel-family-design.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-csel-coverage-correctness-gate/report.md`

## 数据文件

- `data/run-contract.json`
- `data/aws-check.log`
- `data/ninja-build.log`
- `data/object-programs-arm64-all-disable/`
- `data/object-programs-arm64-combined/`
- `data/object-programs-x86-scoped/`
- `analysis/object-symbol-summary.tsv`
- `analysis/kfunc-relocation-summary.tsv`
- `analysis/per-object-kfunc-summary.tsv`
- `attempts/aws-full-micro/data/run.stdout.log`
- `attempts/aws-full-micro/data/run.stderr.log`
- `attempts/aws-full-micro/data/aws_arm64_micro_20260526_092531_866575/`
- `attempts/aws-full-micro/data/micro_tnt_20260526_092530.remote.log`
- `attempts/aws-full-micro/data/aws-instance-final.json`
- `attempts/aws-full-micro/data/aws-active-instances-after-run.json`
- `attempts/aws-full-micro/data/aws-pricing-ec2-t4g-small.raw.json`
- `attempts/aws-full-micro/data/aws-pricing-ebs-gp3.raw.json`
- `attempts/aws-full-micro/analysis/run-result-summary.tsv`
- `attempts/aws-full-micro/analysis/sample-summary.tsv`
- `attempts/aws-full-micro/analysis/failed-samples.tsv`
- `attempts/aws-full-micro/analysis/aws-cost-summary.tsv`
- `attempts/aws-full-micro/analysis/aws-cost-total.txt`

## 问题和处理

- x86 default broad policy 的既有 crash 不作为本实验 gate。本实验使用 scoped x86 flags 检查
  target isolation。
- AWS treatment 只跑 `RUNTIMES="native kernel"`，因为 userspace `llvmbpf` runtime 不支持
  `bpf_arm64_*` extern。
- AWS wrapper exit code 为 0。后续 `describe-instances` 确认 instance 已 `terminated`。
- `aws-active-instances-after-run.json` 确认没有 pending/running/stopping/stopped/shutting-down 的
  `bpf-benchmark-*` instance。

## 结果

Object isolation：

```text
case                 objects  kfunc_symbol_objects  arm64_symbol_objects  x86_symbol_objects  arm64_relocations  x86_relocations  arm64_rev  arm64_extr  arm64_ubfm  arm64_ldr  arm64_csel  arm64_ccmp
arm64-all-disable    31       0                     0                     0                   0                  0                0          0           0           0          0           0
arm64-combined       31       28                    28                    0                   280                0                4          160         38          66         4           8
x86-scoped           31       25                    0                     25                  0                  240              0          0           0           0          0           0
```

ARM64 combined relocation coverage：

```text
kfunc                         object_count  relocations
bpf_arm64_cmp_w               2             2
bpf_arm64_ccmp_w              2             4
bpf_arm64_cset_x_cond         2             2
bpf_arm64_tst                 1             2
bpf_arm64_csel_ne             1             2
bpf_arm64_extr_w              4             40
bpf_arm64_extr_x              4             120
bpf_arm64_ldrh                4             11
bpf_arm64_ldr_w               21            43
bpf_arm64_ldr_x               2             12
bpf_arm64_rev16_w             1             2
bpf_arm64_rev_w               1             2
bpf_arm64_ubfm_x              12            38
```

Selected target evidence：

```text
csel_select64:
  object symbols: bpf_arm64_tst,bpf_arm64_csel_ne,bpf_arm64_extr_x,bpf_arm64_ldr_x
  kernel code compare: tst / csel present

ccmp_all_nonzero:
  object symbols: bpf_arm64_cmp_w,bpf_arm64_ccmp_w,bpf_arm64_cset_x_cond
  kernel code compare: cmp / ccmp / cset present
```

AWS correctness：

```text
attempt          result_dir                            status     benchmarks  runtimes       samples  failed_samples
aws-full-micro   aws_arm64_micro_20260526_092531_866575 completed  31          kernel,native  62       0
```

Selected target runtime samples:

```text
benchmark          runtime  result                retval  exec_ns  bpf_bytecode_bytes  native_code_bytes
csel_select64      native   15327322346016019187  2       4        0                   92
csel_select64      kernel   15327322346016019187  2       17       416                 240
ccmp_all_nonzero   native   1                     2       5        0                   100
ccmp_all_nonzero   kernel   1                     2       17       376                 256
```

AWS cost：

```text
instance_id          instance_type  region     state       launch_time_utc            end_time_utc               wall_seconds  compute_usd  ebs_usd     total_usd
i-0a658c46ed71b3734  t4g.small      us-east-1  terminated  2026-05-26T09:19:07+00:00  2026-05-26T09:25:48+00:00  401           0.00187133  0.00039062  0.00226196
```

价格口径：

- EC2：AWS Pricing API，`t4g.small` Linux on-demand，US East (N. Virginia)，`$0.0168/hour`。
- EBS：AWS Pricing API，gp3 volume usage，US East (N. Virginia)，`$0.08/GB-month`。
- root volume：`32 GB`。
- wall time：从 EC2 `LaunchTime` 到 `StateTransitionReason` 里的 terminate time。
- 不包含 data transfer、tax、free tier、credits、Savings Plans、Reserved Instances 或账号折扣。
- EBS 估算只按 volume usage rate 计算，未单独计入 provisioned IOPS / throughput。

## 后续

`CCMP/CMP/CSET` 第一版 selected-safe subset 已完成到 combined regression，可以标为
`development-complete on micro`。下一步不应继续扩大 CCMP selector；应先进入下一个 family 的
design gate。候选顺序：

1. `LDP/STP`：需要 pair access safety design。
2. `PRFM`：correctness 简单，但 performance attribution 噪声高。
3. `MOV`：需要先证明独立 kfunc 化有价值。

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-local-object-smoke`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-aws-correctness`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-full-micro-correctness`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-performance-attribution`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-rev-extr-ubfm-ldr-csel-combined-regression`
- `/home/ruoji/github/bpf-opt/docs/arm64-ccmp-cmp-cset-family-design.md`
- `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend-implementation-plan.md`
- `/home/ruoji/github/bpf-opt/docs/arm64-kinsn-experiment-matrix.md`
- `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend-guide.md`
- `/home/ruoji/github/bpf-opt/docs/arm64-load-store-family-design.md`
- `/home/ruoji/github/bpf-opt/docs/arm64-csel-family-design.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-csel-coverage-correctness-gate/report.md`

发现和处理：

- 相关文档仍写 `CCMP/CMP/CSET` combined regression pending。已更新为 completed，并明确
  performance 当前不是 win。
- `docs/arm64-load-store-family-design.md` 和 `docs/arm64-csel-family-design.md` 仍保留
  `CCMP/CMP/CSET` performance / combined regression pending 的旧状态。已更新。
- `experiments/2026-05-25-arm64-csel-coverage-correctness-gate/report.md` 的总体进度仍写
  CSEL combined regression pending、CCMP not started。已回填当前最终状态。
- 旧 CCMP report 已在 performance attribution 收尾时更新过，不再保留“下一步 performance”的
  过时说法。
- 未发现需要删除的 LLVM、runner、module 或 benchmark framework 临时代码。

是否重跑：

- 本实验实际重跑了 object isolation 和 AWS full micro correctness。
- 收尾只更新文档和实验记录，没有修改代码行为，因此不需要额外 rerun。
