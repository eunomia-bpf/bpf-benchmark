# Static vs Dynamic Evidence (2026-03-27)

## Scope / 口径

- 本报告统一使用 `exec_ratio = rejit / baseline`。
- `exec_ratio > 1.0` 表示回归，`< 1.0` 表示加速。
- 旧文档里很多表用的是反向口径 `baseline / rejit`。本文已全部翻转到论文更直观的口径。
- family 名称统一为当前 daemon / 论文口径：
  - `cmov -> cond_select`
  - `wide -> wide_mem`
  - `endian -> endian_fusion`
  - `branch-flip -> branch_flip`

## 主要数据源

- Full-apply authoritative corpus:
  `corpus/results/corpus_v5_vm_batch_authoritative_20260311.json`
- Selective authoritative corpus:
  `corpus/results/corpus_authoritative_20260320.json`
- 最新 raw micro:
  `micro/results/vm_micro_20260326_201241/details/result.json`
- 干净的 per-form micro 隔离 rerun:
  `docs/tmp/2026-03-12/per-form-rerun-correct-policy.md`
- policy regeneration 说明:
  `docs/tmp/20260320/corpus_policy_regen_20260320.md`
- map_inline 定向 corpus artifacts:
  `corpus/results/corpus_vm_batch_20260327_141413/details/result.json`
  `runner/corpus/results/vm_corpus_20260327_170425/details/result.json`
  `corpus/results/vm_corpus_20260327_172402/details/result.json`
- E2E:
  `docs/tmp/20260327/vm_e2e_perf_passes_results_20260327.md`
  `e2e/results/*_20260327_*/details/result.json`
- Static verify:
  `docs/tmp/20260324/static_verify.full_micro.rerun.json`

## Executive Summary

最强的 fixed-heuristic 反证来自 authoritative corpus full-apply artifact。`2026-03-11` 的 blind/full apply 在 `92` 个真正发生 rewrite 的程序里有 `63` 个回归，回归占比 `68.5%`；applied-only geomean 为 `1.121x`，即整体是 `12.1%` slowdown。放到全部 `163` 个 measured pairs 上，整体 geomean 仍有 `1.152x` slowdown。

Selective policy 已经能显著降低这类代价。把 `2026-03-11` full-apply 和 `2026-03-20` selective authoritative 两份 artifact 对齐到相同 canonical program 名称后，在 `86` 个共有的 positive-site 程序上，geomean 从 `1.123x` 降到 `1.018x`。其中有 `60` 个程序在 full-apply 下被改写、但在 selective artifact 中被跳过；这些程序的 geomean 从 `1.105x` 几乎回到 `1.003x`。这已经说明“不要固定 always-apply”本身就能消掉大部分回归。

需要强调的是，`2026-03-20` 这份 selective artifact 仍然是 policy-file selective，不是真正基于 live runtime 信号的 daemon oracle。因此它对论文主张的支持是保守下界，不是上限。

更激进的 oracle selective 模拟更直接：在 full-apply 的 `92` 个 applied 程序里，如果只保留 `29` 个 `exec_ratio <= 1.0` 的程序，geomean 会从 `1.121x` 变成 `0.849x`。也就是说，固定 heuristic 不只是“有一点不稳”，而是在 applied subset 上付出了约 `1.32x` 的相对代价。

## 1. Micro 证据：CMOV 不是唯一敏感项，其他 kinsn family 也会回归

先看最干净的 per-form isolation rerun。`docs/tmp/2026-03-12/per-form-rerun-correct-policy.md` 是当前最适合做 family 级因果归因的 micro 证据：

| Benchmark | Family | Stock -> ReJIT | Exec Ratio | 结论 |
| --- | --- | ---: | ---: | --- |
| `cond_select_dense` | `cond_select` | `124.0 -> 101.0 ns` | `0.815x` | 明显加速 |
| `rotate_dense` | `rotate` | `266.0 -> 172.5 ns` | `0.648x` | 明显加速 |
| `extract_dense` | `extract` | `164.0 -> 170.0 ns` | `1.037x` | 小幅回归 |
| `endian_swap_dense` | `endian_fusion` | `211.0 -> 199.5 ns` | `0.945x` | 小幅加速 |
| `branch_flip_dense` | `branch_flip` | `239.0 -> 239.5 ns` | `1.002x` | 基本中性 |

