# BpfReJIT Benchmark Framework OSDI Review (2026-03-28)

## 总评

**结论：当前 benchmark framework 还没有达到 OSDI/SOSP 系统论文的评测标准。**

如果我是严格的 OSDI/SOSP 审稿人，我会把当前评测框架判断为：

| 维度 | 判断 | 主要原因 |
| --- | --- | --- |
| 测量方法论 | 不达标 | 缺少实际 CPU pinning / governor / turbo 控制；corpus 主路径没有独立重复实验；daemon 路径不是真正 same-image paired |
| 统计方法 | 不达标 | geomean 正确，但 corpus/E2E 主路径没有 CI、没有显著性检验、没有多重比较修正 |
| Baseline 完整性 | 严重不达标 | 缺少 fixed-kernel peephole baseline；缺少 K2/Merlin/EPSO 对比；llvmbpf 只在 micro 里作为上界出现 |
| E2E 方法论 | 部分达标 | Katran 很强；其余 5 个 case 更像 demonstration，不足以支撑强 quantitative claim |
| 覆盖率与泛化性 | 设计面较强，证据面不达标 | 469 objects / 2009 programs 的目标覆盖面很好，但当前 authoritative corpus artifact 实际只跑到 288 objects / 1149 programs，且只剩 255 个 numeric ratio |
| 可复现性 | 部分达标 | `make vm-*` 和 artifact 保存做得不错，但 corpus/E2E 元数据缺少 publication-grade 的硬件与工具链描述 |
| 整体投稿就绪度 | 不达标 | 现在更像“正在收敛中的 internal framework”，还不是“可以经得起顶会审稿人攻击”的 evaluation stack |

我不会说这个框架“方向不对”。相反，micro/corpus/E2E 三层结构是对的，Katran case 的设计也说明作者知道什么叫好 benchmark。但就 **top-venue 论文的证据强度** 而言，目前最关键的问题是：

1. **corpus 主路径缺少独立重复测量**，`iterations` 配置基本是死的。
2. **环境控制没有真正落地**，只做了 warning，没有实际 pinning / governor / turbo enforcement。
3. **baseline 不完整**，缺少最关键的 falsification baseline。
4. **统计学没有 mainline 化**，micro 辅助脚本里有 CI/Wilcoxon/BH，corpus/E2E authoritative path 却没有。
5. **当前 corpus 证据是 partial 且 crash-truncated**，不够支撑最终论文里的强 coverage/generalization claim。

---

## 审计范围

本次 review 主要基于以下代码和 artifact：

- 计时/runner：`runner/src/kernel_runner.cpp`，`runner/src/batch_runner.cpp`
- 统计与聚合：`runner/libs/statistics.py`，`runner/libs/results.py`，`runner/libs/reporting.py`
- corpus 框架：`runner/libs/corpus.py`，`runner/libs/rejit.py`，`corpus/config/benchmark_config.yaml`，`corpus/modes.py`
- micro 框架：`micro/driver.py`，`micro/config/micro_pure_jit.yaml`，`micro/generate_figures.py`
- E2E 框架：`e2e/case_common.py`，`e2e/cases/{katran,tracee,tetragon,scx,bcc,bpftrace}/case.py`
- 参考文档：`docs/kernel-jit-optimization-plan.md`，`docs/tmp/20260328/corpus_data_statistics_review_20260328.md`，`docs/tmp/20260328/sosp_paper_review_20260328.md`
- 现有结果：`runner/corpus/results/vm_corpus_20260328_194356/metadata.json`，`docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-result-l3_nwgyk.json`，`e2e/results/{katran,tetragon}_authoritative_20260328.json`

---

## 1. 测量方法论

### 当前状态

- `runner/src/kernel_runner.cpp:414-450` 的 kernel 测量主路径不是简单用户态 wall-clock，而是把 `bpf_prog_test_run_opts()` 返回的 `duration` 记为 `exec_ns`，同时额外用 `rdtsc` 估算 `exec_cycles` 和 `wall_exec_ns`。这是正确方向，因为它至少把 syscall 包装层和外部 Python 调度与主指标分开了。
- `runner/src/kernel_runner.cpp:95-214` 显示 `rdtsc` 频率来自两种方法：
  - 优先从 `/proc/cpuinfo` 的 model string 解析 nominal 频率；
  - 否则通过 20ms sleep window 校准。
  这里没有看到 invariant TSC 的显式验证，也没有 cross-check CPU 当前频率状态。
