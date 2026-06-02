# 2026-06-01 prefetch-micro-kernel-pass-path-fix

## 结论

本实验完成，状态是 `completed_with_policy_miss`。

这一步修复的是 **micro kernel runtime 的 pass application path**：当设置
`BPFREJIT_BENCH_PASSES=prefetch` 时，`micro` 的 `kernel` runtime 现在会先调用
`bpfopt --pass prefetch` 处理 BPF bytecode，再把生成的 raw BPF bytecode 交给 kernel
test-run loader。修复前，micro kernel runtime 直接加载原始 ELF object，所以 x86
`BPFREJIT_BENCH_PASSES=prefetch` 与 control 生成完全相同的 xlated/native code。

两次 AWS x86 smoke 都完成，并且都生成了 bpfopt artifacts：

- `input.bpf.bin`
- `step1-prefetch.bpf.bin`
- `step1-prefetch.report.json`

但是当前 prefetch policy 对两个 smoke case 都没有命中 site：

| benchmark | status | sites matched | sites applied | BPF insn before | BPF insn after |
|---|---|---:|---:|---:|---:|
| `prefetch_packet_first_deref` | completed | 0 | 0 | 135 | 135 |
| `prefetch_map_page_stride` | completed | 0 | 0 | 109 | 109 |

因此，本实验只证明 micro kernel runtime 的 `bpfopt` 路径已接通；它不证明当前
`PREFETCHT0` policy 有性能收益。

## 实验问题

2026-06-01 的 x86 current-policy micro 尝试发现：`BPFREJIT_BENCH_PASSES=prefetch`
没有作用到 micro kernel runtime，导致 treatment/control 的 BPF xlated 和 native JIT code 完全相同。

本实验要回答：

```text
micro kernel runtime 是否能真实执行 bpfopt --pass prefetch，并把结果作为 kernel test-run 程序加载？
```

这个问题和 prefetch 策略是否有效是两件事：

- pass application path：runner 是否调用 `bpfopt`，并加载处理后的 bytecode。
- prefetch policy：`bpfopt --pass prefetch` 是否能识别具体 BPF pattern 并插入 kinsn。

本实验只修复和验证前者。

## 命令

本地验证：

```bash
cd /home/ruoji/github/bpf-opt
python3 -m py_compile code/micro/driver.py
make -C code host-runner-x86
code/runner/build-llvmbpf/micro_exec --help
```

AWS smoke：

```bash
cd /home/ruoji/github/bpf-opt
BPFREJIT_BENCH_PASSES=prefetch \
  /home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  BENCH=prefetch_packet_first_deref \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=1000
```

```bash
cd /home/ruoji/github/bpf-opt
BPFREJIT_BENCH_PASSES=prefetch \
  /home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  BENCH=prefetch_map_page_stride \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=1000
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS x86
- instance type：`t3.small`
- region：`us-east-1`
- remote user：`ec2-user`
- root volume：32 GiB
- kernel：`7.0.0-rc2+`
- container / runner path：`/home/ruoji/github/bpf-opt/code/runner/build-llvmbpf/micro_exec`
- `bpfopt`：`/usr/local/bin/bpfopt`
- `kinsnprober`：`/usr/local/bin/kinsnprober`

AWS instances：

| benchmark | instance id | launch time UTC | shutting-down observed UTC | final state |
|---|---|---|---|---|
| `prefetch_packet_first_deref` | `i-0416af28c660548d6` | `2026-06-01T10:28:31+00:00` | `2026-06-01T10:34:18.584925+00:00` | terminated |
| `prefetch_map_page_stride` | `i-02a4a531de4405e58` | `2026-06-01T10:36:26+00:00` | `2026-06-01T10:41:37.492448+00:00` | terminated |

费用估算：

- 价格来源：AWS public on-demand pricing checked on 2026-06-01.
  EC2 On-Demand pricing page: `https://aws.amazon.com/ec2/pricing/on-demand/`.
  EBS pricing page: `https://aws.amazon.com/ebs/pricing/`.
- compute 单价假设：`t3.small` Linux on-demand in `us-east-1`，`$0.0208/hour`。
- EBS 单价假设：gp3 `us-east-1`，`$0.08/GB-month`。
- root volume：32 GiB。
- 不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

| instance id | AWS wall time seconds | compute cost | EBS cost | total |
|---|---:|---:|---:|---:|
| `i-0416af28c660548d6` | 347.585 | `$0.002008` | `$0.000343` | `$0.002352` |
| `i-02a4a531de4405e58` | 311.492 | `$0.001800` | `$0.000308` | `$0.002107` |
| total | 659.077 | `$0.003808` | `$0.000651` | `$0.004459` |

## 文件改动

代码改动在 `/home/ruoji/github/bpf-opt/code`：

- `micro/driver.py`
  - 读取 `BPFREJIT_BENCH_PASSES`。
  - 为 kernel runtime 生成 `kinsnprober --out .../target.json`。
  - 把 `--bpfopt-passes`、`--bpfopt-target`、`--bpfopt-workdir`、`--bpfopt-bin`
    传给 `micro_exec test-run`。
  - 在 sample JSON 中记录 `bpfopt_passes`。
- `runner/include/micro_exec.hpp`
  - 新增 bpfopt CLI options。
- `runner/src/common.cpp`
  - 新增 bpfopt CLI 参数解析和校验。
- `runner/src/kernel_runner.cpp`
  - 在 raw-kinsn path 中调用 `bpfopt`。
  - 保存 `input.bpf.bin`、每一步 pass output 和 report。
  - 把 kinsn target JSON 中的 module BTF fd 传给 raw loader。

