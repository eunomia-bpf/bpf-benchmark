# Kinsn Prefetch Microbenchmark Design

最后更新：2026-06-04。

## 结论

本文件说明 prefetch task 里的 microbenchmark test cases 怎么构建。

Microbenchmark 不是 policy。它是用来回答 policy 问题的受控实验输入。

每个 prefetch micro case 必须说明：

```text
1. 它模拟哪种 memory access shape。
2. 它服务哪个 prefetch policy 问题。
3. 它是 synthetic-control、real-inspired 还是 real-derived。
4. control 和 treatment 的区别是什么。
5. 为什么这个 case 理论上可能让 prefetch 有用，或者为什么它应该作为 no-prefetch control。
6. 它不能证明什么。
```

当前 prefetch micro cases 基本都是 `synthetic-control`。它们用于筛选 policy，不用于证明真实
BPF workload 会有同样收益。真实覆盖率需要后续 corpus site census 或 real-derived cases。

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

Cases：

```text
prefetch_distance_0
prefetch_distance_2
prefetch_distance_4
prefetch_distance_8
prefetch_distance_16
prefetch_distance_32
```

Construction：

- input：1400-byte staged packet payload。
- loop：64 rounds。
- address：`PREFETCH_RESEARCH_DATA_BASE + slot * 4`。
- `slot` 用 deterministic pseudo-random formula。
- demand load 前插入不同数量的 ALU delay work。

Policy question：

```text
如果只在当前 demand load 前固定距离插 prefetch，是否能隐藏 latency？
```

Why this case exists：

- 验证 naive fixed-distance policy 是否有基本收益。
- 覆盖 no-lead-time 和 short-lead-time negative controls。

Limitation：

- packet payload 很小，cache hot probability 高。
- 不代表 large working-set map / memory-bound workload。

Current result：

- ARM64 geomean T/C `1.004928`，不支持该 policy。

### 2. Packet no-prefetch controls

Cases：

```text
prefetch_hot_l1_load
prefetch_sequential_scan
prefetch_large_stride_scan
prefetch_permuted_index_scan
prefetch_packet_offset_guarded
prefetch_full_packet_ring_scan
```

Construction：

- `hot_l1_load`：反复读同一个 packet offset。
- `sequential_scan`：按 `index * 8` 顺序读 packet。
- `large_stride_scan`：按 64-byte stride 访问 packet 内不同 cacheline。
- `permuted_index_scan`：用 deterministic permutation 访问 bounded offsets。
- `packet_offset_guarded`：variable offset 经过 bounds check 后再读。
- `full_packet_ring_scan`：在 1400-byte packet 内扩大 ring-like scan。

Policy question：

```text
哪些结构上可 prefetch 的 packet loads 应该明确 skip？
```

Why this case exists：

- hot / sequential / small packet working set 通常不应该 prefetch。
- 验证 selector 不应把 “verifier-safe” 等同于 “profitable”。

Limitation：

- 主要是 negative controls。
- 即使某个样本变快，也不能作为 default-enable 证据。

Current result：

- mixed / weak / slowdown；整体支持 no-prefetch-by-default。

### 3. Packet first-deref cases

Cases：

```text
prefetch_packet_first_deref
prefetch_single_first_deref
```

Construction：

- 先从 packet table offset 读一个 byte index。
- 用 index 计算 target offset。
- 对 final packet deref 做 demand load。
- `single_first_deref` 是最小 coverage case。
- `packet_first_deref` 在 loop 中重复该 pattern。

Policy question：

```text
packet load 产生 scalar index 后，是否应该 prefetch final deref？
```

Why this case exists：

- 它是 selector v3 唯一允许的 non-profile packet candidate。
- 它比普通 packet load 更接近 “地址依赖但仍有一点 lead time” 的形态。

Limitation：

- 仍是 packet working set，不是 large memory working set。
- 只能证明 selector/correctness；性能仍需真实 workload 或 larger working set。

Current result：

- x86/ARM64 smoke 都 `sites_applied=1`。
- performance mixed，不支持 default-enable。