- `runner/src/kernel_runner.cpp:453-489` 显示 warmup 只是先跑 `warmup_repeat` 次，然后正式测一次；没有对多次独立样本做 outlier trimming/winsorization/MAD filtering。
- `runner/src/kernel_runner.cpp:491-499` 显示 kernel-side repeat batching 只对 `SK_LOOKUP` 和 `NETFILTER` 特别支持；其它程序类型更多依赖 helper 层面的 repeat。
- `micro/config/micro_pure_jit.yaml:23-28` 的 micro 默认是 `iterations=10, warmups=2, repeat=200`。这在 micro 层面是合理起点。
- `micro/driver.py:468-485` 会对两个 runtime 做交替顺序（偶数轮 `A->B`，奇数轮 `B->A`），多于两个 runtime 则带 seed shuffle。这一点比很多 systems paper 的 micro harness 更严谨。
- `micro/driver.py:807-889` 会保留每轮 sample，并输出 median/summary，而不是只存最终平均值。这个设计是对的。
- `runner/libs/corpus.py:1546-1741` 的 corpus batch plan 在 baseline 与 rejit 两边都传入相同的 `repeat` 与 `warmup_repeat`，并把 `max_parallel_jobs` 固定为 1。这保证了性能 benchmark 不会相互并发污染，是一个明显优点。
- 但 `runner/libs/corpus.py:1594-1669` 与 `1681-1733` 同时说明 corpus 的 job 排列是 **先 baseline，再 rejit**，固定顺序，没有 reverse-order randomization。
- `runner/src/kernel_runner.cpp:3310-3366` 说明 non-daemon 路径支持 same-image paired measurement：先 stock，再原地 `apply_rejit()`，再测 rejit。
- `runner/src/kernel_runner.cpp:3714-3718` 明确写了 daemon-socket 模式会 **在任何测量之前先应用优化**，并依赖单独的 “kernel runtime” 作为 stock baseline，而不是在同一 image 内先 stock 后 rejit。也就是说，daemon 模式不是严格意义上的 same-image pairing。
- `corpus/config/benchmark_config.yaml:1-48` 的 corpus config 默认是 `iterations=3, warmups=1, repeat=200`，dev profile 则是 `iterations=1, warmups=0, repeat=50`，strict profile 是 `iterations=10, warmups=2, repeat=500`。
- 但 `runner/libs/rejit.py:347-348` 定义了 `benchmark_config_iterations()`，而仓库内搜索结果显示它 **没有在 corpus 主路径被消费**。`rg -n "benchmark_config_iterations\\("` 只有这一处定义。
- 这意味着 corpus mainline 事实上只有 **单次 measured run + 内部 repeat**，而没有真正的独立重复试验。对于顶会来说，这是一个核心 methodological defect。
- 环境控制方面，`runner/libs/environment.py:25-68` 只是做 publication environment validation：
  - governor 不是 `performance` 就 warning；
  - turbo 没关就 warning；
  - 没指定 CPU 就 warning；
  - 只有 `strict=True` 才会 fail。
- `micro/driver.py:85` 暴露了 `--cpu`，文案写的是 “Pin child processes to a specific CPU via taskset”。
- 但仓库搜索结果只在 `micro/driver.py:85`、`micro/driver.py:656`、`micro/driver.py:765` 看到 `args.cpu` 被用于 CLI 和 metadata，没有看到 `taskset` / `sched_setaffinity` 的实际执行。也就是说，**CPU pinning 被声明了，但没有真正实现**。
- 仓库中也没有看到 outlier handling 的实现；至少在 `runner/src`、`runner/libs`、`micro`、`e2e` 这些主路径里没有相应逻辑。

### 是否达到 OSDI/SOSP 标准

**不达标。**

更细一点说：

- **micro 层面**：接近达标，但还差最后几步。
- **corpus 层面**：明显不达标。
- **E2E 层面**：只有 Katran 接近，整体不达标。

### 主要缺口

- **缺少真正的独立重复实验**。`repeat` 只能降低单次计时量化误差，不能替代 `N` 个独立试验。顶会审稿人会直接问：你给我的 ratio 是 50 次 loop inside one run，还是 10 次独立 paired runs？
- **CPU pinning 是“说了但没做”**。这在审稿里是危险信号，因为 reviewer 一旦发现 CLI/metadata 声称 pinning，但代码并没有 `taskset`/`sched_setaffinity`，可信度会明显下降。
- **环境稳定化没有真正 enforce**。warning-only 对 internal debugging 足够，但不够支撑 paper artifact。
- **daemon 测量不是严格 same-image paired**。对于 post-load framework，这一点尤其敏感；审稿人会问是否 frequency drift、cache warmth、allocator state、background noise 影响了 baseline/rejit 非对称性。
- **没有 outlier policy**。没有 outlier policy 不一定致命，但如果你报告亚微秒甚至几十纳秒级别改善，又没有 pinning/governor/turbo/outlier 处理，可信度会迅速下降。
- **当前大规模 corpus artifact 用的是 dev profile**。`runner/corpus/results/vm_corpus_20260328_194356/metadata.json:1028-1040` 对应的 run 最终崩溃，且 profile 是 dev；而 dev 的 config 是 `warmups=0, repeat=50`。这绝对不能作为 paper-authoritative corpus 数据。

