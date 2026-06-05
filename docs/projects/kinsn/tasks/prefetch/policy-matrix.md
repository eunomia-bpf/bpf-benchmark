# Kinsn Prefetch 策略矩阵

最后更新：2026-06-05。

## 结论

本文只记录 prefetch 策略分类。`degree`、`horizon`、`hint variant` 不是策略；
它们是策略参数。

Prefetch 策略必须回答：

```text
在什么 BPF memory access pattern 下，对哪个地址插 prefetch，哪些情况明确不插？
```

当前结论：

- `future-address` 类 policy 是当前唯一值得继续推进的方向。
- `same-iteration`、`packet structural default`、`standalone stride-only`、`stream-of-strides`
  degree2 / two-site placement 都不应进入 selector。
- `stream-of-strides` 不能整体拒绝；当前只保留 degree1 / profile-gated weak candidate。
- 下一步不是 integrated prefetcher，而是完成 micro 用例有效性 / PMU 归因收尾。

## 1. 策略和参数的边界

| 类型 | 例子 | 是否策略 | 原因 |
|---|---|---:|---|
| access-pattern policy | MLOP / index-field、spatial-within-page、struct-field、stream-of-strides | 是 | 它们描述“什么访问模式值得预取”。 |
| no-prefetch policy | hot load、sequential stream、dependent chain | 是 | 它们描述“什么访问模式必须跳过”。 |
| selection schema | mixed per-PC policy table | 是 / 元策略 | 它描述“同一 program 内如何按 PC 选择 prefetch 或 skip”。 |
| horizon | `i+1/i+2/i+4` | 否 | 这是 future-address 策略的提前量参数。 |
| degree | 一次插 1/2/3 个 prefetch | 否 | 这是某个策略的激进程度。 |
| hint variant | x86 `t0/t1/t2/nta`，ARM64 `l1/l2 keep/strm` | 否 | 这是 native hint 参数。 |

## 2. 当前策略矩阵

| 策略 | 会加速的代码形态 | 不预取为什么慢 | 代表测试用例 | 当前证据 | 当前状态 |
|---|---|---|---|---|---|
| same-iteration current-address prefetch | 当前没有成立的正向形态；它只覆盖“地址刚算出来马上 load”的当前轮访问。 | 访问本身可以 miss 高，但 prefetch 太晚，无法隐藏 miss。 | `prefetch_upper_page_stride`, `prefetch_map_page_stride` | high-miss 用例下仍几乎不降 miss；T/C 接近 1。 | 拒绝 |
| packet structural prefetch | 当前没有成立的默认正向形态；单纯 packet pointer deref 不是足够条件。 | packet working set 常常小、热、顺序或已被硬件/局部性覆盖；不预取未必慢。 | packet hot/sequential/guarded/first-deref 用例 | 多数基线 miss 低或 timing 中性。 | 拒绝默认启用 |
| packet first-deref prefetch | 理论上需要 final target high-miss，且 target address 能在 demand load 前足够早物化。 | 不预取会慢的前提是 final target 分散且 miss 高；当前 placement 没有足够提前量。 | `prefetch_first_deref_page_stride` | T/C `1.000208`，miss_count_ratio `0.999198`，cycles T/C `1.024748`。 | 拒绝当前 placement |
| map-value same-iteration prefetch | 当前没有成立的正向形态；只是在当前轮 map-value load 前插当前地址。 | map value load 可以 miss 高，但当前轮 prefetch 太晚。 | `prefetch_map_page_stride` | miss 有小降但 timing 中性。 | 拒绝默认启用 |
| future-address single-stream prefetch | loop 第 `i` 轮已经能算出第 `i+1` / `i+2` 轮会访问的 map-value 地址，且访问分散到多个 cache line / page。 | 不预取时，每轮 demand load 都可能在高 miss working set 上停住。 | `prefetch_pipeline_page_stride`, `prefetch_pipeline_horizon*`, `prefetch_degree123_page_stride` | horizon2 / degree1 有 PMU-backed win。 | 候选 |
| stride-only future-address prefetch | 只有 stride 访问同时 high-miss、future address 已提前物化、有足够提前量时才可能加速。 | 不预取慢的原因必须是 stride stream 造成真实 miss；仅有 stride 不代表会慢。 | `prefetch_stride64/256/4096_page_stride` | timing 中性；miss drop 不转化为 time win。 | 拒绝 standalone |
| spatial-within-page prefetch | 已知未来会访问同一 page / region 内多个 offset，例如 future record/page 的多个字段。 | 不预取时，多处 offset 访问会反复触发 cache miss。 | `prefetch_spatial_page_footprint` | T/C `0.971461`，miss ratio `0.000460`，但有 instruction overhead。 | 候选，必须 profile-gated |
| MLOP / index-field prefetch | 地址形如 `base + index + field offset`，且 future index / field address 能提前算出。 | 不预取时，indexed field load 分散且 miss 高。 | `prefetch_mlop_index_field` | T/C `0.945284`，miss ratio `0.019193`。 | 当前最强候选 |
| struct-field fixed-offset prefetch | 程序按 record 扫描固定字段，且能提前算出 future record 的 fixed field addresses。 | 不预取时，future record 的固定字段可能落在冷 cache line 上。 | `prefetch_struct_field_fixed_offsets` | T/C `0.986178`，miss-rate delta `-0.004231`。 | 弱候选 |
| mixed per-PC policy table | 同一个 BPF program 同时有 hot/sequential/no-lead sites 和 high-miss future-address sites。 | 不预取会让 high-miss future-address site 慢；全部预取又会让 hot/no-lead sites 变慢。 | `prefetch_mixed_policy_table` | 1 applied / 16 skipped；T/C `0.977369`。 | schema 候选 |
| stream-of-strides prefetch | 适用于独立 high-miss streams 交错执行，且每个 stream 的 future address 都能足够早知道。 | 不预取时，每个 stream 都可能 miss；但多个 prefetch 会增加指令、带宽和 cache pressure。 | `prefetch_stream_of_strides_high_miss` | degree1 single-site：T/C `0.990870`，miss ratio `0.882631`；degree2 two-site：miss ratio `0.834258` 但 exec/cycles 不赢。 | 只保留 degree1 / profile-gated；拒绝 degree2 two-site |
| no-prefetch / skip policy | hot load、sequential stream、same-cacheline 重复访问、deep dependent-chain、无提前量访问。 | 这些形态不预取通常不慢，或慢也不是 prefetch 能隐藏的 miss。 | `prefetch_hot_l1_load`, `prefetch_sequential_scan`, `prefetch_indirect_two_stage` | 基线 miss 低 / 无有用提前量。 | 保留跳过规则 |

