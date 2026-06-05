# Kinsn Prefetch Microbenchmark 设计

最后更新：2026-06-05。

## 结论

本文件说明 prefetch task 里的 microbenchmark 测试用例怎么构建。

Microbenchmark 不是 policy。它是用来回答 policy 问题的受控实验输入。

当前 suite 中不同 benchmark 的来源清单单独记录在：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-inventory.md
```

读结果前必须先区分三类 benchmark：repo 原有 workload-shaped micro、ARM LLVM backend coverage micro、
prefetch task 新增 micro。只有 prefetch task 中被标为性能归因的用例才可以用来讨论
prefetch policy 是否加速。

每个 prefetch micro 测试用例必须说明：

```text
1. 它模拟哪种 memory access shape。
2. 它服务哪个 prefetch policy 问题。
3. 它是 synthetic-control、real-inspired 还是 real-derived。
4. control 和 treatment 的区别是什么。
5. 为什么这个用例理论上可能让 prefetch 有用，或者为什么它应该作为 no-prefetch 对照。
6. 它不能证明什么。
```

当前 prefetch micro 测试用例基本都是 `synthetic-control`。它们用于筛选 policy，不用于证明真实
BPF workload 会有同样收益。真实覆盖率需要后续 corpus site census 或 real-derived 用例。

本文件是用例设计和清单，不是主技术报告。主结论只看当前有效 suite：

| 当前类别 | 用例 | 当前用途 |
|---|---|---|
| 正向候选 | `prefetch_mlop_index_field` | 最强 MLOP / index-field 候选。 |
| 正向候选 | `prefetch_pipeline_horizon2_page_stride` | 当前保留的未来地址 horizon2 用例。 |
| 正向候选 | `prefetch_degree123_page_stride` | degree1 有效；degree2/3 不默认。 |
| 正向候选 | `prefetch_spatial_page_footprint` | page 内空间 footprint 有效，但要限制额外指令开销。 |
| 正向候选 | `prefetch_struct_field_fixed_offsets` | fixed-field 弱正向候选。 |
| schema 候选 | `prefetch_mixed_policy_table` | 按 PC 区分 prefetch / skip 的 policy table。 |
| 负向对照 | `prefetch_upper_page_stride` | 拒绝当前轮当前地址预取。 |
| 负向对照 | `prefetch_hot_l1_load` | 跳过 hot load。 |
| 负向对照 | `prefetch_sequential_scan` | 跳过简单顺序流。 |
| 负向对照 | `prefetch_indirect_two_stage` | 跳过深依赖地址链。 |
| 安全覆盖 / 跳过规则 | `prefetch_map_line_dedup` | 同 cacheline 去重。 |
| 已完成诊断 | `prefetch_first_deref_page_stride` | 高 miss，但当前 placement 基本不降低 miss；拒绝当前 placement。 |
| 已完成诊断 | `prefetch_stream_of_strides_high_miss` | cache miss 降但执行时间不赢；当前实现应拒绝。 |

其余历史用例只作为探索记录保留，不能直接用于当前 selector 设计或性能结论。

## Microbenchmark 的目的

Prefetch microbenchmark 的目标不是让每个 `prefetch_*` 用例都加速。它的目标是给 prefetcher
建立完整的决策边界：

```text
1. 什么情况下应该插 prefetch。
2. 什么情况下必须 skip。
3. 如果插了但没快，原因是缺失压力不高、提前量不够、degree 太大、hint 错，还是额外指令开销。
4. pass / JIT / verifier 路径是否能安全处理这些访问形态。
```

因此，一个测试用例即使不是正向性能用例，也可能必须存在：

| 测试用例目的 | 为什么必须存在 | 例子 |
|---|---|---|
| 正向性能归因 | 证明某个 policy 在受控高缺失 / 未来地址模式上确实能快。 | `prefetch_mlop_index_field`、`prefetch_pipeline_horizon2_page_stride`。 |
| 负向对照 | 证明某类看起来 verifier-safe 的 load 不应该 prefetch。 | `prefetch_hot_l1_load`、`prefetch_sequential_scan`、`prefetch_indirect_two_stage`。 |
| 覆盖 / 安全 | 证明 pass 能识别、插入、通过 verifier / JIT / runtime。 | `prefetch_packet_offset_guarded`、`prefetch_map_line_dedup`。 |
| 诊断 | 解释某个 policy 为什么不适合当前实现。 | `prefetch_upper_page_stride`、`prefetch_stream_of_strides_high_miss`。 |

如果只保留正向用例，selector 会缺少“哪些 site 应该跳过”的证据，容易把所有 verifier-safe
load 都当成有收益候选。生产级 prefetcher 必须同时有正向用例和跳过规则用例。

## 为什么分成 `research` / `map` / `upper`

`research`、`map`、`upper` 不是 policy 分类，也不是结论分类。它们只是三个源码文件 / 输入载体，
按研究推进顺序和工作集大小分开：

| 源码分组 | 完整路径 | 为什么存在 | 主要用途 |
|---|---|---|---|
| `research` | `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.bpf.c` | 最早期 packet-side scaffold，输入是 1400-byte staged packet，适合快速验证 packet pointer、bounds check、dependent deref 和 small working-set skip。 | 覆盖 / 安全、负向对照。不是 high-miss 性能平台。 |
| `map` | `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_map_research.bpf.c` | packet working set 太小后，加入 256 KiB BPF map value，测试 map-value path、same-cacheline dedup、indirect map access 和 same-iteration map prefetch。 | map-value 机制验证、same-iteration diagnostic。 |
| `upper` | `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c` | 为了构造真正的 high-miss / future-address / degree / spatial / MLOP cases，加入 1 MiB map value 和显式 future pointer materialization。 | performance-attribution、PF-LLM-inspired policy screening、PMU 归因。 |

正确读法是：

```text
source file = 输入载体和构造手段
case type   = 这个测试用例的实验目的
policy      = 这个测试用例回答的 prefetch 决策问题
```

## 全部 Prefetch Micro Test Case 总表

下面这张表列出当前 `micro_pure_jit.yaml` 里的全部 prefetch 测试用例。表里的
`是否为正向性能用例` 只表示“这个用例是否可以作为当前 policy 的正向性能归因证据”，
不表示这个 benchmark 是否有用。覆盖 / 安全用例和负向对照用例仍然有用，但不能拿来证明
prefetch 加速。

源文件缩写：

| 缩写 | 完整路径 | 输入形态 |
|---|---|---|
| `research` | `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.bpf.c` | 1400-byte staged packet。 |
| `map` | `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_map_research.bpf.c` | 256 KiB BPF array map value。 |
| `upper` | `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c` | 1 MiB BPF array map value。 |

| 测试用例 | 源 | 类型 | 构造方式 | 对应 policy / 问题 | 是否为正向性能用例 | 当前判断 |
|---|---|---|---|---|---|---|
| `prefetch_distance_0` | `research` | 负向对照 | 当前 packet load 前 0 slot delay。 | fixed-distance same-iteration；无提前量。 | 否 | 用来证明无提前量应跳过，不重构。 |
| `prefetch_distance_2` | `research` | 负向对照 | 当前 packet load 前 2 slot delay。 | fixed-distance same-iteration；短提前量。 | 否 | 用来证明短提前量不稳定，不重构。 |
| `prefetch_distance_4` | `research` | 负向对照 | 当前 packet load 前 4 slot delay。 | fixed-distance same-iteration；短提前量。 | 否 | 用来证明短提前量不稳定，不重构。 |
| `prefetch_distance_8` | `research` | 负向对照 | 当前 packet load 前 8 slot delay。 | fixed-distance same-iteration。 | 否 | packet working set 太小，不能作为正向性能证据。 |
| `prefetch_distance_16` | `research` | 负向对照 | 当前 packet load 前 16 slot delay。 | fixed-distance same-iteration。 | 否 | packet working set 太小，不能作为正向性能证据。 |
| `prefetch_distance_32` | `research` | 负向对照 | 当前 packet load 前 32 slot delay。 | fixed-distance same-iteration。 | 否 | packet working set 太小，不能作为正向性能证据。 |
| `prefetch_hot_l1_load` | `research` | 负向对照 | 反复读同一个 packet offset。 | hot-load skip。 | 否 | 本来就是证明 hot load 不该 prefetch，不重构。 |
| `prefetch_sequential_scan` | `research` | 负向对照 | packet 内顺序扫描。 | sequential-stream skip。 | 否 | 用来证明简单顺序流不应默认软件 prefetch，不重构。 |
| `prefetch_large_stride_scan` | `research` | 负向对照 | packet 内 64B stride scan。 | small packet stride / structural packet。 | 否 | packet working set 太小，不能证明 stride policy。 |
| `prefetch_permuted_index_scan` | `research` | 负向对照 | deterministic permutation 后读 bounded packet offsets。 | bounded packet permutation。 | 否 | 用来验证 structural packet prefetch 不应默认启用。 |
| `prefetch_packet_offset_guarded` | `research` | 覆盖 / 安全 | variable packet offset 先 bounds check，再 demand load。 | verifier-safe guarded pointer placement。 | 否 | 验证安全插入路径，不作为性能用例。 |
| `prefetch_full_packet_ring_scan` | `research` | 负向对照 | 在 1400-byte packet 中 ring-like scan。 | packet ring scan。 | 否 | small working set 负向对照，不重构。 |
| `prefetch_indirect_lookup` | `research` | 负向对照 | 先读 table byte，再计算 final packet offset。 | dependent address chain skip。 | 否 | 地址知道太晚，支持 skip。 |
| `prefetch_indirect_two_stage` | `research` | 负向对照 | 两级 dependent load 产生 final target。 | deeper dependent chain skip。 | 否 | 地址知道太晚，支持 skip。 |
| `prefetch_cacheline_dedup_scan` | `research` | 覆盖 / 安全 | 同一 packet cacheline 读多个 `u64`。 | same-cacheline dedup。 | 否 | 验证 dedup，不作为性能用例。 |
| `prefetch_packet_first_deref` | `research` | 覆盖 / 安全 | packet load 产生 index，再读 final packet target。 | packet first-deref selector coverage。 | 否 | 证明 selector 能命中，不作为性能用例。 |
| `prefetch_single_first_deref` | `research` | 覆盖 / 安全 | 最小 first-deref pattern。 | first-deref minimal coverage。 | 否 | 证明 selector 能命中，不作为性能用例。 |
| `prefetch_map_page_stride` | `map` | 诊断 | 256 KiB map value 内 page-spread same-iteration load。 | map-value same-iteration。 | 诊断 | miss 小降但 timing neutral；不重构，作为 same-iteration 诊断。 |
| `prefetch_map_indirect_page` | `map` | 负向对照 | table value 选择 page 和 in-page offset。 | map dependent-address skip。 | 否 | 地址知道太晚，支持 skip。 |
| `prefetch_map_line_dedup` | `map` | 覆盖 / 安全 | 256 KiB map value 内同一 cacheline 多 load。 | map same-cacheline dedup。 | 否 | 验证 dedup，不作为性能用例。 |
| `prefetch_upper_page_stride` | `upper` | 诊断 / 有效负向用例 | 1 MiB map value，page-spread current-address load，load 前有 independent work。 | high-miss same-iteration upper bound。 | 否 | control miss 高但 treatment 不赢；足以拒绝当前地址 same-iteration。 |
| `prefetch_pipeline_page_stride` | `upper` | 性能归因 | 本轮 load `i`，本轮提前物化 `i+1` pointer。 | next-iteration future-address。 | 是 | 正向候选。 |
| `prefetch_pipeline_horizon1_page_stride` | `upper` | 性能归因 | 本轮提前物化 `i+1` pointer。 | horizon 1。 | 是 | 有正向信号但弱于 horizon2。 |
| `prefetch_pipeline_horizon2_page_stride` | `upper` | 性能归因 | 本轮提前物化 `i+2` pointer。 | horizon 2。 | 是 | 当前强正向候选。 |
| `prefetch_pipeline_horizon4_page_stride` | `upper` | 性能归因 | 本轮提前物化 `i+4` pointer。 | horizon 4。 | 是 | 有正向信号，但不稳定优于 horizon2。 |
| `prefetch_pipeline_degree_page_stride` | `upper` | 性能归因 / 诊断 | 同一轮同时物化 `i+1/i+2/i+4` pointers。 | degree parameter / multiple future addresses。 | 是 | 正向但对额外指令开销敏感。 |
| `prefetch_stride64_page_stride` | `upper` | 诊断 | 1 MiB map value，64B stride，物化 `i+2` future pointer。 | stride-class 64B。 | 否 | timing 中性；standalone stride 不作为候选。 |
| `prefetch_stride256_page_stride` | `upper` | 诊断 | 1 MiB map value，256B stride，物化 `i+2` future pointer。 | stride-class 256B。 | 否 | timing 中性；standalone stride 不作为候选。 |
| `prefetch_stride4096_page_stride` | `upper` | 诊断 | 1 MiB map value，4KiB stride，物化 `i+2` future pointer。 | stride-class page stride。 | 否 | timing 中性；standalone stride 不作为候选。 |
| `prefetch_variable_stride_page_stride` | `upper` | 诊断 | 1 MiB map value，deterministic variable stride，物化 `i+2` future pointer。 | variable stride。 | 否 | miss 下降但 timing 弱；当前不作为候选。 |
| `prefetch_spatial_page_footprint` | `upper` | 性能归因 | 同一 future page 内物化 0/128/256 三个 offsets。 | spatial-within-page。 | 是 | 正向候选，但必须限制 degree / 额外指令开销。 |
| `prefetch_struct_field_fixed_offsets` | `upper` | 性能归因 | record base + 0/64/128 fixed fields，物化 future record fields。 | fixed-offset struct-field。 | 是 | 弱正向候选。 |
| `prefetch_mlop_index_field` | `upper` | 性能归因 | 地址由 record index + field offset 组合，物化 future offset。 | MLOP / index-field。 | 是 | 当前最强正向候选。 |
| `prefetch_first_deref_page_stride` | `upper` | 诊断 | 先读 future key，再计算 future target pointer。 | high-miss first-deref-like shape。 | 否 | PMU 已补：control miss 高，但 treatment miss 基本不降；拒绝当前 placement。 |
| `prefetch_degree123_page_stride` | `upper` | 性能归因 | 同一 stream 物化 `i+2/i+4/i+8`，profile 控制 degree1/2/3。 | normalized degree 1/2/3。 | 是 | degree1 最好，degree2/3 没超过 degree1。 |
| `prefetch_mixed_policy_table` | `upper` | schema + 性能归因 | 同一 program 混合 hot fixed load 和 future page pointer，用 profile 指定 skip/prefetch。 | per-PC mixed policy table / negative filtering。 | 是 | 弱正向；主要证明 per-PC schema。 |
| `prefetch_stream_of_strides` | `upper` | 诊断 | 两个 interleaved streams，分别物化 `A(i+2)`、`B(i+2)`。 | stream-of-strides。 | 否 | 旧 two-stream placement 明显变慢，作为历史诊断。 |
| `prefetch_stream_of_strides_high_miss` | `upper` | 性能归因 / 诊断 | 两个 page-spread streams，分别物化 `A(i+4)`、`B(i+4)`。 | high-miss stream-of-strides。 | 是 | degree1 single-site profile 弱正向；degree2 two-site placement miss 降但 exec/cycles 不赢。 |
| `prefetch_stream_of_strides_degree1_high_miss` | `upper` | 无效 case | 试图构造 degree1 stream case。 | stream-of-strides degree1。 | 否 | selector smoke `sites_applied=0`，不作为性能证据。 |

从这张表可以直接得到当前需要处理的 case：

```text
已补 PMU：prefetch_first_deref_page_stride；结论是拒绝当前 placement
保留弱候选：prefetch_stream_of_strides_high_miss + degree1 single-site profile
不再作为候选：prefetch_stream_of_strides_high_miss + degree2 two-site placement
不再作为候选：prefetch_stride64/256/4096_page_stride，standalone stride 已拒绝
不用重构：覆盖 / 安全和负向对照用例，它们的目标不是正向加速
```

## 用例类型

| 类型 | 目的 | 结果解释 |
|---|---|---|
| 覆盖 / 安全 | 验证 pass 能插、JIT 能 emit、verifier/runtime 不坏。 | 即使 timing 变快，也不能作为性能证据。 |
| 负向对照 | 验证 hot/no-lead/sequential/dependent-chain 等形态应当跳过。 | 不能改成正向用例后还声称测试同一个问题。 |
| 性能归因 | 构造高缺失基线、明确 future address、足够提前量，用 PMU 解释结果。 | 可以证明受控 pattern 上某 policy 是否有效。 |
| 诊断 | 定位慢因：基线 miss 不够、hint 错、degree 过大、额外指令开销等。 | 服务后续 policy 修改。 |

负向对照用例是必要的。它们不是“坏 case”，而是用来防止 selector 把所有 verifier-safe
load 都当成有收益 load。一个生产级 prefetcher 同时需要正向用例和负向对照用例：

```text
正向用例：证明什么情况下应该插。
负向对照：证明什么情况下必须跳过。
```

为什么覆盖 / 安全和负向对照会和 policy 有关系：

- prefetch policy 不只定义“在哪里插”，也定义“在哪里不插”。
- Kinsn prefetcher 会扫描 BPF bytecode。只要它会扫描 packet load、map load、first-deref、
  stride-like load，就一定会遇到 hot load、sequential load、same-cacheline load、dependent chain
  和没有提前量的 load。
- 这些 pattern 在语义上可能 verifier-safe，但性能上不一定有收益。负向对照用例的作用就是给跳过规则提供证据。

因此，覆盖 / 安全和负向对照用例的成功标准不是 speedup，而是：

```text
覆盖 / 安全：pass / JIT / verifier / runtime path 正确。
负向对照：selector 应该跳过；如果强行插入，实验应显示它不适合作为正向候选。
```

## 有效性能用例标准

只有用来回答“某个 policy 是否能加速”的 micro 用例，才必须满足下面标准。覆盖 / 安全用例和
负向对照用例不需要满足这些标准，也不应该被拿来做性能收益结论。

一个有效正向性能归因用例必须同时满足：

| 条件 | 要求 |
|---|---|
| policy 匹配 | 用例的访问形态必须真正对应被测 policy，例如 horizon 用例必须有 `i+N` future pointer，degree 用例必须有多个 future pointer，stream 用例必须有多个独立 stream。 |
| 高缺失 control | control 必须有足够 cache miss / miss rate；control miss 为 0 或很低时，不能证明 prefetch 有效。 |
| 预期 prefetch 已插入 | treatment 必须有 `sites_applied > 0`，并且 native JIT dump 或 codegen evidence 能看到目标 `prfm` / `prefetch*`。 |
| cache 效果 | treatment 必须降低 cache miss count 或 miss rate。 |
| runtime 效果 | treatment 必须降低 `exec_ns` 或 cycles；只降 miss 但 exec/cycles 不赢，只能算诊断。 |
| 开销解释 | 若 instructions、cycles、native bytes 增加，必须说明这些开销是否抵消 miss drop。 |

用公式表示：

```text
有效正向 =
  pattern matches policy
  && control misses are non-trivial
  && treatment emits expected prefetch
  && treatment misses/rate decrease
  && treatment exec_ns or cycles decrease