### 4. Indirect / dependent-chain cases

Cases：

```text
prefetch_indirect_lookup
prefetch_indirect_two_stage
prefetch_map_indirect_page
```

Construction：

- `indirect_lookup`：读 table byte，计算 target offset，再读 target。
- `indirect_two_stage`：第一阶段 load 产生中间 index，中间 load 再产生 final target。
- `map_indirect_page`：在 map value 内用 table value 选择 page 和 in-page offset。

Policy question：

```text
dependent address chain 是否还有足够 lead time 让 prefetch 有用？
```

Why this case exists：

- 验证 pointer-chasing / indirect style 不能简单 structural prefetch。
- 如果地址太晚才知道，prefetch hint 只能很晚发，可能只增加成本。

Current result：

- 没有稳定收益；支持 dependent-chain skip。

### 5. Cacheline dedup cases

Cases：

```text
prefetch_cacheline_dedup_scan
prefetch_map_line_dedup
```

Construction：

- 同一 cacheline 内连续读多个 `u64`。
- packet version 用 1400-byte packet。
- map version 用 256 KiB map value 和 64-byte line stride。

Policy question：

```text
同一 cacheline 多个 loads 是否只应 prefetch 一次？
```

Why this case exists：

- 它主要验证 admission / dedup rule。
- 不应把多个 same-line loads 当成多个 independent prefetch opportunities。

Current result：

- dedup 逻辑可用。
- 性能不是稳定 win。

### 6. Map page-stride cases

Cases：

```text
prefetch_map_page_stride
prefetch_map_indirect_page
prefetch_map_line_dedup
```

Construction：

- input：BPF array map value，256 KiB。
- `page_stride`：32 pages 内 deterministic page-spread access。
- `line_dedup`：不同 cacheline / same-line multi-load。
- `indirect_page`：table byte 决定 page 和 in-page offset。

Policy question：

```text
map-backed large working set 是否比 packet case 更适合 prefetch？
```

Why this case exists：

- packet case 太小，可能不敏感。
- map value 更接近 BPF 程序的大 working-set memory access。

Limitation：

- 256 KiB 仍是 synthetic-control。
- same-iteration placement 仍可能 lead time 不足。

Current result：

- map page stride weak / mixed。
- map indirect 和 line dedup 没有稳定收益。

### 7. Same-iteration upper-bound map case

Case：

```text
prefetch_upper_page_stride
```

Construction：

- input：BPF array map value，1 MiB。
- loop：512 rounds。
- address：page-spread offset，覆盖 256 pages。
- demand load 前加入 independent ALU work。
- prefetch 仍针对当前轮 demand address。

Policy question：

```text
如果给 same-iteration prefetch 更大的 working set 和更多 independent work，它是否能变快？
```

Why this case exists：

- 排除 “旧 micro 不够偏向 prefetch” 的可能。
- 给 same-iteration policy 一个更强的 best-case probe。

Current result：

- x86 noise-level。
- ARM64 slowdown。
- 说明 same-iteration placement 本身仍不足。

### 8. Next-iteration / future-address cases

Cases：

```text
prefetch_pipeline_page_stride
prefetch_pipeline_horizon1_page_stride
prefetch_pipeline_horizon2_page_stride
prefetch_pipeline_horizon4_page_stride
```

Construction：

- input：BPF array map value，1 MiB。
- loop：512 rounds。
- current pointer `cur` 用于本轮 demand load。
- future pointer 在本轮提前计算出来。
- `horizon1` 预取 `i+1`。
- `horizon2` 预取 `i+2`。
- `horizon4` 预取 `i+4`。
- 用 pointer barrier 避免 compiler 把 future pointer 优化掉。
- treatment 通过 profile point 指定 BPF PC 和 live register。

Policy question：

```text
预取未来轮次地址是否比预取当前轮地址更有效？
```

Why this case exists：

- 它直接测试 lead time 是否是关键因素。
- 它是当前最接近 PF-LLM “per-load policy / degree / horizon” 思路的 Kinsn synthetic-control case。

Current result：

