# BPFOptBench 评估章节草稿（中文）

Last updated: 2026-06-22

本文件把现有数据整理成论文 Evaluation section 的叙事形式。它的定位是
“可写进论文的评估骨架”，不是最终实验结果表。已经有数据支撑的部分用
“现有结果显示”；还没有跑完的部分明确标注为“待完成实验”。

## 5. Evaluation

本节评估 BPFOptBench 是否能把 eBPF 优化变成一个可度量、可复现、可比较的
agent benchmark。我们的目标不是证明某一个 eBPF pass 已经稳定带来性能收益，
而是回答一个更基础的问题：当 agent 面对真实 verifier、JIT、应用启动和 workload
反馈时，benchmark 是否能区分有效优化、无效优化、噪声追逐和 benchmark 作弊。

我们围绕六个问题组织评估：

- **RQ1：任务覆盖。** BPFOptBench 能否表达真实 eBPF 优化任务，而不是只覆盖
  一个固定 pass 或一个 kop 后端？
- **RQ2：难度来源。** 现有数据是否说明 eBPF 优化不是简单的静态 pass 选择问题？
- **RQ3：组合 oracle。** verifier 接受是否足够？还是必须同时检查 app、workload、
  performance 和 benchmark integrity？
- **RQ4：agent 表现。** 在相同预算下，agent 是否优于 no-op、静态策略、随机搜索和
  human-tuned 策略？
- **RQ5：反馈格式。** 结构化反馈是否比 raw log 或 one-shot prompt 更能帮助 agent
  做出有效决策？
- **RQ6：后端依赖。** benchmark 是否依赖 kop/kprog，还是 bytecode-only 任务也能
  形成有意义的评测？

当前已有数据主要支撑 RQ1-RQ3 的动机和可行性；RQ4-RQ6 需要 frozen task set 和
agent runs 后才能形成最终结论。

## 5.1 Experimental Setup

### Workloads

BPFOptBench 的第一版评估以现有 macro corpus 为主，使用真实应用启动路径加载 BPF
程序，而不是在 benchmark 框架中直接加载 `.bpf.o`。当前支持的六个 macro apps 是：

| App | 角色 |
|---|---|
| `bcc/set` | tracing-style BPF workloads |
| `tracee/monitor` | security tracing workload |
| `tetragon/observer` | tracing and policy workload |
| `katran` | XDP/load-balancing workload |
| `cilium/agent` | networking/control-plane workload |
| `otelcol-ebpf-profiler/profiling` | profiler workload with tail-call-heavy paths |

最新检查的 v3 raw run 是
`corpus/results/x86_kvm_corpus_20260622_190658_322856/details/result.json`。
该 run 成功覆盖六个 app，`samples=1`，`workload_seconds=5.0`，所有 app 的
`rejit_result.mode` 是 `native_loader`，`enabled_passes=[]`。因此它证明当前 runner
能产出六 app raw payload，但它不是优化结果，因为没有启用 pass。

### Artifact Corpus

我们扫描了 `corpus/results/*/details/result.json`：

| 项目 | 数量 |
|---|---:|
| `details/result.json` 文件 | 1535 |
| raw-only v3-style result | 799 |
| legacy/mixed schema result | 736 |
| `status=ok` | 938 |
| `status=error` | 588 |

这些 artifact 说明本仓库已经有足够的历史运行材料来构建 benchmark 任务和难度研究。
但由于 schema 迁移、历史 run 配置不完全一致，以及旧 artifact 中包含现在不允许放在
framework 内的 summary 字段，最终论文数字必须来自 post-hoc analysis，而不是框架内聚合。

### Metrics

BPFOptBench 不应只报告一个 leaderboard scalar。eBPF 优化有多层失败边界，因此我们
报告分解指标：

