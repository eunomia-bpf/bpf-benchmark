# Corpus 结果分析（2026-03-28）

## 输入与口径

- plan 文档：`docs/kernel-jit-optimization-plan.md`
  - 重点条目：`#474e`、`#476`、`#501`、`#523`、`#529-#538`
- benchmark 配置：`corpus/config/benchmark_config.yaml`
- 最新结果目录：
  - `runner/corpus/results/`
  - `corpus/results/`
- 最新 build 报告：`corpus/results/expanded_corpus_build.latest.json` + `corpus/results/expanded_corpus_build.md`

一个关键事实需要先说清：

- 到 `2026-03-28` 为止，`runner/corpus/results/` 和 `corpus/results/` 里的最新 `vm_corpus_*` 基本都是 **Katran / Tracee / Tetragon 的定向 rerun**，不是新的全量 corpus 跑分。
- 因此，“当前全量 corpus benchmark”的最后一份可用结果，仍然是 `2026-03-26` 的 full run：`corpus/results/vm_corpus_20260326_201508/metadata.json`。
- `2026-03-27/28` 的新 artifact 主要用于回答“当前 map_inline/const_prop/dce 在单对象上的真实状态”，不能直接当成新的 corpus geomean。

关于 ratio 方向也要统一：

- 结果文件和 markdown 报告里的 `Exec Ratio` 是 **`baseline / rejit`**。
- 所以 `< 1.0x` 表示 **REJIT 更慢**，`> 1.0x` 表示 **REJIT 更快**。
- `#474e` 里“`0.854x` 代表快 ~17%”这句和后续 artifact 的口径不一致。本文统一按结果文件本身的 `baseline/rejit` 口径解释。

## 1. 当前 artifact 状态

### 1.1 全量 corpus 的最新可用结果

- 文件：`corpus/results/vm_corpus_20260326_201508/metadata.json`
- 日期：`2026-03-26`
- 这是最后一份覆盖大规模 corpus target set 的结果。
- 它仍然带有 `#501` 已经指出的问题：**security pass 混入 perf benchmark**，所以这个 geomean 不能当成“当前 performance-only pipeline”的权威数字。

### 1.2 3 月 27/28 的最新结果其实是定向 rerun

- Katran 当前稳定真值：
  - `corpus/results/vm_corpus_20260327_172402/details/result.json`
  - `runner/corpus/results/katran_ablation_map_inline_full_20260327_1_20260327_175405/details/result.json`
- Tracee 定向 rerun：
  - `runner/corpus/results/vm_corpus_tracee_cgroup_skb_bindfix_20260327_060208/details/result.json`
  - `runner/corpus/results/vm_corpus_tracee_sys_enter_submit_rerun_20260327_130229/details/result.json`
- Tetragon 单 pass matrix：
  - `runner/corpus/results/vm_corpus_20260328_041923/metadata.json`
  - `runner/corpus/results/vm_corpus_20260328_042542/metadata.json`
  - `runner/corpus/results/vm_corpus_20260328_042647/details/result.json`

### 1.3 当前 build availability

`corpus/results/expanded_corpus_build.md`（生成时间 `2026-03-28T04:26:46Z`）显示：

- sources considered: `1213`
- built from source: `429`
- staged existing: `128`
- available objects: `557`
- failures: `656`

这和背景里提到的“568 个 `.bpf.o` / 2019 个程序”不完全一致。更准确地说：

- `2019` 仍然是 plan/metadata 里反复出现的 **程序总量**
- 但 `2026-03-28` 的最新 build report 只给出了 **557 个当前可用 object**
- 这说明现在除了 runtime coverage 问题，还有一个 **build availability / 统计口径漂移** 问题

## 2. 总体覆盖率

以最后一份全量 run `corpus/results/vm_corpus_20260326_201508/metadata.json` 为准：

| 指标 | 绝对值 | 占 benchmark target | 占 2019 程序库存 |
| --- | ---: | ---: | ---: |
| targets_attempted | 764 | 100.0% | 37.8% |
| compile_pairs | 442 | 57.9% | 21.9% |
| measured_pairs | 315 | 41.2% | 15.6% |
| applied_programs | 130 | 17.0% | 6.4% |

补充两个更直接的比率：

- `measured_pairs / compile_pairs = 315 / 442 = 71.3%`
- `applied_programs / compile_pairs = 130 / 442 = 29.4%`

结论：

- 当前 benchmark 真正进入“baseline + rejit 都跑通”的，只覆盖了 **2019 个程序里的约 15.6%**。
- 真正出现 pass 命中的，只覆盖了 **2019 个程序里的约 6.4%**。
- 如果把目标定为“评估 recent map_inline + const_prop + dce 的 corpus 效果”，这个 coverage 明显不够。