### 修复建议与优先级

- **P0**：把 corpus 主路径改成真正的 `iterations` 次独立 paired trials，并把每次 baseline/rejit 原始样本保留下来。没有这个，corpus 不应进论文主结果。
- **P0**：真正实现 CPU affinity。要么在 runner 进程层面用 `sched_setaffinity()`，要么对子进程统一用 `taskset` 包装；不能只在 CLI 和 metadata 里写。
- **P0**：把 publication profile 设为 hard requirement。对于最终数据，governor 不在 `performance`、turbo 未关、未 pin CPU 时应直接失败，而不是 warning。
- **P1**：给 daemon path 增加真正的 paired design。理想做法是同一 live image 上执行 stock->apply->rejit，或者显式支持 reverse-order cross-over；否则要在论文中降调为 “quasi-paired with separate stock runtime baseline”。
- **P1**：定义明确的 outlier policy。可以是 median-of-iterations + IQR/MAD 报告，不一定要 aggressively trim，但必须事先写清楚。
- **P2**：如果要保留 sub-100ns 级数字，最好增加 measurement floor 校准与 baseline subtraction 说明，否则 reviewer 很容易说 “numbers too small to trust”。

---

## 2. 统计方法

### 当前状态

- `runner/libs/statistics.py:18-22` 的 `geometric_mean()` 数学上是正确的：只对正值做 `log-mean-exp`。
- `runner/libs/statistics.py:25-72` 的 `ns_summary()` / `float_summary()` 只提供 `count / mean / median / min / max / p95 / stdev`。这是 descriptive statistics，不是 inferential statistics。
- `runner/libs/results.py:232-370` 的 corpus summary 结构比较清楚，区分了：
  - `compile_pairs`
  - `measured_pairs`
  - `comparable_pairs`
  - `applied_comparable_pairs`
  - `applied_programs`
- `runner/libs/results.py:289-357` 同时计算了：
  - `exec_ratio_geomean`：只对 `applied_comparable_pairs`
  - `all_exec_ratio_geomean`：对全部 `comparable_pairs`
  这一点本身是优点，因为它至少试图区分 “apply 了且可比” 与 “全部可比”。
- 但 `docs/tmp/20260328/corpus_data_statistics_review_20260328.md:16-21` 与 `:110-132` 明确指出，当前 partial corpus run 里：
  - `measured_pairs = 483`
  - 真正进入 geomean 的 `numeric speedup_ratio` 只有 `255`
  - applied-only numeric 只有 `170`
  如果论文只写 “483 measured pairs”，而 geomean 实际分母是 255 或 170，会被 reviewer 认为 denominator 不透明。
- `runner/libs/results.py:257-260` 以及审计文档 `docs/tmp/20260328/corpus_data_statistics_review_20260328.md:18` 还表明 `applied_programs` 的语义是 `applied_passes` 非空，而不是简单的 `rejit.applied == true`。这很容易在论文写作时被误报。
- `runner/libs/reporting.py:140-203` 已经有 bootstrap CI：
  - `bootstrap_geometric_mean_ci()`
  - `bootstrap_ratio_ci()`
- `runner/libs/reporting.py:479-520` 的 RQ report 也会把 CI 带进 group-level statistics。
- `micro/generate_figures.py:241-290` 实现了 paired Wilcoxon signed-rank test。
- `micro/generate_figures.py:277-290` 和 `:384-395` 实现了 Benjamini-Hochberg adjusted p-values，并把显著性标签绑定到 benchmark record。
- 换言之：**统计学工具本身在 repo 里已经存在**，但它们主要留在 micro figure generation / reporting side path，而不是 corpus/E2E authoritative result path。
- `e2e/case_common.py:435-480` 只提供 `summarize_numbers()`、`percent_delta()`、`percentile()`、`speedup_ratio()` 等 helper；没有 CI，也没有 hypothesis test。

### 是否达到 OSDI/SOSP 标准

**不达标。**

当前状态更准确的描述是：**有统计学部件，但没有把它们主线化、制度化。**

### 主要缺口