这里最关键的不是“cond_select 赢了”，而是它只在隔离、纯 select-diamond 场景里稳定赢。它和 corpus 上的净负收益并不矛盾，反而正好支持论文想要的论点：相同合法 lowering 在不同 branch predictability / workload mix 下会翻转。

再看最新 raw micro snapshot `2026-03-26`。这份数据已经不适合做干净 family 归因，但很适合证明“当前 active pipeline 里的 kinsn rewrite 不是 always-win”：

| Benchmark | 实际 applied pass | Stock -> ReJIT | Exec Ratio | 备注 |
| --- | --- | ---: | ---: | --- |
| `binary_search` | `wide_mem` | `981 -> 1066 ns` | `1.087x` | branch-heavy case 回归 |
| `switch_dispatch` | `wide_mem` | `650 -> 638 ns` | `0.982x` | 同类 control-flow case 接近持平 |
| `log2_fold` | `wide_mem` | `290 -> 278 ns` | `0.959x` | 小幅加速 |
| `rotate_dense` | `rotate` | `224 -> 178 ns` | `0.795x` | 明显加速 |
| `extract_dense` | `extract` | `281 -> 148 ns` | `0.527x` | 明显加速 |
| `endian_swap_dense` | `endian_fusion` | `114 -> 294 ns` | `2.579x` | 强回归 |
| `cond_select_dense` | none | `78 -> 78 ns` | `1.000x` | 当前 raw run 根本没 apply |
| `cmov_select` | `wide_mem` | `484 -> 1144 ns` | `2.364x` | 这个 benchmark 已不再是 clean cmov case |

`cmov_select` 的 benchmark drift 很重要。`docs/tmp/20260318/micro_further_optimization_20260318.md` 已明确指出：当前 manifest 里它已经没有 `cmov` site，而是 `rotate=4, wide=6`。因此，最新 raw run 里它的巨大回归不能拿来证明 `cond_select` 本身变差，但它非常适合证明另一点：一旦 benchmark 本体、site census、active policy 不再严格对齐，fixed heuristic 的 family attribution 会迅速失真。

如果只看 `2026-03-26` 最新 raw micro 里“某个 family 实际发生 apply 的 benchmark”回归占比：

| Family | Applied benchmarks | Regressed | 回归占比 |
| --- | ---: | ---: | ---: |
| `wide_mem` | `49` | `17` | `34.7%` |
| `rotate` | `13` | `2` | `15.4%` |
| `extract` | `4` | `1` | `25.0%` |
| `endian_fusion` | `1` | `1` | `100%` |
| `cond_select` | `0` | `0` | n/a |
| `branch_flip` | `0` | `0` | n/a |

结论：不仅 `cond_select`，其他 kinsn family 也都不是 always-win。Micro 层面的强支持点是“workload sensitivity exists”；真正的回归占比证据要靠 corpus。

## 2. Corpus：full-apply 下 applied 程序的大多数都回归

### 2.1 Overall

`corpus/results/corpus_v5_vm_batch_authoritative_20260311.json` 的 full-apply authoritative 结果：

- measured programs: `163`
- applied programs: `92`
- applied programs 中回归: `63 / 92 = 68.5%`
- applied-only geomean: `1.121x`
- all-measured geomean: `1.152x`

这已经足够支撑“固定 kernel peephole always apply 会在真实 workload 上导致回归”。

### 2.2 Per-pass 回归率

下面这张表的口径是“family 在该程序上确实 applied”。注意这些不是完美的单-family 因果隔离，因为一个程序可能同时触发多个 family；但它能回答用户最关心的问题：所有 kinsn family 到底有没有回归、回归占比多少。

| Pass | Full-apply applied | Full-apply regressed | 回归占比 | Full-apply geomean | Selective applied | Selective regressed | 回归占比 | Selective geomean |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `cond_select` | `79` | `53` | `67.1%` | `1.091x` | `0` | `0` | n/a | n/a |
| `extract` | `37` | `29` | `78.4%` | `1.200x` | `0` | `0` | n/a | n/a |
| `wide_mem` | `39` | `28` | `71.8%` | `1.129x` | `15` | `11` | `73.3%` | `1.139x` |
| `rotate` | `2` | `1` | `50.0%` | `1.035x` | `0` | `0` | n/a | n/a |
| `endian_fusion` | n/a | n/a | n/a | n/a | `23` | `15` | `65.2%` | `1.018x` |
| `branch_flip` | n/a | n/a | n/a | n/a | `0` | `0` | n/a | n/a |

