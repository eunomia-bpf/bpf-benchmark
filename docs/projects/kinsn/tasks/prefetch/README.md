# Kinsn Prefetch Task

最后更新：2026-06-02。

## 结论

`PREFETCHT0` / `PRFM` 的 Kinsn 通路已经打通：`bpfopt` 能在 BPF bytecode 里插入
`KINSN_SIDECAR + KINSN_CALL`，kernel kinsn JIT 能把它们翻译成 x86 `prefetcht0` 或
ARM64 `prfm pldl1keep`。但是当前 prefetch 还不能默认启用。

原因是 prefetch 是 **插入型优化**。它不会替换原始 load，而是在原始 load 前额外插入一个
cache hint。已有实验显示，简单地“在 load 前插 prefetch”大多没有稳定收益。当前最有希望的
策略是 **next-iteration prefetch**，即第 `i` 轮提前预取第 `i+1` 轮会用到的 pointer。该策略
在 ARM64 上两轮都显示 treatment 更快，但幅度不稳定：第一轮 treatment/control 是 `0.858777`，
独立 rerun 是 `0.962181`。

因此当前状态是：

```text
prefetch = research-only / profile-gated candidate
default policy = disabled
```

## 背景：prefetch 和替换型 kinsn 的区别

Kinsn 的共同机制是：BPF object 中用 sidecar 携带 payload，再用 kinsn call 指定目标 kfunc。
Verifier 仍检查普通 BPF 语义，目标架构 JIT 在 verifier 之后生成 native instruction。

多数 kinsn family 是替换型优化：

```text
BPF sequence:
  shift + shift + or

native execution:
  rotate/extr instruction
```

这种优化的性能逻辑通常是 native 指令更少、dependency 更短。

Prefetch 不同：

```text
control:
  load *(ptr)

treatment:
  KINSN_SIDECAR(ptr_reg)
  KINSN_CALL(bpf_x86_prefetcht0 or bpf_arm64_prfm_pldl1keep)
  load *(ptr)
```

也就是说，treatment 保留原始 load，并额外增加 native hint：

| arch | kfunc target | native hint |
|---|---|---|
| x86 | `bpf_x86_prefetcht0` | `prefetcht0 [rN]` |
| ARM64 | `bpf_arm64_prfm_pldl1keep` | `prfm pldl1keep, [xN]` |

因此 prefetch 只有在下面条件同时满足时才可能变快：

- 目标地址大概率不在目标 cache 中。
- prefetch 到 demand load 之间有足够 lead time。
- 插入点已经在 verifier-safe bounds/null check 之后。
- 额外 hint 不造成明显 frontend、bandwidth 或 cache pollution 成本。

## 当前实现

主要实现路径：

```text
/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs
```

运行路径：

```text
BPF object
  -> runner 读取 object
  -> 如果设置 BPFREJIT_BENCH_PASSES=prefetch，先调用 bpfopt
  -> bpfopt 输出 transformed raw BPF bytecode
  -> raw kinsn loader 加载 BPF
  -> kernel kinsn JIT emit native prefetch hint
  -> micro kernel runtime 测量 execution time
```

已实现能力：

| component | 实现内容 |
|---|---|
| `bpfopt` prefetch pass | packet/map pointer tracking、stack alias、register offset、same-cacheline dedup、site budget。 |
| profile gate | `bpfopt --pass prefetch -- --profile FILE`，只允许 profile 指定的 map-value PC 或 prefetch point。 |
| micro kernel runtime | 支持先应用 `bpfopt` pass，再加载 raw kinsn BPF。 |
| raw kinsn loader | 支持 BTF `.maps` 和 map relocation。 |
| micro benchmark | 新增 packet、map、upper-bound、next-iteration strategy probes。 |

## 策略如何实现

当前 prefetch policy 是 BPF bytecode-level selector。它扫描 BPF instruction，判断哪些 memory
access 值得插入 prefetch kinsn。

