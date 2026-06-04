# Kinsn Prefetch Plan

最后更新：2026-06-04。

## 结论

Kinsn prefetch 的最终目标不是保留一组零散 micro policy，而是在 Kinsn 项目里实现一个
profile-assisted software prefetcher：

```text
BPF bytecode
  -> bpfopt prefetch selector 分析 load site
  -> 对每个 site 选择 skip / horizon / spatial / MLOP / degree / hint
  -> 插入 KINSN_SIDECAR + KINSN_CALL
  -> kernel kinsn JIT emit x86 prefetch* 或 ARM64 prfm
```

当前还不能 default-enable。已经证明的是：在 synthetic-control micro 上，部分
profile-fed future-address policy 在 ARM64 `c7g.large` 上有 cache-miss-drop evidence。还没证明的是：
真实 BPF 程序中这些 pattern 足够常见，或者 selector 能自动识别这些 pattern。

## Scope

本 task 只讨论 Kinsn 项目里的 CPU cache prefetch：

```text
/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs
/home/ruoji/github/bpf-opt/code/module/x86/bpf_x86_prefetch.c
/home/ruoji/github/bpf-opt/code/module/arm64/bpf_arm64_prfm.c
```

它不是：

- 普通 LLVM `llvm.prefetch` / `LoopDataPrefetch`。
- Dynamic ReJIT 项目的整体 runtime policy。
- PF-LLM 的 hardware prefetcher ensemble。

PF-LLM 对本 task 的作用是提供 access-pattern taxonomy 和 per-PC policy table 这个设计启发；
当前实现是 Kinsn 子集 / 简化映射，不是 PF-LLM 本身。

## 总体阶段

| stage | 目标 | 当前状态 |
|---|---|---|
| 1. 机制打通 | 让 BPF bytecode 中的 kinsn prefetch call 能被 x86/ARM64 JIT 变成 native hint。 | 已完成。 |
| 2. Safety / admission | 保证插入点 verifier-safe、register stable、不会跨 call/jump/exit，并支持 profile gate。 | 已完成第一版；复杂 CFG dominance 仍待加强。 |
| 3. Policy screening | 对 fixed-distance、same-iteration、horizon、degree、hint variant、PF-LLM-inspired access shape 做 synthetic micro 验证。 | 已完成第一轮，并补齐 struct-field、mixed-policy-table、stream-of-strides 的 ARM64 paired attribution。 |
| 4. PMU attribution | 用能采 `cache_misses` 的 ARM64 AWS instance 验证 positive timing 是否来自 miss 下降。 | 已完成 `c7g.large` 一轮。 |
| 5. Integrated prefetcher | 做 per-PC policy/profile schema，按 site 选择 skip/horizon/spatial/MLOP/degree/hint。 | 已完成最小 `prefetch` / `skip` schema 和 x86 smoke；完整 schema / selector 未完成。 |
| 6. Real coverage | 做 corpus site census，确认真实 BPF 里是否存在足够多 candidate。 | 未完成。 |
| 7. Regression / default decision | 在原本通用 micro 和 corpus 上测集成 selector，决定 default / profile-gated / disabled。 | 未完成。 |

## 已完成的设计结论

### 值得继续追的 policy

这些 policy 在 ARM64 `c7g.large` 上有 PMU-backed evidence：

| policy / case | treatment/control | cache miss ratio | 解释 |
|---|---:|---:|---|
| MLOP/index-field | `0.945284` | `0.019193` | 地址由 index + field offset 组成，并且 future address 已物化。 |
| degree1 | `0.958149` | `0.006768` | 预取一个 future address 比 degree2/3 更好。 |
| horizon2 | `0.961195` | `0.009627` | 提前两个 logical step 比 horizon1 更合理。 |
| pipeline next-iteration | `0.968297` | `0.006868` | 当前轮提前预取下一轮 pointer。 |
| spatial-within-page | `0.971461` | `0.000460` | 同一 future page 内多个 offset 有 miss drop，但有 instruction overhead。 |

这些结果只能支持 `profile-gated candidate`。原因是它们依赖 hand-profiled PC/register，并且都是
synthetic-control micro。

### 不应进入默认策略的 policy

