# prefetch_map_research

## 目的

`prefetch_map_research.bpf.c` 是 Kinsn prefetch task 的 map-backed
synthetic-control micro benchmark。它用来确认 packet-based PRFM 结果为负，是否只是因为
1400-byte staged packet working set 太小。

这些 case 不是从真实 BPF 程序自动提取的 `real-derived` benchmark。它们是 larger working-set
prefetch 行为的策略探针。

## 输入和 IO 模式

- `io_mode`: map.
- `kernel_input_size`: 262144 bytes.
- `input_generator`: `prefetch_map_research`.
- `runtimes`: kernel only.
- maps:
  - `input_map`: one `BPF_MAP_TYPE_ARRAY` entry containing a 256 KiB byte array.
  - `result_map`: micro framework 使用的单个 result slot。

这里必须使用 map IO mode，因为 staged XDP packet 不能代表大 working set。no-kinsn control
可以由 libbpf 直接加载 maps；kinsn treatment 需要 raw-kinsn loader 解析 BTF `.maps`、
创建 maps，并在加载 program 前 patch map relocations。

## Case

| benchmark | source type | 问题 |
|---|---|---|
| `prefetch_map_page_stride` | `synthetic-control` | 256 KiB page-spread access pattern 是否能从 `PRFM` lead time 受益。 |
| `prefetch_map_indirect_page` | `synthetic-control` | indirect page-level address pattern 是否能从 prefetch 受益。 |
| `prefetch_map_line_dedup` | `synthetic-control` | 大 working set 中，同 cacheline 多个 load 是否需要 dedup。 |

## 预期 Codegen 效果

使用 ARM64 forced LLVM path 编译时：

```text
-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=prefetch=force
```

treatment object 应该包含 `bpf_arm64_prfm_pldl1keep`，ARM64 kernel JIT dump
应该包含 native `prfm pldl1keep`。

## 当前证据

raw-kinsn loader 补齐 BTF `.maps` 支持后，map-backed 实验已经完成：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-raw-loader-fix/report.md
```

结果：

| benchmark | treatment native PRFM | median treatment/control | 结论 |
|---|---:|---:|---|
| `prefetch_map_page_stride` | 1 | `0.997014` | 弱 faster signal，约 0.30%。 |
| `prefetch_map_indirect_page` | 2 | `1.005259` | 约 0.53% slower。 |
| `prefetch_map_line_dedup` | 1 | `1.002829` | 约 0.28% slower。 |
| geomean | - | `1.001694` | 整体约 0.17% slower。 |

这排除了一个简单解释：之前 PRFM 为负只是因为 packet micro working set 太小。但这个结果仍然
不支持默认启用 prefetch。