| policy | 实现方式 | 当前结果 |
|---|---|---|
| verifier-safe insertion | 只在同一 basic block 内插入；插入窗口不能跨 call、jump、exit 或 pseudo func。 | correctness 通过。 |
| pointer register stability | 插入点到 target load 之间，prefetch 使用的 register 不能被重定义。 | correctness 通过。 |
| packet pointer tracking | 从 packet `data` / `data_end` 派生 pointer fact，追踪 MOV、ADD/SUB、stack spill/reload。 | 能识别 packet load。 |
| map value tracking | 识别 `bpf_map_lookup_elem` 返回的 `r0`，通过 CFG/dataflow 传播 map-value alias。 | 结构可识别，但默认不应用。 |
| load-only filtering | 只对 `BPF_LDX` read load 插入，不对 store 插入。 | 降低误报。 |
| same-cacheline dedup | 同一 pointer / cacheline 多个 load 只保留一个 candidate。 | 已实现。 |
| dependent depth | `packet load -> scalar index -> final deref` 只允许 depth 1；depth 0 和 depth > 1 默认跳过。 | selector v3 行为正确。 |
| profile gate | map-value load 只有 profile allow-list 或 profile point 指定时才应用。 | admission 可控，但性能仍不稳定。 |
| next-iteration point | profile 指定某个 BPF PC 和 live register，表示这里已有下一轮 pointer。 | 当前最有希望，但还不是自动 selector。 |

## Micro benchmark 是什么

`micro` 是 isolated pure-JIT benchmark。它不是 corpus，也不是 end-to-end app。它的目的不是证明
真实应用收益，而是控制某种 BPF code shape，观察 control 和 treatment 的 native code 与 runtime
差异。

每个 prefetch micro 都包含：

- BPF C program，例如 `prefetch_research.bpf.c`。
- manifest entry：`/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`。
- deterministic input generator。
- expected result。
- source type：当前 prefetch probes 都是 `synthetic-control`，用于策略筛选，不是 real-derived case。

典型实验流程：

```text
control:
  运行同一个 micro benchmark，不应用 prefetch pass

treatment:
  设置 BPFREJIT_BENCH_PASSES=prefetch
  可选：设置 BPFREJIT_BENCH_PASS_ARGS='--profile ...'
  runner 调用 bpfopt，把 prefetch kinsn 插入 raw BPF
  kernel JIT 生成 prefetcht0 / prfm

analysis:
  检查 sites_applied、native JIT dump、BPF/native code size、exec_ns 或 wall/cycles
  计算 treatment/control ratio
```

ratio 小于 `1` 表示 treatment 更快。完整实验表见：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md
```

完整 policy matrix 见：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md
```

提交到 repo 的实验 artifact 见：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments/README.md
```

## 已试策略和结论

| strategy | test case | 结论 |
|---|---|---|
| fixed-distance prefetch | `prefetch_distance_0/2/4/8/16/32` | ARM64 geomean T/C `1.004928`，没有稳定收益。 |
| packet candidate filtering | hot、sequential、large-stride、permuted、packet-first-deref | 大多数 mixed；不能 default-enable。 |
| map-backed large working set | `prefetch_map_page_stride` 等 | geomean `1.001694`，约慢 `0.17%`。 |
| selector v3 packet first-deref | `prefetch_packet_first_deref`, `prefetch_single_first_deref` | correctness/codegen 通过，performance mixed。 |
| profile-fed map-value prefetch | profile allow-list 指定 map-value PC | admission 可用；结果 preliminary。 |
| PMU attribution | AWS x86/ARM64 PMU smoke | 当前 AWS micro 环境缺少关键 PMU counters。 |
| same-iteration upper-bound map | `prefetch_upper_page_stride` | x86 noise-level，ARM64 slowdown。 |
| next-iteration prefetch | `prefetch_pipeline_page_stride` | ARM64 positive direction reproduced，但 effect size 不稳定。 |

## 当前判断

不能 default-enable 的原因：

- structural-only policy 没有稳定收益。
- profile-fed map-value prefetch 只说明 admission gate 可用，不说明策略有效。
- default AWS micro 环境不能提供 cache-miss PMU counters，无法证明机制原因。
- P19 next-iteration 仍是 hand-profiled profile point，不是自动 selector。
- P19 在 ARM64 上方向复现，但 effect size 不稳定。

## 下一步

下一步不应扩大 structural-only admission。应该先做：

1. 对 `prefetch_pipeline_page_stride` 做更稳定的 ARM64-only rerun，例如更长 `INNER_REPEAT`。
2. 建 PMU-capable 环境，验证 positive signal 是否对应 cache miss / refill 下降。
3. 设计自动 selector，从 BPF bytecode 中识别 `cur` / `next` pipeline 和合法 insertion point。
4. 设计 real-inspired case 或 corpus site census，确认 P19 是否出现在真实 BPF workload 中。