| Metric | 定义 | 作用 |
|---|---|---|
| Validity rate | verifier 接受且未违反 benchmark policy 的 attempt 比例 | 衡量 eBPF 安全可行性 |
| Workload success rate | app lifecycle 和 workload 检查成功的 attempt 比例 | 防止 fast-but-broken |
| Performance success rate | workload 成功后，性能超过阈值或 noise gate 的比例 | 衡量有用优化 |
| `bpfopt_success_p` | verifier/app/workload 全部通过，且速度超过 baseline 至少 `p` 的任务比例 | 严格成功率 |
| Geomean ratio | 保留程序上的 post/base per-program runtime ratio；越低越好 | 对齐现有 corpus 方法 |
| Regret | 与同任务 best-known valid action 的差距 | 区分搜索质量和 pass 本身质量 |
| Cost | attempts、wall-clock、tokens、benchmark runs | 防止 brute force 被免费计入 |
| Integrity failure rate | workload 修改、run budget 改动、loader 绕过、结果伪造等无效行为比例 | 衡量 reward hacking |

性能数字必须在 analysis side 计算：跳过 `run_cnt_delta == 0` 的程序，要求两阶段
`min_runs >= 100`，计算 `post_avg_ns_per_run / baseline_avg_ns_per_run`，再报告
per-program geomean 和 win/loss/tie。tail-called program 的收益必须归因到直接 attached
caller，不能把 tail target 的 `run_cnt=0` 解释为没有运行。

### Baselines

第一版评估应至少包含这些 baseline：

| Baseline | 用途 |
|---|---|
| No-op | 没有优化，提供任务自然 baseline |
| Noop ReJIT | 控制 ReJIT 本身和测量扰动 |
| Static policy | 当前默认 pass 组合或全量 pass 组合 |
| Random/grid | 相同 attempt budget 下的盲搜索 |
| Human-tuned policy | 基于历史分析的专家策略 |
| Oracle best-known | 每个任务观察到的最佳 valid action，仅用于计算 regret |

Agent variants 应从三种最小对比开始：one-shot raw-log prompt、one-shot structured-feedback
prompt、closed-loop agent。

## 5.2 RQ1: Can BPFOptBench Express Real eBPF Optimization Tasks?

BPFOptBench 的任务不应绑定到某一个 optimizer implementation。任务接口需要表达：

1. action space：pass list、per-app policy、per-program policy、per-site gating、profile-guided
   decision；
2. feedback：verifier log、app status、workload raw metrics、BPF counter deltas、pass reports；
3. oracle：verifier acceptance、app success、workload semantic success、performance threshold、
   integrity checks；
4. provenance：base commit、task manifest、allowed knobs、agent action trace、result path。

现有数据说明这个方向可行。v3 raw result 已经能记录 per-app payload 和 raw counters；
历史 docs 中也有足够多的 policy、noise、pass-signal 分析，可以转化为 seed tasks。
但是最终论文还需要一个 frozen task manifest。推荐第一版任务规模是：

| 规模 | 可支撑说法 |
|---|---|
| 15-25 tasks | vertical-slice testbed |
| 30-50 tasks | workshop benchmark paper |
| 80-150 tasks | 更成熟的 standalone benchmark claim |

当前最合理的第一步是 20-50 个 expert-audited seed tasks，并且每个任务带 hidden evaluator。

## 5.3 RQ2: Why Is Agentic eBPF Optimization Hard?

现有历史数据已经可以支撑一个强动机：eBPF 优化的困难不是 pass 不够多，而是反馈和评价
高度不稳定。

### No-op Floor Shows Measurement Perturbation

`docs/tmp/pass_signal_audit_20260508.md` 记录了两个关键 floor：

| Run | Retained Programs | Method B Ratio | W/L/T |
|---|---:|---:|---|
| noop ReJIT floor, `x86_kvm_corpus_20260507_190554_205137` | 147 | 0.9019 | 73/74/0 |
| noop SKIP_REJIT floor, `x86_kvm_corpus_20260508_000244_131324` | 147 | 0.8587 | 75/72/0 |

两个 floor 的 suite-level 差异是 `0.0431`。更重要的是，app 间 noise 不均匀：
`bcc/set` 和 `cilium` 相对稳定，而 `otel`、`tetragon` 的区间明显更宽。这个结果直接说明，
如果没有 no-op floor 和 noise gate，agent 很容易把系统扰动误判为优化收益。

