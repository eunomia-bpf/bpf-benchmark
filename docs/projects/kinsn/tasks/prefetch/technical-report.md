# Kinsn Prefetch 技术报告

最后更新：2026-06-05。

## 结论

`PREFETCH` / `PRFM` 的 Kinsn 通路已经可用：`bpfopt` 能扫描 BPF bytecode，
插入 `KINSN_SIDECAR + KINSN_CALL`，kernel kinsn JIT 能把它翻译成 x86 `prefetch*`
或 ARM64 `prfm`。

但 prefetch 现在不能 default-enable。原因不是 ABI 或 JIT 没打通，而是 prefetch 是插入型优化：
它不会替换原有 load，只是在原有 load 前额外插入 cache hint。只有在下面条件同时成立时，
prefetch 才可能有收益：

```text
1. future address 可以提前知道。
2. prefetch 和 demand load 之间有足够提前量。
3. control case 本来有足够 cache miss。
4. treatment 确实降低 cache miss。
5. 额外 prefetch 指令和 hint 本身的成本没有抵消 miss 下降。
```

当前可保留的 profile-gated 候选策略是：

| 候选策略 | 测试用例 | 当前结果 |
|---|---|---|
| MLOP / index-field | `prefetch_mlop_index_field` | T/C exec `0.945284`，cache miss ratio `0.019193`，当前最强。 |
| horizon2 / future-address | `prefetch_pipeline_horizon2_page_stride` | T/C exec `0.961195`，cache miss ratio `0.009627`。 |
| degree1 | `prefetch_degree123_page_stride` | degree1 T/C exec `0.958149`；degree2/3 不如 degree1。 |
| next-iteration pipeline | `prefetch_pipeline_page_stride` | T/C exec `0.968297`，cache miss ratio `0.006868`。 |
| spatial-within-page | `prefetch_spatial_page_footprint` | T/C exec `0.971461`，cache miss ratio `0.000460`，但有 instruction overhead。 |
| struct-field fixed-offset | `prefetch_struct_field_fixed_offsets` | T/C exec `0.986178`，小幅正向。 |
| mixed-policy-table schema | `prefetch_mixed_policy_table` | T/C exec `0.977369`；主要证明 per-PC prefetch / skip schema。 |
| stream-of-strides degree1 | `prefetch_stream_of_strides_high_miss` + single-site profile | T/C exec `0.990870`，cache miss ratio `0.882631`，cycles T/C `0.981531`。 |

当前明确不应进入 selector 的规则是：same-iteration prefetch、plain structural packet prefetch、
standalone stride-class、x86 `nta` default、stream-of-strides degree2 / two-site placement。

## 1. 背景和目标

Kinsn 的目标是在 BPF 字节码中表达普通 BPF ISA 表达不了的目标架构 native instruction。
普通 BPF JIT 只能把 BPF load / ALU / branch 翻译成目标架构 native 指令；它没有一个通用机制，
让优化器在 BPF program 中插入“这条 ARM64 `prfm` 或 x86 `prefetcht0`”。

Kinsn 提供这个机制：`bpfopt` 在 BPF bytecode 中插入一个 sidecar payload 和一个 kfunc call，
kernel JIT 看到这个 kfunc 后，不把它当普通 helper call 执行，而是根据 sidecar payload
发出目标架构 native instruction。

Prefetch task 的研究问题是：

```text
RQ1. Kinsn 能不能表达 x86 / ARM64 software prefetch hint？
RQ2. 哪些 BPF memory access pattern 值得插 prefetch？
RQ3. 如何用 microbenchmark 证明某个 policy 有效或无效？
RQ4. 如果有效，后续如何设计 profile-gated / evidence-backed prefetcher？
```

## 2. Prefetch 在 Kinsn 中怎么运行

当前 pipeline 是：

```text
BPF C program
  -> clang/LLVM 编译成 BPF object
  -> bpfopt --pass prefetch 扫描 BPF bytecode
  -> 根据 policy / profile 判断是否插入 prefetch
  -> 插入 KINSN_SIDECAR + KINSN_CALL
  -> kernel 加载 BPF program
  -> kinsn JIT 读取 sidecar payload
  -> 生成 x86 prefetch* 或 ARM64 prfm native hint
  -> BPF_PROG_TEST_RUN / corpus runner 执行优化后的 program
```

当前支持的 native hint：

| arch | supported hints |
|---|---|
| x86 | `prefetchnta`、`prefetcht0`、`prefetcht1`、`prefetcht2` |
| ARM64 | `prfm pldl1keep`、`prfm pldl1strm`、`prfm pldl2keep`、`prfm pldl2strm` |

关键区别：其他 kinsn family 通常是替换型优化，例如把多条 BPF ALU sequence 替换成一个 native
`rev` / `extr`。Prefetch 是插入型优化。原始 demand load 仍然存在，prefetch 只是额外提示 CPU
提前把某个 cache line 拉近。因此，prefetch 是否有收益主要取决于 timing、cache miss 和硬件行为，
而不是语义等价性本身。

