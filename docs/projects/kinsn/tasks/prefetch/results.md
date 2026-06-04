# Kinsn Prefetch Experiments

最后更新：2026-06-04。

## 结论

已有实验回答了两个问题：

1. `PREFETCHT0` / `PRFM` 的 Kinsn 通路是否能工作：能。
2. 是否已经找到可默认启用的 prefetch 策略：没有。

当前最有希望的是 profile-fed future-address prefetch。它不是预取当前 load，而是在第 `i` 轮提前
预取后续轮次或后续 region 会用到的 map-value pointer。2026-06-03 的 AWS `c7g.large`
PMU-capable run 已经补齐 `cycles/instructions/cache_references/cache_misses` 证据：

- `prefetch_mlop_index_field`：T/C `0.945284`，cache miss ratio `0.019193`。
- `prefetch_degree123_page_stride` degree1：T/C `0.958149`，cache miss ratio `0.006768`。
- `prefetch_pipeline_horizon2_page_stride`：T/C `0.961195`，cache miss ratio `0.009627`。
- `prefetch_pipeline_page_stride`：T/C `0.968297`，cache miss ratio `0.006868`。
- `prefetch_spatial_page_footprint`：T/C `0.971461`，cache miss ratio `0.000460`。

这比旧的 same-iteration upper-bound case 更有说服力，并且第一次有 ARM64 cache-miss PMU
证据。限制仍然明确：这些都是 hand-profiled synthetic-control cases，还不是 real-derived/corpus
coverage，也不是 automatic selector，所以仍是 research-only / profile-gated candidate。

2026-06-02 又补齐了 prefetch hint variant ABI 和 smoke：

- x86 已支持 `prefetchnta`、`prefetcht0`、`prefetcht1`、`prefetcht2`。
- ARM64 已支持 `prfm pldl1keep`、`prfm pldl1strm`、`prfm pldl2keep`、`prfm pldl2strm`。
- AWS kernel micro JIT dump 已确认 `--hint t1`、`--hint nta`、`--hint pldl2keep`、
  `--hint pldl1strm` 都能发出对应 native hint。

随后完成的 paired sweep 显示：ARM64 L1 hints 明显优于 L2 hints；x86 `nta` 在这些 cases
上明显变慢；true degree 没有超过单个 horizon2/horizon4。

2026-06-03 先补齐了 PF-LLM-inspired micro case coverage，再完成 ARM64 paired attribution。
这把 policy sweep 从“只测 horizon / degree / hint”扩展到“按 access pattern 分类”：

- `prefetch_upper_bound.bpf.o` 和 native object build 通过。
- 新增 stride-class、spatial-within-page、fixed-offset struct-field、multi-level offset、
  normalized degree 和 per-PC mixed policy-table cases。
- x86 / ARM64 control smoke 各跑 9 个新增 cases，全部 `result == expected`。
- ARM64 `prefetch_stride64_page_stride` treatment 在 selector fix 后 `sites_applied=1`；
  JIT dump 确认 `prfm pldl1keep, [x20]`。
- 随后用 `SAMPLES=5 WARMUPS=1 INNER_REPEAT=10000` 跑 ARM64 paired attribution。
- `spatial-within-page` 是本轮最强 signal，T/C `0.928342`，约快 `7.166%`。
- `MLOP/index-field` T/C `0.962787`，约快 `3.721%`。
- `degree1/2/3` 都是弱 signal，且 degree 越大没有越好。
- `stride64/stride256` 是 noise-level，不支持作为独立收益证据。
- `struct-field fixed offsets` 和 `mixed policy table` 当时仍未完成 treatment。2026-06-04 已补
  x86 treatment smoke：struct-field applied 3，mixed-policy applied 1。
- 2026-06-04 又补齐 `struct-field`、`mixed-policy-table`、`stream-of-strides` 的 ARM64 smoke
  和 paired attribution：struct-field T/C `0.959350`，mixed-policy T/C `0.990555`，
  stream-of-strides T/C `1.553949`。
- 又在 `c7g.large` 上重跑已实现且有 profile 的 ARM64 policy/case，确认 positive cases 伴随
  `cache_misses` 显著下降；default structural、plain stride、same-iteration map/upper-bound
  没有足够 PMU 证据支持继续作为 candidate。

## 实验怎么跑

所有 benchmark 都通过 Makefile / AWS wrapper 路径运行。原始记录在：

```text
/home/ruoji/github/bpf-opt/experiments
```

基本流程：

```text
1. 构造一个 micro benchmark，控制某种 BPF memory access pattern。
2. control：不应用 prefetch pass。
3. treatment：应用 bpfopt --pass prefetch，必要时传入 profile JSON。
4. kernel runtime 把 BPF program 加载到目标架构 AWS instance。
5. runner 执行 BPF_PROG_TEST_RUN，并保存 raw measurements。
6. analysis-side 计算 treatment/control ratio。
```

