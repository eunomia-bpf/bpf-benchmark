# Kinsn Prefetch Policy Matrix

最后更新：2026-06-04。

## 结论

本文只记录真正的 prefetch policy。ABI、JIT emit、runner、loader、PMU smoke、verifier-safe
placement 和 register stability 不属于 policy。

Prefetch policy 必须回答：

```text
1. 对哪个地址 prefetch？
2. 什么时候 prefetch？
3. 提前多远 prefetch？
4. 一次 prefetch 几个未来地址？
5. 用哪个 cache hint variant？
6. 哪些 load 明确不 prefetch？
```

当前 policy-space 还不完整。已经测出并完成 ARM64 PMU attribution 的 candidate 是：

```text
profile-fed future-address prefetch
```

最新 `c7g.large` PMU-backed 结果：

| case | policy | treatment/control | cache miss ratio | 结论 |
|---|---|---:|---:|---|
| `prefetch_mlop_index_field` | MLOP/index-field + ARM64 `l1keep` | `0.945284` | `0.019193` | 当前最强 PMU-backed signal。 |
| `prefetch_degree123_page_stride` degree1 | normalized degree1 + ARM64 `l1keep` | `0.958149` | `0.006768` | degree1 最好；degree 不是越大越好。 |
| `prefetch_pipeline_horizon2_page_stride` | horizon2 + ARM64 `l1keep` | `0.961195` | `0.009627` | horizon2 继续是 strong candidate。 |
| `prefetch_pipeline_page_stride` | next-iteration + ARM64 `l1keep` | `0.968297` | `0.006868` | placement 有 PMU 证据。 |
| `prefetch_spatial_page_footprint` | spatial-within-page + ARM64 `l1keep` | `0.971461` | `0.000460` | miss drop 很大，但有 instruction overhead。 |

PF-LLM-inspired synthetic-control cases 的非 PMU paired attribution 先给出过下面方向：

| policy | case | mean treatment/control | 结论 |
|---|---|---:|---|
| spatial-within-page | `prefetch_spatial_page_footprint` | `0.928342` | 当前最强 PF-LLM-inspired signal |
| MLOP/index-field | `prefetch_mlop_index_field` | `0.962787` | 中等 positive signal |
| page-stride | `prefetch_stride4096_page_stride` | `0.988941` | 弱 signal |
| normalized degree 1/2/3 | `prefetch_degree123_page_stride` | `0.981194` / `0.981286` / `0.985769` | 弱 signal；degree 越大没有越好 |
| stride64 / stride256 | `prefetch_stride64_page_stride`, `prefetch_stride256_page_stride` | `1.004118` / `0.997847` | noise-level，不支持独立收益结论 |

但当前仍不能 default-enable，因为：

- horizon2/horizon4 仍依赖 hand-profiled PC/register；
- `spatial` / `MLOP` 也仍依赖 hand-profiled PC/register；
- 还没有 real-derived / corpus site census 证明真实 BPF 程序中存在足够多这类 shape。
- `struct-field`、`mixed-policy-table`、`stream-of-strides` 已完成 ARM64 paired attribution：
  struct-field 有非 PMU positive timing，mixed-policy 接近 noise-level，stream-of-strides 明显变慢。

## 非 policy 文档

不要把下面内容混进 policy matrix：