注意：`runner/src/kernel_runner.cpp` 中的 raw BTF map loader 支持是此前 prefetch map-backed
实验已有改动，本实验是在该基础上增加 bpfopt pass application path；没有回滚已有 dirty
worktree。

文档改动：

- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`
  - 更新 x86 micro path 状态：从 “runner 未应用 pass” 改为 “path 已修复，但当前 policy miss”。

## 数据文件

实验记录目录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-micro-kernel-pass-path-fix
```

raw data 副本：

- `data/run-contract.json`
- `data/code-diff.patch`
- `data/py-compile.log`
- `data/py-compile.stderr.log`
- `data/host-runner-x86.log`
- `data/host-runner-x86.stderr.log`
- `data/micro-exec-help.log`
- `data/micro-exec-help.stderr.log`
- `data/docs-actions-experiments-file-list.txt`
- `data/aws-instance-state.json`
- `data/aws-x86-packet-first-deref-result/`
- `data/aws-x86-packet-first-deref.remote.log`
- `data/aws-x86-map-page-stride-result/`
- `data/aws-x86-map-page-stride.remote.log`

原始同步路径：

- `/home/ruoji/github/bpf-opt/code/micro/results/aws_x86_micro_20260601_103417_746687`
- `/home/ruoji/github/bpf-opt/code/micro/results/aws_x86_micro_20260601_104136_466415`
- `/home/ruoji/github/bpf-opt/code/.cache/aws-x86/results/logs/micro_6lflrkoq_20260601_103415.remote.log`
- `/home/ruoji/github/bpf-opt/code/.cache/aws-x86/results/logs/micro_8bu8_20260601_104134.remote.log`

## 问题和处理

### 原问题

`BPFREJIT_BENCH_PASSES=prefetch` 原本主要服务 Dynamic ReJIT / corpus 路径。micro kernel
runtime 只是把 ELF object 交给 `micro_exec test-run`，没有先执行 `bpfopt`，所以无法用 micro
直接测 “Kinsn prefetch pass 在 kernel runtime 下的 effect”。

这不是当前修复引入的问题，而是 micro runner 原本缺失的实验路径。此前 x86 current-policy
micro 尝试已经暴露了这个问题：treatment/control code size 完全相同，且没有 `bpf_x86_prefetcht0`
或 `prefetcht0` 证据。

### 修复

修复后的路径：

```text
micro driver
  -> kinsnprober 生成 target.json
  -> micro_exec test-run --bpfopt-passes prefetch --bpfopt-target target.json
  -> kernel_runner 读取原始 object
  -> load_program_image 生成 raw BPF bytecode
  -> bpfopt --target target.json --pass prefetch input.bpf.bin step1-prefetch.bpf.bin
  -> raw-kinsn loader 加载 step1-prefetch.bpf.bin
  -> kernel BPF_PROG_TEST_RUN
```

### 当前限制

两个 smoke 都是 `sites_applied=0`。这说明 runner path 已经接通，但当前 prefetch policy 没有识别
这些 micro case。后续要单独定位 `bpfopt` policy 为什么没有命中，而不是继续调 runner。

## 结果

本地验证：

| check | status |
|---|---|
| `python3 -m py_compile code/micro/driver.py` | passed |
| `make -C code host-runner-x86` | passed |
| `micro_exec --help` includes bpfopt flags | passed |

AWS smoke：

| benchmark | AWS result status | exec_ns | retval | xlated bytes | native bytes | bpfopt artifacts | sites applied |
|---|---|---:|---:|---:|---:|---|---:|
| `prefetch_packet_first_deref` | completed | 2382 | 2 | 1080 | 592 | yes | 0 |
| `prefetch_map_page_stride` | completed | 10413 | 2 | 920 | 494 | yes | 0 |

关键证据：

```text
data/aws-x86-packet-first-deref-result/details/bpfopt_runs/prefetch_packet_first_deref__kernel__sample00/step1-prefetch.report.json
data/aws-x86-map-page-stride-result/details/bpfopt_runs/prefetch_map_page_stride__kernel__sample00/step1-prefetch.report.json
```

两个 report 都是：

```text
sites_matched = 0
sites_applied = 0
insn_delta = 0
```

## 后续

下一步应该做 policy-level debug：

1. 对 `prefetch_packet_first_deref` 和 `prefetch_map_page_stride` 运行 bpfopt-side tracing 或增加
   report skip reason，定位为什么当前 pass 没有把它们识别为 candidate。
2. 修复 policy 后，再跑 paired control/treatment：
   - control：同一 runner / same kernel / no prefetch pass。
   - treatment：`BPFREJIT_BENCH_PASSES=prefetch`。
3. 只有当 pass report 显示 `sites_applied > 0`，并且 xlated/native dump 有 `bpf_x86_prefetcht0`
   或 `prefetcht0` evidence，才能解释 performance result。

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-x86-prefetch-current-policy-micro-attribution/report.md`
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`
- 当前新增 raw result 和 bpfopt pass reports。

发现和处理：

- 旧文档仍写着 x86 micro runner 不能应用 `BPFREJIT_BENCH_PASSES=prefetch`。已更新为当前状态：
  runner path 已修复，但当前 policy miss。
- 没有删除既有 raw result。新增实验只复制 raw data 到本实验目录。
- 本实验没有改 prefetch policy，因此不更新 “当前策略无稳定收益” 的总体结论。

是否重跑：

- 已重跑本地 Python compile、host runner build、CLI help check。
- 已跑两个 AWS x86 kernel smoke，覆盖新 pass application path。
- 没有跑 full x86/ARM64 attribution，因为当前 policy 对 smoke case 是 `sites_applied=0`，full
  attribution 还不能回答性能问题。