常用命令形态：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  BENCH=prefetch_pipeline_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=1000
```

treatment 增加：

```bash
BPFREJIT_BENCH_PASSES=prefetch
BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-page-stride-profile-pc45-r1.json'
```

指标解释：

| column / metric | 含义 |
|---|---|
| `sites_matched` | `bpfopt` 找到的候选 prefetch site 数量。 |
| `sites_applied` | 实际插入 prefetch kinsn 的 site 数量。 |
| `insn_delta` | treatment BPF instruction 数量相对 control 的变化。 |
| `exec_ns` | kernel test-run 口径下的 execution time。 |
| `wall_exec_ns` / `exec_cycles` | x86 部分实验能采到的 wall/cycle timing。 |
| treatment/control | ratio；小于 `1` 表示 treatment 更快。 |

## Micro benchmark 是什么

`micro` 是 isolated pure-JIT benchmark，用来隔离某种 BPF code shape 的 JIT/codegen/runtime 效果。
它不是 corpus，也不是真实 app benchmark。

每类 testcase 的构造原则、access shape、control/treatment 区别和局限写在：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-design.md
```

当前 prefetch micro 都是 `synthetic-control`。也就是说，它们不是从真实 BPF 程序自动提取的，
而是为了测试一个明确策略而手写：

| program file | 主要 case | 测什么 |
|---|---|---|
| `prefetch_research.bpf.c` | distance、packet filtering、indirect、guarded offset | packet-side policy probes。 |
| `prefetch_map_research.bpf.c` | map page stride、map indirect、map line dedup | map-backed working set。 |
| `prefetch_upper_bound.bpf.c` | upper-bound same-iteration、next-iteration pipeline | 更偏向 prefetch 的 best-case probes。 |

每个 case 都在 `micro_pure_jit.yaml` 里注册，有 deterministic input generator 和 expected result。

### Micro case catalog

repo 原有 micro suite 没有 prefetch-specific policy probe。下面这些 prefetch micro case 都是本
task 新增的 `synthetic-control` case；它们用于隔离策略行为，不是 real-derived workload 证据。