## 3. 参数 matrix

这些结果用于给 policy 选参数，不应写成独立 policy。

| 参数 | 测试对象 | 当前结果 |
|---|---|---|
| horizon | future-address single-stream | horizon2 当前最好；horizon1 太近，horizon4 没有更好。 |
| degree | future-address single-stream / spatial / stream-of-strides | degree1 当前最好；degree2/3 或 two-site stream placement 没超过 degree1。 |
| ARM64 hint | horizon / degree cases | L1 hints 好于 L2 hints。 |
| x86 hint | horizon / degree cases | `nta` 明显慢；`t0/t1/t2` 没稳定大收益。 |
| profile gate | 所有正向候选 | 当前正向候选都依赖 hand-profiled PC/register；不能 default-enable。 |

## 4. Micro gate 状态

| 策略 | 有效性能用例状态 | 后续动作 |
|---|---|---|
| MLOP / index-field | 正向有效 | 保留。 |
| future-address single-stream | 正向有效 | 保留；继续审计 horizon / degree 参数。 |
| spatial-within-page | 正向有效，但有额外指令开销 | 保留 profile-gated。 |
| struct-field fixed-offset | 弱正向有效 | 保留 weak candidate。 |
| mixed per-PC policy table | schema 有效，性能弱正向 | 保留 schema；不当作最强性能用例。 |
| stream-of-strides degree1 | 正向有效，弱收益 | 保留 profile-gated weak candidate。 |
| same-iteration current-address | 负向有效 | 不继续投入，除非出现新 placement。 |
| packet first-deref | PMU attribution 已完成；高 miss 但当前 placement 不降 miss | 已明确排除当前 placement。 |
| stream-of-strides degree2 / two-site | high-miss diagnostic completed；miss 下降但 exec/cycles 不赢 | 若继续研究 degree>1，需要重构 scheduling / placement 后重测。 |
| stride-only | 诊断用例已完成；standalone 不赢 | 保持 reject standalone。 |
| packet structural / hot / sequential / dependent | 跳过规则 / 负向对照用例 | 保留为 no-prefetch policy，不作为正向性能用例。 |

## 5. 下一步

当前不进入 integrated prefetcher。下一步是完成 micro 证据收尾：

```text
1. 用本策略分类审计所有 active 用例。
2. 标清每个用例是有效性能用例 / 诊断用例 / 跳过规则用例。
3. 如果重新提出 stream-of-strides degree>1，需要先重构 scheduling / placement，再重新跑 PMU attribution。
4. 更新 technical report / results，确保结果表按策略 + 参数 + 测试用例展示。
```
