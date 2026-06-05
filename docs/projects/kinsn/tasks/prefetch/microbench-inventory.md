# Kinsn Prefetch Microbenchmark Inventory

最后更新：2026-06-05。

## 结论

当前 `micro_pure_jit` suite 里的 benchmark 必须分三类看：

1. repo 中已有的 workload-shaped micro；
2. ARM LLVM backend task 新增的 kinsn coverage micro；
3. prefetch task 新增的策略 / 安全覆盖 / 性能归因 micro。

这三类不能混在一起解释。原有 workload-shaped micro 用来观察现有 workload 上是否自然触发某类优化；
ARM LLVM backend 新增 micro 多数是 ABI / selector coverage；prefetch 新增 micro 多数是 synthetic-control，
用于回答特定 prefetch policy 是否可能有效。

Manifest 路径：

```text
/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml
```

本文件中的分类依据是当前 branch 的 manifest tags 和 git history：

- ARM LLVM backend coverage micro 首次加入在 `2026-05-26` / `2026-05-27` 的 micro commits。
- prefetch micro 使用 `new-2026-*` / `prefetch` tags，主要首次加入在 `2026-06-02`，之后继续扩展。
- 没有 `prefetch` tag、也不是 ARM64 coverage tag 的条目归为已有 workload-shaped micro。

## Case 类型定义

| 类型 | 目的 | 是否能作为 prefetch 性能收益证据 |
|---|---|---|
| workload-shaped micro | 模拟真实 BPF workload 中的 packet、map、branch、hash、string、field scan 等形态。 | 可以作为通用 regression / broad coverage；如果要证明 prefetch 收益，还必须显示它触发具体 prefetch policy 且有 PMU evidence。 |
| ABI / selector coverage micro | 让某个 kfunc / kinsn family 的 ABI、selector、JIT emit 被覆盖。 | 不能。它只证明能 emit / 能跑。 |
| 安全覆盖 prefetch micro | 验证 prefetch pass 能识别 site、插入 kinsn、通过 verifier/JIT/runtime。 | 不能。 |
| 负向对照 prefetch micro | 验证某类形态不应该 prefetch，例如 hot load、无提前量、sequential stream、dependent chain。 | 不能证明加速；能证明跳过规则 / admission rule。 |
| 性能归因 prefetch micro | 构造 high-miss 基线、明确 future address、足够提前量，用 PMU 解释加速或变慢。 | 可以，但只代表受控 micro pattern，不代表真实程序覆盖率。 |

## Repo 里已有的 workload-shaped micro

这 29 个 case 是 ARM LLVM backend coverage 和 prefetch task 之前已经存在或不属于这两类新增任务的
workload-shaped micro。它们不是专门为 prefetch policy 构造的。