| case | program file | 本 task 新增 | IO mode | 访问形态 / 测试问题 |
|---|---|---|---|---|
| `prefetch_distance_0` | `prefetch_research.bpf.c` | yes | staged packet | target load 前没有明显 independent work；作为 no-lead-time control。理论上不应该稳定变快。 |
| `prefetch_distance_2` | `prefetch_research.bpf.c` | yes | staged packet | target load 前约 2 个 BPF slot 的 gap；测试非常短 lead time 是否足够。 |
| `prefetch_distance_4` | `prefetch_research.bpf.c` | yes | staged packet | target load 前约 4 个 BPF slot 的 gap；测试短 lead time。 |
| `prefetch_distance_8` | `prefetch_research.bpf.c` | yes | staged packet | target load 前约 8 个 BPF slot 的 gap；对应当前 fixed-distance selector 的目标距离。 |
| `prefetch_distance_16` | `prefetch_research.bpf.c` | yes | staged packet | target load 前约 16 个 BPF slot 的 gap；测试更长 but still local 的 lead time。 |
| `prefetch_distance_32` | `prefetch_research.bpf.c` | yes | staged packet | target load 前有更长 independent work，但当前 selector 最大窗口是 16 BPF slot；用于观察 window 限制。 |
| `prefetch_hot_l1_load` | `prefetch_research.bpf.c` | yes | staged packet | 反复读 hot packet offset；理论上数据大概率已在 L1，应作为 skip/control，而不是收益证据。 |
| `prefetch_sequential_scan` | `prefetch_research.bpf.c` | yes | staged packet | 顺序扫描 packet；硬件 prefetcher 可能已经覆盖，软件 hint 可能只是额外成本。 |
| `prefetch_large_stride_scan` | `prefetch_research.bpf.c` | yes | staged packet | packet 内跨 cacheline/large-stride 访问；测试较稀疏 packet access 是否有收益。packet working set 仍小。 |
| `prefetch_permuted_index_scan` | `prefetch_research.bpf.c` | yes | staged packet | bounded permutation index；测试 irregular-but-verifier-safe packet access。已有结果不支持默认启用。 |
| `prefetch_packet_first_deref` | `prefetch_research.bpf.c` | yes | staged packet | `packet load -> scalar index -> final packet deref`；selector v3 只允许 final deref 这类 depth-1 candidate。 |
| `prefetch_single_first_deref` | `prefetch_research.bpf.c` | yes | staged packet | 最小化的 packet first-deref coverage case；主要验证 selector 命中 final deref，不作为真实 workload 收益证据。 |
| `prefetch_indirect_lookup` | `prefetch_research.bpf.c` | yes | staged packet | 后续地址依赖先前 load 的值；测试 dependent address chain 是否太晚。当前应默认 skip。 |
| `prefetch_indirect_two_stage` | `prefetch_research.bpf.c` | yes | staged packet | 两级 dependent load chain；测试 depth > 1 的 indirect case。当前应默认 skip。 |
| `prefetch_cacheline_dedup_scan` | `prefetch_research.bpf.c` | yes | staged packet | 同一 cacheline 内多个 load；测试 same-cacheline dedup，避免重复 prefetch。 |
| `prefetch_packet_offset_guarded` | `prefetch_research.bpf.c` | yes | staged packet | variable offset 已经 bounds-guarded；测试 verifier-safe 不等于 profitable。 |
| `prefetch_full_packet_ring_scan` | `prefetch_research.bpf.c` | yes | staged packet | 在 1400-byte packet 内做 ring scan；测试较大 packet scan，但 working set 仍远小于 map case。 |
| `prefetch_map_page_stride` | `prefetch_map_research.bpf.c` | yes | map, 256 KiB | map value page-spread access；测试大 working set 下 map-value prefetch。默认 skipped，需要 profile gate 才应用。 |
| `prefetch_map_indirect_page` | `prefetch_map_research.bpf.c` | yes | map, 256 KiB | map-backed indirect page access；测试 indirect map address 是否有足够 timeliness。已有结果偏慢。 |
| `prefetch_map_line_dedup` | `prefetch_map_research.bpf.c` | yes | map, 256 KiB | map working set 中同 cacheline 多个 load；测试 dedup 在 map case 上是否有效。 |
| `prefetch_upper_page_stride` | `prefetch_upper_bound.bpf.c` | yes | map, 1 MiB | same-iteration upper-bound probe：1 MiB map、page stride、demand load 前 independent ALU work。用于检查旧 case 是否不够敏感；结果仍不稳定。 |
| `prefetch_pipeline_page_stride` | `prefetch_upper_bound.bpf.c` | yes | map, 1 MiB | next-iteration / software-pipeline probe：当前轮读 `cur`，提前对下一轮 `next` pointer 发 prefetch。当前最有希望；ARM64 三轮 positive，但仍缺少 PMU 归因。 |
| `prefetch_pipeline_horizon1_page_stride` | `prefetch_upper_bound.bpf.c` | yes | map, 1 MiB | 第 `i` 轮预取 `i+1` future pointer；测试最短 future-address horizon。 |
| `prefetch_pipeline_horizon2_page_stride` | `prefetch_upper_bound.bpf.c` | yes | map, 1 MiB | 第 `i` 轮预取 `i+2` future pointer；本轮 ARM64 L1 hint 最稳定。 |
| `prefetch_pipeline_horizon4_page_stride` | `prefetch_upper_bound.bpf.c` | yes | map, 1 MiB | 第 `i` 轮预取 `i+4` future pointer；测试更长 lead time。 |
| `prefetch_pipeline_degree_page_stride` | `prefetch_upper_bound.bpf.c` | yes | map, 1 MiB | 同一轮同时预取 `i+1/i+2/i+4` 三个 future pointers；测试 true degree 是否优于 single horizon。 |
| `prefetch_stride64_page_stride` | `prefetch_upper_bound.bpf.c` | yes, 2026-06-03 | map, 1 MiB | PF-LLM-inspired stride-class case：64-byte stride，每轮保留 `i+2` future pointer；测试 line-stride policy。 |
| `prefetch_stride256_page_stride` | `prefetch_upper_bound.bpf.c` | yes, 2026-06-03 | map, 1 MiB | PF-LLM-inspired stride-class case：256-byte stride，每轮保留 `i+2` future pointer；测试 larger line-stride policy。 |
| `prefetch_stride4096_page_stride` | `prefetch_upper_bound.bpf.c` | yes, 2026-06-03 | map, 1 MiB | PF-LLM-inspired page-stride case：4 KiB stride；测试 page-distance lead time 和 TLB/cache interaction。 |
| `prefetch_variable_stride_page_stride` | `prefetch_upper_bound.bpf.c` | yes, 2026-06-03 | map, 1 MiB | PF-LLM-inspired variable-stride case：stride 在 64/128/256/512 bytes 间变化；测试单 stream 内 stride class 变化。 |
| `prefetch_spatial_page_footprint` | `prefetch_upper_bound.bpf.c` | yes, 2026-06-03 | map, 1 MiB | PF-LLM-inspired spatial-within-page case：每轮读同一 page 内 0/128/256 三个 offset；测试 region footprint policy。 |
| `prefetch_struct_field_fixed_offsets` | `prefetch_upper_bound.bpf.c` | yes, 2026-06-03 | map, 1 MiB | PF-LLM-inspired fixed-offset / struct-field case：每轮读同一 record 内 0/64/128 三个 field；2026-06-04 x86 treatment 插入 3 个 `prefetcht0`，ARM64 treatment 插入 3 个 `prfm`，paired T/C `0.959350`。 |
| `prefetch_mlop_index_field` | `prefetch_upper_bound.bpf.c` | yes, 2026-06-03 | map, 1 MiB | PF-LLM-inspired multi-level-offset case：地址由 record index + field offset 组成；测试 MLOP-style future pointer。 |
| `prefetch_degree123_page_stride` | `prefetch_upper_bound.bpf.c` | yes, 2026-06-03 | map, 1 MiB | normalized degree case：同一 stream 保留 `i+2/i+4/i+8` future pointers，用 profile 控制 degree 1/2/3。 |
| `prefetch_mixed_policy_table` | `prefetch_upper_bound.bpf.c` | yes, 2026-06-03 | map, 1 MiB | per-PC policy table / negative filtering stress：同一 program 混合 hot fixed load 和 page-stride load；2026-06-04 profile schema 支持 `prefetch` / `skip` action，x86 treatment 插入 1 个 `prefetcht0`；ARM64 treatment 插入 1 个 `prfm` 并 skip 16 个 site，paired T/C `0.990555`。 |
| `prefetch_stream_of_strides` | `prefetch_upper_bound.bpf.c` | yes, 2026-06-04 | map, 1 MiB | PF-LLM-inspired stream-of-strides case：同一 loop 有两个交错 stream，分别物化 `i+2` future pointer；x86 treatment 插入 2 个 `prefetcht0`；ARM64 treatment 插入 2 个 `prfm`，paired T/C `1.553949`，当前明显变慢。 |

