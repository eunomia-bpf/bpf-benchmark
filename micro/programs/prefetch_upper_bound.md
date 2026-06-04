# prefetch_upper_bound

## 目的

`prefetch_upper_bound.bpf.c` 是 Kinsn prefetch task 的 best-case
synthetic-control micro benchmark。它不是从真实 BPF 程序提取的 benchmark，
也不能单独证明真实应用收益；它只回答一个更窄的问题：

```text
如果 working set、访问跨度和 load 前独立计算都更适合 prefetch，
当前 Kinsn prefetch selector 是否能观察到正收益。
```

## 输入和 IO 模式

- `io_mode`: map.
- `kernel_input_size`: 1048576 bytes.
- `input_generator`: `prefetch_upper_bound`.
- `runtimes`: kernel only.
- maps:
  - `input_map`: one `BPF_MAP_TYPE_ARRAY` entry containing a 1 MiB byte array.
  - `result_map`: micro framework 使用的单个 result slot。

这里必须使用 map IO mode。packet-backed staged input 只有约 1400 bytes，
更适合测试 packet datapath pattern，不适合测试 prefetch 对大 working set
memory access 的影响。

## Case

| benchmark | source type | 问题 | 触发条件 |
|---|---|---|---|
| `prefetch_upper_page_stride` | `synthetic-control` | 1 MiB page-spread map-value load，在 load 前有一段 straight-line independent ALU work，当前 prefetch selector 是否能有效。 | profile allow-list 允许第一个 map-value dereference PC。 |
| `prefetch_pipeline_page_stride` | `synthetic-control` | 当前轮读取 `cur`，同时提前计算下一轮 `next` pointer，并在当前轮 demand load 前对 `next` 发 prefetch。 | profile prefetch point 指定 program-local PC 45 / r1，这是 `next` pointer 已经物化、当前轮 demand load 尚未开始的位置。 |
| `prefetch_pipeline_horizon1_page_stride` | `synthetic-control` | future-address horizon=1。第 `i` 轮 demand load 前预取第 `i+1` 轮 map-value 地址。 | profile 指定 live future pointer。 |
| `prefetch_pipeline_horizon2_page_stride` | `synthetic-control` | future-address horizon=2。第 `i` 轮 demand load 前预取第 `i+2` 轮 map-value 地址。 | profile `prefetch-pipeline-horizon2-page-stride-profile-pc23-r6.json`。 |
| `prefetch_pipeline_horizon4_page_stride` | `synthetic-control` | future-address horizon=4。第 `i` 轮 demand load 前预取第 `i+4` 轮 map-value 地址。 | profile `prefetch-pipeline-horizon4-page-stride-profile-pc23-r9.json`。 |
| `prefetch_pipeline_degree_page_stride` | `synthetic-control` | true degree probe。第 `i` 轮同时预取 `i+1`、`i+2`、`i+4` 三个 future addresses。 | profile `prefetch-pipeline-degree-page-stride-profile-pc259-r5-pc273-r3-pc287-r0.json`。 |
| `prefetch_stride64_page_stride` | `synthetic-control`, `new-2026-06-03` | PF-LLM-inspired stride-class case。64-byte stride，每轮预取 `i+2` future line。 | profile `prefetch-stride64-page-stride-profile-pc54-r7.json`。 |
| `prefetch_stride256_page_stride` | `synthetic-control`, `new-2026-06-03` | PF-LLM-inspired stride-class case。256-byte stride，每轮预取 `i+2` future line。 | profile `prefetch-stride256-page-stride-profile-pc51-r7.json`。 |
| `prefetch_stride4096_page_stride` | `synthetic-control`, `new-2026-06-03` | PF-LLM-inspired large-stride/page-stride case。4 KiB stride，测试 page-distance lead time。 | profile `prefetch-stride4096-page-stride-profile-pc239-r0.json`，需要 runtime smoke 再确认该 PC/register 是否稳定表达 future pointer。 |
| `prefetch_variable_stride_page_stride` | `synthetic-control`, `new-2026-06-03` | PF-LLM-inspired stream-of-strides case。stride 在 64/128/256/512 bytes 间变化。 | profile `prefetch-variable-stride-page-stride-profile-pc44-r4.json`。 |
| `prefetch_spatial_page_footprint` | `synthetic-control`, `new-2026-06-03` | PF-LLM-inspired spatial-within-page case。每轮读同一 page 内 0/128/256 三个 offset，预取未来 page 的同类 footprint。 | profile `prefetch-spatial-page-footprint-profile-pc333-r0-r7-r5.json`。 |
| `prefetch_struct_field_fixed_offsets` | `synthetic-control`, `new-2026-06-03` | PF-LLM-inspired fixed-offset / struct-field case。每轮读同一 record 内 0/64/128 三个 fixed fields。 | 当前用于 case coverage；future-pointer profile 仍需 runtime/JIT dump 验证。 |
| `prefetch_mlop_index_field` | `synthetic-control`, `new-2026-06-03` | PF-LLM-inspired multi-level-offset case。地址形态为 record index + field offset。 | profile `prefetch-mlop-index-field-profile-pc67-r6.json`。 |
| `prefetch_degree123_page_stride` | `synthetic-control`, `new-2026-06-03` | normalized degree case。同一个 access stream 可分别测 degree=1/2/3。 | profiles `prefetch-degree123-page-stride-degree{1,2,3}-*.json`。 |
| `prefetch_mixed_policy_table` | `synthetic-control`, `new-2026-06-03` | per-PC policy-table / negative-filtering stress。一个 program 混合 hot fixed load 和 page-stride load，理论上只应 prefetch page-stride future pointer。 | 当前用于 mixed-case coverage；per-PC profile table 仍需 selector/profile schema 后续扩展。 |