## 3. 预取策略分类

预取策略是访问模式上的决策规则。它必须回答：

```text
在什么 BPF memory access pattern 下，对哪个地址插 prefetch，哪些情况明确不插？
```

`horizon`、`degree`、`hint variant` 不是策略。它们是参数，只有绑定到某个策略之后才有意义。

### 3.1 当前策略

这张表里的“会加速的代码形态”是策略定义的核心。一个 prefetch 策略只有在能说明：

```text
代码里出现什么访问 pattern，
为什么这个 pattern 不预取会慢，
以及 prefetch 怎么提前隐藏这类 miss
```

时，才算是有清楚的策略定义。

| 策略 | 会加速的代码形态 | 不预取为什么慢 | 当前实现 / 测试方式 | 当前状态 |
|---|---|---|---|---|
| same-iteration current-address prefetch | 当前没有成立的正向形态。它只适用于“地址刚算出来，马上就要 load”的当前轮访问。 | 这种形态即使本身 high-miss，prefetch 距离 demand load 太近，CPU 没时间把 cache line 拉进来；不预取慢是因为 miss，但当前 prefetch 也隐藏不了 miss。 | 对当前 demand load 前的 live address 插 hint。 | 拒绝；没有足够提前量。 |
| packet structural prefetch | 当前没有成立的默认正向形态。单纯“这是 packet pointer deref”不足以说明会加速。 | packet working set 通常小、热、顺序或已被 bounds-check/访问局部性覆盖；不预取未必慢，盲插 prefetch 反而增加 hint 成本。 | 扫描 packet-derived pointer load。 | 拒绝默认启用；只保留跳过规则经验。 |
| packet first-deref prefetch | 理论上需要出现“先从 packet 读出 index / offset，再访问一个高 miss target，并且 target address 能提前物化”的形态。 | 不预取会慢的前提是 final target 分散且 miss 高；但当前用例里 prefetch site 到实际 demand load 的提前量不足，miss 基本不降。 | 只允许 depth-1 final deref 作为候选。 | 当前 placement 已用 PMU 验证，不成立。 |
| map-value same-iteration prefetch | 当前没有成立的正向形态。它只是在当前轮 map-value load 前插当前地址。 | map value 可以 high-miss，但当前轮地址预取仍太晚；不预取慢来自 miss，当前 prefetch 隐藏不了这次 miss。 | 追踪 `bpf_map_lookup_elem` 返回的 map value pointer。 | 拒绝默认启用。 |
| future-address single-stream prefetch | loop 第 `i` 轮已经能算出第 `i+1` / `i+2` 轮会访问的 map-value 地址，并且访问分散到多个 cache line / page。 | 不预取时，每轮 demand load 都可能在高 miss working set 上停住；提前预取 future address 可以把下一轮 miss 藏在当前轮计算中。 | profile 指定 future pointer register；在当前轮插 hint。 | 候选策略。 |
| stride-only future-address prefetch | 只有在 stride 访问同时满足 high-miss、future address 已提前物化、有足够提前量时才可能加速；单看 stride class 不够。 | 不预取慢的原因必须是 stride stream 造成真实 miss；如果硬件 prefetch 已覆盖、miss 低或提前量不足，软件 prefetch 没用。 | 构造 64B / 256B / 4096B / variable stride streams。 | 拒绝 standalone 策略。 |
| spatial-within-page prefetch | 已知未来会访问同一 page / region 内多个 offset，例如 future record/page 的多个字段。 | 不预取时，多处 offset 访问会反复触发 cache miss；提前预取 future page/offsets 可以降低这些 demand load 的 miss。 | 预取 future page 内多个 offsets。 | 候选策略，必须 profile-gated。 |
| MLOP / index-field prefetch | 地址形如 `base + index + field offset`，且 future index / field address 能提前算出；典型是 indexed record/table field。 | 不预取时，indexed field load 分散且 miss 高；提前预取 future field address 可以把随机/半随机 field miss 隐藏掉。 | 预取 future index 对应的 field address。 | 当前最强候选。 |
| struct-field fixed-offset prefetch | 程序按 record 扫描固定字段，且能提前算出 future record 的 fixed field addresses。 | 不预取时，future record 的固定字段可能落在冷 cache line 上；提前预取 future fields 可以降低后续 field load miss。 | 预取 future record 的 fixed fields。 | 弱候选。 |
| mixed per-PC policy table | 同一个 BPF program 同时有 hot/sequential/no-lead sites 和 high-miss future-address sites。 | 不预取会让 high-miss future-address site 慢；但全部预取又会让 hot/no-lead sites 变慢。per-PC table 的价值是只预取该慢的 site，跳过不该插的 site。 | profile 对每个 PC 指定 `prefetch` 或 `skip`。 | schema 候选。 |
| stream-of-strides prefetch | 理论上适用于多个独立 high-miss stream 交错执行，且每个 stream 的 future address 都能足够早知道。 | 不预取时，每个 stream 都可能产生 miss；但多个 prefetch 同时插入会增加指令、带宽和 cache pressure。新 PMU 结果显示 single-site / degree1 有小幅正向；two-site / degree2 虽然降 miss，但开销抵消收益。 | profile 控制一个或两个 future stream site 发 hint。 | 只保留 degree1 / profile-gated 候选；拒绝 degree2 two-site placement。 |
| no-prefetch / skip policy | hot load、sequential stream、same-cacheline 重复访问、deep dependent-chain、无提前量访问。 | 这些形态不预取通常不慢，或慢也不是 prefetch 能提前隐藏的 miss；插 prefetch 只会增加额外 hint、带宽或污染风险。 | explicit skip / admission rule。 | 保留。 |

