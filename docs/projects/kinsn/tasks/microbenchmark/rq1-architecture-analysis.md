# Kinsn x86 vs ARM64 microbenchmark 差异分析

## 数据口径

本文分析下面两张 27-benchmark RQ1 图：

- `micro/results/figures/sec-6-x86-kinsn-micro-best-raw-27-20260608.pdf`
- `micro/results/figures/sec-6-arm64-kinsn-micro-rejit-27-20260608.pdf`

两张图都来自 `micro/results/figures/kinsn-rq1-micro-percase-20260606.csv`，排除了 `simple` 和 `simple_packet` 两个无 Kinsn 点的 trivial benchmark，并按 x86 speedup 降序排列。

一个必须在论文里说明的口径差异是：x86 图是 LLVM-Kinsn upper-bound candidate over stock kernel eBPF；ARM64 图是 selector-fixed matched ReJIT run。因此，x86/ARM 的逐项差异不能被直接解释成纯硬件架构差异，其中也包含实现路径和实验控制程度的差异。

## 结果概览

27 个 benchmark 上，两种架构的总体收益接近：

| platform | geomean speedup | median speedup | wins/ties/losses | geomean code-size reduction |
|---|---:|---:|---:|---:|
| x86 KVM | 1.242x | 1.205x | 22/2/3 | 24.0% |
| ARM64 AWS | 1.222x | 1.179x | 24/1/2 | 12.9% |

因此，不能把这两张图总结为“x86 明显整体更好”或“ARM 明显整体更好”。更准确的 SIGCOMM-style 结论是：Kinsn 的总体收益在两种 ISA 上都成立，但收益来自不同 workload 类别；x86 的收益更强地伴随 JIT code-size reduction，而 ARM64 的收益更依赖具体指令模式和 applied Kinsn sites。

## per-benchmark 差异模式

x86 显著强于 ARM64 的 benchmark：

| benchmark | x86 speedup | ARM64 speedup | x86/ARM |
|---|---:|---:|---:|
| bitmap_popcount_scan | 2.267x | 0.966x | 2.35x |
| flow_5tuple_rss_hash | 1.455x | 1.106x | 1.31x |
| tracee_syscall_name_table_lookup | 1.527x | 1.175x | 1.30x |
| packet_vlan_tcpopt_parser | 1.364x | 1.049x | 1.30x |
| katran_lb_consistent_hash_select | 1.467x | 1.133x | 1.29x |
| packet_record_bounds_window | 1.639x | 1.272x | 1.29x |

ARM64 显著强于 x86 的 benchmark：

| benchmark | x86 speedup | ARM64 speedup | ARM/x86 |
|---|---:|---:|---:|
| cgroup_skb_hash_chain | 0.976x | 1.616x | 1.66x |
| payload_prefix_memcmp_scan | 0.796x | 1.179x | 1.48x |
| cilium_socket_lb_service_select | 1.145x | 1.691x | 1.48x |
| bcc_tcpconnect_ipv4_tuple_filter | 1.117x | 1.624x | 1.45x |
| cilium_ct_nat_tuple_rewrite | 1.073x | 1.482x | 1.38x |
| packed_header_bitfield_decode | 0.835x | 1.134x | 1.36x |

两边都稳定受益的 benchmark 包括 `siphash_rotate64_mixer`、`bpftrace_string_search_prefix_scan`、`packet_checksum_fold`、`tc_packet_checksum_fold`、`tetragon_process_event_arg_filter` 等。这说明 Kinsn 的核心效果不是单架构偶然现象，而是能跨 ISA 改善一些常见 BPF 模式。

## 可能原因

### 1. x86 收益更像 code-size / instruction-count 效应

x86 上 speedup 与 code-size reduction 的相关性较高，相关系数约为 0.62。典型例子包括：

- `siphash_rotate64_mixer`: code size 降低 55.5%，speedup 1.742x。
- `bpf_local_call_fanout_dispatch`: code size 降低 49.9%，speedup 1.488x。
- `packet_record_bounds_window`: code size 降低 44.0%，speedup 1.639x。
- `bitmap_popcount_scan`: code size 降低 33.1%，speedup 2.267x。

这说明 x86 stock eBPF JIT 在这些 microbenchmark 上可能生成了较长、较保守的指令序列；Kinsn/LLVM-Kinsn candidate 更容易通过融合、消除冗余边界检查或压缩常见数据路径来减少动态指令数和 front-end pressure。对 x86 来说，短代码通常直接转化为更少的 decode/uop-cache/front-end 开销，所以 code-size reduction 与 speedup 同向。

### 2. ARM64 收益更依赖是否命中特定 idiom，而不是单纯 code size

ARM64 上 speedup 与 code-size reduction 的相关性很弱，约为 -0.17；但是 speedup 与 applied sites 有中等相关性，约为 0.49。典型例子：

- `siphash_rotate64_mixer`: 124 个 applied sites，ARM64 speedup 1.902x。
- `cilium_socket_lb_service_select`: applied sites 7，ARM64 speedup 1.691x。
- `bcc_tcpconnect_ipv4_tuple_filter`: applied sites 8，ARM64 speedup 1.624x。
- `cilium_ct_nat_tuple_rewrite`: applied sites 10，ARM64 speedup 1.482x。