## 和现有 map case 的区别

`prefetch_map_research` 已经测试了 256 KiB map-backed working set，但结果只有一个弱正信号。
`prefetch_upper_bound` 做了三个调整：

- working set 从 256 KiB 增加到 1 MiB。
- 每轮访问分散到 4 KiB page 粒度。
- demand load 前使用 straight-line independent work，避免 loop branch 落入 prefetch insertion window。

这些 case 仍然受当前 selector 限制：selector 不合成 `i + k` future pointer，只能对 profile 指定
的 live register 插入 prefetch。因此它们是 policy-space probe，不是完整自动 selector。

`prefetch_pipeline_page_stride` 是下一步 probe。它仍然不让 pass 合成未来地址，而是让 BPF 程序
显式维护 `cur` 和 `next` 两个 pointer；profile 只指定一个 prefetch point：

```json
{
  "map_value_prefetch_points": [
    { "pc": 45, "reg": 1 }
  ]
}
```

含义是：在 program-local PC 45 前，用 live register `r1` 中的 map-value `next` pointer 发
prefetch。这个形态比 `prefetch_upper_page_stride` 更接近 software-pipeline prefetch，因为 hint
服务的是下一轮 demand load，而不是当前轮 demand load。

## PF-LLM-inspired cases

PF-LLM 研究的是硬件 prefetcher ensemble，不是 Kinsn 软件 pass。本文件新增的 PF-LLM-inspired
cases 只借鉴它的 access-pattern taxonomy：

- stride-class：不同 stride size 对 lead time / hardware prefetcher 覆盖的敏感度不同；
- spatial-within-page：一次 demand stream 会消费同一 page/region 内多个 offset；
- fixed-offset：record / struct 中有多个固定 field；
- multi-level offset：地址由 base + index + field offset 组合；
- degree：同一轮可以预取 1、2 或 3 个 future addresses；
- per-PC policy table：同一个 program 中 profitable 和 non-profitable load sites 共存。

这些 case 是 `synthetic-control`。它们能回答 “某种 policy 在受控 memory shape 上是否可能有效”，
不能回答 “真实 BPF corpus 中这种 shape 是否常见”。后者需要 corpus site census。