### 3.2 当前参数

| 参数 | 绑定到哪个策略 | 当前结论 |
|---|---|---|
| horizon | future-address single-stream / spatial / MLOP / stream | horizon2 当前最好；horizon1 太近，horizon4 不一定更好。 |
| degree | future-address single-stream / spatial / stream | degree1 当前最好；degree2/3 没超过 degree1。 |
| hint variant | 所有发 native prefetch 的 policy | ARM64 L1 hint 当前最好；x86 `nta` reject。 |
| profile gate | 所有非 skip policy | 当前 positive 都依赖 hand-profiled PC/register，不能 default-enable。 |

## 4. Microbenchmark 设计

microbenchmark 的作用是让每个策略都有一个明确、可解释的测试用例。结果不按“历史实验”
汇报，而按 `策略 -> 测试用例 -> 构造方式 -> 结果` 汇报。

repo 原有 micro suite 不是为 prefetch 策略设计的。当前 prefetch 测试用例都是本 task 新增的
`synthetic-control` 用例，用来隔离策略机制，不是从真实 BPF program 自动提取的。

有效性能用例必须满足：

```text
1. 一个测试用例只回答一个主要策略问题。
2. control 有足够 cache miss，或者明确标为负向对照 / 安全覆盖用例。
3. treatment 与 control 只差 prefetch kinsn / profile 配置。
4. report 必须同时看 exec、cycles、instructions、cache_misses、cache_references / miss_rate。
5. 如果 control cache miss 为 0 或很低，这个 case 不能作为 positive evidence。
```

当前 active micro cases：

| 策略 | 测试参数 | 测试用例 | 源码 | 用例怎么构造 / 为什么合理 |
|---|---|---|---|---|
| MLOP / index-field prefetch | horizon, hint | `prefetch_mlop_index_field` | [prefetch_upper_bound.bpf.c](/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c:432) | 地址由 record index 和 field offset 生成，提前物化 `i+2` field pointer；future address 可提前算，基线 miss 高。 |
| future-address single-stream prefetch | horizon | `prefetch_pipeline_page_stride`, `prefetch_pipeline_horizon1/2/4_page_stride` | [prefetch_upper_bound.bpf.c](/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c:139) | 第 `i` 轮读 current pointer，预取 future pointer；用于测提前量。 |
| future-address single-stream prefetch | degree | `prefetch_degree123_page_stride`, `prefetch_pipeline_degree_page_stride` | [prefetch_upper_bound.bpf.c](/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c:462) | 同一 stream 物化多个 future pointers，用 profile 控制一次发几个 hint。 |
| spatial-within-page prefetch | degree, hint | `prefetch_spatial_page_footprint` | [prefetch_upper_bound.bpf.c](/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c:349) | 每轮访问同一 future page 内多个 offsets；测 region footprint。 |
| struct-field fixed-offset prefetch | degree, hint | `prefetch_struct_field_fixed_offsets` | [prefetch_upper_bound.bpf.c](/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c:390) | 每个 record 有固定 fields；测 future record fields 是否可预取。 |
| mixed per-PC policy table | profile action | `prefetch_mixed_policy_table` | [prefetch_upper_bound.bpf.c](/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c:503) | 同一 program 混合 hot/current/future sites，profile 只允许一个 future site。 |
| same-iteration current-address prefetch | placement | `prefetch_upper_page_stride`, `prefetch_map_page_stride` | [prefetch_upper_bound.bpf.c](/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c:117) | 高 miss map access，但预取当前轮地址；用于证明 no-lead-time 不够。 |
| packet first-deref prefetch | placement | `prefetch_first_deref_page_stride` | [prefetch_upper_bound.bpf.c](/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c:591) | map-backed page-spread target，模拟 first-deref high-miss target。 |
| stream-of-strides prefetch | horizon, degree | `prefetch_stream_of_strides_high_miss` | [prefetch_upper_bound.bpf.c](/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c:618) | 两个 page-spread future streams，horizon4；用 profile 分别测 degree1 single-site 和 degree2 two-site placement。 |
| stride-only future-address prefetch | stride class | `prefetch_stride64/256/4096_page_stride` | [prefetch_upper_bound.bpf.c](/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c:270) | 只改变 stride class；测试 stride alone 是否足够成为 policy。 |
| no-prefetch / skip policy | access shape | `prefetch_hot_l1_load`, `prefetch_sequential_scan`, `prefetch_indirect_two_stage` | [prefetch_research.bpf.c](/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.bpf.c:270) | 构造 hot、sequential、dependent-chain access；这些是跳过规则 / 负向对照用例，不是正向性能用例。 |