## 策略实现和对应实验

| policy | pass 怎么识别 / 插入 | 对应 micro | 实验目的 |
|---|---|---|---|
| fixed-distance prefetch | 找到 load candidate 后，在 target load 前最多 16 个 BPF slot 内选接近 8 slot 的插入点。 | `prefetch_distance_0/2/4/8/16/32` | 判断“当前 load 前固定距离插 hint”是否有效。 |
| packet first-deref | 追踪 packet data pointer，识别 `packet load -> scalar index -> final packet deref`，只允许 depth 1 final deref。 | `prefetch_packet_first_deref`, `prefetch_single_first_deref` | 判断 data-dependent packet deref 是否值得 prefetch。 |
| hot/sequential skip | 构造 hot L1 和 sequential scan pattern，观察 structural prefetch 是否会误判。 | `prefetch_hot_l1_load`, `prefetch_sequential_scan` | 判断哪些 shape 应默认 skip。 |
| indirect skip | 构造地址依赖前一次 load 的 two-stage chain。 | `prefetch_indirect_lookup`, `prefetch_indirect_two_stage` | 判断 dependent chain 是否没有足够 lead time。 |
| cacheline dedup | 同一 pointer/cacheline 多次 load，只保留一个 candidate。 | `prefetch_cacheline_dedup_scan`, `prefetch_map_line_dedup` | 避免重复 prefetch 同一 cacheline。 |
| map-value profile gate | 追踪 map lookup 返回的 `r0`，但只有 profile 指定 PC 时才插。 | `prefetch_map_page_stride` | 避免 structural-only map prefetch。 |
| same-iteration upper bound | map value 1 MiB、page stride、load 前 independent work。 | `prefetch_upper_page_stride` | 测试更适合 prefetch 的 same-iteration case 是否稳定变快。 |
| next-iteration prefetch | profile 指定 PC 和 register，此处 register 已保存下一轮 pointer。 | `prefetch_pipeline_page_stride` | 测试 software-pipeline 形态是否比 same-iteration 更有效。 |
| hint variant sweep | 同一 future-address profile point 下切换 x86 `t0/t1/t2/nta` 或 ARM64 `l1keep/l1strm/l2keep/l2strm`。 | horizon1/2/4、degree | 判断慢是不是 hint variant 选错。 |
| true degree sweep | 同一 logical case 中显式物化多个 future pointers，并用 profile points 对多个 live registers 发 prefetch。 | `prefetch_pipeline_degree_page_stride` | 判断多个 future-address hints 是否比单个 future-address hint 更有效。 |
| horizon sweep | 分别构造 `i+1/i+2/i+4` future pointer。 | `prefetch_pipeline_horizon1/2/4_page_stride` | 判断 lead time 是否是关键因素。 |
| stride-class selection | 根据 stride class 区分 line stride、larger line stride、page stride 和 variable stride。 | `prefetch_stride64/256/4096/variable_stride_page_stride` | 判断 policy 是否必须按 access shape 分开，而不是统一 horizon/hint。 |
| spatial-within-page policy | 对同一 future page 内多个 offset 保留多个 future pointer。 | `prefetch_spatial_page_footprint` | 判断 region footprint 是否比单 future pointer 更适合部分 workload。 |
| fixed-offset struct-field policy | 对 record / struct 内固定 offset field 建模。 | `prefetch_struct_field_fixed_offsets` | 判断 Sandbox-style fixed-offset pattern 是否值得做 profile-gated prefetch。 |
| multi-level offset policy | 把地址拆成 base + record index + field offset。 | `prefetch_mlop_index_field` | 判断 MLOP-style address shape 是否能被 Kinsn future-address policy 覆盖。 |
| normalized degree sweep | 在同一 case 中保留 `i+2/i+4/i+8` future pointers，用 profile 控制 degree 1/2/3。 | `prefetch_degree123_page_stride` | 判断 conservative / moderate / aggressive degree 是否存在不同最优点。 |
| per-PC policy-table stress | 同一 program 混合应该 skip 的 hot load 和可能值得 prefetch 的 page-stride load。 | `prefetch_mixed_policy_table` | 判断 per-PC policy table 是否必要，以及 negative filtering 是否能保护性能。 |