- **corpus/E2E 主路径没有 CI**。顶会里，如果给 geomean/median/speedup 但没有 error bar 或 CI，几乎一定会被点名。
- **corpus/E2E 主路径没有显著性检验**。micro figure 脚本里有 Wilcoxon，但 authoritative summary 没有。
- **没有 multiple-comparison correction**。一旦你在 62 个 micro benchmarks 或多类 E2E workload 上逐个做显著性标记，不做 BH/Bonferroni 会被 reviewer 追问。
- **sample size 报告不统一**。有些地方有 count，有些地方只有 geomean，没有明确 “N 是多少、paired N 是多少、numeric N 是多少、applied-only N 是多少”。
- **applied vs non-applied 的口径容易混淆**。当前代码可以区分，但论文非常容易把 `applied_programs`、`applied_comparable_pairs`、`rejit.applied` 混写。

### 修复建议与优先级

- **P0**：把 CI 集成到 corpus/E2E 主结果 pipeline。最小要求是：
  - micro：每个 benchmark 的 paired CI 或至少 group-level bootstrap CI；
  - corpus：overall geomean、按 repo/prog_type geomean 附 CI；
  - E2E：主要指标附 CI 或至少 repeated paired samples distribution。
- **P0**：把 paired Wilcoxon 或 permutation test 集成到 corpus/E2E 的 paired results 上。对成千上百个 program，Wilcoxon signed-rank 是自然选择。
- **P0**：所有主图主表统一报告 `N`。至少要显式写：
  - selected
  - compile-success
  - measured
  - comparable
  - applied-comparable
- **P1**：对多 benchmark 的显著性标记加 BH correction。仓库里已有实现，应该直接复用。
- **P1**：在结果表中强制区分：
  - `all comparable`
  - `applied-only`
  - `changed-program-only`
  并在 caption/legend 里写清楚口径。

---

## 3. Baseline 完整性

### 当前状态

- **stock kernel JIT** 作为 primary baseline 是合理且公平的。对于一个 post-load dynamic optimization framework，这是最自然的 baseline。
- `docs/kernel-jit-optimization-plan.md:340-346` 明确列出了论文所需 baselines：
  1. Stock kernel JIT
  2. fixed kernel peephole baseline
  3. advisor-static
  4. advisor-profiled
  5. llvmbpf 上界
- `docs/kernel-jit-optimization-plan.md:165` 还写了一个非常关键的原则：如果 fixed kernel heuristics 在所有测试硬件和 workload 上恢复相同收益，正确结论应该是“去做 kernel peepholes”，而不是发布 userspace-guided interface。
- `docs/kernel-jit-optimization-plan.md:871-873` 显示当前仍然待做：
  - task 494：fixed kernel peephole baseline 对比
  - task 496：K2/Merlin/EPSO head-to-head
- `docs/tmp/20260328/sosp_paper_review_20260328.md:26-34` 已经把这两点明确列为 major weakness。
- llvmbpf 作为上界参考在 micro 世界里是存在的：
  - `micro/config/micro_pure_jit.yaml:27` 默认 runtime 就包含 `llvmbpf`
  - `micro/generate_figures.py:363-395` 也在做 `llvmbpf` vs `kernel` 的统计整理
- 但 llvmbpf 当前更像 **micro characterization upper bound**，不是 corpus/E2E 的统一 baseline。

### 是否达到 OSDI/SOSP 标准

**严重不达标。**

这不是“小缺一个 baseline”，而是缺了 **最能 falsify 论文核心论点** 的 baseline。

### 主要缺口

- **没有 fixed kernel peephole baseline**。这是最大的缺口。没有它，你无法证明 “userspace policy separation + post-load interface” 真的是必要的。
- **没有 K2/Merlin/EPSO 对比**。如果论文 claim 自己相对 prior art 的增量是 “post-load + runtime-guided + transparent”，那就必须 head-to-head。
- **没有把 llvmbpf 上界贯通到全部评测故事**。如果 llvmbpf 只出现在 micro，而 corpus/E2E 只和 stock kernel 比，审稿人会说你没有把 “理论上界/编译上界” 接回真实工作负载。

### 修复建议与优先级

- **P0**：补 fixed kernel peephole baseline。这是 submission blocker。
- **P0**：补至少一个 prior-work baseline。理想是 K2 + Merlin/EPSO；最少也要有可复现、可公平比较的一个代表。
- **P1**：把 llvmbpf 定位写清楚：
  - 若是 micro 上界，就只在 micro 用，但必须在论文中明确“不是 apples-to-apples deployable baseline”；
  - 若要作为 general upper bound，就要扩展到 corpus 子集或 representative subset。
- **P2**：如果 fixed-kernel baseline 最终吃掉了大部分收益，那论文故事必须重构，转向“runtime-only passes / deployment-time specialization / transparency benefits”，而不是继续硬讲 framework 必要性。