| policy | 当前证据 |
|---|---|
| default structural prefetch | 只在 low-cache-miss 小 case 上有 timing win，不能证明 cache-prefetch 机理。 |
| same-iteration map / upper-bound | c7g PMU 显示 cache miss 没有实质下降。 |
| plain stride64 / stride256 / stride4096 | timing 中性，不能证明独立收益。 |
| x86 `nta` | 在当前 horizon/degree cases 明显变慢。 |
| ARM64 L2 hint default | L2 hints 没有超过 L1 hints。 |

## 下一步计划

### Step 1: 统一 profile schema

目标：把当前 hand-profile JSON 从 allow-list 扩展为 per-PC policy table。

每个 site 至少需要记录：

```text
program / benchmark
BPF PC
register
policy: skip | horizon | spatial | mlop | degree
hint: t0/t1/t2/nta or pldl1keep/pldl1strm/pldl2keep/pldl2strm
degree
horizon
reason
```

成功标准：

- 能表达当前所有 positive candidates。
- 能表达 negative filtering，例如 hot/sequential/no-lead-time/dependent-chain skip。
- profile schema 改动必须有 unit test 和一个 micro smoke。

当前状态：

- 已实现 `map_value_policy_points`。
- 已支持每个 point 的 `action: prefetch | skip`。
- 已有 Rust unit tests。
- 已用 `prefetch_mixed_policy_table` 在 x86 AWS smoke 中验证 schema 能插入 1 个 prefetch point。
- 还没实现完整字段：`policy`、`degree`、`horizon`、`hint`、`reason`。

### Step 2: 补未完成 policy case

优先补：

| item | 当前状态 | 还缺什么 |
|---|---|---|
| `struct-field` stable future-pointer profile point | x86 smoke done；ARM64 treatment 插入 3 个 `prfm`；paired T/C `0.959350`。 | PMU-capable rerun，确认 timing positive 是否来自 cache miss 下降。 |
| `mixed-policy-table` treatment | schema done；x86 smoke done；ARM64 treatment 插入 1 个 `prfm` 并 skip 16 个 site；paired T/C `0.990555`。 | 完整 policy metadata 字段；不优先做 PMU，因为 timing 接近 noise-level。 |
| `stream-of-strides` case | case/profile done；x86 smoke done；ARM64 treatment 插入 2 个 `prfm`；paired T/C `1.553949`。 | Slowdown 归因；若不能解释并修正，默认从 candidate set 排除。 |

### Step 3: Corpus site census

目标：回答真实 BPF 中是否存在这些 shape。

需要统计：

- map-value load sites 数量。
- packet first-deref sites 数量。
- future pointer 是否能在 BPF bytecode 中提前物化。
- spatial/MLOP/degree1-like pattern 是否存在。
- 哪些 site 只适合 skip。

成功标准：

- 输出 per-program / per-site TSV。
- 每个候选 site 标注 pattern、是否 verifier-safe、是否需要 profile。
- 不把 synthetic micro 结果直接外推到真实程序。

### Step 4: 集成 profile-assisted selector

目标：让 `bpfopt --pass prefetch -- --profile FILE` 按 per-PC policy table 插入 prefetch。

成功标准：

- positive policy 只在 profile 指定 site 生效。
- negative site 明确 skip。
- 每个 transformed program 输出 `sites_matched / sites_applied / skip_reason`。
- x86/ARM64 object/JIT smoke 均能看到对应 native hint。

### Step 5: 评估集成效果

必须分三层跑：

| level | 目的 |
|---|---|
| targeted synthetic micro | 继续验证每个 policy 的 best-case / controlled behavior。 |
| 原本通用 micro suite | 检查集成 selector 是否误伤普通 BPF code shape。 |
| corpus / real-derived programs | 检查真实覆盖率和真实性能影响。 |

默认启用条件：

- synthetic micro 上有 PMU-backed positive evidence。
- 通用 micro 不出现系统性 regression。
- corpus/site census 证明 pattern 真实存在。
- corpus 或 real-derived run 上至少没有明显 regression。

如果这些条件不满足，prefetch 只能保持 `profile-gated research candidate`。

## 文档和实验入口

Canonical task docs：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/mechanism.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/safety-rules.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-design.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md
```

Experiment artifacts：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments
/home/ruoji/github/bpf-opt/experiments
```

Literature review and source cache：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/literature-review.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/sources
```
