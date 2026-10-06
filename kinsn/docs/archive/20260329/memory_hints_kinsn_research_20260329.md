# Prefetch + NT store 在 BPF 程序中的优化价值调研

日期：2026-03-29  
面向项目：BpfReJIT / kinsn 调研  
历史上下文：
- `/home/yunwei37/.codex/sessions/2026/03/29/rollout-2026-03-29T18-33-04-019d3c5f-7fcc-7643-828d-850b42d7cd14.jsonl`
- `/home/yunwei37/.codex/sessions/2026/03/29/rollout-2026-03-29T18-52-19-019d3c71-1fb4-75c2-8c18-7643a09a2657.jsonl`

## TL;DR

- 当前 corpus 里，`Prefetch` 的“潜在站点数”很大：精确统计到 `17391` 个 `map_lookup_elem` 和 `21` 个 `map_lookup_percpu_elem`。但把这些 lookup 精确还原到 map family 时，绝大多数编译后 site 都落在 `unknown`，所以 map-type 结论只能给 lower bound。
- `NT store` 的直接 BPF-side 机会很窄。真正能在 BPF 指令流里直接写目标缓冲区的，基本只剩 `ringbuf_reserve -> stores -> ringbuf_submit` 这一类；当前 corpus 里只有 `10` 个 reserve site 和 `9` 个 submit site。更大的写流量热点其实是 `map_update_elem`、`perf_event_output`、`ringbuf_output` 这些 helper 内部 copy。
- 从机制上说，这两个方向都不是“因为需要插入新指令所以做不了”。当前 daemon pass 已经能插入 `kinsn_sidecar + call_kinsn`，并重建指令流、修 branch target、携带 BTF FD。
- 真正的分水岭在 profitability：
  - `Prefetch` 明显更依赖 runtime-guided / PGO-style gate，因为它是否有收益高度依赖 hotness、miss 行为和 prefetch distance。
  - `NT store` 也需要 gate，但当前最大问题不是缺 profile，而是 direct site 太少。
- 如果要把 memory hints 作为 BpfReJIT 的一个研究方向继续推进，应该优先保留 `Prefetch`，并明确把它定义成一个 runtime-guided 方向；`NT store` 不值得作为当前阶段的优先 kinsn。

## 1. 范围与方法

本文只做静态调研，不改代码，不跑 VM。

本次结论来自四类输入：

1. 恢复并继承两次被中断 session 的工作历史。
2. 复核仓库内已有 PGO / kinsn 调研文档，特别是 `docs/tmp/20260320/pgo_policy_design_20260320.md`。
3. 复核 daemon 当前 pass / kinsn plumbing，确认“插入新指令”在现有框架里是否可行。
4. 使用前一轮 session 已完成的 object-level helper census 与 map-family lower-bound 归类结果。

统计口径有两个关键说明：

- `helper` 调用次数是精确计数。
- `lookup -> map family` 的分类不是精确计数，而是 lower bound。原因是很多编译后 site 经过 wrapper、宏和间接表达式之后，已经不能从简单的源注释 / relocation 关联里稳定还原到具体 map symbol。

## 2. Corpus Site Count

### 2.1 按 repo 的精确 helper site count

下表只列出有非零相关站点的 repo。`xdp-examples`、`xdp-tutorial`、`libbpf-bootstrap`、`bcc`、`bpftrace` 等没有进入这组热点 helper 统计，故省略。