---

## 4. E2E 方法论

### 当前状态

- `e2e/case_common.py:283-399` 把所有 E2E case 的 shared lifecycle 固化为：
  1. setup
  2. start
  3. optional pre-baseline
  4. baseline workload
  5. optional after-baseline
  6. scan + daemon apply
  7. post-ReJIT workload
  8. stop + cleanup

这套骨架本身是合理的，也保证了 before/after 的工作流一致。

#### Katran

- `e2e/cases/katran/case.py:75-90` 设定了明确的 `duration=10s`、`sample_count=3`、`warmup_duration=2s`、`warmup_packet_count=100`、`min_measurement_requests=1000`。
- `e2e/cases/katran/case.py:1772-1811` 实现了真正的 warmup-with-retry，而不是只 sleep 一下。
- `e2e/cases/katran/case.py:1814-1917` 测的是真实应用级指标：
  - 请求数/成功数
  - measurement duration
  - latency data
  - system CPU
  - BPF runtime delta
  - packet path counters
  并且当请求数为 0、成功率过低、没有包、没有 BPF runtime events 时会直接 fail。这是 publication-grade design 的样子。
- `e2e/cases/katran/case.py:2033-2255` 在同一个 live image 上做 repeated same-image paired cycles，再汇总到 `baseline` / `post_rejit` summary。
- `e2e/results/katran_authoritative_20260328.json:17679-17680` 也显示最终 artifact 记录了 `same_image_measurement=true` 与 `sample_count=3`。
- 唯一明显缺口是 `e2e/cases/katran/case.py:2021-2023` 已自承 phase order 仍是 stock then rejit，没有 reverse-order randomization。

#### Tracee / Tetragon / SCX / BCC / bpftrace

- `e2e/cases/tracee/case.py:982-1063` 是一轮 baseline + 一轮 post-rejit，带 optional preflight，但没有 repeated paired cycles。
- `e2e/cases/tetragon/case.py:948-1027` 也是单轮 lifecycle；`e2e/cases/tetragon/case.py:998-1000` 还明确承认 `events_total` / `events_per_sec` 来自 aggregate BPF run_cnt delta，不是一对一 application operation 指标。
- `e2e/cases/scx/case.py:489-530` 的比较基本是 percent delta over throughput/latency/context switches/agent CPU；`718-789` 也是单次 baseline/post。
- `e2e/cases/bcc/case.py:373-519` 和 `e2e/cases/bpftrace/case.py:396-480` 都是 “每个 tool/script 跑一次 baseline，再 apply，再跑一次 post”。这是可以工作，但统计上很弱。
- `e2e/cases/bcc/case.py:526-569` 与 `e2e/cases/bpftrace/case.py:483-549` 只做 geomean/percent delta 汇总，没有 CI/significance。

#### Daemon overhead

- `runner/libs/rejit.py:1002-1125` 的 daemon apply 返回的是 `applied`、`per_program`、`counts`、`error`，没有结构化的 scan/apply latency。
- 因此当前 E2E payload 里没有把 daemon overhead 作为 first-class metric 系统化报告。

#### Host provenance

- `e2e/case_common.py:420-428` 的 `host_metadata()` 只有：
  - hostname
  - platform
  - kernel
  - python
  - git_sha
- `e2e/results/tetragon_authoritative_20260328.json:286-299` 与 `e2e/results/katran_authoritative_20260328.json:651-656` 也说明最终 artifact 的 host block 很弱。

### 是否达到 OSDI/SOSP 标准

**整体不达标，但 Katran 单独接近达标。**

如果 paper 现在的叙事是 “6 个真实应用都做了 publication-grade E2E evaluation”，我不会接受。

更准确的判断是：

- **Katran**：可以进入主结果。
- **Tracee/Tetragon/SCX/BCC/bpftrace**：更像 supporting case studies / demonstrations，不够做强 quantitative claim。

### 主要缺口

- **E2E methodological quality 不均衡**。一个强 Katran 和五个弱 case 不能自动平均成“六个强 case”。
- **多数 case 缺少 repeated paired trials**。
- **多数 case 没有 CI/显著性分析**。
- **daemon 开销没被系统化测量**。对 post-load optimizer，这是 reviewer 一定会问的点。
- **before/after 大多是固定顺序 stock->rejit**，没有 order randomization，也没有跨 cycle restore-to-stock。
- **host metadata 太弱**，不够支撑 artifact reproducibility。

### 修复建议与优先级

