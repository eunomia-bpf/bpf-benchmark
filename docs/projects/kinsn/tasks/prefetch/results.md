# Kinsn Prefetch Experiments

最后更新：2026-06-02。

## 结论

已有实验回答了两个问题：

1. `PREFETCHT0` / `PRFM` 的 Kinsn 通路是否能工作：能。
2. 是否已经找到可默认启用的 prefetch 策略：没有。

当前最有希望的是 `prefetch_pipeline_page_stride` 对应的 next-iteration prefetch。它在 ARM64 上
两轮都显示 treatment 更快，但幅度不稳定，因此仍是 research-only candidate。

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

当前 prefetch micro 都是 `synthetic-control`。也就是说，它们不是从真实 BPF 程序自动提取的，
而是为了测试一个明确策略而手写：

| program file | 主要 case | 测什么 |
|---|---|---|
| `prefetch_research.bpf.c` | distance、packet filtering、indirect、guarded offset | packet-side strategy probes。 |
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
| `prefetch_pipeline_page_stride` | `prefetch_upper_bound.bpf.c` | yes | map, 1 MiB | next-iteration / software-pipeline probe：当前轮读 `cur`，提前对下一轮 `next` pointer 发 prefetch。当前最有希望，但 effect size 不稳定。 |

## 策略实现和对应实验

| strategy | pass 怎么识别 / 插入 | 对应 micro | 实验目的 |
|---|---|---|---|
| fixed-distance prefetch | 找到 load candidate 后，在 target load 前最多 16 个 BPF slot 内选接近 8 slot 的插入点。 | `prefetch_distance_0/2/4/8/16/32` | 判断“当前 load 前固定距离插 hint”是否有效。 |
| packet first-deref | 追踪 packet data pointer，识别 `packet load -> scalar index -> final packet deref`，只允许 depth 1 final deref。 | `prefetch_packet_first_deref`, `prefetch_single_first_deref` | 判断 data-dependent packet deref 是否值得 prefetch。 |
| hot/sequential skip | 构造 hot L1 和 sequential scan pattern，观察 structural prefetch 是否会误判。 | `prefetch_hot_l1_load`, `prefetch_sequential_scan` | 判断哪些 shape 应默认 skip。 |
| indirect skip | 构造地址依赖前一次 load 的 two-stage chain。 | `prefetch_indirect_lookup`, `prefetch_indirect_two_stage` | 判断 dependent chain 是否没有足够 lead time。 |
| cacheline dedup | 同一 pointer/cacheline 多次 load，只保留一个 candidate。 | `prefetch_cacheline_dedup_scan`, `prefetch_map_line_dedup` | 避免重复 prefetch 同一 cacheline。 |
| map-value profile gate | 追踪 map lookup 返回的 `r0`，但只有 profile 指定 PC 时才插。 | `prefetch_map_page_stride` | 避免 structural-only map prefetch。 |
| same-iteration upper bound | map value 1 MiB、page stride、load 前 independent work。 | `prefetch_upper_page_stride` | 测试更适合 prefetch 的 same-iteration case 是否稳定变快。 |
| next-iteration prefetch | profile 指定 PC 和 register，此处 register 已保存下一轮 pointer。 | `prefetch_pipeline_page_stride` | 测试 software-pipeline 形态是否比 same-iteration 更有效。 |

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

## 提交的实验 artifact

本 task 不只提交摘要。repo 内提交了每个关键实验的小型可复查 artifact：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments
```

该目录包含 20 个实验、144 个文件、约 1.2 MiB。每个实验子目录包含：

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
```