| benchmark | tags | 主要作用 |
|---|---|---|
| `simple` | `baseline,pure-jit` | 最小基线。 |
| `simple_packet` | `baseline,packet-backed,helper-free` | packet-backed 基线。 |
| `bitmap_popcount_scan` | `bitops,pure-jit` | bitmap / bit operation scan。 |
| `sorted_rule_binary_search` | `branch,search,pure-jit` | rule lookup / branch search。 |
| `bcc_runqlat_log2_histogram_bucket` | `bcc,tracing,log2,histogram,pure-jit` | BCC tracing histogram bucket。 |
| `trace_event_type_switch_dispatch` | `branch,dispatch,pure-jit` | trace event type dispatch。 |
| `packet_checksum_fold` | `alu,memory,pure-jit` | packet checksum fold。 |
| `payload_prefix_memcmp_scan` | `memory,compare,branch,pure-jit` | payload prefix compare / scan。 |
| `packet_vlan_tcpopt_parser` | `packet,parse,bounds,variable-offsets,pure-jit` | packet parser with bounds and variable offsets。 |
| `bpf_local_call_fanout_dispatch` | `call,bpf-to-bpf,local-call,reg-pressure,pure-jit` | BPF local call / register pressure。 |
| `flow_5tuple_rss_hash` | `packet,hash,endian,pure-jit` | flow tuple hash / endian shape。 |
| `katran_lb_consistent_hash_select` | `packet,katran,hash,endian,pure-jit` | Katran-like hash selection。 |
| `cilium_policy_guard_tree_filter` | `cilium,branch,nested,guards,pure-jit` | Cilium-like guard tree filter。 |
| `siphash_rotate64_mixer` | `compute,rotate,hash,pure-jit` | rotate-heavy hash mixer。 |
| `packet_record_bounds_window` | `packet,bounds,redundant-checks,pure-jit` | packet bounds window。 |
| `flow_record_field_scan` | `memory,fields,fixed-offsets,pure-jit` | record fixed-field scan。 |
| `packed_header_bitfield_decode` | `memory,fields,bitfield,pure-jit` | packed header bitfield decode。 |
| `bpftrace_string_search_prefix_scan` | `bpftrace,string,compare,loop,pure-jit` | bpftrace-like string prefix scan。 |
| `tracee_syscall_name_table_lookup` | `tracee,syscall,dispatch,pure-jit` | Tracee syscall name dispatch。 |
| `tracee_http_method_prefix_detect` | `tracee,http,string,branch,pure-jit` | Tracee HTTP method prefix detect。 |
| `cilium_socket_lb_service_select` | `cilium,socket-lb,branch,hash,pure-jit` | Cilium socket LB selection。 |
| `bcc_tcpconnect_ipv4_tuple_filter` | `bcc,tracing,tuple,branch,pure-jit` | BCC tcpconnect tuple filter。 |
| `tetragon_process_event_arg_filter` | `tetragon,security,branch,string,pure-jit` | Tetragon process-event arg filter。 |
| `otel_stack_frame_unwind_scan` | `otel,profiler,stack,fields,pure-jit` | OpenTelemetry stack unwind scan。 |
| `cilium_ct_nat_tuple_rewrite` | `cilium,conntrack,nat,tuple,pure-jit` | Cilium conntrack/NAT tuple rewrite。 |
| `packet_toeplitz_rss_hash` | `packet,hash,toeplitz,rss,pure-jit` | Toeplitz RSS hash。 |
| `bpftrace_comm_key_fnv_hash` | `bpftrace,tracing,hash,string,pure-jit` | bpftrace comm key FNV hash。 |
| `tc_packet_checksum_fold` | `tc,pure-jit,non-xdp,kernel-only` | TC checksum fold kernel-only case。 |
| `cgroup_skb_hash_chain` | `cgroup-skb,pure-jit,non-xdp,kernel-only` | cgroup skb hash chain kernel-only case。 |

这些 case 最终仍然需要用于 integrated prefetcher regression：如果 selector 默认启用或 profile-fed
selector 进入通用路径，必须确认它不会让原有 workload-shaped suite 系统性变慢。

## ARM LLVM backend 新增的 micro

这 5 个用例是 ARM64 LLVM kinsn backend 的覆盖 / ABI 用例。它们不是 prefetch 性能用例。

| benchmark | first-added commit intent | tags | 目的 |
|---|---|---|---|
| `csel_select64` | `micro: add arm64 kinsn coverage programs` | `select,csel,pure-jit,coverage` | 覆盖 CSEL selector / ABI。 |
| `ccmp_all_nonzero` | `micro: add arm64 kinsn coverage programs` | `compare,ccmp,pure-jit,coverage` | 覆盖 CCMP/CMP/CSET 相关 shape。 |
| `stp_stack_pair` | `micro: add arm64 kinsn ABI coverage cases` | `memory,pair-store,stp,pure-jit,coverage` | 覆盖 STP pair-store ABI。 |
| `ldp_stack_pair` | `micro: add arm64 kinsn ABI coverage cases` | `memory,pair-load,ldp,pure-jit,coverage` | 覆盖 LDP pair-load ABI。 |
| `arm64_direct_abi_coverage` | `micro: add arm64 kinsn ABI coverage cases` | `memory,direct-load,direct-store,arm64-abi,pure-jit,coverage` | 覆盖 ARM64 direct load/store ABI。 |

这些 case 可以证明 ARM64 LLVM backend 能 emit 对应 `bpf_arm64_*` target，但不能证明 prefetch
策略有效。

## Prefetch task 新增的 micro

Prefetch task 当前有 38 个 micro benchmark。它们要再分成安全覆盖、负向对照、
性能归因和诊断，不应该统一解释为“prefetch benchmark”。

### 安全覆盖 / 负向对照

这些用例的主要作用是验证 pass 能安全插入或应当跳过。多数用例的 control cache miss 为 0 或很低，
不能作为 prefetch 性能收益证据。