### Rewrite Count Does Not Predict Speedup

同一份 pass-signal audit 显示：完成的单 pass run 中，没有一个 pass 具备
paper-ready 的稳定收益。`map_inline` 在一个早期 7-app run 中对 OTEL 有强 signal
（app-level `B=0.6567`，`applied=1192`），但在后续命名 run 中没有复现到足够强的
paper-grade 结论。combined kop run 也出现 OTEL 低 ratio，但 single-pass ablation
无法把收益归因到具体 pass。

这说明 benchmark 不能只看 `applied` 数量。agent 的任务不只是“找到可应用 rewrite”，
而是“判断 rewrite 是否真的跨过 verifier、JIT、workload 和 noise gate”。

### Corpus-Level Result Is Near-Flat But Informative

`docs/tmp/corpus-performance-analysis-20260428.md` 记录了一个更干净的 full-corpus run：

| Metric | Value |
|---|---:|
| comparable programs | 146 |
| geomean post/base | 1.003828 |
| wins/losses | 81/65 |
| app status | 21/22 ok |
| changed-code rows | 63/146 |
| applied rows geomean | 1.032346 |
| non-applied rows geomean | 0.982708 |

这个结果最有价值的地方不是 headline flat，而是它拆出了两个相反信号：
changed-code rows 变慢，non-applied rows 却变快。后者证明没有变更的程序也会因测量、
event mix 或 phase effect 偏离 1.0；前者说明 applied subset 的确存在 profitability
问题。一个 agent benchmark 必须能把这两类现象分开，否则 leaderboard 会奖励噪声追逐。

### Policy Helps But Does Not Solve The Corpus

`docs/tmp/2026-03-11/corpus-tuned-policy-comparison.md` 显示，human-tuned policy 相比 blind
all-apply 有改进：

| Run | Measured Pairs | Applied Programs | Exec Geomean | Wins | Regressions |
|---|---:|---:|---:|---:|---:|
| Blind all-apply | 163 | 92 | 0.868x | 40 | 107 |
| Tuned policy | 142 | 94 | 0.898x | 42 | 84 |

shared subset 上，tuned policy 从 `0.891x` 提升到 `0.898x`，wins 从 38 增到 42，
regressions 从 90 降到 84。方向正确，但仍未超过 break-even。这个结果非常适合
作为 BPFOptBench 的 human baseline：它证明“选择不优化”本身就是一个有价值的 agent 决策。

## 5.4 RQ3: Why Does BPFOptBench Need A Composed Oracle?

一个 eBPF optimization attempt 可能在多个边界失败：

| Failure Class | Oracle |
|---|---|
| verifier rejection | verifier log / ReJIT status |
| app lifecycle failure | app status / stderr / lifecycle events |
| workload semantic failure | workload raw counters, success count, error count |
| no performance signal | retained-program ratio inside noise gate |
| regression | retained-program ratio crosses regression threshold |
| noise chasing | no-op/non-applied movement explains apparent win |
| integrity failure | workload hash drift, protected path edit, loader bypass, hidden failure filtering |

这也是 BPFOptBench 和 verifier-error repair benchmark 的区别。verifier repair 可以把
“verifier 接受”作为核心成功条件；BPFOptBench 不能。一个通过 verifier 的 rewrite 仍然可能
破坏 app、改变 workload mix、没有任何 measurable signal，或者只是利用了 benchmark 漏洞。

这一节最应该做成论文里的 Table：把每个 failure class、检测信号、示例 artifact 和
scoring consequence 列出来。它会让 reviewer 相信 BPFOptBench 是一个真实系统 benchmark，
而不是 prompt collection。

## 5.5 RQ4: Do Agents Outperform Baselines?

这一部分是最终论文最醒目的 scoreboard，但它不应该是当前工作的第一优先级。原因是：
如果没有 frozen tasks、no-op floor、hidden evaluator 和 baseline fairness，agent win
很容易被 reviewer 解释成 prompt overfitting 或 measurement noise。

建议的 live scoreboard 设计如下：

