# 2026-05-27 ARM64 LLVM backend family-only same-LLC attribution

## 结论

本实验已完成，状态是 `completed`。

实验问题：在同一个 custom LLVM `llc` 下，分别只打开一个 ARM64 kinsn selector policy，和
`all=disable` control 比较，哪些 family 在 AWS ARM64 full micro 上有独立性能信号？这里的
same-LLC 指同一个 LLVM `llc` 编译器，不是 CPU cache。

主结论：

- 13 个 AWS group 全部 rc=0：baseline、same-LLC control，以及 11 个 family-only treatment。
- 所有 group 都完成 34 个 micro benchmark，runtime 为 `native` 和 `kernel`，每个 runtime
  3 个 sample，总计 2652 个 runtime sample，0 bad sample。
- object isolation 通过：`control-disabled` 是 0 个 `bpf_arm64_*` / `bpf_x86_*`；所有
  treatment 都是 0 个 `bpf_x86_*`。
- family-only attribution 中，`EXTR / rotate` 是最明确的 positive signal：10 个 affected
  benchmark，kernel affected geomean treatment/control 是 `0.920357048`，约 `7.96%` faster。
- `LDR / wide-load` 也有 development-grade positive kernel signal：24 个 affected benchmark，
  kernel affected geomean 是 `0.969490539`，约 `3.05%` faster；但 native all geomean 是
  `1.009537961`，说明 run-to-run drift 存在，不能按 paper-grade claim 使用。
- `PRFM / prefetch` family-only 不是收益来源：33 个 affected benchmark，kernel affected geomean
  是 `1.009656628`，约 `0.97%` slower。
- `MOV / mov` 在 full micro 没有自然 `bpf_arm64_mov_x` 命中，性能上没有可归因对象。

## 总体进度

总体目标：实现 ARM64 LLVM kinsn backend。这里不是新增普通 AArch64 backend，而是在 LLVM
BPF backend 中把安全的 BPF MachineInstr pattern 改写成 ARM64 kinsn pseudo，最终 emit
`KINSN_SIDECAR + KINSN_CALL bpf_arm64_*`，由 verifier 检查 proof expansion，再由 ARM64
kinsn module lower 成 native AArch64 instruction。

Family 总清单和当前状态：

| Family | kfunc count | 当前状态 |
|---|---:|---|
| `REV` | 3 | development-complete on micro；family-only performance neutral/slightly slower。 |
| `EXTR` | 2 | development-complete on micro；family-only positive signal。 |
| `UBFM` | 1 | development-complete on micro；family-only neutral。 |
| `LDR` | 4 | correctness-complete on micro；wide-load positive development-grade signal，direct-load small signal。 |
| `STR` | 4 | correctness-complete on micro；direct-store neutral。 |
| `LDP/STP` | 2 | stack-only subset development-complete on micro；family-only neutral。 |
| `CSEL` | 2 | selected target complete；family-only single-benchmark signal，not enough for broad claim。 |
| `CCMP/CMP/CSET` | 5 | selected-safe subset complete；family-only not a performance win。 |
| `PRFM` | 1 | forced path complete，default disabled；family-only not a performance win。 |
| `MOV` | 1 | forced path complete，default disabled；full micro no natural hit。 |

单个 family 的完整 gate：

1. 读 ARM64 module ABI 和 payload decoder。
2. 在 LLVM BPF backend 里实现 pseudo、AsmPrinter payload、selector 和 FileCheck。
3. 做 object smoke 和 target isolation。
4. 做 AWS runtime correctness。
5. 做 same-LLC performance attribution。
6. 做 combined regression 和文档 / 实验收尾。

当前处于第 5 步：已有 ABI family 的 family-only same-LLC attribution 已完成，结果也已经
回填到公开大报告。下一步是决定默认策略是否只保留 `EXTR` / selected `LDR` 这类有稳定正信号的
policy，或者进入 paper-grade 重跑。

## 实验设计

三类 group：

| group type | 编译配置 | 作用 |
|---|---|---|
| `baseline` | 普通 clang | 辅助观察普通 clang 与 custom LLVM 的差异；不是主对照。 |
| `control-disabled` | custom `llc` + `-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable` | same-LLC 主对照组。 |
| `treatment-*` | 同一个 custom `llc` + `all=disable` + 单个 selector policy `force` | family-only attribution。 |

主性能口径：

```text
treatment-* / control-disabled
```

## Family-only 结果