## 3. 每个 pass 的命中率和效果

### 3.1 最新全量 run 里的 pass 命中

仍以 `2026-03-26` full run 为准，compile-side hit 数如下：

| Pass | Compile hits | Hit rate vs compile_pairs |
| --- | ---: | ---: |
| const_prop | 71 | 16.1% |
| live_patch | 63 | 14.3% |
| endian_fusion | 60 | 13.6% |
| dangerous_helper_firewall | 44 | 10.0% |
| wide_mem | 34 | 7.7% |
| dce | 19 | 4.3% |
| cond_select | 10 | 2.3% |
| extract | 7 | 1.6% |
| skb_load_bytes_spec | 1 | 0.2% |
| map_inline | 0 | 0.0% |

这里最重要的不是谁最多，而是：

- **`map_inline = 0`**
- 当前 full-corpus 最新可用 run **根本没有记录到 map_inline 命中**
- 所以它不能回答“最近 map_inline + const_prop + dce 优化在 corpus 上是否有效”

### 3.2 这份全量 run 的 pass 统计已经过时

根据 `#523`，从 `2026-03-27` 开始：

- corpus 的 active performance pass 已明确收口为 `map_inline, const_prop, dce`
- pass 选择也已经改成 request-level 注入

但 full run 没有在这个新控制面下重跑，所以：

- 当前全量 pass hit rate 看到的还是旧混合状态
- `live_patch / dangerous_helper_firewall / endian_fusion / wide_mem` 的命中大量污染了 perf benchmark
- 这正是 `#501` 明确指出的问题

### 3.3 当前定向 rerun 反映出的“真实 active-pass 状态”

| Artifact | map_inline | const_prop | dce | measured? | 结论 |
| --- | --- | --- | --- | --- | --- |
| Katran `balancer_ingress` `20260327_175405` | yes | no | no | yes | 安全版本只剩 2 个 site，运行时反而变慢 |
| Katran `balancer_ingress` `20260327_172402` | yes | no | no | yes | 同样是安全版本，`1474 -> 3096 ns`，明显变慢 |
| Tracee `cgroup_skb_egress` `20260327_060208` | yes | yes | yes | no | 编译命中很好，但 `BPF_PROG_TEST_RUN` 路径坏了 |
| Tracee `sys_enter_submit` `20260327_130229` | no | yes | yes | no | attach 失败，拿不到 runtime |
| Tetragon `bpf_execve_event` matrix `20260328_041923/042542/042647` | no | no | no | no | 三条 pass 都收敛到同一个 attach blocker |

这说明 active pass 的“潜在命中”并不是 0，但它们现在被两类问题切断了：

- runtime harness / attach 根本跑不起来
- map_inline 安全版本 coverage 太窄，不能再触发明显级联折叠

## 4. 性能数据：geomean 和 wins/losses

### 4.1 最后一份全量 run 的总体性能

`corpus/results/vm_corpus_20260326_201508/metadata.json`：

- exec geomean: `0.807x`
- exec median: `0.902x`
- exec min: `0.135x`
- exec max: `12.875x`

按 `baseline/rejit` 口径解释：

- `0.807x` 表示整体是 **慢了约 23.9%**
- 这和 `#501` 的旧分析一致，只是 `#501` 把它倒数成了 `rejit/stock = 1.239x`

### 4.2 当前这个 geomean 不可信，原因不是一个

`#501` 已经指出两个核心污染源：

- security pass 混入了 perf benchmark
- 还有 **138 个完全没有 pass 命中、代码大小也完全不变的程序**，它们依然出现了 `1.249x` 的回归

这说明：

- 当前 full run 的 geomean 里混进了 **明显的测量噪声 / 执行路径噪声**
- 这个 geomean 不能用来评价 `map_inline + const_prop + dce`

### 4.3 wins / losses 分布

workspace 里已经没有 `vm_corpus_20260326_201508/details/result.json` 原件，所以无法在今天重新精确统计“全局 wins/losses 个数”。但 `2026-03-26` 已保存的分析文档仍给出了 pass-bearing 子集分布：

| Pass 子集 | Faster | Slower | 结论 |
| --- | ---: | ---: | --- |
| const_prop | 8 | 47 | 明显 loss-heavy |
| live_patch | 11 | 21 | 仍然偏 loss-heavy |
| endian_fusion | 14 | 41 | loss-heavy |
| dangerous_helper_firewall | 8 | 33 | loss-heavy |
| wide_mem | 7 | 26 | loss-heavy |
| dce | 0 | 4 | 全是 loss |

