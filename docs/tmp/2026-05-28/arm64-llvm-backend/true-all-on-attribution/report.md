# 2026-05-28 arm64-true-all-on-same-llc-attribution

## 结论

本实验已完成，状态是 `completed`。

实验问题：在同一个 custom LLVM `llc` 下，把已有 ARM64 kinsn selector 全部打开以后，
full micro 上每个 benchmark 实际触发哪些 `bpf_arm64_*` kfunc？这些触发是否能稳定解释
kernel runtime 的变化？这里的 same-LLC 指同一个 LLVM `llc` 编译器，不是 CPU cache。

主结论：

- 9 个 AWS ARM64 full micro run 全部 rc=0：3 轮 `baseline`、3 轮 same-LLC
  `control-disabled`、3 轮 `treatment-true-all-on`。
- 每个 run 都完成 34 个 benchmark，runtime 为 `native` 和 `kernel`，每个 runtime 3 个
  sample。总计 1836 个 runtime sample，0 个 bad sample。
- Object isolation 通过：`control-disabled` 生成 34 个 object、0 个 `bpf_arm64_*`、0 个
  `bpf_x86_*`；`treatment-true-all-on` 生成 34 个 object、396 个 `bpf_arm64_*`
  relocation、0 个 `bpf_x86_*`。
- true all-on 相对 same-LLC control 的 kernel all geomean 三轮分别是 `0.939098387`、
  `0.935947497`、`0.945958541`，中位数 `0.939098387`，约 `6.09%` faster。
- native all geomean 中位数是 `1.003011563`，方向 mixed，说明非 kernel drift 很小但存在。
- per-benchmark kernel 稳定性：15 个 benchmark 三轮都 faster，6 个三轮都 slower，
  4 个三轮 equal，9 个 mixed。
- 不能把 true all-on 的 family scope geomean 解释成单个 family 的独立因果收益，因为一个
  benchmark 往往同时触发多个 family。独立收益仍以 2026-05-27 family-only attribution 为准。

## 总体进度

总体目标：实现 ARM64 LLVM kinsn backend。这里不是新增普通 AArch64 backend，而是在 LLVM
BPF backend 中把安全的 BPF MachineInstr pattern 改写成 ARM64 kinsn pseudo，最终 emit
`KINSN_SIDECAR + KINSN_CALL bpf_arm64_*`，由 verifier 检查 proof expansion，再由 ARM64
kinsn module lower 成 native AArch64 instruction。

Family 总清单和当前状态：

| Family | kfunc count | 当前状态 |
|---|---:|---|
| `REV` | 3 | development-complete on micro；true all-on 中 1 个 benchmark 触发。 |
| `EXTR` | 2 | development-complete on micro；true all-on 中 10 个 benchmark 触发。 |
| `UBFM` | 1 | development-complete on micro；true all-on 中 12 个 benchmark 触发。 |
| `LDR` | 4 | correctness-complete on micro；true all-on 中 25 个 benchmark 触发。 |
| `STR` | 4 | correctness-complete on micro；true all-on 中 1 个 ABI coverage benchmark 触发。 |
| `LDP/STP` | 2 | stack-only subset complete；true all-on 中 2 个 benchmark 触发。 |
| `CSEL` | 2 | selected target complete；true all-on 中 1 个 benchmark 触发。 |
| `CCMP/CMP/CSET` | 5 | selected-safe subset complete；true all-on 中 2 个 benchmark 触发。 |
| `PRFM` | 1 | forced path complete，default disabled；true all-on 中 33 个 benchmark 触发。 |
| `MOV` | 1 | forced path complete，default disabled；true all-on full micro 无自然 hit。 |

单个 family 的完整 gate：

1. 读 ARM64 module ABI 和 payload decoder。
2. 在 LLVM BPF backend 里实现 pseudo、AsmPrinter payload、selector 和 FileCheck。
3. 做 object smoke 和 target isolation。
4. 做 AWS runtime correctness。
5. 做 same-LLC performance attribution。
6. 做 combined regression 和文档 / 实验收尾。

