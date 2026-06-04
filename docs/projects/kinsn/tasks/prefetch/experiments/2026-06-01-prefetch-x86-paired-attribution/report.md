# 2026-06-01 prefetch-x86-paired-attribution

## 结论

本实验完成，状态是 `completed_preliminary_not_default_ready`。

这次实验回答的问题是：在 x86 kernel JIT runtime 上，当前 Kinsn prefetch policy 是否能把
`bpf_x86_prefetcht0` 稳定插入到两个 representative micro benchmark，并带来可解释的性能收益。

结论：

- correctness / codegen：通过。两个 treatment 都正确运行，每个 sample 都插入 1 个
  `PREFETCHT0`，JIT dump 中能看到实际 native `prefetcht0`。
- `prefetch_packet_first_deref`：不是稳定收益。`exec_ns` median 是 `0.964235x`，但
  `wall_exec_ns` / `exec_cycles` median 都是约 `1.264x`，两个计时源方向相反，不能作为 win。
- `prefetch_map_page_stride`：有弱 positive signal。`exec_ns` median 是 `0.981004x`，
  `wall_exec_ns` / `exec_cycles` median 是约 `0.846x`。但这里只有一轮 independent pair，
  还不能作为默认启用依据。
- 当前结论仍是：x86 `PREFETCHT0` path 可以作为 selector v2 的 candidate evidence，
  但不能默认启用 prefetch family。

## 实验问题

Kinsn prefetch 和替换型 kinsn 不同。替换型 kinsn 通常把语义等价的 BPF sequence 替换成更短
native 指令；prefetch 是额外插入 cache hint：

```text
control:
  load [ptr]

treatment:
  prefetcht0 [ptr]
  load [ptr]
```

因此本实验必须同时确认三件事：

1. `bpfopt --pass prefetch` 是否实际插入 prefetch kinsn。
2. kernel JIT native 是否真的出现 x86 `prefetcht0`。
3. 插入 hint 后 runtime 是否稳定变好，而不是只增加指令和 code size。

本实验只看 x86 Kinsn prefetch，不是 ARM LLVM backend，也不是普通 LLVM `llvm.prefetch`。

## 命令

以下命令都从顶层 workspace 执行：

```bash
cd /home/ruoji/github/bpf-opt

BPFREJIT_BENCH_PASSES=noop \
  /home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  BENCH=prefetch_packet_first_deref \
  RUNTIMES=kernel SAMPLES=5 WARMUPS=1 INNER_REPEAT=10000

BPFREJIT_BENCH_PASSES=prefetch \
  /home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  BENCH=prefetch_packet_first_deref \
  RUNTIMES=kernel SAMPLES=5 WARMUPS=1 INNER_REPEAT=10000

BPFREJIT_BENCH_PASSES=noop \
  /home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  BENCH=prefetch_map_page_stride \
  RUNTIMES=kernel SAMPLES=5 WARMUPS=1 INNER_REPEAT=10000

BPFREJIT_BENCH_PASSES=prefetch \
  /home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  BENCH=prefetch_map_page_stride \
  RUNTIMES=kernel SAMPLES=5 WARMUPS=1 INNER_REPEAT=10000
```

所有 benchmark 都通过 Makefile wrapper 运行，没有直接调用底层 Python、Docker、Cargo 或 runner
binary。

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS EC2
- arch：x86_64
- instance type：`t3.small`
- region：`us-east-1`
- remote user：`ec2-user`
- root volume：`32 GiB gp3`
- runtime：kernel
- kernel：`7.0.0-rc2+`
- CPU：`Intel(R) Xeon(R) Platinum 8259CL CPU @ 2.50GHz`
- runner setting：`SAMPLES=5 WARMUPS=1 INNER_REPEAT=10000`
- treatment pass：`BPFREJIT_BENCH_PASSES=prefetch`
- control pass：`BPFREJIT_BENCH_PASSES=noop`

Instance：