所以 wins/losses 的主结论很明确：

- **最后一份全量 run 是明显的 losses 主导**
- 但这些 losses 很大一部分并不是“当前 performance-only pipeline”的真实优化效果，而是 benchmark 本身的污染

## 5. 为什么 `measured_pairs < compile_pairs`

### 5.1 全量 run 的主要丢失点

根据 `docs/tmp/20260326/corpus_results_analysis_20260326.md`，`2026-03-26` full run 中 compile 成功但 run 失败的主要原因是：

| 原因 | 程序数 |
| --- | ---: |
| `bpf_program__attach failed: Operation not supported` | 75 |
| `bpf_program__attach failed: No such file or directory` | 17 |
| `io-mode packet requires an XDP or skb packet context` | 15 |
| `bpf_program__attach failed: Bad file descriptor` | 9 |
| `bpf_program__attach failed: Invalid argument` | 7 |
| `bpf_program__attach failed: Device or resource busy` | 3 |

metadata 里的原始 failure counter 还显示：

- `missing prepared kernel state for ref: target-0001:baseline-prepared = 151`
- `missing prepared kernel state for ref: target-0001:rejit-prepared = 151`

说明 measured gap 的主因不是“编译不过”，而是：

- attach 失败
- io-mode/context 不匹配
- prepared-state orchestration 也不够稳

### 5.2 当前 targeted rerun 里的 blocker 更具体

#### Tetragon

`runner/corpus/results/vm_corpus_20260328_042647/details/result.json`：

- `compile_pairs = 3`
- `measured_pairs = 0`
- 三个 program 全部是 `bpf_program__attach failed: Invalid argument`

也就是说：

- 这已经不是某个 pass 单独的问题
- `map_inline / const_prop / dce` 三条单-pass rerun 都收敛到同一个 attach blocker

#### Tracee `cgroup_skb_egress`

`runner/corpus/results/vm_corpus_tracee_cgroup_skb_bindfix_20260327_060208/details/result.json`：

- `compile_pairs = 1`
- `measured_pairs = 0`
- baseline 和 rejit 都失败在 `bpf_prog_test_run_opts failed: Invalid argument`

这条结果很重要，因为它说明：

- `map_inline + const_prop + dce` 其实已经能在 Tracee 的真实程序上同时命中
- 但 run path 本身坏掉了，收益被 benchmark harness 截断

#### Tracee `sys_enter_submit`

`runner/corpus/results/vm_corpus_tracee_sys_enter_submit_rerun_20260327_130229/details/result.json`：

- `compile_pairs = 1`
- `measured_pairs = 0`
- baseline 和 rejit 都失败在 `bpf_program__attach failed: No such file or directory`

这说明 Tracee 现在至少有两条不同的 runtime blocker：

- raw tracepoint attach/anchor 问题
- `cgroup_skb` 的 `test_run` 问题

## 6. `applied = 0` 的程序占多少？为什么？

### 6.1 全量 run 里的占比

在 `2026-03-26` full run 里：

- `compile_pairs = 442`
- `applied_programs = 130`
- 所以 `applied = 0` 的 compile-success 程序是 `312`
- 占比 `312 / 442 = 70.6%`

如果按 measured pair 看：

- `315 - 130 = 185`
- 占比 `58.7%`

### 6.2 原因

对这批 full-run 结果，`applied = 0` 的主要原因并不是“现在 map_inline 太差”，而是：

- 这是 **旧混合 pass 控制面** 下的 full run
- `map_inline` 在这份结果里是 **0-hit**
- `dce` 命中本来就很少，compile-side 只有 `19`
- 大部分程序本来就没有落进 `const_prop / dce / 其他 pass` 的可改写模式

而对 `2026-03-27/28` 的 targeted current-profile 结果，`applied = 0` 又分成两类：

- **真正 no-change**
  - 例如 Tetragon e2e 的 `map_inline`，现在因为 tail-call guard 被保守关闭（`#537`）
- **还没来得及观察 apply，就先死在 attach/run**
  - 例如 Tetragon corpus matrix 三条单-pass 都 attach `EINVAL`

所以“applied=0”现在不能只看一个数，必须区分：

- pass 自己没命中
- harness 先挂了
- pass 被保守 guard 主动关闭

## 7. map_inline 在 corpus 中的命中率和效果

### 7.1 corpus-wide 命中率：现在其实没有权威数字

原因很简单：

- 最新 full run（`2026-03-26`）里 `map_inline = 0`
- 最新有 `map_inline` 的 artifact 全部是单对象定向 rerun
- 也就是说，**没有一份 post-#523 / post-#534 / post-#537 的全量 corpus rerun**

