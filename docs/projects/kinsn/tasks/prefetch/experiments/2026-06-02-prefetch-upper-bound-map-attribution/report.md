# 2026-06-02 prefetch-upper-bound-map-attribution

## 结论

本轮新增了一个更偏向 prefetch 的 synthetic-control micro：
`prefetch_upper_page_stride`。它使用 1 MiB map value、page-stride 访问、profile 指定目标
PC 62，并在 demand load 前放入独立 ALU work，目的是回答：

```text
如果 test case 本身更适合 prefetch，当前 profile-gated map-value policy 是否能稳定变快？
```

结论是：仍然没有稳定 positive。

| arch | control mean ns | treatment mean ns | mean ratio | control median ns | treatment median ns | median ratio | paired geomean ratio | nominal speedup |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| x86 | 8809.2 | 8792.4 | 0.998093 | 8775 | 8700 | 0.991453 | 0.998018 | 0.199% |
| ARM64 | 16603.2 | 16725.4 | 1.007360 | 16518 | 16694 | 1.010655 | 1.007389 | -0.734% |

解释：

- x86 只有约 0.2% nominal speedup，5 个 sample 的 pair ratio 方向不稳定，属于 noise-level。
- ARM64 是约 0.7% slowdown。
- treatment 都确实 applied 1 个 prefetch site；这不是 selector 没触发。
- BPF bytecode 增加 16 B；x86 native 增加 3 B，ARM64 native 增加 8 B。

因此，问题不只是“之前的 micro case 太容易 / 对 prefetch 不敏感”。即使在这个 upper-bound
case 上，当前 **same-iteration map-value prefetch** 也没有证明自己能稳定隐藏 memory latency。
后续如果继续做 prefetch，应优先尝试更本质不同的策略，例如 next-iteration / software-pipeline
prefetch，而不是继续微调当前同一 load 前的 fixed-distance placement。

当前结论：

```text
Kinsn prefetch 仍保持 profile-gated / research-only，不能 default-enable。
```

## 实验问题

前序实验已经说明：

- structural-only prefetch policy 不稳定。
- profile-fed `prefetch_map_page_stride` 有 weak positive signal，但 PMU attribution 在默认 AWS
  环境下不可用。
- 现有 micro 可能没有充分暴露 cold working-set 和 lead-time。

本实验专门补一个 best-case / upper-bound micro，检查“case 不够敏感”是不是主要 blocker。

## Micro 设计

新增程序：

```text
/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c
/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.md
```

manifest：

```text
/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml
```

case：

```text
prefetch_upper_page_stride
```

设计目标：

- `io_mode: map`，输入放在 1 MiB `input_map` value 中，而不是 1400-byte XDP packet。
- 每轮访问跨 page / cacheline 的 offset，避免普通 tiny packet case 全部 hot。
- 使用 `volatile` byte loads 组装 `u64`，避免 clang 把 demand load 提前 hoist 到 independent work 前。
- 在 demand load 前加入 independent ALU work，给 prefetch hint 留出 lead time。
- profile 文件只允许 PC 62 通过 admission：

```text
/home/ruoji/github/bpf-opt/code/micro/config/prefetch-upper-page-stride-profile-pc62.json
```

profile：

```json
{
  "map_value_pcs": [62]
}
```

这个 micro 不是从真实 BPF program 提取的 case。它是 synthetic-control upper-bound probe，用于验证
当前 prefetch policy 在一个更友好的工作负载上是否至少能稳定变快。

## 实现改动

本轮发现旧 map-value scanner 不适合 clang loop rotation 后的 CFG 形态。

旧逻辑：

```text
bpf_map_lookup_elem 后，按 BPF instruction linear order 向后扫描固定窗口。
```

问题：

- 新 micro 被 clang 编译成 loop-shaped CFG。
- map value pointer 的恢复和 demand load 不在简单线性后继关系里。
- 旧 scanner 能看到 0 个 map-value prefetch site。

修复：

```text
改为 CFG/dataflow map-value alias propagation。
```

具体改动文件：

- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c`
- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.md`
- `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-upper-page-stride-profile-pc62.json`
- `/home/ruoji/github/bpf-opt/code/runner/libs/input_generators.py`

修复后本地 `bpfopt` 结果：

| mode | sites matched | sites applied | sites skipped | BPF insn before | BPF insn after |
|---|---:|---:|---:|---:|---:|
| no profile | 8 | 0 | 8 | 250 | 250 |
| profile PC 62 | 8 | 1 | 7 | 250 | 252 |

## 命令

本地验证：

```bash
make -C code/micro/programs \
  OUTPUT_DIR=/tmp/bpf-opt-prefetch-upper-build \
  /tmp/bpf-opt-prefetch-upper-build/prefetch_upper_bound.bpf.o
```

```bash
cargo test --manifest-path code/bpfopt/Cargo.toml --release -p bpfopt prefetch
```

```bash
cargo build --manifest-path code/bpfopt/Cargo.toml --release -p bpfopt -p kinsnprober
```

AWS x86 control / treatment：

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  RUN_TOKEN=upper-x86-control \
  BENCH=prefetch_upper_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=1000
```

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  RUN_TOKEN=upper-x86-treatment \
  BENCH=prefetch_upper_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=1000 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-upper-page-stride-profile-pc62.json'
```

AWS ARM64 control / treatment：

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUN_TOKEN=upper-arm64-control \
  BENCH=prefetch_upper_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=1000