| benchmark | source file | 用例类型 | 测什么 |
|---|---|---|---|
| `prefetch_distance_0` | `prefetch_research.bpf.c` | 负向对照 | no-lead-time same-iteration。 |
| `prefetch_distance_2` | `prefetch_research.bpf.c` | 负向对照 | 短提前量。 |
| `prefetch_distance_4` | `prefetch_research.bpf.c` | 负向对照 | 短提前量。 |
| `prefetch_distance_8` | `prefetch_research.bpf.c` | 负向对照 | fixed-distance same-iteration。 |
| `prefetch_distance_16` | `prefetch_research.bpf.c` | 负向对照 | fixed-distance same-iteration。 |
| `prefetch_distance_32` | `prefetch_research.bpf.c` | 负向对照 | 更长 same-iteration delay；基线 miss 仍低。 |
| `prefetch_hot_l1_load` | `prefetch_research.bpf.c` | 负向对照 | hot load skip。 |
| `prefetch_sequential_scan` | `prefetch_research.bpf.c` | 负向对照 | sequential stream skip / hardware-prefetch-covered shape。 |
| `prefetch_large_stride_scan` | `prefetch_research.bpf.c` | 负向对照 | packet working set large stride but low miss。 |
| `prefetch_permuted_index_scan` | `prefetch_research.bpf.c` | 负向对照 | bounded packet permutation。 |
| `prefetch_packet_offset_guarded` | `prefetch_research.bpf.c` | 安全覆盖 | guarded packet pointer placement。 |
| `prefetch_full_packet_ring_scan` | `prefetch_research.bpf.c` | 负向对照 | packet ring scan in small working set。 |
| `prefetch_indirect_lookup` | `prefetch_research.bpf.c` | 负向对照 | address known too late。 |
| `prefetch_indirect_two_stage` | `prefetch_research.bpf.c` | 负向对照 | dependent-chain skip。 |
| `prefetch_cacheline_dedup_scan` | `prefetch_research.bpf.c` | 安全覆盖 | same-cacheline dedup。 |
| `prefetch_packet_first_deref` | `prefetch_research.bpf.c` | 安全覆盖 | packet first-deref selector。 |
| `prefetch_single_first_deref` | `prefetch_research.bpf.c` | 安全覆盖 | minimal packet first-deref selector。 |
| `prefetch_first_deref_page_stride` | `prefetch_upper_bound.bpf.c` | 诊断 | map-backed high-miss first-deref-like shape；AWS ARM64 PMU attribution 已完成，profile-fed treatment 插入 1 个 `prfm`，T/C `1.000208`，miss_count_ratio `0.999198`。当前 placement 已拒绝。 |
| `prefetch_map_indirect_page` | `prefetch_map_research.bpf.c` | 负向对照 | map indirect page / dependent address。 |
| `prefetch_map_line_dedup` | `prefetch_map_research.bpf.c` | 安全覆盖 | map cacheline dedup。 |

### 性能归因 / 诊断

这些用例的目标是制造更高 memory pressure、明确 future address 或 policy-specific shape，并结合 PMU
判断策略是否有效。

| benchmark | source file | 用例类型 | 测什么 | 当前结论 |
|---|---|---|---|---|
| `prefetch_map_page_stride` | `prefetch_map_research.bpf.c` | 诊断 | map-value same-iteration。 | miss 小降，timing neutral。 |
| `prefetch_upper_page_stride` | `prefetch_upper_bound.bpf.c` | 负向对照 / 诊断 | high-miss same-iteration upper bound。 | high miss 但 neutral，证明提前量不够。 |
| `prefetch_pipeline_page_stride` | `prefetch_upper_bound.bpf.c` | 性能归因 | next-iteration future pointer。 | positive。 |
| `prefetch_pipeline_horizon1_page_stride` | `prefetch_upper_bound.bpf.c` | 性能归因 | horizon 1。 | positive but weaker。 |
| `prefetch_pipeline_horizon2_page_stride` | `prefetch_upper_bound.bpf.c` | 性能归因 | horizon 2。 | positive，当前 strong candidate。 |
| `prefetch_pipeline_horizon4_page_stride` | `prefetch_upper_bound.bpf.c` | 性能归因 | horizon 4。 | positive but weaker than horizon2。 |
| `prefetch_pipeline_degree_page_stride` | `prefetch_upper_bound.bpf.c` | 性能归因 / 诊断 | multi-site degree under pipeline。 | positive with instruction overhead。 |
| `prefetch_stride64_page_stride` | `prefetch_upper_bound.bpf.c` | 诊断 | 64B stride-class。 | timing neutral。 |
| `prefetch_stride256_page_stride` | `prefetch_upper_bound.bpf.c` | 诊断 | 256B stride-class。 | timing neutral。 |
| `prefetch_stride4096_page_stride` | `prefetch_upper_bound.bpf.c` | 诊断 | 4096B stride-class。 | timing neutral。 |
| `prefetch_variable_stride_page_stride` | `prefetch_upper_bound.bpf.c` | 诊断 | variable stride。 | miss drops, timing weak。 |
| `prefetch_spatial_page_footprint` | `prefetch_upper_bound.bpf.c` | 性能归因 | spatial within page。 | positive with instruction overhead。 |
| `prefetch_struct_field_fixed_offsets` | `prefetch_upper_bound.bpf.c` | 性能归因 | fixed-offset struct fields。 | weak positive。 |
| `prefetch_mlop_index_field` | `prefetch_upper_bound.bpf.c` | 性能归因 | MLOP / index-field future pointer。 | strongest positive。 |
| `prefetch_degree123_page_stride` | `prefetch_upper_bound.bpf.c` | 性能归因 | normalized degree 1/2/3。 | degree1 best。 |
| `prefetch_mixed_policy_table` | `prefetch_upper_bound.bpf.c` | schema + 性能归因 | per-PC prefetch / skip table。 | 弱正向，验证 schema。 |
| `prefetch_stream_of_strides` | `prefetch_upper_bound.bpf.c` | 诊断 | two interleaved streams。 | current implementation slow; needs redesign if continued。 |
| `prefetch_stream_of_strides_high_miss` | `prefetch_upper_bound.bpf.c` | 诊断 | two page-spread future streams with `i+4` horizon。 | AWS ARM64 paired attribution 曾显示 profile-fed treatment 插入 2 个 `prfm`，T/C `0.918211`；后续 `c7g.medium` PMU rerun 显示 cache misses 下降但 exec/cycles 不赢，因此当前 placement 不是 positive candidate。 |

