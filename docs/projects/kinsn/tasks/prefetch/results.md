# Kinsn Prefetch 结果附录

最后更新：2026-06-05。

本文是 prefetch task 的结果附录。主线解释见：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/technical-report.md
```

## 结论

Prefetch 通路可用，但不能 default-enable。当前结果支持 profile-gated future-address prefetch，
不支持 same-iteration / structural default prefetch。

当前保留的 policy candidate：

```text
MLOP / index-field
future-address single-stream
spatial-within-page, profile-gated
struct-field fixed-offset, weak candidate
mixed-policy-table schema
stream-of-strides degree1, weak profile-gated candidate
```

当前保留的参数选择：

```text
horizon2 / next-iteration
degree1
ARM64 L1 hint
```

当前 reject：

```text
same-iteration current address
plain packet structural prefetch
standalone stride-class
x86 NTA default
stream-of-strides degree2 / two-site placement
```

## 指标定义

所有 ratio 都在 analysis-side 从 raw measurements 计算，不写入 benchmark framework。

### 采集命令和 raw 字段来源

这些指标不是手工猜出来的。每个 prefetch micro 实验都通过 Makefile / AWS wrapper 入口跑
`micro`，runner 把每个 sample 的 raw measurement 写入 `result.json` / `metadata.json`。

PMU-capable ARM64 attribution 的典型命令形态如下：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh arm64 micro \
  AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.large \
  RUN_TOKEN=<token> \
  BENCH=<bench-name> \
  RUNTIMES=kernel \
  SAMPLES=3 \
  WARMUPS=1 \
  INNER_REPEAT=10000 \
  PERF_COUNTERS=1 \
  PERF_SCOPE=full_repeat_raw \
  CPU=0
```

treatment 在同一命令上额外打开 `bpfopt` prefetch pass：

```bash
BPFREJIT_BENCH_PASSES=prefetch
BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/<profile>.json --max-sites=<N> --hint=<hint>'
```

`PERF_COUNTERS=1` 会让 micro runner 给底层 helper 加 `--perf-counters`。
`PERF_SCOPE=full_repeat_raw` 表示 PMU counters 是整个 `INNER_REPEAT` repeated run 的累计 raw
total，不除以 `INNER_REPEAT`。因此 `cycles`、`instructions`、`cache_references`、
`cache_misses` 都是每个 sample 的 full-repeat raw totals。

raw sample 字段位置：

```text
result.json
  benchmarks[]
    runs[]
      samples[]
        exec_ns
        perf_counters.cycles
        perf_counters.instructions
        perf_counters.cache_references
        perf_counters.cache_misses
```

这些字段的含义：

| raw field | 怎么测得 | 单位 / 粒度 |
|---|---|---|
| `exec_ns` | micro runner 调用 kernel runtime helper 后记录的单个 sample 执行时间。该 helper 对同一个 BPF program 执行 `INNER_REPEAT` 次。 | ns；单个 full repeated sample。 |
| `cycles` | `PERF_COUNTERS=1` 打开的 generic PMU counter。 | cycles；单个 full repeated sample。 |
| `instructions` | `PERF_COUNTERS=1` 打开的 generic PMU counter。 | retired instructions；单个 full repeated sample。 |
| `cache_references` | `PERF_COUNTERS=1` 打开的 generic PMU counter。 | cache references；单个 full repeated sample。 |
| `cache_misses` | `PERF_COUNTERS=1` 打开的 generic PMU counter。 | cache misses；单个 full repeated sample。 |

analysis-side 再把 control 和 treatment 的 raw samples 配对汇总。常见输入表是：

```text
/home/ruoji/github/bpf-opt/experiments/<experiment>/analysis/pmu-samples.tsv
/home/ruoji/github/bpf-opt/experiments/<experiment>/analysis/raw-samples.tsv
```

常见输出表是：

```text
/home/ruoji/github/bpf-opt/experiments/<experiment>/analysis/pmu-policy-attribution.tsv
/home/ruoji/github/bpf-opt/experiments/<experiment>/analysis/paired-ratio.tsv
```

`mean_*` 是同一 bench / runtime / treatment group 的 sample mean。`T/C` ratio 一律是
`treatment mean / control mean`。

| metric | 定义 | 用途 |
|---|---|---|
| `T/C exec` | `mean_exec_ns(treatment) / mean_exec_ns(control)` | 小于 `1` 表示 treatment 更快。 |
| `ctrl_misses` / `trt_misses` | control / treatment mean cache miss count | 判断总 miss 是否下降。 |
| `miss_count_ratio` | `trt_misses / ctrl_misses` | 小于 `1` 表示 treatment 总 miss 更少。 |
| `ctrl_refs` / `trt_refs` | control / treatment mean cache reference count | 判断 treatment 是否改变 cache reference 总数。 |
| `ctrl_miss_rate` / `trt_miss_rate` | `cache_misses / cache_references` | 判断每次 cache reference 的 miss 概率。 |
| `miss_rate_delta` | `trt_miss_rate - ctrl_miss_rate` | 小于 `0` 表示 treatment miss rate 下降。 |
| `cycles T/C` | treatment cycles / control cycles | 判断 timing 是否与 CPU cycles 同方向。 |
| `instructions T/C` | treatment instructions / control instructions | 判断 prefetch 是否引入显著动态指令开销。 |