### 4.1 用例有效性审计

这里先只判断 case 是否有效，不判断 policy 是否有收益。一个有效性能用例必须满足：

```text
1. case 的访问模式和 policy 要解决的问题匹配。
2. control 有足够 cache miss pressure；如果基线 miss rate / miss count 很低，就不是正向性能用例。
3. prefetch address 在 demand load 前足够早知道，有提前量。
4. treatment 真的在预期 site 插入预期 native prefetch。
5. control / treatment 除 prefetch 外没有无关差异。
```

`是否为有效性能用例` 只表示“这个用例能不能用来评估策略是否有效”。它不表示
treatment 已经加速。加速与否必须在第 6 节用 timing / PMU 结果单独判断。

| 策略 | 目标正向用例 | 模式匹配 | 基线缺失压力 | 提前量 | 是否插入预期预取 | 是否为有效性能用例 | 后续动作 |
|---|---|---|---|---|---|---|---|
| MLOP / index-field prefetch | `prefetch_mlop_index_field` | 是：地址由 record index + field offset 组成。 | 是：control `cache_misses` mean `1527440`。 | 是：future field pointer 可提前物化。 | 是：profile-fed ARM64 L1 PRFM。 | 是 | 无 |
| future-address single-stream prefetch | `prefetch_pipeline_horizon2_page_stride` | 是：第 `i` 轮可算第 `i+2` 轮地址。 | 是：control `cache_misses` mean `1484550`。 | 是：horizon2。 | 是：profile-fed ARM64 L1 PRFM。 | 是 | 无 |
| future-address single-stream prefetch | `prefetch_pipeline_page_stride` | 是：第 `i` 轮可算第 `i+1` 轮地址。 | 是：control `cache_misses` mean `1649502`。 | 是：next-iteration。 | 是：profile-fed ARM64 L1 PRFM。 | 是 | 无 |
| future-address degree parameter | `prefetch_degree123_page_stride` | 是：同一 stream 可算多个 future addresses。 | 是：control `cache_misses` mean `1440755`。 | 是：profile 控制 degree1/2/3。 | 是：profile-fed ARM64 L1 PRFM。 | 是 | 无 |
| spatial-within-page prefetch | `prefetch_spatial_page_footprint` | 是：future page 内多个 offsets 会被访问。 | 是：control `cache_misses` mean `3316317`。 | 是：future page / offsets 可提前物化。 | 是：profile-fed ARM64 L1 PRFM。 | 是 | 无 |
| struct-field fixed-offset prefetch | `prefetch_struct_field_fixed_offsets` | 是：future record 的固定 field offsets。 | 是：control `cache_misses` mean `362260.333`，control miss rate `0.005006681`。 | 是：future record field pointers 可提前物化。 | 是：profile-fed ARM64 L1 PRFM。 | 是 | 无 |
| mixed per-PC policy table | `prefetch_mixed_policy_table` | 是：同一 program 混合 should-prefetch 和 should-skip sites。 | 是：control `cache_misses` mean `1281564.0`，control miss rate `0.026966484`。 | 是：profile 只允许 future-address site。 | 是：profile-fed ARM64 L1 PRFM；其他 sites skip。 | 是，但该 case 同时也是 schema 用例。 | 无 |
| same-iteration current-address prefetch | `prefetch_upper_page_stride` | 是：当前轮 demand load address。 | 是：control `cache_misses` mean `1657730`。 | 否：address 只在当前轮 demand load 前短时间可用。 | 是。 | 否；这是有效负向用例，不是正向性能用例。 | 无 |
| map-value same-iteration prefetch | `prefetch_map_page_stride` | 是：map value current-address load。 | 是：control `cache_misses` mean `304785`。 | 否：same-iteration。 | 是。 | 否；这是有效负向 / 诊断用例。 | 无 |
| packet structural default prefetch | packet structural cases | 是：packet-derived loads。 | 否 / 混合：多数 packet 用例基线 miss 低。 | 否 / 混合：很多 site 地址知道太晚或太近。 | 覆盖用例中是。 | 否；不是正向性能用例。 | 如果重新定义 packet 策略，需要另建正向用例。 |
| packet first-deref prefetch | `prefetch_first_deref_page_stride` | 是：first-deref-like high-miss shape。 | 是：control `cache_misses` mean `1395197.0`，control miss rate `0.032932241`。 | 有一定提前量，但 prefetch site 到实际 demand load 的距离不足以降低 miss。 | 是：treatment JIT dump 中有 `prfm pldl1keep, [x7]`。 | 否；这是有效诊断用例，不是正向性能用例。 | 无；当前 placement 已拒绝。 |
| stream-of-strides prefetch | `prefetch_stream_of_strides_high_miss` + degree1 profile | 是：interleaved page-spread streams，profile 只打开一个 stream site。 | 是：control `cache_misses` mean `3210484.2`。 | 是：horizon4。 | 是：1 个 profile-fed ARM64 L1 PRFM site。 | 是 | 保留 degree1 / profile-gated 候选。 |
| stream-of-strides prefetch | `prefetch_stream_of_strides_high_miss` + degree2 profile | 是：两个 interleaved page-spread streams。 | 是：control `cache_misses` mean `3320449.667`。 | 是：horizon4。 | 是：2 个 profile-fed ARM64 L1 PRFM sites。 | 是，针对 two-site placement。 | two-site placement 已可评估并拒绝。 |
| stream-of-strides prefetch | `prefetch_stream_of_strides_degree1_high_miss` | 否：scanner 没匹配到 expected site。 | 未作为 PMU 性能证据。 | N/A | 否：profile smoke `sites_applied=0`。 | 否 | 归档为无效 case；不用它证明 policy。 |
| stride-only future-address prefetch | `prefetch_stride64/256/4096_page_stride` | 部分匹配：有 future-address stride class，但策略只看 stride class。 | 弱 / 混合：control misses `1511.67`, `26697`, `28186.7`，不足以作为强正向用例。 | 是：future pointer 可物化。 | 是。 | 否；当前只是诊断用例。 | 无；standalone stride 策略已拒绝。 |
| no-prefetch / skip policy | `prefetch_hot_l1_load`, `prefetch_sequential_scan`, `prefetch_indirect_two_stage` | 是：hot / sequential / dependent-chain patterns。 | 有意构造成低缺失或不适合作为正向用例。 | 没有有用提前量或没有预取必要。 | 预期行为是跳过。 | 否；这是有效跳过规则用例。 | 无 |

