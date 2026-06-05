# 2026-06-04 prefetch-missing-performance-attribution

## 结论

本实验补齐两个 prefetch policy 缺失的 performance-attribution case：

- `prefetch_first_deref_page_stride`
- `prefetch_stream_of_strides_high_miss`

最终结论：

| case | final status | 关键数字 |
|---|---|---|
| `prefetch_first_deref_page_stride` | timing-negative | `t4g.small` paired runtime T/C `1.007421` |
| `prefetch_stream_of_strides_high_miss` degree2 / two-site | cache-miss-drop diagnostic, not selector-ready | `t4g.small` paired runtime T/C `0.918211`; `c7g.medium` PMU rerun mean exec T/C `1.002240`, mean cycles T/C `1.005900`, mean cache misses T/C `0.834258` |

`c7g.medium` 能提供 `cycles/instructions/cache_references/cache_misses`，因此本实验没有使用 `large`。

## 实验过程

本实验先在 `t4g.small` 上完成 correctness、candidate diagnostics、profile transform smoke、
treatment smoke 和 paired runtime attribution。随后用 `c7g.medium` 只重跑
`prefetch_stream_of_strides_high_miss` 的 degree2 / two-site profile，补 PMU attribution。

关键命令：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh arm64 micro \
  AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.medium \
  RUN_TOKEN=prefetch-stream-high-c7gm-control \
  PERF_COUNTERS=1 \
  PERF_SCOPE=full_repeat_raw \
  CPU=0 \
  BENCH=prefetch_stream_of_strides_high_miss \
  RUNTIMES=kernel \
  SAMPLES=3 \
  WARMUPS=1 \
  INNER_REPEAT=10000
```

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh arm64 micro \
  AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.medium \
  RUN_TOKEN=prefetch-stream-high-c7gm-treatment \
  PERF_COUNTERS=1 \
  PERF_SCOPE=full_repeat_raw \
  CPU=0 \
  BENCH=prefetch_stream_of_strides_high_miss \
  RUNTIMES=kernel \
  SAMPLES=3 \
  WARMUPS=1 \
  INNER_REPEAT=10000 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile micro/config/prefetch-stream-of-strides-high-miss-profile-pc24-r9-pc31-r1.json --max-sites=2 --hint=pldl1keep'
```

## PMU 结果

| metric | control | treatment | treatment/control |
|---|---:|---:|---:|
| mean exec_ns | 16967.000000 | 17005.000000 | 1.002240 |
| mean cycles | 207326715.000000 | 208550030.333333 | 1.005900 |
| mean instructions | 886240928.333333 | 898944901.333333 | 1.014335 |
| mean cache misses | 3320449.666667 | 2770112.000000 | 0.834258 |
| median cache misses | 3348873 | 2723798 | 0.813348 |
| mean miss rate | 0.040607450 | 0.034224896 | 0.842823 |

Interpretation：

- prefetch 确实降低 cache miss。
- 但额外指令和执行成本抵消了 miss drop，exec/cycles 没有降低。
- 当前 stream-of-strides degree2 / two-site placement 不能进入 selector；如果继续研究，需要重新设计 scheduling、
  degree 或 insertion placement，并重新做 PMU-capable paired attribution。

后续 2026-06-05 实验已补同一 high-miss case 的 degree1 / single-site profile。degree1 有弱正向
PMU evidence；因此本报告只拒绝 degree2 / two-site placement，不拒绝整个 stream-of-strides
policy family。

## Artifact

本目录只保存小型可提交 artifact：

- `analysis/raw-samples.tsv`
- `analysis/run-summary.tsv`
- `analysis/paired-ratio.tsv`
- `analysis/codegen-evidence.tsv`
- `analysis/aws-cost-summary.tsv`
- `data/run-contract.json`
- `data/aws-instance-describe.json`
- `data/aws-price-c7g-medium.json`
- `data/aws-price-ebs-gp.json`

完整原始实验目录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-missing-performance-attribution
```