| group | affected benchmarks | arm64 refs | x86 refs | kernel all | kernel affected | kernel affected delta | native all | observed kfunc families |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| REV / unary | 1 | 2 | 0 | 1.011896267 | 1.016393443 | -1.64% | 0.999702351 | REV:2 |
| EXTR / rotate | 10 | 10 | 0 | 0.982282564 | 0.920357048 | 7.96% | 0.992384681 | EXTR:10 |
| UBFM / bextr | 12 | 12 | 0 | 1.002549851 | 0.999867703 | 0.01% | 0.998771785 | UBFM:12 |
| LDR / wide-load | 24 | 27 | 0 | 0.969922486 | 0.969490539 | 3.05% | 1.009537961 | LDR:27 |
| LDR / direct-load | 2 | 5 | 0 | 0.988429307 | 0.975900073 | 2.41% | 0.997392897 | LDR:5 |
| STR / direct-store | 2 | 5 | 0 | 0.999048242 | 1.000000000 | 0.00% | 1.008177345 | STR:5 |
| LDP/STP / pair-mem | 2 | 2 | 0 | 0.996459491 | 0.998865570 | 0.11% | 1.005776979 | LDP/STP:2 |
| CSEL / cmov | 1 | 2 | 0 | 0.987715561 | 0.928571429 | 7.14% | 0.991567794 | CSEL:1,CCMP/CMP/CSET:1 |
| CCMP/CMP/CSET / ccmp | 2 | 6 | 0 | 0.995866053 | 1.007685031 | -0.77% | 1.002442756 | CCMP/CMP/CSET:6 |
| MOV / mov | 0 | 0 | 0 | 0.998393325 |  |  | 0.999661770 | none |
| PRFM / prefetch | 33 | 33 | 0 | 1.009434119 | 1.009656628 | -0.97% | 0.995179589 | PRFM:33 |

解释：

| policy group | primary reading | reason |
| --- | --- | --- |
| REV / unary | not a performance win | 1 affected benchmark(s); kernel affected geomean 1.016393443; native all 0.999702351. |
| EXTR / rotate | positive development-grade signal | 10 affected benchmarks; affected kernel geomean 0.920357. |
| UBFM / bextr | neutral / too small for claim | 12 affected benchmark(s); kernel affected geomean 0.999867703; native all 0.998771785. |
| LDR / wide-load | positive development-grade signal | 24 affected benchmarks; affected kernel geomean 0.969491, but native all is 1.009538, so treat as development-grade only. |
| LDR / direct-load | neutral / too small for claim | 2 affected benchmark(s); kernel affected geomean 0.975900073; native all 0.997392897. |
| STR / direct-store | neutral / too small for claim | 2 affected benchmark(s); kernel affected geomean 1.000000000; native all 1.008177345. |
| LDP/STP / pair-mem | neutral / too small for claim | 2 affected benchmark(s); kernel affected geomean 0.998865570; native all 1.005776979. |
| CSEL / cmov | positive development-grade signal | single affected benchmark improves, but object includes supporting TST and sample size is small. |
| CCMP/CMP/CSET / ccmp | neutral / too small for claim | 2 affected benchmark(s); kernel affected geomean 1.007685031; native all 1.002442756. |
| MOV / mov | no natural micro hit | 0 symbol refs; normal BPF MOV already lowers to native MOV. |
| PRFM / prefetch | neutral / too small for claim | 33 affected benchmarks but kernel affected geomean is 1.009657; family-only PRFM regresses slightly. |

## Correctness

| group | benchmarks | runtime samples | bad samples | status |
| --- | --- | --- | --- | --- |
| baseline | 34 | 204 | 0 | pass |
| control-disabled | 34 | 204 | 0 | pass |
| treatment-rev-unary | 34 | 204 | 0 | pass |
| treatment-extr-rotate | 34 | 204 | 0 | pass |
| treatment-ubfm-bextr | 34 | 204 | 0 | pass |
| treatment-ldr-wide-load | 34 | 204 | 0 | pass |
| treatment-ldr-direct-load | 34 | 204 | 0 | pass |
| treatment-str-direct-store | 34 | 204 | 0 | pass |
| treatment-ldp-stp-pair-mem | 34 | 204 | 0 | pass |
| treatment-csel-cmov | 34 | 204 | 0 | pass |
| treatment-ccmp | 34 | 204 | 0 | pass |
| treatment-mov | 34 | 204 | 0 | pass |
| treatment-prfm | 34 | 204 | 0 | pass |

Raw summary：

```text
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/family-only/data/correctness-summary.tsv
```

## 命令

所有 benchmark 都通过 Makefile / AWS wrapper 入口执行。

预检查：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/check.sh arm64
ninja -C code/llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4
```

Object build 命令按 group 记录在各自：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-family-only-same-llc-attribution/attempts/<group>/data/object-command.txt
```