- **P0**：不要把 6 个 E2E 都包装成同样强度的 quantitative benchmark。更现实的 paper 结构是：
  - 1 个最强 case（Katran）做 fully quantitative；
  - 1 到 2 个中等 case（如 Tracee/Tetragon）做 repeated paired quantitative；
  - 其余作为 qualitative/feasibility/supporting case study。
- **P0**：至少再把 Tracee 或 Tetragon 提升到 Katran 的方法学水平：warmup、sample_count、same-image repeated cycles、CI。
- **P1**：把 daemon scan/apply overhead 纳入 E2E payload，最少报告：
  - scan latency
  - apply latency
  - programs scanned
  - programs changed
- **P1**：若无法实现 reverse-order randomization，就在论文中明确承认 fixed phase order，并解释为什么 paired same-image cycles 足以缓解主要风险。
- **P2**：把真实应用指标优先级排清楚。每个 E2E 至少要固定三类主指标中的两类：
  - throughput
  - latency tail
  - error/drop rate
  当前有些 case 还是太依赖 BPF runtime delta 本身。

---

## 5. 覆盖率和泛化性

### 当前状态

- 从框架设计和 corpus manifest 来看，覆盖面是这套 benchmark 的强项之一。
- `runner/corpus/results/vm_corpus_20260328_194356/metadata.json:3748-3753` 显示本次 selected corpus 的目标规模是：
  - `469 objects`
  - `2009 programs`
- `docs/tmp/20260328/corpus_data_statistics_review_20260328.md:92-132` 说明当前 partial dev run 的运行漏斗是：
  - selected / build-available：2009 programs
  - completed before crash：1149
  - compile pairs：648
  - measured pairs：483
  - numeric `speedup_ratio`：255
  - applied + numeric：170
- `runner/corpus/results/vm_corpus_20260328_194356/metadata.json:1007-1011` 和 `:1031-1040` 还明确显示当前 authoritative artifact 是 **crash-truncated** 的：
  - `returncode=139`
  - `completed_objects=288 / total_objects=469`
  - `completed_programs=1149 / total_programs=2009`
- `docs/tmp/20260328/corpus_data_statistics_review_20260328.md:90-106` 还指出 selection/build gate 当前是 **availability-based**，不是严格的 fresh-build-only。这不是绝对错误，但需要透明汇报，否则 reviewer 会问 selection bias。

基于本次额外复算，selected corpus 的组成总体上是合理的，不是明显人为 cherry-pick：

- repo 维度同时覆盖了 `linux-selftests`、`bcc`、`tracee`、`xdp-tools`、`tetragon`、`scx`、`KubeArmor`、`calico`、`coroot-node-agent` 等。
- prog_type 维度覆盖了 `kprobe`、`tracing`、`sched_cls`、`tracepoint`、`raw_tracepoint`、`xdp`、`lsm`、`struct_ops`、`syscall` 等。
- workload category 大致覆盖了 networking / observability / security / resource-control / selftests。

但 reviewer 关心的不是“manifest 看起来全”，而是“**最终 paper 中真正 measured/comparable 的集合是否仍然全**”。这里当前证据明显不够。

### 是否达到 OSDI/SOSP 标准

**设计面接近达标，证据面不达标。**

### 主要缺口

- **当前没有完整跑完 469/2009 的 authoritative corpus artifact**。这一点足以阻止强 coverage claim。
- **comparable funnel 掉得太多**。从 2009 到 255 numeric ratio，审稿人会立即问：
  - 掉的是哪些 repo？
  - 掉的是哪些 prog_type？
  - 是否系统性偏向了对 BpfReJIT 更有利的程序？
- **selection bias 解释还不够强**。availability-based build gate + existing/prebuilt objects 的存在，会让 reviewer 问“是不是只保留了更容易测的对象？”
- **program-weighted geomean 会掩盖 object-level variance**。`docs/tmp/20260328/corpus_data_statistics_review_20260328.md:16-18` 与 `:260-263` 已指出当前 overall geomean 是 program-weighted，而不是 object-weighted。这本身不是错，但论文必须说清楚。

### 修复建议与优先级

- **P0**：先把 full corpus 跑完，再谈论文。没有完整 authoritative run，不应写“469 objects / 2009 programs measured”。
- **P0**：对最终 corpus 主结果强制报告完整 funnel：
  - selected
  - build-available
  - compile-success
  - runtime-eligible
  - measured
  - numeric comparable
  - applied-comparable
- **P0**：按 `repo`、`prog_type`、`category` 给出 coverage table，至少报告 measured/comparable/applied-comparable 三个分母。
- **P1**：同时报告 program-weighted 和 object-weighted aggregation，避免 reviewer 指责“大 object 权重过高”。
- **P1**：对 exclusion reasons 做 top-k breakdown，并区分：
  - measurement unsupported
  - attach did not fire
  - exec_ns=0
  - prepare/load failure