`cache_misses` 和 `cache_miss_rate` 必须一起看。miss count 回答“总 miss 是否更少”；
miss rate 回答“每次 cache access 的 miss 概率是否更低”。如果 treatment 改变
`cache_references`，只看其中一个会误导。

## Policy / test case 对齐结果

每个性能结果都按 `策略 -> 测试用例` 对齐。一个测试用例只回答一个主要
策略问题；如果用例只是安全覆盖或负向对照，会明确标注。

### 正向 / 弱正向

这些 case 是有效正向性能用例。表里的 `原因` 只基于 timing / PMU / codegen evidence，
不使用未验证猜测。

| 策略 | 参数设置 | 测试用例 | T/C exec | cycles T/C | instructions T/C | ctrl_misses | trt_misses | miss_count_ratio | miss_rate_delta | 原因 | 结论 |
|---|---|---|---:|---:|---:|---:|---:|---:|---:|---|---|
| MLOP / index-field prefetch | horizon2, ARM64 L1 | `prefetch_mlop_index_field` | `0.945284` | `0.970091` | `0.957288` | `1527440` | `29316.3` | `0.019193` | `-0.051594` | future indexed field address 可提前物化；miss 和 cycles 同时下降。 | strongest candidate |
| future-address single-stream prefetch | horizon2, ARM64 L1 | `prefetch_pipeline_horizon2_page_stride` | `0.961195` | `0.997167` | `0.970903` | `1484550` | `14292` | `0.009627` | `-0.037009` | 第 `i` 轮预取第 `i+2` 轮地址；miss 大幅下降。 | keep horizon2 |
| future-address single-stream prefetch | degree1, ARM64 L1 | `prefetch_degree123_page_stride` | `0.958149` | `1.000250` | `0.969921` | `1440755` | `9751` | `0.006768` | `-0.035913` | degree1 降 miss 且避免 degree2/3 的额外 hint 压力。 | keep degree1 |
| future-address single-stream prefetch | next-iteration, ARM64 L1 | `prefetch_pipeline_page_stride` | `0.968297` | `0.935296` | `0.970491` | `1649502` | `11328` | `0.006868` | `-0.040931` | next-iteration address 有提前量；miss/cycles/exec 同向下降。 | keep placement |
| spatial-within-page prefetch | degree3, ARM64 L1 | `prefetch_spatial_page_footprint` | `0.971461` | `0.957085` | `1.037390` | `3316317` | `1524.67` | `0.000460` | `-0.046003` | miss 几乎清掉，但 instructions 增加，必须 profile-gated。 | keep, profile-gated |
| struct-field fixed-offset prefetch | 3 fields, ARM64 L1 | `prefetch_struct_field_fixed_offsets` | `0.986178` | `0.970069` | `1.022834` | `362260.333` | `54552.0` | `0.150586` | `-0.004231` | fixed-field future address 可提前算；miss-rate 下降但 treatment retired instructions 增加约 `2.28%`，所以只算 weak candidate。 | weak candidate |
| mixed per-PC policy table | 1 prefetch / 16 skip | `prefetch_mixed_policy_table` | `0.977369` | `0.983388` | `1.025640` | `1281564.0` | `13696.667` | `0.010690` | `-0.026663` | 17 个 candidate 只应用 1 个 useful future site；其他 hot/no-lead sites skip。instructions 增加约 `2.56%`，但 miss drop 足够大。 | keep schema |
| stream-of-strides prefetch | degree1, ARM64 L1 | `prefetch_stream_of_strides_high_miss` + single-site profile | `0.990870` | `0.981531` | `0.993567` | `3210484.2` | `2833672.4` | `0.882631` | `-0.004916` | profile 只打开一个 high-miss stream site，miss/cycles/instructions 同向下降。 | weak candidate, profile-gated |

### 拒绝 / 非正向

这些 case 是有效诊断用例。它们用于解释为什么某类 placement / 参数不应进入 selector。