当前处于项目级后验验证：已有 ABI 的 25 个 target 已完成 micro 级 implementation/correctness，
本实验补齐 “true all-on 多轮稳定性 attribution”。下一步是决定默认 policy 只启用哪些稳定正向
selector，或进入 corpus / paper-grade benchmark。

## 实验设计

术语：

- `kinsn`：本项目中由 BPF object 通过 `KINSN_SIDECAR + KINSN_CALL` 表达的 kernel instruction
  substitution。ARM64 路径最终调用 `bpf_arm64_*` kfunc。
- `family`：一组 ARM64 instruction target，例如 `EXTR` 表示 rotate 相关 kfunc，
  `LDR` 表示 load 相关 kfunc。
- `same-LLC`：baseline 以外的 control 和 treatment 使用同一个 custom LLVM `llc`。
  主对照是 treatment / `all=disable`，不是 treatment / normal clang。
- `true all-on`：先设置 `all=disable`，再同时 force 所有已有 selector policy：
  `unary, rotate, bextr, wide-load, direct-load, direct-store, pair-mem, cmov, ccmp, mov, prefetch`。
- ratio：`treatment median exec_ns / control median exec_ns`。小于 1 表示 treatment 更快。

三类 group：

| group | 编译配置 | 作用 |
|---|---|---|
| `baseline` | 普通 clang | 辅助观察 normal clang 与 custom LLVM 的 drift；不是主性能结论。 |
| `control-disabled` | custom `llc` + `-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable` | same-LLC 主对照组。 |
| `treatment-true-all-on` | 同一个 custom `llc` + all policies forced | 验证全开组合下每个 benchmark 实际触发的 kinsn 和性能。 |

主性能口径：

```text
treatment-true-all-on / control-disabled
```

## 命令

所有 benchmark 都通过 Makefile / AWS wrapper 入口执行。

预检查：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/check.sh arm64
ninja -C code/llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4
```

Object build：

```bash
cd /home/ruoji/github/bpf-opt/code
make -C micro/programs clean all \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc \
  BPF_KINSN_LLC_FLAGS='-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable'

make -C micro/programs clean all \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc \
  BPF_KINSN_LLC_FLAGS='-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=unary=force,rotate=force,bextr=force,wide-load=force,direct-load=force,direct-store=force,pair-mem=force,cmov=force,ccmp=force,mov=force,prefetch=force'
```

AWS benchmark 每组每轮都使用：

```bash
cd /home/ruoji/github/bpf-opt
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro \
  'RUNTIMES=native kernel' SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

`control-disabled` 额外设置：

```text
BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm
BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc
BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable
```

`treatment-true-all-on` 额外设置：

```text
BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm
BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc
BPF_KINSN_LLC_FLAGS=-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=unary=force,rotate=force,bextr=force,wide-load=force,direct-load=force,direct-store=force,pair-mem=force,cmov=force,ccmp=force,mov=force,prefetch=force
```

每个实际命令保存在：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/attempts/rep*/data/aws-command.txt
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

本实验没有修改 LLVM、kernel module、runner 或 benchmark framework code。

新增实验记录和公开报告：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-28/arm64-llvm-backend/true-all-on-attribution
```

已同步更新的总体文档只记录本实验结论，不改变代码行为。

## 数据文件

关键 raw / analysis 文件：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/analysis/run-summary.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/analysis/raw-samples.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/analysis/correctness-summary.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/analysis/object-group-summary.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/analysis/triggered-kinsn-by-benchmark.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/analysis/geomean-stability.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/analysis/kernel-stability-by-benchmark.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/analysis/true-all-on-vs-family-only.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/analysis/aws-cost-summary.tsv
```