## 实验清单和结果

| date | experiment | 做法 | 结果 |
|---|---|---|---|
| 2026-05-26 | `arm64-prfm-prefetch-coverage-attribution` | 在 AWS ARM64 corpus targeted run 上对 Katran `balancer_ingres` 应用 `bpfopt --pass prefetch`。 | 命中 44 个 PRFM site，ReJIT 正确；单样本性能不是 win。 |
| 2026-05-31 | `prefetch-research-micro-smoke` | 新增第一组 distance / indirect packet micro，只做本地 object/native build smoke。 | benchmark 能编译；无性能结论。 |
| 2026-05-31 | `prefetch-research-micro-attribution` | AWS ARM64 kernel runtime，跑 distance sweep control/treatment。 | geomean T/C `1.004928`，约慢 `0.49%`；无稳定收益。 |
| 2026-05-31 | `prefetch-candidate-filtering-micro-attribution` | AWS ARM64，跑 hot、sequential、large-stride、permuted、packet-first-deref。 | `exec_ns` 有弱信号，但 wall time 反向；不能 default-enable。 |
| 2026-06-01 | `prefetch-indirect-timeliness-micro-attribution` | AWS ARM64，跑 two-stage indirect、cacheline dedup、guarded offset、ring scan。 | geomean `1.00367168`，约慢 `0.37%`。 |
| 2026-06-01 | `x86-prefetch-current-policy-micro-attribution` | AWS x86，试图跑完整 prefetch micro。 | 发现 runner path 没有真正应用 pass；本实验不能作为性能结论。 |
| 2026-06-01 | `prefetch-micro-kernel-pass-path-fix` | 修复 micro kernel runtime，让它先跑 `bpfopt` 再加载 raw BPF。 | pass path 接通。 |
| 2026-06-01 | `prefetch-policy-stack-alias-fix` | 修复 stack spill/reload alias 和 register-offset pointer tracking。 | x86 AWS kernel runtime 对 packet/map 代表 case 都 applied 1。 |
| 2026-06-01 | `prefetch-map-large-working-set-attribution` | 新增 map-backed 256 KiB working-set case。 | treatment 因 raw loader map relocation 不支持而失败；后续已修复。 |
| 2026-06-01 | `prefetch-map-raw-loader-fix` | 修复 raw-kinsn loader 的 BTF `.maps` 和 map relocation。 | loader 修复；3 个 map case geomean `1.001694`，约慢 `0.17%`。 |
| 2026-06-01 | `prefetch-selector-v3-policy-smoke` | x86/ARM64 smoke，验证 v3 admission。 | packet first-deref applied 1；无 profile 的 map-value skipped。 |
| 2026-06-01 | `prefetch-packet-first-deref-v3-attribution` | x86/ARM64 same-LLC attribution，测 v3 packet first-deref。 | correctness/codegen 通过；performance mixed。 |
| 2026-06-01 | `prefetch-profile-gate-impl` | 实现 profile allow-list / PMU-style metrics parser，并跑 Rust tests。 | `13 passed`；admission gate 正确。 |
| 2026-06-01 | `prefetch-x86-paired-attribution` | AWS x86，测 packet first-deref 和 map page stride。 | `map_page_stride` 有 weak signal，但 timing source 不一致。 |
| 2026-06-01 | `prefetch-x86-map-page-stride-independent-rerun` | AWS x86 独立 rerun map page stride。 | `exec_ns` geomean `1.0268` slower；wall/cycles geomean `0.9239` faster；计时源冲突。 |
| 2026-06-02 | `prefetch-profile-fed-map-value-attribution` | x86/ARM64，profile 指定 map-value PC 后应用 prefetch。 | x86 `exec_mean` T/C `0.897679` 但 wall 不支持；ARM64 mean T/C `0.966154`。 |
| 2026-06-02 | `prefetch-profile-fed-map-value-pmu-attribution` | 检查 AWS micro 是否能采集 PMU cache counters。 | x86 没有硬件 PMU counters；ARM64 只有 `cycles`。PMU attribution blocked。 |
| 2026-06-02 | `prefetch-upper-bound-map-attribution` | 新增 1 MiB map value、page stride、same-iteration upper-bound case。 | x86 T/C `0.998018` noise-level；ARM64 `1.007389` slowdown。 |
| 2026-06-02 | `prefetch-pipeline-map-attribution` | 新增 next-iteration case，profile point 指向下一轮 pointer。 | x86 T/C `0.985484` weak；ARM64 T/C `0.858777`，需复核。 |
| 2026-06-02 | `prefetch-pipeline-map-independent-rerun1` | 对同一 P19 case 做独立 AWS rerun。 | ARM64 T/C `0.962181`，方向复现但幅度不稳定；x86 timing 不可信。 |
| 2026-06-02 | `prefetch-pipeline-arm64-long-stability` | ARM64-only long-repeat run，`SAMPLES=10`、`WARMUPS=2`、`INNER_REPEAT=10000`。 | ARM64 paired geomean T/C `0.948348`；方向继续 positive，样本波动降低，但仍缺少 PMU cache-miss attribution。 |
| 2026-06-02 | `prefetch-variant-degree-evidence` | 扩展 x86/ARM64 prefetch hint ABI，先做 native emit smoke，再跑 horizon1/2/4 和 degree paired sweep。 | ARM64 horizon2/horizon4 + L1 hints 有 stable positive signal；x86 `nta` 明显慢；degree 不如 single horizon；当时默认实例缺 cache PMU，后续 c7g 已补。 |
| 2026-06-02 | `prefetch-arm64-horizon-l1-pmu-stability` | ARM64 horizon2/horizon4 + `l1keep` long-repeat run，`SAMPLES=10`、`WARMUPS=2`、`INNER_REPEAT=10000`，并启用 `PERF_COUNTERS=1`。 | horizon2 mean T/C `0.945361`，horizon4 mean T/C `0.971207`；`cycles` 同方向；`cache_misses/cache_references/instructions` 仍不可用。 |
| 2026-06-03 | `prefetch-pf-llm-inspired-micro-smoke` | 新增 PF-LLM-inspired stride/spatial/fixed-offset/MLOP/degree/per-PC mixed micro cases，记录 profile points，跑 x86/ARM64 AWS control smoke，并对 ARM64 stride64 跑 treatment emit smoke。 | build 通过；x86/ARM64 9 个新增 cases control correctness 通过；ARM64 stride64 treatment `sites_applied=1`，JIT dump 有 `prfm pldl1keep`；无 performance 结论。 |
| 2026-06-03 | `prefetch-pf-llm-inspired-arm64-attribution` | ARM64 AWS paired attribution，`SAMPLES=5`、`WARMUPS=1`、`INNER_REPEAT=10000`，对 stride/spatial/MLOP/degree policy cases 跑 control/treatment。 | `spatial` T/C `0.928342`，`MLOP` T/C `0.962787`，`stride4096` T/C `0.988941`，degree 1/2/3 为弱 signal；`stride64/256` noise-level；当时默认实例缺 cache PMU，后续 c7g 已补。 |
| 2026-06-03 | `prefetch-c7g-pmu-policy-diagnosis` | AWS ARM64 `c7g.large`，对 control、default structural 和 16 个 profile-fed treatment 跑 `SAMPLES=3`、`WARMUPS=1`、`INNER_REPEAT=10000`，采集 `cycles/instructions/cache_references/cache_misses`。 | `mlop`、`degree1`、`horizon2`、`pipeline`、`spatial` 有 cache-miss-drop evidence；plain stride / same-iteration / default structural 不支持；使用 `c7g.large` 是 PMU capability exception。 |
| 2026-06-04 | `prefetch-pf-llm-missing-policy-smoke` | 补 `struct-field`、`mixed-policy-table`、`stream-of-strides`。实现 `map_value_policy_points` profile schema，新增 stream-of-strides case/profile，跑 Rust tests、本地 build 和 x86 AWS treatment smoke。 | x86 correctness / emit smoke 通过：struct-field applied 3，mixed-policy applied 1，stream-of-strides applied 2；native JIT dump 有对应 `prefetcht0`。不是性能结论。 |
| 2026-06-04 | `prefetch-pf-llm-missing-policy-arm64-attribution` | 对 `struct-field`、`mixed-policy-table`、`stream-of-strides` 跑 ARM64 smoke 和 paired treatment/control attribution。 | correctness / emit 通过；struct-field T/C `0.959350`，mixed-policy T/C `0.990555`，stream-of-strides T/C `1.553949`。没有 PMU counters，不能解释 cache miss。 |