所以今天最多只能给出：

- “当前 map_inline 在几个关键对象上的真实状态”
- 不能给出“当前全 corpus 的 map_inline hit rate”

### 7.2 Katran：当前安全真值是“命中了，但收益没了”

最稳的两个 artifact：

- `corpus/results/vm_corpus_20260327_172402/details/result.json`
  - `1474 ns -> 3096 ns`
  - `0.476x`
  - 语义正确
- `runner/corpus/results/katran_ablation_map_inline_full_20260327_1_20260327_175405/details/result.json`
  - `1643 ns -> 2448 ns`
  - `0.671x`
  - 语义正确

共同结论：

- 当前安全版本只保住了 **2 个可证明安全的 `ctl_array` site**
- `const_prop / dce` 没有继续级联
- 代码尺寸只减少了 `0.16%` 左右
- runtime 反而变慢

更早的 `40-41 site` 和 `1.714x` 提升（`#529-#532`）已经被 `#533` 明确判定为 **混入 correctness regression 的假阳性**

### 7.3 Tracee：有潜力，但 harness 和 fixture 还没补齐

两个最关键的事实：

- `cgroup_skb_egress` 已经出现 `map_inline + const_prop + dce` 同时命中，JIT 从 `19479 -> 16509`，代码尺寸明显下降
- 但 `BPF_PROG_TEST_RUN` 路径直接 `EINVAL`，测不到 runtime

另外：

- `sys_enter_submit` 这条 raw tracepoint 路目前只看到 `const_prop + dce`
- `map_inline` 还受限于 `#516/#518` 里已经点名的问题：
  - dynamic key
  - map value 写回 / non-fixed-load uses
  - `type=13` map
  - inner-map fixture 仍不完整

所以 Tracee 的主要问题不是“pass 完全没戏”，而是：

- live map state / fixture replay 还不够完整
- attach/test-run harness 也不稳定

### 7.4 Tetragon：现在的主 blocker 已经不是 pass 本身

`#537/#538` 的结论很一致：

- e2e 侧：`map_inline` 因为 tail-call helper guard 被保守禁用，得到的是 clean `no_change`
- corpus 侧：`map_inline / const_prop / dce` 三条单-pass 跑法全部收敛到 **同一个 generic attach `EINVAL`**

所以 Tetragon 当前最该修的不是 pass 逻辑，而是：

- generic attach 路径
- benchmark harness 对 `event_execve` family 的挂载方式

## 8. 和 plan 历史数据的对比

### 8.1 `#474e`（2026-03-25）

`corpus/results/vm_corpus_20260325_053936/metadata.json`：

- `targets_attempted = 152`
- `compile_pairs = 152`
- `measured_pairs = 152`
- `applied_programs = 72`
- `exec_ratio_geomean = 0.854x`

这是一份 **小得多但非常干净** 的 run：

- 目标少
- compile/measured 都是满覆盖
- 但当时 Tracee/Tetragon 还有明显 verifier blocker（`#474e`、`#476`）

### 8.2 `#501` / latest full run（2026-03-26）

`corpus/results/vm_corpus_20260326_201508/metadata.json`：

- `764 / 442 / 315 / 130`
- `exec_ratio_geomean = 0.807x`

相对 `#474e` 的变化：

- target 从 `152 -> 764`
- compile 从 `152 -> 442`
- measured 从 `152 -> 315`
- applied 从 `72 -> 130`
- geomean 从 `0.854x -> 0.807x`

但这不是 apples-to-apples 比较，因为：

- corpus target set 大幅扩容
- pass mix 被 security pass 污染
- full run 里 `map_inline = 0`

### 8.3 `#523/#534/#537/#538` 之后的当前状态

到 `2026-03-28`，状态变成：

- pass 控制面已经修正到 performance-only
- warmup 接线已经修正
- Tetragon 的问题也被收敛成 attach blocker，而不是继续混杂 pass-specific 结论
- Katran 的 unsafe 假阳性已经被回退到 correctness-first 的安全版本

但代价是：

- **没有新的全量 corpus 权威数字**
- 当前只能说“局部 case 的 correctness 收敛了”，还不能说“全 corpus 的 performance story 成立了”

## 9. 当前 corpus benchmark 的主要问题

### 9.1 最严重的问题：缺少新的 authoritative full-corpus rerun

这是最大的结论。

- 当前没有一份同时满足下面四个条件的全量 artifact：
  - post-`#523` request-level pass control
  - post-`#534` warmup 修复
  - post-`#533/#535` Katran correctness rollback
  - post-`#537/#538` Tetragon attach blocker 显性化

所以今天根本没有办法回答：