| 策略 | 测试用例 | T/C exec | cycles T/C | instructions T/C | ctrl_misses | trt_misses | miss_count_ratio | miss_rate_delta | 原因 | 结论 |
|---|---|---:|---:|---:|---:|---:|---:|---:|---|---|
| same-iteration current address | `prefetch_upper_page_stride` | `0.996947` | `0.993570` | `1.000640` | `1657730` | `1648055` | `0.994163` | `-0.000419` | high-miss 但 no lead time，miss 基本不降。 | reject |
| map-value same-iteration | `prefetch_map_page_stride` | `0.994264` | `0.986915` | `1.008210` | `304785` | `293968` | `0.964509` | `-0.000858` | 少量 miss drop 被 instruction overhead 抵消。 | reject default |
| first-deref current placement | `prefetch_first_deref_page_stride` | `1.000208` | `1.024748` | `1.024585` | `1395197.0` | `1394078.0` | `0.999198` | `-0.000334` | JIT 有 `prfm`，但 miss 基本不降，cycles/instructions 上升。 | reject current placement |
| packet future-first diagnostic | `prefetch_future_first_deref_window` | `0.997711` | `0.994716` | `0.999671` | `1688497.6` | `1694404.6` | `1.003498` | `0.000031` | 插入 1 个 `prfm`，但 miss count/rate 没下降；微小 timing 改善不能作为 cache-prefetch evidence。 | diagnostic only |
| stream-of-strides degree2 / two-site | `prefetch_stream_of_strides_high_miss` + two-site profile | `1.002240` | `1.005900` | `1.014335` | `3320449.667` | `2770112.0` | `0.834258` | `-0.006383` | miss 下降，但两个 hints 带来 instruction/code-size overhead，exec/cycles 不赢。 | reject degree2/two-site placement |
| stream-of-strides invalid custom case | `prefetch_stream_of_strides_degree1_high_miss` | N/A | N/A | N/A | N/A | N/A | N/A | N/A | profile smoke `sites_applied=0`，selector 没命中 expected site；不能作为性能证据。 | archived invalid case |
| old stream-of-strides | `prefetch_stream_of_strides` | `1.557562` | `1.706492` | `0.963653` | `48109.7` | `31147.3` | `0.647446` | `-0.000377` | 旧 case exec/cycles 明显变慢；虽然 retired instructions 和 miss count 下降，但 cache references 增加、cycles 大涨，说明这个旧 layout 不是有效正向性能 case。已被 high-miss case 取代。 | archived diagnostic |
| standalone stride64 | `prefetch_stride64_page_stride` | `0.998684` | `0.998030` | `1.002690` | `1511.67` | `1148` | `0.759427` | `-0.000012` | control miss pressure 太低，不能形成稳定 timing win。 | reject standalone |
| standalone stride256 | `prefetch_stride256_page_stride` | `0.999031` | `0.997228` | `1.002940` | `26697` | `21900.3` | `0.820329` | `-0.000155` | miss drop 小，instructions 上升。 | reject standalone |
| standalone stride4096 | `prefetch_stride4096_page_stride` | `1.000230` | `1.000520` | `1.004340` | `28186.7` | `27757.3` | `0.984768` | `-0.000014` | miss 几乎不降，instructions 上升。 | reject standalone |

### 跳过规则 / 安全覆盖

| 规则 | 测试用例 | 结果 | 结论 |
|---|---|---|---|
| hot-load skip | `prefetch_hot_l1_load` | 基线 cache miss 低 | skip |
| sequential-stream skip | `prefetch_sequential_scan` | 基线 cache miss 低 / timing 中性 | skip |
| dependent-chain skip | `prefetch_indirect_two_stage` | address known too late | skip |
| same-cacheline dedup | `prefetch_map_line_dedup` | dedup / admission evidence | keep rule |

## 参数 sweep

参数 sweep 不单独构成 policy；它们用于给 candidate policy 选参数。

### ARM64 hint

| case | l1keep | l1strm | l2keep | l2strm | decision |
|---|---:|---:|---:|---:|---|
| horizon1 | `1.004758` | `1.046112` | `1.052638` | `1.045345` | reject horizon1 |
| horizon2 | `0.954973` | `0.957488` | `1.003412` | `0.999053` | keep L1 |
| horizon4 | `0.964590` | `0.966710` | `0.986399` | `0.980974` | L1 positive but weaker than horizon2 |
| degree | `0.982073` | `1.001012` | `1.052795` | `1.017365` | degree parameter not better than horizon2 |

### X86 hint

| case | t0 | t1 | t2 | nta | decision |
|---|---:|---:|---:|---:|---|
| horizon1 | `1.001926` | `1.008699` | `0.998209` | `2.944734` | no stable win; reject `nta` |
| horizon2 | `1.000225` | `0.981512` | `1.040229` | `2.393923` | `t1` weak only; reject `nta` |
| horizon4 | `0.991978` | `1.003474` | `2.345639` | `1.681460` | no stable win |
| degree | `1.445870` | `0.996759` | `1.045975` | `1.610153` | reject degree / `nta` |

## 关键 artifact

主要 PMU / policy 结果来自：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-03-prefetch-c7g-pmu-policy-diagnosis
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-schema-and-pmu-evidence
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-missing-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-variant-degree-evidence
/home/ruoji/github/bpf-opt/experiments/2026-06-05-prefetch-reworked-performance-cases
```

repo 内提交的小型可复查 artifact 在：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments
```

完整 AWS logs、runner raw result 和 analysis TSV 保存在顶层：

```text
/home/ruoji/github/bpf-opt/experiments
```