更强的子集证据：

- pure `cond_select` rows in full-apply: `34` applied，`21` regress，geomean `1.052x`
- pure `extract` rows in full-apply: `10` applied，`10` regress，geomean `1.465x`
- pure `wide_mem` rows in full-apply: `2` applied，`0` regress，geomean `0.924x`
- pure `endian_fusion` rows in selective: `11` applied，`5` regress，geomean `0.953x`
- `endian_fusion + wide_mem` rows in selective: `12` applied，`10` regress，geomean `1.081x`

这说明两个关键点：

- `cond_select` 确实是强 policy-sensitive family，但不是唯一的问题。
- `extract` 和 `wide_mem` 也不是 blanket enable 就能稳定挣钱的 substrate pass；尤其 `extract` 在 full-apply corpus 里几乎是系统性亏损。
- `rotate` 在 corpus authoritative 里的 applied 样本仍然很少，现阶段更适合作为“并非 guaranteed win”的辅助证据，而不是主论点。

### 2.3 Combination-level 结果

full-apply 里最常见的 applied family 组合如下：

| Family 组合 | Programs | Regressed | Geomean |
| --- | ---: | ---: | ---: |
| `cond_select` | `34` | `21` | `1.052x` |
| `cond_select + extract + wide_mem` | `18` | `14` | `1.147x` |
| `cond_select + wide_mem` | `18` | `13` | `1.134x` |
| `extract` | `10` | `10` | `1.465x` |

这和 `docs/paper/documents/outline.md` 里的 “combination interference” 叙事是同向的：code size 效应可以叠加，但 execution-time 效应不会线性叠加，组合在真实程序上经常变差。

## 3. “Always apply” vs “selective” 对比

### 3.1 同一 full-apply artifact 内部的 oracle selective

如果把 `2026-03-11` full-apply artifact 看成 “always apply all passes”，那么：

- always apply: `92` applied rows，geomean `1.121x`
- oracle selective: 只保留 `29` 个 `exec_ratio <= 1.0` 的 applied rows，geomean `0.849x`

这说明 fixed heuristic 的回归代价不是边角噪声，而是 applied subset 里的主导因素。

### 3.2 Full-apply vs selective authoritative 的 same-program 对齐

把 `2026-03-11` full-apply 和 `2026-03-20` selective 对齐到相同 canonical program 名称后：

- common positive-site programs: `86`
- full-apply geomean on common set: `1.123x`
- selective geomean on common set: `1.018x`
- full-apply regressions on common set: `59`
- selective regressions on common set: `49`

更关键的是 skip 集：

- `60` 个程序在 full-apply 下被改写，但在 selective authoritative 中被跳过
- 这 `60` 个程序在 full-apply 下 geomean 为 `1.105x`
- 同一批 canonical program 在 selective artifact 中 geomean 为 `1.003x`

也就是说，哪怕还不是“真正的 runtime daemon oracle”，仅仅是更保守地不去 blanket apply，也已经几乎把这批 loser 消平了。

### 3.3 代表性 same-program 例子

下面这些例子最能直接支撑 “dynamic/selective > static fixed heuristic”：