## 最新 policy-space 结果

hint / degree variant sweep 来自：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-variant-degree-evidence
```

核心指标是 `mean_exec_ns(treatment) / mean_exec_ns(control)`。小于 `1` 表示 treatment 更快。

ARM64：

| case | l1keep | l1strm | l2keep | l2strm | takeaway |
|---|---:|---:|---:|---:|---|
| horizon1 | `1.004758` | `1.046112` | `1.052638` | `1.045345` | 没有收益。 |
| horizon2 | `0.954973` | `0.957488` | `1.003412` | `0.999053` | L1 hints 有稳定收益。 |
| horizon4 | `0.964590` | `0.966710` | `0.986399` | `0.980974` | L1 hints 有稳定收益；L2 只有弱信号。 |
| degree | `0.982073` | `1.001012` | `1.052795` | `1.017365` | true degree 没有超过 horizon2/horizon4。 |

x86：

| case | t0 | t1 | t2 | nta | takeaway |
|---|---:|---:|---:|---:|---|
| horizon1 | `1.001926` | `1.008699` | `0.998209` | `2.944734` | 没有稳定收益；`nta` 明显慢。 |
| horizon2 | `1.000225` | `0.981512` | `1.040229` | `2.393923` | `t1` 有弱信号，但按当前标准仍是 noise。 |
| horizon4 | `0.991978` | `1.003474` | `2.345639` | `1.681460` | 没有稳定收益；`t2/nta` 明显慢。 |
| degree | `1.445870` | `0.996759` | `1.045975` | `1.610153` | degree 没有收益；`nta` 明显慢。 |

PF-LLM-inspired ARM64 paired attribution，非 PMU 版本：

| policy | case | sites applied | treatment/control | takeaway |
|---|---|---:|---:|---|
| stride-64 lookahead | `prefetch_stride64_page_stride` | 1 | `1.004118` | noise-level / slightly slower |
| stride-256 lookahead | `prefetch_stride256_page_stride` | 1 | `0.997847` | noise-level |
| page-stride lookahead | `prefetch_stride4096_page_stride` | 1 | `0.988941` | weak positive |
| variable-stride profile point | `prefetch_variable_stride_page_stride` | 1 | `0.993809` | weak/noise |
| spatial footprint degree=3 | `prefetch_spatial_page_footprint` | 3 | `0.928342` | strongest current PF-LLM-inspired signal |
| MLOP/index-field profile point | `prefetch_mlop_index_field` | 1 | `0.962787` | medium positive |
| degree1 | `prefetch_degree123_page_stride` | 1 | `0.981194` | weak positive |
| degree2 | `prefetch_degree123_page_stride` | 2 | `0.981286` | weak positive, not better than degree1 |
| degree3 | `prefetch_degree123_page_stride` | 3 | `0.985769` | weak positive, worse than degree1/2 |

2026-06-04 补齐的 x86 correctness / emit smoke：

| policy | case | sites applied | BPF bytecode bytes | native bytes | native hint | takeaway |
|---|---|---:|---:|---:|---|---|
| fixed-offset struct-field | `prefetch_struct_field_fixed_offsets` | 3 | 2840 | 1425 | 3 x `prefetcht0` | treatment path 可表达 fixed-field future pointers。 |
| per-PC mixed policy table | `prefetch_mixed_policy_table` | 1 | 2664 | 1314 | 1 x `prefetcht0` | `prefetch` / `skip` schema 可用。 |
| stream-of-strides | `prefetch_stream_of_strides` | 2 | 2680 | 1367 | 2 x `prefetcht0` | two-stream future pointer profile 可用。 |

2026-06-04 补齐的 ARM64 smoke / paired attribution：

| policy | case | ARM64 treatment `prfm` | sites applied / skipped | paired treatment/control | takeaway |
|---|---|---:|---:|---:|---|
| fixed-offset struct-field | `prefetch_struct_field_fixed_offsets` | 3 | 3 / 0 | `0.959350` | 有 positive timing signal；还缺 PMU cache-miss 归因。 |
| per-PC mixed policy table | `prefetch_mixed_policy_table` | 1 | 1 / 16 | `0.990555` | 接近 noise-level；主要证明 per-PC skip schema。 |
| stream-of-strides | `prefetch_stream_of_strides` | 2 | 2 / 16 | `1.553949` | 明显变慢；不进入当前 candidate set。 |

PMU-backed ARM64 attribution，来自：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-03-prefetch-c7g-pmu-policy-diagnosis
```