```

如果只满足前四项，但 exec/cycles 不降，例如 `prefetch_stream_of_strides_high_miss`，它是
`cache-miss-drop 诊断用例`，不是正向候选。

## 目录和入口

当前 prefetch micro 主要在三个 BPF C 文件里：

| file | input shape | 作用 |
|---|---|---|
| `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.bpf.c` | staged packet, 1400 bytes | packet-side / negative control / first-deref cases。 |
| `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_map_research.bpf.c` | BPF array map value, 256 KiB | map-backed page/line/indirect working-set cases。 |
| `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c` | BPF array map value, 1 MiB | upper-bound, future-address horizon, true-degree cases。 |

Manifest：

```text
/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml
```

所有 benchmark 必须通过 Makefile / AWS wrapper 路径运行，不能绕过 framework 直接调用底层
Python / Cargo / Docker。

## 通用构造规范

新增 prefetch micro case 时必须包含：

| required item | 要求 |
|---|---|
| source type | 标注 `synthetic-control`、`real-inspired`、`real-derived`、`abi-coverage` 或 `regression`。 |
| deterministic input | 用固定 input generator，确保 expected result 稳定。 |
| expected result | control 和 treatment 必须返回同一个 deterministic result。 |
| IO mode | 说明为什么使用 staged packet、packet、map 或其他 input shape。 |
| target policy | 明确这个 case 是测哪个 policy，而不是只为了命中 pass。 |
| control native shape | 不应用 prefetch pass 时的 native/JIT shape。 |
| treatment evidence | `sites_applied`、JIT dump、code size 或 raw result 至少有一种证据证明 treatment 生效。 |
| limitation | 说明这个 case 不能证明真实 workload 覆盖率或 e2e 收益。 |

## Existing case families

### 1. Fixed-distance packet cases

用例：

```text
prefetch_distance_0
prefetch_distance_2
prefetch_distance_4
prefetch_distance_8
prefetch_distance_16
prefetch_distance_32
```

构造方式：

- input：1400-byte staged packet payload。
- loop：64 rounds。
- address：`PREFETCH_RESEARCH_DATA_BASE + slot * 4`。
- `slot` 用 deterministic pseudo-random formula。
- demand load 前插入不同数量的 ALU delay work。

回答的 policy 问题：

```text
如果只在当前 demand load 前固定距离插 prefetch，是否能隐藏 latency？
```

为什么这个用例存在：

- 验证 naive fixed-distance policy 是否有基本收益。
- 覆盖 no-lead-time 和 short-lead-time negative controls。

限制：

- packet payload 很小，cache hot probability 高。
- 不代表 large working-set map / memory-bound workload。

当前结果：

- ARM64 geomean T/C `1.004928`，不支持该 policy。

### 2. Packet no-prefetch controls

用例：

```text
prefetch_hot_l1_load
prefetch_sequential_scan
prefetch_large_stride_scan
prefetch_permuted_index_scan
prefetch_packet_offset_guarded
prefetch_full_packet_ring_scan
```

构造方式：

- `hot_l1_load`：反复读同一个 packet offset。
- `sequential_scan`：按 `index * 8` 顺序读 packet。
- `large_stride_scan`：按 64-byte stride 访问 packet 内不同 cacheline。
- `permuted_index_scan`：用 deterministic permutation 访问 bounded offsets。
- `packet_offset_guarded`：variable offset 经过 bounds check 后再读。
- `full_packet_ring_scan`：在 1400-byte packet 内扩大 ring-like scan。

回答的 policy 问题：

```text
哪些结构上可 prefetch 的 packet loads 应该明确 skip？
```

为什么这个用例存在：

- hot / sequential / small packet working set 通常不应该 prefetch。
- 验证 selector 不应把 “verifier-safe” 等同于 “profitable”。

限制：

- 主要是 negative controls。
- 即使某个样本变快，也不能作为 default-enable 证据。

当前结果：

- mixed / weak / slowdown；整体支持 no-prefetch-by-default。

### 3. Packet first-deref cases

用例：

```text
prefetch_packet_first_deref
prefetch_single_first_deref
```

构造方式：

- 先从 packet table offset 读一个 byte index。
- 用 index 计算 target offset。
- 对 final packet deref 做 demand load。
- `single_first_deref` 是最小 coverage case。
- `packet_first_deref` 在 loop 中重复该 pattern。

回答的 policy 问题：

```text
packet load 产生 scalar index 后，是否应该 prefetch final deref？
```

为什么这个用例存在：

- 它是 selector v3 唯一允许的 non-profile packet candidate。
- 它比普通 packet load 更接近“地址依赖但仍有一点提前量”的形态。

限制：

- 仍是 packet working set，不是 large memory working set。
- 只能证明 selector/correctness；性能仍需真实 workload 或 larger working set。

当前结果：

- x86/ARM64 smoke 都 `sites_applied=1`。
- performance mixed，不支持 default-enable。

### 4. Indirect / dependent-chain cases

用例：

```text
prefetch_indirect_lookup
prefetch_indirect_two_stage
prefetch_map_indirect_page
```

构造方式：

- `indirect_lookup`：读 table byte，计算 target offset，再读 target。
- `indirect_two_stage`：第一阶段 load 产生中间 index，中间 load 再产生 final target。
- `map_indirect_page`：在 map value 内用 table value 选择 page 和 in-page offset。

回答的 policy 问题：

```text
dependent address chain 是否还有足够提前量让 prefetch 有用？
```

为什么这个用例存在：

- 验证 pointer-chasing / indirect style 不能简单 structural prefetch。
- 如果地址太晚才知道，prefetch hint 只能很晚发，可能只增加成本。

当前结果：

- 没有稳定收益；支持 dependent-chain skip。

### 5. Cacheline dedup cases

用例：

```text
prefetch_cacheline_dedup_scan
prefetch_map_line_dedup
```

构造方式：

- 同一 cacheline 内连续读多个 `u64`。
- packet version 用 1400-byte packet。
- map version 用 256 KiB map value 和 64-byte line stride。

回答的 policy 问题：

```text
同一 cacheline 多个 loads 是否只应 prefetch 一次？
```

为什么这个用例存在：

- 它主要验证 admission / dedup rule。
- 不应把多个 same-line loads 当成多个 independent prefetch opportunities。

当前结果：

- dedup 逻辑可用。
- 性能不是稳定 win。

### 6. Map page-stride cases

用例：

```text
prefetch_map_page_stride
prefetch_map_indirect_page
prefetch_map_line_dedup
```

构造方式：

- input：BPF array map value，256 KiB。
- `page_stride`：32 pages 内 deterministic page-spread access。
- `line_dedup`：不同 cacheline / same-line multi-load。
- `indirect_page`：table byte 决定 page 和 in-page offset。

回答的 policy 问题：

```text
map-backed large working set 是否比 packet case 更适合 prefetch？
```

为什么这个用例存在：

- packet case 太小，可能不敏感。
- map value 更接近 BPF 程序的大 working-set memory access。

限制：

- 256 KiB 仍是 synthetic-control。
- same-iteration placement 仍可能提前量不足。

当前结果：

- map page stride weak / mixed。
- map indirect 和 line dedup 没有稳定收益。

### 7. Same-iteration upper-bound map case

Case：

```text
prefetch_upper_page_stride
```

构造方式：

- input：BPF array map value，1 MiB。
- loop：512 rounds。
- address：page-spread offset，覆盖 256 pages。
- demand load 前加入 independent ALU work。
- prefetch 仍针对当前轮 demand address。

回答的 policy 问题：

```text
如果给 same-iteration prefetch 更大的 working set 和更多 independent work，它是否能变快？
```

为什么这个用例存在：

- 排除 “旧 micro 不够偏向 prefetch” 的可能。
- 给 same-iteration policy 一个更强的 best-case probe。

当前结果：

- x86 noise-level。
- ARM64 slowdown。
- 说明 same-iteration placement 本身仍不足。

### 8. Next-iteration / future-address cases

用例：

```text
prefetch_pipeline_page_stride
prefetch_pipeline_horizon1_page_stride
prefetch_pipeline_horizon2_page_stride
prefetch_pipeline_horizon4_page_stride
```

构造方式：

- input：BPF array map value，1 MiB。
- loop：512 rounds。
- current pointer `cur` 用于本轮 demand load。
- future pointer 在本轮提前计算出来。
- `horizon1` 预取 `i+1`。
- `horizon2` 预取 `i+2`。
- `horizon4` 预取 `i+4`。
- 用 pointer barrier 避免 compiler 把 future pointer 优化掉。
- treatment 通过 profile point 指定 BPF PC 和 live register。

回答的 policy 问题：

```text
预取未来轮次地址是否比预取当前轮地址更有效？
```

为什么这个用例存在：

- 它直接测试提前量是否是关键因素。
- 它是当前最接近 PF-LLM “per-load policy / degree / horizon” 思路的 Kinsn synthetic-control case。

当前结果：

- ARM64 horizon2/horizon4 + L1 hint 是当前最强 candidate。
- 最新 long-repeat：
  - horizon2 `l1keep` mean T/C `0.945361`
  - horizon4 `l1keep` mean T/C `0.971207`

限制：

- 仍是 hand-profiled PC/register。
- 还不是自动 selector。
- ARM64 `c7g` PMU attribution 已补 horizon2 / pipeline 等重点 case 的 cache-miss evidence；
  当前缺口是自动 selector 和真实 workload 覆盖率，不是 micro PMU 机制证据。

### 9. True-degree case

Case：

```text
prefetch_pipeline_degree_page_stride
```

构造方式：

- input：BPF array map value，1 MiB。
- 每轮同时计算：
  - current pointer；
  - `i+1` future pointer；
  - `i+2` future pointer；
  - `i+4` future pointer。
- profile points 对三个 future pointer 分别插入 prefetch。

回答的 policy 问题：

```text
一次 prefetch 多个 future addresses 是否比 single horizon 更好？
```

为什么这个用例存在：

- PF-LLM 把 degree 作为核心参数。
- Kinsn 没有硬件 degree 字段，只能用多个 explicit prefetch hints 模拟 degree 参数。

当前结果：

- ARM64 `l1keep` T/C `0.982073`，弱信号。
- 没超过 single horizon2/horizon4。

## PF-LLM-inspired cases

PF-LLM 的 policy space 不是直接插软件 prefetch，而是为硬件 prefetcher ensemble 选择：

- sub-prefetcher type；
- degree；
- demand filtering。

Kinsn 可以借鉴它的 access-pattern taxonomy，但实现方式必须落到 BPF bytecode pass 能表达的
live register prefetch point。下面表格区分已经加入 micro suite 的 cases 和仍未实现的 cases。

| case family | status | cases | 构造方式 | 要回答的问题 |
|---|---|---|---|---|
| stride-class sweep | ARM64 paired + c7g PMU attribution done | `prefetch_stride64_page_stride`, `prefetch_stride256_page_stride`, `prefetch_stride4096_page_stride`, `prefetch_variable_stride_page_stride` | 在 1 MiB map value 上构造 64B、256B、4KiB、variable stride；每轮 demand load 使用 current pointer，并在 load 前保留一个 future pointer profile point。 | Kinsn 是否应该按 stride class 选择不同 horizon/hint，而不是统一 policy？当前结果：plain stride timing 中性，不支持独立 candidate。 |
| spatial-within-page | ARM64 paired + c7g PMU attribution done | `prefetch_spatial_page_footprint` | 每轮访问同一 page 内 0/128/256 三个 offset，并保留未来 page 的 0/128/256 三个 pointer。 | 是否应该预取 region / page-local footprint，而不是单个 future pointer？当前结果：有 cache-miss-drop evidence，但有 instruction overhead。 |
| fixed-offset struct-field | x86 smoke + ARM64 paired + c7g PMU attribution done | `prefetch_struct_field_fixed_offsets` | 1 MiB map value 被看作 fixed-size records；每轮访问 record 内 0/64/128 三个 fields；profile 在 pc 29 对 r2/r6/r4 插 3 个 prefetch points。 | Sandbox-style fixed-offset pattern 是否适合 Kinsn prefetch？当前 c7g PMU 结果：T/C exec `0.986178`，T/C cycles `0.970069`，cache miss rate delta `-0.004231218`；小幅正向，但仍是 synthetic-control。 |
| multi-level offset | ARM64 paired + c7g PMU attribution done | `prefetch_mlop_index_field` | 地址形态为 record index + field offset；index 和 field 都由 deterministic expression 计算。 | MLOP-style multi-level offset 是否适合 future-address selector？当前结果：PMU-backed timing signal 最强。 |
| normalized degree 1/2/3 | ARM64 paired + c7g PMU attribution done | `prefetch_degree123_page_stride` with degree1/2/3 profiles | 同一个 page-stride stream 同时保留 `i+2/i+4/i+8` future pointers；不同 profile 控制 degree=1/2/3。 | degree 的最优点是否不是当前 `i+1/i+2/i+4` 全发？当前结果：degree1 最好，degree2/3 没超过 degree1。 |
| per-PC policy table / negative filtering stress | schema + x86 smoke + ARM64 paired + c7g PMU attribution done | `prefetch_mixed_policy_table` | 同一个 program 内混合 hot fixed load 和 page-stride load；profile schema 用 `prefetch` / `skip` action 表达 per-PC decision。 | per-PC policy 是否优于 program-level policy？no-prefetch filtering 是否能保护性能？当前 c7g PMU 结果：1 个 `prfm`、16 个 skipped site，T/C exec `0.977369`，cache miss rate delta `-0.026663413`；主要证明 per-PC schema 和 negative filtering。 |
| stream-of-strides | case/profile + x86 smoke + ARM64 paired + c7g PMU attribution done | `prefetch_stream_of_strides`, `prefetch_stream_of_strides_high_miss` | loop 内两个交错 stride streams，分别物化 `A(i+2/i+4)` 和 `B(i+2/i+4)` future pointer；profile 可打开 1 个或 2 个 prefetch points。 | 多 stream 是否需要 degree 或 per-stream filtering？旧 2-site case 明显变慢；high-miss degree1 single-site T/C exec `0.990870`、miss ratio `0.882631`，保留弱候选；degree2 two-site miss ratio `0.834258` 但 exec/cycles 不赢，应排除。 |

## 2026-06-04 新增 / 补齐 case 的构造细节

### `prefetch_struct_field_fixed_offsets`

构造目的：

```text
模拟 record / struct 中多个固定 offset field 的访问。
```

代码形态：

```text
base = map value base + record_index * record_size
load base + 0
load base + 64
load base + 128
```

Kinsn adaptation：

- 不是 hardcode native instruction。
- BPF bytecode 中先物化 future field pointer registers。
- `bpfopt --pass prefetch -- --profile ...` 扫描 profile 指定的 BPF PC/register。
- pass 插入 `KINSN_SIDECAR + KINSN_CALL`。
- x86 kernel JIT 把 kfunc 翻译成 `prefetcht0 [reg]`。

本轮 profile：

```text
/home/ruoji/github/bpf-opt/code/micro/config/prefetch-struct-field-fixed-offsets-profile-pc29-r2-r6-r4.json
```

2026-06-04 x86 smoke 证据：

```text
sites_matched = 3
sites_applied = 3
native hints = 3 x prefetcht0
```

### `prefetch_mixed_policy_table`

构造目的：

```text
模拟同一 program 内同时存在应该 skip 的 hot load 和可能值得 prefetch 的 page-stride load。
```

代码形态：

```text
hot fixed load:       should skip
future page pointer:  should prefetch
```

Kinsn adaptation：

- 新增 profile schema `map_value_policy_points`。
- 每个 point 允许 `action: prefetch` 或 `action: skip`。
- `prefetch` point 需要指定 register。
- `skip` point 可以跳过整个 PC 或某个 PC/register。

本轮 profile：

```text
/home/ruoji/github/bpf-opt/code/micro/config/prefetch-mixed-policy-table-profile-pc23-r2.json
```

语义：

```text
pc 23 reg 0: skip
pc 23 reg 2: prefetch
```

2026-06-04 x86 smoke 证据：

```text
sites_matched = 17
sites_applied = 1
sites_skipped = 16
native hints = 1 x prefetcht0
```

### `prefetch_stream_of_strides`

构造目的：

```text
模拟一个 loop 里有两个交错 stride stream，而不是单一 stride。
```

代码形态：

```text
stream A: current offset A(i), future offset A(i+2)
stream B: current offset B(i), future offset B(i+2)
demand load: load A(i), load B(i)
prefetch:    prefetch A(i+2), prefetch B(i+2)
```

Kinsn adaptation：

- micro program 显式物化两个 future pointer registers。
- profile 指定同一 BPF PC 下两个 live registers。
- pass 插入两个 independent prefetch kinsn sequences。

本轮 profile：

```text
/home/ruoji/github/bpf-opt/code/micro/config/prefetch-stream-of-strides-profile-pc316-r2-r9.json
```

2026-06-04 x86 smoke 证据：

```text
sites_matched = 18
sites_applied = 2
sites_skipped = 16
native hints = 2 x prefetcht0
```

## 如何决定新 case 是否值得加入

新增 case 必须先回答：

1. 它是否对应 PF-LLM 或 literature review 中明确的 access pattern？
2. 它是否能在 BPF verifier 约束下自然表达？
3. 它是否比现有 case 提供新的信息？
4. 它是否有明确 control / treatment 对照？
5. 它的 expected result 是否 deterministic？
6. 它是 `synthetic-control`、`real-inspired` 还是 `real-derived`？

如果只是为了让 pass 命中一个 toy pattern，不应加入 performance micro suite；可以放到
correctness / regression 路径。

## Micro 用例有效性审计

当前需要按 case 类型处理，不是把所有 low-miss case 都重构掉：

| case / family | 当前角色 | 是否需要重构重测 | 原因 |
|---|---|---:|---|
| `prefetch_hot_l1_load` | 负向对照 | 否 | 它本来就是证明 hot load 不该 prefetch；改成 high-miss 会改变问题。 |
| `prefetch_sequential_scan` | 负向对照 | 否 | 它证明 simple sequential scan 不应默认软件 prefetch。 |
| `prefetch_cacheline_dedup_scan` / `prefetch_map_line_dedup` | 覆盖 / 负向对照 | 否 | 它们主要证明 same-cacheline dedup，不是性能用例。 |
| `prefetch_indirect_lookup` / `prefetch_indirect_two_stage` / `prefetch_map_indirect_page` | 负向对照 / 诊断 | 否 | 当前作用是证明地址太晚才知道时应 skip。若要研究 pointer-chasing，需要另建新的性能用例。 |
| `prefetch_distance_0/2/4/8/16/32` | 无提前量负向对照 / 诊断 | 否 | 多数 control miss 为 0 或很低，不能作为正向用例。`prefetch_upper_page_stride` 已经提供 high-miss same-iteration 负面证据。 |
| `prefetch_packet_first_deref` / `prefetch_single_first_deref` | coverage | 否 | 它们证明 selector 能命中 first-deref，不是性能 case。 |
| `prefetch_first_deref_page_stride` | 诊断用例 | 否 | PMU 已补：control `cache_misses` mean `1395197.0`，treatment `1394078.0`，miss 基本不降；cycles / instructions 变高，当前 placement 拒绝。 |
| `prefetch_map_page_stride` | performance diagnostic | 不优先 | 有中等 miss pressure，但 same-iteration 不赢；`upper_page_stride` 已给出更强负面证据。 |
| `prefetch_upper_page_stride` | 有效负向性能用例 | 否 | control miss 高但 treatment 不赢，足以拒绝 same-iteration placement。 |
| `prefetch_pipeline_page_stride` | 有效正向性能用例 | 否 | high miss、future pointer、miss drop、exec win 都成立。 |
| `prefetch_pipeline_horizon1/2/4_page_stride` | 有效性能用例 | 否 | horizon sweep 已能比较提前量。 |
| `prefetch_pipeline_degree_page_stride` / `prefetch_degree123_page_stride` | 有效性能用例 | 否 | 已证明 degree1 最好，degree>1 不优。 |
| `prefetch_stride64/256/4096_page_stride` | diagnostic | 视目标决定 | 当前 plain stride timing 中性。若仍要给 stride standalone policy 一个公平机会，需要重构成 high-miss + explicit lead-time case；否则标为 reject standalone。 |
| `prefetch_variable_stride_page_stride` | diagnostic | 可选 | miss 降但 timing 弱。如果继续研究 variable stride，需要降低 hint overhead 或加强 workload。 |
| `prefetch_spatial_page_footprint` | 有效正向性能用例 | 否 | high miss、miss drop、exec win 成立，但必须 profile-gated。 |
| `prefetch_mlop_index_field` | 有效正向性能用例 | 否 | 当前最强正向用例。 |
| `prefetch_struct_field_fixed_offsets` | 有效弱正向用例 | 否 | PMU-backed 小幅正向。 |
| `prefetch_mixed_policy_table` | 有效 schema / 性能混合用例 | 否 | 它主要证明 per-PC prefetch/skip，同时有小幅正向。 |
| `prefetch_stream_of_strides` | 无效正向用例 / 有效负向诊断 | 否 | 基线 miss rate 低且明显变慢，足以排除当前实现。 |
| `prefetch_stream_of_strides_high_miss` | 有效诊断，不是正向用例 | 否 | control miss 高、miss 降，但 exec/cycles 不赢。当前 stream placement 已可判定无收益。 |

当前已定义策略中没有必须补跑的正向性能用例。已经关闭的缺口：

1. `prefetch_first_deref_page_stride`：已补 PMU-capable rerun，结论是当前 placement 不成立。
2. `stream-of-strides` family：如果还想研究该方向，重构 scheduling / degree / placement，再用
   high-miss case 做 PMU attribution。
3. `stride-class` family：如果还想保留 standalone stride policy，重构 high-miss + lead-time matched
   stride cases；否则明确 reject standalone。
4. `hint variant`：对已确认 positive 的 micro policy 做完整 `policy x hint` sweep，而不是只在部分
   horizon / degree case 上测。

## 下一步建议

下一步不是继续加更多 toy pattern，而是把 micro 用例有效性收敛：

1. 同步更新 technical report / results / policy matrix，确保 first-deref PMU 结论一致。
2. 决定是否继续 `stream-of-strides`。如果继续，先重构 case 和 placement，再重测；如果不继续，
   明确写成 rejected current direction。
3. 决定是否继续 standalone stride policy。若继续，新增 high-miss + lead-time matched stride cases；
   若不继续，明确写成 rejected standalone。
4. 对当前正向候选做完整 hint sweep：MLOP、horizon2、degree1、spatial。
5. 只把有效正向用例作为 selector candidate；覆盖 / 安全和负向对照用例只用于
   correctness 和 skip-policy 证据。