| case | instance id | state | AWS wall seconds |
|---|---|---|---:|
| packet control | `i-00d62f08414877ff4` | terminated | 291.4 |
| packet treatment | `i-01b1d5f77d84533b9` | terminated | 349.9 |
| map control | `i-0edb42554e24149e0` | terminated | 376.2 |
| map treatment | `i-005f003924fb6631a` | terminated | 324.0 |

活跃 x86 instance 查询结果为空：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/data/aws-active-x86-instances.json
```

## 文件改动

本实验没有修改代码、runner、micro framework 或 benchmark 程序。

新增 / 更新：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/data/aws-results/`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/data/aws-logs/`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/data/aws-instance-state.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/data/aws-active-x86-instances.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/data/aws-price-t3-small-linux-us-east-1.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/data/aws-price-gp3-us-east-1.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/analysis/*.tsv`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`

## 数据文件

Raw result 副本：

- `data/aws-results/aws_x86_micro_20260601_222520_226332`
- `data/aws-results/aws_x86_micro_20260601_223237_631554`
- `data/aws-results/aws_x86_micro_20260601_224018_661551`
- `data/aws-results/aws_x86_micro_20260601_224712_350691`

Remote log 副本：

- `data/aws-logs/micro_z3p_20260601_222519.remote.log`
- `data/aws-logs/micro_rioire_20260601_223235.remote.log`
- `data/aws-logs/micro_p4_20260601_224016.remote.log`
- `data/aws-logs/micro_wg9090_20260601_224710.remote.log`

Analysis：

- `analysis/raw-samples.tsv`：每个 sample 的 raw measurement。
- `analysis/summary.tsv`：每个 case 的 median / mean / min / max。
- `analysis/pair-ratio.tsv`：treatment median / control median。
- `analysis/codegen-evidence.tsv`：pass counter 和 JIT `prefetcht0` count。
- `analysis/aws-cost-summary.tsv`：instance wall time 和费用估算。
- `analysis/*-treatment-jit-prefetch-snippet.txt`：treatment sample00 的 JIT snippet。

## 指标解释

- `exec_ns`：runner 从 kernel runtime 收集的 ktime 计时，单位 ns。
- `wall_exec_ns`：runner 从 rdtsc wall timing 派生的计时，单位 ns。
- `exec_cycles`：runner 从 rdtsc 和 TSC frequency 派生的 cycles。
- `jited_prog_len`：kernel JIT native code bytes。
- `xlated_prog_len`：kernel xlated BPF bytecode bytes。
- `treatment/control`：同一 benchmark 中 treatment median 除以 control median。小于 1 表示
  treatment 更快或更小，大于 1 表示 treatment 更慢或更大。

这次 `exec_ns` 和 `wall_exec_ns` 对 packet case 给出相反方向，因此 packet 不能按单一指标宣布 win。

## 结果

### Runtime summary

| bench | condition | median `exec_ns` | median `wall_exec_ns` | median `exec_cycles` | JIT bytes | xlated bytes |
|---|---|---:|---:|---:|---:|---:|
| `prefetch_packet_first_deref` | control | 2125 | 5538 | 13846 | 592 | 1080 |
| `prefetch_packet_first_deref` | treatment | 2049 | 6999 | 17498 | 595 | 1096 |
| `prefetch_map_page_stride` | control | 7949 | 12999 | 32497 | 494 | 920 |
| `prefetch_map_page_stride` | treatment | 7798 | 11000 | 27500 | 498 | 936 |

### Treatment / control ratio

| bench | `exec_ns` | `wall_exec_ns` | `exec_cycles` | JIT bytes | xlated bytes |
|---|---:|---:|---:|---:|---:|
| `prefetch_packet_first_deref` | 0.964235 | 1.263814 | 1.263758 | 1.005068 | 1.014815 |
| `prefetch_map_page_stride` | 0.981004 | 0.846219 | 0.846232 | 1.008097 | 1.017391 |

Interpretation：

- packet case：`exec_ns` 看起来快 3.58%，但 wall/cycles 慢 26.38%。该 case 不能作为稳定收益。
- map case：三个指标方向一致为 treatment 更快，但只有一轮 independent pair，且 code size 增加。
  它是 weak positive signal，不是 default policy 证据。

### Codegen evidence

| bench | condition | `prefetcht0` per sample | pass sites applied | BPF insn delta |
|---|---|---|---|---|
| `prefetch_packet_first_deref` | control | `0,0,0,0,0` | - | - |
| `prefetch_packet_first_deref` | treatment | `1,1,1,1,1` | `1,1,1,1,1` | `2,2,2,2,2` |
| `prefetch_map_page_stride` | control | `0,0,0,0,0` | - | - |
| `prefetch_map_page_stride` | treatment | `1,1,1,1,1` | `1,1,1,1,1` | `2,2,2,2,2` |

Packet treatment JIT snippet：

```asm
  90: 48 01 fe              add    %rdi,%rsi
  93: 0f 18 0e              prefetcht0 (%rsi)
  96: 48 0f b6 46 40        movzbq 0x40(%rsi),%rax
```

Map treatment JIT snippet：

```asm
  fd: 4d 01 f7              add    %r14,%r15
 100: 41 0f 18 0f           prefetcht0 (%r15)
 104: 49 0f b6 4f 00        movzbq 0x0(%r15),%rcx
```

因此，treatment 确实执行了当前 prefetch pass，并且 kernel JIT native path 确实生成了
`prefetcht0`。

## AWS 费用

价格来源保存为 AWS Pricing API raw response：

- `data/aws-price-t3-small-linux-us-east-1.json`
- `data/aws-price-gp3-us-east-1.json`

估算口径：

- EC2：On-Demand Linux `t3.small`，`us-east-1`，`$0.0208 / hour`。
- EBS：gp3，`us-east-1`，`$0.08 / GB-month`。
- root volume：`32 GiB`，来自 `AWS_X86_ROOT_VOLUME_GB=32`。
- 不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

逐 instance 和总估算见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/analysis/aws-cost-summary.tsv
```

本次估算总成本：`$0.009058`。

## 问题和处理

- `prefetch_packet_first_deref` 的 `exec_ns` 和 `wall_exec_ns`/`exec_cycles` 指标方向相反。
  处理：报告中分开列两个计时源，不把 packet case 计入稳定 win。
- 当前没有收集 PMU counters。处理：本实验只作为 paired attribution，不作为 paper-grade
  memory-system 归因。
- 每个 condition 只有一轮 AWS instance。处理：结论限定为 preliminary。后续如果要把 map case
  纳入 selector v2，需要做 multi-run independent rerun。

## 后续

下一步应该做 x86/ARM64 同构对比和 selector v2 决策：

1. 对 `prefetch_map_page_stride` 做至少 3 轮 independent pair rerun，确认 weak positive 是否稳定。
2. 如果 x86 map case 稳定为正、ARM64 仍为负，则把 selector policy 设为架构相关，不做跨架构默认。
3. 如果 x86 rerun 也不稳定，则 prefetch family 继续保持 forced-only / research-only。
4. 如果要继续探索收益，需要新增更能产生 cold miss 和 lead time 的 micro，而不是只在现有
   small-packet / simple-map case 上调 selector。

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-candidate-filtering-micro-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-indirect-timeliness-micro-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-large-working-set-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-raw-loader-fix/report.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`

发现和处理：

- prefetch task 文档还没有记录 x86 paired attribution。已更新。
- 本实验没有修改 code repo 行为，因此不需要重跑 ARM64 或 x86 micro。
- 当前实验目录是非 phase 顶层目录，符合 `YYYY-MM-DD-experiment-name` 命名规则。
- raw result、remote log、instance state、pricing raw response 和 analysis 文件都已复制到本实验目录。
- AWS x86 活跃 instance 查询为空，四个本次 instance 均为 `terminated`。