| repo | `map_lookup_elem` | `map_lookup_percpu_elem` | `map_update_elem` | `perf_event_output` | `ringbuf_output` | `ringbuf_reserve` | `ringbuf_submit` |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `KubeArmor` | 2671 | 0 | 934 | 28 | 0 | 9 | 8 |
| `calico` | 534 | 0 | 101 | 12 | 0 | 0 | 0 |
| `cilium` | 2118 | 0 | 1422 | 120 | 0 | 0 | 0 |
| `coroot-node-agent` | 157 | 0 | 35 | 29 | 0 | 0 | 0 |
| `datadog-agent` | 7 | 0 | 3 | 0 | 0 | 0 | 0 |
| `katran` | 85 | 0 | 4 | 0 | 0 | 0 | 0 |
| `linux-selftests` | 22 | 0 | 0 | 0 | 0 | 0 | 0 |
| `loxilb` | 280 | 0 | 112 | 16 | 0 | 0 | 0 |
| `netbird` | 13 | 0 | 0 | 0 | 0 | 0 | 0 |
| `opentelemetry-ebpf-profiler` | 76 | 0 | 10 | 4 | 0 | 0 | 0 |
| `scx` | 81 | 21 | 3 | 0 | 0 | 1 | 1 |
| `suricata` | 16 | 0 | 0 | 0 | 0 | 0 | 0 |
| `systemd` | 16 | 0 | 0 | 0 | 2 | 0 | 0 |
| `tetragon` | 6645 | 0 | 1015 | 136 | 63 | 0 | 0 |
| `tracee` | 4555 | 0 | 336 | 275 | 0 | 0 | 0 |
| `tubular` | 4 | 0 | 0 | 0 | 0 | 0 | 0 |
| `xdp-tools` | 111 | 0 | 8 | 0 | 0 | 0 | 0 |
| **total** | **17391** | **21** | **3983** | **620** | **65** | **10** | **9** |

对两个方向最重要的读法是：

- `Prefetch` 的候选规模是 lookup 量级，集中在 `tetragon`、`tracee`、`KubeArmor`、`cilium`。
- `NT store` 如果只看 direct BPF-side write，几乎只剩 `KubeArmor` 和 `scx` 的 `ringbuf_reserve/submit` 站点。

### 2.2 Prefetch 的 map-type lower bound

`map_lookup*` 的 helper 次数是精确的，但 family 归类只能做 lower bound。

全局 lower-bound 结果：

| 指标 | 数量 |
| --- | ---: |
| 精确 `map_lookup_elem` | 17391 |
| 精确 `map_lookup_percpu_elem` | 21 |
| 已解析 `array` family lower bound | 248 |
| 已解析 `hash` family lower bound | 53 |
| 未解析 / `unknown` lower bound | 17111 |

已解析的具体 map type lower bound：

| map type | 数量 |
| --- | ---: |
| `BPF_MAP_TYPE_PERCPU_ARRAY` | 221 |
| `BPF_MAP_TYPE_HASH` | 38 |
| `BPF_MAP_TYPE_ARRAY` | 27 |
| `BPF_MAP_TYPE_LRU_HASH` | 14 |
| `BPF_MAP_TYPE_HASH_OF_MAPS` | 1 |

按 repo 看，能稳定还原出部分 family 的代表性样本如下：

| repo | `hash` lower bound | `array` lower bound | 备注 |
| --- | ---: | ---: | --- |
| `tetragon` | 27 | 120 | 仍有 `6498` 个 unresolved |
| `tracee` | 9 | 96 | 仍有 `4450` 个 unresolved |
| `KubeArmor` | 3 | 0 | 仍有 `2668` 个 unresolved |
| `loxilb` | 0 | 16 | 仍有 `264` 个 unresolved |
| `coroot-node-agent` | 11 | 0 | 仍有 `146` 个 unresolved |
| `calico` | 0 | 6 | 仍有 `528` 个 unresolved |
| `systemd` | 3 | 0 | 仍有 `13` 个 unresolved |
| `xdp-tools` | 0 | 4 | 仍有 `107` 个 unresolved |
| `scx` | 0 | 3 | 另有 `21` 个 `map_lookup_percpu_elem` |

这组数据足够支撑两个结论：

- 当前 corpus 里确实存在 `hash/LRU_HASH` lookup，但可直接解析出来的只是一小部分。
- `array/PERCPU_ARRAY` 更容易被静态归类和 specialization，这也意味着它们更接近 map-inline 一类已有优化的舒适区。

### 2.3 NT store 的真正 direct-site 有多小

如果把 “BPF JIT 可以直接把 store 改成 `MOVNTI`” 作为标准，那么当前 corpus 里最接近的只有 `ringbuf_reserve` 路线：

- `ringbuf_reserve`: `10`
- `ringbuf_submit`: `9`

更大的写流量并不等于 direct NT-store 机会：

- `map_update_elem`: `3983`
- `perf_event_output`: `620`
- `ringbuf_output`: `65`

这些调用量说明“写密集 tracing / telemetry 程序”确实存在，但大多写入发生在 helper 内部 copy path，不在 BPF 程序自己的 store 指令里。