- ARM64 horizon2/horizon4 + L1 hint 是当前最强 candidate。
- 最新 long-repeat：
  - horizon2 `l1keep` mean T/C `0.945361`
  - horizon4 `l1keep` mean T/C `0.971207`

Limitation：

- 仍是 hand-profiled PC/register。
- 还不是自动 selector。
- 还缺 cache-miss PMU attribution。

### 9. True-degree case

Case：

```text
prefetch_pipeline_degree_page_stride
```

Construction：

- input：BPF array map value，1 MiB。
- 每轮同时计算：
  - current pointer；
  - `i+1` future pointer；
  - `i+2` future pointer；
  - `i+4` future pointer。
- profile points 对三个 future pointer 分别插入 prefetch。

Policy question：

```text
一次 prefetch 多个 future addresses 是否比 single horizon 更好？
```

Why this case exists：

- PF-LLM 把 degree 作为核心 hint。
- Kinsn 没有硬件 degree 字段，只能用多个 explicit prefetch hints 模拟 true degree。

Current result：

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
| fixed-offset struct-field | x86 smoke + ARM64 paired attribution done | `prefetch_struct_field_fixed_offsets` | 1 MiB map value 被看作 fixed-size records；每轮访问 record 内 0/64/128 三个 fields；profile 在 pc 29 对 r2/r6/r4 插 3 个 prefetch points。 | Sandbox-style fixed-offset pattern 是否适合 Kinsn prefetch？当前结果：ARM64 paired T/C `0.959350`，还缺 PMU cache-miss 归因。 |
| multi-level offset | ARM64 paired + c7g PMU attribution done | `prefetch_mlop_index_field` | 地址形态为 record index + field offset；index 和 field 都由 deterministic expression 计算。 | MLOP-style multi-level offset 是否适合 future-address selector？当前结果：PMU-backed timing signal 最强。 |
| normalized degree 1/2/3 | ARM64 paired + c7g PMU attribution done | `prefetch_degree123_page_stride` with degree1/2/3 profiles | 同一个 page-stride stream 同时保留 `i+2/i+4/i+8` future pointers；不同 profile 控制 degree=1/2/3。 | degree 的最优点是否不是当前 `i+1/i+2/i+4` 全发？当前结果：degree1 最好，degree2/3 没超过 degree1。 |
| per-PC policy table / negative filtering stress | schema + x86 smoke + ARM64 paired attribution done | `prefetch_mixed_policy_table` | 同一个 program 内混合 hot fixed load 和 page-stride load；profile schema 用 `prefetch` / `skip` action 表达 per-PC decision。 | per-PC policy 是否优于 program-level policy？no-prefetch filtering 是否能保护性能？当前结果：ARM64 treatment 插 1 个 `prfm` 并 skip 16 个 site，paired T/C `0.990555`，主要证明 schema。 |
| stream-of-strides | case/profile + x86 smoke + ARM64 paired attribution done | `prefetch_stream_of_strides` | loop 内两个交错 stride streams，分别物化 `A(i+2)` 和 `B(i+2)` future pointer；profile 在 pc 316 对 r2/r9 插 2 个 prefetch points。 | 多 stream 是否需要 degree 或 per-stream filtering？当前结果：ARM64 paired T/C `1.553949`，明显变慢。 |

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

## 下一步建议

下一步不是继续加更多 toy pattern，而是对 2026-06-04 已补齐的 three missing policy probes 做
ARM64 attribution：

1. `struct-field`、`mixed-policy-table`、`stream-of-strides` 先跑 ARM64 treatment smoke，保存
   `sites_applied`、JIT dump 和 code-size evidence。
2. 对 smoke 通过的 cases 做 paired treatment/control attribution。
3. 如果 timing 有 positive signal，再用 `c7g.large` 做 PMU attribution。
4. 区分 policy result 和支撑机制结果：JIT dump 只证明 emit，不证明加速。
5. 对没有收益的 cases 保存证据：sites applied、native/JIT dump、timing raw data、PMU 能力状态。
6. 只有在 synthetic-control 上出现稳定正信号后，才进入 corpus site census 和 selector 设计。