AWS run 命令按 group 记录在各自：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-family-only-same-llc-attribution/attempts/<group>/data/aws-command.txt
```

本次 AWS group 命令摘要：

```text
baseline:
RUN_TOKEN=famonlyb QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro 'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
control-disabled:
RUN_TOKEN=famonlyc QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc 'BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable' 'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
treatment-rev-unary:
RUN_TOKEN=famrev QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc 'BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=unary=force' 'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
treatment-extr-rotate:
RUN_TOKEN=famextr QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc 'BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=rotate=force' 'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
treatment-ubfm-bextr:
RUN_TOKEN=famubfm QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc 'BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=bextr=force' 'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
treatment-ldr-wide-load:
RUN_TOKEN=famwload QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc 'BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=wide-load=force' 'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
treatment-ldr-direct-load:
RUN_TOKEN=famdload QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc 'BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=direct-load=force' 'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
treatment-str-direct-store:
RUN_TOKEN=famdstr QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc 'BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=direct-store=force' 'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
treatment-ldp-stp-pair-mem:
RUN_TOKEN=fampair QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc 'BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=pair-mem=force' 'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
treatment-csel-cmov:
RUN_TOKEN=famcmov QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc 'BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=cmov=force' 'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
treatment-ccmp:
RUN_TOKEN=famccmp QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc 'BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=ccmp=force' 'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
treatment-mov:
RUN_TOKEN=fammov QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc 'BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=mov=force' 'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
treatment-prfm:
RUN_TOKEN=famprfm QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc 'BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=prefetch=force' 'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- LLVM submodule：`/home/ruoji/github/bpf-opt/code/llvm-backend/llvm`
- custom `llc`：`/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc`
- platform：AWS ARM64
- AWS region：`us-east-1`
- AWS instance type：`t4g.small`
- AWS remote user：`ec2-user`
- container image：`bpf-benchmark/runner-runtime:arm64`
- kernel：`7.0.0-rc2+`
- root volume：32 GB gp3
- benchmark suite：full micro，34 benchmark
- runtime：`native kernel`
- samples：`SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000`

## 文件改动

本实验没有修改 LLVM、kernel module、runner 或 benchmark framework code。新增的是实验记录、
analysis TSV 和公开整理报告。

实验记录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-family-only-same-llc-attribution
```

公开报告副本：

```text
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/family-only
```

## 数据文件

关键 analysis：

```text
analysis/run-summary.tsv
analysis/correctness-summary.tsv
analysis/median-summary.tsv
analysis/ratio-summary.tsv
analysis/geomean-summary.tsv
analysis/family-effect-summary.tsv
analysis/object-symbols.tsv
analysis/object-family-summary.tsv
analysis/affected-benchmarks.tsv
analysis/kernel-ratio-ranked.tsv
analysis/aws-cost-summary.tsv
analysis/aws-price-source.tsv
analysis/aws-cleanup-summary.tsv
```

Raw runner result 副本保存在：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-family-only-same-llc-attribution/attempts/<group>/data/aws_arm64_micro_*/
```