- **P2**：如果某些 prog_type 基本不可测，应该在论文里把 claim 收敛到“适用于 XXX families”，而不是继续讲 general eBPF corpus。

---

## 6. 可复现性

### 当前状态

- 好的一面：
  - repo 有比较清晰的一键入口：`make vm-micro`、`make vm-corpus`、`make vm-e2e`。
  - micro/corpus/E2E 都有 artifact session / structured JSON 输出，不是只靠 stdout。
  - `micro/driver.py:650-681` 的 host metadata 相对完整，包含 kernel cmdline、governor、turbo、perf_event_paranoid、toolchain root、git SHA 等。
- 不足的一面：
  - `corpus/modes.py:552-573` 与 `:596-624` 的 result/metadata 没有 publication-grade host block；主要是路径、binary、profile、summary，没有 CPU 型号/核数/内存/频率策略/编译器版本。
  - `e2e/case_common.py:420-428` 的 host metadata 过于简陋。
  - `e2e/results/katran_authoritative_20260328.json:651-656` 与 `e2e/results/tetragon_authoritative_20260328.json:288-293` 也验证了最终 E2E artifact 只有 hostname/platform/kernel/python/git_sha。
  - `docs/tmp/20260328/sosp_paper_review_20260328.md:58-59` 已经点名当前 paper setup 描述过于粗糙，像 “Recent x86-64 workstation-class CPU” 这样的表述不符合系统论文复现标准。

### 是否达到 OSDI/SOSP 标准

**部分达标，但还不够。**

框架层面已经有 artifact 意识；论文层面还没有 publication-grade reproducibility discipline。

### 主要缺口

- **缺少 exact CPU model、核心数、SMT 状态、内存容量、频率策略、turbo 状态、kernel config 摘要、clang/LLVM version、bpftool/libbpf version**。
- **micro / corpus / E2E 三层 metadata 不统一**。micro 相对完整，corpus/E2E 明显弱。
- **缺少环境 fingerprint 的统一 schema**。这会导致 cross-layer 结果难以核对。

### 修复建议与优先级

- **P0**：定义统一的 publication metadata schema，三层 benchmark 全部写入：
  - CPU model
  - sockets/cores/threads
  - SMT on/off
  - memory size
  - governor
  - turbo state
  - kernel release + git SHA/config hash
  - clang/LLVM/bpftool/libbpf versions
  - daemon/runner git SHA
- **P1**：把 micro 已有的 host metadata 机制下沉到 corpus/E2E 共用库。
- **P1**：对每个 authoritative artifact 记录 exact command line 与 profile。
- **P2**：如果论文最终包含远程 ARM64 或多平台数据，必须把平台信息同样结构化保存，而不是只在 caption/正文里口述。

---

## 7. 常见 OSDI/SOSP Reviewer 攻击点

### 7.1 “Cherry-picked benchmarks”

**当前风险：中高。**

正面因素：

- manifest 设计并不窄，覆盖 repo/prog_type/category 比较广。

负面因素：

- 当前 authoritative corpus 只完成了 288/469 objects；
- 真正进 exec geomean 的只有 255 个 numeric ratios；
- build gate 是 availability-based，不是 strict fresh-build-only；
- linux selftests 与 tracing-family 占比高。

如果论文直接写 “we evaluate on 2009 real programs”，而不把完整 funnel 和 exclusions 公开，我会认为作者在模糊 selection bias。

### 7.2 “Unfair baseline”

**当前风险：极高。**

这是当前最危险的 reviewer 攻击点。

- 没有 fixed kernel peephole baseline；
- 没有 prior-work head-to-head；
- llvmbpf 只在 micro 里出现。

只和 stock kernel 比，在系统审稿语境里远远不够。

### 7.3 “Insufficient statistical rigor”

**当前风险：极高。**

- corpus/E2E 主路径没有 CI；
- 没有显著性检验；
- 没有多重比较修正；
- 多个 case 实际只有 single baseline + single post。

这会被直接评价为 “numbers without statistical support”。

### 7.4 “Numbers too good to be true” / “numbers too small to matter”

**当前风险：高。**

- micro 里如果出现几十纳秒级差异，而又缺少真实 pinning/governor/turbo control，reviewer 很容易不信。
- 反过来，如果 corpus overall geomean 接近 1.0x，而 applied-only 改善不大，reviewer 也会说 “small effect size, practical significance unclear”。

因此现在同时暴露在两个方向的攻击下：既可能被说“太小不重要”，也可能被说“太小却测不准”。