## 负向对照为什么存在

负向对照用例不是“坏用例”。它们回答的问题不同：

```text
在这个访问形态下，prefetch 是否应该明确不插？
```

例如 hot L1 load、sequential scan、dependent-chain 和 no-lead-time same-iteration 都是应该 skip 的形态。
如果没有负向对照，selector 很容易把“verifier-safe candidate”误当成“profitable candidate”，导致
默认策略过度插入 hint。

这些用例不能简单“改造成可加速用例”。一旦把 hot load 改成 high-miss future pointer，它就不再测试
hot-load skip；一旦把 same-iteration 改成 next-iteration，它就不再测试 no-lead-time skip。因此同一个
policy family 应同时有：

1. 负向对照：证明不该插的形态会被跳过；
2. 性能归因：证明该插的形态确实能快；
3. 诊断：解释慢是因为 low miss、无提前量、degree 过大、hint 选择不合适，还是 instruction overhead。

## 当前 coverage 缺口

现有 prefetch performance coverage 仍不完整：

| policy area | 当前问题 | 应补什么 |
|---|---|---|
| packet structural | 多数是 low-miss packet 负向对照。 | 如果要继续研究 packet prefetch，需要 real-inspired high-miss packet-like working set 或真实 packet corpus evidence。 |
| packet first-deref | 已新增 `prefetch_first_deref_page_stride` 并完成 AWS paired attribution 和 PMU attribution。 | 结果显示当前 first-deref placement 不降低 miss，不能作为 positive candidate；如果继续研究，需要重新设计 placement 或用真实 packet/corpus case。 |
| fixed-distance same-iteration | 主要是 low-miss/no-lead negative evidence。 | 若继续研究，需要 high-miss case；但 upper-bound 已显示 same-iteration 即使 high miss 也弱，因此优先级低。 |
| stream-of-strides | 旧 `prefetch_stream_of_strides` 已证明 two-stream placement 明显变慢；新增 high-miss case 已完成 AWS paired attribution 和 `c7g.medium` PMU rerun。 | high-miss degree1 single-site 有弱正向；degree2 two-site cache misses 下降但 exec/cycles 不赢。当前缺口不是 PMU，而是如果继续 degree>1，需要重设 stream scheduling / placement。 |
| hint variant | 只在部分 horizon/degree candidate 上测过。 | 对最终候选 policy 做完整 `policy x hint` matrix。 |
| workload-shaped original suite | 没有系统测 integrated selector regression。 | selector 接入后必须在 29 个原有 workload-shaped micro 上跑 regression。 |

因此当前正确表述是：

```text
已有 micro 足够证明：profile-fed future-address 类 prefetch 在若干 synthetic-control case 上有 PMU-backed
positive evidence；同时也证明了 naive same-iteration、default packet structural 和 plain stride 不应默认启用。
但 micro suite 还没有完整证明一个 production-ready integrated prefetcher。
```