| Variant | Allowed Feedback | Action Budget |
|---|---|---|
| no-op | none | 0 |
| noop ReJIT | fixed noop | 1 |
| static policy | fixed pass list | 1 |
| random/grid | task action space | same as agent |
| human-tuned | historical expert policy | 1 |
| one-shot raw LLM | raw logs/result snippets | 1 |
| one-shot structured LLM | normalized feedback summary | 1 |
| closed-loop LLM | feedback after each attempt | fixed attempt budget |

Primary result 应报告：

1. full-oracle success rate；
2. `bpfopt_success_p`；
3. geomean post/base ratio；
4. regret to best-known valid action；
5. attempts/time/tokens；
6. integrity failure rate。

如果 agent 赢了，claim 可以是：“closed-loop feedback helps agents select profitable eBPF
optimization actions under real kernel feedback。”如果 agent 没赢，claim 仍然可以成立为：
“BPFOptBench exposes why current agents fail: invalid actions, noise chasing, overfitting, or inability
to reason about eBPF-specific accounting.”

## 5.6 RQ5: Does Structured Feedback Help?

这个实验是 BPFOptBench 最像 agent benchmark 的地方，因为它不依赖某个 pass 突然有大收益，
而是测 agent 是否能更少犯错。

推荐三种 prompt mode：

| Mode | Agent Sees | 要验证的问题 |
|---|---|---|
| raw | 原始 result/log/source tree | agent 能否自己抽取关键信号 |
| structured | verifier/app/workload/perf 被规范化后的摘要 | 结构化反馈是否降低 invalid/noisy decision |
| expert-summary | 简短专家分析 + raw artifacts | 上限是信息抽取还是优化推理 |

最重要的指标不是 geomean，而是：

- invalid-action rate 是否下降；
- noise-chasing rate 是否下降；
- first valid improvement 的 attempt 数是否下降；
- heldout task 上是否不退化。

这个实验可以先做 offline：让 agent 读已有 pass-signal/policy 文档，判断结果是否可信、
下一步应该跑什么。这样成本低，而且能先验证 task/interface/prompt 设计。

## 5.7 RQ6: Is The Benchmark Independent Of KOperation?

论文必须避免让 reviewer 误解为“BPFOptBench 只是 kop 的新包装”。评估中应明确分层：

| Track | Action Space | 第一版状态 |
|---|---|---|
| bytecode-only | `wide_mem`, `map_inline`, `const_prop`, `dce`, pass policy | 必须有 |
| live ReJIT | post-load bytecode rewrite + verifier/JIT feedback | 主路径 |
| kop-enabled | `rotate`, `cond_select`, `extract`, `endian_fusion`, `bulk_memory`, `prefetch` | 可作为扩展后端 |
| source/LLVM | source edit、compiler flag、LLVM backend patch | 未来 adapter 或 smoke |

最低要求是至少一个 meaningful task track 不依赖 kop。这样 contribution 才是 agentic eBPF
optimization benchmark，而不是某个 kernel-extension benchmark。

## 5.8 Integrity Evaluation

Agent benchmark 里最容易被忽略但最有 reviewer 价值的是 anti-gaming。BPFOptBench 应该把
以下行为记为 invalid attempt：

- 降低 `WORKLOAD_DURATION`、`SAMPLES` 或改变任务预算；
- filter/skip 某些 BPF program 或 ReJIT failure；
- 改 workload，让 app 少做事；
- 用自定义 loader 取代真实 app loader；
- 在 framework 内加入 summary/geomean/ratio 逻辑；
- 修改 protected evaluator files；
- 伪造 result path 或隐藏 error。

评估上可以设计一组 adversarial tasks：公开检查较弱，hidden evaluator 会检查 workload hash、
protected path、run command、result provenance 和 fresh-VM replay。这个表即使没有性能 win，
也能让 BPFOptBench 看起来像一个严肃 benchmark。

## 5.9 Recommended Figure/Table Plan