每个 AWS run 的 raw result 目录已复制到对应 attempt，例如：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/attempts/rep1-treatment-true-all-on/data/aws_arm64_micro_20260528_091113_548309
```

## Correctness

所有 run 都通过：

| rep | group | kernel samples | native samples | bad samples |
|---:|---|---:|---:|---:|
| 1 | `baseline` | 102 | 102 | 0 |
| 1 | `control-disabled` | 102 | 102 | 0 |
| 1 | `treatment-true-all-on` | 102 | 102 | 0 |
| 2 | `baseline` | 102 | 102 | 0 |
| 2 | `control-disabled` | 102 | 102 | 0 |
| 2 | `treatment-true-all-on` | 102 | 102 | 0 |
| 3 | `baseline` | 102 | 102 | 0 |
| 3 | `control-disabled` | 102 | 102 | 0 |
| 3 | `treatment-true-all-on` | 102 | 102 | 0 |

## Object Isolation

| group | objects | objects with ARM64 kfunc | objects with x86 kfunc | ARM64 relocations | x86 relocations |
|---|---:|---:|---:|---:|---:|
| `control-disabled` | 34 | 0 | 0 | 0 | 0 |
| `treatment-true-all-on` | 34 | 34 | 0 | 396 | 0 |

## Geomean Stability

| scope | benchmarks | kernel rep geomeans | kernel median | kernel direction | native median |
|---|---:|---|---:|---|---:|
| `ALL` | 34 | 0.939098387 / 0.935947497 / 0.945958541 | 0.939098387 | `all_faster` | 1.003011563 |
| `NON_PRFM` | 31 | 0.931585359 / 0.931844046 / 0.935595451 | 0.931844046 | `all_faster` | 1.000618244 |
| `REV` | 1 | 0.848484848 / 0.918032787 / 0.950819672 | 0.918032787 | `all_faster` | 0.964285714 |
| `EXTR` | 10 | 0.861081632 / 0.871606888 / 0.877348285 | 0.871606888 | `all_faster` | 1.006797560 |
| `UBFM` | 12 | 0.964633359 / 0.972496433 / 0.977137137 | 0.972496433 | `all_faster` | 0.989896718 |
| `LDR` | 25 | 0.925022523 / 0.923831308 / 0.929261884 | 0.925022523 | `all_faster` | 0.993494774 |
| `STR` | 1 | 0.950000000 / 0.950000000 / 0.950000000 | 0.950000000 | `all_faster` | 1.000000000 |
| `LDP/STP` | 2 | 1.000000000 / 1.000000000 / 1.000000000 | 1.000000000 | `all_equal` | 1.000000000 |
| `CSEL` | 1 | 0.607142857 / 0.607142857 / 0.607142857 | 0.607142857 | `all_faster` | 1.000000000 |
| `CCMP/CMP/CSET` | 2 | 1.008666508 / 1.003362969 / 1.016292400 | 1.008666508 | `all_slower` | 1.000000000 |
| `PRFM` | 33 | 0.937215069 / 0.934116517 / 0.944178250 | 0.937215069 | `all_faster` | 1.002342782 |
| `MOV` | 0 |  /  /  |  | `mixed` |  |

解释：

- `ALL` 三轮 kernel geomean 都 faster，说明 true all-on 组合相对 same-LLC control 有稳定
  development-grade 正向信号。
- `NON_PRFM` 仍然稳定 faster，说明 signal 不是只由 `PRFM` 覆盖面造成。
- family scope 是“包含该 family 的 benchmark 子集”，不是 family-only 因果结论。比如
  `PRFM` scope faster，是因为 33/34 benchmark 同时也包含其他 kinsn；这不推翻
  `PRFM-only` 不是 win 的结论。

## Per-Case Attribution

下表回答：每个 micro case 实际触发哪些 family，以及 true all-on 相对 all-disabled control 的
kernel speed ratio。其他没有触发的 family 对该 object 没有直接 kfunc 影响。

| benchmark | kinsn families hit | refs | median kernel ratio | direction | rep ratios |
|---|---|---:|---:|---|---|
| `simple` | `PRFM` | `PRFM:2` | 1.000000000 | `mixed` | 1.000000000 / 1.000000000 / 1.142857143 |
| `simple_packet` | `PRFM` | `PRFM:2` | 1.071428571 | `all_slower` | 1.071428571 / 1.071428571 / 1.142857143 |
| `csel_select64` | `CSEL,EXTR,LDR,PRFM` | `CSEL:4,EXTR:1,LDR:4,PRFM:2` | 0.607142857 | `all_faster` | 0.607142857 / 0.607142857 / 0.607142857 |
| `ccmp_all_nonzero` | `CCMP/CMP/CSET,PRFM` | `CCMP/CMP/CSET:5,PRFM:2` | 1.000000000 | `all_equal` | 1.000000000 / 1.000000000 / 1.000000000 |
| `stp_stack_pair` | `LDP/STP,PRFM` | `LDP/STP:1,PRFM:2` | 1.000000000 | `all_equal` | 1.000000000 / 1.000000000 / 1.000000000 |
| `ldp_stack_pair` | `EXTR,LDP/STP,PRFM` | `EXTR:1,LDP/STP:1,PRFM:2` | 1.000000000 | `all_equal` | 1.000000000 / 1.000000000 / 1.000000000 |
| `arm64_direct_abi_coverage` | `EXTR,LDR,PRFM,STR` | `EXTR:1,LDR:4,PRFM:2,STR:4` | 0.950000000 | `all_faster` | 0.950000000 / 0.950000000 / 0.950000000 |
| `bitmap_popcount_scan` | `LDR,PRFM,UBFM` | `LDR:2,PRFM:3,UBFM:1` | 1.000867679 | `mixed` | 0.998263889 / 1.000867679 / 1.007423581 |
| `sorted_rule_binary_search` | `LDR,PRFM` | `LDR:2,PRFM:11` | 1.030848329 | `all_slower` | 1.030848329 / 1.031362468 / 1.016984045 |
| `bcc_runqlat_log2_histogram_bucket` | `LDR,PRFM,UBFM` | `LDR:2,PRFM:10,UBFM:1` | 0.994988725 | `all_faster` | 0.994988725 / 0.986567164 / 0.998497370 |
| `trace_event_type_switch_dispatch` | `LDR,PRFM` | `LDR:2,PRFM:2` | 0.875358166 | `all_faster` | 0.918998527 / 0.859154930 / 0.875358166 |
| `packet_checksum_fold` | `LDR,PRFM` | `LDR:3,PRFM:2` | 0.998517577 | `mixed` | 0.998517577 / 1.000000000 / 0.998123316 |
| `payload_prefix_memcmp_scan` | `EXTR,LDR,PRFM` | `EXTR:2,LDR:1,PRFM:5` | 1.128919861 | `all_slower` | 1.128919861 / 1.121951220 / 1.129370629 |
| `packet_vlan_tcpopt_parser` | `PRFM,UBFM` | `PRFM:5,UBFM:1` | 1.000000000 | `mixed` | 1.000000000 / 1.000000000 / 0.978260870 |
| `bpf_local_call_fanout_dispatch` | `LDR,PRFM` | `LDR:3,PRFM:2` | 0.932307692 | `all_faster` | 0.926605505 / 0.996923077 / 0.932307692 |
| `flow_5tuple_rss_hash` | `EXTR,PRFM,UBFM` | `EXTR:14,PRFM:4,UBFM:2` | 0.812500000 | `all_faster` | 0.780000000 / 0.812500000 / 0.812500000 |
| `katran_lb_consistent_hash_select` | `EXTR,LDR,PRFM,REV,UBFM` | `EXTR:24,LDR:7,PRFM:3,REV:4,UBFM:11` | 0.918032787 | `all_faster` | 0.848484848 / 0.918032787 / 0.950819672 |
| `cilium_policy_guard_tree_filter` | `LDR,PRFM` | `LDR:1,PRFM:3` | 0.991836735 | `mixed` | 1.000000000 / 0.931034483 / 0.991836735 |
| `siphash_rotate64_mixer` | `EXTR,LDR,PRFM` | `EXTR:116,LDR:8,PRFM:2` | 0.528301887 | `all_faster` | 0.528301887 / 0.525000000 / 0.531250000 |
| `packet_record_bounds_window` | `LDR,PRFM` | `LDR:8,PRFM:2` | 0.577259475 | `all_faster` | 0.578947368 / 0.577259475 / 0.577259475 |
| `flow_record_field_scan` | `PRFM,UBFM` | `PRFM:3,UBFM:1` | 1.000000000 | `all_equal` | 1.000000000 / 1.000000000 / 1.000000000 |
| `packed_header_bitfield_decode` | `LDR,PRFM,UBFM` | `LDR:2,PRFM:3,UBFM:13` | 0.978632479 | `all_faster` | 0.978655283 / 0.978632479 / 0.976520811 |
| `bpftrace_string_search_prefix_scan` | `EXTR,LDR,PRFM` | `EXTR:1,LDR:1,PRFM:2` | 1.052325581 | `all_slower` | 1.035087719 / 1.052325581 / 1.060546875 |
| `tracee_syscall_name_table_lookup` | `LDR,PRFM` | `LDR:1,PRFM:3` | 1.018181818 | `mixed` | 1.018181818 / 0.982808023 / 1.027027027 |
| `tracee_http_method_prefix_detect` | `LDR,PRFM` | `LDR:2,PRFM:3` | 0.951612903 | `all_faster` | 0.951612903 / 0.967213115 / 0.951612903 |
| `cilium_socket_lb_service_select` | `CCMP/CMP/CSET,LDR,PRFM,UBFM` | `CCMP/CMP/CSET:3,LDR:2,PRFM:3,UBFM:2` | 1.017408124 | `all_slower` | 1.017408124 / 1.006737247 / 1.032850242 |
| `bcc_tcpconnect_ipv4_tuple_filter` | `EXTR,LDR,PRFM,UBFM` | `EXTR:1,LDR:2,PRFM:3,UBFM:2` | 0.990595611 | `all_faster` | 0.990595611 / 0.990625000 / 0.990595611 |
| `tetragon_process_event_arg_filter` | `LDR,PRFM` | `LDR:2,PRFM:3` | 1.015267176 | `all_slower` | 1.015267176 / 1.015267176 / 1.017175573 |
| `otel_stack_frame_unwind_scan` | `LDR,PRFM,UBFM` | `LDR:2,PRFM:3,UBFM:1` | 1.005249344 | `mixed` | 1.007874016 / 1.005249344 / 0.997395833 |
| `cilium_ct_nat_tuple_rewrite` | `EXTR,LDR,PRFM` | `EXTR:1,LDR:2,PRFM:3` | 0.960000000 | `all_faster` | 0.960000000 / 0.957894737 / 0.962105263 |
| `packet_toeplitz_rss_hash` | `PRFM` | `PRFM:3` | 0.911877395 | `all_faster` | 0.991543340 / 0.876893939 / 0.911877395 |
| `bpftrace_comm_key_fnv_hash` | `LDR,PRFM,UBFM` | `LDR:2,PRFM:3,UBFM:1` | 0.998188406 | `all_faster` | 0.998188406 / 0.996984318 / 0.998189499 |
| `tc_packet_checksum_fold` | `LDR` | `LDR:3` | 1.003417201 | `mixed` | 1.003417201 / 0.998425960 / 1.006629734 |
| `cgroup_skb_hash_chain` | `LDR,PRFM,UBFM` | `LDR:2,PRFM:1,UBFM:2` | 0.995187680 | `mixed` | 0.995187680 / 0.993262753 / 1.001924928 |

## 和 Family-Only 的关系

本实验回答的是 “所有已有 selector 同时打开后，真实组合表现如何”。它不替代 family-only
attribution：

- 如果一个 benchmark 只触发 `PRFM`，true all-on 对它的直接 kfunc 影响就只有 `PRFM`。
- 如果一个 benchmark 同时触发 `EXTR,LDR,PRFM`，true all-on ratio 是三者组合后的结果，
  不能拆成单个 family 的独立收益。
- 如果某个 family 没有出现在该 benchmark 的 object relocation 中，它对该 benchmark 没有
  直接 kfunc 影响。

对照文件：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/analysis/true-all-on-vs-family-only.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-family-only-same-llc-attribution/analysis/family-effect-summary.tsv
```

