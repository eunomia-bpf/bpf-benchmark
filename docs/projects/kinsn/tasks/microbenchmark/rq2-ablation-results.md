# Kinsn RQ2 microbenchmark ablation 结果

## 研究问题

RQ2: How should Kinsn families be selected for different workloads?

本实验把 stock kernel eBPF JIT 作为固定 baseline，并比较 full Kinsn 与逐类关闭 Kinsn pass family 后的 `kernel_rejit`。主要观察三类指标：相对 stock 的执行加速、相对 full 的性能 delta、以及 matched/applied Kinsn site 覆盖。

## 数据来源

- `/home/weichen/bpf-benchmark/micro/results/rq2_ablation_full_20260608_195318_696581/metadata.json`
- `/home/weichen/bpf-benchmark/micro/results/rq2_ablation_no_bulk_20260608_211638_295060/metadata.json`
- `/home/weichen/bpf-benchmark/micro/results/rq2_ablation_no_cond_select_20260608_205937_596964/metadata.json`
- `/home/weichen/bpf-benchmark/micro/results/rq2_ablation_no_endian_20260608_204323_226983/metadata.json`
- `/home/weichen/bpf-benchmark/micro/results/rq2_ablation_no_extract_20260608_202713_851426/metadata.json`
- `/home/weichen/bpf-benchmark/micro/results/rq2_ablation_no_prefetch_20260608_213241_489262/metadata.json`
- `/home/weichen/bpf-benchmark/micro/results/rq2_ablation_no_rotate_20260608_201113_541387/metadata.json`
- `/home/weichen/bpf-benchmark/micro/results/rq2_ablation_no_wide_mem_20260608_215317_831111/metadata.json`

- summary CSV: `/home/weichen/bpf-benchmark/micro/results/figures/kinsn-rq2-ablation-summary-20260608.csv`
- per-case CSV: `/home/weichen/bpf-benchmark/micro/results/figures/kinsn-rq2-ablation-percase-20260608.csv`

## 汇总结果

| config | geomean speedup vs stock | delta vs full | code-size reduction | applied sites | wins / ties / losses |
|---|---:|---:|---:|---:|---:|
| full | 1.112x | 1.000x | 1.2% | 29 | 20/3/6 |
| no-wide-mem | 1.027x | 0.924x | 0.0% | 0 | 12/13/4 |
| no-rotate | 1.138x | 1.023x | 1.2% | 29 | 19/4/6 |
| no-extract | 1.117x | 1.005x | 1.2% | 29 | 19/6/4 |
| no-endian | 1.150x | 1.034x | 1.2% | 29 | 21/3/5 |
| no-cond-select | 1.127x | 1.013x | 1.2% | 29 | 21/5/3 |
| no-bulk | 1.145x | 1.030x | 1.2% | 29 | 21/3/5 |
| no-prefetch | 1.135x | 1.021x | 1.2% | 29 | 18/4/7 |

## 初步结论

- full Kinsn 的 geomean speedup 为 `1.112x`，作为本轮 ablation 的 full 配置参照点。
- `no-wide-mem` 相对 full 的 geomean delta 最低，为 `0.924x`，说明被关闭的 family 对当前 micro workload 最关键。
- applied/matched site 数可以解释 ablation 的机制：如果关闭某个 family 后覆盖下降明显且性能也下降，说明该 family 是实际生效路径；如果覆盖变化小但性能变化大，需要回到 per-case CSV 看具体 benchmark。

## 图表

- `figures/kinsn-rq2-ablation-speedup.png/.pdf`: 各配置相对 stock 的 geomean speedup。
- `figures/kinsn-rq2-ablation-delta-full.png/.pdf`: 各配置相对 full 的 geomean delta。
- `figures/kinsn-rq2-ablation-applied-sites.png/.pdf`: 各配置 applied sites 覆盖。