Object output 副本保存在：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-family-only-same-llc-attribution/data/object-programs/<group>/
```

## AWS 时间和费用

| group | instance | state | wall seconds | time source | estimated USD |
| --- | --- | --- | --- | --- | --- |
| baseline | `i-0066d1e41cef918d6` | terminated-observed-by-run-log | 572 | run-log-birth-to-mtime-upper-bound; aws-describe-missing-for-terminated-instance | $0.003234272 |
| control-disabled | `i-03226888c904594c2` | terminated-observed-by-run-log | 637 | run-log-birth-to-mtime-upper-bound; aws-describe-missing-for-terminated-instance | $0.003601802 |
| treatment-rev-unary | `i-0e8507a681d26785c` | terminated-observed-by-run-log | 666 | run-log-birth-to-mtime-upper-bound; aws-describe-missing-for-terminated-instance | $0.003765778 |
| treatment-extr-rotate | `i-0fe4aedcc15dca427` | terminated-observed-by-run-log | 598 | run-log-birth-to-mtime-upper-bound; aws-describe-missing-for-terminated-instance | $0.003381284 |
| treatment-ubfm-bextr | `i-0e185c5562011a653` | terminated-observed-by-run-log | 619 | run-log-birth-to-mtime-upper-bound; aws-describe-missing-for-terminated-instance | $0.003500025 |
| treatment-ldr-wide-load | `i-0e25d99c7b4171027` | terminated-observed-by-run-log | 590 | run-log-birth-to-mtime-upper-bound; aws-describe-missing-for-terminated-instance | $0.003336049 |
| treatment-ldr-direct-load | `i-0873e6a311aa1b19b` | terminated-observed-by-run-log | 563 | run-log-birth-to-mtime-upper-bound; aws-describe-missing-for-terminated-instance | $0.003183383 |
| treatment-str-direct-store | `i-0d76f2eec3105ec29` | terminated | 529 | aws-describe-instances | $0.002991136 |
| treatment-ldp-stp-pair-mem | `i-04d764c2704163d5e` | terminated | 510 | aws-describe-instances | $0.002883704 |
| treatment-csel-cmov | `i-0566d568b24cd2cd5` | terminated | 537 | aws-describe-instances | $0.003036370 |
| treatment-ccmp | `i-0f08035b6fcf6de79` | terminated | 515 | aws-describe-instances | $0.002911975 |
| treatment-mov | `i-0aba809c4d61efcf7` | terminated | 562 | aws-describe-instances | $0.003177728 |
| treatment-prfm | `i-0f80894f68568d69f` | terminated | 575 | aws-describe-instances | $0.003251235 |

Estimated total：`$0.042254741`。

价格假设：

| item | unit | price | source |
| --- | --- | --- | --- |
| EC2 t4g.small Linux On-Demand us-east-1 | USD/hour | 0.0168 | AWS public On-Demand price assumption used by prior project reports |
| EBS gp3 root volume | USD/GB-month | 0.08 | AWS public gp3 storage price assumption used by prior project reports |
| root volume size | GB | 32 | aws-config RUN_ROOT_VOLUME_GB |

费用估算不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

说明：AWS `describe-instances` 在收尾时只返回了后 6 个 terminated instance 的完整 launch / terminate
字段。前 7 个 instance 已从 `describe-instances` 结果中消失；这些行使用本地 `run.log` birth time
到 mtime 作为 wall-time upper bound，并在 `time_source` 列明确标出。

实例清理：

```text
query	result
active_or_stopped_bpf-benchmark-arm64	[]
```

## 问题和处理

- `baseline` 不是主对照；主对照是同一个 custom `llc` 下的 `control-disabled`。
- `treatment-csel-cmov` object 同时出现 `bpf_arm64_csel_ne` 和 supporting `bpf_arm64_tst`，
  因此本实验按 selector policy group 归因，而不是假设每组只有单一 kfunc family。
- `MOV` 没有自然 micro hit；这符合预期，因为普通 BPF register move 已经 lower 成同等 native MOV。
- `PRFM` family-only 结果为慢，不支持默认启用。
- AWS 前 7 个 terminated instance 的完整 EC2 metadata 在收尾查询时不可见；报告中保留 instance id，
  并用 run-log upper bound 做费用估算。

## 结果

结论按 gate：

- correctness gate：通过，13 组全部 0 bad sample。
- target isolation gate：通过，control 0 kfunc，treatment 0 x86 symbol。
- family-only performance gate：`EXTR` 明确正向；`LDR wide-load` 有 development-grade 正向；
  `UBFM`、`STR`、`LDP/STP`、`CCMP` 基本 neutral；`REV`、`PRFM` 不是 performance win；`MOV` 无自然 hit。
- artifact gate：通过，raw runner data、object output、analysis TSV、AWS cost/cleanup 记录已保存。

## 后续

1. 更新公开 ARM64 backend 大报告，把本次 family-only attribution 作为 performance attribution 的主索引。
2. 默认策略上，不应因为 combined result 默认启用 `PRFM` 或 `MOV`。
3. 如果要做 paper-grade claim，优先对 `EXTR` 和 selected `LDR` 做更高 samples / warmups 的重跑；其它 family 先保留 correctness/coverage 状态。

## 收尾一致性复查

已回看：

- 当前实验所有 13 个 group 的 `exit-code.txt`、`metadata.json`、`result.json`、object build log 和 symbol summary。
- 相关前序报告：
  `/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-existing-abi-same-llc-attribution/report.md`，
  `/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-prfm-disabled-combined-attribution/report.md`，
  `/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-existing-abi-completion/report.md`。
- 公开大报告：
  `/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/report.md`。

发现和处理：

- 前序 combined report 只能说明 combined signal，不能拆分 family 归因。本实验补齐 family-only
  attribution，并在公开报告中单独建子目录。
- `PRFM` 在 combined run 中命中很广，但 family-only 结果不是 win；这会写回公开大报告，避免以后
  把 combined positive signal 误归因给 `PRFM`。
- 本实验没有代码改动，因此不需要重跑 LLVM build 或 micro benchmark。所有需要的数据已经来自本次
  13 组 AWS run。