历史上做过但不再作为主线的 cases 只保留在
[microbench-inventory.md](/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-inventory.md)。

## 5. 实验设置和指标

所有 benchmark 必须通过 Makefile / AWS wrapper 路径运行。基本流程：

```text
control：不应用 prefetch pass。
treatment：应用 bpfopt --pass prefetch，并按需要传入 profile JSON。
runner：kernel runtime 执行 BPF_PROG_TEST_RUN，保存 raw measurements。
analysis：从 raw measurements 计算 treatment/control ratio。
```

常用命令形态：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.large \
  BENCH=prefetch_pipeline_horizon2_page_stride \
  RUNTIMES=kernel \
  SAMPLES=3 \
  WARMUPS=1 \
  INNER_REPEAT=10000 \
  PERF_COUNTERS=1 \
  PERF_SCOPE=full_repeat_raw \
  CPU=0
```

PMU-capable attribution 使用 AWS ARM64 `c7g.large` 或 `c7g.medium`。默认 `t4g.small`
缺少 generic `cache_misses` / `cache_references` PMU counters，只能做 correctness / runtime smoke，
不能做 cache-miss 归因。

`PERF_SCOPE=full_repeat_raw` 表示 PMU counters 是单个 sample 中整个 `INNER_REPEAT` repeated run
的累计 raw totals，不是除以 `INNER_REPEAT` 后的平均值。

raw measurements 保存在每个 micro result 的 `result.json` / `metadata.json`：

```text
benchmarks[].runs[].samples[].exec_ns
benchmarks[].runs[].samples[].perf_counters.cycles
benchmarks[].runs[].samples[].perf_counters.instructions
benchmarks[].runs[].samples[].perf_counters.cache_references
benchmarks[].runs[].samples[].perf_counters.cache_misses
```

每个 sample 的采集粒度是一次 full repeated run。也就是说，如果命令里设置
`INNER_REPEAT=10000`，那么下面这些 raw counter 都覆盖这 10000 次 repeated BPF run 的总量，
不是单次 BPF run 的均值。

| raw field | 怎么测出来 | 单位 / 粒度 | 在结果表里的用途 |
|---|---|---|---|
| `exec_ns` | micro runner 在 kernel runtime helper 外侧测量一次 sample 的执行时间；该 helper 内部重复执行 `INNER_REPEAT` 次 BPF program。 | ns；单个 full repeated sample。 | 计算 `T/C exec`。这是最终 runtime 指标。 |
| `cycles` | `PERF_COUNTERS=1` 打开 Linux `perf_event` generic `cycles` PMU counter；`PERF_SCOPE=full_repeat_raw` 表示统计整个 full repeated sample。 | CPU cycles；单个 full repeated sample。 | 计算 `cycles T/C`，用于判断 runtime 变化是否对应 CPU cycle 变化。 |
| `instructions` | `PERF_COUNTERS=1` 打开 Linux `perf_event` generic `instructions` PMU counter。 | retired instructions；单个 full repeated sample。 | 计算 `instructions T/C`，用于判断 prefetch 是否引入额外动态指令开销，或是否因为代码路径变化导致指令数变化。 |
| `cache_references` | `PERF_COUNTERS=1` 打开 Linux generic `cache-references` PMU counter。它是平台暴露的 generic cache reference 事件，不等价于固定的 L1 或 L2 事件。 | cache references；单个 full repeated sample。 | 计算 miss rate 的分母。 |
| `cache_misses` | `PERF_COUNTERS=1` 打开 Linux generic `cache-misses` PMU counter。它是平台暴露的 generic cache miss 事件，不等价于固定的 L1 或 L2 miss。 | cache misses；单个 full repeated sample。 | 计算 miss count ratio 和 miss rate。 |

每个表里的 ratio 都在 analysis side 从 raw samples 计算，公式是：

```text
mean_control_X = average(control samples' X)
mean_treatment_X = average(treatment samples' X)
X T/C = mean_treatment_X / mean_control_X
miss_count_ratio = mean_treatment_cache_misses / mean_control_cache_misses
miss_rate = mean_cache_misses / mean_cache_references
miss_rate_delta = treatment_miss_rate - control_miss_rate
```

因此，`cycles T/C < 1` 表示 treatment 的平均 CPU cycles 更少；`instructions T/C > 1`
表示 treatment 的平均 retired instructions 更多；`miss_count_ratio < 1` 表示总 cache miss
下降。性能判断不能只看一个指标，必须同时看 `exec_ns`、`cycles`、`instructions` 和
`cache_misses/cache_references`。

完整字段来源和 analysis-side ratio 计算方式另见
[results.md](/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md)。

统一指标：

| column | 含义 |
|---|---|
| `T/C exec` | `mean_exec_ns(treatment) / mean_exec_ns(control)`；小于 `1` 表示 treatment 更快。 |
| `ctrl_misses` / `trt_misses` | control / treatment 的 mean cache miss count。 |
| `miss_count_ratio` | `trt_misses / ctrl_misses`；小于 `1` 表示 treatment 总 miss 下降。 |
| `ctrl_refs` / `trt_refs` | control / treatment 的 cache references。 |
| `ctrl_miss_rate` / `trt_miss_rate` | `cache_misses / cache_references`。 |
| `miss_rate_delta` | `trt_miss_rate - ctrl_miss_rate`；小于 `0` 表示 treatment miss rate 下降。 |
| `cycles T/C` | treatment cycles / control cycles。 |
| `instructions T/C` | treatment instructions / control instructions。 |

`cache_misses` 和 `cache_miss_rate` 不能合并成一个指标，但必须放在同一个 policy/test-case 表里。
miss count 回答“总 miss 有没有变少”；miss rate 回答“每次 cache reference 的 miss 概率有没有变低”。
当 treatment 改变 `cache_references` 时，必须同时看二者。

## 6. 结果和原因分析

本节只回答两个问题：

```text
1. 有效正向用例是否真的有收益？
2. 有收益或无收益的原因是什么？
```

判断顺序是：

```text
case validity -> native prefetch 是否插入 -> cache miss 是否下降 -> exec/cycles 是否下降 -> instructions / code size 是否抵消收益
```

### 6.1 有效正向用例：是否有收益

这些 case 都满足第 4.1 节的有效正向用例标准。结论是：大部分 future-address 类 case 有收益；
收益主要来自 cache miss count / miss rate 大幅下降。弱收益 case 也有 miss-rate 下降，但
收益幅度较小或需要 profile gate 控制插入点。

| 策略 | 测试用例 | T/C exec | cycles T/C | instructions T/C | miss_count_ratio | miss_rate_delta | 原因分析 | 决策 |
|---|---|---:|---:|---:|---:|---:|---|---|
| MLOP / index-field | `prefetch_mlop_index_field` | `0.945284` | `0.970091` | `0.957288` | `0.019193` | `-0.051594` | future indexed field address 能在 demand load 前物化；treatment 把 mean cache misses 从 `1527440` 降到 `29316.3`，miss rate 明显下降，cycles 同向下降。 | keep；当前最强。 |
| future-address horizon2 | `prefetch_pipeline_horizon2_page_stride` | `0.961195` | `0.997167` | `0.970903` | `0.009627` | `-0.037009` | 第 `i` 轮提前预取第 `i+2` 轮 page-spread 地址；miss 从 `1484550` 降到 `14292`。cycles 只小降，但 exec 和 instructions 都下降。 | keep；当前默认 horizon。 |
| future-address degree1 | `prefetch_degree123_page_stride` | `0.958149` | `1.000250` | `0.969921` | `0.006768` | `-0.035913` | degree1 只发一个 future hint，miss 从 `1440755` 降到 `9751`，没有 degree2/3 的额外 hint 压力。cycles 基本持平，exec 仍有收益。 | keep degree1；不默认 degree>1。 |
| future-address next-iteration | `prefetch_pipeline_page_stride` | `0.968297` | `0.935296` | `0.970491` | `0.006868` | `-0.040931` | 第 `i` 轮提前预取第 `i+1` 轮地址；miss 从 `1649502` 降到 `11328`，cycles/exec 都下降。 | keep；但 horizon2 更稳。 |
| spatial-within-page | `prefetch_spatial_page_footprint` | `0.971461` | `0.957085` | `1.037390` | `0.000460` | `-0.046003` | 多个 future offsets 落在同一 future page / region；miss 从 `3316317` 降到 `1524.67`。但 instructions 增加 `3.7%`，说明收益依赖足够高的 miss pressure 和 profile gate。 | keep profile-gated。 |
| struct-field fixed-offset | `prefetch_struct_field_fixed_offsets` | `0.986178` | `0.970069` | `1.022834` | `0.150586` | `-0.004231` | fixed fields 的 future record address 可提前算，miss rate 下降；但 treatment retired instructions 增加约 `2.28%`，所以 exec 只提升约 `1.4%`。 | weak keep。 |
| mixed per-PC policy table | `prefetch_mixed_policy_table` | `0.977369` | `0.983388` | `1.025640` | `0.010690` | `-0.026663` | 同一 program 里 17 个 candidate 只允许 1 个 future-address site，其他 16 个 hot/no-lead sites skip；miss rate 从 `0.026966484` 降到 `0.000303070`。treatment retired instructions 增加约 `2.56%`，但 miss drop 足以带来小幅 runtime win。 | keep schema。 |
| stream-of-strides degree1 | `prefetch_stream_of_strides_high_miss` + single-site profile | `0.990870` | `0.981531` | `0.993567` | `0.882631` | `-0.004916` | 只打开 PC `24` / `r9` 一个 high-miss stream site；miss 从 `3210484.2` 降到 `2833672.4`，cycles 和 instructions 同向下降。 | weak keep；只保留 profile-gated degree1。 |

结论：

```text
positive candidate 的共同条件是：
1. future address 早于 demand load 可知；
2. control 有明显 cache miss pressure；
3. treatment 明确插入 PRFM；
4. miss count / miss rate 明显下降；
5. prefetch 指令开销没有完全抵消 miss 下降。
```

### 6.2 有效诊断用例：为什么没有收益

这些 case 不是无效实验；它们是用来拒绝某类 placement 或参数的诊断用例。它们回答的是：
“如果 pattern 看起来能插 prefetch，为什么实际不应该插？”

| 策略 / placement | 测试用例 | T/C exec | cycles T/C | instructions T/C | miss_count_ratio | miss_rate_delta | 无收益原因 | 决策 |
|---|---|---:|---:|---:|---:|---:|---|---|
| same-iteration current address | `prefetch_upper_page_stride` | `0.996947` | `0.993570` | `1.000640` | `0.994163` | `-0.000419` | control miss 高，但 prefetch 插在当前 demand load 前太近，miss 基本没降。问题不是 case 没 miss，而是没有 lead time。 | reject same-iteration。 |
| map-value same-iteration | `prefetch_map_page_stride` | `0.994264` | `0.986915` | `1.008210` | `0.964509` | `-0.000858` | miss 只小幅下降，instructions 增加；收益不足以 justify default map-value current-address prefetch。 | reject default。 |
| packet first-deref current placement | `prefetch_first_deref_page_stride` | `1.000208` | `1.024748` | `1.024585` | `0.999198` | `-0.000334` | JIT dump 确认有 `prfm pldl1keep, [x7]`，但 miss 从 `1395197.0` 只降到 `1394078.0`；prefetch site 到 demand load 的距离不足，且 instructions/cycles 上升约 `2.5%`。 | reject 当前 placement。 |
| packet future-first diagnostic | `prefetch_future_first_deref_window` | `0.997711` | `0.994716` | `0.999671` | `1.003498` | `0.000031` | profile smoke 确认插入 1 个 `prfm`，但 miss 从 `1688497.6` 增到 `1694404.6`；微小 timing 改善没有 cache-miss evidence 支撑。 | 不作为正向 policy evidence；需要更清楚的 future-first case 才能继续。 |
| stream-of-strides degree2 / two-site placement | `prefetch_stream_of_strides_high_miss` + two-site profile | `1.002240` | `1.005900` | `1.014335` | `0.834258` | `-0.006383` | 这个 case 证明 miss 可以下降：miss 从 `3320449.667` 降到 `2770112.0`。但两个 stream 同时插 hint 增加动态 instructions `1.43%`、BPF bytes `1.10%`、native bytes `0.46%`，cycles/exec 反而变差。 | reject degree2 / two-site placement；若继续，必须重设计 scheduling。 |
| standalone stride64 | `prefetch_stride64_page_stride` | `0.998684` | `0.998030` | `1.002690` | `0.759427` | `-0.000012` | control miss count 只有 `1511.67`，基线 miss pressure 太低；miss 小降不能转化为 timing win。 | reject standalone stride。 |
| standalone stride256 | `prefetch_stride256_page_stride` | `0.999031` | `0.997228` | `1.002940` | `0.820329` | `-0.000155` | control miss count `26697`，miss pressure 不足且 instructions 上升。 | reject standalone stride。 |
| standalone stride4096 | `prefetch_stride4096_page_stride` | `1.000230` | `1.000520` | `1.004340` | `0.984768` | `-0.000014` | page stride 本身没有带来可隐藏的 demand miss；miss 几乎不降，instructions 上升。 | reject standalone stride。 |

结论：

```text
没有收益的原因分三类：
1. 无 lead time：same-iteration、first-deref current placement。
2. miss pressure 不够：standalone stride64/256/4096。
3. miss 降了但 overhead 抵消：stream-of-strides degree2 / two-site placement。
```

这些结论说明：`stride`、`packet`、`map-value` 这类名字本身不是 policy。只有当它们形成
`future-address + high-miss + enough lead time + bounded overhead` 的访问模式时，才可能成为正向策略。

### 6.3 跳过规则 / 安全覆盖

这些用例不用于证明性能收益；它们用于证明某些 pattern 应该跳过，或者验证 admission rule。

| 规则 | 测试用例 | 证据 | 当前决策 |
|---|---|---|---|
| hot-load skip | `prefetch_hot_l1_load` | 基线 cache misses 低或为 0。 | skip hot load。 |
| sequential-stream skip | `prefetch_sequential_scan` | 基线 cache misses 低；硬件 prefetch 可能已覆盖。 | skip simple sequential。 |
| dependent-chain skip | `prefetch_indirect_two_stage` | 地址知道太晚，没有有用提前量。 | skip deep dependent chain。 |
| same-cacheline dedup | `prefetch_map_line_dedup` | 同一 cacheline 多 candidate；主要验证 dedup。 | keep admission rule。 |

## 7. 当前计划和进度

Prefetch task 的总体计划：

```text
1. 打通 Kinsn PREFETCH / PRFM ABI 和 JIT emit。已完成。
2. 做 literature review，提取可适配 Kinsn 的 policy 维度。已完成。
3. 为每个策略构造 active micro 测试用例。已完成当前策略集合的一轮审计。
4. 做 correctness / emit smoke。已完成。
5. 做 paired runtime attribution。已完成。
6. 做 PMU-capable attribution。已完成主要 candidate / reject cases。
7. 清理文档，把策略、micro、指标、结果分开。已完成当前轮。
8. 补齐 / 重构不合格 micro 用例，并重新跑必要的 PMU attribution。已补 first-deref PMU、future-first diagnostic、stream-of-strides degree1；当前策略集合没有缺失 PMU 的有效正向性能用例。
9. 在 micro evidence 完整后，再讨论 integrated profile-gated prefetcher。未开始。
10. 用真实 corpus site census 生成 evidence-backed profile table。未开始。
```

当前进度：第 7 步已完成当前轮文档整理；第 8 步中 first-deref、future-first diagnostic、
stream-of-strides degree1 缺口已经补完。stream-of-strides 不能整体拒绝：degree1 是弱正向
profile-gated 候选，degree2 / two-site placement 被拒绝。当前不需要补跑已定义策略用例。

下一步不是 integrated prefetcher，而是做 artifact / commit 收尾：

```text
1. 确认 repo 内需要提交的 prefetch docs / compact artifacts 完整。
2. 确认顶层 experiments 保留 raw data，code/docs 只保留小型可复查 artifact。
3. 准备 commit plan。
4. 如果后续重新提出 stream-of-strides degree>1，需要先给出新的 scheduling / placement，再重测。
5. 如果后续重新提出 standalone stride，需要先给出新的 high-miss、lead-time-matched 用例，再重测。
```

## 8. 文档和 artifact 入口

主文档：

| 文档 | 作用 |
|---|---|
| [README.md](/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md) | task 入口和当前结论。 |
| [technical-report.md](/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/technical-report.md) | 本文，当前 self-contained 技术报告。 |
| [policy-matrix.md](/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md) | policy taxonomy 和 policy 状态。 |
| [microbench-design.md](/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-design.md) | microbenchmark 构造细节。 |
| [results.md](/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md) | 结果附录和 artifact 入口。 |
| [literature/literature-review.md](/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/literature-review.md) | literature review。 |

关键实验 artifact 在：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments
/home/ruoji/github/bpf-opt/experiments
/home/ruoji/github/bpf-opt/experiments/2026-06-05-prefetch-reworked-performance-cases
```