## 3. 这些数字意味着什么

### 3.1 Prefetch 的机会主要在 lookup-heavy 程序

从纯数量上看，`Prefetch` 的机会明显大于 `NT store`：

- lookup site 是 `17412` 量级。
- direct ringbuf reserve/store/submit site 只有个位数到十位数。

但 `Prefetch` 不是“site 多就能盲开”的优化。真正可能有较大收益的，一般是 hash / LRU-hash 一类容易发生 pointer-chasing 和 cache miss 的 lookup；而 array / percpu-array 虽然也能做 prefetch，但地址模式更规则，也更容易被更便宜的 specialization 吃掉。

### 3.2 NT store 的大头热点在 helper 内部，不在 BPF store 本身

`tracee`、`tetragon`、`cilium` 这些 repo 的 `perf_event_output` / `map_update_elem` 量都很高，说明“单向写出大量 telemetry 数据”在 corpus 里是存在的。

但这里要澄清一个容易混淆的点：

- `bpf_map_update_elem()` 是 “把 `value` 指针指向的数据写进 map”，真正的 map memory write 发生在 helper 内部。
- `bpf_perf_event_output()` 是 “把 blob 写入 perf-event buffer”，真正的 copy 也在 helper 内部。
- `bpf_ringbuf_output()` 也是 helper copy。

所以如果优化面定义为 “BPF-side 把现有 store peephole 成 `MOVNTI`”，那这些热点不能直接复用。它们更像 helper specialization / helper lowering 的候选，而不是 BPF-side NT store pass 的候选。

## 4. 当前 daemon / kinsn 框架是否支持“插入新指令”

答案是支持，困难不在 plumbing。

已经确认的机制证据：

- `daemon/src/passes/utils.rs:494-517` 已经有 `emit_packed_kinsn_call_with_off()` 和 `ensure_btf_fd_slot()`，可以发出 `kinsn_sidecar + call_kinsn`，并把目标 BTF FD 填进 `fd_array`。
- `daemon/src/passes/rotate.rs:140-185` 已经在实际 pass 里重建整段 instruction stream，并在替换后做 `fixup_all_branches()`。
- `daemon/src/pass.rs:457-488` 的 `PassContext` / `KinsnRegistry` 已经提供了 kinsn target、BTF FD 和平台能力入口。
- `daemon/src/pass.rs:881-895` 的 `run_with_profiling_and_verifier()` 已经能在跑 pass 前把 profiling 注入 program annotation。

所以“Prefetch / NT store 不是简单替换旧指令，而是要插入新指令”这一点本身，不构成阻碍。

真正难点在这里：

1. 识别哪些 site 真正有意义。
2. 为这些 site 找到 verifier-safe、pointer-safe 的地址表达。
3. 证明不会破坏原有内存语义和 publication ordering。

## 5. 实现路径分析

### 5.1 Prefetch

`Prefetch` 至少有三种不同语义，不能混成一个：

1. **helper 调用前，对“真正将被访问的 map value / bucket / node”做 prefetch**
2. **helper 返回 value pointer 后，对随后要读的 value line 做 prefetch**
3. **只 prefetch map 元数据或固定基址**

这三种里，真正有说服力的是第 1 种，但它也是最难的。

原因是：在普通 `bpf_map_lookup_elem(map, key)` 调用点之前，BPF 指令流手里通常只有 `map` 和 `key`，没有 helper 内部最终要访问的 bucket/node/value 地址。也就是说，简单地在 helper call 前插一个 `PREFETCHT0`，并不自动等于“prefetch 到真正有价值的 cache line”。

当前树上更现实的实现入口有两个：

- **map-inline-like specialization**
  - `daemon/src/analysis/map_info.rs:36-65` 已经把“哪些 map type 支持 direct value access”刻画出来。
  - `daemon/src/passes/map_inline.rs:53-66`、`daemon/src/passes/map_inline.rs:768-822` 已经有 lookup-site discovery、map info resolution、fixed-load use classification。
  - 这说明 pass 侧已经能识别一部分 “lookup 之后马上读固定 offset value” 的模式。