- “现在的 performance-only `map_inline + const_prop + dce` 在全 corpus 上 geomean 到底是多少”

### 9.2 runtime coverage 远低于程序库存

当前最好的全量数字也只是：

- `315 / 2019 = 15.6%` measured
- `130 / 2019 = 6.4%` applied

coverage 太低，导致任何 geomean 都会被少数 source family 主导。

### 9.3 measured gap 主要是 harness/attach，不是 pass 本身

现在丢失 measured pair 的主因已经很明确：

- Tetragon: attach `EINVAL`
- Tracee raw tracepoint: attach `ENOENT`
- Tracee cgroup_skb: `BPF_PROG_TEST_RUN EINVAL`
- full run 里还有 prepared-state orchestration 噪声

如果这些不先修，继续调 pass heuristic 的 ROI 很低。

### 9.4 map_inline 的安全 coverage 现在太窄

Katran 已经证明：

- 不安全放宽能拿到很漂亮的数字
- 但一旦 correctness 收紧，coverage 很快从 `40+` site 掉回 **2** site

这说明 map_inline 当前真正的瓶颈不是“再多放一点 alias 规则”，而是：

- 需要新的、可证明 dominated 的 config-load cluster 识别
- 需要更完整的 live map state / fixture 支撑

### 9.5 build availability 也在拖后腿

最新 build report 只有 `557` 个 available objects，且：

- `656` 个 source build 失败
- 其中 `648` 个是 clang 阶段失败
- `linux-selftests` 单 repo 就有 `555` 个 build error

这说明当前 corpus benchmark 不是只受 runtime harness 限制，build 面也还没有完全稳定。

## 10. 改进方向

### 10.1 先补一份新的权威全量 run

这是最高优先级。

目标应该是重跑一份 full corpus，并且同时满足：

- `performance` profile 真正只含 `map_inline, const_prop, dce`
- warmup 用的是配置文件里的真实值
- 结果保留完整 `details/result.json`
- 明确区分 `compile/measured/timed/applied`

没有这一步，所有“当前 corpus 性能结论”都只能停留在 case study。

### 10.2 先修 attach / test-run / prepared-state，再调 pass

具体 blocker 已经很明确：

- Tetragon `event_execve` family 的 generic attach `EINVAL`
- Tracee raw tracepoint attach `ENOENT`
- Tracee `cgroup_skb` 的 `BPF_PROG_TEST_RUN EINVAL`
- full corpus prepared-state 缺失

这类问题直接决定 `measured_pairs`，对 coverage 的收益比继续抠 pass heuristic 更大。

### 10.3 把“是否可信”变成 benchmark 报告的一等公民

建议后续 corpus 报告默认分开列：

- compile coverage
- measured coverage
- timed coverage
- applied coverage
- no-pass/no-size-change 对照组

并对下列样本单独标记或剔除：

- timing floor dominated
- baseline/rejit 都无 pass 命中
- code ratio 完全 `1.0x`

否则 geomean 很容易继续被噪声污染。

### 10.4 map_inline 的下一步不要再走“不安全放宽”

Katran `#532 -> #533` 已经证明：

- mutable store-back
- spill-slot alias lifetime

这两类一旦放宽错了，拿到的漂亮 speedup 基本都是假阳性。

更靠谱的方向是：

- dominated config-load cluster 专项识别
- 动态 key / 间接 key 恢复，但只在可证明范围内做
- fixture/live map state 补全，让本来就安全的 site 真正可命中

### 10.5 把 benchmark target coverage 从 764 往 2019 拉

当前全量 run 只有 `764` 个 benchmark target，远低于 `2019` 的程序库存。

下一步应该同时推进：

- macro corpus target/hypothesis 扩展
- object/program attach recipe 补齐
- runtime input/context 补齐

否则即便 build availability 提高，runtime benchmark 也还是只覆盖到少数热门 family。

## 11. 总结

当前 corpus benchmark 的核心问题不是“map_inline 完全没效果”，而是：

- **没有新的全量权威 run**
- **runtime coverage 太低**
- **measured gap 主要卡在 attach / test-run / prepared-state**
- **当前安全版 map_inline coverage 过窄，局部 case 已经证明 correctness-first 后收益会大幅缩水**

如果按工程优先级排序，最该做的三件事是：

1. 补一份 post-`#523/#534/#537/#538` 的 authoritative full-corpus rerun。
2. 先修 Tetragon/Tracee 的 attach 与 test-run 路径，把 `measured_pairs` 拉起来。
3. 在 correctness-first 前提下扩 safe `map_inline` coverage，而不是再回到 `#532` 那种不安全放宽。