### 7.5 “Evaluation doesn’t support claims”

**当前风险：极高。**

如果论文 claim 是：

- transparent post-load optimization is broadly effective
- benefits generalize across 2009 programs
- end-to-end wins hold across 6 real applications

那当前证据明显还不够。

更安全的当前 claim 上限应该是：

- micro 说明 framework 能在合成模式上恢复部分 codegen gap；
- corpus 说明框架具有广覆盖潜力，但 full evidence 仍在收敛；
- Katran 说明真实应用场景下确实可能得到 measurable end-to-end benefit。

### 7.6 “No error bars / no confidence intervals”

**当前风险：极高。**

micro 辅助脚本里虽然已经有 CI，但只要最终论文主图主表没有 error bars / CI，这条攻击仍然成立。

### 7.7 “Measurement methodology not described”

**当前风险：中高。**

代码里其实已经有不少 methodology 逻辑，但它们还没有收敛成能让 reviewer 一眼放心的方法学叙述。尤其以下几点如果不在 paper 中明确写出，会被认为 methodology 不充分：

- `exec_ns` 来自哪里；
- `repeat` 与 `iterations` 的区别；
- paired 还是 quasi-paired；
- warmup policy；
- CPU pinning/governor/turbo policy；
- outlier policy；
- CI / significance policy；
- denominator policy（selected vs measured vs comparable vs applied）。

---

## 分层结论

### Micro benchmark（62 synthetic programs）

**判断：接近可发表，但还需要方法学补强。**

优点：

- timing path 不算粗糙；
- per-iteration sample 保存完整；
- runtime order 做了 counterbalancing；
- 已有 bootstrap CI / Wilcoxon / BH 实现；
- llvmbpf upper bound 叙事较完整。

缺点：

- CPU pinning 没真正落地；
- env control 是 warning-only；
- 如果要打几十纳秒级结果，当前 methodology 还不够硬。

### Corpus benchmark（469 objects / 2009 programs）

**判断：当前明确不达标。**

主要原因：

- `iterations` 没进入 mainline；
- 当前 authoritative run 是 dev profile、warmup 过弱、repeat 过小；
- run 没跑完且崩溃；
- CI/significance 缺失；
- coverage funnel 尚不足以支撑强 generalization claim。

### E2E benchmark（6 apps）

**判断：不均衡，不能整体按同一强度 claim。**

- Katran：强，可以做主结果。
- Tracee/Tetragon：需要再强化，才能成为主结果。
- BCC/bpftrace/SCX：目前更适合作 supporting case study。

---

## 优先级行动清单

### P0：投稿前必须完成

1. **把 corpus 改成真正的独立 repeated paired trials。**
2. **实现真实 CPU pinning，并对 governor/turbo 做 hard enforcement。**
3. **补 fixed kernel peephole baseline。**
4. **补至少一个 K2/Merlin/EPSO prior-work 对比。**
5. **把 CI + paired significance test 集成到 corpus/E2E 主路径。**
6. **跑完完整 469/2009 corpus authoritative run，且不能 crash。**
7. **给最终 paper 结果统一报告完整 funnel 和 sample size。**

### P1：强烈建议完成

1. 再把 Tracee 或 Tetragon 提升到 Katran 级别的方法学强度。
2. 系统化测量 daemon scan/apply overhead。
3. 统一 micro/corpus/E2E 的 publication metadata schema。
4. 同时报告 program-weighted 和 object-weighted corpus aggregation。

### P2：有助于进一步减小 reviewer 攻击面

1. reverse-order / cross-over measurement 设计。
2. measurement floor / harness overhead subtraction 说明。
3. llvmbpf upper bound 向 corpus representative subset 延伸。
4. 如果论文保留 multi-platform claim，补 ARM64 publication-grade data。

---

## 最终审稿判断

如果今天把这套 benchmark framework 放进 OSDI/SOSP 投稿，我的判断会是：

**Reject / Not evaluation-ready.**

不是因为框架设计差，而是因为它已经具备顶会评测的骨架，却还缺少几项最关键的“硬证据”：

- corpus independent repetitions
- 真正的环境控制
- 完整 baseline
- mainline 统计学
- 完整且未截断的 corpus authoritative result

一旦把这些补齐，这套评测框架是有潜力进入 top-venue 标准线的。尤其是：

- micro 层已经有不错的基础；
- Katran case 已经证明作者能做高质量 E2E；
- corpus 的覆盖设计也确实有野心。

但在当前状态下，**benchmark framework 还不能支撑论文里的强 claim**。如果强行投稿，最可能被打回来的点不是 implementation，而是 evaluation methodology。