- **helper lowering / specialized kinsn**
  - 如果想碰到 hash/LRU-hash 真正高 miss 的内部访问，最终更像是把 helper 语义下沉，或者新增一个在 kernel/JIT 空间里自行推导目标地址的 prefetch kinsn，而不是在 BPF-side 盲目 prefetch。

一个重要判断是：

- 对 array / percpu-array，地址模式更规则，很多情况下更适合直接做 map-inline / direct-load specialization，prefetch 只是次优选项。
- 对 hash / LRU-hash，prefetch 理论收益更大，但静态 pass 更难在 helper 边界外拿到正确地址。

因此，`Prefetch` 的难点不是“怎么插一个 hint”，而是“什么时候、对哪一条线插这个 hint”。

### 5.2 NT store

这里必须先纠正一个常见误解：`map_update_elem` 之后并没有一个“对 map memory 的 BPF store”可供直接换成 `MOVNTI`。同理，`perf_event_output` / `ringbuf_output` 也没有。

按实现方式分，`NT store` 只有两条路：

1. **BPF-side direct store rewrite**
   - 典型对象是 `ringbuf_reserve()` 返回的 record pointer。
   - 这时 BPF 程序确实会对返回指针做一串 `stx/st`，然后 `ringbuf_submit()`。
   - 这类 site 数量很少，但语义最像“把普通 store 换成 NT store”。
2. **helper-side copy specialization**
   - 典型对象是 `map_update_elem`、`perf_event_output`、`ringbuf_output`。
   - 这里真正的 copy 在 helper 内部；如果想用 streaming store，应该在 helper lowering 或 helper 本身实现里做，而不是在 BPF-side peephole。

就当前 corpus 而言，第 1 条路的 direct site 太少，第 2 条路又已经不再是“小 kinsn”问题，而是 helper specialization 问题。

### 5.3 verifier 与内存语义

两类 hint 都不能被当作“纯装饰”处理。

- `Prefetch` 需要合法、已知边界的地址表达。否则 pass 很容易在 verifier 语义外制造一个不可证明安全的额外 memory touch。
- `NT store` 需要证明写后不读，或者至少证明 immediate reread 不重要。否则 non-temporal 路径反而可能伤害局部性。
- 如果 `NT store` 用在 `ringbuf_reserve -> submit` 路径上，还必须确认 publish 语义不被破坏。这里我把“需要额外审计 ordering / visibility”视为工程推断：因为 ringbuf 文档明确规定了 record 提交后的可见性与 reservation order，而 `MOVNTI` 属于专门的 non-temporal store 语义，不能默认与当前普通 store 完全等价。

## 6. 预期收益与风险

### 6.1 Prefetch

理论收益：

- 如果命中的是 hot hash / LRU-hash lookup，并且 prefetch distance 合适，它可以隐藏一部分 lookup miss latency，尤其是在后续还要继续读取 returned value 的情况下。
- 对 lookup-heavy tracing / policy 程序，收益上限显然比 direct NT-store 大，因为 site count 高两个数量级。

主要风险：

- **时机敏感**：太早会把线提前驱逐，太晚又隐藏不了 miss。
- **目标敏感**：对错 cache line prefetch 只会浪费带宽。
- **静态信息不够**：helper 边界外往往没有最终访问地址。
- **blanket insertion 很危险**：没有 runtime gate 的普遍启用，大概率会带来噪声甚至回退。

### 6.2 NT store

理论收益：

- 对真正的 streaming write-only path，non-temporal store 可以减少 cache pollution。
- 如果 payload 足够大、producer 很热、写后几乎不 reread，这个方向在 tracing/event export 场景是有理论吸引力的。

主要风险：

- **当前 corpus 的 direct site 太少**：只有 `10/9` 级别的 reserve/submit。
- **多数热点是 helper-internal copy**：BPF-side pass 根本碰不到。
- **读后重用风险**：如果刚写完很快又读，NT store 可能适得其反。
- **publication ordering 审计成本高**：尤其是 ringbuf 这类 producer/consumer 接口。

## 7. Prefetch 和 PGO / runtime-guided 的关系

这是这次调研最重要的结论之一。

仓库内已有 PGO 设计文档已经把边界讲得很清楚：

- `docs/tmp/20260320/pgo_policy_design_20260320.md:28-32`
  - 已有 `program-level hotness`，缺的是 `per-site attribution`。
