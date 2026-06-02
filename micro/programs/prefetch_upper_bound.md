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

## 和现有 map case 的区别

`prefetch_map_research` 已经测试了 256 KiB map-backed working set，但结果只有一个弱正信号。
`prefetch_upper_bound` 做了三个调整：

- working set 从 256 KiB 增加到 1 MiB。
- 每轮访问分散到 4 KiB page 粒度。
- demand load 前使用 straight-line independent work，避免 loop branch 落入 prefetch insertion window。

这个 case 仍然受当前 selector 限制：selector 不合成 `i + k` future pointer，只能对已有
map-value demand load 插入 prefetch。因此它是“当前 selector 的 upper-bound probe”，不是完整
next-iteration prefetch 策略。

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