```

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUN_TOKEN=upper-arm64-treatment \
  BENCH=prefetch_upper_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=1000 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-upper-page-stride-profile-pc62.json'
```

前置 x86 smoke 各跑过一次 `SAMPLES=1 WARMUPS=0 INNER_REPEAT=100`，只用于确认 runtime
correctness 和 pass args propagation，不作为性能结论。

## 环境

| arch | instance | runtime | kernel | samples | warmups | inner repeat |
|---|---|---|---|---:|---:|---:|
| x86 | `t3.small` | kernel micro | `7.0.0-rc2+` | 5 | 1 | 1000 |
| ARM64 | `t4g.small` | kernel micro | `7.0.0-rc2+` | 5 | 1 | 1000 |

路径：

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- AWS region：`us-east-1`
- benchmark：`prefetch_upper_page_stride`
- expected result：`10526166669351037997`

## 数据文件

Raw AWS result 副本：

- `data/aws-results/aws_x86_micro_20260602_084029_398969`
- `data/aws-results/aws_x86_micro_20260602_085326_619208`
- `data/aws-results/aws_x86_micro_20260602_090051_077465`
- `data/aws-results/aws_x86_micro_20260602_090833_041103`
- `data/aws-results/aws_arm64_micro_20260602_091609_963089`
- `data/aws-results/aws_arm64_micro_20260602_092216_529142`

Analysis：

- `analysis/run-summary.tsv`
- `analysis/sample-results.tsv`
- `analysis/bpfopt-sites.tsv`
- `analysis/paired-comparison.tsv`
- `analysis/aws-instances.tsv`

Run contract：

- `data/run-contract.json`

## 结果

Raw `exec_ns` samples：

| arch | variant | samples |
|---|---|---|
| x86 | control | `8706, 8764, 8946, 8775, 8855` |
| x86 | treatment | `8696, 9045, 8700, 8830, 8691` |
| ARM64 | control | `16796, 16518, 16410, 16775, 16517` |
| ARM64 | treatment | `16621, 16836, 16694, 16824, 16652` |

Per-sample paired ratios：

| arch | treatment/control ratios |
|---|---|
| x86 | `0.998851, 1.032063, 0.972502, 1.006268, 0.981479` |
| ARM64 | `0.989581, 1.019252, 1.017307, 1.002921, 1.008173` |

Code size：

| arch | BPF control | BPF treatment | native control | native treatment |
|---|---:|---:|---:|---:|
| x86 | 2048 B | 2064 B | 1004 B | 1007 B |
| ARM64 | 2048 B | 2064 B | 1256 B | 1264 B |

Prefetch admission：

| arch / run | sites matched | sites applied | sites skipped | BPF insn delta |
|---|---:|---:|---:|---:|
| x86 treatment smoke | 8 | 1 | 7 | +2 |
| x86 treatment multi | 8 | 1 | 7 | +2 |
| ARM64 treatment multi | 8 | 1 | 7 | +2 |

## 问题和处理

### 中断尝试

两次早期 AWS smoke 被手动中断：

- `i-050a52770a502a91b`：x86 control smoke，remote setup 中断。
- `i-01098217013a60c02`：x86 treatment smoke，Docker install 阶段中断。

两个 instance 都已 terminated，并记录在 `analysis/aws-instances.tsv`。

### 旧 map-value scanner 漏掉 CFG 形态

本地检查发现旧 scanner 在新 micro 上 `sites_matched=0`。原因是旧逻辑只做 linear forward scan；
新程序经过 clang loop rotation 后，map value pointer alias 和 demand load 需要跨 basic block
传播。

处理：把 map-value tracking 改成 CFG/dataflow alias propagation。修复后 profile PC 62 能稳定
applied 1 个 site。

## AWS 时间和费用

价格沿用前序实验通过 AWS Pricing API 查询到的 `US East (N. Virginia)` Linux on-demand 价格：

- `t3.small`：`$0.0208/hour`
- `t4g.small`：`$0.0168/hour`
- EBS root volume：按 General Purpose SSD gp2 `32 GiB * $0.10/GB-month` 保守估算。

| group | instance seconds | compute USD |
|---|---:|---:|
| x86 `t3.small` | 1627 | 0.009401 |
| ARM64 `t4g.small` | 601 | 0.002805 |
| EBS estimate | 2228 | 0.002751 |

估算合计：`$0.014957`。

费用不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。
所有 instance 均已 terminated。

## 收尾一致性复查

已回看：

- `docs/projects/kinsn/tasks/prefetch/plan.md`
- `docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- 前序实验：
  - `2026-06-02-prefetch-profile-fed-map-value-attribution`
  - `2026-06-02-prefetch-profile-fed-map-value-pmu-attribution`
  - `2026-06-01-prefetch-selector-v3-policy-smoke`

发现和处理：

- policy matrix 仍把 map-value scanner 描述成固定线性 lookahead；已更新为 CFG/dataflow。
- plan 还没有记录 upper-bound micro 结果；已更新。
- 本轮改了 `prefetch.rs`，因此已重跑 Rust prefetch tests、本地 object build、x86/ARM64 AWS
  paired micro。

## 后续

1. 不把当前 same-iteration map-value prefetch default-enable。
2. 如果继续研究 prefetch，应优先设计 next-iteration / software-pipeline prefetch：提前为下一轮
   地址发 hint，而不是对当前轮 demand load 做 late prefetch。
3. 若要证明 cache miss reduction，需要换 PMU-capable 环境；当前默认 AWS micro 环境已确认不能做
   cache-miss attribution。