- `docs/tmp/20260320/pgo_policy_design_20260320.md:81-92`
  - `coarse-grained PGO` 今天就能做，`fine-grained per-site PGO` 目前只能近似。
- `docs/tmp/20260320/pgo_policy_design_20260320.md:723-748`
  - 内核自己的 in-tree profile-guided build 入口就是 `AUTOFDO_CLANG` / `PROPELLER_CLANG`。
- `docs/tmp/20260320/pgo_policy_design_20260320.md:822`
  - BpfReJIT 的价值不在于“发明 profile”，而在于给 eBPF JIT 提供 safe, bounded, post-load optimization interface。

`Prefetch` 比大多数 pass 更依赖 runtime-guided 信息，原因有三个：

1. **site hotness 决定值不值得插**
   - cold lookup 根本不值得多一条 memory hint。
2. **workload miss 行为决定 hint 是否有收益**
   - 同一个 lookup site，在不同工作负载下可能完全不同。
3. **distance 调参本身就是 runtime-sensitive**
   - Intel 的 prefetch directive 文档本身就是用 “多少个 loop iterations 提前量” 来表达 prefetch distance，这说明它天然依赖运行时行为和执行节奏。

对比之下，`NT store` 也需要 runtime gate，但它的收益判定更像一个保守过滤条件：

- 只有在“足够热、明显 streaming、写后基本不读”的 site 上才值得考虑。
- 而当前 corpus 的主要问题首先是 direct site 不够多，其次才是缺细粒度 profile。

所以：

- **Prefetch 是更好的 runtime-guided showcase。**
- **NT store 更像一个窄场景、强前提、helper-lowering 优先的问题。**

## 8. 结论与优先级建议

### 8.1 是否需要 PGO 数据

需要，尤其是 `Prefetch`。

但这里的 “需要” 不是说必须先做 full AutoFDO/BOLT-style per-site attribution 才能开始，而是：

- 第一阶段就该接入 coarse-grained runtime gate，至少按 program hotness / runtime profile 过滤。
- 更细的 site 选择和 distance 调优，后面再做更重的 attribution。

### 8.2 哪个方向更能体现 runtime-guided 优势

明确是 `Prefetch`。

理由：

- 它的收益高度依赖 workload 和 hotness。
- 它不是一个静态永远正确的 peephole。
- 它和现有 `run_with_profiling_and_verifier()`、program-level profiling 注入天然兼容。

### 8.3 当前阶段该不该做

建议排序如下：

1. **不要优先做 NT-store kinsn。**
   - direct site 太少。
   - 真正的大头热点在 helper 内部。
2. **把 Prefetch 保留为 phase-2 方向，但必须绑定 runtime-guided policy。**
   - 最适合做成 “hot program only + narrow site family only” 的选择性优化。
3. **如果论文或系统叙事里只选一个 memory hint 方向，选 Prefetch，不选 NT store。**
   - 它更能体现 BpfReJIT 的 runtime-guided 优势。
   - 也更符合现有 PGO 设计文档已经铺好的路线。

## 参考

本地代码与文档：

- `daemon/src/passes/utils.rs:494-517`
- `daemon/src/passes/rotate.rs:140-185`
- `daemon/src/pass.rs:457-488`
- `daemon/src/pass.rs:881-895`
- `daemon/src/analysis/map_info.rs:36-65`
- `daemon/src/passes/map_inline.rs:53-66`
- `daemon/src/passes/map_inline.rs:768-822`
- `vendor/linux-framework/include/uapi/linux/bpf.h:1966-1989`
- `vendor/linux-framework/include/uapi/linux/bpf.h:2481-2510`
- `vendor/linux-framework/include/uapi/linux/bpf.h:4627-4676`
- `docs/tmp/20260320/pgo_policy_design_20260320.md`

外部一手资料：

- Linux kernel ring buffer 文档：<https://docs.kernel.org/bpf/ringbuf.html>
- Linux kernel Propeller 文档：<https://docs.kernel.org/6.14/dev-tools/propeller.html>
- Intel prefetch directives 文档：<https://www.intel.com/content/www/us/en/docs/fortran-compiler/developer-guide-reference/2025-1/prefetch-and-noprefetch-general-directives.html>
- Intel Intrinsics Guide：<https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html>