这些结果使用 `c7g.large`，因为默认 `t4g.small` 缺少 generic cache-miss PMU counters。

| policy / case | treatment/control | cache miss ratio | instruction ratio | takeaway |
|---|---:|---:|---:|---|
| MLOP/index-field | `0.945284` | `0.019193` | `0.957288` | strongest current PMU-backed signal。 |
| normalized degree1 | `0.958149` | `0.006768` | `0.969921` | degree1 比 degree2/3 更好。 |
| horizon2 | `0.961195` | `0.009627` | `0.970903` | horizon2 继续是 strong candidate。 |
| pipeline next-iteration | `0.968297` | `0.006868` | `0.970491` | next-iteration placement 有 PMU 证据。 |
| spatial-within-page | `0.971461` | `0.000460` | `1.037390` | 有 instruction overhead，但 miss drop 足够大。 |
| pipeline degree | `0.969781` | `0.010138` | `1.041210` | 有效但 instruction overhead 高；degree 不是越大越好。 |
| stride64 | `0.998684` | `0.759427` | `1.002690` | cache miss 小降但时间中性。 |
| stride256 | `0.999031` | `0.820329` | `1.002940` | 中性。 |
| stride4096 | `1.000233` | `0.984768` | `1.004340` | 中性，没有 miss benefit。 |
| map same-iteration | `0.994264` | `0.964509` | `1.008210` | 中性，placement 不够。 |
| upper-bound same-iteration | `0.996947` | `0.994163` | `1.000640` | 中性，same-iteration 不支持。 |