| 图表 | 讲什么 | 当前数据状态 |
|---|---|---|
| Fig. 1 | benchmark loop：agent action -> real app loader -> verifier/JIT/workload -> raw feedback -> hidden evaluator | design-ready |
| Table 1 | optimization space：source、LLVM、bytecode、live ReJIT、kop | design-ready |
| Fig. 2 | historical difficulty：noop floor、pass instability、applied-count mismatch | 有现有数据 |
| Table 2 | oracle/failure taxonomy | 需要整理 task examples |
| Fig. 3 | agent/baseline scoreboard | 待跑 |
| Fig. 4 | raw vs structured vs closed-loop feedback | 待跑，可先 offline |
| Table 3 | bytecode-only vs kop-enabled track | 待跑/需 task manifest |
| Table 4 | integrity failures and hidden evaluator catches | 需要实现 hidden evaluator |

## 5.10 What Is The Most Valuable Evaluation?

按 reviewer value 排序，最有价值的不是马上跑大规模 agent leaderboard，而是下面三件事：

### 第一优先级：Historical Difficulty Study

这部分已经有数据，成本最低，价值最高。它能证明 BPFOptBench 的必要性：

1. no-op/no-ReJIT floor 本身很大；
2. applied count 不等于 speedup；
3. corpus headline flat 但拆开后有 applied/non-applied 反向信号；
4. human policy 能改善但不能解决问题。

这会把论文从“我们想做一个 agent benchmark”变成“现有 eBPF 优化数据确实需要一个 agent
benchmark 和组合 oracle”。

### 第二优先级：Task Manifest + Hidden Evaluator

这是 benchmark paper 的硬贡献。没有它，agent 结果很容易被认为是一次性 demo；
有了它，即使 agent 暂时不赢，论文也可以贡献一个可复现 benchmark。

最小可交付是 20-50 个 audited tasks，每个任务有：

- source artifact；
- allowed actions；
- forbidden actions；
- hidden oracle；
- baseline；
- result path convention；
- prompt/action trace。

### 第三优先级：Offline Agent Study

在 live runs 之前先做 offline study 最划算。任务可以是：

- 判断某个 pass signal 是否可信；
- 根据历史 policy log 选择下一步实验；
- 识别 invalid benchmark manipulation；
- 从 v3 raw payload 中提取有效证据。

它能低成本回答“structured feedback 是否减少错误”，并给最终 live study 选择 prompt 格式。

### 第四优先级：Small Live Scoreboard

最后再跑小规模 live A1/A2：

- A1：suite-wide pass-list tuning；
- A2：per-app policy；
- A3：复现一个历史 strong-looking signal，例如 OTEL `map_inline`。

这时 live experiment 的作用不是一次性证明 agent 很强，而是验证 benchmark loop 能真实地区分
no-op、static、random、human 和 agent。

## 5.11 Claim Gate

在当前数据状态下，论文 claim 应这样分级：

| Claim | 当前状态 | 推荐写法 |
|---|---|---|
| BPFOptBench 和 BpfReJIT/kop/native-loader 是不同 contribution | supported | 它评测 agent task/oracle，而不是提出一个 optimizer 机制 |
| eBPF optimization 难、噪声大、policy-sensitive | supported | 用 historical difficulty study 支撑 |
| 真实 evaluator 可以基于当前 repo 构建 | partially supported | v3 six-app raw run 支撑 substrate，hidden evaluator 待实现 |
| session history 可转成真实任务 | partially supported | 有聚合证据，但需要 task manifest 和 labels |
| structured feedback improves decisions | unsupported until run | 先做 offline ablation |
| agents outperform baselines | unsupported until run | frozen live scoreboard 后再说 |
| benchmark 不依赖 kop | planned | 必须放入 bytecode-only task track |

因此，当前最稳的论文定位是：

> BPFOptBench provides a real-kernel benchmark and oracle for evaluating agents
> that tune existing eBPF programs; historical data shows why such an oracle is
> necessary, and the first task suite measures whether agents can avoid invalid,
> noisy, or unprofitable optimization decisions.

而不是：

> Agents already optimize eBPF programs well.

后者要等 RQ4/RQ5 的 scoreboard 完成后才能写。