| 文档 | 内容 |
|---|---|
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/mechanism.md` | kfunc ABI、`KINSN_SIDECAR + KINSN_CALL`、JIT emit、runner / loader 路径。 |
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/safety-rules.md` | verifier-safe insertion、register stability、load-only、dedup、site budget、profile gate 等 admission rules。 |
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md` | 实验列表、结果、artifact。 |

## 已测 policy

| policy | 问题 | 实现方式 | test cases | 结果 |
|---|---|---|---|---|
| fixed-distance same-iteration | 当前 demand load 前固定距离插 hint 是否有效？ | 在 target load 前最多 16 个 BPF slot 内选择接近 8 slot 的插入点。 | `prefetch_distance_0/2/4/8/16/32` | ARM64 geomean T/C `1.004928`，不支持。 |
| packet structural prefetch | 看到 packet pointer deref 就插是否有效？ | 追踪 packet `data/data_end` 派生 pointer，对 packet load 插入 prefetch。 | hot、sequential、large-stride、permuted、guarded、ring scan | mixed / slowdown，不支持 default。 |
| packet first-deref | `packet load -> scalar index -> final deref` 是否值得插？ | 只允许 dependent depth 1 的 final deref。 | `prefetch_packet_first_deref`、`prefetch_single_first_deref` | correctness 通过，performance mixed。 |
| map-value profile-fed prefetch | 只对 profile 指定 map-value PC 插是否有效？ | profile allow-list 指定 BPF PC 或 PC/register point。 | `prefetch_map_page_stride`、`prefetch_upper_page_stride` | admission 可用，same-iteration 性能不稳定。 |
| same-iteration upper-bound | 1 MiB map + page stride + independent work，仍预取当前轮地址，是否有效？ | 当前轮 demand load 前插 prefetch。 | `prefetch_upper_page_stride` | x86 noise-level，ARM64 slowdown。说明问题不只是旧 case 不敏感。 |
| next-iteration prefetch | 第 `i` 轮预取第 `i+1` 轮 pointer 是否有效？ | micro 显式维护 `cur/next`，profile point 指向 next pointer。 | `prefetch_pipeline_page_stride` | ARM64 三轮 positive；c7g PMU 显示 T/C `0.968297`、cache miss ratio `0.006868`；仍缺自动 selector 和 corpus evidence。 |
| horizon sweep | `i+1/i+2/i+4` 哪个 lead time 更合理？ | profile point 指向不同 future pointer。 | `prefetch_pipeline_horizon1/2/4_page_stride` | ARM64 horizon2/horizon4 + L1 最强；horizon1 不支持。 |
| true degree | 同一轮同时 prefetch 多个 future pointer 是否更好？ | 对 `i+1/i+2/i+4` 三个 future pointers 插多个 hint。 | `prefetch_pipeline_degree_page_stride` | 没超过 single horizon2/horizon4。 |
| hint variant | cache level / temporal / streaming hint 是否影响结果？ | `--hint` 选择 x86 `t0/t1/t2/nta` 或 ARM64 `l1keep/l1strm/l2keep/l2strm`。 | horizon1/2/4 + degree cases | ARM64 L1 hints 最好；x86 `nta` 明显慢；x86 没稳定大收益。 |
| PMU-backed future-address diagnosis | positive timing 是否真对应 cache miss 下降？ | 在 AWS ARM64 `c7g.large` 上采集 `cycles/instructions/cache_references/cache_misses`。 | horizon、pipeline、spatial、MLOP、degree、stride、same-iteration | MLOP、degree1、horizon2、pipeline、spatial 有 miss-drop evidence；plain stride/same-iteration/default structural 不支持。 |

## 明确 skip / no-prefetch policy

这些不是 safety rule，而是性能层面的 no-prefetch decision。

| no-prefetch policy | 依据 | 当前证据 |
|---|---|---|
| no-lead-time skip | prefetch 太接近 demand load，来不及隐藏 miss。 | fixed-distance sweep 没收益。 |
| hot-load skip | 数据大概率已在 L1，hint 只增加成本。 | hot case mixed，不能作为收益证据。 |
| sequential-stream skip by default | 顺序 scan 常被硬件 prefetcher 覆盖。 | sequential case mixed；软件 hint 不应默认插。 |
| dependent-chain skip | 地址依赖前一次 load，地址太晚才知道。 | indirect / two-stage / map-indirect 没稳定收益。 |
| same-iteration map skip by default | 即使 1 MiB map + page stride + independent work，当前轮 prefetch 仍不稳定。 | `prefetch_upper_page_stride` 不支持。 |
| plain-stride skip by default | line/page stride 只说明地址可预测，不保证 miss enough / lead time enough。 | c7g PMU 中 stride64/256/4096 timing 中性，miss ratio 没有转化成稳定收益。 |
| x86 NTA skip | `nta` 在当前 horizon/degree cases 明显慢。 | x86 `nta` 全部新 case 变慢。 |
| ARM64 L2 hint skip by default | L2 hints 弱或慢，未超过 L1 hints。 | variant sweep 中 L1 明显更好。 |

## PF-LLM 中可借鉴的 policy 维度

PF-LLM 的 scope 是硬件 prefetcher ensemble。它不是软件 kinsn pass，也不是直接插入
`prefetch` instruction。它的 offline model 为每个 load PC 生成三个 hint：

1. prefetcher selection：选择哪个 sub-prefetcher；
2. prefetch degree：控制 aggressive 程度；
3. demand request filtering：控制哪些 demand request 不喂给某些 sub-prefetcher。

PF-LLM 的 sub-prefetcher policy space 覆盖：

| PF-LLM 维度 | 例子 | Kinsn 是否可借鉴 |
|---|---|---|
| simple stride | Stride / AMPM / Power7 | 可借鉴；ARM64 PMU attribution 已完成。64B/256B/4096B timing 中性，不支持独立收益结论。 |
| sequential stream | Stream / Next Line | 可借鉴；但当前结果提示默认 skip 更合理，需要 profile 才启用。 |
| fixed offset / stream | Sandbox | 可借鉴；struct-field 已完成 ARM64 paired attribution，T/C `0.959350`，还缺 PMU cache-miss 归因。 |
| spatial within page | Bingo / SMS | 可借鉴；ARM64 PMU attribution 已完成，有 miss-drop evidence，但 instruction overhead 需要控制。 |
| multi-level offset | MLOP | 可借鉴；ARM64 PMU attribution 已完成，是当前最强 timing signal。 |
| irregular spatial | DSPatch / PPF / Pythia | 只能作为 long-term profile-guided idea；Kinsn bytecode pass 当前不适合直接实现复杂硬件预测器。 |
| degree 1/2/3 | conservative / moderate / aggressive | 可借鉴；ARM64 PMU attribution 已完成，degree1 最好，degree 2/3 没超过 degree 1。 |
| demand filtering | 保护 sub-prefetcher 内部状态 | 不能直接照搬；Kinsn 没有硬件 sub-prefetcher state。但可转成 per-load no-prefetch / skip policy。 |
| per-PC hint table | Prefetch Hint Table / Buffer | 可借鉴；Kinsn 已新增 `map_value_policy_points` schema，可表达 per-PC `prefetch` / `skip` action；ARM64 mixed-policy attribution 已跑，完整 `policy/horizon/degree/hint/reason` schema 和 corpus census 仍 pending。 |

## PF-LLM 中不适合直接照搬的内容

| PF-LLM 内容 | 为什么不适合直接用于 Kinsn |
|---|---|
| hardware sub-prefetcher ensemble | Kinsn 是 BPF bytecode 插入 kfunc，不控制硬件 prefetcher ensemble。 |
| PHB/PHT hardware lookup | Kinsn 没有硬件 hint buffer；只能用 offline profile JSON 或 selector。 |
| filtering demand requests into sub-prefetchers | Kinsn 不训练硬件 prefetcher state；只能决定插或不插软件 hint。 |
| ChampSim oracle AMAT label | 我们当前目标是真实 kernel/JIT micro，不是硬件模拟器 AMAT oracle。 |
| L1D-only hardware model | Kinsn 可发 L1/L2 software hint，但真实效果受 kernel/JIT/AWS PMU 可见性影响。 |

## 已加入 case 的 PF-LLM-inspired policy

这些 policy 已经有 synthetic-control micro case。2026-06-03 已完成 x86 / ARM64 control
correctness smoke，并完成 ARM64 paired treatment/control attribution。所有 treatment 都使用
profile-gated `l1keep`，不是自动 selector。

| policy | 如何改成 Kinsn policy | micro case | 当前状态 |
|---|---|---|---|
| stride-class selection | 区分 simple stride、large stride、page stride、variable stride，而不是统一 fixed-distance。 | `prefetch_stride64_page_stride`, `prefetch_stride256_page_stride`, `prefetch_stride4096_page_stride`, `prefetch_variable_stride_page_stride` | ARM64 PMU done；64B/256B/4096B timing 中性，variable 有 miss drop 但 timing 弱。 |
| spatial-within-page policy | 对同一 page / region 的多个 future offsets 发少量 prefetch，而不是单 future pointer。 | `prefetch_spatial_page_footprint` | ARM64 PMU done；T/C `0.971461`，cache miss ratio `0.000460`，但有 instruction overhead。 |
| fixed-offset struct-field policy | 对 map-value struct 中后续 fixed fields 预取。 | `prefetch_struct_field_fixed_offsets` | ARM64 treatment 插入 3 个 `prfm`；paired T/C `0.959350`；值得做 PMU attribution。 |
| multi-level offset policy | 地址由 base + index + offset 组合，且 future index 可提前算。 | `prefetch_mlop_index_field` | ARM64 PMU done；T/C `0.945284`，cache miss ratio `0.019193`。 |
| normalized degree 1/2/3 | 明确 conservative/moderate/aggressive 三档。 | `prefetch_degree123_page_stride` with degree1/2/3 profiles | ARM64 PMU done；degree1 T/C `0.958149` 最好，degree 2/3 没超过 degree 1。 |
| per-PC policy table / negative filtering | 用 profile JSON 或 selector 给每个 PC 选择 policy/hint/degree，并跳过 hot/indirect loads。 | `prefetch_mixed_policy_table` plus existing negative cases | ARM64 treatment 插入 1 个 `prfm`，16 个 site 被 skip；paired T/C `0.990555`；主要证明 schema。 |
| stream-of-strides | 同一 loop 内两个或多个交错 stream 分别选择 prefetch point。 | `prefetch_stream_of_strides` | ARM64 treatment 插入 2 个 `prfm`；paired T/C `1.553949`；当前 policy 明显变慢。 |

## 还没完成的 PF-LLM-inspired policy gate

| pending item | 当前已有 | 还缺什么 | 优先级 |
|---|---|---|---|
| `struct-field` PMU attribution | ARM64 smoke / paired done；T/C `0.959350`。 | `c7g.large` PMU rerun，确认 cache miss 是否下降。 | 高 |
| `mixed-policy-table` complete schema | ARM64 smoke / paired done；T/C `0.990555`；`skip` action 有效。 | profile 字段补全为 `policy/horizon/degree/hint/reason`，而不只是 `prefetch` / `skip`。 | 中 |
| `stream-of-strides` slowdown diagnosis | ARM64 smoke / paired done；T/C `1.553949`。 | JIT/native/PMU 归因，确认变慢来自 instruction overhead、timeliness、cache pollution 还是 case-policy mismatch。 | 中 |
| static-context classification | 只有 synthetic-control cases。 | corpus site census，统计真实 BPF 中 loop shape、map-value base、future pointer availability。 | 中 |
| integrated profile-table schema | `map_value_policy_points` 只支持 `prefetch` / `skip`，尚未记录 `policy/degree/horizon/hint/reason` 全字段。 | 扩展 profile JSON schema 和 bpfopt report。 | 高 |

## Policy 完整性判断

当前 policy 不完整。

已经覆盖：

- 当前轮地址 vs future 地址；
- horizon 1/2/4；
- single vs multi future pointer degree；
- x86 / ARM64 hint variant；
- structural packet/map candidates；
- no-prefetch negative cases；
- PF-LLM-inspired stride-class、spatial-within-page、MLOP/index-field、normalized degree。
- PF-LLM-inspired struct-field、mixed-policy-table、stream-of-strides 的 x86 correctness / emit smoke
  和 ARM64 paired attribution。

仍缺：

- struct-field 的 PMU attribution；
- stream-of-strides 的 slowdown 归因；
- per-PC policy table 的完整字段，不只是 `prefetch` / `skip`；
- real-derived / corpus site census；
- 自动 future-address selector。

因此，当前正确表述是：

```text
我们已经完成第一轮 Kinsn-specific policy sweep，并把 PF-LLM-inspired access-pattern taxonomy
中的 stride、spatial、MLOP 和 degree 维度跑到了 ARM64 paired attribution；其中 spatial、MLOP、
degree1、horizon2、pipeline 又补了 c7g PMU-backed evidence。当前最值得继续追的是
ARM64 horizon2/horizon4 + L1 hint、spatial-within-page、MLOP/index-field 和 degree1。它们仍缺
real-derived 覆盖率和自动 selector。
```

## 下一步

优先级：

1. 保留当前 best candidate：ARM64 horizon2/horizon4 + L1 hint、spatial、MLOP、degree1。
2. 补 PF-LLM-inspired 未完成项：
   - fixed-offset struct-field PMU attribution；
   - stream-of-strides slowdown diagnosis；
   - per-PC policy table / full profile schema。
3. 做 corpus site census，确认真实 BPF 中哪些 access shape 出现。
4. 再设计自动 selector。不要在 policy space 不完整时过早把 hand-profiled horizon 逻辑固化成默认规则。

## 参考

- PF-LLM PDF：
  `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/sources/papers/pf-llm-2026-asplos.pdf`
- Online PDF：
  `https://fact-lab.hkust.edu.hk/publications/conference-paper/2025/xu-2025-pf-llm/3779212.3790202.pdf`