这表明 ARM64 的收益更像“命中特定 instruction idiom 后改变关键路径”的效果，而不是简单压缩代码体积。ARM64 本身是固定长度指令 ISA，stock JIT 的 code-size/decoder 行为与 x86 不同；同样的代码缩短比例不一定带来同样的前端收益。相反，当 Kinsn 把 rotate/hash/packet-field extraction 等模式映射到更合适的 ARM64 指令序列时，收益会很明显。

### 3. stock kernel JIT 的架构基线不同

Kinsn 的 speedup 本质上是相对 stock kernel eBPF JIT 的提升，因此它取决于每个架构的 stock JIT 已经做得多好。一个 benchmark 在 x86 上提升大，可能是因为 x86 stock JIT 对该模式更保守；同一个 benchmark 在 ARM64 上提升小，可能是因为 ARM64 stock JIT 的基线已经接近目标序列，或者 Kinsn 选择器没有生成更优映射。

这可以解释 `bitmap_popcount_scan`：x86 从 1.0x 提升到 2.267x，但 ARM64 是 0.966x。它不像是 workload 本身不适合 Kinsn，而更可能是 x86 LLVM-Kinsn candidate 对 bitmap loop 的代码形态改变更大；ARM64 matched ReJIT 没有得到同等程度的关键路径缩短，甚至可能引入了局部 instruction scheduling 或 register pressure 代价。

### 4. packet/network workloads 在 ARM64 上更强

按 workload 类别聚合，packet/Cilium 类在 ARM64 上更强：

| group | x86 geomean | ARM64 geomean |
|---|---:|---:|
| packet/Cilium | 1.267x | 1.303x |
| bit/rotate/hash | 1.320x | 1.205x |
| scan/search | 1.312x | 1.155x |
| dispatch/table | 1.251x | 1.100x |

这说明 ARM64 不是整体更弱，而是收益集中在 packet parsing、tuple rewrite、socket LB、tcpconnect filtering 等网络路径。这对 SIGCOMM 文章是好消息：文章关心的是网络系统和 production eBPF，而不是每个 synthetic micro 都必须同等提升。可以把这个作为 cross-architecture robustness 的重点：Kinsn 在 ARM64 上对网络相关 idiom 仍然有效。

### 5. 少数 regression 应该作为边界条件讨论

需要显式讨论的 regression：

- x86 regression: `payload_prefix_memcmp_scan` 0.796x，`packed_header_bitfield_decode` 0.835x，`cgroup_skb_hash_chain` 0.976x。
- ARM64 regression: `bitmap_popcount_scan` 0.966x，`bpftrace_comm_key_fnv_hash` 0.862x。

这些说明 Kinsn 不是无条件收益。可能原因包括：转换后代码尺寸变小但调度/寄存器压力变差；分支布局改变导致预测或 I-cache 行为变差；benchmark 本身过短，固定开销和噪声放大；或者某些 idiom 在该 ISA 的 stock JIT 中已经足够好。

## 建议写法

可以在 evaluation 中这样写：

> Although the geomean improvements on x86 and ARM64 are similar, the per-benchmark distributions reveal different mechanisms. On x86, Kinsn speedups are strongly associated with native code-size reduction, suggesting that the LLVM-Kinsn candidate primarily reduces front-end and dynamic-instruction overhead relative to the stock kernel JIT. On ARM64, code-size reduction is a weaker predictor; improvements are concentrated in benchmarks with many applied Kinsn sites and in packet-processing idioms such as socket load balancing, TCP tuple filtering, and NAT tuple rewriting. This suggests that Kinsn is not merely a code-size optimization, but an architecture-sensitive specialization mechanism whose benefit depends on both the stock JIT baseline and the availability of efficient target-ISA idioms.

中文对应写法：

> 两个架构的总体 geomean 很接近，但 per-benchmark 分布不同。x86 上的收益更强地伴随 JIT code size 降低，说明 Kinsn 在该路径上主要通过缩短 stock kernel JIT 生成的保守指令序列来降低 front-end 和动态指令开销。ARM64 上 code size 与 speedup 的相关性较弱，收益更多集中在 applied Kinsn sites 较多以及 packet-processing idiom 明显的 workload 中，例如 socket LB、TCP tuple filter 和 NAT tuple rewrite。这说明 Kinsn 不是简单的代码尺寸优化，而是依赖 stock JIT baseline、目标 ISA idiom 和 workload 结构的架构敏感 specialization。

## 图表建议

除了现有两张 per-benchmark speedup 图，建议补一个小表或小图：

1. x86 vs ARM64 per-benchmark scatter plot：横轴 x86 speedup，纵轴 ARM64 speedup，标出 `bitmap`、`sock_lb`、`tcpconn`、`cgroup`、`siphash`。
2. 每类 workload 的 geomean 表：packet/Cilium、bit/hash、scan/search、dispatch/table。
3. 相关性说明表：x86 speedup vs code-size reduction 相关性约 0.62；ARM64 speedup vs code-size reduction 约 -0.17；ARM64 speedup vs applied sites 约 0.49。

这样比只放两张柱状图更像系统论文：不只是展示结果，而是解释为什么不同架构上收益来自不同机制。