## AWS 时间和费用

清理状态：

- 每个 benchmark run 结束时 runner 已请求 terminate。
- 实验结束后额外执行 `./aws-config/run.sh arm64 terminate`。
- `aws-cleanup-summary.tsv` 中没有 active instance，表示按 tag 查询不到 pending/running/stopping/stopped/shutting-down 的 `bpf-benchmark-arm64` 实例。

费用估算：

- EC2 价格：`t4g.small` Linux On-Demand `us-east-1`，`$0.0168/hour`，来源为 AWS Pricing API
  `get-products`；同时和 AWS EC2 On-Demand pricing page 一致。
- EBS 价格：gp3 `us-east-1`，`$0.08/GB-month`，来源为 AWS Pricing API `get-products`；
  同时和 AWS EBS pricing page 一致。
- root volume：32 GB gp3。
- 合计估算：`$0.027751408`。
- 不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

详细逐 instance 估算：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/analysis/aws-cost-summary.tsv
```

## 问题和处理

- EC2 `describe-instances` 没有返回最早 3 个已经 terminated 的 instance。费用估算对这 3 个 run
  使用本地 `aws-run.log` birth-to-mtime 作为 wall-time upper bound；后 6 个 run 使用
  `describe-instances` 的 launch time 和 termination reason。
- true all-on 中 `PRFM` 命中 33/34 个 benchmark，容易误导 family scope 解释。报告中明确区分
  true all-on 组合效果和 family-only 因果效果。
- 本实验只修改文档和实验记录，不修改 LLVM / runner / module，因此不需要重跑 build 或 benchmark。

## 后续

下一步建议：

1. 默认 selector policy 只考虑有稳定正向证据且语义风险低的 subset，不能简单采用 true all-on。
2. 把 `PRFM` 继续保持 default disabled，除非有 corpus 或 workload-specific evidence。
3. 如果目标是论文级结论，需要扩大样本数、固定 instance / CPU 条件，并加 confidence interval。
4. 如果目标是工程默认策略，可以先做 “candidate default policy” attribution：排除 PRFM/MOV，
   只打开 `EXTR`、selected `LDR`、必要 ABI-safe subset。

## 收尾一致性复查

已回看：

- 本实验所有 9 个 attempt 的 exit code 和 result dir。
- 本实验 object isolation：`analysis/object-group-summary.tsv`、`analysis/object-family-summary.tsv`。
- 前序相关实验：
  - `/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-existing-abi-same-llc-attribution`
  - `/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-prfm-disabled-combined-attribution`
  - `/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-family-only-same-llc-attribution`
- 相关公开报告：
  - `/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/report.md`
  - `/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/family-only/report.md`
- 相关本地规划文档：
  - `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/implementation-plan.md`
  - `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/experiment-matrix.md`

发现和处理：

- 旧报告只说明 single-run combined / family-only attribution，不能回答 “true all-on 多轮是否稳定”。
  本实验已补齐该缺口，并新增公开整理报告。
- 已同步更新 `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/implementation-plan.md` 和
  `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/experiment-matrix.md`，把 2026-05-28 true
  all-on 3 轮结果列入当前状态。
- 已同步更新 `/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/report.md`，
  指向 2026-05-28 true all-on 公开报告，避免旧大报告仍停留在 single-run attribution 状态。
- 未发现需要删除的临时代码或 workaround。
- 未修改 LLVM / runner / module / benchmark framework code，因此不需要重跑实验。