## Non-win case 的证据分类

不能把所有 slowdown 都解释成同一个原因。当前证据只能支持下面的分类：

| policy / case | 已排除的原因 | 有证据支持的原因 | 还缺什么证据 |
|---|---|---|---|
| fixed-distance packet prefetch | 不是 kfunc/JIT 通路不工作；前序 codegen evidence 有 native hint。 | `prefetch_distance_*` geomean T/C `1.004928`，c7g default structural 只有 `distance_0/2/4` 这类 control cache misses 为 `0` 的小 case 显示 timing win，不能证明 cache-prefetch 机理。 | 真实 BPF 中是否存在同类 but miss-heavy 的 fixed-distance packet site。 |
| same-iteration map upper-bound | 不是 selector 没触发；`sites_applied=1`。不是 native 没发；JIT dump 有 hint。 | x86 `0.998018` 是 noise-level，ARM64 `1.007389` 是 slowdown；c7g PMU 中 `upper-bound` T/C `0.996947`、cache miss ratio `0.994163`，说明 same-iteration placement 没有实质 miss 改善。 | real-derived case 是否存在不同 placement，但默认 selector 不应按 same-iteration 启用。 |
| indirect / dependent chain | 不是 verifier/correctness failure。 | two-stage indirect 和 map-indirect cases 是 slowdown；地址依赖前一次 load，prefetch 只能在地址物化后发，lead time 不足。这个原因来自 case 的 data-dependency 结构和结果方向。 | 还缺 PMU 或 finer-grained timing 来证明 hint 到达太晚。 |
| profile-fed map-value prefetch | 不是 admission gate 不工作；profile-fed run applied site。 | gate 可控不等于 profitable；c7g PMU 支持 future-address cases，但不支持 same-iteration map/upper-bound。 | 需要 per-PC policy/profile schema，区分 future-address 和 no-prefetch site。 |
| P19 next-iteration ARM64 | 不是单次偶然方向；三轮 ARM64 都是 treatment 更快：`0.858777`、`0.962181`、`0.948348`。 | next-iteration placement 增加 lead time；c7g PMU T/C `0.968297`，cache miss ratio `0.006868`。 | 自动 selector 和 real-derived/corpus coverage，不能直接 default-enable。 |
| hint variants | 已排除 ABI/native emit 不工作；本轮 paired sweep 已完成。 | ARM64 L1 hints 优于 L2 hints；x86 `nta` 在所有新 case 上慢。 | 缺 PMU 解释为什么具体 hint 变慢。 |
| true degree | 已排除“degree 没有真正插入”；degree case 对 `i+1/i+2/i+4` 三个 future pointers 插入 prefetch。 | c7g PMU 中 degree1 T/C `0.958149`，cache miss ratio `0.006768`，degree2/3 更弱；degree 越大不是越好。 | 是否有真实 case 需要 degree > 1。 |
| horizon | 已排除“case 不够偏向 prefetch”；horizon case 是 future-address upper-bound synthetic-control。 | ARM64 horizon2/horizon4 + L1 hints 有 stable positive signal；c7g PMU 中 horizon2 cache miss ratio `0.009627`。说明 lead time 是关键因素。 | 自动 selector 和 real-derived/corpus coverage。 |

## 提交的实验 artifact

本 task 不只提交摘要。repo 内提交了每个关键实验的小型可复查 artifact：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments
```

该目录包含 22 个实验、185 个文件、约 1.6 MiB。每个实验子目录包含：

- `report.md`
- `analysis/*`
- `data/run-contract.json`
- 小型 `data/*.json` / `data/*.tsv`

没有提交完整 AWS stdout/stderr、大 runner result directory、编译产物和调试大文件。原因是这些文件
数量大、可读性低，不适合作为 repo 内文档 artifact。它们仍保存在顶层原始实验目录，按对应
`report.md` 可复查或重新生成。

## 原始数据位置

完整原始报告、AWS logs、runner raw result 和 analysis TSV 保存在：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-prefetch-coverage-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-candidate-filtering-micro-attribution
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-indirect-timeliness-micro-attribution
/home/ruoji/github/bpf-opt/experiments/2026-06-01-x86-prefetch-current-policy-micro-attribution
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-micro-kernel-pass-path-fix
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-policy-stack-alias-fix
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-large-working-set-attribution
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-raw-loader-fix
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-selector-v3-policy-smoke
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-packet-first-deref-v3-attribution
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-profile-gate-impl
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-map-page-stride-independent-rerun
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-pmu-attribution
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-upper-bound-map-attribution
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-attribution
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-independent-rerun1
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-arm64-long-stability
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-variant-degree-evidence
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-arm64-horizon-l1-pmu-stability
/home/ruoji/github/bpf-opt/experiments/2026-06-03-prefetch-pf-llm-inspired-micro-smoke
/home/ruoji/github/bpf-opt/experiments/2026-06-03-prefetch-pf-llm-inspired-arm64-attribution
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-smoke
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution
```