| Program | Full-apply | Selective | 解释 |
| --- | ---: | ---: | --- |
| `tracee:tracee.bpf.o:cgroup_skb_ingress` | `1.625x` | `1.000x` | 跳过 `cond_select/extract` 后，明显回归直接消失 |
| `tracee:tracee.bpf.o:cgroup_skb_egress` | `1.444x` | `1.083x` | 同样方向，回归幅度显著收敛 |
| `katran:healthchecking.bpf.o:healthcheck_encap` | `1.889x` | `1.000x` | full-apply 的 pure `cond_select` 回归在 selective 下消失 |
| `calico:to_hep_debug.bpf.o:calico_tc_main` | `1.815x` | `0.973x` | 从显著回归翻到小幅加速 |
| `calico:from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | `1.784x` | `0.972x` | 从强回归翻到近似持平/小赢 |
| `xdp-tutorial:xdp_prog_kern.bpf.o:xdp_redirect_func` | `0.909x` | `2.750x` | selective 仍可能选错 pass；这正说明静态 selective 还不够，runtime-aware dynamic 更有必要 |

这些比较跨了两次 authoritative run，不应被写成严格 A/B 因果实验；但它们非常适合做论文里的定性支撑，因为它们直接展示了“同一个真实程序，是否 blanket apply / 是否跳过某 family，会决定结果符号”。

## 4. Dense-site / I-cache 方向证据

如果按 `sites_applied` 的近似代理 `total_sites` 看 full-apply 最 dense 的 applied 程序：

- top-10 site-heavy applied rows 里有 `9 / 10` 回归
- 这 10 个程序的 geomean 是 `1.233x`
- 明显差于 full-apply applied overall 的 `1.121x`

代表行如下：

| Program | Sites | Exec Ratio | Applied Families |
| --- | ---: | ---: | --- |
| `tracee:tracee.bpf.o:cgroup_skb_ingress` | `121` | `1.625x` | `cond_select, extract, wide_mem` |
| `tracee:tracee.bpf.o:cgroup_skb_egress` | `121` | `1.444x` | `cond_select, extract, wide_mem` |
| `katran:balancer.bpf.o:balancer_ingress` | `34` | `1.182x` | `cond_select, extract, rotate, wide_mem` |
| `calico:from_hep_debug.bpf.o:calico_tc_main` | `33` | `1.075x` | `cond_select, extract, wide_mem` |
| `calico:from_wep_debug.bpf.o:calico_tc_main` | `29` | `1.343x` | `cond_select, wide_mem` |
| `calico:to_hep_debug.bpf.o:calico_tc_main` | `26` | `1.815x` | `cond_select, extract, wide_mem` |

这不能单独证明“就是 I-cache flush 成本”，但它至少提供了和论文叙事一致的方向性证据：当 rewrite 足够密集、多个 family 同时介入时，真实 workload 上更容易出现 locality / layout / interference 代价。

Micro 里也有同向迹象：`mega_basic_block_2048` 在最新 raw snapshot 中 applied `262` 个 `wide_mem+rotate` sites，`754 -> 900 ns`，即 `1.194x` 回归。

## 5. Map Inline 的独特价值与局限

map_inline 不属于最初那几类 kinsn lowering，但它值得单列，因为它体现了“某些 pass 的独特价值不是单次替换本身，而是后续 cleanup cascade”。

### 5.1 Compile-only / structure 价值

`corpus/results/corpus_vm_batch_20260327_141413/details/result.json`：

- program: `katran:balancer.bpf.o:balancer_ingress`
- `map_inline`: `sites_found=64`, `sites_applied=7`, `sites_skipped=57`
- 同次 compile 中还有 `wide_mem=4`、`endian_fusion=2`
- native code: `13645 -> 13584`，减少 `61 B`
- xlated size: `23872 -> 23776`，减少 `96 B`
- 这次没有可比 runtime sample

### 5.2 级联收益很真实，但 runtime 仍可能变差

`runner/corpus/results/vm_corpus_20260327_170425/details/result.json`：

- `map_inline`: `sites_found=107`, `sites_applied=43`, `sites_skipped=64`
- 后续触发 `const_prop` 两轮共 `47` 个 site
- 后续触发 `dce` 两轮共 `90` 个 site
- native code: `13645 -> 12864`，减少 `781 B`
- xlated size: `23872 -> 22672`，减少 `1200 B`
- 但 runtime 是 `1749 -> 2288 ns`，即 `1.308x` 回归

这说明 map_inline 的独特价值是真实存在的：它确实能打开 `map_inline -> const_prop -> dce` 的级联清理链条。但这不等于 blanket enable 就会带来吞吐收益。

### 5.3 Map-inline-only artifact 仍可能强回归

`corpus/results/vm_corpus_20260327_172402/details/result.json`：

- `map_inline`: `sites_found=66`, `sites_applied=2`, `sites_skipped=64`
- native code: `13656 -> 13634`，仅减少 `22 B`
- runtime: `1474 -> 3096 ns`
- `exec_ratio = 2.100x`

也就是说，就算只开 `map_inline`，也并不是 always-win。

### 5.4 关于那个 `2.0x` 提升的 Katran report

`docs/tmp/20260327/katran_map_inline_perf_results_20260327.md` 引用的
`runner/corpus/results/vm_corpus_20260327_152626/metadata.json`
确实记录了 `exec_ratio_geomean = 2.0`（旧口径，表示 `2.0x` speedup）以及 `map_inline` hit。

但这个 artifact 缺少 `details/result.json`，无法像上面两个 detailed artifacts 一样复核 pass details 和 per-program raw sample。因此它可以作为“存在正向个例”的辅助背景，但不应作为本报告的主证据。

### 5.5 Map inline 的结论

- map_inline 的独特价值主要在于打开二次优化链路和代码尺寸收缩。
- 但 runtime profitability 明显不稳定。
- 因此 map_inline 也支持“dynamic > static”，而不是支持“再加一个默认 always-on pass”。

## 6. E2E 与 Static Verify：问题在 profitability，不在 safety

`docs/tmp/20260324/static_verify.full_micro.rerun.json` 的结论很清楚：

- `62 / 62` programs verifier accepted
- `53` programs truly applied
- applied-only 平均 `insn delta = -42.3`
- applied-only 平均 `code delta = -188.3 B`

因此，当前主要矛盾不是“这些 pass 不安全”，而是“它们是否值得在这个 workload 上启用”。

E2E 最新 `2026-03-27` artifacts 没法给出一张像 corpus 那样干净的 per-pass 回归率表，因为：

- Tracee / Tetragon 的最新 artifact 里都有 verifier rejection 或 post-rejit 不可比
- SCX 缺 post-rejit measurement
- Katran 最新 artifact 在 map capture 阶段失败

但 E2E 仍提供两个重要方向证据：

- `docs/tmp/20260327/vm_e2e_perf_passes_results_20260327.md` 表明真实 live workloads 里确实有大量 `cmov/branch-flip/endian/wide` 候选 site，问题不是“corpus 里才有，真实系统里没有”。
- Katran 两个同日 live artifacts
  `e2e/results/katran_e2e_live_20260327_065733_20260327_135738/details/result.json`
  和
  `e2e/results/katran_live_20260327_070135_20260327_140143/details/result.json`
  在同样的静态 site mix 下都枚举到 `wide_mem=4 endian_fusion=2 total=6`，但一个给出 `bpf_speedup_ratio = 1.016x`，另一个给出 `0.988x`。

这点非常有论文价值：即便 static site summary 完全相同，runtime 结果仍可跨过 `1.0x` 的盈亏线。也就是说，static heuristic 本身不携带足够信息。

## 7. 哪些证据最有力地支持 “dynamic > static”

我认为最强的四条证据如下：

1. Full-apply authoritative corpus 直接给出回归占比。
   `92` 个 applied 程序里 `63` 个回归，applied-only geomean `1.121x`。

2. Same-program selective 对齐已经证明“不 blanket apply”有效。
   在 `86` 个 common positive-site 程序上，full-apply `1.123x`，selective `1.018x`；
   对那 `60` 个“后来被 selective 跳过”的程序，`1.105x -> 1.003x`。

3. CMOV 只是最明显的 family，不是唯一会翻车的 family。
   full-apply corpus 中：
   `cond_select` 回归率 `67.1%`，
   `extract` 回归率 `78.4%`，
   `wide_mem` 回归率 `71.8%`。
   selective corpus 中：
   `endian_fusion` 仍有 `65.2%` 回归。

4. Dense-site 和 live E2E 都显示 profitability 依赖 runtime context。
   full-apply top-10 site-heavy rows `9/10` 回归、geomean `1.233x`；
   Katran live E2E 在同一 site mix 下既出现 `1.016x` speedup，也出现 `0.988x` slowdown。

## 8. 结论

现有数据已经足够支撑论文核心论点：固定 kernel peephole / fixed heuristic 在真实 workload 上会导致系统性回归，而“是否应用某 family”必须由更高层的 policy 来控制。

如果只围绕 `cond_select` 讲，论点是成立的，但还不够完整。更强的写法应该是：

- `cond_select` 是最典型的 policy-sensitive family：isolated dense benchmark 能赢，corpus full-apply 大量回归。
- 但不只是 `cond_select`；`extract`、`wide_mem`、`endian_fusion` 也都存在显著回归占比。
- 因此论文不是在为“一个坏 heuristic”辩护，而是在证明“fixed peephole as a class”在真实 workload 上不可靠。
- selective policy 已经能显著减损，runtime-aware daemon policy 只会比它更有信息、更有机会避开这些 loser。

如果要在论文里挑最有说服力的数字，我建议优先引用：

- full-apply applied regressions: `63 / 92 = 68.5%`
- full-apply applied-only geomean: `1.121x`
- common positive-site full-vs-selective: `1.123x -> 1.018x`
- skip set full-vs-selective: `1.105x -> 1.003x`
- pure `extract`: `10 / 10` regress，geomean `1.465x`
- pure `cond_select`: `21 / 34` regress，geomean `1.052x`
